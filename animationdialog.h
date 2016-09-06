#ifndef ANIMATIONDIALOG_H
#define ANIMATIONDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <vector>
#include <glm/glm.hpp>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>

class AnimationDialog : public QDialog
{
    Q_OBJECT
public:
    AnimationDialog(std::vector<QString> &vec_faceComponent_name, std::vector<glm::vec3> &vec_faceComponent_values, std::vector<glm::vec3> &vec_outputFaceComponent_values);
    QGridLayout *animationLayout;
    std::vector<QString> *vec_input_name;
    std::vector<glm::vec3> *vec_input_values;
    std::vector<glm::vec3> *vec_output_values;
    QList<QDoubleSpinBox*> list;
    QLabel debug;
    QPushButton *psb_accept;
    QPushButton *psb_close;
    QDoubleSpinBox *dsb0;
    QDoubleSpinBox *dsb1;
    QDoubleSpinBox *dsb2;
public slots:
    void clickedAccept();
    void clickedClose();
};

#endif // ANIMATIONDIALOG_H
