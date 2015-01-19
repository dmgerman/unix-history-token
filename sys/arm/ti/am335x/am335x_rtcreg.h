begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2015 Luiz Otavio O Souza<loos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AM335X_RTCREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_AM335X_RTCREG_H_
end_define

begin_define
define|#
directive|define
name|RTC_SECONDS
value|0x00
end_define

begin_define
define|#
directive|define
name|RTC_MINUTES
value|0x04
end_define

begin_define
define|#
directive|define
name|RTC_HOURS
value|0x08
end_define

begin_define
define|#
directive|define
name|RTC_DAYS
value|0x0c
end_define

begin_define
define|#
directive|define
name|RTC_MONTHS
value|0x10
end_define

begin_define
define|#
directive|define
name|RTC_YEARS
value|0x14
end_define

begin_define
define|#
directive|define
name|RTC_WEEK
value|0x18
end_define

begin_define
define|#
directive|define
name|RTC_CTRL
value|0x40
end_define

begin_define
define|#
directive|define
name|RTC_CTRL_DISABLE
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|RTC_CTRL_RUN
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|RTC_STATUS
value|0x44
end_define

begin_define
define|#
directive|define
name|RTC_STATUS_ALARM2
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|RTC_STATUS_ALARM
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|RTC_STATUS_1D_EVENT
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|RTC_STATUS_1H_EVENT
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|RTC_STATUS_1M_EVENT
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|RTC_STATUS_1S_EVENT
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|RTC_STATUS_RUN
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|RTC_STATUS_BUSY
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|RTC_INTR
value|0x48
end_define

begin_define
define|#
directive|define
name|RTC_INTR_ALARM2
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|RTC_INTR_ALARM
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|RTC_INTR_TIMER
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|RTC_OSC
value|0x54
end_define

begin_define
define|#
directive|define
name|RTC_OSC_32KCLK_EN
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|RTC_OSC_OSC32K_GZ
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|RTC_OSC_32KCLK_SEL
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|RTC_OSC_RES_SELECT
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|RTC_OSC_SW2
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|RTC_OSC_SW1
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|RTC_KICK0R
value|0x6c
end_define

begin_define
define|#
directive|define
name|RTC_KICK0R_PASS
value|0x83e70b13
end_define

begin_define
define|#
directive|define
name|RTC_KICK1R
value|0x70
end_define

begin_define
define|#
directive|define
name|RTC_KICK1R_PASS
value|0x95a4f1e0
end_define

begin_define
define|#
directive|define
name|RTC_REVISION
value|0x74
end_define

begin_define
define|#
directive|define
name|RTC_ALARM2_SECONDS
value|0x80
end_define

begin_define
define|#
directive|define
name|RTC_ALARM2_MINUTES
value|0x84
end_define

begin_define
define|#
directive|define
name|RTC_ALARM2_HOURS
value|0x88
end_define

begin_define
define|#
directive|define
name|RTC_ALARM2_DAYS
value|0x8c
end_define

begin_define
define|#
directive|define
name|RTC_ALARM2_MONTHS
value|0x90
end_define

begin_define
define|#
directive|define
name|RTC_ALARM2_YEARS
value|0x94
end_define

begin_define
define|#
directive|define
name|RTC_PMIC
value|0x98
end_define

begin_define
define|#
directive|define
name|PMIC_PWR_ENABLE
value|(1U<< 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AM335X_RTCREG_H_ */
end_comment

end_unit

