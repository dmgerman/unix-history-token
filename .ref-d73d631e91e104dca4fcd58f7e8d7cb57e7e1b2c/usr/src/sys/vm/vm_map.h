begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1985, Avadis Tevanian, Jr., Michael Wayne Young  * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)vm_map.h	7.1 (Berkeley) %G%  */
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
file|"lock.h"
end_include

begin_include
include|#
directive|include
file|"../vm/pmap.h"
end_include

begin_include
include|#
directive|include
file|"../vm/vm_prot.h"
end_include

begin_include
include|#
directive|include
file|"../vm/vm_inherit.h"
end_include

begin_include
include|#
directive|include
file|"../vm/vm_object.h"
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_prot.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_inherit.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_typedef
typedef|typedef
name|union
name|vm_map_object
name|vm_map_object_t
typedef|;
end_typedef

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
name|vm_offset_t
name|offset
decl_stmt|;
comment|/* offset into object */
name|boolean_t
name|is_a_map
decl_stmt|;
comment|/* Is "object" a map? */
name|boolean_t
name|is_sub_map
decl_stmt|;
comment|/* Is "object" a submap? */
comment|/* Only in sharing maps: */
name|boolean_t
name|copy_on_write
decl_stmt|;
comment|/* is data copy-on-write */
name|boolean_t
name|needs_copy
decl_stmt|;
comment|/* does object need to be copied */
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

begin_typedef
typedef|typedef
name|struct
name|vm_map_entry
modifier|*
name|vm_map_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VM_MAP_ENTRY_NULL
value|((vm_map_entry_t) 0)
end_define

begin_comment
comment|/*  *	Maps are doubly-linked lists of map entries, kept sorted  *	by address.  A single hint is provided to start  *	searches again from the last successful search,  *	insertion, or removal.  */
end_comment

begin_struct
struct|struct
name|vm_map
block|{
name|lock_data_t
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
name|pmap_t
name|pmap
decl_stmt|;
comment|/* Physical map */
name|vm_size_t
name|size
decl_stmt|;
comment|/* virtual size */
name|boolean_t
name|is_main_map
decl_stmt|;
comment|/* Am I a main map? */
name|int
name|ref_count
decl_stmt|;
comment|/* Reference count */
name|simple_lock_data_t
name|ref_lock
decl_stmt|;
comment|/* Lock for ref_count field */
name|vm_map_entry_t
name|hint
decl_stmt|;
comment|/* hint for quick lookups */
name|simple_lock_data_t
name|hint_lock
decl_stmt|;
comment|/* lock for hint storage */
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

begin_typedef
typedef|typedef
name|struct
name|vm_map
modifier|*
name|vm_map_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VM_MAP_NULL
value|((vm_map_t) 0)
end_define

begin_comment
comment|/*  *	Map versions are used to validate a previous lookup attempt.  *  *	Since lookup operations may involve both a main map and  *	a sharing map, it is necessary to have a timestamp from each.  *	[If the main map timestamp has changed, the share_map and  *	associated timestamp are no longer valid; the map version  *	does not include a reference for the imbedded share_map.]  */
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
name|vm_map_lock
parameter_list|(
name|map
parameter_list|)
value|{ lock_write(&(map)->lock); (map)->timestamp++; }
end_define

begin_define
define|#
directive|define
name|vm_map_unlock
parameter_list|(
name|map
parameter_list|)
value|lock_write_done(&(map)->lock)
end_define

begin_define
define|#
directive|define
name|vm_map_lock_read
parameter_list|(
name|map
parameter_list|)
value|lock_read(&(map)->lock)
end_define

begin_define
define|#
directive|define
name|vm_map_unlock_read
parameter_list|(
name|map
parameter_list|)
value|lock_read_done(&(map)->lock)
end_define

begin_comment
comment|/*  *	Exported procedures that operate on vm_map_t.  */
end_comment

begin_function_decl
name|void
name|vm_map_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_map_t
name|vm_map_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_deallocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_reference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_find
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_remove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_lookup_done
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_protect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_inherit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_map_copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_map_t
name|vm_map_fork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_copy_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_map_verify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_map_verify_done
parameter_list|()
function_decl|;
end_function_decl

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
value|500
end_define

begin_endif
endif|#
directive|endif
endif|_VM_MAP_
end_endif

end_unit

