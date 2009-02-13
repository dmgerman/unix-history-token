begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_KERNELDUMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_KERNELDUMP_H_
end_define

begin_struct
struct|struct
name|sparc64_dump_reg
block|{
name|vm_paddr_t
name|dr_pa
decl_stmt|;
name|vm_offset_t
name|dr_size
decl_stmt|;
name|vm_offset_t
name|dr_offs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Kernel dump format for sparc64. This does not use ELF because it is of no  * avail (only libkvm knows how to translate addresses properly anyway) and  * would require some ugly hacks.  */
end_comment

begin_struct
struct|struct
name|sparc64_dump_hdr
block|{
name|vm_offset_t
name|dh_hdr_size
decl_stmt|;
name|vm_paddr_t
name|dh_tsb_pa
decl_stmt|;
name|vm_size_t
name|dh_tsb_size
decl_stmt|;
name|vm_size_t
name|dh_tsb_mask
decl_stmt|;
name|int
name|dh_nregions
decl_stmt|;
name|struct
name|sparc64_dump_reg
name|dh_regions
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_KERNELDUMP_H_ */
end_comment

end_unit

