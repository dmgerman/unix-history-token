begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: sscom_var.h,v 1.5 2003/08/04 12:28:49 bsh Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Fujitsu Component Limited  * Copyright (c) 2002, 2003 Genetec Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Fujitsu Component Limited nor the name of  *    Genetec corporation may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY FUJITSU COMPONENT LIMITED AND GENETEC  * CORPORATION ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL FUJITSU COMPONENT LIMITED OR GENETEC  * CORPORATION BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* derived from sys/dev/ic/comvar.h */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_S3C2XX0_SSCOM_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_S3C2XX0_SSCOM_VAR_H
end_define

begin_comment
comment|/* Hardware flag masks */
end_comment

begin_define
define|#
directive|define
name|SSCOM_HW_FLOW
value|0x02
end_define

begin_define
define|#
directive|define
name|SSCOM_HW_DEV_OK
value|0x04
end_define

begin_define
define|#
directive|define
name|SSCOM_HW_CONSOLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SSCOM_HW_KGDB
value|0x10
end_define

begin_define
define|#
directive|define
name|SSCOM_HW_TXINT
value|0x20
end_define

begin_define
define|#
directive|define
name|SSCOM_HW_RXINT
value|0x40
end_define

begin_comment
comment|/* Buffer size for character buffer */
end_comment

begin_define
define|#
directive|define
name|SSCOM_RING_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|sscom_rxrdy
parameter_list|(
name|iot
parameter_list|,
name|ioh
parameter_list|)
define|\
value|(bus_space_read_1((iot), (ioh), SSCOM_UTRSTAT)& UTRSTAT_RXREADY)
end_define

begin_define
define|#
directive|define
name|sscom_getc
parameter_list|(
name|iot
parameter_list|,
name|ioh
parameter_list|)
value|bus_space_read_1((iot), (ioh), SSCOM_URXH)
end_define

begin_define
define|#
directive|define
name|sscom_geterr
parameter_list|(
name|iot
parameter_list|,
name|ioh
parameter_list|)
value|bus_space_read_1((iot), (ioh), SSCOM_UERSTAT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_S3C2XX0_SSCOM_VAR_H */
end_comment

end_unit

