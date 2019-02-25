%option noyywrap
%{
#include "token.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* {return id;}
"+" {return '+';}
"-" {return '-';}
"(" {return '(';}
")" {return ')';}
%%
