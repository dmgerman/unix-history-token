begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_TIME_H
end_ifndef

begin_define
define|#
directive|define
name|APR_TIME_H
end_define

begin_comment
comment|/**  * @file apr_time.h  * @brief APR Time Library  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

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
comment|/* __cplusplus */
comment|/**  * @defgroup apr_time Time Routines  * @ingroup APR   * @{  */
comment|/** month names */
name|APR_DECLARE_DATA
specifier|extern
specifier|const
name|char
name|apr_month_snames
index|[
literal|12
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/** day names */
name|APR_DECLARE_DATA
specifier|extern
specifier|const
name|char
name|apr_day_snames
index|[
literal|7
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/** number of microseconds since 00:00:00 January 1, 1970 UTC */
typedef|typedef
name|apr_int64_t
name|apr_time_t
typedef|;
comment|/** mechanism to properly type apr_time_t literals */
define|#
directive|define
name|APR_TIME_C
parameter_list|(
name|val
parameter_list|)
value|APR_INT64_C(val)
comment|/** mechanism to properly print apr_time_t values */
define|#
directive|define
name|APR_TIME_T_FMT
value|APR_INT64_T_FMT
comment|/** intervals for I/O timeouts, in microseconds */
typedef|typedef
name|apr_int64_t
name|apr_interval_time_t
typedef|;
comment|/** short interval for I/O timeouts, in microseconds */
typedef|typedef
name|apr_int32_t
name|apr_short_interval_time_t
typedef|;
comment|/** number of microseconds per second */
define|#
directive|define
name|APR_USEC_PER_SEC
value|APR_TIME_C(1000000)
comment|/** @return apr_time_t as a second */
define|#
directive|define
name|apr_time_sec
parameter_list|(
name|time
parameter_list|)
value|((time) / APR_USEC_PER_SEC)
comment|/** @return apr_time_t as a usec */
define|#
directive|define
name|apr_time_usec
parameter_list|(
name|time
parameter_list|)
value|((time) % APR_USEC_PER_SEC)
comment|/** @return apr_time_t as a msec */
define|#
directive|define
name|apr_time_msec
parameter_list|(
name|time
parameter_list|)
value|(((time) / 1000) % 1000)
comment|/** @return apr_time_t as a msec */
define|#
directive|define
name|apr_time_as_msec
parameter_list|(
name|time
parameter_list|)
value|((time) / 1000)
comment|/** @return milliseconds as an apr_time_t */
define|#
directive|define
name|apr_time_from_msec
parameter_list|(
name|msec
parameter_list|)
value|((apr_time_t)(msec) * 1000)
comment|/** @return seconds as an apr_time_t */
define|#
directive|define
name|apr_time_from_sec
parameter_list|(
name|sec
parameter_list|)
value|((apr_time_t)(sec) * APR_USEC_PER_SEC)
comment|/** @return a second and usec combination as an apr_time_t */
define|#
directive|define
name|apr_time_make
parameter_list|(
name|sec
parameter_list|,
name|usec
parameter_list|)
value|((apr_time_t)(sec) * APR_USEC_PER_SEC \                                 + (apr_time_t)(usec))
comment|/**  * @return the current time  */
name|APR_DECLARE
argument_list|(
argument|apr_time_t
argument_list|)
name|apr_time_now
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/** @see apr_time_exp_t */
typedef|typedef
name|struct
name|apr_time_exp_t
name|apr_time_exp_t
typedef|;
comment|/**  * a structure similar to ANSI struct tm with the following differences:  *  - tm_usec isn't an ANSI field  *  - tm_gmtoff isn't an ANSI field (it's a BSDism)  */
struct|struct
name|apr_time_exp_t
block|{
comment|/** microseconds past tm_sec */
name|apr_int32_t
name|tm_usec
decl_stmt|;
comment|/** (0-61) seconds past tm_min */
name|apr_int32_t
name|tm_sec
decl_stmt|;
comment|/** (0-59) minutes past tm_hour */
name|apr_int32_t
name|tm_min
decl_stmt|;
comment|/** (0-23) hours past midnight */
name|apr_int32_t
name|tm_hour
decl_stmt|;
comment|/** (1-31) day of the month */
name|apr_int32_t
name|tm_mday
decl_stmt|;
comment|/** (0-11) month of the year */
name|apr_int32_t
name|tm_mon
decl_stmt|;
comment|/** year since 1900 */
name|apr_int32_t
name|tm_year
decl_stmt|;
comment|/** (0-6) days since Sunday */
name|apr_int32_t
name|tm_wday
decl_stmt|;
comment|/** (0-365) days since January 1 */
name|apr_int32_t
name|tm_yday
decl_stmt|;
comment|/** daylight saving time */
name|apr_int32_t
name|tm_isdst
decl_stmt|;
comment|/** seconds east of UTC */
name|apr_int32_t
name|tm_gmtoff
decl_stmt|;
block|}
struct|;
comment|/**  * Convert an ansi time_t to an apr_time_t  * @param result the resulting apr_time_t  * @param input the time_t to convert  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_time_ansi_put
argument_list|(
argument|apr_time_t *result
argument_list|,
argument|time_t input
argument_list|)
empty_stmt|;
comment|/**  * Convert a time to its human readable components using an offset  * from GMT.  * @param result the exploded time  * @param input the time to explode  * @param offs the number of seconds offset to apply  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_time_exp_tz
argument_list|(
argument|apr_time_exp_t *result
argument_list|,
argument|apr_time_t input
argument_list|,
argument|apr_int32_t offs
argument_list|)
empty_stmt|;
comment|/**  * Convert a time to its human readable components (GMT).  * @param result the exploded time  * @param input the time to explode  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_time_exp_gmt
argument_list|(
argument|apr_time_exp_t *result
argument_list|,
argument|apr_time_t input
argument_list|)
empty_stmt|;
comment|/**  * Convert a time to its human readable components in the local timezone.  * @param result the exploded time  * @param input the time to explode  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_time_exp_lt
argument_list|(
argument|apr_time_exp_t *result
argument_list|,
argument|apr_time_t input
argument_list|)
empty_stmt|;
comment|/**  * Convert time value from human readable format to a numeric apr_time_t  * (elapsed microseconds since the epoch).  * @param result the resulting imploded time  * @param input the input exploded time  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_time_exp_get
argument_list|(
name|apr_time_t
operator|*
name|result
argument_list|,
name|apr_time_exp_t
operator|*
name|input
argument_list|)
expr_stmt|;
comment|/**  * Convert time value from human readable format to a numeric apr_time_t that  * always represents GMT.  * @param result the resulting imploded time  * @param input the input exploded time  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_time_exp_gmt_get
argument_list|(
name|apr_time_t
operator|*
name|result
argument_list|,
name|apr_time_exp_t
operator|*
name|input
argument_list|)
expr_stmt|;
comment|/**  * Sleep for the specified number of micro-seconds.  * @param t desired amount of time to sleep.  * @warning May sleep for longer than the specified time.   */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_sleep
argument_list|(
argument|apr_interval_time_t t
argument_list|)
empty_stmt|;
comment|/** length of a RFC822 Date */
define|#
directive|define
name|APR_RFC822_DATE_LEN
value|(30)
comment|/**  * apr_rfc822_date formats dates in the RFC822  * format in an efficient manner.  It is a fixed length  * format which requires APR_RFC822_DATA_LEN bytes of storage,  * including the trailing NUL terminator.  * @param date_str String to write to.  * @param t the time to convert   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_rfc822_date
argument_list|(
argument|char *date_str
argument_list|,
argument|apr_time_t t
argument_list|)
empty_stmt|;
comment|/** length of a CTIME date */
define|#
directive|define
name|APR_CTIME_LEN
value|(25)
comment|/**  * apr_ctime formats dates in the ctime() format  * in an efficient manner.  It is a fixed length format  * and requires APR_CTIME_LEN bytes of storage including  * the trailing NUL terminator.  * Unlike ANSI/ISO C ctime(), apr_ctime() does not include  * a \\n at the end of the string.  * @param date_str String to write to.  * @param t the time to convert   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_ctime
argument_list|(
argument|char *date_str
argument_list|,
argument|apr_time_t t
argument_list|)
empty_stmt|;
comment|/**  * Formats the exploded time according to the format specified  * @param s string to write to  * @param retsize The length of the returned string  * @param max The maximum length of the string  * @param format The format for the time string  * @param tm The time to convert  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_strftime
argument_list|(
argument|char *s
argument_list|,
argument|apr_size_t *retsize
argument_list|,
argument|apr_size_t max
argument_list|,
argument|const char *format
argument_list|,
argument|apr_time_exp_t *tm
argument_list|)
empty_stmt|;
comment|/**  * Improve the clock resolution for the lifetime of the given pool.  * Generally this is only desirable on benchmarking and other very  * time-sensitive applications, and has no impact on most platforms.  * @param p The pool to associate the finer clock resolution   */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_time_clock_hires
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/** @} */
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
comment|/* ! APR_TIME_H */
end_comment

end_unit

