begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)externs.h	8.3 (Berkeley) 5/30/95  */
end_comment

begin_comment
comment|/* $Id: externs.h,v 1.24 2001/12/20 20:39:52 joda Exp $ */
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
name|binary
decl_stmt|,
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
name|wantencryption
decl_stmt|,
comment|/* User has requested encryption */
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intr_happened
decl_stmt|,
name|intr_waiting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for interrupt handling */
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
name|do_dont_resp
index|[]
decl_stmt|,
name|will_wont_resp
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENCRYPTION
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|encrypt_output
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|decrypt_input
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Make everything symmetrical  */
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

begin_comment
comment|/* authenc.c */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AUTHENTICATION
argument_list|)
operator|||
name|defined
argument_list|(
name|ENCRYPTION
argument_list|)
end_if

begin_function_decl
name|int
name|telnet_net_write
parameter_list|(
name|unsigned
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|net_encrypt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|telnet_spin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|telnet_getenv
parameter_list|(
specifier|const
name|char
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|telnet_gets
parameter_list|(
name|char
modifier|*
name|prompt
parameter_list|,
name|char
modifier|*
name|result
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|echo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* commands.c */
end_comment

begin_function_decl
name|struct
name|env_lst
modifier|*
name|env_define
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|env_lst
modifier|*
name|env_find
parameter_list|(
name|unsigned
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_undefine
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_export
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_unexport
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_send
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|env_default
parameter_list|(
name|int
name|init
parameter_list|,
name|int
name|welldefined
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|env_getvalue
parameter_list|(
name|unsigned
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_escape_char
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sourceroute
parameter_list|(
name|struct
name|addrinfo
modifier|*
name|ai
parameter_list|,
name|char
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
modifier|*
name|cpp
parameter_list|,
name|int
modifier|*
name|prototp
parameter_list|,
name|int
modifier|*
name|optp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AUTHENTICATION
argument_list|)
end_if

begin_function_decl
name|int
name|auth_enable
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_disable
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENCRYPTION
argument_list|)
end_if

begin_function_decl
name|int
name|EncryptEnable
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptDisable
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptType
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptStart
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptStartInput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptStartOutput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptStop
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptStopInput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptStopOutput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EncryptStatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|RETSIGTYPE
name|ayt_status
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|tn
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|command
parameter_list|(
name|int
name|top
parameter_list|,
name|char
modifier|*
name|tbuf
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* main.c */
end_comment

begin_function_decl
name|void
name|tninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* network.c */
end_comment

begin_function_decl
name|void
name|init_network
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stilloob
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setneturg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netflush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sys_bsd.c */
end_comment

begin_function_decl
name|void
name|init_sys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|TerminalWrite
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|TerminalRead
parameter_list|(
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|TerminalAutoFlush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|TerminalSpecialChars
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalFlushOutput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalSaveState
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalDefaultChars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalNewMode
parameter_list|(
name|int
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cc_t
modifier|*
name|tcval
parameter_list|(
name|int
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalSpeeds
parameter_list|(
name|long
modifier|*
name|input_speed
parameter_list|,
name|long
modifier|*
name|output_speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|TerminalWindowSize
parameter_list|(
name|long
modifier|*
name|rows
parameter_list|,
name|long
modifier|*
name|cols
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|NetClose
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|NetNonblockingIO
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|onoff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|process_rings
parameter_list|(
name|int
name|netin
parameter_list|,
name|int
name|netout
parameter_list|,
name|int
name|netex
parameter_list|,
name|int
name|ttyin
parameter_list|,
name|int
name|ttyout
parameter_list|,
name|int
name|poll
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* telnet.c */
end_comment

begin_function_decl
name|void
name|init_telnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tel_leave_binary
parameter_list|(
name|int
name|rw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tel_enter_binary
parameter_list|(
name|int
name|rw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|opt_welldefined
parameter_list|(
name|char
modifier|*
name|ep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|telrcv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rlogin_susp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sendbrk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sendabort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sendsusp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sendeof
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sendayt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xmitAO
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xmitEL
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xmitEC
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Dump
parameter_list|(
name|char
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printoption
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printsub
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sendnaws
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setconnmode
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setcommandmode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setneturg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sys_telnet_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|my_telnet
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tel_enter_binary
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalFlushOutput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalNewMode
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalRestoreState
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TerminalSaveState
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|willoption
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wontoption
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_do
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_dont
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_will
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_wont
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lm_will
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lm_wont
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lm_do
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lm_dont
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lm_mode
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slcstate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_mode_export
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_mode_import
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_import
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_export
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_check
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_start_reply
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_add_reply
parameter_list|(
name|unsigned
name|char
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|cc_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slc_end_reply
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|slc_update
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_opt
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_opt_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_opt_start_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_opt_add
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|env_opt_end
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|env_default
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|env_getvalue
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dosynch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cc_t
modifier|*
name|tcval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* terminal.c */
end_comment

begin_function_decl
name|void
name|init_terminal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ttyflush
parameter_list|(
name|int
name|drop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getconnmode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* utilities.c */
end_comment

begin_function_decl
name|int
name|SetSockOpt
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|option
parameter_list|,
name|int
name|yesno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetNetTrace
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Dump
parameter_list|(
name|char
name|direction
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printoption
parameter_list|(
name|char
modifier|*
name|direction
parameter_list|,
name|int
name|cmd
parameter_list|,
name|int
name|option
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|optionstatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printsub
parameter_list|(
name|int
name|direction
parameter_list|,
name|unsigned
name|char
modifier|*
name|pointer
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmptyTerminal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetForExit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Exit
parameter_list|(
name|int
name|returnCode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ExitString
parameter_list|(
name|char
modifier|*
name|string
parameter_list|,
name|int
name|returnCode
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|termios
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
name|int
name|resettermname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linemode
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KLUDGELINEMODE
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|kludgelinemode
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|want_status_response
decl_stmt|;
end_decl_stmt

end_unit

