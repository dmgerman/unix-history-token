begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEOM_GEOM_CTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEOM_GEOM_CTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Version number.  Used to check consistency between kernel and libgeom.  */
end_comment

begin_define
define|#
directive|define
name|GCTL_VERSION
value|2
end_define

begin_struct
struct|struct
name|gctl_req_arg
block|{
name|u_int
name|nlen
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|off_t
name|offset
decl_stmt|;
name|int
name|flag
decl_stmt|;
name|int
name|len
decl_stmt|;
name|void
modifier|*
name|value
decl_stmt|;
comment|/* kernel only fields */
name|void
modifier|*
name|kvalue
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GCTL_PARAM_RD
value|1
end_define

begin_comment
comment|/* Must match VM_PROT_READ */
end_comment

begin_define
define|#
directive|define
name|GCTL_PARAM_WR
value|2
end_define

begin_comment
comment|/* Must match VM_PROT_WRITE */
end_comment

begin_define
define|#
directive|define
name|GCTL_PARAM_RW
value|(GCTL_PARAM_RD | GCTL_PARAM_WR)
end_define

begin_define
define|#
directive|define
name|GCTL_PARAM_ASCII
value|4
end_define

begin_comment
comment|/* These are used in the kernel only */
end_comment

begin_define
define|#
directive|define
name|GCTL_PARAM_NAMEKERNEL
value|8
end_define

begin_define
define|#
directive|define
name|GCTL_PARAM_VALUEKERNEL
value|16
end_define

begin_define
define|#
directive|define
name|GCTL_PARAM_CHANGED
value|32
end_define

begin_struct
struct|struct
name|gctl_req
block|{
name|u_int
name|version
decl_stmt|;
name|u_int
name|serial
decl_stmt|;
name|u_int
name|narg
decl_stmt|;
name|struct
name|gctl_req_arg
modifier|*
name|arg
decl_stmt|;
name|u_int
name|lerror
decl_stmt|;
name|char
modifier|*
name|error
decl_stmt|;
name|struct
name|gctl_req_table
modifier|*
name|reqt
decl_stmt|;
comment|/* kernel only fields */
name|int
name|nerror
decl_stmt|;
name|struct
name|sbuf
modifier|*
name|serror
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GEOM_CTL
value|_IOW('G', GCTL_VERSION, struct gctl_req)
end_define

begin_define
define|#
directive|define
name|PATH_GEOM_CTL
value|"geom.ctl"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GEOM_GEOM_CTL_H_ */
end_comment

end_unit

