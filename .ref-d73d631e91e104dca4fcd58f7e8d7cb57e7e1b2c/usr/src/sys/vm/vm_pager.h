begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)vm_pager.h	7.1 (Berkeley) %G%  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"queue.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|vm_pager_null
value|((vm_pager_t) 0)
end_define

begin_comment
comment|/* XXX MACH compat */
end_comment

begin_define
define|#
directive|define
name|VM_PAGER_NULL
value|((vm_pager_t) 0)
end_define

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
parameter_list|()
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

begin_define
define|#
directive|define
name|PAGER_OPS_NULL
value|((struct pagerops *)0)
end_define

begin_comment
comment|/*  * get/put return values  * OK	operation was successful  * BAD	specified data was out of the accepted range  * FAIL	specified data was in range, but doesn't exist  * PEND	operations was initiated but not completed  */
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

begin_function_decl
name|vm_pager_t
name|vm_pager_allocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pager_deallocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_pager_get
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_pager_put
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_pager_has_page
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|vm_pager_map_page
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pager_unmap_page
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_pager_t
name|vm_pager_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pager_sync
parameter_list|()
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

