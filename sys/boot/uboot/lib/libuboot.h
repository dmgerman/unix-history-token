begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2000 Benno Rice.  * Copyright (C) 2007 Semihalf, Rafal Jaworowski<raj@semihalf.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|uboot_devdesc
block|{
name|struct
name|devsw
modifier|*
name|d_dev
decl_stmt|;
name|int
name|d_type
decl_stmt|;
name|int
name|d_unit
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|int
name|pnum
decl_stmt|;
name|int
name|ptype
decl_stmt|;
block|}
name|disk
struct|;
block|}
name|d_kind
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|d_disk
value|d_kind.disk
end_define

begin_define
define|#
directive|define
name|PTYPE_BSDLABEL
value|1
end_define

begin_define
define|#
directive|define
name|PTYPE_GPT
value|2
end_define

begin_define
define|#
directive|define
name|PTYPE_MBR
value|3
end_define

begin_comment
comment|/*  * Default network packet alignment in memory  */
end_comment

begin_define
define|#
directive|define
name|PKTALIGN
value|32
end_define

begin_function_decl
name|int
name|uboot_getdev
parameter_list|(
name|void
modifier|*
modifier|*
name|vdev
parameter_list|,
specifier|const
name|char
modifier|*
name|devspec
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|uboot_fmtdev
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uboot_setcurrdev
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

begin_decl_stmt
specifier|extern
name|int
name|devs_no
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|netif_driver
name|uboot_net
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|uboot_storage
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|uboot_vm_translate
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|uboot_copyin
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
specifier|const
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|uboot_copyout
parameter_list|(
specifier|const
name|vm_offset_t
name|src
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
specifier|const
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|uboot_readin
parameter_list|(
specifier|const
name|int
name|fd
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
specifier|const
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uboot_autoload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|preloaded_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|file_format
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|file_format
name|uboot_elf
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|reboot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

