begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)device_pager.h	8.3 (Berkeley) %G%  */
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
name|struct
name|pglist
name|devp_pglist
decl_stmt|;
comment|/* list of pages allocated */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEVICE_PAGER_ */
end_comment

end_unit

