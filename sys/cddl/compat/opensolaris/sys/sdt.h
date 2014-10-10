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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<opt_kdtrace.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<sys/sdt.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
end_ifdef

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|set__error
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SET_ERROR
parameter_list|(
name|err
parameter_list|)
define|\
value|((sdt_sdt___set__error->id ? \ 	(*sdt_probe_func)(sdt_sdt___set__error->id, \ 	    (uintptr_t)err, 0, 0, 0, 0) : 0), err)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_ERROR
parameter_list|(
name|err
parameter_list|)
value|(err)
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
comment|/* _OPENSOLARIS_SYS_SDT_H_ */
end_comment

end_unit

