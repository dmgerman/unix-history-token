begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)clock.h	7.3 (Berkeley) 6/28/90  */
end_comment

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
comment|/*  * Software clock is software interrupt level 8  */
end_comment

begin_define
define|#
directive|define
name|setsoftclock
parameter_list|()
value|mtpr(SIRR, 0x8)
end_define

begin_comment
comment|/*  * To calculate value for interval timer register, we  * use the fact that 20512 yields a 60hz clock.  */
end_comment

begin_define
define|#
directive|define
name|hztocount
parameter_list|(
name|v
parameter_list|)
value|((20512*60) / (v))
end_define

end_unit

