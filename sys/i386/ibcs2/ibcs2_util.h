begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Christos Zoulas  * Copyright (c) 1995 Frank van der Linden  * Copyright (c) 1995 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * from: svr4_util.h,v 1.5 1994/11/18 02:54:31 christos Exp  * from: linux_util.h,v 1.2 1995/03/05 23:23:50 fvdl Exp  */
end_comment

begin_comment
comment|/*  * This file is pretty much the same as Christos' svr4_util.h  * (for now).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function
specifier|static
name|__inline
name|caddr_t
name|stackgap_init
parameter_list|()
block|{
specifier|extern
name|char
name|sigcode
index|[]
decl_stmt|,
name|esigcode
index|[]
decl_stmt|;
define|#
directive|define
name|szsigcode
value|((caddr_t)(esigcode - sigcode))
return|return
name|STACKGAPBASE
return|;
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
init|=
operator|(
name|void
operator|*
operator|)
operator|*
name|sgp
decl_stmt|;
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

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_IBCS2
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|a
parameter_list|)
value|printf a;
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

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|ibcs2_emul_path
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ibcs2_emul_find
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|caddr_t
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
define|\
value|ibcs2_emul_find(p, sgp, ibcs2_emul_path, path,&(path), 0)
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
define|\
value|ibcs2_emul_find(p, sgp, ibcs2_emul_path, path,&(path), 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IBCS2_UTIL_H_ */
end_comment

end_unit

