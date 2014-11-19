begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_CPUID_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_CPUID_H_
end_define

begin_define
define|#
directive|define
name|OMAP_MAKEREV
parameter_list|(
name|d
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|(uint32_t)(((d)<< 16) | (((a)& 0xf)<< 8) | (((b)& 0xf)<< 4) | ((c)& 0xf))
end_define

begin_define
define|#
directive|define
name|OMAP_REV_DEVICE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|OMAP_REV_MAJOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xf)
end_define

begin_define
define|#
directive|define
name|OMAP_REV_MINOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|OMAP_REV_MINOR_MINOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xf)
end_define

begin_define
define|#
directive|define
name|OMAP3350_DEV
value|0x3530
end_define

begin_define
define|#
directive|define
name|OMAP3350_REV_ES1_0
value|OMAP_MAKEREV(OMAP3350_DEV, 1, 0, 0)
end_define

begin_define
define|#
directive|define
name|OMAP3530_REV_ES2_0
value|OMAP_MAKEREV(OMAP3350_DEV, 2, 0, 0)
end_define

begin_define
define|#
directive|define
name|OMAP3530_REV_ES2_1
value|OMAP_MAKEREV(OMAP3350_DEV, 2, 1, 0)
end_define

begin_define
define|#
directive|define
name|OMAP3530_REV_ES3_0
value|OMAP_MAKEREV(OMAP3350_DEV, 3, 0, 0)
end_define

begin_define
define|#
directive|define
name|OMAP3530_REV_ES3_1
value|OMAP_MAKEREV(OMAP3350_DEV, 3, 1, 0)
end_define

begin_define
define|#
directive|define
name|OMAP3530_REV_ES3_1_2
value|OMAP_MAKEREV(OMAP3350_DEV, 3, 1, 2)
end_define

begin_define
define|#
directive|define
name|OMAP4430_DEV
value|0x4430
end_define

begin_define
define|#
directive|define
name|OMAP4430_REV_ES1_0
value|OMAP_MAKEREV(OMAP4430_DEV, 1, 0, 0)
end_define

begin_define
define|#
directive|define
name|OMAP4430_REV_ES2_0
value|OMAP_MAKEREV(OMAP4430_DEV, 2, 0, 0)
end_define

begin_define
define|#
directive|define
name|OMAP4430_REV_ES2_1
value|OMAP_MAKEREV(OMAP4430_DEV, 2, 1, 0)
end_define

begin_define
define|#
directive|define
name|OMAP4430_REV_ES2_2
value|OMAP_MAKEREV(OMAP4430_DEV, 2, 2, 0)
end_define

begin_define
define|#
directive|define
name|OMAP4430_REV_ES2_3
value|OMAP_MAKEREV(OMAP4430_DEV, 2, 3, 0)
end_define

begin_define
define|#
directive|define
name|OMAP4430_REV_UNKNOWN
value|OMAP_MAKEREV(OMAP4430_DEV, 9, 9, 9)
end_define

begin_define
define|#
directive|define
name|OMAP4460_DEV
value|0x4460
end_define

begin_define
define|#
directive|define
name|OMAP4460_REV_ES1_0
value|OMAP_MAKEREV(OMAP4460_DEV, 1, 0, 0)
end_define

begin_define
define|#
directive|define
name|OMAP4460_REV_ES1_1
value|OMAP_MAKEREV(OMAP4460_DEV, 1, 1, 0)
end_define

begin_define
define|#
directive|define
name|OMAP4460_REV_UNKNOWN
value|OMAP_MAKEREV(OMAP4460_DEV, 9, 9, 9)
end_define

begin_define
define|#
directive|define
name|OMAP4470_DEV
value|0x4470
end_define

begin_define
define|#
directive|define
name|OMAP4470_REV_ES1_0
value|OMAP_MAKEREV(OMAP4470_DEV, 1, 0, 0)
end_define

begin_define
define|#
directive|define
name|OMAP4470_REV_UNKNOWN
value|OMAP_MAKEREV(OMAP4470_DEV, 9, 9, 9)
end_define

begin_define
define|#
directive|define
name|OMAP_UNKNOWN_DEV
value|OMAP_MAKEREV(0x9999, 9, 9, 9)
end_define

begin_define
define|#
directive|define
name|AM335X_DEVREV
parameter_list|(
name|x
parameter_list|)
value|((x)>> 28)
end_define

begin_define
define|#
directive|define
name|CHIP_OMAP_4
value|0
end_define

begin_define
define|#
directive|define
name|CHIP_AM335X
value|1
end_define

begin_function
specifier|static
name|__inline
name|int
name|ti_chip
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|SOC_OMAP4
argument_list|)
return|return
name|CHIP_OMAP_4
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_TI_AM335X
argument_list|)
return|return
name|CHIP_AM335X
return|;
else|#
directive|else
error|#
directive|error
error|Chip type not defined, ensure SOC_xxxx is defined
endif|#
directive|endif
block|}
end_function

begin_function_decl
name|uint32_t
name|ti_revision
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_CPUID_H_ */
end_comment

end_unit

