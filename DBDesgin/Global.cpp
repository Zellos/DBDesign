
#include "stdafx.h"
#include"Global.h"
#include <CString>
using namespace std;

int cc,ll;//getchʹ�õļ�������cc��ʾ��ǰ�ַ�(ch)��λ��getch
char ch;//��ǰ�ַ��Ļ����� getch
char line[81];//��ȡ�л�����
char temp[charlength+1];//��ʱ���ţ��������һ���ַ����ڴ��0
char id[charlength+1];//��ǰ��ident,�������һ���ַ����ڴ��0
static int cnum=-1;//������
char sh[charlength];//�洢��ǰ���ַ���
enum symbol sym;//��ǰ�ķ���
int num;//��ǰ����

char word[reservednum][charlength];//������
AnalysisWord AWord[255];//��������������

enum symbol sinsym[256];//ssym,���ַ��ķ���ֵ
enum symbol wordsym[reservednum];//wsym,�����ֶ�Ӧ�ķ���ֵ
char sql[100];
int length;

SQLTYPE AnalyseSql(char csql[]){
	strcpy(sql,csql);
	length=strlen(csql);
	init();

	cc=ll=0;
	ch=' ';
	int count=100;
	 while(count&&!getsym()) count--;	

	 if(AWord[0].type==createsym&&AWord[1].type==tablesym)
		 return CREATE_TABLE;

	return 0;
}

void init(void){

	int i;//singlecharacter,
	/*******************���õ��ַ���**************************/
	for(i=0;i<256;i++){
		sinsym[i]=nul;
	}
	sinsym['+']=plus;
	sinsym['-']=minus;
	sinsym['*']=times;
	sinsym['/']=slash;
	sinsym['(']=lparen;
	sinsym[')']=rparen;
	sinsym['=']=eql;
	sinsym[',']=comma;
	sinsym['.']=period;
	sinsym[';']=semicolon;


/*****************���ñ��������֣�������ĸ˳�򣬱����۰����*************/
	strcpy(&(word[0][0]),"CREATE");
	strcpy(&(word[1][0]),"DATABASE");
	strcpy(&(word[2][0]),"DELETE");
	strcpy(&(word[3][0]),"DROP");
	strcpy(&(word[4][0]),"EDIT");
	strcpy(&(word[5][0]),"FROM");
	strcpy(&(word[6][0]),"IN");
	strcpy(&(word[7][0]),"INSERT");
	strcpy(&(word[8][0]),"INTO");
	strcpy(&(word[9][0]),"KEY");
	strcpy(&(word[10][0]),"NOT_KEY");
	strcpy(&(word[11][0]),"NOT_NULL");
	strcpy(&(word[12][0]),"NULL");
	strcpy(&(word[13][0]),"RENAME");
	strcpy(&(word[14][0]),"SELECT");
	strcpy(&(word[15][0]),"SET");
	strcpy(&(word[16][0]),"TABLE");	
	strcpy(&(word[17][0]),"UPDATE");
	strcpy(&(word[18][0]),"USE");
	strcpy(&(word[19][0]),"VALID");
	strcpy(&(word[20][0]),"WHERE");

	/*****************************���ñ����ַ���*************************************/
	wordsym[0]=createsym;
	wordsym[1]=dbsym;
	wordsym[2]=deletesym;
	wordsym[3]=dropsym;
	wordsym[4]=editsym;
	wordsym[5]=fromsym;
	wordsym[6]=insym;
	wordsym[7]=insertsym;
	wordsym[8]=intosym;
	wordsym[9]=keysym;
	wordsym[10]=notkeysym;
	wordsym[11]=notnul;
	wordsym[12]=nul;
	wordsym[13]=renamesym;
	wordsym[14]=selectsym;
	wordsym[15]=setsym;
	wordsym[16]=tablesym;
	wordsym[17]=updatesym;
	wordsym[18]=usesym;
	wordsym[19]=validsym;
	wordsym[20]=wheresym;


}

int getch(void){//©���ո񣬶�ȡһ���ַ�;ÿ�ζ�һ�У�����line��������line��getsymȡ�պ��ٶ�һ�м���
	if(cc==ll)
	{
		if(cc>=length)
		{
			printf("Program incomplete");
			return -1;
		}
		ll=0;
		cc=0;
		int iter=0;//�ռ���ĸ
		ch=sql[iter];
		while(ch!=10)//�ո�
		{
			if((ch=sql[iter++])==EOF)
			//if(EOF==fscanf(charInString,"%c",&ch))
			{
				line[11]=0;
				break;
			}
			line[ll]=ch;
			ll++;
		}
		
	
	}
		ch=line[cc];
		cc++;
		return 0;
};

int getsym(void){//�ʷ���������ȡһ������
		int i,j,k,m=0;
		int frac=0;
		//char str[10];
		while(ch==' '||ch==10||ch==9)//���Կո񣬻��к�TAB
		{
			
			getchdo;
		}
		if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')//���ֻ�������a-z��ͷ���ߴ�д����ĸ
		{
			k=0;
			do{
				if(k<charlength)
				{
					temp[k]=ch;
					k++;
				}
				getchdo;
			}while(ch>='a'&&ch<='z'||ch>='0'&&ch<='9'||ch>='A'&&ch<='Z'||ch=='_');
			temp[k]=0;//������Ǹ��ַ����Դ��0
			strcpy(id,temp);
			i=0;
			m=0;
			j=reservednum-1;
			do{			//���ַ�������ǰ�����Ƿ�Ϊ������
				k=(i+j)/2;
				if(strcmp(id,word[k])<=0)j=k-1;
				if(strcmp(id,word[k])>=0)i=k+1;
				if(strcmp(id,word[k])==0){m=1;cnum++;
			
				strcpy(AWord[cnum].word,id);
				AWord[cnum].type=wordsym[k];//served
				//AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����
				break; 
				};
			}while(i<=j);
			//if(k==5){
			//	//getchdo;
			//	if(ch=='.')
			//	{cnum++;//printf("%3d     .             PERIOD\n",cnum);
			//	strcat(AWord[cnum].word,&ch);
			//	AWord[cnum].type=period;//period
			//	}
			//	return 1;
			//}///////////////////////////////////////////toend!!!!


			if(!m) {cnum++;
			strcpy(AWord[cnum].word,id);
			AWord[cnum].type=identifier;;//identifier
			}

		}
		else{
			if(ch>='0'&&ch<='9'||ch=='.')//����Ƿ�Ϊ���֣���0..9��ͷ
			{
				//k=0;
				num=0;
				m=0;
				int mi=1;
				int i=0;
				sym=number;
				memset(sh,'\0',charlength);//�����sh��ԭ�������ݣ���ֹ����****************************
				do{
					num=10*num+ch-'0';
					strcat(&sh[i],&ch);
					//k++;
					getchdo;
					i++;
				}while(ch>='0'&&ch<='9');//��ȡ���ֵ�ֵ
				memset(&sh[i],'\0',charlength-i);
				i=0;
				if(ch=='.'){
					m=1;//��������븡����
					strcat(sh,&ch);
					getchdo;
					do{
					frac=10*frac+ch-'0';i++;
					strcat(sh,&ch);
					//k++;
					getchdo;
				}while(ch>='0'&&ch<='9');//��ȡ���ֵ�ֵ
				}
				while(m&&i>0){ mi=mi*10;i--;};//С����λ��
				if(m) {cnum++;
				//printf("%3d     %d.%d           NUMBER           %d.%d\n",cnum,num,frac,num,frac);
	            strcpy(AWord[cnum].word,sh);
				AWord[cnum].type=sym;//number
				//AWord[cnum].num=num+(float)frac/mi;//�洢�Ѿ�ʶ�������
				//AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����
				}
			
				else  {cnum++;//printf("%3d     %-9d     NUMBER           %d\n",cnum,num,num);
				strcpy(AWord[cnum].word,sh);
				AWord[cnum].type=sym;//number
				AWord[cnum].num=num;//�洢�Ѿ�ʶ�������
				
				}
				//k--;
				//if(k>nmax) error(30);//����

				}
			else
			{
				//if(ch==':')//��⸳ֵ����
				//{
				//	getchdo;
				//	if(ch=='=')
				//	{
				//	sym=eql;
				//	cnum++;
				//	
				//	strcpy(AWord[cnum].word,":=");
				//	AWord[cnum].type=eql;//equal		
				//	//AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����
				//	getchdo;
				//	}
				//	else{
				//		sym=nul;
				//		cnum++;
				//	
				//	}
				//}
				//else
				{
					if(ch=='<')//���С�ڻ�С�ڵ��ڷ���
					{
						getchdo;
						if(ch=='=')
						{
						cnum++;
						
						strcpy(AWord[cnum].word,"<=");
						AWord[cnum].type=leql;//less||equal
						//AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����
						getchdo;
						}
						else {sym=lss;
						cnum++;
						//printf("%3d     <             LESS\n",cnum);
						strcpy(AWord[cnum].word,"<");
						AWord[cnum].type=lss;//less
						//AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����
						}
					}
					else
					{
						if(ch=='>')//�����ڻ���ڵ��ڷ���
						{
							getchdo;
							if(ch=='=')
							{								
								cnum++;
								
								strcpy(AWord[cnum].word,">=");
								AWord[cnum].type=geql;//greater||equal
								//AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����
								getchdo;
							}
							else {
								sym=gtr;
								cnum++;
							strcpy(AWord[cnum].word,">");
							AWord[cnum].type=gtr;//greater
							//AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����
							}
						}
						else if(ch=='='){
							getchdo;
							if(ch=='=')
								{sym=eql;
							  cnum++;
								
								strcpy(AWord[cnum].word,"==");
								AWord[cnum].type=eql;//equal
								//AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����
								getchdo;
							}else
								{	sym=eql;
									cnum++;
									
									strcpy(AWord[cnum].word,"=");
									AWord[cnum].type=eql;//becomes
								//	AWord[cnum].line=wordLine;//��ʶ��������ַ��洢����

								}
							}

							else
							{
								sym=sinsym[ch];//�����Ų�������������ʱ��ȫ�����յ��ַ����Ŵ���
								m=0;
								switch(ch){
								case '(':
									cnum++;m=1;
									strcpy(AWord[cnum].word,"(");
									AWord[cnum].type=lparen;//equal
																
									break;
								case ')':
									cnum++;m=1;
									strcpy(AWord[cnum].word,")");
									AWord[cnum].type=rparen;//equal
								
									break;
								case '+':
									cnum++;m=1;
									strcpy(AWord[cnum].word,"+");
									AWord[cnum].type=plus;//equal
									
									break;
								case '-':
									cnum++;m=1;
									strcpy(AWord[cnum].word,"-");
									AWord[cnum].type=minus;
									
									break;
								case '*':
									cnum++;;m=1;
									strcpy(AWord[cnum].word,"*");
									AWord[cnum].type=times;
									
									break;
								case '/':
									cnum++;m=1;
									strcpy(AWord[cnum].word,"/");
									AWord[cnum].type=slash;
									
									break;
								case ';':
									cnum++;m=1;
									strcpy(AWord[cnum].word,";");
									AWord[cnum].type=semicolon;
									return 1;//�����ֺţ���������
									
								case ',':
									cnum++;m=1;
									strcpy(AWord[cnum].word,",");
									AWord[cnum].type=comma;
									
									break;
							}
								if(!m) {cnum++; return 2;}//�����ַ�
							getchdo;
								/*if(sym!=period)
									getchdo;*/
								/*if(ch=='.'){return 1;}*/
							}
					}
				}
			}
		}
	return 0;
};