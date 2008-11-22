begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipc.h	8.4 (Berkeley) 2/19/95  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * SVID compatible ipc.h file  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IPC_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_GID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__gid_t
name|gid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_GID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_KEY_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__key_t
name|key_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_KEY_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MODE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__mode_t
name|mode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_MODE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uid_t
name|uid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX almost all members have wrong types.  */
end_comment

begin_struct
struct|struct
name|ipc_perm
block|{
name|unsigned
name|short
name|cuid
decl_stmt|;
comment|/* creator user id */
name|unsigned
name|short
name|cgid
decl_stmt|;
comment|/* creator group id */
name|unsigned
name|short
name|uid
decl_stmt|;
comment|/* user id */
name|unsigned
name|short
name|gid
decl_stmt|;
comment|/* group id */
name|unsigned
name|short
name|mode
decl_stmt|;
comment|/* r/w permission */
name|unsigned
name|short
name|seq
decl_stmt|;
comment|/* sequence # (to generate unique ipcid) */
name|key_t
name|key
decl_stmt|;
comment|/* user specified msg/sem/shm key */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/* common mode bits */
end_comment

begin_define
define|#
directive|define
name|IPC_R
value|000400
end_define

begin_comment
comment|/* read permission */
end_comment

begin_define
define|#
directive|define
name|IPC_W
value|000200
end_define

begin_comment
comment|/* write/alter permission */
end_comment

begin_define
define|#
directive|define
name|IPC_M
value|010000
end_define

begin_comment
comment|/* permission to change control info */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVID required constants (same values as system 5) */
end_comment

begin_define
define|#
directive|define
name|IPC_CREAT
value|001000
end_define

begin_comment
comment|/* create entry if key does not exist */
end_comment

begin_define
define|#
directive|define
name|IPC_EXCL
value|002000
end_define

begin_comment
comment|/* fail if key exists */
end_comment

begin_define
define|#
directive|define
name|IPC_NOWAIT
value|004000
end_define

begin_comment
comment|/* error if request must wait */
end_comment

begin_define
define|#
directive|define
name|IPC_PRIVATE
value|(key_t)0
end_define

begin_comment
comment|/* private key */
end_comment

begin_define
define|#
directive|define
name|IPC_RMID
value|0
end_define

begin_comment
comment|/* remove identifier */
end_comment

begin_define
define|#
directive|define
name|IPC_SET
value|1
end_define

begin_comment
comment|/* set options */
end_comment

begin_define
define|#
directive|define
name|IPC_STAT
value|2
end_define

begin_comment
comment|/* get options */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|IPC_INFO
value|3
end_define

begin_comment
comment|/* get info */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Macros to convert between ipc ids and array indices or sequence ids */
end_comment

begin_define
define|#
directive|define
name|IPCID_TO_IX
parameter_list|(
name|id
parameter_list|)
value|((id)& 0xffff)
end_define

begin_define
define|#
directive|define
name|IPCID_TO_SEQ
parameter_list|(
name|id
parameter_list|)
value|(((id)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|IXSEQ_TO_IPCID
parameter_list|(
name|ix
parameter_list|,
name|perm
parameter_list|)
value|(((perm.seq)<< 16) | (ix& 0xffff))
end_define

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmspace
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ipcperm
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|ipc_perm
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|shmfork_hook
function_decl|)
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|shmexit_hook
function_decl|)
parameter_list|(
name|struct
name|vmspace
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! _KERNEL */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|key_t
name|ftok
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

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
comment|/* !_SYS_IPC_H_ */
end_comment

end_unit

