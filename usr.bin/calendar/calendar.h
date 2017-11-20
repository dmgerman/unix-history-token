begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_define
define|#
directive|define
name|SECSPERDAY
value|(24 * 60 * 60)
end_define

begin_define
define|#
directive|define
name|SECSPERHOUR
value|(60 * 60)
end_define

begin_define
define|#
directive|define
name|SECSPERMINUTE
value|(60)
end_define

begin_define
define|#
directive|define
name|MINSPERHOUR
value|(60)
end_define

begin_define
define|#
directive|define
name|HOURSPERDAY
value|(24)
end_define

begin_define
define|#
directive|define
name|FSECSPERDAY
value|(24.0 * 60.0 * 60.0)
end_define

begin_define
define|#
directive|define
name|FSECSPERHOUR
value|(60.0 * 60.0)
end_define

begin_define
define|#
directive|define
name|FSECSPERMINUTE
value|(60.0)
end_define

begin_define
define|#
directive|define
name|FMINSPERHOUR
value|(60.0)
end_define

begin_define
define|#
directive|define
name|FHOURSPERDAY
value|(24.0)
end_define

begin_define
define|#
directive|define
name|DAYSPERYEAR
value|365
end_define

begin_define
define|#
directive|define
name|DAYSPERLEAPYEAR
value|366
end_define

begin_comment
comment|/* Not yet categorized */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|t1
decl_stmt|,
name|t2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|calendarFile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yrdays
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fixs
name|neaster
decl_stmt|,
name|npaskha
decl_stmt|,
name|ncny
decl_stmt|,
name|nfullmoon
decl_stmt|,
name|nnewmoon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fixs
name|nmarequinox
decl_stmt|,
name|nsepequinox
decl_stmt|,
name|njunsolstice
decl_stmt|,
name|ndecsolstice
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|UTCOffset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EastLongitude
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isleap
parameter_list|(
name|y
parameter_list|)
value|((((y) % 4) == 0&& ((y) % 100) != 0) || ((y) % 400) == 0)
end_define

begin_comment
comment|/* Flags to determine the returned values by determinestyle() in parsedata.c */
end_comment

begin_define
define|#
directive|define
name|F_NONE
value|0x00000
end_define

begin_define
define|#
directive|define
name|F_MONTH
value|0x00001
end_define

begin_define
define|#
directive|define
name|F_DAYOFWEEK
value|0x00002
end_define

begin_define
define|#
directive|define
name|F_DAYOFMONTH
value|0x00004
end_define

begin_define
define|#
directive|define
name|F_MODIFIERINDEX
value|0x00008
end_define

begin_define
define|#
directive|define
name|F_MODIFIEROFFSET
value|0x00010
end_define

begin_define
define|#
directive|define
name|F_SPECIALDAY
value|0x00020
end_define

begin_define
define|#
directive|define
name|F_ALLMONTH
value|0x00040
end_define

begin_define
define|#
directive|define
name|F_ALLDAY
value|0x00080
end_define

begin_define
define|#
directive|define
name|F_VARIABLE
value|0x00100
end_define

begin_define
define|#
directive|define
name|F_EASTER
value|0x00200
end_define

begin_define
define|#
directive|define
name|F_CNY
value|0x00400
end_define

begin_define
define|#
directive|define
name|F_PASKHA
value|0x00800
end_define

begin_define
define|#
directive|define
name|F_NEWMOON
value|0x01000
end_define

begin_define
define|#
directive|define
name|F_FULLMOON
value|0x02000
end_define

begin_define
define|#
directive|define
name|F_MAREQUINOX
value|0x04000
end_define

begin_define
define|#
directive|define
name|F_SEPEQUINOX
value|0x08000
end_define

begin_define
define|#
directive|define
name|F_JUNSOLSTICE
value|0x10000
end_define

begin_define
define|#
directive|define
name|F_DECSOLSTICE
value|0x20000
end_define

begin_define
define|#
directive|define
name|F_YEAR
value|0x40000
end_define

begin_define
define|#
directive|define
name|STRING_EASTER
value|"Easter"
end_define

begin_define
define|#
directive|define
name|STRING_PASKHA
value|"Paskha"
end_define

begin_define
define|#
directive|define
name|STRING_CNY
value|"ChineseNewYear"
end_define

begin_define
define|#
directive|define
name|STRING_NEWMOON
value|"NewMoon"
end_define

begin_define
define|#
directive|define
name|STRING_FULLMOON
value|"FullMoon"
end_define

begin_define
define|#
directive|define
name|STRING_MAREQUINOX
value|"MarEquinox"
end_define

begin_define
define|#
directive|define
name|STRING_SEPEQUINOX
value|"SepEquinox"
end_define

begin_define
define|#
directive|define
name|STRING_JUNSOLSTICE
value|"JunSolstice"
end_define

begin_define
define|#
directive|define
name|STRING_DECSOLSTICE
value|"DecSolstice"
end_define

begin_define
define|#
directive|define
name|MAXCOUNT
value|125
end_define

begin_comment
comment|/* Random number of maximum number of 					 * repeats of an event. Should be 52 					 * (number of weeks per year), if you 					 * want to show two years then it 					 * should be 104. If you are seeing 					 * more than this you are using this 					 * program wrong. 					 */
end_comment

begin_comment
comment|/*  * All the astronomical calculations are carried out for the meridian 120  * degrees east of Greenwich.  */
end_comment

begin_define
define|#
directive|define
name|UTCOFFSET_CNY
value|8.0
end_define

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show parsing of the input */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|year1
decl_stmt|,
name|year2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* events.c */
end_comment

begin_comment
comment|/*  * Event sorting related functions:  * - Use event_add() to create a new event  * - Use event_continue() to add more text to the last added event  * - Use event_print_all() to display them in time chronological order  */
end_comment

begin_function_decl
name|struct
name|event
modifier|*
name|event_add
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|event_continue
parameter_list|(
name|struct
name|event
modifier|*
name|events
parameter_list|,
name|char
modifier|*
name|txt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|event_print_all
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|event
block|{
name|int
name|year
decl_stmt|;
name|int
name|month
decl_stmt|;
name|int
name|day
decl_stmt|;
name|int
name|var
decl_stmt|;
name|char
modifier|*
name|date
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
name|char
modifier|*
name|extra
decl_stmt|;
name|struct
name|event
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* locale.c */
end_comment

begin_struct
struct|struct
name|fixs
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|days
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|fdays
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|fmonths
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|months
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sequences
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fixs
name|fndays
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* full national days names */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fixs
name|fnmonths
index|[
literal|13
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* full national months names */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fixs
name|ndays
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* short national days names */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fixs
name|nmonths
index|[
literal|13
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* short national month names */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fixs
name|nsequences
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|setnnames
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setnsequences
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* day.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tm
name|tm0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|dayname
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|settimes
parameter_list|(
name|time_t
parameter_list|,
name|int
name|before
parameter_list|,
name|int
name|after
parameter_list|,
name|int
name|friday
parameter_list|,
name|struct
name|tm
modifier|*
name|tp1
parameter_list|,
name|struct
name|tm
modifier|*
name|tp2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|Mktime
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parsedata.c */
end_comment

begin_function_decl
name|int
name|parsedaymonth
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dodebug
parameter_list|(
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* io.c */
end_comment

begin_function_decl
name|void
name|cal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closecal
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|opencalin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|opencalout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ostern.c / paskha.c */
end_comment

begin_function_decl
name|int
name|paskha
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|easter
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|j2g
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dates.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cumdaytab
index|[]
index|[
literal|14
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|monthdaytab
index|[]
index|[
literal|14
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug_remember
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|generatedates
parameter_list|(
name|struct
name|tm
modifier|*
name|tp1
parameter_list|,
name|struct
name|tm
modifier|*
name|tp2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpdates
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|remember_ymd
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|remember_yd
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|d
parameter_list|,
name|int
modifier|*
name|rm
parameter_list|,
name|int
modifier|*
name|rd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|first_dayofweek_of_year
parameter_list|(
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|first_dayofweek_of_month
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|walkthrough_dates
parameter_list|(
name|struct
name|event
modifier|*
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addtodate
parameter_list|(
name|struct
name|event
modifier|*
name|e
parameter_list|,
name|int
name|year
parameter_list|,
name|int
name|month
parameter_list|,
name|int
name|day
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* pom.c */
end_comment

begin_define
define|#
directive|define
name|MAXMOONS
value|18
end_define

begin_function_decl
name|void
name|pom
parameter_list|(
name|int
name|year
parameter_list|,
name|double
name|UTCoffset
parameter_list|,
name|int
modifier|*
name|fms
parameter_list|,
name|int
modifier|*
name|nms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpom
parameter_list|(
name|int
name|year
parameter_list|,
name|double
name|utcoffset
parameter_list|,
name|double
modifier|*
name|ffms
parameter_list|,
name|double
modifier|*
name|fnms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sunpos.c */
end_comment

begin_function_decl
name|void
name|equinoxsolstice
parameter_list|(
name|int
name|year
parameter_list|,
name|double
name|UTCoffset
parameter_list|,
name|int
modifier|*
name|equinoxdays
parameter_list|,
name|int
modifier|*
name|solsticedays
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fequinoxsolstice
parameter_list|(
name|int
name|year
parameter_list|,
name|double
name|UTCoffset
parameter_list|,
name|double
modifier|*
name|equinoxdays
parameter_list|,
name|double
modifier|*
name|solsticedays
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|calculatesunlongitude30
parameter_list|(
name|int
name|year
parameter_list|,
name|int
name|degreeGMToffset
parameter_list|,
name|int
modifier|*
name|ichinesemonths
parameter_list|)
function_decl|;
end_function_decl

end_unit

