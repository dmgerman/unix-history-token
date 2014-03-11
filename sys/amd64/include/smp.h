begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
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
file|<x86/apicvar.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_comment
comment|/* global symbols in mpboot.S */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|mptramp_start
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|mptramp_end
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|mptramp_pagetables
decl_stmt|;
end_decl_stmt

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
name|int
name|cpu_apic_ids
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COUNT_IPIS
end_ifdef

begin_decl_stmt
specifier|extern
name|u_long
modifier|*
name|ipi_invltlb_counts
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
modifier|*
name|ipi_invlrng_counts
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
modifier|*
name|ipi_invlpg_counts
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
modifier|*
name|ipi_invlcache_counts
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
modifier|*
name|ipi_rendezvous_counts
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPI handlers */
end_comment

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|invltlb_pcid
argument_list|)
decl_stmt|,
comment|/* TLB shootdowns - global, pcid enabled */
name|IDTVEC
argument_list|(
name|invltlb
argument_list|)
decl_stmt|,
comment|/* TLB shootdowns - global */
name|IDTVEC
argument_list|(
name|invlpg_pcid
argument_list|)
decl_stmt|,
comment|/* TLB shootdowns - 1 page, pcid enabled */
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
name|invlcache
argument_list|)
decl_stmt|,
comment|/* Write back and invalidate cache */
name|IDTVEC
argument_list|(
name|ipi_intr_bitmap_handler
argument_list|)
decl_stmt|,
comment|/* Bitmap based IPIs */
name|IDTVEC
argument_list|(
name|cpustop
argument_list|)
decl_stmt|,
comment|/* CPU stops& waits to be restarted */
name|IDTVEC
argument_list|(
name|cpususpend
argument_list|)
decl_stmt|,
comment|/* CPU suspends& waits to be resumed */
name|IDTVEC
argument_list|(
name|rendezvous
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* handle CPU rendezvous */
end_comment

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

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
name|cpustop_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpususpend_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invltlb_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invltlb_pcid_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invlpg_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invlpg_pcid_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invlrng_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invlcache_handler
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
name|ipi_startup
parameter_list|(
name|int
name|apic_id
parameter_list|,
name|int
name|vector
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
name|ipi_bitmap_handler
parameter_list|(
name|struct
name|trapframe
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_cpu
parameter_list|(
name|int
name|cpu
parameter_list|,
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipi_nmi_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_selected
parameter_list|(
name|cpuset_t
name|cpus
parameter_list|,
name|u_int
name|ipi
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
name|void
name|smp_cache_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_invlpg
parameter_list|(
name|struct
name|pmap
modifier|*
name|pmap
parameter_list|,
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_masked_invlpg
parameter_list|(
name|cpuset_t
name|mask
parameter_list|,
name|struct
name|pmap
modifier|*
name|pmap
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
name|struct
name|pmap
modifier|*
name|pmap
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
name|smp_masked_invlpg_range
parameter_list|(
name|cpuset_t
name|mask
parameter_list|,
name|struct
name|pmap
modifier|*
name|pmap
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
name|struct
name|pmap
modifier|*
name|pmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_masked_invltlb
parameter_list|(
name|cpuset_t
name|mask
parameter_list|,
name|struct
name|pmap
modifier|*
name|pmap
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

