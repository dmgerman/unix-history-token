begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)filedesc.h	7.3 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FILEDESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_FILEDESC_H_
end_define

begin_comment
comment|/*  * This structure is used for the management of descriptors.  * It may be shared by multiple threads.  *  * A process is initially started out with NDFILE worth of  * descriptors, selected to be enough for typical applications  * based on the historic limit of 20 open files. Additional  * descriptors may be allocated up to a process' resource limit.  * The initial expansion is set to NOEXTENT; each time it runs out,  * it is doubled until the resource limit is reached. NOEXTENT should  * be selected to be the biggest multiple of OFILESIZE (see below)  * that will fit in a power-of-two sized piece of memory.  */
end_comment

begin_define
define|#
directive|define
name|NOEXTENT
value|25
end_define

begin_comment
comment|/* 125 bytes in 128-byte alloc. */
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
name|int
name|fd_lastfile
decl_stmt|;
comment|/* high-water mark of fd_ofiles */
name|int
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
comment|/*  * Data structure access macros.  */
end_comment

begin_define
define|#
directive|define
name|OFILE
parameter_list|(
name|fd
parameter_list|,
name|indx
parameter_list|)
value|((fd)->fd_ofiles[indx])
end_define

begin_define
define|#
directive|define
name|OFILEFLAGS
parameter_list|(
name|fd
parameter_list|,
name|indx
parameter_list|)
value|((fd)->fd_ofileflags[indx])
end_define

begin_define
define|#
directive|define
name|OFILESIZE
value|(sizeof(struct file *) + sizeof(char))
end_define

begin_comment
comment|/*  * Kernel global variables and routines.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|filedesc
modifier|*
name|fdcopy
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FILEDESC_H_ */
end_comment

end_unit

