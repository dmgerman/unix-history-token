begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)psl.h	7.2 (Berkeley) 12/10/87  */
end_comment

begin_comment
comment|/*  * VAX program status longword  */
end_comment

begin_define
define|#
directive|define
name|PSL_C
value|0x00000001
end_define

begin_comment
comment|/* carry bit */
end_comment

begin_define
define|#
directive|define
name|PSL_V
value|0x00000002
end_define

begin_comment
comment|/* overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSL_Z
value|0x00000004
end_define

begin_comment
comment|/* zero bit */
end_comment

begin_define
define|#
directive|define
name|PSL_N
value|0x00000008
end_define

begin_comment
comment|/* negative bit */
end_comment

begin_define
define|#
directive|define
name|PSL_ALLCC
value|0x0000000f
end_define

begin_comment
comment|/* all cc bits - unlikely */
end_comment

begin_define
define|#
directive|define
name|PSL_T
value|0x00000010
end_define

begin_comment
comment|/* trace enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_IV
value|0x00000020
end_define

begin_comment
comment|/* integer overflow enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_FU
value|0x00000040
end_define

begin_comment
comment|/* floating point underflow enable */
end_comment

begin_define
define|#
directive|define
name|PSL_DV
value|0x00000080
end_define

begin_comment
comment|/* decimal overflow enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL
value|0x001f0000
end_define

begin_comment
comment|/* interrupt priority level */
end_comment

begin_define
define|#
directive|define
name|PSL_PRVMOD
value|0x00c00000
end_define

begin_comment
comment|/* previous mode (all on is user) */
end_comment

begin_define
define|#
directive|define
name|PSL_CURMOD
value|0x03000000
end_define

begin_comment
comment|/* current mode (all on is user) */
end_comment

begin_define
define|#
directive|define
name|PSL_IS
value|0x04000000
end_define

begin_comment
comment|/* interrupt stack */
end_comment

begin_define
define|#
directive|define
name|PSL_FPD
value|0x08000000
end_define

begin_comment
comment|/* first part done */
end_comment

begin_define
define|#
directive|define
name|PSL_TP
value|0x40000000
end_define

begin_comment
comment|/* trace pending */
end_comment

begin_define
define|#
directive|define
name|PSL_CM
value|0x80000000
end_define

begin_comment
comment|/* compatibility mode */
end_comment

begin_define
define|#
directive|define
name|PSL_MBZ
value|0x3020ff00
end_define

begin_comment
comment|/* must be zero bits */
end_comment

begin_define
define|#
directive|define
name|PSL_USERSET
value|(PSL_PRVMOD|PSL_CURMOD)
end_define

begin_define
define|#
directive|define
name|PSL_USERCLR
value|(PSL_IS|PSL_IPL|PSL_MBZ)
end_define

begin_define
define|#
directive|define
name|PSL_CM_CLR
value|(PSL_FPD|PSL_DV|PSL_FU|PSL_IV)
end_define

end_unit

