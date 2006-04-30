begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUTYPES_H_
end_define

begin_comment
comment|/*  * Classes of processor.  */
end_comment

begin_define
define|#
directive|define
name|CPUCLASS_X86
value|0
end_define

begin_comment
comment|/* X86 */
end_comment

begin_define
define|#
directive|define
name|CPUCLASS_K8
value|1
end_define

begin_comment
comment|/* K8 AMD64 class */
end_comment

begin_comment
comment|/*  * Kinds of processor.  */
end_comment

begin_define
define|#
directive|define
name|CPU_X86
value|0
end_define

begin_comment
comment|/* Intel */
end_comment

begin_define
define|#
directive|define
name|CPU_CLAWHAMMER
value|1
end_define

begin_comment
comment|/* AMD Clawhammer */
end_comment

begin_define
define|#
directive|define
name|CPU_SLEDGEHAMMER
value|2
end_define

begin_comment
comment|/* AMD Sledgehammer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cpu_class
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPUTYPES_H_ */
end_comment

end_unit

