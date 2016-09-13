#include "animationdialog.h"
#include <QDoubleSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <iostream>

AnimationDialog::AnimationDialog(std::vector<QString> &vec_faceComponent_name, std::vector<glm::vec3> &vec_faceComponent_values,std::vector<glm::vec3> &vec_outputFaceComponent_values)
{
    vec_input_values = &vec_faceComponent_values;
    vec_output_values = &vec_outputFaceComponent_values;
    vec_input_name = &vec_faceComponent_name;


    animationLayout = new QGridLayout(this);
    for(int i = 0; i < vec_input_values->size(); ++i)
    {
    dsb0 = new QDoubleSpinBox(this);
    dsb0->setMinimum(-1);
    dsb0->setMaximum(1);
    dsb0->setSingleStep(0.001);
    dsb0->setDecimals(5);
    dsb1 = new QDoubleSpinBox(this);
    dsb1->setMinimum(-1);
    dsb1->setMaximum(1);
    dsb1->setSingleStep(0.001);
    dsb1->setDecimals(5);
    dsb2 = new QDoubleSpinBox(this);
    dsb2->setMinimum(-1);
    dsb2->setMaximum(1);
    dsb2->setSingleStep(0.001);
    dsb2->setDecimals(5);

    animationLayout->addWidget(new QLabel(vec_input_name->at(i)),i,0);
    animationLayout->addWidget(dsb0,i,1);
    animationLayout->addWidget(dsb1,i,2);
    animationLayout->addWidget(dsb2,i,3);
    dsb0->setValue(vec_input_values->at(i)[0]);
    dsb1->setValue(vec_input_values->at(i)[1]);
    dsb2->setValue(vec_input_values->at(i)[2]);
    }
    psb_accept = new QPushButton("Accept", this);

    psb_close  = new QPushButton("Close", this);
    psb_show  = new QPushButton("Show", this);
    animationLayout->addWidget(psb_accept,vec_input_values->size()+1,0);
    animationLayout->addWidget(psb_close,vec_input_values->size()+1,1);
    animationLayout->addWidget(psb_show,vec_input_values->size()+1,2);
    connect(psb_accept, SIGNAL(clicked()),this, SLOT(clickedAccept()));
    connect(psb_close, SIGNAL(clicked()),this, SLOT(clickedClose()));

    animationLayout->addWidget(&debug,vec_input_values->size()+1,3);



    this->setLayout(animationLayout);
}

void AnimationDialog::clickedClose()
{
    this->close();
}


void AnimationDialog::clickedAccept()
{
    list = this->findChildren<QDoubleSpinBox*>();
    vec_output_values->clear();

    for(int i = 0; i < list.size(); i+=3)
    {
    vec_output_values->push_back(glm::vec3(list.at(i)->value(),list.at(i+1)->value(), list.at(i+2)->value()));
    debug.setText(QString::number(vec_output_values->at(0)[0]));
    }
}
