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

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

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

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/apicvar.h>
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
name|mp_naps
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
name|struct
name|pcb
name|stoppcbs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|smp_tlb_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IPI handlers */
end_comment

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|invltlb
argument_list|)
decl_stmt|,
comment|/* TLB shootdowns - global */
name|IDTVEC
argument_list|(
name|invlpg
argument_list|)
decl_stmt|,
comment|/* TLB shootdowns - 1 page */
name|IDTVEC
argument_list|(
name|invlrng
argument_list|)
decl_stmt|,
comment|/* TLB shootdowns - page range */
name|IDTVEC
argument_list|(
name|hardclock
argument_list|)
decl_stmt|,
comment|/* Forward hardclock() */
name|IDTVEC
argument_list|(
name|statclock
argument_list|)
decl_stmt|,
comment|/* Forward statclock() */
name|IDTVEC
argument_list|(
name|cpuast
argument_list|)
decl_stmt|,
comment|/* Additional software trap on other cpu */
name|IDTVEC
argument_list|(
name|cpustop
argument_list|)
decl_stmt|,
comment|/* CPU stops& waits to be restarted */
name|IDTVEC
argument_list|(
name|rendezvous
argument_list|)
decl_stmt|,
comment|/* handle CPU rendezvous */
name|IDTVEC
argument_list|(
name|lazypmap
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* handle lazy pmap release */
end_comment

begin_comment
comment|/* functions in mp_machdep.c */
end_comment

begin_function_decl
name|void
name|cpu_add
parameter_list|(
name|u_int
name|apic_id
parameter_list|,
name|char
name|boot_cpu
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
name|clockframe
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
name|clockframe
name|frame
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
name|int
name|mp_grab_cpu_hlt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_invlpg
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_masked_invlpg
parameter_list|(
name|u_int
name|mask
parameter_list|,
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_invlpg_range
parameter_list|(
name|vm_offset_t
name|startva
parameter_list|,
name|vm_offset_t
name|endva
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_masked_invlpg_range
parameter_list|(
name|u_int
name|mask
parameter_list|,
name|vm_offset_t
name|startva
parameter_list|,
name|vm_offset_t
name|endva
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
name|smp_masked_invltlb
parameter_list|(
name|u_int
name|mask
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
comment|/* SMP */
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

