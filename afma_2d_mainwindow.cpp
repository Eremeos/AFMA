#include "afma_2d_mainwindow.h"
#include "ui_afma_2d_mainwindow.h"
#include "utility2d.h"
#include <algorithm>
#include <QFileDialog>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <QPointF>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <iostream>
#include <algorithm>
#include <QMessageBox>

AFMA_2D_MainWindow::AFMA_2D_MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AFMA_2D_MainWindow)
{
    ui->setupUi(this);
    ui->annotationWidget->ogl = ui->openGLWidget;
}

AFMA_2D_MainWindow::~AFMA_2D_MainWindow()
{
    delete ui;
}

void AFMA_2D_MainWindow::drawAnnotation(std::vector<glm::vec3> pts)
{
   // double rad = 1;
    for(unsigned int i = 0; i < pts.size(); ++i)
    {
    //ui->graphicsView->scene()->addEllipse(pts[i].x()-rad, pts[i].y()-rad, rad*3.0, rad*3.0, QPen(Qt::red), QBrush(Qt::SolidPattern));
    ui->annotationWidget->vec_vertices.push_back(glm::vec3(pts[i].x, pts[i].y, 1));
    }
}

void AFMA_2D_MainWindow::debugMessage(QString str)
{
    ui->lbl_Debug->setText(str);
}




void AFMA_2D_MainWindow::clearAnnotation()
{
    ui->annotationWidget->vec_vertices.clear();
    ui->annotationWidget->update();
}



void AFMA_2D_MainWindow::on_psBtn_Load_clicked()
{
    clearAnnotation();

    m_fileName = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                            "",
                                            tr("Image Files (*.png *.jpg *.bmp )"));

   if(!QFile::exists(m_fileName))
   {
       debugMessage("No image selected");
       return;
   }

    ui->sld_Scale->setSliderPosition(m_initial_Slider_position);
    Texture.load(m_fileName);
    ui->annotationWidget->textureImage = Texture;
    ui->openGLWidget->textureImage = Texture;
    ui->annotationWidget->filepath = m_fileName;
    ui->annotationWidget->update();

}


void AFMA_2D_MainWindow::on_sld_Scale_sliderMoved(int position)
{
    debugMessage(QString::number(position));
    for(unsigned int i = 0; i < ui->openGLWidget->model.vec_vertices.size(); ++i)
    {
    ui->openGLWidget->model.vec_vertices[i].x *= 0.9f;
    ui->openGLWidget->model.vec_vertices[i].y *= 0.9f;
    }
    ui->openGLWidget->update();
}



void AFMA_2D_MainWindow::on_psBtn_SaveAnnotation_clicked()
{

    debugMessage(QString::number(ui->annotationWidget->vec_vertices.size()));

    QString save_filename = QFileDialog::getSaveFileName(this,
                                           tr("Save Xml"), ".",
                                           tr("Xml files (*.xml)"));

      QFile file(save_filename);
      save_filename.chop(4);


    Texture.save(save_filename+".jpg");


      file.open(QIODevice::WriteOnly);

      QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("AFMAFILE");

        xmlWriter.writeStartElement("ImagePath");
        xmlWriter.writeCharacters(save_filename+".jpg");
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("Annotation");
        for(unsigned int i = 0; i < ui->annotationWidget->vec_vertices.size();++i)
        {
            xmlWriter.writeStartElement("Point" + QString::number(i));
            xmlWriter.writeTextElement("x", QString::number((float)ui->annotationWidget->vec_vertices[i].x));
            xmlWriter.writeTextElement("y", QString::number((float)ui->annotationWidget->vec_vertices[i].y));
            xmlWriter.writeTextElement("z", QString::number((float)ui->annotationWidget->vec_vertices[i].z));
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        file.close();

}

void AFMA_2D_MainWindow::on_psBtn_LoadProject_clicked()
{
        clearAnnotation();


        QString load_filename = QFileDialog::getOpenFileName(this,
                                       tr("Open Xml"), ".",
                                       tr("Xml files (*.xml)"));
        if(!QFile::exists(load_filename))
        {
            debugMessage("No file selected");
            return;
        }
        QFile file(load_filename);
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            std::cerr << "Error: Cannot read file " << qPrintable(load_filename)
             << ": " << qPrintable(file.errorString())
             << std::endl;
        }
        QString s;
        QXmlStreamReader reader(&file);

        if (reader.readNextStartElement()) {
            if (reader.name() == "AFMAFILE"){
                while(reader.readNextStartElement()){
                    if(reader.name() == "ImagePath"){
                        s = reader.readElementText();
                        if(!QFile::exists(s))
                        {
                           debugMessage("Image not found!");
                           return;
                        }
                        qDebug(qPrintable(s));
                    }
                    else
                    {
                        reader.skipCurrentElement();
                    }
                    while(reader.readNextStartElement())
                    {
                        if(reader.name() == "Annotation")
                        {   int i = 0;

                            while(reader.readNextStartElement())
                            {
                                if(reader.name() == "Point" +QString::number(i))
                                {
                                    glm::vec3 pt;
                                    while(reader.readNextStartElement())
                                    {
                                        if(reader.name() == "x")
                                        {
                                            pt.x = reader.readElementText().toDouble();
                                        }
                                        else if(reader.name() == "y")
                                        {
                                            pt.y = reader.readElementText().toDouble();
                                        }
                                        else if(reader.name() == "z")
                                        {
                                            pt.z = reader.readElementText().toDouble();
                                        }
                                        else
                                        {
                                            debugMessage("x,y,z fail");
                                            reader.skipCurrentElement();
                                        }
                                    }

                                    ui->annotationWidget->vec_vertices.push_back(pt);
                                    debugMessage(QString::number(ui->annotationWidget->vec_vertices.size()));
                                }
                                else
                                {
                                    debugMessage("Point fail");
                                    reader.skipCurrentElement();
                                }
                                    ++i;
                            }
                        }
                        else
                        {
                            debugMessage("Annotation fail");
                            reader.skipCurrentElement();
                        }
                    }
                }
            }
            else
                reader.raiseError(QObject::tr("Incorrect file"));
        }



        m_fileName = s;
        ui->annotationWidget->filepath = s;
        Texture.load(m_fileName);
        ui->annotationWidget->textureImage = Texture;
        ui->openGLWidget->textureImage = Texture;
        ui->sld_Scale->setSliderPosition(m_initial_Slider_position);

        for(unsigned int i = 0; i < ui->annotationWidget->vec_vertices.size(); ++i)
        {
            ui->openGLWidget->next();
        }
        ui->openGLWidget->draw();
        debugMessage(QString::number(ui->openGLWidget->model.vec_vertices.size()) +" " + QString::number(ui->annotationWidget->vec_vertices.size()) +" " + QString::number(ui->openGLWidget->count));
}

void AFMA_2D_MainWindow::on_psBtn_ClearAnnotation_clicked()
{
    clearAnnotation();
    ui->openGLWidget->undoAnnotation();

    ui->openGLWidget->update();

}


void AFMA_2D_MainWindow::on_psBtn_UndoLastPoint_clicked()
{

    if(ui->annotationWidget->vec_vertices.size() > 0)
    {
    ui->annotationWidget->vec_vertices.pop_back();

    ui->openGLWidget->model.vec_color[ui->openGLWidget->count] = glm::vec4(1,1,1,0.3f);
      ui->openGLWidget->count--;
    ui->openGLWidget->model.vec_color[ui->openGLWidget->count] = glm::vec4(1,0,0,1);
    ui->openGLWidget->update();
    }


    ui->annotationWidget->update();

}


void AFMA_2D_MainWindow::on_psBtn_NextPoint_clicked()
{


        ui->openGLWidget->model.vec_changed[16].y -= 0.001f;
        ui->openGLWidget->model.vec_changed[18].y -= 0.001f;

        ui->openGLWidget->model.vec_changed[49].y -= 0.001f;
        ui->openGLWidget->model.vec_changed[51].y -= 0.001f;





    ui->openGLWidget->update();
}



void AFMA_2D_MainWindow::on_psBtn_GenerateModel_clicked()
{
    if(ui->openGLWidget->line == true)
    {
    ui->openGLWidget->line = false;
    }
    else
    {
    ui->openGLWidget->line = true;
    if(changeCount < ui->annotationWidget->vec_vertices.size())
        {
            ui->openGLWidget->model.vec_changed = ui->annotationWidget->vec_vertices;

         for(unsigned int i = 0; i < ui->annotationWidget->vec_vertices.size(); ++i)
        {

        ui->openGLWidget->model.vec_vertices[changeCount].x = ui->annotationWidget->vec_vertices[changeCount].x;
        ui->openGLWidget->model.vec_vertices[changeCount].y = ui->annotationWidget->vec_vertices[changeCount].y;

            ++changeCount;
       }
    }

    }
    debugMessage(QString::number(ui->openGLWidget->model.vec_vertices.size()));
    ui->openGLWidget->update();
}

void AFMA_2D_MainWindow::on_psBtn_AnnotationHelp_clicked()
{
    QMessageBox *mb = new QMessageBox();

    mb->setText(ui->openGLWidget->model.vec_annotationText[ui->openGLWidget->count]);
    mb->show();
}
