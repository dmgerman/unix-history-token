begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vm_map.h	8.9 (Berkeley) 5/17/95  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $Id: vm_map.h,v 1.28 1997/08/18 02:06:24 dyson Exp $  */
end_comment

begin_comment
comment|/*  *	Virtual memory map module definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_MAP_
end_ifndef

begin_define
define|#
directive|define
name|_VM_MAP_
end_define

begin_comment
comment|/*  *	Types defined:  *  *	vm_map_t		the high-level address map data structure.  *	vm_map_entry_t		an entry in an address map.  *	vm_map_version_t	a timestamp of a map, for use with vm_map_lookup  */
end_comment

begin_comment
comment|/*  *	Objects which live in maps may be either VM objects, or  *	another map (called a "sharing map") which denotes read-write  *	sharing with other maps.  */
end_comment

begin_union
union|union
name|vm_map_object
block|{
name|struct
name|vm_object
modifier|*
name|vm_object
decl_stmt|;
comment|/* object object */
name|struct
name|vm_map
modifier|*
name|share_map
decl_stmt|;
comment|/* share map */
name|struct
name|vm_map
modifier|*
name|sub_map
decl_stmt|;
comment|/* belongs to another map */
block|}
union|;
end_union

begin_comment
comment|/*  *	Address map entries consist of start and end addresses,  *	a VM object (or sharing map) and offset into that object,  *	and user-exported inheritance and protection information.  *	Also included is control information for virtual copy operations.  */
end_comment

begin_struct
struct|struct
name|vm_map_entry
block|{
name|struct
name|vm_map_entry
modifier|*
name|prev
decl_stmt|;
comment|/* previous entry */
name|struct
name|vm_map_entry
modifier|*
name|next
decl_stmt|;
comment|/* next entry */
name|vm_offset_t
name|start
decl_stmt|;
comment|/* start address */
name|vm_offset_t
name|end
decl_stmt|;
comment|/* end address */
name|union
name|vm_map_object
name|object
decl_stmt|;
comment|/* object I point to */
name|vm_ooffset_t
name|offset
decl_stmt|;
comment|/* offset into object */
name|u_char
name|eflags
decl_stmt|;
comment|/* map entry flags */
comment|/* Only in task maps: */
name|vm_prot_t
name|protection
decl_stmt|;
comment|/* protection code */
name|vm_prot_t
name|max_protection
decl_stmt|;
comment|/* maximum protection */
name|vm_inherit_t
name|inheritance
decl_stmt|;
comment|/* inheritance */
name|int
name|wired_count
decl_stmt|;
comment|/* can be paged if = 0 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAP_ENTRY_IS_A_MAP
value|0x1
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_IS_SUB_MAP
value|0x2
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_COW
value|0x4
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_NEEDS_COPY
value|0x8
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_NOFAULT
value|0x10
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_USER_WIRED
value|0x20
end_define

begin_comment
comment|/*  *	Maps are doubly-linked lists of map entries, kept sorted  *	by address.  A single hint is provided to start  *	searches again from the last successful search,  *	insertion, or removal.  */
end_comment

begin_struct
struct|struct
name|vm_map
block|{
name|struct
name|pmap
modifier|*
name|pmap
decl_stmt|;
comment|/* Physical map */
name|struct
name|lock
name|lock
decl_stmt|;
comment|/* Lock for map data */
name|struct
name|vm_map_entry
name|header
decl_stmt|;
comment|/* List of entries */
name|int
name|nentries
decl_stmt|;
comment|/* Number of entries */
name|vm_size_t
name|size
decl_stmt|;
comment|/* virtual size */
name|unsigned
name|char
name|is_main_map
decl_stmt|;
comment|/* Am I a main map? */
name|unsigned
name|char
name|system_map
decl_stmt|;
comment|/* Am I a system map? */
name|int
name|ref_count
decl_stmt|;
comment|/* Reference count */
name|struct
name|simplelock
name|ref_lock
decl_stmt|;
comment|/* Lock for ref_count field */
name|vm_map_entry_t
name|hint
decl_stmt|;
comment|/* hint for quick lookups */
name|vm_map_entry_t
name|first_free
decl_stmt|;
comment|/* First free space hint */
name|boolean_t
name|entries_pageable
decl_stmt|;
comment|/* map entries pageable?? */
name|unsigned
name|int
name|timestamp
decl_stmt|;
comment|/* Version number */
define|#
directive|define
name|min_offset
value|header.start
define|#
directive|define
name|max_offset
value|header.end
block|}
struct|;
end_struct

begin_comment
comment|/*   * Shareable process virtual address space.  * May eventually be merged with vm_map.  * Several fields are temporary (text, data stuff).  */
end_comment

begin_struct
struct|struct
name|vmspace
block|{
name|struct
name|vm_map
name|vm_map
decl_stmt|;
comment|/* VM address map */
name|struct
name|pmap
name|vm_pmap
decl_stmt|;
comment|/* private physical map */
name|int
name|vm_refcnt
decl_stmt|;
comment|/* number of references */
name|caddr_t
name|vm_shm
decl_stmt|;
comment|/* SYS5 shared memory private data XXX */
comment|/* we copy from vm_startcopy to the end of the structure on fork */
define|#
directive|define
name|vm_startcopy
value|vm_rssize
name|segsz_t
name|vm_rssize
decl_stmt|;
comment|/* current resident set size in pages */
name|segsz_t
name|vm_swrss
decl_stmt|;
comment|/* resident set size before last swap */
name|segsz_t
name|vm_tsize
decl_stmt|;
comment|/* text size (pages) XXX */
name|segsz_t
name|vm_dsize
decl_stmt|;
comment|/* data size (pages) XXX */
name|segsz_t
name|vm_ssize
decl_stmt|;
comment|/* stack size (pages) */
name|caddr_t
name|vm_taddr
decl_stmt|;
comment|/* user virtual address of text XXX */
name|caddr_t
name|vm_daddr
decl_stmt|;
comment|/* user virtual address of data XXX */
name|caddr_t
name|vm_maxsaddr
decl_stmt|;
comment|/* user VA at max stack growth */
name|caddr_t
name|vm_minsaddr
decl_stmt|;
comment|/* user VA at max stack growth */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Map versions are used to validate a previous lookup attempt.  *  *	Since lookup operations may involve both a main map and  *	a sharing map, it is necessary to have a timestamp from each.  *	[If the main map timestamp has changed, the share_map and  *	associated timestamp are no longer valid; the map version  *	does not include a reference for the embedded share_map.]  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|main_timestamp
decl_stmt|;
name|vm_map_t
name|share_map
decl_stmt|;
name|int
name|share_timestamp
decl_stmt|;
block|}
name|vm_map_version_t
typedef|;
end_typedef

begin_comment
comment|/*  *	Macros:		vm_map_lock, etc.  *	Function:  *		Perform locking on the data portion of a map.  */
end_comment

begin_define
define|#
directive|define
name|vm_map_lock_drain_interlock
parameter_list|(
name|map
parameter_list|)
value|{ \ 	lockmgr(&(map)->lock, LK_DRAIN|LK_INTERLOCK, \&(map)->ref_lock, curproc); \ 	(map)->timestamp++; \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_comment
comment|/* #define MAP_LOCK_DIAGNOSTIC 1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAP_LOCK_DIAGNOSTIC
end_ifdef

begin_define
define|#
directive|define
name|vm_map_lock
parameter_list|(
name|map
parameter_list|)
value|{ \ 	printf ("locking map LK_EXCLUSIVE: 0x%x\n", map); \ 	if (lockmgr(&(map)->lock, LK_EXCLUSIVE, (void *)0, curproc) != 0) { \ 		panic("vm_map_lock: failed to get lock"); \ 	} \ 	(map)->timestamp++; \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vm_map_lock
parameter_list|(
name|map
parameter_list|)
value|{ \ 	if (lockmgr(&(map)->lock, LK_EXCLUSIVE, (void *)0, curproc) != 0) { \ 		panic("vm_map_lock: failed to get lock"); \ 	} \ 	(map)->timestamp++; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vm_map_lock
parameter_list|(
name|map
parameter_list|)
value|{ \ 	lockmgr(&(map)->lock, LK_EXCLUSIVE, (void *)0, curproc); \ 	(map)->timestamp++; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIAGNOSTIC */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAP_LOCK_DIAGNOSTIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|vm_map_unlock
parameter_list|(
name|map
parameter_list|)
define|\
value|do { \ 		printf ("locking map LK_RELEASE: 0x%x\n", map); \ 		lockmgr(&(map)->lock, LK_RELEASE, (void *)0, curproc); \ 	} while (0);
end_define

begin_define
define|#
directive|define
name|vm_map_lock_read
parameter_list|(
name|map
parameter_list|)
define|\
value|do { \ 		printf ("locking map LK_SHARED: 0x%x\n", map); \ 		lockmgr(&(map)->lock, LK_SHARED, (void *)0, curproc); \ 	} while (0);
end_define

begin_define
define|#
directive|define
name|vm_map_unlock_read
parameter_list|(
name|map
parameter_list|)
define|\
value|do { \ 		printf ("locking map LK_RELEASE: 0x%x\n", map); \ 		lockmgr(&(map)->lock, LK_RELEASE, (void *)0, curproc); \ 	} while (0);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vm_map_unlock
parameter_list|(
name|map
parameter_list|)
define|\
value|lockmgr(&(map)->lock, LK_RELEASE, (void *)0, curproc);
end_define

begin_define
define|#
directive|define
name|vm_map_lock_read
parameter_list|(
name|map
parameter_list|)
define|\
value|lockmgr(&(map)->lock, LK_SHARED, (void *)0, curproc);
end_define

begin_define
define|#
directive|define
name|vm_map_unlock_read
parameter_list|(
name|map
parameter_list|)
define|\
value|lockmgr(&(map)->lock, LK_RELEASE, (void *)0, curproc);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline__
name|int
name|_vm_map_lock_upgrade
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|MAP_LOCK_DIAGNOSTIC
argument_list|)
name|printf
argument_list|(
literal|"locking map LK_EXCLUPGRADE: 0x%x\n"
argument_list|,
name|map
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|lockmgr
argument_list|(
operator|&
operator|(
name|map
operator|)
operator|->
name|lock
argument_list|,
name|LK_EXCLUPGRADE
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
name|p
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|vm_map_lock_upgrade
parameter_list|(
name|map
parameter_list|)
value|_vm_map_lock_upgrade(map, curproc)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAP_LOCK_DIAGNOSTIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|vm_map_lock_downgrade
parameter_list|(
name|map
parameter_list|)
define|\
value|do { \ 		printf ("locking map LK_DOWNGRADE: 0x%x\n", map); \ 		lockmgr(&(map)->lock, LK_DOWNGRADE, (void *)0, curproc); \ 	} while (0);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vm_map_lock_downgrade
parameter_list|(
name|map
parameter_list|)
define|\
value|lockmgr(&(map)->lock, LK_DOWNGRADE, (void *)0, curproc);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vm_map_set_recursive
parameter_list|(
name|map
parameter_list|)
value|{ \ 	simple_lock(&(map)->lock.lk_interlock); \ 	(map)->lock.lk_flags |= LK_CANRECURSE; \ 	simple_unlock(&(map)->lock.lk_interlock); \ }
end_define

begin_define
define|#
directive|define
name|vm_map_clear_recursive
parameter_list|(
name|map
parameter_list|)
value|{ \ 	simple_lock(&(map)->lock.lk_interlock); \ 	(map)->lock.lk_flags&= ~LK_CANRECURSE; \ 	simple_unlock(&(map)->lock.lk_interlock); \ }
end_define

begin_comment
comment|/*  *	Functions implemented as macros  */
end_comment

begin_define
define|#
directive|define
name|vm_map_min
parameter_list|(
name|map
parameter_list|)
value|((map)->min_offset)
end_define

begin_define
define|#
directive|define
name|vm_map_max
parameter_list|(
name|map
parameter_list|)
value|((map)->max_offset)
end_define

begin_define
define|#
directive|define
name|vm_map_pmap
parameter_list|(
name|map
parameter_list|)
value|((map)->pmap)
end_define

begin_comment
comment|/* XXX: number of kernel maps and entries to statically allocate */
end_comment

begin_define
define|#
directive|define
name|MAX_KMAP
value|10
end_define

begin_define
define|#
directive|define
name|MAX_KMAPENT
value|128
end_define

begin_define
define|#
directive|define
name|MAX_MAPENT
value|128
end_define

begin_comment
comment|/*  * Copy-on-write flags for vm_map operations  */
end_comment

begin_define
define|#
directive|define
name|MAP_COPY_NEEDED
value|0x1
end_define

begin_define
define|#
directive|define
name|MAP_COPY_ON_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|MAP_NOFAULT
value|0x4
end_define

begin_comment
comment|/*  * vm_fault option flags  */
end_comment

begin_define
define|#
directive|define
name|VM_FAULT_NORMAL
value|0
end_define

begin_comment
comment|/* Nothing special */
end_comment

begin_define
define|#
directive|define
name|VM_FAULT_CHANGE_WIRING
value|1
end_define

begin_comment
comment|/* Change the wiring as appropriate */
end_comment

begin_define
define|#
directive|define
name|VM_FAULT_USER_WIRE
value|2
end_define

begin_comment
comment|/* Likewise, but for user purposes */
end_comment

begin_define
define|#
directive|define
name|VM_FAULT_WIRE_MASK
value|(VM_FAULT_CHANGE_WIRING|VM_FAULT_USER_WIRE)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_HOLD
value|4
end_define

begin_comment
comment|/* Hold the page */
end_comment

begin_define
define|#
directive|define
name|VM_FAULT_DIRTY
value|8
end_define

begin_comment
comment|/* Dirty the page */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|kentry_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_size_t
name|kentry_data_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|vm_map_check_protection
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_prot_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_copy
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_size_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_decl_stmt
name|vm_map_t
name|vm_map_create
name|__P
argument_list|(
operator|(
expr|struct
name|pmap
operator|*
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_map_deallocate
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_delete
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_find
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_object_t
operator|,
name|vm_ooffset_t
operator|,
name|vm_offset_t
operator|*
operator|,
name|vm_size_t
operator|,
name|boolean_t
operator|,
name|vm_prot_t
operator|,
name|vm_prot_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_findspace
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_size_t
operator|,
name|vm_offset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_inherit
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_inherit_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_map_init
name|__P
argument_list|(
operator|(
expr|struct
name|vm_map
operator|*
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_insert
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_object_t
operator|,
name|vm_ooffset_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_prot_t
operator|,
name|vm_prot_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_lookup
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|*
operator|,
name|vm_offset_t
operator|,
name|vm_prot_t
operator|,
name|vm_map_entry_t
operator|*
operator|,
name|vm_object_t
operator|*
operator|,
name|vm_pindex_t
operator|*
operator|,
name|vm_prot_t
operator|*
operator|,
name|boolean_t
operator|*
operator|,
name|boolean_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_map_lookup_done
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_map_entry_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|vm_map_lookup_entry
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_map_entry_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_pageable
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_user_pageable
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_clean
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_protect
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_prot_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_map_reference
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_remove
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_map_simplify
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_map_startup
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_map_submap
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_map_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_map_madvise
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|pmap_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_map_simplify_entry
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_map_entry_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_init2
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_uiomove
name|__P
argument_list|(
operator|(
name|vm_map_t
operator|,
name|vm_object_t
operator|,
name|off_t
operator|,
name|int
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_freeze_copyopts
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|vm_pindex_t
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
comment|/* _VM_MAP_ */
end_comment

end_unit

