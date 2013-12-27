begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_EEPROM_V1_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_EEPROM_V1_H_
end_define

begin_include
include|#
directive|include
file|"ah_eeprom.h"
end_include

begin_comment
comment|/*  * EEPROM defines for Version 1 Crete EEPROM.  *  * The EEPROM is segmented into three sections:  *  *    PCI/Cardbus default configuration settings  *    Cardbus CIS tuples and vendor-specific data  *    Atheros-specific data  *  * EEPROM entries are read 32-bits at a time through the PCI bus  * interface but are all 16-bit values.  *  * Access to the Atheros-specific data is controlled by protection  * bits and the data is checksum'd.  The driver reads the Atheros  * data from the EEPROM at attach and caches it in its private state.  * This data includes the local regulatory domain, channel calibration  * settings, and phy-related configuration settings.  */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_MAC
parameter_list|(
name|i
parameter_list|)
value|(0x1f-(i))
end_define

begin_comment
comment|/* MAC address word */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_MAGIC
value|0x3d
end_define

begin_comment
comment|/* magic number */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT
value|0x3f
end_define

begin_comment
comment|/* Atheros segment protect register */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_PROTOTECT_WP_128_191
value|0x80
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_REG_DOMAIN
value|0xbf
end_define

begin_comment
comment|/* Current regulatory domain register */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS_BASE
value|0xc0
end_define

begin_comment
comment|/* Base of Atheros-specific data */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS_MAX
value|64
end_define

begin_comment
comment|/* 64x2=128 bytes of EEPROM settings */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS
parameter_list|(
name|n
parameter_list|)
value|(AR_EEPROM_ATHEROS_BASE+(n))
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VERSION
value|AR_EEPROM_ATHEROS(1)
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS_TP_SETTINGS
value|0x09
end_define

begin_comment
comment|/* Transmit power settings */
end_comment

begin_define
define|#
directive|define
name|AR_REG_DOMAINS_MAX
value|4
end_define

begin_comment
comment|/* # of Regulatory Domains */
end_comment

begin_define
define|#
directive|define
name|AR_CHANNELS_MAX
value|5
end_define

begin_comment
comment|/* # of Channel calibration groups */
end_comment

begin_define
define|#
directive|define
name|AR_TP_SETTINGS_SIZE
value|11
end_define

begin_comment
comment|/* # locations/Channel group */
end_comment

begin_define
define|#
directive|define
name|AR_TP_SCALING_ENTRIES
value|11
end_define

begin_comment
comment|/* # entries in transmit power dBm->pcdac */
end_comment

begin_comment
comment|/*  * NB: we store the rfsilent select+polarity data packed  *     with the encoding used in later parts so values  *     returned to applications are consistent.  */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT_GPIO_SEL
value|0x001c
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT_GPIO_SEL_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT_POLARITY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT_POLARITY_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_I2DBM
parameter_list|(
name|x
parameter_list|)
value|((uint8_t)((x * 2) + 3))
end_define

begin_comment
comment|/*  * Transmit power and channel calibration settings.  */
end_comment

begin_struct
struct|struct
name|tpcMap
block|{
name|uint8_t
name|pcdac
index|[
name|AR_TP_SCALING_ENTRIES
index|]
decl_stmt|;
name|uint8_t
name|gainF
index|[
name|AR_TP_SCALING_ENTRIES
index|]
decl_stmt|;
name|uint8_t
name|rate36
decl_stmt|;
name|uint8_t
name|rate48
decl_stmt|;
name|uint8_t
name|rate54
decl_stmt|;
name|uint8_t
name|regdmn
index|[
name|AR_REG_DOMAINS_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Information retrieved from EEPROM.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|ee_version
decl_stmt|;
comment|/* Version field */
name|uint16_t
name|ee_protect
decl_stmt|;
comment|/* EEPROM protect field */
name|uint16_t
name|ee_antenna
decl_stmt|;
comment|/* Antenna Settings */
name|uint16_t
name|ee_biasCurrents
decl_stmt|;
comment|/* OB, DB */
name|uint8_t
name|ee_thresh62
decl_stmt|;
comment|/* thresh62 */
name|uint8_t
name|ee_xlnaOn
decl_stmt|;
comment|/* External LNA timing */
name|uint8_t
name|ee_xpaOff
decl_stmt|;
comment|/* Extern output stage timing */
name|uint8_t
name|ee_xpaOn
decl_stmt|;
comment|/* Extern output stage timing */
name|uint8_t
name|ee_rfKill
decl_stmt|;
comment|/* Single low bit signalling if RF Kill is implemented */
name|uint8_t
name|ee_devType
decl_stmt|;
comment|/* Type: PCI, miniPCI, CB */
name|uint8_t
name|ee_regDomain
index|[
name|AR_REG_DOMAINS_MAX
index|]
decl_stmt|;
comment|/* calibrated reg domains */
name|struct
name|tpcMap
name|ee_tpc
index|[
name|AR_CHANNELS_MAX
index|]
decl_stmt|;
block|}
name|HAL_EEPROM_v1
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_EEPROM_V1_H_ */
end_comment

end_unit

