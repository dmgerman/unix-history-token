begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: grf_rbreg.h 1.8 89/08/25$  *  *	@(#)grf_rbreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Map of the Renaissance frame buffer controller chip in memory ...  */
end_comment

begin_define
define|#
directive|define
name|rb_waitbusy
parameter_list|(
name|regaddr
parameter_list|)
define|\
value|while (((struct rboxfb *)(regaddr))->wbusy& 0x01) DELAY(100)
end_define

begin_define
define|#
directive|define
name|CM1RED
value|((struct rencm  *)(ip->regbase + 0x6400))
end_define

begin_define
define|#
directive|define
name|CM1GRN
value|((struct rencm  *)(ip->regbase + 0x6800))
end_define

begin_define
define|#
directive|define
name|CM1BLU
value|((struct rencm  *)(ip->regbase + 0x6C00))
end_define

begin_define
define|#
directive|define
name|CM2RED
value|((struct rencm  *)(ip->regbase + 0x7400))
end_define

begin_define
define|#
directive|define
name|CM2GRN
value|((struct rencm  *)(ip->regbase + 0x7800))
end_define

begin_define
define|#
directive|define
name|CM2BLU
value|((struct rencm  *)(ip->regbase + 0x7C00))
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

begin_define
define|#
directive|define
name|vu_int
value|volatile u_int
end_define

begin_struct
struct|struct
name|rencm
block|{
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
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rboxfb
block|{
name|u_char
name|filler1
index|[
literal|1
index|]
decl_stmt|;
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
name|filler1a
decl_stmt|;
name|vu_char
name|fbwmsb
decl_stmt|;
comment|/* frame buffer width MSB	0x05 */
name|u_char
name|filler1b
decl_stmt|;
name|vu_char
name|fbwlsb
decl_stmt|;
comment|/* frame buffer width MSB	0x07 */
name|u_char
name|filler1c
decl_stmt|;
name|vu_char
name|fbhmsb
decl_stmt|;
comment|/* frame buffer height MSB	0x09 */
name|u_char
name|filler1d
decl_stmt|;
name|vu_char
name|fbhlsb
decl_stmt|;
comment|/* frame buffer height MSB	0x0b */
name|u_char
name|filler1e
decl_stmt|;
name|vu_char
name|dwmsb
decl_stmt|;
comment|/* display width MSB		0x0d */
name|u_char
name|filler1f
decl_stmt|;
name|vu_char
name|dwlsb
decl_stmt|;
comment|/* display width MSB		0x0f */
name|u_char
name|filler1g
decl_stmt|;
name|vu_char
name|dhmsb
decl_stmt|;
comment|/* display height MSB		0x11 */
name|u_char
name|filler1h
decl_stmt|;
name|vu_char
name|dhlsb
decl_stmt|;
comment|/* display height MSB		0x13 */
name|u_char
name|filler1i
decl_stmt|;
name|vu_char
name|fbid
decl_stmt|;
comment|/* frame buffer id		0x15 */
name|u_char
name|filler1j
index|[
literal|0x47
index|]
decl_stmt|;
name|vu_char
name|fbomsb
decl_stmt|;
comment|/* frame buffer offset MSB	0x5d */
name|u_char
name|filler1k
decl_stmt|;
name|vu_char
name|fbolsb
decl_stmt|;
comment|/* frame buffer offset LSB	0x5f */
name|u_char
name|filler2
index|[
literal|16359
index|]
decl_stmt|;
name|vu_char
name|wbusy
decl_stmt|;
comment|/* window mover is active     0x4047 */
name|u_char
name|filler3
index|[
literal|0x405b
operator|-
literal|0x4048
index|]
decl_stmt|;
name|vu_char
name|scanbusy
decl_stmt|;
comment|/* scan converteris active    0x405B */
name|u_char
name|filler3b
index|[
literal|0x4083
operator|-
literal|0x405c
index|]
decl_stmt|;
name|vu_char
name|video_enable
decl_stmt|;
comment|/* drive vid. refresh bus     0x4083 */
name|u_char
name|filler4
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|display_enable
decl_stmt|;
comment|/* enable the display	      0x4087 */
name|u_char
name|filler5
index|[
literal|8
index|]
decl_stmt|;
name|vu_int
name|write_enable
decl_stmt|;
comment|/* write enable register      0x4090 */
name|u_char
name|filler6
index|[
literal|11
index|]
decl_stmt|;
name|vu_char
name|wmove
decl_stmt|;
comment|/* start window mover	      0x409f */
name|u_char
name|filler7
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|blink
decl_stmt|;
comment|/* blink register	      0x40a3 */
name|u_char
name|filler8
index|[
literal|15
index|]
decl_stmt|;
name|vu_char
name|fold
decl_stmt|;
comment|/* fold  register	      0x40b3 */
name|vu_int
name|opwen
decl_stmt|;
comment|/* overlay plane write enable 0x40b4 */
name|u_char
name|filler9
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|tmode
decl_stmt|;
comment|/* Tile mode size	      0x40bb */
name|u_char
name|filler9a
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|drive
decl_stmt|;
comment|/* drive register	      0x40bf */
name|u_char
name|filler10
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|vdrive
decl_stmt|;
comment|/* vdrive register	      0x40c3 */
name|u_char
name|filler10a
index|[
literal|0x40cb
operator|-
literal|0x40c4
index|]
decl_stmt|;
name|vu_char
name|zconfig
decl_stmt|;
comment|/* Z-buffer mode	      0x40cb */
name|u_char
name|filler11a
index|[
literal|2
index|]
decl_stmt|;
name|vu_short
name|tpatt
decl_stmt|;
comment|/* Transparency pattern	      0x40ce */
name|u_char
name|filler11b
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|dmode
decl_stmt|;
comment|/* dither mode		      0x40d3 */
name|u_char
name|filler11c
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|en_scan
decl_stmt|;
comment|/* enable scan board to DTACK 0x40d7 */
name|u_char
name|filler11d
index|[
literal|0x40ef
operator|-
literal|0x40d8
index|]
decl_stmt|;
name|vu_char
name|rep_rule
decl_stmt|;
comment|/* replacement rule	      0x40ef */
name|u_char
name|filler12
index|[
literal|2
index|]
decl_stmt|;
name|vu_short
name|source_x
decl_stmt|;
comment|/* source x		      0x40f2 */
name|u_char
name|filler13
index|[
literal|2
index|]
decl_stmt|;
name|vu_short
name|source_y
decl_stmt|;
comment|/* source y		      0x40f6 */
name|u_char
name|filler14
index|[
literal|2
index|]
decl_stmt|;
name|vu_short
name|dest_x
decl_stmt|;
comment|/* dest x		      0x40fa */
name|u_char
name|filler15
index|[
literal|2
index|]
decl_stmt|;
name|vu_short
name|dest_y
decl_stmt|;
comment|/* dest y		      0x40fe */
name|u_char
name|filler16
index|[
literal|2
index|]
decl_stmt|;
name|vu_short
name|wwidth
decl_stmt|;
comment|/* window width		      0x4102 */
name|u_char
name|filler17
index|[
literal|2
index|]
decl_stmt|;
name|vu_short
name|wheight
decl_stmt|;
comment|/* window height	      0x4106 */
name|u_char
name|filler18
index|[
literal|18
index|]
decl_stmt|;
name|vu_short
name|patt_x
decl_stmt|;
comment|/* pattern x		      0x411a */
name|u_char
name|filler19
index|[
literal|2
index|]
decl_stmt|;
name|vu_short
name|patt_y
decl_stmt|;
comment|/* pattern y		      0x411e */
name|u_char
name|filler20
index|[
literal|0x8012
operator|-
literal|0x4120
index|]
decl_stmt|;
name|vu_short
name|te_status
decl_stmt|;
comment|/* transform engine status    0x8012 */
name|u_char
name|filler21
index|[
literal|0x1ffff
operator|-
literal|0x8014
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

