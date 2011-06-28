begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008-2010 Atheros Communications Inc.  * Copyright (c) 2011 Adrian Chadd, Xenion Pty Ltd.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_include
include|#
directive|include
file|"ah.h"
end_include

begin_include
include|#
directive|include
file|"ah_internal.h"
end_include

begin_include
include|#
directive|include
file|"ah_eeprom_v4k.h"
end_include

begin_include
include|#
directive|include
file|"ar9002/ar9285.h"
end_include

begin_include
include|#
directive|include
file|"ar5416/ar5416reg.h"
end_include

begin_include
include|#
directive|include
file|"ar5416/ar5416phy.h"
end_include

begin_include
include|#
directive|include
file|"ar9002/ar9002phy.h"
end_include

begin_comment
comment|//#include "ar9002/ar9287phy.h"
end_comment

begin_include
include|#
directive|include
file|"ar9002/ar9287_cal.h"
end_include

begin_function
name|void
name|ar9287PACal
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_reset
parameter_list|)
block|{
comment|/* XXX not required */
block|}
end_function

begin_comment
comment|/*  * This is like Merlin but without ADC disable  */
end_comment

begin_function
name|HAL_BOOL
name|ar9287InitCalHardware
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
block|{
name|OS_REG_SET_BIT
argument_list|(
name|ah
argument_list|,
name|AR_PHY_AGC_CONTROL
argument_list|,
name|AR_PHY_AGC_CONTROL_FLTR_CAL
argument_list|)
expr_stmt|;
comment|/* Calibrate the AGC */
name|OS_REG_WRITE
argument_list|(
name|ah
argument_list|,
name|AR_PHY_AGC_CONTROL
argument_list|,
name|OS_REG_READ
argument_list|(
name|ah
argument_list|,
name|AR_PHY_AGC_CONTROL
argument_list|)
operator||
name|AR_PHY_AGC_CONTROL_CAL
argument_list|)
expr_stmt|;
comment|/* Poll for offset calibration complete */
if|if
condition|(
operator|!
name|ath_hal_wait
argument_list|(
name|ah
argument_list|,
name|AR_PHY_AGC_CONTROL
argument_list|,
name|AR_PHY_AGC_CONTROL_CAL
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|HALDEBUG
argument_list|(
name|ah
argument_list|,
name|HAL_DEBUG_RESET
argument_list|,
literal|"%s: offset calibration failed to complete in 1ms; "
literal|"noisy environment?\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
name|AH_FALSE
return|;
block|}
name|OS_REG_CLR_BIT
argument_list|(
name|ah
argument_list|,
name|AR_PHY_AGC_CONTROL
argument_list|,
name|AR_PHY_AGC_CONTROL_FLTR_CAL
argument_list|)
expr_stmt|;
return|return
name|AH_TRUE
return|;
block|}
end_function

end_unit

