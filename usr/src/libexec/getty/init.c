begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)init.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Getty table initializations.  *  * Melbourne getty.  */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|"gettytab.h"
end_include

begin_decl_stmt
specifier|extern
name|struct
name|sgttyb
name|tmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tchars
name|tc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ltchars
name|ltc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
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
literal|"login: "
block|}
block|,
comment|/* login message */
block|{
literal|"er"
block|,
operator|&
name|tmode
operator|.
name|sg_erase
block|}
block|,
comment|/* erase character */
block|{
literal|"kl"
block|,
operator|&
name|tmode
operator|.
name|sg_kill
block|}
block|,
comment|/* kill character */
block|{
literal|"et"
block|,
operator|&
name|tc
operator|.
name|t_eofc
block|}
block|,
comment|/* eof chatacter (eot) */
block|{
literal|"pc"
block|,
literal|""
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
literal|"/bin/login"
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
name|tc
operator|.
name|t_intrc
block|}
block|,
comment|/* interrupt char */
block|{
literal|"qu"
block|,
operator|&
name|tc
operator|.
name|t_quitc
block|}
block|,
comment|/* quit char */
block|{
literal|"xn"
block|,
operator|&
name|tc
operator|.
name|t_startc
block|}
block|,
comment|/* XON (start) char */
block|{
literal|"xf"
block|,
operator|&
name|tc
operator|.
name|t_stopc
block|}
block|,
comment|/* XOFF (stop) char */
block|{
literal|"bk"
block|,
operator|&
name|tc
operator|.
name|t_brkc
block|}
block|,
comment|/* brk char (alt \n) */
block|{
literal|"su"
block|,
operator|&
name|ltc
operator|.
name|t_suspc
block|}
block|,
comment|/* suspend char */
block|{
literal|"ds"
block|,
operator|&
name|ltc
operator|.
name|t_dsuspc
block|}
block|,
comment|/* delayed suspend */
block|{
literal|"rp"
block|,
operator|&
name|ltc
operator|.
name|t_rprntc
block|}
block|,
comment|/* reprint char */
block|{
literal|"fl"
block|,
operator|&
name|ltc
operator|.
name|t_flushc
block|}
block|,
comment|/* flush output */
block|{
literal|"we"
block|,
operator|&
name|ltc
operator|.
name|t_werasc
block|}
block|,
comment|/* word erase */
block|{
literal|"ln"
block|,
operator|&
name|ltc
operator|.
name|t_lnextc
block|}
block|,
comment|/* literal next */
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
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

