begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Poul-Henning Kamp.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file documents a private interface and it SHALL only be used  * by kern/kern_conf.c and fs/devfs/...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_DEVFS_DEVFS_INT_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_DEVFS_DEVFS_INT_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|devfs_dirent
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|cdev_priv
block|{
name|struct
name|cdev
name|cdp_c
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|cdev_priv
argument_list|)
name|cdp_list
expr_stmt|;
name|u_int
name|cdp_inode
decl_stmt|;
name|u_int
name|cdp_flags
decl_stmt|;
define|#
directive|define
name|CDP_ACTIVE
value|(1<< 0)
name|u_int
name|cdp_inuse
decl_stmt|;
name|u_int
name|cdp_maxdirent
decl_stmt|;
name|struct
name|devfs_dirent
modifier|*
modifier|*
name|cdp_dirents
decl_stmt|;
name|struct
name|devfs_dirent
modifier|*
name|cdp_dirent0
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|cdev
modifier|*
name|devfs_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_free
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_create
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_destroy
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|unrhdr
modifier|*
name|devfs_inos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|devmtx
decl_stmt|;
end_decl_stmt

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
comment|/* !_FS_DEVFS_DEVFS_INT_H_ */
end_comment

end_unit

