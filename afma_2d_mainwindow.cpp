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

void AFMA_2D_MainWindow::updateAnnotation()
{
    //std::vector<QPointF> newPoints = ui->graphicsView->vec_pt;
    std::vector<glm::vec3> newPoints = ui->annotationWidget->vec_vertices;
    for(unsigned int i = 0; i < newPoints.size(); ++i)
    {

      if(std::find(vec_points.begin(), vec_points.end(), newPoints[i]) == vec_points.end())
      {
        new_vec_points.push_back(newPoints[i]);

        glm::vec3 help = newPoints[i];
        help.x =help.x/m_scale;
        help.y = help.y/m_scale;

        if(std::find(vec_points.begin(), vec_points.end(), help) == vec_points.end())
         {
             vec_points.push_back(help);
            // ui->graphicsView->vec_pt[i] = help;
             ui->annotationWidget->vec_vertices[i] = help;

         }
      }
    }


}

void AFMA_2D_MainWindow::updateAnnotation(std::vector<glm::vec3> pts)
{
    vec_points = pts;
    //ui->graphicsView->vec_pt = pts;
    ui->annotationWidget->vec_vertices = pts;
    new_vec_points = pts;
}

void AFMA_2D_MainWindow::clearAnnotation()
{
    vec_points.clear();
   // ui->graphicsView->vec_pt.clear();
    new_vec_points.clear();
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

    m_image = cv::imread(m_fileName.toStdString());


    m_image.copyTo(m_morphed_Image);

    setDisplayImage(m_image);
    ui->sld_Scale->setSliderPosition(m_initial_Slider_position);
    Texture.load(m_fileName);
    ui->annotationWidget->textureImage = Texture;
    ui->openGLWidget->textureImage = Texture;
    ui->annotationWidget->filepath = m_fileName;
    ui->annotationWidget->update();

}

void AFMA_2D_MainWindow::on_psBtn_SetPixel_clicked()
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

         for(int i = 0; i < ui->annotationWidget->vec_vertices.size(); ++i)
        {



        ui->openGLWidget->model.vec_vertices[changeCount].x = ui->annotationWidget->vec_vertices[changeCount].x;
        ui->openGLWidget->model.vec_vertices[changeCount].y = ui->annotationWidget->vec_vertices[changeCount].y;
           // ui->openGLWidget->model.vec_vertices[changeCount].x *= 0.9;
          //  ui->openGLWidget->model.vec_vertices[changeCount].y *= 0.9;

            ++changeCount;
       }
    }

    }
    debugMessage(QString::number(ui->openGLWidget->model.vec_vertices.size()));
    ui->openGLWidget->update();
}

void AFMA_2D_MainWindow::setDisplayImage(cv::Mat newImage, std::vector<glm::vec3> annotation_points)
{
/*    QImage img = Utility2D::fromOpenCVToQImage(newImage);
    m_scene->clear();
    QPixmap p_Image = QPixmap::fromImage(img);
    m_scene->addPixmap(p_Image);
    m_scene->setSceneRect(p_Image.rect());
    ui->graphicsView->setScene(m_scene);
    newImage.copyTo(m_displayed_Image);
    drawAnnotation(annotation_points);
*/
}

void AFMA_2D_MainWindow::setDisplayImage(cv::Mat newImage)
{
 /*   updateAnnotation();
    QImage img = Utility2D::fromOpenCVToQImage(newImage);
    m_scene->clear();
    QPixmap p_Image = QPixmap::fromImage(img);
    m_scene->addPixmap(p_Image);
    m_scene->setSceneRect(p_Image.rect());
    ui->graphicsView->setScene(m_scene);
    newImage.copyTo(m_displayed_Image);
    drawAnnotation(new_vec_points); */
}

void AFMA_2D_MainWindow::on_psButton_Initial_Image_clicked()
{
    setDisplayImage(m_image);
    m_image.copyTo(m_morphed_Image);
    ui->sld_Scale->setSliderPosition(m_initial_Slider_position);
}

void AFMA_2D_MainWindow::on_psBtn_FaceDet_clicked()
{
    clearAnnotation();
    Utility2D::generateFaceModel(m_FaceModel, m_displayed_Image);
    m_morphed_Image = m_displayed_Image(m_FaceModel.getFace().getComponent());
    ui->sld_Scale->setSliderPosition(m_initial_Slider_position);
    setDisplayImage(m_morphed_Image);

}


void AFMA_2D_MainWindow::on_sld_Scale_sliderMoved(int position)
{
    debugMessage(QString::number(position));
    for(int i = 0; i < ui->openGLWidget->model.vec_vertices.size(); ++i)
    {
    ui->openGLWidget->model.vec_vertices[i].x *= 0.9;
    ui->openGLWidget->model.vec_vertices[i].y *= 0.9;
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

    //  Utility2D::fromOpenCVToQImage(m_displayed_Image).save(save_filename+".jpg");
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
        vec_points.clear();
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
                            vec_points.clear();
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
                                    vec_points.push_back(pt);
                                    ui->annotationWidget->vec_vertices.push_back(pt);
                                    new_vec_points.push_back(pt);
                                    debugMessage(QString::number(vec_points.size()));
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

        for(int i = 0; i < ui->annotationWidget->vec_vertices.size(); ++i)
        {
            ui->openGLWidget->next();
        }
        on_psBtn_Draw3D_clicked();
        debugMessage(QString::number(ui->openGLWidget->model.vec_vertices.size()) +" " + QString::number(ui->annotationWidget->vec_vertices.size()) +" " + QString::number(ui->openGLWidget->count));
}

void AFMA_2D_MainWindow::on_psBtn_ClearAnnotation_clicked()
{
    clearAnnotation();
    ui->openGLWidget->undoAnnotation();
    ui->openGLWidget->update();
    setDisplayImage(m_displayed_Image);
}

void AFMA_2D_MainWindow::on_sld_Scale_sliderReleased()
{
  setDisplayImage(m_displayed_Image, new_vec_points);

}

void AFMA_2D_MainWindow::on_psBtn_UndoLastPoint_clicked()
{
    if(vec_points.size() > 0)
    {
    vec_points.pop_back();
    updateAnnotation();
    }
    if(ui->annotationWidget->vec_vertices.size() > 0)
    {
    ui->annotationWidget->vec_vertices.pop_back();

    ui->openGLWidget->model.vec_color[ui->openGLWidget->count] = glm::vec4(1,1,1,0.1);
      ui->openGLWidget->count--;
    ui->openGLWidget->model.vec_color[ui->openGLWidget->count] = glm::vec4(1,0,0,1);
    ui->openGLWidget->update();
    }
    setDisplayImage(m_displayed_Image);

    ui->annotationWidget->update();

}

void AFMA_2D_MainWindow::on_sld_Scale_sliderPressed()
{
    updateAnnotation();
    setDisplayImage(m_displayed_Image, new_vec_points);
}



void AFMA_2D_MainWindow::on_psBtn_Draw3D_clicked()
{
    ui->openGLWidget->draw();
}

void AFMA_2D_MainWindow::on_psBtn_NextPoint_clicked()
{

    ui->openGLWidget->model.upperLipraiser();
    ui->openGLWidget->update();
}


