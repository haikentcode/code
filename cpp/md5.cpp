#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;
int S11;
int S12;
int S13;
int S14 ;
int S21 ;
int S22 ;
int S23 ;
int S24 ;
int S31 ;
int S32 ;
int S33 ;
int S34 ;
int S41 ;
int S42 ;
int S43 ;
int S44;
const char HEX[16] = {
	'0', '1', '2', '3',
	'4', '5', '6', '7',
	'8', '9', 'a', 'b',
	'c', 'd', 'e', 'f'
};

typedef unsigned char byte;
typedef unsigned int uint32;

//uint32 word[4] = {0x01234567,0x89abcdef,0xfedcba98,0x76543210};

uint32 word[4] = {0x67452301,0xefcdab89,0x98badcfe,0x10325476};

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

#define FF(a, b, c, d, x, s, ac) { \
	(a) += F ((b), (c), (d)) + (x) + ac; \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define GG(a, b, c, d, x, s, ac) { \
	(a) += G ((b), (c), (d)) + (x) + ac; \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define HH(a, b, c, d, x, s, ac) { \
	(a) += H ((b), (c), (d)) + (x) + ac; \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define II(a, b, c, d, x, s, ac) { \
	(a) += I ((b), (c), (d)) + (x) + ac; \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
}

void reset(){

	word[0]=0x67452301;
	word[1]=0xefcdab89;
	word[2]=0x98badcfe;
	word[3]=0x10325476;
	S11 =7;
	S12 =12;
	S13 =17;
	S14 =22;
	S21 =5;
	S22 =9;
	S23 =14;
	S24 =20;
	S31 =4;
	S32 =11;
	S33 =16;
	S34 =23;
	S41 =6;
	S42 =10;
	S43 =15;
	S44 =21;

}

string convert(string s){
	int length = s.size();


	char tt[8*length+1];

	int index = 0;
	for (int i = 0;i < length;i ++){
		for (int j = 0;j <= 7;j ++){
			int a = s[i]%2;
			tt[i*8+7-j] = '0'+a;
			s[i] = s[i]/2;
		}
	}

	tt[8*length] = '\0';


	string str(tt);

	return str;
}


string convertN(int s){

	char tt[65];
	int index = 0;
	for (int i = 63;i >= 0;i --){
		int a = s%2;
		s = s/2;
		tt[i] = '0'+a;

	}
	tt[64]='\0';

	char tt_[65];
	for (int k = 1;k <= 8;k ++){
		for (int i = 0+(k-1)*8,j = 56-(k-1)*8;i <= 7+(k-1)*8;i ++,j++){
			tt_[i] = tt[j];
		}
	}


	tt_[64]='\0';


	string str(tt_);


	return str;
}

string convertFinal(uint32 s){
	char tt[9];
	int index = 0;
	for (int i = 7;i >= 0;i --){
		int a = s%16;
		s = s/16;
		tt[i] = HEX[a];

	}
	tt[8] = '\0';


	char tt_[9];
	for (int i = 0;i < 2;i ++){
		tt_[i] = tt[i+6];
		tt_[i+6] = tt[i];
	}

	for (int i = 2;i < 4;i ++){
		tt_[i] = tt[i+2];
		tt_[i+2] = tt[i];
	}
	tt_[8] = '\0';
	string str(tt_);

	return str;

}

string append(string s){
	int length = s.size();


	string s_length = convertN(length);

	vector<char>v;
	v.clear();
	v.push_back('1');

	int l = length;
	while(l%512 != 447){
		v.push_back('0');
		l ++;
	}
	l ++;

	char *app = new char[l+1-length];
	for (int i = 0;i < l-length;i ++)
		app[i] = v[i];
	app[l-length]='\0';
	string sapp(app);

	char *cstr = new char [s.size()+1];

	strcpy(cstr,s.c_str());
	string ccstr(cstr);

	string newstr = ccstr + sapp + s_length;

	return newstr;


}


uint32 decode(string s,int i,int j){
	uint32 sum = 0x0;


	int temp = (i-1)*512+j*32;
	for (int i = 0+temp;i < 8+temp;i ++)
		sum += (s[i] - '0')*(uint32)pow(2,7-i+temp);

	for (int i = 8+temp;i < 16+temp;i ++)
		sum += (s[i] - '0')*(uint32)pow(2,23-i+temp);
	for (int i = 16+temp;i < 24+temp;i ++)
		sum += (s[i] - '0')*(uint32)pow(2,39-i+temp);

	for (int i = 24+temp;i < 32+temp;i ++)
		sum += (s[i] - '0')*(uint32)pow(2,55-i+temp);

	return sum;
}

string md5(string s){


     s=convert(s);
     s=append(s);
     cout<<s.size()<<endl<<endl;
	int time = s.size()/512;


	uint32 a = word[0],b = word[1],c = word[2], d = word[3];

	for (int i = 1;i <= time;i ++){
		uint32 s_packet[16];
		for (int j = 0;j < 16;j ++){
			 s_packet[j] = decode(s,i,j);


		}
		/*Round 1*/
		FF (a, b, c, d, s_packet[ 0], S11, 0xd76aa478); /* 1 */
		FF (d, a, b, c, s_packet[ 1], S12, 0xe8c7b756); /* 2 */
		FF (c, d, a, b, s_packet[ 2], S13, 0x242070db); /* 3 */
		FF (b, c, d, a, s_packet[ 3], S14, 0xc1bdceee); /* 4 */
		FF (a, b, c, d, s_packet[ 4], S11, 0xf57c0faf); /* 5 */
		FF (d, a, b, c, s_packet[ 5], S12, 0x4787c62a); /* 6 */
		FF (c, d, a, b, s_packet[ 6], S13, 0xa8304613); /* 7 */
		FF (b, c, d, a, s_packet[ 7], S14, 0xfd469501); /* 8 */
		FF (a, b, c, d, s_packet[ 8], S11, 0x698098d8); /* 9 */
		FF (d, a, b, c, s_packet[ 9], S12, 0x8b44f7af); /* 10 */
		FF (c, d, a, b, s_packet[10], S13, 0xffff5bb1); /* 11 */
		FF (b, c, d, a, s_packet[11], S14, 0x895cd7be); /* 12 */
		FF (a, b, c, d, s_packet[12], S11, 0x6b901122); /* 13 */
		FF (d, a, b, c, s_packet[13], S12, 0xfd987193); /* 14 */
		FF (c, d, a, b, s_packet[14], S13, 0xa679438e); /* 15 */
		FF (b, c, d, a, s_packet[15], S14, 0x49b40821); /* 16 */

		/* Round 2 */
		GG (a, b, c, d, s_packet[ 1], S21, 0xf61e2562); /* 17 */
		GG (d, a, b, c, s_packet[ 6], S22, 0xc040b340); /* 18 */
		GG (c, d, a, b, s_packet[11], S23, 0x265e5a51); /* 19 */
		GG (b, c, d, a, s_packet[ 0], S24, 0xe9b6c7aa); /* 20 */
		GG (a, b, c, d, s_packet[ 5], S21, 0xd62f105d); /* 21 */
		GG (d, a, b, c, s_packet[10], S22,  0x2441453); /* 22 */
		GG (c, d, a, b, s_packet[15], S23, 0xd8a1e681); /* 23 */
		GG (b, c, d, a, s_packet[ 4], S24, 0xe7d3fbc8); /* 24 */
		GG (a, b, c, d, s_packet[ 9], S21, 0x21e1cde6); /* 25 */
		GG (d, a, b, c, s_packet[14], S22, 0xc33707d6); /* 26 */
		GG (c, d, a, b, s_packet[ 3], S23, 0xf4d50d87); /* 27 */
		GG (b, c, d, a, s_packet[ 8], S24, 0x455a14ed); /* 28 */
		GG (a, b, c, d, s_packet[13], S21, 0xa9e3e905); /* 29 */
		GG (d, a, b, c, s_packet[ 2], S22, 0xfcefa3f8); /* 30 */
		GG (c, d, a, b, s_packet[ 7], S23, 0x676f02d9); /* 31 */
		GG (b, c, d, a, s_packet[12], S24, 0x8d2a4c8a); /* 32 */

		/* Round 3 */
		HH (a, b, c, d, s_packet[ 5], S31, 0xfffa3942); /* 33 */
		HH (d, a, b, c, s_packet[ 8], S32, 0x8771f681); /* 34 */
		HH (c, d, a, b, s_packet[11], S33, 0x6d9d6122); /* 35 */
		HH (b, c, d, a, s_packet[14], S34, 0xfde5380c); /* 36 */
		HH (a, b, c, d, s_packet[ 1], S31, 0xa4beea44); /* 37 */
		HH (d, a, b, c, s_packet[ 4], S32, 0x4bdecfa9); /* 38 */
		HH (c, d, a, b, s_packet[ 7], S33, 0xf6bb4b60); /* 39 */
		HH (b, c, d, a, s_packet[10], S34, 0xbebfbc70); /* 40 */
		HH (a, b, c, d, s_packet[13], S31, 0x289b7ec6); /* 41 */
		HH (d, a, b, c, s_packet[ 0], S32, 0xeaa127fa); /* 42 */
		HH (c, d, a, b, s_packet[ 3], S33, 0xd4ef3085); /* 43 */
		HH (b, c, d, a, s_packet[ 6], S34,  0x4881d05); /* 44 */
		HH (a, b, c, d, s_packet[ 9], S31, 0xd9d4d039); /* 45 */
		HH (d, a, b, c, s_packet[12], S32, 0xe6db99e5); /* 46 */
		HH (c, d, a, b, s_packet[15], S33, 0x1fa27cf8); /* 47 */
		HH (b, c, d, a, s_packet[ 2], S34, 0xc4ac5665); /* 48 */

		/* Round 4 */
		II (a, b, c, d, s_packet[ 0], S41, 0xf4292244); /* 49 */
		II (d, a, b, c, s_packet[ 7], S42, 0x432aff97); /* 50 */
		II (c, d, a, b, s_packet[14], S43, 0xab9423a7); /* 51 */
		II (b, c, d, a, s_packet[ 5], S44, 0xfc93a039); /* 52 */
		II (a, b, c, d, s_packet[12], S41, 0x655b59c3); /* 53 */
		II (d, a, b, c, s_packet[ 3], S42, 0x8f0ccc92); /* 54 */
		II (c, d, a, b, s_packet[10], S43, 0xffeff47d); /* 55 */
		II (b, c, d, a, s_packet[ 1], S44, 0x85845dd1); /* 56 */
		II (a, b, c, d, s_packet[ 8], S41, 0x6fa87e4f); /* 57 */
		II (d, a, b, c, s_packet[15], S42, 0xfe2ce6e0); /* 58 */
		II (c, d, a, b, s_packet[ 6], S43, 0xa3014314); /* 59 */
		II (b, c, d, a, s_packet[13], S44, 0x4e0811a1); /* 60 */
		II (a, b, c, d, s_packet[ 4], S41, 0xf7537e82); /* 61 */
		II (d, a, b, c, s_packet[11], S42, 0xbd3af235); /* 62 */
		II (c, d, a, b, s_packet[ 2], S43, 0x2ad7d2bb); /* 63 */
		II (b, c, d, a, s_packet[ 9], S44, 0xeb86d391); /* 64 */

		word[0] += a;
		word[1] += b;
		word[2] += c;
		word[3] += d;
		a = word[0],b = word[1],c = word[2], d = word[3];


	}

	string s1 = convertFinal(a);
	string s2 = convertFinal(b);
	string s3 = convertFinal(c);
	string s4 = convertFinal(d);

	string final = s1 + s2 + s3 + s4;
	//string final = s4+s3+s2+s1;
	return final;
}



int main(){




}
