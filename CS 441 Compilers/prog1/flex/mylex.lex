id		[a-zA-Z][a-zA-Z0-9]*
num		[0-9]+"."[0-9]*
letter		[a-zA-Z]
digit		[0-9]
%{
	int countId;
	int countNum;
%}





%%
{letter}({letter}|{digit})*		countId++;
{digit}+"."{digit}*				countNum++;
%%







main()
{
  yylex();
  printf("# ID: %d\n", countId); 
  printf("# num: %d\n", countNum);
  return 0;
}





