begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BEN GRAY ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BEN GRAY BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OMAP4_SCM_PADCONF_H
end_ifndef

begin_define
define|#
directive|define
name|OMAP4_SCM_PADCONF_H
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_WAKEUP_EVENT
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_WAKEUP_ENABLE
value|(1UL<< 14)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_OFF_PULL_UP
value|(1UL<< 13)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_OFF_PULL_ENABLE
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_OFF_OUT_HIGH
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_OFF_OUT_ENABLE
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_OFF_ENABLE
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_INPUT_ENABLE
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_PULL_UP
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_PULL_ENABLE
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_MUXMODE_MASK
value|(0x7)
end_define

begin_define
define|#
directive|define
name|CONTROL_PADCONF_SATE_MASK
value|( CONTROL_PADCONF_WAKEUP_EVENT \                                          | CONTROL_PADCONF_WAKEUP_ENABLE \                                          | CONTROL_PADCONF_OFF_PULL_UP \                                          | CONTROL_PADCONF_OFF_PULL_ENABLE \                                          | CONTROL_PADCONF_OFF_OUT_HIGH \                                          | CONTROL_PADCONF_OFF_OUT_ENABLE \                                          | CONTROL_PADCONF_OFF_ENABLE \                                          | CONTROL_PADCONF_INPUT_ENABLE \                                          | CONTROL_PADCONF_PULL_UP \                                          | CONTROL_PADCONF_PULL_ENABLE )
end_define

begin_comment
comment|/* Active pin states */
end_comment

begin_define
define|#
directive|define
name|PADCONF_PIN_OUTPUT
value|0
end_define

begin_define
define|#
directive|define
name|PADCONF_PIN_INPUT
value|CONTROL_PADCONF_INPUT_ENABLE
end_define

begin_define
define|#
directive|define
name|PADCONF_PIN_INPUT_PULLUP
value|( CONTROL_PADCONF_INPUT_ENABLE \                                         | CONTROL_PADCONF_PULL_ENABLE \                                         | CONTROL_PADCONF_PULL_UP)
end_define

begin_define
define|#
directive|define
name|PADCONF_PIN_INPUT_PULLDOWN
value|( CONTROL_PADCONF_INPUT_ENABLE \                                         | CONTROL_PADCONF_PULL_ENABLE )
end_define

begin_comment
comment|/* Off mode states */
end_comment

begin_define
define|#
directive|define
name|PADCONF_PIN_OFF_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PADCONF_PIN_OFF_OUTPUT_HIGH
value|( CONTROL_PADCONF_OFF_ENABLE \                                         | CONTROL_PADCONF_OFF_OUT_ENABLE \                                         | CONTROL_PADCONF_OFF_OUT_HIGH)
end_define

begin_define
define|#
directive|define
name|PADCONF_PIN_OFF_OUTPUT_LOW
value|( CONTROL_PADCONF_OFF_ENABLE \                                         | CONTROL_PADCONF_OFF_OUT_ENABLE)
end_define

begin_define
define|#
directive|define
name|PADCONF_PIN_OFF_INPUT_PULLUP
value|( CONTROL_PADCONF_OFF_ENABLE \                                         | CONTROL_PADCONF_OFF_PULL_ENABLE \                                         | CONTROL_PADCONF_OFF_PULL_UP)
end_define

begin_define
define|#
directive|define
name|PADCONF_PIN_OFF_INPUT_PULLDOWN
value|( CONTROL_PADCONF_OFF_ENABLE \                                         | CONTROL_PADCONF_OFF_PULL_ENABLE)
end_define

begin_define
define|#
directive|define
name|PADCONF_PIN_OFF_WAKEUPENABLE
value|CONTROL_PADCONF_WAKEUP_ENABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OMAP4_SCM_PADCONF_H */
end_comment

end_unit

