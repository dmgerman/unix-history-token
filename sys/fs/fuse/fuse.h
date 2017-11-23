begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007-2009 Google Inc.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *   * * Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  * * Redistributions in binary form must reproduce the above  *   copyright notice, this list of conditions and the following disclaimer  *   in the documentation and/or other materials provided with the  *   distribution.  * * Neither the name of Google Inc. nor the names of its  *   contributors may be used to endorse or promote products derived from  *   this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * Copyright (C) 2005 Csaba Henk.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"fuse_kernel.h"
end_include

begin_define
define|#
directive|define
name|FUSE_DEFAULT_DAEMON_TIMEOUT
value|60
end_define

begin_comment
comment|/* s */
end_comment

begin_define
define|#
directive|define
name|FUSE_MIN_DAEMON_TIMEOUT
value|0
end_define

begin_comment
comment|/* s */
end_comment

begin_define
define|#
directive|define
name|FUSE_MAX_DAEMON_TIMEOUT
value|600
end_define

begin_comment
comment|/* s */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_FREEBSD_VERSION
end_ifndef

begin_define
define|#
directive|define
name|FUSE_FREEBSD_VERSION
value|"0.4.4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Mapping versions to features */
end_comment

begin_define
define|#
directive|define
name|FUSE_KERNELABI_GEQ
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|)
define|\
value|(FUSE_KERNEL_VERSION> (maj) || (FUSE_KERNEL_VERSION == (maj)&& FUSE_KERNEL_MINOR_VERSION>= (min)))
end_define

begin_comment
comment|/*  * Appearance of new FUSE operations is not always in par with version  * numbering... At least, 7.3 is a sufficient condition for having  * FUSE_{ACCESS,CREATE}.  */
end_comment

begin_if
if|#
directive|if
name|FUSE_KERNELABI_GEQ
argument_list|(
literal|7
operator|,
literal|3
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_ACCESS
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_ACCESS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_CREATE
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_CREATE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FUSE_KERNELABI_GEQ(7, 3) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_ACCESS
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_ACCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_CREATE
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_CREATE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FUSE_KERNELABI_GEQ
argument_list|(
literal|7
operator|,
literal|7
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_GETLK
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_GETLK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_SETLK
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_SETLK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_SETLKW
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_SETLKW
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_INTERRUPT
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_INTERRUPT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FUSE_KERNELABI_GEQ(7, 7) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_GETLK
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_GETLK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_SETLK
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_SETLK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_SETLKW
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_SETLKW
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_INTERRUPT
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_INTERRUPT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FUSE_KERNELABI_GEQ
argument_list|(
literal|7
operator|,
literal|8
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_FLUSH_RELEASE
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_FLUSH_RELEASE
value|1
end_define

begin_comment
comment|/*  * "DESTROY" came in the middle of the 7.8 era,  * so this is not completely exact...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_DESTROY
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_DESTROY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FUSE_KERNELABI_GEQ(7, 8) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_FLUSH_RELEASE
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_FLUSH_RELEASE
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_HAS_DESTROY
end_ifndef

begin_define
define|#
directive|define
name|FUSE_HAS_DESTROY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* misc */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_vfs_fuse
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Fuse locking */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|fuse_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FUSE_LOCK
parameter_list|()
value|fuse_lck_mtx_lock(fuse_mtx)
end_define

begin_define
define|#
directive|define
name|FUSE_UNLOCK
parameter_list|()
value|fuse_lck_mtx_unlock(fuse_mtx)
end_define

begin_define
define|#
directive|define
name|RECTIFY_TDCR
parameter_list|(
name|td
parameter_list|,
name|cred
parameter_list|)
define|\
value|do {						\ 	if (! (td))				\ 		(td) = curthread;		\ 	if (! (cred))				\ 		(cred) = (td)->td_ucred;	\ } while (0)
end_define

begin_comment
comment|/* Debug related stuff */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_DEVICE
end_ifndef

begin_define
define|#
directive|define
name|FUSE_DEBUG_DEVICE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_FILE
end_ifndef

begin_define
define|#
directive|define
name|FUSE_DEBUG_FILE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_INTERNAL
end_ifndef

begin_define
define|#
directive|define
name|FUSE_DEBUG_INTERNAL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_IO
end_ifndef

begin_define
define|#
directive|define
name|FUSE_DEBUG_IO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_IPC
end_ifndef

begin_define
define|#
directive|define
name|FUSE_DEBUG_IPC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_LOCK
end_ifndef

begin_define
define|#
directive|define
name|FUSE_DEBUG_LOCK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_VFSOPS
end_ifndef

begin_define
define|#
directive|define
name|FUSE_DEBUG_VFSOPS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_VNOPS
end_ifndef

begin_define
define|#
directive|define
name|FUSE_DEBUG_VNOPS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_TRACE
end_ifndef

begin_define
define|#
directive|define
name|FUSE_TRACE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEBUGX
parameter_list|(
name|cond
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {                     \     if (((cond))) {                                     \         printf("%s: " fmt, __func__, ## __VA_ARGS__);   \     } } while (0)
end_define

begin_define
define|#
directive|define
name|fuse_lck_mtx_lock
parameter_list|(
name|mtx
parameter_list|)
value|do {                                     \     DEBUGX(FUSE_DEBUG_LOCK, "0:   lock(%s): %s@%d by %d\n",             \         __STRING(mtx), __func__, __LINE__, curthread->td_proc->p_pid);  \     mtx_lock(&(mtx));                                                   \     DEBUGX(FUSE_DEBUG_LOCK, "1:   lock(%s): %s@%d by %d\n",             \         __STRING(mtx), __func__, __LINE__, curthread->td_proc->p_pid);  \     } while (0)
end_define

begin_define
define|#
directive|define
name|fuse_lck_mtx_unlock
parameter_list|(
name|mtx
parameter_list|)
value|do {                                   \     DEBUGX(FUSE_DEBUG_LOCK, "0: unlock(%s): %s@%d by %d\n",             \         __STRING(mtx), __func__, __LINE__, curthread->td_proc->p_pid);  \     mtx_unlock(&(mtx));                                                 \     DEBUGX(FUSE_DEBUG_LOCK, "1: unlock(%s): %s@%d by %d\n",             \         __STRING(mtx), __func__, __LINE__, curthread->td_proc->p_pid);  \     } while (0)
end_define

begin_function_decl
name|void
name|fuse_ipc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fuse_ipc_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fuse_device_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fuse_device_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

