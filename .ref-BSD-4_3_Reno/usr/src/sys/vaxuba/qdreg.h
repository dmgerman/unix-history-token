begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  * 		@(#)qdreg.h	1.5  Berkeley  6/14/88  */
end_comment

begin_comment
comment|/************************************************************************  *									*  *			Copyright (c) 1985, 1986 by			*  *		Digital Equipment Corporation, Maynard, MA		*  *			All rights reserved.				*  *									*  *   This software is furnished under a license and may be used and	*  *   copied  only  in accordance with the terms of such license and	*  *   with the  inclusion  of  the  above  copyright  notice.   This	*  *   software  or  any	other copies thereof may not be provided or	*  *   otherwise made available to any other person.  No title to and	*  *   ownership of the software is hereby transferred.			*  *									*  *   The information in this software is subject to change  without	*  *   notice  and should not be construed as a commitment by Digital	*  *   Equipment Corporation.						*  *									*  *   Digital assumes no responsibility for the use  or	reliability	*  *   of its software on equipment which is not supplied by Digital.	*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/* Dragon ADDER reg map */
end_comment

begin_comment
comment|/* ADDER register bit definitions */
end_comment

begin_comment
comment|/* Y_SCROLL_CONSTANT */
end_comment

begin_define
define|#
directive|define
name|SCROLL_ERASE
value|0x2000
end_define

begin_define
define|#
directive|define
name|ADDER_SCROLL_DOWN
value|0x1000
end_define

begin_comment
comment|/* ADDER status and interrupt enable registers [1], [2], [3] */
end_comment

begin_define
define|#
directive|define
name|DISABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|PAUSE_COMPLETE
value|0x0001
end_define

begin_define
define|#
directive|define
name|FRAME_SYNC
value|0x0002
end_define

begin_define
define|#
directive|define
name|INIT_COMPLETE
value|0x0004
end_define

begin_define
define|#
directive|define
name|RASTEROP_COMPLETE
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADDRESS_COMPLETE
value|0x0010
end_define

begin_define
define|#
directive|define
name|RX_READY
value|0x0020
end_define

begin_define
define|#
directive|define
name|TX_READY
value|0x0040
end_define

begin_define
define|#
directive|define
name|ID_SCROLL_READY
value|0x0080
end_define

begin_define
define|#
directive|define
name|TOP_CLIP
value|0x0100
end_define

begin_define
define|#
directive|define
name|BOTTOM_CLIP
value|0x0200
end_define

begin_define
define|#
directive|define
name|LEFT_CLIP
value|0x0400
end_define

begin_define
define|#
directive|define
name|RIGHT_CLIP
value|0x0800
end_define

begin_define
define|#
directive|define
name|NO_CLIP
value|0x1000
end_define

begin_define
define|#
directive|define
name|VSYNC
value|0x2000
end_define

begin_comment
comment|/* ADDER command register [8], [10] */
end_comment

begin_define
define|#
directive|define
name|OCR_zero
value|0x0000
end_define

begin_define
define|#
directive|define
name|Z_BLOCK0
value|0x0000
end_define

begin_define
define|#
directive|define
name|OCRA
value|0x0000
end_define

begin_define
define|#
directive|define
name|OCRB
value|0x0004
end_define

begin_define
define|#
directive|define
name|RASTEROP
value|0x02c0
end_define

begin_define
define|#
directive|define
name|PBT
value|0x03c0
end_define

begin_define
define|#
directive|define
name|BTPZ
value|0x0bb0
end_define

begin_define
define|#
directive|define
name|PTBZ
value|0x07a0
end_define

begin_define
define|#
directive|define
name|DTE
value|0x0400
end_define

begin_define
define|#
directive|define
name|S1E
value|0x0800
end_define

begin_define
define|#
directive|define
name|S2E
value|0x1000
end_define

begin_define
define|#
directive|define
name|VIPER_Z_LOAD
value|0x01A0
end_define

begin_define
define|#
directive|define
name|ID_LOAD
value|0x0100
end_define

begin_define
define|#
directive|define
name|CANCEL
value|0x0000
end_define

begin_define
define|#
directive|define
name|LF_R1
value|0x0000
end_define

begin_define
define|#
directive|define
name|LF_R2
value|0x0010
end_define

begin_define
define|#
directive|define
name|LF_R3
value|0x0020
end_define

begin_define
define|#
directive|define
name|LF_R4
value|0x0030
end_define

begin_comment
comment|/* ADDER rasterop mode register [9] */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|LINEAR_PATTERN
value|0x0002
end_define

begin_define
define|#
directive|define
name|X_FILL
value|0x0003
end_define

begin_define
define|#
directive|define
name|Y_FILL
value|0x0007
end_define

begin_define
define|#
directive|define
name|BASELINE
value|0x0008
end_define

begin_define
define|#
directive|define
name|HOLE_ENABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|SRC_1_INDEX_ENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|DST_INDEX_ENABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|DST_WRITE_ENABLE
value|0x0080
end_define

begin_comment
comment|/* ADDER source 2 size register */
end_comment

begin_define
define|#
directive|define
name|NO_TILE
value|0x0080
end_define

begin_comment
comment|/* External registers base addresses */
end_comment

begin_define
define|#
directive|define
name|CS_UPDATE_MASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|CS_SCROLL_MASK
value|0x0040
end_define

begin_comment
comment|/* VIPER registers */
end_comment

begin_define
define|#
directive|define
name|RESOLUTION_MODE
value|0x0080
end_define

begin_define
define|#
directive|define
name|MEMORY_BUS_WIDTH
value|0x0081
end_define

begin_define
define|#
directive|define
name|PLANE_ADDRESS
value|0x0083
end_define

begin_define
define|#
directive|define
name|LU_FUNCTION_R1
value|0x0084
end_define

begin_define
define|#
directive|define
name|LU_FUNCTION_R2
value|0x0085
end_define

begin_define
define|#
directive|define
name|LU_FUNCTION_R3
value|0x0086
end_define

begin_define
define|#
directive|define
name|LU_FUNCTION_R4
value|0x0087
end_define

begin_define
define|#
directive|define
name|MASK_1
value|0x0088
end_define

begin_define
define|#
directive|define
name|MASK_2
value|0x0089
end_define

begin_define
define|#
directive|define
name|SOURCE
value|0x008a
end_define

begin_define
define|#
directive|define
name|SOURCE_Z
value|0x0000
end_define

begin_define
define|#
directive|define
name|BACKGROUND_COLOR
value|0x008e
end_define

begin_define
define|#
directive|define
name|BACKGROUND_COLOR_Z
value|0x000C
end_define

begin_define
define|#
directive|define
name|FOREGROUND_COLOR
value|0x008f
end_define

begin_define
define|#
directive|define
name|FOREGROUND_COLOR_Z
value|0x0004
end_define

begin_define
define|#
directive|define
name|SRC1_OCR_A
value|0x0090
end_define

begin_define
define|#
directive|define
name|SRC2_OCR_A
value|0x0091
end_define

begin_define
define|#
directive|define
name|DST_OCR_A
value|0x0092
end_define

begin_define
define|#
directive|define
name|SRC1_OCR_B
value|0x0094
end_define

begin_define
define|#
directive|define
name|SRC2_OCR_B
value|0x0095
end_define

begin_define
define|#
directive|define
name|DST_OCR_B
value|0x0096
end_define

begin_comment
comment|/* VIPER scroll registers */
end_comment

begin_define
define|#
directive|define
name|SCROLL_CONSTANT
value|0x0082
end_define

begin_define
define|#
directive|define
name|SCROLL_FILL
value|0x008b
end_define

begin_define
define|#
directive|define
name|SCROLL_FILL_Z
value|0x0008
end_define

begin_define
define|#
directive|define
name|LEFT_SCROLL_MASK
value|0x008c
end_define

begin_define
define|#
directive|define
name|RIGHT_SCROLL_MASK
value|0x008d
end_define

begin_comment
comment|/* VIPER register bit definitions */
end_comment

begin_define
define|#
directive|define
name|EXT_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|EXT_SOURCE
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT_M1_M2
value|0x0002
end_define

begin_define
define|#
directive|define
name|INT_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|INT_SOURCE
value|0x0004
end_define

begin_define
define|#
directive|define
name|INT_M1_M2
value|0x0008
end_define

begin_define
define|#
directive|define
name|ID
value|0x0010
end_define

begin_define
define|#
directive|define
name|NO_ID
value|0x0000
end_define

begin_define
define|#
directive|define
name|WAIT
value|0x0020
end_define

begin_define
define|#
directive|define
name|NO_WAIT
value|0x0000
end_define

begin_define
define|#
directive|define
name|BAR_SHIFT_DELAY
value|WAIT
end_define

begin_define
define|#
directive|define
name|NO_BAR_SHIFT_DELAY
value|NO_WAIT
end_define

begin_comment
comment|/* VIPER logical function unit codes */
end_comment

begin_define
define|#
directive|define
name|LF_ZEROS
value|0x0000
end_define

begin_define
define|#
directive|define
name|LF_D_XOR_S
value|0x0006
end_define

begin_define
define|#
directive|define
name|LF_SOURCE
value|0x000A
end_define

begin_define
define|#
directive|define
name|LF_D_OR_S
value|0x000E
end_define

begin_define
define|#
directive|define
name|LF_ONES
value|0x000F
end_define

begin_define
define|#
directive|define
name|INV_M1_M2
value|0x0030
end_define

begin_define
define|#
directive|define
name|FULL_SRC_RESOLUTION
value|0X00C0
end_define

begin_comment
comment|/* makes second pass like first pass */
end_comment

begin_comment
comment|/* VIPER scroll register [2] */
end_comment

begin_define
define|#
directive|define
name|SCROLL_DISABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|SCROLL_ENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|VIPER_LEFT
value|0x0000
end_define

begin_define
define|#
directive|define
name|VIPER_RIGHT
value|0x0010
end_define

begin_define
define|#
directive|define
name|VIPER_UP
value|0x0040
end_define

begin_define
define|#
directive|define
name|VIPER_DOWN
value|0x0000
end_define

begin_comment
comment|/* Adder scroll register */
end_comment

begin_define
define|#
directive|define
name|ADDER_UP
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADDER_DOWN
value|0x1000
end_define

begin_comment
comment|/* Misc scroll definitions */
end_comment

begin_define
define|#
directive|define
name|UP
value|0
end_define

begin_define
define|#
directive|define
name|DOWN
value|1
end_define

begin_define
define|#
directive|define
name|LEFT
value|2
end_define

begin_define
define|#
directive|define
name|RIGHT
value|3
end_define

begin_define
define|#
directive|define
name|NODIR
value|4
end_define

begin_define
define|#
directive|define
name|SCROLL_VMAX
value|31
end_define

begin_define
define|#
directive|define
name|SCROLL_HMAX
value|15
end_define

begin_define
define|#
directive|define
name|NEW
value|2
end_define

begin_define
define|#
directive|define
name|OLD
value|1
end_define

begin_define
define|#
directive|define
name|BUSY
value|1
end_define

begin_define
define|#
directive|define
name|DRAG
value|1
end_define

begin_define
define|#
directive|define
name|SCROLL
value|0
end_define

begin_comment
comment|/* miscellaneous defines */
end_comment

begin_define
define|#
directive|define
name|ALL_PLANES
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|UNITY
value|0x1fff
end_define

begin_comment
comment|/* Adder scale factor */
end_comment

begin_define
define|#
directive|define
name|MAX_SCREEN_X
value|1024
end_define

begin_define
define|#
directive|define
name|MAX_SCREEN_Y
value|864
end_define

begin_define
define|#
directive|define
name|FONT_HEIGHT
value|32
end_define

begin_struct
struct|struct
name|adder
block|{
comment|/* adder control registers */
name|u_short
name|register_address
decl_stmt|;
comment|/* ADDER reg pntr for use by DGA */
name|u_short
name|request_enable
decl_stmt|;
comment|/* DMA request enables */
name|u_short
name|interrupt_enable
decl_stmt|;
comment|/* interrupt enables */
name|u_short
name|status
decl_stmt|;
comment|/* ADDER status bits */
name|u_short
name|reserved1
decl_stmt|;
comment|/* test function only */
name|u_short
name|spare1
decl_stmt|;
comment|/* spare address (what else?) */
name|u_short
name|reserved2
decl_stmt|;
comment|/* test function only */
name|u_short
name|id_data
decl_stmt|;
comment|/* data path to I/D bus */
name|u_short
name|command
decl_stmt|;
comment|/* ADDER chip command register */
name|u_short
name|rasterop_mode
decl_stmt|;
comment|/* sets rasterop execution modes */
name|u_short
name|cmd
decl_stmt|;
comment|/* duplicate path to above cmd reg */
name|u_short
name|reserved3
decl_stmt|;
comment|/* test function only */
comment|/* scroll registers */
name|u_short
name|ID_scroll_data
decl_stmt|;
comment|/* I/D bus scroll data */
name|u_short
name|ID_scroll_command
decl_stmt|;
comment|/* I/D bus scroll command */
name|u_short
name|scroll_x_min
decl_stmt|;
comment|/* X scroll min - left boundary */
name|u_short
name|scroll_x_max
decl_stmt|;
comment|/* X scroll max - right boundary */
name|u_short
name|scroll_y_min
decl_stmt|;
comment|/* Y scroll min - upper boundary */
name|u_short
name|scroll_y_max
decl_stmt|;
comment|/* Y scroll max - lower boundary */
name|u_short
name|pause
decl_stmt|;
comment|/* Y coord to set stat when scanned */
name|u_short
name|y_offset_pending
decl_stmt|;
comment|/* vertical scroll control */
name|u_short
name|y_scroll_constant
decl_stmt|;
comment|/* update control registers */
name|u_short
name|x_index_pending
decl_stmt|;
comment|/* x pending index */
name|u_short
name|y_index_pending
decl_stmt|;
comment|/* y pending index */
name|u_short
name|x_index_new
decl_stmt|;
comment|/* new x index */
name|u_short
name|y_index_new
decl_stmt|;
comment|/* new y index */
name|u_short
name|x_index_old
decl_stmt|;
comment|/* old x index */
name|u_short
name|y_index_old
decl_stmt|;
comment|/* old y index */
name|u_short
name|x_clip_min
decl_stmt|;
comment|/* left clipping boundary */
name|u_short
name|x_clip_max
decl_stmt|;
comment|/* right clipping boundary */
name|u_short
name|y_clip_min
decl_stmt|;
comment|/* upper clipping boundary */
name|u_short
name|y_clip_max
decl_stmt|;
comment|/* lower clipping boundary */
name|u_short
name|spare2
decl_stmt|;
comment|/* spare address (another!) */
comment|/* rasterop control registers */
name|u_short
name|source_1_dx
decl_stmt|;
comment|/* source #1 x vector */
name|u_short
name|source_1_dy
decl_stmt|;
comment|/* source #1 y vector*/
name|u_short
name|source_1_x
decl_stmt|;
comment|/* source #1 x origin */
name|u_short
name|source_1_y
decl_stmt|;
comment|/* source #1 y origin */
name|u_short
name|destination_x
decl_stmt|;
comment|/* destination x origin */
name|u_short
name|destination_y
decl_stmt|;
comment|/* destination y origin */
name|u_short
name|fast_dest_dx
decl_stmt|;
comment|/* destination x fast vector */
name|u_short
name|fast_dest_dy
decl_stmt|;
comment|/* destination y fast vector */
name|u_short
name|slow_dest_dx
decl_stmt|;
comment|/* destination x slow vector */
name|u_short
name|slow_dest_dy
decl_stmt|;
comment|/* destination y slow vector */
name|u_short
name|fast_scale
decl_stmt|;
comment|/* scale factor for fast vector */
name|u_short
name|slow_scale
decl_stmt|;
comment|/* scale factor for slow vector */
name|u_short
name|source_2_x
decl_stmt|;
comment|/* source #2 x origin */
name|u_short
name|source_2_y
decl_stmt|;
comment|/* source #2 y origin */
name|u_short
name|source_2_size
decl_stmt|;
comment|/* source #2 height& width */
name|u_short
name|error_1
decl_stmt|;
comment|/* error regs (?) */
name|u_short
name|error_2
decl_stmt|;
comment|/* screen format control registers */
name|u_short
name|y_scan_count_0
decl_stmt|;
comment|/* y scan counts for vert timing */
name|u_short
name|y_scan_count_1
decl_stmt|;
name|u_short
name|y_scan_count_2
decl_stmt|;
name|u_short
name|y_scan_count_3
decl_stmt|;
name|u_short
name|x_scan_conf
decl_stmt|;
comment|/* x scan configuration */
name|u_short
name|x_limit
decl_stmt|;
name|u_short
name|y_limit
decl_stmt|;
name|u_short
name|x_scan_count_0
decl_stmt|;
comment|/* x scan count for horiz timing */
name|u_short
name|x_scan_count_1
decl_stmt|;
name|u_short
name|x_scan_count_2
decl_stmt|;
name|u_short
name|x_scan_count_3
decl_stmt|;
name|u_short
name|x_scan_count_4
decl_stmt|;
name|u_short
name|x_scan_count_5
decl_stmt|;
name|u_short
name|x_scan_count_6
decl_stmt|;
name|u_short
name|sync_phase_adj
decl_stmt|;
comment|/* sync phase (horiz sync count) */
block|}
struct|;
end_struct

begin_comment
comment|/*--------------------- * DUART definitions */
end_comment

begin_comment
comment|/* command definitions */
end_comment

begin_define
define|#
directive|define
name|EN_RCV
value|0x01
end_define

begin_define
define|#
directive|define
name|DIS_RCV
value|0x02
end_define

begin_define
define|#
directive|define
name|EN_XMT
value|0x04
end_define

begin_define
define|#
directive|define
name|DIS_XMT
value|0x08
end_define

begin_define
define|#
directive|define
name|RESET_M
value|0x10
end_define

begin_define
define|#
directive|define
name|RESET_RCV
value|0x20
end_define

begin_define
define|#
directive|define
name|RESET_XMT
value|0x30
end_define

begin_define
define|#
directive|define
name|RESET_ERR
value|0x40
end_define

begin_define
define|#
directive|define
name|RESET_BD
value|0x50
end_define

begin_define
define|#
directive|define
name|START_BREAK
value|0x60
end_define

begin_define
define|#
directive|define
name|STOP_BREAK
value|0x70
end_define

begin_comment
comment|/* interupt bit definitions */
end_comment

begin_define
define|#
directive|define
name|EI_XMT_A
value|0x01
end_define

begin_define
define|#
directive|define
name|EI_RCV_A
value|0x02
end_define

begin_define
define|#
directive|define
name|EI_XMT_B
value|0x10
end_define

begin_define
define|#
directive|define
name|EI_RCV_B
value|0x20
end_define

begin_define
define|#
directive|define
name|XMT_RDY_A
value|0x01
end_define

begin_define
define|#
directive|define
name|RCV_RDY_A
value|0x02
end_define

begin_define
define|#
directive|define
name|XMT_RDY_B
value|0x10
end_define

begin_define
define|#
directive|define
name|RCV_RDY_B
value|0x20
end_define

begin_comment
comment|/* status register bit defintions */
end_comment

begin_define
define|#
directive|define
name|RCV_RDY
value|0x01
end_define

begin_define
define|#
directive|define
name|FIFO_FULL
value|0x02
end_define

begin_define
define|#
directive|define
name|XMT_RDY
value|0x04
end_define

begin_define
define|#
directive|define
name|XMT_EMT
value|0x08
end_define

begin_define
define|#
directive|define
name|OVER_ERR
value|0x10
end_define

begin_define
define|#
directive|define
name|ERR_PARITY
value|0x20
end_define

begin_define
define|#
directive|define
name|FRAME_ERR
value|0x40
end_define

begin_define
define|#
directive|define
name|RCVD_BREAK
value|0x80
end_define

begin_struct
struct|struct
name|duart
block|{
comment|/* channel A - LK201 */
name|short
name|modeA
decl_stmt|;
comment|/* ch.A mode reg (read/write) */
name|short
name|statusA
decl_stmt|;
comment|/* ch.A status reg (read) */
define|#
directive|define
name|clkselA
value|statusA
comment|/* ch.A clock slect reg (write) */
name|short
name|cmdA
decl_stmt|;
comment|/* ch.A command reg (write) */
name|short
name|dataA
decl_stmt|;
comment|/* rcv/xmt data ch.A (read/write) */
name|short
name|inchng
decl_stmt|;
comment|/* input change state reg (read) */
define|#
directive|define
name|auxctl
value|inchng
comment|/* auxiliary control reg (write) */
name|short
name|istatus
decl_stmt|;
comment|/* interrupt status reg (read) */
define|#
directive|define
name|imask
value|istatus
comment|/* interrupt mask reg (write) */
name|short
name|CThi
decl_stmt|;
comment|/* counter/timer hi byte (read) */
define|#
directive|define
name|CTRhi
value|CThi
comment|/* counter/timer hi reg (write) */
name|short
name|CTlo
decl_stmt|;
comment|/* counter/timer lo byte (read) */
define|#
directive|define
name|CTRlo
value|CTlo
comment|/* counter/timer lo reg (write) */
comment|/* channel B - pointing device */
name|short
name|modeB
decl_stmt|;
comment|/* ch.B mode reg (read/write) */
name|short
name|statusB
decl_stmt|;
comment|/* ch.B status reg (read) */
define|#
directive|define
name|clkselB
value|statusB
comment|/* ch.B clock select reg (write) */
name|short
name|cmdB
decl_stmt|;
comment|/* ch.B command reg (write) */
name|short
name|dataB
decl_stmt|;
comment|/* ch.B rcv/xmt data (read/write) */
name|short
name|rsrvd
decl_stmt|;
name|short
name|inport
decl_stmt|;
comment|/* input port (read) */
define|#
directive|define
name|outconf
value|inport
comment|/* output port config reg (write) */
name|short
name|strctr
decl_stmt|;
comment|/* start counter command (read) */
define|#
directive|define
name|setbits
value|setctr
comment|/* output bits set command (write) */
name|short
name|stpctr
decl_stmt|;
comment|/* stop counter command (read) */
define|#
directive|define
name|resetbits
value|stpctr
comment|/* output bits reset cmd (write) */
block|}
struct|;
end_struct

end_unit

