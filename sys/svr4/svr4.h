begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_svr4.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_SVR4_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_SVR4_H
end_define

begin_decl_stmt
specifier|extern
name|struct
name|sysentvec
name|svr4_sysvec
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|bzero(x,z)
end_define

begin_define
define|#
directive|define
name|COMPAT_SVR4_SOLARIS2
end_define

begin_define
define|#
directive|define
name|KTRACE
end_define

begin_comment
comment|/* These are currently unimplemented (see svr4_ipc.c) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSVMSG
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SYSVMSG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSVSHM
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SYSVSHM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSVSEM
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SYSVSEM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

