begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vm_pager.h	8.4 (Berkeley) 1/12/94  * $FreeBSD$  */
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

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pagerlst
argument_list|,
name|pager_struct
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|pager_struct
block|{
name|TAILQ_ENTRY
argument_list|(
argument|pager_struct
argument_list|)
name|pg_list
expr_stmt|;
comment|/* links for list management */
name|void
modifier|*
name|pg_handle
decl_stmt|;
comment|/* ext. handle (vp, dev, fp) */
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
name|void
modifier|*
name|pg_data
decl_stmt|;
comment|/* private pager data */
block|}
struct|;
end_struct

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

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|PG_CLUSTERGET
value|1
end_define

begin_define
define|#
directive|define
name|PG_CLUSTERPUT
value|2
end_define

begin_struct
struct|struct
name|pagerops
block|{
name|void
argument_list|(
argument|*pgo_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Initialize pager. */
name|vm_pager_t
argument_list|(
argument|*pgo_alloc
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|vm_size_t
operator|,
name|vm_prot_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Allocate pager. */
name|void
argument_list|(
argument|*pgo_dealloc
argument_list|)
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Disassociate. */
name|int
argument_list|(
argument|*pgo_getpage
argument_list|)
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_page_t
operator|,
name|boolean_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pgo_getpages
argument_list|)
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_page_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|boolean_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Get (read) page. */
name|int
argument_list|(
argument|*pgo_putpage
argument_list|)
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_page_t
operator|,
name|boolean_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pgo_putpages
argument_list|)
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_page_t
operator|*
operator|,
name|int
operator|,
name|boolean_t
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Put (write) page. */
name|boolean_t
argument_list|(
argument|*pgo_haspage
argument_list|)
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Does pager have page? */
block|}
struct|;
end_struct

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
value|(*(pg)->pg_ops->pgo_getpages)(pg, m, c, r, s)
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
name|VM_PAGER_PUT_MULTI
parameter_list|(
name|pg
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|,
name|rtval
parameter_list|)
value|(*(pg)->pg_ops->pgo_putpages)(pg, m, c, s, rtval)
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

begin_comment
comment|/*  * get/put return values  * OK	 operation was successful  * BAD	 specified data was out of the accepted range  * FAIL	 specified data was in range, but doesn't exist  * PEND	 operations was initiated but not completed  * ERROR error while accessing data that is in range and exists  * AGAIN temporary resource shortage prevented operation from happening  */
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
name|VM_PAGER_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|VM_PAGER_AGAIN
value|5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pagerops
modifier|*
name|dfltpagerops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_pager_t
name|vm_pager_allocate
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|vm_size_t
operator|,
name|vm_prot_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_page_t
name|vm_pager_atop
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_pager_bufferinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_pager_deallocate
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_pager_get_pages
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_page_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|vm_pager_has_page
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_pager_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_pager_t
name|vm_pager_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|pagerlst
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|vm_pager_map_pages
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|*
operator|,
name|int
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|vm_pager_map_page
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_pager_put_pages
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_page_t
operator|*
operator|,
name|int
operator|,
name|boolean_t
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_pager_sync
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_pager_unmap_pages
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_pager_unmap_page
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * XXX compat with old interface  */
end_comment

begin_define
define|#
directive|define
name|vm_pager_get
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
define|\
value|({ \ 	vm_page_t ml[1]; \ 	ml[0] = (m); \ 	vm_pager_get_pages(p, ml, 1, 0, s); \ })
end_define

begin_define
define|#
directive|define
name|vm_pager_put
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
define|\
value|({ \ 	int rtval; \ 	vm_page_t ml[1]; \ 	ml[0] = (m); \ 	vm_pager_put_pages(p, ml, 1, s,&rtval); \ 	rtval; \ })
end_define

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

