begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_SDT_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_SDT_H_
end_define

begin_empty
empty|#include_next<sys/sdt.h>
end_empty

begin_undef
undef|#
directive|undef
name|DTRACE_PROBE
end_undef

begin_undef
undef|#
directive|undef
name|DTRACE_PROBE1
end_undef

begin_undef
undef|#
directive|undef
name|DTRACE_PROBE2
end_undef

begin_undef
undef|#
directive|undef
name|DTRACE_PROBE3
end_undef

begin_undef
undef|#
directive|undef
name|DTRACE_PROBE4
end_undef

begin_define
define|#
directive|define
name|DTRACE_PROBE
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DTRACE_PROBE1
parameter_list|(
name|name
parameter_list|,
name|type1
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DTRACE_PROBE2
parameter_list|(
name|name
parameter_list|,
name|type1
parameter_list|,
name|arg1
parameter_list|,
name|type2
parameter_list|,
name|arg2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DTRACE_PROBE3
parameter_list|(
name|name
parameter_list|,
name|type1
parameter_list|,
name|arg1
parameter_list|,
name|type2
parameter_list|,
name|arg2
parameter_list|,
name|type3
parameter_list|,
name|arg3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DTRACE_PROBE4
parameter_list|(
name|name
parameter_list|,
name|type1
parameter_list|,
name|arg1
parameter_list|,
name|type2
parameter_list|,
name|arg2
parameter_list|,
name|type3
parameter_list|,
name|arg3
parameter_list|,
name|type4
parameter_list|,
name|arg4
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_SDT_H_ */
end_comment

end_unit

