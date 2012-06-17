#include "stdafx.h"

#include"EditTable.h"

/*Sample SQL:
EDIT TABLE mytable(
username varchar  NOT_KEY  NOT_NULL  VALID)IN myDB;
*/

CString EditTable(void){
	CString result;
	char tableName[15];
	char dbName[15];
	bool mark;
	bool nullmark;
	bool keymark;
	bool validmark;
	int i=4;
	///////////////����﷨///////////////////
	if(AWord[2].type!=identifier){
		result="'EDIT TABLE' �������﷨����©�˱�����";//ȱ�ٱ���
		return result;
	}
	if(AWord[3].type==lparen){

			mark=false;//����,�������͵ı�ǣ���ֹȱ����������
			if(AWord[i].type==identifier){//����
				i++;
			}else {
			result="'(' �������﷨����!ȱ������?";//ȱ�ٱ�ʶ������������
			return result;
			}
			if(AWord[i].type==datetimesym){//datetime��������
				i++;mark=1;//������������,���1
			}
			if(AWord[i].type==varcharsym){//varchar��������
				i++;mark=1;//������������,���1
			}
			if(AWord[i].type==intsym){//int��������
				i++;mark=1;//������������,���1
			}
			if(mark==0){
			result="��������ȱ�ٶ�Ӧ����������!";
			return result;
			}
			if(AWord[i].type==keysym) i++;			
			if(AWord[i].type==notkeysym)i++;
			if(AWord[i].type==nul)	i++;		
			if(AWord[i].type==notnul)	i++;
			if(AWord[i].type==validsym) i++;
			if(AWord[i].type==invalidsym) i++;
		
	if(AWord[i].type!=rparen){
		result="ȱ��')'!";
		return result;
	}
	i++;
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
}else{//lparen��while
		result="ȱ��'('!";
		return result;
	}

	///////�ٽ���д���ļ�����//////
	strcpy(tableName,AWord[2].word);//��������//////////////������Ҫ�ļ������ѱ��������ļ���
    keymark=false;//�ж��Ƿ�����key ����not key ��û�� ��ִ��Ĭ�ϵĲ���not key
	nullmark=false;//�ж��Ƿ�����null ����not null ��û�� ��ִ��Ĭ�ϵĲ���null
	validmark=false;//�ж��Ƿ�����valid ��û�� ��ִ��Ĭ�ϵĲ���valid
	i=5;//���ĸ�������,�����Ϊ��������
	if(AWord[4].type==identifier){//����
		////////////////������Ҫ�ļ������ж������Ĵ�������ٽ����޸ġ�
	}
	if(AWord[i].type==datetimesym){//datetime��������
		//strcpy(columnName[c],AWord[i].word);///////////////������Ҫ�ļ����������ʹ����ļ���
		i++;
	}

	if(AWord[i].type==varcharsym){//varchar��������
		//strcpy(columnName[c],AWord[i].word);///////////////������Ҫ�ļ����������ʹ����ļ���
		i++;
	}
	if(AWord[i].type==intsym){//int��������
		//strcpy(columnName[c],AWord[i].word);///////////////������Ҫ�ļ������޸�����
		i++;
	}
	if(AWord[i].type==keysym){
		///////////////������Ҫ�ļ���������key��ǡ�///////////////������Ҫ�ļ����������ļ���
		i++;keymark=1;
	}
	if(AWord[i].type==notkeysym){
		///////////////������Ҫ�ļ���������notkey��ǡ�///////////////������Ҫ�ļ����������ļ���
		i++;keymark=1;
	}
	if(keymark==0){
		//����ִ��Ĭ�ϲ��� ������Ϊnot key///////////////������Ҫ�ļ�����notkey�����ļ���
	}

	if(AWord[i].type==nul){//null���
		///////////////������Ҫ�ļ�����������key��ǡ�///////////////������Ҫ�ļ����������ļ���
		i++;nullmark=1;
	}
	if(AWord[i].type==notnul){//not null���
		///////////////������Ҫ�ļ�����������key��ǡ�///////////////������Ҫ�ļ����������ļ���
		i++;nullmark=1;
	}
	if(nullmark==0){
		//����ִ��Ĭ�ϲ��� ������Ϊnull///////////////������Ҫ�ļ�����Ĭ�ϲ���null�����ļ���
	}
	if(AWord[i].type==validsym){//VALID���
		///////////////������Ҫ�ļ�����������key��ǡ�///////////////������Ҫ�ļ����������ļ���
		i++;validmark=1;
	}
	if(AWord[i].type==invalidsym){//INVALID���
		///////////////������Ҫ�ļ�����������key��ǡ�///////////////������Ҫ�ļ����������ļ���
		i++;validmark=1;
	}
	if(validmark==0){
		//����ִ��Ĭ�ϲ��� ������Ϊnull///////////////������Ҫ�ļ�����Ĭ�ϲ���valid�����ļ���
	}

	
	result="�����ɹ���";

	return result;
}
