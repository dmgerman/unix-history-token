begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_RTCREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_RTCREG_H
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|RTC_CR
value|0x00
end_define

begin_comment
comment|/* RTC Control Register */
end_comment

begin_define
define|#
directive|define
name|RTC_MR
value|0x04
end_define

begin_comment
comment|/* RTC Mode Register */
end_comment

begin_define
define|#
directive|define
name|RTC_TIMR
value|0x08
end_define

begin_comment
comment|/* RTC Time Register */
end_comment

begin_define
define|#
directive|define
name|RTC_CALR
value|0x0c
end_define

begin_comment
comment|/* RTC Calendar Register */
end_comment

begin_define
define|#
directive|define
name|RTC_TIMALR
value|0x10
end_define

begin_comment
comment|/* RTC Time Alarm Register */
end_comment

begin_define
define|#
directive|define
name|RTC_CALALR
value|0x14
end_define

begin_comment
comment|/* RTC Calendar Alarm Register */
end_comment

begin_define
define|#
directive|define
name|RTC_SR
value|0x18
end_define

begin_comment
comment|/* RTC Status Register */
end_comment

begin_define
define|#
directive|define
name|RTC_SCCR
value|0x1c
end_define

begin_comment
comment|/* RTC Status Command Clear Register */
end_comment

begin_define
define|#
directive|define
name|RTC_IER
value|0x20
end_define

begin_comment
comment|/* RTC Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|RTC_IDR
value|0x24
end_define

begin_comment
comment|/* RTC Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|RTC_IMR
value|0x28
end_define

begin_comment
comment|/* RTC Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|RTC_VER
value|0x2c
end_define

begin_comment
comment|/* RTC Valid Entry Register */
end_comment

begin_comment
comment|/* TIMR */
end_comment

begin_define
define|#
directive|define
name|RTC_TIMR_SEC_M
value|0x7fUL
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_SEC_S
value|0
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_SEC
parameter_list|(
name|x
parameter_list|)
value|FROMBCD(((x)& RTC_TIMR_SEC_M)>> RTC_TIMR_SEC_S)
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_MIN_M
value|0x7f00UL
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_MIN_S
value|8
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_MIN
parameter_list|(
name|x
parameter_list|)
value|FROMBCD(((x)& RTC_TIMR_MIN_M)>> RTC_TIMR_MIN_S)
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_HR_M
value|0x3f0000UL
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_HR_S
value|16
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_HR
parameter_list|(
name|x
parameter_list|)
value|FROMBCD(((x)& RTC_TIMR_HR_M)>> RTC_TIMR_HR_S)
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_MK
parameter_list|(
name|hr
parameter_list|,
name|min
parameter_list|,
name|sec
parameter_list|)
define|\
value|((TOBCD(hr)<< RTC_TIMR_HR_S) | \ 		 (TOBCD(min)<< RTC_TIMR_MIN_S) | \ 		 (TOBCD(sec)<< RTC_TIMR_SEC_S))
end_define

begin_define
define|#
directive|define
name|RTC_TIMR_PM
value|(1UL<< 22)
end_define

begin_comment
comment|/* CALR */
end_comment

begin_define
define|#
directive|define
name|RTC_CALR_CEN_M
value|0x0000007fUL
end_define

begin_define
define|#
directive|define
name|RTC_CALR_CEN_S
value|0
end_define

begin_define
define|#
directive|define
name|RTC_CALR_CEN
parameter_list|(
name|x
parameter_list|)
value|FROMBCD(((x)& RTC_CALR_CEN_M)>> RTC_CALR_CEN_S)
end_define

begin_define
define|#
directive|define
name|RTC_CALR_YEAR_M
value|0x0000ff00UL
end_define

begin_define
define|#
directive|define
name|RTC_CALR_YEAR_S
value|8
end_define

begin_define
define|#
directive|define
name|RTC_CALR_YEAR
parameter_list|(
name|x
parameter_list|)
value|FROMBCD(((x)& RTC_CALR_YEAR_M)>> RTC_CALR_YEAR_S)
end_define

begin_define
define|#
directive|define
name|RTC_CALR_MON_M
value|0x001f0000UL
end_define

begin_define
define|#
directive|define
name|RTC_CALR_MON_S
value|16
end_define

begin_define
define|#
directive|define
name|RTC_CALR_MON
parameter_list|(
name|x
parameter_list|)
value|FROMBCD(((x)& RTC_CALR_MON_M)>> RTC_CALR_MON_S)
end_define

begin_define
define|#
directive|define
name|RTC_CALR_DOW_M
value|0x00d0000UL
end_define

begin_define
define|#
directive|define
name|RTC_CALR_DOW_S
value|21
end_define

begin_define
define|#
directive|define
name|RTC_CALR_DOW
parameter_list|(
name|x
parameter_list|)
value|FROMBCD(((x)& RTC_CALR_DOW_M)>> RTC_CALR_DOW_S)
end_define

begin_define
define|#
directive|define
name|RTC_CALR_DAY_M
value|0x3f00000UL
end_define

begin_define
define|#
directive|define
name|RTC_CALR_DAY_S
value|24
end_define

begin_define
define|#
directive|define
name|RTC_CALR_DAY
parameter_list|(
name|x
parameter_list|)
value|FROMBCD(((x)& RTC_CALR_DAY_M)>> RTC_CALR_DAY_S)
end_define

begin_define
define|#
directive|define
name|RTC_CALR_MK
parameter_list|(
name|yr
parameter_list|,
name|mon
parameter_list|,
name|day
parameter_list|,
name|dow
parameter_list|)
define|\
value|((TOBCD((yr) / 100 + 19)<< RTC_CALR_CENTURY_S) | \ 		 (TOBCD((yr) % 100)<< RTC_CALR_YEAR_S) | \ 		 (TOBCD(mon)<< RTC_CALR_MON_S) | \ 		 (TOBCD(dow)<< RTC_CALR_DOW_S) | \ 		 (TOBCD(day)<< RTC_CALR_DAY_S))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_RTCREG_H */
end_comment

end_unit

