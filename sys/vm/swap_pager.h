begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)swap_pager.h	7.1 (Berkeley) 12/5/90  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Modifications to the block allocation data structure by John S. Dyson  * 18 Dec 93.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_SWAP_PAGER_H_
end_ifndef

begin_define
define|#
directive|define
name|_VM_SWAP_PAGER_H_
value|1
end_define

begin_comment
comment|/*  * Swap device table  */
end_comment

begin_struct
struct|struct
name|swdevt
block|{
name|udev_t
name|sw_dev
decl_stmt|;
comment|/* For quasibogus swapdev reporting */
name|int
name|sw_flags
decl_stmt|;
name|int
name|sw_nblks
decl_stmt|;
name|int
name|sw_used
decl_stmt|;
name|struct
name|vnode
modifier|*
name|sw_vp
decl_stmt|;
name|dev_t
name|sw_device
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SW_FREED
value|0x01
end_define

begin_define
define|#
directive|define
name|SW_SEQUENTIAL
value|0x02
end_define

begin_define
define|#
directive|define
name|SW_CLOSING
value|0x04
end_define

begin_define
define|#
directive|define
name|sw_freed
value|sw_flags
end_define

begin_comment
comment|/* XXX compat */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|swap_pager_full
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vm_swap_size
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|swap_pager_putpages
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_page_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_copy
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_freespace
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_swap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swap_pager_isswapped
parameter_list|(
name|vm_object_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swap_pager_reserve
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_status
parameter_list|(
name|int
modifier|*
name|total
parameter_list|,
name|int
modifier|*
name|used
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VM_SWAP_PAGER_H_ */
end_comment

end_unit

