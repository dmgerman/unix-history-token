begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department. Originally from University of Wisconsin.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: uipc_shm.c 1.9 89/08/14$  *  *	@(#)sysv_shm.c	7.15 (Berkeley) 5/13/91  */
end_comment

begin_comment
comment|/*  * IPC routines shared by some or all of the SYSV IPC system calls.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSVIPC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSHM
end_ifdef

begin_define
define|#
directive|define
name|SYSVIPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSEM
end_ifdef

begin_define
define|#
directive|define
name|SYSVIPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVMSG
end_ifdef

begin_define
define|#
directive|define
name|SYSVIPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVIPC
end_ifdef

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"ipc.h"
end_include

begin_include
include|#
directive|include
file|"shm.h"
end_include

begin_comment
comment|/*  * Perform access checking.  */
end_comment

begin_function
name|int
name|ipcaccess
parameter_list|(
name|ipc
parameter_list|,
name|mode
parameter_list|,
name|cred
parameter_list|)
specifier|register
name|struct
name|ipc_perm
modifier|*
name|ipc
decl_stmt|;
name|int
name|mode
decl_stmt|;
specifier|register
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
block|{
specifier|register
name|int
name|m
decl_stmt|;
if|if
condition|(
name|cred
operator|->
name|cr_uid
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * Access check is based on only one of owner, group, public. 	 * If not owner, then check group. 	 * If not a member of the group, then check public access. 	 */
name|mode
operator|&=
literal|0700
expr_stmt|;
name|m
operator|=
name|ipc
operator|->
name|mode
expr_stmt|;
if|if
condition|(
name|cred
operator|->
name|cr_uid
operator|!=
name|ipc
operator|->
name|uid
operator|&&
name|cred
operator|->
name|cr_uid
operator|!=
name|ipc
operator|->
name|cuid
condition|)
block|{
name|m
operator|<<=
literal|3
expr_stmt|;
if|if
condition|(
operator|!
name|groupmember
argument_list|(
name|ipc
operator|->
name|gid
argument_list|,
name|cred
argument_list|)
operator|&&
operator|!
name|groupmember
argument_list|(
name|ipc
operator|->
name|cgid
argument_list|,
name|cred
argument_list|)
condition|)
name|m
operator|<<=
literal|3
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|mode
operator|&
name|m
operator|)
operator|==
name|mode
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|EACCES
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSVSHM */
end_comment

end_unit

