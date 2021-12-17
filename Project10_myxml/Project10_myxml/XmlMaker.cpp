#include "XmlMaker.h"
#include<queue>
using namespace tinyxml2;
void Pz_XmlManagement::XmlMaker::MakeXml(std::string xmlPath, MyXml_Xml xml_doc)
{
    XMLDocument doc;
    doc.InsertFirstChild(doc.NewDeclaration());
    //set root name and attributes
    XMLElement* root = doc.NewElement(xml_doc.root_name.c_str());
    for (int i = 0; i < xml_doc.root_attribute.size(); i++)
    {
        root->SetAttribute(xml_doc.root_attribute[i].key.c_str(), xml_doc.root_attribute[i].value.c_str());
    }
    doc.InsertEndChild(root);
    //add elements by layers
    add_subElements(&doc,root, xml_doc.root_elements);   

    doc.SaveFile(xmlPath.c_str());
}

void Pz_XmlManagement::XmlMaker::add_subElements(tinyxml2::XMLDocument* doc,tinyxml2::XMLElement* cur_element,std::vector< MyXml_Element > sub_elements)
{
    for (int i_ele = 0; i_ele < sub_elements.size(); i_ele++)
    {
        //set name
        XMLElement* element = doc->NewElement(sub_elements[i_ele].name.c_str());
        //set attribute
        for (int i_attri = 0; i_attri < sub_elements[i_ele].attribute.size(); i_attri++)
        {
            element->SetAttribute(sub_elements[i_ele].attribute[i_attri].key.c_str(), sub_elements[i_ele].attribute[i_attri].value.c_str());
        }
        cur_element->InsertEndChild(element);
        //add sub elements
        add_subElements(doc,element, sub_elements[i_ele].sub_elements);
    }
}