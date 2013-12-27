begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCF2123REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCF2123REG_H__
end_define

begin_comment
comment|/* Control and status */
end_comment

begin_define
define|#
directive|define
name|PCF2123_REG_CTRL1
value|0x0
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_CTRL2
value|0x1
end_define

begin_comment
comment|/* Time and date */
end_comment

begin_define
define|#
directive|define
name|PCF2123_REG_SECONDS
value|0x2
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_MINUTES
value|0x3
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_HOURS
value|0x4
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_DAYS
value|0x5
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_WEEKDAYS
value|0x6
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_MONTHS
value|0x7
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_YEARS
value|0x8
end_define

begin_comment
comment|/* Alarm registers */
end_comment

begin_define
define|#
directive|define
name|PCF2123_REG_MINUTE_ALARM
value|0x9
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_HOUR_ALARM
value|0xA
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_DAY_ALARM
value|0xB
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_WEEKDAY_ALARM
value|0xC
end_define

begin_comment
comment|/* Offset */
end_comment

begin_define
define|#
directive|define
name|PCF2123_REG_OFFSET
value|0xD
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|PCF2123_REG_TIMER_CLKOUT
value|0xE
end_define

begin_define
define|#
directive|define
name|PCF2123_REG_COUNTDOWN_TIMER
value|0xF
end_define

begin_comment
comment|/* Commands */
end_comment

begin_define
define|#
directive|define
name|PCF2123_CMD_READ
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PCF2123_CMD_WRITE
value|(0<< 7)
end_define

begin_define
define|#
directive|define
name|PCF2123_READ
parameter_list|(
name|reg
parameter_list|)
value|(PCF2123_CMD_READ | (1<< 4) | (reg))
end_define

begin_define
define|#
directive|define
name|PCF2123_WRITE
parameter_list|(
name|reg
parameter_list|)
value|(PCF2123_CMD_WRITE | (1<< 4) | (reg))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PCF2123REG_H__ */
end_comment

end_unit

