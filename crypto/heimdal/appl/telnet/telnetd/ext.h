begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ext.h	8.2 (Berkeley) 12/15/93  */
end_comment

begin_comment
comment|/* $Id: ext.h,v 1.20 2000/11/15 23:03:38 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXT_H__
end_ifndef

begin_define
define|#
directive|define
name|__EXT_H__
end_define

begin_comment
comment|/*  * Telnet server variable declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|options
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|do_dont_resp
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|will_wont_resp
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flowmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current flow control state */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|restartany
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restart output on any character state */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTICS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|diagnostic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* telnet diagnostic capabilities */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIAGNOSTICS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|require_otp
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|AUTHENTICATION
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|auth_level
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|new_login
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|slcfun
name|slctab
index|[
name|NSLC
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* slc mapping table */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|terminaltype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * I/O data buffers, pointers, and counters.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ptyobuf
index|[
name|BUFSIZ
operator|+
name|NETSLOP
index|]
decl_stmt|,
modifier|*
name|pfrontp
decl_stmt|,
modifier|*
name|pbackp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|netibuf
index|[
name|BUFSIZ
index|]
decl_stmt|,
modifier|*
name|netip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|netobuf
index|[
name|BUFSIZ
operator|+
name|NETSLOP
index|]
decl_stmt|,
modifier|*
name|nfrontp
decl_stmt|,
modifier|*
name|nbackp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|neturg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one past last bye of urgent data */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pcc
decl_stmt|,
name|ncc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ourpty
decl_stmt|,
name|net
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SYNCHing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we are in TELNET SYNCH mode */
end_comment

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

begin_function_decl
name|void
name|get_slc_defaults
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|telrcv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_do
parameter_list|(
name|int
name|option
parameter_list|,
name|int
name|init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|willoption
parameter_list|(
name|int
name|option
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_dont
parameter_list|(
name|int
name|option
parameter_list|,
name|int
name|init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wontoption
parameter_list|(
name|int
name|option
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_will
parameter_list|(
name|int
name|option
parameter_list|,
name|int
name|init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dooption
parameter_list|(
name|int
name|option
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_wont
parameter_list|(
name|int
name|option
parameter_list|,
name|int
name|init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dontoption
parameter_list|(
name|int
name|option
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|suboption
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|doclientstat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_termbuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_termbuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|spcset
parameter_list|(
name|int
name|func
parameter_list|,
name|cc_t
modifier|*
name|valp
parameter_list|,
name|cc_t
modifier|*
modifier|*
name|valpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_utid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpty
parameter_list|(
name|int
modifier|*
name|ptynum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_isecho
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_flowmode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_restartany
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_setecho
parameter_list|(
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_israw
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_binaryin
parameter_list|(
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_binaryout
parameter_list|(
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_isbinaryin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_isbinaryout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_issofttab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_setsofttab
parameter_list|(
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_islitecho
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_setlitecho
parameter_list|(
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_iscrnl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_tspeed
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_rspeed
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getptyslave
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cleanopen
parameter_list|(
name|char
modifier|*
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|startslave
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|int
name|autologin
parameter_list|,
name|char
modifier|*
name|autoname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_env
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_login
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|int
name|autologin
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cleanup
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|main
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
name|int
name|getterminaltype
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_gettermname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|terminaltypeok
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|my_telnet
parameter_list|(
name|int
name|f
parameter_list|,
name|int
name|p
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|interrupt
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
name|sendsusp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|recv_ayt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|doeof
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flowstat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clientstat
parameter_list|(
name|int
name|code
parameter_list|,
name|int
name|parm1
parameter_list|,
name|int
name|parm2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ttloop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stilloob
parameter_list|(
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ptyflush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|nextitem
parameter_list|(
name|char
modifier|*
name|current
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netclear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netflush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writenet
parameter_list|(
name|unsigned
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
name|int
name|f
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatalperror
parameter_list|(
name|int
name|f
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|edithost
parameter_list|(
name|char
modifier|*
name|pat
parameter_list|,
name|char
modifier|*
name|host
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putstr
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putchr
parameter_list|(
name|int
name|cc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putf
parameter_list|(
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printoption
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
name|int
name|option
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
name|printdata
parameter_list|(
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_tty
parameter_list|(
name|int
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ENCRYPTION
end_ifdef

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nclearto
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following are some clocks used to decide how to interpret  * the relationship between various variables.  */
end_comment

begin_struct
struct|struct
name|clocks_t
block|{
name|int
name|system
decl_stmt|,
comment|/* what the current time is */
name|echotoggle
decl_stmt|,
comment|/* last time user entered echo character */
name|modenegotiated
decl_stmt|,
comment|/* last time operating mode negotiated */
name|didnetreceive
decl_stmt|,
comment|/* last time we read data from network */
name|ttypesubopt
decl_stmt|,
comment|/* ttype subopt is received */
name|tspeedsubopt
decl_stmt|,
comment|/* tspeed subopt is received */
name|environsubopt
decl_stmt|,
comment|/* environ subopt is received */
name|oenvironsubopt
decl_stmt|,
comment|/* old environ subopt is received */
name|xdisplocsubopt
decl_stmt|,
comment|/* xdisploc subopt is received */
name|baseline
decl_stmt|,
comment|/* time started to do timed action */
name|gotDM
decl_stmt|;
comment|/* when did we last see a data mark */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|clocks_t
name|clocks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|log_unauth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_warn
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMSPTY
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|really_stream
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_IM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_define
define|#
directive|define
name|USE_IM
value|"Cray UNICOS (%h) (%t)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_define
define|#
directive|define
name|USE_IM
value|"%s %v.%r (%h) (%t)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_IM
end_ifndef

begin_define
define|#
directive|define
name|USE_IM
value|"%s %r (%h) (%t)"
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
name|DEFAULT_IM
value|"\r\n\r\n" USE_IM "\r\n\r\n\r\n"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EXT_H__ */
end_comment

end_unit

