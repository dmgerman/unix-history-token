begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University,  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)pmaxtype.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Mother board type byte of "systype" environment variable.  */
end_comment

begin_define
define|#
directive|define
name|DS_PMAX
value|0x1
end_define

begin_comment
comment|/* DECstation 2100/3100 */
end_comment

begin_define
define|#
directive|define
name|DS_3MAX
value|0x2
end_define

begin_comment
comment|/* DECstation 5000/200 */
end_comment

begin_define
define|#
directive|define
name|DS_3MIN
value|0x3
end_define

begin_comment
comment|/* DECstation 5000/1xx */
end_comment

begin_define
define|#
directive|define
name|DS_LSIS
value|0x5
end_define

begin_comment
comment|/* DECsystem 5800 */
end_comment

begin_define
define|#
directive|define
name|DS_MIPSFAIR
value|0x6
end_define

begin_comment
comment|/* DECsystem 5400 */
end_comment

begin_define
define|#
directive|define
name|DS_MAXINE
value|0x7
end_define

begin_comment
comment|/* Personal DECstation 5000/xx */
end_comment

begin_define
define|#
directive|define
name|DS_3MAXPLUS
value|0x8
end_define

begin_comment
comment|/* DECstation 5000/240 (JUST A GUESS) */
end_comment

begin_define
define|#
directive|define
name|DS_MIPSFAIR2
value|0xb
end_define

begin_comment
comment|/* DECsystem 5500 */
end_comment

begin_define
define|#
directive|define
name|DS_MIPSMATE
value|0xc
end_define

begin_comment
comment|/* DECsystem 5100 */
end_comment

end_unit

