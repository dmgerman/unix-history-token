begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-1999 Andrew Gallatin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct
struct|struct
name|freebsd32_ps_strings
block|{
name|u_int32_t
name|ps_argvstr
decl_stmt|;
comment|/* first of 0 or more argument strings */
name|int
name|ps_nargvstr
decl_stmt|;
comment|/* the number of argument strings */
name|u_int32_t
name|ps_envstr
decl_stmt|;
comment|/* first of 0 or more environment strings */
name|int
name|ps_nenvstr
decl_stmt|;
comment|/* the number of environment strings */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<compat/ia32/ia32_util.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FREEBSD32_PS_STRINGS
define|\
value|(FREEBSD32_USRSTACK - sizeof(struct freebsd32_ps_strings))
end_define

end_unit

