begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000  *	John Baldwin<jhb@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This module holds the global variables used by KTR.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KTR_EXTEND
end_ifdef

begin_comment
comment|/*  * This variable is used only by gdb to work out what fields are in  * ktr_entry.  */
end_comment

begin_decl_stmt
name|int
name|ktr_extend
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_debug
argument_list|,
name|OID_AUTO
argument_list|,
name|ktr_extend
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|ktr_extend
argument_list|,
literal|1
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|ktr_extend
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_debug
argument_list|,
name|OID_AUTO
argument_list|,
name|ktr_extend
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|ktr_extend
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ktr_cpumask
init|=
name|KTR_CPUMASK
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_debug
argument_list|,
name|OID_AUTO
argument_list|,
name|ktr_cpumask
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ktr_cpumask
argument_list|,
name|KTR_CPUMASK
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|ktr_mask
init|=
name|KTR_MASK
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_debug
argument_list|,
name|OID_AUTO
argument_list|,
name|ktr_mask
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ktr_mask
argument_list|,
name|KTR_MASK
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|ktr_entries
init|=
name|KTR_ENTRIES
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_debug
argument_list|,
name|OID_AUTO
argument_list|,
name|ktr_entries
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|ktr_entries
argument_list|,
name|KTR_ENTRIES
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|volatile
name|int
name|ktr_idx
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ktr_entry
name|ktr_buf
index|[
name|KTR_ENTRIES
index|]
decl_stmt|;
end_decl_stmt

end_unit

