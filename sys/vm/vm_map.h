begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vm_map.h	8.9 (Berkeley) 5/17/95  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MAP_LOCK_DIAGNOSTIC
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_define
define|#
directive|define
name|vm_map_printf
parameter_list|(
name|str
parameter_list|,
name|arg
parameter_list|)
value|printf(str,arg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vm_map_printf
parameter_list|(
name|str
parameter_list|,
name|arg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	Types defined:  *  *	vm_map_t		the high-level address map data structure.  *	vm_map_entry_t		an entry in an address map.  */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|vm_eflags_t
typedef|;
end_typedef

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
name|vm_offset_t
name|avail_ssize
decl_stmt|;
comment|/* amt can grow if this is a stack */
name|union
name|vm_map_object
name|object
decl_stmt|;
comment|/* object I point to */
name|vm_ooffset_t
name|offset
decl_stmt|;
comment|/* offset into object */
name|vm_eflags_t
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
name|vm_pindex_t
name|lastr
decl_stmt|;
comment|/* last read */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAP_ENTRY_NOSYNC
value|0x0001
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_IS_SUB_MAP
value|0x0002
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_COW
value|0x0004
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_NEEDS_COPY
value|0x0008
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_NOFAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_USER_WIRED
value|0x0020
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_BEHAV_NORMAL
value|0x0000
end_define

begin_comment
comment|/* default behavior */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_BEHAV_SEQUENTIAL
value|0x0040
end_define

begin_comment
comment|/* expect sequential access */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_BEHAV_RANDOM
value|0x0080
end_define

begin_comment
comment|/* expect random access */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_BEHAV_RESERVED
value|0x00C0
end_define

begin_comment
comment|/* future use */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_BEHAV_MASK
value|0x00C0
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_NOCOREDUMP
value|0x0400
end_define

begin_comment
comment|/* don't include in a core */
end_comment

begin_comment
comment|/*  *	Maps are doubly-linked lists of map entries, kept sorted  *	by address.  A single hint is provided to start  *	searches again from the last successful search,  *	insertion, or removal.  *  *	Note: the lock structure cannot be the first element of vm_map  *	because this can result in a running lockup between two or more  *	system processes trying to kmem_alloc_wait() due to kmem_alloc_wait()  *	and free tsleep/waking up 'map' and the underlying lockmgr also  *	sleeping and waking up on 'map'.  The lockup occurs when the map fills  *	up.  The 'exec' map, for example.  */
end_comment

begin_struct
struct|struct
name|vm_map
block|{
name|struct
name|vm_map_entry
name|header
decl_stmt|;
comment|/* List of entries */
name|struct
name|sx
name|lock
decl_stmt|;
comment|/* Lock for map data */
name|int
name|nentries
decl_stmt|;
comment|/* Number of entries */
name|vm_size_t
name|size
decl_stmt|;
comment|/* virtual size */
name|u_char
name|system_map
decl_stmt|;
comment|/* Am I a system map? */
name|u_char
name|infork
decl_stmt|;
comment|/* Am I in fork processing? */
name|vm_map_entry_t
name|hint
decl_stmt|;
comment|/* hint for quick lookups */
name|unsigned
name|int
name|timestamp
decl_stmt|;
comment|/* Version number */
name|vm_map_entry_t
name|first_free
decl_stmt|;
comment|/* First free space hint */
name|struct
name|pmap
modifier|*
name|pmap
decl_stmt|;
comment|/* Physical map */
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
define|#
directive|define
name|vm_endcopy
value|vm_freer
name|struct
name|proc
modifier|*
name|vm_freer
decl_stmt|;
comment|/* vm freed on whose behalf */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|u_char
name|vm_map_entry_behavior
parameter_list|(
name|struct
name|vm_map_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_entry_set_behavior
parameter_list|(
name|struct
name|vm_map_entry
modifier|*
name|entry
parameter_list|,
name|u_char
name|behavior
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Macros:		vm_map_lock, etc.  *	Function:  *		Perform locking on the data portion of a map.  Note that  *		these macros mimic procedure calls returning void.  The  *		semicolon is supplied by the user of these macros, not  *		by the macros themselves.  The macros can safely be used  *		as unbraced elements in a higher level statement.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX This macro is not called anywhere, and (map)->ref_lock doesn't exist. */
end_comment

begin_define
define|#
directive|define
name|vm_map_lock_drain_interlock
parameter_list|(
name|map
parameter_list|)
define|\
value|do { \ 		lockmgr(&(map)->lock, LK_DRAIN|LK_INTERLOCK, \&(map)->ref_lock, curthread); \ 		(map)->timestamp++; \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|_vm_map_lock
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_vm_map_try_lock
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_vm_map_unlock
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_vm_map_lock_read
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_vm_map_unlock_read
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_vm_map_lock_upgrade
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_vm_map_lock_downgrade
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vm_map_lock
parameter_list|(
name|map
parameter_list|)
value|_vm_map_lock(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_try_lock
parameter_list|(
name|map
parameter_list|)
value|_vm_map_try_lock(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_unlock
parameter_list|(
name|map
parameter_list|)
value|_vm_map_unlock(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_lock_read
parameter_list|(
name|map
parameter_list|)
value|_vm_map_lock_read(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_unlock_read
parameter_list|(
name|map
parameter_list|)
value|_vm_map_unlock_read(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_lock_upgrade
parameter_list|(
name|map
parameter_list|)
value|_vm_map_lock_upgrade(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_lock_downgrade
parameter_list|(
name|map
parameter_list|)
value|_vm_map_lock_downgrade(map, LOCK_FILE, \     LOCK_LINE)
end_define

begin_function_decl
name|vm_offset_t
name|vm_map_min
parameter_list|(
name|vm_map_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|vm_map_max
parameter_list|(
name|vm_map_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmap
modifier|*
name|vm_map_pmap
parameter_list|(
name|vm_map_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmap
modifier|*
name|vmspace_pmap
parameter_list|(
name|struct
name|vmspace
modifier|*
name|vmspace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|vmspace_resident_count
parameter_list|(
name|struct
name|vmspace
modifier|*
name|vmspace
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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
name|MAP_UNUSED_01
value|0x0001
end_define

begin_define
define|#
directive|define
name|MAP_COPY_ON_WRITE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MAP_NOFAULT
value|0x0004
end_define

begin_define
define|#
directive|define
name|MAP_PREFAULT
value|0x0008
end_define

begin_define
define|#
directive|define
name|MAP_PREFAULT_PARTIAL
value|0x0010
end_define

begin_define
define|#
directive|define
name|MAP_DISABLE_SYNCER
value|0x0020
end_define

begin_define
define|#
directive|define
name|MAP_DISABLE_COREDUMP
value|0x0100
end_define

begin_define
define|#
directive|define
name|MAP_PREFAULT_MADVISE
value|0x0200
end_define

begin_comment
comment|/* from (user) madvise request */
end_comment

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
name|_KERNEL
end_ifdef

begin_function_decl
name|boolean_t
name|vm_map_check_protection
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_prot_t
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_function_decl
name|vm_map_t
name|vm_map_create
parameter_list|(
name|struct
name|pmap
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_delete
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_find
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_object_t
parameter_list|,
name|vm_ooffset_t
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|,
name|boolean_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_findspace
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_inherit
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_inherit_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_init
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_destroy
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_insert
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_object_t
parameter_list|,
name|vm_ooffset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_lookup
parameter_list|(
name|vm_map_t
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_map_entry_t
modifier|*
parameter_list|,
name|vm_object_t
modifier|*
parameter_list|,
name|vm_pindex_t
modifier|*
parameter_list|,
name|vm_prot_t
modifier|*
parameter_list|,
name|boolean_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_lookup_done
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_map_entry_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_map_lookup_entry
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_map_entry_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_pageable
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_user_pageable
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_clean
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|boolean_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_protect
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_remove
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_startup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_submap
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_map_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_madvise
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_simplify_entry
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_map_entry_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_init2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_uiomove
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_object_t
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_freeze_copyopts
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_pindex_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_stack
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_growstack
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmspace_swap_count
parameter_list|(
name|struct
name|vmspace
modifier|*
name|vmspace
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VM_MAP_ */
end_comment

end_unit

