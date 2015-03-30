begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cpuconf.h,v 1.8 2003/09/06 08:55:42 rearnsha Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUCONF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUCONF_H_
end_define

begin_comment
comment|/*  * IF YOU CHANGE THIS FILE, MAKE SURE TO UPDATE THE DEFINITION OF  * "PMAP_NEEDS_PTE_SYNC" IN<arm/arm32/pmap.h> FOR THE CPU TYPE  * YOU ARE ADDING SUPPORT FOR.  */
end_comment

begin_comment
comment|/*  * Step 1: Count the number of CPU types configured into the kernel.  */
end_comment

begin_define
define|#
directive|define
name|CPU_NTYPES
value|(defined(CPU_ARM9) +				\ 			 defined(CPU_ARM9E) +				\ 			 defined(CPU_ARM1176) +				\ 			 defined(CPU_XSCALE_80200) +			\ 			 defined(CPU_XSCALE_80321) +			\ 			 defined(CPU_XSCALE_PXA2X0) +			\ 			 defined(CPU_FA526) +				\ 			 defined(CPU_XSCALE_IXP425)) +			\ 			 defined(CPU_CORTEXA) +				\ 			 defined(CPU_KRAIT) +				\ 			 defined(CPU_MV_PJ4B)
end_define

begin_comment
comment|/*  * Step 2: Determine which ARM architecture versions are configured.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_FA526
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARM_ARCH_4
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_ARCH_4
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80200
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_PXA2X0
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_IXP425
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ARM_ARCH_5
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_ARCH_5
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ARM_ARCH_6
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARM_ARCH_6
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_ARCH_6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_CORTEXA
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_KRAIT
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_MV_PJ4B
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARM_ARCH_7A
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_ARCH_7A
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARM_NARCH
value|(ARM_ARCH_4 + ARM_ARCH_5 + ARM_ARCH_6 | ARM_ARCH_7A)
end_define

begin_comment
comment|/*  * Compatibility for userland builds that have no CPUTYPE defined.  Use the ARCH  * constants predefined by the compiler to define our old-school arch constants.  * This is a stopgap measure to tide us over until the conversion of all code  * to the newer ACLE constants defined by ARM (see acle-compat.h).  */
end_comment

begin_if
if|#
directive|if
name|ARM_NARCH
operator|==
literal|0
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_4T__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|ARM_ARCH_4
end_undef

begin_undef
undef|#
directive|undef
name|ARM_NARCH
end_undef

begin_define
define|#
directive|define
name|ARM_ARCH_4
value|1
end_define

begin_define
define|#
directive|define
name|ARM_NARCH
value|1
end_define

begin_define
define|#
directive|define
name|CPU_ARM9
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
end_elif

begin_undef
undef|#
directive|undef
name|ARM_ARCH_6
end_undef

begin_undef
undef|#
directive|undef
name|ARM_NARCH
end_undef

begin_define
define|#
directive|define
name|ARM_ARCH_6
value|1
end_define

begin_define
define|#
directive|define
name|ARM_NARCH
value|1
end_define

begin_define
define|#
directive|define
name|CPU_ARM1176
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ARM_NARCH
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_error
error|#
directive|error
error|ARM_NARCH is 0
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ARM_ARCH_5
operator|||
name|ARM_ARCH_6
operator|||
name|ARM_ARCH_7A
end_if

begin_comment
comment|/*  * We could support Thumb code on v4T, but the lack of clean interworking  * makes that hard.  */
end_comment

begin_define
define|#
directive|define
name|THUMB_CODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Step 3: Define which MMU classes are configured:  *  *	ARM_MMU_MEMC		Prehistoric, external memory controller  *				and MMU for ARMv2 CPUs.  *  *      ARM_MMU_GENERIC		Generic ARM MMU, compatible with ARMv4 and v5.  *  *	ARM_MMU_V6		ARMv6 MMU.  *  *	ARM_MMU_V7		ARMv7 MMU.  *  *	ARM_MMU_XSCALE		XScale MMU.  Compatible with generic ARM  *				MMU, but also has several extensions which  *				require different PTE layout to use.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_FA526
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ARM_MMU_GENERIC
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_MMU_GENERIC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARM_MMU_V6
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_MMU_V6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_CORTEXA
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_KRAIT
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_MV_PJ4B
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARM_MMU_V7
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_MMU_V7
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|CPU_XSCALE_80200
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_PXA2X0
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_IXP425
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ARM_MMU_XSCALE
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_MMU_XSCALE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARM_NMMUS
value|(ARM_MMU_GENERIC + ARM_MMU_V6 + \ 				 ARM_MMU_V7 + ARM_MMU_XSCALE)
end_define

begin_if
if|#
directive|if
name|ARM_NMMUS
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_error
error|#
directive|error
error|ARM_NMMUS is 0
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Step 4: Define features that may be present on a subset of CPUs  *  *	ARM_XSCALE_PMU		Performance Monitoring Unit on 80200 and 80321  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|CPU_XSCALE_80200
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ARM_XSCALE_PMU
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_XSCALE_PMU
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
end_if

begin_define
define|#
directive|define
name|CPU_XSCALE_CORE3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_CPUCONF_H_ */
end_comment

end_unit

