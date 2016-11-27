begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_IOVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_IOVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_io.h"
end_include

begin_comment
comment|/** @see bhnd_nvram_io_read() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_iop_read
function_decl|)
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
end_typedef

begin_comment
comment|/** @see bhnd_nvram_io_read_ptr() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_iop_read_ptr
function_decl|)
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
end_typedef

begin_comment
comment|/** @see bhnd_nvram_io_write() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_iop_write
function_decl|)
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
end_typedef

begin_comment
comment|/** @see bhnd_nvram_io_write_ptr() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_iop_write_ptr
function_decl|)
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
end_typedef

begin_comment
comment|/** @see bhnd_nvram_io_getsize() */
end_comment

begin_typedef
typedef|typedef
name|size_t
function_decl|(
name|bhnd_nvram_iop_getsize
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_io_setsize() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_iop_setsize
function_decl|)
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
end_typedef

begin_comment
comment|/** @see bhnd_nvram_io_free() */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|bhnd_nvram_iop_free
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * NVRAM abstract I/O operations.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_iops
block|{
name|bhnd_nvram_iop_read
modifier|*
name|read
decl_stmt|;
comment|/**< read() implementation */
name|bhnd_nvram_iop_read_ptr
modifier|*
name|read_ptr
decl_stmt|;
comment|/**< read_ptr() implementation */
name|bhnd_nvram_iop_getsize
modifier|*
name|getsize
decl_stmt|;
comment|/**< getsize() implementation */
name|bhnd_nvram_iop_setsize
modifier|*
name|setsize
decl_stmt|;
comment|/**< setsize() implementation */
name|bhnd_nvram_iop_write
modifier|*
name|write
decl_stmt|;
comment|/**< write() implementation */
name|bhnd_nvram_iop_write_ptr
modifier|*
name|write_ptr
decl_stmt|;
comment|/**< write_ptr() implementation */
name|bhnd_nvram_iop_free
modifier|*
name|free
decl_stmt|;
comment|/**< free() implementation */
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM abstract I/O context.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_io
block|{
specifier|const
name|struct
name|bhnd_nvram_iops
modifier|*
name|iops
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Declare a bhnd_nvram_iops class with name @p _n.  */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_IOPS_DEFN
parameter_list|(
name|_n
parameter_list|)
define|\
value|static bhnd_nvram_iop_read	bhnd_nvram_ ## _n ## _read;	\ 	static bhnd_nvram_iop_read_ptr	bhnd_nvram_ ## _n ## _read_ptr;	\ 	static bhnd_nvram_iop_write	bhnd_nvram_ ## _n ## _write;	\ 	static bhnd_nvram_iop_write_ptr	bhnd_nvram_ ## _n ## _write_ptr;\ 	static bhnd_nvram_iop_getsize	bhnd_nvram_ ## _n ## _getsize;	\ 	static bhnd_nvram_iop_setsize	bhnd_nvram_ ## _n ## _setsize;	\ 	static bhnd_nvram_iop_free	bhnd_nvram_ ## _n ## _free;	\ 									\ 	static struct bhnd_nvram_iops	bhnd_nvram_ ## _n ## _ops = {	\ 		.read		= bhnd_nvram_ ## _n ## _read,		\ 		.read_ptr	= bhnd_nvram_ ## _n ## _read_ptr,	\ 		.write		= bhnd_nvram_ ## _n ## _write,		\ 		.write_ptr	= bhnd_nvram_ ## _n ## _write_ptr,	\ 		.getsize	= bhnd_nvram_ ## _n ## _getsize,	\ 		.setsize	= bhnd_nvram_ ## _n ## _setsize,	\ 		.free		= bhnd_nvram_ ## _n ## _free		\ 	};
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_IOVAR_H_ */
end_comment

end_unit

