begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell. This file is derived from the MIPS RISC  * Architecture book by Gerry Kane.  *  * %sccs.include.redist.c%  *  *	@(#)regdef.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|zero
value|$0
end_define

begin_comment
comment|/* always zero */
end_comment

begin_define
define|#
directive|define
name|AT
value|$at
end_define

begin_comment
comment|/* assembler temp */
end_comment

begin_define
define|#
directive|define
name|v0
value|$2
end_define

begin_comment
comment|/* return value */
end_comment

begin_define
define|#
directive|define
name|v1
value|$3
end_define

begin_define
define|#
directive|define
name|a0
value|$4
end_define

begin_comment
comment|/* argument registers */
end_comment

begin_define
define|#
directive|define
name|a1
value|$5
end_define

begin_define
define|#
directive|define
name|a2
value|$6
end_define

begin_define
define|#
directive|define
name|a3
value|$7
end_define

begin_define
define|#
directive|define
name|t0
value|$8
end_define

begin_comment
comment|/* temp registers (not saved across subroutine calls) */
end_comment

begin_define
define|#
directive|define
name|t1
value|$9
end_define

begin_define
define|#
directive|define
name|t2
value|$10
end_define

begin_define
define|#
directive|define
name|t3
value|$11
end_define

begin_define
define|#
directive|define
name|t4
value|$12
end_define

begin_define
define|#
directive|define
name|t5
value|$13
end_define

begin_define
define|#
directive|define
name|t6
value|$14
end_define

begin_define
define|#
directive|define
name|t7
value|$15
end_define

begin_define
define|#
directive|define
name|s0
value|$16
end_define

begin_comment
comment|/* saved across subroutine calls (callee saved) */
end_comment

begin_define
define|#
directive|define
name|s1
value|$17
end_define

begin_define
define|#
directive|define
name|s2
value|$18
end_define

begin_define
define|#
directive|define
name|s3
value|$19
end_define

begin_define
define|#
directive|define
name|s4
value|$20
end_define

begin_define
define|#
directive|define
name|s5
value|$21
end_define

begin_define
define|#
directive|define
name|s6
value|$22
end_define

begin_define
define|#
directive|define
name|s7
value|$23
end_define

begin_define
define|#
directive|define
name|t8
value|$24
end_define

begin_comment
comment|/* two more temp registers */
end_comment

begin_define
define|#
directive|define
name|t9
value|$25
end_define

begin_define
define|#
directive|define
name|k0
value|$26
end_define

begin_comment
comment|/* kernel temporary */
end_comment

begin_define
define|#
directive|define
name|k1
value|$27
end_define

begin_define
define|#
directive|define
name|gp
value|$28
end_define

begin_comment
comment|/* global pointer */
end_comment

begin_define
define|#
directive|define
name|sp
value|$29
end_define

begin_comment
comment|/* stack pointer */
end_comment

begin_define
define|#
directive|define
name|s8
value|$30
end_define

begin_comment
comment|/* one more callee saved */
end_comment

begin_define
define|#
directive|define
name|ra
value|$31
end_define

begin_comment
comment|/* return address */
end_comment

end_unit

