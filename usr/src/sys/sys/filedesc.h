begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)filedesc.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This structure is used for the management of descriptors.  It may be  * shared by multiple processes.  *  * A process is initially started out with NDFILE descriptors stored within  * this structure, selected to be enough for typical applications based on  * the historical limit of 20 open files (and the usage of descriptors by  * shells).  If these descriptors are exhausted, a larger descriptor table  * may be allocated, up to a process' resource limit; the internal arrays  * are then unused.  The initial expansion is set to NDEXTENT; each time  * it runs out, it is doubled until the resource limit is reached. NDEXTENT  * should be selected to be the biggest multiple of OFILESIZE (see below)  * that will fit in a power-of-two sized piece of memory.  */
end_comment

begin_define
define|#
directive|define
name|NDFILE
value|20
end_define

begin_define
define|#
directive|define
name|NDEXTENT
value|50
end_define

begin_comment
comment|/* 250 bytes in 256-byte alloc. */
end_comment

begin_struct
struct|struct
name|filedesc
block|{
name|struct
name|file
modifier|*
modifier|*
name|fd_ofiles
decl_stmt|;
comment|/* file structures for open files */
name|char
modifier|*
name|fd_ofileflags
decl_stmt|;
comment|/* per-process open file flags */
name|struct
name|vnode
modifier|*
name|fd_cdir
decl_stmt|;
comment|/* current directory */
name|struct
name|vnode
modifier|*
name|fd_rdir
decl_stmt|;
comment|/* root directory */
name|int
name|fd_nfiles
decl_stmt|;
comment|/* number of open files allocated */
name|u_short
name|fd_lastfile
decl_stmt|;
comment|/* high-water mark of fd_ofiles */
name|u_short
name|fd_freefile
decl_stmt|;
comment|/* approx. next free file */
name|u_short
name|fd_cmask
decl_stmt|;
comment|/* mask for file creation */
name|u_short
name|fd_refcnt
decl_stmt|;
comment|/* reference count */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Basic allocation of descriptors:  * one of the above, plus arrays for NDFILE descriptors.  */
end_comment

begin_struct
struct|struct
name|filedesc0
block|{
name|struct
name|filedesc
name|fd_fd
decl_stmt|;
comment|/* 	 * These arrays are used when the number of open files is 	 *<= NDFILE, and are then pointed to by the pointers above. 	 */
name|struct
name|file
modifier|*
name|fd_dfiles
index|[
name|NDFILE
index|]
decl_stmt|;
name|char
name|fd_dfileflags
index|[
name|NDFILE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-process open flags.  */
end_comment

begin_define
define|#
directive|define
name|UF_EXCLOSE
value|0x01
end_define

begin_comment
comment|/* auto-close on exec */
end_comment

begin_define
define|#
directive|define
name|UF_MAPPED
value|0x02
end_define

begin_comment
comment|/* mapped from device */
end_comment

begin_comment
comment|/*  * Storage required per open file descriptor.  */
end_comment

begin_define
define|#
directive|define
name|OFILESIZE
value|(sizeof(struct file *) + sizeof(char))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Kernel global variables and routines.  */
end_comment

begin_decl_stmt
name|int
name|fdalloc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|want
operator|,
name|int
operator|*
name|result
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fdavail
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|falloc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|file
operator|*
operator|*
name|resultfp
operator|,
name|int
operator|*
name|resultfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|filedesc
modifier|*
name|fdcopy
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fdfree
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

