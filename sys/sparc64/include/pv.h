begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PV_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PV_H_
end_define

begin_decl_stmt
specifier|extern
name|vm_zone_t
name|pvzone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vm_zone
name|pvzone_store
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vm_object
name|pvzone_obj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pv_entry_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pv_entry_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pv_entry_high_water
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pv_entry
modifier|*
name|pvinit
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|pv_allocf
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|bytes
parameter_list|,
name|u_int8_t
modifier|*
name|flags
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pv_entry_t
name|pv_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pv_free
parameter_list|(
name|pv_entry_t
name|pv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pv_insert
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_page_t
name|m
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pv_entry_t
name|pv_lookup
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_page_t
name|m
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pv_remove
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_page_t
name|m
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pv_page_exists
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pv_remove_all
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pv_bit_clear
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|u_long
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pv_bit_count
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|u_long
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pv_bit_test
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|u_long
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PV_H_ */
end_comment

end_unit

