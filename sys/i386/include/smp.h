begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: smp.h,v 1.34 1998/01/01 08:47:12 bde Exp $  *  */
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
name|KERNEL
end_ifdef

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

begin_comment
comment|/* Number of CPUs. */
end_comment

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
name|NCPU
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCPU
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP&& NCPU */
end_comment

begin_comment
comment|/* Number of IO APICs. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|APIC_IO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NAPIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|NAPIC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP&& NAPIC */
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
file|<machine/apic.h>
end_include

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
comment|/* global data in mplock.s */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mp_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|isr_lock
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RECURSIVE_MPINTRLOCK
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int
name|mpintr_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  RECURSIVE_MPINTRLOCK */
end_comment

begin_comment
comment|/* functions in mplock.s */
end_comment

begin_decl_stmt
name|void
name|get_mplock
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
name|rel_mplock
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
name|try_mplock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RECURSIVE_MPINTRLOCK
end_ifdef

begin_decl_stmt
name|void
name|get_mpintrlock
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
name|rel_mpintrlock
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
name|try_mpintrlock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  RECURSIVE_MPINTRLOCK */
end_comment

begin_comment
comment|/* global data in apic_vector.s */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|ivectors
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|stopped_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|started_cpus
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BETTER_CLOCK
end_ifdef

begin_decl_stmt
name|void
name|forward_statclock
name|__P
argument_list|(
operator|(
name|int
name|pscnt
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
name|int
name|pscnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|checkstate_probed_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|checkstate_need_ast
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* global data in apic_ipl.s */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|vec
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|Xintr8254
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|mask8254
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions in apic_ipl.s */
end_comment

begin_decl_stmt
name|void
name|vec8254
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
name|apic_eoi
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
name|mp_ncpus
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
name|io_apic_versions
index|[]
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

begin_decl_stmt
specifier|extern
name|u_int
name|all_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|SMP_ioapic
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions in mp_machdep.c */
end_comment

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
name|int
name|mp_probe
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
name|mp_start
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
name|mp_announce
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
name|isa_apic_pin
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
name|pci_apic_pin
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
name|int
name|stop_cpus
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
name|restart_cpus
name|__P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLE_IOAPICS
argument_list|)
end_if

begin_error
error|#
directive|error
error|MULTIPLE_IOAPICSXXX
end_error

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
specifier|volatile
name|ioapic_t
modifier|*
name|ioapic
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIPLE_IOAPICS */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READY
argument_list|)
end_if

begin_decl_stmt
name|void
name|clr_io_apic_mask24
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_io_apic_mask24
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READY */
end_comment

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

begin_comment
comment|/* global data in init_smp.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|invltlb_ok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smp_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|smp_idle_loops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'private' global data in locore.s */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|cpuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|cpu_lockid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inside_intr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|other_cpus
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
comment|/* SMP || APIC_IO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SMP_H_ */
end_comment

end_unit

