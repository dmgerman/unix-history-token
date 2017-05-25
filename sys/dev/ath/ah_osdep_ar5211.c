begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2017 Adrian Chadd<adrian@FreeBSD.org>.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_include
include|#
directive|include
file|"opt_wlan.h"
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah_internal.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|ath_hal_chip
name|AR5211_chip
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|ath_hal_ar5211_modevent
parameter_list|(
name|module_t
name|mod
name|__unused
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
name|__unused
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|MOD_LOAD
case|:
name|ath_hal_add_chip
argument_list|(
operator|&
name|AR5211_chip
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"[ar5211] loaded\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|ath_hal_remove_chip
argument_list|(
operator|&
name|AR5211_chip
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"[ar5211] unloaded\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_SHUTDOWN
case|:
break|break;
default|default:
name|error
operator|=
name|EOPNOTSUPP
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DEV_MODULE
argument_list|(
name|ath_hal_ar5211
argument_list|,
name|ath_hal_ar5211_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ath_hal_ar5211
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ath_hal_ar5211
argument_list|,
name|ath_hal
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

