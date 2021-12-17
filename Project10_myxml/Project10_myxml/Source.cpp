#include"XmlMaker.h"

int main()
{
    Pz_XmlManagement::XmlMaker* xmlmaker = new Pz_XmlManagement::XmlMaker();
    std::string xmlPath = "./xmlfiles/setup.xml";
    Pz_XmlManagement::MyXml_Xml myxml_doc;
    //define name
    myxml_doc.root_name = "Root";
    //define attributes
    Pz_XmlManagement::MyXml_Attribute tmp_attri;
    tmp_attri.key = "Target";
    tmp_attri.value = "Map";
    myxml_doc.root_attribute.push_back(tmp_attri);
    //define elements
    Pz_XmlManagement::MyXml_Element tmp_ele;
    tmp_ele.name = "Map";
    //sub elements
    Pz_XmlManagement::MyXml_Element tmp_sub_ele;
    tmp_sub_ele.name = "ServerSetup";
    tmp_ele.sub_elements.push_back(tmp_sub_ele);

    myxml_doc.root_elements.push_back(tmp_ele);
    
    xmlmaker->MakeXml(xmlPath,myxml_doc);
    return 0;
}