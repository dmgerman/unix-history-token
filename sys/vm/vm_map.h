begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vm_map.h	8.9 (Berkeley) 5/17/95  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_comment
comment|/*  *	Types defined:  *  *	vm_map_t		the high-level address map data structure.  *	vm_map_entry_t		an entry in an address map.  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|vm_flags_t
typedef|;
end_typedef

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
name|struct
name|vm_map_entry
modifier|*
name|left
decl_stmt|;
comment|/* left child in binary search tree */
name|struct
name|vm_map_entry
modifier|*
name|right
decl_stmt|;
comment|/* right child in binary search tree */
name|vm_offset_t
name|start
decl_stmt|;
comment|/* start address */
name|vm_offset_t
name|end
decl_stmt|;
comment|/* end address */
name|vm_offset_t
name|next_read
decl_stmt|;
comment|/* vaddr of the next sequential read */
name|vm_size_t
name|adj_free
decl_stmt|;
comment|/* amount of adjacent free space */
name|vm_size_t
name|max_free
decl_stmt|;
comment|/* max free space in subtree */
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
name|uint8_t
name|read_ahead
decl_stmt|;
comment|/* pages in the read-ahead window */
name|int
name|wired_count
decl_stmt|;
comment|/* can be paged if = 0 */
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
comment|/* tmp storage for creator ref */
name|struct
name|thread
modifier|*
name|wiring_thread
decl_stmt|;
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
name|MAP_ENTRY_IN_TRANSITION
value|0x0100
end_define

begin_comment
comment|/* entry being changed */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_NEEDS_WAKEUP
value|0x0200
end_define

begin_comment
comment|/* waiters in transition */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_NOCOREDUMP
value|0x0400
end_define

begin_comment
comment|/* don't include in a core */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_GROWS_DOWN
value|0x1000
end_define

begin_comment
comment|/* Top-down stacks */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_GROWS_UP
value|0x2000
end_define

begin_comment
comment|/* Bottom-up stacks */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_WIRE_SKIPPED
value|0x4000
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_VN_WRITECNT
value|0x8000
end_define

begin_comment
comment|/* writeable vnode mapping */
end_comment

begin_define
define|#
directive|define
name|MAP_ENTRY_GUARD
value|0x10000
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_STACK_GAP_DN
value|0x20000
end_define

begin_define
define|#
directive|define
name|MAP_ENTRY_STACK_GAP_UP
value|0x40000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function
specifier|static
name|__inline
name|u_char
name|vm_map_entry_behavior
parameter_list|(
name|vm_map_entry_t
name|entry
parameter_list|)
block|{
return|return
operator|(
name|entry
operator|->
name|eflags
operator|&
name|MAP_ENTRY_BEHAV_MASK
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|vm_map_entry_user_wired_count
parameter_list|(
name|vm_map_entry_t
name|entry
parameter_list|)
block|{
if|if
condition|(
name|entry
operator|->
name|eflags
operator|&
name|MAP_ENTRY_USER_WIRED
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|vm_map_entry_system_wired_count
parameter_list|(
name|vm_map_entry_t
name|entry
parameter_list|)
block|{
return|return
operator|(
name|entry
operator|->
name|wired_count
operator|-
name|vm_map_entry_user_wired_count
argument_list|(
name|entry
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  *	A map is a set of map entries.  These map entries are  *	organized both as a binary search tree and as a doubly-linked  *	list.  Both structures are ordered based upon the start and  *	end addresses contained within each map entry.  Sleator and  *	Tarjan's top-down splay algorithm is employed to control  *	height imbalance in the binary search tree.  *  * List of locks  *	(c)	const until freed  */
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
name|struct
name|mtx
name|system_mtx
decl_stmt|;
name|int
name|nentries
decl_stmt|;
comment|/* Number of entries */
name|vm_size_t
name|size
decl_stmt|;
comment|/* virtual size */
name|u_int
name|timestamp
decl_stmt|;
comment|/* Version number */
name|u_char
name|needs_wakeup
decl_stmt|;
name|u_char
name|system_map
decl_stmt|;
comment|/* (c) Am I a system map? */
name|vm_flags_t
name|flags
decl_stmt|;
comment|/* flags for this vm_map */
name|vm_map_entry_t
name|root
decl_stmt|;
comment|/* Root of a binary search tree */
name|pmap_t
name|pmap
decl_stmt|;
comment|/* (c) Physical map */
define|#
directive|define
name|min_offset
value|header.start
comment|/* (c) */
define|#
directive|define
name|max_offset
value|header.end
comment|/* (c) */
name|int
name|busy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * vm_flags_t values  */
end_comment

begin_define
define|#
directive|define
name|MAP_WIREFUTURE
value|0x01
end_define

begin_comment
comment|/* wire all future pages */
end_comment

begin_define
define|#
directive|define
name|MAP_BUSY_WAKEUP
value|0x02
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function
specifier|static
name|__inline
name|vm_offset_t
name|vm_map_max
parameter_list|(
specifier|const
name|struct
name|vm_map
modifier|*
name|map
parameter_list|)
block|{
return|return
operator|(
name|map
operator|->
name|max_offset
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|vm_offset_t
name|vm_map_min
parameter_list|(
specifier|const
name|struct
name|vm_map
modifier|*
name|map
parameter_list|)
block|{
return|return
operator|(
name|map
operator|->
name|min_offset
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|pmap_t
name|vm_map_pmap
parameter_list|(
name|vm_map_t
name|map
parameter_list|)
block|{
return|return
operator|(
name|map
operator|->
name|pmap
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vm_map_modflags
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|vm_flags_t
name|set
parameter_list|,
name|vm_flags_t
name|clear
parameter_list|)
block|{
name|map
operator|->
name|flags
operator|=
operator|(
name|map
operator|->
name|flags
operator||
name|set
operator|)
operator|&
operator|~
name|clear
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Shareable process virtual address space.  *  * List of locks  *	(c)	const until freed  */
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
name|shmmap_state
modifier|*
name|vm_shm
decl_stmt|;
comment|/* SYS5 shared memory private data XXX */
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
comment|/* (c) user virtual address of text */
name|caddr_t
name|vm_daddr
decl_stmt|;
comment|/* (c) user virtual address of data */
name|caddr_t
name|vm_maxsaddr
decl_stmt|;
comment|/* user VA at max stack growth */
specifier|volatile
name|int
name|vm_refcnt
decl_stmt|;
comment|/* number of references */
comment|/* 	 * Keep the PMAP last, so that CPU-specific variations of that 	 * structure on a single architecture don't result in offset 	 * variations of the machine-independent fields in the vmspace. 	 */
name|struct
name|pmap
name|vm_pmap
decl_stmt|;
comment|/* private physical map */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function
specifier|static
name|__inline
name|pmap_t
name|vmspace_pmap
parameter_list|(
name|struct
name|vmspace
modifier|*
name|vmspace
parameter_list|)
block|{
return|return
operator|&
name|vmspace
operator|->
name|vm_pmap
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  *	Macros:		vm_map_lock, etc.  *	Function:  *		Perform locking on the data portion of a map.  Note that  *		these macros mimic procedure calls returning void.  The  *		semicolon is supplied by the user of these macros, not  *		by the macros themselves.  The macros can safely be used  *		as unbraced elements in a higher level statement.  */
end_comment

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
name|int
name|_vm_map_unlock_and_wait
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|int
name|timo
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
name|_vm_map_trylock
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
name|_vm_map_trylock_read
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

begin_function_decl
name|int
name|vm_map_locked
parameter_list|(
name|vm_map_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_wakeup
parameter_list|(
name|vm_map_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_busy
parameter_list|(
name|vm_map_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_unbusy
parameter_list|(
name|vm_map_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_wait_busy
parameter_list|(
name|vm_map_t
name|map
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
name|vm_map_unlock
parameter_list|(
name|map
parameter_list|)
value|_vm_map_unlock(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_unlock_and_wait
parameter_list|(
name|map
parameter_list|,
name|timo
parameter_list|)
define|\
value|_vm_map_unlock_and_wait(map, timo, LOCK_FILE, LOCK_LINE)
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
name|vm_map_trylock
parameter_list|(
name|map
parameter_list|)
value|_vm_map_trylock(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_trylock_read
parameter_list|(
name|map
parameter_list|)
define|\
value|_vm_map_trylock_read(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_lock_upgrade
parameter_list|(
name|map
parameter_list|)
define|\
value|_vm_map_lock_upgrade(map, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_map_lock_downgrade
parameter_list|(
name|map
parameter_list|)
define|\
value|_vm_map_lock_downgrade(map, LOCK_FILE, LOCK_LINE)
end_define

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
comment|/* XXX: number of kernel maps to statically allocate */
end_comment

begin_define
define|#
directive|define
name|MAX_KMAP
value|10
end_define

begin_comment
comment|/*  * Copy-on-write flags for vm_map operations  */
end_comment

begin_define
define|#
directive|define
name|MAP_INHERIT_SHARE
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
name|MAP_CHECK_EXCL
value|0x0040
end_define

begin_define
define|#
directive|define
name|MAP_CREATE_GUARD
value|0x0080
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

begin_define
define|#
directive|define
name|MAP_VN_WRITECOUNT
value|0x0400
end_define

begin_define
define|#
directive|define
name|MAP_STACK_GROWS_DOWN
value|0x1000
end_define

begin_define
define|#
directive|define
name|MAP_STACK_GROWS_UP
value|0x2000
end_define

begin_define
define|#
directive|define
name|MAP_ACC_CHARGED
value|0x4000
end_define

begin_define
define|#
directive|define
name|MAP_ACC_NO_CHARGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MAP_CREATE_STACK_GAP_UP
value|0x10000
end_define

begin_define
define|#
directive|define
name|MAP_CREATE_STACK_GAP_DN
value|0x20000
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
name|VM_FAULT_WIRE
value|1
end_define

begin_comment
comment|/* Wire the mapped page */
end_comment

begin_define
define|#
directive|define
name|VM_FAULT_DIRTY
value|2
end_define

begin_comment
comment|/* Dirty the page; use w/VM_PROT_COPY */
end_comment

begin_comment
comment|/*  * Initially, mappings are slightly sequential.  The maximum window size must  * account for the map entry's "read_ahead" field being defined as an uint8_t.  */
end_comment

begin_define
define|#
directive|define
name|VM_FAULT_READ_AHEAD_MIN
value|7
end_define

begin_define
define|#
directive|define
name|VM_FAULT_READ_AHEAD_INIT
value|15
end_define

begin_define
define|#
directive|define
name|VM_FAULT_READ_AHEAD_MAX
value|min(atop(MAXPHYS) - 1, UINT8_MAX)
end_define

begin_comment
comment|/*  * The following "find_space" options are supported by vm_map_find().  *  * For VMFS_ALIGNED_SPACE, the desired alignment is specified to  * the macro argument as log base 2 of the desired alignment.  */
end_comment

begin_define
define|#
directive|define
name|VMFS_NO_SPACE
value|0
end_define

begin_comment
comment|/* don't find; use the given range */
end_comment

begin_define
define|#
directive|define
name|VMFS_ANY_SPACE
value|1
end_define

begin_comment
comment|/* find a range with any alignment */
end_comment

begin_define
define|#
directive|define
name|VMFS_OPTIMAL_SPACE
value|2
end_define

begin_comment
comment|/* find a range with optimal alignment*/
end_comment

begin_define
define|#
directive|define
name|VMFS_SUPER_SPACE
value|3
end_define

begin_comment
comment|/* find a superpage-aligned range */
end_comment

begin_define
define|#
directive|define
name|VMFS_ALIGNED_SPACE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* find a range with fixed alignment */
end_comment

begin_comment
comment|/*  * vm_map_wire and vm_map_unwire option flags  */
end_comment

begin_define
define|#
directive|define
name|VM_MAP_WIRE_SYSTEM
value|0
end_define

begin_comment
comment|/* wiring in a kernel map */
end_comment

begin_define
define|#
directive|define
name|VM_MAP_WIRE_USER
value|1
end_define

begin_comment
comment|/* wiring in a user map */
end_comment

begin_define
define|#
directive|define
name|VM_MAP_WIRE_NOHOLES
value|0
end_define

begin_comment
comment|/* region must not have holes */
end_comment

begin_define
define|#
directive|define
name|VM_MAP_WIRE_HOLESOK
value|2
end_define

begin_comment
comment|/* region may have holes */
end_comment

begin_define
define|#
directive|define
name|VM_MAP_WIRE_WRITE
value|4
end_define

begin_comment
comment|/* Validate writable. */
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

begin_function_decl
name|vm_map_t
name|vm_map_create
parameter_list|(
name|pmap_t
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
name|vm_offset_t
parameter_list|,
name|int
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
name|vm_map_find_min
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
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
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
name|vm_map_fixed
parameter_list|(
name|vm_map_t
parameter_list|,
name|vm_object_t
parameter_list|,
name|vm_ooffset_t
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
name|vm_map_t
parameter_list|,
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
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
name|int
name|vm_map_lookup_locked
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
name|vm_map_simplify_entry
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|vm_map_entry_t
name|entry
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
name|vm_map_sync
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
name|vm_map_unwire
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|vm_offset_t
name|start
parameter_list|,
name|vm_offset_t
name|end
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_wire
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|vm_offset_t
name|start
parameter_list|,
name|vm_offset_t
name|end
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
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

