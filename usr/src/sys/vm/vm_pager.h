begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)vm_pager.h	7.4 (Berkeley) %G%  */
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
argument_list|(
argument|*pgo_init
argument_list|)
comment|/* Initialize pager. */
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|vm_pager_t
argument_list|(
argument|*pgo_alloc
argument_list|)
comment|/* Allocate pager. */
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|vm_size_t
operator|,
name|vm_prot_t
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*pgo_dealloc
argument_list|)
comment|/* Disassociate. */
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pgo_getpage
argument_list|)
comment|/* Get (read) page. */
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
argument|*pgo_putpage
argument_list|)
comment|/* Put (write) page. */
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
name|boolean_t
argument_list|(
argument|*pgo_haspage
argument_list|)
comment|/* Does pager have page? */
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * get/put return values  * OK	 operation was successful  * BAD	 specified data was out of the accepted range  * FAIL	 specified data was in range, but doesn't exist  * PEND	 operations was initiated but not completed  * ERROR error while accessing data that is in range and exists  */
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
name|VM_PAGER_ALLOC
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|)
value|(*(pg)->pg_ops->pgo_alloc)(h, s, p)
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
name|caddr_t
operator|,
name|vm_size_t
operator|,
name|vm_prot_t
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
name|vm_pager_get
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
name|queue_head_t
operator|*
operator|,
name|caddr_t
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
name|vm_pager_put
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
name|vm_pager_unmap_page
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|)
argument_list|)
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

