begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rui Paulo<rpaulo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_HWPMC_XSCALE_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_HWPMC_XSCALE_H_
end_define

begin_define
define|#
directive|define
name|XSCALE_PMC_CAPS
value|(PMC_CAP_INTERRUPT | PMC_CAP_USER |     \ 				 PMC_CAP_SYSTEM | PMC_CAP_EDGE |	\ 				 PMC_CAP_THRESHOLD | PMC_CAP_READ |	\ 				 PMC_CAP_WRITE | PMC_CAP_INVERT |	\ 				 PMC_CAP_QUALIFIER)
end_define

begin_define
define|#
directive|define
name|XSCALE_PMNC_ENABLE
value|0x01
end_define

begin_comment
comment|/* Enable all Counters */
end_comment

begin_define
define|#
directive|define
name|XSCALE_PMNC_PMNRESET
value|0x02
end_define

begin_comment
comment|/* Performance Counter Reset */
end_comment

begin_define
define|#
directive|define
name|XSCALE_PMNC_CCNTRESET
value|0x04
end_define

begin_comment
comment|/* Clock Counter Reset */
end_comment

begin_define
define|#
directive|define
name|XSCALE_PMNC_CCNTDIV
value|0x08
end_define

begin_comment
comment|/* Clock Counter Divider */
end_comment

begin_comment
comment|/* IXP425 only -- first generation */
end_comment

begin_define
define|#
directive|define
name|XSCALE_PMNC_EVT0_MASK
value|0x00ff000
end_define

begin_define
define|#
directive|define
name|XSCALE_PMNC_EVT1_MASK
value|0xff00000
end_define

begin_define
define|#
directive|define
name|XSCALE_INTEN_CCNT
value|0x01
end_define

begin_comment
comment|/* Enable Clock Counter Int. */
end_comment

begin_define
define|#
directive|define
name|XSCALE_INTEN_PMN0
value|0x02
end_define

begin_comment
comment|/* Enable PMN0 Interrupts */
end_comment

begin_define
define|#
directive|define
name|XSCALE_INTEN_PMN1
value|0x04
end_define

begin_comment
comment|/* Enable PMN1 Interrupts */
end_comment

begin_define
define|#
directive|define
name|XSCALE_INTEN_PMN2
value|0x08
end_define

begin_comment
comment|/* Enable PMN2 Interrupts */
end_comment

begin_define
define|#
directive|define
name|XSCALE_INTEN_PMN3
value|0x10
end_define

begin_comment
comment|/* Enable PMN3 Interrupts */
end_comment

begin_define
define|#
directive|define
name|XSCALE_EVTSEL_EVT0_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|XSCALE_EVTSEL_EVT1_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|XSCALE_EVTSEL_EVT2_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|XSCALE_EVTSEL_EVT3_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|XSCALE_FLAG_CCNT_OVERFLOW
value|0x01
end_define

begin_define
define|#
directive|define
name|XSCALE_FLAG_PMN0_OVERFLOW
value|0x02
end_define

begin_define
define|#
directive|define
name|XSCALE_FLAG_PMN1_OVERFLOW
value|0x04
end_define

begin_define
define|#
directive|define
name|XSCALE_FLAG_PMN2_OVERFLOW
value|0x08
end_define

begin_define
define|#
directive|define
name|XSCALE_FLAG_PMN3_OVERFLOW
value|0x10
end_define

begin_define
define|#
directive|define
name|XSCALE_RELOAD_COUNT_TO_PERFCTR_VALUE
parameter_list|(
name|R
parameter_list|)
value|(-(R))
end_define

begin_define
define|#
directive|define
name|XSCALE_PERFCTR_VALUE_TO_RELOAD_COUNT
parameter_list|(
name|P
parameter_list|)
value|(-(P))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* MD extension for 'struct pmc' */
end_comment

begin_struct
struct|struct
name|pmc_md_xscale_pmc
block|{
name|uint32_t
name|pm_xscale_evsel
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_HWPMC_XSCALE_H_ */
end_comment

end_unit

