#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int c = 0;
int w = 0;
int l = 0;
int main(int argc, char *argv[])
{
    FILE *fp;
    char order;
    char *file=argv[2];
    order=argv[1][1];
    if( (fp = fopen(file,"r") ) == NULL)		//���ļ����Ҷ�ȡ
    {
        printf( "open file failed!\n" );
        exit(-1);
    }
    else if( argc <= 2)
		printf( "wrong command!" );
	else
	{
		switch(order)
		{
			case 'c':
				{
					while( !feof(fp) )							//��ȡ�ļ�ֱ�����һ���ַ�
			    	{
				        char a = fgetc(fp);						//��ѭ��������ÿ��ȡ��һ���ֽ�
				        if( a!=' ' && a!='\n' && a!='\t' && a!=',' && a!='.' && a!='!' && a!=';' && a!='=' )
			            	c++;								//�ַ�����һ
			        }
			        c--;
			        printf( "the number of characters:%d\n", c);
			        break;
				}
			//case 'w':                   //��һ��˼·��Ѱ�ҵ���ͷ
/*				{
                    char a = fgetc(fp);		            //��ѭ��������ÿ��ȡ��һ���ֽ�
                    if( isalnum(a) )                    //��ͷ�������ַ�
                        w--;
					else
                    {
                        while( !feof(fp) )			    //��ȡ�ļ�ֱ�����һ���ַ�
                        {
                            char b = fgetc(fp)
                            if( isalnum(b) )            //�����ַ���������+1
                                w++;
                            char c =fgetc(fp);          //
                            if( !isalnum(b) )
                            {
                                if( isalnum(c) && c != EOF)
                                    w--;
                            }
                        }
                    }
            		w++;

            		printf( "the number of words:%d\n", w);
            		break;
            	}   */
            case 'w':
                {
                    char a =fgetc(fp);
                    while( a != EOF)
                    {
                        if( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') )
                        {
                            while( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') )
                                a =fgetc(fp);
                            w++;
                            a =fgetc(fp);
                        }
                        else
                            a =fgetc(fp);
                    }
                    printf("the number of words:%d\n",w);
                    break;
                }
                    //else                            //��������ſ�ͷ
                    //if( isalnum(head) ){
                    /*    while( !feof(fp))
                        {
                            char a = fgetc(fp);
                            if( isalnum(a) )           //����0
                                {
                                    char b =fgetc(fp);
                                    if( !isalnum(b) )
                                        w++;
                                }
                        }
                        w++;
                        printf( "the number of words:%d\n", w);
                    break;
                    }   */
                case 'l':
				{
					while( !feof(fp) )							//��ȡ�ļ�ֱ�����һ���ַ�
				    {
				        char a = fgetc(fp);						//��ѭ��������ÿ��ȡ��һ���ֽ�
				        if( a=='\n')
            				l++;								//������һ
            		}
            		l++;
                    printf( "the number of linies:%d\n", l);
            		break;
            	}
            default:
            	{
            		printf( "wrong command!\n");
            		break;
				}
		}
	}
    return 0;
}

