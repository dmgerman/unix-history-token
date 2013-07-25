begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * This file provides support for real time clocks on some boards  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_RTC_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_RTC_H__
end_define

begin_include
include|#
directive|include
file|"cvmx-sysinfo.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-thunder.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-cn3010-evb-hs5.h"
end_include

begin_comment
comment|/**  * Supported RTC options  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CVMX_RTC_READ
init|=
literal|0x1
block|,
comment|/**< Device supports read access */
name|CVMX_RTC_WRITE
init|=
literal|0x2
block|,
comment|/**< Device supports write access */
name|CVMX_RTC_TIME_EPOCH
init|=
literal|0x10
block|,
comment|/**< Time stored as seconds from epoch */
name|CVMX_RTC_TIME_CAL
init|=
literal|0x20
block|,
comment|/**< Time stored as calendar */
block|}
name|cvmx_rtc_options_t
typedef|;
end_typedef

begin_comment
comment|/**  * Return options supported by the RTC device  *  * @return Supported options, or 0 if RTC is not supported  */
end_comment

begin_function
specifier|static
specifier|inline
name|cvmx_rtc_options_t
name|cvmx_rtc_supported
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|supported
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|supported
operator|<
literal|0
condition|)
block|{
switch|switch
condition|(
name|cvmx_sysinfo_get
argument_list|()
operator|->
name|board_type
condition|)
block|{
case|case
name|CVMX_BOARD_TYPE_THUNDER
case|:
name|supported
operator|=
name|CVMX_RTC_READ
operator||
name|CVMX_RTC_WRITE
operator||
name|CVMX_RTC_TIME_EPOCH
expr_stmt|;
break|break;
case|case
name|CVMX_BOARD_TYPE_EBH3000
case|:
case|case
name|CVMX_BOARD_TYPE_CN3010_EVB_HS5
case|:
case|case
name|CVMX_BOARD_TYPE_EBH5200
case|:
name|supported
operator|=
name|CVMX_RTC_READ
operator||
name|CVMX_RTC_WRITE
operator||
name|CVMX_RTC_TIME_CAL
expr_stmt|;
break|break;
default|default:
name|supported
operator|=
literal|0
expr_stmt|;
break|break;
block|}
ifdef|#
directive|ifdef
name|CVMX_RTC_DEBUG
name|cvmx_dprintf
argument_list|(
literal|"Board type: %s, RTC support: 0x%x\n"
argument_list|,
name|cvmx_board_type_to_string
argument_list|(
name|cvmx_sysinfo_get
argument_list|()
operator|->
name|board_type
argument_list|)
argument_list|,
name|supported
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
return|return
operator|(
name|cvmx_rtc_options_t
operator|)
name|supported
return|;
block|}
end_function

begin_comment
comment|/**  * Read time from RTC device.  *  * Time is expressed in seconds from epoch (Jan 1 1970 at 00:00:00 UTC)  *  * @return Time in seconds or 0 if RTC is not supported  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|cvmx_rtc_read
parameter_list|(
name|void
parameter_list|)
block|{
switch|switch
condition|(
name|cvmx_sysinfo_get
argument_list|()
operator|->
name|board_type
condition|)
block|{
case|case
name|CVMX_BOARD_TYPE_THUNDER
case|:
return|return
name|cvmx_rtc_ds1374_read
argument_list|()
return|;
break|break;
default|default:
return|return
name|cvmx_rtc_ds1337_read
argument_list|()
return|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/**  * Write time to the RTC device  *  * @param time    Number of seconds from epoch (Jan 1 1970 at 00:00:00 UTC)  *  * @return Zero on success or device-specific error on failure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|cvmx_rtc_write
parameter_list|(
name|uint32_t
name|time
parameter_list|)
block|{
switch|switch
condition|(
name|cvmx_sysinfo_get
argument_list|()
operator|->
name|board_type
condition|)
block|{
case|case
name|CVMX_BOARD_TYPE_THUNDER
case|:
return|return
name|cvmx_rtc_ds1374_write
argument_list|(
name|time
argument_list|)
return|;
break|break;
default|default:
return|return
name|cvmx_rtc_ds1337_write
argument_list|(
name|time
argument_list|)
return|;
break|break;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_RTC_H__  */
end_comment

end_unit

