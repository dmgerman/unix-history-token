begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_GLOBALS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_GLOBALS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/globaldata.h>
end_include

begin_expr_stmt
specifier|register
expr|struct
name|globaldata
operator|*
name|globaldata
end_expr_stmt

begin_asm
asm|__asm("%g7");
end_asm

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|name
parameter_list|)
value|(globaldata->gd_ ## name)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|name
parameter_list|)
value|(&globaldata->gd_ ## name)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
value|(globaldata->gd_ ## name = (value))
end_define

begin_define
define|#
directive|define
name|curproc
value|PCPU_GET(curproc)
end_define

begin_define
define|#
directive|define
name|CURPROC
value|PCPU_GET(curproc)
end_define

begin_define
define|#
directive|define
name|CURTHD
value|PCPU_GET(curproc)
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
comment|/* !_MACHINE_GLOBALS_H_ */
end_comment

end_unit

