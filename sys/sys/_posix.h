begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__POSIX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__POSIX_H_
end_define

begin_comment
comment|/*-  * Copyright (c) 1998 HD Associates, Inc.  * All rights reserved.  * contact: dufault@hda.com  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This is a stand alone header file to set up for feature specification  * defined to take place before the inclusion of any standard header.  * It should only handle pre-processor defines.  *  * See section B.2.7 of 1003.1b-1993   *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_posix.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Only kern_mib.c uses _POSIX_VERSION.  Introduce a kernel  * one to avoid other pieces of the kernel getting dependant  * on that.  * XXX Complain if you think this dumb.  */
end_comment

begin_comment
comment|/* Make P1003 structures visible for the kernel if  * the P1003_1B option is in effect.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|P1003_1B
end_ifdef

begin_define
define|#
directive|define
name|_P1003_1B_VISIBLE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KPOSIX_VERSION
end_ifndef

begin_define
define|#
directive|define
name|_KPOSIX_VERSION
value|199309L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_KPOSIX_VERSION
end_ifndef

begin_define
define|#
directive|define
name|_KPOSIX_VERSION
value|199009L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_P1003_1B_VISIBLE_HISTORICALLY
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Default to existing user space version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VERSION
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_VERSION
value|199009L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test for visibility of P1003.1B features:  * If _POSIX_SOURCE and POSIX_C_SOURCE are completely undefined  * they show up.  *  * If they specify a version including P1003.1B then they show up.  *  * (Two macros are added to permit hiding new extensions while   * keeping historic BSD features - that is not done now)  *  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|_POSIX_VERSION
operator|>=
literal|199309L
operator|&&
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|&&
expr|\
name|_POSIX_C_SOURCE
operator|>=
literal|199309L
operator|)
end_if

begin_define
define|#
directive|define
name|_P1003_1B_VISIBLE
end_define

begin_define
define|#
directive|define
name|_P1003_1B_VISIBLE_HISTORICALLY
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS__POSIX_H_ */
end_comment

end_unit

