begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: smp.h,v 1.6 1997/05/05 22:56:37 fsmp Exp $  *  */
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

begin_include
include|#
directive|include
file|"opt_smp.h"
end_include

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
comment|/* SMP&& NCPU */
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
name|void
name|try_mplock
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
name|struct
name|proc
modifier|*
name|SMPcurproc
index|[
name|NCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pcb
modifier|*
name|SMPcurpcb
index|[
name|NCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|SMPruntime
index|[
name|NCPU
index|]
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
name|mpenabled
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
name|int
name|get_isa_apic_irq
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
name|get_isa_apic_mask
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
name|get_eisa_apic_irq
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
name|get_pci_apic_irq
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
name|configure_local_apic
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

begin_comment
comment|/* global data in mpapic.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
modifier|*
name|apic_base
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
name|u_int
modifier|*
name|io_apic_base
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
name|apic_initialize
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

begin_decl_stmt
name|void
name|write_io_apic_mask24
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
name|smp_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|invltlb_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in pmap.c FIXME: belongs in pmap.h??? */
end_comment

begin_decl_stmt
name|void
name|pmap_bootstrap_apics
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
name|pmap_bootstrap2
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* chicken and egg problem... */
end_comment

begin_else
unit|static __inline unsigned cpunumber(void) { 	return (unsigned)ID_TO_CPU((apic_base[APIC_ID]& APIC_ID_MASK)>> 24); }
else|#
directive|else
end_else

begin_comment
comment|/*  * we 'borrow' this info from apic.h  * this will go away soon...  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|cpunumber
parameter_list|(
name|void
parameter_list|)
block|{
return|return
call|(
name|unsigned
call|)
argument_list|(
name|apic_id_to_logical
index|[
operator|(
name|apic_base
index|[
literal|8
index|]
operator|&
literal|0x0f000000
operator|)
operator|>>
literal|24
index|]
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
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

