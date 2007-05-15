begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Bernd Walter.  All rights reserved.  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * "$FreeBSD$"  */
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
comment|//    MMC_IVAR_,
block|}
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for pci devices  */
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
argument|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_MMC_MMCVAR_H */
end_comment

end_unit

