begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	$NetBSD: intr.h,v 1.7 2003/06/16 20:01:00 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Mark Brinicombe.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Brinicombe  *	for the NetBSD Project.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_INTRNG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NIRQ
end_ifndef

begin_define
define|#
directive|define
name|NIRQ
value|1024
end_define

begin_comment
comment|/* XXX - It should be an option. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/intr.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_typedef
typedef|typedef
name|void
name|intr_ipi_send_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|cpuset_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|intr_ipi_handler_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|intr_ipi_dispatch
parameter_list|(
name|u_int
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_ipi_send
parameter_list|(
name|cpuset_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_ipi_setup
parameter_list|(
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|intr_ipi_handler_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|intr_ipi_send_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_pic_ipi_setup
parameter_list|(
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|intr_ipi_handler_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARM_INTRNG */
end_comment

begin_comment
comment|/* XXX move to std.* files? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_81342
end_ifdef

begin_define
define|#
directive|define
name|NIRQ
value|128
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_XSCALE_PXA2X0
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<arm/xscale/pxa/pxareg.h>
end_include

begin_define
define|#
directive|define
name|NIRQ
value|IRQ_GPIO_MAX
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_elif

begin_define
define|#
directive|define
name|NIRQ
value|96
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
operator|||
name|defined
argument_list|(
name|SOC_MV_KIRKWOOD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_IXP435
argument_list|)
end_elif

begin_define
define|#
directive|define
name|NIRQ
value|64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_CORTEXA
argument_list|)
end_elif

begin_define
define|#
directive|define
name|NIRQ
value|1020
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_KRAIT
argument_list|)
end_elif

begin_define
define|#
directive|define
name|NIRQ
value|288
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
end_elif

begin_define
define|#
directive|define
name|NIRQ
value|128
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MAIN_IRQ_NUM
value|116
end_define

begin_define
define|#
directive|define
name|ERR_IRQ_NUM
value|32
end_define

begin_define
define|#
directive|define
name|ERR_IRQ
value|(MAIN_IRQ_NUM)
end_define

begin_define
define|#
directive|define
name|MSI_IRQ_NUM
value|32
end_define

begin_define
define|#
directive|define
name|MSI_IRQ
value|(ERR_IRQ + ERR_IRQ_NUM)
end_define

begin_define
define|#
directive|define
name|NIRQ
value|(MAIN_IRQ_NUM + ERR_IRQ_NUM + MSI_IRQ_NUM)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NIRQ
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|arm_get_next_irq
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_mask_irq
parameter_list|(
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_unmask_irq
parameter_list|(
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_intrnames_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_setup_irqhandler
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_remove_irqhandler
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|arm_post_filter
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|arm_config_irq
function_decl|)
parameter_list|(
name|int
name|irq
parameter_list|,
name|enum
name|intr_trigger
name|trig
parameter_list|,
name|enum
name|intr_polarity
name|pol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_pic_init_secondary
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_function_decl
name|int
name|gic_decode_fdt
parameter_list|(
name|phandle_t
parameter_list|,
name|pcell_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_fdt_map_irq
parameter_list|(
name|phandle_t
parameter_list|,
name|pcell_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_INTRNG */
end_comment

begin_function_decl
name|void
name|arm_irq_memory_barrier
parameter_list|(
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_INTR_H */
end_comment

end_unit

