begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1982, 1990, 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: clockreg.h 1.14 91/01/18$  * from: hp300/hp300/clockreg.h	7.4 (Berkeley) 12/27/92  *  *	@(#)clockreg.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *  LUNA system clock defines  */
end_comment

begin_define
define|#
directive|define
name|CLOCK_REG
value|0x63000000
end_define

begin_comment
comment|/* system clock address */
end_comment

begin_define
define|#
directive|define
name|CLK_INT
value|0x7
end_define

begin_comment
comment|/* system clock intr flag */
end_comment

begin_define
define|#
directive|define
name|CLK_CLR
value|0x1
end_define

begin_comment
comment|/* system clock intr clear */
end_comment

begin_comment
comment|/*  * LUNA battery-backed clock  */
end_comment

begin_comment
comment|/* only use software */
end_comment

begin_struct
struct|struct
name|bbc_tm
block|{
name|int
name|tm_sec
decl_stmt|;
name|int
name|tm_min
decl_stmt|;
name|int
name|tm_hour
decl_stmt|;
name|int
name|tm_mday
decl_stmt|;
name|int
name|tm_mon
decl_stmt|;
name|int
name|tm_year
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FEBRUARY
value|2
end_define

begin_define
define|#
directive|define
name|STARTOFTIME
value|1970
end_define

begin_define
define|#
directive|define
name|SECDAY
value|86400L
end_define

begin_define
define|#
directive|define
name|SECYR
value|(SECDAY * 365)
end_define

begin_define
define|#
directive|define
name|leapyear
parameter_list|(
name|year
parameter_list|)
value|((year) % 4 == 0)
end_define

begin_define
define|#
directive|define
name|range_test
parameter_list|(
name|n
parameter_list|,
name|l
parameter_list|,
name|h
parameter_list|)
value|if ((n)< (l) || (n)> (h)) return(0)
end_define

begin_define
define|#
directive|define
name|days_in_year
parameter_list|(
name|a
parameter_list|)
value|(leapyear(a) ? 366 : 365)
end_define

begin_define
define|#
directive|define
name|days_in_month
parameter_list|(
name|a
parameter_list|)
value|(month_days[(a) - 1])
end_define

begin_comment
comment|/*  * TIME KEEPER RAM -- (MK48T02/12(B)-12/15/20/25)  */
end_comment

begin_include
include|#
directive|include
file|<luna68k/dev/nvram.h>
end_include

begin_struct
struct|struct
name|bbc
block|{
name|struct
name|nvram
name|nvram
decl_stmt|;
comment|/* non-volatile RAM area */
name|unsigned
name|char
name|cal_ctl
decl_stmt|;
comment|/* calender control resistor */
name|unsigned
name|char
name|cal_sec
decl_stmt|;
comment|/* secons resistor */
name|unsigned
name|char
name|cal_min
decl_stmt|;
comment|/* minutes resistor */
name|unsigned
name|char
name|cal_hour
decl_stmt|;
comment|/* hours resitor */
name|unsigned
name|char
name|cal_dow
decl_stmt|;
comment|/* day of the weeks */
name|unsigned
name|char
name|cal_day
decl_stmt|;
comment|/* days resistor */
name|unsigned
name|char
name|cal_mon
decl_stmt|;
comment|/* months resistor */
name|unsigned
name|char
name|cal_year
decl_stmt|;
comment|/* years resistor */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BBC_ADDR
value|0x45000000
end_define

begin_comment
comment|/* battery backuped clock address */
end_comment

begin_define
define|#
directive|define
name|BBC_FRQ
value|0x40
end_define

begin_comment
comment|/* Frequency test (in day) */
end_comment

begin_define
define|#
directive|define
name|BBC_KICK
value|0x80
end_define

begin_comment
comment|/* Kick start (in hour) */
end_comment

begin_define
define|#
directive|define
name|BBC_STOP
value|0x80
end_define

begin_comment
comment|/* Stop bit (in seconds) */
end_comment

begin_define
define|#
directive|define
name|BBC_WRT
value|0x80
end_define

begin_comment
comment|/* Write bit (in control) */
end_comment

begin_define
define|#
directive|define
name|BBC_RD
value|0x40
end_define

begin_comment
comment|/* Read bit (in control) */
end_comment

begin_define
define|#
directive|define
name|BBC_SGN
value|0x20
end_define

begin_comment
comment|/* Sign bit (in control) */
end_comment

begin_define
define|#
directive|define
name|BBC_DELAY
value|180
end_define

begin_comment
comment|/* delay time */
end_comment

begin_define
define|#
directive|define
name|binary_to_bcd
parameter_list|(
name|i
parameter_list|)
value|(((i) / 10)<< 4 | ((i) % 10))
end_define

begin_define
define|#
directive|define
name|bcd_to_binary
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 4) *10 + ((i)& 0x0F))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LUNA2
end_ifdef

begin_struct
struct|struct
name|bbc2
block|{
name|unsigned
name|char
name|cal_sec
decl_stmt|;
comment|/* secons resistor */
name|unsigned
name|char
name|cal_sec_alarm
decl_stmt|;
comment|/* secons alarm resistor */
name|unsigned
name|char
name|cal_min
decl_stmt|;
comment|/* minutes resistor */
name|unsigned
name|char
name|cal_min_alarm
decl_stmt|;
comment|/* minutes alarm resistor */
name|unsigned
name|char
name|cal_hour
decl_stmt|;
comment|/* hours resitor */
name|unsigned
name|char
name|cal_hour_alarm
decl_stmt|;
comment|/* hours alarm resitor */
name|unsigned
name|char
name|cal_dow
decl_stmt|;
comment|/* day of the weeks */
name|unsigned
name|char
name|cal_day
decl_stmt|;
comment|/* days resistor */
name|unsigned
name|char
name|cal_mon
decl_stmt|;
comment|/* months resistor */
name|unsigned
name|char
name|cal_year
decl_stmt|;
comment|/* years resistor */
name|unsigned
name|char
name|cal_ctl_a
decl_stmt|;
comment|/* calender control resistor */
name|unsigned
name|char
name|cal_ctl_b
decl_stmt|;
comment|/* calender control resistor */
name|unsigned
name|char
name|cal_ctl_c
decl_stmt|;
comment|/* calender control resistor */
name|unsigned
name|char
name|cal_ctl_d
decl_stmt|;
comment|/* calender control resistor */
name|unsigned
name|char
name|nvram
index|[
literal|50
index|]
decl_stmt|;
comment|/* non-volatile RAM area */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

