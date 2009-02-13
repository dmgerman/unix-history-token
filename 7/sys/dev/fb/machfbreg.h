begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1992,1993,1994,1995,1996,1997 by Kevin E. Martin, Chapel Hill, North Carolina.  *  * Permission to use, copy, modify, distribute, and sell this software and  * its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and that  * both that copyright notice and this permission notice appear in  * supporting documentation, and that the name of Kevin E. Martin not be  * used in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  Kevin E. Martin  * makes no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  * KEVIN E. MARTIN, RICKARD E. FAITH, AND TIAGO GONS DISCLAIM ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL THE  * AUTHORS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR  * ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,  * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  *  * Modified for the Mach-8 by Rickard E. Faith (faith@cs.unc.edu)  * Modified for the Mach32 by Kevin E. Martin (martin@cs.unc.edu)  * Modified for the Mach64 by Kevin E. Martin (martin@cs.unc.edu)  *  *	from: NetBSD: machfbreg.h,v 1.1 2002/10/24 18:15:57 junyoung Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_FB_MACHFB_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_FB_MACHFB_H_
end_define

begin_comment
comment|/* NON-GUI MEMORY MAPPED Registers - expressed in BYTE offsets */
end_comment

begin_define
define|#
directive|define
name|CRTC_H_TOTAL_DISP
value|0x0000
end_define

begin_comment
comment|/* Dword offset 00 */
end_comment

begin_define
define|#
directive|define
name|CRTC_H_SYNC_STRT_WID
value|0x0004
end_define

begin_comment
comment|/* Dword offset 01 */
end_comment

begin_define
define|#
directive|define
name|CRTC_V_TOTAL_DISP
value|0x0008
end_define

begin_comment
comment|/* Dword offset 02 */
end_comment

begin_define
define|#
directive|define
name|CRTC_V_SYNC_STRT_WID
value|0x000C
end_define

begin_comment
comment|/* Dword offset 03 */
end_comment

begin_define
define|#
directive|define
name|CRTC_VLINE_CRNT_VLINE
value|0x0010
end_define

begin_comment
comment|/* Dword offset 04 */
end_comment

begin_define
define|#
directive|define
name|CRTC_OFF_PITCH
value|0x0014
end_define

begin_comment
comment|/* Dword offset 05 */
end_comment

begin_define
define|#
directive|define
name|CRTC_INT_CNTL
value|0x0018
end_define

begin_comment
comment|/* Dword offset 06 */
end_comment

begin_define
define|#
directive|define
name|CRTC_GEN_CNTL
value|0x001C
end_define

begin_comment
comment|/* Dword offset 07 */
end_comment

begin_define
define|#
directive|define
name|DSP_CONFIG
value|0x0020
end_define

begin_comment
comment|/* Dword offset 08 */
end_comment

begin_define
define|#
directive|define
name|DSP_ON_OFF
value|0x0024
end_define

begin_comment
comment|/* Dword offset 09 */
end_comment

begin_define
define|#
directive|define
name|SHARED_CNTL
value|0x0038
end_define

begin_comment
comment|/* Dword offset 0E */
end_comment

begin_define
define|#
directive|define
name|OVR_CLR
value|0x0040
end_define

begin_comment
comment|/* Dword offset 10 */
end_comment

begin_define
define|#
directive|define
name|OVR_WID_LEFT_RIGHT
value|0x0044
end_define

begin_comment
comment|/* Dword offset 11 */
end_comment

begin_define
define|#
directive|define
name|OVR_WID_TOP_BOTTOM
value|0x0048
end_define

begin_comment
comment|/* Dword offset 12 */
end_comment

begin_define
define|#
directive|define
name|CUR_CLR0
value|0x0060
end_define

begin_comment
comment|/* Dword offset 18 */
end_comment

begin_define
define|#
directive|define
name|CUR_CLR1
value|0x0064
end_define

begin_comment
comment|/* Dword offset 19 */
end_comment

begin_define
define|#
directive|define
name|CUR_OFFSET
value|0x0068
end_define

begin_comment
comment|/* Dword offset 1A */
end_comment

begin_define
define|#
directive|define
name|CUR_HORZ_VERT_POSN
value|0x006C
end_define

begin_comment
comment|/* Dword offset 1B */
end_comment

begin_define
define|#
directive|define
name|CUR_HORZ_VERT_OFF
value|0x0070
end_define

begin_comment
comment|/* Dword offset 1C */
end_comment

begin_define
define|#
directive|define
name|HW_DEBUG
value|0x007C
end_define

begin_comment
comment|/* Dword offset 1F */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_REG0
value|0x0080
end_define

begin_comment
comment|/* Dword offset 20 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_REG1
value|0x0084
end_define

begin_comment
comment|/* Dword offset 21 */
end_comment

begin_define
define|#
directive|define
name|CLOCK_CNTL
value|0x0090
end_define

begin_comment
comment|/* Dword offset 24 */
end_comment

begin_define
define|#
directive|define
name|BUS_CNTL
value|0x00A0
end_define

begin_comment
comment|/* Dword offset 28 */
end_comment

begin_define
define|#
directive|define
name|LCD_INDEX
value|0x00A4
end_define

begin_comment
comment|/* Dword offset 29 (LTPro) */
end_comment

begin_define
define|#
directive|define
name|LCD_DATA
value|0x00A8
end_define

begin_comment
comment|/* Dword offset 2A (LTPro) */
end_comment

begin_define
define|#
directive|define
name|MEM_CNTL
value|0x00B0
end_define

begin_comment
comment|/* Dword offset 2C */
end_comment

begin_define
define|#
directive|define
name|MEM_VGA_WP_SEL
value|0x00B4
end_define

begin_comment
comment|/* Dword offset 2D */
end_comment

begin_define
define|#
directive|define
name|MEM_VGA_RP_SEL
value|0x00B8
end_define

begin_comment
comment|/* Dword offset 2E */
end_comment

begin_define
define|#
directive|define
name|DAC_REGS
value|0x00C0
end_define

begin_comment
comment|/* Dword offset 30 */
end_comment

begin_define
define|#
directive|define
name|DAC_WINDEX
value|0x00C0
end_define

begin_comment
comment|/* Dword offset 30 */
end_comment

begin_define
define|#
directive|define
name|DAC_DATA
value|0x00C1
end_define

begin_comment
comment|/* Dword offset 30 */
end_comment

begin_define
define|#
directive|define
name|DAC_MASK
value|0x00C2
end_define

begin_comment
comment|/* Dword offset 30 */
end_comment

begin_define
define|#
directive|define
name|DAC_RINDEX
value|0x00C3
end_define

begin_comment
comment|/* Dword offset 30 */
end_comment

begin_define
define|#
directive|define
name|DAC_CNTL
value|0x00C4
end_define

begin_comment
comment|/* Dword offset 31 */
end_comment

begin_define
define|#
directive|define
name|HORZ_STRETCHING
value|0x00C8
end_define

begin_comment
comment|/* Dword offset 32 (LT) */
end_comment

begin_define
define|#
directive|define
name|VERT_STRETCHING
value|0x00CC
end_define

begin_comment
comment|/* Dword offset 33 (LT) */
end_comment

begin_define
define|#
directive|define
name|GEN_TEST_CNTL
value|0x00D0
end_define

begin_comment
comment|/* Dword offset 34 */
end_comment

begin_define
define|#
directive|define
name|LCD_GEN_CNTL
value|0x00D4
end_define

begin_comment
comment|/* Dword offset 35 (LT) */
end_comment

begin_define
define|#
directive|define
name|POWER_MANAGEMENT
value|0x00D8
end_define

begin_comment
comment|/* Dword offset 36 (LT) */
end_comment

begin_define
define|#
directive|define
name|CONFIG_CNTL
value|0x00DC
end_define

begin_comment
comment|/* Dword offset 37 (CT, ET, VT) */
end_comment

begin_define
define|#
directive|define
name|CONFIG_CHIP_ID
value|0x00E0
end_define

begin_comment
comment|/* Dword offset 38 */
end_comment

begin_define
define|#
directive|define
name|CONFIG_STAT0
value|0x00E4
end_define

begin_comment
comment|/* Dword offset 39 */
end_comment

begin_define
define|#
directive|define
name|CONFIG_STAT1
value|0x00E8
end_define

begin_comment
comment|/* Dword offset 3A */
end_comment

begin_comment
comment|/* GUI MEMORY MAPPED Registers */
end_comment

begin_define
define|#
directive|define
name|DST_OFF_PITCH
value|0x0100
end_define

begin_comment
comment|/* Dword offset 40 */
end_comment

begin_define
define|#
directive|define
name|DST_X
value|0x0104
end_define

begin_comment
comment|/* Dword offset 41 */
end_comment

begin_define
define|#
directive|define
name|DST_Y
value|0x0108
end_define

begin_comment
comment|/* Dword offset 42 */
end_comment

begin_define
define|#
directive|define
name|DST_Y_X
value|0x010C
end_define

begin_comment
comment|/* Dword offset 43 */
end_comment

begin_define
define|#
directive|define
name|DST_WIDTH
value|0x0110
end_define

begin_comment
comment|/* Dword offset 44 */
end_comment

begin_define
define|#
directive|define
name|DST_HEIGHT
value|0x0114
end_define

begin_comment
comment|/* Dword offset 45 */
end_comment

begin_define
define|#
directive|define
name|DST_HEIGHT_WIDTH
value|0x0118
end_define

begin_comment
comment|/* Dword offset 46 */
end_comment

begin_define
define|#
directive|define
name|DST_X_WIDTH
value|0x011C
end_define

begin_comment
comment|/* Dword offset 47 */
end_comment

begin_define
define|#
directive|define
name|DST_BRES_LNTH
value|0x0120
end_define

begin_comment
comment|/* Dword offset 48 */
end_comment

begin_define
define|#
directive|define
name|DST_BRES_ERR
value|0x0124
end_define

begin_comment
comment|/* Dword offset 49 */
end_comment

begin_define
define|#
directive|define
name|DST_BRES_INC
value|0x0128
end_define

begin_comment
comment|/* Dword offset 4A */
end_comment

begin_define
define|#
directive|define
name|DST_BRES_DEC
value|0x012C
end_define

begin_comment
comment|/* Dword offset 4B */
end_comment

begin_define
define|#
directive|define
name|DST_CNTL
value|0x0130
end_define

begin_comment
comment|/* Dword offset 4C */
end_comment

begin_define
define|#
directive|define
name|SRC_OFF_PITCH
value|0x0180
end_define

begin_comment
comment|/* Dword offset 60 */
end_comment

begin_define
define|#
directive|define
name|SRC_X
value|0x0184
end_define

begin_comment
comment|/* Dword offset 61 */
end_comment

begin_define
define|#
directive|define
name|SRC_Y
value|0x0188
end_define

begin_comment
comment|/* Dword offset 62 */
end_comment

begin_define
define|#
directive|define
name|SRC_Y_X
value|0x018C
end_define

begin_comment
comment|/* Dword offset 63 */
end_comment

begin_define
define|#
directive|define
name|SRC_WIDTH1
value|0x0190
end_define

begin_comment
comment|/* Dword offset 64 */
end_comment

begin_define
define|#
directive|define
name|SRC_HEIGHT1
value|0x0194
end_define

begin_comment
comment|/* Dword offset 65 */
end_comment

begin_define
define|#
directive|define
name|SRC_HEIGHT1_WIDTH1
value|0x0198
end_define

begin_comment
comment|/* Dword offset 66 */
end_comment

begin_define
define|#
directive|define
name|SRC_X_START
value|0x019C
end_define

begin_comment
comment|/* Dword offset 67 */
end_comment

begin_define
define|#
directive|define
name|SRC_Y_START
value|0x01A0
end_define

begin_comment
comment|/* Dword offset 68 */
end_comment

begin_define
define|#
directive|define
name|SRC_Y_X_START
value|0x01A4
end_define

begin_comment
comment|/* Dword offset 69 */
end_comment

begin_define
define|#
directive|define
name|SRC_WIDTH2
value|0x01A8
end_define

begin_comment
comment|/* Dword offset 6A */
end_comment

begin_define
define|#
directive|define
name|SRC_HEIGHT2
value|0x01AC
end_define

begin_comment
comment|/* Dword offset 6B */
end_comment

begin_define
define|#
directive|define
name|SRC_HEIGHT2_WIDTH2
value|0x01B0
end_define

begin_comment
comment|/* Dword offset 6C */
end_comment

begin_define
define|#
directive|define
name|SRC_CNTL
value|0x01B4
end_define

begin_comment
comment|/* Dword offset 6D */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA0
value|0x0200
end_define

begin_comment
comment|/* Dword offset 80 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA1
value|0x0204
end_define

begin_comment
comment|/* Dword offset 81 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA2
value|0x0208
end_define

begin_comment
comment|/* Dword offset 82 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA3
value|0x020C
end_define

begin_comment
comment|/* Dword offset 83 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA4
value|0x0210
end_define

begin_comment
comment|/* Dword offset 84 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA5
value|0x0214
end_define

begin_comment
comment|/* Dword offset 85 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA6
value|0x0218
end_define

begin_comment
comment|/* Dword offset 86 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA7
value|0x021C
end_define

begin_comment
comment|/* Dword offset 87 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA8
value|0x0220
end_define

begin_comment
comment|/* Dword offset 88 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATA9
value|0x0224
end_define

begin_comment
comment|/* Dword offset 89 */
end_comment

begin_define
define|#
directive|define
name|HOST_DATAA
value|0x0228
end_define

begin_comment
comment|/* Dword offset 8A */
end_comment

begin_define
define|#
directive|define
name|HOST_DATAB
value|0x022C
end_define

begin_comment
comment|/* Dword offset 8B */
end_comment

begin_define
define|#
directive|define
name|HOST_DATAC
value|0x0230
end_define

begin_comment
comment|/* Dword offset 8C */
end_comment

begin_define
define|#
directive|define
name|HOST_DATAD
value|0x0234
end_define

begin_comment
comment|/* Dword offset 8D */
end_comment

begin_define
define|#
directive|define
name|HOST_DATAE
value|0x0238
end_define

begin_comment
comment|/* Dword offset 8E */
end_comment

begin_define
define|#
directive|define
name|HOST_DATAF
value|0x023C
end_define

begin_comment
comment|/* Dword offset 8F */
end_comment

begin_define
define|#
directive|define
name|HOST_CNTL
value|0x0240
end_define

begin_comment
comment|/* Dword offset 90 */
end_comment

begin_define
define|#
directive|define
name|PAT_REG0
value|0x0280
end_define

begin_comment
comment|/* Dword offset A0 */
end_comment

begin_define
define|#
directive|define
name|PAT_REG1
value|0x0284
end_define

begin_comment
comment|/* Dword offset A1 */
end_comment

begin_define
define|#
directive|define
name|PAT_CNTL
value|0x0288
end_define

begin_comment
comment|/* Dword offset A2 */
end_comment

begin_define
define|#
directive|define
name|SC_LEFT
value|0x02A0
end_define

begin_comment
comment|/* Dword offset A8 */
end_comment

begin_define
define|#
directive|define
name|SC_RIGHT
value|0x02A4
end_define

begin_comment
comment|/* Dword offset A9 */
end_comment

begin_define
define|#
directive|define
name|SC_LEFT_RIGHT
value|0x02A8
end_define

begin_comment
comment|/* Dword offset AA */
end_comment

begin_define
define|#
directive|define
name|SC_TOP
value|0x02AC
end_define

begin_comment
comment|/* Dword offset AB */
end_comment

begin_define
define|#
directive|define
name|SC_BOTTOM
value|0x02B0
end_define

begin_comment
comment|/* Dword offset AC */
end_comment

begin_define
define|#
directive|define
name|SC_TOP_BOTTOM
value|0x02B4
end_define

begin_comment
comment|/* Dword offset AD */
end_comment

begin_define
define|#
directive|define
name|DP_BKGD_CLR
value|0x02C0
end_define

begin_comment
comment|/* Dword offset B0 */
end_comment

begin_define
define|#
directive|define
name|DP_FRGD_CLR
value|0x02C4
end_define

begin_comment
comment|/* Dword offset B1 */
end_comment

begin_define
define|#
directive|define
name|DP_WRITE_MASK
value|0x02C8
end_define

begin_comment
comment|/* Dword offset B2 */
end_comment

begin_define
define|#
directive|define
name|DP_CHAIN_MASK
value|0x02CC
end_define

begin_comment
comment|/* Dword offset B3 */
end_comment

begin_define
define|#
directive|define
name|DP_PIX_WIDTH
value|0x02D0
end_define

begin_comment
comment|/* Dword offset B4 */
end_comment

begin_define
define|#
directive|define
name|DP_MIX
value|0x02D4
end_define

begin_comment
comment|/* Dword offset B5 */
end_comment

begin_define
define|#
directive|define
name|DP_SRC
value|0x02D8
end_define

begin_comment
comment|/* Dword offset B6 */
end_comment

begin_define
define|#
directive|define
name|CLR_CMP_CLR
value|0x0300
end_define

begin_comment
comment|/* Dword offset C0 */
end_comment

begin_define
define|#
directive|define
name|CLR_CMP_MASK
value|0x0304
end_define

begin_comment
comment|/* Dword offset C1 */
end_comment

begin_define
define|#
directive|define
name|CLR_CMP_CNTL
value|0x0308
end_define

begin_comment
comment|/* Dword offset C2 */
end_comment

begin_define
define|#
directive|define
name|FIFO_STAT
value|0x0310
end_define

begin_comment
comment|/* Dword offset C4 */
end_comment

begin_define
define|#
directive|define
name|CONTEXT_MASK
value|0x0320
end_define

begin_comment
comment|/* Dword offset C8 */
end_comment

begin_define
define|#
directive|define
name|CONTEXT_LOAD_CNTL
value|0x032C
end_define

begin_comment
comment|/* Dword offset CB */
end_comment

begin_define
define|#
directive|define
name|GUI_TRAJ_CNTL
value|0x0330
end_define

begin_comment
comment|/* Dword offset CC */
end_comment

begin_define
define|#
directive|define
name|GUI_STAT
value|0x0338
end_define

begin_comment
comment|/* Dword offset CE */
end_comment

begin_comment
comment|/* CRTC control values */
end_comment

begin_define
define|#
directive|define
name|CRTC_HSYNC_NEG
value|0x00200000
end_define

begin_define
define|#
directive|define
name|CRTC_VSYNC_NEG
value|0x00200000
end_define

begin_define
define|#
directive|define
name|CRTC_DBL_SCAN_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CRTC_INTERLACE_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CRTC_HSYNC_DIS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CRTC_VSYNC_DIS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CRTC_CSYNC_EN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_BY_2_EN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CRTC_DISPLAY_DIS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CRTC_VGA_XOVERSCAN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_WIDTH
value|0x00000700
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_WIDTH_4BPP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_WIDTH_8BPP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_WIDTH_15BPP
value|0x00000300
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_WIDTH_16BPP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_WIDTH_24BPP
value|0x00000500
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_WIDTH_32BPP
value|0x00000600
end_define

begin_define
define|#
directive|define
name|CRTC_BYTE_PIX_ORDER
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_ORDER_MSN_LSN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CRTC_PIX_ORDER_LSN_MSN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CRTC_FIFO_LWM
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|CRTC_LOCK_REGS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CRTC_EXT_DISP_EN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CRTC_EN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CRTC_DISP_REQ_EN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CRTC_VGA_LINEAR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CRTC_VSYNC_FALL_EDGE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CRTC_VGA_TEXT_132
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CRTC_CNT_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CRTC_CUR_B_TEST
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CRTC_CRNT_VLINE
value|0x07f00000
end_define

begin_define
define|#
directive|define
name|CRTC_VBLANK
value|0x00000001
end_define

begin_comment
comment|/* DAC control values */
end_comment

begin_define
define|#
directive|define
name|DAC_EXT_SEL_RS2
value|0x01
end_define

begin_define
define|#
directive|define
name|DAC_EXT_SEL_RS3
value|0x02
end_define

begin_define
define|#
directive|define
name|DAC_8BIT_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DAC_PIX_DLY_MASK
value|0x00000600
end_define

begin_define
define|#
directive|define
name|DAC_PIX_DLY_0NS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DAC_PIX_DLY_2NS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DAC_PIX_DLY_4NS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DAC_BLANK_ADJ_MASK
value|0x00001800
end_define

begin_define
define|#
directive|define
name|DAC_BLANK_ADJ_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DAC_BLANK_ADJ_1
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DAC_BLANK_ADJ_2
value|0x00001000
end_define

begin_comment
comment|/* Mix control values */
end_comment

begin_define
define|#
directive|define
name|MIX_NOT_DST
value|0x0000
end_define

begin_define
define|#
directive|define
name|MIX_0
value|0x0001
end_define

begin_define
define|#
directive|define
name|MIX_1
value|0x0002
end_define

begin_define
define|#
directive|define
name|MIX_DST
value|0x0003
end_define

begin_define
define|#
directive|define
name|MIX_NOT_SRC
value|0x0004
end_define

begin_define
define|#
directive|define
name|MIX_XOR
value|0x0005
end_define

begin_define
define|#
directive|define
name|MIX_XNOR
value|0x0006
end_define

begin_define
define|#
directive|define
name|MIX_SRC
value|0x0007
end_define

begin_define
define|#
directive|define
name|MIX_NAND
value|0x0008
end_define

begin_define
define|#
directive|define
name|MIX_NOT_SRC_OR_DST
value|0x0009
end_define

begin_define
define|#
directive|define
name|MIX_SRC_OR_NOT_DST
value|0x000a
end_define

begin_define
define|#
directive|define
name|MIX_OR
value|0x000b
end_define

begin_define
define|#
directive|define
name|MIX_AND
value|0x000c
end_define

begin_define
define|#
directive|define
name|MIX_SRC_AND_NOT_DST
value|0x000d
end_define

begin_define
define|#
directive|define
name|MIX_NOT_SRC_AND_DST
value|0x000e
end_define

begin_define
define|#
directive|define
name|MIX_NOR
value|0x000f
end_define

begin_comment
comment|/* Maximum engine dimensions */
end_comment

begin_define
define|#
directive|define
name|ENGINE_MIN_X
value|0
end_define

begin_define
define|#
directive|define
name|ENGINE_MIN_Y
value|0
end_define

begin_define
define|#
directive|define
name|ENGINE_MAX_X
value|4095
end_define

begin_define
define|#
directive|define
name|ENGINE_MAX_Y
value|16383
end_define

begin_comment
comment|/* Mach64 engine bit constants - these are typically ORed together */
end_comment

begin_comment
comment|/* HW_DEBUG register constants */
end_comment

begin_comment
comment|/* For RagePro only... */
end_comment

begin_define
define|#
directive|define
name|AUTO_FF_DIS
value|0x000001000
end_define

begin_define
define|#
directive|define
name|AUTO_BLKWRT_DIS
value|0x000002000
end_define

begin_comment
comment|/* BUS_CNTL register constants */
end_comment

begin_define
define|#
directive|define
name|BUS_FIFO_ERR_ACK
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BUS_HOST_ERR_ACK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BUS_APER_REG_DIS
value|0x00000010
end_define

begin_comment
comment|/* GEN_TEST_CNTL register constants */
end_comment

begin_define
define|#
directive|define
name|GEN_OVR_OUTPUT_EN
value|0x20
end_define

begin_define
define|#
directive|define
name|HWCURSOR_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|GUI_ENGINE_ENABLE
value|0x100
end_define

begin_define
define|#
directive|define
name|BLOCK_WRITE_ENABLE
value|0x200
end_define

begin_comment
comment|/* DSP_CONFIG register constants */
end_comment

begin_define
define|#
directive|define
name|DSP_XCLKS_PER_QW
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|DSP_LOOP_LATENCY
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|DSP_PRECISION
value|0x00700000
end_define

begin_comment
comment|/* DSP_ON_OFF register constants */
end_comment

begin_define
define|#
directive|define
name|DSP_OFF
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|DSP_ON
value|0x07ff0000
end_define

begin_comment
comment|/* SHARED_CNTL register constants */
end_comment

begin_define
define|#
directive|define
name|CTD_FIFO5
value|0x01000000
end_define

begin_comment
comment|/* CLOCK_CNTL register constants */
end_comment

begin_define
define|#
directive|define
name|CLOCK_SEL
value|0x0f
end_define

begin_define
define|#
directive|define
name|CLOCK_DIV
value|0x30
end_define

begin_define
define|#
directive|define
name|CLOCK_DIV1
value|0x00
end_define

begin_define
define|#
directive|define
name|CLOCK_DIV2
value|0x10
end_define

begin_define
define|#
directive|define
name|CLOCK_DIV4
value|0x20
end_define

begin_define
define|#
directive|define
name|CLOCK_STROBE
value|0x40
end_define

begin_define
define|#
directive|define
name|PLL_WR_EN
value|0x02
end_define

begin_comment
comment|/* PLL registers */
end_comment

begin_define
define|#
directive|define
name|PLL_MACRO_CNTL
value|0x01
end_define

begin_define
define|#
directive|define
name|PLL_REF_DIV
value|0x02
end_define

begin_define
define|#
directive|define
name|PLL_GEN_CNTL
value|0x03
end_define

begin_define
define|#
directive|define
name|MCLK_FB_DIV
value|0x04
end_define

begin_define
define|#
directive|define
name|PLL_VCLK_CNTL
value|0x05
end_define

begin_define
define|#
directive|define
name|VCLK_POST_DIV
value|0x06
end_define

begin_define
define|#
directive|define
name|VCLK0_FB_DIV
value|0x07
end_define

begin_define
define|#
directive|define
name|VCLK1_FB_DIV
value|0x08
end_define

begin_define
define|#
directive|define
name|VCLK2_FB_DIV
value|0x09
end_define

begin_define
define|#
directive|define
name|VCLK3_FB_DIV
value|0x0A
end_define

begin_define
define|#
directive|define
name|PLL_XCLK_CNTL
value|0x0B
end_define

begin_define
define|#
directive|define
name|PLL_TEST_CTRL
value|0x0E
end_define

begin_define
define|#
directive|define
name|PLL_TEST_COUNT
value|0x0F
end_define

begin_comment
comment|/* Memory types for CT, ET, VT, GT */
end_comment

begin_define
define|#
directive|define
name|DRAM
value|1
end_define

begin_define
define|#
directive|define
name|EDO_DRAM
value|2
end_define

begin_define
define|#
directive|define
name|PSEUDO_EDO
value|3
end_define

begin_define
define|#
directive|define
name|SDRAM
value|4
end_define

begin_define
define|#
directive|define
name|SGRAM
value|5
end_define

begin_define
define|#
directive|define
name|SGRAM32
value|6
end_define

begin_define
define|#
directive|define
name|DAC_INTERNAL
value|0x00
end_define

begin_define
define|#
directive|define
name|DAC_IBMRGB514
value|0x01
end_define

begin_define
define|#
directive|define
name|DAC_ATI68875
value|0x02
end_define

begin_define
define|#
directive|define
name|DAC_TVP3026_A
value|0x72
end_define

begin_define
define|#
directive|define
name|DAC_BT476
value|0x03
end_define

begin_define
define|#
directive|define
name|DAC_BT481
value|0x04
end_define

begin_define
define|#
directive|define
name|DAC_ATT20C491
value|0x14
end_define

begin_define
define|#
directive|define
name|DAC_SC15026
value|0x24
end_define

begin_define
define|#
directive|define
name|DAC_MU9C1880
value|0x34
end_define

begin_define
define|#
directive|define
name|DAC_IMSG174
value|0x44
end_define

begin_define
define|#
directive|define
name|DAC_ATI68860_B
value|0x05
end_define

begin_define
define|#
directive|define
name|DAC_ATI68860_C
value|0x15
end_define

begin_define
define|#
directive|define
name|DAC_TVP3026_B
value|0x75
end_define

begin_define
define|#
directive|define
name|DAC_STG1700
value|0x06
end_define

begin_define
define|#
directive|define
name|DAC_ATT498
value|0x16
end_define

begin_define
define|#
directive|define
name|DAC_STG1702
value|0x07
end_define

begin_define
define|#
directive|define
name|DAC_SC15021
value|0x17
end_define

begin_define
define|#
directive|define
name|DAC_ATT21C498
value|0x27
end_define

begin_define
define|#
directive|define
name|DAC_STG1703
value|0x37
end_define

begin_define
define|#
directive|define
name|DAC_CH8398
value|0x47
end_define

begin_define
define|#
directive|define
name|DAC_ATT20C408
value|0x57
end_define

begin_define
define|#
directive|define
name|CLK_ATI18818_0
value|0
end_define

begin_define
define|#
directive|define
name|CLK_ATI18818_1
value|1
end_define

begin_define
define|#
directive|define
name|CLK_STG1703
value|2
end_define

begin_define
define|#
directive|define
name|CLK_CH8398
value|3
end_define

begin_define
define|#
directive|define
name|CLK_INTERNAL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_ATT20C408
value|5
end_define

begin_define
define|#
directive|define
name|CLK_IBMRGB514
value|6
end_define

begin_comment
comment|/* DST_CNTL register constants */
end_comment

begin_define
define|#
directive|define
name|DST_X_RIGHT_TO_LEFT
value|0
end_define

begin_define
define|#
directive|define
name|DST_X_LEFT_TO_RIGHT
value|1
end_define

begin_define
define|#
directive|define
name|DST_Y_BOTTOM_TO_TOP
value|0
end_define

begin_define
define|#
directive|define
name|DST_Y_TOP_TO_BOTTOM
value|2
end_define

begin_define
define|#
directive|define
name|DST_X_MAJOR
value|0
end_define

begin_define
define|#
directive|define
name|DST_Y_MAJOR
value|4
end_define

begin_define
define|#
directive|define
name|DST_X_TILE
value|8
end_define

begin_define
define|#
directive|define
name|DST_Y_TILE
value|0x10
end_define

begin_define
define|#
directive|define
name|DST_LAST_PEL
value|0x20
end_define

begin_define
define|#
directive|define
name|DST_POLYGON_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|DST_24_ROTATION_ENABLE
value|0x80
end_define

begin_comment
comment|/* SRC_CNTL register constants */
end_comment

begin_define
define|#
directive|define
name|SRC_PATTERN_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|SRC_ROTATION_ENABLE
value|2
end_define

begin_define
define|#
directive|define
name|SRC_LINEAR_ENABLE
value|4
end_define

begin_define
define|#
directive|define
name|SRC_BYTE_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|SRC_LINE_X_RIGHT_TO_LEFT
value|0
end_define

begin_define
define|#
directive|define
name|SRC_LINE_X_LEFT_TO_RIGHT
value|0x10
end_define

begin_comment
comment|/* HOST_CNTL register constants */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ALIGN
value|1
end_define

begin_comment
comment|/* DP_CHAIN_MASK register constants */
end_comment

begin_define
define|#
directive|define
name|DP_CHAIN_4BPP
value|0x8888
end_define

begin_define
define|#
directive|define
name|DP_CHAIN_7BPP
value|0xD2D2
end_define

begin_define
define|#
directive|define
name|DP_CHAIN_8BPP
value|0x8080
end_define

begin_define
define|#
directive|define
name|DP_CHAIN_8BPP_RGB
value|0x9292
end_define

begin_define
define|#
directive|define
name|DP_CHAIN_15BPP
value|0x4210
end_define

begin_define
define|#
directive|define
name|DP_CHAIN_16BPP
value|0x8410
end_define

begin_define
define|#
directive|define
name|DP_CHAIN_24BPP
value|0x8080
end_define

begin_define
define|#
directive|define
name|DP_CHAIN_32BPP
value|0x8080
end_define

begin_comment
comment|/* DP_PIX_WIDTH register constants */
end_comment

begin_define
define|#
directive|define
name|DST_1BPP
value|0
end_define

begin_define
define|#
directive|define
name|DST_4BPP
value|1
end_define

begin_define
define|#
directive|define
name|DST_8BPP
value|2
end_define

begin_define
define|#
directive|define
name|DST_15BPP
value|3
end_define

begin_define
define|#
directive|define
name|DST_16BPP
value|4
end_define

begin_define
define|#
directive|define
name|DST_32BPP
value|6
end_define

begin_define
define|#
directive|define
name|SRC_1BPP
value|0
end_define

begin_define
define|#
directive|define
name|SRC_4BPP
value|0x100
end_define

begin_define
define|#
directive|define
name|SRC_8BPP
value|0x200
end_define

begin_define
define|#
directive|define
name|SRC_15BPP
value|0x300
end_define

begin_define
define|#
directive|define
name|SRC_16BPP
value|0x400
end_define

begin_define
define|#
directive|define
name|SRC_32BPP
value|0x600
end_define

begin_define
define|#
directive|define
name|HOST_1BPP
value|0
end_define

begin_define
define|#
directive|define
name|HOST_4BPP
value|0x10000
end_define

begin_define
define|#
directive|define
name|HOST_8BPP
value|0x20000
end_define

begin_define
define|#
directive|define
name|HOST_15BPP
value|0x30000
end_define

begin_define
define|#
directive|define
name|HOST_16BPP
value|0x40000
end_define

begin_define
define|#
directive|define
name|HOST_32BPP
value|0x60000
end_define

begin_define
define|#
directive|define
name|BYTE_ORDER_MSB_TO_LSB
value|0
end_define

begin_define
define|#
directive|define
name|BYTE_ORDER_LSB_TO_MSB
value|0x1000000
end_define

begin_comment
comment|/* DP_SRC register constants */
end_comment

begin_define
define|#
directive|define
name|BKGD_SRC_BKGD_CLR
value|0
end_define

begin_define
define|#
directive|define
name|BKGD_SRC_FRGD_CLR
value|1
end_define

begin_define
define|#
directive|define
name|BKGD_SRC_HOST
value|2
end_define

begin_define
define|#
directive|define
name|BKGD_SRC_BLIT
value|3
end_define

begin_define
define|#
directive|define
name|BKGD_SRC_PATTERN
value|4
end_define

begin_define
define|#
directive|define
name|FRGD_SRC_BKGD_CLR
value|0
end_define

begin_define
define|#
directive|define
name|FRGD_SRC_FRGD_CLR
value|0x100
end_define

begin_define
define|#
directive|define
name|FRGD_SRC_HOST
value|0x200
end_define

begin_define
define|#
directive|define
name|FRGD_SRC_BLIT
value|0x300
end_define

begin_define
define|#
directive|define
name|FRGD_SRC_PATTERN
value|0x400
end_define

begin_define
define|#
directive|define
name|MONO_SRC_ONE
value|0
end_define

begin_define
define|#
directive|define
name|MONO_SRC_PATTERN
value|0x10000
end_define

begin_define
define|#
directive|define
name|MONO_SRC_HOST
value|0x20000
end_define

begin_define
define|#
directive|define
name|MONO_SRC_BLIT
value|0x30000
end_define

begin_comment
comment|/* PCI IDs */
end_comment

begin_define
define|#
directive|define
name|ATI_VENDOR
value|0x1002
end_define

begin_define
define|#
directive|define
name|ATI_MACH64_CT
value|0x4354
end_define

begin_comment
comment|/* Mach64 CT */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_PRO_AGP
value|0x4742
end_define

begin_comment
comment|/* 3D Rage Pro (AGP) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_PRO_AGP1X
value|0x4744
end_define

begin_comment
comment|/* 3D Rage Pro (AGP 1x) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_PRO_PCI_B
value|0x4749
end_define

begin_comment
comment|/* 3D Rage Pro Turbo */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_XC_PCI66
value|0x474c
end_define

begin_comment
comment|/* Rage XC (PCI66) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_XL_AGP
value|0x474d
end_define

begin_comment
comment|/* Rage XL (AGP) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_XC_AGP
value|0x474e
end_define

begin_comment
comment|/* Rage XC (AGP) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_XL_PCI66
value|0x474f
end_define

begin_comment
comment|/* Rage XL (PCI66) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_PRO_PCI_P
value|0x4750
end_define

begin_comment
comment|/* 3D Rage Pro */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_PRO_PCI_L
value|0x4751
end_define

begin_comment
comment|/* 3D Rage Pro (limited 3D) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_XL_PCI
value|0x4752
end_define

begin_comment
comment|/* Rage XL */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_XC_PCI
value|0x4753
end_define

begin_comment
comment|/* Rage XC */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_II
value|0x4754
end_define

begin_comment
comment|/* 3D Rage I/II */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_IIP
value|0x4755
end_define

begin_comment
comment|/* 3D Rage II+ */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_IIC_PCI
value|0x4756
end_define

begin_comment
comment|/* 3D Rage IIC */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_IIC_AGP_B
value|0x4757
end_define

begin_comment
comment|/* 3D Rage IIC (AGP) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_IIC_AGP_P
value|0x475a
end_define

begin_comment
comment|/* 3D Rage IIC (AGP) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_LT_PRO_AGP
value|0x4c42
end_define

begin_comment
comment|/* 3D Rage LT Pro (AGP 133MHz) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_MOB_M3_PCI
value|0x4c45
end_define

begin_comment
comment|/* Rage Mobility M3 */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_MOB_M3_AGP
value|0x4c46
end_define

begin_comment
comment|/* Rage Mobility M3 (AGP) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_LT
value|0x4c47
end_define

begin_comment
comment|/* 3D Rage LT */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_LT_PRO_PCI
value|0x4c49
end_define

begin_comment
comment|/* 3D Rage LT Pro */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_MOBILITY
value|0x4c4d
end_define

begin_comment
comment|/* Rage Mobility */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_L_MOBILITY
value|0x4c4e
end_define

begin_comment
comment|/* Rage L Mobility */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_LT_PRO
value|0x4c50
end_define

begin_comment
comment|/* 3D Rage LT Pro */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_LT_PRO2
value|0x4c51
end_define

begin_comment
comment|/* 3D Rage LT Pro */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_MOB_M1_PCI
value|0x4c52
end_define

begin_comment
comment|/* Rage Mobility M1 (PCI) */
end_comment

begin_define
define|#
directive|define
name|ATI_RAGE_L_MOB_M1_PCI
value|0x4c53
end_define

begin_comment
comment|/* Rage L Mobility (PCI) */
end_comment

begin_define
define|#
directive|define
name|ATI_MACH64_VT
value|0x5654
end_define

begin_comment
comment|/* Mach64 VT */
end_comment

begin_define
define|#
directive|define
name|ATI_MACH64_VTB
value|0x5655
end_define

begin_comment
comment|/* Mach64 VTB */
end_comment

begin_define
define|#
directive|define
name|ATI_MACH64_VT4
value|0x5656
end_define

begin_comment
comment|/* Mach64 VT4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_FB_MACHFB_H_ */
end_comment

end_unit

