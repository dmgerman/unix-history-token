begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 Solarflare Communications Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright notice,  *    this list of conditions and the following disclaimer in the documentation  *    and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation are  * those of the authors and should not be interpreted as representing official  * policies, either expressed or implied, of the FreeBSD Project.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EFX_CHECK_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EFX_CHECK_H
end_define

begin_include
include|#
directive|include
file|"efsys.h"
end_include

begin_comment
comment|/*  * Check that the efsys.h header in client code has a valid combination of  * EFSYS_OPT_xxx options.  *  * NOTE: Keep checks for obsolete options here to ensure that they are removed  * from client code (and do not reappear in merges from other branches).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_FALCON
end_ifdef

begin_error
error|#
directive|error
literal|"FALCON is obsolete and is not supported."
end_error

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FIXME: remove this after Falcon support has been removed */
end_comment

begin_define
define|#
directive|define
name|EFSYS_OPT_MAC_FALCON_XMAC
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_MON_LM87
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_MON_MAX6647
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_MON_NULL
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_NVRAM_FALCON_BOOTROM
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_NVRAM_SFT9001
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_NVRAM_SFX7101
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_PHY_NULL
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_PHY_QT2022C2
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_PHY_QT2025C
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_PHY_SFT9001
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_PHY_SFX7101
value|(0)
end_define

begin_define
define|#
directive|define
name|EFSYS_OPT_PHY_TXC43128
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support NVRAM based boot config */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_BOOTCFG
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_NVRAM
end_if

begin_error
error|#
directive|error
literal|"BOOTCFG requires NVRAM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_BOOTCFG */
end_comment

begin_comment
comment|/* Verify chip implements accessed registers */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_CHECK_REG
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"CHECK_REG requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_CHECK_REG */
end_comment

begin_comment
comment|/* Decode fatal errors */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_DECODE_INTR_FATAL
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_SIENA
end_if

begin_error
error|#
directive|error
literal|"INTR_FATAL requires SIENA"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_DECODE_INTR_FATAL */
end_comment

begin_comment
comment|/* Support diagnostic hardware tests */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_DIAG
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"DIAG requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_DIAG */
end_comment

begin_comment
comment|/* Support optimized EVQ data access */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_EV_PREFETCH
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"EV_PREFETCH requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_EV_PREFETCH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_FALCON_NIC_CFG_OVERRIDE
end_ifdef

begin_error
error|#
directive|error
literal|"FALCON_NIC_CFG_OVERRIDE is obsolete and is not supported."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support hardware packet filters */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_FILTER
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"FILTER requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_FILTER */
end_comment

begin_if
if|#
directive|if
operator|(
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FILTER
end_if

begin_error
error|#
directive|error
literal|"HUNTINGTON or MEDFORD requires FILTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_HUNTINGTON */
end_comment

begin_comment
comment|/* Support hardware loopback modes */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_LOOPBACK
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"LOOPBACK requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_LOOPBACK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_MAC_FALCON_GMAC
end_ifdef

begin_error
error|#
directive|error
literal|"MAC_FALCON_GMAC is obsolete and is not supported."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support Falcon XMAC */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MAC_FALCON_XMAC
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"MAC_FALCON_XMAC requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MAC_FALCON_XMAC */
end_comment

begin_comment
comment|/* Support MAC statistics */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MAC_STATS
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"MAC_STATS requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MAC_STATS */
end_comment

begin_comment
comment|/* Support management controller messages */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MCDI
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"MCDI requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MCDI */
end_comment

begin_if
if|#
directive|if
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_MCDI
end_if

begin_error
error|#
directive|error
literal|"SIENA or HUNTINGTON or MEDFORD requires MCDI"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support MCDI logging */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MCDI_LOGGING
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_MCDI
end_if

begin_error
error|#
directive|error
literal|"MCDI_LOGGING requires MCDI"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MCDI_LOGGING */
end_comment

begin_comment
comment|/* Support MCDI proxy authorization */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MCDI_PROXY_AUTH
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_MCDI
end_if

begin_error
error|#
directive|error
literal|"MCDI_PROXY_AUTH requires MCDI"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MCDI_PROXY_AUTH */
end_comment

begin_comment
comment|/* Support LM87 monitor */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MON_LM87
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"MON_LM87 requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MON_LM87 */
end_comment

begin_comment
comment|/* Support MAX6647 monitor */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MON_MAX6647
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"MON_MAX6647 requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MON_MAX6647 */
end_comment

begin_comment
comment|/* Support null monitor */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MON_NULL
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"MON_NULL requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MON_NULL */
end_comment

begin_comment
comment|/* Obsolete option */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_MON_SIENA
end_ifdef

begin_error
error|#
directive|error
literal|"MON_SIENA is obsolete (replaced by MON_MCDI)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MON_SIENA*/
end_comment

begin_comment
comment|/* Obsolete option */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_MON_HUNTINGTON
end_ifdef

begin_error
error|#
directive|error
literal|"MON_HUNTINGTON is obsolete (replaced by MON_MCDI)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MON_HUNTINGTON*/
end_comment

begin_comment
comment|/* Support monitor statistics (voltage/temperature) */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MON_STATS
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"MON_STATS requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MON_STATS */
end_comment

begin_comment
comment|/* Support Monitor via mcdi */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_MON_MCDI
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"MON_MCDI requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MON_MCDI*/
end_comment

begin_comment
comment|/* Support printable names for statistics */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_NAMES
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_LOOPBACK
operator|||
name|EFSYS_OPT_MAC_STATS
operator|||
name|EFSYS_OPT_MCDI
operator|||
expr|\
name|EFSYS_MON_STATS
operator|||
name|EFSYS_OPT_PHY_PROPS
operator|||
name|EFSYS_OPT_PHY_STATS
operator|||
expr|\
name|EFSYS_OPT_QSTATS
operator|)
end_if

begin_error
error|#
directive|error
literal|"NAMES requires LOOPBACK or xxxSTATS or MCDI or PHY_PROPS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_NAMES */
end_comment

begin_comment
comment|/* Support non volatile configuration */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_NVRAM
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"NVRAM requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_NVRAM */
end_comment

begin_comment
comment|/* Support Falcon bootrom */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_NVRAM_FALCON_BOOTROM
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_NVRAM
end_if

begin_error
error|#
directive|error
literal|"NVRAM_FALCON_BOOTROM requires NVRAM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"NVRAM_FALCON_BOOTROM requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_NVRAM_FALCON_BOOTROM */
end_comment

begin_comment
comment|/* Support NVRAM config for SFT9001 */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_NVRAM_SFT9001
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_NVRAM
end_if

begin_error
error|#
directive|error
literal|"NVRAM_SFT9001 requires NVRAM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"NVRAM_SFT9001 requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_NVRAM_SFT9001 */
end_comment

begin_comment
comment|/* Support NVRAM config for SFX7101 */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_NVRAM_SFX7101
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_NVRAM
end_if

begin_error
error|#
directive|error
literal|"NVRAM_SFX7101 requires NVRAM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"NVRAM_SFX7101 requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_NVRAM_SFX7101 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_PCIE_TUNE
end_ifdef

begin_error
error|#
directive|error
literal|"PCIE_TUNE is obsolete and is not supported."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Obsolete option */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_PHY_BIST
end_ifdef

begin_error
error|#
directive|error
literal|"PHY_BIST is obsolete (replaced by BIST)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support PHY flags */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_FLAGS
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_SIENA
end_if

begin_error
error|#
directive|error
literal|"PHY_FLAGS requires SIENA"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_FLAGS */
end_comment

begin_comment
comment|/* Support for PHY LED control */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_LED_CONTROL
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_SIENA
end_if

begin_error
error|#
directive|error
literal|"PHY_LED_CONTROL requires SIENA"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_LED_CONTROL */
end_comment

begin_comment
comment|/* Support NULL PHY */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_NULL
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"PHY_NULL requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_NULL */
end_comment

begin_comment
comment|/* Obsolete option */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_PHY_PM8358
end_ifdef

begin_error
error|#
directive|error
literal|"EFSYS_OPT_PHY_PM8358 is obsolete and is not supported."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support PHY properties */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_PROPS
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_SIENA
end_if

begin_error
error|#
directive|error
literal|"PHY_PROPS requires SIENA"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_PROPS */
end_comment

begin_comment
comment|/* Support QT2022C2 PHY */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_QT2022C2
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"PHY_QT2022C2 requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_QT2022C2 */
end_comment

begin_comment
comment|/* Support QT2025C PHY (Wakefield NIC) */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_QT2025C
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"PHY_QT2025C requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_QT2025C */
end_comment

begin_comment
comment|/* Support SFT9001 PHY (Starbolt NIC) */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_SFT9001
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"PHY_SFT9001 requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_SFT9001 */
end_comment

begin_comment
comment|/* Support SFX7101 PHY (SFE4001 NIC) */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_SFX7101
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"PHY_SFX7101 requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_SFX7101 */
end_comment

begin_comment
comment|/* Support PHY statistics */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_STATS
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_SIENA
end_if

begin_error
error|#
directive|error
literal|"PHY_STATS requires SIENA"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_STATS */
end_comment

begin_comment
comment|/* Support TXC43128 PHY (SFE4003 NIC) */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_PHY_TXC43128
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_FALCON
end_if

begin_error
error|#
directive|error
literal|"PHY_TXC43128 requires FALCON"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_PHY_TXC43128 */
end_comment

begin_comment
comment|/* Support EVQ/RXQ/TXQ statistics */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_QSTATS
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"QSTATS requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_QSTATS */
end_comment

begin_comment
comment|/* Obsolete option */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_RX_HDR_SPLIT
end_ifdef

begin_error
error|#
directive|error
literal|"RX_HDR_SPLIT is obsolete and is not supported"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_RX_HDR_SPLIT */
end_comment

begin_comment
comment|/* Support receive scaling (RSS) */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_RX_SCALE
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"RX_SCALE requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_RX_SCALE */
end_comment

begin_comment
comment|/* Support receive scatter DMA */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_RX_SCATTER
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"RX_SCATTER requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_RX_SCATTER */
end_comment

begin_comment
comment|/* Obsolete option */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_STAT_NAME
end_ifdef

begin_error
error|#
directive|error
literal|"STAT_NAME is obsolete (replaced by NAMES)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support PCI Vital Product Data (VPD) */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_VPD
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"VPD requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_VPD */
end_comment

begin_comment
comment|/* Support Wake on LAN */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_WOL
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_SIENA
end_if

begin_error
error|#
directive|error
literal|"WOL requires SIENA"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_WOL */
end_comment

begin_comment
comment|/* Obsolete option */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EFSYS_OPT_MCAST_FILTER_LIST
end_ifdef

begin_error
error|#
directive|error
literal|"MCAST_FILTER_LIST is obsolete and is not supported"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_MCAST_FILTER_LIST */
end_comment

begin_comment
comment|/* Support BIST */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_BIST
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|EFSYS_OPT_SIENA
operator|||
name|EFSYS_OPT_HUNTINGTON
operator|||
name|EFSYS_OPT_MEDFORD
operator|)
end_if

begin_error
error|#
directive|error
literal|"BIST requires SIENA or HUNTINGTON or MEDFORD"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_BIST */
end_comment

begin_comment
comment|/* Support MCDI licensing API */
end_comment

begin_if
if|#
directive|if
name|EFSYS_OPT_LICENSING
end_if

begin_if
if|#
directive|if
operator|!
name|EFSYS_OPT_MCDI
end_if

begin_error
error|#
directive|error
literal|"LICENSING requires MCDI"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|EFSYS_HAS_UINT64
end_if

begin_error
error|#
directive|error
literal|"LICENSING requires UINT64"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_LICENSING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_EFX_CHECK_H */
end_comment

end_unit

