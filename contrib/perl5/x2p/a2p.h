begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: a2p.h,v $$Revision: 4.1 $$Date: 92/08/07 18:29:09 $  *  *    Copyright (c) 1991-1997, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log:	a2p.h,v $  */
end_comment

begin_define
define|#
directive|define
name|VOIDUSED
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|_INC_WIN32_PERL5
end_define

begin_comment
comment|/* kludge around win32 stdio layer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|vax11c
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|__stdc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|STANDARD_C
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_undef
undef|#
directive|undef
name|USE_STDIO_PTR
end_undef

begin_comment
comment|/* XXX fast gets won't work, must investigate */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_C
end_ifndef

begin_define
define|#
directive|define
name|STANDARD_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|ccc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|rch
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|sig
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|pia
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|par
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|aus
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|use
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|csu
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|pro
end_pragma

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_elif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use all the "standard" definitions? */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_STDLIB
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STANDARD_C */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|I_MATH
end_ifdef

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_TYPES
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NEXT_CTYPE
end_ifdef

begin_if
if|#
directive|if
name|NX_CURRENT_COMPILER_RELEASE
operator|>=
literal|400
end_if

begin_include
include|#
directive|include
file|<objc/NXCType.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  NX_CURRENT_COMPILER_RELEASE< 400 */
end_comment

begin_include
include|#
directive|include
file|<appkit/NXCType.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  NX_CURRENT_COMPILER_RELEASE>= 400 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !USE_NEXT_CTYPE */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_NEXT_CTYPE */
end_comment

begin_define
define|#
directive|define
name|MEM_SIZE
value|Size_t
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STANDARD_C
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|Malloc_t
name|malloc
name|_
argument_list|(
operator|(
name|MEM_SIZE
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Malloc_t
name|calloc
name|_
argument_list|(
operator|(
name|MEM_SIZE
name|elements
operator|,
name|MEM_SIZE
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Malloc_t
name|realloc
name|_
argument_list|(
operator|(
name|Malloc_t
name|where
operator|,
name|MEM_SIZE
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Free_t
name|free
name|_
argument_list|(
operator|(
name|Malloc_t
name|where
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I_STRING
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAS_BCOPY
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|memcpy(s2,s1,l)
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
argument_list|(
name|HAS_BZERO
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|)
value|memset(s,0,l)
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
argument_list|(
name|HAS_STRCHR
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_INDEX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|strchr
argument_list|)
end_if

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_TIME
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_TIME
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_TIME_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_TIME_KERNEL
end_ifdef

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

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
name|MSDOS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_TIMES
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_SYS_TIMES
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

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
name|DOSISH
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OS2
argument_list|)
end_if

begin_include
include|#
directive|include
file|"../os2ish.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../dosish.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_PERL_TYPEDEFS
end_define

begin_include
include|#
directive|include
file|"vmsish.h"
end_include

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
name|STANDARD_C
end_ifndef

begin_comment
comment|/* All of these are in stdlib.h or time.h for ANSI C */
end_comment

begin_function_decl
name|Time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tm
modifier|*
name|gmtime
argument_list|()
decl_stmt|,
modifier|*
name|localtime
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! STANDARD_C */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|"handy.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../handy.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|Nullfp
end_undef

begin_define
define|#
directive|define
name|Nullfp
value|Null(FILE*)
end_define

begin_define
define|#
directive|define
name|Nullop
value|0
end_define

begin_define
define|#
directive|define
name|OPROG
value|1
end_define

begin_define
define|#
directive|define
name|OJUNK
value|2
end_define

begin_define
define|#
directive|define
name|OHUNKS
value|3
end_define

begin_define
define|#
directive|define
name|ORANGE
value|4
end_define

begin_define
define|#
directive|define
name|OPAT
value|5
end_define

begin_define
define|#
directive|define
name|OHUNK
value|6
end_define

begin_define
define|#
directive|define
name|OPPAREN
value|7
end_define

begin_define
define|#
directive|define
name|OPANDAND
value|8
end_define

begin_define
define|#
directive|define
name|OPOROR
value|9
end_define

begin_define
define|#
directive|define
name|OPNOT
value|10
end_define

begin_define
define|#
directive|define
name|OCPAREN
value|11
end_define

begin_define
define|#
directive|define
name|OCANDAND
value|12
end_define

begin_define
define|#
directive|define
name|OCOROR
value|13
end_define

begin_define
define|#
directive|define
name|OCNOT
value|14
end_define

begin_define
define|#
directive|define
name|ORELOP
value|15
end_define

begin_define
define|#
directive|define
name|ORPAREN
value|16
end_define

begin_define
define|#
directive|define
name|OMATCHOP
value|17
end_define

begin_define
define|#
directive|define
name|OMPAREN
value|18
end_define

begin_define
define|#
directive|define
name|OCONCAT
value|19
end_define

begin_define
define|#
directive|define
name|OASSIGN
value|20
end_define

begin_define
define|#
directive|define
name|OADD
value|21
end_define

begin_define
define|#
directive|define
name|OSUBTRACT
value|22
end_define

begin_define
define|#
directive|define
name|OMULT
value|23
end_define

begin_define
define|#
directive|define
name|ODIV
value|24
end_define

begin_define
define|#
directive|define
name|OMOD
value|25
end_define

begin_define
define|#
directive|define
name|OPOSTINCR
value|26
end_define

begin_define
define|#
directive|define
name|OPOSTDECR
value|27
end_define

begin_define
define|#
directive|define
name|OPREINCR
value|28
end_define

begin_define
define|#
directive|define
name|OPREDECR
value|29
end_define

begin_define
define|#
directive|define
name|OUMINUS
value|30
end_define

begin_define
define|#
directive|define
name|OUPLUS
value|31
end_define

begin_define
define|#
directive|define
name|OPAREN
value|32
end_define

begin_define
define|#
directive|define
name|OGETLINE
value|33
end_define

begin_define
define|#
directive|define
name|OSPRINTF
value|34
end_define

begin_define
define|#
directive|define
name|OSUBSTR
value|35
end_define

begin_define
define|#
directive|define
name|OSTRING
value|36
end_define

begin_define
define|#
directive|define
name|OSPLIT
value|37
end_define

begin_define
define|#
directive|define
name|OSNEWLINE
value|38
end_define

begin_define
define|#
directive|define
name|OINDEX
value|39
end_define

begin_define
define|#
directive|define
name|ONUM
value|40
end_define

begin_define
define|#
directive|define
name|OSTR
value|41
end_define

begin_define
define|#
directive|define
name|OVAR
value|42
end_define

begin_define
define|#
directive|define
name|OFLD
value|43
end_define

begin_define
define|#
directive|define
name|ONEWLINE
value|44
end_define

begin_define
define|#
directive|define
name|OCOMMENT
value|45
end_define

begin_define
define|#
directive|define
name|OCOMMA
value|46
end_define

begin_define
define|#
directive|define
name|OSEMICOLON
value|47
end_define

begin_define
define|#
directive|define
name|OSCOMMENT
value|48
end_define

begin_define
define|#
directive|define
name|OSTATES
value|49
end_define

begin_define
define|#
directive|define
name|OSTATE
value|50
end_define

begin_define
define|#
directive|define
name|OPRINT
value|51
end_define

begin_define
define|#
directive|define
name|OPRINTF
value|52
end_define

begin_define
define|#
directive|define
name|OBREAK
value|53
end_define

begin_define
define|#
directive|define
name|ONEXT
value|54
end_define

begin_define
define|#
directive|define
name|OEXIT
value|55
end_define

begin_define
define|#
directive|define
name|OCONTINUE
value|56
end_define

begin_define
define|#
directive|define
name|OREDIR
value|57
end_define

begin_define
define|#
directive|define
name|OIF
value|58
end_define

begin_define
define|#
directive|define
name|OWHILE
value|59
end_define

begin_define
define|#
directive|define
name|OFOR
value|60
end_define

begin_define
define|#
directive|define
name|OFORIN
value|61
end_define

begin_define
define|#
directive|define
name|OVFLD
value|62
end_define

begin_define
define|#
directive|define
name|OBLOCK
value|63
end_define

begin_define
define|#
directive|define
name|OREGEX
value|64
end_define

begin_define
define|#
directive|define
name|OLENGTH
value|65
end_define

begin_define
define|#
directive|define
name|OLOG
value|66
end_define

begin_define
define|#
directive|define
name|OEXP
value|67
end_define

begin_define
define|#
directive|define
name|OSQRT
value|68
end_define

begin_define
define|#
directive|define
name|OINT
value|69
end_define

begin_define
define|#
directive|define
name|ODO
value|70
end_define

begin_define
define|#
directive|define
name|OPOW
value|71
end_define

begin_define
define|#
directive|define
name|OSUB
value|72
end_define

begin_define
define|#
directive|define
name|OGSUB
value|73
end_define

begin_define
define|#
directive|define
name|OMATCH
value|74
end_define

begin_define
define|#
directive|define
name|OUSERFUN
value|75
end_define

begin_define
define|#
directive|define
name|OUSERDEF
value|76
end_define

begin_define
define|#
directive|define
name|OCLOSE
value|77
end_define

begin_define
define|#
directive|define
name|OATAN2
value|78
end_define

begin_define
define|#
directive|define
name|OSIN
value|79
end_define

begin_define
define|#
directive|define
name|OCOS
value|80
end_define

begin_define
define|#
directive|define
name|ORAND
value|81
end_define

begin_define
define|#
directive|define
name|OSRAND
value|82
end_define

begin_define
define|#
directive|define
name|ODELETE
value|83
end_define

begin_define
define|#
directive|define
name|OSYSTEM
value|84
end_define

begin_define
define|#
directive|define
name|OCOND
value|85
end_define

begin_define
define|#
directive|define
name|ORETURN
value|86
end_define

begin_define
define|#
directive|define
name|ODEFINED
value|87
end_define

begin_define
define|#
directive|define
name|OSTAR
value|88
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|opname
index|[]
init|=
block|{
literal|"0"
block|,
literal|"PROG"
block|,
literal|"JUNK"
block|,
literal|"HUNKS"
block|,
literal|"RANGE"
block|,
literal|"PAT"
block|,
literal|"HUNK"
block|,
literal|"PPAREN"
block|,
literal|"PANDAND"
block|,
literal|"POROR"
block|,
literal|"PNOT"
block|,
literal|"CPAREN"
block|,
literal|"CANDAND"
block|,
literal|"COROR"
block|,
literal|"CNOT"
block|,
literal|"RELOP"
block|,
literal|"RPAREN"
block|,
literal|"MATCHOP"
block|,
literal|"MPAREN"
block|,
literal|"CONCAT"
block|,
literal|"ASSIGN"
block|,
literal|"ADD"
block|,
literal|"SUBTRACT"
block|,
literal|"MULT"
block|,
literal|"DIV"
block|,
literal|"MOD"
block|,
literal|"POSTINCR"
block|,
literal|"POSTDECR"
block|,
literal|"PREINCR"
block|,
literal|"PREDECR"
block|,
literal|"UMINUS"
block|,
literal|"UPLUS"
block|,
literal|"PAREN"
block|,
literal|"GETLINE"
block|,
literal|"SPRINTF"
block|,
literal|"SUBSTR"
block|,
literal|"STRING"
block|,
literal|"SPLIT"
block|,
literal|"SNEWLINE"
block|,
literal|"INDEX"
block|,
literal|"NUM"
block|,
literal|"STR"
block|,
literal|"VAR"
block|,
literal|"FLD"
block|,
literal|"NEWLINE"
block|,
literal|"COMMENT"
block|,
literal|"COMMA"
block|,
literal|"SEMICOLON"
block|,
literal|"SCOMMENT"
block|,
literal|"STATES"
block|,
literal|"STATE"
block|,
literal|"PRINT"
block|,
literal|"PRINTF"
block|,
literal|"BREAK"
block|,
literal|"NEXT"
block|,
literal|"EXIT"
block|,
literal|"CONTINUE"
block|,
literal|"REDIR"
block|,
literal|"IF"
block|,
literal|"WHILE"
block|,
literal|"FOR"
block|,
literal|"FORIN"
block|,
literal|"VFLD"
block|,
literal|"BLOCK"
block|,
literal|"REGEX"
block|,
literal|"LENGTH"
block|,
literal|"LOG"
block|,
literal|"EXP"
block|,
literal|"SQRT"
block|,
literal|"INT"
block|,
literal|"DO"
block|,
literal|"POW"
block|,
literal|"SUB"
block|,
literal|"GSUB"
block|,
literal|"MATCH"
block|,
literal|"USERFUN"
block|,
literal|"USERDEF"
block|,
literal|"CLOSE"
block|,
literal|"ATAN2"
block|,
literal|"SIN"
block|,
literal|"COS"
block|,
literal|"RAND"
block|,
literal|"SRAND"
block|,
literal|"DELETE"
block|,
literal|"SYSTEM"
block|,
literal|"COND"
block|,
literal|"RETURN"
block|,
literal|"DEFINED"
block|,
literal|"STAR"
block|,
literal|"89"
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|opname
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|int
name|mop
name|INIT
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_union
union|union
name|u_ops
block|{
name|int
name|ival
decl_stmt|;
name|char
modifier|*
name|cval
decl_stmt|;
block|}
union|;
end_union

begin_if
if|#
directive|if
name|defined
argument_list|(
name|iAPX286
argument_list|)
operator|||
name|defined
argument_list|(
name|M_I286
argument_list|)
operator|||
name|defined
argument_list|(
name|I80286
argument_list|)
end_if

begin_comment
comment|/* 80286 hack */
end_comment

begin_define
define|#
directive|define
name|OPSMAX
value|(64000/sizeof(union u_ops))
end_define

begin_comment
comment|/* approx. max segment size */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPSMAX
value|50000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 80286 hack */
end_comment

begin_decl_stmt
name|EXT
name|union
name|u_ops
name|ops
index|[
name|OPSMAX
index|]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|string
name|STR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|htbl
name|HASH
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"str.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_comment
comment|/* A string is TRUE if not "" or "0". */
end_comment

begin_define
define|#
directive|define
name|True
parameter_list|(
name|val
parameter_list|)
value|(tmps = (val), (*tmps&& !(*tmps == '0'&& !tmps[1])))
end_define

begin_decl_stmt
name|EXT
name|char
modifier|*
name|Yes
name|INIT
argument_list|(
literal|"1"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|No
name|INIT
argument_list|(
literal|""
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|str_true
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), (Str->str_pok ? True(Str->str_ptr) : (Str->str_nok ? (Str->str_nval != 0.0) : 0 )))
end_define

begin_define
define|#
directive|define
name|str_peek
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), (Str->str_pok ? Str->str_ptr : (Str->str_nok ? (sprintf(buf,"num(%g)",Str->str_nval),buf) : "" )))
end_define

begin_define
define|#
directive|define
name|str_get
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), (Str->str_pok ? Str->str_ptr : str_2ptr(Str)))
end_define

begin_define
define|#
directive|define
name|str_gnum
parameter_list|(
name|str
parameter_list|)
value|(Str = (str), (Str->str_nok ? Str->str_nval : str_2num(Str)))
end_define

begin_decl_stmt
name|EXT
name|STR
modifier|*
name|Str
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GROWSTR
parameter_list|(
name|pp
parameter_list|,
name|lp
parameter_list|,
name|len
parameter_list|)
value|if (*(lp)< (len)) growstr(pp,lp,len)
end_define

begin_comment
comment|/* Prototypes for things in a2p.c */
end_comment

begin_decl_stmt
name|int
name|aryrefarg
name|_
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bl
name|_
argument_list|(
operator|(
name|int
name|arg
operator|,
name|int
name|maybe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dump
name|_
argument_list|(
operator|(
name|int
name|branch
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fixfargs
name|_
argument_list|(
operator|(
name|int
name|name
operator|,
name|int
name|arg
operator|,
name|int
name|prevargs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fixrargs
name|_
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|arg
operator|,
name|int
name|prevargs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fixup
name|_
argument_list|(
operator|(
name|STR
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|numary
name|_
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oper0
name|_
argument_list|(
operator|(
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oper1
name|_
argument_list|(
operator|(
name|int
name|type
operator|,
name|int
name|arg1
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oper2
name|_
argument_list|(
operator|(
name|int
name|type
operator|,
name|int
name|arg1
operator|,
name|int
name|arg2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oper3
name|_
argument_list|(
operator|(
name|int
name|type
operator|,
name|int
name|arg1
operator|,
name|int
name|arg2
operator|,
name|int
name|arg3
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oper4
name|_
argument_list|(
operator|(
name|int
name|type
operator|,
name|int
name|arg1
operator|,
name|int
name|arg2
operator|,
name|int
name|arg3
operator|,
name|int
name|arg4
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oper5
name|_
argument_list|(
operator|(
name|int
name|type
operator|,
name|int
name|arg1
operator|,
name|int
name|arg2
operator|,
name|int
name|arg3
operator|,
name|int
name|arg4
operator|,
name|int
name|arg5
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putlines
name|_
argument_list|(
operator|(
name|STR
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putone
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rememberargs
name|_
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|scannum
name|_
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|scanpat
name|_
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|string
name|_
argument_list|(
operator|(
name|char
operator|*
name|ptr
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|yyerror
name|_
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yylex
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|line
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|FILE
modifier|*
name|rsfp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|buf
index|[
literal|2048
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|char
modifier|*
name|bufptr
name|INIT
parameter_list|(
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|STR
modifier|*
name|linestr
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
name|tokenbuf
index|[
literal|2048
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|int
name|expectterm
name|INIT
parameter_list|(
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_decl_stmt
name|EXT
name|int
name|debug
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|dlevel
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|YYDEBUG
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXT
name|STR
modifier|*
name|freestrroot
name|INIT
parameter_list|(
name|Nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|STR
name|str_no
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|STR
name|str_yes
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|do_split
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|split_to_array
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|set_array_base
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|saw_RS
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|saw_OFS
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|saw_ORS
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|saw_line_op
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|in_begin
name|INIT
parameter_list|(
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|do_opens
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|do_fancy_opens
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|lval_field
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|do_chop
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|need_entire
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|absmaxfld
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|saw_altinput
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|nomemok
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
name|const_FS
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|char
modifier|*
name|namelist
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
name|fswitch
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|old_awk
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|saw_FS
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|maxfld
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|arymax
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|nameary
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|STR
modifier|*
name|opens
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|HASH
modifier|*
name|symtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|HASH
modifier|*
name|curarghash
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|P_MIN
value|0
end_define

begin_define
define|#
directive|define
name|P_LISTOP
value|5
end_define

begin_define
define|#
directive|define
name|P_COMMA
value|10
end_define

begin_define
define|#
directive|define
name|P_ASSIGN
value|15
end_define

begin_define
define|#
directive|define
name|P_COND
value|20
end_define

begin_define
define|#
directive|define
name|P_DOTDOT
value|25
end_define

begin_define
define|#
directive|define
name|P_OROR
value|30
end_define

begin_define
define|#
directive|define
name|P_ANDAND
value|35
end_define

begin_define
define|#
directive|define
name|P_OR
value|40
end_define

begin_define
define|#
directive|define
name|P_AND
value|45
end_define

begin_define
define|#
directive|define
name|P_EQ
value|50
end_define

begin_define
define|#
directive|define
name|P_REL
value|55
end_define

begin_define
define|#
directive|define
name|P_UNI
value|60
end_define

begin_define
define|#
directive|define
name|P_FILETEST
value|65
end_define

begin_define
define|#
directive|define
name|P_SHIFT
value|70
end_define

begin_define
define|#
directive|define
name|P_ADD
value|75
end_define

begin_define
define|#
directive|define
name|P_MUL
value|80
end_define

begin_define
define|#
directive|define
name|P_MATCH
value|85
end_define

begin_define
define|#
directive|define
name|P_UNARY
value|90
end_define

begin_define
define|#
directive|define
name|P_POW
value|95
end_define

begin_define
define|#
directive|define
name|P_AUTO
value|100
end_define

begin_define
define|#
directive|define
name|P_MAX
value|999
end_define

begin_decl_stmt
name|EXT
name|int
name|an
decl_stmt|;
end_decl_stmt

end_unit

