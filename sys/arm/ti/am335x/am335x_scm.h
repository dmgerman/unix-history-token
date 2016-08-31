begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AM335X_SCM_H__
end_ifndef

begin_define
define|#
directive|define
name|__AM335X_SCM_H__
end_define

begin_comment
comment|/* AM335x-specific registers for control module (scm) */
end_comment

begin_define
define|#
directive|define
name|SCM_CTRL_STATUS
value|0x40
end_define

begin_define
define|#
directive|define
name|SCM_USB_CTRL0
value|0x620
end_define

begin_define
define|#
directive|define
name|SCM_USB_STS0
value|0x624
end_define

begin_define
define|#
directive|define
name|SCM_USB_CTRL1
value|0x628
end_define

begin_define
define|#
directive|define
name|SCM_USB_STS1
value|0x62C
end_define

begin_define
define|#
directive|define
name|SCM_MAC_ID0_LO
value|0x630
end_define

begin_define
define|#
directive|define
name|SCM_MAC_ID0_HI
value|0x634
end_define

begin_define
define|#
directive|define
name|SCM_PWMSS_CTRL
value|0x664
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AM335X_SCM_H__ */
end_comment

end_unit

