begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)from: init.c	8.1 (Berkeley) 6/4/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Getty table initializations.  *  * Melbourne getty.  */
end_comment

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_include
include|#
directive|include
file|"gettytab.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_decl_stmt
specifier|static
name|char
name|loginmsg
index|[]
init|=
literal|"login: "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|nullstr
index|[]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|loginprg
index|[]
init|=
name|_PATH_LOGIN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|datefmt
index|[]
init|=
literal|"%+"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|gettystrs
name|gettystrs
index|[]
init|=
block|{
block|{
literal|"nx"
block|}
block|,
comment|/* next table */
block|{
literal|"cl"
block|}
block|,
comment|/* screen clear characters */
block|{
literal|"im"
block|}
block|,
comment|/* initial message */
block|{
literal|"lm"
block|,
name|loginmsg
block|}
block|,
comment|/* login message */
block|{
literal|"er"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VERASE
index|]
block|}
block|,
comment|/* erase character */
block|{
literal|"kl"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VKILL
index|]
block|}
block|,
comment|/* kill character */
block|{
literal|"et"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VEOF
index|]
block|}
block|,
comment|/* eof chatacter (eot) */
block|{
literal|"pc"
block|,
name|nullstr
block|}
block|,
comment|/* pad character */
block|{
literal|"tt"
block|}
block|,
comment|/* terminal type */
block|{
literal|"ev"
block|}
block|,
comment|/* enviroment */
block|{
literal|"lo"
block|,
name|loginprg
block|}
block|,
comment|/* login program */
block|{
literal|"hn"
block|,
name|hostname
block|}
block|,
comment|/* host name */
block|{
literal|"he"
block|}
block|,
comment|/* host name edit */
block|{
literal|"in"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VINTR
index|]
block|}
block|,
comment|/* interrupt char */
block|{
literal|"qu"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VQUIT
index|]
block|}
block|,
comment|/* quit char */
block|{
literal|"xn"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VSTART
index|]
block|}
block|,
comment|/* XON (start) char */
block|{
literal|"xf"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VSTOP
index|]
block|}
block|,
comment|/* XOFF (stop) char */
block|{
literal|"bk"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VEOL
index|]
block|}
block|,
comment|/* brk char (alt \n) */
block|{
literal|"su"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VSUSP
index|]
block|}
block|,
comment|/* suspend char */
block|{
literal|"ds"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VDSUSP
index|]
block|}
block|,
comment|/* delayed suspend */
block|{
literal|"rp"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VREPRINT
index|]
block|}
block|,
comment|/* reprint char */
block|{
literal|"fl"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VDISCARD
index|]
block|}
block|,
comment|/* flush output */
block|{
literal|"we"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VWERASE
index|]
block|}
block|,
comment|/* word erase */
block|{
literal|"ln"
block|,
operator|&
name|tmode
operator|.
name|c_cc
index|[
name|VLNEXT
index|]
block|}
block|,
comment|/* literal next */
block|{
literal|"Lo"
block|}
block|,
comment|/* locale for strftime() */
block|{
literal|"pp"
block|}
block|,
comment|/* ppp login program */
block|{
literal|"if"
block|}
block|,
comment|/* sysv-like 'issue' filename */
block|{
literal|"ic"
block|}
block|,
comment|/* modem init-chat */
block|{
literal|"ac"
block|}
block|,
comment|/* modem answer-chat */
block|{
literal|"al"
block|}
block|,
comment|/* user to auto-login */
block|{
literal|"df"
block|,
name|datefmt
block|}
block|,
comment|/* format for strftime() */
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|gettynums
name|gettynums
index|[]
init|=
block|{
block|{
literal|"is"
block|}
block|,
comment|/* input speed */
block|{
literal|"os"
block|}
block|,
comment|/* output speed */
block|{
literal|"sp"
block|}
block|,
comment|/* both speeds */
block|{
literal|"nd"
block|}
block|,
comment|/* newline delay */
block|{
literal|"cd"
block|}
block|,
comment|/* carriage-return delay */
block|{
literal|"td"
block|}
block|,
comment|/* tab delay */
block|{
literal|"fd"
block|}
block|,
comment|/* form-feed delay */
block|{
literal|"bd"
block|}
block|,
comment|/* backspace delay */
block|{
literal|"to"
block|}
block|,
comment|/* timeout */
block|{
literal|"f0"
block|}
block|,
comment|/* output flags */
block|{
literal|"f1"
block|}
block|,
comment|/* input flags */
block|{
literal|"f2"
block|}
block|,
comment|/* user mode flags */
block|{
literal|"pf"
block|}
block|,
comment|/* delay before flush at 1st prompt */
block|{
literal|"c0"
block|}
block|,
comment|/* output c_flags */
block|{
literal|"c1"
block|}
block|,
comment|/* input c_flags */
block|{
literal|"c2"
block|}
block|,
comment|/* user mode c_flags */
block|{
literal|"i0"
block|}
block|,
comment|/* output i_flags */
block|{
literal|"i1"
block|}
block|,
comment|/* input i_flags */
block|{
literal|"i2"
block|}
block|,
comment|/* user mode i_flags */
block|{
literal|"l0"
block|}
block|,
comment|/* output l_flags */
block|{
literal|"l1"
block|}
block|,
comment|/* input l_flags */
block|{
literal|"l2"
block|}
block|,
comment|/* user mode l_flags */
block|{
literal|"o0"
block|}
block|,
comment|/* output o_flags */
block|{
literal|"o1"
block|}
block|,
comment|/* input o_flags */
block|{
literal|"o2"
block|}
block|,
comment|/* user mode o_flags */
block|{
literal|"de"
block|}
block|,
comment|/* delay before sending 1st prompt */
block|{
literal|"rt"
block|}
block|,
comment|/* reset timeout */
block|{
literal|"ct"
block|}
block|,
comment|/* chat script timeout */
block|{
literal|"dc"
block|}
block|,
comment|/* debug chat script value */
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|gettyflags
name|gettyflags
index|[]
init|=
block|{
block|{
literal|"ht"
block|,
literal|0
block|}
block|,
comment|/* has tabs */
block|{
literal|"nl"
block|,
literal|1
block|}
block|,
comment|/* has newline char */
block|{
literal|"ep"
block|,
literal|0
block|}
block|,
comment|/* even parity */
block|{
literal|"op"
block|,
literal|0
block|}
block|,
comment|/* odd parity */
block|{
literal|"ap"
block|,
literal|0
block|}
block|,
comment|/* any parity */
block|{
literal|"ec"
block|,
literal|1
block|}
block|,
comment|/* no echo */
block|{
literal|"co"
block|,
literal|0
block|}
block|,
comment|/* console special */
block|{
literal|"cb"
block|,
literal|0
block|}
block|,
comment|/* crt backspace */
block|{
literal|"ck"
block|,
literal|0
block|}
block|,
comment|/* crt kill */
block|{
literal|"ce"
block|,
literal|0
block|}
block|,
comment|/* crt erase */
block|{
literal|"pe"
block|,
literal|0
block|}
block|,
comment|/* printer erase */
block|{
literal|"rw"
block|,
literal|1
block|}
block|,
comment|/* don't use raw */
block|{
literal|"xc"
block|,
literal|1
block|}
block|,
comment|/* don't ^X ctl chars */
block|{
literal|"lc"
block|,
literal|0
block|}
block|,
comment|/* terminal las lower case */
block|{
literal|"uc"
block|,
literal|0
block|}
block|,
comment|/* terminal has no lower case */
block|{
literal|"ig"
block|,
literal|0
block|}
block|,
comment|/* ignore garbage */
block|{
literal|"ps"
block|,
literal|0
block|}
block|,
comment|/* do port selector speed select */
block|{
literal|"hc"
block|,
literal|1
block|}
block|,
comment|/* don't set hangup on close */
block|{
literal|"ub"
block|,
literal|0
block|}
block|,
comment|/* unbuffered output */
block|{
literal|"ab"
block|,
literal|0
block|}
block|,
comment|/* auto-baud detect with '\r' */
block|{
literal|"dx"
block|,
literal|0
block|}
block|,
comment|/* set decctlq */
block|{
literal|"np"
block|,
literal|0
block|}
block|,
comment|/* no parity at all (8bit chars) */
block|{
literal|"mb"
block|,
literal|0
block|}
block|,
comment|/* do MDMBUF flow control */
block|{
literal|"hw"
block|,
literal|0
block|}
block|,
comment|/* do CTSRTS flow control */
block|{
literal|"nc"
block|,
literal|0
block|}
block|,
comment|/* set clocal (no carrier) */
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

