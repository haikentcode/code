

 # include <iostream.h>
 # include <fstream.h>
 # include <string.h>
 # include <stdlib.h>
 # include <stdio.h>
 # include <conio.h>
 # include <ctype.h>

 //--------------------------  Global Variables  ---------------/
  
 /

 constint iRows = 34;
 constint iCols = 15;

 int iTT[iRows][iCols] = {0};

 //------------------------  Function Definitions  *------------------/
 //-------------------- loadTransitionTable( )  ---------------------//
 void loadTransitionTable( )
 {
    fstream File("tt.txt", ios::in|ios::nocreate);

    if (!File)
    {
       cout << "\n Unable to open the input file." << endl;
       cout << "\n Press any key to exit.";

       getch( );
       exit(0);
    }

    char sInput[100]={NULL};

    for (int i = 0; i < iRows; i ++)
    {
       strset(sInput, NULL);

       File.getline(sInput, 80);

       char *sPtr=NULL;

       sPtr = strtok(sInput, " ");

       iTT[i][0] = atoi(sPtr);

       for(int j = 1; j < iCols; j ++)
       {
      sPtr=strtok(NULL, " ");

      iTT[i][j] = atoi(sPtr);
       }
    }

    File.close( );
 }

 //---------------------------  getNextState( )  -------------------------//

 int getNextState(int iState, char cChar)
 {
    if (isalpha(cChar))
       return iTT[iState][1];

    elseif (isdigit(cChar))
       return iTT[iState][2];

    elseif (cChar == '.')
       return iTT[iState][3];

    elseif (cChar == '"')
       return iTT[iState][4];

    elseif (cChar == '_')
       return iTT[iState][6];

    elseif (cChar == '+')
       return iTT[iState][7];

    elseif (cChar == '=')
       return iTT[iState][8];

    elseif (cChar == '-')
       return iTT[iState][9];

    elseif (cChar == '%')
       return iTT[iState][10];

    elseif (cChar == '!')
       return iTT[iState][11];

    elseif (cChar == '>')
       return iTT[iState][12];

    elseif (cChar == '<')
       return iTT[iState][13];

    elseif (cChar == '/')
       return iTT[iState][14];

    return iTT[iState][0];
 }

 //----------------------------  isKeyword( )  ----------------------------//

 int isKeyword(char* sToken)
 {
    if (strlen(sToken) > 16 || strlen(sToken) == 0)
       return 0;

    char sKeywords[64][20] = {
                   "asm","auto","bool","break","case","catch",
                   "char","class","const","const_cast",
                   "continue","default","delete","do","double",
                   "dynamic_cast","else","enum","explicit",
                   "export","extern","false","float","for",
                   "friend","goto","if","inline","int","long",
                   "main","mutable","namespace","new",
                   "operator","private","protected","public",
                   "register","reinterpret_cast","return",
                   "short","signed","sizeof","static",
                   "static_cast","struct","switch","template",
                   "this","throw","true","try","typedef",
                   "typeid","typename","union","unsigned","using",
                   "virtual","void","volatile","wchar_t","while"
                 };

    for(int iCount = 0; iCount < 64; iCount ++)
    {
       if (strcmpi(sKeywords[iCount], sToken) == 0)
      return 1;
    }

    return 0;
 }

 /*************************************************************************/
 //-------------------------------  main( )  -----------------------------/
//*************************************************************************/
 int main( )
 {
    clrscr( );

    loadTransitionTable( );

    fstream File("input.txt", ios::in|ios::nocreate);

    if (!File)
    {
       cout<<"\n Unable to open the input file."<<endl;
       cout<<"\n Press any key to exit.";

       getch( );
       exit(0);
    }

    char sToken[255] = {NULL};
    int iTokenIndex = 0;

    char cChar = NULL;
    int iState = 0;
    int iFlag = 0;

    char cTemp = File.get( );

    do
    {
       Start:

       if (iFlag == 0)
       {
      cChar = cTemp;
      cTemp = File.get( );
       }

       else
      iFlag = 0;

       if (cChar == '/' && cTemp == '/')
       {
      while(File.get( ) != '\n')
      {
         if (File.eof( ))
        goto End;
      }

      cout<<'\r';

      cTemp = File.get( );

      goto Start;
       }

       if (cChar == '/' && cTemp == '*')
       {
      cTemp = File.get( );

      do
      {
         cChar = cTemp;
         cTemp = File.get( );

         if (File.eof( ))
        goto End;
      }
      while(cChar != '*' && cTemp != '/');

      cout<<'\r';

      cTemp = File.get( );

      goto Start;
       }

       iState = getNextState(iState, cChar);

       switch (iState)
       {
      case  0 :  cout << cChar;

             iState = 0;
             iTokenIndex = 0;

             strset(sToken, NULL);

             break;

      case  1 :
      case  3 :
      case  5 :
      case  7 :
      case 10 :
      case 14 :
      case 18 :
      case 25 :
      case 26 :  sToken[iTokenIndex] = cChar;
             iTokenIndex ++;

             break;

      case  2 :  if (isKeyword(sToken))
            cout << sToken;

             else
            cout << "<ID>";

             iState = 0;
             iTokenIndex = 0;
             iFlag = 1;

             strset(sToken, NULL);

             break;

      case  4 :  cout << "<INT>";

             iState = 0;
             iTokenIndex = 0;
             iFlag = 1;

             strset(sToken, NULL);

             break;

      case  6 :  cout << "<FLOAT>";

             iState = 0;
             iTokenIndex = 0;
             iFlag = 1;

             strset(sToken, NULL);

             break;

      case  8 :  cout << "<STR>";

             iState = 0;
             iTokenIndex = 0;

             strset(sToken, NULL);

             break;

      case  9 :
      case 11 :
      case 12 :
      case 13 :
      case 15 :
      case 16 :
      case 17 :
      case 19 :
      case 20 :
      case 21 :
      case 22 :
      case 23 :
      case 24 :
      case 27 :
      case 28 :  cout << "<OPR>";

             if (cChar != '+' && cChar != '-' && cChar != '/'
                && cChar != '>' && cChar != '<' && cChar != '=')
            iFlag = 1;

             iState = 0;
             iTokenIndex = 0;

             strset(sToken, NULL);

             break;

      case 30 :
      case 33 :  iState = 0;
             iTokenIndex = 0;

             strset(sToken, NULL);

             break;
       }
    }
    while(!File.eof( ));

    End:

    getch( );
    return 0;
 }
