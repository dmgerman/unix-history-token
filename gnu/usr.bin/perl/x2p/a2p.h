begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: a2p.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:37 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: a2p.h,v $  * Revision 1.2  1995/05/30 05:03:37  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:53  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:30:09  nate  * PERL!  *  * Revision 4.0.1.2  92/06/08  16:12:23  lwall  * patch20: hash tables now split only if the memory is available to do so  *  * Revision 4.0.1.1  91/06/07  12:12:27  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  01:57:07  lwall  * 4.0 baseline.  *  */
end_comment

begin_define
define|#
directive|define
name|VOIDUSED
value|1
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BCOPY
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BZERO
end_ifndef

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

begin_include
include|#
directive|include
file|"handy.h"
end_include

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
name|union
name|u_ops
name|ops
index|[
name|OPSMAX
index|]
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

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

begin_function_decl
name|STR
modifier|*
name|str_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|scanpat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|scannum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_free
parameter_list|()
function_decl|;
end_function_decl

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

end_unit

