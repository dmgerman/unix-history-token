begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	clock.h	1.3	86/12/06	*/
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

