begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_IO_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_IO_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_io
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|bhnd_nvram_io
modifier|*
name|bhnd_nvram_iobuf_new
parameter_list|(
specifier|const
name|void
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_nvram_io
modifier|*
name|bhnd_nvram_iobuf_empty
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|capacity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_nvram_io
modifier|*
name|bhnd_nvram_iobuf_copy
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_nvram_io
modifier|*
name|bhnd_nvram_iobuf_copy_range
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|src
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_nvram_io
modifier|*
name|bhnd_nvram_ioptr_new
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|capacity
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|struct
name|bhnd_nvram_io
modifier|*
name|bhnd_nvram_iores_new
parameter_list|(
name|struct
name|bhnd_resource
modifier|*
name|r
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|u_int
name|bus_width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_function_decl
name|size_t
name|bhnd_nvram_io_getsize
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_io_setsize
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_io_read
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_io_read_ptr
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
name|size_t
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|ptr
parameter_list|,
name|size_t
name|nbytes
parameter_list|,
name|size_t
modifier|*
name|navail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_io_write
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_io_write_ptr
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|void
modifier|*
modifier|*
name|ptr
parameter_list|,
name|size_t
name|nbytes
parameter_list|,
name|size_t
modifier|*
name|navail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvram_io_free
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * bhnd_nvram_ioptr flags  */
end_comment

begin_enum
enum|enum
block|{
name|BHND_NVRAM_IOPTR_RDONLY
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/**< read-only */
name|BHND_NVRAM_IOPTR_RDWR
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/**< read/write */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_IO_H_ */
end_comment

end_unit

