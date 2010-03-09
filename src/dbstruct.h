/******************************************************************************
ProjectName: cro2sql
FileName: dbstruct.h 20081225
Subj: ���������� ������, ���������� ��������� �� ����� CronosPlus � SQL-�� � �� ������������ (����������)
Author: Nosov Yuri
*******************************************************************************
  (c) Copyright 2008 Nosov Yuri (cro2sql@gmail.ru)

  The contents of this file are subject to the CPSQL License (the "License");
  you may not use this file except in compliance with the License.  You may
  obtain a copy of the License in the 'LICENSE' file which must have been
  distributed along with this file.

  This software, distributed under the License, is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See the
  License for the specific language governing rights and limitations
  under the License.
******************************************************************************/

#ifndef __DATABASE_STRUCT__
#define __DATABASE_STRUCT__ 1

#include <string>
#include <vector>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif // EXIT_SUCCESS
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif // EXIT_FAILURE
#ifndef EXIT_WARNING
#define EXIT_WARNING 2
#endif // EXIT_WARNING


class CTable;

/**
* \class Field
* \brief �����, ���������� ��������� ���� ����������� �� (�������������� ����� CronosPlus).
**/
class CField
{
	public:
    const char * TYPE_DIGITS;
    const char * TYPE_TEXT;
    const char * TYPE_DICTIONARY;
    const char * TYPE_DATE;
    const char * TYPE_TIME;
    const char * TYPE_FILE;
    const char * TYPE_TEMP_FILE;
    const char * TYPE_LINK_DIRECT;
    const char * TYPE_LINK_INVERSE;
    const char * TYPE_LINK_MULTY;
    const char * TYPE_SECURITY_LEVEL;
    CField() : TYPE_DIGITS("�\0"),
               TYPE_TEXT("�\0"),
               TYPE_DICTIONARY("�\0"),
               TYPE_DATE("�\0"),
               TYPE_TIME("�\0"),
               TYPE_FILE("�\0"),
               TYPE_TEMP_FILE("��\0"),
               TYPE_LINK_DIRECT("�\0"),
               TYPE_LINK_INVERSE("�\0"),
               TYPE_LINK_MULTY("��\0"),
               TYPE_SECURITY_LEVEL("��\0"){};
		std::string cro_name;       //!< ��������
    std::string link_to_base;   //!< ���� ���� ���������, ����������� ����������� ������ (����)
    std::string link_to_field;  //!< ���� ���� ���������, ����������� ����������� ������ (����)
    std::string sql_name;       //!< sql ���
    std::string number;         //!< �����
		std::string cro_type;       //!< ��� ������ cro
    std::string sql_type;       //!< ��� ������ sql
		std::string cro_length;     //!< ����� (�����������) cro, 0 - ���� ���
    std::string dict;           //!< ��� ��������� ������� (����)
		std::string attrib;         //!< �������������� �������� (� CronosPlus, ��������, ������ ��������������)
    bool flexible;              //!< ���� ����������� �������� ��������� � �������� ����
    CTable * table;             //!< ���� ����������� �������
    CField * operator=(CField * other);
};


class CDatabase;

/**
* \class Table
* \brief �����, ���������� ��������� ������� �� (���� ����� CronosPlus).
**/
class CTable
{
	public:
		std::string cro_name;           //!< �������� ������� (����) cro.
    std::string sql_name;           //!< �������� ������� (����) sql.
    std::string short_name;         //!< �������� ����.
    std::string number;             //!< ����� ����.
    std::string file;               //!< ��� �����, ����������� ������� ������ �� �������.
    CDatabase * _database;          //!< ������� ����������� ��
		std::vector<CField *> fields;   //!< ���� �������

    /// ���� ���� �� ��� cro �����, ��������� NULL, ���� �� �����
    CField * get_field_by_cro_name(std::string);
    /// ���� ���� �� ��� sql �����, ��������� NULL, ���� �� �����
    CField * get_field_by_sql_name(std::string);
    /// ���� ���� �� ��� ������, ��������� NULL, ���� �� �����
    CField * get_field_by_number(std::string);
    /// �������� �������� ���������� ������������� ���� �� ������ �������������. ���� ��� �� ����������, ���������� ������ ������.
    std::string modify_field_identificator(std::string);
    CTable() {};
    ~CTable();
private:
  CTable(CTable&);
  CTable& operator=(CTable& other);
};

/**
* \class Reference
* \brief �����, ���������� ��������� ����������� ��.
* \author Psycho
*
* ����� CronosPlus ����� �������� �� ����������� �� ������ ����������������. ������� ���� ����� ������������ � ����� ������ ��� ����������� ��������� (�������� ��� �������� ������� ��������).
* \copyright (c) 2008 psycho.ukcu@gmail.ru
**/
class CReference
{
	public:
    std::string sql_name;
	std::string cro_name;
    CTable * from;
    CTable * to;
};

/**
* \class CDatabase
* \brief ����� ���������� ��������� ����� ������ (���� ������).
**/
class CDatabase
{
	public:
		std::string name;                         //!< �������� ��
    std::string data_folder;                  //!< ���� � �����, � ������� ���������� ������� ������ ��
    const size_t MAX_TABIDENTLEN;             //!< ������������ ����� �������������� �������
    const size_t MAX_FIELDIDENTLEN;           //!< ������������ ����� �������������� ����
    const size_t MAX_VARCHAR;                 //!< ������������ ���������� �������� ��� ���� VARCHAR
    std::string separator;                    //!< ����������� ����� ������� � ������ ��������
		std::vector<CTable *>  tables;            //!< ������� �� (���� �����)
		std::vector<CReference *> references;     //!< ��������� ����� ��������� �� (������ ����� ������ �����)

    /// ���� ������� �� �� cro �����, ��������� NULL, ���� �� �������.
    CTable * get_table_by_cro_name(std::string);
    /// ���� ������� �� �� sql �����, ��������� NULL, ���� �� �������.
    CTable * get_table_by_sql_name(std::string);
    /// ���� ������� �� ���������, ��������� NULL, ���� �� �������.
    CTable * get_table_by_short_name(std::string);
    /// ���� ������ �� sql �����, ��������� NULL, ���� �� �������.
    CReference * get_ref_by_sql_name(std::string);
    ///
    std::string _translit_identifier(std::string str);
    /// �������� ������������ �������. ���� ���������� �������� ���������� ���, ���������� ������ ������
    std::string modify_tab_identificator(std::string);
    /// ������� ��������� �� �� �����. ���������� 0, ���� ������ �� ����, 1 ���� ���� ������ � 2, ���� ���� ��������������
    int read_from_file(std::string path, std::string name);
    /// ���������� ��������� ������
    std::string get_last_error() const {return error_msg;};
    /// ���������� ��������������� ������ �������������� ���������.
    std::string get_warnings();
    /// ���������� �� ��������� �� SQL DDL ���������
    std::string generate_DDL();
    const std::string ESCAPABLE;
    const std::string ESCAPE_SYMBOL;
    const char * TYPE_NUMBER;
    const char * TYPE_LONG;
    const char * TYPE_FLOAT;
    const char * TYPE_VARCHAR;
    const char * TYPE_CLOB;
    const char * TYPE_DATE;
    const char * TYPE_TIME;
    CDatabase(
      const size_t max_tab_identificator_len,   //!< ������������ ����� �������������� �������
      const size_t max_field_identificator_len, //!< ������������ ����� �������������� ����
      const size_t max_varchar_len,             //!< ������������ ����� ���� VARCHAR
      const char * escapable,                   //!< ������, ���������� �������, ������� ���������� ������������ (������ ������ ������)
      const char * escape_symbol,
      const char * integer_type,                //!< ���, ��������� ������� ����� �� 10 ������
      const char * long_type,                   //!< ���, ��������� ������� �� C++ long ��������
      const char * float_type,                  //!< ���, ��������� ������� ����� � ��������� ������
      const char * clob_type,                   //!< ���, ��������� ������� ������ ����� ������� �����
      const char * varchar_type,                //!< ���, ��������� ������� ������ �� max_varchar_len ������
      const char * date_type,                   //!< ���, ��������� ������� ����
      const char * time_type                    //!< ���, ��������� �������� �����
      ) :
      MAX_TABIDENTLEN(max_tab_identificator_len),
      MAX_FIELDIDENTLEN(max_field_identificator_len),
      MAX_VARCHAR(max_varchar_len),
      ESCAPABLE(escapable),
      ESCAPE_SYMBOL(escape_symbol),
      TYPE_NUMBER(integer_type),
      TYPE_LONG(long_type),
      TYPE_FLOAT(float_type),
      TYPE_VARCHAR(varchar_type),
      TYPE_CLOB(clob_type),
      TYPE_DATE(date_type),
      TYPE_TIME(time_type)
      {};
    /*
    // ��������� ������������ - MySQL
    CDatabase() : MAX_IDENTLEN(MAX_IDENTIFICATOR_LEN),
                  MAX_VARCHAR(2000),
                  ESCAPABLE("\\"),
                  TYPE_NUMBER("INTEGER\0"),
                  TYPE_LONG("LONG\0"),
                  TYPE_FLOAT("FLOAT\0"),
                  TYPE_CLOB("TEXT\0"),
                  TYPE_VARCHAR("VARCHAR\0"),
                  TYPE_DATE("DATE\0"),
                  TYPE_TIME("TIME\0")
                  {};*/

    ~CDatabase();
    /// ���������� true, ���� SQL-��� �������� 1 ��������� �� 2 false � ��������� ������
    bool is_extendable(std::string , std::string);
protected:
  /// �������� �� ������ ������ � ����. ��������� �������� - ���� �� �������������� SQL-��� ����
  int fetch_base_info(const std::string, CTable *, bool, size_t delim_count);
  /// �������� �� ������ ������ � ����. ��������� �������� - ���� �� �������������� SQL-��� ����
  /**
  * \return EXIT_SUCCESS ��� ���������� ��������� �������� (������������) ����. \
            EXIT_FAILURE ��� ������������� ����������� ������ (��� ��������� ���������� �� ��� ������������ get_last_error()), \
            EXIT_WARNING ��� ������������� ��������, � ������� ������ ���� ��������������� ������������ (��� ��������� �� ��� ���������� ������������ get_warnings()). \
            3 � ������, ���� ��������� ���� �������� ��������� ����
  **/
  int fetch_field_info(const std::string *, size_t &, CField *, CTable *, std::vector<CField *> *, bool);
  /// ��������� ������. ��� ������ ������� ��������������� ������� CReference
  int links_resolve(std::vector<CField *> * links);
  /// ���������� SQL ���, ������� ����� ��������� ��� ������� ����. �� ������ ��� ����������.
  std::string get_sql_type(CField *);
  // ����������� ����������� ��������
  CDatabase(CDatabase&) :
   MAX_TABIDENTLEN(0),
    MAX_FIELDIDENTLEN(0),
    MAX_VARCHAR(0),
    ESCAPABLE(""),
    ESCAPE_SYMBOL(0),
    TYPE_NUMBER(""),
    TYPE_LONG(""),
    TYPE_FLOAT(""),
    TYPE_VARCHAR(""),
    TYPE_CLOB(""),
    TYPE_DATE(""),
    TYPE_TIME("") {};
  // �������� ������������ ���������
  CDatabase& operator=(CDatabase& other);
  std::vector<std::string> warning_msgs;
  std::string error_msg;
};

#endif // __DATABASE_STRUCT__
