begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vm.h	8.4 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_H
end_ifndef

begin_define
define|#
directive|define
name|VM_H
end_define

begin_typedef
typedef|typedef
name|int
name|vm_inherit_t
typedef|;
end_typedef

begin_comment
comment|/* XXX: inheritance codes */
end_comment

begin_union_decl
union_decl|union
name|vm_map_object
union_decl|;
end_union_decl

begin_typedef
typedef|typedef
name|union
name|vm_map_object
name|vm_map_object_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|vm_map_entry
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|vm_map_entry
modifier|*
name|vm_map_entry_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|vm_map
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|vm_map
modifier|*
name|vm_map_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|vm_object
modifier|*
name|vm_object_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|vm_page
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|vm_page
modifier|*
name|vm_page_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|pager_struct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|pager_struct
modifier|*
name|vm_pager_t
typedef|;
end_typedef

begin_comment
comment|/*  *	MACH VM locking primitives mappings to kernel locking primitives.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|simplelock
name|simple_lock_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|simplelock
modifier|*
name|simple_lock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lock
name|lock_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lock
modifier|*
name|lock_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
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
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_comment
comment|/*  * Shareable process virtual address space.  * May eventually be merged with vm_map.  * Several fields are temporary (text, data stuff).  */
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
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VM_H */
end_comment

end_unit

