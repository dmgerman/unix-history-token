begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 SigmaSoft, Th. Lockert<tholo@sigmasoft.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * The split of ipcs.c into ipcs.c and ipc.c to accomodate the  * changes in ipcrm.c was done by Edwin Groothuis<edwin@FreeBSD.org>  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Part of struct nlist symbols[] */
end_comment

begin_define
define|#
directive|define
name|X_SEMA
value|0
end_define

begin_define
define|#
directive|define
name|X_SEMINFO
value|1
end_define

begin_define
define|#
directive|define
name|X_MSGINFO
value|2
end_define

begin_define
define|#
directive|define
name|X_MSQIDS
value|3
end_define

begin_define
define|#
directive|define
name|X_SHMINFO
value|4
end_define

begin_define
define|#
directive|define
name|X_SHMSEGS
value|5
end_define

begin_define
define|#
directive|define
name|SHMINFO
value|1
end_define

begin_define
define|#
directive|define
name|SHMTOTAL
value|2
end_define

begin_define
define|#
directive|define
name|MSGINFO
value|4
end_define

begin_define
define|#
directive|define
name|MSGTOTAL
value|8
end_define

begin_define
define|#
directive|define
name|SEMINFO
value|16
end_define

begin_define
define|#
directive|define
name|SEMTOTAL
value|32
end_define

begin_define
define|#
directive|define
name|IPC_TO_STR
parameter_list|(
name|x
parameter_list|)
value|(x == 'Q' ? "msq" : (x == 'M' ? "shm" : "sem"))
end_define

begin_define
define|#
directive|define
name|IPC_TO_STRING
parameter_list|(
name|x
parameter_list|)
value|(x == 'Q' ? "message queue" : \ 	    (x == 'M' ? "shared memory segment" : "semaphore"))
end_define

begin_comment
comment|/* SysCtlGatherStruct structure. */
end_comment

begin_struct
struct|struct
name|scgs_vector
block|{
specifier|const
name|char
modifier|*
name|sysctl
decl_stmt|;
name|off_t
name|offset
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|kget
parameter_list|(
name|int
name|idx
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sysctlgatherstruct
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|struct
name|scgs_vector
modifier|*
name|vec
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|use_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nlist
name|symbols
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|kvm_t
modifier|*
name|kd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|semid_kernel
modifier|*
name|sema
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|seminfo
name|seminfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|msginfo
name|msginfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|msqid_kernel
modifier|*
name|msqids
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|shminfo
name|shminfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|shmid_kernel
modifier|*
name|shmsegs
decl_stmt|;
end_decl_stmt

end_unit

