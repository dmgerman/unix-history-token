begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)clock.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * VAX clock registers  */
end_comment

begin_define
define|#
directive|define
name|ICCS_RUN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ICCS_TRANS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ICCS_SS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ICCS_IE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ICCS_INT
value|0x00000080
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
value|((year)%4==0)
end_define

begin_comment
comment|/* good till time becomes negative */
end_comment

begin_comment
comment|/*  * Has the time-of-day clock wrapped around?  */
end_comment

begin_define
define|#
directive|define
name|clkwrap
parameter_list|()
value|(((unsigned)mfpr(TODR) - TODRZERO)/100> SECYR+SECDAY)
end_define

begin_comment
comment|/*  * Software clock is software interrupt level 8,  * implemented as mtpr(SIRR, 0x8) in asm.sed.  */
end_comment

end_unit

