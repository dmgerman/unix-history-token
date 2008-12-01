begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ar5312reg.h,v 1.4 2008/11/10 04:08:04 sam Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5312REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5312REG_H_
end_define

begin_include
include|#
directive|include
file|"ar5212/ar5212reg.h"
end_include

begin_comment
comment|/*  * Definitions for the Atheros 5312 chipset.  */
end_comment

begin_comment
comment|/* Register base addresses for modules which are not wmac modules */
end_comment

begin_comment
comment|/* 531X has a fixed memory map */
end_comment

begin_define
define|#
directive|define
name|REG_WRITE
parameter_list|(
name|_reg
parameter_list|,
name|_val
parameter_list|)
value|*((volatile uint32_t *)(_reg)) = (_val);
end_define

begin_define
define|#
directive|define
name|REG_READ
parameter_list|(
name|_reg
parameter_list|)
value|*((volatile uint32_t *)(_reg))
end_define

begin_comment
comment|/*   * PCI-MAC Configuration registers (AR2315+)  */
end_comment

begin_define
define|#
directive|define
name|AR5315_RSTIMER_BASE
value|0xb1000000
end_define

begin_comment
comment|/* Address for reset/timer registers */
end_comment

begin_define
define|#
directive|define
name|AR5315_GPIO_BASE
value|0xb1000000
end_define

begin_comment
comment|/* Address for GPIO registers */
end_comment

begin_define
define|#
directive|define
name|AR5315_WLAN0
value|0xb0000000
end_define

begin_define
define|#
directive|define
name|AR5315_RESET
value|0x0004
end_define

begin_comment
comment|/* Offset of reset control register */
end_comment

begin_define
define|#
directive|define
name|AR5315_SREV
value|0x0014
end_define

begin_comment
comment|/* Offset of reset control register */
end_comment

begin_define
define|#
directive|define
name|AR5315_ENDIAN_CTL
value|0x000c
end_define

begin_comment
comment|/* offset of the endian control register */
end_comment

begin_define
define|#
directive|define
name|AR5315_CONFIG_WLAN
value|0x00000002
end_define

begin_comment
comment|/* WLAN byteswap */
end_comment

begin_define
define|#
directive|define
name|AR5315_REV_MAJ
value|0x00f0
end_define

begin_define
define|#
directive|define
name|AR5315_REV_MIN
value|0x000f
end_define

begin_define
define|#
directive|define
name|AR5315_GPIODIR
value|0x0098
end_define

begin_comment
comment|/* GPIO direction register */
end_comment

begin_define
define|#
directive|define
name|AR5315_GPIODO
value|0x0090
end_define

begin_comment
comment|/* GPIO data output access reg */
end_comment

begin_define
define|#
directive|define
name|AR5315_GPIODI
value|0x0088
end_define

begin_comment
comment|/* GPIO data input access reg*/
end_comment

begin_define
define|#
directive|define
name|AR5315_GPIOINT
value|0x00a0
end_define

begin_comment
comment|/* GPIO interrupt control */
end_comment

begin_define
define|#
directive|define
name|AR5315_GPIODIR_M
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_comment
comment|/* mask for i/o */
end_comment

begin_define
define|#
directive|define
name|AR5315_GPIODIR_O
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_comment
comment|/* output */
end_comment

begin_define
define|#
directive|define
name|AR5315_GPIODIR_I
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_comment
comment|/* input */
end_comment

begin_define
define|#
directive|define
name|AR5315_GPIOINT_S
value|0
end_define

begin_define
define|#
directive|define
name|AR5315_GPIOINT_M
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR5315_GPIOINTLVL_S
value|6
end_define

begin_define
define|#
directive|define
name|AR5315_GPIOINTLVL_M
value|(3<< AR5315_GPIOINTLVL_S)
end_define

begin_define
define|#
directive|define
name|AR5315_WREV
value|(-0xefbfe0)
end_define

begin_comment
comment|/* Revision ID register offset */
end_comment

begin_define
define|#
directive|define
name|AR5315_WREV_S
value|0
end_define

begin_comment
comment|/* Shift for WMAC revision info */
end_comment

begin_define
define|#
directive|define
name|AR5315_WREV_ID
value|0x000000FF
end_define

begin_comment
comment|/* Mask for WMAC revision info */
end_comment

begin_define
define|#
directive|define
name|AR5315_WREV_ID_S
value|4
end_define

begin_comment
comment|/* Shift for WMAC Rev ID */
end_comment

begin_define
define|#
directive|define
name|AR5315_WREV_REVISION
value|0x0000000F
end_define

begin_comment
comment|/* Mask for WMAN Revsion version */
end_comment

begin_define
define|#
directive|define
name|AR5315_RC_BB0_CRES
value|0x00000002
end_define

begin_comment
comment|/* Cold reset to WMAC0& WBB0 */
end_comment

begin_define
define|#
directive|define
name|AR5315_RC_BB1_CRES
value|0x00000200
end_define

begin_comment
comment|/* Cold reset to WMAC1& WBB1n */
end_comment

begin_define
define|#
directive|define
name|AR5315_RC_WMAC0_RES
value|0x00000001
end_define

begin_comment
comment|/* Warm reset to WMAC 0 */
end_comment

begin_define
define|#
directive|define
name|AR5315_RC_WBB0_RES
value|0x00000002
end_define

begin_comment
comment|/* Warm reset to WBB0 */
end_comment

begin_define
define|#
directive|define
name|AR5315_RC_WMAC1_RES
value|0x00020000
end_define

begin_comment
comment|/* Warm reset to WMAC1 */
end_comment

begin_define
define|#
directive|define
name|AR5315_RC_WBB1_RES
value|0x00040000
end_define

begin_comment
comment|/* Warm reset to WBB */
end_comment

begin_comment
comment|/*  * PCI-MAC Configuration registers (AR5312)  */
end_comment

begin_define
define|#
directive|define
name|AR5312_RSTIMER_BASE
value|0xbc003000
end_define

begin_comment
comment|/* Address for reset/timer registers */
end_comment

begin_define
define|#
directive|define
name|AR5312_GPIO_BASE
value|0xbc002000
end_define

begin_comment
comment|/* Address for GPIO registers */
end_comment

begin_define
define|#
directive|define
name|AR5312_WLAN0
value|0xb8000000
end_define

begin_define
define|#
directive|define
name|AR5312_WLAN1
value|0xb8500000
end_define

begin_define
define|#
directive|define
name|AR5312_RESET
value|0x0020
end_define

begin_comment
comment|/* Offset of reset control register */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG
value|0x00B0
end_define

begin_comment
comment|/* MAC/PCI configuration reg (LEDs) */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDMODE
value|0x0000001c
end_define

begin_comment
comment|/* LED Mode mask */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDMODE_S
value|2
end_define

begin_comment
comment|/* LED Mode shift */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDMOD0
value|0
end_define

begin_comment
comment|/* Blnk prop to Tx and filtered Rx */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDMOD1
value|1
end_define

begin_comment
comment|/* Blnk prop to all Tx and Rx */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDMOD2
value|2
end_define

begin_comment
comment|/* DEBG flash */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDMOD3
value|3
end_define

begin_comment
comment|/* BLNK Randomly */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL
value|0x000000e0
end_define

begin_comment
comment|/* LED Throughput select */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL_S
value|5
end_define

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL0
value|0
end_define

begin_comment
comment|/* See blink rate table on p. 143 */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL1
value|1
end_define

begin_comment
comment|/* of AR5212 data sheet */
end_comment

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL2
value|2
end_define

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL3
value|3
end_define

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL4
value|4
end_define

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL5
value|5
end_define

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL6
value|6
end_define

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSEL7
value|7
end_define

begin_define
define|#
directive|define
name|AR5312_PCICFG_LEDSBR
value|0x00000100
end_define

begin_comment
comment|/* Slow blink rate if no 			   		     activity. 0 = blink @ lowest 					     rate */
end_comment

begin_undef
undef|#
directive|undef
name|AR_GPIOCR
end_undef

begin_undef
undef|#
directive|undef
name|AR_GPIODO
end_undef

begin_comment
comment|/* Undefine the 5212 defs */
end_comment

begin_undef
undef|#
directive|undef
name|AR_GPIODI
end_undef

begin_define
define|#
directive|define
name|AR5312_GPIOCR
value|0x0008
end_define

begin_comment
comment|/* GPIO Control register */
end_comment

begin_define
define|#
directive|define
name|AR5312_GPIODO
value|0x0000
end_define

begin_comment
comment|/* GPIO data output access reg */
end_comment

begin_define
define|#
directive|define
name|AR5312_GPIODI
value|0x0004
end_define

begin_comment
comment|/* GPIO data input access reg*/
end_comment

begin_comment
comment|/* NB: AR5312 uses AR5212 defines for GPIOCR definitions */
end_comment

begin_define
define|#
directive|define
name|AR5312_WREV
value|0x0090
end_define

begin_comment
comment|/* Revision ID register offset */
end_comment

begin_define
define|#
directive|define
name|AR5312_WREV_S
value|8
end_define

begin_comment
comment|/* Shift for WMAC revision info */
end_comment

begin_define
define|#
directive|define
name|AR5312_WREV_ID
value|0x000000FF
end_define

begin_comment
comment|/* Mask for WMAC revision info */
end_comment

begin_define
define|#
directive|define
name|AR5312_WREV_ID_S
value|4
end_define

begin_comment
comment|/* Shift for WMAC Rev ID */
end_comment

begin_define
define|#
directive|define
name|AR5312_WREV_REVISION
value|0x0000000F
end_define

begin_comment
comment|/* Mask for WMAN Revsion version */
end_comment

begin_define
define|#
directive|define
name|AR5312_RC_BB0_CRES
value|0x00000004
end_define

begin_comment
comment|/* Cold reset to WMAC0& WBB0 */
end_comment

begin_define
define|#
directive|define
name|AR5312_RC_BB1_CRES
value|0x00000200
end_define

begin_comment
comment|/* Cold reset to WMAC1& WBB1n */
end_comment

begin_define
define|#
directive|define
name|AR5312_RC_WMAC0_RES
value|0x00002000
end_define

begin_comment
comment|/* Warm reset to WMAC 0 */
end_comment

begin_define
define|#
directive|define
name|AR5312_RC_WBB0_RES
value|0x00004000
end_define

begin_comment
comment|/* Warm reset to WBB0 */
end_comment

begin_define
define|#
directive|define
name|AR5312_RC_WMAC1_RES
value|0x00020000
end_define

begin_comment
comment|/* Warm reset to WMAC1 */
end_comment

begin_define
define|#
directive|define
name|AR5312_RC_WBB1_RES
value|0x00040000
end_define

begin_comment
comment|/* Warm reset to WBB */
end_comment

begin_define
define|#
directive|define
name|AR_RAD2112_SREV_MAJOR
value|0x40
end_define

begin_comment
comment|/* 2112 Major Rev */
end_comment

begin_enum
enum|enum
name|AR5312PowerMode
block|{
name|AR5312_POWER_MODE_FORCE_SLEEP
init|=
literal|0
block|,
name|AR5312_POWER_MODE_FORCE_WAKE
init|=
literal|1
block|,
name|AR5312_POWER_MODE_NORMAL
init|=
literal|2
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_AR5312REG_H_ */
end_comment

end_unit

