begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NOICP
end_ifndef

begin_comment
comment|/*  C K U U S 5 --  "User Interface" for Unix Kermit, part 5  */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_comment
comment|/* Includes */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_include
include|#
directive|include
file|"ckcasc.h"
end_include

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_include
include|#
directive|include
file|"ckuusr.h"
end_include

begin_include
include|#
directive|include
file|"ckcnet.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NOCSETS
end_ifndef

begin_include
include|#
directive|include
file|"ckcxla.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCSETS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_include
include|#
directive|include
file|"ckmasm.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_comment
comment|/* For formatted screens, "more?" prompting, etc. */
end_comment

begin_define
define|#
directive|define
name|SCRNLEN
value|21
end_define

begin_comment
comment|/* Screen length */
end_comment

begin_define
define|#
directive|define
name|SCRNWID
value|79
end_define

begin_comment
comment|/* Screen width */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT18
end_ifdef

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|isdigit(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT18 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* Internal MAC file routines */
end_comment

begin_define
define|#
directive|define
name|feof
value|mac_feof
end_define

begin_define
define|#
directive|define
name|rewind
value|mac_rewind
end_define

begin_define
define|#
directive|define
name|fgets
value|mac_fgets
end_define

begin_define
define|#
directive|define
name|fopen
value|mac_fopen
end_define

begin_define
define|#
directive|define
name|fclose
value|mac_fclose
end_define

begin_function_decl
name|int
name|mac_feof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_rewind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mac_fgets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|mac_fopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_fclose
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_comment
comment|/* External variables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|carrier
decl_stmt|,
name|cdtimo
decl_stmt|,
name|local
decl_stmt|,
name|backgrd
decl_stmt|,
name|bgset
decl_stmt|,
name|sosi
decl_stmt|,
name|suspend
decl_stmt|,
name|displa
decl_stmt|,
name|binary
decl_stmt|,
name|deblog
decl_stmt|,
name|escape
decl_stmt|,
name|xargs
decl_stmt|,
name|flow
decl_stmt|,
name|cmdmsk
decl_stmt|,
name|duplex
decl_stmt|,
name|ckxech
decl_stmt|,
name|pktlog
decl_stmt|,
name|seslog
decl_stmt|,
name|tralog
decl_stmt|,
name|what
decl_stmt|,
name|keep
decl_stmt|,
name|warn
decl_stmt|,
name|tlevel
decl_stmt|,
name|cwdf
decl_stmt|,
name|nfuncs
decl_stmt|,
name|unkcs
decl_stmt|,
name|msgflg
decl_stmt|,
name|mdmtyp
decl_stmt|,
name|zincnt
decl_stmt|,
name|cmask
decl_stmt|,
name|rcflag
decl_stmt|,
name|success
decl_stmt|,
name|xitsta
decl_stmt|,
name|pflag
decl_stmt|,
name|lf_opts
decl_stmt|,
name|tnlm
decl_stmt|,
name|tn_nlm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ccntab
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOFRILLS
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|en_cwd
decl_stmt|,
name|en_del
decl_stmt|,
name|en_dir
decl_stmt|,
name|en_fin
decl_stmt|,
name|en_bye
decl_stmt|,
name|en_get
decl_stmt|,
name|en_hos
decl_stmt|,
name|en_sen
decl_stmt|,
name|en_set
decl_stmt|,
name|en_spa
decl_stmt|,
name|en_typ
decl_stmt|,
name|en_who
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOFRILLS */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|vernum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|srvtim
decl_stmt|,
name|srvdis
decl_stmt|,
name|incase
decl_stmt|,
name|inecho
decl_stmt|,
name|intime
decl_stmt|,
name|insilence
decl_stmt|,
name|nvars
decl_stmt|,
name|verwho
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|protv
decl_stmt|,
modifier|*
name|fnsv
decl_stmt|,
modifier|*
name|cmdv
decl_stmt|,
modifier|*
name|userv
decl_stmt|,
modifier|*
name|ckxv
decl_stmt|,
modifier|*
name|ckzv
decl_stmt|,
modifier|*
name|ckzsys
decl_stmt|,
modifier|*
name|xlav
decl_stmt|,
modifier|*
name|cknetv
decl_stmt|,
modifier|*
name|clcmds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|connv
decl_stmt|,
modifier|*
name|dialv
decl_stmt|,
modifier|*
name|loginv
decl_stmt|,
modifier|*
name|nvlook
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOSCRIPT
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|secho
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSCRIPT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NODIAL
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|nmdm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|keytab
name|mdmtab
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIAL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NETCONN
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|tn_init
decl_stmt|,
name|network
decl_stmt|,
name|ttnproto
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETCONN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|tt_type
decl_stmt|,
name|tt_arrow
decl_stmt|,
name|tt_keypad
decl_stmt|,
name|tt_wrap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tt_crd
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOCSETS
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|language
decl_stmt|,
name|nfilc
decl_stmt|,
name|tcsr
decl_stmt|,
name|tcsl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|keytab
name|fcstab
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|keytab
name|ttcstab
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCSETS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atcapr
decl_stmt|,
name|atenci
decl_stmt|,
name|atenco
decl_stmt|,
name|atdati
decl_stmt|,
name|atdato
decl_stmt|,
name|atleni
decl_stmt|,
name|atleno
decl_stmt|,
name|atblki
decl_stmt|,
name|atblko
decl_stmt|,
name|attypi
decl_stmt|,
name|attypo
decl_stmt|,
name|atsidi
decl_stmt|,
name|atsido
decl_stmt|,
name|atsysi
decl_stmt|,
name|atsyso
decl_stmt|,
name|atdisi
decl_stmt|,
name|atdiso
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|speed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DIRCMD
decl_stmt|,
modifier|*
name|PWDCMD
decl_stmt|,
modifier|*
name|DELCMD
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOXMIT
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|xmitf
decl_stmt|,
name|xmitl
decl_stmt|,
name|xmitp
decl_stmt|,
name|xmitx
decl_stmt|,
name|xmits
decl_stmt|,
name|xmitw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|xmitbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOXMIT */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|xargv
decl_stmt|,
modifier|*
name|versio
decl_stmt|,
modifier|*
name|ckxsys
decl_stmt|,
modifier|*
name|dftty
decl_stmt|,
modifier|*
name|cmarg
decl_stmt|,
modifier|*
name|lp
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DCMDBUF
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmdbuf
decl_stmt|,
modifier|*
name|atmbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command buffers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|savbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
name|cmdbuf
index|[]
decl_stmt|,
name|atmbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command buffers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|savbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCMDBUF */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|toktab
index|[]
decl_stmt|,
name|ttname
index|[]
decl_stmt|,
name|psave
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CHAR
name|sstate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cmflgs
decl_stmt|,
name|techo
decl_stmt|,
name|terror
decl_stmt|,
name|repars
decl_stmt|,
name|ncmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|keytab
name|cmdtab
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOSETKEY
end_ifndef

begin_decl_stmt
name|KEY
modifier|*
name|keymap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MACRO
modifier|*
name|macrotab
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSETKEY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|mtab
modifier|*
name|mactab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|keytab
name|vartab
index|[]
decl_stmt|,
name|fnctab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cmdlvl
decl_stmt|,
name|maclvl
decl_stmt|,
name|nmac
decl_stmt|,
name|mecho
decl_stmt|,
name|merror
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|tfile
index|[
name|MAXTAKE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TAKE file stack */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tfnam
index|[
name|MAXTAKE
index|]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/* Local declarations */
end_comment

begin_decl_stmt
name|int
name|nulcmd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for next cmd to be ignored */
end_comment

begin_comment
comment|/* Definitions for built-in macros */
end_comment

begin_comment
comment|/* First, the single line macros, installed with addmac()... */
end_comment

begin_comment
comment|/* IBM-LINEMODE macro */
end_comment

begin_decl_stmt
name|char
modifier|*
name|m_ibm
init|=
literal|"set parity mark, set dupl half, set handsh xon, set flow none"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FATAL macro */
end_comment

begin_decl_stmt
name|char
modifier|*
name|m_fat
init|=
literal|"if def \\%1 echo \\%1, if not = \\v(local) 0 hangup, stop 1"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/*   Long macro definitions were formerly done like this.  But some compilers   cannot handle continued string constants, others cannot handle string   constants that are this long.  So these definitions have been broken up   into pieces and put into arrays, see below. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|m_forx
init|=
literal|"if def _floop ass \\%9 \\fdef(_floop),else def \\%9,\ ass _floop { _getargs,\ define \\\\\\%1 \\%2,:top,if \\%5 \\\\\\%1 \\%3 goto bot,\ \\%6,:inc, incr \\\\\\%1 \\%4,goto top,:bot,_putargs,return},\ def break goto bot, def continue goto inc,\ do _floop \\%1 \\%2 \\%3 \\%4 { \\%5 },assign _floop \\fcont(\\%9)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|m_while
init|=
literal|"if def _wloop ass \\%9 \\fdef(_wloop),\ ass _wloop {_getargs,:wtest,\\%1,\\%2,goto wtest,:wbot,_putargs,return},\ def break goto wbot, def continue goto wtest,\ do _wloop,assign _wloop \\fcont(\\%9)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|m_xif
init|=
literal|"ass \\%9 \\fdef(_ify),ass _ify {_getargs, \\%1, _putargs},\ do _ify,ass _ify \\fcont(\\%9)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* Now the multiline macros, defined with addmmac()... */
end_comment

begin_comment
comment|/* FOR macro */
end_comment

begin_decl_stmt
name|char
modifier|*
name|for_def
index|[]
init|=
block|{
literal|"_assign _for\\v(cmdlevel) { _getargs,"
block|,
literal|"define \\\\\\%1 \\%2,:top,if \\%5 \\\\\\%1 \\%3 goto bot,"
block|,
literal|"\\%6,:inc,incr \\\\\\%1 \\%4,goto top,:bot,_putargs},"
block|,
literal|"def break goto bot, def continue goto inc,"
block|,
literal|"do _for\\v(cmdlevel) \\%1 \\%2 \\%3 \\%4 { \\%5 },_assign _for\\v(cmdlevel)"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/*   This one didn't work right.  When an interior loop finished executing,   the definition of the enclosing loop was restored, but the new definition   could be in a different location in memory, so its macro execution pointer   could (and usually was) pointing at garbage. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|old_for_def
index|[]
init|=
block|{
literal|"if def _floop ass \\%9 \\fdef(_floop),else def \\%9,"
block|,
literal|"ass _floop { _getargs,"
block|,
literal|"define \\\\\\%1 \\%2,:top,if \\%5 \\\\\\%1 \\%3 goto bot,"
block|,
literal|"\\%6,:inc, incr \\\\\\%1 \\%4,goto top,:bot,_putargs,return},"
block|,
literal|"def break goto bot, def continue goto inc,"
block|,
literal|"do _floop \\%1 \\%2 \\%3 \\%4 { \\%5 },assign _floop \\fcont(\\%9)"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* WHILE macro */
end_comment

begin_decl_stmt
name|char
modifier|*
name|whil_def
index|[]
init|=
block|{
literal|"_assign _whi\\v(cmdlevel) {_getargs,"
block|,
literal|":wtest,\\%1,\\%2,goto wtest,:wbot,_putargs},"
block|,
literal|"def break goto wbot, def continue goto wtest,"
block|,
literal|"do _whi\\v(cmdlevel),_assign _whi\\v(cmdlevel)"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/*   Same deal as FOR loop... */
end_comment

begin_decl_stmt
name|char
modifier|*
name|old_whil_def
index|[]
init|=
block|{
literal|"if def _wloop asg \\%9 \\fdef(_wloop),"
block|,
literal|"asg _wloop {_getargs,:wtest,\\%1,\\%2,goto wtest,:wbot,_putargs,return},"
block|,
literal|"def break goto wbot, def continue goto wtest,"
block|,
literal|"do _wloop,assign _wloop \\fcont(\\%9)"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* XIF macro */
end_comment

begin_decl_stmt
name|char
modifier|*
name|xif_def
index|[]
init|=
block|{
literal|"_assign _if\\v(cmdlevel) {_getargs,\\%1,_putargs},"
block|,
literal|"do _if\\v(cmdlevel),_assign _if\\v(cmdlevel)"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/* Same deal */
end_comment

begin_decl_stmt
name|char
modifier|*
name|old_xif_def
index|[]
init|=
block|{
literal|"asg \\%9 \\fdef(_ify),ass _ify {_getargs, \\%1, _putargs},"
block|,
literal|"do _ify,ass _ify \\fcont(\\%9)"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* Variables declared here for use by other ckuus*.c modules */
end_comment

begin_comment
comment|/* Space is allocated here to save room in ckuusr.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DCMDBUF
end_ifdef

begin_decl_stmt
name|struct
name|cmdptr
modifier|*
name|cmdstk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|ifcmd
decl_stmt|,
modifier|*
name|count
decl_stmt|,
modifier|*
name|iftest
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|cmdptr
name|cmdstk
index|[
name|CMDSTKL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ifcmd
index|[
name|CMDSTKL
index|]
decl_stmt|,
name|count
index|[
name|CMDSTKL
index|]
decl_stmt|,
name|iftest
index|[
name|CMDSTKL
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCMDBUF */
end_comment

begin_decl_stmt
name|char
modifier|*
name|m_arg
index|[
name|MACLEVEL
index|]
index|[
name|NARGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|g_var
index|[
name|GVARS
index|]
decl_stmt|,
modifier|*
name|macp
index|[
name|MACLEVEL
index|]
decl_stmt|,
modifier|*
name|mrval
index|[
name|MACLEVEL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|macargc
index|[
name|MACLEVEL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|macx
index|[
name|MACLEVEL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|varnam
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|a_ptr
index|[
literal|27
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Array pointers, for arrays a-z */
end_comment

begin_decl_stmt
name|int
name|a_dim
index|[
literal|27
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dimensions for each array */
end_comment

begin_decl_stmt
name|char
name|inpbuf
index|[
name|INPBUFSIZ
index|]
init|=
block|{
name|NUL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for INPUT and REINPUT */
end_comment

begin_decl_stmt
name|char
name|inpbufa
index|[
literal|2
index|]
init|=
block|{
name|NUL
block|,
name|NUL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Null terminators for INPUT buffer */
end_comment

begin_decl_stmt
name|char
name|inchar
index|[
literal|2
index|]
init|=
block|{
name|NUL
block|,
name|NUL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last character that was INPUT */
end_comment

begin_decl_stmt
name|int
name|incount
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* INPUT character count */
end_comment

begin_decl_stmt
name|char
name|lblbuf
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for labels */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DCMDBUF
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character buffer for anything */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|line
index|[
name|LINBUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCMDBUF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_CURSES
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TRMBUFL
end_ifndef

begin_define
define|#
directive|define
name|TRMBUFL
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRMBUFL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DCMDBUF
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|trmbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character buffer for termcap */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|trmbuf
index|[
name|TRMBUFL
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCMDBUF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_CURSES */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|pktfil
index|[]
decl_stmt|,
ifdef|#
directive|ifdef
name|DEBUG
name|debfil
index|[]
decl_stmt|,
endif|#
directive|endif
comment|/* DEBUG */
ifdef|#
directive|ifdef
name|TLOG
name|trafil
index|[]
decl_stmt|,
endif|#
directive|endif
comment|/* TLOG */
name|sesfil
index|[]
decl_stmt|,
name|cmdstr
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOFRILLS
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|rmailf
decl_stmt|,
name|rprintf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* REMOTE MAIL& PRINT items */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|optbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOFRILLS */
end_comment

begin_decl_stmt
name|char
modifier|*
name|homdir
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to home directory string */
end_comment

begin_decl_stmt
name|char
name|tmpbuf
index|[
literal|50
index|]
decl_stmt|,
modifier|*
name|tp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temporary buffer */
end_comment

begin_decl_stmt
name|char
name|numbuf
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for numeric strings. */
end_comment

begin_decl_stmt
name|char
name|kermrc
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of initialization file */
end_comment

begin_decl_stmt
name|int
name|noinit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for skipping init file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_macro
name|_PROTOTYP
argument_list|(
argument|static long expon
argument_list|,
argument|(long, long)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static long gcd
argument_list|,
argument|(long, long)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static long fact
argument_list|,
argument|(long)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|int
comment|/* Initialize macro data structures. */
name|macini
parameter_list|()
block|{
comment|/* Allocate mactab and preset the first element. */
if|if
condition|(
operator|!
operator|(
name|mactab
operator|=
operator|(
expr|struct
name|mtab
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|mtab
argument_list|)
operator|*
name|MAC_MAX
argument_list|)
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|mactab
index|[
literal|0
index|]
operator|.
name|kwd
operator|=
name|NULL
expr_stmt|;
name|mactab
index|[
literal|0
index|]
operator|.
name|mval
operator|=
name|NULL
expr_stmt|;
name|mactab
index|[
literal|0
index|]
operator|.
name|flgs
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_comment
comment|/*  C M D I N I  --  Initialize the interactive command parser  */
end_comment

begin_function
name|VOID
name|cmdini
parameter_list|()
block|{
name|int
name|i
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
ifndef|#
directive|ifndef
name|NOSPL
comment|/*   On stack in case of recursion! */
name|char
name|vnambuf
index|[
name|VNAML
index|]
decl_stmt|;
comment|/* Buffer for variable names */
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|MAC
ifndef|#
directive|ifndef
name|NOSETKEY
comment|/* Allocate& initialize the keymap */
if|if
condition|(
operator|!
operator|(
name|keymap
operator|=
operator|(
name|KEY
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|KEY
argument_list|)
operator|*
name|KMSIZE
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"cmdini: no memory for keymap"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|macrotab
operator|=
operator|(
name|MACRO
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|MACRO
argument_list|)
operator|*
name|KMSIZE
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"cmdini: no memory for macrotab"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|KMSIZE
condition|;
name|i
operator|++
control|)
block|{
name|keymap
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
name|macrotab
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|OS2
name|keymapinit
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* NOSETKEY */
endif|#
directive|endif
comment|/* MAC */
ifdef|#
directive|ifdef
name|DCMDBUF
if|if
condition|(
name|cmsetup
argument_list|()
operator|<
literal|0
condition|)
name|fatal
argument_list|(
literal|"Can't allocate command buffers!"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
operator|!
operator|(
name|cmdstk
operator|=
operator|(
expr|struct
name|cmdptr
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|cmdptr
argument_list|)
operator|*
name|CMDSTKL
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"cmdini: no memory for cmdstk"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ifcmd
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|CMDSTKL
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"cmdini: no memory for ifcmd"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|count
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|CMDSTKL
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"cmdini: no memory for count"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|iftest
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|CMDSTKL
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"cmdini: no memory for iftest"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
ifdef|#
directive|ifdef
name|CK_CURSES
comment|/*   Termcap buffer for fullscreen display, UNIX only.  VMS does it another way.   The fullscreen display is not supported on AOS/VS or OS-9, etc, yet, and   the Mac has its own built-in fullscreen display. */
ifdef|#
directive|ifdef
name|UNIX
if|if
condition|(
operator|!
operator|(
name|trmbuf
operator|=
name|malloc
argument_list|(
name|TRMBUFL
operator|+
literal|1
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"cmdini: no memory for termcap buffer"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* UNIX */
endif|#
directive|endif
comment|/* CK_CURSES */
if|if
condition|(
operator|!
operator|(
name|line
operator|=
name|malloc
argument_list|(
name|LINBUFSIZ
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"cmdini: no memory for line"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DCMDBUF */
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|macini
argument_list|()
operator|<
literal|0
condition|)
name|fatal
argument_list|(
literal|"Can't allocate macro buffers!"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
ifdef|#
directive|ifdef
name|AMIGA
if|if
condition|(
name|tlevel
operator|<
literal|0
condition|)
name|concb
argument_list|(
name|escape
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* AMIGA */
ifndef|#
directive|ifndef
name|NOSPL
name|cmdlvl
operator|=
literal|0
expr_stmt|;
comment|/* Start at command level 0 */
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|=
name|CMD_KB
expr_stmt|;
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|lvl
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
name|tlevel
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Take file level = keyboard */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXTAKE
condition|;
name|i
operator|++
control|)
comment|/* Initialize command file names */
name|tfnam
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
ifdef|#
directive|ifdef
name|MAC
name|cmsetp
argument_list|(
literal|"Mac-Kermit>"
argument_list|)
expr_stmt|;
comment|/* Set default prompt */
else|#
directive|else
name|cmsetp
argument_list|(
literal|"C-Kermit>"
argument_list|)
expr_stmt|;
comment|/* Set default prompt */
endif|#
directive|endif
comment|/* MAC */
ifndef|#
directive|ifndef
name|NOSPL
name|initmac
argument_list|()
expr_stmt|;
comment|/* Initialize macro table */
comment|/* Add one-line macros */
name|addmac
argument_list|(
literal|"ibm-linemode"
argument_list|,
name|m_ibm
argument_list|)
expr_stmt|;
comment|/* Add built-in macros. */
name|addmac
argument_list|(
literal|"fatal"
argument_list|,
name|m_fat
argument_list|)
expr_stmt|;
comment|/* FATAL macro. */
comment|/* Add multiline macros */
name|addmmac
argument_list|(
literal|"_forx"
argument_list|,
name|for_def
argument_list|)
expr_stmt|;
comment|/* FOR macro. */
name|addmmac
argument_list|(
literal|"_xif"
argument_list|,
name|xif_def
argument_list|)
expr_stmt|;
comment|/* XIF macro. */
name|addmmac
argument_list|(
literal|"_while"
argument_list|,
name|whil_def
argument_list|)
expr_stmt|;
comment|/* WHILE macro. */
comment|/* Fill in command line argument vector */
name|sprintf
argument_list|(
name|vnambuf
argument_list|,
literal|"\\&@[%d]"
argument_list|,
name|xargs
argument_list|)
expr_stmt|;
comment|/* Command line argument vector */
name|y
operator|=
name|arraynam
argument_list|(
name|vnambuf
argument_list|,
operator|&
name|x
argument_list|,
operator|&
name|z
argument_list|)
expr_stmt|;
comment|/* goes in array \&@[] */
if|if
condition|(
name|y
operator|>
operator|-
literal|1
condition|)
block|{
name|dclarray
argument_list|(
operator|(
name|char
operator|)
name|x
argument_list|,
name|z
argument_list|)
expr_stmt|;
comment|/* Declare the array */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|xargs
condition|;
name|i
operator|++
control|)
block|{
comment|/* Fill it */
name|sprintf
argument_list|(
name|vnambuf
argument_list|,
literal|"\\&@[%d]"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|addmac
argument_list|(
name|vnambuf
argument_list|,
name|xargv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
operator|*
name|vnambuf
operator|=
name|NUL
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
comment|/* Get our home directory now.  This needed in lots of places. */
name|homdir
operator|=
name|zhome
argument_list|()
expr_stmt|;
comment|/* If skipping init file ('-Y' on Kermit command line), return now. */
if|if
condition|(
name|noinit
condition|)
return|return;
ifdef|#
directive|ifdef
name|OS2
comment|/*   The -y init file must be fully specified or in the current directory.   KERMRC is looked for via INIT, PATH and DPATH in that order.  Finally, our   own executable file path is taken and the .EXE suffix is replaced by .INI   and this is tried as initialization file. */
if|if
condition|(
name|rcflag
condition|)
block|{
name|strcpy
argument_list|(
name|line
argument_list|,
name|kermrc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|_searchenv
argument_list|(
name|kermrc
argument_list|,
literal|"INIT"
argument_list|,
name|line
argument_list|)
expr_stmt|;
if|if
condition|(
name|line
index|[
literal|0
index|]
operator|==
literal|0
condition|)
name|_searchenv
argument_list|(
name|kermrc
argument_list|,
literal|"PATH"
argument_list|,
name|line
argument_list|)
expr_stmt|;
if|if
condition|(
name|line
index|[
literal|0
index|]
operator|==
literal|0
condition|)
name|_searchenv
argument_list|(
name|kermrc
argument_list|,
literal|"DPATH"
argument_list|,
name|line
argument_list|)
expr_stmt|;
if|if
condition|(
name|line
index|[
literal|0
index|]
operator|==
literal|0
condition|)
block|{
name|char
modifier|*
name|pgmptr
init|=
name|GetLoadPath
argument_list|()
decl_stmt|;
if|if
condition|(
name|pgmptr
condition|)
block|{
name|lp
operator|=
name|strrchr
argument_list|(
name|pgmptr
argument_list|,
literal|'.'
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|line
argument_list|,
name|pgmptr
argument_list|,
name|lp
operator|-
name|pgmptr
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|line
operator|+
operator|(
name|lp
operator|-
name|pgmptr
operator|)
argument_list|,
literal|".ini"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|(
name|tfile
index|[
literal|0
index|]
operator|=
name|fopen
argument_list|(
name|line
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|tlevel
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tfnam
index|[
name|tlevel
index|]
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|line
argument_list|)
operator|+
literal|1
argument_list|)
condition|)
name|strcpy
argument_list|(
name|tfnam
index|[
name|tlevel
index|]
argument_list|,
name|line
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOSPL
name|cmdlvl
operator|++
expr_stmt|;
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|=
name|CMD_TF
expr_stmt|;
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|lvl
operator|=
name|tlevel
expr_stmt|;
name|ifcmd
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|iftest
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|count
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"init file"
argument_list|,
name|line
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"no init file"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* not OS2 */
name|lp
operator|=
name|line
expr_stmt|;
name|lp
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
ifdef|#
directive|ifdef
name|GEMDOS
name|zkermini
argument_list|(
name|line
argument_list|,
name|rcflag
argument_list|,
name|kermrc
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VMS
name|zkermini
argument_list|(
name|line
argument_list|,
name|LINBUFSIZ
argument_list|,
name|kermrc
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* not VMS */
if|if
condition|(
name|rcflag
condition|)
block|{
comment|/* If init file name from cmd line */
name|strcpy
argument_list|(
name|lp
argument_list|,
name|kermrc
argument_list|)
expr_stmt|;
comment|/* use it */
block|}
else|else
block|{
comment|/* otherwise */
if|if
condition|(
name|homdir
condition|)
block|{
comment|/* look in home directory for it */
name|strcpy
argument_list|(
name|lp
argument_list|,
name|homdir
argument_list|)
expr_stmt|;
if|if
condition|(
name|lp
index|[
literal|0
index|]
operator|==
literal|'/'
condition|)
name|strcat
argument_list|(
name|lp
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
block|}
name|strcat
argument_list|(
name|lp
argument_list|,
name|kermrc
argument_list|)
expr_stmt|;
comment|/* and use the default name */
block|}
endif|#
directive|endif
comment|/* VMS */
endif|#
directive|endif
comment|/* GEMDOS */
ifdef|#
directive|ifdef
name|AMIGA
name|reqoff
argument_list|()
expr_stmt|;
comment|/* disable requestors */
endif|#
directive|endif
comment|/* AMIGA */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ini file is"
argument_list|,
name|line
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|tfile
index|[
literal|0
index|]
operator|=
name|fopen
argument_list|(
name|line
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|tlevel
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tfnam
index|[
name|tlevel
index|]
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|line
argument_list|)
operator|+
literal|1
argument_list|)
condition|)
name|strcpy
argument_list|(
name|tfnam
index|[
name|tlevel
index|]
argument_list|,
name|line
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOSPL
name|cmdlvl
operator|++
expr_stmt|;
name|ifcmd
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|iftest
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|count
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"open ok"
argument_list|,
literal|""
argument_list|,
name|cmdlvl
argument_list|)
expr_stmt|;
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|=
name|CMD_TF
expr_stmt|;
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|lvl
operator|=
name|tlevel
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"init file"
argument_list|,
name|line
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|homdir
operator|&&
operator|(
name|tlevel
operator|<
literal|0
operator|)
condition|)
block|{
name|strcpy
argument_list|(
name|lp
argument_list|,
name|kermrc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|tfile
index|[
literal|0
index|]
operator|=
name|fopen
argument_list|(
name|line
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|tlevel
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tfnam
index|[
name|tlevel
index|]
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|line
argument_list|)
operator|+
literal|1
argument_list|)
condition|)
name|strcpy
argument_list|(
name|tfnam
index|[
name|tlevel
index|]
argument_list|,
name|line
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOSPL
name|cmdlvl
operator|++
expr_stmt|;
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|=
name|CMD_TF
expr_stmt|;
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|lvl
operator|=
name|tlevel
expr_stmt|;
name|ifcmd
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|iftest
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|count
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
block|}
block|}
endif|#
directive|endif
comment|/* OS2 */
ifdef|#
directive|ifdef
name|AMIGA
name|reqpop
argument_list|()
expr_stmt|;
comment|/* Restore requestors */
endif|#
directive|endif
comment|/* AMIGA */
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/*   G E T N C M    Get next command from current macro definition.    Moved to a separate routine in edit 181 to allow multiline GET   to work when issued in a macro.    Command is copied into string pointed to by argument s, max length n.   Returns:    0 if a string was copied, -1 if there was no string to copy. */
end_comment

begin_function
name|int
name|getncm
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|n
decl_stmt|;
block|{
name|int
name|y
decl_stmt|,
name|kp
init|=
literal|0
decl_stmt|,
name|pp
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|s2
decl_stmt|;
name|s2
operator|=
name|s
expr_stmt|;
operator|*
name|s
operator|=
name|NUL
expr_stmt|;
comment|/* Copy next cmd to command buffer. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"getncm"
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|macp
index|[
name|maclvl
index|]
operator|&&
operator|*
name|macp
index|[
name|maclvl
index|]
operator|&&
name|y
operator|<
name|n
condition|;
name|y
operator|++
operator|,
name|s
operator|++
operator|,
name|macp
index|[
name|maclvl
index|]
operator|++
control|)
block|{
operator|*
name|s
operator|=
operator|*
name|macp
index|[
name|maclvl
index|]
expr_stmt|;
comment|/* Get next character */
name|debug
argument_list|(
name|F000
argument_list|,
literal|"char"
argument_list|,
literal|""
argument_list|,
operator|*
name|s
argument_list|)
expr_stmt|;
comment|/*   Allow braces around macro definition to prevent commas from being turned to   end-of-lines and also treat any commas within parens as text so that   multiple-argument functions won't cause the command to break prematurely. */
if|if
condition|(
operator|*
name|s
operator|==
literal|'{'
condition|)
name|kp
operator|++
expr_stmt|;
comment|/* Count braces */
if|if
condition|(
operator|*
name|s
operator|==
literal|'}'
condition|)
name|kp
operator|--
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|'('
condition|)
name|pp
operator|++
expr_stmt|;
comment|/* Count parentheses. */
if|if
condition|(
operator|*
name|s
operator|==
literal|')'
condition|)
name|pp
operator|--
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|','
operator|&&
name|pp
operator|<=
literal|0
operator|&&
name|kp
operator|<=
literal|0
condition|)
block|{
name|macp
index|[
name|maclvl
index|]
operator|++
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"next cmd"
argument_list|,
name|s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|kp
operator|=
name|pp
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
comment|/* Reached end. */
if|if
condition|(
operator|*
name|s2
operator|==
name|NUL
condition|)
block|{
comment|/* If nothing was copied, */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getncm eom"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|popclvl
argument_list|()
expr_stmt|;
comment|/* pop command level. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
block|{
comment|/* otherwise, tack CR onto end */
operator|*
name|s
operator|++
operator|=
name|CR
expr_stmt|;
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|mecho
operator|&&
name|pflag
condition|)
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|s2
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getncm returns ptr to"
argument_list|,
name|s2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_comment
comment|/*   G E T N C T    Get next command from current TAKE file.    Moved to a separate routine in edit 181 to allow multiline GET   to work when issued in a macro.    Command is copied into string pointed to by argument s, max length n.   Returns:    0 if a string was copied,   -1 on EOF,   -2 on malloc failure   -3 if line not properly terminated */
end_comment

begin_function
name|int
name|getnct
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|n
decl_stmt|;
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|char
name|c
decl_stmt|,
modifier|*
name|s2
decl_stmt|,
modifier|*
name|lp
decl_stmt|,
modifier|*
name|lp2
decl_stmt|;
name|s2
operator|=
name|s
expr_stmt|;
comment|/* Remember original pointer */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getnct"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|lp2
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|n
operator|+
literal|1
argument_list|)
operator|)
condition|)
block|{
comment|/* Get a temporary buffer */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getnct malloc failure"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
name|lp
operator|=
name|lp2
expr_stmt|;
comment|/* Make a working pointer */
comment|/* (lp2 must not change!) */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* Loop to read lines from file */
if|if
condition|(
name|fgets
argument_list|(
name|lp2
argument_list|,
name|n
argument_list|,
name|tfile
index|[
name|tlevel
index|]
argument_list|)
operator|==
name|NULL
condition|)
block|{
comment|/* EOF */
name|free
argument_list|(
name|lp2
argument_list|)
expr_stmt|;
comment|/* Free temporary storage */
operator|*
name|s
operator|=
name|NUL
expr_stmt|;
comment|/* Make destination be empty */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Return failure code */
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"Line from TAKE file"
argument_list|,
name|lp2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Got a line */
if|if
condition|(
name|techo
operator|&&
name|pflag
condition|)
comment|/* If TAKE ECHO ON, */
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|lp2
argument_list|)
expr_stmt|;
comment|/* echo it. */
name|lp
operator|=
name|lp2
expr_stmt|;
comment|/* Make a working pointer */
comment|/* Trim trailing whitespace */
name|j
operator|=
name|strlen
argument_list|(
name|lp2
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* Position of line terminator */
if|if
condition|(
name|j
operator|<
literal|0
condition|)
name|j
operator|=
literal|0
expr_stmt|;
name|c
operator|=
name|lp2
index|[
name|j
index|]
expr_stmt|;
comment|/* Value of line terminator */
if|if
condition|(
name|c
operator|<
name|LF
operator|||
name|c
operator|>
name|CR
condition|)
block|{
comment|/* It's not a terminator */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"getnct bad line"
argument_list|,
name|lp2
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|feof
argument_list|(
name|tfile
index|[
name|tlevel
index|]
argument_list|)
operator|&&
name|j
operator|>
literal|0
operator|&&
name|j
operator|<
name|n
condition|)
block|{
name|printf
argument_list|(
literal|"Warning: Last line of TAKE file lacks terminator\n"
argument_list|)
expr_stmt|;
name|c
operator|=
name|lp2
index|[
operator|++
name|j
index|]
operator|=
literal|'\n'
expr_stmt|;
block|}
else|else
return|return
operator|(
operator|-
literal|3
operator|)
return|;
block|}
for|for
control|(
name|i
operator|=
name|j
operator|-
literal|1
init|;
name|i
operator|>
operator|-
literal|1
condition|;
name|i
operator|--
control|)
comment|/* Back up over spaces and tabs */
if|if
condition|(
name|lp2
index|[
name|i
index|]
operator|!=
name|SP
operator|&&
name|lp2
index|[
name|i
index|]
operator|!=
name|HT
operator|&&
name|lp2
index|[
name|i
index|]
operator|!=
name|NUL
condition|)
break|break;
name|lp2
index|[
name|i
operator|+
literal|1
index|]
operator|=
name|c
expr_stmt|;
comment|/* Move after last nonblank char */
name|lp2
index|[
name|i
operator|+
literal|2
index|]
operator|=
name|NUL
expr_stmt|;
comment|/* Terminate the string */
while|while
condition|(
operator|*
name|s
operator|++
operator|=
operator|*
name|lp
operator|++
condition|)
block|{
comment|/* Copy result to target buffer */
if|if
condition|(
operator|--
name|n
operator|<
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"?Command too long, maximum length: %d.\n"
argument_list|,
name|CMDBL
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|lp2
argument_list|)
expr_stmt|;
return|return
operator|(
name|dostop
argument_list|()
operator|)
return|;
block|}
comment|/* Check for trailing comment, " ;" or " #" */
if|if
condition|(
operator|(
name|s
operator|>
name|s2
operator|+
literal|1
operator|)
operator|&&
operator|(
operator|*
operator|(
name|s
operator|-
literal|1
operator|)
operator|==
literal|';'
operator|||
operator|*
operator|(
name|s
operator|-
literal|1
operator|)
operator|==
literal|'#'
operator|)
operator|&&
operator|(
operator|*
operator|(
name|s
operator|-
literal|2
operator|)
operator|==
name|SP
operator|||
operator|*
operator|(
name|s
operator|-
literal|2
operator|)
operator|==
name|HT
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"Trailing comment"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|s
operator|-=
literal|2
expr_stmt|;
comment|/* Got one, back up buffer pointer */
name|n
operator|+=
literal|2
expr_stmt|;
comment|/* and adjust free space count. */
while|while
condition|(
operator|(
name|s
operator|>=
name|s2
operator|)
comment|/* Trim whitespace again. */
operator|&&
operator|(
operator|*
name|s
operator|==
name|SP
operator|||
operator|*
name|s
operator|==
name|HT
operator|)
condition|)
name|s
operator|--
operator|,
name|n
operator|++
expr_stmt|;
name|s
operator|++
expr_stmt|;
comment|/* Point after last character */
operator|*
name|s
operator|++
operator|=
name|c
expr_stmt|;
comment|/* Put back line terminator */
operator|*
name|s
operator|++
operator|=
name|NUL
expr_stmt|;
comment|/* and string terminator */
name|n
operator|-=
literal|3
expr_stmt|;
comment|/* Adjust free count */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"Comment trimmed& terminated"
argument_list|,
name|s2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/* Check whether this line is continued */
name|debug
argument_list|(
name|F000
argument_list|,
literal|"Last char in line"
argument_list|,
literal|""
argument_list|,
operator|*
operator|(
name|s
operator|-
literal|3
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|s
operator|-
literal|3
operator|)
operator|!=
name|CMDQ
operator|&&
operator|*
operator|(
name|s
operator|-
literal|3
operator|)
operator|!=
literal|'-'
condition|)
comment|/* Line continued? */
break|break;
comment|/* No, done. */
name|s
operator|-=
literal|3
expr_stmt|;
comment|/* No, back up pointer */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"Got continue char"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* and continue */
block|}
name|untab
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|/* Done, convert tabs to spaces */
name|free
argument_list|(
name|lp2
argument_list|)
expr_stmt|;
comment|/* Free temporary storage */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Return success */
block|}
end_function

begin_comment
comment|/*  P A R S E R  --  Top-level interactive command parser.  */
end_comment

begin_comment
comment|/*   Call with:     m = 0 for normal behavior: keep parsing and executing commands           until an action command is parsed, then return with a           Kermit start-state as the value of this function.     m = 1 to parse only one command, can also be used to call parser()           recursively.     m = 2 to read but do not execute one command.   In all cases, parser() returns:     0     if no Kermit protocol action required> 0   with a Kermit protocol start-state.< 0   upon error. */
end_comment

begin_function
name|int
name|parser
parameter_list|(
name|m
parameter_list|)
name|int
name|m
decl_stmt|;
block|{
name|int
name|tfcode
decl_stmt|,
name|xx
decl_stmt|,
name|yy
decl_stmt|,
name|zz
decl_stmt|;
comment|/* Workers */
ifndef|#
directive|ifndef
name|NOSPL
name|int
name|inlevel
decl_stmt|;
comment|/* Level we were called at */
endif|#
directive|endif
comment|/* NOSPL */
name|char
modifier|*
name|cbp
decl_stmt|;
comment|/* Command buffer pointer */
ifdef|#
directive|ifdef
name|MAC
specifier|extern
name|char
modifier|*
name|lfiles
decl_stmt|;
comment|/* Fake extern cast */
endif|#
directive|endif
comment|/* MAC */
ifdef|#
directive|ifdef
name|AMIGA
name|reqres
argument_list|()
expr_stmt|;
comment|/* restore AmigaDOS requestors */
endif|#
directive|endif
comment|/* AMIGA */
name|what
operator|=
name|W_COMMAND
expr_stmt|;
comment|/* Now we're parsing commands. */
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
comment|/* If at top (interactive) level, */
else|#
directive|else
if|if
condition|(
name|tlevel
operator|<
literal|0
condition|)
endif|#
directive|endif
comment|/* NOSPL */
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* put console in cbreak mode. */
ifndef|#
directive|ifndef
name|NOSPL
name|ifcmd
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|/* Command-level related variables */
name|iftest
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|/* initialize variables at top level */
name|count
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|/* of stack... */
name|inlevel
operator|=
name|cmdlvl
expr_stmt|;
comment|/* Current macro level */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"&parser entry maclvl"
argument_list|,
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"&parser entry inlevel"
argument_list|,
literal|""
argument_list|,
name|inlevel
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"&parser entry tlevel"
argument_list|,
literal|""
argument_list|,
name|tlevel
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"&parser entry cmdlvl"
argument_list|,
literal|""
argument_list|,
name|cmdlvl
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"&parser entry m"
argument_list|,
literal|""
argument_list|,
name|m
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
comment|/*   sstate becomes nonzero when a command has been parsed that requires some   action from the protocol module.  Any non-protocol actions, such as local   directory listing or terminal emulation, are invoked directly from below. */
ifdef|#
directive|ifdef
name|COMMENT
if|if
condition|(
name|local
operator|&&
name|pflag
condition|)
comment|/* Just returned from connect? */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
name|sstate
operator|=
literal|0
expr_stmt|;
comment|/* Start with no start state. */
ifndef|#
directive|ifndef
name|NOFRILLS
name|rmailf
operator|=
name|rprintf
operator|=
literal|0
expr_stmt|;
comment|/* MAIL and PRINT modifiers for SEND */
operator|*
name|optbuf
operator|=
name|NUL
expr_stmt|;
comment|/* MAIL and PRINT options */
endif|#
directive|endif
comment|/* NOFRILLS */
while|while
condition|(
name|sstate
operator|==
literal|0
condition|)
block|{
comment|/* Parse cmds until action requested */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"top of parse loop"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Take requested action if there was an error in the previous command */
ifndef|#
directive|ifndef
name|MAC
name|conint
argument_list|(
name|trap
argument_list|,
name|stptrap
argument_list|)
expr_stmt|;
comment|/* In case we were just fg'd */
name|bgchk
argument_list|()
expr_stmt|;
comment|/* Check background status */
endif|#
directive|endif
comment|/* MAC */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tlevel"
argument_list|,
literal|""
argument_list|,
name|tlevel
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOSPL
comment|/* In case we just reached top level */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"cmdlvl"
argument_list|,
literal|""
argument_list|,
name|cmdlvl
argument_list|)
expr_stmt|;
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|tlevel
operator|<
literal|0
condition|)
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|success
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|==
name|CMD_TF
operator|&&
name|terror
condition|)
block|{
name|printf
argument_list|(
literal|"Command error: take file terminated.\n"
argument_list|)
expr_stmt|;
name|popclvl
argument_list|()
expr_stmt|;
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|==
name|CMD_MD
operator|&&
name|merror
condition|)
block|{
name|printf
argument_list|(
literal|"Command error: macro terminated.\n"
argument_list|)
expr_stmt|;
name|popclvl
argument_list|()
expr_stmt|;
if|if
condition|(
name|m
operator|&&
operator|(
name|cmdlvl
operator|<
name|inlevel
operator|)
condition|)
return|return
operator|(
operator|(
name|int
operator|)
name|sstate
operator|)
return|;
block|}
block|}
name|nulcmd
operator|=
operator|(
name|m
operator|==
literal|2
operator|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|success
operator|==
literal|0
operator|&&
name|tlevel
operator|>
operator|-
literal|1
operator|&&
name|terror
condition|)
block|{
name|printf
argument_list|(
literal|"Command error: take file terminated.\n"
argument_list|)
expr_stmt|;
name|popclvl
argument_list|()
expr_stmt|;
name|cmini
argument_list|(
name|ckxech
argument_list|)
expr_stmt|;
comment|/* Clear the cmd buffer. */
if|if
condition|(
name|tlevel
operator|<
literal|0
condition|)
comment|/* Just popped out of cmd files? */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* End of init file or whatever. */
block|}
endif|#
directive|endif
comment|/* NOSPL */
ifdef|#
directive|ifdef
name|MAC
comment|/* Check for TAKE initiated by menu. */
if|if
condition|(
operator|(
name|tlevel
operator|==
operator|-
literal|1
operator|)
operator|&&
name|lfiles
condition|)
name|startlfile
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
comment|/* If in TAKE file, check for EOF */
ifndef|#
directive|ifndef
name|NOSPL
ifdef|#
directive|ifdef
name|MAC
if|if
else|#
directive|else
if|while
endif|#
directive|endif
comment|/* MAC */
condition|(
operator|(
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|==
name|CMD_TF
operator|)
comment|/* If end of take file */
operator|&&
operator|(
name|tlevel
operator|>
operator|-
literal|1
operator|)
operator|&&
name|feof
argument_list|(
name|tfile
index|[
name|tlevel
index|]
argument_list|)
condition|)
block|{
name|popclvl
argument_list|()
expr_stmt|;
comment|/* pop command level */
name|cmini
argument_list|(
name|ckxech
argument_list|)
expr_stmt|;
comment|/* and clear the cmd buffer. */
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
comment|/* Just popped out of all cmd files? */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* End of init file or whatever. */
block|}
ifdef|#
directive|ifdef
name|MAC
name|miniparser
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|sstate
operator|==
literal|'a'
condition|)
block|{
comment|/* if cmd-. cancel */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"parser: cancel take due to sstate"
argument_list|,
literal|""
argument_list|,
name|sstate
argument_list|)
expr_stmt|;
name|sstate
operator|=
literal|'\0'
expr_stmt|;
name|dostop
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* End of init file or whatever. */
block|}
endif|#
directive|endif
comment|/*  MAC */
else|#
directive|else
comment|/* NOSPL */
if|if
condition|(
operator|(
name|tlevel
operator|>
operator|-
literal|1
operator|)
operator|&&
name|feof
argument_list|(
name|tfile
index|[
name|tlevel
index|]
argument_list|)
condition|)
block|{
comment|/* If end of take */
name|popclvl
argument_list|()
expr_stmt|;
comment|/* Pop up one level. */
name|cmini
argument_list|(
name|ckxech
argument_list|)
expr_stmt|;
comment|/* and clear the cmd buffer. */
if|if
condition|(
name|tlevel
operator|<
literal|0
condition|)
comment|/* Just popped out of cmd files? */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* End of init file or whatever. */
block|}
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|==
name|CMD_MD
condition|)
block|{
comment|/* Executing a macro? */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"parser macro"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|maclvl
operator|=
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|lvl
expr_stmt|;
comment|/* Get current level */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"parser maclvl"
argument_list|,
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
name|cbp
operator|=
name|cmdbuf
expr_stmt|;
comment|/* Copy next cmd to command buffer. */
operator|*
name|cbp
operator|=
name|NUL
expr_stmt|;
if|if
condition|(
operator|*
name|savbuf
condition|)
block|{
comment|/* In case then-part of 'if' command */
name|strcpy
argument_list|(
name|cbp
argument_list|,
name|savbuf
argument_list|)
expr_stmt|;
comment|/* was saved, restore it. */
operator|*
name|savbuf
operator|=
literal|'\0'
expr_stmt|;
block|}
else|else
block|{
comment|/* Else get next cmd from macro def */
if|if
condition|(
name|getncm
argument_list|(
name|cbp
argument_list|,
name|CMDBL
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|m
operator|&&
operator|(
name|cmdlvl
operator|<
name|inlevel
operator|)
condition|)
return|return
operator|(
operator|(
name|int
operator|)
name|sstate
operator|)
return|;
else|else
comment|/* if (!m) */
continue|continue;
block|}
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"cmdbuf from macro"
argument_list|,
name|cmdbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|==
name|CMD_TF
condition|)
else|#
directive|else
if|if
condition|(
name|tlevel
operator|>
operator|-
literal|1
condition|)
endif|#
directive|endif
comment|/* NOSPL */
block|{
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
operator|*
name|savbuf
condition|)
block|{
comment|/* In case THEN-part of IF command */
name|strcpy
argument_list|(
name|cmdbuf
argument_list|,
name|savbuf
argument_list|)
expr_stmt|;
comment|/* was saved, restore it. */
operator|*
name|savbuf
operator|=
literal|'\0'
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
comment|/* NOSPL */
comment|/* Get next line from TAKE file */
if|if
condition|(
operator|(
name|tfcode
operator|=
name|getnct
argument_list|(
name|cmdbuf
argument_list|,
name|CMDBL
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|tfcode
operator|<
operator|-
literal|1
condition|)
block|{
comment|/* Error */
name|printf
argument_list|(
literal|"?Error in TAKE command file: %s\n"
argument_list|,
operator|(
name|tfcode
operator|==
operator|-
literal|2
operator|)
condition|?
literal|"Memory allocation failure"
else|:
literal|"Line too long or contains NUL characters"
argument_list|)
expr_stmt|;
name|popclvl
argument_list|()
expr_stmt|;
block|}
continue|continue;
comment|/* -1 means EOF */
block|}
comment|/* If interactive, get next command from user. */
block|}
else|else
block|{
comment|/* User types it in. */
if|if
condition|(
name|pflag
condition|)
name|prompt
argument_list|(
name|xxstring
argument_list|)
expr_stmt|;
name|cmini
argument_list|(
name|ckxech
argument_list|)
expr_stmt|;
block|}
comment|/* Now know where next command is coming from. Parse and execute it. */
name|repars
operator|=
literal|1
expr_stmt|;
comment|/* 1 = command needs parsing */
name|displa
operator|=
literal|0
expr_stmt|;
comment|/* Assume no file transfer display */
while|while
condition|(
name|repars
condition|)
block|{
comment|/* Parse this cmd until entered. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"parser top of while loop"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|cmres
argument_list|()
expr_stmt|;
comment|/* Reset buffer pointers. */
name|xx
operator|=
name|cmkey2
argument_list|(
name|cmdtab
argument_list|,
name|ncmd
argument_list|,
literal|"Command"
argument_list|,
literal|""
argument_list|,
name|toktab
argument_list|,
name|xxstring
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"top-level cmkey2"
argument_list|,
literal|""
argument_list|,
name|xx
argument_list|)
expr_stmt|;
if|if
condition|(
name|xx
operator|==
operator|-
literal|5
condition|)
block|{
name|yy
operator|=
name|chktok
argument_list|(
name|toktab
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"top-level cmkey token"
argument_list|,
literal|""
argument_list|,
name|yy
argument_list|)
expr_stmt|;
name|ungword
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|yy
condition|)
block|{
ifndef|#
directive|ifndef
name|NOPUSH
case|case
literal|'!'
case|:
name|xx
operator|=
name|XXSHE
expr_stmt|;
break|break;
comment|/* Shell escape */
endif|#
directive|endif
comment|/* NOPUSH */
case|case
literal|'#'
case|:
name|xx
operator|=
name|XXCOM
expr_stmt|;
break|break;
comment|/* Comment */
case|case
literal|';'
case|:
name|xx
operator|=
name|XXCOM
expr_stmt|;
break|break;
comment|/* Comment */
ifndef|#
directive|ifndef
name|NOSPL
case|case
literal|':'
case|:
name|xx
operator|=
name|XXLBL
expr_stmt|;
break|break;
comment|/* GOTO label */
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOPUSH
case|case
literal|'@'
case|:
name|xx
operator|=
name|XXSHE
expr_stmt|;
break|break;
comment|/* Shell (DCL) escape */
endif|#
directive|endif
comment|/* NOPUSH */
default|default:
name|printf
argument_list|(
literal|"\n?Invalid - %s\n"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
name|xx
operator|=
operator|-
literal|2
expr_stmt|;
block|}
block|}
ifndef|#
directive|ifndef
name|NOSPL
comment|/* Special handling for IF..ELSE */
if|if
condition|(
name|ifcmd
index|[
name|cmdlvl
index|]
condition|)
comment|/* Count stmts after IF */
name|ifcmd
index|[
name|cmdlvl
index|]
operator|++
expr_stmt|;
if|if
condition|(
name|ifcmd
index|[
name|cmdlvl
index|]
operator|>
literal|2
operator|&&
name|xx
operator|!=
name|XXELS
operator|&&
name|xx
operator|!=
name|XXCOM
condition|)
name|ifcmd
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
comment|/* Execute the command and take action based on return code. */
if|if
condition|(
name|nulcmd
condition|)
block|{
comment|/* Ignoring this command? */
name|xx
operator|=
name|XXCOM
expr_stmt|;
comment|/* Make this command a comment. */
block|}
endif|#
directive|endif
comment|/* NOSPL */
name|zz
operator|=
name|docmd
argument_list|(
name|xx
argument_list|)
expr_stmt|;
comment|/* Parse rest of command& execute. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"docmd returns"
argument_list|,
literal|""
argument_list|,
name|zz
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MAC
if|if
condition|(
name|tlevel
operator|>
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|sstate
operator|==
literal|'a'
condition|)
block|{
comment|/* if cmd-. cancel */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"parser: cancel take, sstate:"
argument_list|,
literal|"a"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sstate
operator|=
literal|'\0'
expr_stmt|;
name|dostop
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* End of init file or whatever. */
block|}
block|}
endif|#
directive|endif
comment|/* MAC */
switch|switch
condition|(
name|zz
condition|)
block|{
case|case
operator|-
literal|4
case|:
comment|/* EOF (e.g. on redirected stdin) */
name|doexit
argument_list|(
name|GOOD_EXIT
argument_list|,
name|xitsta
argument_list|)
expr_stmt|;
comment|/* ...exit successfully */
case|case
operator|-
literal|1
case|:
comment|/* Reparse needed */
name|repars
operator|=
literal|1
expr_stmt|;
comment|/* Just set reparse flag and  */
continue|continue;
case|case
operator|-
literal|6
case|:
comment|/* Invalid command given w/no args */
case|case
operator|-
literal|2
case|:
comment|/* Invalid command given w/args */
ifdef|#
directive|ifdef
name|COMMENT
ifndef|#
directive|ifndef
name|NOSPL
comment|/* This is going to be really ugly... */
name|yy
operator|=
name|mlook
argument_list|(
name|mactab
argument_list|,
name|atmbuf
argument_list|,
name|nmac
argument_list|)
expr_stmt|;
comment|/* Look in macro table */
if|if
condition|(
name|yy
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* If it's there */
if|if
condition|(
name|zz
operator|==
operator|-
literal|2
condition|)
block|{
comment|/* insert "do" */
name|char
modifier|*
name|mp
decl_stmt|;
name|mp
operator|=
name|malloc
argument_list|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|cmdbuf
argument_list|)
operator|+
literal|5
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mp
condition|)
block|{
name|printf
argument_list|(
literal|"?malloc error 1\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
name|sprintf
argument_list|(
name|mp
argument_list|,
literal|"do %s "
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|cmdbuf
argument_list|,
name|mp
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|mp
argument_list|)
expr_stmt|;
block|}
else|else
name|sprintf
argument_list|(
name|cmdbuf
argument_list|,
literal|"do %s %c"
argument_list|,
name|atmbuf
argument_list|,
name|CR
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifcmd
index|[
name|cmdlvl
index|]
operator|==
literal|2
condition|)
comment|/* This one doesn't count! */
name|ifcmd
index|[
name|cmdlvl
index|]
operator|--
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"stuff cmdbuf"
argument_list|,
name|cmdbuf
argument_list|,
name|zz
argument_list|)
expr_stmt|;
name|repars
operator|=
literal|1
expr_stmt|;
comment|/* go for reparse */
continue|continue;
block|}
else|else
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|n
decl_stmt|;
name|p
operator|=
name|cmdbuf
expr_stmt|;
name|lp
operator|=
name|line
expr_stmt|;
name|n
operator|=
name|LINBUFSIZ
expr_stmt|;
if|if
condition|(
name|cmflgs
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|xxstring
argument_list|(
name|p
argument_list|,
operator|&
name|lp
argument_list|,
operator|&
name|n
argument_list|)
operator|>
operator|-
literal|1
condition|)
name|printf
argument_list|(
literal|"?Invalid: %s\n"
argument_list|,
name|line
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"?Invalid: %s\n"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
block|}
comment|/* (fall thru...) */
else|#
directive|else
name|printf
argument_list|(
literal|"?Invalid: %s\n"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
else|#
directive|else
name|printf
argument_list|(
literal|"?Invalid: %s\n"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
case|case
operator|-
literal|9
case|:
comment|/* Bad, error message already done */
name|success
operator|=
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"top-level cmkey failed"
argument_list|,
name|cmdbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|pflag
operator|==
literal|0
condition|)
comment|/* if background, terminate */
name|fatal
argument_list|(
literal|"Kermit command error in background execution"
argument_list|)
expr_stmt|;
name|cmini
argument_list|(
name|ckxech
argument_list|)
expr_stmt|;
comment|/* (fall thru) */
case|case
operator|-
literal|3
case|:
comment|/* Empty command OK at top level */
name|repars
operator|=
literal|0
expr_stmt|;
comment|/* Don't need to reparse. */
continue|continue;
comment|/* Go back and get another command. */
default|default:
comment|/* Command was successful. */
ifndef|#
directive|ifndef
name|NOSPL
name|debug
argument_list|(
name|F101
argument_list|,
literal|"parser preparing to continue"
argument_list|,
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
name|repars
operator|=
literal|0
expr_stmt|;
comment|/* Don't need to reparse. */
continue|continue;
comment|/* Go back and get another command. */
block|}
block|}
ifndef|#
directive|ifndef
name|NOSPL
name|debug
argument_list|(
name|F101
argument_list|,
literal|"parser breaks out of while loop"
argument_list|,
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|&&
operator|(
name|cmdlvl
operator|<
name|inlevel
operator|)
condition|)
return|return
operator|(
operator|(
name|int
operator|)
name|sstate
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
block|}
comment|/* Got an action command, return start state. */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* This is done in ckcpro.w instead, no need to do it twice. */
comment|/* Interrupts off only if remote */
if|if
condition|(
operator|!
name|local
condition|)
name|connoi
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
return|return
operator|(
operator|(
name|int
operator|)
name|sstate
operator|)
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/* OUTPUT command */
end_comment

begin_function
name|int
comment|/* This could easily become a macro */
ifdef|#
directive|ifdef
name|CK_ANSIC
name|xxout
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|xxout
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* xxout */
block|{
comment|/* Function to output a character. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"xxout"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|local
condition|)
comment|/* If in local mode */
return|return
operator|(
name|ttoc
argument_list|(
name|c
argument_list|)
operator|)
return|;
comment|/* then to the external line */
else|else
return|return
operator|(
name|conoc
argument_list|(
name|c
argument_list|)
operator|)
return|;
comment|/* otherwise to the console. */
block|}
end_function

begin_comment
comment|/* Returns 0 on failure, 1 on success */
end_comment

begin_function
name|int
name|dooutput
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|quote
decl_stmt|;
if|if
condition|(
name|local
condition|)
block|{
comment|/* Condition external line */
name|y
operator|=
name|ttvt
argument_list|(
name|speed
argument_list|,
name|flow
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|quote
operator|=
literal|0
expr_stmt|;
comment|/* Initialize backslash (\) quote */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* This is done automatically in ttopen() now... */
ifdef|#
directive|ifdef
name|TNCODE
if|if
condition|(
name|network
operator|&&
name|ttnproto
operator|==
name|NP_TELNET
condition|)
comment|/* If telnet connection, */
if|if
condition|(
operator|!
name|tn_init
operator|++
condition|)
name|tn_ini
argument_list|()
expr_stmt|;
comment|/* initialize it if necessary */
endif|#
directive|endif
comment|/* TNCODE */
endif|#
directive|endif
comment|/* COMMENT */
while|while
condition|(
name|x
operator|=
operator|*
name|s
operator|++
condition|)
block|{
comment|/* Loop through the string */
name|y
operator|=
literal|0
expr_stmt|;
comment|/* Error code, 0 = no error. */
if|if
condition|(
name|x
operator|==
name|CMDQ
condition|)
block|{
comment|/* Look for \b or \B in string */
name|quote
operator|++
expr_stmt|;
comment|/* Got \ */
continue|continue;
comment|/* Get next character */
block|}
elseif|else
if|if
condition|(
name|quote
condition|)
block|{
comment|/* This character is quoted */
if|if
condition|(
name|quote
operator|==
literal|1
operator|&&
operator|(
name|x
operator|==
literal|'b'
operator|||
name|x
operator|==
literal|'B'
operator|)
condition|)
block|{
comment|/* If \b or \B */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"OUTPUT BREAK"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttsndb
argument_list|()
expr_stmt|;
comment|/* send BREAK signal */
name|quote
operator|=
literal|0
expr_stmt|;
comment|/* Turn off quote flag */
continue|continue;
comment|/* and not the b or B */
ifdef|#
directive|ifdef
name|CK_LBRK
block|}
elseif|else
if|if
condition|(
name|quote
operator|==
literal|1
operator|&&
operator|(
name|x
operator|==
literal|'l'
operator|||
name|x
operator|==
literal|'L'
operator|)
condition|)
block|{
comment|/* \l or \L */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"OUTPUT Long BREAK"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttsndlb
argument_list|()
expr_stmt|;
comment|/* send Long BREAK signal */
name|quote
operator|=
literal|0
expr_stmt|;
comment|/* Turn off quote flag */
continue|continue;
comment|/* and not the l or L */
endif|#
directive|endif
comment|/* CK_LBRK */
block|}
else|else
block|{
comment|/* if \ not followed by b or B */
name|y
operator|=
name|xxout
argument_list|(
name|dopar
argument_list|(
name|CMDQ
argument_list|)
argument_list|)
expr_stmt|;
comment|/* output the backslash. */
name|quote
operator|=
literal|0
expr_stmt|;
comment|/* Turn off quote flag */
block|}
block|}
else|else
name|quote
operator|=
literal|0
expr_stmt|;
comment|/* Turn off quote flag */
name|y
operator|=
name|xxout
argument_list|(
name|dopar
argument_list|(
operator|(
name|char
operator|)
name|x
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Output this character */
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"output error.\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|x
operator|==
literal|'\015'
condition|)
block|{
comment|/* User typed carriage return */
if|if
condition|(
name|tnlm
comment|/* If TERMINAL NEWLINE-MODE is ON */
ifdef|#
directive|ifdef
name|TNCODE
operator|||
operator|(
name|network
operator|&&
comment|/* Or we have a network connection */
name|ttnproto
operator|==
name|NP_TELNET
operator|&&
comment|/* using TELNET protocol */
name|tn_nlm
comment|/* and TELNET NEWLINE-MODE is ON */
operator|)
endif|#
directive|endif
comment|/* TNCODE */
condition|)
name|xxout
argument_list|(
name|dopar
argument_list|(
literal|'\012'
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Send LF too (CR => CRLF) */
block|}
if|if
condition|(
name|seslog
operator|&&
name|duplex
condition|)
if|if
condition|(
name|zchout
argument_list|(
name|ZSFILE
argument_list|,
operator|(
name|char
operator|)
name|x
argument_list|)
operator|<
literal|0
condition|)
name|seslog
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_comment
comment|/* Display version herald and initial prompt */
end_comment

begin_function
name|VOID
name|herald
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|bgset
operator|>
literal|0
operator|||
operator|(
name|bgset
operator|!=
literal|0
operator|&&
name|backgrd
operator|!=
literal|0
operator|)
condition|)
name|x
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"herald"
argument_list|,
literal|""
argument_list|,
name|backgrd
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
ifdef|#
directive|ifdef
name|datageneral
name|printf
argument_list|(
literal|"%s,%s\nType ? or HELP for help\n"
argument_list|,
name|versio
argument_list|,
name|ckxsys
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"%s,%s\n\rType ? or HELP for help\n"
argument_list|,
name|versio
argument_list|,
name|ckxsys
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* datageneral */
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/*  M L O O K  --  Lookup the macro name in the macro table  */
end_comment

begin_comment
comment|/*  Call this way:  v = mlook(table,word,n);      table - a 'struct mtab' table.    word  - the target string to look up in the table.    n     - the number of elements in the table.    The keyword table must be arranged in ascending alphabetical order, and  all letters must be lowercase.    Returns the table index, 0 or greater, if the name was found, or:     -3 if nothing to look up (target was null),   -2 if ambiguous,   -1 if not found.    A match is successful if the target matches a keyword exactly, or if  the target is a prefix of exactly one keyword.  It is ambiguous if the  target matches two or more keywords from the table. */
end_comment

begin_function
name|int
name|mlook
parameter_list|(
name|table
parameter_list|,
name|cmd
parameter_list|,
name|n
parameter_list|)
name|struct
name|mtab
name|table
index|[]
decl_stmt|;
name|char
modifier|*
name|cmd
decl_stmt|;
name|int
name|n
decl_stmt|;
block|{
name|int
name|i
decl_stmt|,
name|v
decl_stmt|,
name|cmdlen
decl_stmt|;
comment|/* Lowercase& get length of target, if it's null return code -3. */
if|if
condition|(
operator|(
operator|(
operator|(
name|cmdlen
operator|=
name|lower
argument_list|(
name|cmd
argument_list|)
operator|)
operator|)
operator|==
literal|0
operator|)
operator|||
operator|(
name|n
operator|<
literal|1
operator|)
condition|)
return|return
operator|(
operator|-
literal|3
operator|)
return|;
comment|/* Not null, look it up */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
operator|-
literal|1
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|)
operator|||
operator|(
operator|(
name|v
operator|=
operator|!
name|strncmp
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|,
name|cmdlen
argument_list|)
operator|)
operator|&&
name|strncmp
argument_list|(
name|table
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|,
name|cmdlen
argument_list|)
operator|)
condition|)
block|{
return|return
operator|(
name|i
operator|)
return|;
block|}
if|if
condition|(
name|v
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
comment|/* Last (or only) element */
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|table
index|[
name|n
operator|-
literal|1
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|,
name|cmdlen
argument_list|)
condition|)
block|{
return|return
operator|(
name|n
operator|-
literal|1
operator|)
return|;
block|}
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* mxlook is like mlook, but an exact full-length match is required */
end_comment

begin_function
name|int
name|mxlook
parameter_list|(
name|table
parameter_list|,
name|cmd
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|cmd
decl_stmt|;
name|struct
name|mtab
name|table
index|[]
decl_stmt|;
name|int
name|n
decl_stmt|;
block|{
name|int
name|i
decl_stmt|,
name|cmdlen
decl_stmt|;
if|if
condition|(
operator|(
operator|(
operator|(
name|cmdlen
operator|=
name|lower
argument_list|(
name|cmd
argument_list|)
operator|)
operator|)
operator|==
literal|0
operator|)
operator|||
operator|(
name|n
operator|<
literal|1
operator|)
condition|)
return|return
operator|(
operator|-
literal|3
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
if|if
condition|(
operator|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|kwd
argument_list|)
operator|==
name|cmdlen
operator|)
operator|&&
operator|(
operator|!
name|strncmp
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|,
name|cmdlen
argument_list|)
operator|)
condition|)
return|return
operator|(
name|i
operator|)
return|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*   This routine is for the benefit of those compilers that can't handle   long string constants or continued lines within them.  Long predefined   macros like FOR, WHILE, and XIF have their contents broken up into   arrays of string pointers.  This routine concatenates them back into a   single string again, and then calls the real addmac() routine to enter   the definition into the macro table. */
end_comment

begin_decl_stmt
name|int
name|addmmac
argument_list|(
name|nam
argument_list|,
name|s
argument_list|)
name|char
modifier|*
name|nam
decl_stmt|,
modifier|*
name|s
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Add a multiline macro definition */
name|int
name|i
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|x
operator|=
literal|0
expr_stmt|;
comment|/* Length counter */
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|(
name|y
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
index|[
name|i
index|]
argument_list|)
operator|)
operator|>
literal|0
condition|;
name|i
operator|++
control|)
block|{
comment|/* Add up total length */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addmmac line"
argument_list|,
name|s
index|[
name|i
index|]
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|x
operator|+=
name|y
expr_stmt|;
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"addmmac lines"
argument_list|,
literal|""
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"addmmac loop exit"
argument_list|,
literal|""
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addmmac length"
argument_list|,
name|nam
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|p
operator|=
name|malloc
argument_list|(
name|x
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* Allocate space for all of it. */
if|if
condition|(
operator|!
name|p
condition|)
block|{
name|printf
argument_list|(
literal|"?addmmac malloc error: %s\n"
argument_list|,
name|nam
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"addmmac malloc error"
argument_list|,
name|nam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
comment|/* Start off with null string. */
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|*
name|s
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
comment|/* Concatenate them all together. */
name|strcat
argument_list|(
name|p
argument_list|,
name|s
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|y
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Final precaution. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addmmac constructed string"
argument_list|,
name|p
argument_list|,
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|==
name|x
condition|)
block|{
name|y
operator|=
name|addmac
argument_list|(
name|nam
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* Add result to the macro table. */
block|}
else|else
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"addmmac length mismatch"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n!addmmac internal error!\n"
argument_list|)
expr_stmt|;
name|y
operator|=
operator|-
literal|1
expr_stmt|;
block|}
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Free the temporary copy. */
return|return
operator|(
name|y
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Here is the real addmac routine. */
end_comment

begin_function
name|int
name|addmac
parameter_list|(
name|nam
parameter_list|,
name|def
parameter_list|)
name|char
modifier|*
name|nam
decl_stmt|,
decl|*
name|def
decl_stmt|;
end_function

begin_block
block|{
comment|/* Add a macro to the macro table */
name|int
name|i
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|namlen
decl_stmt|,
name|deflen
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
name|c
decl_stmt|;
if|if
condition|(
operator|!
name|nam
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|namlen
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|nam
argument_list|)
expr_stmt|;
comment|/* Get argument lengths */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addmac nam"
argument_list|,
name|nam
argument_list|,
name|namlen
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|def
condition|)
block|{
comment|/* Watch out for null pointer */
name|deflen
operator|=
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addmac def"
argument_list|,
literal|"(null pointer)"
argument_list|,
name|deflen
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|deflen
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|def
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addmac def"
argument_list|,
name|def
argument_list|,
name|deflen
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|deflen
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* strlen() failure, fail. */
if|if
condition|(
name|namlen
operator|<
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* No name given, fail. */
if|if
condition|(
operator|*
name|nam
operator|==
name|CMDQ
condition|)
name|nam
operator|++
expr_stmt|;
comment|/* Backslash quote? */
if|if
condition|(
operator|*
name|nam
operator|==
literal|'%'
condition|)
block|{
comment|/* Yes, if it's a variable name, */
name|delmac
argument_list|(
name|nam
argument_list|)
expr_stmt|;
comment|/* Delete any old value. */
if|if
condition|(
operator|!
operator|(
name|c
operator|=
operator|*
operator|(
name|nam
operator|+
literal|1
operator|)
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Variable name letter or digit */
if|if
condition|(
name|deflen
operator|<
literal|1
condition|)
block|{
comment|/* Null definition */
name|p
operator|=
name|NULL
expr_stmt|;
comment|/* Better not malloc or strcpy! */
block|}
else|else
block|{
comment|/* A substantial definition */
name|p
operator|=
name|malloc
argument_list|(
name|deflen
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* Allocate space for it */
if|if
condition|(
operator|!
name|p
condition|)
block|{
name|printf
argument_list|(
literal|"?addmac malloc error 2\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
name|strcpy
argument_list|(
name|p
argument_list|,
name|def
argument_list|)
expr_stmt|;
comment|/* Copy definition into new space */
block|}
comment|/* Now p points to the definition, or is a null pointer */
if|if
condition|(
name|p
condition|)
name|debug
argument_list|(
name|F110
argument_list|,
literal|"addmac p"
argument_list|,
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|debug
argument_list|(
name|F110
argument_list|,
literal|"addmac p"
argument_list|,
literal|"(null pointer)"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|>=
literal|'0'
operator|&&
name|c
operator|<=
literal|'9'
condition|)
block|{
comment|/* Digit variable */
if|if
condition|(
name|maclvl
operator|<
literal|0
condition|)
block|{
comment|/* Are we calling or in a macro? */
name|g_var
index|[
name|c
index|]
operator|=
name|p
expr_stmt|;
comment|/* No, it's a global "top level" one */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"addmac numeric global maclvl"
argument_list|,
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Yes, it's a macro argument */
name|m_arg
index|[
name|maclvl
index|]
index|[
name|c
operator|-
literal|'0'
index|]
operator|=
name|p
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"addmac macro arg maclvl"
argument_list|,
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* It's a global variable */
if|if
condition|(
name|c
operator|<
literal|33
operator|||
name|c
operator|>
name|GVARS
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|isupper
argument_list|(
name|c
argument_list|)
condition|)
name|c
operator|=
name|tolower
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|g_var
index|[
name|c
index|]
operator|=
name|p
expr_stmt|;
comment|/* Put pointer in global-var table */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"addmac global"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
elseif|else
if|if
condition|(
operator|*
name|nam
operator|==
literal|'&'
condition|)
block|{
comment|/* An array reference? */
name|char
modifier|*
modifier|*
name|q
decl_stmt|;
if|if
condition|(
operator|(
name|y
operator|=
name|arraynam
argument_list|(
name|nam
argument_list|,
operator|&
name|x
argument_list|,
operator|&
name|z
argument_list|)
operator|)
operator|<
literal|0
condition|)
comment|/* If syntax is bad */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* return -1. */
if|if
condition|(
name|chkarray
argument_list|(
name|x
argument_list|,
name|z
argument_list|)
operator|<
literal|0
condition|)
comment|/* If array not declared or */
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* subscript out of range, ret -2 */
name|delmac
argument_list|(
name|nam
argument_list|)
expr_stmt|;
comment|/* Delete any current definition. */
name|x
operator|-=
literal|96
expr_stmt|;
comment|/* Convert name letter to index. */
if|if
condition|(
operator|(
name|q
operator|=
name|a_ptr
index|[
name|x
index|]
operator|)
operator|==
name|NULL
condition|)
comment|/* If array not declared, */
return|return
operator|(
operator|-
literal|3
operator|)
return|;
comment|/* return -3. */
if|if
condition|(
name|deflen
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|p
operator|=
name|malloc
argument_list|(
name|deflen
operator|+
literal|1
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* Allocate space */
name|printf
argument_list|(
literal|"addmac macro error 7: %s\n"
argument_list|,
name|nam
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|4
operator|)
return|;
comment|/* for new def, return -4 on fail. */
block|}
name|strcpy
argument_list|(
name|p
argument_list|,
name|def
argument_list|)
expr_stmt|;
comment|/* Copy definition into new space. */
block|}
else|else
name|p
operator|=
name|NULL
expr_stmt|;
name|q
index|[
name|z
index|]
operator|=
name|p
expr_stmt|;
comment|/* Store pointer to it. */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Done. */
block|}
else|else
name|debug
argument_list|(
name|F110
argument_list|,
literal|"addmac macro def"
argument_list|,
name|nam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Not a macro argument or a variable, so it's a macro definition */
name|lower
argument_list|(
name|nam
argument_list|)
expr_stmt|;
comment|/* Lowercase the name */
if|if
condition|(
name|mxlook
argument_list|(
name|mactab
argument_list|,
name|nam
argument_list|,
name|nmac
argument_list|)
operator|>
operator|-
literal|1
condition|)
comment|/* Look up, requiring exact match */
name|delmac
argument_list|(
name|nam
argument_list|)
expr_stmt|;
comment|/* if it's there, delete it. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addmac table size"
argument_list|,
name|nam
argument_list|,
name|nmac
argument_list|)
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
comment|/* Find the alphabetical slot */
name|y
operator|<
name|MAC_MAX
operator|&&
name|mactab
index|[
name|y
index|]
operator|.
name|kwd
operator|!=
name|NULL
operator|&&
name|strcmp
argument_list|(
name|nam
argument_list|,
name|mactab
index|[
name|y
index|]
operator|.
name|kwd
argument_list|)
operator|>
literal|0
condition|;
name|y
operator|++
control|)
empty_stmt|;
if|if
condition|(
name|y
operator|==
name|MAC_MAX
condition|)
block|{
comment|/* No more room. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"addmac table overflow"
argument_list|,
literal|""
argument_list|,
name|y
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addmac position"
argument_list|,
name|nam
argument_list|,
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|mactab
index|[
name|y
index|]
operator|.
name|kwd
operator|!=
name|NULL
condition|)
block|{
comment|/* Must insert */
for|for
control|(
name|i
operator|=
name|nmac
init|;
name|i
operator|>
name|y
condition|;
name|i
operator|--
control|)
block|{
comment|/* Move the rest down one slot */
name|mactab
index|[
name|i
index|]
operator|.
name|kwd
operator|=
name|mactab
index|[
name|i
operator|-
literal|1
index|]
operator|.
name|kwd
expr_stmt|;
name|mactab
index|[
name|i
index|]
operator|.
name|mval
operator|=
name|mactab
index|[
name|i
operator|-
literal|1
index|]
operator|.
name|mval
expr_stmt|;
name|mactab
index|[
name|i
index|]
operator|.
name|flgs
operator|=
name|mactab
index|[
name|i
operator|-
literal|1
index|]
operator|.
name|flgs
expr_stmt|;
block|}
block|}
name|p
operator|=
name|malloc
argument_list|(
name|namlen
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* Allocate space for name */
if|if
condition|(
operator|!
name|p
condition|)
block|{
name|printf
argument_list|(
literal|"?addmac malloc error 3: %s\n"
argument_list|,
name|nam
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|strcpy
argument_list|(
name|p
argument_list|,
name|nam
argument_list|)
expr_stmt|;
comment|/* Copy name into new space */
name|mactab
index|[
name|y
index|]
operator|.
name|kwd
operator|=
name|p
expr_stmt|;
comment|/* Add pointer to table */
if|if
condition|(
name|deflen
operator|>
literal|0
condition|)
block|{
comment|/* Same deal for definition */
name|p
operator|=
name|malloc
argument_list|(
name|deflen
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* but watch out for null pointer */
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"?addmac malloc error 5: %s\n"
argument_list|,
name|nam
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|mactab
index|[
name|y
index|]
operator|.
name|kwd
argument_list|)
expr_stmt|;
name|mactab
index|[
name|y
index|]
operator|.
name|kwd
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
name|strcpy
argument_list|(
name|p
argument_list|,
name|def
argument_list|)
expr_stmt|;
comment|/* Copy the definition */
block|}
else|else
name|p
operator|=
name|NULL
expr_stmt|;
name|mactab
index|[
name|y
index|]
operator|.
name|mval
operator|=
name|p
expr_stmt|;
name|mactab
index|[
name|y
index|]
operator|.
name|flgs
operator|=
literal|0
expr_stmt|;
name|nmac
operator|++
expr_stmt|;
comment|/* Count this macro */
return|return
operator|(
name|y
operator|)
return|;
block|}
end_block

begin_function
name|int
name|delmac
parameter_list|(
name|nam
parameter_list|)
name|char
modifier|*
name|nam
decl_stmt|;
block|{
comment|/* Delete the named macro */
name|int
name|i
decl_stmt|,
name|x
decl_stmt|,
name|z
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
name|c
decl_stmt|;
if|if
condition|(
operator|!
name|nam
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Watch out for null pointer */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"delmac nam"
argument_list|,
name|nam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|nam
operator|==
name|CMDQ
condition|)
name|nam
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|nam
operator|==
literal|'%'
condition|)
block|{
comment|/* If it's a variable name */
if|if
condition|(
operator|!
operator|(
name|c
operator|=
operator|*
operator|(
name|nam
operator|+
literal|1
operator|)
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Get variable name letter or digit */
name|p
operator|=
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|/* Initialize value pointer */
if|if
condition|(
name|maclvl
operator|>
operator|-
literal|1
operator|&&
name|c
operator|>=
literal|'0'
operator|&&
name|c
operator|<=
literal|'9'
condition|)
block|{
comment|/* Digit? */
name|p
operator|=
name|m_arg
index|[
name|maclvl
index|]
index|[
name|c
operator|-
literal|'0'
index|]
expr_stmt|;
comment|/* Get pointer from macro-arg table */
name|m_arg
index|[
name|maclvl
index|]
index|[
name|c
operator|-
literal|'0'
index|]
operator|=
name|NULL
expr_stmt|;
comment|/* Zero the table pointer */
block|}
else|else
block|{
comment|/* It's a global variable */
if|if
condition|(
name|c
operator|<
literal|33
operator|||
name|c
operator|>
name|GVARS
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|p
operator|=
name|g_var
index|[
name|c
index|]
expr_stmt|;
comment|/* Get pointer from global-var table */
name|g_var
index|[
name|c
index|]
operator|=
name|NULL
expr_stmt|;
comment|/* Zero the table entry */
block|}
if|if
condition|(
name|p
condition|)
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"delmac def"
argument_list|,
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Free the storage */
block|}
else|else
name|debug
argument_list|(
name|F110
argument_list|,
literal|"delmac def"
argument_list|,
literal|"(null pointer)"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
operator|*
name|nam
operator|==
literal|'&'
condition|)
block|{
comment|/* An array reference? */
name|char
modifier|*
modifier|*
name|q
decl_stmt|;
if|if
condition|(
name|arraynam
argument_list|(
name|nam
argument_list|,
operator|&
name|x
argument_list|,
operator|&
name|z
argument_list|)
operator|<
literal|0
condition|)
comment|/* If syntax is bad */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* return -1. */
name|x
operator|-=
literal|96
expr_stmt|;
comment|/* Convert name to number. */
if|if
condition|(
operator|(
name|q
operator|=
name|a_ptr
index|[
name|x
index|]
operator|)
operator|==
name|NULL
condition|)
comment|/* If array not declared, */
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* return -2. */
if|if
condition|(
name|z
operator|>
name|a_dim
index|[
name|x
index|]
condition|)
comment|/* If subscript out of range, */
return|return
operator|(
operator|-
literal|3
operator|)
return|;
comment|/* return -3. */
if|if
condition|(
name|q
index|[
name|z
index|]
condition|)
block|{
comment|/* If there is an old value, */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"delman def"
argument_list|,
name|q
index|[
name|z
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|q
index|[
name|z
index|]
argument_list|)
expr_stmt|;
comment|/* delete it. */
name|q
index|[
name|z
index|]
operator|=
name|NULL
expr_stmt|;
block|}
else|else
name|debug
argument_list|(
name|F110
argument_list|,
literal|"delmac def"
argument_list|,
literal|"(null pointer)"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* Not a variable or an array, so it must be a macro. */
if|if
condition|(
operator|(
name|x
operator|=
name|mlook
argument_list|(
name|mactab
argument_list|,
name|nam
argument_list|,
name|nmac
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Look it up */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"delmac mlook"
argument_list|,
name|nam
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
if|if
condition|(
name|mactab
index|[
name|x
index|]
operator|.
name|kwd
condition|)
comment|/* Free the storage for the name */
name|free
argument_list|(
name|mactab
index|[
name|x
index|]
operator|.
name|kwd
argument_list|)
expr_stmt|;
if|if
condition|(
name|mactab
index|[
name|x
index|]
operator|.
name|mval
condition|)
comment|/* and for the definition */
name|free
argument_list|(
name|mactab
index|[
name|x
index|]
operator|.
name|mval
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|x
init|;
name|i
operator|<
name|nmac
condition|;
name|i
operator|++
control|)
block|{
comment|/* Now move up the others. */
name|mactab
index|[
name|i
index|]
operator|.
name|kwd
operator|=
name|mactab
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|kwd
expr_stmt|;
name|mactab
index|[
name|i
index|]
operator|.
name|mval
operator|=
name|mactab
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|mval
expr_stmt|;
name|mactab
index|[
name|i
index|]
operator|.
name|flgs
operator|=
name|mactab
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|flgs
expr_stmt|;
block|}
name|nmac
operator|--
expr_stmt|;
comment|/* One less macro */
name|mactab
index|[
name|nmac
index|]
operator|.
name|kwd
operator|=
name|NULL
expr_stmt|;
comment|/* Delete last item from table */
name|mactab
index|[
name|nmac
index|]
operator|.
name|mval
operator|=
name|NULL
expr_stmt|;
name|mactab
index|[
name|nmac
index|]
operator|.
name|flgs
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|VOID
name|initmac
parameter_list|()
block|{
comment|/* Init macro& variable tables */
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|nmac
operator|=
literal|0
expr_stmt|;
comment|/* No macros */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAC_MAX
condition|;
name|i
operator|++
control|)
block|{
comment|/* Initialize the macro table */
name|mactab
index|[
name|i
index|]
operator|.
name|kwd
operator|=
name|NULL
expr_stmt|;
name|mactab
index|[
name|i
index|]
operator|.
name|mval
operator|=
name|NULL
expr_stmt|;
name|mactab
index|[
name|i
index|]
operator|.
name|flgs
operator|=
literal|0
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MACLEVEL
condition|;
name|i
operator|++
control|)
block|{
comment|/* Init the macro argument tables */
name|mrval
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
literal|10
condition|;
name|j
operator|++
control|)
block|{
name|m_arg
index|[
name|i
index|]
index|[
name|j
index|]
operator|=
name|NULL
expr_stmt|;
block|}
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|GVARS
condition|;
name|i
operator|++
control|)
block|{
comment|/* And the global variables table */
name|g_var
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|26
condition|;
name|i
operator|++
control|)
block|{
comment|/* And the table of arrays */
name|a_ptr
index|[
name|i
index|]
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
expr_stmt|;
comment|/* Null pointer for each */
name|a_dim
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
comment|/* and a dimension of zero */
block|}
block|}
end_function

begin_function
name|int
name|popclvl
parameter_list|()
block|{
comment|/* Pop command level, return cmdlvl */
if|if
condition|(
name|cmdlvl
operator|<
literal|1
condition|)
block|{
comment|/* If we're already at top level */
name|cmdlvl
operator|=
literal|0
expr_stmt|;
comment|/* just make sure all the */
name|tlevel
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* stack pointers are set right */
name|maclvl
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* and return */
block|}
elseif|else
if|if
condition|(
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|==
name|CMD_TF
condition|)
block|{
comment|/* Reading from TAKE file? */
if|if
condition|(
name|tlevel
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Yes, */
if|if
condition|(
name|tfnam
index|[
name|tlevel
index|]
condition|)
block|{
name|free
argument_list|(
name|tfnam
index|[
name|tlevel
index|]
argument_list|)
expr_stmt|;
name|tfnam
index|[
name|tlevel
index|]
operator|=
name|NULL
expr_stmt|;
block|}
name|fclose
argument_list|(
name|tfile
index|[
name|tlevel
operator|--
index|]
argument_list|)
expr_stmt|;
comment|/* close it and pop take level */
name|cmdlvl
operator|--
expr_stmt|;
comment|/* pop command level */
block|}
else|else
name|tlevel
operator|=
operator|-
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|==
name|CMD_MD
condition|)
block|{
comment|/* In a macro? */
if|if
condition|(
name|maclvl
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Yes, */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"popclvl before"
argument_list|,
name|macx
index|[
name|maclvl
index|]
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
name|macp
index|[
name|maclvl
index|]
operator|=
literal|""
expr_stmt|;
comment|/* set macro pointer to null string */
operator|*
name|cmdbuf
operator|=
literal|'\0'
expr_stmt|;
comment|/* clear the command buffer */
if|if
condition|(
name|mrval
index|[
name|maclvl
operator|+
literal|1
index|]
condition|)
block|{
comment|/* Free any deeper return values. */
name|free
argument_list|(
name|mrval
index|[
name|maclvl
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
name|mrval
index|[
name|maclvl
operator|+
literal|1
index|]
operator|=
name|NULL
expr_stmt|;
block|}
name|maclvl
operator|--
expr_stmt|;
comment|/* pop macro level */
name|cmdlvl
operator|--
expr_stmt|;
comment|/* and command level */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"popclvl after "
argument_list|,
name|macx
index|[
name|maclvl
index|]
condition|?
name|macx
index|[
name|maclvl
index|]
else|:
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
block|}
else|else
name|maclvl
operator|=
operator|-
literal|1
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|MAC
if|if
condition|(
name|cmdlvl
operator|<
literal|1
condition|)
block|{
comment|/* If back at top level */
name|conint
argument_list|(
name|trap
argument_list|,
name|stptrap
argument_list|)
expr_stmt|;
comment|/* Fix interrupts */
name|bgchk
argument_list|()
expr_stmt|;
comment|/* Check background status */
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* Go into cbreak mode */
block|}
endif|#
directive|endif
comment|/* MAC */
return|return
operator|(
name|cmdlvl
operator|<
literal|1
condition|?
literal|0
else|:
name|cmdlvl
operator|)
return|;
comment|/* Return command level */
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* No script programming language */
end_comment

begin_function
name|int
name|popclvl
parameter_list|()
block|{
comment|/* Just close current take file. */
if|if
condition|(
name|tlevel
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* if any... */
if|if
condition|(
name|tfnam
index|[
name|tlevel
index|]
condition|)
block|{
name|free
argument_list|(
name|tfnam
index|[
name|tlevel
index|]
argument_list|)
expr_stmt|;
name|tfnam
index|[
name|tlevel
index|]
operator|=
name|NULL
expr_stmt|;
block|}
name|fclose
argument_list|(
name|tfile
index|[
name|tlevel
operator|--
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tlevel
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* And if back at top level */
name|conint
argument_list|(
name|trap
argument_list|,
name|stptrap
argument_list|)
expr_stmt|;
comment|/* check and set interrupts */
name|bgchk
argument_list|()
expr_stmt|;
comment|/* and background status */
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* and go back into cbreak mode. */
block|}
return|return
operator|(
name|tlevel
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_comment
comment|/* STOP - get back to C-Kermit prompt, no matter where from. */
end_comment

begin_function
name|int
name|dostop
parameter_list|()
block|{
while|while
condition|(
name|popclvl
argument_list|()
condition|)
empty_stmt|;
comment|/* Pop all macros& take files */
ifndef|#
directive|ifndef
name|NOSPL
while|while
condition|(
name|cmpop
argument_list|()
operator|>
operator|-
literal|1
condition|)
empty_stmt|;
comment|/* And all recursive cmd pkg invocations */
endif|#
directive|endif
comment|/* NOSPL */
name|cmini
argument_list|(
name|ckxech
argument_list|)
expr_stmt|;
comment|/* Clear the command buffer. */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Close the given log */
end_comment

begin_function
name|int
name|doclslog
parameter_list|(
name|x
parameter_list|)
name|int
name|x
decl_stmt|;
block|{
name|int
name|y
decl_stmt|;
switch|switch
condition|(
name|x
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
case|case
name|LOGD
case|:
if|if
condition|(
name|deblog
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"?Debugging log wasn't open\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
operator|*
name|debfil
operator|=
literal|'\0'
expr_stmt|;
name|deblog
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|zclose
argument_list|(
name|ZDFILE
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* DEBUG */
case|case
name|LOGP
case|:
if|if
condition|(
name|pktlog
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"?Packet log wasn't open\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
operator|*
name|pktfil
operator|=
literal|'\0'
expr_stmt|;
name|pktlog
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|zclose
argument_list|(
name|ZPFILE
argument_list|)
operator|)
return|;
case|case
name|LOGS
case|:
if|if
condition|(
name|seslog
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"?Session log wasn't open\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
operator|*
name|sesfil
operator|=
literal|'\0'
expr_stmt|;
name|seslog
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|zclose
argument_list|(
name|ZSFILE
argument_list|)
operator|)
return|;
ifdef|#
directive|ifdef
name|TLOG
case|case
name|LOGT
case|:
if|if
condition|(
name|tralog
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"?Transaction log wasn't open\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
operator|*
name|trafil
operator|=
literal|'\0'
expr_stmt|;
name|tralog
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|zclose
argument_list|(
name|ZTFILE
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* TLOG */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|LOGW
case|:
comment|/* WRITE file */
case|case
name|LOGR
case|:
comment|/* READ file */
name|y
operator|=
operator|(
name|x
operator|==
name|LOGR
operator|)
condition|?
name|ZRFILE
else|:
name|ZWFILE
expr_stmt|;
if|if
condition|(
name|chkfn
argument_list|(
name|y
argument_list|)
operator|<
literal|1
condition|)
comment|/* If no file to close */
return|return
operator|(
literal|1
operator|)
return|;
comment|/* succeed silently. */
return|return
operator|(
name|zclose
argument_list|(
name|y
argument_list|)
operator|)
return|;
comment|/* Otherwise, close the file. */
endif|#
directive|endif
comment|/* NOSPL */
default|default:
name|printf
argument_list|(
literal|"\n?Unexpected log designator - %ld\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|NOSERVER
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOFRILLS
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|nm
index|[]
init|=
block|{
literal|"disabled"
block|,
literal|"enabled"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOFRILLS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSERVER */
end_comment

begin_decl_stmt
specifier|static
name|int
name|slc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Screen line count */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSHOW
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOFRILLS
end_ifndef

begin_define
define|#
directive|define
name|xxdiff
parameter_list|(
name|v
parameter_list|,
name|sys
parameter_list|)
value|strncmp(v,sys,strlen(sys))
end_define

begin_function
name|VOID
name|shover
parameter_list|()
block|{
name|printf
argument_list|(
literal|"\nVersions:\n %s\n Numeric: %ld"
argument_list|,
name|versio
argument_list|,
name|vernum
argument_list|)
expr_stmt|;
if|if
condition|(
name|verwho
condition|)
name|printf
argument_list|(
literal|"-%d"
argument_list|,
name|verwho
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|xxdiff
argument_list|(
name|ckxv
argument_list|,
name|ckxsys
argument_list|)
condition|?
literal|"\n %s for%s\n"
else|:
literal|"\n %s\n"
argument_list|,
name|ckxv
argument_list|,
name|ckxsys
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|xxdiff
argument_list|(
name|ckzv
argument_list|,
name|ckzsys
argument_list|)
condition|?
literal|" %s for%s\n"
else|:
literal|" %s\n"
argument_list|,
name|ckzv
argument_list|,
name|ckzsys
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|protv
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|fnsv
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %s\n %s\n"
argument_list|,
name|cmdv
argument_list|,
name|userv
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOCSETS
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|xlav
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCSETS */
ifndef|#
directive|ifndef
name|MAC
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|connv
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
ifndef|#
directive|ifndef
name|NODIAL
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|dialv
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NODIAL */
ifndef|#
directive|ifndef
name|NOSCRIPT
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|loginv
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSCRIPT */
ifdef|#
directive|ifdef
name|NETCONN
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|cknetv
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NETCONN */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|VOID
name|shofea
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|OS2
ifdef|#
directive|ifdef
name|M_I286
name|printf
argument_list|(
literal|"\nOS/2 16-bit.\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"\nOS/2 32-bit.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* M_I286 */
endif|#
directive|endif
comment|/* OS2 */
name|printf
argument_list|(
literal|"\nSpecial features:\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NETCONN
name|printf
argument_list|(
literal|" Network support (type SHOW NET for further info)\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NETCONN */
ifndef|#
directive|ifndef
name|NOCSETS
name|printf
argument_list|(
literal|" Latin-1 (West European) character-set translation\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|LATIN2
name|printf
argument_list|(
literal|" Latin-2 (East European) character-set translation\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* LATIN2 */
ifdef|#
directive|ifdef
name|CYRILLIC
name|printf
argument_list|(
literal|" Cyrillic (Russian, Ukrainian, etc) character-set translation\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CYRILLIC */
ifdef|#
directive|ifdef
name|KANJI
name|printf
argument_list|(
literal|" Kanji (Japanese) character-set translation\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* KANJI */
endif|#
directive|endif
comment|/* NOCSETS */
ifdef|#
directive|ifdef
name|CK_CURSES
name|printf
argument_list|(
literal|" Fullscreen file transfer display\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CK_CURSES */
name|printf
argument_list|(
literal|"\nFeatures not included:\n"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|CK_CURSES
ifndef|#
directive|ifndef
name|MAC
name|printf
argument_list|(
literal|" No fullscreen file transfer display\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
endif|#
directive|endif
comment|/* CK_CURSES */
ifdef|#
directive|ifdef
name|NOSERVER
name|printf
argument_list|(
literal|" No server mode\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSERVER */
ifdef|#
directive|ifdef
name|NODEBUG
name|printf
argument_list|(
literal|" No debugging\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NODEBUG */
ifdef|#
directive|ifdef
name|NOTLOG
name|printf
argument_list|(
literal|" No transaction log\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOTLOG */
ifdef|#
directive|ifdef
name|NOHELP
name|printf
argument_list|(
literal|" No built-in help\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOHELP */
ifndef|#
directive|ifndef
name|NETCONN
name|printf
argument_list|(
literal|" No network support\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NETCONN */
ifdef|#
directive|ifdef
name|NOMSEND
name|printf
argument_list|(
literal|" No MSEND command\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOMSEND */
ifdef|#
directive|ifdef
name|NODIAL
name|printf
argument_list|(
literal|" No DIAL command\n"
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|MINIDIAL
name|printf
argument_list|(
literal|" DIAL command for modems other than Hayes, CCITT, and Unknown\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MINIDIAL */
endif|#
directive|endif
comment|/* NODIAL */
ifdef|#
directive|ifdef
name|NOXMIT
name|printf
argument_list|(
literal|" No TRANSMIT command\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOXMIT */
ifdef|#
directive|ifdef
name|NOSCRIPT
name|printf
argument_list|(
literal|" No SCRIPT command\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSCRIPT */
ifdef|#
directive|ifdef
name|NOSPL
name|printf
argument_list|(
literal|" No script programming features\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
ifdef|#
directive|ifdef
name|NOCSETS
name|printf
argument_list|(
literal|" No character-set translation\n"
argument_list|)
expr_stmt|;
else|#
directive|else
ifndef|#
directive|ifndef
name|LATIN2
name|printf
argument_list|(
literal|" No Latin-2 character-set translation\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* LATIN2 */
ifdef|#
directive|ifdef
name|NOCYRIL
name|printf
argument_list|(
literal|" No Cyrillic character-set translation\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCYRIL */
ifndef|#
directive|ifndef
name|KANJI
name|printf
argument_list|(
literal|" No Kanji character-set translation\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* KANJI */
endif|#
directive|endif
comment|/* NOCSETS */
ifdef|#
directive|ifdef
name|NOCMDL
name|printf
argument_list|(
literal|" No command-line arguments\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCMDL */
ifdef|#
directive|ifdef
name|NOFRILLS
name|printf
argument_list|(
literal|" No frills\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOFRILLS */
ifdef|#
directive|ifdef
name|NOPUSH
name|printf
argument_list|(
literal|" No escape to system\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOPUSH */
ifdef|#
directive|ifdef
name|NOJC
ifdef|#
directive|ifdef
name|UNIX
name|printf
argument_list|(
literal|" No UNIX job control\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* UNIX */
endif|#
directive|endif
comment|/* NOJC */
ifdef|#
directive|ifdef
name|NOSETKEY
name|printf
argument_list|(
literal|" No SET KEY command\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSETKEY */
ifdef|#
directive|ifdef
name|NOESCSEQ
name|printf
argument_list|(
literal|" No ANSI escape sequence recognition\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOESCSEQ */
ifndef|#
directive|ifndef
name|PARSENSE
name|printf
argument_list|(
literal|" No automatic parity detection\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PARSENSE */
comment|/*   Print all of Kermit's compile-time options, as well as C preprocessor   predefined symbols that might affect us... */
name|printf
argument_list|(
literal|"\nCompiler options:\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
ifdef|#
directive|ifdef
name|IFDEBUG
name|prtopt
argument_list|(
literal|" IFDEBUG"
argument_list|)
expr_stmt|;
else|#
directive|else
name|prtopt
argument_list|(
literal|" DEBUG"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* IFDEBUG */
endif|#
directive|endif
comment|/* DEBUG */
ifdef|#
directive|ifdef
name|TLOG
name|prtopt
argument_list|(
literal|" TLOG"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TLOG */
ifdef|#
directive|ifdef
name|NODIAL
name|prtopt
argument_list|(
literal|" NODIAL"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NODIAL */
ifdef|#
directive|ifdef
name|MINIDIAL
name|prtopt
argument_list|(
literal|" MINIDIAL"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MINIDIAL */
ifdef|#
directive|ifdef
name|DYNAMIC
name|prtopt
argument_list|(
literal|" DYNAMIC"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* IFDEBUG */
ifndef|#
directive|ifndef
name|NOSPL
name|sprintf
argument_list|(
name|line
argument_list|,
literal|" CMDDEP=%d"
argument_list|,
name|CMDDEP
argument_list|)
expr_stmt|;
name|prtopt
argument_list|(
name|line
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
ifdef|#
directive|ifdef
name|UNIX
name|prtopt
argument_list|(
literal|" UNIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* UNIX */
ifdef|#
directive|ifdef
name|VMS
name|prtopt
argument_list|(
literal|" VMS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
ifdef|#
directive|ifdef
name|vms
name|prtopt
argument_list|(
literal|" vms"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* vms */
ifdef|#
directive|ifdef
name|VMSSHARE
name|prtopt
argument_list|(
literal|" VMSSHARE"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMSSHARE */
ifdef|#
directive|ifdef
name|datageneral
name|prtopt
argument_list|(
literal|" datageneral"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* datageneral */
ifdef|#
directive|ifdef
name|apollo
name|prtopt
argument_list|(
literal|" apollo"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* apollo */
ifdef|#
directive|ifdef
name|aegis
name|prtopt
argument_list|(
literal|" aegis"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* aegis */
ifdef|#
directive|ifdef
name|A986
name|prtopt
argument_list|(
literal|" A986"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* A986 */
ifdef|#
directive|ifdef
name|AMIGA
name|prtopt
argument_list|(
literal|" AMIGA"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* AMIGA */
ifdef|#
directive|ifdef
name|CONVEX9
name|prtopt
argument_list|(
literal|" CONVEX9"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CONVEX9 */
ifdef|#
directive|ifdef
name|MAC
name|prtopt
argument_list|(
literal|" MAC"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
ifdef|#
directive|ifdef
name|AUX
name|prtopt
argument_list|(
literal|" AUX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* AUX */
ifdef|#
directive|ifdef
name|OS2
name|prtopt
argument_list|(
literal|" OS2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
ifdef|#
directive|ifdef
name|OS9
name|prtopt
argument_list|(
literal|" OS9"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS9 */
ifdef|#
directive|ifdef
name|MSDOS
name|prtopt
argument_list|(
literal|" MSDOS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MSDOS */
ifdef|#
directive|ifdef
name|DIRENT
name|prtopt
argument_list|(
literal|" DIRENT"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DIRENT */
ifdef|#
directive|ifdef
name|SDIRENT
name|prtopt
argument_list|(
literal|" SDIRENT"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SDIRENT */
ifdef|#
directive|ifdef
name|NDIR
name|prtopt
argument_list|(
literal|" NDIR"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NDIR */
ifdef|#
directive|ifdef
name|XNDIR
name|prtopt
argument_list|(
literal|" XNDIR"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* XNDIR */
ifdef|#
directive|ifdef
name|MATCHDOT
name|prtopt
argument_list|(
literal|" MATCHDOT"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MATCHDOT */
ifdef|#
directive|ifdef
name|SAVEDUID
name|prtopt
argument_list|(
literal|" SAVEDUID"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SAVEDUID */
ifdef|#
directive|ifdef
name|NOCCTRAP
name|prtopt
argument_list|(
literal|" NOCCTRAP"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCCTRAP */
ifdef|#
directive|ifdef
name|SUNX25
name|prtopt
argument_list|(
literal|" SUNX25"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SUNX25 */
ifdef|#
directive|ifdef
name|DECNET
name|prtopt
argument_list|(
literal|" DECNET"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DECNET */
ifdef|#
directive|ifdef
name|ATT7300
name|prtopt
argument_list|(
literal|" ATT7300"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ATT7300 */
ifdef|#
directive|ifdef
name|ATT6300
name|prtopt
argument_list|(
literal|" ATT6300"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ATT6300 */
ifdef|#
directive|ifdef
name|HDBUUCP
name|prtopt
argument_list|(
literal|" HDBUUCP"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HDBUUCP */
ifdef|#
directive|ifdef
name|NOUUCP
name|prtopt
argument_list|(
literal|" NOUUCP"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOUUCP */
ifdef|#
directive|ifdef
name|LONGFN
name|prtopt
argument_list|(
literal|" LONGFN"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* LONGFN */
ifdef|#
directive|ifdef
name|RDCHK
name|prtopt
argument_list|(
literal|" RDCHK"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RDCHK */
ifdef|#
directive|ifdef
name|NAP
name|prtopt
argument_list|(
literal|" NAP"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NAP */
ifdef|#
directive|ifdef
name|NAPHACK
name|prtopt
argument_list|(
literal|" NAPHACK"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NAPHACK */
ifdef|#
directive|ifdef
name|NOIEXTEN
name|prtopt
argument_list|(
literal|" NOIEXTEN"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOIEXTEN */
ifdef|#
directive|ifdef
name|EXCELAN
name|prtopt
argument_list|(
literal|" EXCELAN"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* EXCELAN */
ifdef|#
directive|ifdef
name|PARAMH
name|prtopt
argument_list|(
literal|" PARAMH"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PARAMH */
ifdef|#
directive|ifdef
name|INTERLAN
name|prtopt
argument_list|(
literal|" INTERLAN"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* INTERLAN */
ifdef|#
directive|ifdef
name|NOFILEH
name|prtopt
argument_list|(
literal|" NOFILEH"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOFILEH */
ifdef|#
directive|ifdef
name|NOSYSIOCTLH
name|prtopt
argument_list|(
literal|" NOSYSIOCTLH"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSYSIOCTLH */
ifdef|#
directive|ifdef
name|DCLPOPEN
name|prtopt
argument_list|(
literal|" DCLPOPEN"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DCLPOPEN */
ifdef|#
directive|ifdef
name|NOSETBUF
name|prtopt
argument_list|(
literal|" NOSETBUF"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSETBUF */
ifdef|#
directive|ifdef
name|NOFDZERO
name|prtopt
argument_list|(
literal|" NOFDZERO"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOFDZERO */
ifdef|#
directive|ifdef
name|NOPOPEN
name|prtopt
argument_list|(
literal|" NOPOPEN"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOPOPEN */
ifdef|#
directive|ifdef
name|NOPARTIAL
name|prtopt
argument_list|(
literal|" NOPARTIAL"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOPARTIAL */
ifdef|#
directive|ifdef
name|NOSETREU
name|prtopt
argument_list|(
literal|" NOSETREU"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSETREU */
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
name|prtopt
argument_list|(
literal|" _POSIX_SOURCE"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _POSIX_SOURCE */
ifdef|#
directive|ifdef
name|LCKDIR
name|prtopt
argument_list|(
literal|" LCKDIR"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* LCKDIR */
ifdef|#
directive|ifdef
name|ACUCNTRL
name|prtopt
argument_list|(
literal|" ACUCNTRL"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ACUCNTRL */
ifdef|#
directive|ifdef
name|BSD4
name|prtopt
argument_list|(
literal|" BSD4"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD4 */
ifdef|#
directive|ifdef
name|BSD44
name|prtopt
argument_list|(
literal|" BSD44"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD44 */
ifdef|#
directive|ifdef
name|BSD41
name|prtopt
argument_list|(
literal|" BSD41"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD41 */
ifdef|#
directive|ifdef
name|BSD43
name|prtopt
argument_list|(
literal|" BSD43"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD43 */
ifdef|#
directive|ifdef
name|BSD29
name|prtopt
argument_list|(
literal|" BSD29"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD29 */
ifdef|#
directive|ifdef
name|V7
name|prtopt
argument_list|(
literal|" V7"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* V7 */
ifdef|#
directive|ifdef
name|AIX370
name|prtopt
argument_list|(
literal|" AIX370"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* AIX370 */
ifdef|#
directive|ifdef
name|RTAIX
name|prtopt
argument_list|(
literal|" RTAIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RTAIX */
ifdef|#
directive|ifdef
name|HPUX
name|prtopt
argument_list|(
literal|" HPUX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HPUX */
ifdef|#
directive|ifdef
name|HPUXPRE65
name|prtopt
argument_list|(
literal|" HPUXPRE65"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HPUXPRE65 */
ifdef|#
directive|ifdef
name|DGUX
name|prtopt
argument_list|(
literal|" DGUX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DGUX */
ifdef|#
directive|ifdef
name|DGUX430
name|prtopt
argument_list|(
literal|" DGUX430"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DGUX430 */
ifdef|#
directive|ifdef
name|DGUX540
name|prtopt
argument_list|(
literal|" DGUX540"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DGUX540 */
ifdef|#
directive|ifdef
name|sony_news
name|prtopt
argument_list|(
literal|" sony_news"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sony_news */
ifdef|#
directive|ifdef
name|CIE
name|prtopt
argument_list|(
literal|" CIE"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CIE */
ifdef|#
directive|ifdef
name|XENIX
name|prtopt
argument_list|(
literal|" XENIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* XENIX */
ifdef|#
directive|ifdef
name|SCO_XENIX
name|prtopt
argument_list|(
literal|" SCO_XENIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SCO_XENIX */
ifdef|#
directive|ifdef
name|ISIII
name|prtopt
argument_list|(
literal|" ISIII"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ISIII */
ifdef|#
directive|ifdef
name|I386IX
name|prtopt
argument_list|(
literal|" I386IX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* I386IX */
ifdef|#
directive|ifdef
name|RTU
name|prtopt
argument_list|(
literal|" RTU"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RTU */
ifdef|#
directive|ifdef
name|PROVX1
name|prtopt
argument_list|(
literal|" PROVX1"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PROVX1 */
ifdef|#
directive|ifdef
name|TOWER1
name|prtopt
argument_list|(
literal|" TOWER1"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TOWER1 */
ifdef|#
directive|ifdef
name|UTEK
name|prtopt
argument_list|(
literal|" UTEK"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* UTEK */
ifdef|#
directive|ifdef
name|ZILOG
name|prtopt
argument_list|(
literal|" ZILOG"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ZILOG */
ifdef|#
directive|ifdef
name|TRS16
name|prtopt
argument_list|(
literal|" TRS16"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TRS16 */
ifdef|#
directive|ifdef
name|MINIX
name|prtopt
argument_list|(
literal|" MINIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MINIX */
ifdef|#
directive|ifdef
name|C70
name|prtopt
argument_list|(
literal|" C70"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* C70 */
ifdef|#
directive|ifdef
name|AIXPS2
name|prtopt
argument_list|(
literal|" AIXPS2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* AIXPS2 */
ifdef|#
directive|ifdef
name|AIXRS
name|prtopt
argument_list|(
literal|" AIXRS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* AIXRS */
ifdef|#
directive|ifdef
name|UTSV
name|prtopt
argument_list|(
literal|" UTSV"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* UTSV */
ifdef|#
directive|ifdef
name|ATTSV
name|prtopt
argument_list|(
literal|" ATTSV"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ATTSV */
ifdef|#
directive|ifdef
name|SVR3
name|prtopt
argument_list|(
literal|" SVR3"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SVR3 */
ifdef|#
directive|ifdef
name|SVR4
name|prtopt
argument_list|(
literal|" SVR4"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SVR4 */
ifdef|#
directive|ifdef
name|DELL_SVR4
name|prtopt
argument_list|(
literal|" DELL_SVR4"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DELL_SVR4 */
ifdef|#
directive|ifdef
name|ICL_SVR4
name|prtopt
argument_list|(
literal|" ICL_SVR4"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ICL_SVR4 */
ifdef|#
directive|ifdef
name|OSF
name|prtopt
argument_list|(
literal|" OSF"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OSF */
ifdef|#
directive|ifdef
name|PTX
name|prtopt
argument_list|(
literal|" PTX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PTX */
ifdef|#
directive|ifdef
name|POSIX
name|prtopt
argument_list|(
literal|" POSIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* POSIX */
ifdef|#
directive|ifdef
name|SOLARIS
name|prtopt
argument_list|(
literal|" SOLARIS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SOLARIS */
ifdef|#
directive|ifdef
name|SUNOS4
name|prtopt
argument_list|(
literal|" SUNOS4"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SUNOS4 */
ifdef|#
directive|ifdef
name|SUN4S5
name|prtopt
argument_list|(
literal|" SUN4S5"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SUN4S5 */
ifdef|#
directive|ifdef
name|ENCORE
name|prtopt
argument_list|(
literal|" ENCORE"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ENCORE */
ifdef|#
directive|ifdef
name|ultrix
name|prtopt
argument_list|(
literal|" ultrix"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sxaE50
name|prtopt
argument_list|(
literal|" sxaE50"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mips
name|prtopt
argument_list|(
literal|" mips"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MIPS
name|prtopt
argument_list|(
literal|" MIPS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|vax
name|prtopt
argument_list|(
literal|" vax"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|VAX
name|prtopt
argument_list|(
literal|" VAX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|prtopt
argument_list|(
literal|" sun"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun3
name|prtopt
argument_list|(
literal|" sun3"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun386
name|prtopt
argument_list|(
literal|" sun386"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_SUN
name|prtopt
argument_list|(
literal|" _SUN"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun4
name|prtopt
argument_list|(
literal|" sun4"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sparc
name|prtopt
argument_list|(
literal|" sparc"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NEXT
name|prtopt
argument_list|(
literal|" NEXT"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NeXT
name|prtopt
argument_list|(
literal|" NeXT"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sgi
name|prtopt
argument_list|(
literal|" sgi"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_SYS5
name|prtopt
argument_list|(
literal|" M_SYS5"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__SYSTEM_FIVE
name|prtopt
argument_list|(
literal|" __SYSTEM_FIVE"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sysV
name|prtopt
argument_list|(
literal|" sysV"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_XENIX
comment|/* SCO Xenix V and UNIX/386 */
name|prtopt
argument_list|(
literal|" M_XENIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_UNIX
name|prtopt
argument_list|(
literal|" M_UNIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_I386
name|prtopt
argument_list|(
literal|" M_I386"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_M_I386
name|prtopt
argument_list|(
literal|" _M_I386"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|i386
name|prtopt
argument_list|(
literal|" i386"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|i286
name|prtopt
argument_list|(
literal|" i286"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_I286
name|prtopt
argument_list|(
literal|" M_I286"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mc68000
name|prtopt
argument_list|(
literal|" mc68000"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mc68010
name|prtopt
argument_list|(
literal|" mc68010"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mc68020
name|prtopt
argument_list|(
literal|" mc68020"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mc68030
name|prtopt
argument_list|(
literal|" mc68030"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mc68040
name|prtopt
argument_list|(
literal|" mc68040"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_68000
name|prtopt
argument_list|(
literal|" M_68000"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_68010
name|prtopt
argument_list|(
literal|" M_68010"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_68020
name|prtopt
argument_list|(
literal|" M_68020"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_68030
name|prtopt
argument_list|(
literal|" M_68030"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M_68040
name|prtopt
argument_list|(
literal|" M_68040"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|m68k
name|prtopt
argument_list|(
literal|" m68k"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|m88k
name|prtopt
argument_list|(
literal|" m88k"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|pdp11
name|prtopt
argument_list|(
literal|" pdp11"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|iAPX
name|prtopt
argument_list|(
literal|" iAPX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__hp9000s800
name|prtopt
argument_list|(
literal|" __hp9000s800"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__hp9000s500
name|prtopt
argument_list|(
literal|" __hp9000s500"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__hp9000s300
name|prtopt
argument_list|(
literal|" __hp9000s300"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__hp9000s200
name|prtopt
argument_list|(
literal|" __hp9000s200"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|AIX
name|prtopt
argument_list|(
literal|" AIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_AIXFS
name|prtopt
argument_list|(
literal|" _AIXFS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|u370
name|prtopt
argument_list|(
literal|" u370"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|u3b
name|prtopt
argument_list|(
literal|" u3b"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|u3b2
name|prtopt
argument_list|(
literal|" u3b2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|multimax
name|prtopt
argument_list|(
literal|" multimax"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|balance
name|prtopt
argument_list|(
literal|" balance"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ibmrt
name|prtopt
argument_list|(
literal|" ibmrt"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_IBMRT
name|prtopt
argument_list|(
literal|" _IBMRT"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ibmrs6000
name|prtopt
argument_list|(
literal|" ibmrs6000"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_AIX
name|prtopt
argument_list|(
literal|" _AIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _AIX */
ifdef|#
directive|ifdef
name|_IBMR2
name|prtopt
argument_list|(
literal|" _IBMR2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__STRICT_BSD__
name|prtopt
argument_list|(
literal|" __STRICT_BSD__"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__STRICT_ANSI__
name|prtopt
argument_list|(
literal|" __STRICT_ANSI__"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_ANSI_C_SOURCE
name|prtopt
argument_list|(
literal|" _ANSI_C_SOURCE"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__STDC__
name|prtopt
argument_list|(
literal|" __STDC__"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__GNUC__
comment|/* gcc in ansi mode */
name|prtopt
argument_list|(
literal|" __GNUC__"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|GNUC
comment|/* gcc in traditional mode */
name|prtopt
argument_list|(
literal|" GNUC"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CK_ANSIC
name|prtopt
argument_list|(
literal|" CK_ANSIC"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CK_ANSILIBS
name|prtopt
argument_list|(
literal|" CK_ANSILIBS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_XOPEN_SOURCE
name|prtopt
argument_list|(
literal|" _XOPEN_SOURCE"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_ALL_SOURCE
name|prtopt
argument_list|(
literal|" _ALL_SOURCE"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_SC_JOB_CONTROL
name|prtopt
argument_list|(
literal|" _SC_JOB_CONTROL"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_POSIX_JOB_CONTROL
name|prtopt
argument_list|(
literal|" _POSIX_JOB_CONTROL"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SVR3JC
name|prtopt
argument_list|(
literal|" SVR3JC"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_386BSD
name|prtopt
argument_list|(
literal|" _386BSD"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_BSD
name|prtopt
argument_list|(
literal|" _BSD"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TERMIOX
name|prtopt
argument_list|(
literal|" TERMIOX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TERMIOX */
ifdef|#
directive|ifdef
name|STERMIOX
name|prtopt
argument_list|(
literal|" STERMIOX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* STERMIOX */
ifdef|#
directive|ifdef
name|CK_CURSES
name|prtopt
argument_list|(
literal|" CK_CURSES"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CK_CURSES */
ifdef|#
directive|ifdef
name|CK_DTRCD
name|prtopt
argument_list|(
literal|" CK_DTRCD"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CK_DTRCD */
ifdef|#
directive|ifdef
name|CK_DTRCTS
name|prtopt
argument_list|(
literal|" CK_DTRCTS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CK_DTRCTS */
ifdef|#
directive|ifdef
name|CK_RTSCTS
name|prtopt
argument_list|(
literal|" CK_RTSCTS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CK_RTSCTS */
name|prtopt
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOFRILLS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSHOW */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_function
name|int
name|sholbl
parameter_list|()
block|{
name|printf
argument_list|(
literal|"VMS Labeled File Features:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" acl %s (ACL info %s)\n"
argument_list|,
name|lf_opts
operator|&
name|LBL_ACL
condition|?
literal|"on "
else|:
literal|"off"
argument_list|,
name|lf_opts
operator|&
name|LBL_ACL
condition|?
literal|"preserved"
else|:
literal|"discarded"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" backup-date %s (backup date/time %s)\n"
argument_list|,
name|lf_opts
operator|&
name|LBL_BCK
condition|?
literal|"on "
else|:
literal|"off"
argument_list|,
name|lf_opts
operator|&
name|LBL_BCK
condition|?
literal|"preserved"
else|:
literal|"discarded"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" name %s (original filename %s)\n"
argument_list|,
name|lf_opts
operator|&
name|LBL_NAM
condition|?
literal|"on "
else|:
literal|"off"
argument_list|,
name|lf_opts
operator|&
name|LBL_NAM
condition|?
literal|"preserved"
else|:
literal|"discarded"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" owner %s (original file owner id %s)\n"
argument_list|,
name|lf_opts
operator|&
name|LBL_OWN
condition|?
literal|"on "
else|:
literal|"off"
argument_list|,
name|lf_opts
operator|&
name|LBL_OWN
condition|?
literal|"preserved"
else|:
literal|"discarded"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" path %s (original file's disk:[directory] %s)\n"
argument_list|,
name|lf_opts
operator|&
name|LBL_PTH
condition|?
literal|"on "
else|:
literal|"off"
argument_list|,
name|lf_opts
operator|&
name|LBL_PTH
condition|?
literal|"preserved"
else|:
literal|"discarded"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSHOW
end_ifndef

begin_function
name|VOID
name|shotcs
parameter_list|(
name|cs1
parameter_list|,
name|cs2
parameter_list|)
name|int
name|cs1
decl_stmt|,
name|cs2
decl_stmt|;
block|{
comment|/* Show terminal character set */
ifndef|#
directive|ifndef
name|NOCSETS
ifndef|#
directive|ifndef
name|MAC
name|int
name|y
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|CK_ANSIC
name|int
name|gettcs
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|;
else|#
directive|else
name|int
name|gettcs
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* CK_ANSIC */
name|printf
argument_list|(
literal|" Terminal character-set"
argument_list|)
expr_stmt|;
if|if
condition|(
name|cs1
operator|==
name|cs2
condition|)
block|{
name|printf
argument_list|(
literal|": transparent\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|s
operator|=
literal|"unknown"
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<=
name|nfilc
condition|;
name|y
operator|++
control|)
comment|/* Look up name in keyword table */
if|if
condition|(
name|ttcstab
index|[
name|y
index|]
operator|.
name|kwval
operator|==
name|cs2
condition|)
block|{
if|if
condition|(
name|ttcstab
index|[
name|y
index|]
operator|.
name|flgs
operator|&
name|CM_INV
condition|)
comment|/* Skip synonyms */
continue|continue;
name|s
operator|=
name|ttcstab
index|[
name|y
index|]
operator|.
name|kwd
expr_stmt|;
break|break;
block|}
name|printf
argument_list|(
literal|"s:\n   Remote: %s\n   Local:  "
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|s
operator|=
literal|"unknown"
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<=
name|nfilc
condition|;
name|y
operator|++
control|)
if|if
condition|(
name|ttcstab
index|[
name|y
index|]
operator|.
name|kwval
operator|==
name|cs1
condition|)
block|{
if|if
condition|(
name|ttcstab
index|[
name|y
index|]
operator|.
name|flgs
operator|&
name|CM_INV
condition|)
comment|/* Skip synonyms */
continue|continue;
name|s
operator|=
name|ttcstab
index|[
name|y
index|]
operator|.
name|kwd
expr_stmt|;
break|break;
block|}
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|cs2
operator|!=
name|cs1
condition|)
block|{
switch|switch
condition|(
name|gettcs
argument_list|(
name|cs2
argument_list|,
name|cs1
argument_list|)
condition|)
block|{
case|case
name|TC_USASCII
case|:
name|s
operator|=
literal|"ascii"
expr_stmt|;
break|break;
case|case
name|TC_1LATIN
case|:
name|s
operator|=
literal|"latin1-iso"
expr_stmt|;
break|break;
case|case
name|TC_2LATIN
case|:
name|s
operator|=
literal|"latin2-iso"
expr_stmt|;
break|break;
case|case
name|TC_CYRILL
case|:
name|s
operator|=
literal|"cyrillic-iso"
expr_stmt|;
break|break;
case|case
name|TC_JEUC
case|:
name|s
operator|=
literal|"japanese-euc"
expr_stmt|;
break|break;
default|default:
name|s
operator|=
literal|"transparent"
expr_stmt|;
break|break;
block|}
name|printf
argument_list|(
literal|"\n   Via:    %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* MAC */
endif|#
directive|endif
comment|/* NOCSETS */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSHOW */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSHOW
end_ifndef

begin_function
name|int
name|doshow
parameter_list|(
name|x
parameter_list|)
name|int
name|x
decl_stmt|;
block|{
name|int
name|y
decl_stmt|,
name|i
decl_stmt|;
name|long
name|zz
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
ifndef|#
directive|ifndef
name|NOSETKEY
if|if
condition|(
name|x
operator|==
name|SHKEY
condition|)
block|{
comment|/* SHOW KEY */
name|int
name|c
decl_stmt|;
name|KEY
name|ch
decl_stmt|;
name|CHAR
modifier|*
name|s
decl_stmt|;
if|if
condition|(
operator|(
name|y
operator|=
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|y
operator|)
return|;
ifdef|#
directive|ifdef
name|MAC
name|printf
argument_list|(
literal|"Not implemented\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
comment|/* Not MAC */
name|printf
argument_list|(
literal|" Press key: "
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|UNIX
ifdef|#
directive|ifdef
name|NOSETBUF
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSETBUF */
endif|#
directive|endif
comment|/* UNIX */
name|conbin
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* Put terminal in binary mode */
name|c
operator|=
name|congks
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Get character or scan code */
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* Restore terminal to cbreak mode */
if|if
condition|(
name|c
operator|<
literal|0
condition|)
block|{
comment|/* Check for error */
name|printf
argument_list|(
literal|"?Error reading key\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
ifndef|#
directive|ifndef
name|OS2
comment|/*   Do NOT mask when it can be a raw scan code, perhaps> 255 */
name|c
operator|&=
name|cmdmsk
expr_stmt|;
comment|/* Apply command mask */
endif|#
directive|endif
comment|/* OS2 */
name|printf
argument_list|(
literal|"\n Key code \\%d => "
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|macrotab
index|[
name|c
index|]
condition|)
block|{
comment|/* See if there's a macro */
name|printf
argument_list|(
literal|"String: "
argument_list|)
expr_stmt|;
comment|/* If so, display its definition */
name|s
operator|=
name|macrotab
index|[
name|c
index|]
expr_stmt|;
while|while
condition|(
name|ch
operator|=
operator|*
name|s
operator|++
condition|)
if|if
condition|(
name|ch
operator|<
literal|32
operator|||
name|ch
operator|==
literal|127
comment|/*   Systems whose native character sets have graphic characters in C1... */
ifndef|#
directive|ifndef
name|NEXT
comment|/* NeXT */
ifndef|#
directive|ifndef
name|AUX
comment|/* Macintosh */
ifndef|#
directive|ifndef
name|XENIX
comment|/* IBM PC */
ifndef|#
directive|ifndef
name|OS2
comment|/* IBM PC */
operator|||
operator|(
name|ch
operator|>
literal|127
operator|&&
name|ch
operator|<
literal|160
operator|)
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* XENIX */
endif|#
directive|endif
comment|/* AUX */
endif|#
directive|endif
comment|/* NEXT */
condition|)
name|printf
argument_list|(
literal|"\\{%d}"
argument_list|,
name|ch
argument_list|)
expr_stmt|;
comment|/* Display control characters */
else|else
name|putchar
argument_list|(
operator|(
name|char
operator|)
name|ch
argument_list|)
expr_stmt|;
comment|/* in backslash notation */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* No macro, show single character */
name|printf
argument_list|(
literal|"Character: "
argument_list|)
expr_stmt|;
name|ch
operator|=
name|keymap
index|[
name|c
index|]
expr_stmt|;
if|if
condition|(
name|ch
operator|<
literal|32
operator|||
name|ch
operator|==
literal|127
operator|||
name|ch
operator|>
literal|255
ifndef|#
directive|ifndef
name|NEXT
ifndef|#
directive|ifndef
name|AUX
ifndef|#
directive|ifndef
name|XENIX
ifndef|#
directive|ifndef
name|OS2
operator|||
operator|(
name|ch
operator|>
literal|127
operator|&&
name|ch
operator|<
literal|160
operator|)
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* XENIX */
endif|#
directive|endif
comment|/* AUX */
endif|#
directive|endif
comment|/* NEXT */
condition|)
name|printf
argument_list|(
literal|"\\%d"
argument_list|,
operator|(
name|unsigned
name|int
operator|)
name|ch
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%c \\%d"
argument_list|,
name|ch
argument_list|,
operator|(
name|unsigned
name|int
operator|)
name|ch
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ch
operator|==
operator|(
name|KEY
operator|)
name|c
condition|)
name|printf
argument_list|(
literal|" (self, no translation)\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* MAC */
block|}
endif|#
directive|endif
comment|/* NOSETKEY */
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|x
operator|==
name|SHMAC
condition|)
block|{
comment|/* SHOW MACRO */
name|x
operator|=
name|cmfld
argument_list|(
literal|"Macro name, or carriage return to see them all"
argument_list|,
literal|""
argument_list|,
operator|&
name|s
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
operator|-
literal|3
condition|)
comment|/* This means they want see all */
operator|*
name|line
operator|=
literal|'\0'
expr_stmt|;
elseif|else
if|if
condition|(
name|x
operator|<
literal|0
condition|)
comment|/* Otherwise negative = parse error */
return|return
operator|(
name|x
operator|)
return|;
else|else
comment|/* 0 or greater */
name|strcpy
argument_list|(
name|line
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|/* means they typed something */
if|if
condition|(
operator|(
name|y
operator|=
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|y
operator|)
return|;
comment|/* Get confirmation */
if|if
condition|(
operator|*
name|line
condition|)
block|{
name|slc
operator|=
literal|0
expr_stmt|;
comment|/* Initial SHO MAC line number */
name|x
operator|=
name|mlook
argument_list|(
name|mactab
argument_list|,
name|s
argument_list|,
name|nmac
argument_list|)
expr_stmt|;
comment|/* Look up what they typed */
switch|switch
condition|(
name|x
condition|)
block|{
case|case
operator|-
literal|3
case|:
comment|/* Nothing to look up */
return|return
operator|(
literal|0
operator|)
return|;
case|case
operator|-
literal|1
case|:
comment|/* Not found */
name|printf
argument_list|(
literal|"%s - not found\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
operator|-
literal|2
case|:
comment|/* Ambiguous, matches more than one */
name|y
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|line
argument_list|)
expr_stmt|;
name|slc
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<
name|nmac
condition|;
name|x
operator|++
control|)
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|mactab
index|[
name|x
index|]
operator|.
name|kwd
argument_list|,
name|line
argument_list|,
name|y
argument_list|)
condition|)
if|if
condition|(
name|shomac
argument_list|(
name|mactab
index|[
name|x
index|]
operator|.
name|kwd
argument_list|,
name|mactab
index|[
name|x
index|]
operator|.
name|mval
argument_list|)
operator|<
literal|0
condition|)
break|break;
return|return
operator|(
literal|1
operator|)
return|;
default|default:
comment|/* Matches one exactly */
name|shomac
argument_list|(
name|mactab
index|[
name|x
index|]
operator|.
name|kwd
argument_list|,
name|mactab
index|[
name|x
index|]
operator|.
name|mval
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
else|else
block|{
comment|/* They want to see them all */
name|printf
argument_list|(
literal|"Macros:\n"
argument_list|)
expr_stmt|;
name|slc
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
name|nmac
condition|;
name|y
operator|++
control|)
if|if
condition|(
name|shomac
argument_list|(
name|mactab
index|[
name|y
index|]
operator|.
name|kwd
argument_list|,
name|mactab
index|[
name|y
index|]
operator|.
name|mval
argument_list|)
operator|<
literal|0
condition|)
break|break;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
endif|#
directive|endif
comment|/* NOSPL */
comment|/*   Other SHOW commands only have two fields.  Get command confirmation here,   then handle with big switch() statement. */
if|if
condition|(
operator|(
name|y
operator|=
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|y
operator|)
return|;
switch|switch
condition|(
name|x
condition|)
block|{
ifdef|#
directive|ifdef
name|SUNX25
case|case
name|SHPAD
case|:
name|shopad
argument_list|()
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* SUNX25 */
ifdef|#
directive|ifdef
name|NETCONN
case|case
name|SHNET
case|:
name|shonet
argument_list|()
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NETCONN */
case|case
name|SHPAR
case|:
name|shopar
argument_list|()
expr_stmt|;
break|break;
case|case
name|SHATT
case|:
name|shoatt
argument_list|()
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|SHCOU
case|:
name|printf
argument_list|(
literal|" %d\n"
argument_list|,
name|count
index|[
name|cmdlvl
index|]
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOSERVER
case|case
name|SHSER
case|:
comment|/* Show Server */
ifndef|#
directive|ifndef
name|NOFRILLS
name|printf
argument_list|(
literal|"Function           Status:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" GET                %s\n"
argument_list|,
name|nm
index|[
name|en_get
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" SEND               %s\n"
argument_list|,
name|nm
index|[
name|en_sen
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" REMOTE CD/CWD      %s\n"
argument_list|,
name|nm
index|[
name|en_cwd
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" REMOTE DELETE      %s\n"
argument_list|,
name|nm
index|[
name|en_del
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" REMOTE DIRECTORY   %s\n"
argument_list|,
name|nm
index|[
name|en_dir
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" REMOTE HOST        %s\n"
argument_list|,
name|nm
index|[
name|en_hos
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" REMOTE SET         %s\n"
argument_list|,
name|nm
index|[
name|en_set
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" REMOTE SPACE       %s\n"
argument_list|,
name|nm
index|[
name|en_spa
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" REMOTE TYPE        %s\n"
argument_list|,
name|nm
index|[
name|en_typ
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" REMOTE WHO         %s\n"
argument_list|,
name|nm
index|[
name|en_who
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" BYE                %s\n"
argument_list|,
name|nm
index|[
name|en_bye
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" FINISH             %s\n"
argument_list|,
name|nm
index|[
name|en_fin
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOFRILLS */
name|printf
argument_list|(
literal|"Server timeout: %d\n"
argument_list|,
name|srvtim
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Server display: %s\n\n"
argument_list|,
name|srvdis
condition|?
literal|"on"
else|:
literal|"off"
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NOSERVER */
case|case
name|SHSTA
case|:
comment|/* Status of last command */
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|success
condition|?
literal|"SUCCESS"
else|:
literal|"FAILURE"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Don't change it */
ifdef|#
directive|ifdef
name|MAC
case|case
name|SHSTK
case|:
block|{
comment|/* Stack for MAC debugging */
name|long
name|sp
decl_stmt|;
name|sp
operator|=
operator|-
literal|1
expr_stmt|;
name|loadA0
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|sp
argument_list|)
expr_stmt|;
comment|/* set destination address */
name|SPtoaA0
argument_list|()
expr_stmt|;
comment|/* move SP to destination */
name|printf
argument_list|(
literal|"Stack at 0x%x\n"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
name|show_queue
argument_list|()
expr_stmt|;
comment|/* more debugging */
break|break;
block|}
endif|#
directive|endif
comment|/* MAC */
case|case
name|SHTER
case|:
name|printf
argument_list|(
literal|" Command bytesize:  %d bits\n"
argument_list|,
operator|(
name|cmdmsk
operator|==
literal|0377
operator|)
condition|?
literal|8
else|:
literal|7
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Terminal bytesize: %d bits\n"
argument_list|,
operator|(
name|cmask
operator|==
literal|0377
operator|)
condition|?
literal|8
else|:
literal|7
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
name|printf
argument_list|(
literal|" Terminal type: %s\n"
argument_list|,
operator|(
name|tt_type
operator|==
name|TT_VT102
operator|)
condition|?
literal|"VT102"
else|:
literal|"VT52"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
name|printf
argument_list|(
literal|" Terminal echo: %s\n"
argument_list|,
name|duplex
condition|?
literal|"local"
else|:
literal|"remote"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Terminal locking-shift: %s\n"
argument_list|,
name|sosi
condition|?
literal|"on"
else|:
literal|"off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Terminal newline-mode:  %s\n"
argument_list|,
name|tnlm
condition|?
literal|"on"
else|:
literal|"off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Terminal cr-display:    %s\n"
argument_list|,
name|tt_crd
condition|?
literal|"crlf"
else|:
literal|"normal"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
comment|/* Should show cursor and colors here too... */
name|printf
argument_list|(
literal|" Terminal arrow-keys:    %s\n"
argument_list|,
name|tt_arrow
condition|?
literal|"cursor"
else|:
literal|"application"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Terminal keypad-mode:   %s\n"
argument_list|,
name|tt_keypad
condition|?
literal|"numeric"
else|:
literal|"application"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Terminal wrap:          %s\n"
argument_list|,
name|tt_wrap
condition|?
literal|"on"
else|:
literal|"off"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
ifndef|#
directive|ifndef
name|NOCSETS
name|shotcs
argument_list|(
name|tcsl
argument_list|,
name|tcsr
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCSETS */
name|printf
argument_list|(
literal|" CONNECT-mode escape character: %d (Ctrl-%c, %s)\n"
argument_list|,
name|escape
argument_list|,
name|ctl
argument_list|(
name|escape
argument_list|)
argument_list|,
operator|(
name|escape
operator|==
literal|127
condition|?
literal|"DEL"
else|:
name|ccntab
index|[
name|escape
index|]
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|UNIX
name|printf
argument_list|(
literal|" Suspend: %s\n"
argument_list|,
name|suspend
condition|?
literal|"on"
else|:
literal|"off"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* UNIX */
break|break;
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|SHVER
case|:
name|shover
argument_list|()
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NOFRILLS */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|SHBUI
case|:
comment|/* Built-in variables */
name|i
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
name|nvars
condition|;
name|y
operator|++
control|)
block|{
name|printf
argument_list|(
literal|" \\v(%s) = %s\n"
argument_list|,
name|vartab
index|[
name|y
index|]
operator|.
name|kwd
argument_list|,
name|nvlook
argument_list|(
name|vartab
index|[
name|y
index|]
operator|.
name|kwd
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|i
operator|>
name|SCRNLEN
condition|)
block|{
comment|/* More than a screenful... */
if|if
condition|(
operator|!
name|askmore
argument_list|()
condition|)
break|break;
else|else
name|i
operator|=
literal|0
expr_stmt|;
block|}
block|}
break|break;
case|case
name|SHFUN
case|:
comment|/* Functions */
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
name|nfuncs
condition|;
name|y
operator|++
control|)
name|printf
argument_list|(
literal|" \\f%s()\n"
argument_list|,
name|fnctab
index|[
name|y
index|]
operator|.
name|kwd
argument_list|)
expr_stmt|;
break|break;
case|case
name|SHVAR
case|:
comment|/* Global variables */
name|x
operator|=
literal|0
expr_stmt|;
comment|/* Variable count */
name|slc
operator|=
literal|1
expr_stmt|;
comment|/* Screen line count for "more?" */
for|for
control|(
name|y
operator|=
literal|33
init|;
name|y
operator|<
name|GVARS
condition|;
name|y
operator|++
control|)
if|if
condition|(
name|g_var
index|[
name|y
index|]
condition|)
block|{
if|if
condition|(
name|x
operator|++
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"Global variables:\n"
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|line
argument_list|,
literal|" \\%%%c"
argument_list|,
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|shomac
argument_list|(
name|line
argument_list|,
name|g_var
index|[
name|y
index|]
argument_list|)
operator|<
literal|0
condition|)
break|break;
block|}
if|if
condition|(
operator|!
name|x
condition|)
name|printf
argument_list|(
literal|" No variables defined\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SHARG
case|:
comment|/* Args */
if|if
condition|(
name|maclvl
operator|>
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Macro arguments at level %d\n"
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
literal|10
condition|;
name|y
operator|++
control|)
if|if
condition|(
name|m_arg
index|[
name|maclvl
index|]
index|[
name|y
index|]
condition|)
name|printf
argument_list|(
literal|" \\%%%d = %s\n"
argument_list|,
name|y
argument_list|,
name|m_arg
index|[
name|maclvl
index|]
index|[
name|y
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|" No macro arguments at top level\n"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|SHARR
case|:
comment|/* Arrays */
name|x
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
literal|27
condition|;
name|y
operator|++
control|)
if|if
condition|(
name|a_ptr
index|[
name|y
index|]
condition|)
block|{
if|if
condition|(
name|x
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"Declared arrays:\n"
argument_list|)
expr_stmt|;
name|x
operator|=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|" \\&%c[%d]\n"
argument_list|,
operator|(
name|y
operator|==
literal|0
operator|)
condition|?
literal|64
else|:
name|y
operator|+
literal|96
argument_list|,
name|a_dim
index|[
name|y
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|x
condition|)
name|printf
argument_list|(
literal|" No arrays declared\n"
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NOSPL */
case|case
name|SHPRO
case|:
comment|/* Protocol parameters */
name|shoparp
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SHCOM
case|:
comment|/* Communication parameters */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|shoparc
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|NODIAL
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
operator|!
name|network
condition|)
endif|#
directive|endif
comment|/* NETCONN */
name|shodial
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* NODIAL */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|shomdm
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SHFIL
case|:
comment|/* File parameters */
name|shoparf
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|NOCSETS
case|case
name|SHLNG
case|:
comment|/* Languages */
name|shoparl
argument_list|()
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NOCSETS */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|SHSCR
case|:
comment|/* Scripts */
name|printf
argument_list|(
literal|" Take  Echo:     %s\n"
argument_list|,
name|techo
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Take  Error:    %s\n"
argument_list|,
name|terror
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Macro Echo:     %s\n"
argument_list|,
name|mecho
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Macro Error:    %s\n"
argument_list|,
name|merror
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Input Case:     %s\n"
argument_list|,
name|incase
condition|?
literal|"Observe"
else|:
literal|"Ignore"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Input Echo:     %s\n"
argument_list|,
name|inecho
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Input Silence:  %d\n"
argument_list|,
name|insilence
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Input Timeout:  %s\n"
argument_list|,
name|intime
condition|?
literal|"Quit"
else|:
literal|"Proceed"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOSCRIPT
name|printf
argument_list|(
literal|" Script Echo:    %s\n"
argument_list|,
name|secho
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSCRIPT */
break|break;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOXMIT
case|case
name|SHXMI
case|:
name|printf
argument_list|(
literal|" File type: %s\n"
argument_list|,
name|binary
condition|?
literal|"binary"
else|:
literal|"text"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOCSETS
name|shotcs
argument_list|(
name|tcsl
argument_list|,
name|tcsr
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCSETS */
name|printf
argument_list|(
literal|" Terminal echo: %s\n"
argument_list|,
name|duplex
condition|?
literal|"local"
else|:
literal|"remote"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Transmit EOF: "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|xmitbuf
operator|==
name|NUL
condition|)
block|{
name|printf
argument_list|(
literal|"none\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|xmitbuf
expr_stmt|;
while|while
condition|(
operator|*
name|p
condition|)
block|{
if|if
condition|(
operator|*
name|p
operator|<
name|SP
condition|)
name|printf
argument_list|(
literal|"^%c"
argument_list|,
name|ctl
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%c"
argument_list|,
operator|*
name|p
argument_list|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|xmitf
condition|)
name|printf
argument_list|(
literal|" Transmit Fill: %d (fill character for blank lines)\n"
argument_list|,
name|xmitf
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" Transmit Fill: none\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Transmit Linefeed: %s\n"
argument_list|,
name|xmitl
condition|?
literal|"on (send linefeeds too)"
else|:
literal|"off"
argument_list|)
expr_stmt|;
if|if
condition|(
name|xmitp
condition|)
name|printf
argument_list|(
literal|" Transmit Prompt: %d (host line end character)\n"
argument_list|,
name|xmitp
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" Transmit Prompt: none\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Transmit Echo: %s\n"
argument_list|,
name|xmitx
condition|?
literal|"on"
else|:
literal|"off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Transmit Locking-Shift: %s\n"
argument_list|,
name|xmits
condition|?
literal|"on"
else|:
literal|"off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Transmit Pause: %d milliseconds\n"
argument_list|,
name|xmitw
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NOXMIT */
case|case
name|SHMOD
case|:
comment|/* SHOW MODEM */
name|shmdmlin
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|shomdm
argument_list|()
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|MAC
case|case
name|SHDFLT
case|:
name|zsyscmd
argument_list|(
name|PWDCMD
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* MAC */
case|case
name|SHESC
case|:
name|printf
argument_list|(
literal|" Escape character: Ctrl-%c (ASCII %d, %s)\r\n"
argument_list|,
name|ctl
argument_list|(
name|escape
argument_list|)
argument_list|,
name|escape
argument_list|,
operator|(
name|escape
operator|==
literal|127
condition|?
literal|"DEL"
else|:
name|ccntab
index|[
name|escape
index|]
operator|)
argument_list|)
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|NODIAL
case|case
name|SHDIA
case|:
name|shmdmlin
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|", speed: "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|zz
operator|=
name|ttgspd
argument_list|()
operator|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"unknown\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|zz
operator|==
literal|8880
condition|)
name|printf
argument_list|(
literal|"75/1200\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%ld\n"
argument_list|,
name|zz
argument_list|)
expr_stmt|;
block|}
name|doshodial
argument_list|()
expr_stmt|;
if|if
condition|(
name|carrier
operator|==
name|CAR_OFF
condition|)
name|s
operator|=
literal|"off"
expr_stmt|;
elseif|else
if|if
condition|(
name|carrier
operator|==
name|CAR_ON
condition|)
name|s
operator|=
literal|"on"
expr_stmt|;
elseif|else
if|if
condition|(
name|carrier
operator|==
name|CAR_AUT
condition|)
name|s
operator|=
literal|"auto"
expr_stmt|;
else|else
name|s
operator|=
literal|"unknown"
expr_stmt|;
name|printf
argument_list|(
literal|" Carrier: %s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|carrier
operator|==
name|CAR_ON
condition|)
block|{
if|if
condition|(
name|cdtimo
condition|)
name|printf
argument_list|(
literal|", timeout: %d sec"
argument_list|,
name|cdtimo
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|", timeout: none"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|local
ifdef|#
directive|ifdef
name|NETCONN
operator|&&
operator|!
name|network
endif|#
directive|endif
comment|/* NETCONN */
condition|)
block|{
name|printf
argument_list|(
literal|"\n%s modem signals:\n"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
name|shomdm
argument_list|()
expr_stmt|;
block|}
else|else
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NODIAL */
ifdef|#
directive|ifdef
name|VMS
case|case
name|SHLBL
case|:
comment|/* Labeled file info */
name|sholbl
argument_list|()
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* VMS */
case|case
name|SHCSE
case|:
comment|/* Character sets */
ifdef|#
directive|ifdef
name|NOCSETS
name|printf
argument_list|(
literal|" Character set translation is not supported in this version of C-Kermit\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|shocharset
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\n Unknown-Char-Set: %s\n"
argument_list|,
name|unkcs
condition|?
literal|"Keep"
else|:
literal|"Discard"
argument_list|)
expr_stmt|;
name|shotcs
argument_list|(
name|tcsl
argument_list|,
name|tcsr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCSETS */
break|break;
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|SHFEA
case|:
comment|/* Features */
name|shofea
argument_list|()
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* NOFRILLS */
default|default:
name|printf
argument_list|(
literal|"\nNothing to show...\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
return|return
operator|(
name|success
operator|=
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|VOID
name|shmdmlin
parameter_list|()
block|{
comment|/* Briefly show modem& line */
name|int
name|i
decl_stmt|;
ifndef|#
directive|ifndef
name|NODIAL
ifndef|#
directive|ifndef
name|MINIDIAL
specifier|extern
name|int
name|tbmodel
decl_stmt|;
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|gtbmodel
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MINIDIAL */
endif|#
directive|endif
comment|/* NODIAL */
if|if
condition|(
name|local
condition|)
name|printf
argument_list|(
literal|" Line: %s, Modem: "
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" Communication device not yet selected with SET LINE\n Modem: "
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NODIAL
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nmdm
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|mdmtab
index|[
name|i
index|]
operator|.
name|kwval
operator|==
name|mdmtyp
condition|)
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|mdmtab
index|[
name|i
index|]
operator|.
name|kwd
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
ifndef|#
directive|ifndef
name|MINIDIAL
if|if
condition|(
name|tbmodel
condition|)
name|printf
argument_list|(
literal|" (%s)"
argument_list|,
name|gtbmodel
argument_list|()
argument_list|)
expr_stmt|;
comment|/* Telebit model info */
endif|#
directive|endif
comment|/* MINIDIAL */
else|#
directive|else
name|printf
argument_list|(
literal|"(disabled)"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NODIAL */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSHOW */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_macro
name|isxdigit
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|isdigit
argument_list|(
name|c
argument_list|)
operator|||
operator|(
name|c
operator|>=
literal|'a'
operator|&&
name|c
operator|<=
literal|'f'
operator|)
operator|||
operator|(
name|c
operator|>=
literal|'A'
operator|&&
name|c
operator|<=
literal|'F'
operator|)
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSHOW
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_function
name|int
comment|/* SHO MACROS */
name|shomac
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
name|int
name|x
decl_stmt|,
name|n
decl_stmt|,
name|pp
decl_stmt|;
name|pp
operator|=
literal|0
expr_stmt|;
comment|/* Parenthesis counter */
if|if
condition|(
operator|!
name|s1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
name|printf
argument_list|(
literal|"\n%s = "
argument_list|,
name|s1
argument_list|)
expr_stmt|;
comment|/* Print blank line and macro name */
name|slc
operator|++
expr_stmt|;
comment|/* Count the line */
name|n
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
literal|4
expr_stmt|;
comment|/* Width of current line */
if|if
condition|(
operator|!
name|s2
condition|)
name|s2
operator|=
literal|"(null definition)"
expr_stmt|;
while|while
condition|(
name|x
operator|=
operator|*
name|s2
operator|++
condition|)
block|{
comment|/* Loop thru definition */
if|if
condition|(
name|x
operator|==
literal|'('
condition|)
name|pp
operator|++
expr_stmt|;
comment|/* Treat commas within parens */
if|if
condition|(
name|x
operator|==
literal|')'
condition|)
name|pp
operator|--
expr_stmt|;
comment|/* as ordinary text */
if|if
condition|(
name|pp
operator|<
literal|0
condition|)
name|pp
operator|=
literal|0
expr_stmt|;
comment|/* Outside parens, */
if|if
condition|(
name|x
operator|==
literal|','
operator|&&
name|pp
operator|==
literal|0
condition|)
block|{
comment|/* comma becomes comma-dash-NL. */
name|putchar
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'-'
argument_list|)
expr_stmt|;
name|x
operator|=
literal|'\n'
expr_stmt|;
block|}
name|putchar
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|/* Output the character */
if|if
condition|(
name|x
operator|==
literal|'\n'
condition|)
block|{
comment|/* If it was a newline */
ifdef|#
directive|ifdef
name|UNIX
ifdef|#
directive|ifdef
name|NOSETBUF
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSETBUF */
endif|#
directive|endif
comment|/* UNIX */
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
comment|/* Indent the next line 1 space */
while|while
condition|(
operator|*
name|s2
operator|==
literal|' '
condition|)
name|s2
operator|++
expr_stmt|;
comment|/* skip past leading blanks */
name|n
operator|=
literal|2
expr_stmt|;
comment|/* restart the character counter */
name|slc
operator|++
expr_stmt|;
comment|/* and increment the line counter. */
block|}
elseif|else
if|if
condition|(
operator|++
name|n
operator|>
name|SCRNWID
condition|)
block|{
comment|/* If line is too wide */
name|putchar
argument_list|(
literal|'-'
argument_list|)
expr_stmt|;
comment|/* output a dash */
name|putchar
argument_list|(
name|NL
argument_list|)
expr_stmt|;
comment|/* and a newline */
ifdef|#
directive|ifdef
name|UNIX
ifdef|#
directive|ifdef
name|NOSETBUF
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSETBUF */
endif|#
directive|endif
comment|/* UNIX */
name|n
operator|=
literal|1
expr_stmt|;
comment|/* and restart the char counter */
name|slc
operator|++
expr_stmt|;
comment|/* and increment the line counter */
block|}
if|if
condition|(
name|n
operator|<
literal|3
operator|&&
name|slc
operator|>
name|SCRNLEN
condition|)
block|{
comment|/* If new line and screen is full */
if|if
condition|(
operator|!
name|askmore
argument_list|()
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* ask if they want more. */
name|n
operator|=
literal|1
expr_stmt|;
comment|/* They do, start a new line */
name|slc
operator|=
literal|0
expr_stmt|;
comment|/* and restart line counter */
block|}
block|}
name|putchar
argument_list|(
name|NL
argument_list|)
expr_stmt|;
comment|/* End of definition */
if|if
condition|(
operator|++
name|slc
operator|>
name|SCRNLEN
condition|)
block|{
if|if
condition|(
operator|!
name|askmore
argument_list|()
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|slc
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSHOW */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSHOW
end_ifndef

begin_function
name|int
name|shoatt
parameter_list|()
block|{
name|printf
argument_list|(
literal|"Attributes: %s\n"
argument_list|,
name|atcapr
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|atcapr
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|printf
argument_list|(
literal|" Blocksize: %s\n"
argument_list|,
name|atblki
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Date: %s\n"
argument_list|,
name|atdati
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Disposition: %s\n"
argument_list|,
name|atdisi
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Encoding (Character Set): %s\n"
argument_list|,
name|atenci
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Length: %s\n"
argument_list|,
name|atleni
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Type (text/binary): %s\n"
argument_list|,
name|attypi
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" System ID: %s\n"
argument_list|,
name|atsidi
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" System Info: %s\n"
argument_list|,
name|atsysi
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSHOW */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/* Evaluate an arithmetic expression. */
end_comment

begin_comment
comment|/* Code adapted from ev, by Howie Kaye of Columbia U& others. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|xerror
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|tokval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|curtok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|expval
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LONGBITS
value|(8*sizeof (long))
end_define

begin_define
define|#
directive|define
name|NUMBER
value|'N'
end_define

begin_define
define|#
directive|define
name|EOT
value|'E'
end_define

begin_comment
comment|/*  Replacement for strchr() and index(), neither of which seem to be universal. */
end_comment

begin_function
specifier|static
name|char
modifier|*
ifdef|#
directive|ifdef
name|CK_ANSIC
name|windex
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|char
name|c
parameter_list|)
else|#
directive|else
function|windex
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|,
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* windex */
block|{
while|while
condition|(
operator|*
name|s
operator|!=
name|NUL
operator|&&
operator|*
name|s
operator|!=
name|c
condition|)
name|s
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
name|c
condition|)
return|return
operator|(
name|s
operator|)
return|;
else|else
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  g e t t o k   Returns the next token.  If token is a NUMBER, sets tokval appropriately. */
end_comment

begin_function
specifier|static
name|char
name|gettok
parameter_list|()
block|{
while|while
condition|(
name|isspace
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
name|cp
operator|++
expr_stmt|;
switch|switch
condition|(
operator|*
name|cp
condition|)
block|{
case|case
literal|'$'
case|:
comment|/* ??? */
case|case
literal|'+'
case|:
comment|/* Add */
case|case
literal|'-'
case|:
comment|/* Subtract or Negate */
case|case
literal|'@'
case|:
comment|/* Greatest Common Divisor */
case|case
literal|'*'
case|:
comment|/* Multiply */
case|case
literal|'/'
case|:
comment|/* Divide */
case|case
literal|'%'
case|:
comment|/* Modulus */
case|case
literal|'<'
case|:
comment|/* Left shift */
case|case
literal|'>'
case|:
comment|/* Right shift */
case|case
literal|'&'
case|:
comment|/* And */
case|case
literal|'|'
case|:
comment|/* Or */
case|case
literal|'#'
case|:
comment|/* Exclusive Or */
case|case
literal|'~'
case|:
comment|/* Not */
case|case
literal|'^'
case|:
comment|/* Exponent */
case|case
literal|'!'
case|:
comment|/* Factorial */
case|case
literal|'('
case|:
comment|/* Parens for grouping */
case|case
literal|')'
case|:
return|return
operator|(
operator|*
name|cp
operator|++
operator|)
return|;
comment|/* operator, just return it */
case|case
literal|'\n'
case|:
case|case
literal|'\0'
case|:
return|return
operator|(
name|EOT
operator|)
return|;
comment|/* end of line, return that */
block|}
if|if
condition|(
name|isxdigit
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
block|{
comment|/* digit, must be a number */
name|char
name|tbuf
index|[
literal|80
index|]
decl_stmt|,
modifier|*
name|tp
decl_stmt|;
comment|/* buffer to accumulate number */
name|int
name|radix
init|=
literal|10
decl_stmt|;
comment|/* default radix */
for|for
control|(
name|tp
operator|=
name|tbuf
init|;
name|isxdigit
argument_list|(
operator|*
name|cp
argument_list|)
condition|;
name|cp
operator|++
control|)
operator|*
name|tp
operator|++
operator|=
name|isupper
argument_list|(
operator|*
name|cp
argument_list|)
condition|?
name|tolower
argument_list|(
operator|*
name|cp
argument_list|)
else|:
operator|*
name|cp
expr_stmt|;
operator|*
name|tp
operator|=
literal|'\0'
expr_stmt|;
comment|/* end number */
switch|switch
condition|(
name|isupper
argument_list|(
operator|*
name|cp
argument_list|)
condition|?
name|tolower
argument_list|(
operator|*
name|cp
argument_list|)
else|:
operator|*
name|cp
condition|)
block|{
comment|/* examine break char */
case|case
literal|'h'
case|:
case|case
literal|'x'
case|:
name|radix
operator|=
literal|16
expr_stmt|;
name|cp
operator|++
expr_stmt|;
break|break;
comment|/* if radix signifier... */
case|case
literal|'o'
case|:
case|case
literal|'q'
case|:
name|radix
operator|=
literal|8
expr_stmt|;
name|cp
operator|++
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
name|radix
operator|=
literal|2
expr_stmt|;
name|cp
operator|++
expr_stmt|;
break|break;
block|}
for|for
control|(
name|tp
operator|=
name|tbuf
operator|,
name|tokval
operator|=
literal|0
init|;
operator|*
name|tp
operator|!=
literal|'\0'
condition|;
name|tp
operator|++
control|)
block|{
name|int
name|dig
decl_stmt|;
name|dig
operator|=
operator|*
name|tp
operator|-
literal|'0'
expr_stmt|;
comment|/* convert number */
if|if
condition|(
name|dig
operator|>
literal|10
condition|)
name|dig
operator|-=
literal|'a'
operator|-
literal|'0'
operator|-
literal|10
expr_stmt|;
if|if
condition|(
name|dig
operator|>=
name|radix
condition|)
block|{
name|xerror
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"invalid digit '%c' in number\n"
argument_list|,
operator|*
name|tp
argument_list|)
expr_stmt|;
return|return
operator|(
name|NUMBER
operator|)
return|;
block|}
name|tokval
operator|=
name|radix
operator|*
name|tokval
operator|+
name|dig
expr_stmt|;
block|}
return|return
operator|(
name|NUMBER
operator|)
return|;
block|}
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"Invalid character '%c' in input\n"
argument_list|,
operator|*
name|cp
argument_list|)
expr_stmt|;
name|xerror
operator|=
literal|1
expr_stmt|;
name|cp
operator|++
expr_stmt|;
return|return
operator|(
name|gettok
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
ifdef|#
directive|ifdef
name|CK_ANSIC
name|expon
parameter_list|(
name|long
name|x
parameter_list|,
name|long
name|y
parameter_list|)
else|#
directive|else
function|expon
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|long
name|x
decl_stmt|,
name|y
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* expon */
block|{
name|long
name|result
init|=
literal|1
decl_stmt|;
name|int
name|sign
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|y
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|x
operator|=
operator|-
name|x
expr_stmt|;
if|if
condition|(
name|y
operator|&
literal|1
condition|)
name|sign
operator|=
operator|-
literal|1
expr_stmt|;
block|}
while|while
condition|(
name|y
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|y
operator|&
literal|1
condition|)
name|result
operator|*=
name|x
expr_stmt|;
name|y
operator|>>=
literal|1
expr_stmt|;
if|if
condition|(
name|y
operator|!=
literal|0
condition|)
name|x
operator|*=
name|x
expr_stmt|;
block|}
return|return
operator|(
name|result
operator|*
name|sign
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * factor ::= simple | simple ^ factor  *  */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|static VOID simple
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|VOID
name|factor
parameter_list|()
block|{
name|long
name|oldval
decl_stmt|;
name|simple
argument_list|()
expr_stmt|;
if|if
condition|(
name|curtok
operator|==
literal|'^'
condition|)
block|{
name|oldval
operator|=
name|expval
expr_stmt|;
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
name|factor
argument_list|()
expr_stmt|;
name|expval
operator|=
name|expon
argument_list|(
name|oldval
argument_list|,
name|expval
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * termp ::= NULL | {*,/,%,&} factor termp  *  */
end_comment

begin_function
specifier|static
name|VOID
name|termp
parameter_list|()
block|{
while|while
condition|(
name|curtok
operator|==
literal|'*'
operator|||
name|curtok
operator|==
literal|'/'
operator|||
name|curtok
operator|==
literal|'%'
operator|||
name|curtok
operator|==
literal|'&'
condition|)
block|{
name|long
name|oldval
decl_stmt|;
name|char
name|op
decl_stmt|;
name|op
operator|=
name|curtok
expr_stmt|;
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
comment|/* skip past operator */
name|oldval
operator|=
name|expval
expr_stmt|;
name|factor
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|op
condition|)
block|{
case|case
literal|'*'
case|:
name|expval
operator|=
name|oldval
operator|*
name|expval
expr_stmt|;
break|break;
case|case
literal|'/'
case|:
if|if
condition|(
name|expval
operator|==
literal|0
condition|)
name|expval
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* don't divide by 0 */
else|else
name|expval
operator|=
name|oldval
operator|/
name|expval
expr_stmt|;
break|break;
case|case
literal|'%'
case|:
name|expval
operator|=
name|oldval
operator|%
name|expval
expr_stmt|;
break|break;
case|case
literal|'&'
case|:
name|expval
operator|=
name|oldval
operator|&
name|expval
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

begin_function
specifier|static
name|long
ifdef|#
directive|ifdef
name|CK_ANSIC
name|fact
parameter_list|(
name|long
name|x
parameter_list|)
else|#
directive|else
function|fact
parameter_list|(
name|x
parameter_list|)
name|long
name|x
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* fact */
block|{
comment|/* factorial */
name|long
name|result
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|x
operator|>
literal|1
condition|)
name|result
operator|*=
name|x
operator|--
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * term ::= factor termp  *  */
end_comment

begin_function
specifier|static
name|VOID
name|term
parameter_list|()
block|{
name|factor
argument_list|()
expr_stmt|;
name|termp
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|long
ifdef|#
directive|ifdef
name|CK_ANSIC
name|gcd
parameter_list|(
name|long
name|x
parameter_list|,
name|long
name|y
parameter_list|)
else|#
directive|else
function|gcd
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|long
name|x
decl_stmt|,
name|y
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* gcd */
block|{
comment|/* Greatest Common Divisor */
name|int
name|nshift
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|x
operator|=
operator|-
name|x
expr_stmt|;
if|if
condition|(
name|y
operator|<
literal|0
condition|)
name|y
operator|=
operator|-
name|y
expr_stmt|;
comment|/* validate arguments */
if|if
condition|(
name|x
operator|==
literal|0
operator|||
name|y
operator|==
literal|0
condition|)
return|return
operator|(
name|x
operator|+
name|y
operator|)
return|;
comment|/* this is bogus */
while|while
condition|(
operator|!
operator|(
operator|(
name|x
operator|&
literal|1
operator|)
operator||
operator|(
name|y
operator|&
literal|1
operator|)
operator|)
condition|)
block|{
comment|/* get rid of powers of 2 */
name|nshift
operator|++
expr_stmt|;
name|x
operator|>>=
literal|1
expr_stmt|;
name|y
operator|>>=
literal|1
expr_stmt|;
block|}
while|while
condition|(
name|x
operator|!=
literal|1
operator|&&
name|y
operator|!=
literal|1
operator|&&
name|x
operator|!=
literal|0
operator|&&
name|y
operator|!=
literal|0
condition|)
block|{
while|while
condition|(
operator|!
operator|(
name|x
operator|&
literal|1
operator|)
condition|)
name|x
operator|>>=
literal|1
expr_stmt|;
comment|/* eliminate unnecessary */
while|while
condition|(
operator|!
operator|(
name|y
operator|&
literal|1
operator|)
condition|)
name|y
operator|>>=
literal|1
expr_stmt|;
comment|/* powers of 2 */
if|if
condition|(
name|x
operator|<
name|y
condition|)
block|{
comment|/* force x to be larger */
name|long
name|t
decl_stmt|;
name|t
operator|=
name|x
expr_stmt|;
name|x
operator|=
name|y
expr_stmt|;
name|y
operator|=
name|t
expr_stmt|;
block|}
name|x
operator|-=
name|y
expr_stmt|;
block|}
if|if
condition|(
name|x
operator|==
literal|0
operator|||
name|y
operator|==
literal|0
condition|)
return|return
operator|(
operator|(
name|x
operator|+
name|y
operator|)
operator|<<
name|nshift
operator|)
return|;
comment|/* gcd is non-zero one */
else|else
return|return
operator|(
operator|(
name|long
operator|)
literal|1
operator|<<
name|nshift
operator|)
return|;
comment|/* else gcd is 1 */
block|}
end_function

begin_comment
comment|/*  * exprp ::= NULL | {+,-,|,...} term exprp  *  */
end_comment

begin_function
specifier|static
name|VOID
name|exprp
parameter_list|()
block|{
while|while
condition|(
name|windex
argument_list|(
literal|"+-|<>#@"
argument_list|,
name|curtok
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|long
name|oldval
decl_stmt|;
name|char
name|op
decl_stmt|;
name|op
operator|=
name|curtok
expr_stmt|;
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
comment|/* skip past operator */
name|oldval
operator|=
name|expval
expr_stmt|;
name|term
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|op
condition|)
block|{
case|case
literal|'+'
case|:
name|expval
operator|=
name|oldval
operator|+
name|expval
expr_stmt|;
break|break;
case|case
literal|'-'
case|:
name|expval
operator|=
name|oldval
operator|-
name|expval
expr_stmt|;
break|break;
case|case
literal|'|'
case|:
name|expval
operator|=
name|oldval
operator||
name|expval
expr_stmt|;
break|break;
case|case
literal|'#'
case|:
name|expval
operator|=
name|oldval
operator|^
name|expval
expr_stmt|;
break|break;
case|case
literal|'@'
case|:
name|expval
operator|=
name|gcd
argument_list|(
name|oldval
argument_list|,
name|expval
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'<'
case|:
name|expval
operator|=
name|oldval
operator|<<
name|expval
expr_stmt|;
break|break;
case|case
literal|'>'
case|:
name|expval
operator|=
name|oldval
operator|>>
name|expval
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

begin_comment
comment|/*  * expr ::= term exprp  *  */
end_comment

begin_function
specifier|static
name|VOID
name|expr
parameter_list|()
block|{
name|term
argument_list|()
expr_stmt|;
name|exprp
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|long
name|xparse
parameter_list|()
block|{
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
name|expr
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
if|if
condition|(
name|curtok
operator|==
literal|'$'
condition|)
block|{
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
if|if
condition|(
name|curtok
operator|!=
name|NUMBER
condition|)
block|{
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"illegal radix\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* COMMENT */
if|if
condition|(
name|curtok
operator|!=
name|EOT
condition|)
block|{
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"extra characters after expression\n"
argument_list|)
expr_stmt|;
name|xerror
operator|=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|expval
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|evala
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
comment|/* Return pointer */
name|long
name|v
decl_stmt|;
comment|/* Numeric value */
name|xerror
operator|=
literal|0
expr_stmt|;
comment|/* Start out with no error */
name|cp
operator|=
name|s
expr_stmt|;
comment|/* Make the argument global */
name|v
operator|=
name|xparse
argument_list|()
expr_stmt|;
comment|/* Parse the string */
name|p
operator|=
name|numbuf
expr_stmt|;
comment|/* Convert long number to string */
name|sprintf
argument_list|(
name|p
argument_list|,
literal|"%ld"
argument_list|,
name|v
argument_list|)
expr_stmt|;
return|return
operator|(
name|xerror
condition|?
literal|""
else|:
name|p
operator|)
return|;
comment|/* Return empty string on error */
block|}
end_function

begin_comment
comment|/*  * simplest ::= NUMBER | ( expr )  *  */
end_comment

begin_function
specifier|static
name|VOID
name|simplest
parameter_list|()
block|{
if|if
condition|(
name|curtok
operator|==
name|NUMBER
condition|)
name|expval
operator|=
name|tokval
expr_stmt|;
elseif|else
if|if
condition|(
name|curtok
operator|==
literal|'('
condition|)
block|{
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
comment|/* skip over paren */
name|expr
argument_list|()
expr_stmt|;
if|if
condition|(
name|curtok
operator|!=
literal|')'
condition|)
block|{
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"missing right parenthesis\n"
argument_list|)
expr_stmt|;
name|xerror
operator|=
literal|1
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|cmdlvl
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"operator unexpected\n"
argument_list|)
expr_stmt|;
name|xerror
operator|=
literal|1
expr_stmt|;
block|}
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * simpler ::= simplest | simplest !  *  */
end_comment

begin_function
specifier|static
name|VOID
name|simpler
parameter_list|()
block|{
name|simplest
argument_list|()
expr_stmt|;
if|if
condition|(
name|curtok
operator|==
literal|'!'
condition|)
block|{
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
name|expval
operator|=
name|fact
argument_list|(
name|expval
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * simple ::= {-,~} simpler | simpler  *  */
end_comment

begin_function
specifier|static
name|VOID
name|simple
parameter_list|()
block|{
if|if
condition|(
name|curtok
operator|==
literal|'-'
operator|||
name|curtok
operator|==
literal|'~'
condition|)
block|{
name|int
name|op
init|=
name|curtok
decl_stmt|;
name|curtok
operator|=
name|gettok
argument_list|()
expr_stmt|;
comment|/* skip over - sign */
name|simpler
argument_list|()
expr_stmt|;
comment|/* parse the factor again */
name|expval
operator|=
name|op
operator|==
literal|'-'
condition|?
operator|-
name|expval
else|:
operator|~
name|expval
expr_stmt|;
block|}
else|else
name|simpler
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/*  D C L A R R A Y  --  Declare an array  */
end_comment

begin_function
name|int
comment|/* Declare an array of size n */
ifdef|#
directive|ifdef
name|CK_ANSIC
name|dclarray
parameter_list|(
name|char
name|a
parameter_list|,
name|int
name|n
parameter_list|)
else|#
directive|else
function|dclarray
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
name|char
name|a
decl_stmt|;
name|int
name|n
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* dclarray */
block|{
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
name|int
name|i
decl_stmt|,
name|n2
decl_stmt|;
if|if
condition|(
name|a
operator|>
literal|63
operator|&&
name|a
operator|<
literal|96
condition|)
name|a
operator|+=
literal|32
expr_stmt|;
comment|/* Convert to lowercase */
if|if
condition|(
name|a
operator|<
literal|96
operator|||
name|a
operator|>
literal|122
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Verify name */
name|a
operator|-=
literal|96
expr_stmt|;
comment|/* Convert name to number */
if|if
condition|(
operator|(
name|p
operator|=
name|a_ptr
index|[
name|a
index|]
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* Delete old array of same name */
name|n2
operator|=
name|a_dim
index|[
name|a
index|]
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|n2
condition|;
name|i
operator|++
control|)
comment|/* First delete its elements */
if|if
condition|(
name|p
index|[
name|i
index|]
condition|)
name|free
argument_list|(
name|p
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|a_ptr
index|[
name|a
index|]
argument_list|)
expr_stmt|;
comment|/* Then the element list */
name|a_ptr
index|[
name|a
index|]
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
expr_stmt|;
comment|/* Remove pointer to element list */
name|a_dim
index|[
name|a
index|]
operator|=
literal|0
expr_stmt|;
comment|/* Set dimension at zero. */
block|}
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* If dimension 0, just deallocate. */
name|p
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|n
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|char
operator|*
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Allocate for new array */
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Check */
name|a_ptr
index|[
name|a
index|]
operator|=
name|p
expr_stmt|;
comment|/* Save pointer to member list */
name|a_dim
index|[
name|a
index|]
operator|=
name|n
expr_stmt|;
comment|/* Save dimension */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|n
condition|;
name|i
operator|++
control|)
comment|/* Initialize members to null */
name|p
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  A R R A Y N A M  --  Parse an array name  */
end_comment

begin_comment
comment|/*   Call with pointer to string that starts with the array reference.   String may begin with either \& or just&.   On success,     Returns letter ID (always lowercase) in argument c,       which can also be accent grave (` = 96; '@' is converted to grave);     Dimension or subscript in argument n;     IMPORTANT: These arguments must be provided by the caller as addresses     of ints (not chars), for example:       char *s; int x, y;       arraynam(s,&x,&y);   On failure, returns a negative number, with args n and c set to zero. */
end_comment

begin_function
name|int
name|arraynam
parameter_list|(
name|ss
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|ss
decl_stmt|;
name|int
modifier|*
name|c
decl_stmt|;
name|int
modifier|*
name|n
decl_stmt|;
block|{
name|int
name|i
decl_stmt|,
name|y
decl_stmt|,
name|pp
decl_stmt|;
name|char
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|p
decl_stmt|,
modifier|*
name|sx
decl_stmt|,
modifier|*
name|vnp
decl_stmt|;
name|char
name|vnbuf
index|[
name|VNAML
operator|+
literal|1
index|]
decl_stmt|;
comment|/* On stack to allow for */
name|char
name|ssbuf
index|[
name|VNAML
operator|+
literal|1
index|]
decl_stmt|;
comment|/* recursive calls... */
name|char
name|sxbuf
index|[
name|VNAML
operator|+
literal|1
index|]
decl_stmt|;
operator|*
name|c
operator|=
operator|*
name|n
operator|=
literal|0
expr_stmt|;
comment|/* Initialize return values */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|ss
argument_list|)
condition|;
name|i
operator|++
control|)
comment|/* Check length */
if|if
condition|(
name|ss
index|[
name|i
index|]
operator|==
literal|']'
condition|)
break|break;
if|if
condition|(
name|i
operator|>
name|VNAML
condition|)
block|{
name|printf
argument_list|(
literal|"?Array reference too long - %s\n"
argument_list|,
name|ss
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
name|strncpy
argument_list|(
name|vnbuf
argument_list|,
name|ss
argument_list|,
name|VNAML
argument_list|)
expr_stmt|;
name|vnp
operator|=
name|vnbuf
expr_stmt|;
if|if
condition|(
name|vnbuf
index|[
literal|0
index|]
operator|==
name|CMDQ
operator|&&
name|vnbuf
index|[
literal|1
index|]
operator|==
literal|'&'
condition|)
name|vnp
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|vnp
operator|!=
literal|'&'
condition|)
block|{
name|printf
argument_list|(
literal|"?Not an array - %s\n"
argument_list|,
name|vnbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
name|x
operator|=
operator|*
operator|(
name|vnp
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* Fold case of array name */
comment|/* We don't use isupper& tolower here on purpose because these */
comment|/* would produce undesired effects with accented letters. */
if|if
condition|(
name|x
operator|>
literal|63
operator|&&
name|x
operator|<
literal|91
condition|)
name|x
operator|=
operator|*
operator|(
name|vnp
operator|+
literal|1
operator|)
operator|=
name|x
operator|+
literal|32
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|<
literal|96
operator|)
operator|||
operator|(
name|x
operator|>
literal|122
operator|)
operator|||
operator|(
operator|*
operator|(
name|vnp
operator|+
literal|2
operator|)
operator|!=
literal|'['
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"?Invalid format for array name - %s\n"
argument_list|,
name|vnbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
operator|*
name|c
operator|=
name|x
expr_stmt|;
comment|/* Return the array name */
name|s
operator|=
name|vnp
operator|+
literal|3
expr_stmt|;
comment|/* Get dimension */
name|p
operator|=
name|ssbuf
expr_stmt|;
name|pp
operator|=
literal|1
expr_stmt|;
comment|/* Bracket counter */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|VNAML
operator|&&
operator|*
name|s
operator|!=
name|NUL
condition|;
name|i
operator|++
control|)
block|{
comment|/* Copy up to ] */
if|if
condition|(
operator|*
name|s
operator|==
literal|'['
condition|)
name|pp
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|']'
operator|&&
operator|--
name|pp
operator|==
literal|0
condition|)
break|break;
operator|*
name|p
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|s
operator|!=
literal|']'
condition|)
block|{
name|printf
argument_list|(
literal|"?No closing bracket on array dimension - %s\n"
argument_list|,
name|vnbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
operator|*
name|p
operator|=
name|NUL
expr_stmt|;
comment|/* Terminate subscript with null */
name|p
operator|=
name|ssbuf
expr_stmt|;
comment|/* Point to beginning of subscript */
name|sx
operator|=
name|sxbuf
expr_stmt|;
comment|/* Where to put expanded subscript */
name|y
operator|=
name|VNAML
operator|-
literal|1
expr_stmt|;
name|xxstring
argument_list|(
name|p
argument_list|,
operator|&
name|sx
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
comment|/* Convert variables, etc. */
if|if
condition|(
operator|!
name|chknum
argument_list|(
name|sxbuf
argument_list|)
condition|)
block|{
comment|/* Make sure it's all digits */
name|printf
argument_list|(
literal|"?Array dimension or subscript must be numeric - %s\n"
argument_list|,
name|sxbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|y
operator|=
name|atoi
argument_list|(
name|sxbuf
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|cmflgs
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"?Array dimension or subscript must be positive or zero - %s\n"
argument_list|,
name|sxbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
operator|*
name|n
operator|=
name|y
expr_stmt|;
comment|/* Return the subscript or dimension */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|chkarray
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
name|int
name|a
decl_stmt|,
name|i
decl_stmt|;
block|{
comment|/* Check if array is declared */
name|int
name|x
decl_stmt|;
comment|/* and if subscript is in range */
if|if
condition|(
name|a
operator|==
literal|64
condition|)
name|a
operator|=
literal|96
expr_stmt|;
comment|/* Convert atsign to grave accent */
name|x
operator|=
name|a
operator|-
literal|96
expr_stmt|;
comment|/* Values must be in range 96-122 */
if|if
condition|(
name|x
operator|<
literal|0
operator|||
name|x
operator|>
literal|26
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* Not in range */
if|if
condition|(
name|a_ptr
index|[
name|x
index|]
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Not declared */
if|if
condition|(
name|i
operator|>
name|a_dim
index|[
name|x
index|]
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* Declared but out of range. */
return|return
operator|(
name|a_dim
index|[
name|x
index|]
operator|)
return|;
comment|/* All ok, return dimension */
block|}
end_function

begin_function
name|char
modifier|*
name|arrayval
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
name|int
name|a
decl_stmt|,
name|i
decl_stmt|;
block|{
comment|/* Return value of \&a[i] */
name|int
name|x
decl_stmt|;
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
comment|/* (possibly NULL) */
if|if
condition|(
name|a
operator|==
literal|64
condition|)
name|a
operator|=
literal|96
expr_stmt|;
comment|/* Convert atsign to grave accent */
name|x
operator|=
name|a
operator|-
literal|96
expr_stmt|;
comment|/* Values must be in range 96-122 */
if|if
condition|(
name|x
operator|<
literal|0
operator|||
name|x
operator|>
literal|26
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
comment|/* Not in range */
if|if
condition|(
operator|(
name|p
operator|=
name|a_ptr
index|[
name|x
index|]
operator|)
operator|==
name|NULL
condition|)
comment|/* Array not declared */
return|return
operator|(
name|NULL
operator|)
return|;
if|if
condition|(
name|i
operator|>
name|a_dim
index|[
name|x
index|]
condition|)
comment|/* Subscript out of range. */
return|return
operator|(
name|NULL
operator|)
return|;
return|return
operator|(
name|p
index|[
name|i
index|]
operator|)
return|;
comment|/* All ok, return pointer to value. */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/*  P A R S E V A R  --  Parse a variable name or array reference.  */
end_comment

begin_comment
comment|/*  Call with:    s  = pointer to candidate variable name or array reference.    *c = address of integer in which to return variable ID.    *i = address of integer in which to return array subscript.  Returns:    -2:  syntax error in variable name or array reference.     1:  successful parse of a simple variable, with ID in c.     2:  successful parse of an array reference, w/ID in c and subscript in i. */
end_comment

begin_function
name|int
name|parsevar
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|i
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
modifier|*
name|c
decl_stmt|,
decl|*
name|i
decl_stmt|;
end_function

begin_block
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
name|p
operator|=
name|s
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
name|CMDQ
condition|)
name|s
operator|++
expr_stmt|;
comment|/* Point after backslash */
if|if
condition|(
operator|*
name|s
operator|!=
literal|'%'
operator|&&
operator|*
name|s
operator|!=
literal|'&'
condition|)
block|{
comment|/* Make sure it's % or& */
name|printf
argument_list|(
literal|"?Not a variable name - %s\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
operator|<
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"?Incomplete variable name - %s\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
if|if
condition|(
operator|*
name|s
operator|==
literal|'%'
operator|&&
operator|*
operator|(
name|s
operator|+
literal|2
operator|)
operator|!=
literal|'\0'
condition|)
block|{
name|printf
argument_list|(
literal|"?Only one character after '%%' in variable name, please\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
if|if
condition|(
operator|*
name|s
operator|==
literal|'&'
operator|&&
operator|*
operator|(
name|s
operator|+
literal|2
operator|)
operator|!=
literal|'['
condition|)
block|{
name|printf
argument_list|(
literal|"?Array subscript expected - %s\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
if|if
condition|(
operator|*
name|s
operator|==
literal|'%'
condition|)
block|{
comment|/* Simple variable. */
name|y
operator|=
operator|*
operator|(
name|s
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* Get variable ID letter/char */
if|if
condition|(
name|isupper
argument_list|(
name|y
argument_list|)
condition|)
name|y
operator|-=
operator|(
literal|'a'
operator|-
literal|'A'
operator|)
expr_stmt|;
comment|/* Convert upper to lower case */
operator|*
name|c
operator|=
name|y
expr_stmt|;
comment|/* Set the return values. */
operator|*
name|i
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* No array subscript. */
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Return 1 = simple variable */
block|}
if|if
condition|(
operator|*
name|s
operator|==
literal|'&'
condition|)
block|{
comment|/* Array reference. */
if|if
condition|(
name|arraynam
argument_list|(
name|s
argument_list|,
operator|&
name|x
argument_list|,
operator|&
name|z
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Go parse it. */
name|printf
argument_list|(
literal|"?Invalid array reference - %s\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
if|if
condition|(
name|chkarray
argument_list|(
name|x
argument_list|,
name|z
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Check if declared, etc. */
name|printf
argument_list|(
literal|"?Array not declared or subscript out of range\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
operator|*
name|c
operator|=
name|x
expr_stmt|;
comment|/* Return array letter */
operator|*
name|i
operator|=
name|z
expr_stmt|;
comment|/* and subscript. */
return|return
operator|(
literal|2
operator|)
return|;
block|}
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* None of the above. */
block|}
end_block

begin_define
define|#
directive|define
name|VALN
value|20
end_define

begin_comment
comment|/* Get the numeric value of a variable */
end_comment

begin_comment
comment|/*   Call with pointer to variable name, pointer to int for return value.   Returns:     0 on success with second arg containing the value.    -1 on failure (bad variable syntax, variable not defined or not numeric). */
end_comment

begin_function
name|int
name|varval
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
modifier|*
name|v
decl_stmt|;
block|{
name|char
name|valbuf
index|[
name|VALN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* s is pointer to variable name */
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|y
decl_stmt|;
name|p
operator|=
name|valbuf
expr_stmt|;
comment|/* Expand variable into valbuf. */
name|y
operator|=
name|VALN
expr_stmt|;
if|if
condition|(
name|xxstring
argument_list|(
name|s
argument_list|,
operator|&
name|p
argument_list|,
operator|&
name|y
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|p
operator|=
name|valbuf
expr_stmt|;
comment|/* Make sure value is numeric */
if|if
condition|(
operator|!
name|chknum
argument_list|(
name|p
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
name|v
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Convert numeric string to int */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Increment or decrement a variable */
end_comment

begin_comment
comment|/* Returns -1 on failure, 0 on success, with 4th argument set to result */
end_comment

begin_function
name|int
name|incvar
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|,
name|z
parameter_list|,
name|r
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|x
decl_stmt|,
name|z
decl_stmt|,
decl|*
name|r
decl_stmt|;
end_function

begin_block
block|{
comment|/* Increment a numeric variable */
name|char
name|valbuf
index|[
name|VALN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* s is pointer to variable name */
comment|/* x is amount to increment by */
name|int
name|n
decl_stmt|;
comment|/* z != 0 means add */
comment|/* z = 0 means subtract */
if|if
condition|(
name|varval
argument_list|(
name|s
argument_list|,
operator|&
name|n
argument_list|)
operator|<
literal|0
condition|)
comment|/* Convert numeric string to int */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|z
condition|)
comment|/* Increment it by the given amount */
name|n
operator|+=
name|x
expr_stmt|;
else|else
comment|/* or decrement as requested. */
name|n
operator|-=
name|x
expr_stmt|;
name|sprintf
argument_list|(
name|valbuf
argument_list|,
literal|"%d"
argument_list|,
name|n
argument_list|)
expr_stmt|;
comment|/* Convert back to numeric string */
name|addmac
argument_list|(
name|s
argument_list|,
name|valbuf
argument_list|)
expr_stmt|;
comment|/* Replace old variable */
operator|*
name|r
operator|=
name|n
expr_stmt|;
comment|/* Return the integer value */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_comment
comment|/* Functions moved here from ckuusr.c to even out the module sizes... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/* Need xwords() function to break */
end_comment

begin_define
define|#
directive|define
name|XWORDS
end_define

begin_comment
comment|/* string up into words. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NODIAL
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|XWORDS
end_ifndef

begin_define
define|#
directive|define
name|XWORDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XWORDS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIAL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XWORDS
end_ifdef

begin_comment
comment|/*   Breaks string s up into a list of up to max words.   Pointers to each word go into the array list[].   If list is NULL, then they are added to the macro table. */
end_comment

begin_function
name|VOID
name|xwords
parameter_list|(
name|s
parameter_list|,
name|max
parameter_list|,
name|list
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|max
decl_stmt|;
name|char
modifier|*
name|list
index|[]
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|b
decl_stmt|,
name|k
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
ifndef|#
directive|ifndef
name|NOSPL
name|int
name|macro
decl_stmt|;
name|macro
operator|=
operator|(
name|list
operator|==
name|NULL
operator|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"xwords macro"
argument_list|,
literal|""
argument_list|,
name|macro
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
name|p
operator|=
name|s
expr_stmt|;
comment|/* Pointer to beginning of string */
name|b
operator|=
literal|0
expr_stmt|;
comment|/* Flag for outer brace removal */
name|k
operator|=
literal|0
expr_stmt|;
comment|/* Flag for in-word */
name|y
operator|=
literal|0
expr_stmt|;
comment|/* Brace nesting level */
name|z
operator|=
literal|0
expr_stmt|;
comment|/* Argument counter, 0 thru max */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* Go thru argument list */
if|if
condition|(
operator|!
name|s
operator|||
operator|(
operator|*
name|s
operator|==
literal|'\0'
operator|)
condition|)
block|{
comment|/* No more characters? */
if|if
condition|(
name|k
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|z
operator|==
name|max
condition|)
break|break;
comment|/* Only go up to max. */
name|z
operator|++
expr_stmt|;
comment|/* Count it. */
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|macro
condition|)
block|{
name|varnam
index|[
literal|1
index|]
operator|=
name|z
operator|+
literal|'0'
expr_stmt|;
comment|/* Assign last argument */
name|addmac
argument_list|(
name|varnam
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|/* NOSPL */
name|list
index|[
name|z
index|]
operator|=
name|p
expr_stmt|;
break|break;
comment|/* And get out. */
block|}
else|else
break|break;
block|}
if|if
condition|(
name|k
operator|==
literal|0
operator|&&
operator|(
operator|*
name|s
operator|==
name|SP
operator|||
operator|*
name|s
operator|==
name|HT
operator|)
condition|)
block|{
comment|/* Eat leading blanks */
name|s
operator|++
expr_stmt|;
continue|continue;
block|}
elseif|else
if|if
condition|(
operator|*
name|s
operator|==
literal|'{'
condition|)
block|{
comment|/* An opening brace */
if|if
condition|(
name|k
operator|==
literal|0
operator|&&
name|y
operator|==
literal|0
condition|)
block|{
comment|/* If leading brace */
name|p
operator|=
name|s
operator|+
literal|1
expr_stmt|;
comment|/* point past it */
name|b
operator|=
literal|1
expr_stmt|;
comment|/* and flag that we did this */
block|}
name|k
operator|=
literal|1
expr_stmt|;
comment|/* Flag that we're in a word */
name|y
operator|++
expr_stmt|;
comment|/* Count the brace. */
block|}
elseif|else
if|if
condition|(
operator|*
name|s
operator|==
literal|'}'
condition|)
block|{
comment|/* A closing brace. */
name|y
operator|--
expr_stmt|;
comment|/* Count it. */
if|if
condition|(
name|y
operator|==
literal|0
operator|&&
name|b
operator|!=
literal|0
condition|)
block|{
comment|/* If it matches the leading brace */
operator|*
name|s
operator|=
name|SP
expr_stmt|;
comment|/* change it to a space */
name|b
operator|=
literal|0
expr_stmt|;
comment|/* and we're not in braces any more */
block|}
elseif|else
if|if
condition|(
name|y
operator|<
literal|0
condition|)
name|k
operator|=
literal|1
expr_stmt|;
comment|/* otherwise just start a new word. */
block|}
elseif|else
if|if
condition|(
operator|*
name|s
operator|!=
name|SP
operator|&&
operator|*
name|s
operator|!=
name|HT
condition|)
block|{
comment|/* Nonspace means we're in a word */
if|if
condition|(
name|k
operator|==
literal|0
condition|)
name|p
operator|=
name|s
expr_stmt|;
comment|/* Mark the beginning */
name|k
operator|=
literal|1
expr_stmt|;
comment|/* Set in-word flag */
block|}
comment|/* If we're not inside a braced quantity, and we are in a word, and */
comment|/* we have hit whitespace, then we have an argument to assign. */
if|if
condition|(
operator|(
name|y
operator|<
literal|1
operator|)
operator|&&
operator|(
name|k
operator|!=
literal|0
operator|)
operator|&&
operator|(
operator|*
name|s
operator|==
name|SP
operator|||
operator|*
name|s
operator|==
name|HT
operator|)
condition|)
block|{
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
comment|/* terminate the arg with null */
name|k
operator|=
literal|0
expr_stmt|;
comment|/* say we're not in a word any more */
name|y
operator|=
literal|0
expr_stmt|;
comment|/* start braces off clean again */
if|if
condition|(
name|z
operator|==
name|max
condition|)
break|break;
comment|/* Only go up to max. */
name|z
operator|++
expr_stmt|;
comment|/* count this arg */
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|macro
condition|)
block|{
name|varnam
index|[
literal|1
index|]
operator|=
name|z
operator|+
literal|'0'
expr_stmt|;
comment|/* compute its name */
name|addmac
argument_list|(
name|varnam
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* add it to the macro table */
block|}
else|else
endif|#
directive|endif
comment|/* NOSPL */
name|list
index|[
name|z
index|]
operator|=
name|p
expr_stmt|;
name|p
operator|=
name|s
operator|+
literal|1
expr_stmt|;
block|}
name|s
operator|++
expr_stmt|;
comment|/* Point past this character */
block|}
if|if
condition|(
operator|(
name|z
operator|==
literal|0
operator|)
operator|&&
operator|(
name|y
operator|>
literal|1
operator|)
condition|)
block|{
comment|/* Extra closing brace(s) at end */
name|z
operator|++
expr_stmt|;
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|macro
condition|)
block|{
name|varnam
index|[
literal|1
index|]
operator|=
name|z
operator|+
literal|'0'
expr_stmt|;
comment|/* compute its name */
name|addmac
argument_list|(
name|varnam
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* Add rest of line to last arg */
block|}
else|else
endif|#
directive|endif
comment|/* NOSPL */
name|list
index|[
name|z
index|]
operator|=
name|p
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|macro
condition|)
name|macargc
index|[
name|maclvl
index|]
operator|=
name|z
operator|+
literal|1
expr_stmt|;
comment|/* Set \v(argc) variable */
endif|#
directive|endif
comment|/* NOSPL */
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XWORDS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/* D O D O  --  Do a macro */
end_comment

begin_comment
comment|/*   Call with x = macro table index, s = pointer to arguments.   Returns 0 on failure, 1 on success. */
end_comment

begin_function
name|int
name|dodo
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|y
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"dodo maclvl"
argument_list|,
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|maclvl
operator|>
name|MACLEVEL
condition|)
block|{
comment|/* Make sure we have storage */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"dodo maclvl too deep"
argument_list|,
literal|""
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
operator|--
name|maclvl
expr_stmt|;
name|printf
argument_list|(
literal|"Macros nested too deeply\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|macp
index|[
name|maclvl
index|]
operator|=
name|mactab
index|[
name|x
index|]
operator|.
name|mval
expr_stmt|;
comment|/* Point to the macro body */
name|macx
index|[
name|maclvl
index|]
operator|=
name|mactab
index|[
name|x
index|]
operator|.
name|mval
expr_stmt|;
comment|/* Remember where the beginning is */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"do macro"
argument_list|,
name|macp
index|[
name|maclvl
index|]
argument_list|,
name|maclvl
argument_list|)
expr_stmt|;
name|cmdlvl
operator|++
expr_stmt|;
comment|/* Entering a new command level */
if|if
condition|(
name|cmdlvl
operator|>
name|CMDSTKL
condition|)
block|{
comment|/* Too many macros + TAKE files? */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"dodo cmdlvl too deep"
argument_list|,
literal|""
argument_list|,
name|cmdlvl
argument_list|)
expr_stmt|;
name|cmdlvl
operator|--
expr_stmt|;
name|printf
argument_list|(
literal|"?TAKE files and DO commands nested too deeply\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|VMS
name|conres
argument_list|()
expr_stmt|;
comment|/* So Ctrl-C, etc, will work. */
endif|#
directive|endif
comment|/* VMS */
name|ifcmd
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|iftest
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|count
index|[
name|cmdlvl
index|]
operator|=
literal|0
expr_stmt|;
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|src
operator|=
name|CMD_MD
expr_stmt|;
comment|/* Say we're in a macro */
name|cmdstk
index|[
name|cmdlvl
index|]
operator|.
name|lvl
operator|=
name|maclvl
expr_stmt|;
comment|/* and remember the macro level */
name|mrval
index|[
name|maclvl
index|]
operator|=
name|NULL
expr_stmt|;
comment|/* Initialize return value */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"do macro"
argument_list|,
name|mactab
index|[
name|x
index|]
operator|.
name|kwd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear old %0..%9 arguments */
name|addmac
argument_list|(
literal|"%0"
argument_list|,
name|mactab
index|[
name|x
index|]
operator|.
name|kwd
argument_list|)
expr_stmt|;
comment|/* Define %0 = name of macro */
name|varnam
index|[
literal|0
index|]
operator|=
literal|'%'
expr_stmt|;
name|varnam
index|[
literal|2
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|1
init|;
name|y
operator|<
literal|10
condition|;
name|y
operator|++
control|)
block|{
comment|/* Clear args %1..%9 */
name|varnam
index|[
literal|1
index|]
operator|=
name|y
operator|+
literal|'0'
expr_stmt|;
name|delmac
argument_list|(
name|varnam
argument_list|)
expr_stmt|;
block|}
comment|/* Assign the new args one word per arg, allowing braces to group words */
name|xwords
argument_list|(
name|s
argument_list|,
literal|9
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Insert "literal" quote around each comma-separated command to prevent */
end_comment

begin_comment
comment|/* its premature expansion.  Only do this if object command is surrounded */
end_comment

begin_comment
comment|/* by braces. */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|flit
init|=
literal|"\\flit("
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|litcmd
parameter_list|(
name|src
parameter_list|,
name|dest
parameter_list|)
name|char
modifier|*
modifier|*
name|src
decl_stmt|,
decl|*
modifier|*
name|dest
decl_stmt|;
end_function

begin_block
block|{
name|int
name|bc
init|=
literal|0
decl_stmt|,
name|pp
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|lp
decl_stmt|,
modifier|*
name|ss
decl_stmt|;
name|s
operator|=
operator|*
name|src
expr_stmt|;
name|lp
operator|=
operator|*
name|dest
expr_stmt|;
while|while
condition|(
operator|*
name|s
operator|==
name|SP
condition|)
name|s
operator|++
expr_stmt|;
comment|/* strip extra leading spaces */
if|if
condition|(
operator|*
name|s
operator|==
literal|'{'
condition|)
block|{
name|pp
operator|=
literal|0
expr_stmt|;
comment|/* paren counter */
name|bc
operator|=
literal|1
expr_stmt|;
comment|/* count leading brace */
operator|*
name|lp
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
comment|/* copy it */
while|while
condition|(
operator|*
name|s
operator|==
name|SP
condition|)
name|s
operator|++
expr_stmt|;
comment|/* strip interior leading spaces */
name|ss
operator|=
name|flit
expr_stmt|;
comment|/* point to "\flit(" */
while|while
condition|(
operator|*
name|lp
operator|++
operator|=
operator|*
name|ss
operator|++
condition|)
empty_stmt|;
comment|/* copy it */
name|lp
operator|--
expr_stmt|;
comment|/* back up over null */
while|while
condition|(
operator|*
name|s
condition|)
block|{
comment|/* go thru rest of text */
name|ss
operator|=
name|flit
expr_stmt|;
comment|/* point back to start of "\flit(" */
if|if
condition|(
operator|*
name|s
operator|==
literal|'{'
condition|)
name|bc
operator|++
expr_stmt|;
comment|/* count brackets */
if|if
condition|(
operator|*
name|s
operator|==
literal|'('
condition|)
name|pp
operator|++
expr_stmt|;
comment|/* and parens */
if|if
condition|(
operator|*
name|s
operator|==
literal|')'
condition|)
name|pp
operator|--
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|'}'
condition|)
block|{
comment|/* Closing brace. */
if|if
condition|(
operator|--
name|bc
operator|==
literal|0
condition|)
block|{
comment|/* Final one? */
operator|*
name|lp
operator|++
operator|=
literal|')'
expr_stmt|;
comment|/* Add closing paren for "\flit()" */
operator|*
name|lp
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|*
name|s
operator|==
literal|','
operator|&&
name|pp
operator|==
literal|0
condition|)
block|{
comment|/* comma not inside of parens */
operator|*
name|lp
operator|++
operator|=
literal|')'
expr_stmt|;
comment|/* closing ) of \flit( */
operator|*
name|lp
operator|++
operator|=
literal|','
expr_stmt|;
comment|/* insert the comma */
while|while
condition|(
operator|*
name|lp
operator|++
operator|=
operator|*
name|ss
operator|++
condition|)
empty_stmt|;
comment|/* start new "\flit(" */
name|lp
operator|--
expr_stmt|;
comment|/* back up over null */
name|s
operator|++
expr_stmt|;
comment|/* skip over comma in source string */
while|while
condition|(
operator|*
name|s
operator|++
operator|==
name|SP
condition|)
empty_stmt|;
comment|/* eat leading spaces again. */
name|s
operator|--
expr_stmt|;
comment|/* back up over nonspace */
continue|continue;
block|}
operator|*
name|lp
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
comment|/* Copy anything but comma here. */
block|}
operator|*
name|lp
operator|=
name|NUL
expr_stmt|;
block|}
else|else
block|{
comment|/* No brackets around, */
while|while
condition|(
operator|*
name|lp
operator|++
operator|=
operator|*
name|s
operator|++
condition|)
empty_stmt|;
comment|/* just copy. */
name|lp
operator|--
expr_stmt|;
block|}
operator|*
name|src
operator|=
name|s
expr_stmt|;
operator|*
name|dest
operator|=
name|lp
expr_stmt|;
if|if
condition|(
name|bc
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_function
name|int
name|docd
parameter_list|()
block|{
comment|/* Do the CD command */
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|GEMDOS
if|if
condition|(
operator|(
name|x
operator|=
name|cmdir
argument_list|(
literal|"Name of local directory, or carriage return"
argument_list|,
name|homdir
argument_list|,
operator|&
name|s
argument_list|,
name|NULL
argument_list|)
operator|)
operator|<
literal|0
condition|)
else|#
directive|else
if|if
condition|(
operator|(
name|x
operator|=
name|cmdir
argument_list|(
literal|"Name of local directory, or carriage return"
argument_list|,
name|homdir
argument_list|,
operator|&
name|s
argument_list|,
name|xxstring
argument_list|)
operator|)
operator|<
literal|0
condition|)
endif|#
directive|endif
comment|/* GEMDOS */
return|return
operator|(
name|x
operator|)
return|;
if|if
condition|(
name|x
operator|==
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"?Wildcards not allowed in directory name\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|9
operator|)
return|;
block|}
name|strcpy
argument_list|(
name|line
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|/* Make a safe copy */
name|s
operator|=
name|line
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
comment|/* Get confirmation */
return|return
operator|(
name|x
operator|)
return|;
if|if
condition|(
operator|!
name|zchdir
argument_list|(
name|s
argument_list|)
condition|)
block|{
name|cwdf
operator|=
literal|0
expr_stmt|;
name|perror
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
else|else
name|cwdf
operator|=
literal|1
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|zgtdir
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Not OS2 */
ifndef|#
directive|ifndef
name|MAC
name|zsyscmd
argument_list|(
name|PWDCMD
argument_list|)
expr_stmt|;
comment|/* assume this works... */
endif|#
directive|endif
comment|/* MAC */
endif|#
directive|endif
comment|/* OS2 */
return|return
operator|(
name|cwdf
operator|)
return|;
block|}
end_function

begin_function
name|VOID
name|fixcmd
parameter_list|()
block|{
comment|/* Fix command parser after interruption */
name|dostop
argument_list|()
expr_stmt|;
comment|/* Back to top level (also calls conint()). */
name|bgchk
argument_list|()
expr_stmt|;
comment|/* Check background status */
if|if
condition|(
operator|*
name|psave
condition|)
block|{
comment|/* If old prompt saved, */
name|cmsetp
argument_list|(
name|psave
argument_list|)
expr_stmt|;
comment|/* restore it. */
operator|*
name|psave
operator|=
name|NUL
expr_stmt|;
block|}
name|success
operator|=
literal|0
expr_stmt|;
comment|/* Tell parser last command failed */
block|}
end_function

begin_function
name|VOID
name|prtopt
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
comment|/* Print an option */
specifier|static
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|/* (used by SHOW VER) */
name|int
name|y
decl_stmt|;
comment|/* Does word wrap. */
if|if
condition|(
operator|!
name|s
condition|)
block|{
name|x
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|/* Call with null pointer to */
name|y
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* reset horizontal position. */
name|x
operator|+=
name|y
expr_stmt|;
if|if
condition|(
name|x
operator|>
literal|79
condition|)
block|{
name|printf
argument_list|(
literal|"\n%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|x
operator|=
name|y
expr_stmt|;
block|}
else|else
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOICP */
end_comment

end_unit

