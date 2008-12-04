begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/modules/auditfilter_noop/auditfilter_noop.c#6 $  */
end_comment

begin_comment
comment|/*  * Sample audit filter: no-op which sinks audit records in both BSM and  * parsed formats, but does nothing with them.  */
end_comment

begin_include
include|#
directive|include
file|<bsm/libbsm.h>
end_include

begin_include
include|#
directive|include
file|<bsm/libbsm.h>
end_include

begin_include
include|#
directive|include
file|<bsm/audit_filter.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__unused
end_ifndef

begin_define
define|#
directive|define
name|__unused
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|AUDIT_FILTER_ATTACH
parameter_list|(
name|void
modifier|*
name|instance
name|__unused
parameter_list|,
name|int
name|argc
name|__unused
parameter_list|,
name|char
modifier|*
name|argv
index|[]
name|__unused
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|AUDIT_FILTER_REINIT
parameter_list|(
name|void
modifier|*
name|instance
name|__unused
parameter_list|,
name|int
name|argc
name|__unused
parameter_list|,
name|char
modifier|*
name|argv
index|[]
name|__unused
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|AUDIT_FILTER_RECORD
parameter_list|(
name|void
modifier|*
name|instance
name|__unused
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
name|__unused
parameter_list|,
name|int
name|token_count
name|__unused
parameter_list|,
specifier|const
name|tokenstr_t
modifier|*
name|tok
index|[]
name|__unused
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|AUDIT_FILTER_RAWRECORD
parameter_list|(
name|void
modifier|*
name|instance
name|__unused
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
name|__unused
parameter_list|,
name|u_char
modifier|*
name|data
name|__unused
parameter_list|,
name|u_int
name|len
name|__unused
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|AUDIT_FILTER_DETACH
parameter_list|(
name|void
modifier|*
name|instance
name|__unused
parameter_list|)
block|{  }
end_function

end_unit

