begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)time.h	8.3 (Berkeley) 1/21/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_H_
end_ifndef

begin_define
define|#
directive|define
name|_TIME_H_
end_define

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_comment
comment|/*  * Frequency of the clock ticks reported by times().  Deprecated - use  * sysconf(_SC_CLK_TCK) instead.  */
end_comment

begin_define
define|#
directive|define
name|CLK_TCK
value|_BSD_CLK_TCK_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Frequency of the clock ticks reported by clock().  */
end_comment

begin_define
define|#
directive|define
name|CLOCKS_PER_SEC
value|_BSD_CLOCKS_PER_SEC_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_CLOCK_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_CLOCK_T_
name|clock_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_CLOCK_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_TIME_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_TIME_T_
name|time_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_TIME_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tm
block|{
name|int
name|tm_sec
decl_stmt|;
comment|/* seconds after the minute [0-60] */
name|int
name|tm_min
decl_stmt|;
comment|/* minutes after the hour [0-59] */
name|int
name|tm_hour
decl_stmt|;
comment|/* hours since midnight [0-23] */
name|int
name|tm_mday
decl_stmt|;
comment|/* day of the month [1-31] */
name|int
name|tm_mon
decl_stmt|;
comment|/* months since January [0-11] */
name|int
name|tm_year
decl_stmt|;
comment|/* years since 1900 */
name|int
name|tm_wday
decl_stmt|;
comment|/* days since Sunday [0-6] */
name|int
name|tm_yday
decl_stmt|;
comment|/* days since January 1 [0-365] */
name|int
name|tm_isdst
decl_stmt|;
comment|/* Daylight Savings Time flag */
name|long
name|tm_gmtoff
decl_stmt|;
comment|/* offset from CUT in seconds */
name|char
modifier|*
name|tm_zone
decl_stmt|;
comment|/* timezone abbreviation */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|char
modifier|*
name|asctime
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|tm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|clock_t
name|clock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ctime
name|__P
argument_list|(
operator|(
specifier|const
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|difftime
name|__P
argument_list|(
operator|(
name|time_t
operator|,
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tm
modifier|*
name|gmtime
name|__P
argument_list|(
operator|(
specifier|const
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tm
modifier|*
name|localtime
name|__P
argument_list|(
operator|(
specifier|const
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|mktime
name|__P
argument_list|(
operator|(
expr|struct
name|tm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|strftime
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|tm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|time
name|__P
argument_list|(
operator|(
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_decl_stmt
name|int
name|asctime_r
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|tm
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ctime_r
name|__P
argument_list|(
operator|(
specifier|const
name|time_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tm
modifier|*
name|gmtime_r
name|__P
argument_list|(
operator|(
specifier|const
name|time_t
operator|*
operator|,
expr|struct
name|tm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tm
modifier|*
name|localtime_r
name|__P
argument_list|(
operator|(
specifier|const
name|time_t
operator|*
operator|,
expr|struct
name|tm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_decl_stmt
name|void
name|tzset
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not ANSI */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_decl_stmt
specifier|const
name|char
modifier|*
name|strptime
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|tm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|timezone
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tzsetwall
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|timelocal
name|__P
argument_list|(
operator|(
expr|struct
name|tm
operator|*
specifier|const
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|timegm
name|__P
argument_list|(
operator|(
expr|struct
name|tm
operator|*
specifier|const
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* neither ANSI nor POSIX */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TIME_H_ */
end_comment

end_unit

