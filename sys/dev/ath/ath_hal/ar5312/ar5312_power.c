begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_AR5312
end_ifdef

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
file|"ar5312/ar5312.h"
end_include

begin_include
include|#
directive|include
file|"ar5312/ar5312reg.h"
end_include

begin_include
include|#
directive|include
file|"ar5212/ar5212desc.h"
end_include

begin_comment
comment|/*  * Notify Power Mgt is enabled in self-generated frames.  * If requested, force chip awake.  *  * Returns A_OK if chip is awake or successfully forced awake.  *  * WARNING WARNING WARNING  * There is a problem with the chip where sometimes it will not wake up.  */
end_comment

begin_function
specifier|static
name|HAL_BOOL
name|ar5312SetPowerModeAwake
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|setChip
parameter_list|)
block|{
comment|/* No need for this at the moment for APs */
return|return
name|AH_TRUE
return|;
block|}
end_function

begin_comment
comment|/*  * Notify Power Mgt is disabled in self-generated frames.  * If requested, force chip to sleep.  */
end_comment

begin_function
specifier|static
name|void
name|ar5312SetPowerModeSleep
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|setChip
parameter_list|)
block|{
comment|/* No need for this at the moment for APs */
block|}
end_function

begin_comment
comment|/*  * Notify Power Management is enabled in self-generating  * fames.  If request, set power mode of chip to  * auto/normal.  Duration in units of 128us (1/8 TU).  */
end_comment

begin_function
specifier|static
name|void
name|ar5312SetPowerModeNetworkSleep
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|setChip
parameter_list|)
block|{
comment|/* No need for this at the moment for APs */
block|}
end_function

begin_comment
comment|/*  * Set power mgt to the requested mode, and conditionally set  * the chip as well  */
end_comment

begin_function
name|HAL_BOOL
name|ar5312SetPowerMode
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_POWER_MODE
name|mode
parameter_list|,
name|int
name|setChip
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|AH_DEBUG
specifier|static
specifier|const
name|char
modifier|*
name|modes
index|[]
init|=
block|{
literal|"AWAKE"
block|,
literal|"FULL-SLEEP"
block|,
literal|"NETWORK SLEEP"
block|,
literal|"UNDEFINED"
block|}
decl_stmt|;
endif|#
directive|endif
name|int
name|status
init|=
name|AH_TRUE
decl_stmt|;
name|HALDEBUG
argument_list|(
name|ah
argument_list|,
name|HAL_DEBUG_POWER
argument_list|,
literal|"%s: %s -> %s (%s)\n"
argument_list|,
name|__func__
argument_list|,
name|modes
index|[
name|ah
operator|->
name|ah_powerMode
index|]
argument_list|,
name|modes
index|[
name|mode
index|]
argument_list|,
name|setChip
condition|?
literal|"set chip "
else|:
literal|""
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|HAL_PM_AWAKE
case|:
name|status
operator|=
name|ar5312SetPowerModeAwake
argument_list|(
name|ah
argument_list|,
name|setChip
argument_list|)
expr_stmt|;
break|break;
case|case
name|HAL_PM_FULL_SLEEP
case|:
name|ar5312SetPowerModeSleep
argument_list|(
name|ah
argument_list|,
name|setChip
argument_list|)
expr_stmt|;
break|break;
case|case
name|HAL_PM_NETWORK_SLEEP
case|:
name|ar5312SetPowerModeNetworkSleep
argument_list|(
name|ah
argument_list|,
name|setChip
argument_list|)
expr_stmt|;
break|break;
default|default:
name|HALDEBUG
argument_list|(
name|ah
argument_list|,
name|HAL_DEBUG_POWER
argument_list|,
literal|"%s: unknown power mode %u\n"
argument_list|,
name|__func__
argument_list|,
name|mode
argument_list|)
expr_stmt|;
return|return
name|AH_FALSE
return|;
block|}
name|ah
operator|->
name|ah_powerMode
operator|=
name|mode
expr_stmt|;
return|return
name|status
return|;
block|}
end_function

begin_comment
comment|/*  * Return the current sleep mode of the chip  */
end_comment

begin_function
name|uint32_t
name|ar5312GetPowerMode
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
block|{
return|return
name|HAL_PM_AWAKE
return|;
block|}
end_function

begin_comment
comment|/*  * Return the current sleep state of the chip  * TRUE = sleeping  */
end_comment

begin_function
name|HAL_BOOL
name|ar5312GetPowerStatus
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
block|{
return|return
literal|0
return|;
comment|/* Currently, 5312 is never in sleep mode. */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_SUPPORT_AR5312 */
end_comment

end_unit

