begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: imx51_tzicreg.h,v 1.1 2010/11/13 07:11:03 bsh Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2010  Genetec Corporation.  All rights reserved.  * Written by Hashimoto Kenichi for Genetec Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY GENETEC CORPORATION ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORPORATION  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Oleksandr Rybalko  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IMX51_TZICREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IMX51_TZICREG_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|TZIC_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|TZIC_INTCNTL
value|0x0000
end_define

begin_define
define|#
directive|define
name|INTCNTL_NSEN_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|INTCNTL_NSEN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INTCNTL_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TZIC_INTTYPE
value|0x0004
end_define

begin_define
define|#
directive|define
name|TZIC_PRIOMASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|TZIC_SYNCCTRL
value|0x0010
end_define

begin_define
define|#
directive|define
name|TZIC_DSMINT
value|0x0014
end_define

begin_define
define|#
directive|define
name|TZIC_INTSEC
parameter_list|(
name|n
parameter_list|)
value|(0x0080 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_ENSET
parameter_list|(
name|n
parameter_list|)
value|(0x0100 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_ENCLEAR
parameter_list|(
name|n
parameter_list|)
value|(0x0180 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_SRCSET
parameter_list|(
name|n
parameter_list|)
value|(0x0200 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_SRCCLAR
parameter_list|(
name|n
parameter_list|)
value|(0x0280 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_PRIORITY
parameter_list|(
name|n
parameter_list|)
value|(0x0400 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_PND
parameter_list|(
name|n
parameter_list|)
value|(0x0d00 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_HIPND
parameter_list|(
name|n
parameter_list|)
value|(0x0d80 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_WAKEUP
parameter_list|(
name|n
parameter_list|)
value|(0x0e00 + 0x04 * (n))
end_define

begin_define
define|#
directive|define
name|TZIC_SWINT
value|0x0f00
end_define

begin_define
define|#
directive|define
name|TZIC_INTNUM
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IMX51_TZICRREG_H_ */
end_comment

end_unit

