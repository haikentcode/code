#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* The grammar follwed by this analyser is : you have to give a blank to 
   differentite between two different entities, for eg 
   instead of writing "int c=a+b;", write it as "int c = a + b ;".
   
   To execute this program first create an "input.txt" 
   file where the program is written or specify the path of the file which has 
   to be analysed, after compiling an "output.txt" file will be created where you 
   have stored the program.

*/

bool keycheck(string str)
{
     string keyword[] ={"int","main()","float","if"};
  
     int flag=0;
     if(!(str[0]>=97 && str[0]<=122))
                     return false;
      for(int i=0;i<4;i++)
      {
             if(str == keyword[i])
              {     
                     flag = 1;
                     break;
              }
      }
     

     
     if(flag == 1)
             return true;
     else
             return false;
} 

string opcheck(string str)
{
     string reloperators[8] ={"=","==",">","<",">=","<="};
     string mathoperators[5] ={"+","*","/","-","%"};
     string operators[4]={"{","}",";",","};
     int flag1=0,flag2=0,flag=0;
     
    
    for(int i=0;i<4;i++)
    {
            if(str == operators[i])
            {
                   flag = 1;
                   break;
            }
    }
    if(flag == 1)
    {
            return "operator";
    }
    else
    {
    
        for(int i=0;i<8;i++)
         {       
             if(str == reloperators[i])
             {
                    flag1 = 1;
                    break;
             }
         }
         if(flag1 == 1)
         {
             return "relational operator";
         }
         else
         {
          for(int i=0;i<5;i++)
          {       
             if(str == mathoperators[i])
             {
                    flag2 =1;
                    break;
             }
          }
          
          if(flag2 == 1)
                  return "mathematical operator";
          else
                  return "error";
     }
    }
}
                   
         
             
int ischar(char c)
{
     if((c>=65 && c<=90) || (c>=97 && c<=122))
             return 1;
    else
             return 0; 
}          
                     

int isnum(char c)
{
    if(c>=48 && c<=57)
             return 1;
    else
             return 0;
}
    
int isnums(string str)
{
    int flag=0;
    for(int i = 0;i<str.length();i++)
    {
         if(!isnum(str[i]))
         {
                           if(str[i] != 46) 
                           {
                                     flag=1;
                                     break;
                           }
         }
    }
    
    if(flag == 1)
            return 0;
    else
            return 1;
}

int isidentifier(string str)
{
    int flag =0;
     for(int i=1;i<str.length();i++)
     {
      if(!ischar(str[i]))
      {
       if(!isnum(str[i]))
       {
        if(str[i] != 95)
        {
           if(str[i] == 91)
           {
                     i++;
                     for(;str[i]!= 93;)
                     {
                      if(!isnum(str[i]))
                      {
                                        flag =1;
                                        break;
                      }
                      i++;
                     }
           }
           else
           {         
                     flag = 1;
                     
           }
           
           if(flag ==1)
                   break;
        }
      }
     }
    }
    
    return flag;
}


             
                                                        
int main(int argc,char *argv[])
{
    ifstream ifs(argv[1]);
    ofstream ofs("output.txt");
    int line=0,flag=0;
    bool check;
    string str="",strch,strline;
   
   
   
    
    while(!ifs.eof())
    {
                      
    getline(ifs,strline);
    line++;
     ofs<<"---------\n";
    ofs<<line<<"\n";
   
    strline = strline + " ";
    for(int j=0;j<strline.length();j++)
    {       
            if(strline[j] ==' ' || strline[j]=='\t')
            {
                                    
                      
              
                      
                     if(str != "")
                     {
                      if(ischar(str[0]))
                      {
                                    check = keycheck(str);
                                    
                                    if(check)
                                    {
                                            ofs<<str<<"\t --> reserved word\n";  
                                    }        
                                    else
                                    {
                                      
                                        flag = isidentifier(str);
                                        
                                        if(flag == 1)
                                        {
                                                ofs<<str<<"\t --> error\n";
                                                flag = 0;
                                        
                                        }
                                        else
                                        {
                                            ofs<<str<<"\t --> identifier\n";
                                        }
                                    }
                                                                                             
                      
                                           
                      }
                      else
                      {
                          if(isnum(str[0]))
                          {
                                          if(isnums(str))
                                                         ofs<<str<<"\t -->number\n";
                                          else
                                                         ofs<<str<<"\t -->error\n";
                          }
                          else
                          {
                              strch = opcheck(str);
                              if(strch == "error")
                                     ofs<<str<<"\t -->"<<strch<<"\n";
                              else
                                     ofs<<str<<"\t -->"<<strch<<"\n";
                          }
                      } 
                      
                     }
                      
                     str="";  
            }
           else
            {
               str=str+strline[j];    
            }    
     }      
                      
    
                      
    
    }
    
    
    cout<<"output file is generated : output.txt";
    
    
    //getch();
    return 0;
}
    
