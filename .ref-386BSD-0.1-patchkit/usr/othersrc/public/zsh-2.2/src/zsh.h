begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * zsh.h - standard header file  *  * This file is part of zsh, the Z shell.  *  * This software is Copyright 1992 by Paul Falstad  *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   *  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_STRING
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_LOCALE
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_STDLIB
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<sys/bsdtypes.h>
end_include

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/sioctl.h>
end_include

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_define
define|#
directive|define
name|lstat
value|stat
end_define

begin_function_decl
specifier|extern
name|int
name|gethostname
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|m
parameter_list|)
value|m
end_define

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* this is the key to the whole thing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_IBMR2
end_ifdef

begin_undef
undef|#
directive|undef
name|_BSD
end_undef

begin_comment
comment|/* union wait SUCKS! */
end_comment

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_define
define|#
directive|define
name|_BSD
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV
end_ifndef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIO
end_ifdef

begin_define
define|#
directive|define
name|VDISABLEVAL
value|-1
end_define

begin_define
define|#
directive|define
name|TIO
value|1
end_define

begin_include
include|#
directive|include
file|<sys/termio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIOS
end_ifdef

begin_define
define|#
directive|define
name|VDISABLEVAL
value|0
end_define

begin_define
define|#
directive|define
name|TIO
value|1
end_define

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sgtty.h>
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
name|SYSV
end_ifdef

begin_undef
undef|#
directive|undef
name|TIOCGWINSZ
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__hp9000s800
end_ifdef

begin_include
include|#
directive|include
file|<sys/bsdtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|sun
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VERSIONSTR
value|"zsh v2.2.0"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* __STDC__ */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stat.h>
end_include

begin_define
define|#
directive|define
name|DCLPROTO
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_define
define|#
directive|define
name|DCLPROTO
parameter_list|(
name|X
parameter_list|)
value|()
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
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
comment|/* __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QDEBUG
end_ifdef

begin_define
define|#
directive|define
name|DCLPROTO
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFWORDCHARS
value|"*?_-.[]~=/&;!#$%^(){}<>"
end_define

begin_define
define|#
directive|define
name|DEFTIMEFMT
value|"%E real  %U user  %S system  %P %J"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UTMP_HOST
end_ifdef

begin_define
define|#
directive|define
name|DEFWATCHFMT
value|"%n has %a %l from %m."
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFWATCHFMT
value|"%n has %a %l."
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_STRING
end_ifdef

begin_define
define|#
directive|define
name|killpg
parameter_list|(
name|pgrp
parameter_list|,
name|sig
parameter_list|)
value|kill(-(pgrp),sig)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|00
end_define

begin_define
define|#
directive|define
name|R_OK
value|04
end_define

begin_define
define|#
directive|define
name|W_OK
value|02
end_define

begin_define
define|#
directive|define
name|X_OK
value|01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"zle.h"
end_include

begin_comment
comment|/* size of job list */
end_comment

begin_define
define|#
directive|define
name|MAXJOB
value|80
end_define

begin_comment
comment|/* memory allocation routines - changed with permalloc()/heapalloc() */
end_comment

begin_macro
name|vptr
argument_list|(
argument|*alloc
argument_list|)
end_macro

begin_expr_stmt
name|DCLPROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|vptr
argument_list|(
argument|*ncalloc
argument_list|)
end_macro

begin_expr_stmt
name|DCLPROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|addhnode
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|)
value|Addhnode(A,B,C,D,1)
end_define

begin_define
define|#
directive|define
name|addhperm
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|)
value|Addhnode(A,B,C,D,0)
end_define

begin_comment
comment|/* character tokens */
end_comment

begin_define
define|#
directive|define
name|ALPOP
value|((char) 0x81)
end_define

begin_define
define|#
directive|define
name|HISTSPACE
value|((char) 0x83)
end_define

begin_define
define|#
directive|define
name|Pound
value|((char) 0x84)
end_define

begin_define
define|#
directive|define
name|String
value|((char) 0x85)
end_define

begin_define
define|#
directive|define
name|Hat
value|((char) 0x86)
end_define

begin_define
define|#
directive|define
name|Star
value|((char) 0x87)
end_define

begin_define
define|#
directive|define
name|Inpar
value|((char) 0x88)
end_define

begin_define
define|#
directive|define
name|Outpar
value|((char) 0x89)
end_define

begin_define
define|#
directive|define
name|Qstring
value|((char) 0x8a)
end_define

begin_define
define|#
directive|define
name|Equals
value|((char) 0x8b)
end_define

begin_define
define|#
directive|define
name|Bar
value|((char) 0x8c)
end_define

begin_define
define|#
directive|define
name|Inbrace
value|((char) 0x8d)
end_define

begin_define
define|#
directive|define
name|Outbrace
value|((char) 0x8e)
end_define

begin_define
define|#
directive|define
name|Inbrack
value|((char) 0x8f)
end_define

begin_define
define|#
directive|define
name|Outbrack
value|((char) 0x90)
end_define

begin_define
define|#
directive|define
name|Tick
value|((char) 0x91)
end_define

begin_define
define|#
directive|define
name|Inang
value|((char) 0x92)
end_define

begin_define
define|#
directive|define
name|Outang
value|((char) 0x93)
end_define

begin_define
define|#
directive|define
name|Quest
value|((char) 0x94)
end_define

begin_define
define|#
directive|define
name|Tilde
value|((char) 0x95)
end_define

begin_define
define|#
directive|define
name|Qtick
value|((char) 0x96)
end_define

begin_define
define|#
directive|define
name|Comma
value|((char) 0x97)
end_define

begin_define
define|#
directive|define
name|Nularg
value|((char) 0x98)
end_define

begin_comment
comment|/* chars that need to be quoted if meant literally */
end_comment

begin_define
define|#
directive|define
name|SPECCHARS
value|"#$^*()$=|{}[]`<>?~;&!\n\t \\\'\""
end_define

begin_comment
comment|/* ALPOP in the form of a string */
end_comment

begin_define
define|#
directive|define
name|ALPOPS
value|" \201"
end_define

begin_define
define|#
directive|define
name|HISTMARK
value|"\201"
end_define

begin_define
define|#
directive|define
name|SEPER
value|1
end_define

begin_define
define|#
directive|define
name|NEWLIN
value|2
end_define

begin_define
define|#
directive|define
name|LEXERR
value|3
end_define

begin_define
define|#
directive|define
name|SEMI
value|4
end_define

begin_define
define|#
directive|define
name|DSEMI
value|5
end_define

begin_define
define|#
directive|define
name|AMPER
value|6
end_define

begin_define
define|#
directive|define
name|INPAR
value|7
end_define

begin_define
define|#
directive|define
name|INBRACE
value|8
end_define

begin_define
define|#
directive|define
name|OUTPAR
value|9
end_define

begin_define
define|#
directive|define
name|DBAR
value|10
end_define

begin_define
define|#
directive|define
name|DAMPER
value|11
end_define

begin_define
define|#
directive|define
name|BANG
value|12
end_define

begin_define
define|#
directive|define
name|OUTBRACE
value|13
end_define

begin_define
define|#
directive|define
name|OUTANG
value|14
end_define

begin_define
define|#
directive|define
name|OUTANGBANG
value|15
end_define

begin_define
define|#
directive|define
name|DOUTANG
value|16
end_define

begin_define
define|#
directive|define
name|DOUTANGBANG
value|17
end_define

begin_define
define|#
directive|define
name|INANG
value|18
end_define

begin_define
define|#
directive|define
name|DINANG
value|19
end_define

begin_define
define|#
directive|define
name|DINANGDASH
value|20
end_define

begin_define
define|#
directive|define
name|INANGAMP
value|21
end_define

begin_define
define|#
directive|define
name|OUTANGAMP
value|22
end_define

begin_define
define|#
directive|define
name|OUTANGAMPBANG
value|23
end_define

begin_define
define|#
directive|define
name|DOUTANGAMP
value|24
end_define

begin_define
define|#
directive|define
name|DOUTANGAMPBANG
value|25
end_define

begin_define
define|#
directive|define
name|TRINANG
value|26
end_define

begin_define
define|#
directive|define
name|BAR
value|27
end_define

begin_define
define|#
directive|define
name|BARAMP
value|28
end_define

begin_define
define|#
directive|define
name|DINBRACK
value|29
end_define

begin_define
define|#
directive|define
name|DOUTBRACK
value|30
end_define

begin_define
define|#
directive|define
name|STRING
value|31
end_define

begin_define
define|#
directive|define
name|ENVSTRING
value|32
end_define

begin_define
define|#
directive|define
name|ENVARRAY
value|33
end_define

begin_define
define|#
directive|define
name|ENDINPUT
value|34
end_define

begin_define
define|#
directive|define
name|INOUTPAR
value|35
end_define

begin_define
define|#
directive|define
name|DO
value|36
end_define

begin_define
define|#
directive|define
name|DONE
value|37
end_define

begin_define
define|#
directive|define
name|ESAC
value|38
end_define

begin_define
define|#
directive|define
name|THEN
value|39
end_define

begin_define
define|#
directive|define
name|ELIF
value|40
end_define

begin_define
define|#
directive|define
name|ELSE
value|41
end_define

begin_define
define|#
directive|define
name|FI
value|42
end_define

begin_define
define|#
directive|define
name|FOR
value|43
end_define

begin_define
define|#
directive|define
name|CASE
value|44
end_define

begin_define
define|#
directive|define
name|IF
value|45
end_define

begin_define
define|#
directive|define
name|WHILE
value|46
end_define

begin_define
define|#
directive|define
name|FUNC
value|47
end_define

begin_define
define|#
directive|define
name|REPEAT
value|48
end_define

begin_define
define|#
directive|define
name|TIME
value|49
end_define

begin_define
define|#
directive|define
name|UNTIL
value|50
end_define

begin_define
define|#
directive|define
name|EXEC
value|51
end_define

begin_define
define|#
directive|define
name|COMMAND
value|52
end_define

begin_define
define|#
directive|define
name|SELECT
value|53
end_define

begin_define
define|#
directive|define
name|COPROC
value|54
end_define

begin_define
define|#
directive|define
name|NOGLOB
value|55
end_define

begin_define
define|#
directive|define
name|DASH
value|56
end_define

begin_define
define|#
directive|define
name|NOCORRECT
value|57
end_define

begin_define
define|#
directive|define
name|FOREACH
value|58
end_define

begin_define
define|#
directive|define
name|ZEND
value|59
end_define

begin_define
define|#
directive|define
name|WRITE
value|0
end_define

begin_define
define|#
directive|define
name|WRITENOW
value|1
end_define

begin_define
define|#
directive|define
name|APP
value|2
end_define

begin_define
define|#
directive|define
name|APPNOW
value|3
end_define

begin_define
define|#
directive|define
name|MERGEOUT
value|4
end_define

begin_define
define|#
directive|define
name|MERGEOUTNOW
value|5
end_define

begin_define
define|#
directive|define
name|ERRAPP
value|6
end_define

begin_define
define|#
directive|define
name|ERRAPPNOW
value|7
end_define

begin_define
define|#
directive|define
name|READ
value|8
end_define

begin_define
define|#
directive|define
name|HEREDOC
value|9
end_define

begin_define
define|#
directive|define
name|HEREDOCDASH
value|10
end_define

begin_define
define|#
directive|define
name|HERESTR
value|11
end_define

begin_define
define|#
directive|define
name|MERGE
value|12
end_define

begin_define
define|#
directive|define
name|CLOSE
value|13
end_define

begin_define
define|#
directive|define
name|INPIPE
value|14
end_define

begin_define
define|#
directive|define
name|OUTPIPE
value|15
end_define

begin_define
define|#
directive|define
name|NONE
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GLOBALS
end_ifdef

begin_decl_stmt
name|int
name|redirtab
index|[
name|TRINANG
operator|-
name|OUTANG
operator|+
literal|1
index|]
init|=
block|{
name|WRITE
block|,
name|WRITENOW
block|,
name|APP
block|,
name|APPNOW
block|,
name|READ
block|,
name|HEREDOC
block|,
name|HEREDOCDASH
block|,
name|MERGE
block|,
name|MERGEOUT
block|,
name|MERGEOUTNOW
block|,
name|ERRAPP
block|,
name|ERRAPPNOW
block|,
name|HERESTR
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|redirtab
index|[
name|TRINANG
operator|-
name|OUTANG
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IS_READFD
parameter_list|(
name|X
parameter_list|)
value|((X)>=READ&& (X)<=MERGE)
end_define

begin_define
define|#
directive|define
name|IS_REDIROP
parameter_list|(
name|X
parameter_list|)
value|((X)>=OUTANG&& (X)<=TRINANG)
end_define

begin_define
define|#
directive|define
name|IS_ERROR_REDIR
parameter_list|(
name|X
parameter_list|)
value|((X)>=MERGEOUT&& (X)<=ERRAPPNOW)
end_define

begin_define
define|#
directive|define
name|UN_ERROR_REDIR
parameter_list|(
name|X
parameter_list|)
value|((X)-MERGEOUT+WRITE)
end_define

begin_define
define|#
directive|define
name|FD_WORD
value|-1
end_define

begin_define
define|#
directive|define
name|FD_COPROC
value|-2
end_define

begin_define
define|#
directive|define
name|FD_CLOSE
value|-3
end_define

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|hashtab
modifier|*
name|Hashtab
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hashnode
modifier|*
name|Hashnode
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|schedcmd
modifier|*
name|Schedcmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|alias
modifier|*
name|Alias
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|process
modifier|*
name|Process
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|job
modifier|*
name|Job
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|value
modifier|*
name|Value
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|arrind
modifier|*
name|Arrind
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|varasg
modifier|*
name|Varasg
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|param
modifier|*
name|Param
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cmdnam
modifier|*
name|Cmdnam
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cond
modifier|*
name|Cond
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cmd
modifier|*
name|Cmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pline
modifier|*
name|Pline
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sublist
modifier|*
name|Sublist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|list
modifier|*
name|List
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lklist
modifier|*
name|Lklist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lknode
modifier|*
name|Lknode
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|comp
modifier|*
name|Comp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|redir
modifier|*
name|Redir
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|complist
modifier|*
name|Complist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heap
modifier|*
name|Heap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|histent
modifier|*
name|Histent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hp
modifier|*
name|Hp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|compctl
modifier|*
name|Compctl
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*FFunc
argument_list|)
name|DCLPROTO
argument_list|(
operator|(
name|vptr
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|vptr
argument_list|(
argument|*VFunc
argument_list|)
name|DCLPROTO
argument_list|(
operator|(
name|vptr
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*HFunc
argument_list|)
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* linked list abstract data type */
end_comment

begin_struct_decl
struct_decl|struct
name|lknode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lklist
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|lknode
block|{
name|Lknode
name|next
decl_stmt|,
name|last
decl_stmt|;
name|vptr
name|dat
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lklist
block|{
name|Lknode
name|first
decl_stmt|,
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|addnode
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|insnode(X,(X)->last,Y)
end_define

begin_define
define|#
directive|define
name|full
parameter_list|(
name|X
parameter_list|)
value|((X)->first != NULL)
end_define

begin_define
define|#
directive|define
name|firstnode
parameter_list|(
name|X
parameter_list|)
value|((X)->first)
end_define

begin_define
define|#
directive|define
name|getaddrdata
parameter_list|(
name|X
parameter_list|)
value|(&((X)->dat))
end_define

begin_define
define|#
directive|define
name|getdata
parameter_list|(
name|X
parameter_list|)
value|((X)->dat)
end_define

begin_define
define|#
directive|define
name|setdata
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|((X)->dat = (Y))
end_define

begin_define
define|#
directive|define
name|lastnode
parameter_list|(
name|X
parameter_list|)
value|((X)->last)
end_define

begin_define
define|#
directive|define
name|nextnode
parameter_list|(
name|X
parameter_list|)
value|((X)->next)
end_define

begin_define
define|#
directive|define
name|prevnode
parameter_list|(
name|X
parameter_list|)
value|((X)->last)
end_define

begin_define
define|#
directive|define
name|peekfirst
parameter_list|(
name|X
parameter_list|)
value|((X)->first->dat)
end_define

begin_define
define|#
directive|define
name|pushnode
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|insnode(X,(Lknode) X,Y)
end_define

begin_define
define|#
directive|define
name|incnode
parameter_list|(
name|X
parameter_list|)
value|(X = nextnode(X))
end_define

begin_define
define|#
directive|define
name|gethistent
parameter_list|(
name|X
parameter_list|)
value|(histentarr+((X)%histentct))
end_define

begin_comment
comment|/* node structure for syntax trees */
end_comment

begin_comment
comment|/* struct list, struct sublist, struct pline, etc.  all fit the form 	of this structure and are used interchangably */
end_comment

begin_struct
struct|struct
name|node
block|{
name|int
name|data
index|[
literal|4
index|]
decl_stmt|;
comment|/* arbitrary integer data */
name|vptr
name|ptrs
index|[
literal|4
index|]
decl_stmt|;
comment|/* arbitrary pointer data */
name|int
name|types
index|[
literal|4
index|]
decl_stmt|;
comment|/* what ptrs[] are pointing to */
name|int
name|type
decl_stmt|;
comment|/* node type */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|N_LIST
value|0
end_define

begin_define
define|#
directive|define
name|N_SUBLIST
value|1
end_define

begin_define
define|#
directive|define
name|N_PLINE
value|2
end_define

begin_define
define|#
directive|define
name|N_CMD
value|3
end_define

begin_define
define|#
directive|define
name|N_REDIR
value|4
end_define

begin_define
define|#
directive|define
name|N_COND
value|5
end_define

begin_define
define|#
directive|define
name|N_FOR
value|6
end_define

begin_define
define|#
directive|define
name|N_CASE
value|7
end_define

begin_define
define|#
directive|define
name|N_IF
value|8
end_define

begin_define
define|#
directive|define
name|N_WHILE
value|9
end_define

begin_define
define|#
directive|define
name|N_VARASG
value|10
end_define

begin_define
define|#
directive|define
name|N_COUNT
value|11
end_define

begin_comment
comment|/* values for types[4] */
end_comment

begin_define
define|#
directive|define
name|NT_EMPTY
value|0
end_define

begin_define
define|#
directive|define
name|NT_NODE
value|1
end_define

begin_define
define|#
directive|define
name|NT_STR
value|2
end_define

begin_define
define|#
directive|define
name|NT_LIST
value|4
end_define

begin_define
define|#
directive|define
name|NT_MALLOC
value|8
end_define

begin_comment
comment|/* tree element for lists */
end_comment

begin_struct
struct|struct
name|list
block|{
name|int
name|type
decl_stmt|;
name|int
name|ifil
index|[
literal|3
index|]
decl_stmt|;
comment|/* to fit struct node */
name|Sublist
name|left
decl_stmt|;
name|List
name|right
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYNC
value|0
end_define

begin_comment
comment|/* ; */
end_comment

begin_define
define|#
directive|define
name|ASYNC
value|1
end_define

begin_comment
comment|/*& */
end_comment

begin_define
define|#
directive|define
name|TIMED
value|2
end_define

begin_comment
comment|/* tree element for sublists */
end_comment

begin_struct
struct|struct
name|sublist
block|{
name|int
name|type
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* see PFLAGs below */
name|int
name|ifil
index|[
literal|2
index|]
decl_stmt|;
name|Pline
name|left
decl_stmt|;
name|Sublist
name|right
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ORNEXT
value|10
end_define

begin_comment
comment|/* || */
end_comment

begin_define
define|#
directive|define
name|ANDNEXT
value|11
end_define

begin_comment
comment|/*&& */
end_comment

begin_define
define|#
directive|define
name|PFLAG_NOT
value|1
end_define

begin_comment
comment|/* ! ... */
end_comment

begin_define
define|#
directive|define
name|PFLAG_COPROC
value|32
end_define

begin_comment
comment|/* coproc ... */
end_comment

begin_comment
comment|/* tree element for pipes */
end_comment

begin_struct
struct|struct
name|pline
block|{
name|int
name|type
decl_stmt|;
name|int
name|ifil
index|[
literal|3
index|]
decl_stmt|;
name|Cmd
name|left
decl_stmt|;
name|Pline
name|right
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|END
value|0
end_define

begin_comment
comment|/* pnode *right is null */
end_comment

begin_define
define|#
directive|define
name|PIPE
value|1
end_define

begin_comment
comment|/* pnode *right is the rest of the pipeline */
end_comment

begin_comment
comment|/* tree element for commands */
end_comment

begin_struct
struct|struct
name|cmd
block|{
name|int
name|type
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* see CFLAGs below */
name|int
name|ifil
index|[
literal|2
index|]
decl_stmt|;
name|Lklist
name|args
decl_stmt|;
comment|/* command& argmument List (char *'s) */
union|union
block|{
name|List
name|list
decl_stmt|;
comment|/* for SUBSH/CURSH/SHFUNC */
name|struct
name|forcmd
modifier|*
name|forcmd
decl_stmt|;
name|struct
name|casecmd
modifier|*
name|casecmd
decl_stmt|;
name|struct
name|ifcmd
modifier|*
name|ifcmd
decl_stmt|;
name|struct
name|whilecmd
modifier|*
name|whilecmd
decl_stmt|;
name|Sublist
name|pline
decl_stmt|;
name|Cond
name|cond
decl_stmt|;
block|}
name|u
union|;
name|Lklist
name|redir
decl_stmt|;
comment|/* i/o redirections (struct redir *'s) */
name|Lklist
name|vars
decl_stmt|;
comment|/* param assignments (struct varasg *'s) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIMPLE
value|0
end_define

begin_define
define|#
directive|define
name|SUBSH
value|1
end_define

begin_define
define|#
directive|define
name|CURSH
value|2
end_define

begin_define
define|#
directive|define
name|ZCTIME
value|3
end_define

begin_define
define|#
directive|define
name|FUNCDEF
value|4
end_define

begin_define
define|#
directive|define
name|CFOR
value|5
end_define

begin_define
define|#
directive|define
name|CWHILE
value|6
end_define

begin_define
define|#
directive|define
name|CREPEAT
value|7
end_define

begin_define
define|#
directive|define
name|CIF
value|8
end_define

begin_define
define|#
directive|define
name|CCASE
value|9
end_define

begin_define
define|#
directive|define
name|CSELECT
value|10
end_define

begin_define
define|#
directive|define
name|COND
value|11
end_define

begin_define
define|#
directive|define
name|CFLAG_EXEC
value|1
end_define

begin_comment
comment|/* exec ... */
end_comment

begin_define
define|#
directive|define
name|CFLAG_COMMAND
value|2
end_define

begin_comment
comment|/* command ... */
end_comment

begin_define
define|#
directive|define
name|CFLAG_NOGLOB
value|4
end_define

begin_comment
comment|/* noglob ... */
end_comment

begin_define
define|#
directive|define
name|CFLAG_DASH
value|8
end_define

begin_comment
comment|/* - ... */
end_comment

begin_comment
comment|/* tree element for redirection lists */
end_comment

begin_struct
struct|struct
name|redir
block|{
name|int
name|type
decl_stmt|,
name|fd1
decl_stmt|,
name|fd2
decl_stmt|,
name|ifil
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* tree element for conditionals */
end_comment

begin_struct
struct|struct
name|cond
block|{
name|int
name|type
decl_stmt|;
comment|/* can be cond_type, or a single letter (-a, -b, ...) */
name|int
name|ifil
index|[
literal|3
index|]
decl_stmt|;
name|vptr
name|left
decl_stmt|,
name|right
decl_stmt|,
name|vfil
index|[
literal|2
index|]
decl_stmt|;
name|int
name|types
index|[
literal|4
index|]
decl_stmt|,
name|typ
decl_stmt|;
comment|/* from struct node.  DO NOT REMOVE */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|COND_NOT
value|0
end_define

begin_define
define|#
directive|define
name|COND_AND
value|1
end_define

begin_define
define|#
directive|define
name|COND_OR
value|2
end_define

begin_define
define|#
directive|define
name|COND_STREQ
value|3
end_define

begin_define
define|#
directive|define
name|COND_STRNEQ
value|4
end_define

begin_define
define|#
directive|define
name|COND_STRLT
value|5
end_define

begin_define
define|#
directive|define
name|COND_STRGTR
value|6
end_define

begin_define
define|#
directive|define
name|COND_NT
value|7
end_define

begin_define
define|#
directive|define
name|COND_OT
value|8
end_define

begin_define
define|#
directive|define
name|COND_EF
value|9
end_define

begin_define
define|#
directive|define
name|COND_EQ
value|10
end_define

begin_define
define|#
directive|define
name|COND_NE
value|11
end_define

begin_define
define|#
directive|define
name|COND_LT
value|12
end_define

begin_define
define|#
directive|define
name|COND_GT
value|13
end_define

begin_define
define|#
directive|define
name|COND_LE
value|14
end_define

begin_define
define|#
directive|define
name|COND_GE
value|15
end_define

begin_struct
struct|struct
name|forcmd
block|{
comment|/* for/select */
comment|/* Cmd->args contains list of words to loop thru */
name|int
name|inflag
decl_stmt|;
comment|/* if there is an in ... clause */
name|int
name|ifil
index|[
literal|3
index|]
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* parameter to assign values to */
name|List
name|list
decl_stmt|;
comment|/* list to look through for each name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|casecmd
block|{
comment|/* Cmd->args contains word to test */
name|int
name|ifil
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|casecmd
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|pat
decl_stmt|;
name|List
name|list
decl_stmt|;
comment|/* list to execute */
block|}
struct|;
end_struct

begin_comment
comment|/*  	a command like "if foo then bar elif baz then fubar else fooble" 	generates a tree like:  	struct ifcmd a = { next =&b,  ifl = "foo", thenl = "bar" } 	struct ifcmd b = { next =&c,  ifl = "baz", thenl = "fubar" } 	struct ifcmd c = { next = NULL, ifl = NULL, thenl = "fooble" }  */
end_comment

begin_struct
struct|struct
name|ifcmd
block|{
name|int
name|ifil
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|ifcmd
modifier|*
name|next
decl_stmt|;
name|List
name|ifl
decl_stmt|;
name|List
name|thenl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|whilecmd
block|{
name|int
name|cond
decl_stmt|;
comment|/* 0 for while, 1 for until */
name|int
name|ifil
index|[
literal|3
index|]
decl_stmt|;
name|List
name|cont
decl_stmt|;
comment|/* condition */
name|List
name|loop
decl_stmt|;
comment|/* list to execute until condition met */
block|}
struct|;
end_struct

begin_comment
comment|/* structure used for multiple i/o redirection */
end_comment

begin_comment
comment|/* one for each fd open */
end_comment

begin_struct
struct|struct
name|multio
block|{
name|int
name|ct
decl_stmt|;
comment|/* # of redirections on this fd */
name|int
name|rflag
decl_stmt|;
comment|/* 0 if open for reading, 1 if open for writing */
name|int
name|pipe
decl_stmt|;
comment|/* fd of pipe if ct> 1 */
name|int
name|fds
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* list of src/dests redirected to/from this fd */
block|}
struct|;
end_struct

begin_comment
comment|/* node used in command path hash table (cmdnamtab) */
end_comment

begin_struct
struct|struct
name|cmdnam
block|{
name|struct
name|hashnode
modifier|*
name|next
decl_stmt|;
name|int
name|canfree
decl_stmt|;
name|char
modifier|*
name|nam
decl_stmt|;
comment|/* hash data */
name|int
name|type
decl_stmt|,
name|flags
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|nam
decl_stmt|;
comment|/* full pathname if type != BUILTIN */
name|int
name|binnum
decl_stmt|;
comment|/* func to exec if type == BUILTIN */
name|List
name|list
decl_stmt|;
comment|/* list to exec if type == SHFUNC */
block|}
name|u
union|;
name|char
modifier|*
modifier|*
name|pcomp
decl_stmt|;
comment|/* location in path for EXCMD's */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXCMD
value|0
end_define

begin_define
define|#
directive|define
name|BUILTIN
value|2
end_define

begin_define
define|#
directive|define
name|SHFUNC
value|3
end_define

begin_define
define|#
directive|define
name|DISABLED
value|4
end_define

begin_define
define|#
directive|define
name|ISEXCMD
parameter_list|(
name|X
parameter_list|)
value|((X)==EXCMD)
end_define

begin_comment
comment|/* node used in parameter hash table (paramtab) */
end_comment

begin_struct
struct|struct
name|param
block|{
name|struct
name|hashnode
modifier|*
name|next
decl_stmt|;
name|int
name|canfree
decl_stmt|;
name|char
modifier|*
name|nam
decl_stmt|;
comment|/* hash data */
union|union
block|{
name|char
modifier|*
modifier|*
name|arr
decl_stmt|;
comment|/* value if declared array */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* value if declared string (scalar) */
name|long
name|val
decl_stmt|;
comment|/* value if declared integer */
block|}
name|u
union|;
union|union
block|{
comment|/* functions to call to set value */
name|void
argument_list|(
argument|*cfn
argument_list|)
name|DCLPROTO
argument_list|(
operator|(
name|Param
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*ifn
argument_list|)
name|DCLPROTO
argument_list|(
operator|(
name|Param
operator|,
name|long
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*afn
argument_list|)
name|DCLPROTO
argument_list|(
operator|(
name|Param
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
name|sets
union|;
union|union
block|{
comment|/* functions to call to get value */
name|char
operator|*
operator|(
operator|*
name|cfn
operator|)
name|DCLPROTO
argument_list|(
operator|(
name|Param
operator|)
argument_list|)
expr_stmt|;
name|long
argument_list|(
argument|*ifn
argument_list|)
name|DCLPROTO
argument_list|(
operator|(
name|Param
operator|)
argument_list|)
expr_stmt|;
name|char
operator|*
operator|*
operator|(
operator|*
name|afn
operator|)
name|DCLPROTO
argument_list|(
operator|(
name|Param
operator|)
argument_list|)
expr_stmt|;
block|}
name|gets
union|;
name|int
name|ct
decl_stmt|;
comment|/* output base or field width */
name|int
name|flags
decl_stmt|;
name|vptr
name|data
decl_stmt|;
comment|/* used by getfns */
name|char
modifier|*
name|env
decl_stmt|;
comment|/* location in environment, if exported */
name|char
modifier|*
name|ename
decl_stmt|;
comment|/* name of corresponding environment var */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMFLAG_s
value|0
end_define

begin_comment
comment|/* scalar */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_L
value|1
end_define

begin_comment
comment|/* left justify and remove leading blanks */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_R
value|2
end_define

begin_comment
comment|/* right justify and fill with leading blanks */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_Z
value|4
end_define

begin_comment
comment|/* right justify and fill with leading zeros */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_i
value|8
end_define

begin_comment
comment|/* integer */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_l
value|16
end_define

begin_comment
comment|/* all lower case */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_u
value|32
end_define

begin_comment
comment|/* all upper case */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_r
value|64
end_define

begin_comment
comment|/* readonly */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_t
value|128
end_define

begin_comment
comment|/* tagged */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_x
value|256
end_define

begin_comment
comment|/* exported */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_A
value|512
end_define

begin_comment
comment|/* array */
end_comment

begin_define
define|#
directive|define
name|PMFLAG_SPECIAL
value|1024
end_define

begin_define
define|#
directive|define
name|PMTYPE
value|(PMFLAG_i|PMFLAG_A)
end_define

begin_define
define|#
directive|define
name|pmtype
parameter_list|(
name|X
parameter_list|)
value|((X)->flags& PMTYPE)
end_define

begin_comment
comment|/* variable assignment tree element */
end_comment

begin_struct
struct|struct
name|varasg
block|{
name|int
name|type
decl_stmt|;
comment|/* nonzero means array */
name|int
name|ifil
index|[
literal|3
index|]
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
comment|/* should've been a union here.  oh well */
name|Lklist
name|arr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* lvalue for variable assignment/expansion */
end_comment

begin_struct
struct|struct
name|value
block|{
name|int
name|isarr
decl_stmt|;
name|struct
name|param
modifier|*
name|pm
decl_stmt|;
comment|/* parameter node */
name|int
name|a
decl_stmt|;
comment|/* first element of array slice, or -1 */
name|int
name|b
decl_stmt|;
comment|/* last element of array slice, or -1 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdpair
block|{
name|int
name|fd1
decl_stmt|,
name|fd2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* tty state structure */
end_comment

begin_struct
struct|struct
name|ttyinfo
block|{
ifdef|#
directive|ifdef
name|TERMIOS
name|struct
name|termios
name|tio
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|TERMIO
name|struct
name|termio
name|tio
decl_stmt|;
else|#
directive|else
name|struct
name|sgttyb
name|sgttyb
decl_stmt|;
name|int
name|lmodes
decl_stmt|;
name|struct
name|tchars
name|tchars
decl_stmt|;
name|struct
name|ltchars
name|ltchars
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCGWINSZ
name|struct
name|winsize
name|winsize
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|ttyinfo
name|savedttyinfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* entry in job table */
end_comment

begin_struct
struct|struct
name|job
block|{
name|long
name|gleader
decl_stmt|;
comment|/* process group leader of this job */
name|int
name|stat
decl_stmt|;
name|char
modifier|*
name|pwd
decl_stmt|;
comment|/* current working dir of shell when 											this job was spawned */
name|struct
name|process
modifier|*
name|procs
decl_stmt|;
comment|/* list of processes */
name|Lklist
name|filelist
decl_stmt|;
comment|/* list of files to delete when done */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STAT_CHANGED
value|1
end_define

begin_comment
comment|/* status changed and not reported */
end_comment

begin_define
define|#
directive|define
name|STAT_STOPPED
value|2
end_define

begin_comment
comment|/* all procs stopped or exited */
end_comment

begin_define
define|#
directive|define
name|STAT_TIMED
value|4
end_define

begin_comment
comment|/* job is being timed */
end_comment

begin_define
define|#
directive|define
name|STAT_DONE
value|8
end_define

begin_define
define|#
directive|define
name|STAT_LOCKED
value|16
end_define

begin_comment
comment|/* shell is finished creating this job, 										may be deleted from job table */
end_comment

begin_define
define|#
directive|define
name|STAT_INUSE
value|64
end_define

begin_comment
comment|/* this job entry is in use */
end_comment

begin_define
define|#
directive|define
name|SP_RUNNING
value|-1
end_define

begin_comment
comment|/* fake statusp for running jobs */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RUSAGE_CHILDREN
end_ifndef

begin_undef
undef|#
directive|undef
name|HAS_RUSAGE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|timeinfo
block|{
ifdef|#
directive|ifdef
name|HAS_RUSAGE
name|struct
name|rusage
name|ru
decl_stmt|;
else|#
directive|else
name|long
name|ut
decl_stmt|,
name|st
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* node in job process lists */
end_comment

begin_define
define|#
directive|define
name|JOBTEXTSIZE
value|80
end_define

begin_struct
struct|struct
name|process
block|{
name|struct
name|process
modifier|*
name|next
decl_stmt|;
name|long
name|pid
decl_stmt|;
name|char
name|text
index|[
name|JOBTEXTSIZE
index|]
decl_stmt|;
comment|/* text to print when 'jobs' is run */
name|int
name|statusp
decl_stmt|;
comment|/* return code from wait3() */
name|struct
name|timeinfo
name|ti
decl_stmt|;
name|time_t
name|bgtime
decl_stmt|;
comment|/* time job was spawned */
name|time_t
name|endtime
decl_stmt|;
comment|/* time job exited */
block|}
struct|;
end_struct

begin_comment
comment|/* node in alias hash table */
end_comment

begin_struct
struct|struct
name|alias
block|{
name|struct
name|hashnode
modifier|*
name|next
decl_stmt|;
name|int
name|canfree
decl_stmt|;
name|char
modifier|*
name|nam
decl_stmt|;
comment|/* hash data */
name|char
modifier|*
name|text
decl_stmt|;
comment|/* expansion of alias */
name|int
name|cmd
decl_stmt|;
comment|/* one for regular aliases, 								zero for global aliases, 								negative for reserved words */
name|int
name|inuse
decl_stmt|;
comment|/* alias is being expanded */
block|}
struct|;
end_struct

begin_comment
comment|/* node in sched list */
end_comment

begin_struct
struct|struct
name|schedcmd
block|{
name|struct
name|schedcmd
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|cmd
decl_stmt|;
comment|/* command to run */
name|time_t
name|time
decl_stmt|;
comment|/* when to run it */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXAL
value|20
end_define

begin_comment
comment|/* maximum number of aliases expanded at once */
end_comment

begin_comment
comment|/* hash table node */
end_comment

begin_struct
struct|struct
name|hashnode
block|{
name|struct
name|hashnode
modifier|*
name|next
decl_stmt|;
name|int
name|canfree
decl_stmt|;
comment|/* nam is free()able */
name|char
modifier|*
name|nam
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* hash table */
end_comment

begin_struct
struct|struct
name|hashtab
block|{
name|int
name|hsize
decl_stmt|;
comment|/* size of nodes[] */
name|int
name|ct
decl_stmt|;
comment|/* # of elements */
name|struct
name|hashnode
modifier|*
modifier|*
name|nodes
decl_stmt|;
comment|/* array of size hsize */
block|}
struct|;
end_struct

begin_comment
comment|/* history entry */
end_comment

begin_struct
struct|struct
name|histent
block|{
name|char
modifier|*
name|lex
decl_stmt|;
comment|/* lexical history line */
name|char
modifier|*
name|lit
decl_stmt|;
comment|/* literal history line */
name|time_t
name|stim
decl_stmt|;
comment|/* command started time (datestamp) */
name|time_t
name|ftim
decl_stmt|;
comment|/* command finished time */
block|}
struct|;
end_struct

begin_comment
comment|/* completion control */
end_comment

begin_struct
struct|struct
name|compctl
block|{
name|struct
name|hashnode
modifier|*
name|next
decl_stmt|;
name|int
name|canfree
decl_stmt|;
name|char
modifier|*
name|nam
decl_stmt|;
comment|/* hash data */
name|int
name|mask
decl_stmt|;
name|char
modifier|*
name|keyvar
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CC_FILES
value|1
end_define

begin_define
define|#
directive|define
name|CC_COMMPATH
value|2
end_define

begin_define
define|#
directive|define
name|CC_HOSTS
value|4
end_define

begin_define
define|#
directive|define
name|CC_OPTIONS
value|8
end_define

begin_define
define|#
directive|define
name|CC_VARS
value|16
end_define

begin_define
define|#
directive|define
name|CC_BINDINGS
value|32
end_define

begin_define
define|#
directive|define
name|CC_USRKEYS
value|64
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* values in opts[] array */
end_comment

begin_define
define|#
directive|define
name|OPT_INVALID
value|1
end_define

begin_comment
comment|/* opt is invalid, like -$ */
end_comment

begin_define
define|#
directive|define
name|OPT_UNSET
value|0
end_define

begin_define
define|#
directive|define
name|OPT_SET
value|2
end_define

begin_comment
comment|/* the options */
end_comment

begin_struct
struct|struct
name|option
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
name|id
decl_stmt|;
comment|/* corresponding letter */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CORRECT
value|'0'
end_define

begin_define
define|#
directive|define
name|NOCLOBBER
value|'1'
end_define

begin_define
define|#
directive|define
name|NOBADPATTERN
value|'2'
end_define

begin_define
define|#
directive|define
name|NONOMATCH
value|'3'
end_define

begin_define
define|#
directive|define
name|GLOBDOTS
value|'4'
end_define

begin_define
define|#
directive|define
name|NOTIFY
value|'5'
end_define

begin_define
define|#
directive|define
name|BGNICE
value|'6'
end_define

begin_define
define|#
directive|define
name|IGNOREEOF
value|'7'
end_define

begin_define
define|#
directive|define
name|MARKDIRS
value|'8'
end_define

begin_define
define|#
directive|define
name|AUTOLIST
value|'9'
end_define

begin_define
define|#
directive|define
name|NOBEEP
value|'B'
end_define

begin_define
define|#
directive|define
name|PRINTEXITVALUE
value|'C'
end_define

begin_define
define|#
directive|define
name|PUSHDTOHOME
value|'D'
end_define

begin_define
define|#
directive|define
name|PUSHDSILENT
value|'E'
end_define

begin_define
define|#
directive|define
name|NOGLOBOPT
value|'F'
end_define

begin_define
define|#
directive|define
name|NULLGLOB
value|'G'
end_define

begin_define
define|#
directive|define
name|RMSTARSILENT
value|'H'
end_define

begin_define
define|#
directive|define
name|IGNOREBRACES
value|'I'
end_define

begin_define
define|#
directive|define
name|AUTOCD
value|'J'
end_define

begin_define
define|#
directive|define
name|NOBANGHIST
value|'K'
end_define

begin_define
define|#
directive|define
name|SUNKEYBOARDHACK
value|'L'
end_define

begin_define
define|#
directive|define
name|SINGLELINEZLE
value|'M'
end_define

begin_define
define|#
directive|define
name|AUTOPUSHD
value|'N'
end_define

begin_define
define|#
directive|define
name|CORRECTALL
value|'O'
end_define

begin_define
define|#
directive|define
name|RCEXPANDPARAM
value|'P'
end_define

begin_define
define|#
directive|define
name|PATHDIRS
value|'Q'
end_define

begin_define
define|#
directive|define
name|LONGLISTJOBS
value|'R'
end_define

begin_define
define|#
directive|define
name|RECEXACT
value|'S'
end_define

begin_define
define|#
directive|define
name|CDABLEVARS
value|'T'
end_define

begin_define
define|#
directive|define
name|MAILWARNING
value|'U'
end_define

begin_define
define|#
directive|define
name|NOPROMPTCR
value|'V'
end_define

begin_define
define|#
directive|define
name|AUTORESUME
value|'W'
end_define

begin_define
define|#
directive|define
name|LISTTYPES
value|'X'
end_define

begin_define
define|#
directive|define
name|MENUCOMPLETE
value|'Y'
end_define

begin_define
define|#
directive|define
name|USEZLE
value|'Z'
end_define

begin_define
define|#
directive|define
name|ALLEXPORT
value|'a'
end_define

begin_define
define|#
directive|define
name|ERREXIT
value|'e'
end_define

begin_define
define|#
directive|define
name|NORCS
value|'f'
end_define

begin_define
define|#
directive|define
name|HISTIGNORESPACE
value|'g'
end_define

begin_define
define|#
directive|define
name|HISTIGNOREDUPS
value|'h'
end_define

begin_define
define|#
directive|define
name|INTERACTIVE
value|'i'
end_define

begin_define
define|#
directive|define
name|HISTLIT
value|'j'
end_define

begin_define
define|#
directive|define
name|INTERACTIVECOMMENTS
value|'k'
end_define

begin_define
define|#
directive|define
name|LOGINSHELL
value|'l'
end_define

begin_define
define|#
directive|define
name|MONITOR
value|'m'
end_define

begin_define
define|#
directive|define
name|NOEXEC
value|'n'
end_define

begin_define
define|#
directive|define
name|SHINSTDIN
value|'s'
end_define

begin_define
define|#
directive|define
name|NOUNSET
value|'u'
end_define

begin_define
define|#
directive|define
name|VERBOSE
value|'v'
end_define

begin_define
define|#
directive|define
name|CHASELINKS
value|'w'
end_define

begin_define
define|#
directive|define
name|XTRACE
value|'x'
end_define

begin_define
define|#
directive|define
name|SHWORDSPLIT
value|'y'
end_define

begin_define
define|#
directive|define
name|MENUCOMPLETEBEEP
value|'\2'
end_define

begin_define
define|#
directive|define
name|HISTNOSTORE
value|'\3'
end_define

begin_define
define|#
directive|define
name|EXTENDEDGLOB
value|'\5'
end_define

begin_define
define|#
directive|define
name|GLOBCOMPLETE
value|'\6'
end_define

begin_define
define|#
directive|define
name|CSHJUNKIEQUOTES
value|'\7'
end_define

begin_define
define|#
directive|define
name|PUSHDMINUS
value|'\10'
end_define

begin_define
define|#
directive|define
name|CSHJUNKIELOOPS
value|'\11'
end_define

begin_define
define|#
directive|define
name|RCQUOTES
value|'\12'
end_define

begin_define
define|#
directive|define
name|KSHOPTIONPRINT
value|'\13'
end_define

begin_define
define|#
directive|define
name|NOSHORTLOOPS
value|'\14'
end_define

begin_define
define|#
directive|define
name|LASTMENU
value|'\15'
end_define

begin_define
define|#
directive|define
name|AUTOMENU
value|'\16'
end_define

begin_define
define|#
directive|define
name|HISTVERIFY
value|'\17'
end_define

begin_define
define|#
directive|define
name|NOLISTBEEP
value|'\20'
end_define

begin_define
define|#
directive|define
name|NOHUP
value|'\21'
end_define

begin_define
define|#
directive|define
name|NOEQUALS
value|'\22'
end_define

begin_define
define|#
directive|define
name|CSHNULLGLOB
value|'\23'
end_define

begin_define
define|#
directive|define
name|HASHCMDS
value|'\24'
end_define

begin_define
define|#
directive|define
name|HASHDIRS
value|'\25'
end_define

begin_define
define|#
directive|define
name|NUMERICGLOBSORT
value|'\26'
end_define

begin_define
define|#
directive|define
name|BRACECCL
value|'\27'
end_define

begin_define
define|#
directive|define
name|HASHLISTALL
value|'\30'
end_define

begin_define
define|#
directive|define
name|OVERSTRIKE
value|'\31'
end_define

begin_define
define|#
directive|define
name|NOHISTBEEP
value|'\32'
end_define

begin_define
define|#
directive|define
name|PUSHDIGNOREDUPS
value|'\33'
end_define

begin_define
define|#
directive|define
name|AUTOREMOVESLASH
value|'\34'
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GLOBALS
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|option
name|optns
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|option
name|optns
index|[]
init|=
block|{
literal|"correct"
block|,
name|CORRECT
block|,
literal|"noclobber"
block|,
name|NOCLOBBER
block|,
literal|"nobadpattern"
block|,
name|NOBADPATTERN
block|,
literal|"nonomatch"
block|,
name|NONOMATCH
block|,
literal|"globdots"
block|,
name|GLOBDOTS
block|,
literal|"notify"
block|,
name|NOTIFY
block|,
literal|"bgnice"
block|,
name|BGNICE
block|,
literal|"ignoreeof"
block|,
name|IGNOREEOF
block|,
literal|"markdirs"
block|,
name|MARKDIRS
block|,
literal|"autolist"
block|,
name|AUTOLIST
block|,
literal|"nobeep"
block|,
name|NOBEEP
block|,
literal|"printexitvalue"
block|,
name|PRINTEXITVALUE
block|,
literal|"pushdtohome"
block|,
name|PUSHDTOHOME
block|,
literal|"pushdsilent"
block|,
name|PUSHDSILENT
block|,
literal|"noglob"
block|,
name|NOGLOBOPT
block|,
literal|"nullglob"
block|,
name|NULLGLOB
block|,
literal|"rmstarsilent"
block|,
name|RMSTARSILENT
block|,
literal|"ignorebraces"
block|,
name|IGNOREBRACES
block|,
literal|"braceccl"
block|,
name|BRACECCL
block|,
literal|"autocd"
block|,
name|AUTOCD
block|,
literal|"nobanghist"
block|,
name|NOBANGHIST
block|,
literal|"sunkeyboardhack"
block|,
name|SUNKEYBOARDHACK
block|,
literal|"singlelinezle"
block|,
name|SINGLELINEZLE
block|,
literal|"autopushd"
block|,
name|AUTOPUSHD
block|,
literal|"correctall"
block|,
name|CORRECTALL
block|,
literal|"rcexpandparam"
block|,
name|RCEXPANDPARAM
block|,
literal|"pathdirs"
block|,
name|PATHDIRS
block|,
literal|"longlistjobs"
block|,
name|LONGLISTJOBS
block|,
literal|"recexact"
block|,
name|RECEXACT
block|,
literal|"cdablevars"
block|,
name|CDABLEVARS
block|,
literal|"mailwarning"
block|,
name|MAILWARNING
block|,
literal|"nopromptcr"
block|,
name|NOPROMPTCR
block|,
literal|"autoresume"
block|,
name|AUTORESUME
block|,
literal|"listtypes"
block|,
name|LISTTYPES
block|,
literal|"menucomplete"
block|,
name|MENUCOMPLETE
block|,
literal|"zle"
block|,
name|USEZLE
block|,
literal|"allexport"
block|,
name|ALLEXPORT
block|,
literal|"errexit"
block|,
name|ERREXIT
block|,
literal|"norcs"
block|,
name|NORCS
block|,
literal|"histignorespace"
block|,
name|HISTIGNORESPACE
block|,
literal|"histignoredups"
block|,
name|HISTIGNOREDUPS
block|,
literal|"interactive"
block|,
name|INTERACTIVE
block|,
literal|"histlit"
block|,
name|HISTLIT
block|,
literal|"interactivecomments"
block|,
name|INTERACTIVECOMMENTS
block|,
literal|"login"
block|,
name|LOGINSHELL
block|,
literal|"monitor"
block|,
name|MONITOR
block|,
literal|"noexec"
block|,
name|NOEXEC
block|,
literal|"shinstdin"
block|,
name|SHINSTDIN
block|,
literal|"nounset"
block|,
name|NOUNSET
block|,
literal|"verbose"
block|,
name|VERBOSE
block|,
literal|"chaselinks"
block|,
name|CHASELINKS
block|,
literal|"xtrace"
block|,
name|XTRACE
block|,
literal|"shwordsplit"
block|,
name|SHWORDSPLIT
block|,
literal|"menucompletebeep"
block|,
name|MENUCOMPLETEBEEP
block|,
literal|"histnostore"
block|,
name|HISTNOSTORE
block|,
literal|"extendedglob"
block|,
name|EXTENDEDGLOB
block|,
literal|"globcomplete"
block|,
name|GLOBCOMPLETE
block|,
literal|"cshjunkiequotes"
block|,
name|CSHJUNKIEQUOTES
block|,
literal|"pushdminus"
block|,
name|PUSHDMINUS
block|,
literal|"cshjunkieloops"
block|,
name|CSHJUNKIELOOPS
block|,
literal|"rcquotes"
block|,
name|RCQUOTES
block|,
literal|"noshortloops"
block|,
name|NOSHORTLOOPS
block|,
literal|"lastmenu"
block|,
name|LASTMENU
block|,
literal|"automenu"
block|,
name|AUTOMENU
block|,
literal|"histverify"
block|,
name|HISTVERIFY
block|,
literal|"nolistbeep"
block|,
name|NOLISTBEEP
block|,
literal|"nohup"
block|,
name|NOHUP
block|,
literal|"noequals"
block|,
name|NOEQUALS
block|,
literal|"kshoptionprint"
block|,
name|KSHOPTIONPRINT
block|,
literal|"cshnullglob"
block|,
name|CSHNULLGLOB
block|,
literal|"hashcmds"
block|,
name|HASHCMDS
block|,
literal|"hashdirs"
block|,
name|HASHDIRS
block|,
literal|"numericglobsort"
block|,
name|NUMERICGLOBSORT
block|,
literal|"hashlistall"
block|,
name|HASHLISTALL
block|,
literal|"overstrike"
block|,
name|OVERSTRIKE
block|,
literal|"nohistbeep"
block|,
name|NOHISTBEEP
block|,
literal|"pushdignoredups"
block|,
name|PUSHDIGNOREDUPS
block|,
literal|"autoremoveslash"
block|,
name|AUTOREMOVESLASH
block|,
name|NULL
block|,
literal|0
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
name|ALSTAT_MORE
value|1
end_define

begin_comment
comment|/* last alias ended with ' ' */
end_comment

begin_define
define|#
directive|define
name|ALSTAT_JUNK
value|2
end_define

begin_comment
comment|/* don't put word in history List */
end_comment

begin_undef
undef|#
directive|undef
name|isset
end_undef

begin_define
define|#
directive|define
name|isset
parameter_list|(
name|X
parameter_list|)
value|(opts[X])
end_define

begin_define
define|#
directive|define
name|unset
parameter_list|(
name|X
parameter_list|)
value|(!opts[X])
end_define

begin_define
define|#
directive|define
name|interact
value|(isset(INTERACTIVE))
end_define

begin_define
define|#
directive|define
name|jobbing
value|(isset(MONITOR))
end_define

begin_define
define|#
directive|define
name|nointr
parameter_list|()
value|signal(SIGINT,SIG_IGN)
end_define

begin_define
define|#
directive|define
name|islogin
value|(isset(LOGINSHELL))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_IBMR2
end_ifndef

begin_undef
undef|#
directive|undef
name|WIFSTOPPED
end_undef

begin_undef
undef|#
directive|undef
name|WIFSIGNALED
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WTERMSIG
end_undef

begin_undef
undef|#
directive|undef
name|WSTOPSIG
end_undef

begin_undef
undef|#
directive|undef
name|WCOREDUMPED
end_undef

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|X
parameter_list|)
value|(((X)&0377)==0177)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|X
parameter_list|)
value|(((X)&0377)!=0&&((X)&0377)!=0177)
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|X
parameter_list|)
value|(((X)&0377)==0)
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|X
parameter_list|)
value|(((X)>>8)&0377)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|X
parameter_list|)
value|((X)&0177)
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|X
parameter_list|)
value|(((X)>>8)&0377)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WCOREDUMPED
parameter_list|(
name|X
parameter_list|)
value|((X)&0200)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISBLK
end_ifndef

begin_define
define|#
directive|define
name|_IFMT
value|0170000
end_define

begin_define
define|#
directive|define
name|_IFDIR
value|0040000
end_define

begin_define
define|#
directive|define
name|_IFCHR
value|0020000
end_define

begin_define
define|#
directive|define
name|_IFBLK
value|0060000
end_define

begin_define
define|#
directive|define
name|_IFREG
value|0100000
end_define

begin_define
define|#
directive|define
name|_IFIFO
value|0010000
end_define

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)&_IFMT) == _IFBLK)
end_define

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)&_IFMT) == _IFCHR)
end_define

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)&_IFMT) == _IFDIR)
end_define

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)&_IFMT) == _IFIFO)
end_define

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)&_IFMT) == _IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISSOCK
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_IFMT
end_ifndef

begin_define
define|#
directive|define
name|_IFMT
value|0170000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_IFLNK
value|0120000
end_define

begin_define
define|#
directive|define
name|_IFSOCK
value|0140000
end_define

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)&_IFMT) == _IFLNK)
end_define

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(((m)&_IFMT) == _IFSOCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|S_IFIFO
operator|==
name|S_IFSOCK
end_if

begin_undef
undef|#
directive|undef
name|S_IFIFO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFIFO
end_ifndef

begin_define
define|#
directive|define
name|NO_FIFOS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* buffered shell input for non-interactive shells */
end_comment

begin_decl_stmt
name|EXTERN
name|FILE
modifier|*
name|bshin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NULL-terminated arrays containing path, cdpath, etc. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|path
decl_stmt|,
modifier|*
modifier|*
name|cdpath
decl_stmt|,
modifier|*
modifier|*
name|fpath
decl_stmt|,
modifier|*
modifier|*
name|watch
decl_stmt|,
modifier|*
modifier|*
name|mailpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|manpath
decl_stmt|,
modifier|*
modifier|*
name|tildedirs
decl_stmt|,
modifier|*
modifier|*
name|fignore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|hosts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* named directories */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|userdirs
decl_stmt|,
modifier|*
modifier|*
name|usernames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of userdirs[], # of userdirs */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|userdirsz
decl_stmt|,
name|userdirct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|mailfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|yytext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error/break flag */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|errflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|tokstr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|tok
decl_stmt|,
name|tokfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lexical analyzer error flag */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|lexstop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress error messages */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|noerrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current history event number */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|curhist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if != 0, this is the first line of the command */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|isfirstln
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if != 0, this is the first char of the command (not including 	white space */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|isfirstch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of history entries */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|histentct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array of history entries */
end_comment

begin_decl_stmt
name|EXTERN
name|Histent
name|histentarr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* capacity of history lists */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|histsiz
decl_stmt|,
name|lithistsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if = 1, we have performed history substitution on the current line  	if = 2, we have used the 'p' modifier */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|histdone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default event (usually curhist-1, that is, "!!") */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|defev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we are about to read a command word */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|incmdpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we are in the middle of a [[ ... ]] */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|incond
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we are after a redirection (for ctxtlex only) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|inredir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we are about to read a case pattern */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|incasepat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we just read FUNCTION */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|infunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we just read a newline */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|isnewlin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the lists of history events */
end_comment

begin_decl_stmt
name|EXTERN
name|Lklist
name|histlist
decl_stmt|,
name|lithistlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the directory stack */
end_comment

begin_decl_stmt
name|EXTERN
name|Lklist
name|dirstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the zle buffer stack */
end_comment

begin_decl_stmt
name|EXTERN
name|Lklist
name|bufstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the input queue (stack?)  	inbuf    = start of buffer 	inbufptr = location in buffer (= inbuf for a FULL buffer) 											(= inbuf+inbufsz for an EMPTY buffer) 	inbufct  = # of chars in buffer (inbufptr+inbufct == inbuf+inbufsz) 	inbufsz  = max size of buffer */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|inbuf
decl_stmt|,
modifier|*
name|inbufptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|inbufct
decl_stmt|,
name|inbufsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|ifs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $IFS */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|oldpwd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $OLDPWD */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|underscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $_ */
end_comment

begin_comment
comment|/* != 0 if this is a subshell */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|subsh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of break levels */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|breaks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we have a return pending */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|retflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how far we've hashed the PATH so far */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|pathchecked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested loops we are in */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|loops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of continue levels */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|contflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the job we are working on */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|thisjob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current job (+) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|curjob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the previous job (-) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|prevjob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table containing the aliases and reserved words */
end_comment

begin_decl_stmt
name|EXTERN
name|Hashtab
name|aliastab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table containing the parameters */
end_comment

begin_decl_stmt
name|EXTERN
name|Hashtab
name|paramtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table containing the builtins/shfuncs/hashed commands */
end_comment

begin_decl_stmt
name|EXTERN
name|Hashtab
name|cmdnamtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table containing the zle multi-character bindings */
end_comment

begin_decl_stmt
name|EXTERN
name|Hashtab
name|xbindtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table for completion info for commands */
end_comment

begin_decl_stmt
name|EXTERN
name|Hashtab
name|compctltab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default completion infos */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|compctl
name|cc_compos
decl_stmt|,
name|cc_default
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the job table */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|job
name|jobtab
index|[
name|MAXJOB
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shell timings */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_RUSAGE
end_ifndef

begin_decl_stmt
name|EXTERN
name|struct
name|tms
name|shtms
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the list of sched jobs pending */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|schedcmd
modifier|*
name|schedcmds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last l for s/l/r/ history substitution */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|hsubl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last r for s/l/r/ history substitution */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|hsubr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|username
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $USERNAME */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|logname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $LOGNAME */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|lastval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $? */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|baud
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $BAUD */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|columns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $COLUMNS */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $LINES */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|reporttime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $REPORTTIME */
end_comment

begin_comment
comment|/* input fd from the coprocess */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|coprocin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output fd from the coprocess */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|coprocout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|long
name|mailcheck
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $MAILCHECK */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|logcheck
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $LOGCHECK */
end_comment

begin_comment
comment|/* the last time we checked mail */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|lastmailcheck
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last time we checked the people in the WATCH variable */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|lastwatch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last time we did the periodic() shell function */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|lastperiod
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $SECONDS = time(NULL) - shtimer */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|shtimer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|long
name|mypid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $$ */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|lastpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $! */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|ppid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $PPID */
end_comment

begin_comment
comment|/* the process group of the shell */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|mypgrp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|pwd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $PWD */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $OPTARG */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|zoptind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $OPTIND */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $PROMPT */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|rprompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $RPROMPT */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|prompt2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* etc. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|prompt3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|prompt4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|sprompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|timefmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|watchfmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|wordchars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|fceditparam
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|tmpprefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|rstring
decl_stmt|,
modifier|*
name|Rstring
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|postedit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|argzero
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $0 */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|hackzero
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the hostname */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|hostnam
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|home
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $HOME */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|pparams
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $argv */
end_comment

begin_comment
comment|/* the default command for null commands */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|nullcmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|readnullcmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the List of local variables we have to destroy */
end_comment

begin_decl_stmt
name|EXTERN
name|Lklist
name|locallist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the shell input fd */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|SHIN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the shell tty fd */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|SHTTY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the stack of aliases we are expanding */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|alias
modifier|*
name|alstack
index|[
name|MAXAL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the alias stack pointer; also, the number of aliases currently  	being expanded */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|alstackind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 means we are reading input from a string */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|strin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* period between periodic() commands, in seconds */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|period
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 means history substitution is turned off */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|stophist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|lithist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this line began with a space, so junk it if HISTIGNORESPACE is on */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|spaceflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't do spelling correction */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|nocorrect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 means we have removed the current event from the history List */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|histremmed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the options; e.g. if opts['a'] == OPT_SET, -a is turned on */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|opts
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|long
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LINENO */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|listmax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LISTMAX */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|savehist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SAVEHIST */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|shlvl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SHLVL */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|tmout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TMOUT */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|dirstacksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DIRSTACKSIZE */
end_comment

begin_comment
comment|/* != 0 means we have called execlist() and then intend to exit(),  	so don't fork if not necessary */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|exiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|lastbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last input base we used */
end_comment

begin_comment
comment|/* the limits for child processes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RLIM_INFINITY
end_ifdef

begin_decl_stmt
name|EXTERN
name|struct
name|rlimit
name|limits
index|[
name|RLIM_NLIMITS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the current word in the history List */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|hlastw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into the history line */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|hptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current history line */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|hline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the termcap buffer */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|termbuf
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $TERM */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|term
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if this $TERM setup is usable */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|termok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for CSHNULLGLOB */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|badcshglob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max size of hline */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|hlinesz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the alias expansion status - if == ALSTAT_MORE, we just finished 	expanding an alias ending with a space */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|alstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we have printed a 'you have stopped (running) jobs.' message */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|stopmsg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the default tty state */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|ttyinfo
name|shttyinfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $TTY */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|ttystrname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if ttyctl -f has been executed */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ttyfrozen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of memory heaps */
end_comment

begin_decl_stmt
name|EXTERN
name|Lklist
name|heaplist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we are allocating in the heaplist */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|useheap
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"signals.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|GLOBALS
end_ifdef

begin_comment
comment|/* signal names */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|sigptr
init|=
name|sigs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tokens */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ztokens
init|=
literal|"#$^*()$=|{}[]`<>?~`,"
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
name|ztokens
decl_stmt|,
modifier|*
modifier|*
name|sigptr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGERR
value|(SIGCOUNT+1)
end_define

begin_define
define|#
directive|define
name|SIGDEBUG
value|(SIGCOUNT+2)
end_define

begin_define
define|#
directive|define
name|VSIGCOUNT
value|(SIGCOUNT+3)
end_define

begin_define
define|#
directive|define
name|SIGEXIT
value|0
end_define

begin_comment
comment|/* signals that are trapped = 1, signals ignored =2 */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|sigtrapped
index|[
name|VSIGCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trap functions for each signal */
end_comment

begin_decl_stmt
name|EXTERN
name|List
name|sigfuncs
index|[
name|VSIGCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $HISTCHARS */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|bangchar
decl_stmt|,
name|hatchar
decl_stmt|,
name|hashchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|eofseen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we are parsing a line sent to use by the editor */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|zleparse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|wordbeg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|parbegin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interesting termcap strings */
end_comment

begin_define
define|#
directive|define
name|TCCLEARSCREEN
value|0
end_define

begin_define
define|#
directive|define
name|TCLEFT
value|1
end_define

begin_define
define|#
directive|define
name|TCMULTLEFT
value|2
end_define

begin_define
define|#
directive|define
name|TCRIGHT
value|3
end_define

begin_define
define|#
directive|define
name|TCMULTRIGHT
value|4
end_define

begin_define
define|#
directive|define
name|TCUP
value|5
end_define

begin_define
define|#
directive|define
name|TCMULTUP
value|6
end_define

begin_define
define|#
directive|define
name|TCDOWN
value|7
end_define

begin_define
define|#
directive|define
name|TCMULTDOWN
value|8
end_define

begin_define
define|#
directive|define
name|TCDEL
value|9
end_define

begin_define
define|#
directive|define
name|TCMULTDEL
value|10
end_define

begin_define
define|#
directive|define
name|TCINS
value|11
end_define

begin_define
define|#
directive|define
name|TCMULTINS
value|12
end_define

begin_define
define|#
directive|define
name|TCCLEAREOD
value|13
end_define

begin_define
define|#
directive|define
name|TCCLEAREOL
value|14
end_define

begin_define
define|#
directive|define
name|TCINSLINE
value|15
end_define

begin_define
define|#
directive|define
name|TCDELLINE
value|16
end_define

begin_define
define|#
directive|define
name|TC_COUNT
value|17
end_define

begin_comment
comment|/* lengths of each string */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|tclen
index|[
name|TC_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|tcstr
index|[
name|TC_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GLOBALS
end_ifdef

begin_comment
comment|/* names of the strings we want */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tccapnams
index|[
name|TC_COUNT
index|]
init|=
block|{
literal|"cl"
block|,
literal|"le"
block|,
literal|"LE"
block|,
literal|"nd"
block|,
literal|"RI"
block|,
literal|"up"
block|,
literal|"UP"
block|,
literal|"do"
block|,
literal|"DO"
block|,
literal|"dc"
block|,
literal|"DC"
block|,
literal|"ic"
block|,
literal|"IC"
block|,
literal|"cd"
block|,
literal|"ce"
block|,
literal|"al"
block|,
literal|"dl"
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
name|tccapnams
index|[
name|TC_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tccan
parameter_list|(
name|X
parameter_list|)
value|(!!tclen[X])
end_define

begin_define
define|#
directive|define
name|HISTFLAG_DONE
value|1
end_define

begin_define
define|#
directive|define
name|HISTFLAG_NOEXEC
value|2
end_define

begin_define
define|#
directive|define
name|HISTFLAG_RECALL
value|4
end_define

begin_include
include|#
directive|include
file|"ztype.h"
end_include

begin_include
include|#
directive|include
file|"funcs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETPGID
end_ifdef

begin_define
define|#
directive|define
name|setpgrp
value|setpgid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_INCLUDE_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|_INCLUDE_XOPEN_SOURCE
end_define

begin_define
define|#
directive|define
name|_INCLUDE_HPUX_SOURCE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SV_BSDSIG
end_ifdef

begin_define
define|#
directive|define
name|SV_INTERRUPT
value|SV_BSDSIG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SIGRELSE
end_ifdef

begin_define
define|#
directive|define
name|blockchld
parameter_list|()
value|sighold(SIGCHLD)
end_define

begin_define
define|#
directive|define
name|unblockchld
parameter_list|()
value|sigrelse(SIGCHLD)
end_define

begin_define
define|#
directive|define
name|chldsuspend
parameter_list|()
value|sigpause(SIGCHLD)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|blockchld
parameter_list|()
value|sigblock(sigmask(SIGCHLD))
end_define

begin_define
define|#
directive|define
name|unblockchld
parameter_list|()
value|sigsetmask(0)
end_define

begin_define
define|#
directive|define
name|chldsuspend
parameter_list|()
value|sigpause(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

