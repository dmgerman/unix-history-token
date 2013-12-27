begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pcf8563reg.h,v 1.1 2011/01/21 19:11:47 jakllsch Exp $	*/
end_comment

begin_comment
comment|/*-  * Jonathan Kollasch, 2011  *  * This file is in the public domain.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * NXP (Philips) PCF8563 RTC registers  */
end_comment

begin_comment
comment|/* We only have clock mode registers here. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCF8563REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCF8563REG_H_
end_define

begin_comment
comment|/*  * PCF8563 RTC I2C address:  *  *	101 0001  */
end_comment

begin_define
define|#
directive|define
name|PCF8563_ADDR
value|0xa2
end_define

begin_define
define|#
directive|define
name|PCF8563_R_CS1
value|0x00
end_define

begin_define
define|#
directive|define
name|PCF8563_R_CS2
value|0x01
end_define

begin_define
define|#
directive|define
name|PCF8563_R_SECOND
value|0x02
end_define

begin_define
define|#
directive|define
name|PCF8563_R_MINUTE
value|0x03
end_define

begin_define
define|#
directive|define
name|PCF8563_R_HOUR
value|0x04
end_define

begin_define
define|#
directive|define
name|PCF8563_R_DAY
value|0x05
end_define

begin_define
define|#
directive|define
name|PCF8563_R_WEEKDAY
value|0x06
end_define

begin_define
define|#
directive|define
name|PCF8563_R_MONTH
value|0x07
end_define

begin_define
define|#
directive|define
name|PCF8563_R_YEAR
value|0x08
end_define

begin_define
define|#
directive|define
name|PCF8563_R_MINUTE_ALARM
value|0x09
end_define

begin_define
define|#
directive|define
name|PCF8563_R_HOUR_ALARM
value|0x0a
end_define

begin_define
define|#
directive|define
name|PCF8563_R_DAY_ALARM
value|0x0b
end_define

begin_define
define|#
directive|define
name|PCF8563_R_WEEKDAY_ALARM
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCF8563_R_CLKOUT_CNTRL
value|0x0d
end_define

begin_define
define|#
directive|define
name|PCF8563_R_TIMER_CNTRL
value|0x0e
end_define

begin_define
define|#
directive|define
name|PCF8563_R_TIMER
value|0x0f
end_define

begin_define
define|#
directive|define
name|PCF8563_R_SECOND_VL
value|0x80
end_define

begin_define
define|#
directive|define
name|PCF8563_R_MONTH_C
value|0x80
end_define

begin_define
define|#
directive|define
name|PCF8563_NREGS
value|0x10
end_define

begin_define
define|#
directive|define
name|PCF8563_M_SECOND
value|0x7f
end_define

begin_define
define|#
directive|define
name|PCF8563_M_MINUTE
value|0x7f
end_define

begin_define
define|#
directive|define
name|PCF8563_M_HOUR
value|0x3f
end_define

begin_define
define|#
directive|define
name|PCF8563_M_DAY
value|0x3f
end_define

begin_define
define|#
directive|define
name|PCF8563_M_WEEKDAY
value|0x07
end_define

begin_define
define|#
directive|define
name|PCF8563_M_MONTH
value|0x1f
end_define

begin_define
define|#
directive|define
name|PCF8563_M_CENTURY
value|0x80
end_define

begin_define
define|#
directive|define
name|PCF8563_M_YEAR
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCF8563REG_H_ */
end_comment

end_unit

