begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (C) 2001 Benno Rice  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *	$NetBSD: machdep.c,v 1.74.2.1 2000/11/01 16:13:48 tv Exp $  */
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
file|"opt_compat.h"
end_include

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_kstack_pages.h"
end_include

begin_include
include|#
directive|include
file|"opt_platform.h"
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
file|<sys/bio.h>
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
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/imgact.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
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
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscallsubr.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pager.h>
end_include

begin_include
include|#
directive|include
file|<machine/altivec.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__powerpc64__
end_ifndef

begin_include
include|#
directive|include
file|<machine/bat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<machine/fpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/hid.h>
end_include

begin_include
include|#
directive|include
file|<machine/kdb.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/metadata.h>
end_include

begin_include
include|#
directive|include
file|<machine/mmuvar.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/sigframe.h>
end_include

begin_include
include|#
directive|include
file|<machine/spr.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/ofw_machdep.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_subr.h>
end_include

begin_decl_stmt
name|int
name|cold
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_decl_stmt
name|int
name|cacheline_size
init|=
literal|128
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|cacheline_size
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|hw_direct_map
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|ap_pcpu
decl_stmt|;
end_decl_stmt

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
specifier|static
name|char
name|init_kenv
index|[
literal|2048
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|trapframe
name|frame0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|machine
index|[]
init|=
literal|"powerpc"
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
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_machdep
argument_list|,
name|CPU_CACHELINE
argument_list|,
name|cacheline_size
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|cacheline_size
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|uintptr_t
name|powerpc_init
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|long
name|Maxmem
init|=
literal|0
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
name|struct
name|kva_md_info
name|kmi
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
comment|/* 	 * Initialise the decrementer-based clock. 	 */
name|decr_init
argument_list|()
expr_stmt|;
comment|/* 	 * Good {morning,afternoon,evening,night}. 	 */
name|cpu_setup
argument_list|(
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PERFMON
name|perfmon_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"real memory  = %ju (%ju MB)\n"
argument_list|,
name|ptoa
argument_list|(
operator|(
name|uintmax_t
operator|)
name|physmem
argument_list|)
argument_list|,
name|ptoa
argument_list|(
operator|(
name|uintmax_t
operator|)
name|physmem
argument_list|)
operator|/
literal|1048576
argument_list|)
expr_stmt|;
name|realmem
operator|=
name|physmem
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"available KVA = %zu (%zu MB)\n"
argument_list|,
name|virtual_end
operator|-
name|virtual_avail
argument_list|,
operator|(
name|virtual_end
operator|-
name|virtual_avail
operator|)
operator|/
literal|1048576
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
name|vm_paddr_t
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
ifdef|#
directive|ifdef
name|__powerpc64__
name|printf
argument_list|(
literal|"0x%016jx - 0x%016jx, %ju bytes (%ju pages)\n"
argument_list|,
else|#
directive|else
argument|printf(
literal|"0x%09jx - 0x%09jx, %ju bytes (%ju pages)\n"
argument|,
endif|#
directive|endif
argument|(uintmax_t)phys_avail[indx], 			    (uintmax_t)phys_avail[indx +
literal|1
argument|] -
literal|1
argument|, 			    (uintmax_t)size1, (uintmax_t)size1 / PAGE_SIZE); 		} 	}  	vm_ksubmap_init(&kmi);  	printf(
literal|"avail memory = %ju (%ju MB)\n"
argument|, 	    ptoa((uintmax_t)vm_cnt.v_free_count), 	    ptoa((uintmax_t)vm_cnt.v_free_count) /
literal|1048576
argument|);
comment|/* 	 * Set up buffers, so they can be used to read disk labels. 	 */
argument|bufinit(); 	vm_pager_bufferinit(); }  extern vm_offset_t	__startkernel
argument_list|,
argument|__endkernel; extern unsigned char	__bss_start[]; extern unsigned char	__sbss_start[]; extern unsigned char	__sbss_end[]; extern unsigned char	_end[];  void aim_cpu_init(vm_offset_t toc); void booke_cpu_init(void);  uintptr_t powerpc_init(vm_offset_t fdt, vm_offset_t toc, vm_offset_t ofentry, void *mdp,     vm_offset_t mdp_cookie) { 	struct		pcpu *pc; 	struct cpuref	bsp; 	vm_offset_t	startkernel
argument_list|,
argument|endkernel; 	void		*kmdp; 	char		*env;         bool		ofw_bootargs = false;
ifdef|#
directive|ifdef
name|DDB
argument|vm_offset_t ksym_start; 	vm_offset_t ksym_end;
endif|#
directive|endif
argument|kmdp = NULL;
comment|/* First guess at start/end kernel positions */
argument|startkernel = __startkernel; 	endkernel = __endkernel;
comment|/* 	 * If the metadata pointer cookie is not set to the magic value, 	 * the number in mdp should be treated as nonsense. 	 */
argument|if (mdp_cookie !=
literal|0xfb5d104d
argument|) 		mdp = NULL;
ifdef|#
directive|ifdef
name|AIM
comment|/* 	 * If running from an FDT, make sure we are in real mode to avoid 	 * tromping on firmware page tables. Everything in the kernel assumes 	 * 1:1 mappings out of firmware, so this won't break anything not 	 * already broken. This doesn't work if there is live OF, since OF 	 * may internally use non-1:1 mappings. 	 */
argument|if (ofentry ==
literal|0
argument|) 		mtmsr(mfmsr()& ~(PSL_IR | PSL_DR));
endif|#
directive|endif
comment|/* 	 * Parse metadata if present and fetch parameters.  Must be done 	 * before console is inited so cninit gets the right value of 	 * boothowto. 	 */
argument|if (mdp != NULL) { 		preload_metadata = mdp; 		kmdp = preload_search_by_type(
literal|"elf kernel"
argument|); 		if (kmdp != NULL) { 			boothowto = MD_FETCH(kmdp, MODINFOMD_HOWTO, int); 			init_static_kenv(MD_FETCH(kmdp, MODINFOMD_ENVP, char *),
literal|0
argument|); 			endkernel = ulmax(endkernel, MD_FETCH(kmdp, 			    MODINFOMD_KERNEND, vm_offset_t));
ifdef|#
directive|ifdef
name|DDB
argument|ksym_start = MD_FETCH(kmdp, MODINFOMD_SSYM, uintptr_t); 			ksym_end = MD_FETCH(kmdp, MODINFOMD_ESYM, uintptr_t); 			db_fetch_ksymtab(ksym_start, ksym_end);
endif|#
directive|endif
argument|} 	} else {
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BOOKE
argument_list|)
comment|/* 		 * On BOOKE the BSS is already cleared and some variables 		 * initialized.  Do not wipe them out. 		 */
argument|bzero(__sbss_start, __sbss_end - __sbss_start); 		bzero(__bss_start, _end - __bss_start);
endif|#
directive|endif
argument|init_static_kenv(init_kenv, sizeof(init_kenv)); 		ofw_bootargs = true; 	}
comment|/* Store boot environment state */
argument|OF_initial_setup((void *)fdt, NULL, (int (*)(void *))ofentry);
comment|/* 	 * Init params/tunables that can be overridden by the loader 	 */
argument|init_param1();
comment|/* 	 * Start initializing proc0 and thread0. 	 */
argument|proc_linkup0(&proc0,&thread0); 	thread0.td_frame =&frame0;
ifdef|#
directive|ifdef
name|__powerpc64__
asm|__asm __volatile("mr 13,%0" :: "r"(&thread0));
else|#
directive|else
asm|__asm __volatile("mr 2,%0" :: "r"(&thread0));
endif|#
directive|endif
comment|/* 	 * Init mutexes, which we use heavily in PMAP 	 */
argument|mutex_init();
comment|/* 	 * Install the OF client interface 	 */
argument|OF_bootstrap();  	if (ofw_bootargs) 		ofw_parse_bootargs();
comment|/* 	 * Initialize the console before printing anything. 	 */
argument|cninit();
ifdef|#
directive|ifdef
name|AIM
argument|aim_cpu_init(toc);
else|#
directive|else
comment|/* BOOKE */
argument|booke_cpu_init();
comment|/* Make sure the kernel icache is valid before we go too much further */
argument|__syncicache((caddr_t)startkernel, endkernel - startkernel);
endif|#
directive|endif
comment|/* 	 * Choose a platform module so we can get the physical memory map. 	 */
argument|platform_probe_and_attach();
comment|/* 	 * Set up per-cpu data for the BSP now that the platform can tell 	 * us which that is. 	 */
argument|if (platform_smp_get_bsp(&bsp) !=
literal|0
argument|) 		bsp.cr_cpuid =
literal|0
argument|; 	pc =&__pcpu[bsp.cr_cpuid]; 	pcpu_init(pc, bsp.cr_cpuid, sizeof(struct pcpu)); 	pc->pc_curthread =&thread0; 	thread0.td_oncpu = bsp.cr_cpuid; 	pc->pc_cpuid = bsp.cr_cpuid; 	pc->pc_hwref = bsp.cr_hwref; 	pc->pc_pir = mfspr(SPR_PIR);
asm|__asm __volatile("mtsprg 0, %0" :: "r"(pc));
comment|/* 	 * Init KDB 	 */
argument|kdb_init();
comment|/* 	 * Bring up MMU 	 */
argument|pmap_bootstrap(startkernel, endkernel); 	mtmsr(PSL_KERNSET& ~PSL_EE);
comment|/* 	 * Initialize params/tunables that are derived from memsize 	 */
argument|init_param2(physmem);
comment|/* 	 * Grab booted kernel's name 	 */
argument|env = kern_getenv(
literal|"kernelname"
argument|);         if (env != NULL) { 		strlcpy(kernelname, env, sizeof(kernelname)); 		freeenv(env); 	}
comment|/* 	 * Finish setting up thread0. 	 */
argument|thread0.td_pcb = (struct pcb *) 	    ((thread0.td_kstack + thread0.td_kstack_pages * PAGE_SIZE - 	    sizeof(struct pcb))& ~
literal|15UL
argument|); 	bzero((void *)thread0.td_pcb, sizeof(struct pcb)); 	pc->pc_curpcb = thread0.td_pcb;
comment|/* Initialise the message buffer. */
argument|msgbufinit(msgbufp, msgbufsize);
ifdef|#
directive|ifdef
name|KDB
argument|if (boothowto& RB_KDB) 		kdb_enter(KDB_WHY_BOOTFLAGS,
literal|"Boot flags requested debugger"
argument|);
endif|#
directive|endif
argument|return (((uintptr_t)thread0.td_pcb - 	    (sizeof(struct callframe) -
literal|3
argument|*sizeof(register_t)))& ~
literal|15UL
argument|); }
comment|/*  * Flush the D-cache for non-DMA I/O so that the I-cache can  * be made coherent later.  */
argument|void cpu_flush_dcache(void *ptr, size_t len) { 	register_t addr
argument_list|,
argument|off;
comment|/* 	 * Align the address to a cacheline and adjust the length 	 * accordingly. Then round the length to a multiple of the 	 * cacheline for easy looping. 	 */
argument|addr = (uintptr_t)ptr; 	off = addr& (cacheline_size -
literal|1
argument|); 	addr -= off; 	len = roundup2(len + off, cacheline_size);  	while (len>
literal|0
argument|) {
asm|__asm __volatile ("dcbf 0,%0" :: "r"(addr));
asm|__asm __volatile ("sync");
argument|addr += cacheline_size; 		len -= cacheline_size; 	} }  int ptrace_set_pc(struct thread *td, unsigned long addr) { 	struct trapframe *tf;  	tf = td->td_frame; 	tf->srr0 = (register_t)addr;  	return (
literal|0
argument|); }  void spinlock_enter(void) { 	struct thread *td; 	register_t msr;  	td = curthread; 	if (td->td_md.md_spinlock_count ==
literal|0
argument|) {
asm|__asm __volatile("or 2,2,2");
comment|/* Set high thread priority */
argument|msr = intr_disable(); 		td->td_md.md_spinlock_count =
literal|1
argument|; 		td->td_md.md_saved_msr = msr; 	} else 		td->td_md.md_spinlock_count++; 	critical_enter(); }  void spinlock_exit(void) { 	struct thread *td; 	register_t msr;  	td = curthread; 	critical_exit(); 	msr = td->td_md.md_saved_msr; 	td->td_md.md_spinlock_count--; 	if (td->td_md.md_spinlock_count ==
literal|0
argument|) { 		intr_restore(msr);
asm|__asm __volatile("or 6,6,6");
comment|/* Set normal thread priority */
argument|} }
comment|/*  * Simple ddb(4) command/hack to view any SPR on the running CPU.  * Uses a trivial asm function to perform the mfspr, and rewrites the mfspr  * instruction each time.  * XXX: Since it uses code modification, it won't work if the kernel code pages  * are marked RO.  */
argument|extern register_t get_spr(int);
ifdef|#
directive|ifdef
name|DDB
argument|DB_SHOW_COMMAND(spr, db_show_spr) { 	register_t spr; 	volatile uint32_t *p; 	int sprno
argument_list|,
argument|saved_sprno;  	if (!have_addr) 		return;  	saved_sprno = sprno = (intptr_t) addr; 	sprno = ((sprno&
literal|0x3e0
argument|)>>
literal|5
argument|) | ((sprno&
literal|0x1f
argument|)<<
literal|5
argument|); 	p = (uint32_t *)(void *)&get_spr; 	*p = (*p& ~
literal|0x001ff800
argument|) | (sprno<<
literal|11
argument|); 	__syncicache(get_spr, cacheline_size); 	spr = get_spr(sprno);  	db_printf(
literal|"SPR %d(%x): %lx\n"
argument|, saved_sprno, saved_sprno, 	    (unsigned long)spr); }
endif|#
directive|endif
undef|#
directive|undef
name|bzero
argument|void bzero(void *buf, size_t len) { 	caddr_t	p;  	p = buf;  	while (((vm_offset_t) p& (sizeof(u_long) -
literal|1
argument|))&& len) { 		*p++ =
literal|0
argument|; 		len--; 	}  	while (len>= sizeof(u_long) *
literal|8
argument|) { 		*(u_long*) p =
literal|0
argument|; 		*((u_long*) p +
literal|1
argument|) =
literal|0
argument|; 		*((u_long*) p +
literal|2
argument|) =
literal|0
argument|; 		*((u_long*) p +
literal|3
argument|) =
literal|0
argument|; 		len -= sizeof(u_long) *
literal|8
argument|; 		*((u_long*) p +
literal|4
argument|) =
literal|0
argument|; 		*((u_long*) p +
literal|5
argument|) =
literal|0
argument|; 		*((u_long*) p +
literal|6
argument|) =
literal|0
argument|; 		*((u_long*) p +
literal|7
argument|) =
literal|0
argument|; 		p += sizeof(u_long) *
literal|8
argument|; 	}  	while (len>= sizeof(u_long)) { 		*(u_long*) p =
literal|0
argument|; 		len -= sizeof(u_long); 		p += sizeof(u_long); 	}  	while (len) { 		*p++ =
literal|0
argument|; 		len--; 	} }
end_function

end_unit

