begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: hp300: @(#)pmap.h 7.2 (Berkeley) 12/16/90  *	from: @(#)pmap.h        7.4 (Berkeley) 5/12/91  *	from: FreeBSD: src/sys/i386/include/pmap.h,v 1.70 2000/11/30  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PMAP_H_
end_define

begin_include
include|#
directive|include
file|<machine/tte.h>
end_include

begin_define
define|#
directive|define
name|PMAP_CONTEXT_MAX
value|8192
end_define

begin_define
define|#
directive|define
name|pmap_resident_count
parameter_list|(
name|pm
parameter_list|)
value|(pm->pm_stats.resident_count)
end_define

begin_typedef
typedef|typedef
name|struct
name|pmap
modifier|*
name|pmap_t
typedef|;
end_typedef

begin_struct
struct|struct
name|md_page
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|stte
name|pm_stte
decl_stmt|;
name|vm_object_t
name|pm_object
decl_stmt|;
name|u_int
name|pm_active
decl_stmt|;
name|u_int
name|pm_context
decl_stmt|;
name|u_int
name|pm_count
decl_stmt|;
name|u_int
name|pm_pages
decl_stmt|;
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
name|vm_offset_t
name|ekva
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pmap_kextract
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kenter_flags
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_offset_t
name|pa
parameter_list|,
name|u_long
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|pmap_kextract(((vm_offset_t) (va)))
end_define

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|avail_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|avail_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pmap
modifier|*
name|kernel_pmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|phys_avail
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|virtual_avail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|virtual_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|msgbuf_phys
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|int
name|pmap_track_modified
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
return|return
operator|(
operator|(
name|va
operator|<
name|kmi
operator|.
name|clean_sva
operator|)
operator|||
operator|(
name|va
operator|>=
name|kmi
operator|.
name|clean_eva
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PMAP_H_ */
end_comment

end_unit

