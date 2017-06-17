begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * i386 fully-qualified device descriptor.  * Note, this must match the 'struct devdesc' declaration  * in bootstrap.h and also with struct zfs_devdesc for zfs  * support.  */
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
name|slice
decl_stmt|;
name|int
name|partition
decl_stmt|;
name|off_t
name|offset
decl_stmt|;
block|}
name|biosdisk
struct|;
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|bioscd
struct|;
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|uint64_t
name|pool_guid
decl_stmt|;
name|uint64_t
name|root_guid
decl_stmt|;
block|}
name|zfs
struct|;
block|}
name|d_kind
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * relocater trampoline support.  */
end_comment

begin_struct
struct|struct
name|relocate_data
block|{
name|uint32_t
name|src
decl_stmt|;
name|uint32_t
name|dest
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|relocater
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint32_t
name|relocater_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|relocater_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_ip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_cs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_ds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_es
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_fs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_gs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_ss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_sp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|relocator_esi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|relocator_eax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|relocator_ebx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|relocator_edx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|relocator_ebp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint16_t
name|relocator_a20_enabled
decl_stmt|;
end_decl_stmt

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
specifier|const
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

begin_define
define|#
directive|define
name|MAXBDDEV
value|MAXDEV
end_define

begin_comment
comment|/* exported devices XXX rename? */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|bioscd
decl_stmt|;
end_decl_stmt

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
name|int
name|bc_add
parameter_list|(
name|int
name|biosdev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register CD booted from. */
end_comment

begin_function_decl
name|int
name|bc_getdev
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
name|int
name|bc_bios2unit
parameter_list|(
name|int
name|biosdev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* xlate BIOS device -> bioscd unit */
end_comment

begin_function_decl
name|int
name|bc_unit2bios
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* xlate bioscd unit -> BIOS device */
end_comment

begin_function_decl
name|uint32_t
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

begin_struct_decl
struct_decl|struct
name|preloaded_file
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|bios_addsmapdata
parameter_list|(
name|struct
name|preloaded_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bios_getsmap
parameter_list|(
name|void
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
name|uint32_t
name|bios_basemem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base memory in bytes */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
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

begin_comment
comment|/* last address of physical memory + 1 */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|memtop_copyin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memtop less heap size for the cases */
end_comment

begin_comment
comment|/*  when heap is at the top of         */
end_comment

begin_comment
comment|/*  extended memory; for other cases   */
end_comment

begin_comment
comment|/*  just the same as memtop            */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|high_heap_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extended memory region available */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|high_heap_base
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for use as the heap */
end_comment

begin_function_decl
name|void
name|biospci_detect
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|biospci_find_devclass
parameter_list|(
name|uint32_t
name|class
parameter_list|,
name|int
name|index
parameter_list|,
name|uint32_t
modifier|*
name|locator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|biospci_read_config
parameter_list|(
name|uint32_t
name|locator
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|width
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|biospci_locator
parameter_list|(
name|int8_t
name|bus
parameter_list|,
name|uint8_t
name|device
parameter_list|,
name|uint8_t
name|function
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|biospci_write_config
parameter_list|(
name|uint32_t
name|locator
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|width
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|biosacpi_detect
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
name|addr
parameter_list|,
name|vm_offset_t
modifier|*
name|modulep
parameter_list|,
name|vm_offset_t
modifier|*
name|kernend
parameter_list|,
name|int
name|add_smap
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

