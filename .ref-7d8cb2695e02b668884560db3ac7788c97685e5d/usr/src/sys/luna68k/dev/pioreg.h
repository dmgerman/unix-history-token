begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)pioreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * PIO definitions  * OMRON: $Id: pioreg.h,v 1.1 92/05/27 14:33:18 moti Exp $  * by Shigeto Mochida   */
end_comment

begin_define
define|#
directive|define
name|PIO0_ADDR
value|0x49000000
end_define

begin_comment
comment|/* pio0 address */
end_comment

begin_define
define|#
directive|define
name|PIO1_ADDR
value|0x4D000000
end_define

begin_comment
comment|/* pio1 address */
end_comment

begin_define
define|#
directive|define
name|PIO_MODED
value|0xB6
end_define

begin_comment
comment|/* pio mode set */
end_comment

begin_struct
struct|struct
name|pio
block|{
name|unsigned
name|char
name|a_port
decl_stmt|;
name|unsigned
name|char
name|b_port
decl_stmt|;
name|unsigned
name|char
name|c_port
decl_stmt|;
name|unsigned
name|char
name|control_port
decl_stmt|;
block|}
struct|;
end_struct

end_unit

