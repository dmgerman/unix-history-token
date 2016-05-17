begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    Broadcom B43 wireless driver   IEEE 802.11n PHY data tables    Copyright (c) 2008 Michael Buesch<m@bues.ch>   Copyright (c) 2010 RafaÅ MiÅecki<zajec5@gmail.com>    This program is free software; you can redistribute it and/or modify   it under the terms of the GNU General Public License as published by   the Free Software Foundation; either version 2 of the License, or   (at your option) any later version.    This program is distributed in the hope that it will be useful,   but WITHOUT ANY WARRANTY; without even the implied warranty of   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the   GNU General Public License for more details.    You should have received a copy of the GNU General Public License   along with this program; see the file COPYING.  If not, write to   the Free Software Foundation, Inc., 51 Franklin Steet, Fifth Floor,   Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_BWN_PHY_N_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_BWN_PHY_N_REGS_H__
end_define

begin_comment
comment|/* N-PHY registers. */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BBCFG
value|BWN_PHY_N(0x001)
end_define

begin_comment
comment|/* BB config */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BBCFG_RSTCCA
value|0x4000
end_define

begin_comment
comment|/* Reset CCA */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BBCFG_RSTRX
value|0x8000
end_define

begin_comment
comment|/* Reset RX */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CHANNEL
value|BWN_PHY_N(0x005)
end_define

begin_comment
comment|/* Channel */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXERR
value|BWN_PHY_N(0x007)
end_define

begin_comment
comment|/* TX error */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BANDCTL
value|BWN_PHY_N(0x009)
end_define

begin_comment
comment|/* Band control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BANDCTL_5GHZ
value|0x0001
end_define

begin_comment
comment|/* Use the 5GHz band */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_4WI_ADDR
value|BWN_PHY_N(0x00B)
end_define

begin_comment
comment|/* Four-wire bus address */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_4WI_DATAHI
value|BWN_PHY_N(0x00C)
end_define

begin_comment
comment|/* Four-wire bus data high */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_4WI_DATALO
value|BWN_PHY_N(0x00D)
end_define

begin_comment
comment|/* Four-wire bus data low */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BIST_STAT0
value|BWN_PHY_N(0x00E)
end_define

begin_comment
comment|/* Built-in self test status 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BIST_STAT1
value|BWN_PHY_N(0x00F)
end_define

begin_comment
comment|/* Built-in self test status 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_DESPWR
value|BWN_PHY_N(0x018)
end_define

begin_comment
comment|/* Core 1 desired power */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_DESPWR
value|BWN_PHY_N(0x019)
end_define

begin_comment
comment|/* Core 1 CCK desired power */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_BCLIPBKOFF
value|BWN_PHY_N(0x01A)
end_define

begin_comment
comment|/* Core 1 barely clip backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_BCLIPBKOFF
value|BWN_PHY_N(0x01B)
end_define

begin_comment
comment|/* Core 1 CCK barely clip backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CGAINI
value|BWN_PHY_N(0x01C)
end_define

begin_comment
comment|/* Core 1 compute gain info */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CGAINI_GAINBKOFF
value|0x001F
end_define

begin_comment
comment|/* Gain backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CGAINI_GAINBKOFF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CGAINI_CLIPGBKOFF
value|0x03E0
end_define

begin_comment
comment|/* Clip gain backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CGAINI_CLIPGBKOFF_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CGAINI_GAINSTEP
value|0x1C00
end_define

begin_comment
comment|/* Gain step */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CGAINI_GAINSTEP_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CGAINI_CL2DETECT
value|0x2000
end_define

begin_comment
comment|/* Clip 2 detect mask */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_CGAINI
value|BWN_PHY_N(0x01D)
end_define

begin_comment
comment|/* Core 1 CCK compute gain info */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_CGAINI_GAINBKOFF
value|0x001F
end_define

begin_comment
comment|/* Gain backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_CGAINI_CLIPGBKOFF
value|0x01E0
end_define

begin_comment
comment|/* CCK barely clip gain backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_MINMAX_GAIN
value|BWN_PHY_N(0x01E)
end_define

begin_comment
comment|/* Core 1 min/max gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_MINGAIN
value|0x00FF
end_define

begin_comment
comment|/* Minimum gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_MINGAIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_MAXGAIN
value|0xFF00
end_define

begin_comment
comment|/* Maximum gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_MAXGAIN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_MINMAX_GAIN
value|BWN_PHY_N(0x01F)
end_define

begin_comment
comment|/* Core 1 CCK min/max gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_MINGAIN
value|0x00FF
end_define

begin_comment
comment|/* Minimum gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_MINGAIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_MAXGAIN
value|0xFF00
end_define

begin_comment
comment|/* Maximum gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CCK_MAXGAIN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN
value|BWN_PHY_N(0x020)
end_define

begin_comment
comment|/* Core 1 initial gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_EXTLNA
value|0x0001
end_define

begin_comment
comment|/* External LNA index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_LNA
value|0x0006
end_define

begin_comment
comment|/* LNA index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_LNAIDX_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_HPVGA1
value|0x0078
end_define

begin_comment
comment|/* HPVGA1 index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_HPVGA1_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_HPVGA2
value|0x0F80
end_define

begin_comment
comment|/* HPVGA2 index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_HPVGA2_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_TRRX
value|0x1000
end_define

begin_comment
comment|/* TR RX index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_INITGAIN_TRTX
value|0x2000
end_define

begin_comment
comment|/* TR TX index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_INITGAIN_A
value|BWN_PHY_N(0x020)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIP1_HIGAIN
value|BWN_PHY_N(0x021)
end_define

begin_comment
comment|/* Core 1 clip1 high gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_INITGAIN_B
value|BWN_PHY_N(0x021)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIP1_MEDGAIN
value|BWN_PHY_N(0x022)
end_define

begin_comment
comment|/* Core 1 clip1 medium gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_CLIP_HIGAIN_A
value|BWN_PHY_N(0x022)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIP1_LOGAIN
value|BWN_PHY_N(0x023)
end_define

begin_comment
comment|/* Core 1 clip1 low gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_CLIP_HIGAIN_B
value|BWN_PHY_N(0x023)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIP2_GAIN
value|BWN_PHY_N(0x024)
end_define

begin_comment
comment|/* Core 1 clip2 gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_CLIP_MEDGAIN_A
value|BWN_PHY_N(0x024)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_FILTERGAIN
value|BWN_PHY_N(0x025)
end_define

begin_comment
comment|/* Core 1 filter gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_LPF_QHPF_BW
value|BWN_PHY_N(0x026)
end_define

begin_comment
comment|/* Core 1 LPF Q HP F bandwidth */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIPWBTHRES
value|BWN_PHY_N(0x027)
end_define

begin_comment
comment|/* Core 1 clip wideband threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIPWBTHRES_CLIP2
value|0x003F
end_define

begin_comment
comment|/* Clip 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIPWBTHRES_CLIP2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIPWBTHRES_CLIP1
value|0x0FC0
end_define

begin_comment
comment|/* Clip 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIPWBTHRES_CLIP1_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_W1THRES
value|BWN_PHY_N(0x028)
end_define

begin_comment
comment|/* Core 1 W1 threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_EDTHRES
value|BWN_PHY_N(0x029)
end_define

begin_comment
comment|/* Core 1 ED threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_SMSIGTHRES
value|BWN_PHY_N(0x02A)
end_define

begin_comment
comment|/* Core 1 small sig threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_NBCLIPTHRES
value|BWN_PHY_N(0x02B)
end_define

begin_comment
comment|/* Core 1 NB clip threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIP1THRES
value|BWN_PHY_N(0x02C)
end_define

begin_comment
comment|/* Core 1 clip1 threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_CLIP2THRES
value|BWN_PHY_N(0x02D)
end_define

begin_comment
comment|/* Core 1 clip2 threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_DESPWR
value|BWN_PHY_N(0x02E)
end_define

begin_comment
comment|/* Core 2 desired power */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_DESPWR
value|BWN_PHY_N(0x02F)
end_define

begin_comment
comment|/* Core 2 CCK desired power */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_BCLIPBKOFF
value|BWN_PHY_N(0x030)
end_define

begin_comment
comment|/* Core 2 barely clip backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_BCLIPBKOFF
value|BWN_PHY_N(0x031)
end_define

begin_comment
comment|/* Core 2 CCK barely clip backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CGAINI
value|BWN_PHY_N(0x032)
end_define

begin_comment
comment|/* Core 2 compute gain info */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CGAINI_GAINBKOFF
value|0x001F
end_define

begin_comment
comment|/* Gain backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CGAINI_GAINBKOFF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CGAINI_CLIPGBKOFF
value|0x03E0
end_define

begin_comment
comment|/* Clip gain backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CGAINI_CLIPGBKOFF_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CGAINI_GAINSTEP
value|0x1C00
end_define

begin_comment
comment|/* Gain step */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CGAINI_GAINSTEP_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CGAINI_CL2DETECT
value|0x2000
end_define

begin_comment
comment|/* Clip 2 detect mask */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_CGAINI
value|BWN_PHY_N(0x033)
end_define

begin_comment
comment|/* Core 2 CCK compute gain info */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_CGAINI_GAINBKOFF
value|0x001F
end_define

begin_comment
comment|/* Gain backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_CGAINI_CLIPGBKOFF
value|0x01E0
end_define

begin_comment
comment|/* CCK barely clip gain backoff */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_MINMAX_GAIN
value|BWN_PHY_N(0x034)
end_define

begin_comment
comment|/* Core 2 min/max gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_MINGAIN
value|0x00FF
end_define

begin_comment
comment|/* Minimum gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_MINGAIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_MAXGAIN
value|0xFF00
end_define

begin_comment
comment|/* Maximum gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_MAXGAIN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_MINMAX_GAIN
value|BWN_PHY_N(0x035)
end_define

begin_comment
comment|/* Core 2 CCK min/max gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_MINGAIN
value|0x00FF
end_define

begin_comment
comment|/* Minimum gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_MINGAIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_MAXGAIN
value|0xFF00
end_define

begin_comment
comment|/* Maximum gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CCK_MAXGAIN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN
value|BWN_PHY_N(0x036)
end_define

begin_comment
comment|/* Core 2 initial gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_EXTLNA
value|0x0001
end_define

begin_comment
comment|/* External LNA index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_LNA
value|0x0006
end_define

begin_comment
comment|/* LNA index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_LNAIDX_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_HPVGA1
value|0x0078
end_define

begin_comment
comment|/* HPVGA1 index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_HPVGA1_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_HPVGA2
value|0x0F80
end_define

begin_comment
comment|/* HPVGA2 index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_HPVGA2_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_TRRX
value|0x1000
end_define

begin_comment
comment|/* TR RX index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_INITGAIN_TRTX
value|0x2000
end_define

begin_comment
comment|/* TR TX index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_CLIP_MEDGAIN_B
value|BWN_PHY_N(0x036)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIP1_HIGAIN
value|BWN_PHY_N(0x037)
end_define

begin_comment
comment|/* Core 2 clip1 high gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_CLIP_LOGAIN_A
value|BWN_PHY_N(0x037)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIP1_MEDGAIN
value|BWN_PHY_N(0x038)
end_define

begin_comment
comment|/* Core 2 clip1 medium gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_CLIP_LOGAIN_B
value|BWN_PHY_N(0x038)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIP1_LOGAIN
value|BWN_PHY_N(0x039)
end_define

begin_comment
comment|/* Core 2 clip1 low gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_CLIP2_GAIN_A
value|BWN_PHY_N(0x039)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIP2_GAIN
value|BWN_PHY_N(0x03A)
end_define

begin_comment
comment|/* Core 2 clip2 gain code */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C1_CLIP2_GAIN_B
value|BWN_PHY_N(0x03A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_FILTERGAIN
value|BWN_PHY_N(0x03B)
end_define

begin_comment
comment|/* Core 2 filter gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_LPF_QHPF_BW
value|BWN_PHY_N(0x03C)
end_define

begin_comment
comment|/* Core 2 LPF Q HP F bandwidth */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIPWBTHRES
value|BWN_PHY_N(0x03D)
end_define

begin_comment
comment|/* Core 2 clip wideband threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIPWBTHRES_CLIP2
value|0x003F
end_define

begin_comment
comment|/* Clip 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIPWBTHRES_CLIP2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIPWBTHRES_CLIP1
value|0x0FC0
end_define

begin_comment
comment|/* Clip 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIPWBTHRES_CLIP1_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C2_W1THRES
value|BWN_PHY_N(0x03E)
end_define

begin_comment
comment|/* Core 2 W1 threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_EDTHRES
value|BWN_PHY_N(0x03F)
end_define

begin_comment
comment|/* Core 2 ED threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_SMSIGTHRES
value|BWN_PHY_N(0x040)
end_define

begin_comment
comment|/* Core 2 small sig threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_NBCLIPTHRES
value|BWN_PHY_N(0x041)
end_define

begin_comment
comment|/* Core 2 NB clip threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIP1THRES
value|BWN_PHY_N(0x042)
end_define

begin_comment
comment|/* Core 2 clip1 threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_CLIP2THRES
value|BWN_PHY_N(0x043)
end_define

begin_comment
comment|/* Core 2 clip2 threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRS_THRES1
value|BWN_PHY_N(0x044)
end_define

begin_comment
comment|/* CRS threshold 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRS_THRES2
value|BWN_PHY_N(0x045)
end_define

begin_comment
comment|/* CRS threshold 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRS_THRES3
value|BWN_PHY_N(0x046)
end_define

begin_comment
comment|/* CRS threshold 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSCTL
value|BWN_PHY_N(0x047)
end_define

begin_comment
comment|/* CRS control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_DCFADDR
value|BWN_PHY_N(0x048)
end_define

begin_comment
comment|/* DC filter address */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_NUM0
value|BWN_PHY_N(0x049)
end_define

begin_comment
comment|/* RX filter 20 numerator 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_NUM1
value|BWN_PHY_N(0x04A)
end_define

begin_comment
comment|/* RX filter 20 numerator 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_NUM2
value|BWN_PHY_N(0x04B)
end_define

begin_comment
comment|/* RX filter 20 numerator 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_DENOM0
value|BWN_PHY_N(0x04C)
end_define

begin_comment
comment|/* RX filter 20 denominator 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_DENOM1
value|BWN_PHY_N(0x04D)
end_define

begin_comment
comment|/* RX filter 20 denominator 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_NUM10
value|BWN_PHY_N(0x04E)
end_define

begin_comment
comment|/* RX filter 20 numerator 10 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_NUM11
value|BWN_PHY_N(0x04F)
end_define

begin_comment
comment|/* RX filter 20 numerator 11 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_NUM12
value|BWN_PHY_N(0x050)
end_define

begin_comment
comment|/* RX filter 20 numerator 12 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_DENOM10
value|BWN_PHY_N(0x051)
end_define

begin_comment
comment|/* RX filter 20 denominator 10 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF20_DENOM11
value|BWN_PHY_N(0x052)
end_define

begin_comment
comment|/* RX filter 20 denominator 11 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_NUM0
value|BWN_PHY_N(0x053)
end_define

begin_comment
comment|/* RX filter 40 numerator 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_NUM1
value|BWN_PHY_N(0x054)
end_define

begin_comment
comment|/* RX filter 40 numerator 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_NUM2
value|BWN_PHY_N(0x055)
end_define

begin_comment
comment|/* RX filter 40 numerator 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_DENOM0
value|BWN_PHY_N(0x056)
end_define

begin_comment
comment|/* RX filter 40 denominator 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_DENOM1
value|BWN_PHY_N(0x057)
end_define

begin_comment
comment|/* RX filter 40 denominator 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_NUM10
value|BWN_PHY_N(0x058)
end_define

begin_comment
comment|/* RX filter 40 numerator 10 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_NUM11
value|BWN_PHY_N(0x059)
end_define

begin_comment
comment|/* RX filter 40 numerator 11 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_NUM12
value|BWN_PHY_N(0x05A)
end_define

begin_comment
comment|/* RX filter 40 numerator 12 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_DENOM10
value|BWN_PHY_N(0x05B)
end_define

begin_comment
comment|/* RX filter 40 denominator 10 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXF40_DENOM11
value|BWN_PHY_N(0x05C)
end_define

begin_comment
comment|/* RX filter 40 denominator 11 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PPROC_RSTLEN
value|BWN_PHY_N(0x060)
end_define

begin_comment
comment|/* Packet processing reset length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_INITCARR_DLEN
value|BWN_PHY_N(0x061)
end_define

begin_comment
comment|/* Initial carrier detection length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLIP1CARR_DLEN
value|BWN_PHY_N(0x062)
end_define

begin_comment
comment|/* Clip1 carrier detection length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLIP2CARR_DLEN
value|BWN_PHY_N(0x063)
end_define

begin_comment
comment|/* Clip2 carrier detection length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_INITGAIN_SLEN
value|BWN_PHY_N(0x064)
end_define

begin_comment
comment|/* Initial gain settle length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLIP1GAIN_SLEN
value|BWN_PHY_N(0x065)
end_define

begin_comment
comment|/* Clip1 gain settle length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLIP2GAIN_SLEN
value|BWN_PHY_N(0x066)
end_define

begin_comment
comment|/* Clip2 gain settle length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PACKGAIN_SLEN
value|BWN_PHY_N(0x067)
end_define

begin_comment
comment|/* Packet gain settle length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CARRSRC_TLEN
value|BWN_PHY_N(0x068)
end_define

begin_comment
comment|/* Carrier search timeout length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TISRC_TLEN
value|BWN_PHY_N(0x069)
end_define

begin_comment
comment|/* Timing search timeout length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ENDROP_TLEN
value|BWN_PHY_N(0x06A)
end_define

begin_comment
comment|/* Energy drop timeout length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLIP1_NBDWELL_LEN
value|BWN_PHY_N(0x06B)
end_define

begin_comment
comment|/* Clip1 NB dwell length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLIP2_NBDWELL_LEN
value|BWN_PHY_N(0x06C)
end_define

begin_comment
comment|/* Clip2 NB dwell length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_W1CLIP1_DWELL_LEN
value|BWN_PHY_N(0x06D)
end_define

begin_comment
comment|/* W1 clip1 dwell length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_W1CLIP2_DWELL_LEN
value|BWN_PHY_N(0x06E)
end_define

begin_comment
comment|/* W1 clip2 dwell length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_W2CLIP1_DWELL_LEN
value|BWN_PHY_N(0x06F)
end_define

begin_comment
comment|/* W2 clip1 dwell length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PLOAD_CSENSE_EXTLEN
value|BWN_PHY_N(0x070)
end_define

begin_comment
comment|/* Payload carrier sense extension length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EDROP_CSENSE_EXTLEN
value|BWN_PHY_N(0x071)
end_define

begin_comment
comment|/* Energy drop carrier sense extension length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TABLE_ADDR
value|BWN_PHY_N(0x072)
end_define

begin_comment
comment|/* Table address */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TABLE_DATALO
value|BWN_PHY_N(0x073)
end_define

begin_comment
comment|/* Table data low */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TABLE_DATAHI
value|BWN_PHY_N(0x074)
end_define

begin_comment
comment|/* Table data high */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_WWISE_LENIDX
value|BWN_PHY_N(0x075)
end_define

begin_comment
comment|/* WWiSE length index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_LENIDX
value|BWN_PHY_N(0x076)
end_define

begin_comment
comment|/* TGNsync length index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXMACIF_HOLDOFF
value|BWN_PHY_N(0x077)
end_define

begin_comment
comment|/* TX MAC IF Hold off */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD
value|BWN_PHY_N(0x078)
end_define

begin_comment
comment|/* RF control (command) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_START
value|0x0001
end_define

begin_comment
comment|/* Start sequence */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_RXTX
value|0x0002
end_define

begin_comment
comment|/* RX/TX */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_CORESEL
value|0x0038
end_define

begin_comment
comment|/* Core select */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_CORESEL_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_PORFORCE
value|0x0040
end_define

begin_comment
comment|/* POR force */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_OEPORFORCE
value|0x0080
end_define

begin_comment
comment|/* OE POR force */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_RXEN
value|0x0100
end_define

begin_comment
comment|/* RX enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_TXEN
value|0x0200
end_define

begin_comment
comment|/* TX enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_CHIP0PU
value|0x0400
end_define

begin_comment
comment|/* Chip0 PU */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_EN
value|0x0800
end_define

begin_comment
comment|/* Radio enabled */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_SEQENCORE
value|0xF000
end_define

begin_comment
comment|/* Seq en core */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CMD_SEQENCORE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO1
value|BWN_PHY_N(0x07A)
end_define

begin_comment
comment|/* RF control (RSSI others 1) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO1_RXPD
value|0x0001
end_define

begin_comment
comment|/* RX PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO1_TXPD
value|0x0002
end_define

begin_comment
comment|/* TX PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO1_PAPD
value|0x0004
end_define

begin_comment
comment|/* PA PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO1_RSSICTL
value|0x0030
end_define

begin_comment
comment|/* RSSI control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO1_LPFBW
value|0x00C0
end_define

begin_comment
comment|/* LPF bandwidth */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO1_HPFBWHI
value|0x0100
end_define

begin_comment
comment|/* HPF bandwidth high */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO1_HIQDISCO
value|0x0200
end_define

begin_comment
comment|/* HIQ dis core */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RXG1
value|BWN_PHY_N(0x07B)
end_define

begin_comment
comment|/* RF control (RX gain 1) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_TXG1
value|BWN_PHY_N(0x07C)
end_define

begin_comment
comment|/* RF control (TX gain 1) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO2
value|BWN_PHY_N(0x07D)
end_define

begin_comment
comment|/* RF control (RSSI others 2) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO2_RXPD
value|0x0001
end_define

begin_comment
comment|/* RX PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO2_TXPD
value|0x0002
end_define

begin_comment
comment|/* TX PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO2_PAPD
value|0x0004
end_define

begin_comment
comment|/* PA PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO2_RSSICTL
value|0x0030
end_define

begin_comment
comment|/* RSSI control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO2_LPFBW
value|0x00C0
end_define

begin_comment
comment|/* LPF bandwidth */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO2_HPFBWHI
value|0x0100
end_define

begin_comment
comment|/* HPF bandwidth high */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO2_HIQDISCO
value|0x0200
end_define

begin_comment
comment|/* HIQ dis core */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RXG2
value|BWN_PHY_N(0x07E)
end_define

begin_comment
comment|/* RF control (RX gain 2) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_TXG2
value|BWN_PHY_N(0x07F)
end_define

begin_comment
comment|/* RF control (TX gain 2) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO3
value|BWN_PHY_N(0x080)
end_define

begin_comment
comment|/* RF control (RSSI others 3) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO3_RXPD
value|0x0001
end_define

begin_comment
comment|/* RX PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO3_TXPD
value|0x0002
end_define

begin_comment
comment|/* TX PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO3_PAPD
value|0x0004
end_define

begin_comment
comment|/* PA PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO3_RSSICTL
value|0x0030
end_define

begin_comment
comment|/* RSSI control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO3_LPFBW
value|0x00C0
end_define

begin_comment
comment|/* LPF bandwidth */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO3_HPFBWHI
value|0x0100
end_define

begin_comment
comment|/* HPF bandwidth high */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO3_HIQDISCO
value|0x0200
end_define

begin_comment
comment|/* HIQ dis core */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RXG3
value|BWN_PHY_N(0x081)
end_define

begin_comment
comment|/* RF control (RX gain 3) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_TXG3
value|BWN_PHY_N(0x082)
end_define

begin_comment
comment|/* RF control (TX gain 3) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO4
value|BWN_PHY_N(0x083)
end_define

begin_comment
comment|/* RF control (RSSI others 4) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO4_RXPD
value|0x0001
end_define

begin_comment
comment|/* RX PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO4_TXPD
value|0x0002
end_define

begin_comment
comment|/* TX PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO4_PAPD
value|0x0004
end_define

begin_comment
comment|/* PA PD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO4_RSSICTL
value|0x0030
end_define

begin_comment
comment|/* RSSI control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO4_LPFBW
value|0x00C0
end_define

begin_comment
comment|/* LPF bandwidth */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO4_HPFBWHI
value|0x0100
end_define

begin_comment
comment|/* HPF bandwidth high */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RSSIO4_HIQDISCO
value|0x0200
end_define

begin_comment
comment|/* HIQ dis core */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_RXG4
value|BWN_PHY_N(0x084)
end_define

begin_comment
comment|/* RF control (RX gain 4) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_TXG4
value|BWN_PHY_N(0x085)
end_define

begin_comment
comment|/* RF control (TX gain 4) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_TXIQ_COMP_OFF
value|BWN_PHY_N(0x087)
end_define

begin_comment
comment|/* Core 1 TX I/Q comp offset */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_TXIQ_COMP_OFF
value|BWN_PHY_N(0x088)
end_define

begin_comment
comment|/* Core 2 TX I/Q comp offset */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_TXCTL
value|BWN_PHY_N(0x08B)
end_define

begin_comment
comment|/* Core 1 TX control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_TXCTL
value|BWN_PHY_N(0x08C)
end_define

begin_comment
comment|/* Core 2 TX control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_OVER1
value|BWN_PHY_N(0x08F)
end_define

begin_comment
comment|/* AFE control override 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SCRAM_SIGCTL
value|BWN_PHY_N(0x090)
end_define

begin_comment
comment|/* Scram signal control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SCRAM_SIGCTL_INITST
value|0x007F
end_define

begin_comment
comment|/* Initial state value */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SCRAM_SIGCTL_INITST_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_SCRAM_SIGCTL_SCM
value|0x0080
end_define

begin_comment
comment|/* Scram control mode */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SCRAM_SIGCTL_SICE
value|0x0100
end_define

begin_comment
comment|/* Scram index control enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SCRAM_SIGCTL_START
value|0xFE00
end_define

begin_comment
comment|/* Scram start bit */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SCRAM_SIGCTL_START_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_INTC1
value|BWN_PHY_N(0x091)
end_define

begin_comment
comment|/* RF control (intc 1) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_INTC2
value|BWN_PHY_N(0x092)
end_define

begin_comment
comment|/* RF control (intc 2) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_INTC3
value|BWN_PHY_N(0x093)
end_define

begin_comment
comment|/* RF control (intc 3) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_INTC4
value|BWN_PHY_N(0x094)
end_define

begin_comment
comment|/* RF control (intc 4) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_NRDTO_WWISE
value|BWN_PHY_N(0x095)
end_define

begin_comment
comment|/* # datatones WWiSE */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_NRDTO_TGNSYNC
value|BWN_PHY_N(0x096)
end_define

begin_comment
comment|/* # datatones TGNsync */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SIGFMOD_WWISE
value|BWN_PHY_N(0x097)
end_define

begin_comment
comment|/* Signal field mod WWiSE */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_LEG_SIGFMOD_11N
value|BWN_PHY_N(0x098)
end_define

begin_comment
comment|/* Legacy signal field mod 11n */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_HT_SIGFMOD_11N
value|BWN_PHY_N(0x099)
end_define

begin_comment
comment|/* HT signal field mod 11n */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_RXIQ_COMPA0
value|BWN_PHY_N(0x09A)
end_define

begin_comment
comment|/* Core 1 RX I/Q comp A0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_RXIQ_COMPB0
value|BWN_PHY_N(0x09B)
end_define

begin_comment
comment|/* Core 1 RX I/Q comp B0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_RXIQ_COMPA1
value|BWN_PHY_N(0x09C)
end_define

begin_comment
comment|/* Core 2 RX I/Q comp A1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_RXIQ_COMPB1
value|BWN_PHY_N(0x09D)
end_define

begin_comment
comment|/* Core 2 RX I/Q comp B1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXCTL
value|BWN_PHY_N(0x0A0)
end_define

begin_comment
comment|/* RX control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXCTL_BSELU20
value|0x0010
end_define

begin_comment
comment|/* Band select upper 20 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXCTL_RIFSEN
value|0x0080
end_define

begin_comment
comment|/* RIFS enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQMODE
value|BWN_PHY_N(0x0A1)
end_define

begin_comment
comment|/* RF seq mode */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQMODE_CAOVER
value|0x0001
end_define

begin_comment
comment|/* Core active override */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQMODE_TROVER
value|0x0002
end_define

begin_comment
comment|/* Trigger override */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA
value|BWN_PHY_N(0x0A2)
end_define

begin_comment
comment|/* RF seq core active */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA_TXEN
value|0x000F
end_define

begin_comment
comment|/* TX enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA_TXEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA_RXEN
value|0x00F0
end_define

begin_comment
comment|/* RX enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA_RXEN_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA_TXDIS
value|0x0F00
end_define

begin_comment
comment|/* TX disable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA_TXDIS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA_RXDIS
value|0xF000
end_define

begin_comment
comment|/* RX disable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQCA_RXDIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQTR
value|BWN_PHY_N(0x0A3)
end_define

begin_comment
comment|/* RF seq trigger */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQTR_RX2TX
value|0x0001
end_define

begin_comment
comment|/* RX2TX */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQTR_TX2RX
value|0x0002
end_define

begin_comment
comment|/* TX2RX */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQTR_UPGH
value|0x0004
end_define

begin_comment
comment|/* Update gain H */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQTR_UPGL
value|0x0008
end_define

begin_comment
comment|/* Update gain L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQTR_UPGU
value|0x0010
end_define

begin_comment
comment|/* Update gain U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQTR_RST2RX
value|0x0020
end_define

begin_comment
comment|/* Reset to RX */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQST
value|BWN_PHY_N(0x0A4)
end_define

begin_comment
comment|/* RF seq status. Values same as trigger. */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_OVER
value|BWN_PHY_N(0x0A5)
end_define

begin_comment
comment|/* AFE control override */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_C1
value|BWN_PHY_N(0x0A6)
end_define

begin_comment
comment|/* AFE control core 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_C2
value|BWN_PHY_N(0x0A7)
end_define

begin_comment
comment|/* AFE control core 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_C3
value|BWN_PHY_N(0x0A8)
end_define

begin_comment
comment|/* AFE control core 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_C4
value|BWN_PHY_N(0x0A9)
end_define

begin_comment
comment|/* AFE control core 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_DACGAIN1
value|BWN_PHY_N(0x0AA)
end_define

begin_comment
comment|/* AFE control DAC gain 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_DACGAIN2
value|BWN_PHY_N(0x0AB)
end_define

begin_comment
comment|/* AFE control DAC gain 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_DACGAIN3
value|BWN_PHY_N(0x0AC)
end_define

begin_comment
comment|/* AFE control DAC gain 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFECTL_DACGAIN4
value|BWN_PHY_N(0x0AD)
end_define

begin_comment
comment|/* AFE control DAC gain 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_STR_ADDR1
value|BWN_PHY_N(0x0AE)
end_define

begin_comment
comment|/* STR address 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_STR_ADDR2
value|BWN_PHY_N(0x0AF)
end_define

begin_comment
comment|/* STR address 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLASSCTL
value|BWN_PHY_N(0x0B0)
end_define

begin_comment
comment|/* Classifier control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLASSCTL_CCKEN
value|0x0001
end_define

begin_comment
comment|/* CCK enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLASSCTL_OFDMEN
value|0x0002
end_define

begin_comment
comment|/* OFDM enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CLASSCTL_WAITEDEN
value|0x0004
end_define

begin_comment
comment|/* Waited enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQFLIP
value|BWN_PHY_N(0x0B1)
end_define

begin_comment
comment|/* I/Q flip */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQFLIP_ADC1
value|0x0001
end_define

begin_comment
comment|/* ADC1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQFLIP_ADC2
value|0x0010
end_define

begin_comment
comment|/* ADC2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SISO_SNR_THRES
value|BWN_PHY_N(0x0B2)
end_define

begin_comment
comment|/* SISO SNR threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SIGMA_N_MULT
value|BWN_PHY_N(0x0B3)
end_define

begin_comment
comment|/* Sigma N multiplier */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXMACDELAY
value|BWN_PHY_N(0x0B4)
end_define

begin_comment
comment|/* TX MAC delay */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXFRAMEDELAY
value|BWN_PHY_N(0x0B5)
end_define

begin_comment
comment|/* TX frame delay */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_MLPARM
value|BWN_PHY_N(0x0B6)
end_define

begin_comment
comment|/* ML parameters */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_MLCTL
value|BWN_PHY_N(0x0B7)
end_define

begin_comment
comment|/* ML control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_WWISE_20NCYCDAT
value|BWN_PHY_N(0x0B8)
end_define

begin_comment
comment|/* WWiSE 20 N cyc data */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_WWISE_40NCYCDAT
value|BWN_PHY_N(0x0B9)
end_define

begin_comment
comment|/* WWiSE 40 N cyc data */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_20NCYCDAT
value|BWN_PHY_N(0x0BA)
end_define

begin_comment
comment|/* TGNsync 20 N cyc data */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_40NCYCDAT
value|BWN_PHY_N(0x0BB)
end_define

begin_comment
comment|/* TGNsync 40 N cyc data */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_INITSWIZP
value|BWN_PHY_N(0x0BC)
end_define

begin_comment
comment|/* Initial swizzle pattern */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXTAILCNT
value|BWN_PHY_N(0x0BD)
end_define

begin_comment
comment|/* TX tail count value */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL1
value|BWN_PHY_N(0x0BE)
end_define

begin_comment
comment|/* B PHY control 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL2
value|BWN_PHY_N(0x0BF)
end_define

begin_comment
comment|/* B PHY control 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL2_LUT
value|0x001F
end_define

begin_comment
comment|/* LUT index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL2_LUT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL2_MACDEL
value|0x7FE0
end_define

begin_comment
comment|/* MAC delay */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL2_MACDEL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_IQLOCAL_CMD
value|BWN_PHY_N(0x0C0)
end_define

begin_comment
comment|/* I/Q LO cal command */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQLOCAL_CMD_EN
value|0x8000
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_IQLOCAL_CMDNNUM
value|BWN_PHY_N(0x0C1)
end_define

begin_comment
comment|/* I/Q LO cal command N num */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQLOCAL_CMDGCTL
value|BWN_PHY_N(0x0C2)
end_define

begin_comment
comment|/* I/Q LO cal command G control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SAMP_CMD
value|BWN_PHY_N(0x0C3)
end_define

begin_comment
comment|/* Sample command */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SAMP_CMD_STOP
value|0x0002
end_define

begin_comment
comment|/* Stop */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SAMP_LOOPCNT
value|BWN_PHY_N(0x0C4)
end_define

begin_comment
comment|/* Sample loop count */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SAMP_WAITCNT
value|BWN_PHY_N(0x0C5)
end_define

begin_comment
comment|/* Sample wait count */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SAMP_DEPCNT
value|BWN_PHY_N(0x0C6)
end_define

begin_comment
comment|/* Sample depth count */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SAMP_STAT
value|BWN_PHY_N(0x0C7)
end_define

begin_comment
comment|/* Sample status */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_GPIO_LOOEN
value|BWN_PHY_N(0x0C8)
end_define

begin_comment
comment|/* GPIO low out enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_GPIO_HIOEN
value|BWN_PHY_N(0x0C9)
end_define

begin_comment
comment|/* GPIO high out enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_GPIO_SEL
value|BWN_PHY_N(0x0CA)
end_define

begin_comment
comment|/* GPIO select */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_GPIO_CLKCTL
value|BWN_PHY_N(0x0CB)
end_define

begin_comment
comment|/* GPIO clock control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_AS0
value|BWN_PHY_N(0x0CC)
end_define

begin_comment
comment|/* TX filter 20 coeff A stage 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_AS1
value|BWN_PHY_N(0x0CD)
end_define

begin_comment
comment|/* TX filter 20 coeff A stage 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_AS2
value|BWN_PHY_N(0x0CE)
end_define

begin_comment
comment|/* TX filter 20 coeff A stage 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_B32S0
value|BWN_PHY_N(0x0CF)
end_define

begin_comment
comment|/* TX filter 20 coeff B32 stage 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_B1S0
value|BWN_PHY_N(0x0D0)
end_define

begin_comment
comment|/* TX filter 20 coeff B1 stage 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_B32S1
value|BWN_PHY_N(0x0D1)
end_define

begin_comment
comment|/* TX filter 20 coeff B32 stage 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_B1S1
value|BWN_PHY_N(0x0D2)
end_define

begin_comment
comment|/* TX filter 20 coeff B1 stage 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_B32S2
value|BWN_PHY_N(0x0D3)
end_define

begin_comment
comment|/* TX filter 20 coeff B32 stage 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_B1S2
value|BWN_PHY_N(0x0D4)
end_define

begin_comment
comment|/* TX filter 20 coeff B1 stage 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SIGFLDTOL
value|BWN_PHY_N(0x0D5)
end_define

begin_comment
comment|/* Signal fld tolerance */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXSERFLD
value|BWN_PHY_N(0x0D6)
end_define

begin_comment
comment|/* TX service field */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQ_RX2TX_PUD
value|BWN_PHY_N(0x0D7)
end_define

begin_comment
comment|/* AFE seq RX2TX power up/down delay */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQ_TX2RX_PUD
value|BWN_PHY_N(0x0D8)
end_define

begin_comment
comment|/* AFE seq TX2RX power up/down delay */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_SCRAMI0
value|BWN_PHY_N(0x0D9)
end_define

begin_comment
comment|/* TGNsync scram init 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_SCRAMI1
value|BWN_PHY_N(0x0DA)
end_define

begin_comment
comment|/* TGNsync scram init 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_INITSWIZPATTLEG
value|BWN_PHY_N(0x0DB)
end_define

begin_comment
comment|/* Initial swizzle pattern leg */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL3
value|BWN_PHY_N(0x0DC)
end_define

begin_comment
comment|/* B PHY control 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL3_SCALE
value|0x00FF
end_define

begin_comment
comment|/* Scale */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL3_SCALE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL3_FSC
value|0xFF00
end_define

begin_comment
comment|/* Frame start count value */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL3_FSC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL4
value|BWN_PHY_N(0x0DD)
end_define

begin_comment
comment|/* B PHY control 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_TXBBMULT
value|BWN_PHY_N(0x0DE)
end_define

begin_comment
comment|/* Core 1 TX BB multiplier */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_TXBBMULT
value|BWN_PHY_N(0x0DF)
end_define

begin_comment
comment|/* Core 2 TX BB multiplier */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_AS0
value|BWN_PHY_N(0x0E1)
end_define

begin_comment
comment|/* TX filter 40 coeff A stage 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_AS1
value|BWN_PHY_N(0x0E2)
end_define

begin_comment
comment|/* TX filter 40 coeff A stage 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_AS2
value|BWN_PHY_N(0x0E3)
end_define

begin_comment
comment|/* TX filter 40 coeff A stage 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_B32S0
value|BWN_PHY_N(0x0E4)
end_define

begin_comment
comment|/* TX filter 40 coeff B32 stage 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_B1S0
value|BWN_PHY_N(0x0E5)
end_define

begin_comment
comment|/* TX filter 40 coeff B1 stage 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_B32S1
value|BWN_PHY_N(0x0E6)
end_define

begin_comment
comment|/* TX filter 40 coeff B32 stage 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_B1S1
value|BWN_PHY_N(0x0E7)
end_define

begin_comment
comment|/* TX filter 40 coeff B1 stage 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_RFCTL_OVER0
value|BWN_PHY_N(0x0E7)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_B32S2
value|BWN_PHY_N(0x0E8)
end_define

begin_comment
comment|/* TX filter 40 coeff B32 stage 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_B1S2
value|BWN_PHY_N(0x0E9)
end_define

begin_comment
comment|/* TX filter 40 coeff B1 stage 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BIST_STAT2
value|BWN_PHY_N(0x0EA)
end_define

begin_comment
comment|/* BIST status 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BIST_STAT3
value|BWN_PHY_N(0x0EB)
end_define

begin_comment
comment|/* BIST status 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_OVER
value|BWN_PHY_N(0x0EC)
end_define

begin_comment
comment|/* RF control override */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_RFCTL_OVER1
value|BWN_PHY_N(0x0EC)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_MIMOCFG
value|BWN_PHY_N(0x0ED)
end_define

begin_comment
comment|/* MIMO config */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_MIMOCFG_GFMIX
value|0x0004
end_define

begin_comment
comment|/* Greenfield or mixed mode */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_MIMOCFG_AUTO
value|0x0100
end_define

begin_comment
comment|/* Greenfield/mixed mode auto */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_BLNKCTL
value|BWN_PHY_N(0x0EE)
end_define

begin_comment
comment|/* Radar blank control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_A0RADAR_FIFOCTL
value|BWN_PHY_N(0x0EF)
end_define

begin_comment
comment|/* Antenna 0 radar FIFO control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_A1RADAR_FIFOCTL
value|BWN_PHY_N(0x0F0)
end_define

begin_comment
comment|/* Antenna 1 radar FIFO control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_A0RADAR_FIFODAT
value|BWN_PHY_N(0x0F1)
end_define

begin_comment
comment|/* Antenna 0 radar FIFO data */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_A1RADAR_FIFODAT
value|BWN_PHY_N(0x0F2)
end_define

begin_comment
comment|/* Antenna 1 radar FIFO data */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_THRES0
value|BWN_PHY_N(0x0F3)
end_define

begin_comment
comment|/* Radar threshold 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_THRES1
value|BWN_PHY_N(0x0F4)
end_define

begin_comment
comment|/* Radar threshold 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_THRES0R
value|BWN_PHY_N(0x0F5)
end_define

begin_comment
comment|/* Radar threshold 0R */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_THRES1R
value|BWN_PHY_N(0x0F6)
end_define

begin_comment
comment|/* Radar threshold 1R */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CSEN_20IN40_DLEN
value|BWN_PHY_N(0x0F7)
end_define

begin_comment
comment|/* Carrier sense 20 in 40 dwell length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_TRSW_LO1
value|BWN_PHY_N(0x0F8)
end_define

begin_comment
comment|/* RF control LUT TRSW lower 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_TRSW_UP1
value|BWN_PHY_N(0x0F9)
end_define

begin_comment
comment|/* RF control LUT TRSW upper 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_TRSW_LO2
value|BWN_PHY_N(0x0FA)
end_define

begin_comment
comment|/* RF control LUT TRSW lower 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_TRSW_UP2
value|BWN_PHY_N(0x0FB)
end_define

begin_comment
comment|/* RF control LUT TRSW upper 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_TRSW_LO3
value|BWN_PHY_N(0x0FC)
end_define

begin_comment
comment|/* RF control LUT TRSW lower 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_TRSW_UP3
value|BWN_PHY_N(0x0FD)
end_define

begin_comment
comment|/* RF control LUT TRSW upper 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_TRSW_LO4
value|BWN_PHY_N(0x0FE)
end_define

begin_comment
comment|/* RF control LUT TRSW lower 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_TRSW_UP4
value|BWN_PHY_N(0x0FF)
end_define

begin_comment
comment|/* RF control LUT TRSW upper 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_LNAPA1
value|BWN_PHY_N(0x100)
end_define

begin_comment
comment|/* RF control LUT LNA PA 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_LNAPA2
value|BWN_PHY_N(0x101)
end_define

begin_comment
comment|/* RF control LUT LNA PA 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_LNAPA3
value|BWN_PHY_N(0x102)
end_define

begin_comment
comment|/* RF control LUT LNA PA 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_LUT_LNAPA4
value|BWN_PHY_N(0x103)
end_define

begin_comment
comment|/* RF control LUT LNA PA 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_CRCM0
value|BWN_PHY_N(0x104)
end_define

begin_comment
comment|/* TGNsync CRC mask 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_CRCM1
value|BWN_PHY_N(0x105)
end_define

begin_comment
comment|/* TGNsync CRC mask 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_CRCM2
value|BWN_PHY_N(0x106)
end_define

begin_comment
comment|/* TGNsync CRC mask 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_CRCM3
value|BWN_PHY_N(0x107)
end_define

begin_comment
comment|/* TGNsync CRC mask 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TGNSYNC_CRCM4
value|BWN_PHY_N(0x108)
end_define

begin_comment
comment|/* TGNsync CRC mask 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRCPOLY
value|BWN_PHY_N(0x109)
end_define

begin_comment
comment|/* CRC polynomial */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SIGCNT
value|BWN_PHY_N(0x10A)
end_define

begin_comment
comment|/* # sig count */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SIGSTARTBIT_CTL
value|BWN_PHY_N(0x10B)
end_define

begin_comment
comment|/* Sig start bit control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRCPOLY_ORDER
value|BWN_PHY_N(0x10C)
end_define

begin_comment
comment|/* CRC polynomial order */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CST0
value|BWN_PHY_N(0x10D)
end_define

begin_comment
comment|/* RF control core swap table 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CST1
value|BWN_PHY_N(0x10E)
end_define

begin_comment
comment|/* RF control core swap table 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_CST2O
value|BWN_PHY_N(0x10F)
end_define

begin_comment
comment|/* RF control core swap table 2 + others */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BPHY_CTL5
value|BWN_PHY_N(0x111)
end_define

begin_comment
comment|/* B PHY control 5 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFSEQ_LPFBW
value|BWN_PHY_N(0x112)
end_define

begin_comment
comment|/* RF seq LPF bandwidth */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIBIAS1
value|BWN_PHY_N(0x114)
end_define

begin_comment
comment|/* TSSI bias val 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIBIAS2
value|BWN_PHY_N(0x115)
end_define

begin_comment
comment|/* TSSI bias val 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIBIAS_BIAS
value|0x00FF
end_define

begin_comment
comment|/* Bias */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIBIAS_BIAS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIBIAS_VAL
value|0xFF00
end_define

begin_comment
comment|/* Value */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIBIAS_VAL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ESTPWR1
value|BWN_PHY_N(0x118)
end_define

begin_comment
comment|/* Estimated power 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ESTPWR2
value|BWN_PHY_N(0x119)
end_define

begin_comment
comment|/* Estimated power 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ESTPWR_PWR
value|0x00FF
end_define

begin_comment
comment|/* Estimated power */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ESTPWR_PWR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ESTPWR_VALID
value|0x0100
end_define

begin_comment
comment|/* Estimated power valid */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSI_MAXTXFDT
value|BWN_PHY_N(0x11C)
end_define

begin_comment
comment|/* TSSI max TX frame delay time */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSI_MAXTXFDT_VAL
value|0x00FF
end_define

begin_comment
comment|/* max TX frame delay time */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSI_MAXTXFDT_VAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TSSI_MAXTDT
value|BWN_PHY_N(0x11D)
end_define

begin_comment
comment|/* TSSI max TSSI delay time */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSI_MAXTDT_VAL
value|0x00FF
end_define

begin_comment
comment|/* max TSSI delay time */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSI_MAXTDT_VAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ITSSI1
value|BWN_PHY_N(0x11E)
end_define

begin_comment
comment|/* TSSI idle 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ITSSI2
value|BWN_PHY_N(0x11F)
end_define

begin_comment
comment|/* TSSI idle 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ITSSI_VAL
value|0x00FF
end_define

begin_comment
comment|/* Idle TSSI */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ITSSI_VAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIMODE
value|BWN_PHY_N(0x122)
end_define

begin_comment
comment|/* TSSI mode */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIMODE_EN
value|0x0001
end_define

begin_comment
comment|/* TSSI enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TSSIMODE_PDEN
value|0x0002
end_define

begin_comment
comment|/* Power det enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXMACIFM
value|BWN_PHY_N(0x123)
end_define

begin_comment
comment|/* RX Macif mode */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSIT_COCNT_LO
value|BWN_PHY_N(0x124)
end_define

begin_comment
comment|/* CRS idle time CRS-on count (low) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSIT_COCNT_HI
value|BWN_PHY_N(0x125)
end_define

begin_comment
comment|/* CRS idle time CRS-on count (high) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSIT_MTCNT_LO
value|BWN_PHY_N(0x126)
end_define

begin_comment
comment|/* CRS idle time measure time count (low) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSIT_MTCNT_HI
value|BWN_PHY_N(0x127)
end_define

begin_comment
comment|/* CRS idle time measure time count (high) */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SAMTWC
value|BWN_PHY_N(0x128)
end_define

begin_comment
comment|/* Sample tail wait count */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_CMD
value|BWN_PHY_N(0x129)
end_define

begin_comment
comment|/* I/Q estimate command */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_CMD_START
value|0x0001
end_define

begin_comment
comment|/* Start */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_CMD_MODE
value|0x0002
end_define

begin_comment
comment|/* Mode */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_WT
value|BWN_PHY_N(0x12A)
end_define

begin_comment
comment|/* I/Q estimate wait time */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_WT_VAL
value|0x00FF
end_define

begin_comment
comment|/* Wait time */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_WT_VAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_SAMCNT
value|BWN_PHY_N(0x12B)
end_define

begin_comment
comment|/* I/Q estimate sample count */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_IQACC_LO0
value|BWN_PHY_N(0x12C)
end_define

begin_comment
comment|/* I/Q estimate I/Q acc lo 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_IQACC_HI0
value|BWN_PHY_N(0x12D)
end_define

begin_comment
comment|/* I/Q estimate I/Q acc hi 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_IPACC_LO0
value|BWN_PHY_N(0x12E)
end_define

begin_comment
comment|/* I/Q estimate I power acc lo 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_IPACC_HI0
value|BWN_PHY_N(0x12F)
end_define

begin_comment
comment|/* I/Q estimate I power acc hi 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_QPACC_LO0
value|BWN_PHY_N(0x130)
end_define

begin_comment
comment|/* I/Q estimate Q power acc lo 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_QPACC_HI0
value|BWN_PHY_N(0x131)
end_define

begin_comment
comment|/* I/Q estimate Q power acc hi 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_IQACC_LO1
value|BWN_PHY_N(0x134)
end_define

begin_comment
comment|/* I/Q estimate I/Q acc lo 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_IQACC_HI1
value|BWN_PHY_N(0x135)
end_define

begin_comment
comment|/* I/Q estimate I/Q acc hi 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_IPACC_LO1
value|BWN_PHY_N(0x136)
end_define

begin_comment
comment|/* I/Q estimate I power acc lo 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_IPACC_HI1
value|BWN_PHY_N(0x137)
end_define

begin_comment
comment|/* I/Q estimate I power acc hi 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_QPACC_LO1
value|BWN_PHY_N(0x138)
end_define

begin_comment
comment|/* I/Q estimate Q power acc lo 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_IQEST_QPACC_HI1
value|BWN_PHY_N(0x139)
end_define

begin_comment
comment|/* I/Q estimate Q power acc hi 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_MIMO_CRSTXEXT
value|BWN_PHY_N(0x13A)
end_define

begin_comment
comment|/* MIMO PHY CRS TX extension */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PWRDET1
value|BWN_PHY_N(0x13B)
end_define

begin_comment
comment|/* Power det 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PWRDET2
value|BWN_PHY_N(0x13C)
end_define

begin_comment
comment|/* Power det 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_MAXRSSI_DTIME
value|BWN_PHY_N(0x13F)
end_define

begin_comment
comment|/* RSSI max RSSI delay time */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW0
value|BWN_PHY_N(0x141)
end_define

begin_comment
comment|/* Pilot data weight 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW1
value|BWN_PHY_N(0x142)
end_define

begin_comment
comment|/* Pilot data weight 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW2
value|BWN_PHY_N(0x143)
end_define

begin_comment
comment|/* Pilot data weight 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW_BPSK
value|0x000F
end_define

begin_comment
comment|/* BPSK */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW_BPSK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW_QPSK
value|0x00F0
end_define

begin_comment
comment|/* QPSK */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW_QPSK_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW_16QAM
value|0x0F00
end_define

begin_comment
comment|/* 16-QAM */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW_16QAM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW_64QAM
value|0xF000
end_define

begin_comment
comment|/* 64-QAM */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_DW_64QAM_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_FMDEM_CFG
value|BWN_PHY_N(0x144)
end_define

begin_comment
comment|/* FM demodulation config */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETR_A0
value|BWN_PHY_N(0x145)
end_define

begin_comment
comment|/* Phase track alpha 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETR_A1
value|BWN_PHY_N(0x146)
end_define

begin_comment
comment|/* Phase track alpha 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETR_A2
value|BWN_PHY_N(0x147)
end_define

begin_comment
comment|/* Phase track alpha 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETR_B0
value|BWN_PHY_N(0x148)
end_define

begin_comment
comment|/* Phase track beta 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETR_B1
value|BWN_PHY_N(0x149)
end_define

begin_comment
comment|/* Phase track beta 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETR_B2
value|BWN_PHY_N(0x14A)
end_define

begin_comment
comment|/* Phase track beta 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETR_CHG0
value|BWN_PHY_N(0x14B)
end_define

begin_comment
comment|/* Phase track change 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETR_CHG1
value|BWN_PHY_N(0x14C)
end_define

begin_comment
comment|/* Phase track change 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHASETW_OFF
value|BWN_PHY_N(0x14D)
end_define

begin_comment
comment|/* Phase track offset */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTL_DBG
value|BWN_PHY_N(0x14E)
end_define

begin_comment
comment|/* RF control debug */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CCK_SHIFTB_REF
value|BWN_PHY_N(0x150)
end_define

begin_comment
comment|/* CCK shiftbits reference var */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_OVER_DGAIN0
value|BWN_PHY_N(0x152)
end_define

begin_comment
comment|/* Override digital gain 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_OVER_DGAIN1
value|BWN_PHY_N(0x153)
end_define

begin_comment
comment|/* Override digital gain 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_OVER_DGAIN_FDGV
value|0x0007
end_define

begin_comment
comment|/* Force digital gain value */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_OVER_DGAIN_FDGV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_OVER_DGAIN_FDGEN
value|0x0008
end_define

begin_comment
comment|/* Force digital gain enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_OVER_DGAIN_CCKDGECV
value|0xFF00
end_define

begin_comment
comment|/* CCK digital gain enable count value */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_OVER_DGAIN_CCKDGECV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BIST_STAT4
value|BWN_PHY_N(0x156)
end_define

begin_comment
comment|/* BIST status 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_MAL
value|BWN_PHY_N(0x157)
end_define

begin_comment
comment|/* Radar MA length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_SRCCTL
value|BWN_PHY_N(0x158)
end_define

begin_comment
comment|/* Radar search control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_VLD_DTSIG
value|BWN_PHY_N(0x159)
end_define

begin_comment
comment|/* VLD data tones sig */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_VLD_DTDAT
value|BWN_PHY_N(0x15A)
end_define

begin_comment
comment|/* VLD data tones data */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_BPHY_RXIQCA0
value|BWN_PHY_N(0x15B)
end_define

begin_comment
comment|/* Core 1 B PHY RX I/Q comp A0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_BPHY_RXIQCB0
value|BWN_PHY_N(0x15C)
end_define

begin_comment
comment|/* Core 1 B PHY RX I/Q comp B0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_BPHY_RXIQCA1
value|BWN_PHY_N(0x15D)
end_define

begin_comment
comment|/* Core 2 B PHY RX I/Q comp A1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_BPHY_RXIQCB1
value|BWN_PHY_N(0x15E)
end_define

begin_comment
comment|/* Core 2 B PHY RX I/Q comp B1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN0
value|BWN_PHY_N(0x160)
end_define

begin_comment
comment|/* Frequency gain 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN1
value|BWN_PHY_N(0x161)
end_define

begin_comment
comment|/* Frequency gain 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN2
value|BWN_PHY_N(0x162)
end_define

begin_comment
comment|/* Frequency gain 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN3
value|BWN_PHY_N(0x163)
end_define

begin_comment
comment|/* Frequency gain 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN4
value|BWN_PHY_N(0x164)
end_define

begin_comment
comment|/* Frequency gain 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN5
value|BWN_PHY_N(0x165)
end_define

begin_comment
comment|/* Frequency gain 5 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN6
value|BWN_PHY_N(0x166)
end_define

begin_comment
comment|/* Frequency gain 6 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN7
value|BWN_PHY_N(0x167)
end_define

begin_comment
comment|/* Frequency gain 7 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FREQGAIN_BYPASS
value|BWN_PHY_N(0x168)
end_define

begin_comment
comment|/* Frequency gain bypass */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TRLOSS
value|BWN_PHY_N(0x169)
end_define

begin_comment
comment|/* TR loss value */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C1_ADCCLIP
value|BWN_PHY_N(0x16A)
end_define

begin_comment
comment|/* Core 1 ADC clip */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_ADCCLIP
value|BWN_PHY_N(0x16B)
end_define

begin_comment
comment|/* Core 2 ADC clip */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_LTRN_OFFGAIN
value|BWN_PHY_N(0x16F)
end_define

begin_comment
comment|/* LTRN offset gain */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_LTRN_OFF
value|BWN_PHY_N(0x170)
end_define

begin_comment
comment|/* LTRN offset */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_NRDATAT_WWISE20SIG
value|BWN_PHY_N(0x171)
end_define

begin_comment
comment|/* # data tones WWiSE 20 sig */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_NRDATAT_WWISE40SIG
value|BWN_PHY_N(0x172)
end_define

begin_comment
comment|/* # data tones WWiSE 40 sig */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_NRDATAT_TGNSYNC20SIG
value|BWN_PHY_N(0x173)
end_define

begin_comment
comment|/* # data tones TGNsync 20 sig */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_NRDATAT_TGNSYNC40SIG
value|BWN_PHY_N(0x174)
end_define

begin_comment
comment|/* # data tones TGNsync 40 sig */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_WWISE_CRCM0
value|BWN_PHY_N(0x175)
end_define

begin_comment
comment|/* WWiSE CRC mask 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_WWISE_CRCM1
value|BWN_PHY_N(0x176)
end_define

begin_comment
comment|/* WWiSE CRC mask 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_WWISE_CRCM2
value|BWN_PHY_N(0x177)
end_define

begin_comment
comment|/* WWiSE CRC mask 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_WWISE_CRCM3
value|BWN_PHY_N(0x178)
end_define

begin_comment
comment|/* WWiSE CRC mask 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_WWISE_CRCM4
value|BWN_PHY_N(0x179)
end_define

begin_comment
comment|/* WWiSE CRC mask 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CHANEST_CDDSH
value|BWN_PHY_N(0x17A)
end_define

begin_comment
comment|/* Channel estimate CDD shift */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_HTAGC_WCNT
value|BWN_PHY_N(0x17B)
end_define

begin_comment
comment|/* HT ADC wait counters */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SQPARM
value|BWN_PHY_N(0x17C)
end_define

begin_comment
comment|/* SQ params */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_MCSDUP6M
value|BWN_PHY_N(0x17D)
end_define

begin_comment
comment|/* MCS dup 6M */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_NDATAT_DUP40
value|BWN_PHY_N(0x17E)
end_define

begin_comment
comment|/* # data tones dup 40 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_DUP40_TGNSYNC_CYCD
value|BWN_PHY_N(0x17F)
end_define

begin_comment
comment|/* Dup40 TGNsync cycle data */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_DUP40_GFBL
value|BWN_PHY_N(0x180)
end_define

begin_comment
comment|/* Dup40 GF format BL address */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_DUP40_BL
value|BWN_PHY_N(0x181)
end_define

begin_comment
comment|/* Dup40 format BL address */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_LEGDUP_FTA
value|BWN_PHY_N(0x182)
end_define

begin_comment
comment|/* Legacy dup frm table address */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PACPROC_DBG
value|BWN_PHY_N(0x183)
end_define

begin_comment
comment|/* Packet processing debug */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_CYC1
value|BWN_PHY_N(0x184)
end_define

begin_comment
comment|/* Pilot cycle counter 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PIL_CYC2
value|BWN_PHY_N(0x185)
end_define

begin_comment
comment|/* Pilot cycle counter 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S0A1
value|BWN_PHY_N(0x186)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 0 A1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S0A2
value|BWN_PHY_N(0x187)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 0 A2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S1A1
value|BWN_PHY_N(0x188)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 1 A1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S1A2
value|BWN_PHY_N(0x189)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 1 A2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S2A1
value|BWN_PHY_N(0x18A)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 2 A1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S2A2
value|BWN_PHY_N(0x18B)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 2 A2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S0B1
value|BWN_PHY_N(0x18C)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 0 B1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S0B2
value|BWN_PHY_N(0x18D)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 0 B2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S0B3
value|BWN_PHY_N(0x18E)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 0 B3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S1B1
value|BWN_PHY_N(0x18F)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 1 B1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S1B2
value|BWN_PHY_N(0x190)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 1 B2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S1B3
value|BWN_PHY_N(0x191)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 1 B3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S2B1
value|BWN_PHY_N(0x192)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 2 B1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S2B2
value|BWN_PHY_N(0x193)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 2 B2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_20CO_S2B3
value|BWN_PHY_N(0x194)
end_define

begin_comment
comment|/* TX filter 20 coeff stage 2 B3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S0A1
value|BWN_PHY_N(0x195)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 0 A1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S0A2
value|BWN_PHY_N(0x196)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 0 A2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S1A1
value|BWN_PHY_N(0x197)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 1 A1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S1A2
value|BWN_PHY_N(0x198)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 1 A2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S2A1
value|BWN_PHY_N(0x199)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 2 A1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S2A2
value|BWN_PHY_N(0x19A)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 2 A2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S0B1
value|BWN_PHY_N(0x19B)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 0 B1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S0B2
value|BWN_PHY_N(0x19C)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 0 B2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S0B3
value|BWN_PHY_N(0x19D)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 0 B3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S1B1
value|BWN_PHY_N(0x19E)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 1 B1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S1B2
value|BWN_PHY_N(0x19F)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 1 B2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S1B3
value|BWN_PHY_N(0x1A0)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 1 B3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S2B1
value|BWN_PHY_N(0x1A1)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 2 B1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S2B2
value|BWN_PHY_N(0x1A2)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 2 B2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXF_40CO_S2B3
value|BWN_PHY_N(0x1A3)
end_define

begin_comment
comment|/* TX filter 40 coeff stage 2 B3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0I_RSSI_X
value|BWN_PHY_N(0x1A4)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 I RSSI X */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0I_RSSI_Y
value|BWN_PHY_N(0x1A5)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 I RSSI Y */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0I_RSSI_Z
value|BWN_PHY_N(0x1A6)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 I RSSI Z */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0I_TBD
value|BWN_PHY_N(0x1A7)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 I TBD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0I_PWRDET
value|BWN_PHY_N(0x1A8)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 I power det */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0I_TSSI
value|BWN_PHY_N(0x1A9)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 I TSSI */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0Q_RSSI_X
value|BWN_PHY_N(0x1AA)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 Q RSSI X */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0Q_RSSI_Y
value|BWN_PHY_N(0x1AB)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 Q RSSI Y */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0Q_RSSI_Z
value|BWN_PHY_N(0x1AC)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 Q RSSI Z */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0Q_TBD
value|BWN_PHY_N(0x1AD)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 Q TBD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0Q_PWRDET
value|BWN_PHY_N(0x1AE)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 Q power det */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_0Q_TSSI
value|BWN_PHY_N(0x1AF)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 0 Q TSSI */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1I_RSSI_X
value|BWN_PHY_N(0x1B0)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 I RSSI X */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1I_RSSI_Y
value|BWN_PHY_N(0x1B1)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 I RSSI Y */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1I_RSSI_Z
value|BWN_PHY_N(0x1B2)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 I RSSI Z */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1I_TBD
value|BWN_PHY_N(0x1B3)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 I TBD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1I_PWRDET
value|BWN_PHY_N(0x1B4)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 I power det */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1I_TSSI
value|BWN_PHY_N(0x1B5)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 I TSSI */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1Q_RSSI_X
value|BWN_PHY_N(0x1B6)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 Q RSSI X */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1Q_RSSI_Y
value|BWN_PHY_N(0x1B7)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 Q RSSI Y */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1Q_RSSI_Z
value|BWN_PHY_N(0x1B8)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 Q RSSI Z */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1Q_TBD
value|BWN_PHY_N(0x1B9)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 Q TBD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1Q_PWRDET
value|BWN_PHY_N(0x1BA)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 Q power det */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSIMC_1Q_TSSI
value|BWN_PHY_N(0x1BB)
end_define

begin_comment
comment|/* RSSI multiplication coefficient 1 Q TSSI */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SAMC_WCNT
value|BWN_PHY_N(0x1BC)
end_define

begin_comment
comment|/* Sample collect wait counter */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PTHROUGH_CNT
value|BWN_PHY_N(0x1BD)
end_define

begin_comment
comment|/* Pass-through counter */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_LTRN_OFF_G20L
value|BWN_PHY_N(0x1C4)
end_define

begin_comment
comment|/* LTRN offset gain 20L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_LTRN_OFF_20L
value|BWN_PHY_N(0x1C5)
end_define

begin_comment
comment|/* LTRN offset 20L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_LTRN_OFF_G20U
value|BWN_PHY_N(0x1C6)
end_define

begin_comment
comment|/* LTRN offset gain 20U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_LTRN_OFF_20U
value|BWN_PHY_N(0x1C7)
end_define

begin_comment
comment|/* LTRN offset 20U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_DSSSCCK_GAINSL
value|BWN_PHY_N(0x1C8)
end_define

begin_comment
comment|/* DSSS/CCK gain settle length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_GPIO_LOOUT
value|BWN_PHY_N(0x1C9)
end_define

begin_comment
comment|/* GPIO low out */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_GPIO_HIOUT
value|BWN_PHY_N(0x1CA)
end_define

begin_comment
comment|/* GPIO high out */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRS_CHECK
value|BWN_PHY_N(0x1CB)
end_define

begin_comment
comment|/* CRS check */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOGSS_RAT
value|BWN_PHY_N(0x1CC)
end_define

begin_comment
comment|/* ML/logss ratio */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_DUPSCALE
value|BWN_PHY_N(0x1CD)
end_define

begin_comment
comment|/* Dup scale */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BW1A
value|BWN_PHY_N(0x1CE)
end_define

begin_comment
comment|/* BW 1A */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BW2
value|BWN_PHY_N(0x1CF)
end_define

begin_comment
comment|/* BW 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BW3
value|BWN_PHY_N(0x1D0)
end_define

begin_comment
comment|/* BW 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BW4
value|BWN_PHY_N(0x1D1)
end_define

begin_comment
comment|/* BW 4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BW5
value|BWN_PHY_N(0x1D2)
end_define

begin_comment
comment|/* BW 5 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_BW6
value|BWN_PHY_N(0x1D3)
end_define

begin_comment
comment|/* BW 6 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_COALEN0
value|BWN_PHY_N(0x1D4)
end_define

begin_comment
comment|/* Coarse length 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_COALEN1
value|BWN_PHY_N(0x1D5)
end_define

begin_comment
comment|/* Coarse length 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSTHRES_1U
value|BWN_PHY_N(0x1D6)
end_define

begin_comment
comment|/* CRS threshold 1 U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSTHRES_2U
value|BWN_PHY_N(0x1D7)
end_define

begin_comment
comment|/* CRS threshold 2 U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSTHRES_3U
value|BWN_PHY_N(0x1D8)
end_define

begin_comment
comment|/* CRS threshold 3 U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSCTL_U
value|BWN_PHY_N(0x1D9)
end_define

begin_comment
comment|/* CRS control U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSTHRES_1L
value|BWN_PHY_N(0x1DA)
end_define

begin_comment
comment|/* CRS threshold 1 L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSTHRES_2L
value|BWN_PHY_N(0x1DB)
end_define

begin_comment
comment|/* CRS threshold 2 L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSTHRES_3L
value|BWN_PHY_N(0x1DC)
end_define

begin_comment
comment|/* CRS threshold 3 L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSCTL_L
value|BWN_PHY_N(0x1DD)
end_define

begin_comment
comment|/* CRS control L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_STRA_1U
value|BWN_PHY_N(0x1DE)
end_define

begin_comment
comment|/* STR address 1 U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_STRA_2U
value|BWN_PHY_N(0x1DF)
end_define

begin_comment
comment|/* STR address 2 U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_STRA_1L
value|BWN_PHY_N(0x1E0)
end_define

begin_comment
comment|/* STR address 1 L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_STRA_2L
value|BWN_PHY_N(0x1E1)
end_define

begin_comment
comment|/* STR address 2 L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSCHECK1
value|BWN_PHY_N(0x1E2)
end_define

begin_comment
comment|/* CRS check 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSCHECK2
value|BWN_PHY_N(0x1E3)
end_define

begin_comment
comment|/* CRS check 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CRSCHECK3
value|BWN_PHY_N(0x1E4)
end_define

begin_comment
comment|/* CRS check 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_JMPSTP0
value|BWN_PHY_N(0x1E5)
end_define

begin_comment
comment|/* Jump step 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_JMPSTP1
value|BWN_PHY_N(0x1E6)
end_define

begin_comment
comment|/* Jump step 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_CMD
value|BWN_PHY_N(0x1E7)
end_define

begin_comment
comment|/* TX power control command */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_CMD_INIT
value|0x007F
end_define

begin_comment
comment|/* Init */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_CMD_INIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_CMD_COEFF
value|0x2000
end_define

begin_comment
comment|/* Power control coefficients */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_CMD_HWPCTLEN
value|0x4000
end_define

begin_comment
comment|/* Hardware TX power control enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_CMD_PCTLEN
value|0x8000
end_define

begin_comment
comment|/* TX power control enable */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_N
value|BWN_PHY_N(0x1E8)
end_define

begin_comment
comment|/* TX power control N num */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_N_TSSID
value|0x00FF
end_define

begin_comment
comment|/* N TSSI delay */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_N_TSSID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_N_NPTIL2
value|0x0700
end_define

begin_comment
comment|/* N PT integer log2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_N_NPTIL2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_ITSSI
value|BWN_PHY_N(0x1E9)
end_define

begin_comment
comment|/* TX power control idle TSSI */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_ITSSI_0
value|0x003F
end_define

begin_comment
comment|/* Idle TSSI 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_ITSSI_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_ITSSI_1
value|0x3F00
end_define

begin_comment
comment|/* Idle TSSI 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_ITSSI_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_ITSSI_BINF
value|0x8000
end_define

begin_comment
comment|/* Raw TSSI offset bin format */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_TPWR
value|BWN_PHY_N(0x1EA)
end_define

begin_comment
comment|/* TX power control target power */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_TPWR_0
value|0x00FF
end_define

begin_comment
comment|/* Power 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_TPWR_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_TPWR_1
value|0xFF00
end_define

begin_comment
comment|/* Power 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_TPWR_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_BIDX
value|BWN_PHY_N(0x1EB)
end_define

begin_comment
comment|/* TX power control base index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_BIDX_0
value|0x007F
end_define

begin_comment
comment|/* uC base index 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_BIDX_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_BIDX_1
value|0x7F00
end_define

begin_comment
comment|/* uC base index 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_BIDX_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_BIDX_LOAD
value|0x8000
end_define

begin_comment
comment|/* Load base index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_PIDX
value|BWN_PHY_N(0x1EC)
end_define

begin_comment
comment|/* TX power control power index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_PIDX_0
value|0x007F
end_define

begin_comment
comment|/* uC power index 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_PIDX_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_PIDX_1
value|0x7F00
end_define

begin_comment
comment|/* uC power index 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_PIDX_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_C1_TXPCTL_STAT
value|BWN_PHY_N(0x1ED)
end_define

begin_comment
comment|/* Core 1 TX power control status */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_C2_TXPCTL_STAT
value|BWN_PHY_N(0x1EE)
end_define

begin_comment
comment|/* Core 2 TX power control status */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_STAT_EST
value|0x00FF
end_define

begin_comment
comment|/* Estimated power */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_STAT_EST_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_STAT_BIDX
value|0x7F00
end_define

begin_comment
comment|/* Base index */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_STAT_BIDX_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_STAT_ESTVALID
value|0x8000
end_define

begin_comment
comment|/* Estimated power valid */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_SMALLSGS_LEN
value|BWN_PHY_N(0x1EF)
end_define

begin_comment
comment|/* Small sig gain settle length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHYSTAT_GAIN0
value|BWN_PHY_N(0x1F0)
end_define

begin_comment
comment|/* PHY stats gain info 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHYSTAT_GAIN1
value|BWN_PHY_N(0x1F1)
end_define

begin_comment
comment|/* PHY stats gain info 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHYSTAT_FREQEST
value|BWN_PHY_N(0x1F2)
end_define

begin_comment
comment|/* PHY stats frequency estimate */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHYSTAT_ADVRET
value|BWN_PHY_N(0x1F3)
end_define

begin_comment
comment|/* PHY stats ADV retard */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PHYLB_MODE
value|BWN_PHY_N(0x1F4)
end_define

begin_comment
comment|/* PHY loopback mode */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TONE_MIDX20_1
value|BWN_PHY_N(0x1F5)
end_define

begin_comment
comment|/* Tone map index 20/1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TONE_MIDX20_2
value|BWN_PHY_N(0x1F6)
end_define

begin_comment
comment|/* Tone map index 20/2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TONE_MIDX20_3
value|BWN_PHY_N(0x1F7)
end_define

begin_comment
comment|/* Tone map index 20/3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TONE_MIDX40_1
value|BWN_PHY_N(0x1F8)
end_define

begin_comment
comment|/* Tone map index 40/1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TONE_MIDX40_2
value|BWN_PHY_N(0x1F9)
end_define

begin_comment
comment|/* Tone map index 40/2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TONE_MIDX40_3
value|BWN_PHY_N(0x1FA)
end_define

begin_comment
comment|/* Tone map index 40/3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TONE_MIDX40_4
value|BWN_PHY_N(0x1FB)
end_define

begin_comment
comment|/* Tone map index 40/4 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PILTONE_MIDX1
value|BWN_PHY_N(0x1FC)
end_define

begin_comment
comment|/* Pilot tone map index 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PILTONE_MIDX2
value|BWN_PHY_N(0x1FD)
end_define

begin_comment
comment|/* Pilot tone map index 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_PILTONE_MIDX3
value|BWN_PHY_N(0x1FE)
end_define

begin_comment
comment|/* Pilot tone map index 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXRIFS_FRDEL
value|BWN_PHY_N(0x1FF)
end_define

begin_comment
comment|/* TX RIFS frame delay */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQ_RX2TX_PUD_40M
value|BWN_PHY_N(0x200)
end_define

begin_comment
comment|/* AFE seq rx2tx power up/down delay 40M */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQ_TX2RX_PUD_40M
value|BWN_PHY_N(0x201)
end_define

begin_comment
comment|/* AFE seq tx2rx power up/down delay 40M */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQ_RX2TX_PUD_20M
value|BWN_PHY_N(0x202)
end_define

begin_comment
comment|/* AFE seq rx2tx power up/down delay 20M */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQ_TX2RX_PUD_20M
value|BWN_PHY_N(0x203)
end_define

begin_comment
comment|/* AFE seq tx2rx power up/down delay 20M */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RX_SIGCTL
value|BWN_PHY_N(0x204)
end_define

begin_comment
comment|/* RX signal control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXPIL_CYCNT0
value|BWN_PHY_N(0x205)
end_define

begin_comment
comment|/* RX pilot cycle counter 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXPIL_CYCNT1
value|BWN_PHY_N(0x206)
end_define

begin_comment
comment|/* RX pilot cycle counter 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RXPIL_CYCNT2
value|BWN_PHY_N(0x207)
end_define

begin_comment
comment|/* RX pilot cycle counter 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQ_RX2TX_PUD_10M
value|BWN_PHY_N(0x208)
end_define

begin_comment
comment|/* AFE seq rx2tx power up/down delay 10M */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQ_TX2RX_PUD_10M
value|BWN_PHY_N(0x209)
end_define

begin_comment
comment|/* AFE seq tx2rx power up/down delay 10M */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_DSSSCCK_CRSEXTL
value|BWN_PHY_N(0x20A)
end_define

begin_comment
comment|/* DSSS/CCK CRS extension length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOGSS_RATSLOPE
value|BWN_PHY_N(0x20B)
end_define

begin_comment
comment|/* ML/logss ratio slope */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RIFS_SRCTL
value|BWN_PHY_N(0x20C)
end_define

begin_comment
comment|/* RIFS search timeout length */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXREALFD
value|BWN_PHY_N(0x20D)
end_define

begin_comment
comment|/* TX real frame delay */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_HPANT_SWTHRES
value|BWN_PHY_N(0x20E)
end_define

begin_comment
comment|/* High power antenna switch threshold */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EDCRS_ASSTHRES0
value|BWN_PHY_N(0x210)
end_define

begin_comment
comment|/* ED CRS assert threshold 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EDCRS_ASSTHRES1
value|BWN_PHY_N(0x211)
end_define

begin_comment
comment|/* ED CRS assert threshold 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EDCRS_DEASSTHRES0
value|BWN_PHY_N(0x212)
end_define

begin_comment
comment|/* ED CRS deassert threshold 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EDCRS_DEASSTHRES1
value|BWN_PHY_N(0x213)
end_define

begin_comment
comment|/* ED CRS deassert threshold 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_STR_WTIME20U
value|BWN_PHY_N(0x214)
end_define

begin_comment
comment|/* STR wait time 20U */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_STR_WTIME20L
value|BWN_PHY_N(0x215)
end_define

begin_comment
comment|/* STR wait time 20L */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TONE_MIDX657M
value|BWN_PHY_N(0x216)
end_define

begin_comment
comment|/* Tone map index 657M */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_HTSIGTONES
value|BWN_PHY_N(0x217)
end_define

begin_comment
comment|/* HT signal tones */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSI1
value|BWN_PHY_N(0x219)
end_define

begin_comment
comment|/* RSSI value 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_RSSI2
value|BWN_PHY_N(0x21A)
end_define

begin_comment
comment|/* RSSI value 2 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_CHAN_ESTHANG
value|BWN_PHY_N(0x21D)
end_define

begin_comment
comment|/* Channel estimate hang */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FINERX2_CGC
value|BWN_PHY_N(0x221)
end_define

begin_comment
comment|/* Fine RX 2 clock gate control */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FINERX2_CGC_DECGC
value|0x0008
end_define

begin_comment
comment|/* Decode gated clocks */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_INIT
value|BWN_PHY_N(0x222)
end_define

begin_comment
comment|/* TX power control init */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_INIT_PIDXI1
value|0x00FF
end_define

begin_comment
comment|/* Power index init 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_TXPCTL_INIT_PIDXI1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRSEN
value|BWN_PHY_N(0x223)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS40ASSERTTHRESH0
value|BWN_PHY_N(0x224)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS40ASSERTTHRESH1
value|BWN_PHY_N(0x225)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS40DEASSERTTHRESH0
value|BWN_PHY_N(0x226)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS40DEASSERTTHRESH1
value|BWN_PHY_N(0x227)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS20LASSERTTHRESH0
value|BWN_PHY_N(0x228)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS20LASSERTTHRESH1
value|BWN_PHY_N(0x229)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS20LDEASSERTTHRESH0
value|BWN_PHY_N(0x22A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS20LDEASSERTTHRESH1
value|BWN_PHY_N(0x22B)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS20UASSERTTHRESH0
value|BWN_PHY_N(0x22C)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS20UASSERTTHRESH1
value|BWN_PHY_N(0x22D)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS20UDEASSERTTHRESH0
value|BWN_PHY_N(0x22E)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS20UDEASSERTTHRESH1
value|BWN_PHY_N(0x22F)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ED_CRS
value|BWN_PHY_N(0x230)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TIMEOUTEN
value|BWN_PHY_N(0x231)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_OFDMPAYDECODETIMEOUTLEN
value|BWN_PHY_N(0x232)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CCKPAYDECODETIMEOUTLEN
value|BWN_PHY_N(0x233)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_NONPAYDECODETIMEOUTLEN
value|BWN_PHY_N(0x234)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TIMEOUTSTATUS
value|BWN_PHY_N(0x235)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTRLCORE0GPIO0
value|BWN_PHY_N(0x236)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTRLCORE0GPIO1
value|BWN_PHY_N(0x237)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTRLCORE0GPIO2
value|BWN_PHY_N(0x238)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTRLCORE0GPIO3
value|BWN_PHY_N(0x239)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTRLCORE1GPIO0
value|BWN_PHY_N(0x23A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTRLCORE1GPIO1
value|BWN_PHY_N(0x23B)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTRLCORE1GPIO2
value|BWN_PHY_N(0x23C)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RFCTRLCORE1GPIO3
value|BWN_PHY_N(0x23D)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYTESTCONTROL
value|BWN_PHY_N(0x23E)
end_define

begin_comment
comment|/* REV3+ */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_FORCEFRONT0
value|BWN_PHY_N(0x23F)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_FORCEFRONT1
value|BWN_PHY_N(0x240)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_NORMVARHYSTTH
value|BWN_PHY_N(0x241)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXCCKERROR
value|BWN_PHY_N(0x242)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_AFESEQINITDACGAIN
value|BWN_PHY_N(0x243)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXANTSWLUT
value|BWN_PHY_N(0x244)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CORECONFIG
value|BWN_PHY_N(0x245)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ANTENNADIVDWELLTIME
value|BWN_PHY_N(0x246)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ANTENNACCKDIVDWELLTIME
value|BWN_PHY_N(0x247)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ANTENNADIVBACKOFFGAIN
value|BWN_PHY_N(0x248)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ANTENNADIVMINGAIN
value|BWN_PHY_N(0x249)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BRDSEL_NORMVARHYSTTH
value|BWN_PHY_N(0x24A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXANTSWITCHCTRL
value|BWN_PHY_N(0x24B)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ENERGYDROPTIMEOUTLEN2
value|BWN_PHY_N(0x24C)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOG_TXEVM0
value|BWN_PHY_N(0x250)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOG_TXEVM1
value|BWN_PHY_N(0x251)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOG_TXEVM2
value|BWN_PHY_N(0x252)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOG_TXEVM3
value|BWN_PHY_N(0x253)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOG_TXEVM4
value|BWN_PHY_N(0x254)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOG_TXEVM5
value|BWN_PHY_N(0x255)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOG_TXEVM6
value|BWN_PHY_N(0x256)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_LOG_TXEVM7
value|BWN_PHY_N(0x257)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ML_SCALE_TWEAK
value|BWN_PHY_N(0x258)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_MLUA
value|BWN_PHY_N(0x259)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_ZFUA
value|BWN_PHY_N(0x25A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CHANUPSYM01
value|BWN_PHY_N(0x25B)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CHANUPSYM2
value|BWN_PHY_N(0x25C)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20NUM00
value|BWN_PHY_N(0x25D)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20NUM01
value|BWN_PHY_N(0x25E)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20NUM02
value|BWN_PHY_N(0x25F)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20DEN00
value|BWN_PHY_N(0x260)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20DEN01
value|BWN_PHY_N(0x261)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20NUM10
value|BWN_PHY_N(0x262)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20NUM11
value|BWN_PHY_N(0x263)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20NUM12
value|BWN_PHY_N(0x264)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20DEN10
value|BWN_PHY_N(0x265)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT20DEN11
value|BWN_PHY_N(0x266)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40NUM00
value|BWN_PHY_N(0x267)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40NUM01
value|BWN_PHY_N(0x268)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40NUM02
value|BWN_PHY_N(0x269)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40DEN00
value|BWN_PHY_N(0x26A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40DEN01
value|BWN_PHY_N(0x26B)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40NUM10
value|BWN_PHY_N(0x26C)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40NUM11
value|BWN_PHY_N(0x26D)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40NUM12
value|BWN_PHY_N(0x26E)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40DEN10
value|BWN_PHY_N(0x26F)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RXSTRNFILT40DEN11
value|BWN_PHY_N(0x270)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHPOWTHRESHOLD1
value|BWN_PHY_N(0x271)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHPOWTHRESHOLD2
value|BWN_PHY_N(0x272)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHLOWPOWTHRESHOLD
value|BWN_PHY_N(0x273)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHPOWTHRESHOLD1L
value|BWN_PHY_N(0x274)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHPOWTHRESHOLD2L
value|BWN_PHY_N(0x275)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHLOWPOWTHRESHOLDL
value|BWN_PHY_N(0x276)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHPOWTHRESHOLD1U
value|BWN_PHY_N(0x277)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHPOWTHRESHOLD2U
value|BWN_PHY_N(0x278)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSHIGHLOWPOWTHRESHOLDU
value|BWN_PHY_N(0x279)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSACIDETECTTHRESH
value|BWN_PHY_N(0x27A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSACIDETECTTHRESHL
value|BWN_PHY_N(0x27B)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSACIDETECTTHRESHU
value|BWN_PHY_N(0x27C)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWER0
value|BWN_PHY_N(0x27D)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWER1
value|BWN_PHY_N(0x27E)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWER2
value|BWN_PHY_N(0x27F)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWERL0
value|BWN_PHY_N(0x280)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWERL1
value|BWN_PHY_N(0x281)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWERL2
value|BWN_PHY_N(0x282)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWERU0
value|BWN_PHY_N(0x283)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWERU1
value|BWN_PHY_N(0x284)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_CRSMINPOWERU2
value|BWN_PHY_N(0x285)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_STRPARAM
value|BWN_PHY_N(0x286)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_STRPARAML
value|BWN_PHY_N(0x287)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_STRPARAMU
value|BWN_PHY_N(0x288)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYCRSMINPOWER0
value|BWN_PHY_N(0x289)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYCRSMINPOWER1
value|BWN_PHY_N(0x28A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYCRSMINPOWER2
value|BWN_PHY_N(0x28B)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYFILTDEN0COEF
value|BWN_PHY_N(0x28C)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYFILTDEN1COEF
value|BWN_PHY_N(0x28D)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYFILTDEN2COEF
value|BWN_PHY_N(0x28E)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYFILTNUM0COEF
value|BWN_PHY_N(0x28F)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYFILTNUM1COEF
value|BWN_PHY_N(0x290)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYFILTNUM2COEF
value|BWN_PHY_N(0x291)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYFILTNUM01COEF2
value|BWN_PHY_N(0x292)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_BPHYFILTBYPASS
value|BWN_PHY_N(0x293)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_SGILTRNOFFSET
value|BWN_PHY_N(0x294)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_T2_MIN
value|BWN_PHY_N(0x295)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_TXPWRCTRLDAMPING
value|BWN_PHY_N(0x296)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PAPD_EN0
value|BWN_PHY_N(0x297)
end_define

begin_comment
comment|/* PAPD Enable0 TBD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EPS_TABLE_ADJ0
value|BWN_PHY_N(0x298)
end_define

begin_comment
comment|/* EPS Table Adj0 TBD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EPS_OVERRIDEI_0
value|BWN_PHY_N(0x299)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_EPS_OVERRIDEQ_0
value|BWN_PHY_N(0x29A)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PAPD_EN1
value|BWN_PHY_N(0x29B)
end_define

begin_comment
comment|/* PAPD Enable1 TBD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EPS_TABLE_ADJ1
value|BWN_PHY_N(0x29C)
end_define

begin_comment
comment|/* EPS Table Adj1 TBD */
end_comment

begin_define
define|#
directive|define
name|BWN_NPHY_EPS_OVERRIDEI_1
value|BWN_PHY_N(0x29D)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_EPS_OVERRIDEQ_1
value|BWN_PHY_N(0x29E)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PAPD_CAL_ADDRESS
value|BWN_PHY_N(0x29F)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PAPD_CAL_YREFEPSILON
value|BWN_PHY_N(0x2A0)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PAPD_CAL_SETTLE
value|BWN_PHY_N(0x2A1)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PAPD_CAL_CORRELATE
value|BWN_PHY_N(0x2A2)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PAPD_CAL_SHIFTS0
value|BWN_PHY_N(0x2A3)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_PAPD_CAL_SHIFTS1
value|BWN_PHY_N(0x2A4)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_SAMPLE_START_ADDR
value|BWN_PHY_N(0x2A5)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_RADAR_ADC_TO_DBM
value|BWN_PHY_N(0x2A6)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_INITGAIN_A
value|BWN_PHY_N(0x2A7)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_INITGAIN_B
value|BWN_PHY_N(0x2A8)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_CLIP_HIGAIN_A
value|BWN_PHY_N(0x2A9)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_CLIP_HIGAIN_B
value|BWN_PHY_N(0x2AA)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_CLIP_MEDGAIN_A
value|BWN_PHY_N(0x2AB)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_CLIP_MEDGAIN_B
value|BWN_PHY_N(0x2AC)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_CLIP_LOGAIN_A
value|BWN_PHY_N(0x2AD)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_CLIP_LOGAIN_B
value|BWN_PHY_N(0x2AE)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_CLIP2_GAIN_A
value|BWN_PHY_N(0x2AF)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV3_C2_CLIP2_GAIN_B
value|BWN_PHY_N(0x2B0)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV7_RF_CTL_MISC_REG3
value|BWN_PHY_N(0x340)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV7_RF_CTL_MISC_REG4
value|BWN_PHY_N(0x341)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV7_RF_CTL_OVER3
value|BWN_PHY_N(0x342)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV7_RF_CTL_OVER4
value|BWN_PHY_N(0x343)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV7_RF_CTL_MISC_REG5
value|BWN_PHY_N(0x344)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV7_RF_CTL_MISC_REG6
value|BWN_PHY_N(0x345)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV7_RF_CTL_OVER5
value|BWN_PHY_N(0x346)
end_define

begin_define
define|#
directive|define
name|BWN_NPHY_REV7_RF_CTL_OVER6
value|BWN_PHY_N(0x347)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_B_BBCFG
value|BWN_PHY_N_BMODE(0x001)
end_define

begin_comment
comment|/* BB config */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_B_BBCFG_RSTCCA
value|0x4000
end_define

begin_comment
comment|/* Reset CCA */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_B_BBCFG_RSTRX
value|0x8000
end_define

begin_comment
comment|/* Reset RX */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_B_TEST
value|BWN_PHY_N_BMODE(0x00A)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_BWN_PHY_N_REGS_H__ */
end_comment

end_unit

