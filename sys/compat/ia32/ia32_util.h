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
name|ia32_ps_strings
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

begin_define
define|#
directive|define
name|IA32_USRSTACK
value|((1ul<< 32) - PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|IA32_PS_STRINGS
value|(IA32_USRSTACK - sizeof(struct ia32_ps_strings))
end_define

begin_function_decl
specifier|static
name|__inline
name|caddr_t
name|stackgap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
modifier|*
name|stackgap_alloc
parameter_list|(
name|caddr_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|caddr_t
name|stackgap_init
parameter_list|()
block|{
define|#
directive|define
name|szsigcode
value|(*(curproc->p_sysent->sv_szsigcode))
return|return
call|(
name|caddr_t
call|)
argument_list|(
operator|(
operator|(
name|caddr_t
operator|)
name|IA32_PS_STRINGS
operator|)
operator|-
name|szsigcode
operator|-
name|SPARE_USRSPACE
argument_list|)
return|;
undef|#
directive|undef
name|szsigcode
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|stackgap_alloc
parameter_list|(
name|sgp
parameter_list|,
name|sz
parameter_list|)
name|caddr_t
modifier|*
name|sgp
decl_stmt|;
name|size_t
name|sz
decl_stmt|;
block|{
name|void
modifier|*
name|p
decl_stmt|;
name|p
operator|=
operator|(
name|void
operator|*
operator|)
operator|*
name|sgp
expr_stmt|;
operator|*
name|sgp
operator|+=
name|ALIGN
argument_list|(
name|sz
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|ia32_emul_path
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ia32_emul_find
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CHECKALT
parameter_list|(
name|p
parameter_list|,
name|sgp
parameter_list|,
name|path
parameter_list|,
name|i
parameter_list|)
define|\
value|do {								\ 		int _error;						\ 									\ 		_error = ia32_emul_find(p, sgp, ia32_emul_path, path,	\&path, i);			\ 		if (_error == EFAULT)					\ 			return (_error);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CHECKALTEXIST
parameter_list|(
name|p
parameter_list|,
name|sgp
parameter_list|,
name|path
parameter_list|)
value|CHECKALT((p), (sgp), (path), 0)
end_define

begin_define
define|#
directive|define
name|CHECKALTCREAT
parameter_list|(
name|p
parameter_list|,
name|sgp
parameter_list|,
name|path
parameter_list|)
value|CHECKALT((p), (sgp), (path), 1)
end_define

end_unit

