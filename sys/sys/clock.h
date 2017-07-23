begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Gordon W. Ross  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: clock_subr.h,v 1.7 2000/10/03 13:41:07 tsutsui Exp $  *  *  * This file is the central clearing-house for calendrical issues.  *  * In general the kernel does not know about minutes, hours, days, timezones,  * daylight savings time, leap-years and such.  All that is theoretically a  * matter for userland only.  *  * Parts of kernel code does however care: badly designed filesystems store  * timestamps in local time and RTC chips sometimes track time in a local  * timezone instead of UTC and so on.  *  * All that code should go here for service.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CLOCK_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* No user serviceable parts */
end_comment

begin_comment
comment|/*  * Timezone info from settimeofday(2), usually not used  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tz_minuteswest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tz_dsttime
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|utc_offset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Structure to hold the values typically reported by time-of-day clocks.  * This can be passed to the generic conversion functions to be converted  * to a struct timespec.  */
end_comment

begin_struct
struct|struct
name|clocktime
block|{
name|int
name|year
decl_stmt|;
comment|/* year (4 digit year) */
name|int
name|mon
decl_stmt|;
comment|/* month (1 - 12) */
name|int
name|day
decl_stmt|;
comment|/* day (1 - 31) */
name|int
name|hour
decl_stmt|;
comment|/* hour (0 - 23) */
name|int
name|min
decl_stmt|;
comment|/* minute (0 - 59) */
name|int
name|sec
decl_stmt|;
comment|/* second (0 - 59) */
name|int
name|dow
decl_stmt|;
comment|/* day of week (0 - 6; 0 = Sunday) */
name|long
name|nsec
decl_stmt|;
comment|/* nano seconds */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|clock_ct_to_ts
parameter_list|(
name|struct
name|clocktime
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clock_ts_to_ct
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|clocktime
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Time-of-day clock register/unregister functions, and associated flags.  These  * functions can sleep.  Upon return from unregister, the clock's methods are  * not running and will not be called again.  *  * Flags:  *  *  CLOCKF_SETTIME_NO_TS  *    Do not pass a timespec to clock_settime(), the driver obtains its own time  *    and applies its own adjustments (this flag implies CLOCKF_SETTIME_NO_ADJ).  *  *  CLOCKF_SETTIME_NO_ADJ  *    Do not apply utc offset and resolution/accuracy adjustments to the value  *    passed to clock_settime(), the driver applies them itself.  *  *  CLOCKF_GETTIME_NO_ADJ  *    Do not apply utc offset and resolution/accuracy adjustments to the value  *    returned from clock_gettime(), the driver has already applied them.  */
end_comment

begin_define
define|#
directive|define
name|CLOCKF_SETTIME_NO_TS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CLOCKF_SETTIME_NO_ADJ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CLOCKF_GETTIME_NO_ADJ
value|0x00000004
end_define

begin_function_decl
name|void
name|clock_register
parameter_list|(
name|device_t
name|_clockdev
parameter_list|,
name|long
name|_resolution_us
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clock_register_flags
parameter_list|(
name|device_t
name|_clockdev
parameter_list|,
name|long
name|_resolution_us
parameter_list|,
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clock_unregister
parameter_list|(
name|device_t
name|_clockdev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * BCD to decimal and decimal to BCD.  */
end_comment

begin_define
define|#
directive|define
name|FROMBCD
parameter_list|(
name|x
parameter_list|)
value|bcd2bin(x)
end_define

begin_define
define|#
directive|define
name|TOBCD
parameter_list|(
name|x
parameter_list|)
value|bin2bcd(x)
end_define

begin_comment
comment|/* Some handy constants. */
end_comment

begin_define
define|#
directive|define
name|SECDAY
value|(24 * 60 * 60)
end_define

begin_define
define|#
directive|define
name|SECYR
value|(SECDAY * 365)
end_define

begin_comment
comment|/* Traditional POSIX base year */
end_comment

begin_define
define|#
directive|define
name|POSIX_BASE_YEAR
value|1970
end_define

begin_function_decl
name|void
name|timespec2fattime
parameter_list|(
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|,
name|int
name|utc
parameter_list|,
name|u_int16_t
modifier|*
name|ddp
parameter_list|,
name|u_int16_t
modifier|*
name|dtp
parameter_list|,
name|u_int8_t
modifier|*
name|dhp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fattime2timespec
parameter_list|(
name|unsigned
name|dd
parameter_list|,
name|unsigned
name|dt
parameter_list|,
name|unsigned
name|dh
parameter_list|,
name|int
name|utc
parameter_list|,
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CLOCK_H_ */
end_comment

end_unit

