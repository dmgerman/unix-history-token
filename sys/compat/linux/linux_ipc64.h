begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Maxim Sobolev<sobomax@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_IPC64_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_IPC64_H_
end_define

begin_comment
comment|/*  * The generic ipc64_perm structure.  * Note extra padding because this structure is passed back and forth  * between kernel and user space.  *  * Pad space is left for:  * - 32-bit mode_t on architectures that only had 16 bit  * - 32-bit seq  * - 2 miscellaneous 32-bit values  */
end_comment

begin_struct
struct|struct
name|l_ipc64_perm
block|{
name|l_key_t
name|key
decl_stmt|;
name|l_uid_t
name|uid
decl_stmt|;
name|l_gid_t
name|gid
decl_stmt|;
name|l_uid_t
name|cuid
decl_stmt|;
name|l_gid_t
name|cgid
decl_stmt|;
name|l_mode_t
name|mode
decl_stmt|;
comment|/* pad if mode_t is ushort: */
name|unsigned
name|char
name|__pad1
index|[
sizeof|sizeof
argument_list|(
name|l_int
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|l_mode_t
argument_list|)
index|]
decl_stmt|;
name|l_ushort
name|seq
decl_stmt|;
name|l_ushort
name|__pad2
decl_stmt|;
name|l_ulong
name|__unused1
decl_stmt|;
name|l_ulong
name|__unused2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The generic msqid64_ds structure fro x86 architecture.  * Note extra padding because this structure is passed back and forth  * between kernel and user space.  *  * Pad space is left for:  * - 64-bit time_t to solve y2038 problem  * - 2 miscellaneous 32-bit values  */
end_comment

begin_struct
struct|struct
name|l_msqid64_ds
block|{
name|struct
name|l_ipc64_perm
name|msg_perm
decl_stmt|;
name|l_time_t
name|msg_stime
decl_stmt|;
comment|/* last msgsnd time */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
name|l_ulong
name|__unused1
decl_stmt|;
endif|#
directive|endif
name|l_time_t
name|msg_rtime
decl_stmt|;
comment|/* last msgrcv time */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
name|l_ulong
name|__unused2
decl_stmt|;
endif|#
directive|endif
name|l_time_t
name|msg_ctime
decl_stmt|;
comment|/* last change time */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
name|l_ulong
name|__unused3
decl_stmt|;
endif|#
directive|endif
name|l_ulong
name|msg_cbytes
decl_stmt|;
comment|/* current number of bytes on queue */
name|l_ulong
name|msg_qnum
decl_stmt|;
comment|/* number of messages in queue */
name|l_ulong
name|msg_qbytes
decl_stmt|;
comment|/* max number of bytes on queue */
name|l_pid_t
name|msg_lspid
decl_stmt|;
comment|/* pid of last msgsnd */
name|l_pid_t
name|msg_lrpid
decl_stmt|;
comment|/* last receive pid */
name|l_ulong
name|__unused4
decl_stmt|;
name|l_ulong
name|__unused5
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The generic semid64_ds structure for x86 architecture.  * Note extra padding because this structure is passed back and forth  * between kernel and user space.  *  * Pad space is left for:  * - 64-bit time_t to solve y2038 problem  * - 2 miscellaneous 32-bit values  */
end_comment

begin_struct
struct|struct
name|l_semid64_ds
block|{
name|struct
name|l_ipc64_perm
name|sem_perm
decl_stmt|;
comment|/* permissions */
name|l_time_t
name|sem_otime
decl_stmt|;
comment|/* last semop time */
name|l_ulong
name|__unused1
decl_stmt|;
name|l_time_t
name|sem_ctime
decl_stmt|;
comment|/* last change time */
name|l_ulong
name|__unused2
decl_stmt|;
name|l_ulong
name|sem_nsems
decl_stmt|;
comment|/* no. of semaphores in array */
name|l_ulong
name|__unused3
decl_stmt|;
name|l_ulong
name|__unused4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The generic shmid64_ds structure for x86 architecture.  * Note extra padding because this structure is passed back and forth  * between kernel and user space.  *  * Pad space is left for:  * - 64-bit time_t to solve y2038 problem  * - 2 miscellaneous 32-bit values  */
end_comment

begin_struct
struct|struct
name|l_shmid64_ds
block|{
name|struct
name|l_ipc64_perm
name|shm_perm
decl_stmt|;
comment|/* operation perms */
name|l_size_t
name|shm_segsz
decl_stmt|;
comment|/* size of segment (bytes) */
name|l_time_t
name|shm_atime
decl_stmt|;
comment|/* last attach time */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
name|l_ulong
name|__unused1
decl_stmt|;
endif|#
directive|endif
name|l_time_t
name|shm_dtime
decl_stmt|;
comment|/* last detach time */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
name|l_ulong
name|__unused2
decl_stmt|;
endif|#
directive|endif
name|l_time_t
name|shm_ctime
decl_stmt|;
comment|/* last change time */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
name|l_ulong
name|__unused3
decl_stmt|;
endif|#
directive|endif
name|l_pid_t
name|shm_cpid
decl_stmt|;
comment|/* pid of creator */
name|l_pid_t
name|shm_lpid
decl_stmt|;
comment|/* pid of last operator */
name|l_ulong
name|shm_nattch
decl_stmt|;
comment|/* no. of current attaches */
name|l_ulong
name|__unused4
decl_stmt|;
name|l_ulong
name|__unused5
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_shminfo64
block|{
name|l_ulong
name|shmmax
decl_stmt|;
name|l_ulong
name|shmmin
decl_stmt|;
name|l_ulong
name|shmmni
decl_stmt|;
name|l_ulong
name|shmseg
decl_stmt|;
name|l_ulong
name|shmall
decl_stmt|;
name|l_ulong
name|__unused1
decl_stmt|;
name|l_ulong
name|__unused2
decl_stmt|;
name|l_ulong
name|__unused3
decl_stmt|;
name|l_ulong
name|__unused4
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LINUX_IPC64_H_ */
end_comment

end_unit

