begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * Copyright (c) 2000 Andrew Miklic  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FB_TGA_H_
end_ifndef

begin_define
define|#
directive|define
name|_FB_TGA_H_
end_define

begin_comment
comment|/* TGA-specific FB stuff */
end_comment

begin_struct_decl
struct_decl|struct
name|gfb_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|video_adapter
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Register definitions for the Brooktree Bt463 135MHz Monolithic  * CMOS TrueVu RAMDAC.  */
end_comment

begin_comment
comment|/*  * Directly-accessible registers.  Note the address register is  * auto-incrementing.  */
end_comment

begin_define
define|#
directive|define
name|BT463_REG_ADDR_LOW
value|0x00
end_define

begin_comment
comment|/* C1,C0 == 0,0 */
end_comment

begin_define
define|#
directive|define
name|BT463_REG_ADDR_HIGH
value|0x01
end_define

begin_comment
comment|/* C1,C0 == 0,1 */
end_comment

begin_define
define|#
directive|define
name|BT463_REG_IREG_DATA
value|0x02
end_define

begin_comment
comment|/* C1,C0 == 1,0 */
end_comment

begin_define
define|#
directive|define
name|BT463_REG_CMAP_DATA
value|0x03
end_define

begin_comment
comment|/* C1,C0 == 1,1 */
end_comment

begin_define
define|#
directive|define
name|BT463_REG_MAX
value|BT463_REG_CMAP_DATA
end_define

begin_comment
comment|/*  * All internal register access to the Bt463 is done indirectly via the  * Address Register (mapped into the host bus in a device-specific  * fashion).  The following register definitions are in terms of  * their address register address values.  */
end_comment

begin_comment
comment|/* C1,C0 must be 1,0 */
end_comment

begin_define
define|#
directive|define
name|BT463_IREG_CURSOR_COLOR_0
value|0x0100
end_define

begin_comment
comment|/* 3 r/w cycles */
end_comment

begin_define
define|#
directive|define
name|BT463_IREG_CURSOR_COLOR_1
value|0x0101
end_define

begin_comment
comment|/* 3 r/w cycles */
end_comment

begin_define
define|#
directive|define
name|BT463_IREG_ID
value|0x0200
end_define

begin_define
define|#
directive|define
name|BT463_IREG_COMMAND_0
value|0x0201
end_define

begin_define
define|#
directive|define
name|BT463_IREG_COMMAND_1
value|0x0202
end_define

begin_define
define|#
directive|define
name|BT463_IREG_COMMAND_2
value|0x0203
end_define

begin_define
define|#
directive|define
name|BT463_IREG_READ_MASK_P0_P7
value|0x0205
end_define

begin_define
define|#
directive|define
name|BT463_IREG_READ_MASK_P8_P15
value|0x0206
end_define

begin_define
define|#
directive|define
name|BT463_IREG_READ_MASK_P16_P23
value|0x0207
end_define

begin_define
define|#
directive|define
name|BT463_IREG_READ_MASK_P24_P27
value|0x0208
end_define

begin_define
define|#
directive|define
name|BT463_IREG_BLINK_MASK_P0_P7
value|0x0209
end_define

begin_define
define|#
directive|define
name|BT463_IREG_BLINK_MASK_P8_P15
value|0x020a
end_define

begin_define
define|#
directive|define
name|BT463_IREG_BLINK_MASK_P16_P23
value|0x020b
end_define

begin_define
define|#
directive|define
name|BT463_IREG_BLINK_MASK_P24_P27
value|0x020c
end_define

begin_define
define|#
directive|define
name|BT463_IREG_TEST
value|0x020d
end_define

begin_define
define|#
directive|define
name|BT463_IREG_INPUT_SIG
value|0x020e
end_define

begin_comment
comment|/* 2 of 3 r/w cycles */
end_comment

begin_define
define|#
directive|define
name|BT463_IREG_OUTPUT_SIG
value|0x020f
end_define

begin_comment
comment|/* 3 r/w cycles */
end_comment

begin_define
define|#
directive|define
name|BT463_IREG_REVISION
value|0x0220
end_define

begin_define
define|#
directive|define
name|BT463_IREG_WINDOW_TYPE_TABLE
value|0x0300
end_define

begin_comment
comment|/* 3 r/w cycles */
end_comment

begin_define
define|#
directive|define
name|BT463_NWTYPE_ENTRIES
value|0x10
end_define

begin_comment
comment|/* 16 window type entries */
end_comment

begin_comment
comment|/* C1,C0 must be 1,1 */
end_comment

begin_define
define|#
directive|define
name|BT463_IREG_CPALETTE_RAM
value|0x0000
end_define

begin_comment
comment|/* 3 r/w cycles */
end_comment

begin_define
define|#
directive|define
name|BT463_NCMAP_ENTRIES
value|0x210
end_define

begin_comment
comment|/* 528 CMAP entries */
end_comment

begin_define
define|#
directive|define
name|BT463_DATA_CURCMAP_CHANGED
value|0x01
end_define

begin_comment
comment|/* cursor colormap changed */
end_comment

begin_define
define|#
directive|define
name|BT463_DATA_CMAP_CHANGED
value|0x02
end_define

begin_comment
comment|/* colormap changed */
end_comment

begin_define
define|#
directive|define
name|BT463_DATA_WTYPE_CHANGED
value|0x04
end_define

begin_comment
comment|/* window type table changed */
end_comment

begin_define
define|#
directive|define
name|BT463_DATA_ALL_CHANGED
value|0x07
end_define

begin_comment
comment|/*  * Register definitions for the Brooktree Bt485A 170MHz Monolithic  * CMOS True-Color RAMDAC.  */
end_comment

begin_comment
comment|/*  * Directly-addressed registers.  */
end_comment

begin_define
define|#
directive|define
name|BT485_REG_PCRAM_WRADDR
value|0x00
end_define

begin_define
define|#
directive|define
name|BT485_REG_PALETTE
value|0x01
end_define

begin_define
define|#
directive|define
name|BT485_REG_PIXMASK
value|0x02
end_define

begin_define
define|#
directive|define
name|BT485_REG_PCRAM_RDADDR
value|0x03
end_define

begin_define
define|#
directive|define
name|BT485_REG_COC_WRADDR
value|0x04
end_define

begin_define
define|#
directive|define
name|BT485_REG_COCDATA
value|0x05
end_define

begin_define
define|#
directive|define
name|BT485_REG_COMMAND_0
value|0x06
end_define

begin_define
define|#
directive|define
name|BT485_REG_COC_RDADDR
value|0x07
end_define

begin_define
define|#
directive|define
name|BT485_REG_COMMAND_1
value|0x08
end_define

begin_define
define|#
directive|define
name|BT485_REG_COMMAND_2
value|0x09
end_define

begin_define
define|#
directive|define
name|BT485_REG_STATUS
value|0x0a
end_define

begin_define
define|#
directive|define
name|BT485_REG_EXTENDED
value|BT485_REG_STATUS
end_define

begin_define
define|#
directive|define
name|BT485_REG_CURSOR_RAM
value|0x0b
end_define

begin_define
define|#
directive|define
name|BT485_REG_CURSOR_X_LOW
value|0x0c
end_define

begin_define
define|#
directive|define
name|BT485_REG_CURSOR_X_HIGH
value|0x0d
end_define

begin_define
define|#
directive|define
name|BT485_REG_CURSOR_Y_LOW
value|0x0e
end_define

begin_define
define|#
directive|define
name|BT485_REG_CURSOR_Y_HIGH
value|0x0f
end_define

begin_define
define|#
directive|define
name|BT485_REG_MAX
value|0x0f
end_define

begin_define
define|#
directive|define
name|BT485_IREG_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|BT485_IREG_COMMAND_3
value|0x01
end_define

begin_define
define|#
directive|define
name|BT485_IREG_COMMAND_4
value|0x02
end_define

begin_define
define|#
directive|define
name|BT485_IREG_RSA
value|0x20
end_define

begin_define
define|#
directive|define
name|BT485_IREG_GSA
value|0x21
end_define

begin_define
define|#
directive|define
name|BT485_IREG_BSA
value|0x22
end_define

begin_define
define|#
directive|define
name|BT485_DATA_ENB_CHANGED
value|0x01
end_define

begin_comment
comment|/* cursor enable changed */
end_comment

begin_define
define|#
directive|define
name|BT485_DATA_CURCMAP_CHANGED
value|0x02
end_define

begin_comment
comment|/* cursor colormap changed */
end_comment

begin_define
define|#
directive|define
name|BT485_DATA_CURSHAPE_CHANGED
value|0x04
end_define

begin_comment
comment|/* cursor size, image, mask changed */
end_comment

begin_define
define|#
directive|define
name|BT485_DATA_CMAP_CHANGED
value|0x08
end_define

begin_comment
comment|/* colormap changed */
end_comment

begin_define
define|#
directive|define
name|BT485_DATA_ALL_CHANGED
value|0x0f
end_define

begin_define
define|#
directive|define
name|CURSOR_MAX_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|TGA_DRIVER_NAME
value|"tga"
end_define

begin_define
define|#
directive|define
name|TGA2_DRIVER_NAME
value|"tga2"
end_define

begin_define
define|#
directive|define
name|BTWREG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|sc->gfbc->ramdac_wr((sc), BT463_REG_ADDR_LOW, (addr)& 0xff);	\ 	sc->gfbc->ramdac_wr((sc), BT463_REG_ADDR_HIGH, ((addr)>> 8)& 0xff);\ 	(sc)->gfbc->ramdac_wr((sc), BT463_REG_IREG_DATA, (val))
end_define

begin_define
define|#
directive|define
name|BTWNREG
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|(sc)->gfbc->ramdac_wr((sc), BT463_REG_IREG_DATA, (val))
end_define

begin_define
define|#
directive|define
name|BTRREG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|)
define|\
value|sc->gfbc->ramdac_wr((sc), BT463_REG_ADDR_LOW, (addr)& 0xff);	\ 	sc->gfbc->ramdac_wr((sc), BT463_REG_ADDR_HIGH, ((addr)>> 8)& 0xff);\ 	(sc)->gfbc->ramdac_rd((sc), BT463_REG_IREG_DATA)
end_define

begin_define
define|#
directive|define
name|BTRNREG
parameter_list|(
name|sc
parameter_list|)
define|\
value|(sc)->gfbc->ramdac_rd((sc), BT463_REG_IREG_DATA)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FB_TGA_H_ */
end_comment

end_unit

