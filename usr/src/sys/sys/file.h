begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)file.h	7.7 (Berkeley) %G%  */
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

begin_comment
comment|/*  * Kernel descriptor table entry;  * one for each open kernel vnode and socket.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|int
name|f_flag
decl_stmt|;
comment|/* see below */
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
function_decl|(
modifier|*
name|fo_read
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_write
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_ioctl
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_select
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_close
function_decl|)
parameter_list|()
function_decl|;
block|}
modifier|*
name|f_ops
struct|;
name|caddr_t
name|f_data
decl_stmt|;
comment|/* inode */
name|off_t
name|f_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|file
modifier|*
name|file
decl_stmt|,
modifier|*
name|fileNFILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfile
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

