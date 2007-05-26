begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Bernd Walter.  All rights reserved.  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Portions of this software may have been developed with reference to  * the SD Simplified Specification.  The following disclaimer may apply:  *  * The following conditions apply to the release of the simplified  * specification ("Simplified Specification") by the SD Card Association and  * the SD Group. The Simplified Specification is a subset of the complete SD  * Specification which is owned by the SD Card Association and the SD  * Group. This Simplified Specification is provided on a non-confidential  * basis subject to the disclaimers below. Any implementation of the  * Simplified Specification may require a license from the SD Card  * Association, SD Group, SD-3C LLC or other third parties.  *  * Disclaimers:  *  * The information contained in the Simplified Specification is presented only  * as a standard specification for SD Cards and SD Host/Ancillary products and  * is provided "AS-IS" without any representations or warranties of any  * kind. No responsibility is assumed by the SD Group, SD-3C LLC or the SD  * Card Association for any damages, any infringements of patents or other  * right of the SD Group, SD-3C LLC, the SD Card Association or any third  * parties, which may result from its use. No license is granted by  * implication, estoppel or otherwise under any patent or other rights of the  * SD Group, SD-3C LLC, the SD Card Association or any third party. Nothing  * herein shall be construed as an obligation by the SD Group, the SD-3C LLC  * or the SD Card Association to disclose or distribute any technical  * information, know-how or other confidential information to any third party.  *  * "$FreeBSD$"  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_MMC_MMCBRVAR_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_MMC_MMCBRVAR_H
end_define

begin_include
include|#
directive|include
file|<dev/mmc/bridge.h>
end_include

begin_include
include|#
directive|include
file|"mmcbr_if.h"
end_include

begin_enum
enum|enum
name|mmcbr_device_ivars
block|{
name|MMCBR_IVAR_BUS_MODE
block|,
name|MMCBR_IVAR_BUS_WIDTH
block|,
name|MMCBR_IVAR_CHIP_SELECT
block|,
name|MMCBR_IVAR_CLOCK
block|,
name|MMCBR_IVAR_F_MIN
block|,
name|MMCBR_IVAR_F_MAX
block|,
name|MMCBR_IVAR_HOST_OCR
block|,
name|MMCBR_IVAR_MODE
block|,
name|MMCBR_IVAR_OCR
block|,
name|MMCBR_IVAR_POWER_MODE
block|,
name|MMCBR_IVAR_VDD
block|,
comment|//    MMCBR_IVAR_,
block|}
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for pci devices  */
end_comment

begin_define
define|#
directive|define
name|MMCBR_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(mmcbr, var, MMCBR, ivar, type)
end_define

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|bus_mode
argument_list|,
argument|BUS_MODE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|bus_width
argument_list|,
argument|BUS_WIDTH
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|chip_select
argument_list|,
argument|CHIP_SELECT
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|clock
argument_list|,
argument|CLOCK
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|f_max
argument_list|,
argument|F_MAX
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|f_min
argument_list|,
argument|F_MIN
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|host_ocr
argument_list|,
argument|HOST_OCR
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|mode
argument_list|,
argument|MODE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|ocr
argument_list|,
argument|OCR
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|power_mode
argument_list|,
argument|POWER_MODE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MMCBR_ACCESSOR
argument_list|(
argument|vdd
argument_list|,
argument|VDD
argument_list|,
argument|int
argument_list|)
end_macro

begin_function
specifier|static
name|int
name|__inline
name|mmcbr_update_ios
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|MMCBR_UPDATE_IOS
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_MMC_MMCBRVAR_H */
end_comment

end_unit

