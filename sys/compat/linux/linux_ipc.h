begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_IPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_IPC_H_
end_define

begin_comment
comment|/*  * SystemV IPC defines  */
end_comment

begin_define
define|#
directive|define
name|LINUX_SEMOP
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SEMGET
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SEMCTL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_MSGSND
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_MSGRCV
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_MSGGET
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_MSGCTL
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SHMAT
value|21
end_define

begin_define
define|#
directive|define
name|LINUX_SHMDT
value|22
end_define

begin_define
define|#
directive|define
name|LINUX_SHMGET
value|23
end_define

begin_define
define|#
directive|define
name|LINUX_SHMCTL
value|24
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_RMID
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_SET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_STAT
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_INFO
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_INFO
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_LOCK
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_UNLOCK
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_STAT
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_INFO
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_RDONLY
value|0x1000
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_RND
value|0x2000
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_REMAP
value|0x4000
end_define

begin_comment
comment|/* semctl commands */
end_comment

begin_define
define|#
directive|define
name|LINUX_GETPID
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_GETVAL
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_GETALL
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_GETNCNT
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_GETZCNT
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_SETVAL
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_SETALL
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SEM_STAT
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_SEM_INFO
value|19
end_define

begin_comment
comment|/*  * Version flags for semctl, msgctl, and shmctl commands  * These are passed as bitflags or-ed with the actual command  */
end_comment

begin_define
define|#
directive|define
name|LINUX_IPC_OLD
value|0
end_define

begin_comment
comment|/* Old version (no 32-bit UID support on many 				   architectures) */
end_comment

begin_define
define|#
directive|define
name|LINUX_IPC_64
value|0x0100
end_define

begin_comment
comment|/* New version (support 32-bit UIDs, bigger 				   message sizes, etc. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|&&
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
operator|)
end_if

begin_struct
struct|struct
name|linux_msgctl_args
block|{
name|l_int
name|msqid
decl_stmt|;
name|l_int
name|cmd
decl_stmt|;
name|struct
name|l_msqid_ds
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_msgget_args
block|{
name|l_key_t
name|key
decl_stmt|;
name|l_int
name|msgflg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_msgrcv_args
block|{
name|l_int
name|msqid
decl_stmt|;
name|struct
name|l_msgbuf
modifier|*
name|msgp
decl_stmt|;
name|l_size_t
name|msgsz
decl_stmt|;
name|l_long
name|msgtyp
decl_stmt|;
name|l_int
name|msgflg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_msgsnd_args
block|{
name|l_int
name|msqid
decl_stmt|;
name|struct
name|l_msgbuf
modifier|*
name|msgp
decl_stmt|;
name|l_size_t
name|msgsz
decl_stmt|;
name|l_int
name|msgflg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_semctl_args
block|{
name|l_int
name|semid
decl_stmt|;
name|l_int
name|semnum
decl_stmt|;
name|l_int
name|cmd
decl_stmt|;
name|union
name|l_semun
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_semget_args
block|{
name|l_key_t
name|key
decl_stmt|;
name|l_int
name|nsems
decl_stmt|;
name|l_int
name|semflg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_semop_args
block|{
name|l_int
name|semid
decl_stmt|;
name|struct
name|l_sembuf
modifier|*
name|tsops
decl_stmt|;
name|l_uint
name|nsops
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_shmat_args
block|{
name|l_int
name|shmid
decl_stmt|;
name|char
modifier|*
name|shmaddr
decl_stmt|;
name|l_int
name|shmflg
decl_stmt|;
name|l_ulong
modifier|*
name|raddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_shmctl_args
block|{
name|l_int
name|shmid
decl_stmt|;
name|l_int
name|cmd
decl_stmt|;
name|struct
name|l_shmid_ds
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_shmdt_args
block|{
name|char
modifier|*
name|shmaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_shmget_args
block|{
name|l_key_t
name|key
decl_stmt|;
name|l_size_t
name|size
decl_stmt|;
name|l_int
name|shmflg
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|linux_msgctl
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_msgctl_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_msgget
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_msgget_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_msgrcv
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_msgrcv_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_msgsnd
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_msgsnd_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_semctl
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_semctl_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_semget
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_semget_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_semop
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_semop_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_shmat
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_shmat_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_shmctl
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_shmctl_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_shmdt
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_shmdt_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_shmget
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_shmget_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ || (__amd64__&& COMPAT_LINUX32) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_IPC_H_ */
end_comment

end_unit

