begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)defs.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *	S. R. Bourne  *	Rewritten by David Korn  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* error exits from various parts of shell */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_define
define|#
directive|define
name|SYNBAD
value|2
end_define

begin_define
define|#
directive|define
name|BYTESPERWORD
value|(sizeof(char *))
end_define

begin_define
define|#
directive|define
name|ENDARGS
value|0
end_define

begin_comment
comment|/* arg list terminator */
end_comment

begin_define
define|#
directive|define
name|NIL
value|((char*)0)
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

begin_comment
comment|/* typedefs used in the shell */
end_comment

begin_typedef
typedef|typedef
name|char
name|BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|MSG
index|[]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|STKPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|stat
name|STATBUF
typedef|;
end_typedef

begin_comment
comment|/* defined in /usr/include/sys/stat.h */
end_comment

begin_typedef
typedef|typedef
name|struct
name|blk
modifier|*
name|BLKPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fileblk
name|FILEBLK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fileblk
modifier|*
name|SHFILE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|trenod
modifier|*
name|TREPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|forknod
modifier|*
name|FORKPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|comnod
modifier|*
name|COMPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|swnod
modifier|*
name|SWPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|regnod
modifier|*
name|REGPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|parnod
modifier|*
name|PARPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ifnod
modifier|*
name|IFPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|whnod
modifier|*
name|WHPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fornod
modifier|*
name|FORPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lstnod
modifier|*
name|LSTPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|chnnod
modifier|*
name|CHNPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dolnod
modifier|*
name|DOLPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ionod
modifier|*
name|IOPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Namnod
name|NAMNOD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Namnod
modifier|*
name|NAMPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sysnod
modifier|*
name|SYSPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|procnod
modifier|*
name|PROCPTR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Rcheat
parameter_list|(
name|a
parameter_list|)
value|((unsigned)(a))
end_define

begin_define
define|#
directive|define
name|blank
parameter_list|()
value|putc(SP,output)
end_define

begin_define
define|#
directive|define
name|newline
parameter_list|()
value|putc(NL,output)
end_define

begin_define
define|#
directive|define
name|round
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((int)((ADR(a)+b)-1))&~((b)-1))
end_define

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a,b)==0)
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|exitset
parameter_list|()
value|(savexit=exitval)
end_define

begin_define
define|#
directive|define
name|error
parameter_list|(
name|s
parameter_list|)
value|failed(s,NIL)
end_define

begin_define
define|#
directive|define
name|BLK
parameter_list|(
name|x
parameter_list|)
value|((BLKPTR)(x))
end_define

begin_define
define|#
directive|define
name|BYT
parameter_list|(
name|x
parameter_list|)
value|((BYTPTR)(x))
end_define

begin_define
define|#
directive|define
name|STK
parameter_list|(
name|x
parameter_list|)
value|((STKPTR)(x))
end_define

begin_define
define|#
directive|define
name|ADR
parameter_list|(
name|x
parameter_list|)
value|((char*)(x))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

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

begin_comment
comment|/* BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VENIX
end_ifdef

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

begin_comment
comment|/* VENIX */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_typedef
typedef|typedef
name|long
name|optflag
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|INT16
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|pdp11
end_ifndef

begin_define
define|#
directive|define
name|_OPTIM_
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT16 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_OPTIM_
end_ifdef

begin_define
define|#
directive|define
name|_HIGH_
value|1
end_define

begin_define
define|#
directive|define
name|_LOW_
value|_HIGH_-1
end_define

begin_define
define|#
directive|define
name|is_option
parameter_list|(
name|flag
parameter_list|)
value|((flag)&0xffffL?\ 					st.Flags.i[_LOW_]&(unsigned int)(flag):\ 					st.Flags.i[_HIGH_]&(unsigned int)((flag)>>16))
end_define

begin_define
define|#
directive|define
name|on_option
parameter_list|(
name|flag
parameter_list|)
value|((flag)&0xffffL?\ 					(st.Flags.i[_LOW_] |= (unsigned int)(flag)):\ 					(st.Flags.i[_HIGH_] |= (unsigned int)((flag)>>16)))
end_define

begin_define
define|#
directive|define
name|off_option
parameter_list|(
name|flag
parameter_list|)
value|((flag)&0xffffL?\ 					(st.Flags.i[_LOW_]&= ~(unsigned int)(flag)):\ 					(st.Flags.i[_HIGH_]&= ~(unsigned int)((flag)>>16)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|is_option
parameter_list|(
name|flag
parameter_list|)
value|(st.Flags.l& (flag))
end_define

begin_define
define|#
directive|define
name|on_option
parameter_list|(
name|flag
parameter_list|)
value|(st.Flags.l |= (flag))
end_define

begin_define
define|#
directive|define
name|off_option
parameter_list|(
name|flag
parameter_list|)
value|(st.Flags.l&= ~(flag))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPTIM_ */
end_comment

begin_define
define|#
directive|define
name|Fixflg
value|1
end_define

begin_define
define|#
directive|define
name|Errflg
value|2
end_define

begin_define
define|#
directive|define
name|Readpr
value|3
end_define

begin_define
define|#
directive|define
name|Monitor
value|4
end_define

begin_define
define|#
directive|define
name|Intflg
value|5
end_define

begin_define
define|#
directive|define
name|Rshflg
value|6
end_define

begin_define
define|#
directive|define
name|Execpr
value|7
end_define

begin_define
define|#
directive|define
name|Keyflg
value|8
end_define

begin_define
define|#
directive|define
name|Noset
value|9
end_define

begin_define
define|#
directive|define
name|Noglob
value|10
end_define

begin_define
define|#
directive|define
name|Allexp
value|11
end_define

begin_define
define|#
directive|define
name|Noeof
value|13
end_define

begin_define
define|#
directive|define
name|Nomatch
value|14
end_define

begin_define
define|#
directive|define
name|Markdir
value|15
end_define

begin_define
define|#
directive|define
name|Bgnice
value|16
end_define

begin_define
define|#
directive|define
name|Editvi
value|17
end_define

begin_define
define|#
directive|define
name|Viraw
value|18
end_define

begin_define
define|#
directive|define
name|Oneflg
value|19
end_define

begin_define
define|#
directive|define
name|Hashall
value|20
end_define

begin_define
define|#
directive|define
name|Stdflg
value|21
end_define

begin_define
define|#
directive|define
name|Noexec
value|22
end_define

begin_define
define|#
directive|define
name|Notify
value|23
end_define

begin_define
define|#
directive|define
name|Gmacs
value|24
end_define

begin_define
define|#
directive|define
name|Emacs
value|25
end_define

begin_define
define|#
directive|define
name|Privmod
value|26
end_define

begin_define
define|#
directive|define
name|Inproc
value|27
end_define

begin_define
define|#
directive|define
name|FIXFLG
value|(1<<Fixflg)
end_define

begin_comment
comment|/* used also as a state */
end_comment

begin_define
define|#
directive|define
name|ERRFLG
value|(1<<Errflg)
end_define

begin_comment
comment|/* used also as a state */
end_comment

begin_define
define|#
directive|define
name|READPR
value|(1<<Readpr)
end_define

begin_comment
comment|/* used also as a state */
end_comment

begin_define
define|#
directive|define
name|MONITOR
value|(1<<Monitor)
end_define

begin_comment
comment|/* used also as a state */
end_comment

begin_define
define|#
directive|define
name|INTFLG
value|(1<<Intflg)
end_define

begin_comment
comment|/* used also as a state */
end_comment

begin_define
define|#
directive|define
name|RSHFLG
value|(1L<<Rshflg)
end_define

begin_define
define|#
directive|define
name|EXECPR
value|(1L<<Execpr)
end_define

begin_define
define|#
directive|define
name|KEYFLG
value|(1L<<Keyflg)
end_define

begin_define
define|#
directive|define
name|NOSET
value|(1L<<Noset)
end_define

begin_define
define|#
directive|define
name|NOGLOB
value|(1L<<Noglob)
end_define

begin_define
define|#
directive|define
name|ALLEXP
value|(1L<<Allexp)
end_define

begin_define
define|#
directive|define
name|NOEOF
value|(1L<<Noeof)
end_define

begin_define
define|#
directive|define
name|NOMATCH
value|(1L<<Nomatch)
end_define

begin_define
define|#
directive|define
name|EMACS
value|(1L<<Emacs)
end_define

begin_define
define|#
directive|define
name|BGNICE
value|(1L<<Bgnice)
end_define

begin_define
define|#
directive|define
name|EDITVI
value|(1L<<Editvi)
end_define

begin_define
define|#
directive|define
name|VIRAW
value|(1L<<Viraw)
end_define

begin_define
define|#
directive|define
name|ONEFLG
value|(1L<<Oneflg)
end_define

begin_define
define|#
directive|define
name|HASHALL
value|(1L<<Hashall)
end_define

begin_define
define|#
directive|define
name|STDFLG
value|(1L<<Stdflg)
end_define

begin_define
define|#
directive|define
name|NOEXEC
value|(1L<<Noexec)
end_define

begin_define
define|#
directive|define
name|NOTIFY
value|(1L<<Notify)
end_define

begin_define
define|#
directive|define
name|GMACS
value|(1L<<Gmacs)
end_define

begin_define
define|#
directive|define
name|MARKDIR
value|(1L<<Markdir)
end_define

begin_define
define|#
directive|define
name|PRIVM
value|(1L<<Privmod)
end_define

begin_define
define|#
directive|define
name|INPROC
value|(1L<<Inproc)
end_define

begin_define
define|#
directive|define
name|CFLAG
value|(1L<<30)
end_define

begin_comment
comment|/* states */
end_comment

begin_comment
comment|/* low numbered states are same as flags */
end_comment

begin_define
define|#
directive|define
name|PROMPT
value|INTFLG
end_define

begin_define
define|#
directive|define
name|WAITING
value|0x40
end_define

begin_define
define|#
directive|define
name|FORKED
value|0x80
end_define

begin_define
define|#
directive|define
name|TTYFLG
value|0x100
end_define

begin_define
define|#
directive|define
name|IS_TMP
value|0x200
end_define

begin_comment
comment|/* set when TMPFD is available */
end_comment

begin_define
define|#
directive|define
name|NO_TMP
value|0x400
end_define

begin_comment
comment|/* set when invalid /tmp/filename */
end_comment

begin_define
define|#
directive|define
name|RM_TMP
value|0x800
end_define

begin_comment
comment|/* temp files to remove on exit */
end_comment

begin_define
define|#
directive|define
name|FUNCTION
value|0x1000
end_define

begin_comment
comment|/* set when entering a function */
end_comment

begin_define
define|#
directive|define
name|RWAIT
value|0x2000
end_define

begin_comment
comment|/* set when waiting for a read */
end_comment

begin_define
define|#
directive|define
name|BUILTIN
value|0x4000
end_define

begin_comment
comment|/* set when processing built-in command */
end_comment

begin_define
define|#
directive|define
name|NONSTOP
value|0x8000
end_define

begin_comment
comment|/* set when job cannot be stopped */
end_comment

begin_define
define|#
directive|define
name|READC
value|0x10000
end_define

begin_comment
comment|/* only for BSD */
end_comment

begin_define
define|#
directive|define
name|VFORKED
value|0x20000
end_define

begin_comment
comment|/* only used with VFORK mode */
end_comment

begin_comment
comment|/*	fork constant	*/
end_comment

begin_define
define|#
directive|define
name|FORKLIM
value|32
end_define

begin_comment
comment|/*	comment delimiter 	*/
end_comment

begin_define
define|#
directive|define
name|COMCHAR
value|'#'
end_define

begin_define
define|#
directive|define
name|NL
value|'\n'
end_define

begin_define
define|#
directive|define
name|LITERAL
value|'\''
end_define

begin_define
define|#
directive|define
name|ENDOF
value|0
end_define

begin_define
define|#
directive|define
name|STRIP
value|0377
end_define

begin_define
define|#
directive|define
name|SP
value|' '
end_define

begin_define
define|#
directive|define
name|NOEXP
value|1
end_define

begin_define
define|#
directive|define
name|HAT
value|'^'
end_define

begin_define
define|#
directive|define
name|ESCAPE
value|'\\'
end_define

begin_define
define|#
directive|define
name|HIGHBIT
value|0200
end_define

begin_define
define|#
directive|define
name|TO_PRINT
value|0100
end_define

begin_comment
comment|/* bit to set for printing control char */
end_comment

begin_decl_stmt
specifier|extern
name|MSG
name|argcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|argexp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|arglist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|atline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|baddir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badexec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badopt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badparam
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badsub
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badtrap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|blet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|bltfn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|bset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|bread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|colon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|coredump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|defedit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|defpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|dot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|endmatch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|fn_hdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|execpmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|intbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|is_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|is_alias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|is_builtin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|is_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|is_reserved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|is_talias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|is_xalias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|is_xfunction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|logout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|mailmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|minus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|noalias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|nofork
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|noquery
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|nosign
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|nospace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|noswap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|notfound
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|nullstr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|off_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|on_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|opt_heading
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|parexp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|pexists
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|ptrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|recursive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|restricted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|setpwd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|sptbnl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|stdprompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|suid_profile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|supprompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|t_real
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|t_sys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|t_user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|toobig
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|txtbsy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|unlimited
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|unset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|pcsadr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|pidadr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|pwderr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Amemory
modifier|*
name|alias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for alias names */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Namnod
modifier|*
name|bltin_nodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Saves the state of the shell  */
end_comment

begin_struct
struct|struct
name|State
block|{
name|jmp_buf
name|jmpbuf
decl_stmt|;
union|union
block|{
name|long
name|l
decl_stmt|;
ifdef|#
directive|ifdef
name|_OPTIM_
name|int
name|i
index|[
literal|2
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* _OPTIM_ */
block|}
name|Flags
union|;
name|unsigned
name|States
decl_stmt|;
name|int
name|Breakcnt
decl_stmt|;
name|int
name|Execbrk
decl_stmt|;
name|int
name|Loopcnt
decl_stmt|;
name|int
name|Fn_depth
decl_stmt|;
name|int
name|Peekc
decl_stmt|;
name|int
name|Peekn
decl_stmt|;
name|int
name|Aliflg
decl_stmt|;
name|int
name|Reserv
decl_stmt|;
name|char
modifier|*
name|Cmdadr
decl_stmt|;
name|int
name|Cmdline
decl_stmt|;
name|int
name|Firstline
decl_stmt|;
name|int
name|Exec_flag
decl_stmt|;
name|int
name|Dolc
decl_stmt|;
name|char
modifier|*
modifier|*
name|Dolv
decl_stmt|;
name|IOPTR
name|Iopend
decl_stmt|;
name|int
name|Ioset
decl_stmt|;
name|IOPTR
name|Iotemp
decl_stmt|;
name|int
name|Linked
decl_stmt|;
name|SHFILE
name|Standin
decl_stmt|;
name|FILE
modifier|*
name|Standout
decl_stmt|;
name|FILE
modifier|*
name|Cpipe
index|[
literal|2
index|]
decl_stmt|;
name|int
name|Cpid
decl_stmt|;
name|int
name|Wdset
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|State
name|st
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|flags
value|st.Flags.l
end_define

begin_define
define|#
directive|define
name|states
value|st.States
end_define

begin_define
define|#
directive|define
name|breakcnt
value|st.Breakcnt
end_define

begin_define
define|#
directive|define
name|loopcnt
value|st.Loopcnt
end_define

begin_define
define|#
directive|define
name|execbrk
value|st.Execbrk
end_define

begin_define
define|#
directive|define
name|fn_depth
value|st.Fn_depth
end_define

begin_define
define|#
directive|define
name|peekc
value|st.Peekc
end_define

begin_define
define|#
directive|define
name|peekn
value|st.Peekn
end_define

begin_define
define|#
directive|define
name|aliflg
value|st.Aliflg
end_define

begin_define
define|#
directive|define
name|reserv
value|st.Reserv
end_define

begin_define
define|#
directive|define
name|cmdadr
value|st.Cmdadr
end_define

begin_define
define|#
directive|define
name|cmdline
value|st.Cmdline
end_define

begin_define
define|#
directive|define
name|firstline
value|st.Firstline
end_define

begin_define
define|#
directive|define
name|exec_flag
value|st.Exec_flag
end_define

begin_define
define|#
directive|define
name|dolc
value|st.Dolc
end_define

begin_define
define|#
directive|define
name|dolv
value|st.Dolv
end_define

begin_define
define|#
directive|define
name|linked
value|st.Linked
end_define

begin_define
define|#
directive|define
name|iotemp
value|st.Iotemp
end_define

begin_define
define|#
directive|define
name|ioset
value|st.Ioset
end_define

begin_define
define|#
directive|define
name|iopend
value|st.Iopend
end_define

begin_define
define|#
directive|define
name|standout
value|st.Standout
end_define

begin_define
define|#
directive|define
name|standin
value|st.Standin
end_define

begin_define
define|#
directive|define
name|cpipe
value|st.Cpipe
end_define

begin_define
define|#
directive|define
name|cpid
value|st.Cpid
end_define

begin_define
define|#
directive|define
name|wdset
value|st.Wdset
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|comdiv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|exitval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lastarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|mailchk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|oldexit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|ppid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Amemory
modifier|*
name|prnames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for function names */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|savexit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|topfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|trapcom
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|trapnote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|login_sh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|userid
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|INT16
end_ifndef

begin_define
define|#
directive|define
name|INT16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT16 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INT16
end_ifdef

begin_comment
comment|/* save space */
end_comment

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_define
define|#
directive|define
name|putc
value|fputc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT16 */
end_comment

end_unit

