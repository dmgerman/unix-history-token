begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SMP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|I386_CPU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|COMPILING_LINT
argument_list|)
end_if

begin_error
error|#
directive|error
error|SMP not supported with I386_CPU
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|APIC_IO
argument_list|)
end_if

begin_error
error|#
directive|error
error|APIC_IO required for SMP, add "options APIC_IO" to your config file.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP&& !APIC_IO */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
name|defined
argument_list|(
name|APIC_IO
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * For sending values to POST displays.  * XXX FIXME: where does this really belong, isa.h/isa.c perhaps?  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_postcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** XXX currently in mp_machdep.c */
end_comment

begin_define
define|#
directive|define
name|POSTCODE
parameter_list|(
name|X
parameter_list|)
value|current_postcode = (X), \ 			outb(0x80, current_postcode)
end_define

begin_define
define|#
directive|define
name|POSTCODE_LO
parameter_list|(
name|X
parameter_list|)
value|current_postcode&= 0xf0, \ 			current_postcode |= ((X)& 0x0f), \ 			outb(0x80, current_postcode)
end_define

begin_define
define|#
directive|define
name|POSTCODE_HI
parameter_list|(
name|X
parameter_list|)
value|current_postcode&= 0x0f, \ 			current_postcode |= (((X)<< 4)& 0xf0), \ 			outb(0x80, current_postcode)
end_define

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<machine/apic.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/intr_machdep.h>
end_include

begin_comment
comment|/*  * Interprocessor interrupts for SMP.  */
end_comment

begin_define
define|#
directive|define
name|IPI_INVLTLB
value|XINVLTLB_OFFSET
end_define

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|XRENDEZVOUS_OFFSET
end_define

begin_define
define|#
directive|define
name|IPI_AST
value|XCPUAST_OFFSET
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|XCPUSTOP_OFFSET
end_define

begin_define
define|#
directive|define
name|IPI_HARDCLOCK
value|XHARDCLOCK_OFFSET
end_define

begin_define
define|#
directive|define
name|IPI_STATCLOCK
value|XSTATCLOCK_OFFSET
end_define

begin_comment
comment|/* global data in mpboot.s */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bootMP_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions in mpboot.s */
end_comment

begin_function_decl
name|void
name|bootMP
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global data in mp_machdep.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bsp_apic_ready
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mp_naps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mp_nbusses
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mp_napics
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mp_picmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|boot_cpu_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|cpu_apic_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|io_apic_address
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|cpu_apic_versions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
modifier|*
name|io_apic_versions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cpu_num_to_apic_id
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|io_num_to_apic_id
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|apic_id_to_logical
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|APIC_INTMAPSIZE
value|32
end_define

begin_struct
struct|struct
name|apic_intmapinfo
block|{
name|int
name|ioapic
decl_stmt|;
name|int
name|int_pin
decl_stmt|;
specifier|volatile
name|void
modifier|*
name|apic_address
decl_stmt|;
name|int
name|redirindex
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|apic_intmapinfo
name|int_to_apicintpin
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pcb
name|stoppcbs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions in mp_machdep.c */
end_comment

begin_function_decl
name|void
name|i386_mp_probe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|mp_bootaddress
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|isa_apic_mask
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_apic_irq
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_apic_irq
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apic_irq
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|next_apic_irq
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|undirect_isa_irq
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|undirect_pci_irq
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apic_bus_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apic_src_bus_id
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apic_src_bus_irq
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apic_int_type
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apic_trigger
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apic_polarity
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assign_apic_irq
parameter_list|(
name|int
name|apic
parameter_list|,
name|int
name|intpin
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|revoke_apic_irq
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsp_apic_configure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_secondary
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_invltlb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forward_statclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forwarded_statclock
parameter_list|(
name|struct
name|trapframe
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forward_hardclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forwarded_hardclock
parameter_list|(
name|struct
name|trapframe
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_selected
parameter_list|(
name|u_int
name|cpus
parameter_list|,
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_all
parameter_list|(
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_all_but_self
parameter_list|(
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_self
parameter_list|(
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_INTR_REORDER
end_ifdef

begin_function_decl
name|void
name|set_lapic_isrloc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_INTR_REORDER */
end_comment

begin_comment
comment|/* global data in mpapic.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|lapic_t
name|lapic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|ioapic_t
modifier|*
modifier|*
name|ioapic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions in mpapic.c */
end_comment

begin_function_decl
name|void
name|apic_dump
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apic_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imen_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apic_ipi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|selected_apic_ipi
parameter_list|(
name|u_int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|io_apic_setup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|io_apic_setup_intpin
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|io_apic_set_id
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|io_apic_get_id
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext_int_setup
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_apic_timer
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_apic_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_sleep
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|io_apic_read
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|io_apic_write
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP&& !APIC_IO */
end_comment

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
comment|/* _MACHINE_SMP_H_ */
end_comment

end_unit

