begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"vchiq_build_info.h"
end_include

begin_include
include|#
directive|include
file|<linux/broadcom/vc_debug_sym.h>
end_include

begin_expr_stmt
name|VC_DEBUG_DECLARE_STRING_VAR
argument_list|(
name|vchiq_build_hostname
argument_list|,
literal|"dc4-arm-01"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VC_DEBUG_DECLARE_STRING_VAR
argument_list|(
name|vchiq_build_version
argument_list|,
literal|"9245b4c35b99b3870e1f7dc598c5692b3c66a6f0 (tainted)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VC_DEBUG_DECLARE_STRING_VAR
argument_list|(
name|vchiq_build_time
argument_list|,
literal|"not available"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VC_DEBUG_DECLARE_STRING_VAR
argument_list|(
name|vchiq_build_date
argument_list|,
literal|"not available"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|const
name|char
modifier|*
name|vchiq_get_build_hostname
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|vchiq_build_hostname
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|vchiq_get_build_version
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|vchiq_build_version
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|vchiq_get_build_date
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|vchiq_build_date
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|vchiq_get_build_time
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|vchiq_build_time
return|;
block|}
end_function

end_unit

