begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	clock.h	4.1	%G%	*/
end_comment

begin_comment
comment|/*  * VAX clock registers  */
end_comment

begin_define
define|#
directive|define
name|ICCS_RUN
value|0x1
end_define

begin_define
define|#
directive|define
name|ICCS_TRANS
value|0x10
end_define

begin_define
define|#
directive|define
name|ICCS_SS
value|0x20
end_define

begin_define
define|#
directive|define
name|ICCS_IE
value|0x40
end_define

begin_define
define|#
directive|define
name|ICCS_INT
value|0x80
end_define

begin_define
define|#
directive|define
name|ICCS_ERR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SECDAY
value|((unsigned)(24*60*60))
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
comment|/* per common year */
end_comment

begin_comment
comment|/*  * TODRZERO is the what the TODR should contain when the ``year'' begins.  * The TODR should always contain a number between 0 and SECYR+SECDAY.  */
end_comment

begin_define
define|#
directive|define
name|TODRZERO
value|((unsigned)(1<<28))
end_define

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
value|((year)%4==0&& year != 2000)
end_define

begin_comment
comment|/* good till 2100 */
end_comment

begin_comment
comment|/*  * Start a 60 HZ clock.  */
end_comment

begin_define
define|#
directive|define
name|clkstart
parameter_list|()
value|{\ 	mtpr(NICR, -16667);
comment|/* 16.667 milli-seconds */
value|\ 	mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_TRANS+ICCS_INT+ICCS_ERR);\ }
end_define

begin_define
define|#
directive|define
name|clkreld
parameter_list|()
value|mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_INT+ICCS_ERR)
end_define

begin_define
define|#
directive|define
name|clkwrap
parameter_list|()
value|(((unsigned)mfpr(TODR) - TODRZERO)/100> SECYR+SECDAY)
end_define

end_unit

