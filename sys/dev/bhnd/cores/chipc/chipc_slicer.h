begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michael Zhilin<mizhka@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_CHIPC_CHIPC_SLICER_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_CHIPC_CHIPC_SLICER_H_
end_define

begin_include
include|#
directive|include
file|<sys/slicer.h>
end_include

begin_include
include|#
directive|include
file|"chipcvar.h"
end_include

begin_define
define|#
directive|define
name|TRX_MAGIC
value|0x30524448
end_define

begin_define
define|#
directive|define
name|CFE_MAGIC
value|0x43464531
end_define

begin_define
define|#
directive|define
name|NVRAM_MAGIC
value|0x48534C46
end_define

begin_function_decl
name|void
name|chipc_register_slicer
parameter_list|(
name|chipc_flash
name|flash_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chipc_slicer_spi
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|provider
parameter_list|,
name|struct
name|flash_slice
modifier|*
name|slices
parameter_list|,
name|int
modifier|*
name|nslices
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chipc_slicer_cfi
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|provider
parameter_list|,
name|struct
name|flash_slice
modifier|*
name|slices
parameter_list|,
name|int
modifier|*
name|nslices
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_CHIPC_CHIPC_SLICER_H_ */
end_comment

end_unit

