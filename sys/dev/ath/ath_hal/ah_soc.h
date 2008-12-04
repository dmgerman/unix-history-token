begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ah_soc.h,v 1.4 2008/11/10 04:08:00 sam Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_SOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_SOC_H_
end_define

begin_comment
comment|/*  * Atheros System on Chip (SoC) public definitions.  */
end_comment

begin_comment
comment|/*  * This is board-specific data that is stored in a "known"  * location in flash.  To find the start of this data search  * back from the (aliased) end of flash by 0x1000 bytes at a  * time until you find the string "5311", which marks the  * start of Board Configuration.  Typically one gives up if  * more than 500KB is searched.  */
end_comment

begin_struct
struct|struct
name|ar531x_boarddata
block|{
name|uint32_t
name|magic
decl_stmt|;
comment|/* board data is valid */
define|#
directive|define
name|AR531X_BD_MAGIC
value|0x35333131
comment|/* "5311", for all 531x platforms */
name|uint16_t
name|cksum
decl_stmt|;
comment|/* checksum (starting with BD_REV 2) */
name|uint16_t
name|rev
decl_stmt|;
comment|/* revision of this struct */
define|#
directive|define
name|BD_REV
value|4
name|char
name|boardName
index|[
literal|64
index|]
decl_stmt|;
comment|/* Name of board */
name|uint16_t
name|major
decl_stmt|;
comment|/* Board major number */
name|uint16_t
name|minor
decl_stmt|;
comment|/* Board minor number */
name|uint32_t
name|config
decl_stmt|;
comment|/* Board configuration */
define|#
directive|define
name|BD_ENET0
value|0x00000001
comment|/* ENET0 is stuffed */
define|#
directive|define
name|BD_ENET1
value|0x00000002
comment|/* ENET1 is stuffed */
define|#
directive|define
name|BD_UART1
value|0x00000004
comment|/* UART1 is stuffed */
define|#
directive|define
name|BD_UART0
value|0x00000008
comment|/* UART0 is stuffed (dma) */
define|#
directive|define
name|BD_RSTFACTORY
value|0x00000010
comment|/* Reset factory defaults stuffed */
define|#
directive|define
name|BD_SYSLED
value|0x00000020
comment|/* System LED stuffed */
define|#
directive|define
name|BD_EXTUARTCLK
value|0x00000040
comment|/* External UART clock */
define|#
directive|define
name|BD_CPUFREQ
value|0x00000080
comment|/* cpu freq is valid in nvram */
define|#
directive|define
name|BD_SYSFREQ
value|0x00000100
comment|/* sys freq is set in nvram */
define|#
directive|define
name|BD_WLAN0
value|0x00000200
comment|/* Enable WLAN0 */
define|#
directive|define
name|BD_MEMCAP
value|0x00000400
comment|/* CAP SDRAM @ memCap for testing */
define|#
directive|define
name|BD_DISWATCHDOG
value|0x00000800
comment|/* disable system watchdog */
define|#
directive|define
name|BD_WLAN1
value|0x00001000
comment|/* Enable WLAN1 (ar5212) */
define|#
directive|define
name|BD_ISCASPER
value|0x00002000
comment|/* FLAG for AR2312 */
define|#
directive|define
name|BD_WLAN0_2G_EN
value|0x00004000
comment|/* FLAG for radio0_2G */
define|#
directive|define
name|BD_WLAN0_5G_EN
value|0x00008000
comment|/* FLAG for radio0_2G */
define|#
directive|define
name|BD_WLAN1_2G_EN
value|0x00020000
comment|/* FLAG for radio0_2G */
define|#
directive|define
name|BD_WLAN1_5G_EN
value|0x00040000
comment|/* FLAG for radio0_2G */
name|uint16_t
name|resetConfigGpio
decl_stmt|;
comment|/* Reset factory GPIO pin */
name|uint16_t
name|sysLedGpio
decl_stmt|;
comment|/* System LED GPIO pin */
name|uint32_t
name|cpuFreq
decl_stmt|;
comment|/* CPU core frequency in Hz */
name|uint32_t
name|sysFreq
decl_stmt|;
comment|/* System frequency in Hz */
name|uint32_t
name|cntFreq
decl_stmt|;
comment|/* Calculated C0_COUNT frequency */
name|uint8_t
name|wlan0Mac
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|enet0Mac
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|enet1Mac
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|pciId
decl_stmt|;
comment|/* Pseudo PCIID for common code */
name|uint16_t
name|memCap
decl_stmt|;
comment|/* cap bank1 in MB */
comment|/* version 3 */
name|uint8_t
name|wlan1Mac
index|[
literal|6
index|]
decl_stmt|;
comment|/* (ar5212) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Board support data.  The driver is required to locate  * and fill-in this information before passing a reference to  * this structure as the HAL_BUS_TAG parameter supplied to  * ath_hal_attach.  */
end_comment

begin_struct
struct|struct
name|ar531x_config
block|{
specifier|const
name|struct
name|ar531x_boarddata
modifier|*
name|board
decl_stmt|;
comment|/* board config data */
specifier|const
name|char
modifier|*
name|radio
decl_stmt|;
comment|/* radio config data */
name|int
name|unit
decl_stmt|;
comment|/* unit number [0, 1] */
name|void
modifier|*
name|tag
decl_stmt|;
comment|/* bus space tag */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_SOC_H_ */
end_comment

end_unit

