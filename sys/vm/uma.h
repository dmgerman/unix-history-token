begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002, Jeffrey Roberson<jroberson@chesapeake.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * uma.h - External definitions for the Universal Memory Allocator  *  * Jeff Roberson<jroberson@chesapeake.net> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_UMA_H
end_ifndef

begin_define
define|#
directive|define
name|VM_UMA_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* For NULL */
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_comment
comment|/* For M_* */
end_comment

begin_comment
comment|/* User visable parameters */
end_comment

begin_define
define|#
directive|define
name|UMA_SMALLEST_UNIT
value|(PAGE_SIZE / 256)
end_define

begin_comment
comment|/* Smallest item allocated */
end_comment

begin_comment
comment|/* Types and type defs */
end_comment

begin_struct_decl
struct_decl|struct
name|uma_zone
struct_decl|;
end_struct_decl

begin_comment
comment|/* Opaque type used as a handle to the zone */
end_comment

begin_typedef
typedef|typedef
name|struct
name|uma_zone
modifier|*
name|uma_zone_t
typedef|;
end_typedef

begin_comment
comment|/*   * Item constructor  *  * Arguments:  *	item  A pointer to the memory which has been allocated.  *	arg   The arg field passed to uma_zalloc_arg  *	size  The size of the allocated item  *   * Returns:  *	Nothing  *  * Discussion:  *	The constructor is called just before the memory is returned  *	to the user. It may block if neccisary.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uma_ctor
function_decl|)
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Item destructor  *  * Arguments:  *	item  A pointer to the memory which has been allocated.  *	size  The size of the item being destructed.  *	arg   Argument passed through uma_zfree_arg  *   * Returns:  *	Nothing  *  * Discussion:  *	The destructor may perform operations that differ from those performed  *	by the initializer, but it must leave the object in the same state.  *	This IS type stable storage.  This is called after EVERY zfree call.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uma_dtor
function_decl|)
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*   * Item initializer  *  * Arguments:  *	item  A pointer to the memory which has been allocated.  *	size  The size of the item being initialized.  *   * Returns:  *	Nothing  *  * Discussion:  *	The initializer is called when the memory is cached in the uma zone.   *	this should be the same state that the destructor leaves the object in.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uma_init
function_decl|)
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Item discard function  *  * Arguments:  * 	item  A pointer to memory which has been 'freed' but has not left the   *	      zone's cache.  *	size  The size of the item being discarded.  *  * Returns:  *	Nothing  *  * Discussion:  *	This routine is called when memory leaves a zone and is returned to the  *	system for other uses.  It is the counter part to the init function.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uma_fini
function_decl|)
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * What's the difference between initializing and constructing?  *  * The item is initialized when it is cached, and this is the state that the   * object should be in when returned to the allocator. The purpose of this is  * to remove some code which would otherwise be called on each allocation by  * utilizing a known, stable state.  This differs from the constructor which  * will be called on EVERY allocation.  *  * For example, in the initializer you may want to initialize embeded locks,  * NULL list pointers, set up initial states, magic numbers, etc.  This way if  * the object is held in the allocator and re-used it won't be neccisary to  * re-initialize it.  *  * The constructor may be used to lock a data structure, link it on to lists,  * bump reference counts or total counts of outstanding structures, etc.  *  */
end_comment

begin_comment
comment|/* Function proto types */
end_comment

begin_comment
comment|/*  * Create a new uma zone  *  * Arguments:  *	name  The text name of the zone for debugging and stats, this memory  *		should not be freed until the zone has been deallocated.  *	size  The size of the object that is being created.  *	ctor  The constructor that is called when the object is allocated  *	dtor  The destructor that is called when the object is freed.  *	init  An initializer that sets up the initial state of the memory.  *	fini  A discard function that undoes initialization done by init.  *		ctor/dtor/init/fini may all be null, see notes above.  *	align A bitmask that corisponds to the requested alignment  *		eg 4 would be 0x3  *	flags A set of parameters that control the behavior of the zone  *  * Returns:  *	A pointer to a structure which is intended to be opaque to users of  *	the interface.  The value may be null if the wait flag is not set.  */
end_comment

begin_function_decl
name|uma_zone_t
name|uma_zcreate
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|size
parameter_list|,
name|uma_ctor
name|ctor
parameter_list|,
name|uma_dtor
name|dtor
parameter_list|,
name|uma_init
name|uminit
parameter_list|,
name|uma_fini
name|fini
parameter_list|,
name|int
name|align
parameter_list|,
name|u_int16_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Definitions for uma_zcreate flags */
end_comment

begin_define
define|#
directive|define
name|UMA_ZONE_PAGEABLE
value|0x0001
end_define

begin_comment
comment|/* Return items not fully backed by 					   physical memory XXX Not yet */
end_comment

begin_define
define|#
directive|define
name|UMA_ZONE_ZINIT
value|0x0002
end_define

begin_comment
comment|/* Initialize with zeros */
end_comment

begin_define
define|#
directive|define
name|UMA_ZONE_STATIC
value|0x0004
end_define

begin_comment
comment|/* Staticly sized zone */
end_comment

begin_define
define|#
directive|define
name|UMA_ZONE_OFFPAGE
value|0x0008
end_define

begin_comment
comment|/* Force the slab structure allocation 					   off of the real memory */
end_comment

begin_define
define|#
directive|define
name|UMA_ZONE_MALLOC
value|0x0010
end_define

begin_comment
comment|/* For use by malloc(9) only! */
end_comment

begin_define
define|#
directive|define
name|UMA_ZONE_NOFREE
value|0x0020
end_define

begin_comment
comment|/* Do not free slabs of this type! */
end_comment

begin_comment
comment|/* Definitions for align */
end_comment

begin_define
define|#
directive|define
name|UMA_ALIGN_PTR
value|(sizeof(void *) - 1)
end_define

begin_comment
comment|/* Alignment fit for ptr */
end_comment

begin_define
define|#
directive|define
name|UMA_ALIGN_LONG
value|(sizeof(long) - 1)
end_define

begin_comment
comment|/* "" long */
end_comment

begin_define
define|#
directive|define
name|UMA_ALIGN_INT
value|(sizeof(int) - 1)
end_define

begin_comment
comment|/* "" int */
end_comment

begin_define
define|#
directive|define
name|UMA_ALIGN_SHORT
value|(sizeof(short) - 1)
end_define

begin_comment
comment|/* "" short */
end_comment

begin_define
define|#
directive|define
name|UMA_ALIGN_CHAR
value|(sizeof(char) - 1)
end_define

begin_comment
comment|/* "" char */
end_comment

begin_define
define|#
directive|define
name|UMA_ALIGN_CACHE
value|(16 - 1)
end_define

begin_comment
comment|/* Cache line size align */
end_comment

begin_comment
comment|/*  * Destroys a uma zone  *  * Arguments:  *	zone  The zone we want to destroy.  *	wait  This flag indicates whether or not we should wait for all  *		allocations to free, or return an errno on outstanding memory.  *  * Returns:  *	0 on successful completion, or EWOULDBLOCK if there are outstanding  *	allocations and the wait flag is M_NOWAIT  */
end_comment

begin_function_decl
name|int
name|uma_zdestroy
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocates an item out of a zone  *  * Arguments:  *	zone  The zone we are allocating from  *	arg   This data is passed to the ctor function  *	wait  This flag indicates whether or not we are allowed to block while  *		allocating memory for this zone should we run out.  *  * Returns:  *	A non null pointer to an initialized element from the zone is  *	garanteed if the wait flag is M_WAITOK, otherwise a null pointer may be  *	returned if the zone is empty or the ctor failed.  */
end_comment

begin_function_decl
name|void
modifier|*
name|uma_zalloc_arg
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocates an item out of a zone without supplying an argument  *  * This is just a wrapper for uma_zalloc_arg for convenience.  *  */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
modifier|*
name|uma_zalloc
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|uma_zalloc
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|wait
parameter_list|)
block|{
return|return
name|uma_zalloc_arg
argument_list|(
name|zone
argument_list|,
name|NULL
argument_list|,
name|wait
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Frees an item back into the specified zone.  *  * Arguments:  *	zone  The zone the item was originally allocated out of.  *	item  The memory to be freed.  *	arg   Argument passed to the destructor  *  * Returns:  *	Nothing.  */
end_comment

begin_function_decl
name|void
name|uma_zfree_arg
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|void
modifier|*
name|item
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees an item back to a zone without supplying an argument  *  * This is just a wrapper for uma_zfree_arg for convenience.  *  */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|uma_zfree
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|void
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|uma_zfree
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|void
modifier|*
name|item
parameter_list|)
block|{
return|return
name|uma_zfree_arg
argument_list|(
name|zone
argument_list|,
name|item
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * XXX The rest of the prototypes in this header are h0h0 magic for the VM.  * If you think you need to use it for a normal zone you're probably incorrect.  */
end_comment

begin_comment
comment|/*  * Backend page supplier routines  *  * Arguments:  *	zone  The zone that is requesting pages  *	size  The number of bytes being requested  *	pflag Flags for these memory pages, see below.  *	wait  Indicates our willingness to block.  *  * Returns:  *	A pointer to the alloced memory or NULL on failure.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|uma_alloc
function_decl|)
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|size
parameter_list|,
name|u_int8_t
modifier|*
name|pflag
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Backend page free routines  *  * Arguments:  *	item  A pointer to the previously allocated pages  *	size  The original size of the allocation  *	pflag The flags for the slab.  See UMA_SLAB_* below  *  * Returns:  *	None  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uma_free
function_decl|)
parameter_list|(
name|void
modifier|*
name|item
parameter_list|,
name|int
name|size
parameter_list|,
name|u_int8_t
name|pflag
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Sets up the uma allocator. (Called by vm_mem_init)  *  * Arguments:  *	bootmem  A pointer to memory used to bootstrap the system.  *  * Returns:  *	Nothing  *  * Discussion:  *	This memory is used for zones which allocate things before the  *	backend page supplier can give us pages.  It should be  *	UMA_SLAB_SIZE * UMA_BOOT_PAGES bytes. (see uma_int.h)  *  */
end_comment

begin_function_decl
name|void
name|uma_startup
parameter_list|(
name|void
modifier|*
name|bootmem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finishes starting up the allocator.  This should  * be called when kva is ready for normal allocs.  *  * Arguments:  *	hash   An area of memory that will become the malloc hash  *	elems  The number of elements in this array  *  * Returns:  *	Nothing  *  * Discussion:  *	uma_startup2 is called by kmeminit() to prepare the malloc  *	hash bucket, and enable use of uma for malloc ops.  */
end_comment

begin_function_decl
name|void
name|uma_startup2
parameter_list|(
name|void
modifier|*
name|hash
parameter_list|,
name|u_long
name|elems
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reclaims unused memory for all zones  *  * Arguments:  *	None  * Returns:  *	None  *  * This should only be called by the page out daemon.  */
end_comment

begin_function_decl
name|void
name|uma_reclaim
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Switches the backing object of a zone  *  * Arguments:  *	zone  The zone to update  *	obj   The obj to use for future allocations  *	size  The size of the object to allocate  *  * Returns:  *	0  if kva space can not be allocated  *	1  if successful  *  * Discussion:  *	A NULL object can be used and uma will allocate one for you.  Setting  *	the size will limit the amount of memory allocated to this zone.  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|uma_zone_set_obj
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|struct
name|vm_object
modifier|*
name|obj
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets a high limit on the number of items allowed in a zone  *  * Arguments:  *	zone  The zone to limit  *  * Returns:  *	Nothing  */
end_comment

begin_function_decl
name|void
name|uma_zone_set_max
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|nitems
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Replaces the standard page_alloc or obj_alloc functions for this zone  *  * Arguments:  *	zone   The zone whos back end allocator is being changed.  *	allocf A pointer to the allocation function  *  * Returns:  *	Nothing  *  * Discussion:  *	This could be used to implement pageable allocation, or perhaps  *	even DMA allocators if used in conjunction with the OFFPAGE  *	zone flag.  */
end_comment

begin_function_decl
name|void
name|uma_zone_set_allocf
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|uma_alloc
name|allocf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Used for freeing memory provided by the allocf above  *  * Arguments:  *	zone  The zone that intends to use this free routine.  *	freef The page freeing routine.  *  * Returns:  *	Nothing  */
end_comment

begin_function_decl
name|void
name|uma_zone_set_freef
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|uma_free
name|freef
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These flags are setable in the allocf and visable in the freef.  */
end_comment

begin_define
define|#
directive|define
name|UMA_SLAB_BOOT
value|0x01
end_define

begin_comment
comment|/* Slab alloced from boot pages */
end_comment

begin_define
define|#
directive|define
name|UMA_SLAB_KMEM
value|0x02
end_define

begin_comment
comment|/* Slab alloced from kmem_map */
end_comment

begin_define
define|#
directive|define
name|UMA_SLAB_KMAP
value|0x04
end_define

begin_comment
comment|/* Slab alloced from kernel_map */
end_comment

begin_define
define|#
directive|define
name|UMA_SLAB_PRIV
value|0x08
end_define

begin_comment
comment|/* Slab alloced from priv allocator */
end_comment

begin_define
define|#
directive|define
name|UMA_SLAB_OFFP
value|0x10
end_define

begin_comment
comment|/* Slab is managed seperately  */
end_comment

begin_define
define|#
directive|define
name|UMA_SLAB_MALLOC
value|0x20
end_define

begin_comment
comment|/* Slab is a large malloc slab */
end_comment

begin_comment
comment|/* 0x40 and 0x80 are available */
end_comment

begin_comment
comment|/*  * Used to pre-fill a zone with some number of items  *  * Arguments:  *	zone    The zone to fill  *	itemcnt The number of items to reserve  *  * Returns:  *	Nothing  *  * NOTE: This is blocking and should only be done at startup  */
end_comment

begin_function_decl
name|void
name|uma_prealloc
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|itemcnt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

