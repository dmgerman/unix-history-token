begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_pager.h	7.2 (Berkeley) 4/20/91  *	$Id: vm_pager.h,v 1.5 1994/01/17 09:34:03 davidg Exp $  */
end_comment

begin_comment
comment|/*  * Pager routine interface definition.  * For BSD we use a cleaner version of the internal pager interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_PAGER_
end_ifndef

begin_define
define|#
directive|define
name|_VM_PAGER_
end_define

begin_struct
struct|struct
name|pager_struct
block|{
name|queue_head_t
name|pg_list
decl_stmt|;
comment|/* links for list management */
name|caddr_t
name|pg_handle
decl_stmt|;
comment|/* external handle (vp, dev, fp) */
name|int
name|pg_type
decl_stmt|;
comment|/* type of pager */
name|struct
name|pagerops
modifier|*
name|pg_ops
decl_stmt|;
comment|/* pager operations */
name|caddr_t
name|pg_data
decl_stmt|;
comment|/* private pager data */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pager_struct
modifier|*
name|vm_pager_t
typedef|;
end_typedef

begin_comment
comment|/* pager types */
end_comment

begin_define
define|#
directive|define
name|PG_DFLT
value|-1
end_define

begin_define
define|#
directive|define
name|PG_SWAP
value|0
end_define

begin_define
define|#
directive|define
name|PG_VNODE
value|1
end_define

begin_define
define|#
directive|define
name|PG_DEVICE
value|2
end_define

begin_struct
struct|struct
name|pagerops
block|{
name|void
function_decl|(
modifier|*
name|pgo_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* initialize pager */
name|vm_pager_t
function_decl|(
modifier|*
name|pgo_alloc
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
comment|/* allocate pager */
name|void
function_decl|(
modifier|*
name|pgo_dealloc
function_decl|)
parameter_list|()
function_decl|;
comment|/* disassociate */
name|int
function_decl|(
modifier|*
name|pgo_getpage
function_decl|)
parameter_list|()
function_decl|;
comment|/* get (read) page */
name|int
function_decl|(
modifier|*
name|pgo_getmulti
function_decl|)
parameter_list|()
function_decl|;
comment|/* get (read) multiple pages */
name|int
function_decl|(
modifier|*
name|pgo_putpage
function_decl|)
parameter_list|()
function_decl|;
comment|/* put (write) page */
name|boolean_t
function_decl|(
modifier|*
name|pgo_haspage
function_decl|)
parameter_list|()
function_decl|;
comment|/* does pager have page? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * get/put return values  * OK	operation was successful  * BAD	specified data was out of the accepted range  * FAIL	specified data was in range, but doesn't exist  * PEND	operations was initiated but not completed  * TRYAGAIN operation will be successful in the future  */
end_comment

begin_define
define|#
directive|define
name|VM_PAGER_OK
value|0
end_define

begin_define
define|#
directive|define
name|VM_PAGER_BAD
value|1
end_define

begin_define
define|#
directive|define
name|VM_PAGER_FAIL
value|2
end_define

begin_define
define|#
directive|define
name|VM_PAGER_PEND
value|3
end_define

begin_define
define|#
directive|define
name|VM_PAGER_TRYAGAIN
value|4
end_define

begin_define
define|#
directive|define
name|VM_PAGER_ALLOC
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|,
name|o
parameter_list|)
value|(*(pg)->pg_ops->pgo_alloc)(h, s, p, o)
end_define

begin_define
define|#
directive|define
name|VM_PAGER_DEALLOC
parameter_list|(
name|pg
parameter_list|)
value|(*(pg)->pg_ops->pgo_dealloc)(pg)
end_define

begin_define
define|#
directive|define
name|VM_PAGER_GET
parameter_list|(
name|pg
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
value|(*(pg)->pg_ops->pgo_getpage)(pg, m, s)
end_define

begin_define
define|#
directive|define
name|VM_PAGER_GET_MULTI
parameter_list|(
name|pg
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|,
name|r
parameter_list|,
name|s
parameter_list|)
value|(*(pg)->pg_ops->pgo_getmulti)(pg, m, c, r, s)
end_define

begin_define
define|#
directive|define
name|VM_PAGER_PUT
parameter_list|(
name|pg
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
value|(*(pg)->pg_ops->pgo_putpage)(pg, m, s)
end_define

begin_define
define|#
directive|define
name|VM_PAGER_HASPAGE
parameter_list|(
name|pg
parameter_list|,
name|o
parameter_list|)
value|(*(pg)->pg_ops->pgo_haspage)(pg, o)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|vm_pager_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_pager_t
name|vm_pager_allocate
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vm_pager_deallocate
parameter_list|(
name|vm_pager_t
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|vm_page
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|vm_pager_get
parameter_list|(
name|vm_pager_t
parameter_list|,
name|struct
name|vm_page
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vm_pager_put
parameter_list|(
name|vm_pager_t
parameter_list|,
name|struct
name|vm_page
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean_t
name|vm_pager_has_page
parameter_list|(
name|vm_pager_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vm_pager_sync
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_offset_t
name|vm_pager_map_page
parameter_list|(
name|struct
name|vm_page
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vm_pager_unmap_page
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_pager_t
name|vm_pager_lookup
parameter_list|(
name|queue_head_t
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|pagerops
modifier|*
name|dfltpagerops
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
comment|/* _VM_PAGER_ */
end_comment

end_unit

