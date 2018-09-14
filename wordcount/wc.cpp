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
    if( (fp = fopen(file,"r") ) == NULL)		//打开文件并且读取
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
					while( !feof(fp) )							//读取文件直到左后一个字符
			    	{
				        char a = fgetc(fp);						//大循环来返回每读取的一个字节
				        if( a!=' ' && a!='\n' && a!='\t' && a!=',' && a!='.' && a!='!' && a!=';' && a!='=' )
			            	c++;								//字符数加一
			        }
			        c--;
			        printf( "the number of characters:%d\n", c);
			        break;
				}
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
                case 'l':
				{
					while( !feof(fp) )							//读取文件直到左后一个字符
				    {
				        char a = fgetc(fp);						//大循环来返回每读取的一个字节
				        if( a=='\n')
            				l++;								//行数加一
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
