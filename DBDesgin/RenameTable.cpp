#include"stdafx.h"
#include"RenameTable.h"
/*Sample SQL:

RENAME TABLE mytable yourtable IN myDB;

*/


CString RenameTable(void){
	CString result;
	char preName[15];
	char lasName[15];
	char dbName[15];
	int i=4;
	///////////////����﷨///////////////////
	if(AWord[2].type!=identifier){
		result="'RENAME TABLE' �������﷨����©�˱�����";//ȱ�ٱ���
		return result;
	}
		if(AWord[3].type!=identifier){
		result="�﷨����©�˵ڶ���������";//ȱ�ٱ���
		return result;
		}

	if(AWord[i].type==insym){//in XXX  xxxΪĿ�����ݿ�
		i++;
		if(AWord[i].type==identifier){
			strcpy(dbName,AWord[i+1].word);//��������ݿ������������ø�����ѡ��Ҫ���������ݿ⣬���жϸ����ݿ�治����//////////////�ļ�����
		}
		else{
		result="ȱ����Ҫ���������ݿ�!";
		return result;
		}
		i++;
   	}
	
	if(AWord[i].type!=semicolon){
		result="ȱ��';'!";
		return result;
	}

		///////////////�ļ�����///////////////////
	strcpy(preName,AWord[3].word);//ԭ�������֣���ȷ����治����
	strcpy(lasName,AWord[4].word);//����������
	////////////Ԥ����������Ĳ���//////////////

	result="�����ɹ���";
	return result;
}