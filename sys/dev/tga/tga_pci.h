begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * Copyright (c) 2000 Andrew Miklic  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_TGA_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_TGA_H_
end_define

begin_comment
comment|/*  * Device-specific PCI register offsets and contents.  */
end_comment

begin_define
define|#
directive|define
name|TGA_PCIREG_PVRR
value|0x40
end_define

begin_comment
comment|/* PCI Address Extension Register */
end_comment

begin_define
define|#
directive|define
name|TGA_PCIREG_PAER
value|0x44
end_define

begin_comment
comment|/* PCI VGA Redirect Register */
end_comment

begin_comment
comment|/*  * TGA Memory Space offsets  */
end_comment

begin_define
define|#
directive|define
name|TGA_MEM_ALTROM
value|0x0000000
end_define

begin_comment
comment|/* 0MB -- Alternate ROM space */
end_comment

begin_define
define|#
directive|define
name|TGA2_MEM_EXTDEV
value|0x0000000
end_define

begin_comment
comment|/* 0MB -- External Device Access */
end_comment

begin_define
define|#
directive|define
name|TGA_MEM_CREGS
value|0x0100000
end_define

begin_comment
comment|/* 1MB -- Core Registers */
end_comment

begin_define
define|#
directive|define
name|TGA_CREGS_SIZE
value|0x0100000
end_define

begin_comment
comment|/* Core registers occupy 1MB */
end_comment

begin_define
define|#
directive|define
name|TGA_CREGS_ALIAS
value|0x0000400
end_define

begin_comment
comment|/* Register copies every 1kB */
end_comment

begin_define
define|#
directive|define
name|TGA2_MEM_CLOCK
value|0x0060000
end_define

begin_comment
comment|/* TGA2 Clock access */
end_comment

begin_define
define|#
directive|define
name|TGA2_MEM_RAMDAC
value|0x0080000
end_define

begin_comment
comment|/* TGA2 RAMDAC access */
end_comment

begin_comment
comment|/*  * TGA Core Space register numbers and contents.  */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCBR0
value|0x000
end_define

begin_comment
comment|/* Copy buffer 0 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCBR1
value|0x001
end_define

begin_comment
comment|/* Copy buffer 1 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCBR2
value|0x002
end_define

begin_comment
comment|/* Copy buffer 2 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCBR3
value|0x003
end_define

begin_comment
comment|/* Copy buffer 3 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCBR4
value|0x004
end_define

begin_comment
comment|/* Copy buffer 4 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCBR5
value|0x005
end_define

begin_comment
comment|/* Copy buffer 5 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCBR6
value|0x006
end_define

begin_comment
comment|/* Copy buffer 6 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCBR7
value|0x007
end_define

begin_comment
comment|/* Copy buffer 7 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GFGR
value|0x008
end_define

begin_comment
comment|/* Foreground */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBGR
value|0x009
end_define

begin_comment
comment|/* Background */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GPMR
value|0x00a
end_define

begin_comment
comment|/* Plane Mask */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GPXR_S
value|0x00b
end_define

begin_comment
comment|/* Pixel Mask (one-shot) */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GMOR
value|0x00c
end_define

begin_comment
comment|/* Mode */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GOPR
value|0x00d
end_define

begin_comment
comment|/* Raster Operation */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GPSR
value|0x00e
end_define

begin_comment
comment|/* Pixel Shift */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GADR
value|0x00f
end_define

begin_comment
comment|/* Address */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GB1R
value|0x010
end_define

begin_comment
comment|/* Bresenham 1 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GB2R
value|0x011
end_define

begin_comment
comment|/* Bresenham 2 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GB3R
value|0x012
end_define

begin_comment
comment|/* Bresenham 3 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCTR
value|0x013
end_define

begin_comment
comment|/* Continue */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GDER
value|0x014
end_define

begin_comment
comment|/* Deep */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GREV
value|0x015
end_define

begin_comment
comment|/* Start/Version on TGA, 					 * Revision on TGA2 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSMR
value|0x016
end_define

begin_comment
comment|/* Stencil Mode */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GPXR_P
value|0x017
end_define

begin_comment
comment|/* Pixel Mask (persistent) */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_CCBR
value|0x018
end_define

begin_comment
comment|/* Cursor Base Address */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_VHCR
value|0x019
end_define

begin_comment
comment|/* Horizontal Control */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_VVCR
value|0x01a
end_define

begin_comment
comment|/* Vertical Control */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_VVBR
value|0x01b
end_define

begin_comment
comment|/* Video Base Address */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_VVVR
value|0x01c
end_define

begin_comment
comment|/* Video Valid */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_CXYR
value|0x01d
end_define

begin_comment
comment|/* Cursor XY */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_VSAR
value|0x01e
end_define

begin_comment
comment|/* Video Shift Address */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_SISR
value|0x01f
end_define

begin_comment
comment|/* Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GDAR
value|0x020
end_define

begin_comment
comment|/* Data */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GRIR
value|0x021
end_define

begin_comment
comment|/* Red Increment */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GGIR
value|0x022
end_define

begin_comment
comment|/* Green Increment */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBIR
value|0x023
end_define

begin_comment
comment|/* Blue Increment */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GZIR_L
value|0x024
end_define

begin_comment
comment|/* Z-increment Low */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GZIR_H
value|0x025
end_define

begin_comment
comment|/* Z-Increment High */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GDBR
value|0x026
end_define

begin_comment
comment|/* DMA Base Address */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBWR
value|0x027
end_define

begin_comment
comment|/* Bresenham Width */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GZVR_L
value|0x028
end_define

begin_comment
comment|/* Z-value Low */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GZVR_H
value|0x029
end_define

begin_comment
comment|/* Z-value High */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GZBR
value|0x02a
end_define

begin_comment
comment|/* Z-base address */
end_comment

begin_comment
comment|/*	GADR alias	0x02b */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GRVR
value|0x02c
end_define

begin_comment
comment|/* Red Value */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GGVR
value|0x02d
end_define

begin_comment
comment|/* Green Value */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBVR
value|0x02e
end_define

begin_comment
comment|/* Blue Value */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSWR
value|0x02f
end_define

begin_comment
comment|/* Span Width */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_EPSR
value|0x030
end_define

begin_comment
comment|/* Pallete and DAC Setup */
end_comment

begin_comment
comment|/*	reserved	0x031 - 0x3f */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSNR0
value|0x040
end_define

begin_comment
comment|/* Slope-no-go 0 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSNR1
value|0x041
end_define

begin_comment
comment|/* Slope-no-go 1 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSNR2
value|0x042
end_define

begin_comment
comment|/* Slope-no-go 2 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSNR3
value|0x043
end_define

begin_comment
comment|/* Slope-no-go 3 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSNR4
value|0x044
end_define

begin_comment
comment|/* Slope-no-go 4 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSNR5
value|0x045
end_define

begin_comment
comment|/* Slope-no-go 5 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSNR6
value|0x046
end_define

begin_comment
comment|/* Slope-no-go 6 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSNR7
value|0x047
end_define

begin_comment
comment|/* Slope-no-go 7 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSLR0
value|0x048
end_define

begin_comment
comment|/* Slope 0 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSLR1
value|0x049
end_define

begin_comment
comment|/* Slope 1 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSLR2
value|0x04a
end_define

begin_comment
comment|/* Slope 2 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSLR3
value|0x04b
end_define

begin_comment
comment|/* Slope 3 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSLR4
value|0x04c
end_define

begin_comment
comment|/* Slope 4 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSLR5
value|0x04d
end_define

begin_comment
comment|/* Slope 5 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSLR6
value|0x04e
end_define

begin_comment
comment|/* Slope 6 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GSLR7
value|0x04f
end_define

begin_comment
comment|/* Slope 7 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBCR0
value|0x050
end_define

begin_comment
comment|/* Block Color 0 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBCR1
value|0x051
end_define

begin_comment
comment|/* Block Color 1 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBCR2
value|0x052
end_define

begin_comment
comment|/* Block Color 2 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBCR3
value|0x053
end_define

begin_comment
comment|/* Block Color 3 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBCR4
value|0x054
end_define

begin_comment
comment|/* Block Color 4 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBCR5
value|0x055
end_define

begin_comment
comment|/* Block Color 5 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBCR6
value|0x056
end_define

begin_comment
comment|/* Block Color 6 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GBCR7
value|0x057
end_define

begin_comment
comment|/* Block Color 7 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCSR
value|0x058
end_define

begin_comment
comment|/* Copy 64 Source */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_GCDR
value|0x059
end_define

begin_comment
comment|/* Copy 64 Destination */
end_comment

begin_comment
comment|/*	GC[SD]R aliases 0x05a - 0x05f */
end_comment

begin_comment
comment|/*	reserved	0x060 - 0x077 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_ERWR
value|0x078
end_define

begin_comment
comment|/* EEPROM write */
end_comment

begin_comment
comment|/*	reserved	0x079 */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_ECGR
value|0x07a
end_define

begin_comment
comment|/* Clock */
end_comment

begin_comment
comment|/*	reserved	0x07b */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_EPDR
value|0x07c
end_define

begin_comment
comment|/* Pallete and DAC Data */
end_comment

begin_comment
comment|/*	reserved	0x07d */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_SCSR
value|0x07e
end_define

begin_comment
comment|/* Command Status */
end_comment

begin_comment
comment|/*	reserved	0x07f */
end_comment

begin_comment
comment|/*  * Deep register  */
end_comment

begin_define
define|#
directive|define
name|GDER_HSS
value|0x00010000
end_define

begin_comment
comment|/* Horizontal sync select */
end_comment

begin_define
define|#
directive|define
name|GDER_SDAC
value|0x00004000
end_define

begin_comment
comment|/* Slow DAC */
end_comment

begin_define
define|#
directive|define
name|GDER_RWE
value|0x00001000
end_define

begin_comment
comment|/* ROM write enable */
end_comment

begin_define
define|#
directive|define
name|GDER_SAMS
value|0x00000400
end_define

begin_comment
comment|/* Serial-access memory size */
end_comment

begin_define
define|#
directive|define
name|GDER_CS
value|0x00000200
end_define

begin_comment
comment|/* Column size */
end_comment

begin_define
define|#
directive|define
name|GDER_BLOCK_MASK
value|0x000001e0
end_define

begin_comment
comment|/* eight/four column segments */
end_comment

begin_define
define|#
directive|define
name|GDER_BLOCK_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|GDER_ADDR_MASK
value|0x0000001c
end_define

begin_comment
comment|/* PCI address mask */
end_comment

begin_define
define|#
directive|define
name|GDER_ADDR_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|GDER_ADDR_4MB
value|0x00000000
end_define

begin_comment
comment|/* PCI mask<24:22> =  4MB */
end_comment

begin_define
define|#
directive|define
name|GDER_ADDR_8MB
value|0x00000001
end_define

begin_comment
comment|/* PCI mask<24:23> =  8MB */
end_comment

begin_define
define|#
directive|define
name|GDER_ADDR_16MB
value|0x00000003
end_define

begin_comment
comment|/* PCI mask bit 24  = 16MB */
end_comment

begin_define
define|#
directive|define
name|GDER_ADDR_32MB
value|0x00000007
end_define

begin_comment
comment|/* No PCI masking   = 32MB */
end_comment

begin_define
define|#
directive|define
name|GDER_DEEP
value|0x00000001
end_define

begin_comment
comment|/* 32-bpp or 8 bpp frame buffer */
end_comment

begin_comment
comment|/*  * Graphics mode register  */
end_comment

begin_define
define|#
directive|define
name|GMOR_CE
value|0x00008000
end_define

begin_comment
comment|/* Cap ends */
end_comment

begin_define
define|#
directive|define
name|GMOR_Z16
value|0x00004000
end_define

begin_comment
comment|/* 16 or 24 bit Z valuesx */
end_comment

begin_define
define|#
directive|define
name|GMOR_GE
value|0x00002000
end_define

begin_comment
comment|/* Win32 or X environment */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBY_MASK
value|0x00001800
end_define

begin_comment
comment|/* Source byte mask for 32-bpp FB */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBY_0
value|0x00000000
end_define

begin_comment
comment|/* Source byte 0 */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBY_1
value|0x00000800
end_define

begin_comment
comment|/* Source byte 1 */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBY_2
value|0x00001000
end_define

begin_comment
comment|/* Source byte 2 */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBY_3
value|0x00001800
end_define

begin_comment
comment|/* Source byte 3 */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBM_MASK
value|0x00000700
end_define

begin_comment
comment|/* Source bitmap format (32-bpp FB) */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBM_8P
value|0x00000000
end_define

begin_comment
comment|/* 8-bpp packed */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBM_8U
value|0x00000100
end_define

begin_comment
comment|/* 8-bpp unpacked */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBM_12L
value|0x00000200
end_define

begin_comment
comment|/* 12-bpp low */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBM_12H
value|0x00000600
end_define

begin_comment
comment|/* 12-bpp high */
end_comment

begin_define
define|#
directive|define
name|GMOR_SBM_24
value|0x00000300
end_define

begin_comment
comment|/* 24-bpp */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_MASK
value|0x0000007f
end_define

begin_comment
comment|/* Graphics mode mask */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_SIMPLE
value|0x0000
end_define

begin_comment
comment|/* Simple */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_SIMPLEZ
value|0x0010
end_define

begin_comment
comment|/* Simple Z */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_OPQ_STPL
value|0x0001
end_define

begin_comment
comment|/* Opaque Stipple */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_OPQ_FILL
value|0x0021
end_define

begin_comment
comment|/* Opaque Fill */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_TRN_STPL
value|0x0005
end_define

begin_comment
comment|/* Transparent Stipple */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_TRN_FILL
value|0x0025
end_define

begin_comment
comment|/* Transparent Fill */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_BLK_STPL
value|0x000d
end_define

begin_comment
comment|/* Block Stipple */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_BLK_FILL
value|0x002d
end_define

begin_comment
comment|/* Block Fill */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_OPQ_LINE
value|0x0002
end_define

begin_comment
comment|/* Opaque Line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_TRN_LINE
value|0x0006
end_define

begin_comment
comment|/* Transparent Line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_CITNDL
value|0x000e
end_define

begin_comment
comment|/* Color-interpolated transparent */
end_comment

begin_comment
comment|/* non-dithered line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_CITDL
value|0x002e
end_define

begin_comment
comment|/* Color-intrp. trans. dithered line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_SITL
value|0x004e
end_define

begin_comment
comment|/* Sequential-intrp. transp line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_ZOPQ_LINE
value|0x0012
end_define

begin_comment
comment|/* Z buffered Opaque Line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_ZTRN_LINE
value|0x0016
end_define

begin_comment
comment|/* Z buffered Trans Line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_ZOCITNDL
value|0x001a
end_define

begin_comment
comment|/* Z buffered Opaque CITND line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_ZOCITDL
value|0x003a
end_define

begin_comment
comment|/* Z buffered Opaque CITD line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_ZOSITL
value|0x005a
end_define

begin_comment
comment|/* Z buffered Opaque SIT line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_ZTCITNDL
value|0x001e
end_define

begin_comment
comment|/* Z buffered transparent CITND line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_ZTCITDL
value|0x003e
end_define

begin_comment
comment|/* Z buffered transparent CITD line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_ZTSITL
value|0x005e
end_define

begin_comment
comment|/* Z buffered transparent SIT line */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_COPY
value|0x0007
end_define

begin_comment
comment|/* Copy */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_DRDND
value|0x0017
end_define

begin_comment
comment|/* DMA-read copy, non-dithered */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_DRDD
value|0x0037
end_define

begin_comment
comment|/* DMA-read copy, dithered */
end_comment

begin_define
define|#
directive|define
name|GMOR_MODE_DWCOPY
value|0x001f
end_define

begin_comment
comment|/* DMA-write copy */
end_comment

begin_comment
comment|/*  * Video Horizontal Control Register  */
end_comment

begin_define
define|#
directive|define
name|VHCR_ODD
value|0x80000000
end_define

begin_comment
comment|/* Enable 4-pixel line skew */
end_comment

begin_define
define|#
directive|define
name|VHCR_HSP
value|0x40000000
end_define

begin_comment
comment|/* Horizontal sync polarity */
end_comment

begin_define
define|#
directive|define
name|VHCR_BPORCH_MASK
value|0xfe00000
end_define

begin_comment
comment|/* Back porch pixels / 4 */
end_comment

begin_define
define|#
directive|define
name|VHCR_BPORCH_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|VHCR_HSYNC_MASK
value|0x001fc000
end_define

begin_comment
comment|/* Hsync width / 4 */
end_comment

begin_define
define|#
directive|define
name|VHCR_HSYNC_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|VHCR_FPORCH_MASK
value|0x3e00
end_define

begin_comment
comment|/* Front porch pixels / 4 */
end_comment

begin_define
define|#
directive|define
name|VHCR_FPORCH_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|VHCR_ACTIVE_MASK
value|0x01ff
end_define

begin_comment
comment|/* Active lines */
end_comment

begin_define
define|#
directive|define
name|VHCR_REG2ACTIVE
parameter_list|(
name|reg
parameter_list|)
value|((((reg)>> 19)& 0x0600) | ((reg)& 0x01ff))
end_define

begin_define
define|#
directive|define
name|VHCR_ACTIVE2REG
parameter_list|(
name|val
parameter_list|)
value|((((val)& 0x0600)<< 19) | ((val)& 0x01ff))
end_define

begin_comment
comment|/*  * Video Vertical Control Register  */
end_comment

begin_define
define|#
directive|define
name|VVCR_SE
value|0x80000000
end_define

begin_comment
comment|/* Stereo Enable */
end_comment

begin_define
define|#
directive|define
name|VVCR_VSP
value|0x40000000
end_define

begin_comment
comment|/* Vertical sync polarity */
end_comment

begin_define
define|#
directive|define
name|VVCR_BPORCH_MASK
value|0xfc00000
end_define

begin_comment
comment|/* Back porch in lines */
end_comment

begin_define
define|#
directive|define
name|VVCR_BPORCH_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|VVCR_VSYNC_MASK
value|0x003f0000
end_define

begin_comment
comment|/* Vsync width in lines */
end_comment

begin_define
define|#
directive|define
name|VVCR_VSYNC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|VVCR_FPORCH_MASK
value|0xf800
end_define

begin_comment
comment|/* Front porch in lines */
end_comment

begin_define
define|#
directive|define
name|VVCR_FPORCH_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|VVCR_ACTIVE_MASK
value|0x07ff
end_define

begin_comment
comment|/* Active lines */
end_comment

begin_comment
comment|/*  * Video Valid Register  */
end_comment

begin_define
define|#
directive|define
name|VVR_VIDEOVALID
value|0x00000001
end_define

begin_comment
comment|/* 0 VGA, 1 TGA2 (TGA2 only) */
end_comment

begin_define
define|#
directive|define
name|VVR_BLANK
value|0x00000002
end_define

begin_comment
comment|/* 0 active, 1 blank */
end_comment

begin_define
define|#
directive|define
name|VVR_CURSOR
value|0x00000004
end_define

begin_comment
comment|/* 0 disable, 1 enable (TGA2 R/O) */
end_comment

begin_define
define|#
directive|define
name|VVR_INTERLACE
value|0x00000008
end_define

begin_comment
comment|/* 0 N/Int, 1 Int. (TGA2 R/O) */
end_comment

begin_define
define|#
directive|define
name|VVR_DPMS_MASK
value|0x00000030
end_define

begin_comment
comment|/* See "DMPS mask" below */
end_comment

begin_define
define|#
directive|define
name|VVR_DPMS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|VVR_DDC
value|0x00000040
end_define

begin_comment
comment|/* DDC-in pin value (R/O) */
end_comment

begin_define
define|#
directive|define
name|VVR_TILED
value|0x00000400
end_define

begin_comment
comment|/* 0 linear, 1 tiled (not on TGA2) */
end_comment

begin_define
define|#
directive|define
name|VVR_LDDLY_MASK
value|0x01ff0000
end_define

begin_comment
comment|/* load delay in quad pixel clock ticks 					   (not on TGA2) */
end_comment

begin_define
define|#
directive|define
name|VVR_LDDLY_SHIFT
value|16
end_define

begin_comment
comment|/* TGA PCI register values */
end_comment

begin_define
define|#
directive|define
name|DEC_VENDORID
value|0x1011
end_define

begin_define
define|#
directive|define
name|DEC_DEVICEID_TGA
value|0x0004
end_define

begin_define
define|#
directive|define
name|DEC_DEVICEID_TGA2
value|0x000D
end_define

begin_comment
comment|/* This is 0x000C in the documentation,                                           but probing yields 0x000D... */
end_comment

begin_define
define|#
directive|define
name|TGA_TYPE_T8_01
value|0
end_define

begin_comment
comment|/* 8bpp, 1MB */
end_comment

begin_define
define|#
directive|define
name|TGA_TYPE_T8_02
value|1
end_define

begin_comment
comment|/* 8bpp, 2MB */
end_comment

begin_define
define|#
directive|define
name|TGA_TYPE_T8_22
value|2
end_define

begin_comment
comment|/* 8bpp, 4MB */
end_comment

begin_define
define|#
directive|define
name|TGA_TYPE_T8_44
value|3
end_define

begin_comment
comment|/* 8bpp, 8MB */
end_comment

begin_define
define|#
directive|define
name|TGA_TYPE_T32_04
value|4
end_define

begin_comment
comment|/* 32bpp, 4MB */
end_comment

begin_define
define|#
directive|define
name|TGA_TYPE_T32_08
value|5
end_define

begin_comment
comment|/* 32bpp, 8MB */
end_comment

begin_define
define|#
directive|define
name|TGA_TYPE_T32_88
value|6
end_define

begin_comment
comment|/* 32bpp, 16MB */
end_comment

begin_define
define|#
directive|define
name|TGA2_TYPE_3D30
value|7
end_define

begin_comment
comment|/* 8bpp, 8MB */
end_comment

begin_define
define|#
directive|define
name|TGA2_TYPE_4D20
value|8
end_define

begin_comment
comment|/* 32bpp, 16MB */
end_comment

begin_define
define|#
directive|define
name|TGA_TYPE_UNKNOWN
value|9
end_define

begin_comment
comment|/* unknown */
end_comment

begin_comment
comment|/* Possible video modes for TGA2... */
end_comment

begin_define
define|#
directive|define
name|TGA2_VGA_MODE
value|0
end_define

begin_define
define|#
directive|define
name|TGA2_2DA_MODE
value|1
end_define

begin_comment
comment|/* TGA register access macros */
end_comment

begin_define
define|#
directive|define
name|TGA_REG_SPACE_OFFSET
value|0x100000
end_define

begin_define
define|#
directive|define
name|BASIC_READ_TGA_REGISTER
parameter_list|(
name|adp
parameter_list|,
name|reg
parameter_list|)
define|\
value|*(u_int32_t *)((adp)->va_mem_base +			\ 		       (vm_offset_t)TGA_REG_SPACE_OFFSET +	\ 		       (((vm_offset_t)(reg)<< 2L)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCI_TGA_H_ */
end_comment

end_unit

