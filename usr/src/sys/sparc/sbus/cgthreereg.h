begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)cgthreereg.h	7.3 (Berkeley) %G%  *  * from: $Header: cgthreereg.h,v 1.5 92/11/26 02:28:07 torek Exp $  */
end_comment

begin_comment
comment|/*  * cgthree display registers.  *  * The registers start at offset 0x400000 and repeat every 32 bytes  * (presumably only the low order address lines are decoded).  Video RAM  * starts at offset 0x800000.  We use separate pointers to each so that  * the sparc addressing modes work well.  *  * The cg3 has a Brooktree Bt458 (?) chip to do everything (Brooktree  * makes the only decent color frame buffer chips).  To update the  * color map one would normally do byte writes, but the hardware  * takes longword writes.  Since there are three registers for each  * color map entry (R, then G, then B), we have to set color 1 with  * a write to address 0 (setting 0's R/G/B and color 1's R) followed  * by a second write to address 1 (setting color 1's G/B and color 2's  * R/G).  Software must therefore keep a copy of the current map.  *  * The colormap address register increments automatically, so the above  * write is done as:  *  *	p->cg3_cadr = 0;  *	p->cg3_cmap = R0G0B0R1;  *	p->cg3_cmap = G1B1R2G2;  *  * Yow!  */
end_comment

begin_struct
struct|struct
name|cgthreereg
block|{
name|u_int
name|cg3_addr
decl_stmt|;
comment|/* ?any? address register */
name|u_int
name|cg3_cmap
decl_stmt|;
comment|/* colormap data register */
name|u_int
name|cg3_ctrl
decl_stmt|;
comment|/* control register */
name|u_int
name|cg3_omap
decl_stmt|;
comment|/* overlay map register */
name|char
name|cg3_xxx0
index|[
literal|16
index|]
decl_stmt|;
comment|/* ? (make same size as bwtwo) */
block|}
struct|;
end_struct

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
name|cgthreereg
name|ba_reg
decl_stmt|;
comment|/* control registers */
name|char
name|ba_xxx1
index|[
literal|0x400000
operator|-
literal|32
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

