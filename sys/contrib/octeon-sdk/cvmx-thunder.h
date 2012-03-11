begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_THUNDER_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_THUNDER_H__
end_define

begin_comment
comment|/**  * @file  *  * Interface to the Thunder specific devices  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|CVMX_RTC_DS1374_ADDR
value|(0x68)
comment|/*  * Read time-of-day counter.  * This function is called internally by cvmx-rtc functions.  */
name|uint32_t
name|cvmx_rtc_ds1374_read
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/*  * Write time-of-day counter.  * This function is called internally by cvmx-rtc functions.  */
name|int
name|cvmx_rtc_ds1374_write
parameter_list|(
name|uint32_t
name|time
parameter_list|)
function_decl|;
comment|/**  * LAN bypass modes.  */
typedef|typedef
enum|enum
block|{
name|CVMX_LAN_BYPASS_OFF
init|=
literal|0
block|,
comment|/**< LAN bypass is disabled, port 0 and port 1                                     are always connected to Octeon */
name|CVMX_LAN_BYPASS_GPIO
block|,
comment|/**< LAN bypass controlled by GPIO only */
name|CVMX_LAN_BYPASS_WATCHDOG
block|,
comment|/**< LAN bypass controlled by watchdog (and GPIO) */
name|CVMX_LAN_BYPASS_LAST
comment|/* Keep as last entry */
block|}
name|cvmx_lan_bypass_mode_t
typedef|;
comment|/**  * Set LAN bypass mode.  *  * Supported modes are:  * - CVMX_LAN_BYPASS_OFF  *<br>LAN ports are connected ( port 0<--> Octeon<--> port 1 )  *  * - CVMX_LAN_BYPASS_GPIO  *<br>LAN bypass is controlled by software using cvmx_lan_bypass_force() function.  *     When transitioning to this mode, default is LAN bypass enabled  *     ( port 0<--> port 1, disconnected from Octeon ).  *  * - CVMX_LAN_BYPASS_WATCHDOG  *<br>LAN bypass is inactive as long as the watchdog is kept alive.  *     The default expiration time is 1 second and the function to  *     call periodically to prevent watchdog expiration is  *     cvmx_lan_bypass_keep_alive().  *  * @param mode           LAN bypass mode  *  * @return Error code, or 0 in case of success  */
name|int
name|cvmx_lan_bypass_mode_set
parameter_list|(
name|cvmx_lan_bypass_mode_t
name|mode
parameter_list|)
function_decl|;
comment|/**  * Return status of LAN bypass circuit.  *  * @return 1 if ports are in LAN bypass, or 0 if normally connected  */
name|int
name|cvmx_lan_bypass_is_active
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Refresh watchdog timer.  *  * Call periodically (less than 1 second) to prevent triggering LAN bypass.  * The alternative cvmx_lan_bypass_keep_alive_ms() is provided for cases  * where a variable interval is required.  */
name|void
name|cvmx_lan_bypass_keep_alive
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Refresh watchdog timer, setting a specific expiration interval.  *  * @param interval_ms     Interval, in milliseconds, to next watchdog expiration.  */
name|void
name|cvmx_lan_bypass_keep_alive_ms
parameter_list|(
name|uint32_t
name|interval_ms
parameter_list|)
function_decl|;
comment|/**  * Control LAN bypass via software.  *  * @param force_bypass   Force LAN bypass to active (1) or inactive (0)  *  * @return Error code, or 0 in case of success  */
name|int
name|cvmx_lan_bypass_force
parameter_list|(
name|int
name|force_bypass
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_THUNDER_H__ */
end_comment

end_unit

