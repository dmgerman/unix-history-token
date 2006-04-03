begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_KDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_KDB_H_
end_define

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_define
define|#
directive|define
name|KDB_STOPPEDPCB
parameter_list|(
name|pc
parameter_list|)
value|&stoppcbs[pc->pc_cpuid]
end_define

begin_function
specifier|static
name|__inline
name|void
name|kdb_cpu_clear_singlestep
parameter_list|(
name|void
parameter_list|)
block|{
name|kdb_frame
operator|->
name|tf_eflags
operator|&=
operator|~
name|PSL_T
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|kdb_cpu_set_singlestep
parameter_list|(
name|void
parameter_list|)
block|{
name|kdb_frame
operator|->
name|tf_eflags
operator||=
name|PSL_T
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|kdb_cpu_trap
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|code
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_KDB_H_ */
end_comment

end_unit

