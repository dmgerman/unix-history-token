begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ext.h	5.6 (Berkeley) 6/28/90  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KLUDGELINEMODE
end_ifdef

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
comment|/* KLUDGELINEMODE */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRAY2
argument_list|)
operator|&&
name|defined
argument_list|(
name|UNICOS5
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|unpcc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* characters left unprocessed by CRAY-2 terminal routine */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|unptyip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to remaining characters in buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTICS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|printoption
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|printdata
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRAY2
argument_list|)
operator|&&
name|defined
argument_list|(
name|UNICOS5
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|needtermstat
decl_stmt|;
end_decl_stmt

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
name|DEFAULT_IM
value|"\r\n\r\n4.3 BSD UNIX (%h) (%t)\r\n\r\r\n\r"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_IM
value|"\r\n\r\nCray UNICOS (%h) (%t)\r\n\r\r\n\r"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

