begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)clock.h	7.2 (Berkeley) 6/29/88  */
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

