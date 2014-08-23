begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008,	Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Copyright (c) 2008 Nokia Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__CPUSET_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__CPUSET_H_
end_define

begin_include
include|#
directive|include
file|<sys/_bitset.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CPU_SETSIZE
value|MAXCPU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPU_MAXSIZE
value|256
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPU_SETSIZE
end_ifndef

begin_define
define|#
directive|define
name|CPU_SETSIZE
value|CPU_MAXSIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_NCPUBITS
value|_BITSET_BITS
end_define

begin_define
define|#
directive|define
name|_NCPUWORDS
value|__bitset_words(CPU_SETSIZE)
end_define

begin_expr_stmt
name|BITSET_DEFINE
argument_list|(
name|_cpuset
argument_list|,
name|CPU_SETSIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|struct
name|_cpuset
name|cpuset_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CPUSET_FSET
value|BITSET_FSET(_NCPUWORDS)
end_define

begin_define
define|#
directive|define
name|CPUSET_T_INITIALIZER
value|BITSET_T_INITIALIZER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__CPUSET_H_ */
end_comment

end_unit

