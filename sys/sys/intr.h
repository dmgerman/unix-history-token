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
name|_SYS_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_INTR_H_
end_define

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

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
name|intr_irq_filter_t
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
name|intr_irq_filter_t
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
name|INTR_ISRC_NAMELEN
value|(MAXCOMLEN + 1)
end_define

begin_typedef
typedef|typedef
name|void
name|intr_ipi_filter_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_enum
enum|enum
name|intr_isrc_type
block|{
name|INTR_ISRCT_NAMESPACE
block|,
name|INTR_ISRCT_FDT
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|INTR_ISRCF_REGISTERED
value|0x01
end_define

begin_comment
comment|/* registered in a controller */
end_comment

begin_define
define|#
directive|define
name|INTR_ISRCF_PERCPU
value|0x02
end_define

begin_comment
comment|/* per CPU interrupt */
end_comment

begin_define
define|#
directive|define
name|INTR_ISRCF_BOUND
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
name|intr_irqsrc
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
name|intr_isrc_type
name|isrc_type
decl_stmt|;
comment|/* how is isrc decribed */
name|u_int
name|isrc_flags
decl_stmt|;
name|char
name|isrc_name
index|[
name|INTR_ISRC_NAMELEN
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
ifdef|#
directive|ifdef
name|INTR_SOLO
name|intr_irq_filter_t
modifier|*
name|isrc_filter
decl_stmt|;
endif|#
directive|endif
name|intr_ipi_filter_t
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
name|intr_irq_set_name
parameter_list|(
name|struct
name|intr_irqsrc
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
name|intr_irq_dispatch
parameter_list|(
name|struct
name|intr_irqsrc
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
name|INTR_IRQ_NSPC_NONE
value|0
end_define

begin_define
define|#
directive|define
name|INTR_IRQ_NSPC_PLAIN
value|1
end_define

begin_define
define|#
directive|define
name|INTR_IRQ_NSPC_IRQ
value|2
end_define

begin_define
define|#
directive|define
name|INTR_IRQ_NSPC_IPI
value|3
end_define

begin_function_decl
name|u_int
name|intr_namespace_map_irq
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
name|intr_fdt_map_irq
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

begin_decl_stmt
specifier|extern
name|device_t
name|intr_irq_root_dev
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|intr_pic_register
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
name|intr_pic_unregister
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
name|intr_pic_claim_root
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|intptr_t
name|xref
parameter_list|,
name|intr_irq_filter_t
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
name|intr_irq_add_handler
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
name|intr_irq_remove_handler
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
name|intr_irq_config
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
name|intr_irq_describe
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
name|intr_irq_next_cpu
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
name|intr_irq_bind
parameter_list|(
name|u_int
parameter_list|,
name|int
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

begin_comment
comment|/* Virtualization for interrupt source IPI counter increment. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|intr_ipi_increment_count
parameter_list|(
name|u_long
modifier|*
name|counter
parameter_list|,
name|u_int
name|cpu
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|cpu
operator|<
name|MAXCPU
argument_list|,
operator|(
literal|"%s: too big cpu %u"
operator|,
name|__func__
operator|,
name|cpu
operator|)
argument_list|)
expr_stmt|;
name|counter
index|[
name|cpu
index|]
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Virtualization for interrupt source IPI counters setup. */
end_comment

begin_function_decl
name|u_long
modifier|*
name|intr_ipi_setup_counters
parameter_list|(
specifier|const
name|char
modifier|*
name|name
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
comment|/* _SYS_INTR_H */
end_comment

end_unit

