begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_DEVMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_DEVMAP_H_
end_define

begin_comment
comment|/*  * This structure is used by MD code to describe static mappings of devices  * which are established as part of bringing up the MMU early in the boot.  */
end_comment

begin_struct
struct|struct
name|arm_devmap_entry
block|{
name|vm_offset_t
name|pd_va
decl_stmt|;
comment|/* virtual address */
name|vm_paddr_t
name|pd_pa
decl_stmt|;
comment|/* physical address */
name|vm_size_t
name|pd_size
decl_stmt|;
comment|/* size of region */
name|vm_prot_t
name|pd_prot
decl_stmt|;
comment|/* protection code */
name|int
name|pd_cache
decl_stmt|;
comment|/* cache attributes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Return the lowest KVA address used in any entry in the registered devmap  * table.  This works with whatever table is registered, including the internal  * table used by arm_devmap_add_entry() if that routine was used. Platforms can  * implement platform_lastaddr() by calling this if static device mappings are  * their only use of high KVA space.  */
end_comment

begin_function_decl
name|vm_offset_t
name|arm_devmap_lastaddr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Automatically allocate KVA (from the top of the address space downwards) and  * make static device mapping entries in an internal table.  The internal table  * is automatically registered on the first call to this.  */
end_comment

begin_function_decl
name|void
name|arm_devmap_add_entry
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Register a platform-local table to be bootstrapped by the generic  * initarm() in arm/machdep.c.  This is used by newer code that allocates and  * fills in its own local table but does not have its own initarm() routine.  */
end_comment

begin_function_decl
name|void
name|arm_devmap_register_table
parameter_list|(
specifier|const
name|struct
name|arm_devmap_entry
modifier|*
name|_table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Establish mappings for all the entries in the table.  This is called  * automatically from the common initarm() in arm/machdep.c, and also from the  * custom initarm() routines in older code.  If the table pointer is NULL, this  * will use the table installed previously by arm_devmap_register_table().  */
end_comment

begin_function_decl
name|void
name|arm_devmap_bootstrap
parameter_list|(
name|vm_offset_t
name|_l1pt
parameter_list|,
specifier|const
name|struct
name|arm_devmap_entry
modifier|*
name|_table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Translate between virtual and physical addresses within a region that is  * static-mapped by the devmap code.  If the given address range isn't  * static-mapped, then ptov returns NULL and vtop returns DEVMAP_PADDR_NOTFOUND.  * The latter implies that you can't vtop just the last byte of physical address  * space.  This is not as limiting as it might sound, because even if a device  * occupies the end of the physical address space, you're only prevented from  * doing vtop for that single byte.  If you vtop a size bigger than 1 it works.  */
end_comment

begin_define
define|#
directive|define
name|DEVMAP_PADDR_NOTFOUND
value|((vm_paddr_t)(-1))
end_define

begin_function_decl
name|void
modifier|*
name|arm_devmap_ptov
parameter_list|(
name|vm_paddr_t
name|_pa
parameter_list|,
name|vm_size_t
name|_sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|arm_devmap_vtop
parameter_list|(
name|void
modifier|*
name|_va
parameter_list|,
name|vm_size_t
name|_sz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print the static mapping table; used for bootverbose output. */
end_comment

begin_function_decl
name|void
name|arm_devmap_print_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

