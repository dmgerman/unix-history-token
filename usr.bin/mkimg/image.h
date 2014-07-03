begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MKIMG_IMAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MKIMG_IMAGE_H_
end_define

begin_typedef
typedef|typedef
name|int64_t
name|lba_t
typedef|;
end_typedef

begin_function_decl
name|int
name|image_copyin
parameter_list|(
name|lba_t
name|blk
parameter_list|,
name|int
name|fd
parameter_list|,
name|uint64_t
modifier|*
name|sizep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|image_copyout
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|image_copyout_region
parameter_list|(
name|int
name|fd
parameter_list|,
name|lba_t
name|blk
parameter_list|,
name|lba_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lba_t
name|image_get_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|image_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|image_set_size
parameter_list|(
name|lba_t
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|image_write
parameter_list|(
name|lba_t
name|blk
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|ssize_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MKIMG_IMAGE_H_ */
end_comment

end_unit

