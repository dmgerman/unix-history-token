begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: clockreg.h 1.14 91/01/18$  *  *	@(#)clockreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This file contains definitions for the MC 146818 real-time clock.  *  * For a detailed explanation of the chip, see the "PMAX Desktop  * Workstation Functional Specification, Revision 1.1" pages 62-66.  */
end_comment

begin_define
define|#
directive|define
name|SECMIN
value|((unsigned)60)
end_define

begin_comment
comment|/* seconds per minute */
end_comment

begin_define
define|#
directive|define
name|SECHOUR
value|((unsigned)(60*SECMIN))
end_define

begin_comment
comment|/* seconds per hour */
end_comment

begin_define
define|#
directive|define
name|SECDAY
value|((unsigned)(24*SECHOUR))
end_define

begin_comment
comment|/* seconds per day */
end_comment

begin_define
define|#
directive|define
name|SECYR
value|((unsigned)(365*SECDAY))
end_define

begin_comment
comment|/* seconds per common year */
end_comment

begin_define
define|#
directive|define
name|YRREF
value|1970
end_define

begin_define
define|#
directive|define
name|LEAPYEAR
parameter_list|(
name|year
parameter_list|)
value|(((year) % 4) == 0)
end_define

begin_comment
comment|/*  * Definitions for MC146818 real time clock  */
end_comment

begin_struct
struct|struct
name|chiptime
block|{
name|u_char
name|sec
decl_stmt|;
comment|/* current seconds */
name|char
name|dummy0
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|alarm_sec
decl_stmt|;
comment|/* alarm seconds */
name|char
name|dummy1
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|min
decl_stmt|;
comment|/* current minutes */
name|char
name|dummy2
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|alarm_min
decl_stmt|;
comment|/* alarm minutes */
name|char
name|dummy3
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|hour
decl_stmt|;
comment|/* current hours */
name|char
name|dummy4
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|alarm_hour
decl_stmt|;
comment|/* alarm hours */
name|char
name|dummy5
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|dayw
decl_stmt|;
comment|/* day of the week */
name|char
name|dummy6
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|day
decl_stmt|;
comment|/* day of the month */
name|char
name|dummy7
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|mon
decl_stmt|;
comment|/* month */
name|char
name|dummy8
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|year
decl_stmt|;
comment|/* year */
name|char
name|dummy9
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|rega
decl_stmt|;
comment|/* register a */
name|char
name|dummy10
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|regb
decl_stmt|;
comment|/* register b */
name|char
name|dummy11
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|regc
decl_stmt|;
comment|/* register c */
name|char
name|dummy12
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|regd
decl_stmt|;
comment|/* register d */
name|char
name|dummy13
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|nvram
index|[
literal|50
operator|*
literal|4
index|]
decl_stmt|;
comment|/* battery backed-up ram */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control register A fields.  */
end_comment

begin_define
define|#
directive|define
name|REGA_UIP
value|0x80
end_define

begin_define
define|#
directive|define
name|REGA_TIME_DIV
value|0x70
end_define

begin_define
define|#
directive|define
name|REGA_RATE_SELECT
value|0x0F
end_define

begin_comment
comment|/*  * Time base to use in the REGA_TIME_DIV field.  */
end_comment

begin_define
define|#
directive|define
name|REGA_TIME_BASE
value|0x20
end_define

begin_comment
comment|/*  * Set the interval at 15.625 ms.  */
end_comment

begin_define
define|#
directive|define
name|SELECTED_RATE
value|0xA
end_define

begin_comment
comment|/*  * Control register B fields.  */
end_comment

begin_define
define|#
directive|define
name|REGB_SET_TIME
value|0x80
end_define

begin_define
define|#
directive|define
name|REGB_PER_INT_ENA
value|0x40
end_define

begin_define
define|#
directive|define
name|REGB_UPDATE_INT_ENA
value|0x10
end_define

begin_define
define|#
directive|define
name|REGB_DATA_MODE
value|0x04
end_define

begin_define
define|#
directive|define
name|REGB_HOURS_FORMAT
value|0x02
end_define

begin_comment
comment|/*  * Control register C fields.  */
end_comment

begin_define
define|#
directive|define
name|REGC_INT_PENDING
value|0x80
end_define

begin_define
define|#
directive|define
name|REGC_PER_INT_PENDING
value|0x40
end_define

begin_define
define|#
directive|define
name|REGC_UPDATE_INT_PENDING
value|0x10
end_define

begin_comment
comment|/*  * Control register D fields.  */
end_comment

begin_define
define|#
directive|define
name|REGD_VALID_TIME
value|0x80
end_define

begin_comment
comment|/*  * The RTC registers can only be accessed one byte at a time.  * This routine is used to write words into the non-volatile storage.  */
end_comment

begin_define
define|#
directive|define
name|BYTECOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|num
parameter_list|)
value|{ \ 	int i; \ 	for (i = 0; i< (num); i++) \ 		((char *) (b))[i] = ((char *) (a))[i]; \ }
end_define

end_unit

