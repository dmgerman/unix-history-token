begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copryight 2001 Jamey Wood  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|FOLLOWFORKS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RELATIVETIMESTAMPS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ABSOLUTETIMESTAMPS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NOSIGS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EXECVEARGS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EXECVEENVS
value|0x00000020
end_define

begin_struct
struct|struct
name|threadinfo
block|{
name|SLIST_ENTRY
argument_list|(
argument|threadinfo
argument_list|)
name|entries
expr_stmt|;
name|lwpid_t
name|tid
decl_stmt|;
name|int
name|in_syscall
decl_stmt|;
name|int
name|in_fork
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|trussinfo
block|{
name|int
name|pid
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|pr_why
decl_stmt|;
name|int
name|pr_data
decl_stmt|;
name|int
name|strsize
decl_stmt|;
name|FILE
modifier|*
name|outfile
decl_stmt|;
name|struct
name|timespec
name|start_time
decl_stmt|;
name|struct
name|timespec
name|before
decl_stmt|;
name|struct
name|timespec
name|after
decl_stmt|;
name|struct
name|threadinfo
modifier|*
name|curthread
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|threadinfo
argument_list|)
name|threadlist
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|timespecsubt
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\ 		(vvp)->tv_nsec = (tvp)->tv_nsec - (uvp)->tv_nsec;	\ 		if ((vvp)->tv_nsec< 0) {				\ 			(vvp)->tv_sec--;				\ 			(vvp)->tv_nsec += 1000000000;			\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|S_NONE
value|0
end_define

begin_define
define|#
directive|define
name|S_SCE
value|1
end_define

begin_define
define|#
directive|define
name|S_SCX
value|2
end_define

begin_define
define|#
directive|define
name|S_EXIT
value|3
end_define

begin_define
define|#
directive|define
name|S_SIG
value|4
end_define

begin_define
define|#
directive|define
name|S_EXEC
value|5
end_define

end_unit

