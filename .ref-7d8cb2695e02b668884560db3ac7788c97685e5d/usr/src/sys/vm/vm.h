begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vm.h	7.5 (Berkeley) %G%  */
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

begin_comment
comment|/*  * Compatibility with old MACH queue.h  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|queue_entry
modifier|*
name|queue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|queue_entry
name|queue_head_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|queue_entry
name|queue_chain_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|queue_entry
modifier|*
name|queue_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|queue_first
parameter_list|(
name|head
parameter_list|)
value|((head)->qe_next)
end_define

begin_define
define|#
directive|define
name|queue_next
parameter_list|(
name|elm
parameter_list|)
value|((elm)->qe_next)
end_define

begin_define
define|#
directive|define
name|queue_empty
parameter_list|(
name|head
parameter_list|)
value|((head)->qe_next == 0)
end_define

begin_define
define|#
directive|define
name|queue_end
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|)
value|((elm) == 0)
end_define

begin_define
define|#
directive|define
name|queue_enter
parameter_list|(
name|head
parameter_list|,
name|elt
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|queue_enter_tail(head, elt, type, field)
end_define

begin_define
define|#
directive|define
name|queue_remove_first
parameter_list|(
name|head
parameter_list|,
name|elt
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	elt = queue_first(head); \ 	queue_remove(head, elt, type, field) \ }
end_define

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/lock.h>
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

