begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Rui Paulo<rpaulo@FreeBSD.org>  * Copyright (c) 2017 Manuel Stuehn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_PRUSS_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_PRUSS_H_
end_define

begin_define
define|#
directive|define
name|PRUSS_AM18XX_INTC
value|0x04000
end_define

begin_define
define|#
directive|define
name|PRUSS_AM18XX_REV
value|0x4e825900
end_define

begin_define
define|#
directive|define
name|PRUSS_AM33XX_REV
value|0x4e82A900
end_define

begin_define
define|#
directive|define
name|PRUSS_AM33XX_INTC
value|0x20000
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_GER
value|(PRUSS_AM33XX_INTC + 0x0010)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_SISR
value|(PRUSS_AM33XX_INTC + 0x0020)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_SICR
value|(PRUSS_AM33XX_INTC + 0x0024)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_EISR
value|(PRUSS_AM33XX_INTC + 0x0028)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_EICR
value|(PRUSS_AM33XX_INTC + 0x002C)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_HIEISR
value|(PRUSS_AM33XX_INTC + 0x0034)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_HIDISR
value|(PRUSS_AM33XX_INTC + 0x0038)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_SECR0
value|(PRUSS_AM33XX_INTC + 0x0280)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_SECR1
value|(PRUSS_AM33XX_INTC + 0x0284)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_CMR_BASE
value|(PRUSS_AM33XX_INTC + 0x0400)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_HMR_BASE
value|(PRUSS_AM33XX_INTC + 0x0800)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_HIPIR_BASE
value|(PRUSS_AM33XX_INTC + 0x0900)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_SIPR0
value|(PRUSS_AM33XX_INTC + 0x0D00)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_SIPR1
value|(PRUSS_AM33XX_INTC + 0x0D04)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_SITR0
value|(PRUSS_AM33XX_INTC + 0x0D80)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_SITR1
value|(PRUSS_AM33XX_INTC + 0x0D84)
end_define

begin_define
define|#
directive|define
name|PRUSS_INTC_HIER
value|(PRUSS_AM33XX_INTC + 0x1500)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_PRUSS_H_ */
end_comment

end_unit

