begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: grf_tcreg.h 1.9 89/08/24$  *  *	@(#)grf_tcreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|tccm_waitbusy
parameter_list|(
name|regaddr
parameter_list|)
define|\
value|while (((struct tcboxfb *)(regaddr))->cmap_busy& 0x04) DELAY(100)
end_define

begin_define
define|#
directive|define
name|tc_waitbusy
parameter_list|(
name|regaddr
parameter_list|,
name|planes
parameter_list|)
define|\
value|while (((struct tcboxfb *)(regaddr))->busy& planes) DELAY(100)
end_define

begin_define
define|#
directive|define
name|vu_char
value|volatile u_char
end_define

begin_define
define|#
directive|define
name|vu_short
value|volatile u_short
end_define

begin_struct
struct|struct
name|tcboxfb
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
literal|0x4040
operator|-
literal|0x5f
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|vblank
decl_stmt|;
comment|/* vertical blanking	      0x4040 */
name|u_char
label|:
literal|8
operator|,
operator|:
literal|8
operator|,
operator|:
literal|8
expr_stmt|;
name|vu_char
name|busy
decl_stmt|;
comment|/* window move active	      0x4044 */
name|u_char
label|:
literal|8
operator|,
operator|:
literal|8
operator|,
operator|:
literal|8
expr_stmt|;
name|vu_char
name|vtrace_request
decl_stmt|;
comment|/* vert retrace intr request  0x4048 */
name|u_char
label|:
literal|8
operator|,
operator|:
literal|8
operator|,
operator|:
literal|8
expr_stmt|;
name|vu_char
name|move_request
decl_stmt|;
comment|/* window move intr request   0x404C */
name|u_char
name|f3
index|[
literal|0x4080
operator|-
literal|0x404c
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|nblank
decl_stmt|;
comment|/* display enable planes      0x4080 */
name|u_char
name|f4
index|[
literal|0x4088
operator|-
literal|0x4080
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|wen
decl_stmt|;
comment|/* write enable plane 	      0x4088 */
name|u_char
name|f5
index|[
literal|0x408c
operator|-
literal|0x4088
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|ren
decl_stmt|;
comment|/* read enable plane          0x408c */
name|u_char
name|f6
index|[
literal|0x4090
operator|-
literal|0x408c
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|fben
decl_stmt|;
comment|/* frame buffer write enable  0x4090 */
name|u_char
name|f7
index|[
literal|0x409c
operator|-
literal|0x4090
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|wmove
decl_stmt|;
comment|/* start window move 	      0x409c */
name|u_char
name|f8
index|[
literal|0x40a0
operator|-
literal|0x409c
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|blink
decl_stmt|;
comment|/* enable blink planes 	      0x40a0 */
name|u_char
name|f9
index|[
literal|0x40a8
operator|-
literal|0x40a0
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|altframe
decl_stmt|;
comment|/* enable alternate frame     0x40a8 */
name|u_char
name|f10
index|[
literal|0x40ac
operator|-
literal|0x40a8
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|curon
decl_stmt|;
comment|/* cursor control register    0x40ac */
name|u_char
name|f11
index|[
literal|0x40ea
operator|-
literal|0x40ac
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|prr
decl_stmt|;
comment|/* pixel replacement rule     0x40ea */
name|u_char
name|f12
index|[
literal|0x40ef
operator|-
literal|0x40ea
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|wmrr
decl_stmt|;
comment|/* move replacement rule      0x40ef */
name|u_char
name|f13
index|[
literal|0x40f2
operator|-
literal|0x40ef
operator|-
literal|1
index|]
decl_stmt|;
name|vu_short
name|source_x
decl_stmt|;
comment|/* source x pixel # 	      0x40f2 */
name|u_char
name|f14
index|[
literal|0x40f6
operator|-
literal|0x40f2
operator|-
literal|2
index|]
decl_stmt|;
name|vu_short
name|source_y
decl_stmt|;
comment|/* source y pixel # 	      0x40f6 */
name|u_char
name|f15
index|[
literal|0x40fa
operator|-
literal|0x40f6
operator|-
literal|2
index|]
decl_stmt|;
name|vu_short
name|dest_x
decl_stmt|;
comment|/* dest x pixel # 	      0x40fa */
name|u_char
name|f16
index|[
literal|0x40fe
operator|-
literal|0x40fa
operator|-
literal|2
index|]
decl_stmt|;
name|vu_short
name|dest_y
decl_stmt|;
comment|/* dest y pixel # 	      0x40fe */
name|u_char
name|f17
index|[
literal|0x4102
operator|-
literal|0x40fe
operator|-
literal|2
index|]
decl_stmt|;
name|vu_short
name|wwidth
decl_stmt|;
comment|/* block mover pixel width    0x4102 */
name|u_char
name|f18
index|[
literal|0x4106
operator|-
literal|0x4102
operator|-
literal|2
index|]
decl_stmt|;
name|vu_short
name|wheight
decl_stmt|;
comment|/* block mover pixel height   0x4106 */
name|u_char
name|f19
index|[
literal|0x6002
operator|-
literal|0x4106
operator|-
literal|2
index|]
decl_stmt|;
name|vu_short
name|cmap_busy
decl_stmt|;
comment|/* Color Ram busy	      0x6002 */
name|u_char
name|f20
index|[
literal|0x60b2
operator|-
literal|0x6002
operator|-
literal|2
index|]
decl_stmt|;
name|vu_short
name|rdata
decl_stmt|;
comment|/* color map red data 	      0x60b2 */
name|vu_short
name|gdata
decl_stmt|;
comment|/* color map green data       0x60b4 */
name|vu_short
name|bdata
decl_stmt|;
comment|/* color map blue data 	      0x60b6 */
name|vu_short
name|cindex
decl_stmt|;
comment|/* color map index 	      0x60b8 */
name|vu_short
name|plane_mask
decl_stmt|;
comment|/* plane mask select	      0x60ba */
name|u_char
name|f21
index|[
literal|0x60f0
operator|-
literal|0x60ba
operator|-
literal|2
index|]
decl_stmt|;
name|vu_short
name|strobe
decl_stmt|;
comment|/* color map trigger 	      0x60f0 */
block|}
struct|;
end_struct

end_unit

