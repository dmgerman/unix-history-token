begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ttychars.h	7.2 (Berkeley) 12/18/87  */
end_comment

begin_comment
comment|/*  * User visible structures and constants  * related to terminal handling.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTYCHARS_
end_ifndef

begin_define
define|#
directive|define
name|_TTYCHARS_
end_define

begin_struct
struct|struct
name|ttychars
block|{
name|char
name|tc_erase
decl_stmt|;
comment|/* erase last character */
name|char
name|tc_kill
decl_stmt|;
comment|/* erase entire line */
name|char
name|tc_intrc
decl_stmt|;
comment|/* interrupt */
name|char
name|tc_quitc
decl_stmt|;
comment|/* quit */
name|char
name|tc_startc
decl_stmt|;
comment|/* start output */
name|char
name|tc_stopc
decl_stmt|;
comment|/* stop output */
name|char
name|tc_eofc
decl_stmt|;
comment|/* end-of-file */
name|char
name|tc_brkc
decl_stmt|;
comment|/* input delimiter (like nl) */
name|char
name|tc_suspc
decl_stmt|;
comment|/* stop process signal */
name|char
name|tc_dsuspc
decl_stmt|;
comment|/* delayed stop process signal */
name|char
name|tc_rprntc
decl_stmt|;
comment|/* reprint line */
name|char
name|tc_flushc
decl_stmt|;
comment|/* flush output (toggles) */
name|char
name|tc_werasc
decl_stmt|;
comment|/* word erase */
name|char
name|tc_lnextc
decl_stmt|;
comment|/* literal next character */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|(c&037)
end_define

begin_comment
comment|/* default special characters */
end_comment

begin_define
define|#
directive|define
name|CERASE
value|0177
end_define

begin_define
define|#
directive|define
name|CKILL
value|CTRL('u')
end_define

begin_define
define|#
directive|define
name|CINTR
value|CTRL('c')
end_define

begin_define
define|#
directive|define
name|CQUIT
value|034
end_define

begin_comment
comment|/* FS, ^\ */
end_comment

begin_define
define|#
directive|define
name|CSTART
value|CTRL('q')
end_define

begin_define
define|#
directive|define
name|CSTOP
value|CTRL('s')
end_define

begin_define
define|#
directive|define
name|CEOF
value|CTRL('d')
end_define

begin_define
define|#
directive|define
name|CEOT
value|CEOF
end_define

begin_define
define|#
directive|define
name|CBRK
value|0377
end_define

begin_define
define|#
directive|define
name|CSUSP
value|CTRL('z')
end_define

begin_define
define|#
directive|define
name|CDSUSP
value|CTRL('y')
end_define

begin_define
define|#
directive|define
name|CRPRNT
value|CTRL('r')
end_define

begin_define
define|#
directive|define
name|CFLUSH
value|CTRL('o')
end_define

begin_define
define|#
directive|define
name|CWERASE
value|CTRL('w')
end_define

begin_define
define|#
directive|define
name|CLNEXT
value|CTRL('v')
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

