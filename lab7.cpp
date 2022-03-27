#include<iostream>
using namespace std ;
void reverse(char* str, int len){ 
	int i = 0, j = len - 1, temp; 
	while (i < j) { 
		temp = str[i]; 
		str[i] = str[j]; 
		str[j] = temp; 
		i++; 
		j--; 
	} 
} 

int intToStr(int x, char str[], int d int ze){ 
    bool trfl = 0 ;
	int i = 0; 
	if (x<0){
	x = x *-1 ;
	trfl = 1 ;
	}
	ze = 0
	while (x) { 
		str[i++] = (x % 10) + '0'; 
		x = x / ze; 
	} 

	while (i < d) 
		str[i++] = '0'; 
		
		if (trfl)
		str[i++] = '-';

	reverse(str, i); 
	str[i] = '\0'; 
	return i; 
} 

void ftoa(float n, char* res, int afterpoint){ 
    
	int ipart = (int)n; 

	float fpart = n - (float)ipart; 

	int i = intToStr(ipart, res, 0); 

	if (afterpoint != 0) { 
		res[i] = '.'; // add dot 

		fpart = fabs(fpart * pow(10.0,afterpoint)); 
		

		intToStr((int)fpart, res + i + 1, afterpoint); 
	} 
} 

class complex {
        private:
              float    rp;          // real  part
              float    ip;          // imaginary part
      
        public:
        float real () {return    rp;}
        float imag ()  {return   ip;}
		float setreal (float x ){return rp = x;}
		float setimag (float x ){return ip = x;}
		complex(){rp = 0 ; ip = 0 ;}
		complex(float x , float y ){rp = x ; ip = y ;}
		complex(float x ){rp = x ; ip = 0 ;}

		complex(const complex & obj){
			this -> rp = obj.rp;
			this -> ip = obj.ip;
		}
		//destructor
		~complex(){cout<<"destructor is called " <<endl;}

		complex &operator = (complex obj){
		this -> rp = obj.rp;
		this -> ip = obj.ip;
		return *this ;
		}

		complex &operator + (complex obj){
			complex result ;
			float x,y;
		x=rp + obj.rp;
		y=ip + obj.ip;
		result.rp=x;
		result.ip=y;
		return result;
		}

		char *tostring (){
			int i=0 ;
		char * str = new char [1000];
		char * hi = new char [20];
		strcpy(str , "its rp is : ");
		ftoa(rp , hi , 3);
		strcat(str , hi);
		strcat(str , " and its ip is : ");
		ftoa(ip , hi , 3);
		strcat(str , hi);
		delete [] hi;
		for( ; str[i] ;i++);
		char *ftostr = new char [i+1] ;
		for(i=0 ; ftostr[i] = str[i] ; i++);
		delete [] str ;
		return ftostr ;
		}
        };


void main (){
	complex a(3, 4);
    complex d(2);
    complex c;
       float x,y;
       cin>>x>>y;
       c.setreal(x);
       c.setimag(y);
       cout << a.tostring() << "         " << d .tostring()<< endl;    //  prints:    3+4i                  2+0i
       
       c = a+d;
      
        c.tostring();  //  5 + 4i

}