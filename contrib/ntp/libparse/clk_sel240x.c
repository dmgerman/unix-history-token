begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Copyright (c) 2009,2012 -
end_comment

begin_comment
comment|//        Schweitzer Engineering Laboratories, Inc.<opensource@selinc.com>
end_comment

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Need to have _XOPEN_SOURCE defined for time.h to give the
end_comment

begin_comment
comment|// correct strptime signature.  As per feature_test_macros(7),
end_comment

begin_comment
comment|// define this before including any header files.
end_comment

begin_comment
comment|// #ifndef _XOPEN_SOURCE
end_comment

begin_comment
comment|// #define _XOPEN_SOURCE
end_comment

begin_comment
comment|// #endif
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REFCLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|CLOCK_PARSE
argument_list|)
operator|&&
name|defined
argument_list|(
name|CLOCK_SEL240X
argument_list|)
end_if

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"parse.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PARSESTREAM
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"sys/parsestreams.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// The B8 output has the following format B8 = '\x01YYYY:ddd:hh:mm:ssq\r\n'
end_comment

begin_comment
comment|//    where q = ' ' locked
end_comment

begin_comment
comment|//              '.'<1 us
end_comment

begin_comment
comment|//              '*'<10 us
end_comment

begin_comment
comment|//              '#'<100 us
end_comment

begin_comment
comment|//              '?'>100 us
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Based on this we need to recored the stime when we receive the<SOH>
end_comment

begin_comment
comment|// character and end it when we see the \n.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The q or quality character indicates satellite lock and sync.   For the
end_comment

begin_comment
comment|// purposes of NTP we are going to call it valid when we receive anything but
end_comment

begin_comment
comment|// a '?'.  But we are only going to call it synced when we receive a ' '
end_comment

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_function_decl
specifier|static
name|unsigned
name|long
name|inp_sel240x
parameter_list|(
name|parse_t
modifier|*
name|parseio
parameter_list|,
name|unsigned
name|int
name|ch
parameter_list|,
name|timestamp_t
modifier|*
name|tstamp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|unsigned
name|long
name|cvt_sel240x
parameter_list|(
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|,
name|struct
name|format
modifier|*
name|format
parameter_list|,
name|clocktime_t
modifier|*
name|clock_time
parameter_list|,
name|void
modifier|*
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Parse clock format structure describing the message above
end_comment

begin_decl_stmt
specifier|static
name|struct
name|format
name|sel240x_fmt
init|=
block|{
block|{
block|{
literal|6
block|,
literal|3
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|4
block|}
block|,
block|{
literal|10
block|,
literal|2
block|}
block|,
block|{
literal|13
block|,
literal|2
block|}
block|,
block|{
literal|16
block|,
literal|2
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
block|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
literal|"\x01    :   :  :  :   \x0d\x0a"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Structure desctibing the parser
end_comment

begin_decl_stmt
name|clockformat_t
name|clock_sel240x
init|=
block|{
name|inp_sel240x
block|,
name|cvt_sel240x
block|,
name|pps_one
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|sel240x_fmt
block|,
literal|"SEL B8"
block|,
literal|25
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_function
specifier|static
name|unsigned
name|long
name|inp_sel240x
parameter_list|(
name|parse_t
modifier|*
name|parseio
parameter_list|,
name|unsigned
name|int
name|ch
parameter_list|,
name|timestamp_t
modifier|*
name|tstamp
parameter_list|)
block|{
name|unsigned
name|long
name|rc
decl_stmt|;
name|parseprintf
argument_list|(
name|DD_PARSE
argument_list|,
operator|(
literal|"inp_sel240x(0x%lx, 0x%x, ...)\n"
operator|,
operator|(
name|long
operator|)
name|parseio
operator|,
name|ch
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'\x01'
case|:
name|parseio
operator|->
name|parse_index
operator|=
literal|1
expr_stmt|;
name|parseio
operator|->
name|parse_data
index|[
literal|0
index|]
operator|=
name|ch
expr_stmt|;
name|parseio
operator|->
name|parse_dtime
operator|.
name|parse_stime
operator|=
operator|*
name|tstamp
expr_stmt|;
name|rc
operator|=
name|PARSE_INP_SKIP
expr_stmt|;
break|break;
case|case
literal|'\n'
case|:
if|if
condition|(
operator|(
name|rc
operator|=
name|parse_addchar
argument_list|(
name|parseio
argument_list|,
name|ch
argument_list|)
operator|)
operator|==
name|PARSE_INP_SKIP
condition|)
block|{
name|rc
operator|=
name|parse_end
argument_list|(
name|parseio
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|rc
operator|=
name|parse_addchar
argument_list|(
name|parseio
argument_list|,
name|ch
argument_list|)
expr_stmt|;
block|}
return|return
name|rc
return|;
block|}
end_function

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_function
specifier|static
name|unsigned
name|long
name|cvt_sel240x
parameter_list|(
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|,
name|struct
name|format
modifier|*
name|format
parameter_list|,
name|clocktime_t
modifier|*
name|clock_time
parameter_list|,
name|void
modifier|*
name|local
parameter_list|)
block|{
name|unsigned
name|long
name|rc
init|=
name|CVT_NONE
decl_stmt|;
if|if
condition|(
name|Strok
argument_list|(
name|buffer
argument_list|,
name|format
operator|->
name|fixed_string
argument_list|)
condition|)
block|{
name|struct
name|tm
name|ptime
decl_stmt|;
name|buffer
operator|++
expr_stmt|;
name|buffer
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|strptime
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|buffer
argument_list|,
literal|"%Y:%j:%H:%M:%S"
argument_list|,
operator|&
name|ptime
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|buffer
operator|+
literal|1
operator|)
operator|!=
literal|'\x0d'
condition|)
block|{
name|rc
operator|=
name|CVT_FAIL
operator||
name|CVT_BADFMT
expr_stmt|;
block|}
else|else
block|{
name|clock_time
operator|->
name|day
operator|=
name|ptime
operator|.
name|tm_mday
expr_stmt|;
name|clock_time
operator|->
name|month
operator|=
name|ptime
operator|.
name|tm_mon
operator|+
literal|1
expr_stmt|;
name|clock_time
operator|->
name|year
operator|=
name|ptime
operator|.
name|tm_year
operator|+
literal|1900
expr_stmt|;
name|clock_time
operator|->
name|hour
operator|=
name|ptime
operator|.
name|tm_hour
expr_stmt|;
name|clock_time
operator|->
name|minute
operator|=
name|ptime
operator|.
name|tm_min
expr_stmt|;
name|clock_time
operator|->
name|second
operator|=
name|ptime
operator|.
name|tm_sec
expr_stmt|;
name|clock_time
operator|->
name|usecond
operator|=
literal|0
expr_stmt|;
name|clock_time
operator|->
name|utcoffset
operator|=
literal|0
expr_stmt|;
name|clock_time
operator|->
name|flags
operator|=
name|PARSEB_UTC
expr_stmt|;
if|if
condition|(
operator|*
name|buffer
operator|==
literal|'?'
condition|)
block|{
name|clock_time
operator|->
name|flags
operator||=
name|PARSEB_POWERUP
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|buffer
operator|!=
literal|' '
condition|)
block|{
name|clock_time
operator|->
name|flags
operator||=
name|PARSEB_NOSYNC
expr_stmt|;
block|}
name|rc
operator|=
name|CVT_OK
expr_stmt|;
block|}
block|}
return|return
name|rc
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (REFCLOCK&& CLOCK_PARSE&& CLOCK_SEL240X) */
end_comment

begin_decl_stmt
name|int
name|clk_sel240x_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not (REFCLOCK&& CLOCK_PARSE&& CLOCK_SEL240X) */
end_comment

end_unit

