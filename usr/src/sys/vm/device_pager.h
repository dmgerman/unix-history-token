begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)device_pager.h	7.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVICE_PAGER_
end_ifndef

begin_define
define|#
directive|define
name|_DEVICE_PAGER_
value|1
end_define

begin_comment
comment|/*  * Device pager private data.  */
end_comment

begin_struct
struct|struct
name|devpager
block|{
name|queue_head_t
name|devp_list
decl_stmt|;
comment|/* list of managed devices */
name|dev_t
name|devp_dev
decl_stmt|;
comment|/* devno of device */
name|vm_page_t
name|devp_pages
decl_stmt|;
comment|/* page structs for device */
name|int
name|devp_npages
decl_stmt|;
comment|/* size of device in pages */
name|int
name|devp_count
decl_stmt|;
comment|/* reference count */
name|vm_object_t
name|devp_object
decl_stmt|;
comment|/* object representing this device */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|devpager
modifier|*
name|dev_pager_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEV_PAGER_NULL
value|((dev_pager_t)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEVICE_PAGER_ */
end_comment

end_unit

