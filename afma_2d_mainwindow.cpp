#include "afma_2d_mainwindow.h"
#include "ui_afma_2d_mainwindow.h"
#include <algorithm>
#include <QFileDialog>
#include <QPointF>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <iostream>
#include <algorithm>
#include <QMessageBox>
#include <QFormLayout>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <animationdialog.h>
#include <QInputDialog>
#include <QTimer>


AFMA_2D_MainWindow::AFMA_2D_MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AFMA_2D_MainWindow)
{
    this->setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    ui->setupUi(this);
    ui->annotationWidget->ogl = ui->openGLWidget;
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateAnimation()));
}

AFMA_2D_MainWindow::~AFMA_2D_MainWindow()
{
    delete ui;
}

//aktualisieren des Modells
void AFMA_2D_MainWindow::updateModel()
{
    for(unsigned int i = 0; i < ui->openGLWidget->model.vec_faceComponents.size(); ++i)
    {
    for(unsigned int j = 0; j < ui->openGLWidget->model.vec_faceComponents[i].vec_moved.size(); ++j)
    {
        ui->openGLWidget->model.vec_changed[ui->openGLWidget->model.vec_faceComponents[i].vec_reference_point[j]] = ui->openGLWidget->model.vec_faceComponents[i].vec_moved[j];
        debugMessage("Executed");
    }
    }
    ui->openGLWidget->update();
    this->update();
}

//Wechsel zwischen Animations- und Annotationsmodell
void AFMA_2D_MainWindow::showModel()
{
    if(show == false)
    {
    for(unsigned int i = 0; i < ui->openGLWidget->model.vec_faceComponents.size(); ++i)
    {
    for(unsigned int j = 0; j < ui->openGLWidget->model.vec_faceComponents[i].vec_moved.size(); ++j)
    {
        ui->openGLWidget->model.vec_changed[ui->openGLWidget->model.vec_faceComponents[i].vec_reference_point[j]] = ui->openGLWidget->model.vec_faceComponents[i].vec_moved[j];
        debugMessage("Show");
    }
    }
    show = true;
    }
    else
    {
        for(unsigned int i = 0; i < ui->openGLWidget->model.vec_faceComponents.size(); ++i)
        {
            for(unsigned int j = 0; j < ui->openGLWidget->model.vec_faceComponents[i].vec_moved.size(); ++ j)
            {
                 ui->openGLWidget->model.vec_changed[ui->openGLWidget->model.vec_faceComponents[i].vec_reference_point[j]] = ui->openGLWidget->model.vec_faceComponents[i].vec_vertices[j];
            }
        }
        show = false;
    }
    ui->openGLWidget->update();
    this->update();
}

//Fügt die Annotation aus dem geladen File hinzu
void AFMA_2D_MainWindow::drawAnnotation(std::vector<glm::vec3> pts)
{
   // double rad = 1;
    for(unsigned int i = 0; i < pts.size(); ++i)
    {
    //ui->graphicsView->scene()->addEllipse(pts[i].x()-rad, pts[i].y()-rad, rad*3.0, rad*3.0, QPen(Qt::red), QBrush(Qt::SolidPattern));
    ui->annotationWidget->vec_vertices.push_back(glm::vec3(pts[i].x, pts[i].y, 1));
    }
}

//Erzeugt eine Ausgabe im Debuglabel
void AFMA_2D_MainWindow::debugMessage(QString str)
{
    ui->lbl_Debug->setText(str);
}



//Löscht die komplette Annotation aus der GUI
void AFMA_2D_MainWindow::clearAnnotation()
{
    ui->annotationWidget->vec_vertices.clear();
    ui->annotationWidget->update();
}

//Animationsmodell wird überschrieben
void AFMA_2D_MainWindow::updateAnimation()
{
    if(animationList.size() > 0)
     {
    if(animation == false)
    {
        for(unsigned int i = 0; i < ui->openGLWidget->model.vec_faceComponents.size(); ++i)
        {
            for(unsigned int j = 0; j < ui->openGLWidget->model.vec_faceComponents[i].vec_moved.size(); ++ j)
            {
                 ui->openGLWidget->model.vec_changed[ui->openGLWidget->model.vec_faceComponents[i].vec_reference_point[j]] = ui->openGLWidget->model.vec_faceComponents[i].vec_vertices[j];
            }
        }
        animation = true;
    }
    else
    {
        int i = ui->cb_AnimationList->currentIndex();
        ui->openGLWidget->model.vec_changed = animationList[i];
        animation = false;
    }
    ui->openGLWidget->update();
    }
}


//Läd ein neues Referenzbild
void AFMA_2D_MainWindow::on_psBtn_Load_clicked()
{
    timer.stop();
    clearAnnotation();

    m_fileName = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                            "",
                                            tr("Image Files (*.png *.jpg *.bmp )"));

   if(!QFile::exists(m_fileName))
   {
       debugMessage("No image selected");
       return;
   }

    ui->sld_Time->setSliderPosition(m_initial_Slider_position);
    Texture.load(m_fileName);
    ui->annotationWidget->textureImage = Texture;
    ui->openGLWidget->textureImage = Texture;
    ui->annotationWidget->filepath = m_fileName;
    ui->annotationWidget->update();

}


//Speichert das aktuelle Projekt
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


        xmlWriter.writeStartElement("AnimationList");
        for(unsigned int i = 0; i < animationName.size(); ++i)
        {
            xmlWriter.writeStartElement("AnimationName");
            xmlWriter.writeCharacters(animationName[i]);
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement(animationName[i]);
                for(unsigned int j = 0; j < animationList[i].size(); ++j)
                {
                xmlWriter.writeStartElement("Point" + QString::number(j));
                xmlWriter.writeTextElement("x", QString::number((float)animationList[i][j].x));
                xmlWriter.writeTextElement("y", QString::number((float)animationList[i][j].y));
                xmlWriter.writeTextElement("z", QString::number((float)animationList[i][j].z));
                xmlWriter.writeEndElement();
                }
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        file.close();

}

//Lädt ein komplettes Objekt
void AFMA_2D_MainWindow::on_psBtn_LoadProject_clicked()
{
        timer.stop();
        clearAnnotation();
        animationList.clear();
        animationName.clear();
        ui->cb_AnimationList->clear();
        ui->annotationWidget->vec_vertices.clear();



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
                        else if(reader.name() == "AnimationList")
                        {
                            QString name;
                            while(reader.readNextStartElement())
                            {

                                int j = 0;
                                if(reader.name() == "AnimationName")
                                {   name = QString::fromStdString(reader.readElementText().toStdString());
                                    animationName.push_back(name);
                                }
                                else if(reader.name() == name)
                                {
                                    std::vector<glm::vec3> vec_animationPoints;
                                   while(reader.readNextStartElement())
                                    {
                                        if(reader.name() == "Point" +QString::number(j))
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
                                            vec_animationPoints.push_back(pt);
                                            debugMessage(QString::number(vec_animationPoints.size()));

                                        }
                                        else
                                             {
                                                debugMessage("Point fail");
                                                reader.skipCurrentElement();
                                             }
                                        ++j;
                                    }
                                   animationList.push_back(vec_animationPoints);
                                }
                            }
                        }
                        else
                        {
                            debugMessage("Animation fail");
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
        ui->sld_Time->setSliderPosition(m_initial_Slider_position);
        ui->openGLWidget->count = 0;
        for(unsigned int i = 0; i < ui->annotationWidget->vec_vertices.size(); ++i)
        {
            ui->openGLWidget->next();
        }
        ui->openGLWidget->draw();
        for(unsigned int i = 0; i < animationName.size(); ++i)
        {
            ui->cb_AnimationList->addItem(animationName[i]);
        }
        debugMessage(QString::number(ui->openGLWidget->model.vec_vertices.size()) +" " + QString::number(ui->annotationWidget->vec_vertices.size()) +" " + QString::number(ui->openGLWidget->count));
        this->update();

        if(ui->annotationWidget->vec_vertices.size() == ui->openGLWidget->model.vec_vertices.size())
        {

            on_psBtn_GenerateModel_clicked();
            ui->openGLWidget->line = true;
        }
}

//Löscht Annotation aus dem Speicher
void AFMA_2D_MainWindow::on_psBtn_ClearAnnotation_clicked()
{
    timer.stop();
    clearAnnotation();
    ui->openGLWidget->undoAnnotation();

    ui->openGLWidget->update();

}

//Macht letzten Annotationspunkt rückgängig
void AFMA_2D_MainWindow::on_psBtn_UndoLastPoint_clicked()
{
    timer.stop();
    if(ui->annotationWidget->vec_vertices.size() > 0 && ui->annotationWidget->vec_vertices.size() != ui->openGLWidget->model.vec_vertices.size())
    {
    ui->annotationWidget->vec_vertices.pop_back();

    ui->openGLWidget->model.vec_color[ui->openGLWidget->count] = glm::vec4(1,1,1,0.3f);
      ui->openGLWidget->count--;
    ui->openGLWidget->model.vec_color[ui->openGLWidget->count] = glm::vec4(1,0,0,1);
    ui->openGLWidget->update();
    }


    ui->annotationWidget->update();

}


//Wechsel zwischen Gittermodell und texturierten Modell
void AFMA_2D_MainWindow::on_psBtn_GenerateModel_clicked()
{
    timer.stop();
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
    for(unsigned int i = 0; i < ui->openGLWidget->model.vec_faceComponents.size(); ++i)
    {
    ui->cb_FaceComponents->addItem(ui->openGLWidget->model.vec_faceComponents[i].name);
    this->update();
    }
    ui->cb_AnimationList->clear();
    for(unsigned int i = 0; i < animationName.size(); ++i)
    {
    ui->cb_AnimationList->addItem(animationName[i]);
    }
    ui->openGLWidget->model.setFaceComponents();
}

//Öffnet den AnnotationHelper
void AFMA_2D_MainWindow::on_psBtn_AnnotationHelp_clicked()
{

    QMessageBox *mb = new QMessageBox(this);
    if(ui->annotationWidget->vec_vertices.size() < ui->openGLWidget->model.vec_vertices.size())
    {
        mb->setText(QString::number(ui->openGLWidget->count) + ": " +ui->openGLWidget->model.vec_annotationText[ui->openGLWidget->count]);
    }
    else
    {
        mb->setText("Annotation done");
    }
        mb->show();
}

//Hinzufügen einer neuen Animation
void AFMA_2D_MainWindow::on_psBtn_SetAnimation_clicked()
{
    timer.stop();
    int i = ui->cb_FaceComponents->currentIndex();
    dia = new AnimationDialog(ui->openGLWidget->model.vec_faceComponents[i].vec_name, ui->openGLWidget->model.vec_faceComponents[i].vec_vertices, ui->openGLWidget->model.vec_faceComponents[i].vec_moved);
    dia->setWindowTitle(ui->openGLWidget->model.vec_faceComponents[i].name);
    connect(dia->psb_accept, SIGNAL(clicked(bool)), this, SLOT(updateModel()));
    connect(dia->psb_show, SIGNAL(clicked(bool)), this, SLOT(showModel()));
    dia->exec();

}

//Startet Animation
void AFMA_2D_MainWindow::on_psBtn_StartAnimation_clicked()
{
    if(timer.isActive())
    {
        timer.stop();
    }
    else
    {
    timeframe = ui->sld_Time->value();

    timer.start(timeframe*100);
    }
}

//Speichert die Animation
void AFMA_2D_MainWindow::on_psBtn_SafeAnimation_clicked()
{
    timer.stop();
    bool ok;
    QString newAnimationName = QInputDialog::getText(this, tr("Safe Animation"),tr("Please enter a name for the animation:"),QLineEdit::Normal,"",&ok);
    if(ok == true)
    {
        ui->cb_AnimationList->addItem(newAnimationName);
        animationName.push_back(newAnimationName);
        animationList.push_back(ui->openGLWidget->model.vec_changed);
    }

}

//Verändert Animationsgeschwindigkeit
void AFMA_2D_MainWindow::on_sld_Time_valueChanged(int value)
{
    timeframe = value;
    if(timer.isActive())
    {
        timer.start(timeframe*100);
    }
    ui->openGLWidget->update();
}

//Löscht ausgewählte Animation
void AFMA_2D_MainWindow::on_psBtn_RemoveAnimation_clicked()
{
    timer.stop();
    if(animationName.size() > 0)
    {
    int index = ui->cb_AnimationList->currentIndex();
    ui->cb_AnimationList->removeItem(index);
    animationName.erase(animationName.begin() + index);
    animationList.erase(animationList.begin() + index);
    }
}

//Überschreibt ausgewählte Animation
void AFMA_2D_MainWindow::on_psBtn_Override_clicked()
{
    int i =  ui->cb_AnimationList->currentIndex();
    animationList[i] = ui->openGLWidget->model.vec_changed;
}
