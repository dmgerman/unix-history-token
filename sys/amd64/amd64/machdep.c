begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Terrence R. Lambert.  * Copyright (c) 1982, 1987, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)machdep.c	7.4 (Berkeley) 6/3/91  *	$Id: machdep.c,v 1.93 1994/11/16 00:41:06 davidg Exp $  */
end_comment

begin_include
include|#
directive|include
file|"npx.h"
end_include

begin_include
include|#
directive|include
file|"isa.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
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
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSHM
end_ifdef

begin_include
include|#
directive|include
file|<sys/shm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVMSG
end_ifdef

begin_include
include|#
directive|include
file|<sys/msg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSEM
end_ifdef

begin_include
include|#
directive|include
file|<sys/sem.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
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

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|avail_start
decl_stmt|,
name|avail_end
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"ether.h"
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/npx.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_include
include|#
directive|include
file|<machine/cons.h>
end_include

begin_include
include|#
directive|include
file|<machine/devconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/rtc.h>
end_include

begin_function_decl
specifier|static
name|void
name|identifycpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|initcpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|test_page
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|machine
index|[]
init|=
literal|"i386"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cpu_model
index|[
sizeof|sizeof
argument_list|(
literal|"Cy486DLC"
argument_list|)
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|PANIC_REBOOT_WAIT_TIME
end_ifndef

begin_define
define|#
directive|define
name|PANIC_REBOOT_WAIT_TIME
value|15
end_define

begin_comment
comment|/* default to 15 seconds */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Declare these as initialized data so we can patch them.  */
end_comment

begin_decl_stmt
name|int
name|nswbuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NBUF
end_ifdef

begin_decl_stmt
name|int
name|nbuf
init|=
name|NBUF
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|nbuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BUFPAGES
end_ifdef

begin_decl_stmt
name|int
name|bufpages
init|=
name|BUFPAGES
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|bufpages
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BOUNCE_BUFFERS
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bouncememory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxbkva
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BOUNCEPAGES
end_ifdef

begin_decl_stmt
name|int
name|bouncepages
init|=
name|BOUNCEPAGES
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|bouncepages
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BOUNCE_BUFFERS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|freebufspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msgbufmapped
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set when safe to use msgbuf */
end_comment

begin_decl_stmt
name|int
name|_udatasel
decl_stmt|,
name|_ucodesel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Machine-dependent startup code  */
end_comment

begin_decl_stmt
name|int
name|boothowto
init|=
literal|0
decl_stmt|,
name|bootverbose
init|=
literal|0
decl_stmt|,
name|Maxmem
init|=
literal|0
decl_stmt|,
name|badpages
init|=
literal|0
decl_stmt|,
name|physmem
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dumplo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bootdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|biosmem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|phys_avail
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cpu_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dumpsys
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|buffer_sva
decl_stmt|,
name|buffer_eva
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|clean_sva
decl_stmt|,
name|clean_eva
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|pager_sva
decl_stmt|,
name|pager_eva
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pager_map_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)(&((type *)0)->member))
end_define

begin_function
name|void
name|cpu_startup
parameter_list|()
block|{
specifier|register
name|unsigned
name|i
decl_stmt|;
specifier|register
name|caddr_t
name|v
decl_stmt|;
specifier|extern
name|void
function_decl|(
modifier|*
name|netisrs
index|[
literal|32
index|]
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|vm_offset_t
name|maxaddr
decl_stmt|;
name|vm_size_t
name|size
init|=
literal|0
decl_stmt|;
name|int
name|firstaddr
decl_stmt|;
ifdef|#
directive|ifdef
name|BOUNCE_BUFFERS
name|vm_offset_t
name|minaddr
decl_stmt|;
endif|#
directive|endif
comment|/* BOUNCE_BUFFERS */
if|if
condition|(
name|boothowto
operator|&
name|RB_VERBOSE
condition|)
name|bootverbose
operator|++
expr_stmt|;
comment|/* 	 * Initialize error message buffer (at end of core). 	 */
comment|/* avail_end was pre-decremented in init_386() to compensate */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|btoc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|msgbuf
argument_list|)
argument_list|)
condition|;
name|i
operator|++
control|)
name|pmap_enter
argument_list|(
name|pmap_kernel
argument_list|()
argument_list|,
operator|(
name|vm_offset_t
operator|)
name|msgbufp
argument_list|,
name|avail_end
operator|+
name|i
operator|*
name|NBPG
argument_list|,
name|VM_PROT_ALL
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|msgbufmapped
operator|=
literal|1
expr_stmt|;
comment|/* 	 * Good {morning,afternoon,evening,night}. 	 */
name|printf
argument_list|(
name|version
argument_list|)
expr_stmt|;
name|startrtclock
argument_list|()
expr_stmt|;
name|identifycpu
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"real memory  = %d (%d pages)\n"
argument_list|,
name|ptoa
argument_list|(
name|physmem
argument_list|)
argument_list|,
name|physmem
argument_list|)
expr_stmt|;
if|if
condition|(
name|badpages
condition|)
name|printf
argument_list|(
literal|"bad memory   = %d (%d pages)\n"
argument_list|,
name|ptoa
argument_list|(
name|badpages
argument_list|)
argument_list|,
name|badpages
argument_list|)
expr_stmt|;
comment|/* 	 * Quickly wire in netisrs. 	 */
define|#
directive|define
name|DONET
parameter_list|(
name|isr
parameter_list|,
name|n
parameter_list|)
value|do { extern void isr(void); netisrs[n] = isr; } while(0)
ifdef|#
directive|ifdef
name|INET
if|#
directive|if
name|NETHER
operator|>
literal|0
name|DONET
argument_list|(
name|arpintr
argument_list|,
name|NETISR_ARP
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|DONET
argument_list|(
name|ipintr
argument_list|,
name|NETISR_IP
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NS
name|DONET
argument_list|(
name|nsintr
argument_list|,
name|NETISR_NS
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ISO
name|DONET
argument_list|(
name|clnlintr
argument_list|,
name|NETISR_ISO
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CCITT
name|DONET
argument_list|(
name|ccittintr
argument_list|,
name|NETISR_CCITT
argument_list|)
expr_stmt|;
endif|#
directive|endif
undef|#
directive|undef
name|DONET
comment|/* 	 * Allocate space for system data structures. 	 * The first available kernel virtual address is in "v". 	 * As pages of kernel virtual memory are allocated, "v" is incremented. 	 * As pages of memory are allocated and cleared, 	 * "firstaddr" is incremented. 	 * An index into the kernel page table corresponding to the 	 * virtual memory address maintained in "v" is kept in "mapaddr". 	 */
comment|/* 	 * Make two passes.  The first pass calculates how much memory is 	 * needed and allocates it.  The second pass assigns virtual 	 * addresses to the various data structures. 	 */
name|firstaddr
operator|=
literal|0
expr_stmt|;
name|again
label|:
name|v
operator|=
operator|(
name|caddr_t
operator|)
name|firstaddr
expr_stmt|;
define|#
directive|define
name|valloc
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|num
parameter_list|)
define|\
value|(name) = (type *)v; v = (caddr_t)((name)+(num))
define|#
directive|define
name|valloclim
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|num
parameter_list|,
name|lim
parameter_list|)
define|\
value|(name) = (type *)v; v = (caddr_t)((lim) = ((name)+(num)))
name|valloc
argument_list|(
name|callout
argument_list|,
expr|struct
name|callout
argument_list|,
name|ncallout
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SYSVSHM
name|valloc
argument_list|(
name|shmsegs
argument_list|,
expr|struct
name|shmid_ds
argument_list|,
name|shminfo
operator|.
name|shmmni
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SYSVSEM
name|valloc
argument_list|(
name|sema
argument_list|,
expr|struct
name|semid_ds
argument_list|,
name|seminfo
operator|.
name|semmni
argument_list|)
expr_stmt|;
name|valloc
argument_list|(
name|sem
argument_list|,
expr|struct
name|sem
argument_list|,
name|seminfo
operator|.
name|semmns
argument_list|)
expr_stmt|;
comment|/* This is pretty disgusting! */
name|valloc
argument_list|(
name|semu
argument_list|,
name|int
argument_list|,
operator|(
name|seminfo
operator|.
name|semmnu
operator|*
name|seminfo
operator|.
name|semusz
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SYSVMSG
name|valloc
argument_list|(
name|msgpool
argument_list|,
name|char
argument_list|,
name|msginfo
operator|.
name|msgmax
argument_list|)
expr_stmt|;
name|valloc
argument_list|(
name|msgmaps
argument_list|,
expr|struct
name|msgmap
argument_list|,
name|msginfo
operator|.
name|msgseg
argument_list|)
expr_stmt|;
name|valloc
argument_list|(
name|msghdrs
argument_list|,
expr|struct
name|msg
argument_list|,
name|msginfo
operator|.
name|msgtql
argument_list|)
expr_stmt|;
name|valloc
argument_list|(
name|msqids
argument_list|,
expr|struct
name|msqid_ds
argument_list|,
name|msginfo
operator|.
name|msgmni
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Determine how many buffers to allocate. 	 * Use 20% of memory of memory beyond the first 2MB 	 * Insure a minimum of 16 fs buffers. 	 * We allocate 1/2 as many swap buffer headers as file i/o buffers. 	 */
if|if
condition|(
name|bufpages
operator|==
literal|0
condition|)
name|bufpages
operator|=
operator|(
operator|(
name|physmem
operator|<<
name|PGSHIFT
operator|)
operator|-
literal|2048
operator|*
literal|1024
operator|)
operator|/
name|NBPG
operator|/
literal|6
expr_stmt|;
if|if
condition|(
name|bufpages
operator|<
literal|64
condition|)
name|bufpages
operator|=
literal|64
expr_stmt|;
comment|/* 	 * We must still limit the maximum number of buffers to be no 	 * more than 750 because we'll run out of kernel VM otherwise. 	 */
name|bufpages
operator|=
name|min
argument_list|(
name|bufpages
argument_list|,
literal|1500
argument_list|)
expr_stmt|;
if|if
condition|(
name|nbuf
operator|==
literal|0
condition|)
block|{
name|nbuf
operator|=
name|bufpages
operator|/
literal|2
expr_stmt|;
if|if
condition|(
name|nbuf
operator|<
literal|32
condition|)
name|nbuf
operator|=
literal|32
expr_stmt|;
block|}
name|freebufspace
operator|=
name|bufpages
operator|*
name|NBPG
expr_stmt|;
if|if
condition|(
name|nswbuf
operator|==
literal|0
condition|)
block|{
name|nswbuf
operator|=
operator|(
name|nbuf
operator|/
literal|2
operator|)
operator|&
operator|~
literal|1
expr_stmt|;
comment|/* force even */
if|if
condition|(
name|nswbuf
operator|>
literal|64
condition|)
name|nswbuf
operator|=
literal|64
expr_stmt|;
comment|/* sanity */
block|}
name|valloc
argument_list|(
name|swbuf
argument_list|,
expr|struct
name|buf
argument_list|,
name|nswbuf
argument_list|)
expr_stmt|;
name|valloc
argument_list|(
name|buf
argument_list|,
expr|struct
name|buf
argument_list|,
name|nbuf
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BOUNCE_BUFFERS
comment|/* 	 * If there is more than 16MB of memory, allocate some bounce buffers 	 */
if|if
condition|(
name|Maxmem
operator|>
literal|4096
condition|)
block|{
if|if
condition|(
name|bouncepages
operator|==
literal|0
condition|)
name|bouncepages
operator|=
literal|96
expr_stmt|;
comment|/* largest physio size + extra */
name|v
operator|=
call|(
name|caddr_t
call|)
argument_list|(
call|(
name|vm_offset_t
call|)
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|v
operator|+
name|PAGE_SIZE
operator|-
literal|1
argument_list|)
operator|&
operator|~
operator|(
name|PAGE_SIZE
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
name|valloc
argument_list|(
name|bouncememory
argument_list|,
name|char
argument_list|,
name|bouncepages
operator|*
name|PAGE_SIZE
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* 	 * End of first pass, size has been calculated so allocate memory 	 */
if|if
condition|(
name|firstaddr
operator|==
literal|0
condition|)
block|{
name|size
operator|=
call|(
name|vm_size_t
call|)
argument_list|(
name|v
operator|-
name|firstaddr
argument_list|)
expr_stmt|;
name|firstaddr
operator|=
operator|(
name|int
operator|)
name|kmem_alloc
argument_list|(
name|kernel_map
argument_list|,
name|round_page
argument_list|(
name|size
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|firstaddr
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"startup: no room for tables"
argument_list|)
expr_stmt|;
goto|goto
name|again
goto|;
block|}
comment|/* 	 * End of second pass, addresses have been assigned 	 */
if|if
condition|(
call|(
name|vm_size_t
call|)
argument_list|(
name|v
operator|-
name|firstaddr
argument_list|)
operator|!=
name|size
condition|)
name|panic
argument_list|(
literal|"startup: table size inconsistency"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BOUNCE_BUFFERS
name|clean_map
operator|=
name|kmem_suballoc
argument_list|(
name|kernel_map
argument_list|,
operator|&
name|clean_sva
argument_list|,
operator|&
name|clean_eva
argument_list|,
operator|(
name|nbuf
operator|*
name|MAXBSIZE
operator|)
operator|+
operator|(
name|nswbuf
operator|*
name|MAXPHYS
operator|)
operator|+
name|maxbkva
operator|+
name|pager_map_size
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|io_map
operator|=
name|kmem_suballoc
argument_list|(
name|clean_map
argument_list|,
operator|&
name|minaddr
argument_list|,
operator|&
name|maxaddr
argument_list|,
name|maxbkva
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
else|#
directive|else
name|clean_map
operator|=
name|kmem_suballoc
argument_list|(
name|kernel_map
argument_list|,
operator|&
name|clean_sva
argument_list|,
operator|&
name|clean_eva
argument_list|,
operator|(
name|nbuf
operator|*
name|MAXBSIZE
operator|)
operator|+
operator|(
name|nswbuf
operator|*
name|MAXPHYS
operator|)
operator|+
name|pager_map_size
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|buffer_map
operator|=
name|kmem_suballoc
argument_list|(
name|clean_map
argument_list|,
operator|&
name|buffer_sva
argument_list|,
operator|&
name|buffer_eva
argument_list|,
operator|(
name|nbuf
operator|*
name|MAXBSIZE
operator|)
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|pager_map
operator|=
name|kmem_suballoc
argument_list|(
name|clean_map
argument_list|,
operator|&
name|pager_sva
argument_list|,
operator|&
name|pager_eva
argument_list|,
operator|(
name|nswbuf
operator|*
name|MAXPHYS
operator|)
operator|+
name|pager_map_size
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
comment|/* 	 * Finally, allocate mbuf pool.  Since mclrefcnt is an off-size 	 * we use the more space efficient malloc in place of kmem_alloc. 	 */
name|mclrefcnt
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|NMBCLUSTERS
operator|+
name|CLBYTES
operator|/
name|MCLBYTES
argument_list|,
name|M_MBUF
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|mclrefcnt
argument_list|,
name|NMBCLUSTERS
operator|+
name|CLBYTES
operator|/
name|MCLBYTES
argument_list|)
expr_stmt|;
name|mb_map
operator|=
name|kmem_suballoc
argument_list|(
name|kmem_map
argument_list|,
operator|(
name|vm_offset_t
operator|*
operator|)
operator|&
name|mbutl
argument_list|,
operator|&
name|maxaddr
argument_list|,
name|VM_MBUF_SIZE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
comment|/* 	 * Initialize callouts 	 */
name|callfree
operator|=
name|callout
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|ncallout
condition|;
name|i
operator|++
control|)
name|callout
index|[
name|i
operator|-
literal|1
index|]
operator|.
name|c_next
operator|=
operator|&
name|callout
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|boothowto
operator|&
name|RB_CONFIG
condition|)
name|userconfig
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"avail memory = %d (%d pages)\n"
argument_list|,
name|ptoa
argument_list|(
name|cnt
operator|.
name|v_free_count
argument_list|)
argument_list|,
name|cnt
operator|.
name|v_free_count
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"using %d buffers containing %d bytes of memory\n"
argument_list|,
name|nbuf
argument_list|,
name|bufpages
operator|*
name|CLBYTES
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BOUNCE_BUFFERS
comment|/* 	 * init bounce buffers 	 */
name|vm_bounce_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Set up CPU-specific registers, cache, etc. 	 */
name|initcpu
argument_list|()
expr_stmt|;
comment|/* 	 * Set up buffers, so they can be used to read disk labels. 	 */
name|bufinit
argument_list|()
expr_stmt|;
name|vm_pager_bufferinit
argument_list|()
expr_stmt|;
comment|/* 	 * Configure the system. 	 */
name|configure
argument_list|()
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
block|{
name|printf
argument_list|(
literal|"BIOS Geometries:"
argument_list|,
argument|for (i=
literal|0
argument|; i< N_BIOS_GEOM; i++) 			printf(
literal|" %x:%x\n"
argument|, i, bootinfo.bios_geom[i]); 		printf(
literal|" %d accounted for\n"
argument|,bootinfo.n_bios_used); 	} }   struct cpu_nameclass i386_cpus[] = { 	{
literal|"Intel 80286"
argument_list|,
argument|CPUCLASS_286 }
argument_list|,
comment|/* CPU_286   */
argument|{
literal|"i386SX"
argument_list|,
argument|CPUCLASS_386 }
argument_list|,
comment|/* CPU_386SX */
argument|{
literal|"i386DX"
argument_list|,
argument|CPUCLASS_386 }
argument_list|,
comment|/* CPU_386   */
argument|{
literal|"i486SX"
argument_list|,
argument|CPUCLASS_486 }
argument_list|,
comment|/* CPU_486SX */
argument|{
literal|"i486DX"
argument_list|,
argument|CPUCLASS_486 }
argument_list|,
comment|/* CPU_486   */
argument|{
literal|"Pentium"
argument_list|,
argument|CPUCLASS_586 }
argument_list|,
comment|/* CPU_586   */
argument|{
literal|"Cy486DLC"
argument_list|,
argument|CPUCLASS_486 }
argument_list|,
comment|/* CPU_486DLC */
argument|};  static void identifycpu() { 	extern u_long cpu_id; 	extern char cpu_vendor[]; 	printf(
literal|"CPU: "
argument|); 	if (cpu>=
literal|0
argument|&& cpu< (sizeof i386_cpus/sizeof(struct cpu_nameclass))) { 		printf(
literal|"%s"
argument|, i386_cpus[cpu].cpu_name); 		cpu_class = i386_cpus[cpu].cpu_class; 		strncpy(cpu_model, i386_cpus[cpu].cpu_name, sizeof cpu_model); 	} else { 		printf(
literal|"unknown cpu type %d\n"
argument|, cpu); 		panic(
literal|"startup: bad cpu id"
argument|); 	} 	printf(
literal|" ("
argument|); 	switch(cpu_class) { 	case CPUCLASS_286: 		printf(
literal|"286"
argument|); 		break; 	case CPUCLASS_386: 		printf(
literal|"386"
argument|); 		break; 	case CPUCLASS_486: 		printf(
literal|"486"
argument|); 		break; 	case CPUCLASS_586: 		printf(
literal|"Pentium"
argument|); 		break; 	default: 		printf(
literal|"unknown"
argument|);
comment|/* will panic below... */
argument|} 	printf(
literal|"-class CPU)"
argument|);
ifdef|#
directive|ifdef
name|I586_CPU
argument|if(cpu_class == CPUCLASS_586) { 		calibrate_cyclecounter(); 		printf(
literal|" %d MHz"
argument|, pentium_mhz); 	}
endif|#
directive|endif
argument|if(cpu_id) 		printf(
literal|"  Id = 0x%lx"
argument|,cpu_id); 	if(*cpu_vendor) 		printf(
literal|"  Origin = \"%s\""
argument|,cpu_vendor); 	printf(
literal|"\n"
argument|);
comment|/* cpu speed would be nice, but how? */
comment|/* 	 * Now that we have told the user what they have, 	 * let them know if that machine type isn't configured. 	 */
argument|switch (cpu_class) { 	case CPUCLASS_286:
comment|/* a 286 should not make it this far, anyway */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I386_CPU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I486_CPU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I586_CPU
argument_list|)
error|#
directive|error
error|This kernel is not configured for one of the supported CPUs
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I386_CPU
argument_list|)
argument|case CPUCLASS_386:
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I486_CPU
argument_list|)
argument|case CPUCLASS_486:
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I586_CPU
argument_list|)
argument|case CPUCLASS_586:
endif|#
directive|endif
argument|panic(
literal|"CPU class not configured"
argument|); 	default: 		break; 	} }
ifdef|#
directive|ifdef
name|PGINPROF
comment|/*  * Return the difference (in microseconds)  * between the  current time and a previous  * time as represented  by the arguments.  * If there is a pending clock interrupt  * which has not been serviced due to high  * ipl, return error code.  */
comment|/*ARGSUSED*/
argument|vmtime(otime, olbolt, oicr) 	register int otime
argument_list|,
argument|olbolt
argument_list|,
argument|oicr; {  	return (((time.tv_sec-otime)*
literal|60
argument|+ lbolt-olbolt)*
literal|16667
argument|); }
endif|#
directive|endif
argument|extern int kstack[];
comment|/*  * Send an interrupt to process.  *  * Stack is set up to allow sigcode stored  * in u. to call routine, followed by kcall  * to sigreturn routine below.  After sigreturn  * resets the signal mask, the stack, and the  * frame pointer, it returns to the user  * specified pc, psl.  */
argument|void sendsig(catcher, sig, mask, code) 	sig_t catcher; 	int sig
argument_list|,
argument|mask; 	unsigned code; { 	register struct proc *p = curproc; 	register int *regs; 	register struct sigframe *fp; 	struct sigacts *psp = p->p_sigacts; 	int oonstack;  	regs = p->p_md.md_regs;         oonstack = psp->ps_sigstk.ss_flags& SA_ONSTACK;
comment|/* 	 * Allocate and validate space for the signal handler 	 * context. Note that if the stack is in P0 space, the 	 * call to grow() is a nop, and the useracc() check 	 * will fail if the process has not already allocated 	 * the space with a `brk'. 	 */
argument|if ((psp->ps_flags& SAS_ALTSTACK)&& 	    (psp->ps_sigstk.ss_flags& SA_ONSTACK) ==
literal|0
argument|&& 	    (psp->ps_sigonstack& sigmask(sig))) { 		fp = (struct sigframe *)(psp->ps_sigstk.ss_base + 		    psp->ps_sigstk.ss_size - sizeof(struct sigframe)); 		psp->ps_sigstk.ss_flags |= SA_ONSTACK; 	} else { 		fp = (struct sigframe *)(regs[tESP] 			- sizeof(struct sigframe)); 	}
comment|/* 	 * grow() will return FALSE if the fp will not fit inside the stack 	 *	and the stack can not be grown. useracc will return FALSE 	 *	if access is denied. 	 */
argument|if ((grow(p, (int)fp) == FALSE) || 	    (useracc((caddr_t)fp, sizeof (struct sigframe), B_WRITE) == FALSE)) {
comment|/* 		 * Process has trashed its stack; give it an illegal 		 * instruction to halt it in its tracks. 		 */
argument|SIGACTION(p, SIGILL) = SIG_DFL; 		sig = sigmask(SIGILL); 		p->p_sigignore&= ~sig; 		p->p_sigcatch&= ~sig; 		p->p_sigmask&= ~sig; 		psignal(p, SIGILL); 		return; 	}
comment|/*  	 * Build the argument list for the signal handler. 	 */
argument|if (p->p_sysent->sv_sigtbl) { 		if (sig< p->p_sysent->sv_sigsize) 			sig = p->p_sysent->sv_sigtbl[sig]; 		else 			sig = p->p_sysent->sv_sigsize +
literal|1
argument|; 	} 	fp->sf_signum = sig; 	fp->sf_code = code; 	fp->sf_scp =&fp->sf_sc; 	fp->sf_addr = (char *) regs[tERR]; 	fp->sf_handler = catcher;
comment|/* save scratch registers */
argument|fp->sf_sc.sc_eax = regs[tEAX]; 	fp->sf_sc.sc_ebx = regs[tEBX]; 	fp->sf_sc.sc_ecx = regs[tECX]; 	fp->sf_sc.sc_edx = regs[tEDX]; 	fp->sf_sc.sc_esi = regs[tESI]; 	fp->sf_sc.sc_edi = regs[tEDI]; 	fp->sf_sc.sc_cs = regs[tCS]; 	fp->sf_sc.sc_ds = regs[tDS]; 	fp->sf_sc.sc_ss = regs[tSS]; 	fp->sf_sc.sc_es = regs[tES]; 	fp->sf_sc.sc_isp = regs[tISP];
comment|/* 	 * Build the signal context to be used by sigreturn. 	 */
argument|fp->sf_sc.sc_onstack = oonstack; 	fp->sf_sc.sc_mask = mask; 	fp->sf_sc.sc_sp = regs[tESP]; 	fp->sf_sc.sc_fp = regs[tEBP]; 	fp->sf_sc.sc_pc = regs[tEIP]; 	fp->sf_sc.sc_ps = regs[tEFLAGS]; 	regs[tESP] = (int)fp; 	regs[tEIP] = (int)((struct pcb *)kstack)->pcb_sigc; 	regs[tEFLAGS]&= ~PSL_VM; 	regs[tCS] = _ucodesel; 	regs[tDS] = _udatasel; 	regs[tES] = _udatasel; 	regs[tSS] = _udatasel; }
comment|/*  * System call to cleanup state after a signal  * has been taken.  Reset signal mask and  * stack state from context left by sendsig (above).  * Return to previous pc and psl as specified by  * context left by sendsig. Check carefully to  * make sure that the user has not modified the  * psl to gain improper privileges or to cause  * a machine fault.  */
argument|struct sigreturn_args { 	struct sigcontext *sigcntxp; };  int sigreturn(p, uap, retval) 	struct proc *p; 	struct sigreturn_args *uap; 	int *retval; { 	register struct sigcontext *scp; 	register struct sigframe *fp; 	register int *regs = p->p_md.md_regs; 	int eflags;
comment|/* 	 * (XXX old comment) regs[tESP] points to the return address. 	 * The user scp pointer is above that. 	 * The return address is faked in the signal trampoline code 	 * for consistency. 	 */
argument|scp = uap->sigcntxp; 	fp = (struct sigframe *) 	     ((caddr_t)scp - offsetof(struct sigframe, sf_sc));  	if (useracc((caddr_t)fp, sizeof (*fp),
literal|0
argument|) ==
literal|0
argument|) 		return(EINVAL);  	eflags = scp->sc_ps; 	if ((eflags& PSL_USERCLR) !=
literal|0
argument||| 	    (eflags& PSL_USERSET) != PSL_USERSET || 	    (eflags& PSL_IOPL)< (regs[tEFLAGS]& PSL_IOPL)) {
ifdef|#
directive|ifdef
name|DEBUG
argument|printf(
literal|"sigreturn:  eflags=0x%x\n"
argument|, eflags);
endif|#
directive|endif
argument|return(EINVAL); 	}
comment|/* 	 * Sanity check the user's selectors and error if they 	 * are suspect. 	 */
define|#
directive|define
name|max_ldt_sel
parameter_list|(
name|pcb
parameter_list|)
define|\
value|((pcb)->pcb_ldt ? (pcb)->pcb_ldt_len : (sizeof(ldt) / sizeof(ldt[0])))
define|#
directive|define
name|valid_ldt_sel
parameter_list|(
name|sel
parameter_list|)
define|\
value|(ISLDT(sel)&& ISPL(sel) == SEL_UPL&& \ 	 IDXSEL(sel)< max_ldt_sel(&p->p_addr->u_pcb))
define|#
directive|define
name|null_sel
parameter_list|(
name|sel
parameter_list|)
define|\
value|(!ISLDT(sel)&& IDXSEL(sel) == 0)
argument|if (((scp->sc_cs&
literal|0xffff
argument|) != _ucodesel&& !valid_ldt_sel(scp->sc_cs)) || 	    ((scp->sc_ss&
literal|0xffff
argument|) != _udatasel&& !valid_ldt_sel(scp->sc_ss)) || 	    ((scp->sc_ds&
literal|0xffff
argument|) != _udatasel&& !valid_ldt_sel(scp->sc_ds)&& 	     !null_sel(scp->sc_ds)) || 	    ((scp->sc_es&
literal|0xffff
argument|) != _udatasel&& !valid_ldt_sel(scp->sc_es)&& 	     !null_sel(scp->sc_es))) {
ifdef|#
directive|ifdef
name|DEBUG
argument|printf(
literal|"sigreturn:  cs=0x%x ss=0x%x ds=0x%x es=0x%x\n"
argument|, 			scp->sc_cs, scp->sc_ss, scp->sc_ds, scp->sc_es);
endif|#
directive|endif
argument|trapsignal(p, SIGBUS, T_PROTFLT); 		return(EINVAL); 	}
undef|#
directive|undef
name|max_ldt_sel
undef|#
directive|undef
name|valid_ldt_sel
undef|#
directive|undef
name|null_sel
comment|/* restore scratch registers */
argument|regs[tEAX] = scp->sc_eax; 	regs[tEBX] = scp->sc_ebx; 	regs[tECX] = scp->sc_ecx; 	regs[tEDX] = scp->sc_edx; 	regs[tESI] = scp->sc_esi; 	regs[tEDI] = scp->sc_edi; 	regs[tCS] = scp->sc_cs; 	regs[tDS] = scp->sc_ds; 	regs[tES] = scp->sc_es; 	regs[tSS] = scp->sc_ss; 	regs[tISP] = scp->sc_isp;  	if (useracc((caddr_t)scp, sizeof (*scp),
literal|0
argument|) ==
literal|0
argument|) 		return(EINVAL);  	if (scp->sc_onstack&
literal|01
argument|) 		p->p_sigacts->ps_sigstk.ss_flags |= SA_ONSTACK; 	else 		p->p_sigacts->ps_sigstk.ss_flags&= ~SA_ONSTACK; 	p->p_sigmask = scp->sc_mask&~ 	    (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP)); 	regs[tEBP] = scp->sc_fp; 	regs[tESP] = scp->sc_sp; 	regs[tEIP] = scp->sc_pc; 	regs[tEFLAGS] = eflags; 	return(EJUSTRETURN); }
comment|/*  * a simple function to make the system panic (and dump a vmcore)  * in a predictable fashion  */
argument|void diediedie() { 	panic(
literal|"because you said to!"
argument|); }  int	waittime = -
literal|1
argument|; struct pcb dumppcb;  __dead void boot(arghowto) 	int arghowto; { 	register long dummy;
comment|/* r12 is reserved */
argument|register int howto;
comment|/* r11 == how to boot */
argument|register int devtype;
comment|/* r10 == major of root dev */
argument|extern int cold;  	if (cold) { 		printf(
literal|"hit reset please"
argument|); 		for(;;); 	} 	howto = arghowto; 	if ((howto&RB_NOSYNC) ==
literal|0
argument|&& waittime<
literal|0
argument|) { 		register struct buf *bp; 		int iter
argument_list|,
argument|nbusy;  		waittime =
literal|0
argument|; 		printf(
literal|"\nsyncing disks... "
argument|);
comment|/* 		 * Release inodes held by texts before update. 		 */
argument|if (panicstr ==
literal|0
argument|) 			vnode_pager_umount(NULL); 		sync(curproc, NULL, NULL);  		for (iter =
literal|0
argument|; iter<
literal|20
argument|; iter++) { 			nbusy =
literal|0
argument|; 			for (bp =&buf[nbuf]; --bp>= buf; ) 				if ((bp->b_flags& (B_BUSY|B_INVAL)) == B_BUSY) 					nbusy++; 			if (nbusy ==
literal|0
argument|) 				break; 			printf(
literal|"%d "
argument|, nbusy); 			DELAY(
literal|40000
argument|* iter); 		} 		if (nbusy) {
comment|/* 			 * Failed to sync all blocks. Indicate this and don't 			 * unmount filesystems (thus forcing an fsck on reboot). 			 */
argument|printf(
literal|"giving up\n"
argument|); 		} else { 			printf(
literal|"done\n"
argument|);
comment|/* 			 * Unmount filesystems 			 */
argument|if (panicstr ==
literal|0
argument|) 				vfs_unmountall(); 		} 		DELAY(
literal|100000
argument|);
comment|/* wait for console output to finish */
argument|} 	splhigh(); 	devtype = major(rootdev); 	if (howto&RB_HALT) { 		printf(
literal|"\n"
argument|); 		printf(
literal|"The operating system has halted.\n"
argument|); 		printf(
literal|"Please press any key to reboot.\n\n"
argument|); 		cngetc(); 	} else { 		if (howto& RB_DUMP) { 			savectx(&dumppcb,
literal|0
argument|); 			dumppcb.pcb_ptd = rcr3(); 			dumpsys();	  			if (PANIC_REBOOT_WAIT_TIME !=
literal|0
argument|) { 				if (PANIC_REBOOT_WAIT_TIME != -
literal|1
argument|) { 					int loop; 					printf(
literal|"Automatic reboot in %d seconds - press a key on the console to abort\n"
argument|, 						PANIC_REBOOT_WAIT_TIME); 					for (loop = PANIC_REBOOT_WAIT_TIME; loop>
literal|0
argument|; --loop) { 						DELAY(
literal|1000
argument|*
literal|1000
argument|);
comment|/* one second */
argument|if (cncheckc())
comment|/* Did user type a key? */
argument|break; 					} 					if (!loop) 						goto die; 				} 			} else {
comment|/* zero time specified - reboot NOW */
argument|goto die; 			} 			printf(
literal|"--> Press a key on the console to reboot<--\n"
argument|); 			cngetc(); 		} 	}
ifdef|#
directive|ifdef
name|lint
argument|dummy =
literal|0
argument|; dummy = dummy; 	printf(
literal|"howto %d, devtype %d\n"
argument|, arghowto, devtype);
endif|#
directive|endif
argument|die: 	printf(
literal|"Rebooting...\n"
argument|); 	DELAY(
literal|1000000
argument|);
comment|/* wait 1 sec for printf's to complete and be read */
argument|cpu_reset(); 	for(;;) ;
comment|/* NOTREACHED */
argument|}  unsigned long	dumpmag =
literal|0x8fca0101UL
argument|;
comment|/* magic number for savecore */
argument|int		dumpsize =
literal|0
argument|;
comment|/* also for savecore */
ifdef|#
directive|ifdef
name|DODUMP
argument|int		dodump =
literal|1
argument|;
else|#
directive|else
argument|int		dodump =
literal|0
argument|;
endif|#
directive|endif
comment|/*  * Doadump comes here after turning off memory management and  * getting on the dump stack, either when called above, or by  * the auto-restart code.  */
argument|void dumpsys() {  	if (!dodump) 		return; 	if (dumpdev == NODEV) 		return; 	if ((minor(dumpdev)&
literal|07
argument|) !=
literal|1
argument|) 		return; 	dumpsize = Maxmem; 	printf(
literal|"\ndumping to dev %lx, offset %ld\n"
argument|, dumpdev, dumplo); 	printf(
literal|"dump "
argument|); 	switch ((*bdevsw[major(dumpdev)].d_dump)(dumpdev)) {  	case ENXIO: 		printf(
literal|"device bad\n"
argument|); 		break;  	case EFAULT: 		printf(
literal|"device not ready\n"
argument|); 		break;  	case EINVAL: 		printf(
literal|"area improper\n"
argument|); 		break;  	case EIO: 		printf(
literal|"i/o error\n"
argument|); 		break;  	case EINTR: 		printf(
literal|"aborted from console\n"
argument|); 		break;  	default: 		printf(
literal|"succeeded\n"
argument|); 		break; 	} }  static void initcpu() { }
comment|/*  * Clear registers on exec  */
argument|void setregs(p, entry, stack) 	struct proc *p; 	u_long entry; 	u_long stack; { 	int *regs = p->p_md.md_regs;  	bzero(regs, sizeof(struct trapframe)); 	regs[tEIP] = entry; 	regs[tESP] = stack; 	regs[tEFLAGS] = PSL_USERSET | (regs[tEFLAGS]& PSL_T); 	regs[tSS] = _udatasel; 	regs[tDS] = _udatasel; 	regs[tES] = _udatasel; 	regs[tCS] = _ucodesel;  	p->p_addr->u_pcb.pcb_flags =
literal|0
argument|;
comment|/* no fp at all */
argument|load_cr0(rcr0() | CR0_TS);
comment|/* start emulating */
if|#
directive|if
name|NNPX
operator|>
literal|0
argument|npxinit(__INITIAL_NPXCW__);
endif|#
directive|endif
comment|/* NNPX> 0 */
argument|}
comment|/*  * machine dependent system variables.  */
argument|int cpu_sysctl(name, namelen, oldp, oldlenp, newp, newlen, p) 	int *name; 	u_int namelen; 	void *oldp; 	size_t *oldlenp; 	void *newp; 	size_t newlen; 	struct proc *p; { 	int error;
comment|/* all sysctl names at this level are terminal */
argument|if (namelen !=
literal|1
argument|) 		return (ENOTDIR);
comment|/* overloaded */
argument|switch (name[
literal|0
argument|]) { 	case CPU_CONSDEV: 		return (sysctl_rdstruct(oldp, oldlenp, newp,&cn_tty->t_dev, 		   sizeof cn_tty->t_dev)); 	case CPU_ADJKERNTZ: 		error = sysctl_int(oldp, oldlenp, newp, newlen,&adjkerntz); 		if (!error&& newp) 			resettodr(); 		return error; 	case CPU_DISRTCSET: 		return (sysctl_int(oldp, oldlenp, newp,	newlen,&disable_rtc_set)); 	default: 		return (EOPNOTSUPP); 	}
comment|/* NOTREACHED */
argument|}
comment|/*  * Initialize 386 and configure to run kernel  */
comment|/*  * Initialize segments& interrupt table  */
argument|int currentldt; int _default_ldt; union descriptor gdt[NGDT];
comment|/* global descriptor table */
argument|struct gate_descriptor idt[NIDT];
comment|/* interrupt descriptor table */
argument|union descriptor ldt[NLDT];
comment|/* local descriptor table */
argument|struct	i386tss	tss
argument_list|,
argument|panic_tss;  extern  struct user *proc0paddr;
comment|/* software prototypes -- in more palatable form */
argument|struct soft_segment_descriptor gdt_segs[] = {
comment|/* GNULL_SEL	0 Null Descriptor */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0x0
argument_list|,
comment|/* length */
literal|0
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|0
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GCODE_SEL	1 Code Descriptor for kernel */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0xfffff
argument_list|,
comment|/* length - all address space */
argument|SDT_MEMERA
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|1
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GDATA_SEL	2 Data Descriptor for kernel */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0xfffff
argument_list|,
comment|/* length - all address space */
argument|SDT_MEMRWA
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|1
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GLDT_SEL	3 LDT Descriptor */
argument|{	(int) ldt
argument_list|,
comment|/* segment base address  */
argument|sizeof(ldt)-
literal|1
argument_list|,
comment|/* length - all address space */
argument|SDT_SYSLDT
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* unused - default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GTGATE_SEL	4 Null Descriptor - Placeholder */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0x0
argument_list|,
comment|/* length - all address space */
literal|0
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|0
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GPANIC_SEL	5 Panic Tss Descriptor */
argument|{	(int)&panic_tss
argument_list|,
comment|/* segment base address  */
argument|sizeof(tss)-
literal|1
argument_list|,
comment|/* length - all address space */
argument|SDT_SYS386TSS
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* unused - default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GPROC0_SEL	6 Proc 0 Tss Descriptor */
argument|{	(int) kstack
argument_list|,
comment|/* segment base address  */
argument|sizeof(tss)-
literal|1
argument_list|,
comment|/* length - all address space */
argument|SDT_SYS386TSS
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* unused - default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GUSERLDT_SEL	7 User LDT Descriptor per process */
argument|{	(int) ldt
argument_list|,
comment|/* segment base address  */
argument|(
literal|512
argument|* sizeof(union descriptor)-
literal|1
argument|)
argument_list|,
comment|/* length */
argument|SDT_SYSLDT
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* unused - default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GAPMCODE32_SEL 8 APM BIOS 32-bit interface (32bit Code) */
argument|{
literal|0
argument_list|,
comment|/* segment base address (overwritten by APM)  */
literal|0xfffff
argument_list|,
comment|/* length */
argument|SDT_MEMERA
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|1
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GAPMCODE16_SEL 9 APM BIOS 32-bit interface (16bit Code) */
argument|{
literal|0
argument_list|,
comment|/* segment base address (overwritten by APM)  */
literal|0xfffff
argument_list|,
comment|/* length */
argument|SDT_MEMERA
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|1
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* GAPMDATA_SEL	10 APM BIOS 32-bit interface (Data) */
argument|{
literal|0
argument_list|,
comment|/* segment base address (overwritten by APM) */
literal|0xfffff
argument_list|,
comment|/* length */
argument|SDT_MEMRWA
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|1
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
argument|};  struct soft_segment_descriptor ldt_segs[] = {
comment|/* Null Descriptor - overwritten by call gate */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0x0
argument_list|,
comment|/* length - all address space */
literal|0
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|0
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* Null Descriptor - overwritten by call gate */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0x0
argument_list|,
comment|/* length - all address space */
literal|0
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|0
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* Null Descriptor - overwritten by call gate */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0x0
argument_list|,
comment|/* length - all address space */
literal|0
argument_list|,
comment|/* segment type */
literal|0
argument_list|,
comment|/* segment descriptor priority level */
literal|0
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|0
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* Code Descriptor for user */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0xfffff
argument_list|,
comment|/* length - all address space */
argument|SDT_MEMERA
argument_list|,
comment|/* segment type */
argument|SEL_UPL
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|1
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
comment|/* Data Descriptor for user */
argument|{
literal|0x0
argument_list|,
comment|/* segment base address  */
literal|0xfffff
argument_list|,
comment|/* length - all address space */
argument|SDT_MEMRWA
argument_list|,
comment|/* segment type */
argument|SEL_UPL
argument_list|,
comment|/* segment descriptor priority level */
literal|1
argument_list|,
comment|/* segment descriptor present */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
comment|/* default 32 vs 16 bit size */
literal|1
comment|/* limit granularity (byte/page units)*/
argument|}
argument_list|,
argument|};  void setidt(idx, func, typ, dpl) 	int idx; 	inthand_t *func; 	int typ; 	int dpl; { 	struct gate_descriptor *ip = idt + idx;  	ip->gd_looffset = (int)func; 	ip->gd_selector =
literal|8
argument|; 	ip->gd_stkcpy =
literal|0
argument|; 	ip->gd_xx =
literal|0
argument|; 	ip->gd_type = typ; 	ip->gd_dpl = dpl; 	ip->gd_p =
literal|1
argument|; 	ip->gd_hioffset = ((int)func)>>
literal|16
argument|; }
define|#
directive|define
name|IDTVEC
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(X,name)
argument|extern inthand_t 	IDTVEC(div)
argument_list|,
argument|IDTVEC(dbg)
argument_list|,
argument|IDTVEC(nmi)
argument_list|,
argument|IDTVEC(bpt)
argument_list|,
argument|IDTVEC(ofl)
argument_list|,
argument|IDTVEC(bnd)
argument_list|,
argument|IDTVEC(ill)
argument_list|,
argument|IDTVEC(dna)
argument_list|,
argument|IDTVEC(dble)
argument_list|,
argument|IDTVEC(fpusegm)
argument_list|,
argument|IDTVEC(tss)
argument_list|,
argument|IDTVEC(missing)
argument_list|,
argument|IDTVEC(stk)
argument_list|,
argument|IDTVEC(prot)
argument_list|,
argument|IDTVEC(page)
argument_list|,
argument|IDTVEC(rsvd)
argument_list|,
argument|IDTVEC(fpu)
argument_list|,
argument|IDTVEC(rsvd0)
argument_list|,
argument|IDTVEC(rsvd1)
argument_list|,
argument|IDTVEC(rsvd2)
argument_list|,
argument|IDTVEC(rsvd3)
argument_list|,
argument|IDTVEC(rsvd4)
argument_list|,
argument|IDTVEC(rsvd5)
argument_list|,
argument|IDTVEC(rsvd6)
argument_list|,
argument|IDTVEC(rsvd7)
argument_list|,
argument|IDTVEC(rsvd8)
argument_list|,
argument|IDTVEC(rsvd9)
argument_list|,
argument|IDTVEC(rsvd10)
argument_list|,
argument|IDTVEC(rsvd11)
argument_list|,
argument|IDTVEC(rsvd12)
argument_list|,
argument|IDTVEC(rsvd13)
argument_list|,
argument|IDTVEC(rsvd14)
argument_list|,
argument|IDTVEC(syscall);  void sdtossd(sd, ssd) 	struct segment_descriptor *sd; 	struct soft_segment_descriptor *ssd; { 	ssd->ssd_base  = (sd->sd_hibase<<
literal|24
argument|) | sd->sd_lobase; 	ssd->ssd_limit = (sd->sd_hilimit<<
literal|16
argument|) | sd->sd_lolimit; 	ssd->ssd_type  = sd->sd_type; 	ssd->ssd_dpl   = sd->sd_dpl; 	ssd->ssd_p     = sd->sd_p; 	ssd->ssd_def32 = sd->sd_def32; 	ssd->ssd_gran  = sd->sd_gran; }  void init386(first) 	int first; { 	extern char etext[];  	int x; 	unsigned biosbasemem
argument_list|,
argument|biosextmem; 	struct gate_descriptor *gdp; 	int gsel_tss; 	extern int sigcode
argument_list|,
argument|szsigcode;
comment|/* table descriptors - used to load tables by microp */
argument|struct region_descriptor r_gdt
argument_list|,
argument|r_idt; 	int	pagesinbase
argument_list|,
argument|pagesinext; 	int	target_page; 	extern struct pte *CMAP1; 	extern caddr_t CADDR1;  	proc0.p_addr = proc0paddr;
comment|/* 	 * Initialize the console before we print anything out. 	 */
argument|cninit ();
comment|/* 	 * make gdt memory segments, the code segment goes up to end of the 	 * page with etext in it, the data segment goes to the end of 	 * the address space 	 */
comment|/* 	 * XXX text protection is temporarily (?) disabled.  The limit was 	 * i386_btop(i386_round_page(etext)) - 1. 	 */
argument|gdt_segs[GCODE_SEL].ssd_limit = i386_btop(
literal|0
argument|) -
literal|1
argument|; 	gdt_segs[GDATA_SEL].ssd_limit = i386_btop(
literal|0
argument|) -
literal|1
argument|; 	for (x =
literal|0
argument|; x< NGDT; x++) 		ssdtosd(&gdt_segs[x],&gdt[x].sd);
comment|/* make ldt memory segments */
comment|/* 	 * The data segment limit must not cover the user area because we 	 * don't want the user area to be writable in copyout() etc. (page 	 * level protection is lost in kernel mode on 386's).  Also, we 	 * don't want the user area to be writable directly (page level 	 * protection of the user area is not available on 486's with 	 * CR0_WP set, because there is no user-read/kernel-write mode). 	 * 	 * XXX - VM_MAXUSER_ADDRESS is an end address, not a max.  And it 	 * should be spelled ...MAX_USER... 	 */
define|#
directive|define
name|VM_END_USER_RW_ADDRESS
value|VM_MAXUSER_ADDRESS
comment|/* 	 * The code segment limit has to cover the user area until we move 	 * the signal trampoline out of the user area.  This is safe because 	 * the code segment cannot be written to directly. 	 */
define|#
directive|define
name|VM_END_USER_R_ADDRESS
value|(VM_END_USER_RW_ADDRESS + UPAGES * NBPG)
argument|ldt_segs[LUCODE_SEL].ssd_limit = i386_btop(VM_END_USER_R_ADDRESS) -
literal|1
argument|; 	ldt_segs[LUDATA_SEL].ssd_limit = i386_btop(VM_END_USER_RW_ADDRESS) -
literal|1
argument|;
comment|/* Note. eventually want private ldts per process */
argument|for (x =
literal|0
argument|; x< NLDT; x++) 		ssdtosd(&ldt_segs[x],&ldt[x].sd);
comment|/* exceptions */
argument|setidt(
literal|0
argument|,&IDTVEC(div),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|1
argument|,&IDTVEC(dbg),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|2
argument|,&IDTVEC(nmi),  SDT_SYS386TGT, SEL_KPL);  	setidt(
literal|3
argument|,&IDTVEC(bpt),  SDT_SYS386TGT, SEL_UPL); 	setidt(
literal|4
argument|,&IDTVEC(ofl),  SDT_SYS386TGT, SEL_UPL); 	setidt(
literal|5
argument|,&IDTVEC(bnd),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|6
argument|,&IDTVEC(ill),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|7
argument|,&IDTVEC(dna),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|8
argument|,&IDTVEC(dble),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|9
argument|,&IDTVEC(fpusegm),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|10
argument|,&IDTVEC(tss),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|11
argument|,&IDTVEC(missing),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|12
argument|,&IDTVEC(stk),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|13
argument|,&IDTVEC(prot),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|14
argument|,&IDTVEC(page),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|15
argument|,&IDTVEC(rsvd),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|16
argument|,&IDTVEC(fpu),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|17
argument|,&IDTVEC(rsvd0),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|18
argument|,&IDTVEC(rsvd1),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|19
argument|,&IDTVEC(rsvd2),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|20
argument|,&IDTVEC(rsvd3),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|21
argument|,&IDTVEC(rsvd4),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|22
argument|,&IDTVEC(rsvd5),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|23
argument|,&IDTVEC(rsvd6),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|24
argument|,&IDTVEC(rsvd7),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|25
argument|,&IDTVEC(rsvd8),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|26
argument|,&IDTVEC(rsvd9),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|27
argument|,&IDTVEC(rsvd10),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|28
argument|,&IDTVEC(rsvd11),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|29
argument|,&IDTVEC(rsvd12),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|30
argument|,&IDTVEC(rsvd13),  SDT_SYS386TGT, SEL_KPL); 	setidt(
literal|31
argument|,&IDTVEC(rsvd14),  SDT_SYS386TGT, SEL_KPL);
include|#
directive|include
file|"isa.h"
if|#
directive|if
name|NISA
operator|>
literal|0
argument|isa_defaultirq();
endif|#
directive|endif
argument|r_gdt.rd_limit = sizeof(gdt) -
literal|1
argument|; 	r_gdt.rd_base =  (int) gdt; 	lgdt(&r_gdt);  	r_idt.rd_limit = sizeof(idt) -
literal|1
argument|; 	r_idt.rd_base = (int) idt; 	lidt(&r_idt);  	_default_ldt = GSEL(GLDT_SEL, SEL_KPL); 	lldt(_default_ldt); 	currentldt = _default_ldt;
ifdef|#
directive|ifdef
name|DDB
argument|kdb_init(); 	if (boothowto& RB_KDB) 		Debugger(
literal|"Boot flags requested debugger"
argument|);
endif|#
directive|endif
comment|/* Use BIOS values stored in RTC CMOS RAM, since probing 	 * breaks certain 386 AT relics. 	 */
argument|biosbasemem = rtcin(RTC_BASELO)+ (rtcin(RTC_BASEHI)<<
literal|8
argument|); 	biosextmem = rtcin(RTC_EXTLO)+ (rtcin(RTC_EXTHI)<<
literal|8
argument|);
comment|/* 	 * If BIOS tells us that it has more than 640k in the basemem, 	 *	don't believe it - set it to 640k. 	 */
argument|if (biosbasemem>
literal|640
argument|) 		biosbasemem =
literal|640
argument|;
comment|/* 	 * Some 386 machines might give us a bogus number for extended 	 *	mem. If this happens, stop now. 	 */
ifndef|#
directive|ifndef
name|LARGEMEM
argument|if (biosextmem>
literal|65536
argument|) { 		panic(
literal|"extended memory beyond limit of 64MB"
argument|);
comment|/* NOTREACHED */
argument|}
endif|#
directive|endif
argument|pagesinbase = biosbasemem *
literal|1024
argument|/ NBPG; 	pagesinext = biosextmem *
literal|1024
argument|/ NBPG;
comment|/* 	 * Special hack for chipsets that still remap the 384k hole when 	 *	there's 16MB of memory - this really confuses people that 	 *	are trying to use bus mastering ISA controllers with the 	 *	"16MB limit"; they only have 16MB, but the remapping puts 	 *	them beyond the limit. 	 * XXX - this should be removed when bounce buffers are 	 *	implemented. 	 */
comment|/* 	 * If extended memory is between 15-16MB (16-17MB phys address range), 	 *	chop it to 15MB. 	 */
argument|if ((pagesinext>
literal|3840
argument|)&& (pagesinext<
literal|4096
argument|)) 		pagesinext =
literal|3840
argument|;
comment|/* 	 * Maxmem isn't the "maximum memory", it's the highest page of 	 * of the physical address space. It should be "Maxphyspage". 	 */
argument|Maxmem = pagesinext +
literal|0x100000
argument|/PAGE_SIZE;
ifdef|#
directive|ifdef
name|MAXMEM
argument|Maxmem = MAXMEM/
literal|4
argument|;
endif|#
directive|endif
comment|/* 	 * Calculate number of physical pages, but account for Maxmem 	 *	adjustment above. 	 */
argument|physmem = pagesinbase + Maxmem -
literal|0x100000
argument|/PAGE_SIZE;
comment|/* call pmap initialization to make new kernel address space */
argument|pmap_bootstrap (first,
literal|0
argument|);
comment|/* 	 * Do simple memory test over range of extended memory that BIOS 	 *	indicates exists. Adjust Maxmem to the highest page of 	 *	good memory. 	 */
argument|printf(
literal|"Testing memory (%dMB)..."
argument|, ptoa(Maxmem)/
literal|1024
argument|/
literal|1024
argument|);  	for (target_page = Maxmem -
literal|2
argument|; target_page>= atop(first); target_page--) {
comment|/* 		 * map page into kernel: valid, read/write, non-cacheable 		 */
argument|*(int *)CMAP1 = PG_V | PG_KW | PG_N | ptoa(target_page); 		pmap_update();
comment|/* 		 * Test for alternating 1's and 0's 		 */
argument|filli(
literal|0xaaaaaaaa
argument|, CADDR1, PAGE_SIZE/sizeof(int)); 		if (test_page((int *)CADDR1,
literal|0xaaaaaaaa
argument|)) { 			Maxmem = target_page; 			badpages++; 			continue; 		}
comment|/* 		 * Test for alternating 0's and 1's 		 */
argument|filli(
literal|0x55555555
argument|, CADDR1, PAGE_SIZE/sizeof(int)); 		if (test_page((int *)CADDR1,
literal|0x55555555
argument|)) { 			Maxmem = target_page; 			badpages++; 			continue; 		}
comment|/* 		 * Test for all 1's 		 */
argument|filli(
literal|0xffffffff
argument|, CADDR1, PAGE_SIZE/sizeof(int)); 		if (test_page((int *)CADDR1,
literal|0xffffffff
argument|)) { 			Maxmem = target_page; 			badpages++; 			continue; 		}
comment|/* 		 * Test zeroing of page 		 */
argument|bzero(CADDR1, PAGE_SIZE); 		if (test_page((int *)CADDR1,
literal|0
argument|)) {
comment|/* 			 * test of page failed 			 */
argument|Maxmem = target_page; 			badpages++; 			continue; 		} 	} 	printf(
literal|"done.\n"
argument|);  	*(int *)CMAP1 =
literal|0
argument|; 	pmap_update();  	avail_end = (Maxmem<< PAGE_SHIFT) 		    - i386_round_page(sizeof(struct msgbuf));
comment|/* 	 * Initialize pointers to the two chunks of memory; for use 	 *	later in vm_page_startup. 	 */
comment|/* avail_start is initialized in pmap_bootstrap */
argument|x =
literal|0
argument|; 	if (pagesinbase>
literal|1
argument|) { 		phys_avail[x++] = NBPG;
comment|/* skip first page of memory */
argument|phys_avail[x++] = pagesinbase * NBPG;
comment|/* memory up to the ISA hole */
argument|} 	phys_avail[x++] = avail_start;
comment|/* memory up to the end */
argument|phys_avail[x++] = avail_end; 	phys_avail[x++] =
literal|0
argument|;
comment|/* no more chunks */
argument|phys_avail[x++] =
literal|0
argument|;
comment|/* now running on new page tables, configured,and u/iom is accessible */
comment|/* make a initial tss so microp can get interrupt stack on syscall! */
argument|proc0.p_addr->u_pcb.pcb_tss.tss_esp0 = (int) kstack + UPAGES*NBPG; 	proc0.p_addr->u_pcb.pcb_tss.tss_ss0 = GSEL(GDATA_SEL, SEL_KPL) ; 	gsel_tss = GSEL(GPROC0_SEL, SEL_KPL);  	((struct i386tss *)gdt_segs[GPROC0_SEL].ssd_base)->tss_ioopt =  		(sizeof(tss))<<
literal|16
argument|;  	ltr(gsel_tss);
comment|/* make a call gate to reenter kernel with */
argument|gdp =&ldt[LSYS5CALLS_SEL].gd;  	x = (int)&IDTVEC(syscall); 	gdp->gd_looffset = x++; 	gdp->gd_selector = GSEL(GCODE_SEL,SEL_KPL); 	gdp->gd_stkcpy =
literal|1
argument|; 	gdp->gd_type = SDT_SYS386CGT; 	gdp->gd_dpl = SEL_UPL; 	gdp->gd_p =
literal|1
argument|; 	gdp->gd_hioffset = ((int)&IDTVEC(syscall))>>
literal|16
argument|;
comment|/* transfer to user mode */
argument|_ucodesel = LSEL(LUCODE_SEL, SEL_UPL); 	_udatasel = LSEL(LUDATA_SEL, SEL_UPL);
comment|/* setup proc 0's pcb */
argument|bcopy(&sigcode, proc0.p_addr->u_pcb.pcb_sigc, szsigcode); 	proc0.p_addr->u_pcb.pcb_flags =
literal|0
argument|; 	proc0.p_addr->u_pcb.pcb_ptd = IdlePTD; }  int test_page(address, pattern) 	int *address; 	int pattern; { 	int *x;  	for (x = address; x< (int *)((char *)address + PAGE_SIZE); x++) { 		if (*x != pattern) 			return (
literal|1
argument|); 	} 	return(
literal|0
argument|); }
comment|/*  * The registers are in the frame; the frame is in the user area of  * the process in question; when the process is active, the registers  * are in "the kernel stack"; when it's not, they're still there, but  * things get flipped around.  So, since p->p_md.md_regs is the whole address  * of the register set, take its offset from the kernel stack, and  * index into the user block.  Don't you just *love* virtual memory?  * (I'm starting to think seymour is right...)  */
argument|int ptrace_set_pc (struct proc *p, unsigned int addr) { 	void *regs = (char*)p->p_addr + 		((char*) p->p_md.md_regs - (char*) kstack);  	((struct trapframe *)regs)->tf_eip = addr; 	return
literal|0
argument|; }  int ptrace_single_step (struct proc *p) { 	void *regs = (char*)p->p_addr + 		((char*) p->p_md.md_regs - (char*) kstack);  	((struct trapframe *)regs)->tf_eflags |= PSL_T; 	return
literal|0
argument|; }
comment|/*  * Copy the registers to user-space.  */
argument|int ptrace_getregs (struct proc *p, unsigned int *addr) { 	int error; 	struct reg regs = {
literal|0
argument|};  	error = fill_regs (p,&regs); 	if (error) 		return error; 	   	return copyout (&regs, addr, sizeof (regs)); }  int ptrace_setregs (struct proc *p, unsigned int *addr) { 	int error; 	struct reg regs = {
literal|0
argument|};  	error = copyin (addr,&regs, sizeof(regs)); 	if (error) 		return error;  	return set_regs (p,&regs); }  int fill_regs(struct proc *p, struct reg *regs) { 	struct trapframe *tp; 	void *ptr = (char*)p->p_addr + 		((char*) p->p_md.md_regs - (char*) kstack);  	tp = ptr; 	regs->r_es = tp->tf_es; 	regs->r_ds = tp->tf_ds; 	regs->r_edi = tp->tf_edi; 	regs->r_esi = tp->tf_esi; 	regs->r_ebp = tp->tf_ebp; 	regs->r_ebx = tp->tf_ebx; 	regs->r_edx = tp->tf_edx; 	regs->r_ecx = tp->tf_ecx; 	regs->r_eax = tp->tf_eax; 	regs->r_eip = tp->tf_eip; 	regs->r_cs = tp->tf_cs; 	regs->r_eflags = tp->tf_eflags; 	regs->r_esp = tp->tf_esp; 	regs->r_ss = tp->tf_ss; 	return
literal|0
argument|; }  int set_regs (struct proc *p, struct reg *regs) { 	struct trapframe *tp; 	void *ptr = (char*)p->p_addr + 		((char*) p->p_md.md_regs - (char*) kstack);  	tp = ptr; 	tp->tf_es = regs->r_es; 	tp->tf_ds = regs->r_ds; 	tp->tf_edi = regs->r_edi; 	tp->tf_esi = regs->r_esi; 	tp->tf_ebp = regs->r_ebp; 	tp->tf_ebx = regs->r_ebx; 	tp->tf_edx = regs->r_edx; 	tp->tf_ecx = regs->r_ecx; 	tp->tf_eax = regs->r_eax; 	tp->tf_eip = regs->r_eip; 	tp->tf_cs = regs->r_cs; 	tp->tf_eflags = regs->r_eflags; 	tp->tf_esp = regs->r_esp; 	tp->tf_ss = regs->r_ss; 	return
literal|0
argument|; }
ifndef|#
directive|ifndef
name|DDB
argument|void Debugger(const char *msg) { 	printf(
literal|"Debugger(\"%s\") called.\n"
argument|, msg); }
endif|#
directive|endif
comment|/* no DDB */
include|#
directive|include
file|<sys/disklabel.h>
define|#
directive|define
name|b_cylin
value|b_resid
comment|/*  * Determine the size of the transfer, and make sure it is  * within the boundaries of the partition. Adjust transfer  * if needed, and signal errors or early completion.  */
argument|int bounds_check_with_label(struct buf *bp, struct disklabel *lp, int wlabel) {         struct partition *p = lp->d_partitions + dkpart(bp->b_dev);         int labelsect = lp->d_partitions[
literal|0
argument|].p_offset;         int maxsz = p->p_size
argument_list|,
argument|sz = (bp->b_bcount + DEV_BSIZE -
literal|1
argument|)>> DEV_BSHIFT;
comment|/* overwriting disk label ? */
comment|/* XXX should also protect bootstrap in first 8K */
argument|if (bp->b_blkno + p->p_offset<= LABELSECTOR + labelsect&&
if|#
directive|if
name|LABELSECTOR
operator|!=
literal|0
argument|bp->b_blkno + p->p_offset + sz> LABELSECTOR + labelsect&&
endif|#
directive|endif
argument|(bp->b_flags& B_READ) ==
literal|0
argument|&& wlabel ==
literal|0
argument|) {                 bp->b_error = EROFS;                 goto bad;         }
if|#
directive|if
name|defined
argument_list|(
name|DOSBBSECTOR
argument_list|)
operator|&&
name|defined
argument_list|(
name|notyet
argument_list|)
comment|/* overwriting master boot record? */
argument|if (bp->b_blkno + p->p_offset<= DOSBBSECTOR&&             (bp->b_flags& B_READ) ==
literal|0
argument|&& wlabel ==
literal|0
argument|) {                 bp->b_error = EROFS;                 goto bad;         }
endif|#
directive|endif
comment|/* beyond partition? */
argument|if (bp->b_blkno<
literal|0
argument||| bp->b_blkno + sz> maxsz) {
comment|/* if exactly at end of disk, return an EOF */
argument|if (bp->b_blkno == maxsz) {                         bp->b_resid = bp->b_bcount;                         return(
literal|0
argument|);                 }
comment|/* or truncate if part of it fits */
argument|sz = maxsz - bp->b_blkno;                 if (sz<=
literal|0
argument|) {                         bp->b_error = EINVAL;                         goto bad;                 }                 bp->b_bcount = sz<< DEV_BSHIFT;         }
comment|/* calculate cylinder for disksort to order transfers with */
argument|bp->b_pblkno = bp->b_blkno + p->p_offset;         bp->b_cylin = bp->b_pblkno / lp->d_secpercyl;         return(
literal|1
argument|);  bad:         bp->b_flags |= B_ERROR;         return(-
literal|1
argument|); }  int disk_externalize(int drive, void *userp, size_t *maxlen) { 	if(*maxlen< sizeof drive) { 		return ENOMEM; 	}  	*maxlen -= sizeof drive; 	return copyout(&drive, userp, sizeof drive); }
end_function

end_unit

