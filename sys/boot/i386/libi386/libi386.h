begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * i386 fully-qualified device descriptor.  * Note, this must match the 'struct devdesc' declaration  * in bootstrap.h.  */
end_comment

begin_struct
struct|struct
name|i386_devdesc
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
name|int
name|unit
decl_stmt|;
name|int
name|slice
decl_stmt|;
name|int
name|partition
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|biosdisk
struct|;
struct|struct
block|{
name|int
name|unit
decl_stmt|;
comment|/* XXX net layer lives over these? */
block|}
name|netif
struct|;
block|}
name|d_kind
union|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|i386_getdev
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
name|i386_fmtdev
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i386_setcurrdev
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
name|devdesc
name|currdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our current device */
end_comment

begin_define
define|#
directive|define
name|MAXDEV
value|31
end_define

begin_comment
comment|/* maximum number of distinct devices */
end_comment

begin_comment
comment|/* exported devices XXX rename? */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|biosdisk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|pxedisk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|pxe_fsops
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_int32_t
name|bd_getbigeom
parameter_list|(
name|int
name|bunit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return geometry in bootinfo format */
end_comment

begin_function_decl
name|int
name|bd_bios2unit
parameter_list|(
name|int
name|biosdev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* xlate BIOS device -> biosdisk unit */
end_comment

begin_function_decl
name|int
name|bd_unit2bios
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* xlate biosdisk unit -> BIOS device */
end_comment

begin_function_decl
name|int
name|bd_getdev
parameter_list|(
name|struct
name|i386_devdesc
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return dev_t for (dev) */
end_comment

begin_function_decl
name|ssize_t
name|i386_copyin
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
name|i386_copyout
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
name|i386_readin
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
name|bios_getmem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_int32_t
name|bios_basemem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base memory in bytes */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|bios_extmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extended memory in bytes */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|memtop
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|gateA20
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i386_autoload
parameter_list|(
name|void
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
name|bi_load
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pxe_enable
parameter_list|(
name|void
modifier|*
name|pxeinfo
parameter_list|)
function_decl|;
end_function_decl

end_unit

