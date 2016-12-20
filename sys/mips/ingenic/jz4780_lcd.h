begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Jared McNeill<jmcneill@invisible.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Ingenic JZ4780 LCD Controller  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__JZ4780_LCD_H__
end_ifndef

begin_define
define|#
directive|define
name|__JZ4780_LCD_H__
end_define

begin_define
define|#
directive|define
name|LCDCFG
value|0x0000
end_define

begin_define
define|#
directive|define
name|LCDCFG_LCDPIN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|LCDCFG_TVEPEH
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|LCDCFG_NEWDES
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|LCDCFG_PALBP
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|LCDCFG_TVEN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|LCDCFG_RECOVER
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|LCDCFG_PSM
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|LCDCFG_CLSM
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|LCDCFG_SPLM
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|LCDCFG_REVM
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|LCDCFG_HSYNM
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|LCDCFG_VSYNM
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|LCDCFG_INVDAT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|LCDCFG_SYNDIR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|LCDCFG_PSP
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|LCDCFG_CLSP
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LCDCFG_SPLP
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LCDCFG_REVP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|LCDCFG_HSP
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LCDCFG_PCP
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LCDCFG_DEP
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LCDCFG_VSP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LCDCFG_18_16
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LCDCFG_24
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LCDCFG_MODE
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL
value|0x0030
end_define

begin_define
define|#
directive|define
name|LCDCTRL_PINMD
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BST
value|(0x7<< 28)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BST_4
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BST_8
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BST_16
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BST_32
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BST_64
value|(4<< 28)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_OUTRGB
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_OFUP
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_DACTE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_EOFM
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_SOFM
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_OFUM
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_IFUM0
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_IFUM1
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_LDDM
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_QDM
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BEDN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_PEDN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_DIS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_ENA
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0
value|(0x7<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0_1
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0_2
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0_4
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0_8
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0_15_16
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0_18_24
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0_24_COMP
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTRL_BPP0_30
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|LCDCTR
end_define

begin_define
define|#
directive|define
name|LCDSTATE
value|0x0034
end_define

begin_define
define|#
directive|define
name|LCDSTATE_QD
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LCDSTATE_EOF
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LCDSTATE_SOF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LCDSTATE_OUT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LCDSTATE_IFU0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LCDSTATE_IFU1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LCDSTATE_LDD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LCDOSDC
value|0x0100
end_define

begin_define
define|#
directive|define
name|LCDOSDCTRL
value|0x0104
end_define

begin_define
define|#
directive|define
name|LCDOSDS
value|0x0108
end_define

begin_define
define|#
directive|define
name|LCDBGC0
value|0x010c
end_define

begin_define
define|#
directive|define
name|LCDBGC1
value|0x02c4
end_define

begin_define
define|#
directive|define
name|LCDKEY0
value|0x0110
end_define

begin_define
define|#
directive|define
name|LCDKEY1
value|0x0114
end_define

begin_define
define|#
directive|define
name|LCDALPHA
value|0x0118
end_define

begin_define
define|#
directive|define
name|LCDIPUR
value|0x011c
end_define

begin_define
define|#
directive|define
name|LCDRGBC
value|0x0090
end_define

begin_define
define|#
directive|define
name|LCDRGBC_RGBDM
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|LCDRGBC_DMM
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LCDRGBC_422
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LCDRGBC_RGBFMT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LCDRGBC_ODDRGB
value|(0x7<< 4)
end_define

begin_define
define|#
directive|define
name|LCDRGBC_EVENRGB
value|(0x7<< 0)
end_define

begin_define
define|#
directive|define
name|LCDVAT
value|0x000c
end_define

begin_define
define|#
directive|define
name|LCDVAT_HT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|LCDVAT_VT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LCDDAH
value|0x0010
end_define

begin_define
define|#
directive|define
name|LCDDAH_HDS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|LCDDAH_HDE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LCDDAV
value|0x0014
end_define

begin_define
define|#
directive|define
name|LCDDAV_VDS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|LCDDAV_VDE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LCDXYP0
value|0x0120
end_define

begin_define
define|#
directive|define
name|LCDXYP1
value|0x0124
end_define

begin_define
define|#
directive|define
name|LCDSIZE0
value|0x0128
end_define

begin_define
define|#
directive|define
name|LCDSIZE1
value|0x012c
end_define

begin_define
define|#
directive|define
name|LCDVSYNC
value|0x0004
end_define

begin_define
define|#
directive|define
name|LCDHSYNC
value|0x0008
end_define

begin_define
define|#
directive|define
name|LCDPS
value|0x0018
end_define

begin_define
define|#
directive|define
name|LCDCLS
value|0x001c
end_define

begin_define
define|#
directive|define
name|LCDSPL
value|0x0020
end_define

begin_define
define|#
directive|define
name|LCDREV
value|0x0024
end_define

begin_define
define|#
directive|define
name|LCDIID
value|0x0038
end_define

begin_define
define|#
directive|define
name|LCDDA0
value|0x0040
end_define

begin_define
define|#
directive|define
name|LCDSA0
value|0x0044
end_define

begin_define
define|#
directive|define
name|LCDFID0
value|0x0048
end_define

begin_define
define|#
directive|define
name|LCDCMD0
value|0x004c
end_define

begin_define
define|#
directive|define
name|LCDCMD_SOFINT
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|LCDCMD_EOFINT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|LCDCMD_CMD
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|LCDCMD_COMPE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|LCDCMD_FRM_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|LCDCMD_FIELD_SEL
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|LCDCMD_16X16BLOCK
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|LCDCMD_LEN
value|(0xffffff<< 0)
end_define

begin_define
define|#
directive|define
name|LCDOFFS0
value|0x0060
end_define

begin_define
define|#
directive|define
name|LCDPW0
value|0x0064
end_define

begin_define
define|#
directive|define
name|LCDCNUM0
value|0x0068
end_define

begin_define
define|#
directive|define
name|LCDPOS0
value|LCDCNUM0
end_define

begin_define
define|#
directive|define
name|LCDPOS_ALPHAMD1
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|LCDPOS_RGB01
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|LCDPOS_BPP01
value|(0x7<< 27)
end_define

begin_define
define|#
directive|define
name|LCDPOS_BPP01_15_16
value|(4<< 27)
end_define

begin_define
define|#
directive|define
name|LCDPOS_BPP01_18_24
value|(5<< 27)
end_define

begin_define
define|#
directive|define
name|LCDPOS_BPP01_24_COMP
value|(6<< 27)
end_define

begin_define
define|#
directive|define
name|LCDPOS_BPP01_30
value|(7<< 27)
end_define

begin_define
define|#
directive|define
name|LCDPOS_PREMULTI01
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|LCDPOS_COEF_SLE01
value|(0x3<< 24)
end_define

begin_define
define|#
directive|define
name|LCDPOS_COEF_BLE01_1
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|LCDPOS_YPOS01
value|(0xfff<< 12)
end_define

begin_define
define|#
directive|define
name|LCDPOS_XPOS01
value|(0xfff<< 0)
end_define

begin_define
define|#
directive|define
name|LCDDESSIZE0
value|0x006c
end_define

begin_define
define|#
directive|define
name|LCDDESSIZE_ALPHA
value|(0xff<< 24)
end_define

begin_define
define|#
directive|define
name|LCDDESSIZE_HEIGHT
value|(0xfff<< 12)
end_define

begin_define
define|#
directive|define
name|LCDDESSIZE_HEIGHT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|LCDDESSIZE_WIDTH
value|(0xfff<< 0)
end_define

begin_define
define|#
directive|define
name|LCDDESSIZE_WIDTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LCDDA1
value|0x0050
end_define

begin_define
define|#
directive|define
name|LCDSA1
value|0x0054
end_define

begin_define
define|#
directive|define
name|LCDFID1
value|0x0058
end_define

begin_define
define|#
directive|define
name|LCDCMD1
value|0x005c
end_define

begin_define
define|#
directive|define
name|LCDOFFS1
value|0x0070
end_define

begin_define
define|#
directive|define
name|LCDPW1
value|0x0074
end_define

begin_define
define|#
directive|define
name|LCDCNUM1
value|0x0078
end_define

begin_define
define|#
directive|define
name|LCDPOS1
value|LCDCNUM1
end_define

begin_define
define|#
directive|define
name|LCDDESSIZE1
value|0x007c
end_define

begin_define
define|#
directive|define
name|LCDPCFG
value|0x02c0
end_define

begin_define
define|#
directive|define
name|LCDDUALCTRL
value|0x02c8
end_define

begin_define
define|#
directive|define
name|LCDENH_CFG
value|0x0400
end_define

begin_define
define|#
directive|define
name|LCDENH_CSCCFG
value|0x0404
end_define

begin_define
define|#
directive|define
name|LCDENH_LUMACFG
value|0x0408
end_define

begin_define
define|#
directive|define
name|LCDENH_CHROCFG0
value|0x040c
end_define

begin_define
define|#
directive|define
name|LCDENH_CHROCFG1
value|0x0410
end_define

begin_define
define|#
directive|define
name|LCDENH_DITHERCFG
value|0x0414
end_define

begin_define
define|#
directive|define
name|LCDENH_STATUS
value|0x0418
end_define

begin_define
define|#
directive|define
name|LCDENH_GAMMA
value|0x0800
end_define

begin_comment
comment|/* base */
end_comment

begin_define
define|#
directive|define
name|LCDENH_VEE
value|0x1000
end_define

begin_comment
comment|/* base */
end_comment

begin_struct
struct|struct
name|lcd_frame_descriptor
block|{
name|uint32_t
name|next
decl_stmt|;
name|uint32_t
name|physaddr
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|offs
decl_stmt|;
name|uint32_t
name|pw
decl_stmt|;
name|uint32_t
name|cnum_pos
decl_stmt|;
name|uint32_t
name|dessize
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__JZ4780_LCD_H__ */
end_comment

end_unit

