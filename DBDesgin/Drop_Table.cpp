#include"stdafx.h"
#include"Drop_Table.h"
/*Sample SQL:
DROP TABLE mytable IN myDB;

*/


CString DropTable(void){
	CString result;
	char tableName[15];
	char dbName[15];
	int i=3;
	///////////////����﷨///////////////////
	if(AWord[2].type!=identifier){
		result="'DROP TABLE' �������﷨����©�˱�����";//ȱ�ٱ���
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
	strcpy(tableName,AWord[3].word);//������֣���ȷ����治���ڣ�������ֱ�ӷ���
	//strcpy(lasName,AWord[4].word);//����������
	////////////Ԥ����������Ĳ���//////////////

	result="�����ɹ���";
	return result;



}