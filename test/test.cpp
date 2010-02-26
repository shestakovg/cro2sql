/*
1. �������� ���� ��������� ���������� ���������� ������
   - �������� �������������� -m � -a
   - ��������������� -a, -m � -o
   - �������� ����
2. ���� ������
 �������� �����
   - ����������� ����� ����� � �������� �����
   - ���������� �������� �����
   - ����������� �������� ����� ��������� ���
 �������� ���
   - �������� ���������� ������������ � ��������
     - ������
     - ������
     - ������ ���
     - ���� ������
   - ����������� ����� ����� � ��������
   - �������� �������� ������ |
   - �������� �������� �����
   - ����� ����� �� �������� ������
   - 100 ��� � ����������� ���������� � "�������" �����������
 �������� �������������
   - � ��������� ���� ���� |
   - ����������� �������� ������������� �����-���� �� ���
   - ������� �������� ������������� ��� ��� ����� ���������� �� ������� �� ���������� � �������� �����
   - ��������� ���� ��������������
   - ��������� ���� �� ����� ������ ���� ���������
   - � ����� �� ��� ���� ��������� ���� �� ������, � � ��� ���.
   - ��������� ��������� �������� ���-�
   - �������� ����� �������� |
   - MAX_LEN+1 ������������� � ����������� ���������� ������ MAX_LEN
*/

#include <iostream>
#include <stdexcept>
#include "dbstruct.h"

using namespace std;

class CTestDatabase : public CDatabase
{
public:
  bool test0();
  bool test1();
  bool test2();
  bool test3();
  bool test4();
  bool test(int);
  CTestDatabase(
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
    ) : CDatabase(max_tab_identificator_len, max_field_identificator_len, max_varchar_len, escapable, escape_symbol, integer_type, long_type, float_type, clob_type, varchar_type, date_type, time_type)
    {};
};

bool CTestDatabase::test(int i)
{
  switch(i)
  {
  case 0: return test0();
  case 1: return test1();
  case 2: return test2();
  case 3: return test3();
  case 4: return test4();
  }
  return false;
}

bool CTestDatabase::test0()
{
  bool test = true;
  if(_translit_identifier("����") != "lico") test = false;
  if(_translit_identifier("�������� ��������") != "personal_stolovoi") test = false;
  if(_translit_identifier("1_����") != "lico") test = false;
  if(_translit_identifier("_��������*?��������'�����_1'") != "personal_stolovoi_nomer_1_") test = false;
  if(_translit_identifier("����������������������������������������������������") != "etupesnjunezadushishneubjeshnapoljankulesavilezpjaniiezh") test = false;
  if(_translit_identifier("_���������������������������������������������������") != "tupesnjunezadushishneubjeshnapoljankulesavilezpjaniiezh") test = false;
  return test;
}

// �������� ���
bool CTestDatabase::test1()
{
  string str[] = {
    "1|��|��|��|1|0||2",
    "1|����|��|1|0|2",
    "1||||����|�|�|1|0|2",
    "����",
    "1|��|��|�||1|0||2",
    "1|����|5||1|0||2",
    "��_�����|����|��|1|0||2"
  };
  for(size_t i=0; i < 7; i++)
  {
    CTable * tab = new CTable();
    if( !tab )
      throw runtime_error("Memory allocation error");
    int result;
    warning_msgs.clear();
    error_msg.clear();
    result = fetch_base_info(str[i], tab, false, 7);
    switch(i)
    {
    case 0: 
      if (result != EXIT_SUCCESS || tab->cro_name != "��|��" || tab->short_name != "��" || tab->number != "1" || tab->file != "1.txt") 
        return false;
      break;
    case 1:
      if (result != EXIT_FAILURE || error_msg != "�������� �������� ���������, ���� ����� ����." )
        return false;
      break;
    case 2:
      if (result != EXIT_FAILURE || error_msg != "�������� �������� ���������, ���� ����� ����." )
        return false;
      break;
    case 3:
      if (result != EXIT_FAILURE || error_msg != "�������� �������� ����, ������������ � \"����\"." )
        return false;
      break;
    case 4:
      if (result != EXIT_SUCCESS || tab->cro_name != "��|��" || tab->short_name != "�|" || tab->number != "1" || tab->file != "1.txt")
        return false;
      break;
    case 5:
      if (result != EXIT_SUCCESS || tab->cro_name != "����" || tab->short_name != "5|" || tab->number != "1" || tab->file != "1.txt") 
        return false;
      break;
    case 6:
      if (result != EXIT_FAILURE || error_msg != "�������� ��� ��� ����������� ������ � ���� \"N\": \"��_�����\"")
        return false;
      break;    
    }
    delete tab;
  }
  return true;
}

// �������� ���
bool CTestDatabase::test2()
{
  string str[] = {
    "1|��|��|��|1|0||2|Person",
    "1|����|��|1|0||2",
    "1||||����|�|�|1|0|2",
    "����|ID",
    "1|��|��|�||1|0||2|123",
    "1|����|5||1|0||2||",
    "��_�����|����|��|1|0||2|Person"
  };
  for(size_t i=0; i < 7; i++)
  {
    CTable * tab = new CTable();
    if( !tab )
      throw runtime_error("Memory allocation error");
    int result;
    warning_msgs.clear();
    error_msg.clear();
    // N|�������� ����|���|���|���-�� �������|���� ����|���-�� �������|SQL ���
    result = fetch_base_info(str[i], tab, true, 7);
    switch(i)
    {
    case 0: 
      if (result != EXIT_SUCCESS || tab->cro_name != "��|��" || tab->short_name != "��" || tab->number != "1" || tab->file != "1.txt" || tab->sql_name != "Person") 
        return false;
      break;
    case 1:
      if (result != EXIT_FAILURE || error_msg != "�������� �������� ���������, ���� ����� ����." )
        return false;
      break;
    case 2:
      if (result != EXIT_FAILURE || error_msg != "�������� �������� ���������, ���� ����� ����." )
        return false;
      break;
    case 3:
      if (result != EXIT_FAILURE || error_msg != "�������� �������� ����, ������������ � \"����|ID\"." )
        return false;
      break;
    case 4:
      if (result != EXIT_FAILURE || error_msg != "�������� ��� ������ � ���� \"SQL ���\": \"123\"")
        return false;
      break;
    case 5:
      if (result != EXIT_WARNING || warning_msgs.back() != "�������� ���� \"����|5\" ����� ������, ������� ����� ������� �������� ���������� �� ��� ������." || tab->cro_name != "����|5" || tab->short_name != "|1" || tab->number != "1" || tab->file != "1.txt") 
        return false;
      break;
    case 6:
      if (result != EXIT_FAILURE || error_msg != "�������� ��� ��� ����������� ������ � ���� \"N\": \"��_�����\"")
        return false;
      break;    
    }
    delete tab;
  }
  return true;
}

bool CTestDatabase::test3()
{
  string str[] = {
    "1|�������|�|10000||��|",
    "1|�����|��|�|10000||��|",
    "1|�����||||��|�|10000||��|",
    "1|�����|��|�|10000||��|�|2",
    "1|�����|��|�|10000||��|6|2",
    "1|�����|��|�|10000||��||62",
    "1|�����|��|�|10000||��|622"
  };
  for(size_t i = 0; i < 7; i++)
  {
    CField * field = new CField();
    CTable * tab = new CTable();
    field->table = tab;
    tab->_database = this;
    vector<CField *> list;
    if( !tab || !field)
      throw runtime_error("Memory allocation error");
    int result;
    warning_msgs.clear();
    error_msg.clear();
    size_t cursor = 0;
    result = fetch_field_info(&str[i], cursor, field, tab, &list, false);
    switch(i)
    {
    case 0: 
      if ( result != EXIT_SUCCESS || field->number != "1" || field->cro_name != "�������" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_name != "familija") 
        return false;
      break;
    case 1: 
      if ( result != EXIT_SUCCESS || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_name != "familija") 
        return false;
      break;
    case 2: 
      if ( result != EXIT_SUCCESS || field->number != "1" || field->cro_name != "�����||||��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_name != "familija") 
        return false;
      break;
    case 3: 
      if ( result != 3 || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_name != "familija" || field->link_to_base != "�|" || field->link_to_field != "2") 
        return false;
      break;
    case 4: 
      if ( result != 3 || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_name != "familija" || field->link_to_base != "6|" || field->link_to_field != "2") 
        return false;
      break;
    case 5: 
      if ( result != 3 || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_name != "familija" || field->link_to_base != "|6" || field->link_to_field != "2") 
        return false;
      break;
    case 6: 
      if ( result != 3 || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_name != "familija" || field->link_to_base != "62" || field->link_to_field != "2") 
        return false;
      break;
    }
    delete tab;
    delete field;
  }
  return true;
}

bool CTestDatabase::test4()
{
  string str[] = {
    "1|�������|�|10000||��||SIRNAME|",
    "1|�����|��|�|10000||��||SIRNAME|VARCHAR(50)",
    "1|�����||||��|�|10000||��|||VARCHAR(50)",
    "1|�����|��|�|10000||��|�|2|SIR_NAME|",
    "1|�����|��|�|10000||��|6|2||INTEGER",
    "1|�����|��|�|10000||��||62||TEXT",
    "1|�����|��|�|10000||��|622||"
  };
  for(size_t i = 0; i < 7; i++)
  {
    CField * field = new CField();
    CTable * tab = new CTable();
    field->table = tab;
    tab->_database = this;
    vector<CField *> list;
    if( !tab || !field)
      throw runtime_error("Memory allocation error");
    int result;
    warning_msgs.clear();
    error_msg.clear();
    size_t cursor = 0;
    result = fetch_field_info(&str[i], cursor, field, tab, &list, true);
    switch(i)
    {
    case 0: 
      if ( result != EXIT_SUCCESS || field->number != "1" || field->cro_name != "�������" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_type != "" || field->sql_name != "SIRNAME") 
        return false;
      break;
    case 1: 
      if ( result != EXIT_SUCCESS || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->attrib != "��" || field->dict != "" || field->flexible != false || field->sql_type != "VARCHAR" || field->cro_length != "50" || field->sql_name != "SIRNAME") 
        return false;
      break;
    case 2: 
      if ( result != EXIT_SUCCESS || field->number != "1" || field->cro_name != "�����||||��" || field->cro_type != "�" || field->attrib != "��" || field->dict != "" || field->flexible != false || field->sql_type != "VARCHAR" || field->cro_length != "50"|| field->sql_name != "familija") 
        return false;
      break;
    case 3: 
      if ( result != 3 || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->link_to_base != "�|" || field->link_to_field != "2" || field->flexible != true || field->sql_type != "" || field->sql_name != "SIR_NAME") 
        return false;
      break;
    case 4: 
      if ( result != 3 || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != false || field->sql_name != "familija" || field->link_to_base != "6|" || field->link_to_field != "2" || field->sql_type != "INTEGER" ) 
        return false;
      break;
    case 5: 
      if ( result != 3 || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != false || field->sql_name != "familija" || field->link_to_base != "|6" || field->link_to_field != "2" || field->sql_type != "TEXT" ) 
        return false;
      break;
    case 6: 
      if ( result != 3 || field->number != "1" || field->cro_name != "�����|��" || field->cro_type != "�" || field->cro_length != "10000" || field->attrib != "��" || field->dict != "" || field->flexible != true || field->sql_name != "familija" || field->link_to_base != "62" || field->link_to_field != "2" || field->sql_type != "" ) 
        return false;
      break;
    }
    delete tab;
    delete field;
  }
  return true;
}

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif // EXIT_SUCCESS
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif // EXIT_FAILURE
#ifndef EXIT_WARNING
#define EXIT_WARNING 2
#endif // EXIT_WARNING

int main()
{
  CTestDatabase TestDatabase(20, 30, 4000, "'", "'", "INTEGER\0", "LONG\0", "FLOAT\0", "TEXT\0", "VARCHAR\0", "DATE\0", "TIME\0");

  for(int i=0; i < 5; i++)
    if( TestDatabase.test(i) )
      cout << "OK : Test #" << i << endl;
    else
      cout << "ERR: Test #" << i << endl;
  return 0;
}
