begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: grf_gbreg.h 1.10 89/08/25$  *  *	@(#)grf_gbreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Gatorbox driver regs  */
end_comment

begin_define
define|#
directive|define
name|TILER_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|LINE_MOVER_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|UP_LEFT
value|0x00
end_define

begin_define
define|#
directive|define
name|DOWN_RIGHT
value|0x40
end_define

begin_define
define|#
directive|define
name|MOVE_UP_LEFT
value|TILER_ENABLE|UP_LEFT
end_define

begin_define
define|#
directive|define
name|MOVE_DOWN_RIGHT
value|TILER_ENABLE|DOWN_RIGHT
end_define

begin_define
define|#
directive|define
name|tile_mover_waitbusy
parameter_list|(
name|regaddr
parameter_list|)
define|\
value|while (((struct gboxfb *)(regaddr))->sec_interrupt& 0x10)
end_define

begin_define
define|#
directive|define
name|line_mover_waitbusy
parameter_list|(
name|regaddr
parameter_list|)
define|\
value|while ((((struct gboxfb *)(regaddr))->status& 0x80) == 0)
end_define

begin_define
define|#
directive|define
name|gbcm_waitbusy
parameter_list|(
name|regaddr
parameter_list|)
define|\
value|while (((struct gboxfb *)(regaddr))->cmap_busy != 0xff)
end_define

begin_define
define|#
directive|define
name|vu_char
value|volatile u_char
end_define

begin_struct
struct|struct
name|gboxfb
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
name|sec_interrupt
decl_stmt|;
comment|/* Secondary interrupt register 0x03 */
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
name|f1
index|[
literal|0x5d
operator|-
literal|0x15
operator|-
literal|1
index|]
decl_stmt|;
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
name|crtc_address
decl_stmt|;
comment|/* CTR controller address reg 0x4000 */
name|vu_char
name|status
decl_stmt|;
comment|/* Status register	      0x4001 */
name|vu_char
name|crtc_data
decl_stmt|;
comment|/* CTR controller data reg    0x4002 */
name|u_char
name|f3
index|[
literal|6
index|]
decl_stmt|;
name|vu_char
name|line_mover_rep_rule
decl_stmt|;
comment|/* Line move rep rule	             */
name|u_char
label|:
literal|8
operator|,
operator|:
literal|8
expr_stmt|;
name|vu_char
name|line_mover_width
decl_stmt|;
comment|/* Line move width	             */
name|u_char
name|f4
index|[
literal|0xff3
index|]
decl_stmt|;
name|vu_char
name|width
decl_stmt|;
comment|/* width in tiles	      0x5001 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|height
decl_stmt|;
comment|/* height in tiles	      0x5003 */
name|u_char
name|f5
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|rep_rule
decl_stmt|;
comment|/* replacement rule	      0x5007 */
name|u_char
name|f6
index|[
literal|0x6001
operator|-
literal|0x5007
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|blink1
decl_stmt|;
comment|/* blink 1		      0x6001 */
name|u_char
name|f7
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|blink2
decl_stmt|;
comment|/* blink 2		      0x6005 */
name|u_char
name|f8
index|[
literal|3
index|]
decl_stmt|;
name|vu_char
name|write_protect
decl_stmt|;
comment|/* write protect 	      0x6009 */
name|u_char
name|f9
index|[
literal|0x6803
operator|-
literal|0x6009
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|cmap_busy
decl_stmt|;
comment|/* color map busy             0x6803 */
name|u_char
name|f10
index|[
literal|0x68b9
operator|-
literal|0x6803
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|creg_select
decl_stmt|;
comment|/* color map register select  0x68b8 */
name|u_char
name|f11
index|[
literal|0x68f1
operator|-
literal|0x68b9
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|cmap_write
decl_stmt|;
comment|/* color map write trigger    0x68f1 */
name|u_char
name|f12
index|[
literal|0x69b3
operator|-
literal|0x68f1
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|cmap_red
decl_stmt|;
comment|/* red value register         0x69b3 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|cmap_grn
decl_stmt|;
comment|/* green value register       0x69b5 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|cmap_blu
decl_stmt|;
comment|/* blue value register        0x69b6 */
block|}
struct|;
end_struct

end_unit

