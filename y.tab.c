#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 3 "Parser.y"

	#include "ParseTree.h" 
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <iostream>

	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" void yyerror(char *s);
  
	/* these data structures hold the result of the parsing*/
	struct FuncOperator *finalFunction; /* the aggregate function (NULL if no agg)*/
	struct TableList *tables; /* the list of tables and aliases in the query*/
	struct AndList *boolean; /* the predicate in the WHERE clause*/
	struct NameList *groupingAtts; /* grouping atts (NULL if no grouping)*/
	struct NameList *attsToSelect; /* the set of attributes in the SELECT (NULL if no such atts)*/
	struct AttrList *newattrs;
	struct NameList *sortattrs;	
	int distinctAtts; /* 1 if there is a DISTINCT in a non-aggregate query */
	int distinctFunc;  /* 1 if there is a DISTINCT in an aggregate query*/
	char *newtable;
	char *newfile;
	char *oldtable;
	char *deoutput;

#line 32 "Parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
 	struct FuncOperand *myOperand;
	struct FuncOperator *myOperator; 
	struct TableList *myTables;
	struct ComparisonOp *myComparison;
	struct Operand *myBoolOperand;
	struct OrList *myOrList;
	struct AndList *myAndList;
	struct NameList *myNames;
	struct AttrList *myAttrList;
	struct NameList *mysortattrs;
	char *actualChars;
	char whichOne;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 68 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define Name 257
#define Float 258
#define Int 259
#define String 260
#define SELECT 261
#define GROUP 262
#define DISTINCT 263
#define BY 264
#define FROM 265
#define WHERE 266
#define SUM 267
#define AS 268
#define AND 269
#define OR 270
#define CREATE 271
#define TABLE 272
#define HEAP 273
#define INSERT 274
#define INTO 275
#define SET 276
#define OUTPUT 277
#define DROP 278
#define SORTED 279
#define ON 280
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,   11,   11,   12,
   12,   13,   13,   13,   13,   14,   14,   10,   10,    8,
    8,    4,    4,    4,    4,    4,    5,    5,    5,    5,
    2,    2,    1,    1,    7,    6,    6,    6,    9,    9,
    9,    9,    3,    3,    3,
};
static const short yylen[] = {                            2,
    7,   10,    9,   11,    5,    4,    4,    2,    4,    1,
    3,    3,    1,    1,    2,    4,    5,    1,    3,    3,
    5,    3,    5,    3,    1,    2,    1,    1,    1,    1,
    5,    3,    3,    1,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,   18,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   45,   43,   44,
    0,    0,    0,    0,   19,    0,    0,    0,    0,    0,
    7,    6,    0,    0,   26,   27,   28,   29,   30,    0,
   16,    0,    0,    0,    0,    0,    5,   17,    0,   22,
   20,    0,    0,    0,    0,    0,    0,   42,   40,   41,
   39,    0,    0,    0,    0,    1,    0,    0,    0,   23,
    0,    0,   36,   37,   38,    0,    0,   21,    9,    0,
    0,    0,   33,   35,    0,    3,    0,   31,    2,    0,
    0,    0,    4,   11,
};
static const short yydgoto[] = {                          6,
   72,   63,   33,   34,   50,   86,   73,   37,   74,   10,
   56,  101,   11,   12,
};
static const short yysindex[] = {                      -253,
 -247, -255, -224, -240, -234,    0,    0, -218,  -40,   -4,
 -223,   -1, -216, -231, -212, -211,   -4,    8,  -39, -208,
 -207, -218,   11, -205,   -6,   -5,  -39,    0,    0,    0,
  -39,  -39,  -16,   14,    0, -210,  -42,   -4, -201,   -2,
    0,    0,   18,   19,    0,    0,    0,    0,    0,  -39,
    0, -196,   22, -194, -193,   24,    0,    0,  -16,    0,
    0, -225,  -56, -202,   23, -200,  -39,    0,    0,    0,
    0,   28, -199,  -47, -192,    0, -187, -201, -251,    0,
 -195, -225,    0,    0,    0, -225, -218,    0,    0,   16,
 -204,   22,    0,    0,  -35,    0, -184,    0,    0,   33,
   20, -184,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -185,
    0, -183,    0,    0,    0,    0, -182,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   37,    0,    0,    0,    0, -180,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   40,    0,
    0,    0,    0,    0,   45,    0,    0,    0,    0,    0,
    0,    0,   46,    0,    0,    0,    0,    0,    0,    0,
  -55,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   29,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    7,    1,    0,  -20,   31,    0,    0,    0,    5,   -3,
   17,  -10,    0,    0,
};
#define YYTABLESIZE 224
static const short yytable[] = {                         19,
   31,   54,   76,   32,   17,   32,   43,    1,   20,    7,
   44,   45,   83,   85,   84,    8,   13,    2,   38,    9,
    3,   90,    4,   99,    5,   48,   47,   91,   46,   60,
   49,   68,   69,   70,   71,   14,   15,   16,    7,   20,
   23,   21,   22,   24,   25,   26,   80,   27,   35,   36,
   39,   40,   41,   42,   51,   55,   57,   52,   58,   59,
   61,   62,   64,   65,   66,   77,   78,   79,   81,   88,
   82,   87,  100,   92,   96,   97,  102,   25,  103,   14,
   24,   13,   15,   95,   12,    8,   34,   10,   93,   67,
   94,  104,   98,    0,   89,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   75,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   28,   29,   30,
    0,    0,   18,   53,
};
static const short yycheck[] = {                         40,
   40,   44,   59,   59,    8,   45,   27,  261,   44,  257,
   31,   32,   60,   61,   62,  263,  272,  271,   22,  267,
  274,  273,  276,   59,  278,   42,   43,  279,   45,   50,
   47,  257,  258,  259,  260,  260,  277,  272,  257,   44,
  257,  265,   44,  275,  257,  257,   67,   40,  257,  257,
   40,  257,   59,   59,   41,  257,   59,  268,   41,   41,
  257,   40,  257,  257,   41,  268,   44,  268,   41,  257,
  270,  264,  257,  269,   59,  280,   44,   41,   59,  265,
   41,  265,  265,   87,  265,   41,   41,   59,   82,   59,
   86,  102,   92,   -1,   78,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  262,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,  263,  266,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"Name","Float","Int","String","SELECT","GROUP","DISTINCT","BY",
"FROM","WHERE","SUM","AS","AND","OR","CREATE","TABLE","HEAP","INSERT","INTO",
"SET","OUTPUT","DROP","SORTED","ON",
};
static const char *yyrule[] = {
"$accept : SQL",
"SQL : SELECT WhatIWant FROM Tables WHERE AndList ';'",
"SQL : SELECT WhatIWant FROM Tables WHERE AndList GROUP BY Atts ';'",
"SQL : CREATE TABLE Name '(' NewAtts ')' AS HEAP ';'",
"SQL : CREATE TABLE Name '(' NewAtts ')' AS SORTED ON SortAtts ';'",
"SQL : INSERT String INTO Name ';'",
"SQL : DROP TABLE Name ';'",
"SQL : SET OUTPUT Name ';'",
"NewAtts : Name Name",
"NewAtts : Name Name ',' NewAtts",
"SortAtts : Name",
"SortAtts : Name ',' SortAtts",
"WhatIWant : Function ',' Atts",
"WhatIWant : Function",
"WhatIWant : Atts",
"WhatIWant : DISTINCT Atts",
"Function : SUM '(' CompoundExp ')'",
"Function : SUM DISTINCT '(' CompoundExp ')'",
"Atts : Name",
"Atts : Atts ',' Name",
"Tables : Name AS Name",
"Tables : Tables ',' Name AS Name",
"CompoundExp : SimpleExp Op CompoundExp",
"CompoundExp : '(' CompoundExp ')' Op CompoundExp",
"CompoundExp : '(' CompoundExp ')'",
"CompoundExp : SimpleExp",
"CompoundExp : '-' CompoundExp",
"Op : '-'",
"Op : '+'",
"Op : '*'",
"Op : '/'",
"AndList : '(' OrList ')' AND AndList",
"AndList : '(' OrList ')'",
"OrList : Condition OR OrList",
"OrList : Condition",
"Condition : Literal BoolComp Literal",
"BoolComp : '<'",
"BoolComp : '>'",
"BoolComp : '='",
"Literal : String",
"Literal : Float",
"Literal : Int",
"Literal : Name",
"SimpleExp : Float",
"SimpleExp : Int",
"SimpleExp : Name",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 465 "Parser.y"

#line 339 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 100 "Parser.y"
	{
	tables = yystack.l_mark[-3].myTables;
	boolean = yystack.l_mark[-1].myAndList;	
	groupingAtts = NULL;
        YYACCEPT;
}
break;
case 2:
#line 108 "Parser.y"
	{
	tables = yystack.l_mark[-6].myTables;
	boolean = yystack.l_mark[-4].myAndList;	
	groupingAtts = yystack.l_mark[-1].myNames;
        YYACCEPT;
}
break;
case 3:
#line 116 "Parser.y"
	{
	newtable = yystack.l_mark[-6].actualChars;
	newattrs = yystack.l_mark[-4].myAttrList;
        YYACCEPT;
}
break;
case 4:
#line 123 "Parser.y"
	{
	newtable = yystack.l_mark[-8].actualChars;
	newattrs = yystack.l_mark[-6].myAttrList;
	sortattrs = yystack.l_mark[-1].mysortattrs;
        YYACCEPT;
}
break;
case 5:
#line 131 "Parser.y"
	{
	newfile = yystack.l_mark[-3].actualChars;
	oldtable = yystack.l_mark[-1].actualChars;
        YYACCEPT;
}
break;
case 6:
#line 138 "Parser.y"
	{
	oldtable = yystack.l_mark[-1].actualChars;
        YYACCEPT;
}
break;
case 7:
#line 144 "Parser.y"
	{
	deoutput = yystack.l_mark[-1].actualChars;
        YYACCEPT;
}
break;
case 8:
#line 151 "Parser.y"
	{
	yyval.myAttrList = (struct AttrList *) malloc (sizeof (struct AttrList));
	yyval.myAttrList->name = yystack.l_mark[-1].actualChars;
	if(strcmp(yystack.l_mark[0].actualChars,"INTEGER")==0)
		yyval.myAttrList->type = 0;
	else if(strcmp(yystack.l_mark[0].actualChars,"DOUBLE")==0)
		yyval.myAttrList->type = 1;
	else if(strcmp(yystack.l_mark[0].actualChars,"STRING")==0)
		yyval.myAttrList->type = 2;
	/*$$->type = $2;*/
	yyval.myAttrList->next = NULL;
}
break;
case 9:
#line 165 "Parser.y"
	{
	yyval.myAttrList = (struct AttrList *) malloc (sizeof (struct AttrList));
	yyval.myAttrList->name = yystack.l_mark[-3].actualChars;
	if(strcmp(yystack.l_mark[-2].actualChars,"INTEGER")==0)
		yyval.myAttrList->type = 0;
	else if(strcmp(yystack.l_mark[-2].actualChars,"DOUBLE")==0)
		yyval.myAttrList->type = 1;
	else if(strcmp(yystack.l_mark[-2].actualChars,"STRING")==0)
		yyval.myAttrList->type = 2;
	/*$$->type = $4;*/
	yyval.myAttrList->next = yystack.l_mark[0].myAttrList;
}
break;
case 10:
#line 179 "Parser.y"
	{
	yyval.mysortattrs = (struct NameList *) malloc (sizeof (struct NameList));
	yyval.mysortattrs->name = yystack.l_mark[0].actualChars;
	yyval.mysortattrs->next = NULL;
}
break;
case 11:
#line 186 "Parser.y"
	{
	yyval.mysortattrs = (struct NameList *) malloc (sizeof (struct NameList));
	yyval.mysortattrs->name = yystack.l_mark[-2].actualChars;
	yyval.mysortattrs->next = yystack.l_mark[0].mysortattrs;
}
break;
case 12:
#line 193 "Parser.y"
	{
	attsToSelect = yystack.l_mark[0].myNames;
	distinctAtts = 0;
}
break;
case 13:
#line 199 "Parser.y"
	{
	attsToSelect = NULL;
}
break;
case 14:
#line 204 "Parser.y"
	{
	distinctAtts = 0;
	finalFunction = NULL;
	attsToSelect = yystack.l_mark[0].myNames;
}
break;
case 15:
#line 211 "Parser.y"
	{
	distinctAtts = 1;
	finalFunction = NULL;
	attsToSelect = yystack.l_mark[0].myNames;
	finalFunction = NULL;
}
break;
case 16:
#line 219 "Parser.y"
	{
	distinctFunc = 0;
	finalFunction = yystack.l_mark[-1].myOperator;
}
break;
case 17:
#line 225 "Parser.y"
	{
	distinctFunc = 1;
	finalFunction = yystack.l_mark[-1].myOperator;
}
break;
case 18:
#line 231 "Parser.y"
	{
	yyval.myNames = (struct NameList *) malloc (sizeof (struct NameList));
	yyval.myNames->name = yystack.l_mark[0].actualChars;
	yyval.myNames->next = NULL;
}
break;
case 19:
#line 238 "Parser.y"
	{
	yyval.myNames = (struct NameList *) malloc (sizeof (struct NameList));
	yyval.myNames->name = yystack.l_mark[0].actualChars;
	yyval.myNames->next = yystack.l_mark[-2].myNames;
}
break;
case 20:
#line 245 "Parser.y"
	{
	yyval.myTables = (struct TableList *) malloc (sizeof (struct TableList));
	yyval.myTables->tableName = yystack.l_mark[-2].actualChars;
	yyval.myTables->aliasAs = yystack.l_mark[0].actualChars;
	yyval.myTables->next = NULL;
}
break;
case 21:
#line 253 "Parser.y"
	{
	yyval.myTables = (struct TableList *) malloc (sizeof (struct TableList));
	yyval.myTables->tableName = yystack.l_mark[-2].actualChars;
	yyval.myTables->aliasAs = yystack.l_mark[0].actualChars;
	yyval.myTables->next = yystack.l_mark[-4].myTables;
}
break;
case 22:
#line 263 "Parser.y"
	{
	yyval.myOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));	
	yyval.myOperator->leftOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));
	yyval.myOperator->leftOperator->leftOperator = NULL;
	yyval.myOperator->leftOperator->leftOperand = yystack.l_mark[-2].myOperand;
	yyval.myOperator->leftOperator->right = NULL;
	yyval.myOperator->leftOperand = NULL;
	yyval.myOperator->right = yystack.l_mark[0].myOperator;
	yyval.myOperator->code = yystack.l_mark[-1].whichOne;	

}
break;
case 23:
#line 276 "Parser.y"
	{
	yyval.myOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));	
	yyval.myOperator->leftOperator = yystack.l_mark[-3].myOperator;
	yyval.myOperator->leftOperand = NULL;
	yyval.myOperator->right = yystack.l_mark[0].myOperator;
	yyval.myOperator->code = yystack.l_mark[-1].whichOne;	

}
break;
case 24:
#line 286 "Parser.y"
	{
	yyval.myOperator = yystack.l_mark[-1].myOperator;

}
break;
case 25:
#line 292 "Parser.y"
	{
	yyval.myOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));	
	yyval.myOperator->leftOperator = NULL;
	yyval.myOperator->leftOperand = yystack.l_mark[0].myOperand;
	yyval.myOperator->right = NULL;	

}
break;
case 26:
#line 301 "Parser.y"
	{
	yyval.myOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));	
	yyval.myOperator->leftOperator = yystack.l_mark[0].myOperator;
	yyval.myOperator->leftOperand = NULL;
	yyval.myOperator->right = NULL;	
	yyval.myOperator->code = '-';

}
break;
case 27:
#line 312 "Parser.y"
	{
	yyval.whichOne = '-';
}
break;
case 28:
#line 317 "Parser.y"
	{
	yyval.whichOne = '+';
}
break;
case 29:
#line 322 "Parser.y"
	{
	yyval.whichOne = '*';
}
break;
case 30:
#line 327 "Parser.y"
	{
	yyval.whichOne = '/';
}
break;
case 31:
#line 333 "Parser.y"
	{
        /* here we need to pre-pend the OrList to the AndList*/
        /* first we allocate space for this node*/
        yyval.myAndList = (struct AndList *) malloc (sizeof (struct AndList));

        /* hang the OrList off of the left*/
        yyval.myAndList->left = yystack.l_mark[-3].myOrList;

        /* hang the AndList off of the right*/
        yyval.myAndList->rightAnd = yystack.l_mark[0].myAndList;

}
break;
case 32:
#line 347 "Parser.y"
	{
        /* just return the OrList!*/
        yyval.myAndList = (struct AndList *) malloc (sizeof (struct AndList));
        yyval.myAndList->left = yystack.l_mark[-1].myOrList;
        yyval.myAndList->rightAnd = NULL;
}
break;
case 33:
#line 356 "Parser.y"
	{
        /* here we have to hang the condition off the left of the OrList*/
        yyval.myOrList = (struct OrList *) malloc (sizeof (struct OrList));
        yyval.myOrList->left = yystack.l_mark[-2].myComparison;
        yyval.myOrList->rightOr = yystack.l_mark[0].myOrList;
}
break;
case 34:
#line 364 "Parser.y"
	{
        /* nothing to hang off of the right*/
        yyval.myOrList = (struct OrList *) malloc (sizeof (struct OrList));
        yyval.myOrList->left = yystack.l_mark[0].myComparison;
        yyval.myOrList->rightOr = NULL;
}
break;
case 35:
#line 373 "Parser.y"
	{
        /* in this case we have a simple literal/variable comparison*/
        yyval.myComparison = yystack.l_mark[-1].myComparison;
        yyval.myComparison->left = yystack.l_mark[-2].myBoolOperand;
        yyval.myComparison->right = yystack.l_mark[0].myBoolOperand;
}
break;
case 36:
#line 382 "Parser.y"
	{
        /* construct and send up the comparison*/
        yyval.myComparison = (struct ComparisonOp *) malloc (sizeof (struct ComparisonOp));
        yyval.myComparison->code = LESS_THAN;
}
break;
case 37:
#line 389 "Parser.y"
	{
        /* construct and send up the comparison*/
        yyval.myComparison = (struct ComparisonOp *) malloc (sizeof (struct ComparisonOp));
        yyval.myComparison->code = GREATER_THAN;
}
break;
case 38:
#line 396 "Parser.y"
	{
        /* construct and send up the comparison*/
        yyval.myComparison = (struct ComparisonOp *) malloc (sizeof (struct ComparisonOp));
        yyval.myComparison->code = EQUALS;
}
break;
case 39:
#line 404 "Parser.y"
	{
        /* construct and send up the operand containing the string*/
        yyval.myBoolOperand = (struct Operand *) malloc (sizeof (struct Operand));
        yyval.myBoolOperand->code = STRING;
        yyval.myBoolOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 40:
#line 412 "Parser.y"
	{
        /* construct and send up the operand containing the FP number*/
        yyval.myBoolOperand = (struct Operand *) malloc (sizeof (struct Operand));
        yyval.myBoolOperand->code = DOUBLE;
        yyval.myBoolOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 41:
#line 420 "Parser.y"
	{
        /* construct and send up the operand containing the integer*/
        yyval.myBoolOperand = (struct Operand *) malloc (sizeof (struct Operand));
        yyval.myBoolOperand->code = INT;
        yyval.myBoolOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 42:
#line 428 "Parser.y"
	{
        /* construct and send up the operand containing the name*/
        yyval.myBoolOperand = (struct Operand *) malloc (sizeof (struct Operand));
        yyval.myBoolOperand->code = NAME;
        yyval.myBoolOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 43:
#line 440 "Parser.y"
	{
        /* construct and send up the operand containing the FP number*/
        yyval.myOperand = (struct FuncOperand *) malloc (sizeof (struct FuncOperand));
        yyval.myOperand->code = DOUBLE;
        yyval.myOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 44:
#line 448 "Parser.y"
	{
        /* construct and send up the operand containing the integer*/
        yyval.myOperand = (struct FuncOperand *) malloc (sizeof (struct FuncOperand));
        yyval.myOperand->code = INT;
        yyval.myOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 45:
#line 456 "Parser.y"
	{
        /* construct and send up the operand containing the name*/
        yyval.myOperand = (struct FuncOperand *) malloc (sizeof (struct FuncOperand));
        yyval.myOperand->code = NAME;
        yyval.myOperand->value = yystack.l_mark[0].actualChars;
}
break;
#line 941 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
