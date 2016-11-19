begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A Bison parser, made by GNU Bison 3.0.2.  */
end_comment

begin_comment
comment|/* Bison implementation for Yacc-like parsers in C     Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.     This program is free software: you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation, either version 3 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_comment
comment|/* As a special exception, you may create a larger work that contains    part or all of the Bison parser skeleton and distribute that work    under terms of your choice, so long as that work isn't itself a    parser generator using the skeleton or a modified version thereof    as a parser skeleton.  Alternatively, if you modify or redistribute    the parser skeleton itself, you may (at your option) remove this    special exception, which will cause the skeleton and the resulting    Bison output files to be licensed under the GNU General Public    License without this special exception.     This special exception was added by the Free Software Foundation in    version 2.2 of Bison.  */
end_comment

begin_comment
comment|/* C LALR(1) parser skeleton written by Richard Stallman, by    simplifying the original so-called "semantic" parser.  */
end_comment

begin_comment
comment|/* All symbols defined below should begin with yy or YY, to avoid    infringing on user name space.  This should be done even for local    variables, as they might otherwise be expanded by user macros.    There are some unavoidable exceptions within include files to    define necessary library symbols; they are noted "INFRINGES ON    USER NAME SPACE" below.  */
end_comment

begin_comment
comment|/* Identify Bison output.  */
end_comment

begin_define
define|#
directive|define
name|YYBISON
value|1
end_define

begin_comment
comment|/* Bison version.  */
end_comment

begin_define
define|#
directive|define
name|YYBISON_VERSION
value|"3.0.2"
end_define

begin_comment
comment|/* Skeleton name.  */
end_comment

begin_define
define|#
directive|define
name|YYSKELETON_NAME
value|"yacc.c"
end_define

begin_comment
comment|/* Pure parsers.  */
end_comment

begin_define
define|#
directive|define
name|YYPURE
value|0
end_define

begin_comment
comment|/* Push parsers.  */
end_comment

begin_define
define|#
directive|define
name|YYPUSH
value|0
end_define

begin_comment
comment|/* Pull parsers.  */
end_comment

begin_define
define|#
directive|define
name|YYPULL
value|1
end_define

begin_comment
comment|/* Substitute the variable and function names.  */
end_comment

begin_define
define|#
directive|define
name|yyparse
value|null_parse
end_define

begin_define
define|#
directive|define
name|yylex
value|null_lex
end_define

begin_define
define|#
directive|define
name|yyerror
value|null_error
end_define

begin_define
define|#
directive|define
name|yydebug
value|null_debug
end_define

begin_define
define|#
directive|define
name|yynerrs
value|null_nerrs
end_define

begin_define
define|#
directive|define
name|yylval
value|null_lval
end_define

begin_define
define|#
directive|define
name|yychar
value|null_char
end_define

begin_comment
comment|/* Copy the first part of user declarations.  */
end_comment

begin_line
line|#
directive|line
number|1
file|"../../fsinfo/null_gram.y"
end_line

begin_comment
comment|/* yacc.c:339  */
end_comment

begin_function_decl
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_line
line|#
directive|line
number|79
file|"null_gram.c"
end_line

begin_comment
comment|/* yacc.c:339  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YY_NULLPTR
end_ifndef

begin_if
if|#
directive|if
name|defined
name|__cplusplus
operator|&&
literal|201103L
operator|<=
name|__cplusplus
end_if

begin_define
define|#
directive|define
name|YY_NULLPTR
value|nullptr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YY_NULLPTR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enabling verbose error messages.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|YYERROR_VERBOSE
end_ifdef

begin_undef
undef|#
directive|undef
name|YYERROR_VERBOSE
end_undef

begin_define
define|#
directive|define
name|YYERROR_VERBOSE
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YYERROR_VERBOSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In a future release of Bison, this section will be replaced    by #include "y.tab.h".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YY_NULL_NULL_GRAM_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|YY_NULL_NULL_GRAM_H_INCLUDED
end_define

begin_comment
comment|/* Debug traces.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYDEBUG
end_ifndef

begin_define
define|#
directive|define
name|YYDEBUG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|YYDEBUG
end_if

begin_decl_stmt
specifier|extern
name|int
name|null_debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Value type.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|YYSTYPE
operator|&&
operator|!
name|defined
name|YYSTYPE_IS_DECLARED
end_if

begin_typedef
typedef|typedef
name|int
name|YYSTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|YYSTYPE_IS_TRIVIAL
value|1
end_define

begin_define
define|#
directive|define
name|YYSTYPE_IS_DECLARED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|null_lval
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|null_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !YY_NULL_NULL_GRAM_H_INCLUDED  */
end_comment

begin_comment
comment|/* Copy the second part of user declarations.  */
end_comment

begin_line
line|#
directive|line
number|126
file|"null_gram.c"
end_line

begin_comment
comment|/* yacc.c:358  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|short
end_ifdef

begin_undef
undef|#
directive|undef
name|short
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|YYTYPE_UINT8
end_ifdef

begin_typedef
typedef|typedef
name|YYTYPE_UINT8
name|yytype_uint8
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|yytype_uint8
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|YYTYPE_INT8
end_ifdef

begin_typedef
typedef|typedef
name|YYTYPE_INT8
name|yytype_int8
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|signed
name|char
name|yytype_int8
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|YYTYPE_UINT16
end_ifdef

begin_typedef
typedef|typedef
name|YYTYPE_UINT16
name|yytype_uint16
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|yytype_uint16
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|YYTYPE_INT16
end_ifdef

begin_typedef
typedef|typedef
name|YYTYPE_INT16
name|yytype_int16
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|short
name|int
name|yytype_int16
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YYSIZE_T
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__SIZE_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|YYSIZE_T
value|__SIZE_TYPE__
end_define

begin_elif
elif|#
directive|elif
name|defined
name|size_t
end_elif

begin_define
define|#
directive|define
name|YYSIZE_T
value|size_t
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
name|YYSIZE_T
end_elif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_define
define|#
directive|define
name|YYSIZE_T
value|size_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YYSIZE_T
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YYSIZE_MAXIMUM
value|((YYSIZE_T) -1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|YY_
end_ifndef

begin_if
if|#
directive|if
name|defined
name|YYENABLE_NLS
operator|&&
name|YYENABLE_NLS
end_if

begin_if
if|#
directive|if
name|ENABLE_NLS
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_define
define|#
directive|define
name|YY_
parameter_list|(
name|Msgid
parameter_list|)
value|dgettext ("bison-runtime", Msgid)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YY_
end_ifndef

begin_define
define|#
directive|define
name|YY_
parameter_list|(
name|Msgid
parameter_list|)
value|Msgid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YY_ATTRIBUTE
end_ifndef

begin_if
if|#
directive|if
operator|(
name|defined
name|__GNUC__
expr|\
operator|&&
operator|(
literal|2
operator|<
name|__GNUC__
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
literal|96
operator|<=
name|__GNUC_MINOR__
operator|)
operator|)
operator|)
expr|\
operator|||
name|defined
name|__SUNPRO_C
operator|&&
literal|0x5110
operator|<=
name|__SUNPRO_C
end_if

begin_define
define|#
directive|define
name|YY_ATTRIBUTE
parameter_list|(
name|Spec
parameter_list|)
value|__attribute__(Spec)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YY_ATTRIBUTE
parameter_list|(
name|Spec
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YY_ATTRIBUTE_PURE
end_ifndef

begin_define
define|#
directive|define
name|YY_ATTRIBUTE_PURE
value|YY_ATTRIBUTE ((__pure__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YY_ATTRIBUTE_UNUSED
end_ifndef

begin_define
define|#
directive|define
name|YY_ATTRIBUTE_UNUSED
value|YY_ATTRIBUTE ((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
specifier|_Noreturn
expr|\
operator|&&
operator|(
operator|!
name|defined
name|__STDC_VERSION__
operator|||
name|__STDC_VERSION__
operator|<
literal|201112
operator|)
end_if

begin_if
if|#
directive|if
name|defined
name|_MSC_VER
operator|&&
literal|1200
operator|<=
name|_MSC_VER
end_if

begin_define
define|#
directive|define
name|_Noreturn
value|__declspec (noreturn)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_Noreturn
value|YY_ATTRIBUTE ((__noreturn__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Suppress unused-variable warnings by "using" E.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|lint
operator|||
name|defined
name|__GNUC__
end_if

begin_define
define|#
directive|define
name|YYUSE
parameter_list|(
name|E
parameter_list|)
value|((void) (E))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YYUSE
parameter_list|(
name|E
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|__GNUC__
operator|&&
literal|407
operator|<=
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
end_if

begin_comment
comment|/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
end_comment

begin_define
define|#
directive|define
name|YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
define|\
value|_Pragma ("GCC diagnostic push") \     _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\     _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
end_define

begin_define
define|#
directive|define
name|YY_IGNORE_MAYBE_UNINITIALIZED_END
define|\
value|_Pragma ("GCC diagnostic pop")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YY_INITIAL_VALUE
parameter_list|(
name|Value
parameter_list|)
value|Value
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
end_ifndef

begin_define
define|#
directive|define
name|YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
end_define

begin_define
define|#
directive|define
name|YY_IGNORE_MAYBE_UNINITIALIZED_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YY_INITIAL_VALUE
end_ifndef

begin_define
define|#
directive|define
name|YY_INITIAL_VALUE
parameter_list|(
name|Value
parameter_list|)
end_define

begin_comment
comment|/* Nothing. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|yyoverflow
operator|||
name|YYERROR_VERBOSE
end_if

begin_comment
comment|/* The parser invokes alloca or malloc; define the necessary symbols.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|YYSTACK_USE_ALLOCA
end_ifdef

begin_if
if|#
directive|if
name|YYSTACK_USE_ALLOCA
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|YYSTACK_ALLOC
value|__builtin_alloca
end_define

begin_elif
elif|#
directive|elif
name|defined
name|__BUILTIN_VA_ARG_INCR
end_elif

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_elif
elif|#
directive|elif
name|defined
name|_AIX
end_elif

begin_define
define|#
directive|define
name|YYSTACK_ALLOC
value|__alloca
end_define

begin_elif
elif|#
directive|elif
name|defined
name|_MSC_VER
end_elif

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_define
define|#
directive|define
name|alloca
value|_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YYSTACK_ALLOC
value|alloca
end_define

begin_if
if|#
directive|if
operator|!
name|defined
name|_ALLOCA_H
operator|&&
operator|!
name|defined
name|EXIT_SUCCESS
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_comment
comment|/* Use EXIT_SUCCESS as a witness for stdlib.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|YYSTACK_ALLOC
end_ifdef

begin_comment
comment|/* Pacify GCC's 'empty if-body' warning.  */
end_comment

begin_define
define|#
directive|define
name|YYSTACK_FREE
parameter_list|(
name|Ptr
parameter_list|)
value|do {
comment|/* empty */
value|; } while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|YYSTACK_ALLOC_MAXIMUM
end_ifndef

begin_comment
comment|/* The OS might guarantee only one guard page at the bottom of the stack,        and a page size can be as small as 4096 bytes.  So we cannot safely        invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number        to allow for a few compiler-allocated temporary stack slots.  */
end_comment

begin_define
define|#
directive|define
name|YYSTACK_ALLOC_MAXIMUM
value|4032
end_define

begin_comment
comment|/* reasonable circa 2006 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YYSTACK_ALLOC
value|YYMALLOC
end_define

begin_define
define|#
directive|define
name|YYSTACK_FREE
value|YYFREE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|YYSTACK_ALLOC_MAXIMUM
end_ifndef

begin_define
define|#
directive|define
name|YYSTACK_ALLOC_MAXIMUM
value|YYSIZE_MAXIMUM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
name|__cplusplus
operator|&&
operator|!
name|defined
name|EXIT_SUCCESS
expr|\
operator|&&
operator|!
operator|(
operator|(
name|defined
name|YYMALLOC
operator|||
name|defined
name|malloc
operator|)
expr|\
operator|&&
operator|(
name|defined
name|YYFREE
operator|||
name|defined
name|free
operator|)
operator|)
operator|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YYMALLOC
end_ifndef

begin_define
define|#
directive|define
name|YYMALLOC
value|malloc
end_define

begin_if
if|#
directive|if
operator|!
name|defined
name|malloc
operator|&&
operator|!
name|defined
name|EXIT_SUCCESS
end_if

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|YYSIZE_T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YYFREE
end_ifndef

begin_define
define|#
directive|define
name|YYFREE
value|free
end_define

begin_if
if|#
directive|if
operator|!
name|defined
name|free
operator|&&
operator|!
name|defined
name|EXIT_SUCCESS
end_if

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined yyoverflow || YYERROR_VERBOSE */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
name|yyoverflow
expr|\
operator|&&
operator|(
operator|!
name|defined
name|__cplusplus
expr|\
operator|||
operator|(
name|defined
name|YYSTYPE_IS_TRIVIAL
operator|&&
name|YYSTYPE_IS_TRIVIAL
operator|)
operator|)
operator|)
end_if

begin_comment
comment|/* A type that is properly aligned for any stack member.  */
end_comment

begin_union
union|union
name|yyalloc
block|{
name|yytype_int16
name|yyss_alloc
decl_stmt|;
name|YYSTYPE
name|yyvs_alloc
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* The size of the maximum gap between one aligned stack and the next.  */
end_comment

begin_define
define|#
directive|define
name|YYSTACK_GAP_MAXIMUM
value|(sizeof (union yyalloc) - 1)
end_define

begin_comment
comment|/* The size of an array large to enough to hold all stacks, each with    N elements.  */
end_comment

begin_define
define|#
directive|define
name|YYSTACK_BYTES
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \       + YYSTACK_GAP_MAXIMUM)
end_define

begin_define
define|#
directive|define
name|YYCOPY_NEEDED
value|1
end_define

begin_comment
comment|/* Relocate STACK from its old location to the new one.  The    local variables YYSIZE and YYSTACKSIZE give the old and new number of    elements in the stack, and YYPTR gives the new location of the    stack.  Advance YYPTR to a properly aligned location for the next    stack.  */
end_comment

begin_define
define|#
directive|define
name|YYSTACK_RELOCATE
parameter_list|(
name|Stack_alloc
parameter_list|,
name|Stack
parameter_list|)
define|\
value|do                                                                  \       {                                                                 \         YYSIZE_T yynewbytes;                                            \         YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \         Stack =&yyptr->Stack_alloc;                                    \         yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \         yyptr += yynewbytes / sizeof (*yyptr);                          \       }                                                                 \     while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|YYCOPY_NEEDED
operator|&&
name|YYCOPY_NEEDED
end_if

begin_comment
comment|/* Copy COUNT objects from SRC to DST.  The source and destination do    not overlap.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYCOPY
end_ifndef

begin_if
if|#
directive|if
name|defined
name|__GNUC__
operator|&&
literal|1
operator|<
name|__GNUC__
end_if

begin_define
define|#
directive|define
name|YYCOPY
parameter_list|(
name|Dst
parameter_list|,
name|Src
parameter_list|,
name|Count
parameter_list|)
define|\
value|__builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YYCOPY
parameter_list|(
name|Dst
parameter_list|,
name|Src
parameter_list|,
name|Count
parameter_list|)
define|\
value|do                                        \         {                                       \           YYSIZE_T yyi;                         \           for (yyi = 0; yyi< (Count); yyi++)   \             (Dst)[yyi] = (Src)[yyi];            \         }                                       \       while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !YYCOPY_NEEDED */
end_comment

begin_comment
comment|/* YYFINAL -- State number of the termination state.  */
end_comment

begin_define
define|#
directive|define
name|YYFINAL
value|2
end_define

begin_comment
comment|/* YYLAST -- Last index in YYTABLE.  */
end_comment

begin_define
define|#
directive|define
name|YYLAST
value|0
end_define

begin_comment
comment|/* YYNTOKENS -- Number of terminals.  */
end_comment

begin_define
define|#
directive|define
name|YYNTOKENS
value|3
end_define

begin_comment
comment|/* YYNNTS -- Number of nonterminals.  */
end_comment

begin_define
define|#
directive|define
name|YYNNTS
value|2
end_define

begin_comment
comment|/* YYNRULES -- Number of rules.  */
end_comment

begin_define
define|#
directive|define
name|YYNRULES
value|2
end_define

begin_comment
comment|/* YYNSTATES -- Number of states.  */
end_comment

begin_define
define|#
directive|define
name|YYNSTATES
value|3
end_define

begin_comment
comment|/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned    by yylex, with out-of-bounds checking.  */
end_comment

begin_define
define|#
directive|define
name|YYUNDEFTOK
value|2
end_define

begin_define
define|#
directive|define
name|YYMAXUTOK
value|257
end_define

begin_define
define|#
directive|define
name|YYTRANSLATE
parameter_list|(
name|YYX
parameter_list|)
define|\
value|((unsigned int) (YYX)<= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
end_define

begin_comment
comment|/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM    as returned by yylex, without out-of-bounds checking.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint8
name|yytranslate
index|[]
init|=
block|{
literal|0
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|YYDEBUG
end_if

begin_comment
comment|/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint8
name|yyrline
index|[]
init|=
block|{
literal|0
block|,
literal|8
block|,
literal|8
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|YYDEBUG
operator|||
name|YYERROR_VERBOSE
operator|||
literal|0
end_if

begin_comment
comment|/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|yytname
index|[]
init|=
block|{
literal|"$end"
block|,
literal|"error"
block|,
literal|"$undefined"
block|,
literal|"$accept"
block|,
literal|"token"
block|,
name|YY_NULLPTR
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|YYPRINT
end_ifdef

begin_comment
comment|/* YYTOKNUM[NUM] -- (External) token number corresponding to the    (internal) symbol number NUM (which must be that of a token).  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint16
name|yytoknum
index|[]
init|=
block|{
literal|0
block|,
literal|256
block|,
literal|257
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YYPACT_NINF
value|-1
end_define

begin_define
define|#
directive|define
name|yypact_value_is_default
parameter_list|(
name|Yystate
parameter_list|)
define|\
value|(!!((Yystate) == (-1)))
end_define

begin_define
define|#
directive|define
name|YYTABLE_NINF
value|-1
end_define

begin_define
define|#
directive|define
name|yytable_value_is_error
parameter_list|(
name|Yytable_value
parameter_list|)
define|\
value|0
end_define

begin_comment
comment|/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing      STATE-NUM.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_int8
name|yypact
index|[]
init|=
block|{
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.      Performed when YYTABLE does not specify something else to do.  Zero      means the default is an error.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint8
name|yydefact
index|[]
init|=
block|{
literal|2
block|,
literal|0
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* YYPGOTO[NTERM-NUM].  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_int8
name|yypgoto
index|[]
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* YYDEFGOTO[NTERM-NUM].  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_int8
name|yydefgoto
index|[]
init|=
block|{
operator|-
literal|1
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If      positive, shift that token.  If negative, reduce the rule whose      number is the opposite.  If YYTABLE_NINF, syntax error.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint8
name|yytable
index|[]
init|=
block|{
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint8
name|yycheck
index|[]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing      symbol of state STATE-NUM.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint8
name|yystos
index|[]
init|=
block|{
literal|0
block|,
literal|4
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint8
name|yyr1
index|[]
init|=
block|{
literal|0
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|yytype_uint8
name|yyr2
index|[]
init|=
block|{
literal|0
block|,
literal|2
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|yyerrok
value|(yyerrstatus = 0)
end_define

begin_define
define|#
directive|define
name|yyclearin
value|(yychar = YYEMPTY)
end_define

begin_define
define|#
directive|define
name|YYEMPTY
value|(-2)
end_define

begin_define
define|#
directive|define
name|YYEOF
value|0
end_define

begin_define
define|#
directive|define
name|YYACCEPT
value|goto yyacceptlab
end_define

begin_define
define|#
directive|define
name|YYABORT
value|goto yyabortlab
end_define

begin_define
define|#
directive|define
name|YYERROR
value|goto yyerrorlab
end_define

begin_define
define|#
directive|define
name|YYRECOVERING
parameter_list|()
value|(!!yyerrstatus)
end_define

begin_define
define|#
directive|define
name|YYBACKUP
parameter_list|(
name|Token
parameter_list|,
name|Value
parameter_list|)
define|\
value|do                                                              \   if (yychar == YYEMPTY)                                        \     {                                                           \       yychar = (Token);                                         \       yylval = (Value);                                         \       YYPOPSTACK (yylen);                                       \       yystate = *yyssp;                                         \       goto yybackup;                                            \     }                                                           \   else                                                          \     {                                                           \       yyerror (YY_("syntax error: cannot back up")); \       YYERROR;                                                  \     }                                                           \ while (0)
end_define

begin_comment
comment|/* Error token number */
end_comment

begin_define
define|#
directive|define
name|YYTERROR
value|1
end_define

begin_define
define|#
directive|define
name|YYERRCODE
value|256
end_define

begin_comment
comment|/* Enable debugging if requested.  */
end_comment

begin_if
if|#
directive|if
name|YYDEBUG
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|YYFPRINTF
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* INFRINGES ON USER NAME SPACE */
end_comment

begin_define
define|#
directive|define
name|YYFPRINTF
value|fprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YYDPRINTF
parameter_list|(
name|Args
parameter_list|)
define|\
value|do {                                            \   if (yydebug)                                  \     YYFPRINTF Args;                             \ } while (0)
end_define

begin_comment
comment|/* This macro is provided for backward compatibility. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YY_LOCATION_PRINT
end_ifndef

begin_define
define|#
directive|define
name|YY_LOCATION_PRINT
parameter_list|(
name|File
parameter_list|,
name|Loc
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YY_SYMBOL_PRINT
parameter_list|(
name|Title
parameter_list|,
name|Type
parameter_list|,
name|Value
parameter_list|,
name|Location
parameter_list|)
define|\
value|do {                                                                      \   if (yydebug)                                                            \     {                                                                     \       YYFPRINTF (stderr, "%s ", Title);                                   \       yy_symbol_print (stderr,                                            \                   Type, Value); \       YYFPRINTF (stderr, "\n");                                           \     }                                                                     \ } while (0)
end_define

begin_comment
comment|/*----------------------------------------. | Print this symbol's value on YYOUTPUT.  | `----------------------------------------*/
end_comment

begin_function
specifier|static
name|void
name|yy_symbol_value_print
parameter_list|(
name|FILE
modifier|*
name|yyoutput
parameter_list|,
name|int
name|yytype
parameter_list|,
name|YYSTYPE
specifier|const
modifier|*
specifier|const
name|yyvaluep
parameter_list|)
block|{
name|FILE
modifier|*
name|yyo
init|=
name|yyoutput
decl_stmt|;
name|YYUSE
argument_list|(
name|yyo
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|yyvaluep
condition|)
return|return;
ifdef|#
directive|ifdef
name|YYPRINT
if|if
condition|(
name|yytype
operator|<
name|YYNTOKENS
condition|)
name|YYPRINT
argument_list|(
name|yyoutput
argument_list|,
name|yytoknum
index|[
name|yytype
index|]
argument_list|,
operator|*
name|yyvaluep
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|YYUSE
argument_list|(
name|yytype
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*--------------------------------. | Print this symbol on YYOUTPUT.  | `--------------------------------*/
end_comment

begin_function
specifier|static
name|void
name|yy_symbol_print
parameter_list|(
name|FILE
modifier|*
name|yyoutput
parameter_list|,
name|int
name|yytype
parameter_list|,
name|YYSTYPE
specifier|const
modifier|*
specifier|const
name|yyvaluep
parameter_list|)
block|{
name|YYFPRINTF
argument_list|(
name|yyoutput
argument_list|,
literal|"%s %s ("
argument_list|,
name|yytype
operator|<
name|YYNTOKENS
condition|?
literal|"token"
else|:
literal|"nterm"
argument_list|,
name|yytname
index|[
name|yytype
index|]
argument_list|)
expr_stmt|;
name|yy_symbol_value_print
argument_list|(
name|yyoutput
argument_list|,
name|yytype
argument_list|,
name|yyvaluep
argument_list|)
expr_stmt|;
name|YYFPRINTF
argument_list|(
name|yyoutput
argument_list|,
literal|")"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*------------------------------------------------------------------. | yy_stack_print -- Print the state stack from its BOTTOM up to its | | TOP (included).                                                   | `------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
name|void
name|yy_stack_print
parameter_list|(
name|yytype_int16
modifier|*
name|yybottom
parameter_list|,
name|yytype_int16
modifier|*
name|yytop
parameter_list|)
block|{
name|YYFPRINTF
argument_list|(
name|stderr
argument_list|,
literal|"Stack now"
argument_list|)
expr_stmt|;
for|for
control|(
init|;
name|yybottom
operator|<=
name|yytop
condition|;
name|yybottom
operator|++
control|)
block|{
name|int
name|yybot
init|=
operator|*
name|yybottom
decl_stmt|;
name|YYFPRINTF
argument_list|(
name|stderr
argument_list|,
literal|" %d"
argument_list|,
name|yybot
argument_list|)
expr_stmt|;
block|}
name|YYFPRINTF
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|YY_STACK_PRINT
parameter_list|(
name|Bottom
parameter_list|,
name|Top
parameter_list|)
define|\
value|do {                                                            \   if (yydebug)                                                  \     yy_stack_print ((Bottom), (Top));                           \ } while (0)
end_define

begin_comment
comment|/*------------------------------------------------. | Report that the YYRULE is going to be reduced.  | `------------------------------------------------*/
end_comment

begin_function
specifier|static
name|void
name|yy_reduce_print
parameter_list|(
name|yytype_int16
modifier|*
name|yyssp
parameter_list|,
name|YYSTYPE
modifier|*
name|yyvsp
parameter_list|,
name|int
name|yyrule
parameter_list|)
block|{
name|unsigned
name|long
name|int
name|yylno
init|=
name|yyrline
index|[
name|yyrule
index|]
decl_stmt|;
name|int
name|yynrhs
init|=
name|yyr2
index|[
name|yyrule
index|]
decl_stmt|;
name|int
name|yyi
decl_stmt|;
name|YYFPRINTF
argument_list|(
name|stderr
argument_list|,
literal|"Reducing stack by rule %d (line %lu):\n"
argument_list|,
name|yyrule
operator|-
literal|1
argument_list|,
name|yylno
argument_list|)
expr_stmt|;
comment|/* The symbols being reduced.  */
for|for
control|(
name|yyi
operator|=
literal|0
init|;
name|yyi
operator|<
name|yynrhs
condition|;
name|yyi
operator|++
control|)
block|{
name|YYFPRINTF
argument_list|(
name|stderr
argument_list|,
literal|"   $%d = "
argument_list|,
name|yyi
operator|+
literal|1
argument_list|)
expr_stmt|;
name|yy_symbol_print
argument_list|(
name|stderr
argument_list|,
name|yystos
index|[
name|yyssp
index|[
name|yyi
operator|+
literal|1
operator|-
name|yynrhs
index|]
index|]
argument_list|,
operator|&
operator|(
name|yyvsp
index|[
operator|(
name|yyi
operator|+
literal|1
operator|)
operator|-
operator|(
name|yynrhs
operator|)
index|]
operator|)
argument_list|)
expr_stmt|;
name|YYFPRINTF
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_define
define|#
directive|define
name|YY_REDUCE_PRINT
parameter_list|(
name|Rule
parameter_list|)
define|\
value|do {                                    \   if (yydebug)                          \     yy_reduce_print (yyssp, yyvsp, Rule); \ } while (0)
end_define

begin_comment
comment|/* Nonzero means print parse trace.  It is left uninitialized so that    multiple parsers can coexist.  */
end_comment

begin_decl_stmt
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !YYDEBUG */
end_comment

begin_define
define|#
directive|define
name|YYDPRINTF
parameter_list|(
name|Args
parameter_list|)
end_define

begin_define
define|#
directive|define
name|YY_SYMBOL_PRINT
parameter_list|(
name|Title
parameter_list|,
name|Type
parameter_list|,
name|Value
parameter_list|,
name|Location
parameter_list|)
end_define

begin_define
define|#
directive|define
name|YY_STACK_PRINT
parameter_list|(
name|Bottom
parameter_list|,
name|Top
parameter_list|)
end_define

begin_define
define|#
directive|define
name|YY_REDUCE_PRINT
parameter_list|(
name|Rule
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !YYDEBUG */
end_comment

begin_comment
comment|/* YYINITDEPTH -- initial size of the parser's stacks.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYINITDEPTH
end_ifndef

begin_define
define|#
directive|define
name|YYINITDEPTH
value|200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only    if the built-in stack extension method is used).     Do not make this value too large; the results are undefined if    YYSTACK_ALLOC_MAXIMUM< YYSTACK_BYTES (YYMAXDEPTH)    evaluated with infinite-precision integer arithmetic.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYMAXDEPTH
end_ifndef

begin_define
define|#
directive|define
name|YYMAXDEPTH
value|10000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|YYERROR_VERBOSE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|yystrlen
end_ifndef

begin_if
if|#
directive|if
name|defined
name|__GLIBC__
operator|&&
name|defined
name|_STRING_H
end_if

begin_define
define|#
directive|define
name|yystrlen
value|strlen
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Return the length of YYSTR.  */
end_comment

begin_function
specifier|static
name|YYSIZE_T
name|yystrlen
parameter_list|(
specifier|const
name|char
modifier|*
name|yystr
parameter_list|)
block|{
name|YYSIZE_T
name|yylen
decl_stmt|;
for|for
control|(
name|yylen
operator|=
literal|0
init|;
name|yystr
index|[
name|yylen
index|]
condition|;
name|yylen
operator|++
control|)
continue|continue;
return|return
name|yylen
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|yystpcpy
end_ifndef

begin_if
if|#
directive|if
name|defined
name|__GLIBC__
operator|&&
name|defined
name|_STRING_H
operator|&&
name|defined
name|_GNU_SOURCE
end_if

begin_define
define|#
directive|define
name|yystpcpy
value|stpcpy
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in    YYDEST.  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|yystpcpy
parameter_list|(
name|char
modifier|*
name|yydest
parameter_list|,
specifier|const
name|char
modifier|*
name|yysrc
parameter_list|)
block|{
name|char
modifier|*
name|yyd
init|=
name|yydest
decl_stmt|;
specifier|const
name|char
modifier|*
name|yys
init|=
name|yysrc
decl_stmt|;
while|while
condition|(
operator|(
operator|*
name|yyd
operator|++
operator|=
operator|*
name|yys
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
continue|continue;
return|return
name|yyd
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|yytnamerr
end_ifndef

begin_comment
comment|/* Copy to YYRES the contents of YYSTR after stripping away unnecessary    quotes and backslashes, so that it's suitable for yyerror.  The    heuristic is that double-quoting is unnecessary unless the string    contains an apostrophe, a comma, or backslash (other than    backslash-backslash).  YYSTR is taken from yytname.  If YYRES is    null, do not copy; instead, return the length of what the result    would have been.  */
end_comment

begin_function
specifier|static
name|YYSIZE_T
name|yytnamerr
parameter_list|(
name|char
modifier|*
name|yyres
parameter_list|,
specifier|const
name|char
modifier|*
name|yystr
parameter_list|)
block|{
if|if
condition|(
operator|*
name|yystr
operator|==
literal|'"'
condition|)
block|{
name|YYSIZE_T
name|yyn
init|=
literal|0
decl_stmt|;
name|char
specifier|const
modifier|*
name|yyp
init|=
name|yystr
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
switch|switch
condition|(
operator|*
operator|++
name|yyp
condition|)
block|{
case|case
literal|'\''
case|:
case|case
literal|','
case|:
goto|goto
name|do_not_strip_quotes
goto|;
case|case
literal|'\\'
case|:
if|if
condition|(
operator|*
operator|++
name|yyp
operator|!=
literal|'\\'
condition|)
goto|goto
name|do_not_strip_quotes
goto|;
comment|/* Fall through.  */
default|default:
if|if
condition|(
name|yyres
condition|)
name|yyres
index|[
name|yyn
index|]
operator|=
operator|*
name|yyp
expr_stmt|;
name|yyn
operator|++
expr_stmt|;
break|break;
case|case
literal|'"'
case|:
if|if
condition|(
name|yyres
condition|)
name|yyres
index|[
name|yyn
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|yyn
return|;
block|}
name|do_not_strip_quotes
label|:
empty_stmt|;
block|}
if|if
condition|(
operator|!
name|yyres
condition|)
return|return
name|yystrlen
argument_list|(
name|yystr
argument_list|)
return|;
return|return
name|yystpcpy
argument_list|(
name|yyres
argument_list|,
name|yystr
argument_list|)
operator|-
name|yyres
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message    about the unexpected token YYTOKEN for the state stack whose top is    YYSSP.     Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is    not large enough to hold the message.  In that case, also set    *YYMSG_ALLOC to the required number of bytes.  Return 2 if the    required number of bytes is too large to store.  */
end_comment

begin_function
specifier|static
name|int
name|yysyntax_error
parameter_list|(
name|YYSIZE_T
modifier|*
name|yymsg_alloc
parameter_list|,
name|char
modifier|*
modifier|*
name|yymsg
parameter_list|,
name|yytype_int16
modifier|*
name|yyssp
parameter_list|,
name|int
name|yytoken
parameter_list|)
block|{
name|YYSIZE_T
name|yysize0
init|=
name|yytnamerr
argument_list|(
name|YY_NULLPTR
argument_list|,
name|yytname
index|[
name|yytoken
index|]
argument_list|)
decl_stmt|;
name|YYSIZE_T
name|yysize
init|=
name|yysize0
decl_stmt|;
enum|enum
block|{
name|YYERROR_VERBOSE_ARGS_MAXIMUM
init|=
literal|5
block|}
enum|;
comment|/* Internationalized format string. */
specifier|const
name|char
modifier|*
name|yyformat
init|=
name|YY_NULLPTR
decl_stmt|;
comment|/* Arguments of yyformat. */
name|char
specifier|const
modifier|*
name|yyarg
index|[
name|YYERROR_VERBOSE_ARGS_MAXIMUM
index|]
decl_stmt|;
comment|/* Number of reported tokens (one for the "unexpected", one per      "expected"). */
name|int
name|yycount
init|=
literal|0
decl_stmt|;
comment|/* There are many possibilities here to consider:      - If this state is a consistent state with a default action, then        the only way this function was invoked is if the default action        is an error action.  In that case, don't check for expected        tokens because there are none.      - The only way there can be no lookahead present (in yychar) is if        this state is a consistent state with a default action.  Thus,        detecting the absence of a lookahead is sufficient to determine        that there is no unexpected or expected token to report.  In that        case, just report a simple "syntax error".      - Don't assume there isn't a lookahead just because this state is a        consistent state with a default action.  There might have been a        previous inconsistent state, consistent state with a non-default        action, or user semantic action that manipulated yychar.      - Of course, the expected token list depends on states to have        correct lookahead information, and it depends on the parser not        to perform extra reductions after fetching a lookahead from the        scanner and before detecting a syntax error.  Thus, state merging        (from LALR or IELR) and default reductions corrupt the expected        token list.  However, the list is correct for canonical LR with        one exception: it will still contain any token that will not be        accepted due to an error action in a later state.   */
if|if
condition|(
name|yytoken
operator|!=
name|YYEMPTY
condition|)
block|{
name|int
name|yyn
init|=
name|yypact
index|[
operator|*
name|yyssp
index|]
decl_stmt|;
name|yyarg
index|[
name|yycount
operator|++
index|]
operator|=
name|yytname
index|[
name|yytoken
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|yypact_value_is_default
argument_list|(
name|yyn
argument_list|)
condition|)
block|{
comment|/* Start YYX at -YYN if negative to avoid negative indexes in              YYCHECK.  In other words, skip the first -YYN actions for              this state because they are default actions.  */
name|int
name|yyxbegin
init|=
name|yyn
operator|<
literal|0
condition|?
operator|-
name|yyn
else|:
literal|0
decl_stmt|;
comment|/* Stay within bounds of both yycheck and yytname.  */
name|int
name|yychecklim
init|=
name|YYLAST
operator|-
name|yyn
operator|+
literal|1
decl_stmt|;
name|int
name|yyxend
init|=
name|yychecklim
operator|<
name|YYNTOKENS
condition|?
name|yychecklim
else|:
name|YYNTOKENS
decl_stmt|;
name|int
name|yyx
decl_stmt|;
for|for
control|(
name|yyx
operator|=
name|yyxbegin
init|;
name|yyx
operator|<
name|yyxend
condition|;
operator|++
name|yyx
control|)
if|if
condition|(
name|yycheck
index|[
name|yyx
operator|+
name|yyn
index|]
operator|==
name|yyx
operator|&&
name|yyx
operator|!=
name|YYTERROR
operator|&&
operator|!
name|yytable_value_is_error
argument_list|(
name|yytable
index|[
name|yyx
operator|+
name|yyn
index|]
argument_list|)
condition|)
block|{
if|if
condition|(
name|yycount
operator|==
name|YYERROR_VERBOSE_ARGS_MAXIMUM
condition|)
block|{
name|yycount
operator|=
literal|1
expr_stmt|;
name|yysize
operator|=
name|yysize0
expr_stmt|;
break|break;
block|}
name|yyarg
index|[
name|yycount
operator|++
index|]
operator|=
name|yytname
index|[
name|yyx
index|]
expr_stmt|;
block|{
name|YYSIZE_T
name|yysize1
init|=
name|yysize
operator|+
name|yytnamerr
argument_list|(
name|YY_NULLPTR
argument_list|,
name|yytname
index|[
name|yyx
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|yysize
operator|<=
name|yysize1
operator|&&
name|yysize1
operator|<=
name|YYSTACK_ALLOC_MAXIMUM
operator|)
condition|)
return|return
literal|2
return|;
name|yysize
operator|=
name|yysize1
expr_stmt|;
block|}
block|}
block|}
block|}
switch|switch
condition|(
name|yycount
condition|)
block|{
define|#
directive|define
name|YYCASE_
parameter_list|(
name|N
parameter_list|,
name|S
parameter_list|)
define|\
value|case N:                               \         yyformat = S;                       \       break
name|YYCASE_
argument_list|(
literal|0
argument_list|,
name|YY_
argument_list|(
literal|"syntax error"
argument_list|)
argument_list|)
expr_stmt|;
name|YYCASE_
argument_list|(
literal|1
argument_list|,
name|YY_
argument_list|(
literal|"syntax error, unexpected %s"
argument_list|)
argument_list|)
expr_stmt|;
name|YYCASE_
argument_list|(
literal|2
argument_list|,
name|YY_
argument_list|(
literal|"syntax error, unexpected %s, expecting %s"
argument_list|)
argument_list|)
expr_stmt|;
name|YYCASE_
argument_list|(
literal|3
argument_list|,
name|YY_
argument_list|(
literal|"syntax error, unexpected %s, expecting %s or %s"
argument_list|)
argument_list|)
expr_stmt|;
name|YYCASE_
argument_list|(
literal|4
argument_list|,
name|YY_
argument_list|(
literal|"syntax error, unexpected %s, expecting %s or %s or %s"
argument_list|)
argument_list|)
expr_stmt|;
name|YYCASE_
argument_list|(
literal|5
argument_list|,
name|YY_
argument_list|(
literal|"syntax error, unexpected %s, expecting %s or %s or %s or %s"
argument_list|)
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|YYCASE_
block|}
block|{
name|YYSIZE_T
name|yysize1
init|=
name|yysize
operator|+
name|yystrlen
argument_list|(
name|yyformat
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|yysize
operator|<=
name|yysize1
operator|&&
name|yysize1
operator|<=
name|YYSTACK_ALLOC_MAXIMUM
operator|)
condition|)
return|return
literal|2
return|;
name|yysize
operator|=
name|yysize1
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|yymsg_alloc
operator|<
name|yysize
condition|)
block|{
operator|*
name|yymsg_alloc
operator|=
literal|2
operator|*
name|yysize
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|yysize
operator|<=
operator|*
name|yymsg_alloc
operator|&&
operator|*
name|yymsg_alloc
operator|<=
name|YYSTACK_ALLOC_MAXIMUM
operator|)
condition|)
operator|*
name|yymsg_alloc
operator|=
name|YYSTACK_ALLOC_MAXIMUM
expr_stmt|;
return|return
literal|1
return|;
block|}
comment|/* Avoid sprintf, as that infringes on the user's name space.      Don't have undefined behavior even if the translation      produced a string with the wrong number of "%s"s.  */
block|{
name|char
modifier|*
name|yyp
init|=
operator|*
name|yymsg
decl_stmt|;
name|int
name|yyi
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
operator|*
name|yyp
operator|=
operator|*
name|yyformat
operator|)
operator|!=
literal|'\0'
condition|)
if|if
condition|(
operator|*
name|yyp
operator|==
literal|'%'
operator|&&
name|yyformat
index|[
literal|1
index|]
operator|==
literal|'s'
operator|&&
name|yyi
operator|<
name|yycount
condition|)
block|{
name|yyp
operator|+=
name|yytnamerr
argument_list|(
name|yyp
argument_list|,
name|yyarg
index|[
name|yyi
operator|++
index|]
argument_list|)
expr_stmt|;
name|yyformat
operator|+=
literal|2
expr_stmt|;
block|}
else|else
block|{
name|yyp
operator|++
expr_stmt|;
name|yyformat
operator|++
expr_stmt|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* YYERROR_VERBOSE */
end_comment

begin_comment
comment|/*-----------------------------------------------. | Release the memory associated to this symbol.  | `-----------------------------------------------*/
end_comment

begin_function
specifier|static
name|void
name|yydestruct
parameter_list|(
specifier|const
name|char
modifier|*
name|yymsg
parameter_list|,
name|int
name|yytype
parameter_list|,
name|YYSTYPE
modifier|*
name|yyvaluep
parameter_list|)
block|{
name|YYUSE
argument_list|(
name|yyvaluep
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|yymsg
condition|)
name|yymsg
operator|=
literal|"Deleting"
expr_stmt|;
name|YY_SYMBOL_PRINT
argument_list|(
name|yymsg
argument_list|,
name|yytype
argument_list|,
name|yyvaluep
argument_list|,
name|yylocationp
argument_list|)
expr_stmt|;
name|YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
name|YYUSE
argument_list|(
name|yytype
argument_list|)
decl_stmt|;
name|YY_IGNORE_MAYBE_UNINITIALIZED_END
block|}
end_function

begin_comment
comment|/* The lookahead symbol.  */
end_comment

begin_decl_stmt
name|int
name|yychar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The semantic value of the lookahead symbol.  */
end_comment

begin_decl_stmt
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of syntax errors so far.  */
end_comment

begin_decl_stmt
name|int
name|yynerrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*----------. | yyparse.  | `----------*/
end_comment

begin_function
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|yystate
decl_stmt|;
comment|/* Number of tokens to shift before error messages enabled.  */
name|int
name|yyerrstatus
decl_stmt|;
comment|/* The stacks and their tools:        'yyss': related to states.        'yyvs': related to semantic values.         Refer to the stacks through separate pointers, to allow yyoverflow        to reallocate them elsewhere.  */
comment|/* The state stack.  */
name|yytype_int16
name|yyssa
index|[
name|YYINITDEPTH
index|]
decl_stmt|;
name|yytype_int16
modifier|*
name|yyss
decl_stmt|;
name|yytype_int16
modifier|*
name|yyssp
decl_stmt|;
comment|/* The semantic value stack.  */
name|YYSTYPE
name|yyvsa
index|[
name|YYINITDEPTH
index|]
decl_stmt|;
name|YYSTYPE
modifier|*
name|yyvs
decl_stmt|;
name|YYSTYPE
modifier|*
name|yyvsp
decl_stmt|;
name|YYSIZE_T
name|yystacksize
decl_stmt|;
name|int
name|yyn
decl_stmt|;
name|int
name|yyresult
decl_stmt|;
comment|/* Lookahead token as an internal (translated) token number.  */
name|int
name|yytoken
init|=
literal|0
decl_stmt|;
comment|/* The variables used to return semantic value and location from the      action routines.  */
name|YYSTYPE
name|yyval
decl_stmt|;
if|#
directive|if
name|YYERROR_VERBOSE
comment|/* Buffer for error messages, and its allocated size.  */
name|char
name|yymsgbuf
index|[
literal|128
index|]
decl_stmt|;
name|char
modifier|*
name|yymsg
init|=
name|yymsgbuf
decl_stmt|;
name|YYSIZE_T
name|yymsg_alloc
init|=
sizeof|sizeof
name|yymsgbuf
decl_stmt|;
endif|#
directive|endif
define|#
directive|define
name|YYPOPSTACK
parameter_list|(
name|N
parameter_list|)
value|(yyvsp -= (N), yyssp -= (N))
comment|/* The number of symbols on the RHS of the reduced rule.      Keep to zero when no symbol should be popped.  */
name|int
name|yylen
init|=
literal|0
decl_stmt|;
name|yyssp
operator|=
name|yyss
operator|=
name|yyssa
expr_stmt|;
name|yyvsp
operator|=
name|yyvs
operator|=
name|yyvsa
expr_stmt|;
name|yystacksize
operator|=
name|YYINITDEPTH
expr_stmt|;
name|YYDPRINTF
argument_list|(
operator|(
name|stderr
operator|,
literal|"Starting parse\n"
operator|)
argument_list|)
expr_stmt|;
name|yystate
operator|=
literal|0
expr_stmt|;
name|yyerrstatus
operator|=
literal|0
expr_stmt|;
name|yynerrs
operator|=
literal|0
expr_stmt|;
name|yychar
operator|=
name|YYEMPTY
expr_stmt|;
comment|/* Cause a token to be read.  */
goto|goto
name|yysetstate
goto|;
comment|/*------------------------------------------------------------. | yynewstate -- Push a new state, which is found in yystate.  | `------------------------------------------------------------*/
name|yynewstate
label|:
comment|/* In all cases, when you get here, the value and location stacks      have just been pushed.  So pushing a state here evens the stacks.  */
name|yyssp
operator|++
expr_stmt|;
name|yysetstate
label|:
operator|*
name|yyssp
operator|=
name|yystate
expr_stmt|;
if|if
condition|(
name|yyss
operator|+
name|yystacksize
operator|-
literal|1
operator|<=
name|yyssp
condition|)
block|{
comment|/* Get the current used size of the three stacks, in elements.  */
name|YYSIZE_T
name|yysize
init|=
name|yyssp
operator|-
name|yyss
operator|+
literal|1
decl_stmt|;
ifdef|#
directive|ifdef
name|yyoverflow
block|{
comment|/* Give user a chance to reallocate the stack.  Use copies of            these so that the&'s don't force the real ones into            memory.  */
name|YYSTYPE
modifier|*
name|yyvs1
init|=
name|yyvs
decl_stmt|;
name|yytype_int16
modifier|*
name|yyss1
init|=
name|yyss
decl_stmt|;
comment|/* Each stack pointer address is followed by the size of the            data in use in that stack, in bytes.  This used to be a            conditional around just the two extra args, but that might            be undefined if yyoverflow is a macro.  */
name|yyoverflow
argument_list|(
name|YY_
argument_list|(
literal|"memory exhausted"
argument_list|)
argument_list|,
operator|&
name|yyss1
argument_list|,
name|yysize
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|yyssp
argument_list|)
argument_list|,
operator|&
name|yyvs1
argument_list|,
name|yysize
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|yyvsp
argument_list|)
argument_list|,
operator|&
name|yystacksize
argument_list|)
expr_stmt|;
name|yyss
operator|=
name|yyss1
expr_stmt|;
name|yyvs
operator|=
name|yyvs1
expr_stmt|;
block|}
else|#
directive|else
comment|/* no yyoverflow */
ifndef|#
directive|ifndef
name|YYSTACK_RELOCATE
goto|goto
name|yyexhaustedlab
goto|;
else|#
directive|else
comment|/* Extend the stack our own way.  */
if|if
condition|(
name|YYMAXDEPTH
operator|<=
name|yystacksize
condition|)
goto|goto
name|yyexhaustedlab
goto|;
name|yystacksize
operator|*=
literal|2
expr_stmt|;
if|if
condition|(
name|YYMAXDEPTH
operator|<
name|yystacksize
condition|)
name|yystacksize
operator|=
name|YYMAXDEPTH
expr_stmt|;
block|{
name|yytype_int16
modifier|*
name|yyss1
init|=
name|yyss
decl_stmt|;
name|union
name|yyalloc
modifier|*
name|yyptr
init|=
operator|(
expr|union
name|yyalloc
operator|*
operator|)
name|YYSTACK_ALLOC
argument_list|(
name|YYSTACK_BYTES
argument_list|(
name|yystacksize
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|yyptr
condition|)
goto|goto
name|yyexhaustedlab
goto|;
name|YYSTACK_RELOCATE
argument_list|(
name|yyss_alloc
argument_list|,
name|yyss
argument_list|)
expr_stmt|;
name|YYSTACK_RELOCATE
argument_list|(
name|yyvs_alloc
argument_list|,
name|yyvs
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|YYSTACK_RELOCATE
if|if
condition|(
name|yyss1
operator|!=
name|yyssa
condition|)
name|YYSTACK_FREE
argument_list|(
name|yyss1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
comment|/* no yyoverflow */
name|yyssp
operator|=
name|yyss
operator|+
name|yysize
operator|-
literal|1
expr_stmt|;
name|yyvsp
operator|=
name|yyvs
operator|+
name|yysize
operator|-
literal|1
expr_stmt|;
name|YYDPRINTF
argument_list|(
operator|(
name|stderr
operator|,
literal|"Stack size increased to %lu\n"
operator|,
operator|(
name|unsigned
name|long
name|int
operator|)
name|yystacksize
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|yyss
operator|+
name|yystacksize
operator|-
literal|1
operator|<=
name|yyssp
condition|)
name|YYABORT
expr_stmt|;
block|}
name|YYDPRINTF
argument_list|(
operator|(
name|stderr
operator|,
literal|"Entering state %d\n"
operator|,
name|yystate
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|yystate
operator|==
name|YYFINAL
condition|)
name|YYACCEPT
expr_stmt|;
goto|goto
name|yybackup
goto|;
comment|/*-----------. | yybackup.  | `-----------*/
name|yybackup
label|:
comment|/* Do appropriate processing given the current state.  Read a      lookahead token if we need one and don't already have one.  */
comment|/* First try to decide what to do without reference to lookahead token.  */
name|yyn
operator|=
name|yypact
index|[
name|yystate
index|]
expr_stmt|;
if|if
condition|(
name|yypact_value_is_default
argument_list|(
name|yyn
argument_list|)
condition|)
goto|goto
name|yydefault
goto|;
comment|/* Not known => get a lookahead token if don't already have one.  */
comment|/* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
if|if
condition|(
name|yychar
operator|==
name|YYEMPTY
condition|)
block|{
name|YYDPRINTF
argument_list|(
operator|(
name|stderr
operator|,
literal|"Reading a token: "
operator|)
argument_list|)
expr_stmt|;
name|yychar
operator|=
name|yylex
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|yychar
operator|<=
name|YYEOF
condition|)
block|{
name|yychar
operator|=
name|yytoken
operator|=
name|YYEOF
expr_stmt|;
name|YYDPRINTF
argument_list|(
operator|(
name|stderr
operator|,
literal|"Now at end of input.\n"
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|yytoken
operator|=
name|YYTRANSLATE
argument_list|(
name|yychar
argument_list|)
expr_stmt|;
name|YY_SYMBOL_PRINT
argument_list|(
literal|"Next token is"
argument_list|,
name|yytoken
argument_list|,
operator|&
name|yylval
argument_list|,
operator|&
name|yylloc
argument_list|)
expr_stmt|;
block|}
comment|/* If the proper action on seeing token YYTOKEN is to reduce or to      detect an error, take that action.  */
name|yyn
operator|+=
name|yytoken
expr_stmt|;
if|if
condition|(
name|yyn
operator|<
literal|0
operator|||
name|YYLAST
operator|<
name|yyn
operator|||
name|yycheck
index|[
name|yyn
index|]
operator|!=
name|yytoken
condition|)
goto|goto
name|yydefault
goto|;
name|yyn
operator|=
name|yytable
index|[
name|yyn
index|]
expr_stmt|;
if|if
condition|(
name|yyn
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|yytable_value_is_error
argument_list|(
name|yyn
argument_list|)
condition|)
goto|goto
name|yyerrlab
goto|;
name|yyn
operator|=
operator|-
name|yyn
expr_stmt|;
goto|goto
name|yyreduce
goto|;
block|}
comment|/* Count tokens shifted since error; after three, turn off error      status.  */
if|if
condition|(
name|yyerrstatus
condition|)
name|yyerrstatus
operator|--
expr_stmt|;
comment|/* Shift the lookahead token.  */
name|YY_SYMBOL_PRINT
argument_list|(
literal|"Shifting"
argument_list|,
name|yytoken
argument_list|,
operator|&
name|yylval
argument_list|,
operator|&
name|yylloc
argument_list|)
expr_stmt|;
comment|/* Discard the shifted token.  */
name|yychar
operator|=
name|YYEMPTY
expr_stmt|;
name|yystate
operator|=
name|yyn
expr_stmt|;
name|YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
operator|*
operator|++
name|yyvsp
operator|=
name|yylval
expr_stmt|;
name|YY_IGNORE_MAYBE_UNINITIALIZED_END
goto|goto
name|yynewstate
goto|;
comment|/*-----------------------------------------------------------. | yydefault -- do the default action for the current state.  | `-----------------------------------------------------------*/
name|yydefault
label|:
name|yyn
operator|=
name|yydefact
index|[
name|yystate
index|]
expr_stmt|;
if|if
condition|(
name|yyn
operator|==
literal|0
condition|)
goto|goto
name|yyerrlab
goto|;
goto|goto
name|yyreduce
goto|;
comment|/*-----------------------------. | yyreduce -- Do a reduction.  | `-----------------------------*/
name|yyreduce
label|:
comment|/* yyn is the number of a rule to reduce with.  */
name|yylen
operator|=
name|yyr2
index|[
name|yyn
index|]
expr_stmt|;
comment|/* If YYLEN is nonzero, implement the default value of the action:      '$$ = $1'.       Otherwise, the following line sets YYVAL to garbage.      This behavior is undocumented and Bison      users should not rely upon it.  Assigning to YYVAL      unconditionally makes the parser a bit smaller, and it avoids a      GCC warning that YYVAL may be used uninitialized.  */
name|yyval
operator|=
name|yyvsp
index|[
literal|1
operator|-
name|yylen
index|]
expr_stmt|;
name|YY_REDUCE_PRINT
argument_list|(
name|yyn
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|yyn
condition|)
block|{
line|#
directive|line
number|1188
file|"null_gram.c"
comment|/* yacc.c:1646  */
default|default:
break|break;
block|}
comment|/* User semantic actions sometimes alter yychar, and that requires      that yytoken be updated with the new translation.  We take the      approach of translating immediately before every use of yytoken.      One alternative is translating here after every semantic action,      but that translation would be missed if the semantic action invokes      YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or      if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an      incorrect destructor might then be invoked immediately.  In the      case of YYERROR or YYBACKUP, subsequent parser actions might lead      to an incorrect destructor call or verbose syntax error message      before the lookahead is translated.  */
name|YY_SYMBOL_PRINT
argument_list|(
literal|"-> $$ ="
argument_list|,
name|yyr1
index|[
name|yyn
index|]
argument_list|,
operator|&
name|yyval
argument_list|,
operator|&
name|yyloc
argument_list|)
expr_stmt|;
name|YYPOPSTACK
argument_list|(
name|yylen
argument_list|)
expr_stmt|;
name|yylen
operator|=
literal|0
expr_stmt|;
name|YY_STACK_PRINT
argument_list|(
name|yyss
argument_list|,
name|yyssp
argument_list|)
expr_stmt|;
operator|*
operator|++
name|yyvsp
operator|=
name|yyval
expr_stmt|;
comment|/* Now 'shift' the result of the reduction.  Determine what state      that goes to, based on the state we popped back to and the rule      number reduced by.  */
name|yyn
operator|=
name|yyr1
index|[
name|yyn
index|]
expr_stmt|;
name|yystate
operator|=
name|yypgoto
index|[
name|yyn
operator|-
name|YYNTOKENS
index|]
operator|+
operator|*
name|yyssp
expr_stmt|;
if|if
condition|(
literal|0
operator|<=
name|yystate
operator|&&
name|yystate
operator|<=
name|YYLAST
operator|&&
name|yycheck
index|[
name|yystate
index|]
operator|==
operator|*
name|yyssp
condition|)
name|yystate
operator|=
name|yytable
index|[
name|yystate
index|]
expr_stmt|;
else|else
name|yystate
operator|=
name|yydefgoto
index|[
name|yyn
operator|-
name|YYNTOKENS
index|]
expr_stmt|;
goto|goto
name|yynewstate
goto|;
comment|/*--------------------------------------. | yyerrlab -- here on detecting error.  | `--------------------------------------*/
name|yyerrlab
label|:
comment|/* Make sure we have latest lookahead translation.  See comments at      user semantic actions for why this is necessary.  */
name|yytoken
operator|=
name|yychar
operator|==
name|YYEMPTY
condition|?
name|YYEMPTY
else|:
name|YYTRANSLATE
argument_list|(
name|yychar
argument_list|)
expr_stmt|;
comment|/* If not already recovering from an error, report this error.  */
if|if
condition|(
operator|!
name|yyerrstatus
condition|)
block|{
operator|++
name|yynerrs
expr_stmt|;
if|#
directive|if
operator|!
name|YYERROR_VERBOSE
name|yyerror
argument_list|(
name|YY_
argument_list|(
literal|"syntax error"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
define|#
directive|define
name|YYSYNTAX_ERROR
value|yysyntax_error (&yymsg_alloc,&yymsg, \                                         yyssp, yytoken)
block|{
name|char
specifier|const
modifier|*
name|yymsgp
init|=
name|YY_
argument_list|(
literal|"syntax error"
argument_list|)
decl_stmt|;
name|int
name|yysyntax_error_status
decl_stmt|;
name|yysyntax_error_status
operator|=
name|YYSYNTAX_ERROR
expr_stmt|;
if|if
condition|(
name|yysyntax_error_status
operator|==
literal|0
condition|)
name|yymsgp
operator|=
name|yymsg
expr_stmt|;
elseif|else
if|if
condition|(
name|yysyntax_error_status
operator|==
literal|1
condition|)
block|{
if|if
condition|(
name|yymsg
operator|!=
name|yymsgbuf
condition|)
name|YYSTACK_FREE
argument_list|(
name|yymsg
argument_list|)
expr_stmt|;
name|yymsg
operator|=
operator|(
name|char
operator|*
operator|)
name|YYSTACK_ALLOC
argument_list|(
name|yymsg_alloc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|yymsg
condition|)
block|{
name|yymsg
operator|=
name|yymsgbuf
expr_stmt|;
name|yymsg_alloc
operator|=
sizeof|sizeof
name|yymsgbuf
expr_stmt|;
name|yysyntax_error_status
operator|=
literal|2
expr_stmt|;
block|}
else|else
block|{
name|yysyntax_error_status
operator|=
name|YYSYNTAX_ERROR
expr_stmt|;
name|yymsgp
operator|=
name|yymsg
expr_stmt|;
block|}
block|}
name|yyerror
argument_list|(
name|yymsgp
argument_list|)
expr_stmt|;
if|if
condition|(
name|yysyntax_error_status
operator|==
literal|2
condition|)
goto|goto
name|yyexhaustedlab
goto|;
block|}
undef|#
directive|undef
name|YYSYNTAX_ERROR
endif|#
directive|endif
block|}
if|if
condition|(
name|yyerrstatus
operator|==
literal|3
condition|)
block|{
comment|/* If just tried and failed to reuse lookahead token after an          error, discard it.  */
if|if
condition|(
name|yychar
operator|<=
name|YYEOF
condition|)
block|{
comment|/* Return failure if at end of input.  */
if|if
condition|(
name|yychar
operator|==
name|YYEOF
condition|)
name|YYABORT
expr_stmt|;
block|}
else|else
block|{
name|yydestruct
argument_list|(
literal|"Error: discarding"
argument_list|,
name|yytoken
argument_list|,
operator|&
name|yylval
argument_list|)
expr_stmt|;
name|yychar
operator|=
name|YYEMPTY
expr_stmt|;
block|}
block|}
comment|/* Else will try to reuse lookahead token after shifting the error      token.  */
goto|goto
name|yyerrlab1
goto|;
comment|/*---------------------------------------------------. | yyerrorlab -- error raised explicitly by YYERROR.  | `---------------------------------------------------*/
name|yyerrorlab
label|:
comment|/* Pacify compilers like GCC when the user code never invokes      YYERROR and the label yyerrorlab therefore never appears in user      code.  */
if|if
condition|(
comment|/*CONSTCOND*/
literal|0
condition|)
goto|goto
name|yyerrorlab
goto|;
comment|/* Do not reclaim the symbols of the rule whose action triggered      this YYERROR.  */
name|YYPOPSTACK
argument_list|(
name|yylen
argument_list|)
expr_stmt|;
name|yylen
operator|=
literal|0
expr_stmt|;
name|YY_STACK_PRINT
argument_list|(
name|yyss
argument_list|,
name|yyssp
argument_list|)
expr_stmt|;
name|yystate
operator|=
operator|*
name|yyssp
expr_stmt|;
goto|goto
name|yyerrlab1
goto|;
comment|/*-------------------------------------------------------------. | yyerrlab1 -- common code for both syntax error and YYERROR.  | `-------------------------------------------------------------*/
name|yyerrlab1
label|:
name|yyerrstatus
operator|=
literal|3
expr_stmt|;
comment|/* Each real token shifted decrements this.  */
for|for
control|(
init|;
condition|;
control|)
block|{
name|yyn
operator|=
name|yypact
index|[
name|yystate
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|yypact_value_is_default
argument_list|(
name|yyn
argument_list|)
condition|)
block|{
name|yyn
operator|+=
name|YYTERROR
expr_stmt|;
if|if
condition|(
literal|0
operator|<=
name|yyn
operator|&&
name|yyn
operator|<=
name|YYLAST
operator|&&
name|yycheck
index|[
name|yyn
index|]
operator|==
name|YYTERROR
condition|)
block|{
name|yyn
operator|=
name|yytable
index|[
name|yyn
index|]
expr_stmt|;
if|if
condition|(
literal|0
operator|<
name|yyn
condition|)
break|break;
block|}
block|}
comment|/* Pop the current state because it cannot handle the error token.  */
if|if
condition|(
name|yyssp
operator|==
name|yyss
condition|)
name|YYABORT
expr_stmt|;
name|yydestruct
argument_list|(
literal|"Error: popping"
argument_list|,
name|yystos
index|[
name|yystate
index|]
argument_list|,
name|yyvsp
argument_list|)
expr_stmt|;
name|YYPOPSTACK
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|yystate
operator|=
operator|*
name|yyssp
expr_stmt|;
name|YY_STACK_PRINT
argument_list|(
name|yyss
argument_list|,
name|yyssp
argument_list|)
expr_stmt|;
block|}
name|YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
operator|*
operator|++
name|yyvsp
operator|=
name|yylval
expr_stmt|;
name|YY_IGNORE_MAYBE_UNINITIALIZED_END
comment|/* Shift the error token.  */
name|YY_SYMBOL_PRINT
argument_list|(
literal|"Shifting"
argument_list|,
name|yystos
index|[
name|yyn
index|]
argument_list|,
name|yyvsp
argument_list|,
name|yylsp
argument_list|)
decl_stmt|;
name|yystate
operator|=
name|yyn
expr_stmt|;
goto|goto
name|yynewstate
goto|;
comment|/*-------------------------------------. | yyacceptlab -- YYACCEPT comes here.  | `-------------------------------------*/
name|yyacceptlab
label|:
name|yyresult
operator|=
literal|0
expr_stmt|;
goto|goto
name|yyreturn
goto|;
comment|/*-----------------------------------. | yyabortlab -- YYABORT comes here.  | `-----------------------------------*/
name|yyabortlab
label|:
name|yyresult
operator|=
literal|1
expr_stmt|;
goto|goto
name|yyreturn
goto|;
if|#
directive|if
operator|!
name|defined
name|yyoverflow
operator|||
name|YYERROR_VERBOSE
comment|/*-------------------------------------------------. | yyexhaustedlab -- memory exhaustion comes here.  | `-------------------------------------------------*/
name|yyexhaustedlab
label|:
name|yyerror
argument_list|(
name|YY_
argument_list|(
literal|"memory exhausted"
argument_list|)
argument_list|)
expr_stmt|;
name|yyresult
operator|=
literal|2
expr_stmt|;
comment|/* Fall through.  */
endif|#
directive|endif
name|yyreturn
label|:
if|if
condition|(
name|yychar
operator|!=
name|YYEMPTY
condition|)
block|{
comment|/* Make sure we have latest lookahead translation.  See comments at          user semantic actions for why this is necessary.  */
name|yytoken
operator|=
name|YYTRANSLATE
argument_list|(
name|yychar
argument_list|)
expr_stmt|;
name|yydestruct
argument_list|(
literal|"Cleanup: discarding lookahead"
argument_list|,
name|yytoken
argument_list|,
operator|&
name|yylval
argument_list|)
expr_stmt|;
block|}
comment|/* Do not reclaim the symbols of the rule whose action triggered      this YYABORT or YYACCEPT.  */
name|YYPOPSTACK
argument_list|(
name|yylen
argument_list|)
expr_stmt|;
name|YY_STACK_PRINT
argument_list|(
name|yyss
argument_list|,
name|yyssp
argument_list|)
expr_stmt|;
while|while
condition|(
name|yyssp
operator|!=
name|yyss
condition|)
block|{
name|yydestruct
argument_list|(
literal|"Cleanup: popping"
argument_list|,
name|yystos
index|[
operator|*
name|yyssp
index|]
argument_list|,
name|yyvsp
argument_list|)
expr_stmt|;
name|YYPOPSTACK
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|yyoverflow
if|if
condition|(
name|yyss
operator|!=
name|yyssa
condition|)
name|YYSTACK_FREE
argument_list|(
name|yyss
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|YYERROR_VERBOSE
if|if
condition|(
name|yymsg
operator|!=
name|yymsgbuf
condition|)
name|YYSTACK_FREE
argument_list|(
name|yymsg
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|yyresult
return|;
block|}
end_function

end_unit

