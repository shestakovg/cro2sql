/******************************************************************************
ProjectName: getopt
FileName: getopt.hpp  2008.12.01
Subj: Options parsing
Author: Nosov Yuri
*******************************************************************************
(C) Copyright 2008 Nosov Yuri (cro2sql@mail.ru)

  The contents of this file are subject to the License (the "License");
  you may not use this file except in compliance with the License.  You may
  obtain a copy of the License in the 'LICENSE' file which must have been
  distributed along with this file.

  This software, distributed under the License, is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See the
  License for the specific language governing rights and limitations
  under the License.
******************************************************************************/

#ifndef __GETOPT__
#define __GETOPT__ 1

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

/**
* \class CGetoptManager
* \brief �������� ���������� ���������� ������.
*
* �����-�������� ��������� ������ ������������ ������ ���������� ������, ��������� �� ������� ������, �������� � ����������� ����� ������ ���������.
* ������������� (� ���������� ������� ������� �������������� ����):
*   1. ������������ ��� ��������� ����� ���������� ������ � ������� �������-����� register_option.
*   2. � ����� (��� � GNU getopt) �������� �������-���� getopt �� ��� ���, ���� ��� �� ��������� -1, � ������������ ������������ ���� �������� �������� � �������� ���������� option
*
**/
class COptionsManager
{
public:

  /// ��������� ����� �� ����� ��������. ���� ��, ��, ������ ���� ���� ��������.
  typedef enum{
    NO_ARGUMENT,        //<! ����� �� ����� ���������.
    REQUIRED_ARGUMENT,  //<! ����� ������� ��������.
    OPTIONAL_ARGUMENT   //<! �������� ����� �������� ��������������.
  }ARGTYPE;

  /// ������������ ����� ���������� ������.
  void register_option(char short_name, string long_name, ARGTYPE argument_type, string description = "");
  /// ������������ ����� ���������� ������ � �������� ����� ���������� ����� �������� �� �������� ����� (�� GNU getopt). ��� int - �������� ��� ����������.
  void register_option(char short_name, string long_name, bool * flag, string description = "");

  /// ������������ ��������� ������� ���������� ������ (������� argv[])
  /**
  *  \retval int 0 - getopt �������� ������������������ ����, -1 � ������, ���� ��������� �����, '?' - ���� �������� �� �������� �������������� ������, ':' - ���� ����� �� ����� ���������.
  * ������� ������������ ��������� �� _cursor ��������. ���� ���������� ������ ���, getopt ������ -1. ���� �������� ���� � �� �������� ������, ������� �� ���� ����������������, ������� ��������� '?', ���� ����� ���� ����������������, ������� �������� �������� COptionsManager.option �� ��������� � vector �����.
  *   ���� � ����� ������ ���� ��������, �� �����������, getopt ������ ':'.
  *   ���� � ����� ���� ��������� ����������, ���������� �� �������� �����, ���� ������������ � getopt ���������� 0
  *   ���� getopt ����� ������������������ ����� ����� ��� ����� ���������� 1;
  **/
  int getopt(int argc, const char * argv[]);

  /// ����� ��������� ���������� ��������
  static COptionsManager * Instance();

  /// ���������� �������� ��� ������������������ �����, ����������� getopt �� ������ ����
  char current_short_name() const;
  /// ���������� ������� ��� ������������������ �����, ����������� getopt �� ������ ����
  string current_long_name() const;
  /// ���������� ��������� ������������������ �����, ����������� getopt �� ������ ���� � ����������� �� ���������� ������
  string current_arguments() const;

  /// ������������ �������� - ���������������� �� ����� � ������ �������� ������
  bool is_registered(char short_name);
  /// ������������ �������� - ���������������� �� ����� � ������ �������
  bool is_registered(string long_name);

  /// ������������� POSIX-style ��������� ����� "W" � true
  /**
  * �������� POSIX ����������� ����� -W ��� ������������� ��� ������������� ������������. ������� �� ����������� -W ������������ ����� ���������� ���������.
  * ���� posix_W ��������� � true, ������� getopt ������������� -Wlongopt ��� --longopt. �������������� -Wfile=myfile ��������������� ��� --file=myfile. ����������� posix_W ��������� � false � -W - ��������������� ��� ������� �����.
  **/
  void set_posix_W();

  /// ������� ������, ��� ����� �� ��������� getopt
  /**
  * ��� ������������������ ����� ��������. �������� ���������� (���� ���) posix_W. ������ ����������� ����� �� ��������.
  * \warning ������� �� ���������� ������������� getopt �����. ������������� ���� ������� ������������, ��� ���� ����������� ��� ������������
  **/
  void reset();

  /// ���������� ����� argv[], ������������ getopt ���������
  int cursor() const;

private:
  COptionsManager();
  /// ��������� ��������� ����� ���������� ������
  typedef struct{
    char short_name;                //<! �������� ��� �����
    string long_name;               //<! ������� ��� �����
    string description;             //<! �������� �����
    bool * flag;                    //<! ������ �� ����
    ARGTYPE argument_type;          //<! ��� ���������� �����
  }TOption;
  vector<TOption>::iterator option; //<! ��������� �� �������������� � ������ ������ �������� getopt �����
  vector<TOption> options;          //<! ������ �������� ��� ������������������ �����
  string _arguments;                //<! ��������� ������� �����
  bool _posix_W;                    //<! ���� - ��������� ������� ����� -W (�� set_posix_W())
  int _cursor;                      //<! ����� �������� ���������
  static COptionsManager * _instance;
  void _test_set_names(const char short_name, const string &long_name, const string &description, TOption &option);
  bool _test_unique(const char short_name);
  bool _test_long_optname(string str);
  bool _test_unique(const string &long_name);
  string _reminder;                 //<! ���������, getopt �������� �� � argv, � � _reminder
  string _all_short_names;          //<! ��� ����������� ����� � ����� ���� ������ ����������� �� �������� ���. ������ ������ ��� �������� ������ ���������������� �� ����� � ������ �������� ������.
  vector<string> _all_long_names;   //<! ��� ����������� ����� � ����� ����� ������� ����������� �� ������� ���. ������ ������ ��� �������� ������ ���������������� �� ����� � ������ ������� ������.
};


/**
*  \class getopt_error
*  �������� �����, ������������� ��� ����������.
**/
class getopt_error : public logic_error
{
public:
  getopt_error(string);
};

/**
*  \class registration_error
*  �������� �� ����������, ������������ ��� ����������� �����.
**/
class registration_error : public getopt_error
{
public:
  registration_error(string);
};

/**
*  \class parce_error
* �������� �� ����������, ������������ ��� ������� ���������� ������
**/
class parce_error : public getopt_error
{
public:
  parce_error(string);
};

#endif // __GETOPT__
