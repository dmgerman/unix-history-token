begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014-2015 Luiz Otavio O Souza<loos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Maxim DS3231 RTC registers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DS3231REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DS3231REG_H_
end_define

begin_define
define|#
directive|define
name|DS3231_SECS
value|0x00
end_define

begin_define
define|#
directive|define
name|DS3231_SECS_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|DS3231_MINS
value|0x01
end_define

begin_define
define|#
directive|define
name|DS3231_MINS_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|DS3231_HOUR
value|0x02
end_define

begin_define
define|#
directive|define
name|DS3231_HOUR_MASK_12HR
value|0x3f
end_define

begin_define
define|#
directive|define
name|DS3231_HOUR_MASK_24HR
value|0x1f
end_define

begin_define
define|#
directive|define
name|DS3231_HOUR_IS_PM
value|0x20
end_define

begin_define
define|#
directive|define
name|DS3231_HOUR_USE_AMPM
value|0x40
end_define

begin_define
define|#
directive|define
name|DS3231_WEEKDAY
value|0x03
end_define

begin_define
define|#
directive|define
name|DS3231_WEEKDAY_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|DS3231_DATE
value|0x04
end_define

begin_define
define|#
directive|define
name|DS3231_DATE_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|DS3231_MONTH
value|0x05
end_define

begin_define
define|#
directive|define
name|DS3231_MONTH_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|DS3231_C_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|DS3231_YEAR
value|0x06
end_define

begin_define
define|#
directive|define
name|DS3231_YEAR_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|DS3231_CONTROL
value|0x0e
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_EOSC
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_BBSQW
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_CONV
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_RS2
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_RS1
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_RS_MASK
value|(DS3231_CTRL_RS2 | DS3231_CTRL_RS1)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_RS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_INTCN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_A2IE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_A1IE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DS3231_CTRL_MASK
define|\
value|(DS3231_CTRL_EOSC | DS3231_CTRL_A1IE | DS3231_CTRL_A2IE)
end_define

begin_define
define|#
directive|define
name|DS3231_STATUS
value|0x0f
end_define

begin_define
define|#
directive|define
name|DS3231_STATUS_OSF
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DS3231_STATUS_EN32KHZ
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DS3231_STATUS_BUSY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DS3231_STATUS_A2F
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DS3231_STATUS_A1F
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DS3231_TEMP
value|0x11
end_define

begin_define
define|#
directive|define
name|DS3231_TEMP_MASK
value|0xffc0
end_define

begin_define
define|#
directive|define
name|DS3231_0500C
value|0x80
end_define

begin_define
define|#
directive|define
name|DS3231_0250C
value|0x40
end_define

begin_define
define|#
directive|define
name|DS3231_MSB
value|0x8000
end_define

begin_define
define|#
directive|define
name|DS3231_NEG_BIT
value|DS3231_MSB
end_define

begin_define
define|#
directive|define
name|TZ_ZEROC
value|2731
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DS3231REG_H_ */
end_comment

end_unit

