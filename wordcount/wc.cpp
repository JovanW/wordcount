#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int c = 0;
int w = 0;
int l = 0;

//    fclose(fp);

int main(int argc, char *argv[])
{
    FILE *fp;
    char order;
    char *file=argv[2];
    order=argv[1][1];
    if( (fp = fopen(file,"r") ) == NULL)		//���ļ����Ҷ�ȡ
    {
        printf( "open file failed!\n" );
        exit(-1);								//
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
			case 'w':
				{
					while( !feof(fp) )							//��ȡ�ļ�ֱ�����һ���ַ�
	    			{
	    				char a = fgetc(fp);						//��ѭ��������ÿ��ȡ��һ���ֽ�
	    			    if( a==' ' || a=='\n' || a=='\t' || a==',' || a=='.' || a=='!' || a=='=' || a==';')
            				w++;								//��������һ
            		}
            		w++;
            		printf( "the number of words:%d\n", w);
            		break;
            	}
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

