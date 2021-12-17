#pragma once
#include"tinyxml2.h"
#include<string>
#include<vector>

namespace Pz_XmlManagement
{
	 
	struct MyXml_Attribute
	{
		std::string key;
		std::string value;
	};
	struct MyXml_Element
	{
		std::string name;
		std::vector< MyXml_Attribute >attribute;
		std::vector< MyXml_Element > sub_elements;
	};

	struct MyXml_Xml
	{
		std::string root_name;
		std::vector< MyXml_Attribute > root_attribute;
		std::vector< MyXml_Element > root_elements;
	};

	class XmlMaker
	{
		public:
		void MakeXml(std::string xmlPath, MyXml_Xml xml_doc);
		void add_subElements(tinyxml2::XMLDocument* doc,tinyxml2::XMLElement* cur_element,std::vector< MyXml_Element > sub_elements);
	};

};

