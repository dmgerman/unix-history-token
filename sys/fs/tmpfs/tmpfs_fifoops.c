begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: tmpfs_fifoops.c,v 1.5 2005/12/11 12:24:29 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Julio M. Merino Vidal, developed as part of Google's Summer of Code  * 2005 program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * tmpfs vnode interface for named pipes.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<fs/tmpfs/tmpfs.h>
end_include

begin_include
include|#
directive|include
file|<fs/tmpfs/tmpfs_fifoops.h>
end_include

begin_include
include|#
directive|include
file|<fs/tmpfs/tmpfs_vnops.h>
end_include

begin_function
specifier|static
name|int
name|tmpfs_fifo_close
parameter_list|(
name|struct
name|vop_close_args
modifier|*
name|v
parameter_list|)
block|{
name|struct
name|tmpfs_node
modifier|*
name|node
decl_stmt|;
name|node
operator|=
name|VP_TO_TMPFS_NODE
argument_list|(
name|v
operator|->
name|a_vp
argument_list|)
expr_stmt|;
name|tmpfs_set_status
argument_list|(
name|node
argument_list|,
name|TMPFS_NODE_ACCESSED
argument_list|)
expr_stmt|;
name|tmpfs_update
argument_list|(
name|v
operator|->
name|a_vp
argument_list|)
expr_stmt|;
return|return
operator|(
name|fifo_specops
operator|.
name|vop_close
argument_list|(
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * vnode operations vector used for fifos stored in a tmpfs file system.  */
end_comment

begin_decl_stmt
name|struct
name|vop_vector
name|tmpfs_fifoop_entries
init|=
block|{
operator|.
name|vop_default
operator|=
operator|&
name|fifo_specops
block|,
operator|.
name|vop_close
operator|=
name|tmpfs_fifo_close
block|,
operator|.
name|vop_reclaim
operator|=
name|tmpfs_reclaim
block|,
operator|.
name|vop_access
operator|=
name|tmpfs_access
block|,
operator|.
name|vop_getattr
operator|=
name|tmpfs_getattr
block|,
operator|.
name|vop_setattr
operator|=
name|tmpfs_setattr
block|,
operator|.
name|vop_print
operator|=
name|tmpfs_print
block|, }
decl_stmt|;
end_decl_stmt

end_unit

