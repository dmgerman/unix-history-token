begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)dbg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Screen debug flags  */
end_comment

begin_define
define|#
directive|define
name|DPAUSE
value|0x0001
end_define

begin_comment
comment|/* wait for key press */
end_comment

begin_define
define|#
directive|define
name|DALLTRAPS
value|0x0002
end_define

begin_comment
comment|/* print on alltraps */
end_comment

begin_define
define|#
directive|define
name|DALLSYSC
value|0x0004
end_define

begin_comment
comment|/* print on allsystem calls */
end_comment

begin_define
define|#
directive|define
name|DSYSFAIL
value|0x0008
end_define

begin_comment
comment|/* print on system call failures */
end_comment

begin_define
define|#
directive|define
name|DPAGIN
value|0x0010
end_define

begin_comment
comment|/* print on pagin activity */
end_comment

begin_define
define|#
directive|define
name|DEXEC
value|0x0020
end_define

begin_comment
comment|/* print on exec activity */
end_comment

begin_define
define|#
directive|define
name|DNAMEI
value|0x0040
end_define

begin_comment
comment|/* print on namei activity */
end_comment

begin_define
define|#
directive|define
name|DEXPAND
value|0x0080
end_define

begin_comment
comment|/* print on segment expand activity */
end_comment

begin_define
define|#
directive|define
name|DCLK
value|0x0100
end_define

begin_comment
comment|/* print on clock activity */
end_comment

begin_define
define|#
directive|define
name|DDSK
value|0x0200
end_define

begin_comment
comment|/* print on disk activity */
end_comment

begin_define
define|#
directive|define
name|DSIGNAL
value|0x0400
end_define

begin_comment
comment|/* print on signal delivery */
end_comment

end_unit

