begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000 Benno Rice.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"openfirm.h"
end_include

begin_comment
comment|/* Note: Must match the 'struct devdesc' in bootstrap.h */
end_comment

begin_struct
struct|struct
name|ofw_devdesc
block|{
name|struct
name|devsw
modifier|*
name|d_dev
decl_stmt|;
name|int
name|d_type
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|phandle_t
name|handle
decl_stmt|;
comment|/* OFW handle */
name|unsigned
name|long
name|partoff
decl_stmt|;
comment|/* sector offset */
name|int
name|unit
decl_stmt|;
comment|/* disk number */
name|char
name|path
index|[
literal|64
index|]
decl_stmt|;
comment|/* OFW path */
name|int
name|slice
decl_stmt|;
comment|/* slice# */
name|int
name|partition
decl_stmt|;
comment|/* partition in slice */
name|int
name|bsize
decl_stmt|;
comment|/* block size */
block|}
name|ofwdisk
struct|;
struct|struct
block|{
name|int
name|unit
decl_stmt|;
name|char
name|path
index|[
literal|64
index|]
decl_stmt|;
name|void
modifier|*
name|dmabuf
decl_stmt|;
block|}
name|netif
struct|;
block|}
name|d_kind
union|;
comment|/*  * Keeping this around so I know what came from the NetBSD stuff.  * I've made a wild guess as to what goes where, but I have no idea if it's  * right.  *  *	void *dmabuf;  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXDEV
value|31
end_define

begin_comment
comment|/* Maximum number of devices. */
end_comment

begin_comment
comment|/* Known types.  Use the same as alpha for consistancy. */
end_comment

begin_define
define|#
directive|define
name|DEVT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|DEVT_DISK
value|1
end_define

begin_define
define|#
directive|define
name|DEVT_NET
value|2
end_define

begin_function_decl
specifier|extern
name|int
name|ofw_getdev
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
specifier|extern
name|char
modifier|*
name|ofw_fmtdev
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ofw_parseofwdev
parameter_list|(
name|struct
name|ofw_devdesc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|devspec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ofw_setcurrdev
parameter_list|(
name|struct
name|env_var
modifier|*
name|ev
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|ofwdisk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|netif_driver
name|ofwnet
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ofwd_getunit
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofwn_getunit
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|ofw_copyin
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
name|ofw_copyout
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
name|ofw_readin
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
name|void
name|ofw_devsearch_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_devsearch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_devicetype
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ofw_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ofw_autoload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofw_memmap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ofw_alloc_heap
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofw_release_heap
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

begin_function_decl
name|int
name|ofw_elf_loadfile
parameter_list|(
name|char
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|struct
name|preloaded_file
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_elf_exec
parameter_list|(
name|struct
name|preloaded_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|file_format
name|ofw_elf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|reboot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|main
parameter_list|(
name|int
function_decl|(
modifier|*
name|openfirm
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ofw_reg
block|{
name|cell_t
name|base
decl_stmt|;
name|cell_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

end_unit

