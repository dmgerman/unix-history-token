begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/libparse/clk_hopf6021.c,v 4.7 1999/11/28 09:13:49 kardel RELEASE_19991128_A  *  * clk_hopf6021.c,v 4.7 1999/11/28 09:13:49 kardel RELEASE_19991128_A  *  * Radiocode Clocks HOPF Funkuhr 6021 mit serieller Schnittstelle  * base code version from 24th Nov 1995 - history at end  *  * Created by F.Schnekenbuehl<frank@comsys.dofn.de> from clk_rcc8000.c  * Nortel DASA Network Systems GmbH, Department: ND250  * A Joint venture of Daimler-Benz Aerospace and Nortel  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
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
name|CLOCK_HOPF6021
argument_list|)
end_if

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
file|"ascii.h"
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
file|"ntp_stdlib.h"
end_include

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

begin_decl_stmt
specifier|extern
name|void
name|printf
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * hopf Funkuhr 6021   *      used with 9600,8N1,  *      UTC ueber serielle Schnittstelle   *      Sekundenvorlauf ON  *      ETX zum Sekundenvorlauf ON  *      Datenstring 6021  *      Ausgabe Uhrzeit und Datum  *      Senden mit Steuerzeichen  *      Senden sekuendlich  */
end_comment

begin_comment
comment|/*  *  Type 6021 Serial Output format  *  *      000000000011111111 / char  *      012345678901234567 \ position  *      sABHHMMSSDDMMYYnre  Actual  *       C4110046231195     Parse  *      s              enr  Check  *  *  s = STX (0x02), e = ETX (0x03)  *  n = NL  (0x0A), r = CR  (0x0D)  *  *  A B - Status and weekday  *  *  A - Status  *  *      8 4 2 1  *      x x x 0  - no announcement  *      x x x 1  - Summertime - wintertime - summertime announcement  *      x x 0 x  - Wintertime  *      x x 1 x  - Summertime  *      0 0 x x  - Time/Date invalid  *      0 1 x x  - Internal clock used   *      1 0 x x  - Radio clock  *      1 1 x x  - Radio clock highprecision  *  *  B - 8 4 2 1  *      0 x x x  - MESZ/MEZ  *      1 x x x  - UTC  *      x 0 0 1  - Monday  *      x 0 1 0  - Tuesday  *      x 0 1 1  - Wednesday  *      x 1 0 0  - Thursday  *      x 1 0 1  - Friday  *      x 1 1 0  - Saturday  *      x 1 1 1  - Sunday  */
end_comment

begin_define
define|#
directive|define
name|HOPF_DSTWARN
value|0x01
end_define

begin_comment
comment|/* DST switch warning */
end_comment

begin_define
define|#
directive|define
name|HOPF_DST
value|0x02
end_define

begin_comment
comment|/* DST in effect */
end_comment

begin_define
define|#
directive|define
name|HOPF_MODE
value|0x0C
end_define

begin_comment
comment|/* operation mode mask */
end_comment

begin_define
define|#
directive|define
name|HOPF_INVALID
value|0x00
end_define

begin_comment
comment|/* no time code available */
end_comment

begin_define
define|#
directive|define
name|HOPF_INTERNAL
value|0x04
end_define

begin_comment
comment|/* internal clock */
end_comment

begin_define
define|#
directive|define
name|HOPF_RADIO
value|0x08
end_define

begin_comment
comment|/* radio clock */
end_comment

begin_define
define|#
directive|define
name|HOPF_RADIOHP
value|0x0C
end_define

begin_comment
comment|/* high precision radio clock */
end_comment

begin_define
define|#
directive|define
name|HOPF_UTC
value|0x08
end_define

begin_comment
comment|/* time code in UTC */
end_comment

begin_define
define|#
directive|define
name|HOPF_WMASK
value|0x07
end_define

begin_comment
comment|/* mask for weekday code */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|format
name|hopf6021_fmt
init|=
block|{
block|{
block|{
literal|9
block|,
literal|2
block|}
block|,
block|{
literal|11
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
comment|/* Day, Month, Year */
block|{
literal|3
block|,
literal|2
block|}
block|,
block|{
literal|5
block|,
literal|2
block|}
block|,
block|{
literal|7
block|,
literal|2
block|}
block|,
comment|/* Hour, Minute, Second */
block|{
literal|2
block|,
literal|1
block|}
block|,
block|{
literal|1
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* Weekday, Flags, Zone */
comment|/* ... */
block|}
block|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
literal|"\002              \n\r\003"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OFFS
parameter_list|(
name|x
parameter_list|)
value|format->field_offsets[(x)].offset
end_define

begin_define
define|#
directive|define
name|STOI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|Stoi(&buffer[OFFS(x)], y, format->field_offsets[(x)].length)
end_define

begin_define
define|#
directive|define
name|hexval
parameter_list|(
name|x
parameter_list|)
value|(('0'<= (x)&& (x)<= '9') ? (x) - '0' : \ 		   ('a'<= (x)&& (x)<= 'f') ? (x) - 'a' + 10 : \ 		   ('A'<= (x)&& (x)<= 'F') ? (x) - 'A' + 10 : \ 		   -1)
end_define

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|cvt_hopf6021
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|format
operator|*
operator|,
name|clocktime_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|inp_hopf6021
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|unsigned
name|int
operator|,
name|timestamp_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|clockformat_t
name|clock_hopf6021
init|=
block|{
name|inp_hopf6021
block|,
comment|/* HOPF 6021 input handling */
name|cvt_hopf6021
block|,
comment|/* Radiocode clock conversion */
literal|0
block|,
comment|/* no direct PPS monitoring */
operator|(
name|void
operator|*
operator|)
operator|&
name|hopf6021_fmt
block|,
comment|/* conversion configuration */
literal|"hopf Funkuhr 6021"
block|,
comment|/* clock format name */
literal|19
block|,
comment|/* string buffer */
literal|0
comment|/* private data length, no private data */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|long
name|cvt_hopf6021
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
name|char
name|status
decl_stmt|,
name|weekday
decl_stmt|;
if|if
condition|(
operator|!
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
return|return
name|CVT_NONE
return|;
block|}
if|if
condition|(
name|STOI
argument_list|(
name|O_DAY
argument_list|,
operator|&
name|clock_time
operator|->
name|day
argument_list|)
operator|||
name|STOI
argument_list|(
name|O_MONTH
argument_list|,
operator|&
name|clock_time
operator|->
name|month
argument_list|)
operator|||
name|STOI
argument_list|(
name|O_YEAR
argument_list|,
operator|&
name|clock_time
operator|->
name|year
argument_list|)
operator|||
name|STOI
argument_list|(
name|O_HOUR
argument_list|,
operator|&
name|clock_time
operator|->
name|hour
argument_list|)
operator|||
name|STOI
argument_list|(
name|O_MIN
argument_list|,
operator|&
name|clock_time
operator|->
name|minute
argument_list|)
operator|||
name|STOI
argument_list|(
name|O_SEC
argument_list|,
operator|&
name|clock_time
operator|->
name|second
argument_list|)
condition|)
block|{
return|return
name|CVT_FAIL
operator||
name|CVT_BADFMT
return|;
block|}
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
name|status
operator|=
name|hexval
argument_list|(
name|buffer
index|[
name|OFFS
argument_list|(
name|O_FLAGS
argument_list|)
index|]
argument_list|)
expr_stmt|;
name|weekday
operator|=
name|hexval
argument_list|(
name|buffer
index|[
name|OFFS
argument_list|(
name|O_WDAY
argument_list|)
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|status
operator|==
literal|0xFF
operator|)
operator|||
operator|(
name|weekday
operator|==
literal|0xFF
operator|)
condition|)
block|{
return|return
name|CVT_FAIL
operator||
name|CVT_BADFMT
return|;
block|}
name|clock_time
operator|->
name|flags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|weekday
operator|&
name|HOPF_UTC
condition|)
block|{
name|clock_time
operator|->
name|flags
operator||=
name|PARSEB_UTC
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|status
operator|&
name|HOPF_DST
condition|)
block|{
name|clock_time
operator|->
name|flags
operator||=
name|PARSEB_DST
expr_stmt|;
name|clock_time
operator|->
name|utcoffset
operator|=
operator|-
literal|2
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
comment|/* MET DST */
block|}
else|else
block|{
name|clock_time
operator|->
name|utcoffset
operator|=
operator|-
literal|1
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
comment|/* MET */
block|}
block|}
name|clock_time
operator|->
name|flags
operator||=
operator|(
name|status
operator|&
name|HOPF_DSTWARN
operator|)
condition|?
name|PARSEB_ANNOUNCE
else|:
literal|0
expr_stmt|;
switch|switch
condition|(
name|status
operator|&
name|HOPF_MODE
condition|)
block|{
case|case
name|HOPF_INVALID
case|:
comment|/* Time/Date invalid */
name|clock_time
operator|->
name|flags
operator||=
name|PARSEB_POWERUP
expr_stmt|;
break|break;
case|case
name|HOPF_INTERNAL
case|:
comment|/* internal clock */
name|clock_time
operator|->
name|flags
operator||=
name|PARSEB_NOSYNC
expr_stmt|;
break|break;
case|case
name|HOPF_RADIO
case|:
comment|/* Radio clock */
case|case
name|HOPF_RADIOHP
case|:
comment|/* Radio clock high precision */
break|break;
default|default:
return|return
name|CVT_FAIL
operator||
name|CVT_BADFMT
return|;
block|}
return|return
name|CVT_OK
return|;
block|}
end_function

begin_comment
comment|/*  * inp_hopf6021  *  * grep data from input stream  */
end_comment

begin_function
specifier|static
name|u_long
name|inp_hopf6021
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
name|int
name|rtc
decl_stmt|;
name|parseprintf
argument_list|(
name|DD_PARSE
argument_list|,
operator|(
literal|"inp_hopf6021(0x%lx, 0x%x, ...)\n"
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
name|ETX
case|:
name|parseprintf
argument_list|(
name|DD_PARSE
argument_list|,
operator|(
literal|"inp_hopf6021: EOL seen\n"
operator|)
argument_list|)
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
comment|/* collect timestamp */
if|if
condition|(
operator|(
name|rtc
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
return|return
name|parse_end
argument_list|(
name|parseio
argument_list|)
return|;
else|else
return|return
name|rtc
return|;
default|default:
return|return
name|parse_addchar
argument_list|(
name|parseio
argument_list|,
name|ch
argument_list|)
return|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (REFCLOCK&& CLOCK_PARSE&& CLOCK_HOPF6021) */
end_comment

begin_decl_stmt
name|int
name|clk_hopf6021_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not (REFCLOCK&& CLOCK_PARSE&& CLOCK_HOPF6021) */
end_comment

begin_comment
comment|/*  * History:  *  * clk_hopf6021.c,v  * Revision 4.7  1999/11/28 09:13:49  kardel  * RECON_4_0_98F  *  * Revision 4.6  1998/11/15 20:27:57  kardel  * Release 4.0.73e13 reconcilation  *  * Revision 4.5  1998/06/14 21:09:35  kardel  * Sun acc cleanup  *  * Revision 4.4  1998/06/13 12:02:38  kardel  * fix SYSV clock name clash  *  * Revision 4.3  1998/06/12 15:22:27  kardel  * fix prototypes  *  * Revision 4.2  1998/06/12 09:13:25  kardel  * conditional compile macros fixed  * printf prototype  *  * Revision 4.1  1998/05/24 09:39:52  kardel  * implementation of the new IO handling model  *  * Revision 4.0  1998/04/10 19:45:29  kardel  * Start 4.0 release version numbering  *  * from V3 3.6 log info deleted 1998/04/11 kardel  */
end_comment

end_unit

