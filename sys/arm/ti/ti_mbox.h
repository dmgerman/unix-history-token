begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Rui Paulo<rpaulo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_MBOX_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_MBOX_H_
end_define

begin_define
define|#
directive|define
name|TI_MBOX_REVISION
value|0x00
end_define

begin_define
define|#
directive|define
name|TI_MBOX_SYSCONFIG
value|0x10
end_define

begin_define
define|#
directive|define
name|TI_MBOX_SYSCONFIG_SOFTRST
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_MBOX_SYSCONFIG_SMARTIDLE
value|(0x02<< 2)
end_define

begin_define
define|#
directive|define
name|TI_MBOX_MESSAGE
parameter_list|(
name|n
parameter_list|)
value|(0x40 + (n) * 0x4)
end_define

begin_define
define|#
directive|define
name|TI_MBOX_FIFOSTATUS
parameter_list|(
name|n
parameter_list|)
value|(0x80 + (n) * 0x4)
end_define

begin_define
define|#
directive|define
name|TI_MBOX_MSGSTATUS
parameter_list|(
name|n
parameter_list|)
value|(0xc0 + (n) * 0x4)
end_define

begin_define
define|#
directive|define
name|TI_MBOX_IRQSTATUS_RAW
parameter_list|(
name|n
parameter_list|)
value|(0x100 + (n) * 0x10)
end_define

begin_define
define|#
directive|define
name|TI_MBOX_IRQSTATUS_CLR
parameter_list|(
name|n
parameter_list|)
value|(0x104 + (n) * 0x10)
end_define

begin_define
define|#
directive|define
name|TI_MBOX_IRQENABLE_SET
parameter_list|(
name|n
parameter_list|)
value|(0x108 + (n) * 0x10)
end_define

begin_define
define|#
directive|define
name|TI_MBOX_IRQENABLE_CLR
parameter_list|(
name|n
parameter_list|)
value|(0x10c + (n) * 0x10)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_MBOX_H_ */
end_comment

end_unit

