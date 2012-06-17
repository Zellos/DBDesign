
#include "stdafx.h"

#include "CreateTable.h"

/*����SQL:
CREATE TABLE mytable(
username varchar KEY NOT_NULL VALID,
age int,
birth datetime);
*/


CString CreateTable(void){
	CString result;
	char tableName[15];
	char dbName[15];
	int i=3;
	//char columnName[15][15];
	int c=0;
	int mark;//�ж��Ƿ�������������������
	bool keymark;//�ж��Ƿ�����key ����not key ��û�� ��ִ��Ĭ�ϵĲ���
	bool nullmark;//�ж��Ƿ�����null ����not null ��û�� ��ִ��Ĭ�ϵĲ���
	bool validmark;
	////////�Ƚ����﷨����///////////////////
	if(AWord[2].type!=identifier){
		result="'CREATE TABLE' �������﷨����©�˱�����";//ȱ�ٱ���
		return result;
	}
	if(AWord[3].type==lparen){

		do{
			mark=false;//����,�������͵ı�ǣ���ֹȱ����������
			i++;//ѡ��һ���ؼ���
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
		}while(AWord[i].type==comma);//do
		
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

	i=3;//�ص���ʼ
	if(AWord[2].type==identifier)
	strcpy(tableName,AWord[2].word);//��������//////////////������Ҫ�ļ������ѱ��������ļ���
	
	if(AWord[3].type==lparen){

		do{
			keymark=false;//�ж��Ƿ�����key ����not key ��û�� ��ִ��Ĭ�ϵĲ���not key
			nullmark=false;//�ж��Ƿ�����null ����not null ��û�� ��ִ��Ĭ�ϵĲ���null
			validmark=false;//�ж��Ƿ�����valid ��û�� ��ִ��Ĭ�ϵĲ���valid
			i++;//ѡ��һ���ؼ���
			if(AWord[i].type==identifier){//����
				//strcpy(columnName[c],AWord[i].word);///////////////������Ҫ�ļ����������������ļ���
				c++;i++;
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
				//strcpy(columnName[c],AWord[i].word);///////////////������Ҫ�ļ����������ʹ����ļ���
				i++;
			}
			if(AWord[i].type==keysym){
				///////////////������Ҫ�ļ�����������key��ǡ�///////////////������Ҫ�ļ����������ļ���
				i++;keymark=1;
			}
			if(AWord[i].type==notkeysym){
				///////////////������Ҫ�ļ�����������key��ǡ�///////////////������Ҫ�ļ����������ļ���
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

		}while(AWord[i].type==comma);
	}	
	result="�����ɹ���";
	return result;
}
