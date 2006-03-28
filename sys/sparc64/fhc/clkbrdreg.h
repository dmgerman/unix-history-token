begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Jason L. Wright (jason@thought.net)  * Copyright (c) 2006 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: OpenBSD: clkbrdreg.h,v 1.2 2004/10/01 15:36:30 jason Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_FHC_CLKBRDREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_FHC_CLKBRDREG_H_
end_define

begin_comment
comment|/* register bank 0 */
end_comment

begin_define
define|#
directive|define
name|CLK_CF_REG2
value|0x20
end_define

begin_comment
comment|/* clock frequency register 2 */
end_comment

begin_define
define|#
directive|define
name|CLK_CF_REG2_REN_RCONS
value|0x80
end_define

begin_comment
comment|/* reset enable: remote console */
end_comment

begin_define
define|#
directive|define
name|CLK_CF_REG2_REN_GEN
value|0x40
end_define

begin_comment
comment|/* reset enable: frequency change */
end_comment

begin_define
define|#
directive|define
name|CLK_CF_REG2_REN_WDOG
value|0x20
end_define

begin_comment
comment|/* reset enable: watchdog */
end_comment

begin_define
define|#
directive|define
name|CLK_CF_REG2_DIV1
value|0x10
end_define

begin_comment
comment|/* CPU module divisor bit 1 */
end_comment

begin_define
define|#
directive|define
name|CLK_CF_REG2_RANGE
value|0x0c
end_define

begin_comment
comment|/* clock range */
end_comment

begin_define
define|#
directive|define
name|CLK_CF_REG2_DIV0
value|0x02
end_define

begin_comment
comment|/* CPU module divisor bit 0 */
end_comment

begin_define
define|#
directive|define
name|CLK_CF_REG2_FREQ8
value|0x01
end_define

begin_comment
comment|/* frequency bit 8 */
end_comment

begin_comment
comment|/* register bank 1 */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL
value|0x00
end_define

begin_comment
comment|/* system control register */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_IEN_FAN
value|0x80
end_define

begin_comment
comment|/* intr enable: fan failure */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_IEN_DC
value|0x40
end_define

begin_comment
comment|/* intr enable: power supply DC */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_IEN_AC
value|0x20
end_define

begin_comment
comment|/* intr enable: AC power */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_IEN_BRD
value|0x10
end_define

begin_comment
comment|/* intr enable: board insert */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_POFF
value|0x08
end_define

begin_comment
comment|/* turn off system power */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_LLED
value|0x04
end_define

begin_comment
comment|/* left led (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_MLED
value|0x02
end_define

begin_comment
comment|/* middle led */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_RLED
value|0x01
end_define

begin_comment
comment|/* right led */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1
value|0x10
end_define

begin_comment
comment|/* system status register 1 */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_SLOTS_MASK
value|0xc0
end_define

begin_comment
comment|/* system status 1 slots mask */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_SLOTS_16
value|0x40
end_define

begin_comment
comment|/* 16 slots */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_SLOTS_8
value|0xc0
end_define

begin_comment
comment|/* 8 slots */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_SLOTS_4
value|0x80
end_define

begin_comment
comment|/* 4 slots */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_SLOTS_TESTBED
value|0x00
end_define

begin_comment
comment|/* test machine */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_SECURE
value|0x20
end_define

begin_comment
comment|/* key in position secure (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_FAN
value|0x10
end_define

begin_comment
comment|/* fan tray present (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_BRD
value|0x08
end_define

begin_comment
comment|/* board inserted (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_PS0
value|0x04
end_define

begin_comment
comment|/* power supply 0 present (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_RST_WDOG
value|0x02
end_define

begin_comment
comment|/* rst by: watchdog (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_STS1_RST_GEN
value|0x01
end_define

begin_comment
comment|/* rst by: freq change (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2
value|0x20
end_define

begin_comment
comment|/* system status register 2 */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2_RST_RCONS
value|0x80
end_define

begin_comment
comment|/* rst by: remote console (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2_OK_PS0
value|0x40
end_define

begin_comment
comment|/* ok: power supply 0 */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2_OK_33V
value|0x20
end_define

begin_comment
comment|/* ok: 3.3V on clock board */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2_OK_50V
value|0x10
end_define

begin_comment
comment|/* ok: 5.0V on clock board */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2_FAIL_AC
value|0x08
end_define

begin_comment
comment|/* failed: AC power */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2_FAIL_FAN
value|0x04
end_define

begin_comment
comment|/* failed: rack fans */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2_OK_ACFAN
value|0x02
end_define

begin_comment
comment|/* ok: 4 AC box fans */
end_comment

begin_define
define|#
directive|define
name|CLK_STS2_OK_KEYFAN
value|0x01
end_define

begin_comment
comment|/* ok: keyswitch fans */
end_comment

begin_define
define|#
directive|define
name|CLK_PSTS1
value|0x30
end_define

begin_comment
comment|/* power supply 1 status register */
end_comment

begin_define
define|#
directive|define
name|CLK_PSTS1_PS
value|0x80
end_define

begin_comment
comment|/* power supply 1 present (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES
value|0x40
end_define

begin_comment
comment|/* power supply presence register */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_CSHARE
value|0x80
end_define

begin_comment
comment|/* current share backplane */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_OK_MASK
value|0x7f
end_define

begin_comment
comment|/* precharge and peripheral pwr mask */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_OK_P_5V
value|0x40
end_define

begin_comment
comment|/* ok: peripheral 5V */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_OK_P_12V
value|0x20
end_define

begin_comment
comment|/* ok: peripheral 12V */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_OK_AUX_5V
value|0x10
end_define

begin_comment
comment|/* ok: auxiliary 5V */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_OK_PP_5V
value|0x08
end_define

begin_comment
comment|/* ok: peripheral 5V precharge */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_OK_PP_12V
value|0x04
end_define

begin_comment
comment|/* ok: peripheral 12V precharge */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_OK_SP_3V
value|0x02
end_define

begin_comment
comment|/* ok: system 3.3V precharge */
end_comment

begin_define
define|#
directive|define
name|CLK_PPRES_OK_SP_5V
value|0x01
end_define

begin_comment
comment|/* ok: system 5V precharge */
end_comment

begin_define
define|#
directive|define
name|CLK_TEMP
value|0x50
end_define

begin_comment
comment|/* temperature register */
end_comment

begin_define
define|#
directive|define
name|CLK_IDIAG
value|0x60
end_define

begin_comment
comment|/* interrupt diagnostic register */
end_comment

begin_define
define|#
directive|define
name|CLK_PSTS2
value|0x70
end_define

begin_comment
comment|/* power supply 2 status register */
end_comment

begin_comment
comment|/* register bank 2 */
end_comment

begin_define
define|#
directive|define
name|CLKVER_SLOTS
value|0x00
end_define

begin_comment
comment|/* clock version slots register */
end_comment

begin_define
define|#
directive|define
name|CLKVER_SLOTS_MASK
value|0x80
end_define

begin_comment
comment|/* clock version slots mask */
end_comment

begin_define
define|#
directive|define
name|CLKVER_SLOTS_PLUS
value|0x00
end_define

begin_comment
comment|/* plus system (reversed) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_FHC_CLKBRDREG_H_ */
end_comment

end_unit

