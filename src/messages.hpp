/******************************************************************************
ProjectName: cro2sql
FileName: messages.hpp
Subj: �������� ���������, ���������� �������� ������� ���������.
Author: Nosov Yuri
*******************************************************************************
  (c) Copyright 2008 Nosov Yuri (cro2sql@ggmail.com)

  The contents of this file are subject to the cro2sql License (the "License");
  you may not use this file except in compliance with the License.  You may
  obtain a copy of the License in the 'LICENSE' file which must have been
  distributed along with this file.

  This software, distributed under the License, is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See the
  License for the specific language governing rights and limitations
  under the License.
******************************************************************************/

#ifndef __MESSAGES__
#define __MESSAGES__ 1


#include <string>

// OD - Option description
const char * OD_MODE =          "��⠭����� ���� � ���䨣��樮����� 䠩�� (�. ���䨣��樮��� 䠩�).";
const char * OD_AUTO =          "��⠭����� ���� � 䠩�� ��ᯮ�� ᯨ᪠ ������ ������ ����� CronosPlus � ��� �࠭᫨�㥬��� ����� ������, ࠧ������� \";\".";
const char * OD_OUTPUT =        "���࠭��� 䠩�� � SQL-��ࠦ���ﬨ � 㪠������ �����.";
const char * OD_SILENT =        "�� �뤠���� ��祣� � �⠭����� ��⮪ �뢮��.";
const char * I_HEADER =         "cro2sql - �࠭���� ������ ������ �� ��ᯮ�� ����� CronosPlus � SQL\n�� �ࠢ� ���饭� (c) ��ᮢ �਩ (hoxnox@gmail.com)";
const char * I_FOOTER =         "��ᯮ������ -h ��� --help ��� ����祭�� �ࠢ��";
const char * E_AUTO_MANUAL =    "�ᯮ�짮����� ���祩 -m (--manual) � -a (--auto) �����६���� ����饭�";
const char * E_UNKNOWN_OPT =    "�������⭠� ����";
const char * E_OPT =            "�� �� ��易⥫�� ��ࠬ���� �뫨 ���������.";
const char * E_WRONG_ARG =      "������ ���㬥�� ��樨";
const char * E_PARSE_ERROR =    "�������� �訡�� �� ࠧ��� 䠩��, ᮤ�ঠ饣� ���ଠ�� � ������� �࠭᫨�㥬��� ����� ������.\n����饭�� �����: ";
const char * E_DATA_PARSE =     "�������� �訡�� �� ࠧ��� 䠩�� ������. ����饭�� ����� ������ : ";
const char * E_FILE_NOT_FOUND = "���� �� ������.";
const char * E_FILE_OPEN_ERROR ="�訡�� �� ����⨨ 䠩�� ����ன�� ��� ����";
const char * E_TUNE_FILE =      "���� ����ன�� ���� ����� ���ࠢ����� ��������";
const char * E_EXT_LINES_RANGE ="����୮� ���祭�� ��ࠬ��� -m (--extended).";
const char * E_LIST_ERROR =     "�����㦥�� �訡�� � 䠩��, ᮤ�ঠ騬 ���ଠ�� � ������� �࠭᫨�㥬��� ����� ������:\n";
const char * E_PREFIX =         "ERROR  : ";
const char * W_PREFIX =         "WARNING: ";
const char * M_PREFIX =         "         ";


string GetFullHelp()
{
  stringstream output;
  output << "CRO2SQL(1)                                                           CRO2SQL(1)\n\
\n\
(c) 2008 ��ᮢ �਩ ����ᠭ�஢�� (hoxnox@gmail.com)\n\
�� ������ �� ࠡ�� �ਫ������ ���ࠢ���� cro2sql@gmail.com\n\
\n\
NAME\n\
  cro2sql - �࠭���� ������ ������ �� ��ᯮ�� ����� CronosPlus � SQL\n\
\n\
SYNOPSIS\n\
  cro2sql [-d<sep>|-t<conf>|-m<count>|-s] -c<struct_file>[;<bank_name>] \n\
          -e<data> -o<path>\n\
    struct_file - ���� � 䠩��, ᮤ�ঠ饬� ���ᠭ�� �������� ����� ������.\n\
                  ���஡��� ᬮ�� ����, � ࠧ���� \"����,  ᮤ�ঠ騩 ��������\n\
                  ����� ������\".\n\
    bank_name   - �  ��砥,  �᫨  䠩�,  ᮤ�ঠ騩  ��������  �����  ������\n\
                  ����뢠�� ��᪮�쪮 ������ ������  (���� ��ᯮ�⮬ ᯨ᪠\n\
                  ������  ������ ��  ����� CronosPlus),  ����室��� 㪠���� ���\n\
                  �����, ����� ᮡ�ࠥ��� �࠭᫨஢���.\n\
    data_exp    - ���� �  �����,  ᮤ�ঠ饩  䠩��  ��ᯮ��  ������  �� �����\n\
                  CronosPlus.\n\
    \n\
DESCRIPTION\n\
  ��騥 ᢥ����� \n\
    �࠭���� cro2sql  �㦨� ��� ����ண�  �८�ࠧ������ ����� ������  �����\n\
    CronosPlus  � ५�樮���� ���� ������ �ଠ� SQL. �� �室 cro2sql ��������\n\
    ���ଠ��  �  �������  �����  ������  �ଠ�  ����� CronosPlus �  䠩��\n\
    ��ᯮ��  ������ (����祭��  � ������� �㭪樮���쭮��  \"��ᯮ�� � ⥪��\"\n\
    �����).   �࠭����  ��  �᭮��  ���ଠ樨  �  �������  ��������  SQL\n\
    ������樨, � ������� ������ � ५�樮���� ����  �����  ����⠭�����  ����\n\
    ������.\n\
\n\
  ����, ᮤ�ঠ騩 �������� ����� ������.\n\
    �।�⠢��� ᮡ�� txt-䠩� � ����஢�� windows-1251,  ᮤ�ঠ騩  ᢥ�����\n\
    �  �������  ����� ������. ��ଠ�  䠩��  ᮮ⢥�����  �ଠ��  ��ᯮ��\n\
    ᯨ᪠ ������ �� ����� CronosPlus, ᮤ�ঠ饣� ��� ������:\n\
      ������������ �����, \n\
      ���祭� ���, �� ᢮��⢠,\n\
      ���祭� �����, �� ᢮��⢠.\n\
    ��� ����祭�� ��������� 䠩��,  ᫥���  �  ����� CronosPlus �����  ����:\n\
    ����=>\"���᮪ 䠩���\".  � ���襬�� ����  ������ ������  \"� ⥪�� ...\". �\n\
    ���襬�� ����, �⬥��� ����窠�� �⢥�����騥 �㭪��,  㪠����  ����\n\
    � ����  \"���� ����\" � ������ �믮�����.  ����, ᮤ�ঠ騩 �������� �����\n\
    ������ �㤥� ᣥ���஢��.  �࠭���� ���  ���������� ⠡��� � ����� �㤥�\n\
    �ᯮ�짮����   ��������  ᮮ⢥�������  ���  �  �����   ����� CronosPlus.\n\
    �������  �����������  ������  ᢮�  ��������  ���  �  �����  - � ࠧ���\n\
    \"��ࠢ����� �࠭��樥�\".\n\
      \n\
      �ਬ�� 䠩�� ��������:\n\
      ******************����ঠ��� 䠩�� �������� �����***********************\n\
        ������������ �����:  ���⮢� ����\n\
\n\
\n\
        ���᮪ ���:\n\
        N|�������� ����|���|���|���-�� ����஢|���� ����|���-�� ����ᥩ\n\
        1|���|��|1|0||223\n\
        2|����|��|1|0||142\n\
\n\
        ����  :���\n\
        ���⠢ ����� ����\n\
        N ����| �������� ����|���|����� ����|�������|�����|���� � ������\n\
        0|���⥬�� �����|�|10|||\n\
        6|���|�||���||\n\
        1|�������|�|100000|||\n\
        2|���|�|100000|||\n\
        3|����⢮|�|100000|||\n\
        4|���� ��⥫��⢠|�|||��|��2\n\
\n\
\n\
        ==========================\n\
\n\
        ����  :����\n\
        ���⠢ ����� ����\n\
        N ����| �������� ����|���|����� ����|�������|�����|���� � ������\n\
        0|���⥬�� �����|�|10|||\n\
        1|��த|�|100000|||\n\
        2|�஦�����|�|||��|��4\n\
      *************************************************************************\n\
  \n\
  �࠭����.\n\
    1. �८�ࠧ������ �����䨪��஢.\n\
      - �ਢ������ � ������� ॣ�����\n\
      - ������ ��� ᨬ�����, �⫨��� �� ���, ᨬ����� ������� ॣ���� \n\
        ��⨭᪮�� ��䠢�� � ᨬ���� \"_\" �� ᨬ���� \"_\"\n\
      - ᢮�稢���� ����������� ᨬ����� \"_\"\n\
      - ������ ᨬ����� ��ਫ���� ��⨭��楩 �� �ࠢ����:\n\
         '�'=\"a\"  '�'=\"e\"   '�'=\"m\" '�'=\"t\"   '�'=\"sh\"  '�'=\"yu\"\n\
         '�'=\"b\"  '�'=\"zh\"  '�'=\"n\" '�'=\"u\"   '�'=\"sh\"  '�'=\"ya\"\n\
         '�'=\"v\"  '�'=\"z\"   '�'=\"o\" '�'=\"f\"   '�'=\"j\"\n\
         '�'=\"g\"  '�'=\"i\"   '�'=\"p\" '�'=\"h\"   '�'=\"i\"\n\
         '�'=\"d\"  '�'=\"k\"   '�'=\"r\" '�'=\"c\"   '�'=\"j\"\n\
         '�'=\"e\"  '�'=\"l\"   '�'=\"s\" '�'=\"ch\"  '�'=\"e\"\n\
      - 㤠�����  (�� ��砫�) ���  ᨬ�����,  �⫨��� �� ᨬ�����  ��⨭᪮��\n\
        ��䠢��.\n\
      - � ��砥, �᫨ �८�ࠧ������ ����������, �ᯮ��㥬 \"invalid_name\"\n\
      ���������:\n\
        � �� �����, ����� ����室��� �������� 㭨���쭮�� ����, �ਬ������\n\
        ᫥���騩 ��⮤:\n\
          �᫨ �������� �����, �����뢠�� ������ _N ��� N.\n\
          �᫨ ����� �� ��������,���塞 ��᫥���� ᨬ���� �����䨪��� �� N.\n\
          � ��砥, �᫨ ����稢訩�� �����䨪��� 㦥 �ᯮ������, \n\
          㢥��稢��� N.\n\
            N - ��ப� ᨬ�����,ᮤ�ঠ�� ���� � ᨬ���� ��⨭᪮�� ��䠢��.\n\
            ������� �� 㢥��稢����� ��ࠧ��:\n\
            0, 1, ... , 9, a, b, ..., z, 10, 11, ..., 19, 1a, ..., 1z, 2z, ...\n\
    2. �८�ࠧ������ ⨯��\n\
      ��������  ����⢥���  ࠧ����  �����  ॠ�����ﬨ �⠭���� SQL'99.\n\
      ��㬮�砭�� �� ��࠭ �⠭����, �ᯮ��㥬� MySQL.  �८�ࠧ������ ⨯�\n\
      ���������筮 � ������ �� ������.\n\
        � - VARCHAR ��� TEXT\n\
        � - INTEGER ��� FLOAT\n\
      ��� ������⢥���� ����� ��ந��� �������⥫쭠� ⠡���, ᫥���饣� ����:\n\
        ���: mv_<��� ⠡����>_<��� ����>\n\
        ����� ��� ����: id -  �᫮���  ⨯ �  value -  ⨯ ������⢥����� ����\n\
        ����� CronosPlus.  ������  ��  ���祭��  ������⢥�����  ���� ��������\n\
        � ��ᬮ�७���  ��� �������⥫���  ⠡����, id ��� ����ᥩ �������\n\
        � ⠡���� SQL.\n\
        ���ਬ��:\n\
          ���                                  person\n\
          ���: ������                           name: ������\n\
          �ࠦ����⢮: �����;��ଠ���          citizenship: 1\n\
                                                �������⥫쭠� ⠡���:\n\
                                                mv_person_citizenship\n\
                                                id: 1 value: �����\n\
                                                id: 1 value: ��ଠ���\n\
    3. �८�ࠧ������ �痢�\n\
      �� �裡 ����� CronosPlus, �� ४��������  ࠧࠡ��稪�,  ������  ����\n\
      ������⢥��묨, ���⮬� ��  ᮮ⢥�����騥  �裡 SQL ����  \"������ ��\n\
      ������\".  ���� �����⥫��.  �࠭���� �����  �����४⭮  ࠡ����  �\n\
      ������, ��������� ������ ᮤ�ঠ� ᨬ���� \"|\".\n\
      \n\
  ��ࠢ����� �࠭��樥�.\n\
    � �����, ����� ����室���  ��।�����  ��������  ���  ⨯� ⠡��� � �����\n\
    ������, ����� �������� 䠩� �������� ᫥���騬 ��ࠧ��:\n\
    � ���ᠭ�� ��� �������� � ��������� \"SQL ���\", � �������� ���ᠭ��. \n\
      �ਬ��:\n\
        N|�������� ����|���|���|���-�� ����஢|���� ����|���-�� ����ᥩ|SQL ���\n\
        1|���|��|1|0||223|person\n\
        2|����|��|1|0||142|\n\
      � ������ ��砥,  ᮮ⢥������� ⠡��� ��� ���� \"���\" �㤥� ����� ���\n\
      \"person\", � ��� ���� \"����\" ��� �㤥� ����祭� � ��⮬���᪮� ०���.\n\
    �������筮 ��� �����.:\n\
        ����  :���\n\
        ���⠢ ����� ����\n\
        N ����| �������� ��        ...     ����|SQL ���|SQL ⨯\n\
        0|���⥬�� �����|�|10|||ID|INTEGER\n\
        6|���|�||���||SEX|\n\
        1|�������|�|100000||||VARCHAR(80)\n\
        2|���|�|100000||||VARCHAR(50)\n\
        3|����⢮|�|100000||||VARCHAR(80)\n\
        4|���� ��⥫��⢠|�|||��|��2|LIVING|\n\
    ��� ����� �� �ਬ��, ��� ����� ������� ����������� ���⪮  �������� ⨯\n\
    ������.  �� �⮬  ����஫�  ᮮ⢥��⢨� 䠩��� ��ᯮ�� ⨯�� �����������\n\
    �� ���짮��⥫�.\n\
    ��� ��뫮��� ����� ������� ⨯� ������ ���������� � �㤥� �ந����஢���.\n\
    �� �������  ⨯�  ������  ���뢠�� �����. �᫨ ����� ��������  �������,\n\
    祬 �����  ���������  ���  �⮣� ���� ⨯�, ��� ���� ��祭�.  �᫨ �����\n\
    �  ⨯  ��ᮣ��������,  �����  �����������.  �஬�  ⮣�,  �ਫ������  ��\n\
    �����⢫�� �஢��� �� �ࠢ��쭮��� 㪠����� SQL ⨯�.\n\
    �᫨  �  ���������  �뫨  ���������  \"SQL ���|SQL ⨯\"  �� ������  ��������\n\
    �������⥫��  ࠧ����⥫�  \"|\"  �ᥬ  ����,   ����  �᫨  \"SQL ���\"  ���\n\
    \"SQL ⨯\" �� 㪠����.\n\
\n\
���� ����ன�� ���� ������\n\
  �⠭���� SQL'99  ࠧ���� ��ࠧ��  ॠ������� � ᮢ६����� ����.  ���ਬ��,\n\
  ������ ᨬ����� ��ப� �  ORACLE  ���� ����� ⨯ CLOB, �  � MySQL - TEXT.\n\
  ��� �筮� ���४�஢��  ࠡ��� �࠭����  ���  ������  ����  �ᯮ�������\n\
  䠩��  ����ன��  ����  ������.  ���� ����ன�� -  ⥪�⮢� 䠩�,  ����஢��\n\
  windows-1251 ᫥���饩 �������� (� ᪮���� 㪠���� ���祭�� ��㬮�砭��):\n\
    1 ��ப� - ���ᨬ��쭮� ������⢮ ᨬ����� � �������� ⠡���� (20)\n\
    2 ��ப� - ���ᨬ��쭮� ������⢮ ᨬ����� � �������� ���� (30)\n\
    3 ��ப� - ���ᨬ��쭮� ������⢮ ᨬ����� � ���� ⨯� VARCHAR (VARCHAR)\n\
    4 ��ப� - ᨬ���, �⢥��騩 �� ��࠭�஢���� (�� �ᥣ� \"'\") (\"'\")\n\
    5 ��ப� - ᨬ����, ����� ������ ���� ��࠭�஢��� (\"'\")\n\
    6 c�ப� - ⨯, �⢥��騩 �� �࠭���� ������ INTEGER (INTEGER)\n\
    7 c�ப� - ⨯, �⢥��騩 �� �࠭���� ������ LONG (LONG)\n\
    8 c�ப� - ⨯, �⢥��騩 �� �࠭���� ������ FLOAT (FLOAT)\n\
    9 c�ப� - ⨯, �⢥��騩 �� �࠭���� ������ CLOB (TEXT)\n\
    10 c�ப� - ⨯, �⢥��騩 �� �࠭���� ������ VARCHAR (VARCHAR)\n\
    11 c�ப� - ⨯, �⢥��騩 �� �࠭���� ������ DATE (DATE)\n\
    12 c�ப� - ⨯, �⢥��騩 �� �࠭���� ������ TIME (TIME)    \n\
  ���ਬ�� 䠩� ����ன�� ��� ���� ORACLE ����� �룫廊��, ⠪:\n\
    ***************************************************************************\n\
    20\n\
    30\n\
    4000\n\
    '\n\
    '\n\
    NUMBER(11)\n\
    NUMBER(38)\n\
    NUMBER\n\
    CLOB\n\
    VARCHAR2\n\
    DATE\n\
    VARCHAR2(5)\n\
    ***************************************************************************\n\
\n\
OPTIONS\n\
  -c, --config<=struct_file> - ����뢠�� �ਫ������ ���� �  䠩��,  ᮤ�ঠ饬�\n\
                               ᢥ�����  �  �������  �����  ������. � ��砥,\n\
                               �᫨  䠩�,  ᮤ�ঠ騩 ��������  �����  ������\n\
                               ����뢠��  ��᪮�쪮   ������  ������  (����\n\
                               ��ᯮ�⮬    ᯨ᪠    ������    ������    �����\n\
                               CronosPlus), ����室���  �१  ��� �  ����⮩\n\
                               㪠����    ���    �����,   �����    ᮡ�ࠥ���\n\
                               �࠭᫨஢���.\n\
  -d, --delimiter<=sep>      - ��⠭����� ࠧ����⥫� ��ப  �  䠩��� ��ᯮ��\n\
                               ������ ����� CronosPlus. ��㬮�砭�� \"|\".\n\
  -e, --export<data_export>  - ����뢠�� ���� � ����� � 䠩���� ��ᯮ�� ������\n\
                               ����� CronosPlus.\n\
  -o, --output<=path>        - ���࠭��� 䠩�� �  SQL-��ࠦ���ﬨ  �  㪠������\n\
                               �����.\n\
  -t, --tune<conf>           - �ᯮ�짮����  䠩�  ����ப�  ����  ������.  ��.\n\
                               ࠧ��� \"���� ����ன�� ���� ������\".\n\
  -m, --extended<count>      - ����頥� �࠭�����  � ���������� �ᯮ�짮����\n\
                               ���७��   ��⠢��   (��⮤   ᮪�饭��  sql\n\
                               insert-��ࠦ����). \n\
                               ���ਬ��:\n\
                                     INSERT INTO Tab(a, b) VALUES\\\n\
                                     (1, 2),\n\
                                     (2, 3),\n\
                                     (3, 4);\n\
                               <count> - ᮮ�頥� ����� ������⢮ ��ப  �����\n\
                               ��⠢���  �  �����  ���������� (��㬮�砭�� 50).\n\
                               ��ࠬ���    count    ������    ����    ���㫥��\n\
                               ������⥫�� �᫮�.\n\
  -s, --silent               - �� �뤠���� ��祣� � ���᮫�.\n\
  -h, --help                 - �������� �� ᮮ�饭��.\n\
  \n\
EXAMPLES\n\
  cro2sql -�\"C:\\BankList.txt\";\"���⮢� ����\" -eC:\\EXPORT -s -oC:\\SQL\n\
    ��  �᭮��  䠩��   ���ᠭ��   ��������   \"���᮪  ������.txt\"  �����⢨�\n\
    �࠭���� ����� ������  \"���⮢� ����\" �����  CronosPlus,  ��ᯮ�� ������\n\
    ���ண� �ᯮ����� �� ����� C:\\EXPORT.  SQL 䠩�� ���� ��࠭��� � �����\n\
    C:\\SQL, � stdout �뤠�� ��祣� �� �㤥�.\n\
";

  return output.str();
}


string GetErrorMsg(string err_message)
{
  stringstream output;
  output << I_HEADER << endl << endl
    << E_PREFIX << err_message << endl << endl
    << I_FOOTER;
  return output.str();
}

string GetWarningMsg(string warn_message)
{ return ""; }

#endif // __MESSAGES__
