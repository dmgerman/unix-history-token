begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)externs.h	1.21 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|BSD
operator|>
literal|43
operator|||
name|defined
argument_list|(
name|SYSV_TERMIO
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_TERMIO
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_TERMIO
end_define

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/ioctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_TERMIO
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|VINTR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<sys/termio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_define
define|#
directive|define
name|termio
value|termios
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|cc_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SUBBUFSIZE
value|256
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* outside this world */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* outside this world */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flushout
decl_stmt|,
comment|/* flush output */
name|connected
decl_stmt|,
comment|/* Are we connected to the other side? */
name|globalmode
decl_stmt|,
comment|/* Mode tty should be in */
name|In3270
decl_stmt|,
comment|/* Are we in 3270 mode? */
name|telnetport
decl_stmt|,
comment|/* Are we connected to the telnet port? */
name|localflow
decl_stmt|,
comment|/* Flow control handled locally */
name|localchars
decl_stmt|,
comment|/* we recognize interrupt/quit */
name|donelclchars
decl_stmt|,
comment|/* the user has set "localchars" */
name|showoptions
decl_stmt|,
name|net
decl_stmt|,
comment|/* Network file descriptor */
name|tin
decl_stmt|,
comment|/* Terminal input file descriptor */
name|tout
decl_stmt|,
comment|/* Terminal output file descriptor */
name|crlf
decl_stmt|,
comment|/* Should '\r' be mapped to<CR><LF> (or<CR><NUL>)? */
name|autoflush
decl_stmt|,
comment|/* flush output when interrupting? */
name|autosynch
decl_stmt|,
comment|/* send interrupt characters with SYNCH? */
name|SYNCHing
decl_stmt|,
comment|/* Is the stream in telnet SYNCH mode? */
name|donebinarytoggle
decl_stmt|,
comment|/* the user has put us in binary */
name|dontlecho
decl_stmt|,
comment|/* do we suppress local echoing right now? */
name|crmod
decl_stmt|,
name|netdata
decl_stmt|,
comment|/* Print out network data flow */
name|prettydump
decl_stmt|,
comment|/* Print "netdata" output in user readable format */
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|TN3270
argument_list|)
name|cursesdata
decl_stmt|,
comment|/* Print out curses data flow */
name|apitrace
decl_stmt|,
comment|/* Trace API transactions */
endif|#
directive|endif
comment|/* defined(TN3270) */
name|termdata
decl_stmt|,
comment|/* Print out terminal data flow */
endif|#
directive|endif
comment|/* defined(unix) */
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug level */
end_comment

begin_decl_stmt
specifier|extern
name|cc_t
name|echoc
decl_stmt|,
comment|/* Toggle local echoing */
name|escape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Escape to command mode */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prompt for command. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|doopt
index|[]
decl_stmt|,
name|dont
index|[]
decl_stmt|,
name|will
index|[]
decl_stmt|,
name|wont
index|[]
decl_stmt|,
name|options
index|[]
decl_stmt|,
comment|/* All the little options */
modifier|*
name|hostname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Who are we connected to? */
end_comment

begin_comment
comment|/*  * We keep track of each side of the option negotiation.  */
end_comment

begin_define
define|#
directive|define
name|MY_STATE_WILL
value|0x01
end_define

begin_define
define|#
directive|define
name|MY_WANT_STATE_WILL
value|0x02
end_define

begin_define
define|#
directive|define
name|MY_STATE_DO
value|0x04
end_define

begin_define
define|#
directive|define
name|MY_WANT_STATE_DO
value|0x08
end_define

begin_comment
comment|/*  * Macros to check the current state of things  */
end_comment

begin_define
define|#
directive|define
name|my_state_is_do
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&MY_STATE_DO)
end_define

begin_define
define|#
directive|define
name|my_state_is_will
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&MY_STATE_WILL)
end_define

begin_define
define|#
directive|define
name|my_want_state_is_do
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&MY_WANT_STATE_DO)
end_define

begin_define
define|#
directive|define
name|my_want_state_is_will
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&MY_WANT_STATE_WILL)
end_define

begin_define
define|#
directive|define
name|my_state_is_dont
parameter_list|(
name|opt
parameter_list|)
value|(!my_state_is_do(opt))
end_define

begin_define
define|#
directive|define
name|my_state_is_wont
parameter_list|(
name|opt
parameter_list|)
value|(!my_state_is_will(opt))
end_define

begin_define
define|#
directive|define
name|my_want_state_is_dont
parameter_list|(
name|opt
parameter_list|)
value|(!my_want_state_is_do(opt))
end_define

begin_define
define|#
directive|define
name|my_want_state_is_wont
parameter_list|(
name|opt
parameter_list|)
value|(!my_want_state_is_will(opt))
end_define

begin_define
define|#
directive|define
name|set_my_state_do
parameter_list|(
name|opt
parameter_list|)
value|{options[opt] |= MY_STATE_DO;}
end_define

begin_define
define|#
directive|define
name|set_my_state_will
parameter_list|(
name|opt
parameter_list|)
value|{options[opt] |= MY_STATE_WILL;}
end_define

begin_define
define|#
directive|define
name|set_my_want_state_do
parameter_list|(
name|opt
parameter_list|)
value|{options[opt] |= MY_WANT_STATE_DO;}
end_define

begin_define
define|#
directive|define
name|set_my_want_state_will
parameter_list|(
name|opt
parameter_list|)
value|{options[opt] |= MY_WANT_STATE_WILL;}
end_define

begin_define
define|#
directive|define
name|set_my_state_dont
parameter_list|(
name|opt
parameter_list|)
value|{options[opt]&= ~MY_STATE_DO;}
end_define

begin_define
define|#
directive|define
name|set_my_state_wont
parameter_list|(
name|opt
parameter_list|)
value|{options[opt]&= ~MY_STATE_WILL;}
end_define

begin_define
define|#
directive|define
name|set_my_want_state_dont
parameter_list|(
name|opt
parameter_list|)
value|{options[opt]&= ~MY_WANT_STATE_DO;}
end_define

begin_define
define|#
directive|define
name|set_my_want_state_wont
parameter_list|(
name|opt
parameter_list|)
value|{options[opt]&= ~MY_WANT_STATE_WILL;}
end_define

begin_comment
comment|/*  * Make everything symetrical  */
end_comment

begin_define
define|#
directive|define
name|HIS_STATE_WILL
value|MY_STATE_DO
end_define

begin_define
define|#
directive|define
name|HIS_WANT_STATE_WILL
value|MY_WANT_STATE_DO
end_define

begin_define
define|#
directive|define
name|HIS_STATE_DO
value|MY_STATE_WILL
end_define

begin_define
define|#
directive|define
name|HIS_WANT_STATE_DO
value|MY_WANT_STATE_WILL
end_define

begin_define
define|#
directive|define
name|his_state_is_do
value|my_state_is_will
end_define

begin_define
define|#
directive|define
name|his_state_is_will
value|my_state_is_do
end_define

begin_define
define|#
directive|define
name|his_want_state_is_do
value|my_want_state_is_will
end_define

begin_define
define|#
directive|define
name|his_want_state_is_will
value|my_want_state_is_do
end_define

begin_define
define|#
directive|define
name|his_state_is_dont
value|my_state_is_wont
end_define

begin_define
define|#
directive|define
name|his_state_is_wont
value|my_state_is_dont
end_define

begin_define
define|#
directive|define
name|his_want_state_is_dont
value|my_want_state_is_wont
end_define

begin_define
define|#
directive|define
name|his_want_state_is_wont
value|my_want_state_is_dont
end_define

begin_define
define|#
directive|define
name|set_his_state_do
value|set_my_state_will
end_define

begin_define
define|#
directive|define
name|set_his_state_will
value|set_my_state_do
end_define

begin_define
define|#
directive|define
name|set_his_want_state_do
value|set_my_want_state_will
end_define

begin_define
define|#
directive|define
name|set_his_want_state_will
value|set_my_want_state_do
end_define

begin_define
define|#
directive|define
name|set_his_state_dont
value|set_my_state_wont
end_define

begin_define
define|#
directive|define
name|set_his_state_wont
value|set_my_state_dont
end_define

begin_define
define|#
directive|define
name|set_his_want_state_dont
value|set_my_want_state_wont
end_define

begin_define
define|#
directive|define
name|set_his_want_state_wont
value|set_my_want_state_dont
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|NetTrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where debugging output goes */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|NetTraceFile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of file where debugging output goes */
end_comment

begin_function_decl
specifier|extern
name|void
name|SetNetTrace
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Function to change where debugging goes */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|peerdied
decl_stmt|,
name|toplevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For error conditions. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|command
argument_list|()
decl_stmt|,
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NOT43
argument_list|)
name|dosynch
argument_list|()
decl_stmt|,
endif|#
directive|endif
comment|/* !defined(NOT43) */
name|get_status
argument_list|()
decl_stmt|,
name|Dump
argument_list|()
decl_stmt|,
name|init_3270
argument_list|()
decl_stmt|,
name|printoption
argument_list|()
decl_stmt|,
name|printsub
argument_list|()
decl_stmt|,
name|sendnaws
argument_list|()
decl_stmt|,
name|setconnmode
argument_list|()
decl_stmt|,
name|setcommandmode
argument_list|()
decl_stmt|,
name|setneturg
argument_list|()
decl_stmt|,
name|sys_telnet_init
argument_list|()
decl_stmt|,
name|telnet
argument_list|()
decl_stmt|,
name|TerminalFlushOutput
argument_list|()
decl_stmt|,
name|TerminalNewMode
argument_list|()
decl_stmt|,
name|TerminalRestoreState
argument_list|()
decl_stmt|,
name|TerminalSaveState
argument_list|()
decl_stmt|,
name|tninit
argument_list|()
decl_stmt|,
name|upcase
argument_list|()
decl_stmt|,
name|willoption
argument_list|()
decl_stmt|,
name|wontoption
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NOT43
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|dosynch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NOT43) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_TERMIO
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|tchars
name|ntc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ltchars
name|nltc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sgttyb
name|nttyb
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|termEofChar
value|ntc.t_eofc
end_define

begin_define
define|#
directive|define
name|termEraseChar
value|nttyb.sg_erase
end_define

begin_define
define|#
directive|define
name|termFlushChar
value|nltc.t_flushc
end_define

begin_define
define|#
directive|define
name|termIntChar
value|ntc.t_intrc
end_define

begin_define
define|#
directive|define
name|termKillChar
value|nttyb.sg_kill
end_define

begin_define
define|#
directive|define
name|termLiteralNextChar
value|nltc.t_lnextc
end_define

begin_define
define|#
directive|define
name|termQuitChar
value|ntc.t_quitc
end_define

begin_define
define|#
directive|define
name|termSuspChar
value|nltc.t_suspc
end_define

begin_define
define|#
directive|define
name|termRprntChar
value|nltc.t_rprntc
end_define

begin_define
define|#
directive|define
name|termWerasChar
value|nltc.t_werasc
end_define

begin_define
define|#
directive|define
name|termStartChar
value|ntc.t_startc
end_define

begin_define
define|#
directive|define
name|termStopChar
value|ntc.t_stopc
end_define

begin_define
define|#
directive|define
name|termForw1Char
value|ntc.t_brkc
end_define

begin_decl_stmt
specifier|extern
name|char
name|termForw2Char
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|termEofCharp
value|(cc_t *)&ntc.t_eofc
end_define

begin_define
define|#
directive|define
name|termEraseCharp
value|(cc_t *)&nttyb.sg_erase
end_define

begin_define
define|#
directive|define
name|termFlushCharp
value|(cc_t *)&nltc.t_flushc
end_define

begin_define
define|#
directive|define
name|termIntCharp
value|(cc_t *)&ntc.t_intrc
end_define

begin_define
define|#
directive|define
name|termKillCharp
value|(cc_t *)&nttyb.sg_kill
end_define

begin_define
define|#
directive|define
name|termLiteralNextCharp
value|(cc_t *)&nltc.t_lnextc
end_define

begin_define
define|#
directive|define
name|termQuitCharp
value|(cc_t *)&ntc.t_quitc
end_define

begin_define
define|#
directive|define
name|termSuspCharp
value|(cc_t *)&nltc.t_suspc
end_define

begin_define
define|#
directive|define
name|termRprntCharp
value|(cc_t *)&nltc.t_rprntc
end_define

begin_define
define|#
directive|define
name|termWerasCharp
value|(cc_t *)&nltc.t_werasc
end_define

begin_define
define|#
directive|define
name|termStartCharp
value|(cc_t *)&ntc.t_startc
end_define

begin_define
define|#
directive|define
name|termStopCharp
value|(cc_t *)&ntc.t_stopc
end_define

begin_define
define|#
directive|define
name|termForw1Charp
value|(cc_t *)&ntc.t_brkc
end_define

begin_define
define|#
directive|define
name|termForw2Charp
value|(cc_t *)&termForw2Char
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|struct
name|termio
name|new_tc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|termEofChar
value|new_tc.c_cc[VEOF]
end_define

begin_define
define|#
directive|define
name|termEraseChar
value|new_tc.c_cc[VERASE]
end_define

begin_define
define|#
directive|define
name|termIntChar
value|new_tc.c_cc[VINTR]
end_define

begin_define
define|#
directive|define
name|termKillChar
value|new_tc.c_cc[VKILL]
end_define

begin_define
define|#
directive|define
name|termQuitChar
value|new_tc.c_cc[VQUIT]
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|VSUSP
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termSuspChar
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termSuspChar
value|new_tc.c_cc[VSUSP]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VFLUSHO
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termFlushChar
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termFlushChar
value|new_tc.c_cc[VFLUSHO]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VWERASE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termWerasChar
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termWerasChar
value|new_tc.c_cc[VWERASE]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VREPRINT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termRprntChar
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termRprntChar
value|new_tc.c_cc[VREPRINT]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VLNEXT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termLiteralNextChar
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termLiteralNextChar
value|new_tc.c_cc[VLNEXT]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VSTART
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termStartChar
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termStartChar
value|new_tc.c_cc[VSTART]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VSTOP
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termStopChar
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termStopChar
value|new_tc.c_cc[VSTOP]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VEOL
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termForw1Char
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termForw1Char
value|new_tc.c_cc[VEOL]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VEOL2
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|termForw2Char
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termForw2Char
value|new_tc.c_cc[VEOL]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CRAY
end_ifndef

begin_define
define|#
directive|define
name|termEofCharp
value|&termEofChar
end_define

begin_define
define|#
directive|define
name|termEraseCharp
value|&termEraseChar
end_define

begin_define
define|#
directive|define
name|termIntCharp
value|&termIntChar
end_define

begin_define
define|#
directive|define
name|termKillCharp
value|&termKillChar
end_define

begin_define
define|#
directive|define
name|termQuitCharp
value|&termQuitChar
end_define

begin_define
define|#
directive|define
name|termSuspCharp
value|&termSuspChar
end_define

begin_define
define|#
directive|define
name|termFlushCharp
value|&termFlushChar
end_define

begin_define
define|#
directive|define
name|termWerasCharp
value|&termWerasChar
end_define

begin_define
define|#
directive|define
name|termRprntCharp
value|&termRprntChar
end_define

begin_define
define|#
directive|define
name|termLiteralNextCharp
value|&termLiteralNextChar
end_define

begin_define
define|#
directive|define
name|termStartCharp
value|&termStartChar
end_define

begin_define
define|#
directive|define
name|termStopCharp
value|&termStopChar
end_define

begin_define
define|#
directive|define
name|termForw1Charp
value|&termForw1Char
end_define

begin_define
define|#
directive|define
name|termForw2Charp
value|&termForw2Char
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Work around a compiler bug */
end_comment

begin_define
define|#
directive|define
name|termEofCharp
value|0
end_define

begin_define
define|#
directive|define
name|termEraseCharp
value|0
end_define

begin_define
define|#
directive|define
name|termIntCharp
value|0
end_define

begin_define
define|#
directive|define
name|termKillCharp
value|0
end_define

begin_define
define|#
directive|define
name|termQuitCharp
value|0
end_define

begin_define
define|#
directive|define
name|termSuspCharp
value|0
end_define

begin_define
define|#
directive|define
name|termFlushCharp
value|0
end_define

begin_define
define|#
directive|define
name|termWerasCharp
value|0
end_define

begin_define
define|#
directive|define
name|termRprntCharp
value|0
end_define

begin_define
define|#
directive|define
name|termLiteralNextCharp
value|0
end_define

begin_define
define|#
directive|define
name|termStartCharp
value|0
end_define

begin_define
define|#
directive|define
name|termStopCharp
value|0
end_define

begin_define
define|#
directive|define
name|termForw1Charp
value|0
end_define

begin_define
define|#
directive|define
name|termForw2Charp
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
comment|/* Ring buffer structures which are shared */
end_comment

begin_decl_stmt
specifier|extern
name|Ring
name|netoring
decl_stmt|,
name|netiring
decl_stmt|,
name|ttyoring
decl_stmt|,
name|ttyiring
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tn3270 section */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TN3270
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|HaveInput
decl_stmt|,
comment|/* Whether an asynchronous I/O indication came in */
name|noasynchtty
decl_stmt|,
comment|/* Don't do signals on I/O (SIGURG, SIGIO) */
name|noasynchnet
decl_stmt|,
comment|/* Don't do signals on I/O (SIGURG, SIGIO) */
name|sigiocount
decl_stmt|,
comment|/* Count of SIGIO receptions */
name|shell_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Subshell is active */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Ibackp
decl_stmt|,
comment|/* Oldest byte of 3270 data */
name|Ibuf
index|[]
decl_stmt|,
comment|/* 3270 buffer */
modifier|*
name|Ifrontp
decl_stmt|,
comment|/* Where next 3270 byte goes */
name|tline
index|[]
decl_stmt|,
modifier|*
name|transcom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Transparent command */
end_comment

begin_function_decl
specifier|extern
name|int
name|settranscom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|inputAvailable
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(TN3270) */
end_comment

end_unit

