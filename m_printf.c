#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BLOCK 80
#define STDIN 0
#define STDOUT 1

void m_printf( char* sente , ... );  //printf動作の関数
int keta( int value );               //入力値の桁数を図る関数

int main(){
	
	char c[ ] = { "HELLO!" };
	int a = 55;
	m_printf( "HELLO!%d_%c %s\n" , a , 'a' , c ); //printfの動作関数を呼び出す
	return 0;
	
}

void m_printf( char* sente , ... ){
	
	va_list list;
	char* cp;         //引数senteを入れる変数
	char* a;          //可変引数を入れる変数
	int value;        //		〃
	char x[ 5 ];
	int i;
	
	va_start( list , sente );
	
	/* 可変引数を読み取るループ */
	for( cp = ( char* ) sente ; *cp != '\0' ; cp++ ){
		
		if( *cp == '%' ){
			cp++;		//次の文字
			
			/* 数字の時 */
			if( *cp == 'd' ){
				
				value = va_arg( list , int );	//可変引数にアクセス、読み取る
				i = keta( value );				//桁数を読む
				sprintf( x , "%d" , value );	//int型→char型変換
				write( STDOUT , &x , i );		//出力
				
			/* 文字列の時 */
			}else if( *cp == 's' ){
				
				a = ( va_arg ( list , char* )); //可変引数にアクセス、読み取る
				int ii = strlen( a );			//文字数を読む
				write( STDOUT , &( *a ) ,ii );	//出力
				
			/* 1文字の時 */
			}else if( *cp == 'c' ){
				
				a = ( va_arg ( list , char* )); //可変引数にアクセス、読み取る
				write( STDOUT , &a , 1 );		//出力
				
			}
			
		}else{
			
			write( STDOUT , &(*cp) , 1 );	//通常出力
			
		}
	}
	
	va_end( list );
	
}

int keta( int value ){   //桁数を読む関数
	
	int i = 0;
	
	while( value != 0 ){
		
		value = value / 10;
		i++;
		
	}
	
	return i;
	
}
