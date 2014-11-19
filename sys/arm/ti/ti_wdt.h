begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Rui Paulo<rpaulo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_WDT_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_WDT_H_
end_define

begin_comment
comment|/* TI WDT registers */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WIDR
value|0x00
end_define

begin_comment
comment|/* Watchdog Identification Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WDSC
value|0x10
end_define

begin_comment
comment|/* Watchdog System Control Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WDST
value|0x14
end_define

begin_comment
comment|/* Watchdog Status Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WISR
value|0x18
end_define

begin_comment
comment|/* Watchdog Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WIER
value|0x1c
end_define

begin_comment
comment|/* Watchdog Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WCLR
value|0x24
end_define

begin_comment
comment|/* Watchdog Control Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WCRR
value|0x28
end_define

begin_comment
comment|/* Watchdog Counter Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WLDR
value|0x2c
end_define

begin_comment
comment|/* Watchdog Load Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WTGR
value|0x30
end_define

begin_comment
comment|/* Watchdog Trigger Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WWPS
value|0x34
end_define

begin_comment
comment|/* Watchdog Write Posting Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WDLY
value|0x44
end_define

begin_comment
comment|/* Watchdog Delay Configuration Reg */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WSPR
value|0x48
end_define

begin_comment
comment|/* Watchdog Start/Stop Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WIRQSTATRAW
value|0x54
end_define

begin_comment
comment|/* Watchdog Raw Interrupt Status Reg. */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WIRQSTAT
value|0x58
end_define

begin_comment
comment|/* Watchdog Int. Status Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WIRQENSET
value|0x5c
end_define

begin_comment
comment|/* Watchdog Int. Enable Set Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDT_WIRQENCLR
value|0x60
end_define

begin_comment
comment|/* Watchdog Int. Enable Clear Reg. */
end_comment

begin_comment
comment|/* WDT_WDSC Register */
end_comment

begin_define
define|#
directive|define
name|TI_WDSC_SR
value|(1<< 1)
end_define

begin_comment
comment|/* Soft reset */
end_comment

begin_comment
comment|/*  * WDT_WWPS Register  *  * Writes to some registers require synchronisation with a different clock  * domain.  The WDT_WWPS register is the place where this synchronisation  * happens.  */
end_comment

begin_define
define|#
directive|define
name|TI_W_PEND_WCLR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|TI_W_PEND_WCRR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TI_W_PEND_WLDR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TI_W_PEND_WTGR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TI_W_PEND_WSPR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TI_W_PEND_WDLY
value|(1<< 5)
end_define

begin_comment
comment|/* WDT_WIRQENSET Register */
end_comment

begin_define
define|#
directive|define
name|TI_IRQ_EN_OVF
value|(1<< 0)
end_define

begin_comment
comment|/* Overflow interrupt */
end_comment

begin_define
define|#
directive|define
name|TI_IRQ_EN_DLY
value|(1<< 1)
end_define

begin_comment
comment|/* Delay interrupt */
end_comment

begin_comment
comment|/* WDT_WIRQSTAT Register */
end_comment

begin_define
define|#
directive|define
name|TI_IRQ_EV_OVF
value|(1<< 0)
end_define

begin_comment
comment|/* Overflow event */
end_comment

begin_define
define|#
directive|define
name|TI_IRQ_EV_DLY
value|(1<< 1)
end_define

begin_comment
comment|/* Delay event */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_WDT_H_ */
end_comment

end_unit

