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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_BSD_SETJMP
argument_list|)
end_if

begin_include
include|#
directive|include
file|<bsdsetjmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FILIO_H
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

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STRING_H
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|CRAY
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* outside this world */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CRAY */
end_comment

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
name|In3270
decl_stmt|,
comment|/* Are we in 3270 mode? */
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

begin_ifdef
ifdef|#
directive|ifdef
name|ENCRYPTION
end_ifdef

begin_extern
extern|extern void (*encrypt_output
end_extern

begin_expr_stmt
unit|)
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*decrypt_input
end_extern

begin_expr_stmt
unit|)
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENCRYPTION */
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

begin_decl_stmt
specifier|extern
name|void
name|SetNetTrace
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|Dump
name|P
argument_list|(
operator|(
name|int
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|ExitString
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|init_3270
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|printoption
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|printsub
name|P
argument_list|(
operator|(
name|int
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|sendnaws
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|setconnmode
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|,
name|setcommandmode
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|setneturg
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|sys_telnet_init
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|telnet
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|,
name|tel_enter_binary
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|,
name|TerminalFlushOutput
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|TerminalNewMode
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|,
name|TerminalRestoreState
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|TerminalSaveState
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|tninit
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|upcase
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|,
name|willoption
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|,
name|wontoption
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_do
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|send_dont
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|send_will
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|send_wont
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|lm_will
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|lm_wont
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|lm_do
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|lm_dont
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|lm_mode
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|slc_init
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|slcstate
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|slc_mode_export
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|slc_mode_import
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|,
name|slc_import
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|,
name|slc_export
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|slc
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|slc_check
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|slc_start_reply
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|slc_add_reply
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|slc_end_reply
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|NetClose
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|,
name|netflush
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|SetSockOpt
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|slc_update
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|telrcv
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|TerminalWrite
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|TerminalAutoFlush
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|ttyflush
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|env_opt
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|env_opt_start
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|env_opt_start_info
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|env_opt_add
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|,
name|env_opt_end
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|env_default
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|env_getvalue
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_status
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|dosynch
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cc_t
modifier|*
name|tcval
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
operator|!
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|||
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

begin_decl_stmt
specifier|extern
name|int
name|settranscom
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|inputAvailable
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(TN3270) */
end_comment

end_unit

