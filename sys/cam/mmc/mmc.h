begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014-2016 Ilya Bakulin.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Portions of this software may have been developed with reference to  * the SD Simplified Specification.  The following disclaimer may apply:  *  * The following conditions apply to the release of the simplified  * specification ("Simplified Specification") by the SD Card Association and  * the SD Group. The Simplified Specification is a subset of the complete SD  * Specification which is owned by the SD Card Association and the SD  * Group. This Simplified Specification is provided on a non-confidential  * basis subject to the disclaimers below. Any implementation of the  * Simplified Specification may require a license from the SD Card  * Association, SD Group, SD-3C LLC or other third parties.  *  * Disclaimers:  *  * The information contained in the Simplified Specification is presented only  * as a standard specification for SD Cards and SD Host/Ancillary products and  * is provided "AS-IS" without any representations or warranties of any  * kind. No responsibility is assumed by the SD Group, SD-3C LLC or the SD  * Card Association for any damages, any infringements of patents or other  * right of the SD Group, SD-3C LLC, the SD Card Association or any third  * parties, which may result from its use. No license is granted by  * implication, estoppel or otherwise under any patent or other rights of the  * SD Group, SD-3C LLC, the SD Card Association or any third party. Nothing  * herein shall be construed as an obligation by the SD Group, the SD-3C LLC  * or the SD Card Association to disclose or distribute any technical  * information, know-how or other confidential information to any third party.  *  * Inspired coded in sys/dev/mmc. Thanks to Warner Losh<imp@FreeBSD.org>,  * Bernd Walter<tisco@FreeBSD.org>, and other authors.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CAM_MMC_H
end_ifndef

begin_define
define|#
directive|define
name|CAM_MMC_H
end_define

begin_include
include|#
directive|include
file|<dev/mmc/mmcreg.h>
end_include

begin_comment
comment|/*  * This structure describes an MMC/SD card  */
end_comment

begin_struct
struct|struct
name|mmc_params
block|{
name|u_int8_t
name|model
index|[
literal|40
index|]
decl_stmt|;
comment|/* Card model */
comment|/* Card OCR */
name|uint32_t
name|card_ocr
decl_stmt|;
comment|/* OCR of the IO portion of the card */
name|uint32_t
name|io_ocr
decl_stmt|;
comment|/* Card CID -- raw and parsed */
name|uint32_t
name|card_cid
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|mmc_cid
name|cid
decl_stmt|;
comment|/* Card CSD -- raw */
name|uint32_t
name|card_csd
index|[
literal|4
index|]
decl_stmt|;
comment|/* Card RCA */
name|uint16_t
name|card_rca
decl_stmt|;
comment|/* What kind of card is it */
name|uint32_t
name|card_features
decl_stmt|;
define|#
directive|define
name|CARD_FEATURE_MEMORY
value|0x1
define|#
directive|define
name|CARD_FEATURE_SDHC
value|0x1<< 1
define|#
directive|define
name|CARD_FEATURE_SDIO
value|0x1<< 2
define|#
directive|define
name|CARD_FEATURE_SD20
value|0x1<< 3
define|#
directive|define
name|CARD_FEATURE_MMC
value|0x1<< 4
name|uint8_t
name|sdio_func_count
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

