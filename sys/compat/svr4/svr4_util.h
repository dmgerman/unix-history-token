begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_UTIL_H_
end_define

begin_comment
comment|/*#include<compat/common/compat_util.h>*/
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

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_SVR4
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|a
parameter_list|)
value|uprintf a;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|svr4_emul_find
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|enum
name|uio_seg
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
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|,
name|i
parameter_list|)
define|\
value|do {								\ 		int _error;						\ 									\ 		_error = svr4_emul_find(td, upath, UIO_USERSPACE, pathp, i); \ 		if (*(pathp) == NULL)					\ 			return (_error);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CHECKALTEXIST
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|)
value|CHECKALT(td, upath, pathp, 0)
end_define

begin_define
define|#
directive|define
name|CHECKALTCREAT
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|)
value|CHECKALT(td, upath, pathp, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_UTIL_H_ */
end_comment

end_unit

