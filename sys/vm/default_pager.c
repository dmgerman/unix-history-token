begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, David Greenman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by David Greenman.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The default pager is responsible for supplying backing store to unbacked  * storage.  The backing store is usually swap so we just fall through to  * the swap routines.  However, since swap metadata has not been assigned,  * the swap routines assign and manage the swap backing store through the  * vm_page->swapblk field.  The object is only converted when the page is   * physically freed after having been cleaned and even then vm_page->swapblk  * is maintained whenever a resident page also has swap backing store.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pager.h>
end_include

begin_include
include|#
directive|include
file|<vm/swap_pager.h>
end_include

begin_function_decl
specifier|static
name|vm_object_t
name|default_pager_alloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vm_ooffset_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_ooffset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|default_pager_dealloc
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|default_pager_getpages
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_page_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|default_pager_putpages
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
specifier|static
name|boolean_t
name|default_pager_haspage
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * pagerops for OBJT_DEFAULT - "default pager".  */
end_comment

begin_decl_stmt
name|struct
name|pagerops
name|defaultpagerops
init|=
block|{
name|NULL
block|,
name|default_pager_alloc
block|,
name|default_pager_dealloc
block|,
name|default_pager_getpages
block|,
name|default_pager_putpages
block|,
name|default_pager_haspage
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * no_pager_alloc just returns an initialized object.  */
end_comment

begin_function
specifier|static
name|vm_object_t
name|default_pager_alloc
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|vm_ooffset_t
name|size
parameter_list|,
name|vm_prot_t
name|prot
parameter_list|,
name|vm_ooffset_t
name|offset
parameter_list|)
block|{
if|if
condition|(
name|handle
operator|!=
name|NULL
condition|)
name|panic
argument_list|(
literal|"default_pager_alloc: handle specified"
argument_list|)
expr_stmt|;
return|return
name|vm_object_allocate
argument_list|(
name|OBJT_DEFAULT
argument_list|,
name|OFF_TO_IDX
argument_list|(
name|round_page
argument_list|(
name|offset
operator|+
name|size
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * deallocate resources associated with default objects.   The default objects  * have no special resources allocated to them, but the vm_page's being used  * in this object might.  Still, we do not have to do anything - we will free  * the swapblk in the underlying vm_page's when we free the vm_page or  * garbage collect the vm_page cache list.  */
end_comment

begin_function
specifier|static
name|void
name|default_pager_dealloc
parameter_list|(
name|object
parameter_list|)
name|vm_object_t
name|object
decl_stmt|;
block|{
comment|/* 	 * OBJT_DEFAULT objects have no special resources allocated to them. 	 */
block|}
end_function

begin_comment
comment|/*  * Load pages from backing store.  Since OBJT_DEFAULT is converted to  * OBJT_SWAP at the time a swap-backed vm_page_t is freed, we will never  * see a vm_page with assigned swap here.  */
end_comment

begin_function
specifier|static
name|int
name|default_pager_getpages
parameter_list|(
name|object
parameter_list|,
name|m
parameter_list|,
name|count
parameter_list|,
name|reqpage
parameter_list|)
name|vm_object_t
name|object
decl_stmt|;
name|vm_page_t
modifier|*
name|m
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|reqpage
decl_stmt|;
block|{
return|return
name|VM_PAGER_FAIL
return|;
block|}
end_function

begin_comment
comment|/*  * Store pages to backing store.  We should assign swap and initiate  * I/O.  We do not actually convert the object to OBJT_SWAP here.  The  * object will be converted when the written-out vm_page_t is moved from the  * cache to the free list.  */
end_comment

begin_function
specifier|static
name|void
name|default_pager_putpages
parameter_list|(
name|object
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|,
name|sync
parameter_list|,
name|rtvals
parameter_list|)
name|vm_object_t
name|object
decl_stmt|;
name|vm_page_t
modifier|*
name|m
decl_stmt|;
name|int
name|c
decl_stmt|;
name|boolean_t
name|sync
decl_stmt|;
name|int
modifier|*
name|rtvals
decl_stmt|;
block|{
name|swap_pager_putpages
argument_list|(
name|object
argument_list|,
name|m
argument_list|,
name|c
argument_list|,
name|sync
argument_list|,
name|rtvals
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Tell us whether the backing store for the requested (object,index) is  * synchronized.  i.e. tell us whether we can throw the page away and   * reload it later.  So, for example, if we are in the process of writing  * the page to its backing store, or if no backing store has been assigned,  * it is not yet synchronized.  *  * It is possible to have fully-synchronized swap assigned without the  * object having been converted.  We just call swap_pager_haspage() to  * deal with it since it must already deal with it plus deal with swap  * meta-data structures.  */
end_comment

begin_function
specifier|static
name|boolean_t
name|default_pager_haspage
parameter_list|(
name|object
parameter_list|,
name|pindex
parameter_list|,
name|before
parameter_list|,
name|after
parameter_list|)
name|vm_object_t
name|object
decl_stmt|;
name|vm_pindex_t
name|pindex
decl_stmt|;
name|int
modifier|*
name|before
decl_stmt|;
name|int
modifier|*
name|after
decl_stmt|;
block|{
return|return
name|FALSE
return|;
block|}
end_function

end_unit

