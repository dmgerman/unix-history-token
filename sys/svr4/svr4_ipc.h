begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1995 Christos Zoulas.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Christos Zoulas.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_IPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_IPC_H_
end_define

begin_comment
comment|/*  * General IPC  */
end_comment

begin_define
define|#
directive|define
name|SVR4_IPC_RMID
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_IPC_SET
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_IPC_STAT
value|12
end_define

begin_struct
struct|struct
name|svr4_ipc_perm
block|{
name|svr4_uid_t
name|uid
decl_stmt|;
name|svr4_gid_t
name|gid
decl_stmt|;
name|svr4_uid_t
name|cuid
decl_stmt|;
name|svr4_gid_t
name|cgid
decl_stmt|;
name|svr4_mode_t
name|mode
decl_stmt|;
name|u_long
name|seq
decl_stmt|;
name|svr4_key_t
name|key
decl_stmt|;
name|long
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Message queues  */
end_comment

begin_define
define|#
directive|define
name|SVR4_msgget
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_msgctl
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_msgrcv
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_msgsnd
value|3
end_define

begin_struct
struct|struct
name|svr4_msg
block|{
name|struct
name|svr4_msg
modifier|*
name|msg_next
decl_stmt|;
name|long
name|msg_type
decl_stmt|;
name|u_short
name|msg_ts
decl_stmt|;
name|short
name|msg_spot
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_msqid_ds
block|{
name|struct
name|svr4_ipc_perm
name|msg_perm
decl_stmt|;
name|struct
name|svr4_msg
modifier|*
name|msg_first
decl_stmt|;
name|struct
name|svr4_msg
modifier|*
name|msg_last
decl_stmt|;
name|u_long
name|msg_cbytes
decl_stmt|;
name|u_long
name|msg_qnum
decl_stmt|;
name|u_long
name|msg_qbytes
decl_stmt|;
name|svr4_pid_t
name|msg_lspid
decl_stmt|;
name|svr4_pid_t
name|msg_lrpid
decl_stmt|;
name|svr4_time_t
name|msg_stime
decl_stmt|;
name|long
name|msg_pad1
decl_stmt|;
name|svr4_time_t
name|msg_rtime
decl_stmt|;
name|long
name|msg_pad2
decl_stmt|;
name|svr4_time_t
name|msg_ctime
decl_stmt|;
name|long
name|msg_pad3
decl_stmt|;
name|short
name|msg_cv
decl_stmt|;
name|short
name|msg_qnum_cv
decl_stmt|;
name|long
name|msg_pad4
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_msgbuf
block|{
name|long
name|mtype
decl_stmt|;
comment|/* message type */
name|char
name|mtext
index|[
literal|1
index|]
decl_stmt|;
comment|/* message text */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_msginfo
block|{
name|int
name|msgmap
decl_stmt|;
name|int
name|msgmax
decl_stmt|;
name|int
name|msgmnb
decl_stmt|;
name|int
name|msgmni
decl_stmt|;
name|int
name|msgssz
decl_stmt|;
name|int
name|msgtql
decl_stmt|;
name|u_short
name|msgseg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Shared memory  */
end_comment

begin_define
define|#
directive|define
name|SVR4_shmat
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_shmctl
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_shmdt
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_shmget
value|3
end_define

begin_comment
comment|/* shmctl() operations */
end_comment

begin_define
define|#
directive|define
name|SVR4_SHM_LOCK
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_SHM_UNLOCK
value|4
end_define

begin_struct
struct|struct
name|svr4_shmid_ds
block|{
name|struct
name|svr4_ipc_perm
name|shm_perm
decl_stmt|;
name|int
name|shm_segsz
decl_stmt|;
name|void
modifier|*
name|shm_amp
decl_stmt|;
name|u_short
name|shm_lkcnt
decl_stmt|;
name|svr4_pid_t
name|shm_lpid
decl_stmt|;
name|svr4_pid_t
name|shm_cpid
decl_stmt|;
name|u_long
name|shm_nattch
decl_stmt|;
name|u_long
name|shm_cnattch
decl_stmt|;
name|svr4_time_t
name|shm_atime
decl_stmt|;
name|long
name|shm_pad1
decl_stmt|;
name|svr4_time_t
name|shm_dtime
decl_stmt|;
name|long
name|shm_pad2
decl_stmt|;
name|svr4_time_t
name|shm_ctime
decl_stmt|;
name|long
name|shm_pad3
decl_stmt|;
name|long
name|shm_pad4
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Semaphores  */
end_comment

begin_define
define|#
directive|define
name|SVR4_semctl
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_semget
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_semop
value|2
end_define

begin_comment
comment|/* semctl() operations */
end_comment

begin_define
define|#
directive|define
name|SVR4_SEM_GETNCNT
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_SEM_GETPID
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_SEM_GETVAL
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_SEM_GETALL
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_SEM_GETZCNT
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_SEM_SETVAL
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_SEM_SETALL
value|9
end_define

begin_struct
struct|struct
name|svr4_sem
block|{
name|u_short
name|semval
decl_stmt|;
name|svr4_pid_t
name|sempid
decl_stmt|;
name|u_short
name|semncnt
decl_stmt|;
name|u_short
name|semzcnt
decl_stmt|;
name|u_short
name|semncnt_cv
decl_stmt|;
name|u_short
name|semzcnt_cv
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_semid_ds
block|{
name|struct
name|svr4_ipc_perm
name|sem_perm
decl_stmt|;
name|struct
name|svr4_sem
modifier|*
name|sem_base
decl_stmt|;
name|u_short
name|sem_nsems
decl_stmt|;
name|svr4_time_t
name|sem_otime
decl_stmt|;
name|long
name|sem_pad1
decl_stmt|;
name|svr4_time_t
name|sem_ctime
decl_stmt|;
name|long
name|sem_pad2
decl_stmt|;
name|long
name|sem_pad3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_sembuf
block|{
name|u_short
name|sem_num
decl_stmt|;
name|short
name|sem_op
decl_stmt|;
name|short
name|sem_flg
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SVR4_IPC_H */
end_comment

end_unit

