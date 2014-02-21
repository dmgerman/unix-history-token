begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Robert N. M. Watson  * Copyright (C) 1994 by Rodney W. Grimes, Milwaukie, Oregon  97222  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Rodney W. Grimes.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY RODNEY W. GRIMES ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL RODNEY W. GRIMES BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BOOTINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BOOTINFO_H_
end_define

begin_comment
comment|/* Only change the version number if you break compatibility. */
end_comment

begin_define
define|#
directive|define
name|BOOTINFO_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|MIPS_BOOTINFO_MAGIC
value|0xCDEACDEA
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_typedef
typedef|typedef
name|uint64_t
name|bi_ptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|uint32_t
name|bi_ptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * A zero bootinfo field often means that there is no info available.  * Flags are used to indicate the validity of fields where zero is a  * normal value.  */
end_comment

begin_struct
struct|struct
name|bootinfo
block|{
comment|/* bootinfo meta-data. */
name|uint32_t
name|bi_version
decl_stmt|;
name|uint32_t
name|bi_size
decl_stmt|;
comment|/* bootinfo contents. */
name|uint64_t
name|bi_boot2opts
decl_stmt|;
comment|/* boot2 flags to loader. */
name|bi_ptr_t
name|bi_kernelname
decl_stmt|;
comment|/* Pointer to name. */
name|bi_ptr_t
name|bi_nfs_diskless
decl_stmt|;
comment|/* Pointer to NFS data. */
name|bi_ptr_t
name|bi_dtb
decl_stmt|;
comment|/* Pointer to dtb. */
name|bi_ptr_t
name|bi_memsize
decl_stmt|;
comment|/* Physical memory size in bytes. */
name|bi_ptr_t
name|bi_modulep
decl_stmt|;
comment|/* Preloaded modules. */
name|bi_ptr_t
name|bi_boot_dev_type
decl_stmt|;
comment|/* Boot-device type. */
name|bi_ptr_t
name|bi_boot_dev_unitptr
decl_stmt|;
comment|/* Boot-device unit/pointer. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Possible boot-device types passed from boot2 to loader, loader to kernel.  * In most cases, the object pointed to will hold a filesystem; one exception  * is BOOTINFO_DEV_TYPE_DRAM, which points to a pre-loaded object (e.g.,  * loader, kernel).  */
end_comment

begin_define
define|#
directive|define
name|BOOTINFO_DEV_TYPE_DRAM
value|0
end_define

begin_comment
comment|/* DRAM loader/kernel (ptr). */
end_comment

begin_define
define|#
directive|define
name|BOOTINFO_DEV_TYPE_CFI
value|1
end_define

begin_comment
comment|/* CFI flash (unit). */
end_comment

begin_define
define|#
directive|define
name|BOOTINFO_DEV_TYPE_SDCARD
value|2
end_define

begin_comment
comment|/* SD card (unit). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|bootinfo
name|bootinfo
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BOOTINFO_H_ */
end_comment

end_unit

