/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "P1.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	int yylex();
	int yyerror();

	typedef struct Macro_
	{
		char *id;
		char *replaceWith;
		char **argList;
		int num_arg;
		bool type;
	}Macro;
	Macro List[10000];
	int num_macros = 0;

	char** getList(char *args,int *n)
	{

		int i;
		//size of list
		int l = strlen(args);
		*n = 1;
		for(i = 0;i < l;i++)
		{
			if(args[i] == ',')
			{
				(*n)++;
			}
		}
		if(strcmp(args,"") == 0)
		{
			*n = 0;
		}
		char **list = (char**)malloc((*n)*sizeof(char*));
		for(i = 0;i < *n;i++)
		{
			list[i] = (char*)malloc((l)*sizeof(char));
		}
		int j = 0,k = 0;
		for(i = 0;i < l;i++)
		{
			if(args[i] == ',')
			{
				list[j][k] = '\0';
				k = 0;
				j++;
			}
			else
			{
				list[j][k] = args[i];
				k++;
			}
		}
		return list;
	}
	void addMacro(char *id,char *args,bool type,char *replaceWith)
	{
		//we need to check if the Macro is already present
		int i = 0;
		for(i = 0;i < num_macros;i++)
		{
			if(strcmp(id,List[i].id) == 0)
			{
				printf("Failed, macro already present\n");
				exit(0);
			}
		}
		//if id is not already present
		int n;
		List[num_macros].id = id;
		List[num_macros].argList = getList(args,&n);
		List[num_macros].replaceWith = replaceWith;
		List[num_macros].type = type;
		List[num_macros].num_arg = n;
		num_macros++;
		if(!type)
		{
			//printf("added Macrostatement\n");
			//printf("%d\n",num_macros);
		}
		else
		{
			//printf("added MacroExpression\n");
			//printf("%d\n",num_macros);
		}
	}

	char *replace(char *id,char *args,bool type)
	{
		//first we have to find the index of id
		int index = 0;
		bool flag = false;
		for(index = 0;index < num_macros;index++)
		{
			if(strcmp(id,List[index].id) == 0)
			{
				flag = true;
				break;
			}
		}
		// int i = 0;
		// printf("printing macros\n");
		// for(i = 0;i < num_macros;i++)
		// {
		// 	printf("%s\n",List[i].id);
		// }
		// printf("%s\n",id);
		//if the id is not present in the array, then it should be an error
		if(!flag)
		{
			if(!type)
			{
				printf("Failed,macro is absent, unable to replace in Macrostatement\n");
			}
			else
			{
				printf("Failed,macro is absent, unable to replace in MacroExpression\n");	
			}
			exit(0);
		}
		if(strcmp(args,"") == 0)
		{
			if(List[index].num_arg == 0)
			{
				return List[index].replaceWith;
			}
			else
			{
				printf("Failed,Incorrect arguments passed in replace\n");
				exit(0);
			}
		}
		int n;
		char **argList = getList(args,&n);
		if(n != List[index].num_arg)
		{
			printf("Failed to parse MacorJava\n");
			exit(0);
		}
		char *ans = (char*)malloc(10000*sizeof(char));
		strcpy(ans,List[index].replaceWith);
	}

#line 214 "P1.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "P1.tab.h".  */
#ifndef YY_YY_P1_TAB_H_INCLUDED
# define YY_YY_P1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SCOLON = 258,
    CLASS = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    LPAREN = 263,
    RPAREN = 264,
    LFPAREN = 265,
    RFPAREN = 266,
    LSPAREN = 267,
    RSPAREN = 268,
    GT = 269,
    LT = 270,
    EQ = 271,
    PLUS = 272,
    MINUS = 273,
    DIV = 274,
    MUL = 275,
    COMMA = 276,
    PUBLIC = 277,
    STATIC = 278,
    VOID = 279,
    MAIN = 280,
    NEW = 281,
    EXTENDS = 282,
    THIS = 283,
    DEFINE = 284,
    TRUE = 285,
    FALSE = 286,
    BOOL = 287,
    AND = 288,
    OR = 289,
    NOT = 290,
    DOT = 291,
    LENGTH = 292,
    SYSTEM = 293,
    INT = 294,
    OTHER = 295,
    IDENTIFIER = 296,
    NUM = 297,
    STRING = 298,
    RETURN = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 148 "P1.y" /* yacc.c:355  */

	char *str;

#line 303 "P1.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P1_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 320 "P1.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   177,   184,   195,   196,   198,   198,   200,
     206,   208,   214,   220,   226,   232,   238,   244,   250,   256,
     262,   268,   274,   281,   287,   293,   293,   299,   305,   312,
     318,   325,   331,   337,   343,   349,   351,   357,   363,   369,
     375,   377,   383,   384,   385,   391,   392,   399,   405,   411,
     418,   419,   420,   424,   431,   437,   439,   445,   451,   453,
     463,   469,   471,   478,   488,   494
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCOLON", "CLASS", "IF", "ELSE", "WHILE",
  "LPAREN", "RPAREN", "LFPAREN", "RFPAREN", "LSPAREN", "RSPAREN", "GT",
  "LT", "EQ", "PLUS", "MINUS", "DIV", "MUL", "COMMA", "PUBLIC", "STATIC",
  "VOID", "MAIN", "NEW", "EXTENDS", "THIS", "DEFINE", "TRUE", "FALSE",
  "BOOL", "AND", "OR", "NOT", "DOT", "LENGTH", "SYSTEM", "INT", "OTHER",
  "IDENTIFIER", "NUM", "STRING", "RETURN", "$accept", "goal", "prog",
  "MainClass", "MacroDefinationstar", "MacroDefination", "StatementStar",
  "Expression", "Statement", "$@1", "CommaIdentifierStar",
  "MacroDefStatement", "MacroDefExpression", "CommaExpressionStar",
  "PrimaryExpression", "Type", "TypeIdentifierStar", "CommaTypeIdentifier",
  "MethodDeclaration", "MethodDeclarationStar", "TypeDeclaration",
  "TypeDeclarationStar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -118

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -118,     8,  -118,     1,  -118,   -28,   -27,    16,  -118,  -118,
    -118,    18,    25,    -5,    16,  -118,    28,    -1,    -4,  -118,
      41,    30,    54,  -118,    31,    45,    -1,    11,    55,    63,
      59,  -118,    40,    24,     0,  -118,    68,  -118,    44,    64,
      82,  -118,    83,    40,     6,  -118,  -118,  -118,    40,    94,
    -118,    95,    80,    98,    99,    24,   100,    93,    92,    24,
      69,   106,   108,  -118,  -118,    55,    78,   113,   111,   116,
    -118,    40,  -118,    48,   110,    48,    48,    48,    48,    96,
      97,   112,    86,  -118,    40,    40,   119,    40,    40,    40,
      40,  -118,  -118,   124,  -118,  -118,   122,   123,  -118,    40,
     125,   115,   130,  -118,   127,    48,  -118,  -118,  -118,  -118,
      48,    48,    48,   133,   134,   135,  -118,   136,   137,   129,
     144,     0,  -118,   138,   139,  -118,    40,  -118,  -118,  -118,
    -118,  -118,  -118,    40,    24,    24,   145,   146,   140,  -118,
     109,   148,   114,  -118,  -118,   149,   147,  -118,  -118,  -118,
      40,   141,   150,   152,  -118,    24,  -118,   151,     0,  -118,
     153,  -118,  -118,  -118,     5,   121,    93,   120,   157,    40,
      40,   163,   158,   159,   165,  -118,   160,   161,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     0,     1,     0,     0,    65,     5,     8,
       7,     0,     0,     0,    65,     3,     0,    35,     0,    64,
       0,    34,     0,    55,     0,     0,    35,     0,    61,     0,
       0,    33,     0,    10,     0,    51,    50,    53,     0,    61,
       0,    55,     0,     0,     0,    45,    42,    43,     0,    44,
      41,     0,    21,     0,     0,    10,     0,     0,     0,    10,
       0,     0,     0,    60,    62,    61,     0,     0,     0,     0,
      48,    40,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    40,     0,
       0,    36,     9,     0,    52,    54,     0,     0,    49,     0,
       0,    39,     0,    44,     0,     0,    15,    16,    18,    17,
       0,     0,     0,     0,     0,     0,    24,     0,     0,     0,
       0,    58,    63,     0,     0,    47,    40,    23,    19,    14,
      11,    12,    13,    40,     0,     0,     0,     0,     0,    27,
       0,     0,     0,    46,    38,     0,    29,    31,    25,    32,
       0,    56,     0,     0,    22,     0,    26,     0,    58,    55,
       0,    30,    28,    57,    10,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,    59,     0,     0,     4
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,  -118,  -118,   -52,   -32,  -117,  -118,
     143,  -118,  -118,   -84,   -51,   -33,   -39,    15,  -118,   -30,
    -118,   162
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     3,     8,    58,   101,    59,   156,
      22,     9,    10,   102,    52,    38,    28,   141,    39,    40,
      14,    15
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    60,    65,    86,   118,     5,    23,    92,     4,    63,
      53,    67,    54,    11,    12,    55,    70,   146,   147,    32,
      13,    33,   104,    24,   106,   107,   108,   109,    16,    53,
       6,    54,    35,    17,    55,    96,    18,    35,   161,    36,
      21,    37,   144,    56,    36,    68,   166,    69,    43,   145,
      20,    26,   114,   115,   129,   117,    43,   119,   120,   130,
     131,   132,    56,    27,    25,    57,    44,   124,    45,    30,
      46,    47,    29,    41,    44,    48,    45,    34,    46,    47,
      61,    49,    50,    48,    42,    62,    34,    35,   140,   103,
      50,    66,    73,    64,    36,    74,    37,    75,    76,    77,
      78,    88,    71,    91,    72,    89,    84,    85,    87,    90,
      93,    95,   167,    79,    80,    81,    82,    83,   157,    94,
     164,    97,    98,    99,   100,   140,   105,   113,   112,   110,
     116,   111,   121,   122,   125,   123,   126,   171,   172,   127,
     128,   133,   138,   134,   135,   136,   137,   139,   148,   149,
     151,   142,   143,   155,   162,   153,   150,   152,   154,   168,
     159,   160,   158,   165,   169,   170,   173,   174,   176,    31,
     175,   177,   178,   163,     0,     0,    19
};

static const yytype_int16 yycheck[] =
{
      32,    34,    41,    55,    88,     4,    10,    59,     0,    39,
       5,    43,     7,    41,    41,    10,    48,   134,   135,     8,
       4,    10,    73,    27,    75,    76,    77,    78,    10,     5,
      29,     7,    32,     8,    10,    65,    41,    32,   155,    39,
      41,    41,   126,    38,    39,    39,    41,    41,     8,   133,
      22,    21,    84,    85,   105,    87,     8,    89,    90,   110,
     111,   112,    38,     9,    23,    41,    26,    99,    28,    24,
      30,    31,    41,    10,    26,    35,    28,    22,    30,    31,
      12,    41,    42,    35,    25,    41,    22,    32,   121,    41,
      42,     8,    12,    11,    39,    15,    41,    17,    18,    19,
      20,     8,     8,    11,     9,    12,     8,     8,     8,    16,
      41,     3,   164,    33,    34,    35,    36,    37,   150,    13,
     159,    43,     9,    12,     8,   158,    16,    41,    16,    33,
      11,    34,     8,    11,     9,    12,    21,   169,   170,     9,
      13,     8,    13,     9,     9,     9,     9,     3,     3,     3,
      41,    13,    13,     6,     3,    41,    16,     9,     9,    38,
      10,     9,    21,    10,    44,     8,     3,     9,     3,    26,
      11,    11,    11,   158,    -1,    -1,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,    49,     0,     4,    29,    48,    50,    56,
      57,    41,    41,     4,    65,    66,    10,     8,    41,    66,
      22,    41,    55,    10,    27,    23,    21,     9,    61,    41,
      24,    55,     8,    10,    22,    32,    39,    41,    60,    63,
      64,    10,    25,     8,    26,    28,    30,    31,    35,    41,
      42,    52,    59,     5,     7,    10,    38,    41,    51,    53,
      60,    12,    41,    64,    11,    61,     8,    52,    39,    41,
      52,     8,     9,    12,    15,    17,    18,    19,    20,    33,
      34,    35,    36,    37,     8,     8,    51,     8,     8,    12,
      16,    11,    51,    41,    13,     3,    64,    43,     9,    12,
       8,    52,    58,    41,    59,    16,    59,    59,    59,    59,
      33,    34,    16,    41,    52,    52,    11,    52,    58,    52,
      52,     8,    11,    12,    52,     9,    21,     9,    13,    59,
      59,    59,    59,     8,     9,     9,     9,     9,    13,     3,
      60,    62,    13,    13,    58,    58,    53,    53,     3,     3,
      16,    41,     9,    41,     9,     6,    54,    52,    21,    10,
       9,    53,     3,    62,    61,    10,    41,    51,    38,    44,
       8,    52,    52,     3,     9,    11,     3,    11,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    54,    53,    53,    53,    53,
      53,    53,    53,    55,    55,    55,    56,    57,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    63,
      64,    64,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,    21,     2,     0,     1,     1,     2,
       0,     4,     4,     4,     4,     3,     3,     3,     3,     4,
       2,     1,     6,     4,     3,     0,     6,     4,     7,     5,
       7,     5,     5,     3,     1,     0,     8,     8,     3,     1,
       0,     1,     1,     1,     1,     1,     5,     4,     2,     3,
       1,     1,     3,     1,     4,     0,     2,     4,     0,    13,
       2,     0,     6,     8,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 175 "P1.y" /* yacc.c:1646  */
    {printf("%s\n",(yyvsp[0].str));}
#line 1510 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 178 "P1.y" /* yacc.c:1646  */
    {
				(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 10)*sizeof(char));
				strcpy((yyval.str),(yyvsp[-1].str));strcat((yyval.str),(yyvsp[0].str));
				free((yyvsp[-1].str));free((yyvsp[0].str));
			}
#line 1520 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 186 "P1.y" /* yacc.c:1646  */
    {
				int l = strlen((yyvsp[-19].str)) + strlen((yyvsp[-9].str)) + strlen((yyvsp[-4].str)) + 100;
				(yyval.str) = (char*)malloc(l*sizeof(char));
				strcpy((yyval.str),"class ");strcat((yyval.str),(yyvsp[-19].str));strcat((yyval.str),"\n{\npublic static void main(String[] ");
				strcat((yyval.str),(yyvsp[-9].str));strcat((yyval.str),")\n{\n\tSystem.out.println(");strcat((yyval.str),(yyvsp[-4].str));
				strcat((yyval.str),");\n}\n}\n");
				free((yyvsp[-19].str));free((yyvsp[-9].str));free((yyvsp[-4].str));
			}
#line 1533 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 196 "P1.y" /* yacc.c:1646  */
    {;}
#line 1539 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 201 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 10)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-1].str));strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-1].str));free((yyvsp[0].str));
					}
#line 1549 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 206 "P1.y" /* yacc.c:1646  */
    {(yyval.str)=(char*)malloc(2*sizeof(char));strcpy((yyval.str),"");}
#line 1555 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 209 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-3].str));strcat((yyval.str),"&&");strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-3].str));free((yyvsp[0].str));
					}
#line 1565 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 215 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-3].str));strcat((yyval.str),"||");strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-3].str));free((yyvsp[0].str));
					}
#line 1575 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 221 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-3].str));strcat((yyval.str),"!=");strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-3].str));free((yyvsp[0].str));
					}
#line 1585 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 227 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-3].str));strcat((yyval.str),"<=");strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-3].str));free((yyvsp[0].str));
					}
#line 1595 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 233 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-2].str));strcat((yyval.str),"+");strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-2].str));free((yyvsp[0].str));
					}
#line 1605 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 239 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-2].str));strcat((yyval.str),"-");strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-2].str));free((yyvsp[0].str));
					}
#line 1615 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 245 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-2].str));strcat((yyval.str),"*");strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-2].str));free((yyvsp[0].str));
					}
#line 1625 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 251 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-2].str));strcat((yyval.str),"/");strcat((yyval.str),(yyvsp[0].str));
						free((yyvsp[-2].str));free((yyvsp[0].str));
					}
#line 1635 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 257 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + strlen((yyvsp[-1].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-3].str));strcat((yyval.str),"[");strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),"]");
						free((yyvsp[-3].str));free((yyvsp[-1].str));
					}
#line 1645 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 263 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-1].str));strcat((yyval.str),".length");
						free((yyvsp[-1].str));
					}
#line 1655 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 269 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[0].str)) + 20)*sizeof(char));
						strcpy((yyval.str),(yyvsp[0].str));
						free((yyvsp[0].str));
					}
#line 1665 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 275 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-5].str)) + strlen((yyvsp[-3].str)) + strlen((yyvsp[-1].str)) + 30)*sizeof(char));
						strcpy((yyval.str),(yyvsp[-5].str));strcat((yyval.str),".");strcat((yyval.str),(yyvsp[-3].str));
						strcat((yyval.str),"(");strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),")");
						free((yyvsp[-5].str));free((yyvsp[-3].str));free((yyvsp[-1].str));
					}
#line 1676 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 282 "P1.y" /* yacc.c:1646  */
    {
						//here i need to replace this production(MacroExpression)
						(yyval.str) = replace((yyvsp[-3].str),(yyvsp[-1].str),true);
					}
#line 1685 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 288 "P1.y" /* yacc.c:1646  */
    {
					(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + 30)*sizeof(char));
					strcpy((yyval.str),"{");strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),"}\n");
					free((yyvsp[-1].str));
				}
#line 1695 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 293 "P1.y" /* yacc.c:1646  */
    {/*what happens when you macro the print*/;}
#line 1701 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 294 "P1.y" /* yacc.c:1646  */
    {
					(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + 40)*sizeof(char));
					strcpy((yyval.str),"System.out.println(");strcat((yyval.str),(yyvsp[-3].str));strcat((yyval.str),");\n");
					free((yyvsp[-3].str));
				}
#line 1711 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 300 "P1.y" /* yacc.c:1646  */
    {
					(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + strlen((yyvsp[-1].str)) + 30)*sizeof(char));
					strcpy((yyval.str),(yyvsp[-3].str));strcat((yyval.str)," = ");strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),";\n");
					free((yyvsp[-3].str));free((yyvsp[-1].str));
				}
#line 1721 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 306 "P1.y" /* yacc.c:1646  */
    {
					(yyval.str) = (char*)malloc((strlen((yyvsp[-6].str)) + strlen((yyvsp[-4].str)) + strlen((yyvsp[-1].str)) + 30)*sizeof(char));
					strcpy((yyval.str),(yyvsp[-6].str));strcat((yyval.str),"[");strcat((yyval.str),(yyvsp[-4].str));strcat((yyval.str),"] = ");
					strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),";\n");
					free((yyvsp[-6].str));free((yyvsp[-4].str));free((yyvsp[-1].str));
				}
#line 1732 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 313 "P1.y" /* yacc.c:1646  */
    {
					(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 30)*sizeof(char));
					strcpy((yyval.str),"if(");strcat((yyval.str),(yyvsp[-2].str));strcat((yyval.str),")\n");strcat((yyval.str),(yyvsp[0].str));
					free((yyvsp[-2].str));free((yyvsp[0].str));
				}
#line 1742 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 319 "P1.y" /* yacc.c:1646  */
    {
					(yyval.str) = (char*)malloc((strlen((yyvsp[-4].str)) + strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 30)*sizeof(char));
					strcpy((yyval.str),"if(");strcat((yyval.str),(yyvsp[-4].str));strcat((yyval.str),")");strcat((yyval.str),(yyvsp[-2].str));
					strcat((yyval.str),"else ");strcat((yyval.str),(yyvsp[0].str));
					free((yyvsp[-4].str));free((yyvsp[-2].str));free((yyvsp[0].str));
				}
#line 1753 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 326 "P1.y" /* yacc.c:1646  */
    {
					(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 30)*sizeof(char));
					strcpy((yyval.str),"while(");strcat((yyval.str),(yyvsp[-2].str));strcat((yyval.str),")");strcat((yyval.str),(yyvsp[0].str));
					free((yyvsp[-2].str));free((yyvsp[0].str));
				}
#line 1763 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 332 "P1.y" /* yacc.c:1646  */
    {
					//here i need to replace this production(Macrostatement)
					(yyval.str) = replace((yyvsp[-4].str),(yyvsp[-2].str),false);
				}
#line 1772 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 338 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 10)*sizeof(char));
							strcpy((yyval.str),(yyvsp[-2].str));strcat((yyval.str),",");strcat((yyval.str),(yyvsp[0].str));
							free((yyvsp[-2].str));free((yyvsp[0].str));
						}
#line 1782 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 344 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc(strlen((yyvsp[0].str))*sizeof(char));
							strcpy((yyval.str),(yyvsp[0].str));
							free((yyvsp[0].str));
						}
#line 1792 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 349 "P1.y" /* yacc.c:1646  */
    {(yyval.str)=(char*)malloc(2*sizeof(char));strcpy((yyval.str),"");}
#line 1798 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 352 "P1.y" /* yacc.c:1646  */
    {
							//need to add the macro of type 0
							addMacro((yyvsp[-6].str),(yyvsp[-4].str),false,(yyvsp[-1].str));
						}
#line 1807 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 358 "P1.y" /* yacc.c:1646  */
    {
							//need to add macro of type 1
							addMacro((yyvsp[-6].str),(yyvsp[-4].str),true,(yyvsp[-1].str));
						}
#line 1816 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 364 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 10)*sizeof(char));
							strcpy((yyval.str),(yyvsp[-2].str));strcat((yyval.str),",");strcat((yyval.str),(yyvsp[0].str));
							free((yyvsp[-2].str));free((yyvsp[0].str));
						}
#line 1826 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 370 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc(strlen((yyvsp[0].str))*sizeof(char));
							strcpy((yyval.str),(yyvsp[0].str));
							free((yyvsp[0].str));
						}
#line 1836 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 375 "P1.y" /* yacc.c:1646  */
    {(yyval.str)=(char*)malloc(2*sizeof(char));strcpy((yyval.str),"");}
#line 1842 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 378 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[0].str)) + 5)*sizeof(char));
							strcpy((yyval.str),(yyvsp[0].str));
							free((yyvsp[0].str));
						}
#line 1852 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 383 "P1.y" /* yacc.c:1646  */
    {(yyval.str) = (char*)malloc(10*sizeof(char));strcpy((yyval.str),"true");}
#line 1858 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 384 "P1.y" /* yacc.c:1646  */
    {(yyval.str) = (char*)malloc(10*sizeof(char));strcpy((yyval.str),"false");}
#line 1864 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 386 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[0].str)) + 5)*sizeof(char));
							strcpy((yyval.str),(yyvsp[0].str));
							free((yyvsp[0].str));
						}
#line 1874 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 391 "P1.y" /* yacc.c:1646  */
    {(yyval.str) = (char*)malloc(10*sizeof(char));strcpy((yyval.str),"this");}
#line 1880 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 393 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + 30)*sizeof(char));
							strcpy((yyval.str),"new ");strcat((yyval.str),"int");strcat((yyval.str),"[");
							strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),"]");
							free((yyvsp[-1].str));
						}
#line 1891 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 400 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-2].str)) + 20)*sizeof(char));
							strcpy((yyval.str),"new ");strcat((yyval.str),(yyvsp[-2].str));strcat((yyval.str),"()");
							free((yyvsp[-2].str));
						}
#line 1901 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 406 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[0].str)) + 20)*sizeof(char));
							strcpy((yyval.str),"!");strcat((yyval.str),(yyvsp[0].str));
							free((yyvsp[0].str));
						}
#line 1911 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 412 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + 20)*sizeof(char));
							strcpy((yyval.str),"(");strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),")");
							free((yyvsp[-1].str));
						}
#line 1921 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 418 "P1.y" /* yacc.c:1646  */
    {(yyval.str) = (char*)malloc(10*sizeof(char));strcpy((yyval.str),"int");}
#line 1927 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 419 "P1.y" /* yacc.c:1646  */
    {(yyval.str) = (char*)malloc(10*sizeof(char));strcpy((yyval.str),"boolean");}
#line 1933 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 421 "P1.y" /* yacc.c:1646  */
    {
				(yyval.str) = (char*)malloc(10*sizeof(char));strcpy((yyval.str),"int[]");
			}
#line 1941 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 425 "P1.y" /* yacc.c:1646  */
    {
				(yyval.str) = (char*)malloc((strlen((yyvsp[0].str)) + 5)*sizeof(char));
				strcpy((yyval.str),(yyvsp[0].str));
				free((yyvsp[0].str));
			}
#line 1951 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 432 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + strlen((yyvsp[-2].str)) + strlen((yyvsp[-1].str)) + 10)*sizeof(char));
							strcpy((yyval.str),(yyvsp[-3].str));strcat((yyval.str),(yyvsp[-2].str));strcat((yyval.str)," ");strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),";\n");
							free((yyvsp[-3].str));free((yyvsp[-2].str));free((yyvsp[-1].str));
						}
#line 1961 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 437 "P1.y" /* yacc.c:1646  */
    {(yyval.str)=(char*)malloc(2*sizeof(char));strcpy((yyval.str),"");}
#line 1967 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 440 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 5)*sizeof(char));
							strcpy((yyval.str),(yyvsp[-1].str));strcat((yyval.str)," ");strcat((yyval.str),(yyvsp[0].str));
							free((yyvsp[-1].str));free((yyvsp[0].str));
						}
#line 1977 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 446 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-3].str)) + strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 10)*sizeof(char));
							strcpy((yyval.str),(yyvsp[-3].str));strcat((yyval.str)," ");strcat((yyval.str),(yyvsp[-2].str));strcat((yyval.str),",");strcat((yyval.str),(yyvsp[0].str));
							free((yyvsp[-3].str));free((yyvsp[-2].str));free((yyvsp[0].str));
						}
#line 1987 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 451 "P1.y" /* yacc.c:1646  */
    {(yyval.str)=(char*)malloc(2*sizeof(char));strcpy((yyval.str),"");}
#line 1993 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 455 "P1.y" /* yacc.c:1646  */
    {
							int l = strlen((yyvsp[-5].str)) + strlen((yyvsp[-4].str)) + strlen((yyvsp[-2].str)) + 40;
							(yyval.str) = (char*)malloc((strlen((yyvsp[-11].str)) + strlen((yyvsp[-10].str)) + strlen((yyvsp[-8].str)) + l)*sizeof(char));
							strcpy((yyval.str),"public ");strcat((yyval.str),(yyvsp[-11].str));strcat((yyval.str)," ");strcat((yyval.str),(yyvsp[-10].str));strcat((yyval.str),"(");
							strcat((yyval.str),(yyvsp[-8].str));strcat((yyval.str),")\n{\n");strcat((yyval.str),(yyvsp[-5].str));strcat((yyval.str),(yyvsp[-4].str));
							strcat((yyval.str),"return ");strcat((yyval.str),(yyvsp[-2].str));strcat((yyval.str),";\n}\n");
						}
#line 2005 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 464 "P1.y" /* yacc.c:1646  */
    {
								(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 30)*sizeof(char));
								strcpy((yyval.str),(yyvsp[-1].str));strcat((yyval.str),(yyvsp[0].str));
								free((yyvsp[-1].str));free((yyvsp[0].str));
							}
#line 2015 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 469 "P1.y" /* yacc.c:1646  */
    {(yyval.str)=(char*)malloc(2*sizeof(char));strcpy((yyval.str),"");}
#line 2021 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 472 "P1.y" /* yacc.c:1646  */
    {
						(yyval.str) = (char*)malloc((strlen((yyvsp[-4].str)) + strlen((yyvsp[-2].str)) + strlen((yyvsp[-1].str)) + 30)*sizeof(char));
						strcpy((yyval.str),"class ");strcat((yyval.str),(yyvsp[-4].str));strcat((yyval.str),"\n{\n");strcat((yyval.str),(yyvsp[-2].str));
						strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),"\n}\n");
						free((yyvsp[-1].str));free((yyvsp[-4].str));free((yyvsp[-2].str));
					}
#line 2032 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 480 "P1.y" /* yacc.c:1646  */
    {
						int l = strlen((yyvsp[-2].str)) + strlen((yyvsp[-1].str)) + 40;
						(yyval.str) = (char*)malloc((strlen((yyvsp[-6].str)) + strlen((yyvsp[-4].str)) + l)*sizeof(char));
						strcpy((yyval.str),"class ");strcat((yyval.str),(yyvsp[-6].str));strcat((yyval.str),"extends ");strcat((yyval.str),(yyvsp[-4].str));
						strcat((yyval.str),"\n{\n");strcat((yyval.str),(yyvsp[-2].str));strcat((yyval.str),(yyvsp[-1].str));strcat((yyval.str),"\n}\n");
						free((yyvsp[-2].str));free((yyvsp[-6].str));free((yyvsp[-4].str));free((yyvsp[-1].str));
					}
#line 2044 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 489 "P1.y" /* yacc.c:1646  */
    {
							(yyval.str) = (char*)malloc((strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 30)*sizeof(char));
							strcpy((yyval.str),(yyvsp[-1].str));strcat((yyval.str),(yyvsp[0].str));
							free((yyvsp[-1].str));free((yyvsp[0].str));
						}
#line 2054 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 494 "P1.y" /* yacc.c:1646  */
    {(yyval.str)=(char*)malloc(2*sizeof(char));strcpy((yyval.str),"");}
#line 2060 "P1.tab.c" /* yacc.c:1646  */
    break;


#line 2064 "P1.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 496 "P1.y" /* yacc.c:1906  */
