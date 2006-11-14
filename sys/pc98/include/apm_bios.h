begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 M. Warner Losh. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_INCLUDE_APM_BIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_INCLUDE_APM_BIOS_H_
end_define

begin_comment
comment|/*  * PC98 machines implement APM bios in nearly the same was as i386 machines,  * so include the i386 version and note the changes here.  */
end_comment

begin_include
include|#
directive|include
file|<i386/apm_bios.h>
end_include

begin_comment
comment|/*  * APM BIOS and interrupt are different on pc98  */
end_comment

begin_undef
undef|#
directive|undef
name|APM_BIOS
end_undef

begin_undef
undef|#
directive|undef
name|APM_INT
end_undef

begin_define
define|#
directive|define
name|APM_BIOS
value|0x9a
end_define

begin_define
define|#
directive|define
name|APM_INT
value|0x1f
end_define

begin_comment
comment|/*  * PC98 also has different GETPWSTATUS and DRVVERSION calls.  I believe that  * these only work on newer APM BIOSes, but haven't confirmed that recently  */
end_comment

begin_undef
undef|#
directive|undef
name|APM_GETPWSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|APM_DRVVERSION
end_undef

begin_define
define|#
directive|define
name|APM_GETPWSTATUS
value|0x3a
end_define

begin_define
define|#
directive|define
name|APM_DRVVERSION
value|0x3e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PC98_INCLUDE_APM_BIOS_H_ */
end_comment

end_unit

