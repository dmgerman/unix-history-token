begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_BROADCOM_BCM_NVRAM_CFE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_BROADCOM_BCM_NVRAM_CFE_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/nvram/bhnd_nvram.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/nvram/bhnd_nvram_iovar.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/nvram/bhnd_nvram_store.h>
end_include

begin_struct_decl
struct_decl|struct
name|bcm_nvram_iocfe
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|bcm_nvram_find_cfedev
parameter_list|(
name|struct
name|bcm_nvram_iocfe
modifier|*
name|iocfe
parameter_list|,
name|bhnd_nvram_data_class
modifier|*
modifier|*
name|cls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * CFE-backed bhnd_nvram_io implementation.  */
end_comment

begin_struct
struct|struct
name|bcm_nvram_iocfe
block|{
name|struct
name|bhnd_nvram_io
name|io
decl_stmt|;
comment|/**< common I/O instance state */
name|char
modifier|*
name|dname
decl_stmt|;
comment|/**< CFE device name (borrowed) */
name|int
name|fd
decl_stmt|;
comment|/**< CFE file descriptor */
name|size_t
name|offset
decl_stmt|;
comment|/**< base offset */
name|size_t
name|size
decl_stmt|;
comment|/**< device size */
name|bool
name|req_blk_erase
decl_stmt|;
comment|/**< flash blocks must be erased 						     before writing */
block|}
struct|;
end_struct

begin_comment
comment|/** bhnd_nvram_cfe driver instance state. */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_cfe_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|bhnd_nvram_store
modifier|*
name|store
decl_stmt|;
comment|/**< nvram store */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_BROADCOM_BCM_NVRAM_CFE_H_ */
end_comment

end_unit

