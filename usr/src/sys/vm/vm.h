begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vm.h	7.1 (Berkeley) %G%  */
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
file|<vm/queue.h>
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
file|<vm/vm_statistics.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
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

begin_decl_stmt
name|struct
name|vmspace
modifier|*
name|vmspace_alloc
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|min
operator|,
name|vm_offset_t
name|max
operator|,
name|int
name|pageable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vmspace
modifier|*
name|vmspace_fork
name|__P
argument_list|(
operator|(
expr|struct
name|vmspace
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vmspace_free
name|__P
argument_list|(
operator|(
expr|struct
name|vmspace
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VM_H */
end_comment

end_unit

