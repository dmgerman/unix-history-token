begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)os-xinu43.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  * mt Xinu 4.3 (MORE/bsd) definitions for Amd (automounter)  * Should work on both Vax and HP ...  */
end_comment

begin_comment
comment|/*  * Does the compiler grok void *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|VOIDP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Which version of the Sun RPC library we are using  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|RPC_4
end_define

begin_comment
comment|/*  * mt Xinu have a compatibility problem  * with getreq vs. getreqset.  On SunOS  * getreqset takes a pointer to an fd_set,  * whereas on MORE/bsd, getreq takes a  * fd_set directly (cf. an integer on SunOS).  */
end_comment

begin_define
define|#
directive|define
name|svc_getreqset
parameter_list|(
name|p
parameter_list|)
value|svc_getreq(*p)
end_define

begin_comment
comment|/*  * Which version of the NFS interface are we using.  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|NFS_4
end_define

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|"nfs"
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|"ufs"
end_define

begin_undef
undef|#
directive|undef
name|MTAB_TYPE_UFS
end_undef

begin_define
define|#
directive|define
name|MTAB_TYPE_UFS
value|"ufs"
end_define

begin_comment
comment|/*  * Byte ordering  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_undef
undef|#
directive|undef
name|ARCH_ENDIAN
end_undef

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"little"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|XXX
operator|-
name|Probably
name|no
name|hope
name|of
name|running
name|Amd
name|on
name|this
name|machine
operator|!
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE */
end_comment

begin_comment
comment|/*  * Type of a file handle  */
end_comment

begin_undef
undef|#
directive|undef
name|NFS_FH_TYPE
end_undef

begin_define
define|#
directive|define
name|NFS_FH_TYPE
value|caddr_t
end_define

begin_comment
comment|/*  * Type of filesystem type  */
end_comment

begin_undef
undef|#
directive|undef
name|MTYPE_TYPE
end_undef

begin_define
define|#
directive|define
name|MTYPE_TYPE
value|char *
end_define

end_unit

