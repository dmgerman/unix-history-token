begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Sam Leffler, Errno Consulting, Atheros  * Communications, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the following conditions are met:  * 1. The materials contained herein are unmodified and are used  *    unmodified.  * 2. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following NO  *    ''WARRANTY'' disclaimer below (''Disclaimer''), without  *    modification.  * 3. Redistributions in binary form must reproduce at minimum a  *    disclaimer similar to the Disclaimer below and any redistribution  *    must be conditioned upon including a substantially similar  *    Disclaimer requirement for further binary redistribution.  * 4. Neither the names of the above-listed copyright holders nor the  *    names of any contributors may be used to endorse or promote  *    product derived from this software without specific prior written  *    permission.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT,  * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE  * FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGES.  *  * $Id: //depot/sw/branches/sam_hal/ah_soc.h#3 $  */
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
name|u_int32_t
name|magic
decl_stmt|;
comment|/* board data is valid */
define|#
directive|define
name|AR531X_BD_MAGIC
value|0x35333131
comment|/* "5311", for all 531x platforms */
name|u_int16_t
name|cksum
decl_stmt|;
comment|/* checksum (starting with BD_REV 2) */
name|u_int16_t
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
name|u_int16_t
name|major
decl_stmt|;
comment|/* Board major number */
name|u_int16_t
name|minor
decl_stmt|;
comment|/* Board minor number */
name|u_int32_t
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
name|u_int16_t
name|resetConfigGpio
decl_stmt|;
comment|/* Reset factory GPIO pin */
name|u_int16_t
name|sysLedGpio
decl_stmt|;
comment|/* System LED GPIO pin */
name|u_int32_t
name|cpuFreq
decl_stmt|;
comment|/* CPU core frequency in Hz */
name|u_int32_t
name|sysFreq
decl_stmt|;
comment|/* System frequency in Hz */
name|u_int32_t
name|cntFreq
decl_stmt|;
comment|/* Calculated C0_COUNT frequency */
name|u_int8_t
name|wlan0Mac
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|enet0Mac
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|enet1Mac
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|pciId
decl_stmt|;
comment|/* Pseudo PCIID for common code */
name|u_int16_t
name|memCap
decl_stmt|;
comment|/* cap bank1 in MB */
comment|/* version 3 */
name|u_int8_t
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

