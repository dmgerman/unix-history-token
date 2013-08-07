begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"abts.h"
end_include

begin_include
include|#
directive|include
file|"testutil.h"
end_include

begin_include
include|#
directive|include
file|"apr_date.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_TIME_H
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAVE_TIME_H */
end_comment

begin_struct
specifier|static
struct|struct
name|datetest
block|{
specifier|const
name|char
modifier|*
name|input
decl_stmt|;
specifier|const
name|char
modifier|*
name|output
decl_stmt|;
block|}
name|tests
index|[]
init|=
block|{
block|{
literal|"Mon, 27 Feb 1995 20:49:44 -0800"
block|,
literal|"Tue, 28 Feb 1995 04:49:44 GMT"
block|}
block|,
block|{
literal|"Fri,  1 Jul 2005 11:34:25 -0400"
block|,
literal|"Fri, 01 Jul 2005 15:34:25 GMT"
block|}
block|,
block|{
literal|"Monday, 27-Feb-95 20:49:44 -0800"
block|,
literal|"Tue, 28 Feb 1995 04:49:44 GMT"
block|}
block|,
block|{
literal|"Tue, 4 Mar 1997 12:43:52 +0200"
block|,
literal|"Tue, 04 Mar 1997 10:43:52 GMT"
block|}
block|,
block|{
literal|"Mon, 27 Feb 95 20:49:44 -0800"
block|,
literal|"Tue, 28 Feb 1995 04:49:44 GMT"
block|}
block|,
block|{
literal|"Tue,  4 Mar 97 12:43:52 +0200"
block|,
literal|"Tue, 04 Mar 1997 10:43:52 GMT"
block|}
block|,
block|{
literal|"Tue, 4 Mar 97 12:43:52 +0200"
block|,
literal|"Tue, 04 Mar 1997 10:43:52 GMT"
block|}
block|,
block|{
literal|"Mon, 27 Feb 95 20:49 GMT"
block|,
literal|"Mon, 27 Feb 1995 20:49:00 GMT"
block|}
block|,
block|{
literal|"Tue, 4 Mar 97 12:43 GMT"
block|,
literal|"Tue, 04 Mar 1997 12:43:00 GMT"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|apr_time_t
name|year2secs
index|[]
init|=
block|{
name|APR_INT64_C
argument_list|(
literal|0
argument_list|)
block|,
comment|/* 1970 */
name|APR_INT64_C
argument_list|(
literal|31536000
argument_list|)
block|,
comment|/* 1971 */
name|APR_INT64_C
argument_list|(
literal|63072000
argument_list|)
block|,
comment|/* 1972 */
name|APR_INT64_C
argument_list|(
literal|94694400
argument_list|)
block|,
comment|/* 1973 */
name|APR_INT64_C
argument_list|(
literal|126230400
argument_list|)
block|,
comment|/* 1974 */
name|APR_INT64_C
argument_list|(
literal|157766400
argument_list|)
block|,
comment|/* 1975 */
name|APR_INT64_C
argument_list|(
literal|189302400
argument_list|)
block|,
comment|/* 1976 */
name|APR_INT64_C
argument_list|(
literal|220924800
argument_list|)
block|,
comment|/* 1977 */
name|APR_INT64_C
argument_list|(
literal|252460800
argument_list|)
block|,
comment|/* 1978 */
name|APR_INT64_C
argument_list|(
literal|283996800
argument_list|)
block|,
comment|/* 1979 */
name|APR_INT64_C
argument_list|(
literal|315532800
argument_list|)
block|,
comment|/* 1980 */
name|APR_INT64_C
argument_list|(
literal|347155200
argument_list|)
block|,
comment|/* 1981 */
name|APR_INT64_C
argument_list|(
literal|378691200
argument_list|)
block|,
comment|/* 1982 */
name|APR_INT64_C
argument_list|(
literal|410227200
argument_list|)
block|,
comment|/* 1983 */
name|APR_INT64_C
argument_list|(
literal|441763200
argument_list|)
block|,
comment|/* 1984 */
name|APR_INT64_C
argument_list|(
literal|473385600
argument_list|)
block|,
comment|/* 1985 */
name|APR_INT64_C
argument_list|(
literal|504921600
argument_list|)
block|,
comment|/* 1986 */
name|APR_INT64_C
argument_list|(
literal|536457600
argument_list|)
block|,
comment|/* 1987 */
name|APR_INT64_C
argument_list|(
literal|567993600
argument_list|)
block|,
comment|/* 1988 */
name|APR_INT64_C
argument_list|(
literal|599616000
argument_list|)
block|,
comment|/* 1989 */
name|APR_INT64_C
argument_list|(
literal|631152000
argument_list|)
block|,
comment|/* 1990 */
name|APR_INT64_C
argument_list|(
literal|662688000
argument_list|)
block|,
comment|/* 1991 */
name|APR_INT64_C
argument_list|(
literal|694224000
argument_list|)
block|,
comment|/* 1992 */
name|APR_INT64_C
argument_list|(
literal|725846400
argument_list|)
block|,
comment|/* 1993 */
name|APR_INT64_C
argument_list|(
literal|757382400
argument_list|)
block|,
comment|/* 1994 */
name|APR_INT64_C
argument_list|(
literal|788918400
argument_list|)
block|,
comment|/* 1995 */
name|APR_INT64_C
argument_list|(
literal|820454400
argument_list|)
block|,
comment|/* 1996 */
name|APR_INT64_C
argument_list|(
literal|852076800
argument_list|)
block|,
comment|/* 1997 */
name|APR_INT64_C
argument_list|(
literal|883612800
argument_list|)
block|,
comment|/* 1998 */
name|APR_INT64_C
argument_list|(
literal|915148800
argument_list|)
block|,
comment|/* 1999 */
name|APR_INT64_C
argument_list|(
literal|946684800
argument_list|)
block|,
comment|/* 2000 */
name|APR_INT64_C
argument_list|(
literal|978307200
argument_list|)
block|,
comment|/* 2001 */
name|APR_INT64_C
argument_list|(
literal|1009843200
argument_list|)
block|,
comment|/* 2002 */
name|APR_INT64_C
argument_list|(
literal|1041379200
argument_list|)
block|,
comment|/* 2003 */
name|APR_INT64_C
argument_list|(
literal|1072915200
argument_list|)
block|,
comment|/* 2004 */
name|APR_INT64_C
argument_list|(
literal|1104537600
argument_list|)
block|,
comment|/* 2005 */
name|APR_INT64_C
argument_list|(
literal|1136073600
argument_list|)
block|,
comment|/* 2006 */
name|APR_INT64_C
argument_list|(
literal|1167609600
argument_list|)
block|,
comment|/* 2007 */
name|APR_INT64_C
argument_list|(
literal|1199145600
argument_list|)
block|,
comment|/* 2008 */
name|APR_INT64_C
argument_list|(
literal|1230768000
argument_list|)
block|,
comment|/* 2009 */
name|APR_INT64_C
argument_list|(
literal|1262304000
argument_list|)
block|,
comment|/* 2010 */
name|APR_INT64_C
argument_list|(
literal|1293840000
argument_list|)
block|,
comment|/* 2011 */
name|APR_INT64_C
argument_list|(
literal|1325376000
argument_list|)
block|,
comment|/* 2012 */
name|APR_INT64_C
argument_list|(
literal|1356998400
argument_list|)
block|,
comment|/* 2013 */
name|APR_INT64_C
argument_list|(
literal|1388534400
argument_list|)
block|,
comment|/* 2014 */
name|APR_INT64_C
argument_list|(
literal|1420070400
argument_list|)
block|,
comment|/* 2015 */
name|APR_INT64_C
argument_list|(
literal|1451606400
argument_list|)
block|,
comment|/* 2016 */
name|APR_INT64_C
argument_list|(
literal|1483228800
argument_list|)
block|,
comment|/* 2017 */
name|APR_INT64_C
argument_list|(
literal|1514764800
argument_list|)
block|,
comment|/* 2018 */
name|APR_INT64_C
argument_list|(
literal|1546300800
argument_list|)
block|,
comment|/* 2019 */
name|APR_INT64_C
argument_list|(
literal|1577836800
argument_list|)
block|,
comment|/* 2020 */
name|APR_INT64_C
argument_list|(
literal|1609459200
argument_list|)
block|,
comment|/* 2021 */
name|APR_INT64_C
argument_list|(
literal|1640995200
argument_list|)
block|,
comment|/* 2022 */
name|APR_INT64_C
argument_list|(
literal|1672531200
argument_list|)
block|,
comment|/* 2023 */
name|APR_INT64_C
argument_list|(
literal|1704067200
argument_list|)
block|,
comment|/* 2024 */
name|APR_INT64_C
argument_list|(
literal|1735689600
argument_list|)
block|,
comment|/* 2025 */
name|APR_INT64_C
argument_list|(
literal|1767225600
argument_list|)
block|,
comment|/* 2026 */
name|APR_INT64_C
argument_list|(
literal|1798761600
argument_list|)
block|,
comment|/* 2027 */
name|APR_INT64_C
argument_list|(
literal|1830297600
argument_list|)
block|,
comment|/* 2028 */
name|APR_INT64_C
argument_list|(
literal|1861920000
argument_list|)
block|,
comment|/* 2029 */
name|APR_INT64_C
argument_list|(
literal|1893456000
argument_list|)
block|,
comment|/* 2030 */
name|APR_INT64_C
argument_list|(
literal|1924992000
argument_list|)
block|,
comment|/* 2031 */
name|APR_INT64_C
argument_list|(
literal|1956528000
argument_list|)
block|,
comment|/* 2032 */
name|APR_INT64_C
argument_list|(
literal|1988150400
argument_list|)
block|,
comment|/* 2033 */
name|APR_INT64_C
argument_list|(
literal|2019686400
argument_list|)
block|,
comment|/* 2034 */
name|APR_INT64_C
argument_list|(
literal|2051222400
argument_list|)
block|,
comment|/* 2035 */
name|APR_INT64_C
argument_list|(
literal|2082758400
argument_list|)
block|,
comment|/* 2036 */
name|APR_INT64_C
argument_list|(
literal|2114380800
argument_list|)
block|,
comment|/* 2037 */
name|APR_INT64_C
argument_list|(
literal|2145916800
argument_list|)
comment|/* 2038 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|month_snames
index|[
literal|12
index|]
index|[
literal|4
index|]
init|=
block|{
literal|"Jan"
block|,
literal|"Feb"
block|,
literal|"Mar"
block|,
literal|"Apr"
block|,
literal|"May"
block|,
literal|"Jun"
block|,
literal|"Jul"
block|,
literal|"Aug"
block|,
literal|"Sep"
block|,
literal|"Oct"
block|,
literal|"Nov"
block|,
literal|"Dec"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX: non-portable */
end_comment

begin_function
specifier|static
name|void
name|gm_timestr_822
parameter_list|(
name|char
modifier|*
name|ts
parameter_list|,
name|apr_time_t
name|sec
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|days
index|[
literal|7
index|]
init|=
block|{
literal|"Sun"
block|,
literal|"Mon"
block|,
literal|"Tue"
block|,
literal|"Wed"
block|,
literal|"Thu"
block|,
literal|"Fri"
block|,
literal|"Sat"
block|}
decl_stmt|;
name|struct
name|tm
modifier|*
name|tms
decl_stmt|;
name|time_t
name|ls
init|=
operator|(
name|time_t
operator|)
name|sec
decl_stmt|;
name|tms
operator|=
name|gmtime
argument_list|(
operator|&
name|ls
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|ts
argument_list|,
literal|"%s, %.2d %s %d %.2d:%.2d:%.2d GMT"
argument_list|,
name|days
index|[
name|tms
operator|->
name|tm_wday
index|]
argument_list|,
name|tms
operator|->
name|tm_mday
argument_list|,
name|month_snames
index|[
name|tms
operator|->
name|tm_mon
index|]
argument_list|,
name|tms
operator|->
name|tm_year
operator|+
literal|1900
argument_list|,
name|tms
operator|->
name|tm_hour
argument_list|,
name|tms
operator|->
name|tm_min
argument_list|,
name|tms
operator|->
name|tm_sec
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Linear congruential generator */
end_comment

begin_function
specifier|static
name|apr_uint32_t
name|lgc
parameter_list|(
name|apr_uint32_t
name|a
parameter_list|)
block|{
name|apr_uint64_t
name|z
init|=
name|a
decl_stmt|;
name|z
operator|*=
literal|279470273
expr_stmt|;
name|z
operator|%=
name|APR_UINT64_C
argument_list|(
literal|4294967291
argument_list|)
expr_stmt|;
return|return
operator|(
name|apr_uint32_t
operator|)
name|z
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|test_date_parse_http
parameter_list|(
name|abts_case
modifier|*
name|tc
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|int
name|year
decl_stmt|,
name|i
decl_stmt|;
name|apr_time_t
name|guess
decl_stmt|;
name|apr_time_t
name|offset
init|=
literal|0
decl_stmt|;
name|apr_time_t
name|secstodate
decl_stmt|,
name|newsecs
decl_stmt|;
name|char
name|datestr
index|[
literal|50
index|]
decl_stmt|;
for|for
control|(
name|year
operator|=
literal|1970
init|;
name|year
operator|<
literal|2038
condition|;
operator|++
name|year
control|)
block|{
name|secstodate
operator|=
name|year2secs
index|[
name|year
operator|-
literal|1970
index|]
operator|+
name|offset
expr_stmt|;
name|gm_timestr_822
argument_list|(
name|datestr
argument_list|,
name|secstodate
argument_list|)
expr_stmt|;
name|secstodate
operator|*=
name|APR_USEC_PER_SEC
expr_stmt|;
name|newsecs
operator|=
name|apr_date_parse_http
argument_list|(
name|datestr
argument_list|)
expr_stmt|;
name|ABTS_TRUE
argument_list|(
name|tc
argument_list|,
name|secstodate
operator|==
name|newsecs
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|APR_HAS_RANDOM
name|apr_generate_random_bytes
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|guess
argument_list|,
sizeof|sizeof
argument_list|(
name|guess
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|guess
operator|=
name|apr_time_now
argument_list|()
operator|%
name|APR_TIME_C
argument_list|(
literal|4294967291
argument_list|)
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
operator|++
name|i
control|)
block|{
name|guess
operator|=
operator|(
name|time_t
operator|)
name|lgc
argument_list|(
operator|(
name|apr_uint32_t
operator|)
name|guess
argument_list|)
expr_stmt|;
if|if
condition|(
name|guess
operator|<
literal|0
condition|)
name|guess
operator|*=
operator|-
literal|1
expr_stmt|;
name|secstodate
operator|=
name|guess
operator|+
name|offset
expr_stmt|;
name|gm_timestr_822
argument_list|(
name|datestr
argument_list|,
name|secstodate
argument_list|)
expr_stmt|;
name|secstodate
operator|*=
name|APR_USEC_PER_SEC
expr_stmt|;
name|newsecs
operator|=
name|apr_date_parse_http
argument_list|(
name|datestr
argument_list|)
expr_stmt|;
name|ABTS_TRUE
argument_list|(
name|tc
argument_list|,
name|secstodate
operator|==
name|newsecs
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|test_date_rfc
parameter_list|(
name|abts_case
modifier|*
name|tc
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|apr_time_t
name|date
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|tests
index|[
name|i
index|]
operator|.
name|input
condition|)
block|{
name|char
name|str_date
index|[
name|APR_RFC822_DATE_LEN
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|date
operator|=
name|apr_date_parse_rfc
argument_list|(
name|tests
index|[
name|i
index|]
operator|.
name|input
argument_list|)
expr_stmt|;
name|apr_rfc822_date
argument_list|(
name|str_date
argument_list|,
name|date
argument_list|)
expr_stmt|;
name|ABTS_STR_EQUAL
argument_list|(
name|tc
argument_list|,
name|str_date
argument_list|,
name|tests
index|[
name|i
index|]
operator|.
name|output
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_function
name|abts_suite
modifier|*
name|testdate
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
block|{
name|suite
operator|=
name|ADD_SUITE
argument_list|(
name|suite
argument_list|)
expr_stmt|;
name|abts_run_test
argument_list|(
name|suite
argument_list|,
name|test_date_parse_http
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|abts_run_test
argument_list|(
name|suite
argument_list|,
name|test_date_rfc
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
name|suite
return|;
block|}
end_function

end_unit

