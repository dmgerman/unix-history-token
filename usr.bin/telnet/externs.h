begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)externs.h	8.3 (Berkeley) 5/30/95  *	$FreeBSD$  */
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

begin_comment
comment|/*  * ucb stdio.h defines BSD as something weird  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

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

begin_ifndef
ifndef|#
directive|ifndef
name|USE_TERMIO
end_ifndef

begin_if
if|#
directive|if
name|BSD
operator|>
literal|43
operator|||
name|defined
argument_list|(
name|SYSV_TERMIO
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

begin_include
include|#
directive|include
file|<errno.h>
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

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NO_CC_T
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|USE_TERMIO
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_TERMIO
argument_list|)
end_if

begin_typedef
typedef|typedef
name|char
name|cc_t
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
name|cc_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IPSEC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet6/ipsec.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IPSEC_POLICY_IPSEC
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ipsec_policy_in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ipsec_policy_out
decl_stmt|;
end_decl_stmt

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
name|_POSIX_VDISABLE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* pick up VDISABLE definition, mayby */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VDISABLE
end_ifdef

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|VDISABLE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|((cc_t)'\377')
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
name|SUBBUFSIZE
value|256
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|P
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|autologin
decl_stmt|,
comment|/* Autologin enabled */
name|skiprc
decl_stmt|,
comment|/* Don't process the ~/.telnetrc file */
name|eight
decl_stmt|,
comment|/* use eight bit mode (binary in and/or out */
name|family
decl_stmt|,
comment|/* address family of peer */
name|flushout
decl_stmt|,
comment|/* flush output */
name|connected
decl_stmt|,
comment|/* Are we connected to the other side? */
name|globalmode
decl_stmt|,
comment|/* Mode tty should be in */
name|telnetport
decl_stmt|,
comment|/* Are we connected to the telnet port? */
name|localflow
decl_stmt|,
comment|/* Flow control handled locally */
name|restartany
decl_stmt|,
comment|/* If flow control, restart output on any character */
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
name|termdata
decl_stmt|,
comment|/* Print out terminal data flow */
name|debug
decl_stmt|,
comment|/* Debug level */
name|doaddrlookup
decl_stmt|,
comment|/* do a reverse lookup? */
name|clienteof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Client received EOF */
end_comment

begin_decl_stmt
specifier|extern
name|cc_t
name|escape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Escape to command mode */
end_comment

begin_decl_stmt
specifier|extern
name|cc_t
name|rlogin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rlogin mode escape character */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KLUDGELINEMODE
end_ifdef

begin_decl_stmt
specifier|extern
name|cc_t
name|echoc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Toggle local echoing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_TERMIO
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIG_FUNC_RET
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIG_FUNC_RET
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIGINFO
end_ifdef

begin_function_decl
specifier|extern
name|SIG_FUNC_RET
name|ayt_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
parameter_list|(
name|char
modifier|*
parameter_list|)
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
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|Dump
argument_list|(
name|char
argument_list|,
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|env_init
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|Exit
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|ExitString
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|init_network
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|init_sys
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|init_telnet
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|init_terminal
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|intp
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|optionstatus
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|printoption
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|printsub
argument_list|(
name|char
argument_list|,
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|quit
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sendabort
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sendbrk
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sendeof
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sendsusp
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sendnaws
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sendayt
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|setconnmode
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|setcommandmode
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|set_escape_char
argument_list|(
name|char
operator|*
name|s
argument_list|)
decl_stmt|,
name|setneturg
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sys_telnet_init
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|telnet
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|tel_enter_binary
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tel_leave_binary
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|TerminalFlushOutput
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|TerminalNewMode
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|TerminalRestoreState
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|TerminalSaveState
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|TerminalDefaultChars
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|TerminalSpeeds
argument_list|(
name|long
operator|*
argument_list|,
name|long
operator|*
argument_list|)
decl_stmt|,
name|tninit
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|upcase
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|willoption
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|wontoption
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_do
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|send_dont
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|send_will
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|send_wont
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|lm_will
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|lm_wont
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|lm_do
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|lm_dont
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|lm_mode
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|slc_init
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|slcstate
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|slc_mode_export
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|slc_mode_import
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|slc_import
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|slc_export
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|slc
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|slc_check
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|slc_start_reply
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|slc_add_reply
argument_list|(
name|unsigned
name|char
argument_list|,
name|unsigned
name|char
argument_list|,
name|cc_t
argument_list|)
decl_stmt|,
name|slc_end_reply
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getconnmode
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|opt_welldefined
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|,
name|NetClose
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|netflush
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|process_rings
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|rlogin_susp
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|SetSockOpt
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|slc_update
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|stilloob
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|telrcv
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|TerminalRead
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|TerminalWrite
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|TerminalAutoFlush
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|TerminalWindowSize
argument_list|(
name|long
operator|*
argument_list|,
name|long
operator|*
argument_list|)
decl_stmt|,
name|TerminalSpecialChars
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tn
argument_list|(
name|int
argument_list|,
name|char
operator|*
operator|*
argument_list|)
decl_stmt|,
name|ttyflush
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|env_opt
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|env_opt_start
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|env_opt_start_info
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|env_opt_add
argument_list|(
name|unsigned
name|char
operator|*
argument_list|)
decl_stmt|,
name|env_opt_end
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|env_default
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
modifier|*
name|env_getvalue
argument_list|(
specifier|const
name|unsigned
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_status
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|dosynch
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|cc_t
modifier|*
name|tcval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|cc_t
name|termForw2Char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cc_t
name|termAytChar
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

begin_define
define|#
directive|define
name|termAytCharp
value|(cc_t *)&termAytChar
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
name|cc_t
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VFLUSHO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VDISCARD
argument_list|)
end_if

begin_define
define|#
directive|define
name|VDISCARD
value|VFLUSHO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VDISCARD
end_ifndef

begin_decl_stmt
specifier|extern
name|cc_t
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
value|new_tc.c_cc[VDISCARD]
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
name|cc_t
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
name|cc_t
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
name|cc_t
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
name|cc_t
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
name|cc_t
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
name|cc_t
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
name|cc_t
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
name|VSTATUS
end_ifndef

begin_decl_stmt
specifier|extern
name|cc_t
name|termAytChar
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|termAytChar
value|new_tc.c_cc[VSTATUS]
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
name|__STDC__
argument_list|)
end_if

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

begin_define
define|#
directive|define
name|termAytCharp
value|&termAytChar
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

begin_define
define|#
directive|define
name|termAytCharp
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

begin_decl_stmt
specifier|extern
name|void
name|xmitAO
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|xmitEC
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|xmitEL
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

