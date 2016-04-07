begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Svatopluk Kraus  * Copyright (c) 2015-2016 Michal Meloun  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_enum
enum|enum
name|intr_map_data_type
block|{
name|INTR_MAP_DATA_ACPI
block|,
name|INTR_MAP_DATA_FDT
block|, }
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_ACPI
end_ifdef

begin_struct
struct|struct
name|intr_map_data_acpi
block|{
name|u_int
name|irq
decl_stmt|;
name|enum
name|intr_polarity
name|pol
decl_stmt|;
name|enum
name|intr_trigger
name|trig
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_struct
struct|struct
name|intr_map_data_fdt
block|{
name|u_int
name|ncells
decl_stmt|;
name|pcell_t
modifier|*
name|cells
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|intr_map_data
block|{
name|enum
name|intr_map_data_type
name|type
decl_stmt|;
union|union
block|{
ifdef|#
directive|ifdef
name|DEV_ACPI
name|struct
name|intr_map_data_acpi
name|acpi
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FDT
name|struct
name|intr_map_data_fdt
name|fdt
decl_stmt|;
endif|#
directive|endif
block|}
union|;
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|INTR_ISRCF_IPI
value|0x01
end_define

begin_comment
comment|/* IPI interrupt */
end_comment

begin_define
define|#
directive|define
name|INTR_ISRCF_PPI
value|0x02
end_define

begin_comment
comment|/* PPI interrupt */
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
name|u_int
name|isrc_irq
decl_stmt|;
comment|/* unique identificator */
name|u_int
name|isrc_flags
decl_stmt|;
name|char
name|isrc_name
index|[
name|INTR_ISRC_NAMELEN
index|]
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
name|void
modifier|*
name|isrc_arg
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Intr interface for PIC. */
end_comment

begin_function_decl
name|int
name|intr_isrc_deregister
parameter_list|(
name|struct
name|intr_irqsrc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_isrc_register
parameter_list|(
name|struct
name|intr_irqsrc
modifier|*
parameter_list|,
name|device_t
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function_decl
name|bool
name|intr_isrc_init_on_cpu
parameter_list|(
name|struct
name|intr_irqsrc
modifier|*
name|isrc
parameter_list|,
name|u_int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|intr_isrc_dispatch
parameter_list|(
name|struct
name|intr_irqsrc
modifier|*
parameter_list|,
name|struct
name|trapframe
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

begin_function_decl
name|int
name|intr_pic_register
parameter_list|(
name|device_t
parameter_list|,
name|intptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_pic_deregister
parameter_list|(
name|device_t
parameter_list|,
name|intptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_pic_claim_root
parameter_list|(
name|device_t
parameter_list|,
name|intptr_t
parameter_list|,
name|intr_irq_filter_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|device_t
name|intr_irq_root_dev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Intr interface for BUS. */
end_comment

begin_function_decl
name|int
name|intr_map_irq
parameter_list|(
name|device_t
parameter_list|,
name|intptr_t
parameter_list|,
name|struct
name|intr_map_data
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_alloc_irq
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_release_irq
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_setup_irq
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|,
name|driver_filter_t
parameter_list|,
name|driver_intr_t
parameter_list|,
name|void
modifier|*
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
name|intr_teardown_irq
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_describe_irq
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
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

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_ACPI
end_ifdef

begin_function_decl
name|u_int
name|intr_acpi_map_irq
parameter_list|(
name|device_t
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|intr_polarity
parameter_list|,
name|enum
name|intr_trigger
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function_decl
name|int
name|intr_bind_irq
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
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

