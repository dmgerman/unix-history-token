begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)memreg.h	7.3 (Berkeley) %G%  *  * from: $Header: memreg.h,v 1.6 92/11/26 03:05:05 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Sun-4c memory error register.  * The register is a single word.  */
end_comment

begin_decl_stmt
specifier|volatile
name|int
modifier|*
name|par_err_reg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* virtual address; NULL if not yet mapped */
end_comment

begin_comment
comment|/*  * Bits in parity error register.  * The register is cleared when read, except for the test and enable bits.  */
end_comment

begin_define
define|#
directive|define
name|PER_ERR
value|0x80
end_define

begin_comment
comment|/* a parity error occurred */
end_comment

begin_define
define|#
directive|define
name|PER_MULTI
value|0x40
end_define

begin_comment
comment|/* more than one occurred */
end_comment

begin_define
define|#
directive|define
name|PER_TEST
value|0x20
end_define

begin_comment
comment|/* test (invert parity) */
end_comment

begin_define
define|#
directive|define
name|PER_ENABLE
value|0x10
end_define

begin_comment
comment|/* enable parity error reports */
end_comment

begin_define
define|#
directive|define
name|PER_BYTE0
value|0x08
end_define

begin_comment
comment|/* error occurred in byte 0 (bits 31..24) */
end_comment

begin_define
define|#
directive|define
name|PER_BYTE1
value|0x04
end_define

begin_comment
comment|/* error occurred in byte 1 (bits 23..16) */
end_comment

begin_define
define|#
directive|define
name|PER_BYTE2
value|0x02
end_define

begin_comment
comment|/* error occurred in byte 2 (bits 15..8) */
end_comment

begin_define
define|#
directive|define
name|PER_BYTE3
value|0x01
end_define

begin_comment
comment|/* error occurred in byte 3 (bits 7..0) */
end_comment

begin_define
define|#
directive|define
name|PER_BITS
value|"\20\10ERR\7MULTI\6TEST\5ENABLE\4BYTE0\3BYTE1\2BYTE2\1BYTE3"
end_define

end_unit

