begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)bwtworeg.h	7.3 (Berkeley) %G%  *  * from: $Header: bwtworeg.h,v 1.4 92/11/26 02:28:05 torek Exp $  */
end_comment

begin_comment
comment|/*  * bwtwo display registers.  *  * The registers start at offset 0x400000 and repeat every 32 bytes  * (presumably only the low order address lines are decoded).  Video RAM  * starts at offset 0x800000.  We use separate pointers to each so that  * the sparc addressing modes work well.  */
end_comment

begin_struct
struct|struct
name|bwtworeg
block|{
comment|/* 	 * The xxx0 range is all 0xff on my IPC but causes a screen glitch 	 * on my SS1+, so it must do *some*thing... the xxx1 range is full 	 * of values but I do not know what they are.  bw_ctl changes for 	 * a blanked screen. 	 */
name|char
name|bw_xxx0
index|[
literal|16
index|]
decl_stmt|;
name|u_char
name|bw_ctl
decl_stmt|;
comment|/* contains video enable */
name|char
name|bw_xxx1
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bits in bw_ctl */
end_comment

begin_define
define|#
directive|define
name|CTL_VE
value|0x40
end_define

begin_comment
comment|/* video enable */
end_comment

begin_comment
comment|/* offsets */
end_comment

begin_define
define|#
directive|define
name|BWREG_ID
value|0
end_define

begin_define
define|#
directive|define
name|BWREG_REG
value|0x400000
end_define

begin_define
define|#
directive|define
name|BWREG_MEM
value|0x800000
end_define

begin_comment
comment|/* same, but for gdb */
end_comment

begin_struct
struct|struct
name|bwtwo_all
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
name|bwtworeg
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

