begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|PP
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_define
define|#
directive|define
name|CWIDTH
value|7
end_define

begin_define
define|#
directive|define
name|CMASK
value|0177
end_define

begin_define
define|#
directive|define
name|ASCII
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|gcos
end_ifdef

begin_define
define|#
directive|define
name|CWIDTH
value|9
end_define

begin_define
define|#
directive|define
name|CMASK
value|0777
end_define

begin_define
define|#
directive|define
name|ASCII
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ibm
end_ifdef

begin_define
define|#
directive|define
name|CWIDTH
value|8
end_define

begin_define
define|#
directive|define
name|CMASK
value|0377
end_define

begin_define
define|#
directive|define
name|EBCDIC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII
end_ifdef

begin_define
define|#
directive|define
name|NCH
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EBCDIC
end_ifdef

begin_define
define|#
directive|define
name|NCH
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TOKENSIZE
value|1000
end_define

begin_define
define|#
directive|define
name|DEFSIZE
value|40
end_define

begin_define
define|#
directive|define
name|DEFCHAR
value|1000
end_define

begin_define
define|#
directive|define
name|STARTCHAR
value|100
end_define

begin_define
define|#
directive|define
name|STARTSIZE
value|256
end_define

begin_define
define|#
directive|define
name|CCLSIZE
value|1000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL
end_ifdef

begin_define
define|#
directive|define
name|TREESIZE
value|600
end_define

begin_define
define|#
directive|define
name|NTRANS
value|1500
end_define

begin_define
define|#
directive|define
name|NSTATES
value|300
end_define

begin_define
define|#
directive|define
name|MAXPOS
value|1500
end_define

begin_define
define|#
directive|define
name|NOUTPUT
value|1500
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SMALL
end_ifndef

begin_define
define|#
directive|define
name|TREESIZE
value|1000
end_define

begin_define
define|#
directive|define
name|NSTATES
value|500
end_define

begin_define
define|#
directive|define
name|MAXPOS
value|2500
end_define

begin_define
define|#
directive|define
name|NTRANS
value|2000
end_define

begin_define
define|#
directive|define
name|NOUTPUT
value|3000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NACTIONS
value|100
end_define

begin_define
define|#
directive|define
name|ALITTLEEXTRA
value|30
end_define

begin_define
define|#
directive|define
name|RCCL
value|NCH+90
end_define

begin_define
define|#
directive|define
name|RNCCL
value|NCH+91
end_define

begin_define
define|#
directive|define
name|RSTR
value|NCH+92
end_define

begin_define
define|#
directive|define
name|RSCON
value|NCH+93
end_define

begin_define
define|#
directive|define
name|RNEWE
value|NCH+94
end_define

begin_define
define|#
directive|define
name|FINAL
value|NCH+95
end_define

begin_define
define|#
directive|define
name|RNULLS
value|NCH+96
end_define

begin_define
define|#
directive|define
name|RCAT
value|NCH+97
end_define

begin_define
define|#
directive|define
name|STAR
value|NCH+98
end_define

begin_define
define|#
directive|define
name|PLUS
value|NCH+99
end_define

begin_define
define|#
directive|define
name|QUEST
value|NCH+100
end_define

begin_define
define|#
directive|define
name|DIV
value|NCH+101
end_define

begin_define
define|#
directive|define
name|BAR
value|NCH+102
end_define

begin_define
define|#
directive|define
name|CARAT
value|NCH+103
end_define

begin_define
define|#
directive|define
name|S1FINAL
value|NCH+104
end_define

begin_define
define|#
directive|define
name|S2FINAL
value|NCH+105
end_define

begin_define
define|#
directive|define
name|DEFSECTION
value|1
end_define

begin_define
define|#
directive|define
name|RULESECTION
value|2
end_define

begin_define
define|#
directive|define
name|ENDSECTION
value|5
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|PC
value|1
end_define

begin_define
define|#
directive|define
name|PS
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|LINESIZE
value|110
end_define

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 = on */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|charc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|freturn
parameter_list|(
name|s
parameter_list|)
value|s
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|sargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|sargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|buf
index|[
literal|520
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ratfor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 = ratfor, 0 = C */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number of file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lgatflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|divflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|funcflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|casecount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|chset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 = char set modified */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fin
decl_stmt|,
modifier|*
name|fout
decl_stmt|,
modifier|*
name|fother
decl_stmt|,
modifier|*
name|errorf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ratname
decl_stmt|,
modifier|*
name|cname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|prev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous input character */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pres
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* present input character */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peek
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next input character */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|left
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|right
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|parent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nullstr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|pushc
index|[
name|TOKENSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pushptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|slist
index|[
name|STARTSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|slptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|def
decl_stmt|,
modifier|*
modifier|*
name|subs
decl_stmt|,
modifier|*
name|dchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|sname
decl_stmt|,
modifier|*
name|schar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ccl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ccptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dp
decl_stmt|,
modifier|*
name|sp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dptr
decl_stmt|,
name|sptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* store input position */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tmpstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
modifier|*
name|foll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|nxtpos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|positions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|gotof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|nexts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
modifier|*
name|state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|sfall
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fallback state num */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cpackflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if state has been character packed */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|atable
decl_stmt|,
name|aptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|symbol
index|[
name|NCH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|cindex
index|[
name|NCH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xstate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ctable
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ZCH
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ccount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|match
index|[
name|NCH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|extra
index|[
name|NACTIONS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pcptr
decl_stmt|,
modifier|*
name|pchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pchlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nstates
decl_stmt|,
name|maxpos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yytop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|report
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntrans
decl_stmt|,
name|treesize
decl_stmt|,
name|outsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|rcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|verify
decl_stmt|,
modifier|*
name|advance
decl_stmt|,
modifier|*
name|stoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|psave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|myalloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|buserr
argument_list|()
decl_stmt|,
name|segviol
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

