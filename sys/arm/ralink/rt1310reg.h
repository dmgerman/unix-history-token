begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Jakub Wojciech Klama<jceel@FreeBSD.org>  * Copyright (c) 2015 Hiroki Mori  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_RALINK_RT1310REG_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_RALINK_RT1310REG_H
end_define

begin_comment
comment|/*  * Interrupt controller  */
end_comment

begin_define
define|#
directive|define
name|RT_INTC_SCR0
value|0x00
end_define

begin_define
define|#
directive|define
name|RT_INTC_SVR0
value|0x80
end_define

begin_define
define|#
directive|define
name|RT_INTC_ISR
value|0x104
end_define

begin_define
define|#
directive|define
name|RT_INTC_IPR
value|0x108
end_define

begin_define
define|#
directive|define
name|RT_INTC_IMR
value|0x10c
end_define

begin_define
define|#
directive|define
name|RT_INTC_IECR
value|0x114
end_define

begin_define
define|#
directive|define
name|RT_INTC_ICCR
value|0x118
end_define

begin_define
define|#
directive|define
name|RT_INTC_TRIG_LOW_LVL
value|(0)
end_define

begin_define
define|#
directive|define
name|RT_INTC_TRIG_HIGH_LVL
value|(1)
end_define

begin_define
define|#
directive|define
name|RT_INTC_TRIG_NEG_EDGE
value|(2)
end_define

begin_define
define|#
directive|define
name|RT_INTC_TRIG_POS_EDGE
value|(3)
end_define

begin_define
define|#
directive|define
name|RT_INTC_TRIG_SHIF
value|6
end_define

begin_comment
comment|/*  * Timer 0|1|2|3.  */
end_comment

begin_define
define|#
directive|define
name|RT_TIMER_LOAD
value|0x00
end_define

begin_define
define|#
directive|define
name|RT_TIMER_VALUE
value|0x04
end_define

begin_define
define|#
directive|define
name|RT_TIMER_CONTROL
value|0x08
end_define

begin_define
define|#
directive|define
name|RT_TIMER_CTRL_INTCTL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT_TIMER_CTRL_INTCLR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT_TIMER_CTRL_INTMASK
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT_TIMER_CTRL_DIV16
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|RT_TIMER_CTRL_DIV256
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|RT_TIMER_CTRL_PERIODCAL
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RT_TIMER_CTRL_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RT_TIMER_INTERVAL
value|(5000*150)
end_define

begin_comment
comment|/*  * GPIO  */
end_comment

begin_define
define|#
directive|define
name|RT_GPIO_PORTA
value|(0)
end_define

begin_define
define|#
directive|define
name|RT_GPIO_PORTB
value|(1)
end_define

begin_define
define|#
directive|define
name|RT_GPIO_OFF_PADR
value|(0x0)
end_define

begin_define
define|#
directive|define
name|RT_GPIO_OFF_PADIR
value|(0x4)
end_define

begin_define
define|#
directive|define
name|RT_GPIO_OFF_PBDR
value|(0x8)
end_define

begin_define
define|#
directive|define
name|RT_GPIO_OFF_PBDIR
value|(0xC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_RALINK_RT1310REG_H */
end_comment

end_unit

