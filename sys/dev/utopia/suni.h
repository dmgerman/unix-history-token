begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Register definitions for the following chips:  *	PMC-Sierra PMC-5346 (S/UNI-LITE)  *	PMC-Sierra PMC-5350 (S/UNI-ULTRA)  *	PMC-Sierra PMC-5355 (S/UNI-622)  *  * All definitions ending with _ULTRA are for the ULTRA chip only, all  * definitions ending with _LITE are for the LITE chip only. Some registers  * are only in the ULTRA and the definitions are not suffixed. All other  * definitions are for all chips.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UTOPIA_SUNI_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UTOPIA_SUNI_H
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MRESET
value|"Master Reset and Identity/Load Meters"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MRESET
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_TYPE
value|0x70
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_TYPE_622
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_TYPE_LITE
value|0x30
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_TYPE_ULTRA
value|0x70
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_TIP_ULTRA
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_ID_ULTRA
value|0x07
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_ID_LITE
value|0x0f
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MRESET_ID_622
value|0x0f
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MRESET_ULTRA
value|"\020\10RESET\12\x70\12TYPE\4TIP\12\7\12ID"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MRESET_LITE
value|"\020\10RESET\12\x70\12TYPE\12\xf\12ID"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MRESET_622
value|"\020\10RESET\12\x70\12TYPE\12\xf\12ID"
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MCONFIG
value|"Master Configuration"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MCONFIG
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_AUTOFEBE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_AUTOLRDI
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_AUTOPRDI
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TCAINV
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_RCAINV
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_RXDINV_LITE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TFP_IN_ULTRA
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MCONFIG_LITE
value|"\020\7AUTOFEBE\6AUTOLRDI\5AUTOPRDI\4TCAINV\3RCAINV\2RXDINV"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MCONFIG_ULTRA
value|"\020\7AUTOFEBE\6AUTOLRDI\5AUTOPRDI\4TCAINV\3RCAINV\1TFPI_IN"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TPTBEN_622
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TSTBEN_622
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_SDH_C1_622
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_FIXPTR_622
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TMODE_622
value|0x0C
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TMODE_STS1_BYTE
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TMODE_STS3c
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TMODE_STS1_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_TMODE_STS12c
value|0x0C
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_RMODE_622
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_RMODE_STS1_BYTE
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_RMODE_STS3c
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_RMODE_STS1_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCONFIG_RMODE_STS12c
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MCONFIG_622
value|"\020\10TPTBEN\7TSTBEN\6SDH_C1\5FIXPTR\11\x0C\0x00XSTS1BYTE\11\0x0C\0x04XSTS3c\11\0x0C\0x08XSTS1BIT\11\0x0C\0x0CXSTS12c\11\0x03\0x00RSTS1BYTE\11\0x03\0x01RSTS3c\11\0x03\0x02RSTS1BIT\11\0x03\0x03RSTS12c"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MISTATUS
value|"Master Interrupt Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MISTATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_CSUI_ULTRA
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_TROOLI_LITE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_SUNII_622
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_LCDI
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_STBI_622
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_CRUI_ULTRA
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_RDOOLI_LITE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_RESERVED_622
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_TACPI
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_RACPI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_RPOPI
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_RLOPI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MISTATUS_RSOPI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MISTATUS_LITE
value|"\020\10TROOLI\7LCDI\6RDOOLI\5TACPI\4RACPI\3RPOPI\2RLOPI\1RSOPI"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MISTATUS_ULTRA
value|"\020\10CSUI\7LCDI\6CRUI\5TACPI\4RACPI\3RPOPI\2RLOPI\1RSOPI"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MISTATUS_622
value|"\020\10S/UNII\7STBI\5TACPI\4RACPI\3RPOPI\2RLOPI\1RSOPI"
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MMCTRL
value|"Master Mode Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MMCTRL
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MMCTRL_51
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MMCTRL_155
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MMCTRL
value|"\020\11\3\00251MBIT\11\3\003155MBIT"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_PISO
value|"PISO Interrupt"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_PISO
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_PISO_PAEE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_PISO_PAEI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_PISO
value|"\020\2PAEE\1PAEI"
end_define

begin_comment
comment|/* ultra/lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MCLKM
value|"Master Clock Monitor"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MCLKM
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCLKM_RFCLKA
value|0x10
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCLKM_TFCLKA
value|0x08
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCLKM_RRCLKA
value|0x08
end_define

begin_comment
comment|/* lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCLKM_REFCLKA
value|0x04
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCLKM_TRCLKA
value|0x04
end_define

begin_comment
comment|/* lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCLKM_RCLKA
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCLKM_TCLKA
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MCLKM_LITE
value|"\020\4RRCLKA\3TRCLKA\2RCLKA\1TCLKA"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MCLKM_ULTRA
value|"\020\5RFCLKA\4TFCLKA\3REFCLKA\2RCLKA\1TCLKA"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MCTRLM
value|"Master Control/Monitor"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MCTRLM
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRLM_TCAINV
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRLM_RCAINV
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRLM_LLE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRLM_DLE
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRLM_LOOPT
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRLM_DPLE
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRLM_PICLKA
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRLM_TCLKA
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MCTRLM
value|"\020\10TCAINV\7RCAINV\6LLE\5DLE\4LOOPT\3DPLE\2PICLKA\1TCLKA"
end_define

begin_comment
comment|/* ultra/lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MCTRL
value|"Master Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MCTRL
value|0x05
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_LCDE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_LCDV
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_FIXPTR
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_TPLE
value|0x10
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_PDLE
value|0x08
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_LLE
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_SDLE
value|0x02
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_DLE
value|0x02
end_define

begin_comment
comment|/* lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_MCTRL_LOOPT
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MCTRL_ULTRA
value|"\020\10LCDE\7LCDV\6FIXPTR\5TPLE\4PDLE\3LLE\2SDLE\1LOOPT"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MCTRL_LITE
value|"\020\10LCDE\7LCDV\6FIXPTR\3LLE\2DLE\1LOOPT"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MALARM
value|"Master Auto Alarm"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MALARM
value|0x05
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MALARM_AUTOFEBE
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MALARM_AUTOLRDI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MALARM_AUTOPRDI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MALARM
value|"\020\4AUTOFEBE\2AUTOLRDI\1AUTOPRDI"
end_define

begin_comment
comment|/* ultra/lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_CLKSYN
value|"Clock Synthesis Control and Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_CLKSYN
value|0x06
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_CLKSYN_TROOLI
value|0x20
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_CLKSYN_TROOLV
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_CLKSYN_TROOLE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_CLKSYN_TREFSEL
value|0x01
end_define

begin_comment
comment|/* lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_CLKSYN_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_CLKSYN_ULTRA
value|"\020\6TROOLI\4TROOLV\2TROOLE"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_CLKSYN_LITE
value|"\020\4TROOLV\2TROOLE\1TREFSEL"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_POUT
value|"Parallel Output Port"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_POUT
value|0x06
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_POUT_POP
value|0x3f
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_POUT
value|"\020\12\x3f\12POP"
end_define

begin_comment
comment|/* ultra/lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_CLKREC
value|"Clock Recovery Control and Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_CLKREC_LITE
value|0x07
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_CLKREC_ULTRA
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_CLKREC_RROOLI
value|0x40
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_CLKREC_RDOOLI
value|0x20
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_CLKREC_RROOLV
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_CLKREC_RDOOLV
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_CLKREC_RROOLE
value|0x04
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_CLKREC_RDOOLE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_CLKREC_RREFSEL
value|0x01
end_define

begin_comment
comment|/* lite */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_CLKREC_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_CLKREC_ULTRA
value|"\020\7RROOLI\6RDOOLI\5RROOLV\4RDOOLV\3RROOLE\2RDOOLE"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_CLKREC_LITE
value|"\020\5RROOLV\4RDOOLV\2RDOOLE\1RREFSEL"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_PIN
value|"Parallel Input Port"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_PIN
value|0x07
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_PINV
value|"Parallel Input Port Value"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_PINV
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_PINV_PIPV
value|0x0f
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_PINV
value|"\020\12\0x0f\12PIPIV"
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_CLKRECCFG
value|"Clock Recovery Configuration"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_CLKRECCFG
value|0x09
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_CLKRECCFG_RESERVED
value|0x07
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_CLKRECCFG
value|"\020"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_PINE
value|"Parallel Input Port Enable"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_PINE
value|0x09
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_LTXCFG1
value|"Line Transmitter Configuration 1"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_LTXCFG1
value|0x0A
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_LTXCFG1_VREFSEL
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_LTXCFG1_OEN
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_LTXCFG1_OTQ
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_LTXCFG1_RESERVED
value|0x0C
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_LTXCFG1
value|"\020\10VREFSEL\6OEN\5OTQ"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_XC1
value|"Transmit C1"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_XC1
value|0x0A
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_LTXCFG2
value|"Line Transmitter Configuration 2"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_LTXCFG2
value|0x0B
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_LTXCFG2_RESERVED
value|0xFF
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_LTXCFG2
value|"\020"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_APSCS
value|"APS Control/Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_APSCS
value|0x0B
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_APSCS_PSBFE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_APSCS_COAPSE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_APSCS_Z1E
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_APSCS_Zi1
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_APSCS_PSBFI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_APSCS_COAPSI
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_APSCS_RESERVED
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_APSCS_PSBFV
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_APSCS
value|"\020\10PSBFE\7COAPSE\6Z1E\5Z1I\4PSBFI\3COAPSI\1PSBFV"
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_LRXCFG
value|"Line Receiver Configuration"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_LRXCFG
value|0x0C
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_LRXCFG_RESERVED
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_LRXCFG
value|"\020"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RK1
value|"Receive K1"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RK1
value|0x0C
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RK2
value|"Receive K2"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RK2
value|0x0D
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RZ1
value|"Receive Z1"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RZ1
value|0x0E
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_XZ1
value|"Transmit Z1"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_XZ1
value|0x0F
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RSOPCIE
value|"RSOP Control/Interrupt Enable"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RSOPCIE
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RSOPCIE_BIPWORD_622
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPCIE_DDS
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPCIE_FOOF
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPCIE_RESV
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPCIE_ALGO2_622
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPCIE_BIPEE
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPCIE_LOSE
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPCIE_LOFE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPCIE_OOFE
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RSOPCIE
value|"\020\7DDS\6FOOF\4BIPEE\3LOSE\2LOFE\1OOFE"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RSOPCIE_622
value|"\020\10BIPWORD\7DDS\6FOOF\5ALGO2\4BIPEE\3LOSE\2LOFE\1OOFE"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RSOPSIS
value|"RSOP Status/Interrupt Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RSOPSIS
value|0x11
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPSIS_BIPEI
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPSIS_LOSI
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPSIS_LOFI
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPSIS_OOFI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPSIS_LOSV
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPSIS_LOFV
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RSOPSIS_OOFV
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RSOPSIS
value|"\020\7BIPEI\6LOSI\5LOFI\4OOFI\3LOSV\2LOFV\1OOFV"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RSOP_BIP8
value|"RSOP Section BIP-8"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RSOP_BIP8
value|0x12
end_define

begin_comment
comment|/* +0x13 */
end_comment

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TSOPCTRL
value|"TSOP Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TSOPCTRL
value|0x14
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TSOPCTRL_DS
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TSOPCTRL_LAIS
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TSOPCTRL_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TSOPCTRL
value|"\020\7DS\1LAIS"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TSOPDIAG
value|"TSOP Diagnostics"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TSOPDIAG
value|0x15
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TSOPDIAG_DLOS
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TSOPDIAG_DBIP8
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TSOPDIAG_DFP
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TSOPDIAG
value|"\020\3DLOS\2DBIP8\1DFP"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RLOPCTRL
value|"RLOP Control/Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL
value|0x18
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL_BIPWORD
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL_ALLONES_622
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL_AISDET_622
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL_LRDIDET_622
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL_BIPWORDO_622
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL_LAISV
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL_RDIV
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPCTRL_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RLOPCTRL
value|"\020\10BIPWORD\2LAISV\1RDIV"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RLOPCTRL_622
value|"\020\10BIPWORD\7ALLONES\6AISDET\5LRDIDET\4BIPWORDO\2LAISV\1RDIV"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RLOPINTR
value|"RLOP Interrupt Enable/Interrupt Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR
value|0x19
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR_FEBEE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR_BIPEE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR_LAISE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR_RDIE
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR_FEBEI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR_BIPEI
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR_LAISI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPINTR_RDII
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RLOPINTR
value|"\020\10FEBEE\7BIPEE\6LAISE\5DRIE\4FEBEI\3BIPEI\2LAISI\1RDII"
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RLOPBIP8_24
value|"RLOP Line BIP-8/24"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPBIP8_24
value|0x1A
end_define

begin_comment
comment|/* +1B,1C */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_RLOPBIP8_24
value|0x0F
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RLOPBIP8_24_96
value|"RLOP Line BIP-8/24/96"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPBIP8_24_96
value|0x1A
end_define

begin_comment
comment|/* +1B,1C */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_RLOPBIP8_24_96
value|0x0F
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RLOPFEBE
value|"RLOP Line FEBE"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RLOPFEBE
value|0x1D
end_define

begin_comment
comment|/* +1E,1F */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_RLOPFEBE
value|0x0F
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TLOPCTRL
value|"TLOP Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TLOPCTRL
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TLOPCTRL_APSREG_622
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TLOPCTRL_RDI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TLOPCTRL_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TLOPCTRL
value|"\020\1RDI"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TLOPCTRL_622
value|"\020\6APSREG\1LRDI"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TLOPDIAG
value|"TLOP Diagnostics"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TLOPDIAG
value|0x21
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TLOPDIAG_DBIP
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TLOPDIAG
value|"\020\1DBIP"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TLOP_XK1
value|"TLOP Transmit K1"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TLOP_XK1
value|0x22
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TLOP_XK2
value|"TLOP Transmit K2"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TLOP_XK2
value|0x23
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SSTBCTRL
value|"SSTB Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SSTBCTRL
value|0x28
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCTRL_RRAMACC
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCTRL_RTIUIE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCTRL_RTIMIE
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCTRL_PER5
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCTRL_TNULL
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCTRL_NOSYNC
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCTRL_LEN16
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_SSTBCTRL
value|"\020\7RRAMACC\6RTIUIE\5RTIMIE\4PER5\3TNULL\2NOSYNC\1LEN16"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SSTBSTIS
value|"SSTB Section Trace Identifier Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SSTBSTIS
value|0x29
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBSTIS_BUSY
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBSTIS_RTIUI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBSTIS_RTIUV
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBSTIS_RTIMI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBSTIS_RTIMV
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_SSTBSTIS
value|"\020\10BUSY\4RTIUI\3RTIUV\2RTIMI\1RTIMV"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SSTBIAR
value|"SSTB Indirect Address Register"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SSTBIAR
value|0x2A
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBIAR_RWB
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBIAR_A
value|0x7F
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_SSTBIAR
value|"\020\10RWB\12\x7f\20"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SSTBIDR
value|"SSTB Indirect Data Register"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SSTBIDR
value|0x2B
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* see chip errata */
end_comment

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SSTBECSM
value|"SSTB Expected Clock Synchronization Message"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SSTBECSM
value|0x2C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SSTBCSMS
value|"SSTB Clock Synchronisation Message Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SSTBCSMS
value|0x2D
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCSMS_RCSMUIE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCSMS_RCSMMIE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCSMS_RCSMUI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCSMS_RCSMUV
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCSMS_RCSMMI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SSTBCSMS_RCSMMV
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_SSTBCSMS
value|"\020\10RCSMUIE\7RCSMMIE\4RCSMUI\3RCSMUV\2RCSMMI\1RCSMMV"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPCTRL
value|"RPOP Status/Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPCTRL
value|0x30
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPCTRL_LOP
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPCTRL_PAIS
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPCTRL_PRDI
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPCTRL_NEWPTRI_622
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPCTRL_NEWPTRE_622
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPCTRL_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPCTRL
value|"\020\6LOP\4PAIS\3PRDI"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPCTRL_622
value|"\020\6LOP\4PAIS\3PRDI\2NEWPTRI\1NEWPTRE"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPISTAT
value|"RPOP Interrupt Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPISTAT
value|0x31
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPISTAT_PSLI
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPISTAT_LOPI
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPISTAT_PAISI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPISTAT_PRDII
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPISTAT_BIPEI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPISTAT_FEBEI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPISTAT
value|"\02010PSLI\6LOPI\4PAISI\3PRDII\2BIPEI\1FEBEI"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPPIS
value|"RPOP Pointer Interrupt Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPPIS
value|0x32
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIS_ILLJREQI
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIS_DISCOPAI
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIS_INVNDFI
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIS_ILLPTRI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIS_NSEI
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIS_PSEI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIS_NDFI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPPIS
value|"\020\10ILLJREQI\6DISCOPAI\5INVNDFI\4ILLPTRI\3NSEI\2PSEI\1NDFI"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPIEN
value|"RPOP Interrupt Enable"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPIEN
value|0x33
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPIEN_PSLE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPIEN_LOPE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPIEN_PAISE
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPIEN_PRDIE
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPIEN_BIPEE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPIEN_FEBEE
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPIEN_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPIEN
value|"\02010PSLE\6LOPE\4PAISE\3PRDIE\2BIPEE\1FEBEE"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPPIE
value|"RPOP Pointer Interrupt Enable"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPPIE
value|0x34
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIE_ILLJREQE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIE_DISCOPAE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIE_INVNDFE
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIE_ILLPTRE
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIE_NSEE
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIE_PSEE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPIE_NDFE
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPPIE
value|"\020\10ILLJREQE\6DISCOPAE\5INVNDFE\4ILLPTRE\3NSEE\2PSEE\1NDFE"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPPTR
value|"RPOP Pointer"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPPTR
value|0x35
end_define

begin_comment
comment|/* +36 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPTR_RDI10
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPTR_S
value|0x0c
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RPOPPTR_S
value|2
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPPTR
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RPOPPTR
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPPTR
value|"\020\6RDI10\12\xc\20S"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPPSL
value|"RPOP Path Signal Label"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPPSL
value|0x37
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPBIP8
value|"RPOP Path BIP-8"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPBIP8
value|0x38
end_define

begin_comment
comment|/* +39 */
end_comment

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPFEBE
value|"RPOP Path FEBE"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPFEBE
value|0x3A
end_define

begin_comment
comment|/* +3B */
end_comment

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPRDI
value|"RPOP RDI"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPRDI
value|0x3C
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRDI_BLKFEBE
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRDI_ARDIE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRDI_ARDIV
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRDI_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPRDI
value|"\020\5BLKFEBE\2ARDIE\1ARDIV"
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPBIP8CFG
value|"RPOP Path BIP-8 Configuration"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPBIP8CFG
value|0x3D
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPBIP8CFG_BLKBIP
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPBIP8CFG_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPBIP8CFG
value|"\020\6BLKBIP"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RPOPRING
value|"RPOP Ring Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RPOPRING
value|0x3D
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRING_SOS
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRING_ENSS
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRING_BLKBIP
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRING_DISFS
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRING_BLKBIPO
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RPOPRING_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RPOPRING
value|"\020\10SOS\7ENSS\6BLKBIP\5DISFS\4BLKBIPO"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPCTRL
value|"TPOP Control/Diagnostic"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPCTRL
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPCTRL_EXCFS
value|0x80
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPCTRL_DB3
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPCTRL_PAIS
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPCTRL_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TPOPCTRL
value|"\020\2DB3\1PAIS"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TPOPCTRL_622
value|"\020\4EXCFS\2DB3\1PAIS"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPPTRC
value|"TPOP Pointer Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPPTRC
value|0x41
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPPTRC_FTPTR
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPPTRC_SOS
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPPTRC_PLD
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPPTRC_NDF
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPPTRC_NSE
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPPTRC_PSE
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPPTRC_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TPOPPTRC
value|"\020\7FTPTR\6SOS\5PLD\4NDF\3NSE\2PSE"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPCP
value|"TPOP Current Pointer"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPCP
value|0x43
end_define

begin_comment
comment|/* +44 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPCP
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TPOPCP
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TPOPCP
value|"\020"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPAPTR
value|"TPOP Arbitrary Pointer"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPAPTR
value|0x45
end_define

begin_comment
comment|/* +46 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPAPTR_NDF
value|0xF0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TPOPAPTR_NDF
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPAPTR_S
value|0x0C
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TPOPAPTR_S
value|2
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPAPTR
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TPOPAPTR
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TPOPAPTR
value|"\020\12\x0C\12S\12\xF0\12NDF"
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SONET
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SDH
value|2
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPPT
value|"TPOP Path Trace"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPPT
value|0x47
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPPSL
value|"TPOP Path Signal Label"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPPSL
value|0x48
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPSTATUS
value|"TPOP Path Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPSTATUS
value|0x49
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPSTATUS_FEBE
value|0xF0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TPOPSTATUS_FEBE
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPSTATUS_PRDI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TPOPSTATUS_G1
value|0x07
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TPOPSTATUS_G1
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TPOPSTATUS
value|"\020\12\xF0\12FEBE\4PRDI\12\x7\12G"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPPUC
value|"TPOP Path User Channel"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPPUC
value|0x4A
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPPG1
value|"TPOP Path Grow #1"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPPG1
value|0x4B
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPPG2
value|"TPOP Path Grow #2"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPPG2
value|0x4C
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TPOPPG3
value|"TPOP Path Grow #3"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TPOPPG3
value|0x4D
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPCTRL
value|"RACP Control/Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPCTRL
value|0x50
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_OOCDV
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_FSEN
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_RXPTYP
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_PASS
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_DISCOR
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_HCSPASS
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_HCSADD
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_DDSCR
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCTRL_FIFORST
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPCTRL
value|"\020\10OOCDV\7RXPTYP\6PASS\5DISCO\4HCSPASS\3HCSADD\2DDSCR\1FIFORST"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPCTRL_622
value|"\020\10FSEN\7RXPTYP\6PASS\5DISCO\4HCSPASS\3HCSADD\2DDSCR\1FIFORST"
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPINTR
value|"RACP Interrupt Enable/Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPINTR
value|0x51
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPINTR_OOCDE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPINTR_HCSE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPINTR_FIFOE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPINTR_OOCDI
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPINTR_CHCSI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPINTR_UHCSI
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPINTR_FOVRI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPINTR
value|"\020\10OOCDE\7HCSE\6FIFOE\5OOCDI\4CHCSI\3UHCSI\2FOVRI"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPIS
value|"RACP Interrupt Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPIS
value|0x51
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIS_OCDV
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIS_LCDV
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIS_OCDI
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIS_LCDI
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIS_CHCSI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIS_UHCSI
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIS_FOVRI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIS_FUDRI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPIS
value|"\020\10OCDV\7LCDV\6OCDI\5LCDI\4CHCSI\3UHCSI\2FOVRI\1FUDRI"
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPPATTERN
value|"RACP Match Header Pattern"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPPATTERN
value|0x52
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPPATTERN_GFC
value|0xF0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RACPPATTERN_GFC
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPPATTERN_PTI
value|0x0E
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RACPPATTERN_PTI
value|1
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPPATTERN_CLP
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RACPPATTERN_CLP
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPPATTERN
value|"\020\12\xF0\12GFC\12\x0E\12PTI\1CLP"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPIEC
value|"RACP Interrupt Enable/Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPIEC
value|0x52
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIEC_OCDE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIEC_LCDE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIEC_HCSE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIEC_FIFOE
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIEC_LCDDROP
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIEC_RCALEVEL0
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPIEC_HCSFTR
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPIEC
value|"\020\10OCDE\7LCDE\6HCSE\5FIFOE\4LCDDROP\3RCALEVEL0\12\0x3\12HCSFTR"
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPMASK
value|"RACP Match Header Mask"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPMASK
value|0x53
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPMASK_MGFC
value|0xF0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RACPMASK_MGFC
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPMASK_MPTI
value|0x0E
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RACPMASK_MPTI
value|1
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPMASK_MCLP
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RACPMASK_MCLP
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPMASK
value|"\020\12\xF0\12MGFC\12\x0E\12MPTI\1MCLP"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGO_RACPPATTERN_622
value|0x53
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPCHCS
value|"RACP Correctable HCS Error Count"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPCHCS
value|0x54
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGO_RACPMASK_622
value|0x54
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPUHCS
value|"RACP Uncorrectable HCS Error Count"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPUHCS
value|0x55
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGO_RACPCHCS_622
value|0x55
end_define

begin_comment
comment|/* +56 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCHCS_622
value|0x0f
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPCNT
value|"RACP Receive Cell Counter"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPCNT
value|0x56
end_define

begin_comment
comment|/* +57,58 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCNT
value|0x07
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGO_RACPUHCS_622
value|0x57
end_define

begin_comment
comment|/* +58 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_RACPUHCS_622
value|0x0f
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGO_RACPCNT_622
value|0x59
end_define

begin_comment
comment|/* +5A,5B */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCNT_622
value|0x1F
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPCFG
value|"RACP Configuration"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPCFG
value|0x59
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCFG_RGFCE
value|0xF0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RACPCFG_RGFCE
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCFG_FSEN
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCFG_LEVEL0
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPCFG_HCSFTR
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_RACPCFG_HCSFTR
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPCFG
value|"\020\12\xF0\20RGFCE\4FSEN\3RCALEVEL0\12\x03\12HCSFTR"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_RACPGFC
value|"RACP GFC Control/Misc. Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_RACPGFC
value|0x5C
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPGFC_CDDIS
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPGFC_RXBYTEPRTY
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_RACPGFC_RGFCE
value|0x0f
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_RACPGFC
value|"\020\10CDDIS\7RXBYTEPRTY\12\xf\20"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TACPCTRL
value|"TACP Control/Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPCTRL
value|0x60
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCTRL_FIFOE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCTRL_TSOCI
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCTRL_FOVRI
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCTRL_DHCS
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCTRL_HCSB
value|0x08
end_define

begin_comment
comment|/* ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCTRL_HCSADD
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCTRL_DSCR
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCTRL_FIFORST
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TACPCTRL_LITE
value|"\020\10FIFOE\7TSOCI\6FOVRI\5DHCS\3HCSADD\2DSCR\1FIFORST"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TACPCTRL_ULTRA
value|"\020\10FIFOE\7TSOCI\6FOVRI\5DHCS\4HCSB\3HCSADD\2DSCR\1FIFORST"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TACPCTRL_622
value|"\020\10FIFOE\7TSOCI\6FOVRI\5DHCS\4HCSB\3HCSADD\2DSCR\1FIFORST"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TACPIDLEH
value|"TACP Idle/Unassigned Cell Header Pattern"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPIDLEH
value|0x61
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPIDLEH_GFC
value|0xF0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPIDLEH_GFC
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPIDLEH_PTI
value|0x0E
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPIDLEH_PTI
value|1
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPIDLEH_CLP
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPIDLEH_CLP
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TACPIDLEH
value|"\020\12\xF0\20GFC\12\x0E\20PTI\12\x01\20CLP"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TACPIDLEP
value|"TACP Idle/Unassigned Cell Payload Octet Pattern"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPIDLEP
value|0x62
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TACPFIFOC
value|"TACP FIFO Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPFIFOC
value|0x63
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPFIFOC_TXPTYP
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPFIFOC_TXPRTYE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPFIFOC_TXPRTYI
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPFIFOC_TXPRTYI_622
value|0x30
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPFIFOC_TXPRTYI_622
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPFIFOC_FIFODP
value|0x0C
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPFIFOC_FIFODP
value|2
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPFIFOC_TCALEVEL0
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPFIFOC_HCSCTLEB
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPFIFOC_RESERVED
value|0x00
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TACPFIFOC
value|"\020\10TXPTYP\7TXPRTYE\5TXPRTYI\12\x0C\20FIFODP\2TCALEVEL0"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TACPFIFOC_622
value|"\020\10TXPTYP\7TXPRTYE\12\x30\12TXPRTYI\12\x0C\20FIFODP\2TCALEVEL0\1HCSCTLEB"
end_define

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TACPCNT
value|"TACP Transmit Cell Counter"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPCNT
value|0x64
end_define

begin_comment
comment|/* +65,66 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCNT
value|0x07
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCNT_622
value|0x1F
end_define

begin_comment
comment|/* lite, ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TACPCFG
value|"TACP Configuration"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPCFG
value|0x67
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCFG_TGFCE
value|0xF0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPCFG_TGFCE
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCFG_FSEN
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCFG_H4INSB
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_TACPCFG_FIXBYTE
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPCFG_FIXBYTE
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TACPCFG
value|"\020\12\xF0\20TGFCE\4FSEN\3H4INSB\12\x03\20FIXBYTE"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_TACPGFC
value|"TACP Fixed Stuff/GFC"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPGFC
value|0x67
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPGFC_TGFCE
value|0xf0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPGFC_TGFCE
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPGFC_FSEN
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPGFC_TXBYTEPRTY
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_TACPGFC_FIXBYTE
value|0x03
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_TACPGFC_FIXBYTE
value|0
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_TACPGFC
value|"\020\12\xf0\20TGFCE\4FSEN\3TXBYTEPRTY\12\x3\20FIXBYTE"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SPTBCTRL
value|"SPTB Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBCTRL
value|0x68
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBCTRL_RRAMACC
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBCTRL_RTIUIE
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBCTRL_RTIMIE
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBCTRL_PER5
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBCTRL_TNULL
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBCTRL_NOSYNC
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBCTRL_LEN16
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_SPTBCTRL
value|"\020\7RRAMACC\6RTIUIE\5RTIMIE\4PER5\3TNULL\2NOSYNC\1LEN16"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SPTBPTIS
value|"SPTB Path Trace Identifier Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBPTIS
value|0x69
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPTIS_BUSY
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPTIS_RTIUI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPTIS_RTIUV
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPTIS_RTIMI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPTIS_RTIMV
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_SPTBPTIS
value|"\020\10BUSY\4RTIUI\3RTIUV\2RTIMI\1RTIMV"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SPTBIAR
value|"SPTB Indirect Address Register"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBIAR
value|0x6A
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBIAR_RWB
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBIAR_A
value|0x7f
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_SPTBIAR
value|"\020\10RWB\12\x7f\20A"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SPTBIDR
value|"SPTB Indirect Data Register"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBIDR
value|0x6B
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SPTBEPSL
value|"SPTB Expected Path Signal Label"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBEPSL
value|0x6C
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_SPTBPSLS
value|"SPTB Path Signal Label Status"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_SPTBPSLS
value|0x6D
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPSLS_RPSLUIE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPSLS_RPSLMIE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPSLS_RPSLUI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPSLS_RPSLUV
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPSLS_RPSLMI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_SPTBPSLS_RPSLMV
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_SPTBPSLS
value|"\020\10RPSLUIE\7RPSLMIE\4RPSLUI\3RPSLUV\2RPSLMI\1RPSLMV"
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_POPCCTRL
value|"POPC Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_POPCCTRL
value|0x68
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_POPCCTRL_PDAT
value|0xC0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_POPCCTRL_PDAT
value|6
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_POPCCTRL_TOGGLE
value|0x30
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_POPCCTRL_TOGGLE
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_POPCCTRL_TRAFFIC
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_POPCCTRL_ALARM
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_POPCCTRL
value|"\020\12\xC0\20PDAT\12\x30\20TOGGLE\2TRAFFIC\1ALARM"
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_POPCSTROBE0
value|"POPC Strobe Rate 0"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_POPCSTROBE0
value|0x69
end_define

begin_comment
comment|/* ultra */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_POPCSTROBE1
value|"POPC Strobe Rate 1"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_POPCSTROBE1
value|0x6A
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_BERMCTRL
value|"BERM Control"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_BERMCTRL
value|0x70
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_BERMCTRL_BERTEN
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_BERMCTRL_BERIE
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_BERMCTRL
value|"\020\10BERTEN\1BERIE"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_BERMINT
value|"BERM Interrupt"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_BERMINT
value|0x71
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_BERMINT_TST
value|0xf0
end_define

begin_define
define|#
directive|define
name|SUNI_REGS_BERMINT_TST
value|4
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_BERMINT_BERI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_BERMINT
value|"\020\12\xf0\20BERM_TST\1BERI"
end_define

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_BERMLAP
value|"BERM Line BIP Accumulation Period"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_BERMLAP
value|0x72
end_define

begin_comment
comment|/* +73 */
end_comment

begin_comment
comment|/* 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_BERMLT
value|"BERM Line BIP Threshold"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_BERMLT
value|0x74
end_define

begin_comment
comment|/* +75 */
end_comment

begin_comment
comment|/* lite, ultra, 622 */
end_comment

begin_define
define|#
directive|define
name|SUNI_REGN_MTEST
value|"Master Test"
end_define

begin_define
define|#
directive|define
name|SUNI_REGO_MTEST
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MTEST_DS27_53_622
value|0x80
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MTEST_BYPASS_ULTRA
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MTEST_PMCATST_ULTRA
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MTEST_PMCTST
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MTEST_DBCTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MTEST_IOTST
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MTEST_HIZDATA
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_REGM_MTEST_HIZIO
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MTEST_LITE
value|"\020\5PMCTST\4DBCTRL\3IOTST\2HIZDATA\1HIZIO"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MTEST_ULTRA
value|"\020\7BYPASS\6PMCATST\5PMCTST\4DBCTRL\3IOTST\2HIZDATA\1HIZIO"
end_define

begin_define
define|#
directive|define
name|SUNI_REGX_MTEST_622
value|"\020\10DS27_53\5PMCTST\4DBCTRL\3IOTST\2HIZDATA\1HIZIO"
end_define

begin_comment
comment|/*  * Printing support  */
end_comment

begin_define
define|#
directive|define
name|SUNI_PRINT_LITE
define|\
value|{
comment|/* 00 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MRESET, 			\ 	  SUNI_REGN_MRESET,	SUNI_REGX_MRESET_LITE },		\ 	{
comment|/* 01 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MCONFIG,			\ 	  SUNI_REGN_MCONFIG,	SUNI_REGX_MCONFIG_LITE },		\ 	{
comment|/* 02 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MISTATUS,			\ 	  SUNI_REGN_MISTATUS,	SUNI_REGX_MISTATUS_LITE },		\
comment|/* 03 unused */
value|\ 	{
comment|/* 04 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MCLKM,			\ 	  SUNI_REGN_MCLKM,	SUNI_REGX_MCLKM_LITE },			\ 	{
comment|/* 05 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MCTRL,			\ 	  SUNI_REGN_MCTRL,	SUNI_REGX_MCTRL_LITE },			\ 	{
comment|/* 06 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_CLKSYN,			\ 	  SUNI_REGN_CLKSYN,	SUNI_REGX_CLKSYN_LITE },		\ 	{
comment|/* 07 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_CLKREC_LITE,			\ 	  SUNI_REGN_CLKREC,	SUNI_REGX_CLKREC_LITE },		\
comment|/* 08-0F unused */
value|\ 	{
comment|/* 10 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RSOPCIE,			\ 	  SUNI_REGN_RSOPCIE,	SUNI_REGX_RSOPCIE },			\ 	{
comment|/* 11 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RSOPSIS,			\ 	  SUNI_REGN_RSOPSIS,	SUNI_REGX_RSOPSIS },			\ 	{
comment|/* 12, 13 */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RSOP_BIP8,			\ 	  SUNI_REGN_RSOP_BIP8,	NULL },					\ 	{
comment|/* 14 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TSOPCTRL,			\ 	  SUNI_REGN_TSOPCTRL,	SUNI_REGX_TSOPCTRL },			\ 	{
comment|/* 15 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TSOPDIAG,			\ 	  SUNI_REGN_TSOPDIAG,	SUNI_REGX_TSOPDIAG },			\
comment|/* 16-17 unused */
value|\ 	{
comment|/* 18 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RLOPCTRL,			\ 	  SUNI_REGN_RLOPCTRL,	SUNI_REGX_RLOPCTRL },			\ 	{
comment|/* 19 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RLOPINTR,			\ 	  SUNI_REGN_RLOPINTR,	SUNI_REGX_RLOPINTR },			\ 	{
comment|/* 1A, 1B, 1C */
value|\ 	  UTP_REGT_INT20,	SUNI_REGO_RLOPBIP8_24,			\ 	  SUNI_REGN_RLOPBIP8_24, NULL },				\ 	{
comment|/* 1D, 1E, 1F */
value|\ 	  UTP_REGT_INT20,	SUNI_REGO_RLOPFEBE,			\ 	  SUNI_REGN_RLOPFEBE,	NULL },					\ 	{
comment|/* 20 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TLOPCTRL,			\ 	  SUNI_REGN_TLOPCTRL,	SUNI_REGX_TLOPCTRL },			\ 	{
comment|/* 21 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TLOPDIAG,			\ 	  SUNI_REGN_TLOPDIAG,	SUNI_REGX_TLOPDIAG },			\
comment|/* 22-2F unused */
value|\ 	{
comment|/* 30 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPCTRL,			\ 	  SUNI_REGN_RPOPCTRL,	SUNI_REGX_RPOPCTRL },			\ 	{
comment|/* 31 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPISTAT,			\ 	  SUNI_REGN_RPOPISTAT,	SUNI_REGX_RPOPISTAT },			\
comment|/* 32 unused */
value|\ 	{
comment|/* 33 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPIEN,			\ 	  SUNI_REGN_RPOPIEN,	SUNI_REGX_RPOPIEN },			\
comment|/* 34-36 unused */
value|\ 	{
comment|/* 37 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RPOPPSL,			\ 	  SUNI_REGN_RPOPPSL,	NULL },					\ 	{
comment|/* 38, 39 */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RPOPBIP8,			\ 	  SUNI_REGN_RPOPBIP8,	NULL },					\ 	{
comment|/* 3A, 3B */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RPOPFEBE,			\ 	  SUNI_REGN_RPOPFEBE,	NULL },					\
comment|/* 3C unused */
value|\ 	{
comment|/* 3D */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPBIP8CFG,			\ 	  SUNI_REGN_RPOPBIP8CFG, SUNI_REGX_RPOPBIP8CFG },		\
comment|/* 3E-3F unused */
value|\ 	{
comment|/* 40 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPCTRL,			\ 	  SUNI_REGN_TPOPCTRL,	SUNI_REGX_TPOPCTRL },			\ 	{
comment|/* 41 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPPTRC,			\ 	  SUNI_REGN_TPOPPTRC,	SUNI_REGX_TPOPPTRC },			\
comment|/* 42-44 unused */
value|\ 	{
comment|/* 45, 46 */
value|\ 	  UTP_REGT_INT10BITS,	SUNI_REGO_TPOPAPTR,			\ 	  SUNI_REGN_TPOPAPTR,	SUNI_REGX_TPOPAPTR },			\
comment|/* 47 unused */
value|\ 	{
comment|/* 48 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TPOPPSL,			\ 	  SUNI_REGN_TPOPPSL,	NULL },					\ 	{
comment|/* 49 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPSTATUS,			\ 	  SUNI_REGN_TPOPSTATUS,	SUNI_REGX_TPOPSTATUS },			\
comment|/* 4A-4F unused */
value|\ 	{
comment|/* 50 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPCTRL,			\ 	  SUNI_REGN_RACPCTRL,	SUNI_REGX_RACPCTRL },			\ 	{
comment|/* 51 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPINTR,			\ 	  SUNI_REGN_RACPINTR,	SUNI_REGX_RACPINTR },			\ 	{
comment|/* 52 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPPATTERN,			\ 	  SUNI_REGN_RACPPATTERN, SUNI_REGX_RACPPATTERN },		\ 	{
comment|/* 53 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPMASK,			\ 	  SUNI_REGN_RACPMASK,	SUNI_REGX_RACPMASK },			\ 	{
comment|/* 54 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RACPCHCS,			\ 	  SUNI_REGN_RACPCHCS,	NULL },					\ 	{
comment|/* 55 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RACPUHCS,			\ 	  SUNI_REGN_RACPUHCS,	NULL },					\ 	{
comment|/* 56, 57, 58 */
value|\ 	  UTP_REGT_INT19,	SUNI_REGO_RACPCNT,			\ 	  SUNI_REGN_RACPCNT,	NULL },					\ 	{
comment|/* 59 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPCFG,			\ 	  SUNI_REGN_RACPCFG,	SUNI_REGX_RACPCFG },			\
comment|/* 5A-5F unused */
value|\ 	{
comment|/* 60 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPCTRL,			\ 	  SUNI_REGN_TACPCTRL,	SUNI_REGX_TACPCTRL_LITE },		\ 	{
comment|/* 61 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPIDLEH,			\ 	  SUNI_REGN_TACPIDLEH,	SUNI_REGX_TACPIDLEH },			\ 	{
comment|/* 62 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TACPIDLEP,			\ 	  SUNI_REGN_TACPIDLEP,	NULL },					\ 	{
comment|/* 63 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPFIFOC,			\ 	  SUNI_REGN_TACPFIFOC,	SUNI_REGX_TACPFIFOC },			\ 	{
comment|/* 64, 65, 66 */
value|\ 	  UTP_REGT_INT19,	SUNI_REGO_TACPCNT,			\ 	  SUNI_REGN_TACPCNT,	NULL },					\ 	{
comment|/* 67 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPGFC,			\ 	  SUNI_REGN_TACPGFC,	SUNI_REGX_TACPGFC },			\
comment|/* 68-7f unused */
value|\ 	{
comment|/* 80 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MTEST,			\ 	  SUNI_REGN_MTEST,	SUNI_REGX_MTEST_LITE }
end_define

begin_define
define|#
directive|define
name|SUNI_PRINT_ULTRA
define|\
value|{
comment|/* 00 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MRESET, 			\ 	  SUNI_REGN_MRESET,	SUNI_REGX_MRESET_ULTRA },		\ 	{
comment|/* 01 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MCONFIG,			\ 	  SUNI_REGN_MCONFIG,	SUNI_REGX_MCONFIG_ULTRA },		\ 	{
comment|/* 02 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MISTATUS,			\ 	  SUNI_REGN_MISTATUS,	SUNI_REGX_MISTATUS_ULTRA },		\ 	{
comment|/* 03 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MMCTRL,			\ 	  SUNI_REGN_MMCTRL,	SUNI_REGX_MMCTRL },			\ 	{
comment|/* 04 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MCLKM,			\ 	  SUNI_REGN_MCLKM,	SUNI_REGX_MCLKM_ULTRA },		\ 	{
comment|/* 05 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MCTRL,			\ 	  SUNI_REGN_MCTRL,	SUNI_REGX_MCTRL_ULTRA },		\ 	{
comment|/* 06 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_CLKSYN,			\ 	  SUNI_REGN_CLKSYN,	SUNI_REGX_CLKSYN_ULTRA },		\
comment|/* 07 unused */
value|\ 	{
comment|/* 08 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_CLKREC_ULTRA,			\ 	  SUNI_REGN_CLKREC,	SUNI_REGX_CLKREC_ULTRA },		\ 	{
comment|/* 09 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_CLKRECCFG,			\ 	  SUNI_REGN_CLKRECCFG,	SUNI_REGX_CLKRECCFG },			\ 	{
comment|/* 0A */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_LTXCFG1,			\ 	  SUNI_REGN_LTXCFG1,	SUNI_REGX_LTXCFG1 },			\ 	{
comment|/* 0B */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_LTXCFG2,			\ 	  SUNI_REGN_LTXCFG2,	SUNI_REGX_LTXCFG2 },			\ 	{
comment|/* 0C */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_LRXCFG,			\ 	  SUNI_REGN_LRXCFG,	SUNI_REGX_LRXCFG },			\
comment|/* 0D-0F unused */
value|\ 	{
comment|/* 10 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RSOPCIE,			\ 	  SUNI_REGN_RSOPCIE,	SUNI_REGX_RSOPCIE },			\ 	{
comment|/* 11 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RSOPSIS,			\ 	  SUNI_REGN_RSOPSIS,	SUNI_REGX_RSOPSIS },			\ 	{
comment|/* 12, 13 */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RSOP_BIP8,			\ 	  SUNI_REGN_RSOP_BIP8,	NULL },					\ 	{
comment|/* 14 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TSOPCTRL,			\ 	  SUNI_REGN_TSOPCTRL,	SUNI_REGX_TSOPCTRL },			\ 	{
comment|/* 15 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TSOPDIAG,			\ 	  SUNI_REGN_TSOPDIAG,	SUNI_REGX_TSOPDIAG },			\
comment|/* 16-17 unused */
value|\ 	{
comment|/* 18 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RLOPCTRL,			\ 	  SUNI_REGN_RLOPCTRL,	SUNI_REGX_RLOPCTRL },			\ 	{
comment|/* 19 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RLOPINTR,			\ 	  SUNI_REGN_RLOPINTR,	SUNI_REGX_RLOPINTR },			\ 	{
comment|/* 1A, 1B, 1C */
value|\ 	  UTP_REGT_INT20,	SUNI_REGO_RLOPBIP8_24,			\ 	  SUNI_REGN_RLOPBIP8_24, NULL },				\ 	{
comment|/* 1D, 1E, 1F */
value|\ 	  UTP_REGT_INT20,	SUNI_REGO_RLOPFEBE,			\ 	  SUNI_REGN_RLOPFEBE,	NULL },					\ 	{
comment|/* 20 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TLOPCTRL,			\ 	  SUNI_REGN_TLOPCTRL,	SUNI_REGX_TLOPCTRL },			\ 	{
comment|/* 21 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TLOPDIAG,			\ 	  SUNI_REGN_TLOPDIAG,	SUNI_REGX_TLOPDIAG },			\
comment|/* 22-2F unused */
value|\ 	{
comment|/* 30 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPCTRL,			\ 	  SUNI_REGN_RPOPCTRL,	SUNI_REGX_RPOPCTRL },			\ 	{
comment|/* 31 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPISTAT,			\ 	  SUNI_REGN_RPOPISTAT,	SUNI_REGX_RPOPISTAT },			\
comment|/* 32 unused */
value|\ 	{
comment|/* 33 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPIEN,			\ 	  SUNI_REGN_RPOPIEN,	SUNI_REGX_RPOPIEN },			\
comment|/* 34-36 unused */
value|\ 	{
comment|/* 37 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RPOPPSL,			\ 	  SUNI_REGN_RPOPPSL,	NULL },					\ 	{
comment|/* 38, 39 */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RPOPBIP8,			\ 	  SUNI_REGN_RPOPBIP8,	NULL },					\ 	{
comment|/* 3A, 3B */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RPOPFEBE,			\ 	  SUNI_REGN_RPOPFEBE,	NULL },					\
comment|/* 3C unused */
value|\ 	{
comment|/* 3D */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPBIP8CFG,			\ 	  SUNI_REGN_RPOPBIP8CFG, SUNI_REGX_RPOPBIP8CFG },		\
comment|/* 3E-3F unused */
value|\ 	{
comment|/* 40 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPCTRL,			\ 	  SUNI_REGN_TPOPCTRL,	SUNI_REGX_TPOPCTRL },			\ 	{
comment|/* 41 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPPTRC,			\ 	  SUNI_REGN_TPOPPTRC,	SUNI_REGX_TPOPPTRC },			\
comment|/* 42-44 unused */
value|\ 	{
comment|/* 45, 46 */
value|\ 	  UTP_REGT_INT10BITS,	SUNI_REGO_TPOPAPTR,			\ 	  SUNI_REGN_TPOPAPTR,	SUNI_REGX_TPOPAPTR },			\
comment|/* 47 unused */
value|\ 	{
comment|/* 48 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TPOPPSL,			\ 	  SUNI_REGN_TPOPPSL,	NULL },					\ 	{
comment|/* 49 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPSTATUS,			\ 	  SUNI_REGN_TPOPSTATUS,	SUNI_REGX_TPOPSTATUS },			\
comment|/* 4A-4F unused */
value|\ 	{
comment|/* 50 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPCTRL,			\ 	  SUNI_REGN_RACPCTRL,	SUNI_REGX_RACPCTRL },			\ 	{
comment|/* 51 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPINTR,			\ 	  SUNI_REGN_RACPINTR,	SUNI_REGX_RACPINTR },			\ 	{
comment|/* 52 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPPATTERN,			\ 	  SUNI_REGN_RACPPATTERN, SUNI_REGX_RACPPATTERN },		\ 	{
comment|/* 53 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPMASK,			\ 	  SUNI_REGN_RACPMASK,	SUNI_REGX_RACPMASK },			\ 	{
comment|/* 54 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RACPCHCS,			\ 	  SUNI_REGN_RACPCHCS,	NULL },					\ 	{
comment|/* 55 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RACPUHCS,			\ 	  SUNI_REGN_RACPUHCS,	NULL },					\ 	{
comment|/* 56, 57, 58 */
value|\ 	  UTP_REGT_INT19,	SUNI_REGO_RACPCNT,			\ 	  SUNI_REGN_RACPCNT,	NULL },					\ 	{
comment|/* 59 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPCFG,			\ 	  SUNI_REGN_RACPCFG,	SUNI_REGX_RACPCFG },			\
comment|/* 5A-5F unused */
value|\ 	{
comment|/* 60 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPCTRL,			\ 	  SUNI_REGN_TACPCTRL,	SUNI_REGX_TACPCTRL_ULTRA },		\ 	{
comment|/* 61 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPIDLEH,			\ 	  SUNI_REGN_TACPIDLEH,	SUNI_REGX_TACPIDLEH },			\ 	{
comment|/* 62 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TACPIDLEP,			\ 	  SUNI_REGN_TACPIDLEP,	NULL },					\ 	{
comment|/* 63 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPFIFOC,			\ 	  SUNI_REGN_TACPFIFOC,	SUNI_REGX_TACPFIFOC },			\ 	{
comment|/* 64, 65, 66 */
value|\ 	  UTP_REGT_INT19,	SUNI_REGO_TACPCNT,			\ 	  SUNI_REGN_TACPCNT,	NULL },					\ 	{
comment|/* 67 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPGFC,			\ 	  SUNI_REGN_TACPGFC,	SUNI_REGX_TACPGFC },			\ 	{
comment|/* 68 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_POPCCTRL,			\ 	  SUNI_REGN_POPCCTRL,	SUNI_REGX_POPCCTRL },			\ 	{
comment|/* 69 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_POPCSTROBE0,			\ 	  SUNI_REGN_POPCSTROBE0, NULL },				\ 	{
comment|/* 6A */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_POPCSTROBE1,			\ 	  SUNI_REGN_POPCSTROBE1, NULL },				\
comment|/* 6B-7f unused */
value|\ 	{
comment|/* 80 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MTEST,			\ 	  SUNI_REGN_MTEST,	SUNI_REGX_MTEST_ULTRA }
end_define

begin_define
define|#
directive|define
name|SUNI_PRINT_622
define|\
value|{
comment|/* 00 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MRESET, 			\ 	  SUNI_REGN_MRESET,	SUNI_REGX_MRESET_622 },			\ 	{
comment|/* 01 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MCONFIG,			\ 	  SUNI_REGN_MCONFIG,	SUNI_REGX_MCONFIG_622 },		\ 	{
comment|/* 02 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MISTATUS,			\ 	  SUNI_REGN_MISTATUS,	SUNI_REGX_MISTATUS_622 },		\ 	{
comment|/* 03 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_PISO, 			\ 	  SUNI_REGN_PISO,	SUNI_REGX_PISO },			\ 	{
comment|/* 04 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MCTRLM, 			\ 	  SUNI_REGN_MCTRLM,	SUNI_REGX_MCTRLM },			\ 	{
comment|/* 05 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MALARM,			\ 	  SUNI_REGN_MALARM,	SUNI_REGX_MALARM },			\ 	{
comment|/* 06 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_POUT,				\ 	  SUNI_REGN_POUT,	SUNI_REGX_POUT },			\ 	{
comment|/* 07 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_PIN,				\ 	  SUNI_REGN_PIN,	NULL },					\ 	{
comment|/* 08 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_PINV,				\ 	  SUNI_REGN_PINV,	SUNI_REGX_PINV },			\ 	{
comment|/* 09 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_PINE,				\ 	  SUNI_REGN_PINE,	NULL },					\ 	{
comment|/* 0A */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_XC1,				\ 	  SUNI_REGN_XC1,	NULL },					\ 	{
comment|/* 0B */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_APSCS,			\ 	  SUNI_REGN_APSCS,	SUNI_REGX_APSCS },			\ 	{
comment|/* 0C */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RK1,				\ 	  SUNI_REGN_RK1,	NULL },					\ 	{
comment|/* 0D */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RK2,				\ 	  SUNI_REGN_RK2,	NULL },					\ 	{
comment|/* 0E */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RZ1,				\ 	  SUNI_REGN_RZ1,	NULL },					\ 	{
comment|/* 0F */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_XZ1,				\ 	  SUNI_REGN_XZ1,	NULL },					\ 	{
comment|/* 10 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RSOPCIE,			\ 	  SUNI_REGN_RSOPCIE,	SUNI_REGX_RSOPCIE_622 },		\ 	{
comment|/* 11 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RSOPSIS,			\ 	  SUNI_REGN_RSOPSIS,	SUNI_REGX_RSOPSIS },			\ 	{
comment|/* 12, 13 */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RSOP_BIP8,			\ 	  SUNI_REGN_RSOP_BIP8,	NULL },					\ 	{
comment|/* 14 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TSOPCTRL,			\ 	  SUNI_REGN_TSOPCTRL,	SUNI_REGX_TSOPCTRL },			\ 	{
comment|/* 15 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TSOPDIAG,			\ 	  SUNI_REGN_TSOPDIAG,	SUNI_REGX_TSOPDIAG },			\
comment|/* 16-17 unused */
value|\ 	{
comment|/* 18 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RLOPCTRL,			\ 	  SUNI_REGN_RLOPCTRL,	SUNI_REGX_RLOPCTRL_622 },		\ 	{
comment|/* 19 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RLOPINTR,			\ 	  SUNI_REGN_RLOPINTR,	SUNI_REGX_RLOPINTR },			\ 	{
comment|/* 1A, 1B, 1C */
value|\ 	  UTP_REGT_INT20,	SUNI_REGO_RLOPBIP8_24_96,		\ 	  SUNI_REGN_RLOPBIP8_24_96, NULL },				\ 	{
comment|/* 1D, 1E, 1F */
value|\ 	  UTP_REGT_INT20,	SUNI_REGO_RLOPFEBE,			\ 	  SUNI_REGN_RLOPFEBE,	NULL },					\ 	{
comment|/* 20 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TLOPCTRL,			\ 	  SUNI_REGN_TLOPCTRL,	SUNI_REGX_TLOPCTRL_622 },		\ 	{
comment|/* 21 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TLOPDIAG,			\ 	  SUNI_REGN_TLOPDIAG,	SUNI_REGX_TLOPDIAG },			\ 	{
comment|/* 22 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TLOP_XK1,			\ 	  SUNI_REGN_TLOP_XK1,	NULL },					\ 	{
comment|/* 23 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TLOP_XK2,			\ 	  SUNI_REGN_TLOP_XK2,	NULL },					\
comment|/* 24-27 unused */
value|\ 	{
comment|/* 28 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_SSTBCTRL,			\ 	  SUNI_REGN_SSTBCTRL,	SUNI_REGX_SSTBCTRL },			\ 	{
comment|/* 29 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_SSTBSTIS,			\ 	  SUNI_REGN_SSTBSTIS,	SUNI_REGX_SSTBSTIS },			\ 	{
comment|/* 2A */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_SSTBIAR,			\ 	  SUNI_REGN_SSTBIAR,	SUNI_REGX_SSTBIAR },			\ 	{
comment|/* 2B */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_SSTBIDR,			\ 	  SUNI_REGN_SSTBIDR,	NULL },					\
comment|/* 2C unused (see chip errata) */
value|\ 	{
comment|/* 2D */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_SSTBCSMS,			\ 	  SUNI_REGN_SSTBCSMS,	SUNI_REGX_SSTBCSMS },			\
comment|/* 2E-2F unused */
value|\ 	{
comment|/* 30 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPCTRL,			\ 	  SUNI_REGN_RPOPCTRL,	SUNI_REGX_RPOPCTRL_622 },		\ 	{
comment|/* 31 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPISTAT,			\ 	  SUNI_REGN_RPOPISTAT,	SUNI_REGX_RPOPISTAT },			\ 	{
comment|/* 32 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPPIS,			\ 	  SUNI_REGN_RPOPPIS,	SUNI_REGX_RPOPPIS },			\ 	{
comment|/* 33 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPIEN,			\ 	  SUNI_REGN_RPOPIEN,	SUNI_REGX_RPOPIEN },			\ 	{
comment|/* 34 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPPIE,			\ 	  SUNI_REGN_RPOPPIE,	SUNI_REGX_RPOPPIE },			\ 	{
comment|/* 35, 36 */
value|\ 	  UTP_REGT_INT10BITS,	SUNI_REGO_RPOPPTR,			\ 	  SUNI_REGN_RPOPPTR,	SUNI_REGX_RPOPPTR },			\ 	{
comment|/* 37 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_RPOPPSL,			\ 	  SUNI_REGN_RPOPPSL,	NULL },					\ 	{
comment|/* 38, 39 */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RPOPBIP8,			\ 	  SUNI_REGN_RPOPBIP8,	NULL },					\ 	{
comment|/* 3A, 3B */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_RPOPFEBE,			\ 	  SUNI_REGN_RPOPFEBE,	NULL },					\ 	{
comment|/* 3C */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPRDI,			\ 	  SUNI_REGN_RPOPRDI,	SUNI_REGX_RPOPRDI },			\ 	{
comment|/* 3D */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RPOPRING,			\ 	  SUNI_REGN_RPOPRING,	SUNI_REGX_RPOPRING },			\
comment|/* 3E-3F unused */
value|\ 	{
comment|/* 40 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPCTRL,			\ 	  SUNI_REGN_TPOPCTRL,	SUNI_REGX_TPOPCTRL_622 },		\ 	{
comment|/* 41 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPPTRC,			\ 	  SUNI_REGN_TPOPPTRC,	SUNI_REGX_TPOPPTRC },			\
comment|/* 42 unused */
value|\ 	{
comment|/* 43, 44 */
value|\ 	  UTP_REGT_INT10BITS,	SUNI_REGO_TPOPCP,			\ 	  SUNI_REGN_TPOPCP,	SUNI_REGX_TPOPCP },			\ 	{
comment|/* 45, 46 */
value|\ 	  UTP_REGT_INT10BITS,	SUNI_REGO_TPOPAPTR,			\ 	  SUNI_REGN_TPOPAPTR,	SUNI_REGX_TPOPAPTR },			\ 	{
comment|/* 47 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TPOPPT,			\ 	  SUNI_REGN_TPOPPT,	NULL },					\ 	{
comment|/* 48 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TPOPPSL,			\ 	  SUNI_REGN_TPOPPSL,	NULL },					\ 	{
comment|/* 49 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TPOPSTATUS,			\ 	  SUNI_REGN_TPOPSTATUS,	SUNI_REGX_TPOPSTATUS },			\ 	{
comment|/* 4A */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TPOPPUC,			\ 	  SUNI_REGN_TPOPPUC,	NULL },					\ 	{
comment|/* 4B */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TPOPPG1,			\ 	  SUNI_REGN_TPOPPG1,	NULL },					\ 	{
comment|/* 4C */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TPOPPG2,			\ 	  SUNI_REGN_TPOPPG2,	NULL },					\ 	{
comment|/* 4D */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TPOPPG3,			\ 	  SUNI_REGN_TPOPPG3,	NULL },					\
comment|/* 4E-4F unused */
value|\ 	{
comment|/* 50 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPCTRL,			\ 	  SUNI_REGN_RACPCTRL,	SUNI_REGX_RACPCTRL_622 },		\ 	{
comment|/* 51 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPIS,			\ 	  SUNI_REGN_RACPIS,	SUNI_REGX_RACPIS },			\ 	{
comment|/* 52 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPIEC,			\ 	  SUNI_REGN_RACPIEC,	SUNI_REGX_RACPIEC },			\ 	{
comment|/* 53 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPPATTERN_622,		\ 	  SUNI_REGN_RACPPATTERN, SUNI_REGX_RACPPATTERN },		\ 	{
comment|/* 54 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPMASK_622,			\ 	  SUNI_REGN_RACPMASK,	SUNI_REGX_RACPMASK },			\ 	{
comment|/* 55, 56 */
value|\ 	  UTP_REGT_INT12,	SUNI_REGO_RACPCHCS_622,			\ 	  SUNI_REGN_RACPCHCS,	NULL },					\ 	{
comment|/* 57, 58 */
value|\ 	  UTP_REGT_INT12,	SUNI_REGO_RACPUHCS_622,			\ 	  SUNI_REGN_RACPUHCS,	NULL },					\ 	{
comment|/* 59, 5A, 5B */
value|\ 	  UTP_REGT_INT21,	SUNI_REGO_RACPCNT_622,			\ 	  SUNI_REGN_RACPCNT,	NULL },					\ 	{
comment|/* 5C */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_RACPGFC,			\ 	  SUNI_REGN_RACPGFC,	SUNI_REGX_RACPGFC },			\
comment|/* 5D-5F unused */
value|\ 	{
comment|/* 60 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPCTRL,			\ 	  SUNI_REGN_TACPCTRL,	SUNI_REGX_TACPCTRL_622 },		\ 	{
comment|/* 61 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPIDLEH,			\ 	  SUNI_REGN_TACPIDLEH,	SUNI_REGX_TACPIDLEH },			\ 	{
comment|/* 62 */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_TACPIDLEP,			\ 	  SUNI_REGN_TACPIDLEP,	NULL },					\ 	{
comment|/* 63 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPFIFOC,			\ 	  SUNI_REGN_TACPFIFOC,	SUNI_REGX_TACPFIFOC_622 },		\ 	{
comment|/* 64, 65, 66 */
value|\ 	  UTP_REGT_INT21,	SUNI_REGO_TACPCNT,			\ 	  SUNI_REGN_TACPCNT,	NULL },					\ 	{
comment|/* 67 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_TACPGFC,			\ 	  SUNI_REGN_TACPGFC,	SUNI_REGX_TACPGFC },			\ 	{
comment|/* 68 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_SPTBCTRL,			\ 	  SUNI_REGN_SPTBCTRL,	SUNI_REGX_SPTBCTRL },			\ 	{
comment|/* 69 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_SPTBPTIS,			\ 	  SUNI_REGN_SPTBPTIS,	SUNI_REGX_SPTBPTIS },			\ 	{
comment|/* 6A */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_SPTBIAR,			\ 	  SUNI_REGN_SPTBIAR,	SUNI_REGX_SPTBIAR },			\ 	{
comment|/* 6B */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_SPTBIDR,			\ 	  SUNI_REGN_SPTBIDR,	NULL },					\ 	{
comment|/* 6C */
value|\ 	  UTP_REGT_INT8,	SUNI_REGO_SPTBEPSL,			\ 	  SUNI_REGN_SPTBEPSL,	NULL },					\ 	{
comment|/* 6D */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_SPTBPSLS,			\ 	  SUNI_REGN_SPTBPSLS,	SUNI_REGX_SPTBPSLS },			\
comment|/* 6E-6F unused */
value|\ 	{
comment|/* 70 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_BERMCTRL,			\ 	  SUNI_REGN_BERMCTRL,	SUNI_REGX_BERMCTRL },			\ 	{
comment|/* 71 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_BERMINT,			\ 	  SUNI_REGN_BERMINT,	SUNI_REGX_BERMINT },			\ 	{
comment|/* 72, 73 */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_BERMLAP,			\ 	  SUNI_REGN_BERMLAP,	NULL },					\ 	{
comment|/* 74, 75 */
value|\ 	  UTP_REGT_INT16,	SUNI_REGO_BERMLT,			\ 	  SUNI_REGN_BERMLT,	NULL },					\
comment|/* 76-7f unused */
value|\ 	{
comment|/* 80 */
value|\ 	  UTP_REGT_BITS,	SUNI_REGO_MTEST,			\ 	  SUNI_REGN_MTEST,	SUNI_REGX_MTEST_622 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UTOPIA_SUNI_H */
end_comment

end_unit

