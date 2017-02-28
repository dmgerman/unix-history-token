begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2011-2012 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_MD_H
end_ifndef

begin_define
define|#
directive|define
name|CK_MD_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CK_MD_CACHELINE
end_ifndef

begin_define
define|#
directive|define
name|CK_MD_CACHELINE
value|(64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_MD_PAGESIZE
end_ifndef

begin_define
define|#
directive|define
name|CK_MD_PAGESIZE
value|(4096)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_MD_RTM_DISABLE
end_ifndef

begin_define
define|#
directive|define
name|CK_MD_RTM_DISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_MD_RTM_DISABLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_MD_POINTER_PACK_DISABLE
end_ifndef

begin_define
define|#
directive|define
name|CK_MD_POINTER_PACK_DISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_MD_POINTER_PACK_DISABLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_MD_VMA_BITS_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|CK_MD_VMA_BITS_UNKNOWN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_MD_VMA_BITS_UNKNOWN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_DISABLE_DOUBLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_DISABLE_DOUBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_MD_RMO
end_ifndef

begin_define
define|#
directive|define
name|CK_MD_RMO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_MD_RMO */
end_comment

begin_define
define|#
directive|define
name|CK_VERSION
value|"0.6.0"
end_define

begin_define
define|#
directive|define
name|CK_GIT_SHA
value|""
end_define

begin_comment
comment|/*  * CK expects those, which are normally defined by the build system.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__x86__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__x86__
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sparcv9__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__sparcv9__
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ppc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__ppc64__
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ppc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__ppc__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_MD_H */
end_comment

end_unit

