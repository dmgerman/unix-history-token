begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ext.h	8.2 (Berkeley) 12/15/93  * $FreeBSD$  */
end_comment

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
name|linemode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* linemode on/off */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LINEMODE
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|uselinemode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what linemode to use (on/off) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|editmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* edit modes in use */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|useeditmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* edit modes to use */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alwayslinemode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command line option */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lmodetype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Client support for linemode */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINEMODE */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|BFTPDAEMON
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|bftpd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* behave as bftp daemon */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFTPDAEMON */
end_comment

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
name|pty
decl_stmt|,
name|net
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|line
index|[
literal|16
index|]
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

begin_decl_stmt
specifier|extern
name|void
name|_termstat
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|add_slc
argument_list|(
name|char
argument_list|,
name|char
argument_list|,
name|cc_t
argument_list|)
decl_stmt|,
name|check_slc
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|change_slc
argument_list|(
name|char
argument_list|,
name|char
argument_list|,
name|cc_t
argument_list|)
decl_stmt|,
name|cleanup
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|clientstat
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|copy_termbuf
argument_list|(
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
decl_stmt|,
name|deferslc
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|defer_terminit
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|do_opt_slc
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|doeof
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|dooption
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|dontoption
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|edithost
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|,
name|fatal
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|,
name|fatalperror
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|,
name|get_slc_defaults
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|init_env
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|init_termbuf
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|interrupt
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|localstat
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|flowstat
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|netclear
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|netflush
argument_list|(
name|void
argument_list|)
decl_stmt|,
ifdef|#
directive|ifdef
name|DIAGNOSTICS
name|printoption
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|printdata
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|char
operator|*
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
endif|#
directive|endif
name|process_slc
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
name|ptyflush
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|putchr
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|putf
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|,
name|recv_ayt
argument_list|(
name|void
argument_list|)
decl_stmt|,
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
name|send_slc
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|send_status
argument_list|(
name|void
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
decl_stmt|,
name|sendbrk
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sendsusp
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|set_termbuf
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|start_login
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|,
name|start_slc
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|start_slave
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|,
name|suboption
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|telrcv
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|ttloop
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_binaryin
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tty_binaryout
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|end_slc
argument_list|(
name|unsigned
name|char
operator|*
operator|*
argument_list|)
decl_stmt|,
name|getnpty
argument_list|(
name|void
argument_list|)
decl_stmt|,
ifndef|#
directive|ifndef
name|convex
name|getpty
argument_list|(
name|int
operator|*
argument_list|)
decl_stmt|,
endif|#
directive|endif
name|login_tty
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|spcset
argument_list|(
name|int
argument_list|,
name|cc_t
operator|*
argument_list|,
name|cc_t
operator|*
operator|*
argument_list|)
decl_stmt|,
name|stilloob
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|terminit
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|termstat
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_flowmode
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_restartany
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_isbinaryin
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_isbinaryout
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_iscrnl
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_isecho
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_isediting
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_islitecho
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_isnewmap
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_israw
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_issofttab
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_istrapsig
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|tty_linemode
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tty_rspeed
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tty_setecho
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tty_setedit
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tty_setlinemode
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tty_setlitecho
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tty_setsig
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tty_setsofttab
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|tty_tspeed
argument_list|(
name|int
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

begin_function_decl
name|int
name|output_data
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|output_datalen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|startslave
parameter_list|(
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

begin_comment
comment|/*  * The following are some clocks used to decide how to interpret  * the relationship between various variables.  */
end_comment

begin_struct
specifier|extern
struct|struct
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
name|clocks
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_IM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_IM
value|"\r\n\r\nULTRIX (%h) (%t)\r\n\r\r\n\r"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_IM
value|"\r\n\r\nFreeBSD (%h) (%t)\r\n\r\r\n\r"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_IM
value|"\r\n\r\n4.4 BSD UNIX (%h) (%t)\r\n\r\r\n\r"
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

end_unit

