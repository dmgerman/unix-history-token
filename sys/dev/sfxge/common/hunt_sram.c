begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 Solarflare Communications Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright notice,  *    this list of conditions and the following disclaimer in the documentation  *    and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation are  * those of the authors and should not be interpreted as representing official  * policies, either expressed or implied, of the FreeBSD Project.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"efx.h"
end_include

begin_include
include|#
directive|include
file|"efx_impl.h"
end_include

begin_if
if|#
directive|if
name|EFSYS_OPT_HUNTINGTON
end_if

begin_if
if|#
directive|if
name|EFSYS_OPT_DIAG
end_if

begin_function
name|__checkReturn
name|efx_rc_t
name|ef10_sram_test
parameter_list|(
name|__in
name|efx_nic_t
modifier|*
name|enp
parameter_list|,
name|__in
name|efx_sram_pattern_fn_t
name|func
parameter_list|)
block|{
name|efx_rc_t
name|rc
decl_stmt|;
comment|/* FIXME */
name|_NOTE
argument_list|(
argument|ARGUNUSED(enp)
argument_list|)
name|_NOTE
argument_list|(
argument|ARGUNUSED(func)
argument_list|)
if|if
condition|(
name|B_FALSE
condition|)
block|{
name|rc
operator|=
name|ENOTSUP
expr_stmt|;
goto|goto
name|fail1
goto|;
block|}
comment|/* FIXME */
return|return
operator|(
literal|0
operator|)
return|;
name|fail1
label|:
name|EFSYS_PROBE1
argument_list|(
name|fail1
argument_list|,
name|efx_rc_t
argument_list|,
name|rc
argument_list|)
expr_stmt|;
return|return
operator|(
name|rc
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_DIAG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EFSYS_OPT_HUNTINGTON */
end_comment

end_unit

