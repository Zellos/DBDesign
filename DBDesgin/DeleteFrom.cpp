#include"stdafx.h"
#include"DeleteFrom.h"
/*
DELETE FROM mytable WHERE username='test' IN myDB;

*/


CString DeleteFrom(void){
	CString result;
	char tableName[15];
	char dbName[15];
	int i=7;
	///////////////����﷨///////////////////
	if(AWord[2].type!=identifier){
		result="'DELETE FROM' �������﷨����©�˱�����";//ȱ�ٱ���
		return result;
	}
	if(AWord[3].type!=wheresym){
		result="SQL������﷨����©��WHERE��";//ȱ��where
		return result;
	}
	if(AWord[4].type!=identifier){
		result="SQL������﷨����©��Field��";//ȱ��field
		return result;
	}
	if(AWord[5].type!=eql){
		result="SQL������﷨���󣡲���'='��";//����=��
		return result;
	}
	if(AWord[6].type!=quote){
		result="SQL������﷨����©��content��";//ȱ��content
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
/////////////�ļ�����//////////////////////////////////////////

	result="ɾ���ɹ���";
	return result;
}