begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)cgthreereg.h	8.2 (Berkeley) %G%  *  * from: $Header: cgthreereg.h,v 1.7 93/10/31 05:09:28 torek Exp $  */
end_comment

begin_comment
comment|/*  * cgthree display registers.  Much like bwtwo registers, except that  * there is a Brooktree Video DAC in there (so we also use btreg.h).  */
end_comment

begin_comment
comment|/* offsets */
end_comment

begin_define
define|#
directive|define
name|CG3REG_ID
value|0
end_define

begin_define
define|#
directive|define
name|CG3REG_REG
value|0x400000
end_define

begin_define
define|#
directive|define
name|CG3REG_MEM
value|0x800000
end_define

begin_comment
comment|/* same, but for gdb */
end_comment

begin_struct
struct|struct
name|cgthree_all
block|{
name|long
name|ba_id
decl_stmt|;
comment|/* ID = 0xfe010104 on my IPC */
name|char
name|ba_xxx0
index|[
literal|0x400000
operator|-
literal|4
index|]
decl_stmt|;
name|struct
name|bt_regs
name|ba_btreg
decl_stmt|;
comment|/* Brooktree registers */
name|char
name|ba_xxx1
index|[
literal|0x400000
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|bt_regs
argument_list|)
index|]
decl_stmt|;
name|char
name|ba_ram
index|[
literal|4096
index|]
decl_stmt|;
comment|/* actually larger */
block|}
struct|;
end_struct

end_unit

