begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)psl.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * MC68000 program status word  */
end_comment

begin_define
define|#
directive|define
name|PSL_C
value|0x0001
end_define

begin_comment
comment|/* carry bit */
end_comment

begin_define
define|#
directive|define
name|PSL_V
value|0x0002
end_define

begin_comment
comment|/* overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSL_Z
value|0x0004
end_define

begin_comment
comment|/* zero bit */
end_comment

begin_define
define|#
directive|define
name|PSL_N
value|0x0008
end_define

begin_comment
comment|/* negative bit */
end_comment

begin_define
define|#
directive|define
name|PSL_X
value|0x0010
end_define

begin_comment
comment|/* extend bit */
end_comment

begin_define
define|#
directive|define
name|PSL_ALLCC
value|0x001F
end_define

begin_comment
comment|/* all cc bits - unlikely */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL0
value|0x0000
end_define

begin_comment
comment|/* interrupt priority level 0 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL1
value|0x0100
end_define

begin_comment
comment|/* interrupt priority level 1 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL2
value|0x0200
end_define

begin_comment
comment|/* interrupt priority level 2 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL3
value|0x0300
end_define

begin_comment
comment|/* interrupt priority level 3 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL4
value|0x0400
end_define

begin_comment
comment|/* interrupt priority level 4 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL5
value|0x0500
end_define

begin_comment
comment|/* interrupt priority level 5 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL6
value|0x0600
end_define

begin_comment
comment|/* interrupt priority level 6 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL7
value|0x0700
end_define

begin_comment
comment|/* interrupt priority level 7 */
end_comment

begin_define
define|#
directive|define
name|PSL_S
value|0x2000
end_define

begin_comment
comment|/* supervisor enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_T
value|0x8000
end_define

begin_comment
comment|/* trace enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_LOWIPL
value|(PSL_S)
end_define

begin_define
define|#
directive|define
name|PSL_HIGHIPL
value|(PSL_S | PSL_IPL7)
end_define

begin_define
define|#
directive|define
name|PSL_IPL
value|(PSL_IPL7)
end_define

begin_define
define|#
directive|define
name|PSL_USER
value|(0)
end_define

begin_define
define|#
directive|define
name|PSL_MBZ
value|0x58E0
end_define

begin_comment
comment|/* must be zero bits */
end_comment

begin_define
define|#
directive|define
name|PSL_USERSET
value|(0)
end_define

begin_define
define|#
directive|define
name|PSL_USERCLR
value|(PSL_S | PSL_IPL7 | PSL_MBZ)
end_define

end_unit

