begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)xcfbreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Defines for the Inmos IMS-G332 Colour video controller  * 	Author: Alessandro Forin, Carnegie Mellon University  *	See: IMS G332 Colour Video Controller, 1990 Databook, pg 139-163,  *		Inmos, Ltd.  */
end_comment

begin_define
define|#
directive|define
name|IMS332_ADDRESS
value|0xbc140000
end_define

begin_define
define|#
directive|define
name|VRAM_OFFSET
value|0x2000000
end_define

begin_define
define|#
directive|define
name|IMS332_RESET_ADDRESS
value|0xbc040100
end_define

begin_comment
comment|/*  * Although the chip is built to be memory-mapped  * it can be programmed for 32 or 64 bit addressing.  * Moreover, the hardware bits have been twisted  * even more on the machine I am writing this for.  * So I'll just define the chip's offsets and leave  * it to the implementation to define the rest.  */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_BOOT
value|0x000
end_define

begin_comment
comment|/* boot time config */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_HALF_SYNCH
value|0x021
end_define

begin_comment
comment|/* datapath registers */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_BACK_PORCH
value|0x022
end_define

begin_define
define|#
directive|define
name|IMS332_REG_DISPLAY
value|0x023
end_define

begin_define
define|#
directive|define
name|IMS332_REG_SHORT_DIS
value|0x024
end_define

begin_define
define|#
directive|define
name|IMS332_REG_BROAD_PULSE
value|0x025
end_define

begin_define
define|#
directive|define
name|IMS332_REG_V_SYNC
value|0x026
end_define

begin_define
define|#
directive|define
name|IMS332_REG_V_PRE_EQUALIZE
value|0x027
end_define

begin_define
define|#
directive|define
name|IMS332_REG_V_POST_EQUALIZE
value|0x028
end_define

begin_define
define|#
directive|define
name|IMS332_REG_V_BLANK
value|0x029
end_define

begin_define
define|#
directive|define
name|IMS332_REG_V_DISPLAY
value|0x02a
end_define

begin_define
define|#
directive|define
name|IMS332_REG_LINE_TIME
value|0x02b
end_define

begin_define
define|#
directive|define
name|IMS332_REG_LINE_START
value|0x02c
end_define

begin_define
define|#
directive|define
name|IMS332_REG_MEM_INIT
value|0x02d
end_define

begin_define
define|#
directive|define
name|IMS332_REG_XFER_DELAY
value|0x02e
end_define

begin_define
define|#
directive|define
name|IMS332_REG_COLOR_MASK
value|0x040
end_define

begin_comment
comment|/* color mask register */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_CSR_A
value|0x060
end_define

begin_define
define|#
directive|define
name|IMS332_REG_CSR_B
value|0x070
end_define

begin_define
define|#
directive|define
name|IMS332_REG_TOP_SCREEN
value|0x080
end_define

begin_comment
comment|/* top-of-screen offset */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_CURSOR_LUT_0
value|0x0a1
end_define

begin_comment
comment|/* cursor palette */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_CURSOR_LUT_1
value|0x0a2
end_define

begin_define
define|#
directive|define
name|IMS332_REG_CURSOR_LUT_2
value|0x0a3
end_define

begin_define
define|#
directive|define
name|IMS332_REG_RGB_CKSUM_0
value|0x0c0
end_define

begin_comment
comment|/* test registers */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_RGB_CKSUM_1
value|0x0c1
end_define

begin_define
define|#
directive|define
name|IMS332_REG_RGB_CKSUM_2
value|0x0c2
end_define

begin_define
define|#
directive|define
name|IMS332_REG_CURSOR_LOC
value|0x0c7
end_define

begin_comment
comment|/* cursor location */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_LUT_BASE
value|0x100
end_define

begin_comment
comment|/* color palette */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_LUT_END
value|0x1ff
end_define

begin_define
define|#
directive|define
name|IMS332_REG_CURSOR_RAM
value|0x200
end_define

begin_comment
comment|/* cursor bitmap */
end_comment

begin_define
define|#
directive|define
name|IMS332_REG_CURSOR_RAM_END
value|0x3ff
end_define

begin_comment
comment|/*  * Control register A  */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_VTG_ENABLE
value|0x000001
end_define

begin_comment
comment|/* vertical timing generator */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_INTERLACED
value|0x000002
end_define

begin_comment
comment|/* screen format */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_CCIR
value|0x000004
end_define

begin_comment
comment|/* default is EIA */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_SLAVE_SYNC
value|0x000008
end_define

begin_comment
comment|/* else from our pll */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_PLAIN_SYNC
value|0x000010
end_define

begin_comment
comment|/* else tesselated */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_SEPARATE_SYNC
value|0x000020
end_define

begin_comment
comment|/* else composite */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_VIDEO_ONLY
value|0x000040
end_define

begin_comment
comment|/* else video+sync */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_BLANK_PEDESTAL
value|0x000080
end_define

begin_comment
comment|/* blank level */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_CBLANK_IS_OUT
value|0x000100
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_CBLANK_NO_DELAY
value|0x000200
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_FORCE_BLANK
value|0x000400
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_BLANK_DISABLE
value|0x000800
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_VRAM_INCREMENT
value|0x003000
end_define

begin_define
define|#
directive|define
name|IMS332_VRAM_INC_1
value|0x000000
end_define

begin_define
define|#
directive|define
name|IMS332_VRAM_INC_256
value|0x001000
end_define

begin_comment
comment|/* except interlaced->2 */
end_comment

begin_define
define|#
directive|define
name|IMS332_VRAM_INC_512
value|0x002000
end_define

begin_define
define|#
directive|define
name|IMS332_VRAM_INC_1024
value|0x003000
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_DMA_DISABLE
value|0x004000
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_SYNC_DELAY_MASK
value|0x038000
end_define

begin_comment
comment|/* 0-7 VTG clk delays */
end_comment

begin_define
define|#
directive|define
name|IMS332_CSR_A_PIXEL_INTERLEAVE
value|0x040000
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_DELAYED_SAMPLING
value|0x080000
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_BITS_PER_PIXEL
value|0x700000
end_define

begin_define
define|#
directive|define
name|IMS332_BPP_1
value|0x000000
end_define

begin_define
define|#
directive|define
name|IMS332_BPP_2
value|0x100000
end_define

begin_define
define|#
directive|define
name|IMS332_BPP_4
value|0x200000
end_define

begin_define
define|#
directive|define
name|IMS332_BPP_8
value|0x300000
end_define

begin_define
define|#
directive|define
name|IMS332_BPP_15
value|0x400000
end_define

begin_define
define|#
directive|define
name|IMS332_BPP_16
value|0x500000
end_define

begin_define
define|#
directive|define
name|IMS332_CSR_A_DISABLE_CURSOR
value|0x800000
end_define

begin_comment
comment|/*  * Control register B is mbz  */
end_comment

begin_comment
comment|/*  * Boot register  */
end_comment

begin_define
define|#
directive|define
name|IMS332_BOOT_PLL
value|0x00001f
end_define

begin_comment
comment|/* xPLL, binary */
end_comment

begin_define
define|#
directive|define
name|IMS332_BOOT_CLOCK_PLL
value|0x000020
end_define

begin_comment
comment|/* else xternal */
end_comment

begin_define
define|#
directive|define
name|IMS332_BOOT_64_BIT_MODE
value|0x000040
end_define

begin_comment
comment|/* else 32 */
end_comment

begin_define
define|#
directive|define
name|IMS332_BOOT_xxx
value|0xffff80
end_define

begin_comment
comment|/* reserved, mbz */
end_comment

end_unit

