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
extern YYSTYPE yylval;
