begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)syslimits.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSLIMITS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSLIMITS_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LIMITS_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SYS_PARAM_H_
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__CC_SUPPORTS_WARNING
end_ifdef

begin_warning
warning|#
directive|warning
literal|"No user-serviceable parts inside."
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Do not add any new variables here.  (See the comment at the end of  * the file for why.)  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARG_MAX
value|65536
end_define

begin_comment
comment|/* max bytes for an exec function */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARG_MAX
value|262144
end_define

begin_comment
comment|/* max bytes for an exec function */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHILD_MAX
end_ifndef

begin_define
define|#
directive|define
name|CHILD_MAX
value|40
end_define

begin_comment
comment|/* max simultaneous processes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINK_MAX
value|32767
end_define

begin_comment
comment|/* max file link count */
end_comment

begin_define
define|#
directive|define
name|MAX_CANON
value|255
end_define

begin_comment
comment|/* max bytes in term canon input line */
end_comment

begin_define
define|#
directive|define
name|MAX_INPUT
value|255
end_define

begin_comment
comment|/* max bytes in terminal input */
end_comment

begin_define
define|#
directive|define
name|NAME_MAX
value|255
end_define

begin_comment
comment|/* max bytes in a file name */
end_comment

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|16
end_define

begin_comment
comment|/* max supplemental group id's */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPEN_MAX
end_ifndef

begin_define
define|#
directive|define
name|OPEN_MAX
value|64
end_define

begin_comment
comment|/* max open files per process */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PATH_MAX
value|1024
end_define

begin_comment
comment|/* max bytes in pathname */
end_comment

begin_define
define|#
directive|define
name|PIPE_BUF
value|512
end_define

begin_comment
comment|/* max bytes for atomic pipe writes */
end_comment

begin_define
define|#
directive|define
name|IOV_MAX
value|1024
end_define

begin_comment
comment|/* max elements in i/o vector */
end_comment

begin_comment
comment|/*  * We leave the following values undefined to force applications to either  * assume conservative values or call sysconf() to get the current value.  *  * HOST_NAME_MAX  *  * (We should do this for most of the values currently defined here,  * but many programs are not prepared to deal with this yet.)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

