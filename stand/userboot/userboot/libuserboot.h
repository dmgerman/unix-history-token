begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Google, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"userboot.h"
end_include

begin_decl_stmt
specifier|extern
name|struct
name|loader_callbacks
modifier|*
name|callbacks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|callbacks_arg
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CALLBACK
parameter_list|(
name|fn
parameter_list|,
name|args
modifier|...
parameter_list|)
value|(callbacks->fn(callbacks_arg , ##args))
end_define

begin_define
define|#
directive|define
name|MAXDEV
value|31
end_define

begin_comment
comment|/* maximum number of distinct devices */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|physaddr_t
typedef|;
end_typedef

begin_comment
comment|/* exported devices */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|userboot_disk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|userboot_disk_maxunit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|host_dev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* access to host filesystem */
end_comment

begin_decl_stmt
name|struct
name|fs_ops
name|host_fsops
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|bootinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|preloaded_file
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|bi_load
parameter_list|(
name|struct
name|bootinfo
modifier|*
parameter_list|,
name|struct
name|preloaded_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delay
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|userboot_autoload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|userboot_copyin
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|userboot_copyout
parameter_list|(
name|vm_offset_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|userboot_readin
parameter_list|(
name|int
parameter_list|,
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|userboot_getdev
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|userboot_fmtdev
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|userboot_setcurrdev
parameter_list|(
name|struct
name|env_var
modifier|*
name|ev
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bi_getboothowto
parameter_list|(
name|char
modifier|*
name|kargs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bi_setboothowto
parameter_list|(
name|int
name|howto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|bi_copyenv
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bi_load32
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
modifier|*
name|howtop
parameter_list|,
name|int
modifier|*
name|bootdevp
parameter_list|,
name|vm_offset_t
modifier|*
name|bip
parameter_list|,
name|vm_offset_t
modifier|*
name|modulep
parameter_list|,
name|vm_offset_t
modifier|*
name|kernend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bi_load64
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|vm_offset_t
modifier|*
name|modulep
parameter_list|,
name|vm_offset_t
modifier|*
name|kernend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bios_addsmapdata
parameter_list|(
name|struct
name|preloaded_file
modifier|*
name|kfp
parameter_list|)
function_decl|;
end_function_decl

end_unit

