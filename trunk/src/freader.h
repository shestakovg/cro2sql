/******************************************************************************
ProjectName: freader
FileName: freader.h 20081203
Subj: "��������" fstream ��� ����������� �����c������ ���� �� ������������� �������.
Author: Nosov Yuri
*******************************************************************************
  (c) Copyright 2008 Nosov Yuri (cro2sql@gmail.com)

  The contents of this file are subject to the CPSQL License (the "License");
  you may not use this file except in compliance with the License.  You may
  obtain a copy of the License in the 'LICENSE' file which must have been
  distributed along with this file.

  This software, distributed under the License, is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See the
  License for the specific language governing rights and limitations
  under the License.
******************************************************************************/

#ifndef __FREADER_H__
#define __FREADER_H__

#include <fstream>
#include <string>

class CFileReader : public std::ifstream
{
public:
  CFileReader();
  CFileReader(std::string);
  // ������������� ����� �� ��� ���, ���� �� �������� str ��� end_symbol. ��� ������ ���������� str, ����������� �������������� ������, ������������ true. ���� ����������� end_symbol ������ ��� �� �����-�� ���� ������� ������ �� ������ ������������, ��������� false.
  bool skip_until(const std::string &str, const char end_symbol = 0);
  // ���� ��������� ���������� �� ������ ����� ��������� str, �� ���������� true, false - ���� �� ��������� ��� �������� end_symbol
  bool get_is_equal(const std::string &str, const char end_symbol = 0);
  // ������ ����� ����� �� ��� ��� ���� �� �������� delim ��� end_symbol
  std::string get_until(const std::string &delim, char end_symbol = 0);
};

#endif //__FREADER_H__
