begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)file.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Kernel descriptor table.  * One entry for each open kernel vnode and socket.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|struct
name|file
modifier|*
name|f_filef
decl_stmt|;
comment|/* list of active files */
name|struct
name|file
modifier|*
modifier|*
name|f_fileb
decl_stmt|;
comment|/* list of active files */
name|short
name|f_flag
decl_stmt|;
comment|/* see fcntl.h */
define|#
directive|define
name|DTYPE_VNODE
value|1
comment|/* file */
define|#
directive|define
name|DTYPE_SOCKET
value|2
comment|/* communications endpoint */
name|short
name|f_type
decl_stmt|;
comment|/* descriptor type */
name|short
name|f_count
decl_stmt|;
comment|/* reference count */
name|short
name|f_msgcount
decl_stmt|;
comment|/* references from message queue */
name|struct
name|ucred
modifier|*
name|f_cred
decl_stmt|;
comment|/* credentials associated with descriptor */
struct|struct
name|fileops
block|{
name|int
argument_list|(
argument|*fo_read
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fo_write
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fo_ioctl
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|com
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fo_select
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|which
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fo_close
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
block|}
modifier|*
name|f_ops
struct|;
name|off_t
name|f_offset
decl_stmt|;
name|caddr_t
name|f_data
decl_stmt|;
comment|/* vnode or socket */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|file
modifier|*
name|filehead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list of open files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel limit on number of open files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual number of open files */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

