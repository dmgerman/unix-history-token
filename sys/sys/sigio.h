begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)filedesc.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SIGIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SIGIO_H_
end_define

begin_comment
comment|/*  * This structure holds the information needed to send a SIGIO or  * a SIGURG signal to a process or process group when new data arrives  * on a device or socket.  The structure is placed on an SLIST belonging  * to the proc or pgrp so that the entire list may be revoked when the  * process exits or the process group disappears.  *  * (c)	const  * (pg)	locked by either the process or process group lock  */
end_comment

begin_struct
struct|struct
name|sigio
block|{
union|union
block|{
name|struct
name|proc
modifier|*
name|siu_proc
decl_stmt|;
comment|/* (c)	process to receive SIGIO/SIGURG */
name|struct
name|pgrp
modifier|*
name|siu_pgrp
decl_stmt|;
comment|/* (c)	process group to receive ... */
block|}
name|sio_u
union|;
name|SLIST_ENTRY
argument_list|(
argument|sigio
argument_list|)
name|sio_pgsigio
expr_stmt|;
comment|/* (pg)	sigio's for process or group */
name|struct
name|sigio
modifier|*
modifier|*
name|sio_myref
decl_stmt|;
comment|/* (c)	location of the pointer that holds 					 * 	the reference to this structure */
name|struct
name|ucred
modifier|*
name|sio_ucred
decl_stmt|;
comment|/* (c)	current credentials */
name|pid_t
name|sio_pgid
decl_stmt|;
comment|/* (c)	pgid for signals */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sio_proc
value|sio_u.siu_proc
end_define

begin_define
define|#
directive|define
name|sio_pgrp
value|sio_u.siu_pgrp
end_define

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|sigiolst
argument_list|,
name|sigio
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|pid_t
name|fgetown
parameter_list|(
name|struct
name|sigio
modifier|*
modifier|*
name|sigiop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fsetown
parameter_list|(
name|pid_t
name|pgid
parameter_list|,
name|struct
name|sigio
modifier|*
modifier|*
name|sigiop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|funsetown
parameter_list|(
name|struct
name|sigio
modifier|*
modifier|*
name|sigiop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|funsetownlst
parameter_list|(
name|struct
name|sigiolst
modifier|*
name|sigiolst
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SIGIO_H_ */
end_comment

end_unit

