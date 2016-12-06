begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * the sponsorship of the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GIC_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_GIC_COMMON_H_
end_define

begin_comment
comment|/* Common register values */
end_comment

begin_define
define|#
directive|define
name|GICD_CTLR
value|0x0000
end_define

begin_comment
comment|/* v1 ICDDCR */
end_comment

begin_define
define|#
directive|define
name|GICD_TYPER
value|0x0004
end_define

begin_comment
comment|/* v1 ICDICTR */
end_comment

begin_define
define|#
directive|define
name|GICD_IIDR
value|0x0008
end_define

begin_comment
comment|/* v1 ICDIIDR */
end_comment

begin_define
define|#
directive|define
name|GICD_IIDR_PROD_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_PROD_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_PROD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& GICD_IIDR_PROD_MASK)>> GICD_IIDR_PROD_SHIFT)
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_VAR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_VAR_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_VAR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& GICD_IIDR_VAR_MASK)>> GICD_IIDR_VAR_SHIFT)
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_REV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_REV_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_REV
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& GICD_IIDR_REV_MASK)>> GICD_IIDR_REV_SHIFT)
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_IMPL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_IMPL_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|GICD_IIDR_IMPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& GICD_IIDR_IMPL_MASK)>> GICD_IIDR_IMPL_SHIFT)
end_define

begin_define
define|#
directive|define
name|GICD_IGROUPR
parameter_list|(
name|n
parameter_list|)
value|(0x0080 + (((n)>> 5) * 4))
end_define

begin_comment
comment|/* v1 ICDISER */
end_comment

begin_define
define|#
directive|define
name|GICD_ISENABLER
parameter_list|(
name|n
parameter_list|)
value|(0x0100 + (((n)>> 5) * 4))
end_define

begin_comment
comment|/* v1 ICDISER */
end_comment

begin_define
define|#
directive|define
name|GICD_ICENABLER
parameter_list|(
name|n
parameter_list|)
value|(0x0180 + (((n)>> 5) * 4))
end_define

begin_comment
comment|/* v1 ICDICER */
end_comment

begin_define
define|#
directive|define
name|GICD_ISPENDR
parameter_list|(
name|n
parameter_list|)
value|(0x0200 + (((n)>> 5) * 4))
end_define

begin_comment
comment|/* v1 ICDISPR */
end_comment

begin_define
define|#
directive|define
name|GICD_ICPENDR
parameter_list|(
name|n
parameter_list|)
value|(0x0280 + (((n)>> 5) * 4))
end_define

begin_comment
comment|/* v1 ICDICPR */
end_comment

begin_define
define|#
directive|define
name|GICD_ICACTIVER
parameter_list|(
name|n
parameter_list|)
value|(0x0380 + (((n)>> 5) * 4))
end_define

begin_comment
comment|/* v1 ICDABR */
end_comment

begin_define
define|#
directive|define
name|GICD_IPRIORITYR
parameter_list|(
name|n
parameter_list|)
value|(0x0400 + (((n)>> 2) * 4))
end_define

begin_comment
comment|/* v1 ICDIPR */
end_comment

begin_define
define|#
directive|define
name|GICD_ITARGETSR
parameter_list|(
name|n
parameter_list|)
value|(0x0800 + (((n)>> 2) * 4))
end_define

begin_comment
comment|/* v1 ICDIPTR */
end_comment

begin_define
define|#
directive|define
name|GICD_ICFGR
parameter_list|(
name|n
parameter_list|)
value|(0x0C00 + (((n)>> 4) * 4))
end_define

begin_comment
comment|/* v1 ICDICFR */
end_comment

begin_comment
comment|/* First bit is a polarity bit (0 - low, 1 - high) */
end_comment

begin_define
define|#
directive|define
name|GICD_ICFGR_POL_LOW
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR_POL_HIGH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR_POL_MASK
value|0x1
end_define

begin_comment
comment|/* Second bit is a trigger bit (0 - level, 1 - edge) */
end_comment

begin_define
define|#
directive|define
name|GICD_ICFGR_TRIG_LVL
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR_TRIG_EDGE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR_TRIG_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|GICD_SGIR
value|0x0F00
end_define

begin_comment
comment|/* v1 ICDSGIR */
end_comment

begin_define
define|#
directive|define
name|GICD_SGI_TARGET_SHIFT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GIC_COMMON_H_ */
end_comment

end_unit

