begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)device_pager.h	7.1 (Berkeley) 12/5/90  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|void
name|dev_pager_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_pager_t
name|dev_pager_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_pager_dealloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|boolean_t
name|dev_pager_getpage
argument_list|()
decl_stmt|,
name|dev_pager_putpage
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|boolean_t
name|dev_pager_haspage
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|pagerops
name|devicepagerops
init|=
block|{
name|dev_pager_init
block|,
name|dev_pager_alloc
block|,
name|dev_pager_dealloc
block|,
name|dev_pager_getpage
block|,
name|dev_pager_putpage
block|,
name|dev_pager_haspage
block|}
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
comment|/* _DEVICE_PAGER_ */
end_comment

end_unit

