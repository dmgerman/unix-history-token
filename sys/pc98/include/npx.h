begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 TAKAHASHI Yoshihiro. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_INCLUDE_NPX_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_INCLUDE_NPX_H_
end_define

begin_include
include|#
directive|include
file|<i386/npx.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_undef
undef|#
directive|undef
name|IO_NPX
end_undef

begin_define
define|#
directive|define
name|IO_NPX
value|0x0F8
end_define

begin_comment
comment|/* Numeric Coprocessor */
end_comment

begin_undef
undef|#
directive|undef
name|IO_NPXSIZE
end_undef

begin_define
define|#
directive|define
name|IO_NPXSIZE
value|8
end_define

begin_comment
comment|/* 80387/80487 NPX registers */
end_comment

begin_undef
undef|#
directive|undef
name|IRQ_NPX
end_undef

begin_define
define|#
directive|define
name|IRQ_NPX
value|8
end_define

begin_comment
comment|/* full reset of npx: not needed on pc98 */
end_comment

begin_undef
undef|#
directive|undef
name|npx_full_reset
end_undef

begin_define
define|#
directive|define
name|npx_full_reset
parameter_list|()
end_define

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
comment|/* _PC98_INCLUDE_NPX_H_ */
end_comment

end_unit

