begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Bernd Walter.  All rights reserved.  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Portions of this software may have been developed with reference to  * the SD Simplified Specification.  The following disclaimer may apply:  *  * The following conditions apply to the release of the simplified  * specification ("Simplified Specification") by the SD Card Association and  * the SD Group. The Simplified Specification is a subset of the complete SD  * Specification which is owned by the SD Card Association and the SD  * Group. This Simplified Specification is provided on a non-confidential  * basis subject to the disclaimers below. Any implementation of the  * Simplified Specification may require a license from the SD Card  * Association, SD Group, SD-3C LLC or other third parties.  *  * Disclaimers:  *  * The information contained in the Simplified Specification is presented only  * as a standard specification for SD Cards and SD Host/Ancillary products and  * is provided "AS-IS" without any representations or warranties of any  * kind. No responsibility is assumed by the SD Group, SD-3C LLC or the SD  * Card Association for any damages, any infringements of patents or other  * right of the SD Group, SD-3C LLC, the SD Card Association or any third  * parties, which may result from its use. No license is granted by  * implication, estoppel or otherwise under any patent or other rights of the  * SD Group, SD-3C LLC, the SD Card Association or any third party. Nothing  * herein shall be construed as an obligation by the SD Group, the SD-3C LLC  * or the SD Card Association to disclose or distribute any technical  * information, know-how or other confidential information to any third party.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_MMC_MMCVAR_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_MMC_MMCVAR_H
end_define

begin_enum
enum|enum
name|mmc_device_ivars
block|{
name|MMC_IVAR_SPEC_VERS
block|,
name|MMC_IVAR_DSR_IMP
block|,
name|MMC_IVAR_MEDIA_SIZE
block|,
name|MMC_IVAR_RCA
block|,
name|MMC_IVAR_SECTOR_SIZE
block|,
name|MMC_IVAR_TRAN_SPEED
block|,
name|MMC_IVAR_READ_ONLY
block|,
name|MMC_IVAR_HIGH_CAP
block|,
name|MMC_IVAR_CARD_TYPE
block|,
name|MMC_IVAR_BUS_WIDTH
block|,
name|MMC_IVAR_ERASE_SECTOR
block|,
name|MMC_IVAR_MAX_DATA
block|,
name|MMC_IVAR_CMD6_TIMEOUT
block|,
name|MMC_IVAR_QUIRKS
block|,
name|MMC_IVAR_CARD_ID_STRING
block|,
name|MMC_IVAR_CARD_SN_STRING
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for mmc devices  */
end_comment

begin_define
define|#
directive|define
name|MMC_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(mmc, var, MMC, ivar, type)
end_define

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|spec_vers
argument_list|,
argument|SPEC_VERS
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|dsr_imp
argument_list|,
argument|DSR_IMP
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|media_size
argument_list|,
argument|MEDIA_SIZE
argument_list|,
argument|long
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|rca
argument_list|,
argument|RCA
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|sector_size
argument_list|,
argument|SECTOR_SIZE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|tran_speed
argument_list|,
argument|TRAN_SPEED
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|read_only
argument_list|,
argument|READ_ONLY
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|high_cap
argument_list|,
argument|HIGH_CAP
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|card_type
argument_list|,
argument|CARD_TYPE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|bus_width
argument_list|,
argument|BUS_WIDTH
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|erase_sector
argument_list|,
argument|ERASE_SECTOR
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|max_data
argument_list|,
argument|MAX_DATA
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|cmd6_timeout
argument_list|,
argument|CMD6_TIMEOUT
argument_list|,
argument|u_int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|quirks
argument_list|,
argument|QUIRKS
argument_list|,
argument|u_int
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|card_id_string
argument_list|,
argument|CARD_ID_STRING
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_macro
name|MMC_ACCESSOR
argument_list|(
argument|card_sn_string
argument_list|,
argument|CARD_SN_STRING
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_MMC_MMCVAR_H */
end_comment

end_unit

