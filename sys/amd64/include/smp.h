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

begin_decl_stmt
name|void
name|bootMP
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|i386_mp_probe
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|mp_bootaddress
name|__P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|isa_apic_mask
name|__P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isa_apic_irq
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pci_apic_irq
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|apic_irq
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|next_apic_irq
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|undirect_isa_irq
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|undirect_pci_irq
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|apic_bus_type
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|apic_src_bus_id
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|apic_src_bus_irq
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|apic_int_type
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|apic_trigger
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|apic_polarity
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|assign_apic_irq
name|__P
argument_list|(
operator|(
name|int
name|apic
operator|,
name|int
name|intpin
operator|,
name|int
name|irq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|revoke_apic_irq
name|__P
argument_list|(
operator|(
name|int
name|irq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bsp_apic_configure
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_secondary
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|smp_invltlb
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|forward_statclock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|forwarded_statclock
name|__P
argument_list|(
operator|(
expr|struct
name|trapframe
name|frame
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|forward_hardclock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|forwarded_hardclock
name|__P
argument_list|(
operator|(
expr|struct
name|trapframe
name|frame
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipi_selected
name|__P
argument_list|(
operator|(
name|u_int
name|cpus
operator|,
name|u_int
name|ipi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipi_all
name|__P
argument_list|(
operator|(
name|u_int
name|ipi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipi_all_but_self
name|__P
argument_list|(
operator|(
name|u_int
name|ipi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipi_self
name|__P
argument_list|(
operator|(
name|u_int
name|ipi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_INTR_REORDER
end_ifdef

begin_decl_stmt
name|void
name|set_lapic_isrloc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|apic_dump
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|apic_initialize
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|imen_dump
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|apic_ipi
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|selected_apic_ipi
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|io_apic_setup
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|io_apic_setup_intpin
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|io_apic_set_id
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|io_apic_get_id
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ext_int_setup
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_apic_timer
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|read_apic_timer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|u_sleep
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|io_apic_read
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|io_apic_write
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

