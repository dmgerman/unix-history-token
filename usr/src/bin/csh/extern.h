begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)extern.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * sh.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|rechist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|goodbye
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exitstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pintr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pintr1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dosource
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gethdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|importpath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initdesc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|untty
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|PROF
end_ifndef

begin_function_decl
specifier|extern
name|void
name|xexit
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|done
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|printprompt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.dir.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodirs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|dcanon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtildepr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtilde
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dochngd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|dnormalize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dopushd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dopopd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dfree
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.dol.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|Dfix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|Dfix1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|heredoc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.err.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|seterror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stderror
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.exec.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|doexec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|execash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xechoit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dohash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dounhash
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VFORK
end_ifdef

begin_function_decl
specifier|extern
name|void
name|hashstat
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * sh.exp.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|exp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|exp0
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.time.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|settimes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.file.c  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FILEC
end_ifdef

begin_function_decl
specifier|extern
name|int
name|tenex
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * sh.func.c  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|biltins
modifier|*
name|isbfunc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|func
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doonintr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|donohup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dozip
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prvars
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doalias
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unalias
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dologout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dologin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doif
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doelse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dogoto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doswitch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dobreak
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doexit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doforeach
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dowhile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|docontin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dorepeat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doswbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|srchx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doecho
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doglob
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dosetenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dounsetenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Setenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doumask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dolimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dounlimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dosuspend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doeval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.glob.c  */
end_comment

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|globall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ginit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Gmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Gcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rscan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tglob
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|globone
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|dobackp
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FILEC
end_ifdef

begin_function_decl
specifier|extern
name|int
name|sortcmp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * sh.hist.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|savehist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|Hist
modifier|*
name|enthist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dohist
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.lex.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|lex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prlex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copylex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|freelex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|addla
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|domod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unreadc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|readc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bseek
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|btell
end_ifndef

begin_function_decl
specifier|extern
name|off_t
name|btell
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|btoeof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|settell
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.misc.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|any
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsave
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|blkend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|blkpr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|number
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|blklen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|blkcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|blkcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|blkfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|saveblk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setzero
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NOTUSED
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strstr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|strspl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|blkspl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
name|lastchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|closem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|donefds
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lshift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|number
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|copyblk
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|SHORT_STRINGS
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strend
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|Char
modifier|*
name|strip
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|udvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|prefix
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.parse.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|alias
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|command
modifier|*
name|syntax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|freesyn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.print.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|psecs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pcsecs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xputchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|putraw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|putpure
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|draino
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.proc.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|pchild
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pnote
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pwait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pjwait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dowait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|palloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|psavejob
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prestjob
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pendjob
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dojobs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dofg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dofg1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dobg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dobg1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dokill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dostop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pstart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|panystop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|process
modifier|*
name|pfind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|donotify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pfork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pgetty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.sem.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|execute
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mypipe
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.set.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|doset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dolet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|putn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|value1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|varent
modifier|*
name|adrof1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unset1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unsetv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setNS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|shift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|plist
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * sh.time.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|settimes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dotime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|donice
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ruadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tvadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tvsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prusage
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * tc.alloc.c  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSMALLOC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_function_decl
specifier|extern
name|int
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|ptr_t
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ptr_t
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ptr_t
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|Free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ptr_t
name|Malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ptr_t
name|Realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ptr_t
name|Calloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSMALLOC */
end_comment

begin_function_decl
specifier|extern
name|void
name|showall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * tc.printf.h  */
end_comment

begin_function_decl
specifier|extern
name|void
name|xprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xsprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xvprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xvsprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * tc.str.c:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SHORT_STRINGS
end_ifdef

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strcat
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOTUSED
end_ifdef

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strncat
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strspl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|s_strlen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|s_strcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|s_strncmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strsave
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strspl
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOTUSED
end_ifdef

begin_function_decl
specifier|extern
name|Char
modifier|*
name|s_strstr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|Char
modifier|*
name|str2short
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Char
modifier|*
modifier|*
name|blk2short
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|short2str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|short2qstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|short2blk
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

