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

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|INTR_SOLO
value|INTR_MD1
end_define

begin_typedef
typedef|typedef
name|int
name|arm_irq_filter_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
function_decl|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|arm_irq_filter_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARM_ISRC_NAMELEN
value|(MAXCOMLEN + 1)
end_define

begin_typedef
typedef|typedef
name|void
name|arm_ipi_filter_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_enum
enum|enum
name|arm_isrc_type
block|{
name|ARM_ISRCT_NAMESPACE
block|,
name|ARM_ISRCT_FDT
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|ARM_ISRCF_REGISTERED
value|0x01
end_define

begin_comment
comment|/* registered in a controller */
end_comment

begin_define
define|#
directive|define
name|ARM_ISRCF_PERCPU
value|0x02
end_define

begin_comment
comment|/* per CPU interrupt */
end_comment

begin_define
define|#
directive|define
name|ARM_ISRCF_BOUND
value|0x04
end_define

begin_comment
comment|/* bound to a CPU */
end_comment

begin_comment
comment|/* Interrupt source definition. */
end_comment

begin_struct
struct|struct
name|arm_irqsrc
block|{
name|device_t
name|isrc_dev
decl_stmt|;
comment|/* where isrc is mapped */
name|intptr_t
name|isrc_xref
decl_stmt|;
comment|/* device reference key */
name|uintptr_t
name|isrc_data
decl_stmt|;
comment|/* device data for isrc */
name|u_int
name|isrc_irq
decl_stmt|;
comment|/* unique identificator */
name|enum
name|arm_isrc_type
name|isrc_type
decl_stmt|;
comment|/* how is isrc decribed */
name|u_int
name|isrc_flags
decl_stmt|;
name|char
name|isrc_name
index|[
name|ARM_ISRC_NAMELEN
index|]
decl_stmt|;
name|uint16_t
name|isrc_nspc_type
decl_stmt|;
name|uint16_t
name|isrc_nspc_num
decl_stmt|;
name|enum
name|intr_trigger
name|isrc_trig
decl_stmt|;
name|enum
name|intr_polarity
name|isrc_pol
decl_stmt|;
name|cpuset_t
name|isrc_cpu
decl_stmt|;
comment|/* on which CPUs is enabled */
name|u_int
name|isrc_index
decl_stmt|;
name|u_long
modifier|*
name|isrc_count
decl_stmt|;
name|u_int
name|isrc_handlers
decl_stmt|;
name|struct
name|intr_event
modifier|*
name|isrc_event
decl_stmt|;
name|arm_irq_filter_t
modifier|*
name|isrc_filter
decl_stmt|;
name|arm_ipi_filter_t
modifier|*
name|isrc_ipifilter
decl_stmt|;
name|void
modifier|*
name|isrc_arg
decl_stmt|;
ifdef|#
directive|ifdef
name|FDT
name|u_int
name|isrc_ncells
decl_stmt|;
name|pcell_t
name|isrc_cells
index|[]
decl_stmt|;
comment|/* leave it last */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|void
name|arm_irq_set_name
parameter_list|(
name|struct
name|arm_irqsrc
modifier|*
name|isrc
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|arm_irq_dispatch
parameter_list|(
name|struct
name|arm_irqsrc
modifier|*
name|isrc
parameter_list|,
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ARM_IRQ_NSPC_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ARM_IRQ_NSPC_PLAIN
value|1
end_define

begin_define
define|#
directive|define
name|ARM_IRQ_NSPC_IRQ
value|2
end_define

begin_define
define|#
directive|define
name|ARM_IRQ_NSPC_IPI
value|3
end_define

begin_function_decl
name|u_int
name|arm_namespace_map_irq
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_function_decl
name|u_int
name|arm_fdt_map_irq
parameter_list|(
name|phandle_t
parameter_list|,
name|pcell_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|arm_pic_register
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|intptr_t
name|xref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_pic_unregister
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|intptr_t
name|xref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_pic_claim_root
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|intptr_t
name|xref
parameter_list|,
name|arm_irq_filter_t
modifier|*
name|filter
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|u_int
name|ipicount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_irq_add_handler
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|driver_filter_t
parameter_list|,
name|driver_intr_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
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
name|arm_irq_remove_handler
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_irq_config
parameter_list|(
name|u_int
parameter_list|,
name|enum
name|intr_trigger
parameter_list|,
name|enum
name|intr_polarity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_irq_describe
parameter_list|(
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|arm_irq_next_cpu
parameter_list|(
name|u_int
name|current_cpu
parameter_list|,
name|cpuset_t
modifier|*
name|cpumask
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function_decl
name|int
name|arm_irq_bind
parameter_list|(
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_ipi_dispatch
parameter_list|(
name|struct
name|arm_irqsrc
modifier|*
name|isrc
parameter_list|,
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AISHF_NOALLOC
value|0x0001
end_define

begin_function_decl
name|int
name|arm_ipi_set_handler
parameter_list|(
name|u_int
name|ipi
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|arm_ipi_filter_t
modifier|*
name|filter
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_pic_init_secondary
parameter_list|(
name|void
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
name|arm_pic_init_secondary
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
name|arm_fdt_map_irq
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

