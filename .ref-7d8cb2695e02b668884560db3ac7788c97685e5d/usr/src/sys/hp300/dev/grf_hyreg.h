begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Mark Davies of the Department of Computer  * Science, Victoria University of Wellington, New Zealand.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: grf_hyreg.h 1.1 92/01/22$  *  *	@(#)grf_hyreg.h	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<hp/dev/iotypes.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_struct
struct|struct
name|hyboxfb
block|{
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|reset
decl_stmt|;
comment|/* reset register		0x01 */
name|vu_char
name|fb_address
decl_stmt|;
comment|/* frame buffer address 	0x02 */
name|vu_char
name|interrupt
decl_stmt|;
comment|/* interrupt register		0x03 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbwmsb
decl_stmt|;
comment|/* frame buffer width MSB	0x05 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbwlsb
decl_stmt|;
comment|/* frame buffer width MSB	0x07 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbhmsb
decl_stmt|;
comment|/* frame buffer height MSB	0x09 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbhlsb
decl_stmt|;
comment|/* frame buffer height MSB	0x0b */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|dwmsb
decl_stmt|;
comment|/* display width MSB		0x0d */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|dwlsb
decl_stmt|;
comment|/* display width MSB		0x0f */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|dhmsb
decl_stmt|;
comment|/* display height MSB		0x11 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|dhlsb
decl_stmt|;
comment|/* display height MSB		0x13 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbid
decl_stmt|;
comment|/* Scondary frame buffer id	0x15 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|bits
decl_stmt|;
comment|/* square(0)/double-high(1) 	0x17 */
name|u_char
name|f1
index|[
literal|0x5b
operator|-
literal|0x17
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|num_planes
decl_stmt|;
comment|/* number of color planes       0x5b */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbomsb
decl_stmt|;
comment|/* frame buffer offset MSB	0x5d */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbolsb
decl_stmt|;
comment|/* frame buffer offset LSB	0x5f */
name|u_char
name|f2
index|[
literal|0x4000
operator|-
literal|0x5f
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|nblank
decl_stmt|;
comment|/* display enable planes      0x4000 */
block|}
struct|;
end_struct

end_unit

