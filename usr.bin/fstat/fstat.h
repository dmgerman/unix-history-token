begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSTAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__FSTAT_H__
end_define

begin_comment
comment|/*  * a kvm_read that returns true if everything is read  */
end_comment

begin_define
define|#
directive|define
name|KVM_READ
parameter_list|(
name|kaddr
parameter_list|,
name|paddr
parameter_list|,
name|len
parameter_list|)
define|\
value|(kvm_read(kd, (u_long)(kaddr), (char *)(paddr), (len)) == (len))
end_define

begin_define
define|#
directive|define
name|dprintf
value|if (vflg) fprintf
end_define

begin_typedef
typedef|typedef
struct|struct
name|devs
block|{
name|struct
name|devs
modifier|*
name|next
decl_stmt|;
name|long
name|fsid
decl_stmt|;
name|ino_t
name|ino
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|DEVS
typedef|;
end_typedef

begin_struct
struct|struct
name|filestat
block|{
name|long
name|fsid
decl_stmt|;
name|long
name|fileid
decl_stmt|;
name|mode_t
name|mode
decl_stmt|;
name|u_long
name|size
decl_stmt|;
name|dev_t
name|rdev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Ugh */
end_comment

begin_decl_stmt
specifier|extern
name|kvm_t
modifier|*
name|kd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Pid
decl_stmt|;
end_decl_stmt

begin_function_decl
name|udev_t
name|dev2udev
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Additional filesystem types */
end_comment

begin_function_decl
name|int
name|isofs_filestat
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|filestat
modifier|*
name|fsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msdosfs_filestat
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|filestat
modifier|*
name|fsp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSTAT_H__ */
end_comment

end_unit

