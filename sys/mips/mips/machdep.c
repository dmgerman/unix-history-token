begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: machdep.c,v 1.33 1998/09/15 10:58:54 pefo Exp $	*/
end_comment

begin_comment
comment|/* tracked to 1.38 */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department, The Mach Operating System project at  * Carnegie-Mellon University and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)machdep.c	8.3 (Berkeley) 1/12/94  *	Id: machdep.c,v 1.33 1998/09/15 10:58:54 pefo Exp  *	JNPR: machdep.c,v 1.11.2.3 2007/08/29 12:24:49  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_cputype.h"
end_include

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_md.h"
end_include

begin_include
include|#
directive|include
file|"opt_msgbuf.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/msgbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/sched.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pager.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<machine/asm.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/cache.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/hwfunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_define
define|#
directive|define
name|BOOTINFO_DEBUG
value|0
end_define

begin_decl_stmt
name|char
name|machine
index|[]
init|=
literal|"mips"
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|HW_MACHINE
argument_list|,
name|machine
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|machine
argument_list|,
literal|0
argument_list|,
literal|"Machine class"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|char
name|cpu_model
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|HW_MODEL
argument_list|,
name|model
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|cpu_model
argument_list|,
literal|0
argument_list|,
literal|"Machine model"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|cold
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|realmem
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|Maxmem
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cpu_clock
init|=
name|MIPS_DEFAULT_HZ
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|clockrate
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|cpu_clock
argument_list|,
literal|0
argument_list|,
literal|"CPU instruction clock rate"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|clocks_running
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|kstack0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_decl_stmt
name|struct
name|pcpu
name|__pcpu
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|pcpu_boot_stack
index|[
name|KSTACK_PAGES
operator|*
name|PAGE_SIZE
operator|*
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|pcpu
name|pcpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pcpu
modifier|*
name|pcpup
init|=
operator|&
name|pcpu
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|vm_offset_t
name|phys_avail
index|[
name|PHYS_AVAIL_ENTRIES
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|physmem_desc
index|[
name|PHYS_AVAIL_ENTRIES
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|UNIMPLEMENTED
end_ifdef

begin_decl_stmt
name|struct
name|platform
name|platform
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|vm_paddr_t
name|mips_wired_tlb_physmem_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_paddr_t
name|mips_wired_tlb_physmem_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|need_wired_tlb_page_pool
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|cpu_startup
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SYSINIT
argument_list|(
name|cpu
argument_list|,
name|SI_SUB_CPU
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|cpu_startup
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|kva_md_info
name|kmi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cpucfg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Value of processor config register */
end_comment

begin_decl_stmt
name|int
name|num_tlbentries
init|=
literal|64
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of the CPU tlb */
end_comment

begin_decl_stmt
name|int
name|cputype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|MipsException
index|[]
decl_stmt|,
name|MipsExceptionEnd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TLB miss handler address and end */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|MipsTLBMiss
index|[]
decl_stmt|,
name|MipsTLBMissEnd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cache error handler */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|MipsCache
index|[]
decl_stmt|,
name|MipsCacheEnd
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|edata
index|[]
decl_stmt|,
name|end
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|bootdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bootinfo
name|bootinfo
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|cpu_startup
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
if|if
condition|(
name|boothowto
operator|&
name|RB_VERBOSE
condition|)
name|bootverbose
operator|++
expr_stmt|;
name|bootverbose
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"real memory  = %lu (%luK bytes)\n"
argument_list|,
name|ptoa
argument_list|(
name|realmem
argument_list|)
argument_list|,
name|ptoa
argument_list|(
name|realmem
argument_list|)
operator|/
literal|1024
argument_list|)
expr_stmt|;
comment|/* 	 * Display any holes after the first chunk of extended memory. 	 */
if|if
condition|(
name|bootverbose
condition|)
block|{
name|int
name|indx
decl_stmt|;
name|printf
argument_list|(
literal|"Physical memory chunk(s):\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|indx
operator|=
literal|0
init|;
name|phys_avail
index|[
name|indx
operator|+
literal|1
index|]
operator|!=
literal|0
condition|;
name|indx
operator|+=
literal|2
control|)
block|{
name|uintptr_t
name|size1
init|=
name|phys_avail
index|[
name|indx
operator|+
literal|1
index|]
operator|-
name|phys_avail
index|[
name|indx
index|]
decl_stmt|;
name|printf
argument_list|(
literal|"0x%08llx - 0x%08llx, %llu bytes (%llu pages)\n"
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
name|phys_avail
index|[
name|indx
index|]
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
name|phys_avail
index|[
name|indx
operator|+
literal|1
index|]
operator|-
literal|1
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
name|size1
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
name|size1
operator|/
name|PAGE_SIZE
argument_list|)
expr_stmt|;
block|}
block|}
name|vm_ksubmap_init
argument_list|(
operator|&
name|kmi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"avail memory = %lu (%luMB)\n"
argument_list|,
name|ptoa
argument_list|(
name|cnt
operator|.
name|v_free_count
argument_list|)
argument_list|,
name|ptoa
argument_list|(
name|cnt
operator|.
name|v_free_count
argument_list|)
operator|/
literal|1048576
argument_list|)
expr_stmt|;
name|cpu_init_interrupts
argument_list|()
expr_stmt|;
comment|/* 	 * Set up buffers, so they can be used to read disk labels. 	 */
name|bufinit
argument_list|()
expr_stmt|;
name|vm_pager_bufferinit
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Shutdown the CPU as much as possible  */
end_comment

begin_function
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
block|{
name|platform_reset
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Flush the D-cache for non-DMA I/O so that the I-cache can  * be made coherent later.  */
end_comment

begin_function
name|void
name|cpu_flush_dcache
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
comment|/* TBD */
block|}
end_function

begin_comment
comment|/* Get current clock frequency for the given cpu id. */
end_comment

begin_function
name|int
name|cpu_est_clockrate
parameter_list|(
name|int
name|cpu_id
parameter_list|,
name|uint64_t
modifier|*
name|rate
parameter_list|)
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Shutdown the CPU as much as possible  */
end_comment

begin_function
name|void
name|cpu_halt
parameter_list|(
name|void
parameter_list|)
block|{
for|for
control|(
init|;
condition|;
control|)
empty_stmt|;
block|}
end_function

begin_expr_stmt
name|SYSCTL_STRUCT
argument_list|(
name|_machdep
argument_list|,
name|CPU_BOOTINFO
argument_list|,
name|bootinfo
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|bootinfo
argument_list|,
name|bootinfo
argument_list|,
literal|"Bootinfo struct: kernel filename, BIOS harddisk geometry, etc"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PORT_TO_JMIPS
end_ifdef

begin_function
specifier|static
name|int
name|sysctl_machdep_adjkerntz
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{ }
end_function

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_machdep
argument_list|,
name|CPU_ADJKERNTZ
argument_list|,
name|adjkerntz
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|adjkerntz
argument_list|,
literal|0
argument_list|,
name|sysctl_machdep_adjkerntz
argument_list|,
literal|"I"
argument_list|,
literal|"Local offset from GMT in seconds"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_machdep
argument_list|,
name|CPU_DISRTCSET
argument_list|,
name|disable_rtc_set
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|disable_rtc_set
argument_list|,
literal|0
argument_list|,
literal|"Disable setting the real time clock to system time"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_machdep
argument_list|,
name|CPU_WALLCLOCK
argument_list|,
name|wall_cmos_clock
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|wall_cmos_clock
argument_list|,
literal|0
argument_list|,
literal|"Wall CMOS clock assumed"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PORT_TO_JMIPS */
end_comment

begin_comment
comment|/*  * Initialize mips and configure to run kernel  */
end_comment

begin_function
name|void
name|mips_proc0_init
parameter_list|(
name|void
parameter_list|)
block|{
name|proc_linkup
argument_list|(
operator|&
name|proc0
argument_list|,
operator|&
name|thread0
argument_list|)
expr_stmt|;
name|thread0
operator|.
name|td_kstack
operator|=
name|kstack0
expr_stmt|;
name|thread0
operator|.
name|td_kstack_pages
operator|=
name|KSTACK_PAGES
operator|-
literal|1
expr_stmt|;
name|thread0
operator|.
name|td_md
operator|.
name|md_realstack
operator|=
name|roundup2
argument_list|(
name|thread0
operator|.
name|td_kstack
argument_list|,
name|PAGE_SIZE
operator|*
literal|2
argument_list|)
expr_stmt|;
comment|/* Initialize pcpu info of cpu-zero */
ifdef|#
directive|ifdef
name|SMP
name|pcpu_init
argument_list|(
operator|&
name|__pcpu
index|[
literal|0
index|]
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|pcpu_init
argument_list|(
name|pcpup
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*  	 * Do not use cpu_thread_alloc to initialize these fields  	 * thread0 is the only thread that has kstack located in KSEG0  	 * while cpu_thread_alloc handles kstack allocated in KSEG2. 	 */
name|thread0
operator|.
name|td_pcb
operator|=
operator|(
expr|struct
name|pcb
operator|*
operator|)
operator|(
name|thread0
operator|.
name|td_md
operator|.
name|md_realstack
operator|+
operator|(
name|thread0
operator|.
name|td_kstack_pages
operator|-
literal|1
operator|)
operator|*
name|PAGE_SIZE
operator|)
operator|-
literal|1
expr_stmt|;
name|thread0
operator|.
name|td_frame
operator|=
operator|&
name|thread0
operator|.
name|td_pcb
operator|->
name|pcb_regs
expr_stmt|;
comment|/* Steal memory for the dynamic per-cpu area. */
name|dpcpu_init
argument_list|(
operator|(
name|void
operator|*
operator|)
name|pmap_steal_memory
argument_list|(
name|DPCPU_SIZE
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * There is no need to initialize md_upte array for thread0 as it's 	 * located in .bss section and should be explicitly zeroed during  	 * kernel initialization. 	 */
name|PCPU_SET
argument_list|(
name|curthread
argument_list|,
operator|&
name|thread0
argument_list|)
expr_stmt|;
name|PCPU_SET
argument_list|(
name|curpcb
argument_list|,
name|thread0
operator|.
name|td_pcb
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_initclocks
parameter_list|(
name|void
parameter_list|)
block|{
name|platform_initclocks
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|struct
name|msgbuf
modifier|*
name|msgbufp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initialize the hardware exception vectors, and the jump table used to  * call locore cache and TLB management functions, based on the kind  * of CPU the kernel is running on.  */
end_comment

begin_function
name|void
name|mips_vector_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * Copy down exception vector code. 	 */
if|if
condition|(
name|MipsTLBMissEnd
operator|-
name|MipsTLBMiss
operator|>
literal|0x80
condition|)
name|panic
argument_list|(
literal|"startup: UTLB code too large"
argument_list|)
expr_stmt|;
if|if
condition|(
name|MipsCacheEnd
operator|-
name|MipsCache
operator|>
literal|0x80
condition|)
name|panic
argument_list|(
literal|"startup: Cache error code too large"
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|MipsTLBMiss
argument_list|,
operator|(
name|void
operator|*
operator|)
name|TLB_MISS_EXC_VEC
argument_list|,
name|MipsTLBMissEnd
operator|-
name|MipsTLBMiss
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TARGET_OCTEON
comment|/* Fake, but sufficient, for the 32-bit with 64-bit hardware addresses  */
name|bcopy
argument_list|(
name|MipsTLBMiss
argument_list|,
operator|(
name|void
operator|*
operator|)
name|XTLB_MISS_EXC_VEC
argument_list|,
name|MipsTLBMissEnd
operator|-
name|MipsTLBMiss
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|bcopy
argument_list|(
name|MipsException
argument_list|,
operator|(
name|void
operator|*
operator|)
name|GEN_EXC_VEC
argument_list|,
name|MipsExceptionEnd
operator|-
name|MipsException
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|MipsCache
argument_list|,
operator|(
name|void
operator|*
operator|)
name|CACHE_ERR_EXC_VEC
argument_list|,
name|MipsCacheEnd
operator|-
name|MipsCache
argument_list|)
expr_stmt|;
comment|/* 	 * Clear out the I and D caches. 	 */
name|mips_icache_sync_all
argument_list|()
expr_stmt|;
name|mips_dcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/*  	 * Mask all interrupts. Each interrupt will be enabled 	 * when handler is installed for it 	 */
name|set_intr_mask
argument_list|(
name|ALL_INT_MASK
argument_list|)
expr_stmt|;
comment|/* Clear BEV in SR so we start handling our own exceptions */
name|mips_cp0_status_write
argument_list|(
name|mips_cp0_status_read
argument_list|()
operator|&
operator|~
name|SR_BOOT_EXC_VEC
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Initialise a struct pcpu.  */
end_comment

begin_function
name|void
name|cpu_pcpu_init
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
if|if
condition|(
name|cpuid
operator|!=
literal|0
condition|)
name|pcpu
operator|->
name|pc_boot_stack
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|pcpu_boot_stack
operator|+
name|cpuid
operator|*
operator|(
name|KSTACK_PAGES
operator|*
name|PAGE_SIZE
operator|)
operator|)
expr_stmt|;
endif|#
directive|endif
name|pcpu
operator|->
name|pc_next_asid
operator|=
literal|1
expr_stmt|;
name|pcpu
operator|->
name|pc_asid_generation
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|int
name|fill_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|dbreg
modifier|*
name|dbregs
parameter_list|)
block|{
comment|/* No debug registers on mips */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|set_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|dbreg
modifier|*
name|dbregs
parameter_list|)
block|{
comment|/* No debug registers on mips */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|void
name|spinlock_enter
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|td
operator|=
name|curthread
expr_stmt|;
if|if
condition|(
name|td
operator|->
name|td_md
operator|.
name|md_spinlock_count
operator|==
literal|0
condition|)
name|td
operator|->
name|td_md
operator|.
name|md_saved_intr
operator|=
name|disableintr
argument_list|()
expr_stmt|;
name|td
operator|->
name|td_md
operator|.
name|md_spinlock_count
operator|++
expr_stmt|;
name|critical_enter
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|spinlock_exit
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|td
operator|=
name|curthread
expr_stmt|;
name|critical_exit
argument_list|()
expr_stmt|;
name|td
operator|->
name|td_md
operator|.
name|md_spinlock_count
operator|--
expr_stmt|;
if|if
condition|(
name|td
operator|->
name|td_md
operator|.
name|md_spinlock_count
operator|==
literal|0
condition|)
name|restoreintr
argument_list|(
name|td
operator|->
name|td_md
operator|.
name|md_saved_intr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|u_int32_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int32_t
name|count
decl_stmt|;
name|mfc0_macro
argument_list|(
name|count
argument_list|,
literal|9
argument_list|)
expr_stmt|;
return|return
operator|(
name|count
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * call platform specific code to halt (until next interrupt) for the idle loop  */
end_comment

begin_function
name|void
name|cpu_idle
parameter_list|(
name|int
name|busy
parameter_list|)
block|{
if|if
condition|(
name|mips_cp0_status_read
argument_list|()
operator|&
name|SR_INT_ENAB
condition|)
asm|__asm __volatile ("wait");
else|else
name|panic
argument_list|(
literal|"ints disabled in idleproc!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|dumpsys
parameter_list|(
name|struct
name|dumperinfo
modifier|*
name|di
name|__unused
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Kernel dumps not implemented on this architecture\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|cpu_idle_wakeup
parameter_list|(
name|int
name|cpu
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|is_physical_memory
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|physmem_desc
index|[
name|i
operator|+
literal|1
index|]
operator|!=
literal|0
condition|;
name|i
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|addr
operator|>=
name|physmem_desc
index|[
name|i
index|]
operator|&&
name|addr
operator|<
name|physmem_desc
index|[
name|i
operator|+
literal|1
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

