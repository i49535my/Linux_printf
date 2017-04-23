#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BLOCK 80
#define STDIN 0
#define STDOUT 1

void m_printf( char* sente , ... );  //printf����̊֐�
int keta( int value );               //���͒l�̌�����}��֐�

int main(){
	
	char c[ ] = { "HELLO!" };
	int a = 55;
	m_printf( "HELLO!%d_%c %s\n" , a , 'a' , c ); //printf�̓���֐����Ăяo��
	return 0;
	
}

void m_printf( char* sente , ... ){
	
	va_list list;
	char* cp;         //����sente������ϐ�
	char* a;          //�ψ���������ϐ�
	int value;        //		�V
	char x[ 5 ];
	int i;
	
	va_start( list , sente );
	
	/* �ψ�����ǂݎ�郋�[�v */
	for( cp = ( char* ) sente ; *cp != '\0' ; cp++ ){
		
		if( *cp == '%' ){
			cp++;		//���̕���
			
			/* �����̎� */
			if( *cp == 'd' ){
				
				value = va_arg( list , int );	//�ψ����ɃA�N�Z�X�A�ǂݎ��
				i = keta( value );				//������ǂ�
				sprintf( x , "%d" , value );	//int�^��char�^�ϊ�
				write( STDOUT , &x , i );		//�o��
				
			/* ������̎� */
			}else if( *cp == 's' ){
				
				a = ( va_arg ( list , char* )); //�ψ����ɃA�N�Z�X�A�ǂݎ��
				int ii = strlen( a );			//��������ǂ�
				write( STDOUT , &( *a ) ,ii );	//�o��
				
			/* 1�����̎� */
			}else if( *cp == 'c' ){
				
				a = ( va_arg ( list , char* )); //�ψ����ɃA�N�Z�X�A�ǂݎ��
				write( STDOUT , &a , 1 );		//�o��
				
			}
			
		}else{
			
			write( STDOUT , &(*cp) , 1 );	//�ʏ�o��
			
		}
	}
	
	va_end( list );
	
}

int keta( int value ){   //������ǂފ֐�
	
	int i = 0;
	
	while( value != 0 ){
		
		value = value / 10;
		i++;
		
	}
	
	return i;
	
}
