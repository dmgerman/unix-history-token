begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Konstantin Belousov<kib@FreeBSD.org>  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AMD64_INCLUDE_EFI_H_
end_ifndef

begin_define
define|#
directive|define
name|__AMD64_INCLUDE_EFI_H_
end_define

begin_comment
comment|/*  * XXX: from gcc 6.2 manual:  * Note, the ms_abi attribute for Microsoft Windows 64-bit targets  * currently requires the -maccumulate-outgoing-args option.  *  * Avoid EFIABI_ATTR declarations for compilers that don't support it.  * GCC support began in version 4.4.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
expr|\
operator|(
name|__GNUC__
operator|>
literal|4
operator|||
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|EFIABI_ATTR
value|__attribute__((ms_abi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<isa/rtc.h>
end_include

begin_define
define|#
directive|define
name|EFI_TIME_LOCK
parameter_list|()
value|mtx_lock(&atrtc_time_lock);
end_define

begin_define
define|#
directive|define
name|EFI_TIME_UNLOCK
parameter_list|()
value|mtx_unlock(&atrtc_time_lock);
end_define

begin_define
define|#
directive|define
name|EFI_TIME_OWNED
parameter_list|()
value|mtx_assert(&atrtc_time_lock, MA_OWNED);
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
comment|/* __AMD64_INCLUDE_EFI_H_ */
end_comment

end_unit

