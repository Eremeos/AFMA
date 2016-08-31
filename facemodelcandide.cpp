#include "facemodelcandide.h"
#include <algorithm>
#include <facecomponent.h>

FacemodelCandide::FacemodelCandide()
{

initializeVertices();
initializeIndices();
initializeColor();
initializeAnnotationText();


}

void FacemodelCandide::initializeVertices()
{
    vec_vertices.push_back(glm::vec3(0.000000f    ,1.061000f    ,-0.371000f  ));
    vec_vertices.push_back(glm::vec3(0.174000f    ,0.800000f    ,-0.024000f ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,0.539000f    ,0.085000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,0.278000f    ,0.107000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,0.213000f    ,0.085000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.222000f   ,0.210000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.265000f   ,0.124000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.417000f   ,0.142000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.526000f   ,0.150000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.591000f   ,0.107000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.852000f   ,0.063000f  ));
    vec_vertices.push_back(glm::vec3(0.217000f    ,1.039000f    ,-0.371000f ));
    vec_vertices.push_back(glm::vec3(0.457000f    ,0.909000f    ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(0.435000f    ,0.626000f    ,-0.111000f ));
    vec_vertices.push_back(glm::vec3(0.610000f    ,0.539000f    ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(0.522000f    ,0.278000f    ,-0.111000f ));
    vec_vertices.push_back(glm::vec3(0.391000f    ,0.374000f    ,0.0300000f ));
    vec_vertices.push_back(glm::vec3(0.130000f    ,0.278000f    ,0.107000f  ));
    vec_vertices.push_back(glm::vec3(0.391000f    ,0.322000f    ,0.0300000f ));
    vec_vertices.push_back(glm::vec3(0.304000f    ,0.225000f    ,-0.002000f ));
    vec_vertices.push_back(glm::vec3(0.470000f    ,0.148000f    ,-0.111000f ));
    vec_vertices.push_back(glm::vec3(0.304000f    ,0.204000f    ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(0.304000f    ,0.122000f    ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(0.130000f    ,0.148000f    ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(0.304000f    ,0.104000f    ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(0.109000f    ,-0.157000f   ,0.037000f  ));
    vec_vertices.push_back(glm::vec3(0.174000f    ,-0.244000f   ,0.037000f  ));
    vec_vertices.push_back(glm::vec3(0.387000f    ,-0.100000f   ,-0.045000f ));
    vec_vertices.push_back(glm::vec3(0.550000f    ,-0.250000f   ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(0.609000f    ,0.148000f    ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(0.470000f    ,-0.600000f   ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(0.246000f    ,-0.461000f   ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(0.174000f    ,-0.809000f   ,0.000000f  ));
    vec_vertices.push_back(glm::vec3(0.043000f    ,-0.396000f   ,0.150000f  ));
    vec_vertices.push_back(glm::vec3(-0.174000f   ,0.800000f    ,-0.024000f ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,0.539000f    ,0.085000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,0.278000f    ,0.107000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,0.213000f    ,0.085000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.222000f   ,0.210000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.265000f   ,0.124000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.461000f   ,0.124000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.526000f   ,0.150000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.591000f   ,0.107000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.852000f   ,0.063000f  ));
    vec_vertices.push_back(glm::vec3(-0.217000f   ,1.039000f    ,-0.371000f ));
    vec_vertices.push_back(glm::vec3(-0.457000f   ,0.909000f    ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(-0.435000f   ,0.626000f    ,-0.111000f ));
    vec_vertices.push_back(glm::vec3(-0.610000f   ,0.539000f    ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(-0.522000f   ,0.278000f    ,-0.111000f ));
    vec_vertices.push_back(glm::vec3(-0.391000f   ,0.374000f    ,0.030000f  ));
    vec_vertices.push_back(glm::vec3(-0.130000f   ,0.278000f    ,0.107000f  ));
    vec_vertices.push_back(glm::vec3(-0.391000f   ,0.322000f    ,0.030000f  ));
    vec_vertices.push_back(glm::vec3(-0.304000f   ,0.225000f    ,-0.002000f ));
    vec_vertices.push_back(glm::vec3(-0.470000f   ,0.148000f    ,-0.111000f ));
    vec_vertices.push_back(glm::vec3(-0.304000f   ,0.204000f    ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(-0.304000f   ,0.122000f    ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(-0.130000f   ,0.148000f    ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(-0.304000f   ,0.104000f    ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(-0.109000f   ,-0.157000f   ,0.037000f  ));
    vec_vertices.push_back(glm::vec3(-0.174000f   ,-0.244000f   ,0.037000f  ));
    vec_vertices.push_back(glm::vec3(-0.387000f   ,-0.100000f   ,-0.045000f ));
    vec_vertices.push_back(glm::vec3(-0.550000f   ,-0.250000f   ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(-0.609000f   ,0.148000f    ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(-0.470000f   ,-0.600000f   ,-0.328000f ));
    vec_vertices.push_back(glm::vec3(-0.246000f   ,-0.461000f   ,-0.000000f ));
    vec_vertices.push_back(glm::vec3(-0.174000f   ,-0.809000f   ,0.000000f  ));
    vec_vertices.push_back(glm::vec3(-0.043000f   ,-0.396000f   ,0.150000f  ));
    vec_vertices.push_back(glm::vec3(0.348000f    ,0.200000f    ,-0.0300000f));
    vec_vertices.push_back(glm::vec3(0.348000f    ,0.115000f    ,-0.0300000f));
    vec_vertices.push_back(glm::vec3(-0.348000f   ,0.200000f    ,-0.0300000f));
    vec_vertices.push_back(glm::vec3(-0.348000f   ,0.115000f    ,-0.0300000f));
    vec_vertices.push_back(glm::vec3(0.265000f    ,0.200000f    ,-0.0300000f));
    vec_vertices.push_back(glm::vec3(0.265000f    ,0.115000f    ,-0.0300000f));
    vec_vertices.push_back(glm::vec3(-0.265000f   ,0.200000f    ,-0.0300000f));
    vec_vertices.push_back(glm::vec3(-0.265000f   ,0.115000f    ,-0.0300000f));
    vec_vertices.push_back(glm::vec3(0.080000f   ,-0.220000f   ,0.150000f  ));
    vec_vertices.push_back(glm::vec3(-0.080000f   ,-0.220000f   ,0.150000f  ));
    vec_vertices.push_back(glm::vec3(0.022000f    ,0.213000f    ,0.063000f  ));
    vec_vertices.push_back(glm::vec3(-0.022000f   ,0.213000f    ,0.063000f  ));
    vec_vertices.push_back(glm::vec3(0.123000f    ,-0.410000f   ,0.063000f  ));
    vec_vertices.push_back(glm::vec3(-0.123000f   ,-0.410000f   ,0.063000f  ));
    vec_vertices.push_back(glm::vec3(0.100000f    ,-0.461000f   ,0.050000f  ));
    vec_vertices.push_back(glm::vec3(-0.100000f   ,-0.461000f   ,0.050000f  ));
    vec_vertices.push_back(glm::vec3(0.100000f    ,-0.461000f   ,0.050000f  ));
    vec_vertices.push_back(glm::vec3(-0.100000f   ,-0.461000f   ,0.050000f  ));
    vec_vertices.push_back(glm::vec3(0.123000f    ,-0.508000f   ,0.063000f  ));
    vec_vertices.push_back(glm::vec3(-0.123000f   ,-0.508000f   ,0.063000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,-0.461000f   ,0.124000f  ));
    vec_vertices.push_back(glm::vec3(0.200000f    ,-0.461000f   ,-0.024000f ));
    vec_vertices.push_back(glm::vec3(-0.200000f   ,-0.461000f   ,-0.024000f ));
    vec_vertices.push_back(glm::vec3(0.357000f    ,-0.461000f   ,-0.050000f ));
    vec_vertices.push_back(glm::vec3(-0.357000f   ,-0.461000f   ,-0.050000f ));
    vec_vertices.push_back(glm::vec3(0.065000f    ,0.028000f    ,0.050000f  ));
    vec_vertices.push_back(glm::vec3(-0.065000f   ,0.028000f    ,0.050000f  ));
    vec_vertices.push_back(glm::vec3(0.000000f    ,0.068000f    ,0.100000f  ));
    vec_vertices.push_back(glm::vec3(0.387000f    ,0.201000f    ,-0.056000f ));
    vec_vertices.push_back(glm::vec3(-0.387000f   ,0.201000f    ,-0.056000f ));
    vec_vertices.push_back(glm::vec3(0.387000f    ,0.186000f    ,-0.056000f ));
    vec_vertices.push_back(glm::vec3(-0.387000f   ,0.186000f    ,-0.056000f ));
    vec_vertices.push_back(glm::vec3(0.387000f    ,0.126000f    ,-0.056000f ));
    vec_vertices.push_back(glm::vec3(-0.387000f   ,0.126000f    ,-0.056000f ));
    vec_vertices.push_back(glm::vec3(0.387000f    ,0.117000f    ,-0.067000f ));
    vec_vertices.push_back(glm::vec3(-0.387000f   ,0.117000f    ,-0.067000f ));
    vec_vertices.push_back(glm::vec3(0.217000f    ,0.201000f    ,-0.013000f ));
    vec_vertices.push_back(glm::vec3(-0.217000f   ,0.201000f    ,-0.013000f ));
    vec_vertices.push_back(glm::vec3(0.217000f    ,0.186000f    ,-0.013000f ));
    vec_vertices.push_back(glm::vec3(-0.217000f   ,0.186000f    ,-0.013000f ));
    vec_vertices.push_back(glm::vec3(0.217000f    ,0.126000f    ,-0.013000f ));
    vec_vertices.push_back(glm::vec3(-0.217000f   ,0.126000f    ,-0.013000f ));
    vec_vertices.push_back(glm::vec3(0.217000f    ,0.117000f    ,-0.024000f ));
    vec_vertices.push_back(glm::vec3(-0.217000f   ,0.117000f    ,-0.024000f ));
    vec_vertices.push_back(glm::vec3(0.120000f    ,-0.265000f   ,0.100000f  ));
    vec_vertices.push_back(glm::vec3(-0.120000f   ,-0.265000f   ,0.100000f  ));

    vec_changed = vec_vertices;

    for(unsigned int i = 0; i < vec_vertices.size(); ++i)
    {
        vec_vertices[i].y -= 0.1f;
        vec_vertices_base.push_back(vec_vertices[i]);
    }






}

void FacemodelCandide::initializeColor()
{
    vec_color.push_back(glm::vec4(1,0,0,0.3f));
   for(unsigned int i = 0; i < vec_vertices.size(); ++i)
   {
       vec_color.push_back(glm::vec4(1,1,1,0.3f));
       vec_color_base.push_back(glm::vec4(1,1,1,0.3f));
   }
}

void FacemodelCandide::initializeIndices()
{
    vec_indices.push_back(glm::vec3(0   ,11  ,1  ));
    vec_indices.push_back(glm::vec3(0   ,1   ,34 ));
    vec_indices.push_back(glm::vec3(0   ,34  ,44 ));
    vec_indices.push_back(glm::vec3(11  ,12  ,1  ));
    vec_indices.push_back(glm::vec3(44  ,34  ,45 ));
    vec_indices.push_back(glm::vec3(1   ,12  ,13 ));
    vec_indices.push_back(glm::vec3(1   ,13  ,2  ));
    vec_indices.push_back(glm::vec3(1   ,2   ,34 ));
    vec_indices.push_back(glm::vec3(2   ,46  ,34 ));
    vec_indices.push_back(glm::vec3(34  ,46  ,45 ));
    vec_indices.push_back(glm::vec3(12  ,14  ,13 ));
    vec_indices.push_back(glm::vec3(13  ,14  ,15 ));
    vec_indices.push_back(glm::vec3(13  ,15  ,16 ));
    vec_indices.push_back(glm::vec3(2   ,13  ,16 ));
    vec_indices.push_back(glm::vec3(2   ,16  ,17 ));
    vec_indices.push_back(glm::vec3(2   ,17  ,3  ));
    vec_indices.push_back(glm::vec3(2   ,3   ,50 ));
    vec_indices.push_back(glm::vec3(2   ,50  ,49 ));
    vec_indices.push_back(glm::vec3(2   ,49  ,46 ));
    vec_indices.push_back(glm::vec3(46  ,49  ,48 ));
    vec_indices.push_back(glm::vec3(46  ,48  ,47 ));
    vec_indices.push_back(glm::vec3(45  ,46  ,47 ));
    vec_indices.push_back(glm::vec3(14  ,29  ,15 ));
    vec_indices.push_back(glm::vec3(15  ,29  ,20 ));
    vec_indices.push_back(glm::vec3(18  ,15  ,19 ));
    vec_indices.push_back(glm::vec3(18  ,16  ,15 ));
    vec_indices.push_back(glm::vec3(16  ,18  ,17 ));
    vec_indices.push_back(glm::vec3(17  ,18  ,19 ));
    vec_indices.push_back(glm::vec3(17  ,23  ,77 ));
    vec_indices.push_back(glm::vec3(3   ,17  ,77 ));
    vec_indices.push_back(glm::vec3(3   ,78  ,50 ));
    vec_indices.push_back(glm::vec3(78  ,56  ,50 ));
    vec_indices.push_back(glm::vec3(50  ,52  ,51 ));
    vec_indices.push_back(glm::vec3(49  ,50  ,51 ));
    vec_indices.push_back(glm::vec3(48  ,49  ,51 ));
    vec_indices.push_back(glm::vec3(48  ,51  ,52 ));
    vec_indices.push_back(glm::vec3(48  ,53  ,62 ));
    vec_indices.push_back(glm::vec3(47  ,48  ,62 ));
    vec_indices.push_back(glm::vec3(29  ,28  ,27 ));
    vec_indices.push_back(glm::vec3(20  ,29  ,27 ));
    vec_indices.push_back(glm::vec3(24  ,26  ,25 ));
    vec_indices.push_back(glm::vec3(57  ,58  ,59 ));
    vec_indices.push_back(glm::vec3(53  ,60  ,62 ));
    vec_indices.push_back(glm::vec3(62  ,60  ,61 ));
    vec_indices.push_back(glm::vec3(111 ,26  ,33 ));
    vec_indices.push_back(glm::vec3(75  ,26  ,111));
    vec_indices.push_back(glm::vec3(75  ,25  ,26 ));
    vec_indices.push_back(glm::vec3(76  ,59  ,58 ));
    vec_indices.push_back(glm::vec3(76  ,112 ,59 ));
    vec_indices.push_back(glm::vec3(112 ,66  ,59 ));
    vec_indices.push_back(glm::vec3(6   ,33  ,7  ));
    vec_indices.push_back(glm::vec3(6   ,7   ,66 ));
    vec_indices.push_back(glm::vec3(9   ,32  ,10 ));
    vec_indices.push_back(glm::vec3(9   ,10  ,65 ));
    vec_indices.push_back(glm::vec3(6   ,76  ,5  ));
    vec_indices.push_back(glm::vec3(6   ,5   ,75 ));
    vec_indices.push_back(glm::vec3(3   ,77  ,78 ));
    vec_indices.push_back(glm::vec3(7   ,33  ,79 ));
    vec_indices.push_back(glm::vec3(7   ,79  ,81 ));
    vec_indices.push_back(glm::vec3(7   ,81  ,87 ));
    vec_indices.push_back(glm::vec3(7   ,80  ,66 ));
    vec_indices.push_back(glm::vec3(7   ,82  ,80 ));
    vec_indices.push_back(glm::vec3(7   ,87  ,82 ));
    vec_indices.push_back(glm::vec3(80  ,82  ,89 ));
    vec_indices.push_back(glm::vec3(80  ,89  ,64 ));
    vec_indices.push_back(glm::vec3(79  ,88  ,81 ));
    vec_indices.push_back(glm::vec3(79  ,31  ,88 ));
    vec_indices.push_back(glm::vec3(26  ,79  ,33 ));
    vec_indices.push_back(glm::vec3(26  ,31  ,79 ));
    vec_indices.push_back(glm::vec3(59  ,66  ,80 ));
    vec_indices.push_back(glm::vec3(59  ,80  ,64 ));
    vec_indices.push_back(glm::vec3(88  ,83  ,85 ));
    vec_indices.push_back(glm::vec3(88  ,85  ,31 ));
    vec_indices.push_back(glm::vec3(83  ,8   ,85 ));
    vec_indices.push_back(glm::vec3(83  ,40  ,8  ));
    vec_indices.push_back(glm::vec3(8   ,40  ,84 ));
    vec_indices.push_back(glm::vec3(8   ,84  ,86 ));
    vec_indices.push_back(glm::vec3(86  ,89  ,84 ));
    vec_indices.push_back(glm::vec3(86  ,64  ,89 ));
    vec_indices.push_back(glm::vec3(9   ,85  ,8  ));
    vec_indices.push_back(glm::vec3(9   ,8   ,86 ));
    vec_indices.push_back(glm::vec3(32  ,85  ,31 ));
    vec_indices.push_back(glm::vec3(32  ,9   ,85 ));
    vec_indices.push_back(glm::vec3(65  ,86  ,64 ));
    vec_indices.push_back(glm::vec3(65  ,9   ,86 ));
    vec_indices.push_back(glm::vec3(27  ,26  ,24 ));
    vec_indices.push_back(glm::vec3(90  ,30  ,32 ));
    vec_indices.push_back(glm::vec3(90  ,32  ,31 ));
    vec_indices.push_back(glm::vec3(90  ,30  ,28 ));
    vec_indices.push_back(glm::vec3(90  ,26  ,31 ));
    vec_indices.push_back(glm::vec3(90  ,27  ,26 ));
    vec_indices.push_back(glm::vec3(90  ,28  ,27 ));
    vec_indices.push_back(glm::vec3(60  ,59  ,57 ));
    vec_indices.push_back(glm::vec3(91  ,65  ,63 ));
    vec_indices.push_back(glm::vec3(91  ,64  ,65 ));
    vec_indices.push_back(glm::vec3(91  ,61  ,63 ));
    vec_indices.push_back(glm::vec3(91  ,64  ,59 ));
    vec_indices.push_back(glm::vec3(91  ,59  ,60 ));
    vec_indices.push_back(glm::vec3(91  ,60  ,61 ));
    vec_indices.push_back(glm::vec3(92  ,77  ,23 ));
    vec_indices.push_back(glm::vec3(92  ,23  ,25 ));
    vec_indices.push_back(glm::vec3(92  ,25  ,75 ));
    vec_indices.push_back(glm::vec3(93  ,56  ,78 ));
    vec_indices.push_back(glm::vec3(93  ,76  ,58 ));
    vec_indices.push_back(glm::vec3(93  ,58  ,56 ));
    vec_indices.push_back(glm::vec3(94  ,77  ,92 ));
    vec_indices.push_back(glm::vec3(94  ,92  ,75 ));
    vec_indices.push_back(glm::vec3(94  ,75  ,5  ));
    vec_indices.push_back(glm::vec3(94  ,5   ,76 ));
    vec_indices.push_back(glm::vec3(94  ,76  ,93 ));
    vec_indices.push_back(glm::vec3(94  ,93  ,78 ));
    vec_indices.push_back(glm::vec3(94  ,78  ,77 ));
    vec_indices.push_back(glm::vec3(20  ,95  ,15 ));
    vec_indices.push_back(glm::vec3(20  ,97  ,95 ));
    vec_indices.push_back(glm::vec3(20  ,101 ,99 ));
    vec_indices.push_back(glm::vec3(20  ,27  ,101));
    vec_indices.push_back(glm::vec3(95  ,19  ,15 ));
    vec_indices.push_back(glm::vec3(95  ,21  ,19 ));
    vec_indices.push_back(glm::vec3(95  ,97  ,21 ));
    vec_indices.push_back(glm::vec3(101 ,27  ,24 ));
    vec_indices.push_back(glm::vec3(101 ,24  ,22 ));
    vec_indices.push_back(glm::vec3(101 ,22  ,99 ));
    vec_indices.push_back(glm::vec3(23  ,103 ,17 ));
    vec_indices.push_back(glm::vec3(23  ,105 ,103));
    vec_indices.push_back(glm::vec3(23  ,109 ,107));
    vec_indices.push_back(glm::vec3(23  ,25  ,109));
    vec_indices.push_back(glm::vec3(103 ,17  ,19 ));
    vec_indices.push_back(glm::vec3(103 ,19  ,21 ));
    vec_indices.push_back(glm::vec3(103 ,21  ,105));
    vec_indices.push_back(glm::vec3(109 ,107 ,22 ));
    vec_indices.push_back(glm::vec3(109 ,22  ,24 ));
    vec_indices.push_back(glm::vec3(109 ,24  ,25 ));
    vec_indices.push_back(glm::vec3(56  ,104 ,50 ));
    vec_indices.push_back(glm::vec3(56  ,106 ,104));
    vec_indices.push_back(glm::vec3(56  ,110 ,108));
    vec_indices.push_back(glm::vec3(56  ,58  ,110));
    vec_indices.push_back(glm::vec3(104 ,52  ,50 ));
    vec_indices.push_back(glm::vec3(104 ,54  ,52 ));
    vec_indices.push_back(glm::vec3(104 ,106 ,54 ));
    vec_indices.push_back(glm::vec3(110 ,55  ,108));
    vec_indices.push_back(glm::vec3(110 ,57  ,55 ));
    vec_indices.push_back(glm::vec3(110 ,58  ,57 ));
    vec_indices.push_back(glm::vec3(53  ,48  ,96 ));
    vec_indices.push_back(glm::vec3(53  ,98  ,96 ));
    vec_indices.push_back(glm::vec3(53  ,100 ,102));
    vec_indices.push_back(glm::vec3(53  ,102 ,60 ));
    vec_indices.push_back(glm::vec3(96  ,48  ,52 ));
    vec_indices.push_back(glm::vec3(96  ,52  ,54 ));
    vec_indices.push_back(glm::vec3(96  ,54  ,98 ));
    vec_indices.push_back(glm::vec3(102 ,100 ,55 ));
    vec_indices.push_back(glm::vec3(102 ,55  ,57 ));
    vec_indices.push_back(glm::vec3(102 ,57  ,60 ));
    vec_indices.push_back(glm::vec3(111 ,6   ,75 ));
    vec_indices.push_back(glm::vec3(111 ,33  ,6  ));
    vec_indices.push_back(glm::vec3(112 ,76  ,6  ));
    vec_indices.push_back(glm::vec3(112 ,6   ,66 ));
    vec_indices.push_back(glm::vec3(73  ,74  ,70 ));
    vec_indices.push_back(glm::vec3(73  ,70  ,69 ));
    vec_indices.push_back(glm::vec3(67  ,68  ,72 ));
    vec_indices.push_back(glm::vec3(67  ,72  ,71 ));
    vec_indices.push_back(glm::vec3(53  ,69  ,70 ));
    vec_indices.push_back(glm::vec3(56  ,74  ,73 ));
    vec_indices.push_back(glm::vec3(23  ,71  ,72 ));
    vec_indices.push_back(glm::vec3(20  ,68  ,67 ));
    vec_indices.push_back(glm::vec3(98  ,69  ,53 ));
    vec_indices.push_back(glm::vec3(54  ,69  ,98 ));
    vec_indices.push_back(glm::vec3(54  ,73  ,69 ));
    vec_indices.push_back(glm::vec3(54  ,106 ,73 ));
    vec_indices.push_back(glm::vec3(106 ,56  ,73 ));
    vec_indices.push_back(glm::vec3(56  ,108 ,74 ));
    vec_indices.push_back(glm::vec3(55  ,74  ,108));
    vec_indices.push_back(glm::vec3(55  ,70  ,74 ));
    vec_indices.push_back(glm::vec3(55  ,100 ,70 ));
    vec_indices.push_back(glm::vec3(100 ,53  ,70 ));
    vec_indices.push_back(glm::vec3(20  ,67  ,97 ));
    vec_indices.push_back(glm::vec3(97  ,67  ,21 ));
    vec_indices.push_back(glm::vec3(21  ,67  ,71 ));
    vec_indices.push_back(glm::vec3(21  ,71  ,105));
    vec_indices.push_back(glm::vec3(105 ,71  ,23 ));
    vec_indices.push_back(glm::vec3(20  ,99  ,68 ));
    vec_indices.push_back(glm::vec3(68  ,99  ,22 ));
    vec_indices.push_back(glm::vec3(22  ,72  ,68 ));
    vec_indices.push_back(glm::vec3(22  ,107 ,72 ));
    vec_indices.push_back(glm::vec3(107 ,23  ,72 ));

    for(unsigned int i = 0; i < vec_indices.size(); ++i)
    {
        vec_indices_ushort.push_back(vec_indices[i].x);
        vec_indices_ushort.push_back(vec_indices[i].y);
        vec_indices_ushort.push_back(vec_indices[i].z);
    }

}

void FacemodelCandide::initializeAnnotationText()
{
    vec_annotationText.push_back("Top of skull");
    vec_annotationText.push_back("Middle border between hair and forehead");
    vec_annotationText.push_back("Middle of forehead");
    vec_annotationText.push_back("Midpoint between eyebrows");
    vec_annotationText.push_back("Not used (replaced by 77 and 78 in CANDIDE-1)");
    vec_annotationText.push_back("Nose tip");
    vec_annotationText.push_back("Bottom middle edge of nose");
    vec_annotationText.push_back("Middle point of outer upper lip contour");
    vec_annotationText.push_back("Middle point of outer lower lip contour");
    vec_annotationText.push_back("Chin boss");
    vec_annotationText.push_back("Bottom of the chin");
    vec_annotationText.push_back("Left of top of skull");
    vec_annotationText.push_back("Left of top of skull");
    vec_annotationText.push_back("(Left border between hair and forehead)");
    vec_annotationText.push_back("Left side of skull");
    vec_annotationText.push_back("Outer corner of left eyebrow");
    vec_annotationText.push_back("Uppermost point of the left eyebrow");
    vec_annotationText.push_back("Inner corner of left eyebrow");
    vec_annotationText.push_back("Lower contour of the left eyebrow, straight under 16");
    vec_annotationText.push_back("Center of upper outer left eyelid");
    vec_annotationText.push_back("Outer corner of left eye");
    vec_annotationText.push_back("Center of upper inner left eyelid");
    vec_annotationText.push_back("Center of lower inner left eyelid");
    vec_annotationText.push_back("Inner corner of left eye");
    vec_annotationText.push_back("Center of lower outer left eyelid");
    vec_annotationText.push_back("Left nose border");
    vec_annotationText.push_back("Left nostril outer border");
    vec_annotationText.push_back("Left cheek bone");
    vec_annotationText.push_back("Inner contact point between left ear and face");
    vec_annotationText.push_back("Upper contact point between left ear and face");
    vec_annotationText.push_back("Left corner of jaw bone");
    vec_annotationText.push_back("Left corner of outer lip contour");
    vec_annotationText.push_back("Chin left corner");
    vec_annotationText.push_back("Uppermost point of left outer lip contour");
    vec_annotationText.push_back("(Middle border between hair and forehead)");
    vec_annotationText.push_back("Not used (identical to 2)");
    vec_annotationText.push_back("Not used (identical to 3)");
    vec_annotationText.push_back("Not used (identical to 4)");
    vec_annotationText.push_back("Not used (identical to 5)");
    vec_annotationText.push_back("Not used (identical to 6)");
    vec_annotationText.push_back("Middle point of inner lower lip contour");
    vec_annotationText.push_back("Not used (identical to 8)");
    vec_annotationText.push_back("Not used (identical to 9)");
    vec_annotationText.push_back("Not used (identical to 10)");
    vec_annotationText.push_back("Right of top of skull");
    vec_annotationText.push_back("Right of top of skull");
    vec_annotationText.push_back("Right border between hair and forehead)");
    vec_annotationText.push_back("Right side of skull");
    vec_annotationText.push_back("Outer corner of right eyebrow");
    vec_annotationText.push_back("Uppermost point of the right eyebrow");
    vec_annotationText.push_back("Inner corner of right eyebrow");
    vec_annotationText.push_back("Lower contour of the right eyebrow, straight under 49");
    vec_annotationText.push_back("Center of upper outer right eyelid");
    vec_annotationText.push_back("Outer corner of right eye");
    vec_annotationText.push_back("Center of upper inner right eyelid");
    vec_annotationText.push_back("Center of lower inner right eyelid");
    vec_annotationText.push_back("Inner corner of right eye");
    vec_annotationText.push_back("Center of lower outer right eyelid");
    vec_annotationText.push_back("Right nose border");
    vec_annotationText.push_back("Right nostril border");
    vec_annotationText.push_back("Right cheek bone");
    vec_annotationText.push_back("Lower contact point between right ear and face");
    vec_annotationText.push_back("Upper contact point between right ear and face");
    vec_annotationText.push_back("Right corner of jaw bone");
    vec_annotationText.push_back("Right corner of outer lip contour");
    vec_annotationText.push_back("Chin right corner");
    vec_annotationText.push_back("Uppermost point of right outer lip contour");
    vec_annotationText.push_back("Left iris, outer upper corner of bounding (square) box");
    vec_annotationText.push_back("Left iris, outer lower corner of bounding (square) box");
    vec_annotationText.push_back("Right iris, outer upper corner of bounding (square) box");
    vec_annotationText.push_back("Right iris, outer lower corner of bounding (square) box");
    vec_annotationText.push_back("Left iris, inner upper corner of bounding (square) box");
    vec_annotationText.push_back("Left iris, inner lower corner of bounding (square) box");
    vec_annotationText.push_back("Right iris, inner upper corner of bounding (square) box");
    vec_annotationText.push_back("Right iris, inner lower corner of bounding (square) box");
    vec_annotationText.push_back("Left side of nose tip");
    vec_annotationText.push_back("Right side of nose tip");
    vec_annotationText.push_back("Left upper edge of nose bone");
    vec_annotationText.push_back("Right upper edge of nose bone");
    vec_annotationText.push_back("Midpoint between FFP 8.4 and 8.1 on outer upper lip contour");
    vec_annotationText.push_back("Midpoint between FFP 8.3 and 8.1 on outer upper lip contour");
    vec_annotationText.push_back("Midpoint between FFP 2.2 and 2.5 on the inner upper lip contour");
    vec_annotationText.push_back("Midpoint between FFP 2.2 and 2.4 on the inner upper lip contour");
    vec_annotationText.push_back("Midpoint between FFP 2.3 and 2.5 on the inner lower lip contour");
    vec_annotationText.push_back("Midpoint between FFP 2.3 and 2.4 on the inner lower lip contour");
    vec_annotationText.push_back("Midpoint between FFP 8.4 and 8.2 on outer lower lip contour");
    vec_annotationText.push_back("Midpoint between FFP 8.3 and 8.2 on outer lower lip contour");
    vec_annotationText.push_back("Middle point of inner upper lip contour");
    vec_annotationText.push_back("Left corner of inner lip contour");
    vec_annotationText.push_back("Right corner of inner lip contour");
    vec_annotationText.push_back("Center of the left cheek");
    vec_annotationText.push_back("Center of the right cheek");
    vec_annotationText.push_back("Left lower edge of nose bone");
    vec_annotationText.push_back("Right lower edge of nose bone");
    vec_annotationText.push_back("Middle lower edge of nose bone (or nose bump)");
    vec_annotationText.push_back("Outer upper edge of left upper eyelid");
    vec_annotationText.push_back("Outer upper edge of right upper eyelid");
    vec_annotationText.push_back("Outer lower edge of left upper eyelid");
    vec_annotationText.push_back("Outer lower edge of right upper eyelid");
    vec_annotationText.push_back("Outer upper edge of left lower eyelid");
    vec_annotationText.push_back("Outer upper edge of right lower eyelid");
    vec_annotationText.push_back("Outer lower edge of left lower eyelid");
    vec_annotationText.push_back("Outer lower edge of right lower eyelid");
    vec_annotationText.push_back("Inner upper edge of left upper eyelid");
    vec_annotationText.push_back("Inner upper edge of right upper eyelid");
    vec_annotationText.push_back("Inner lower edge of left upper eyelid");
    vec_annotationText.push_back("Inner lower edge of right upper eyelid");
    vec_annotationText.push_back("Inner upper edge of left lower eyelid");
    vec_annotationText.push_back("Inner upper edge of right lower eyelid");
    vec_annotationText.push_back("Inner lower edge of left lower eyelid");
    vec_annotationText.push_back("Inner lower edge of right lower eyelid");
    vec_annotationText.push_back("Bottom left edge of nose");
    vec_annotationText.push_back("Bottom right edge of nose");
}

void FacemodelCandide::setFaceComponents()
{
    rightEyebrow.vec_reference_point.push_back(48);
    rightEyebrow.vec_reference_point.push_back(49);
    rightEyebrow.vec_reference_point.push_back(50);
    rightEyebrow.vec_reference_point.push_back(51);

    leftEyebrow.vec_reference_point.push_back(15);
    leftEyebrow.vec_reference_point.push_back(16);
    leftEyebrow.vec_reference_point.push_back(17);
    leftEyebrow.vec_reference_point.push_back(18);
}

void FacemodelCandide::upperLipraiser()
{
    std::vector<short> reference;
    std::vector<glm::vec3> lipraiser;

    reference.push_back(7);
    reference.push_back(33);
    reference.push_back(66);
    reference.push_back(79);
    reference.push_back(80);
    reference.push_back(81);
    reference.push_back(82);
    reference.push_back(87);
    reference.push_back(88);
    reference.push_back(89);


    lipraiser.push_back(glm::vec3(0.000000,    0.086957,    0.021739));
    lipraiser.push_back(glm::vec3(0.000000,    0.065217,    0.021739));
    lipraiser.push_back(glm::vec3(0.000000,    0.086957,    0.021739));
    lipraiser.push_back(glm::vec3(0.000000,    0.050000,    0.021739));
    lipraiser.push_back(glm::vec3(0.000000,    0.050000,    0.021739));
    lipraiser.push_back(glm::vec3(0.000000,    0.050000,    0.021739));
    lipraiser.push_back(glm::vec3(0.000000,    0.050000,    0.021739));
    lipraiser.push_back(glm::vec3(0.000000,    0.065217,    0.021739));
    lipraiser.push_back(glm::vec3(0.000000,    0.020000,    0.000000));
    lipraiser.push_back(glm::vec3(0.000000,    0.020000,    0.000000));

    for(unsigned int i = 0; i < lipraiser.size(); ++i)
    {
        lipraiser[i].x /=100;
        lipraiser[i].y /=100;
        lipraiser[i].z /=100;
    }

    for(unsigned int i = 0; i < reference.size(); ++i)
    {
      //  vec_changed[reference[i]].x += lipraiser[i].x;
    vec_changed[reference[i]].y -= lipraiser[i].y;
     //   vec_changed[reference[i]].z += lipraiser[i].z;

    }

}
