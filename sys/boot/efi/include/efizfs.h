begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Eric McCorkle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_EFIZFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFIZFS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EFI_ZFS_BOOT
end_ifdef

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument|zfsinfo_list
argument_list|,
argument|zfsinfo
argument_list|)
name|zfsinfo_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|zfsinfo
block|{
name|STAILQ_ENTRY
argument_list|(
argument|zfsinfo
argument_list|)
name|zi_link
expr_stmt|;
name|EFI_HANDLE
name|zi_handle
decl_stmt|;
name|uint64_t
name|zi_pool_guid
decl_stmt|;
block|}
name|zfsinfo_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|uint64_t
name|pool_guid
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|efi_zfs_probe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|zfsinfo_list_t
modifier|*
name|efizfs_get_zfsinfo_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

