begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (C) 2001 Benno Rice  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *	$NetBSD: machdep.c,v 1.74.2.1 2000/11/01 16:13:48 tv Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_compat.h"
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
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
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<sys/msgbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
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
file|<vm/vm_extern.h>
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
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<machine/bat.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/fpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|<machine/powerpc.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<machine/sigframe.h>
end_include

begin_decl_stmt
name|int
name|physmem
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cold
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mtx
name|sched_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mtx
name|Giant
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|user
modifier|*
name|proc0uarea
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|proc0kstack
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

begin_decl_stmt
specifier|static
name|char
name|model
index|[
literal|128
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
name|model
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
name|bootpath
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_comment
comment|/* start and end of kernel symbol table */
end_comment

begin_decl_stmt
name|void
modifier|*
name|ksym_start
decl_stmt|,
modifier|*
name|ksym_end
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DDB */
end_comment

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

begin_macro
name|SYSINIT
argument_list|(
argument|cpu
argument_list|,
argument|SI_SUB_CPU
argument_list|,
argument|SI_ORDER_FIRST
argument_list|,
argument|cpu_startup
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_function_decl
name|void
name|powerpc_init
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|save_ofw_mapping
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|restore_ofw_mapping
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|install_extint
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_43
end_ifdef

begin_function_decl
name|void
name|osendsig
parameter_list|(
name|sig_t
parameter_list|,
name|int
parameter_list|,
name|sigset_t
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|int
name|sysctl_hw_physmem
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|int
name|error
init|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
literal|0
argument_list|,
name|ctob
argument_list|(
name|physmem
argument_list|)
argument_list|,
name|req
argument_list|)
decl_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_hw
argument_list|,
name|HW_PHYSMEM
argument_list|,
name|physmem
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RD
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|sysctl_hw_physmem
argument_list|,
literal|"IU"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|msgbuf
modifier|*
name|msgbufp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Maxmem
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
name|vm_offset_t
name|phys_avail
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|chosen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|trapframe
name|proc0_tf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pmap
name|ofw_pmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ofmsr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bat
name|battable
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|identifycpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|kva_md_info
name|kmi
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|powerpc_ofw_shutdown
parameter_list|(
name|void
modifier|*
name|junk
parameter_list|,
name|int
name|howto
parameter_list|)
block|{
if|if
condition|(
name|howto
operator|&
name|RB_HALT
condition|)
block|{
name|OF_exit
argument_list|()
expr_stmt|;
block|}
block|}
end_function

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
comment|/* 	 * Good {morning,afternoon,evening,night}. 	 */
name|identifycpu
argument_list|()
expr_stmt|;
comment|/* startrtclock(); */
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
literal|"real memory  = %ld (%ldK bytes)\n"
argument_list|,
name|ptoa
argument_list|(
name|Maxmem
argument_list|)
argument_list|,
name|ptoa
argument_list|(
name|Maxmem
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
name|int
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
literal|"0x%08x - 0x%08x, %d bytes (%d pages)\n"
argument_list|,
name|phys_avail
index|[
name|indx
index|]
argument_list|,
name|phys_avail
index|[
name|indx
operator|+
literal|1
index|]
operator|-
literal|1
argument_list|,
name|size1
argument_list|,
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
if|#
directive|if
name|defined
argument_list|(
name|USERCONFIG
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|USERCONFIG_BOOT
argument_list|)
if|if
condition|(
literal|1
condition|)
else|#
directive|else
if|if
condition|(
name|boothowto
operator|&
name|RB_CONFIG
condition|)
endif|#
directive|endif
block|{
name|userconfig
argument_list|()
expr_stmt|;
name|cninit
argument_list|()
expr_stmt|;
comment|/* the preferred console may have changed */
block|}
endif|#
directive|endif
name|printf
argument_list|(
literal|"avail memory = %ld (%ldK bytes)\n"
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
literal|1024
argument_list|)
expr_stmt|;
comment|/* 	 * Set up buffers, so they can be used to read disk labels. 	 */
name|bufinit
argument_list|()
expr_stmt|;
name|vm_pager_bufferinit
argument_list|()
expr_stmt|;
name|EVENTHANDLER_REGISTER
argument_list|(
name|shutdown_final
argument_list|,
name|powerpc_ofw_shutdown
argument_list|,
literal|0
argument_list|,
name|SHUTDOWN_PRI_LAST
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SMP
comment|/* 	 * OK, enough kmem_alloc/malloc state should be up, lets get on with it! 	 */
name|mp_start
argument_list|()
expr_stmt|;
comment|/* fire up the secondaries */
name|mp_announce
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* SMP */
block|}
end_function

begin_function
name|void
name|identifycpu
parameter_list|()
block|{
name|unsigned
name|int
name|pvr
decl_stmt|,
name|version
decl_stmt|,
name|revision
decl_stmt|;
comment|/* 	 * Find cpu type (Do it by OpenFirmware?) 	 */
asm|__asm ("mfpvr %0" : "=r"(pvr));
name|version
operator|=
name|pvr
operator|>>
literal|16
expr_stmt|;
name|revision
operator|=
name|pvr
operator|&
literal|0xffff
expr_stmt|;
switch|switch
condition|(
name|version
condition|)
block|{
case|case
literal|0x0001
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"601"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0003
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"603 (Wart)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0004
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"604 (Zephyr)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0005
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"602 (Galahad)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0006
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"603e (Stretch)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0007
case|:
if|if
condition|(
operator|(
name|revision
operator|&&
literal|0xf000
operator|)
operator|==
literal|0x0000
condition|)
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"603ev (Valiant)"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"603r (Goldeneye)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0008
case|:
if|if
condition|(
operator|(
name|revision
operator|&&
literal|0xf000
operator|)
operator|==
literal|0x0000
condition|)
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"G3 / 750 (Arthur)"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"G3 / 755 (Goldfinger)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0009
case|:
if|if
condition|(
operator|(
name|revision
operator|&&
literal|0xf000
operator|)
operator|==
literal|0x0000
condition|)
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"604e (Sirocco)"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"604r (Mach V)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x000a
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"604r (Mach V)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x000c
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"G4 / 7400 (Max)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0014
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"620 (Red October)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x0081
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"8240 (Kahlua)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x8000
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"G4 / 7450 (V'ger)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x800c
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"G4 / 7410 (Nitro)"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x8081
case|:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"8245 (Kahlua II)"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|sprintf
argument_list|(
name|model
argument_list|,
literal|"Version %x"
argument_list|,
name|version
argument_list|)
expr_stmt|;
break|break;
block|}
name|sprintf
argument_list|(
name|model
operator|+
name|strlen
argument_list|(
name|model
argument_list|)
argument_list|,
literal|" (Revision %x)"
argument_list|,
name|revision
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"CPU: PowerPC %s\n"
argument_list|,
name|model
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|char
name|kernel_text
index|[]
decl_stmt|,
name|_end
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|trapcode
decl_stmt|,
modifier|*
name|trapsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|alitrap
decl_stmt|,
modifier|*
name|alisize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|dsitrap
decl_stmt|,
modifier|*
name|dsisize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|isitrap
decl_stmt|,
modifier|*
name|isisize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|decrint
decl_stmt|,
modifier|*
name|decrsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|tlbimiss
decl_stmt|,
modifier|*
name|tlbimsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|tlbdlmiss
decl_stmt|,
modifier|*
name|tlbdlmsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|tlbdsmiss
decl_stmt|,
modifier|*
name|tlbdsmsize
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: interrupt handler.  We'll get to this later */
end_comment

begin_endif
unit|extern void	ext_intr(void);
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_extern
extern|extern		ddblow
operator|,
extern|ddbsize;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPKDB
end_ifdef

begin_extern
extern|extern		ipkdblow
operator|,
extern|ipkdbsize;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|powerpc_init
parameter_list|(
name|u_int
name|startkernel
parameter_list|,
name|u_int
name|endkernel
parameter_list|,
name|u_int
name|basekernel
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
block|{
name|unsigned
name|int
name|exc
decl_stmt|,
name|scratch
decl_stmt|;
name|struct
name|mem_region
modifier|*
name|allmem
decl_stmt|,
modifier|*
name|availmem
decl_stmt|,
modifier|*
name|mp
decl_stmt|;
name|struct
name|pcpu
modifier|*
name|pcpup
decl_stmt|;
comment|/* 	 * Set up BAT0 to only map the lowest 256 MB area 	 */
name|battable
index|[
literal|0
index|]
operator|.
name|batl
operator|=
name|BATL
argument_list|(
literal|0x00000000
argument_list|,
name|BAT_M
argument_list|,
name|BAT_PP_RW
argument_list|)
expr_stmt|;
name|battable
index|[
literal|0
index|]
operator|.
name|batu
operator|=
name|BATU
argument_list|(
literal|0x00000000
argument_list|,
name|BAT_BL_256M
argument_list|,
name|BAT_Vs
argument_list|)
expr_stmt|;
comment|/* 	 * Map PCI memory space. 	 */
name|battable
index|[
literal|0x8
index|]
operator|.
name|batl
operator|=
name|BATL
argument_list|(
literal|0x80000000
argument_list|,
name|BAT_I
argument_list|,
name|BAT_PP_RW
argument_list|)
expr_stmt|;
name|battable
index|[
literal|0x8
index|]
operator|.
name|batu
operator|=
name|BATU
argument_list|(
literal|0x80000000
argument_list|,
name|BAT_BL_256M
argument_list|,
name|BAT_Vs
argument_list|)
expr_stmt|;
name|battable
index|[
literal|0x9
index|]
operator|.
name|batl
operator|=
name|BATL
argument_list|(
literal|0x90000000
argument_list|,
name|BAT_I
argument_list|,
name|BAT_PP_RW
argument_list|)
expr_stmt|;
name|battable
index|[
literal|0x9
index|]
operator|.
name|batu
operator|=
name|BATU
argument_list|(
literal|0x90000000
argument_list|,
name|BAT_BL_256M
argument_list|,
name|BAT_Vs
argument_list|)
expr_stmt|;
name|battable
index|[
literal|0xa
index|]
operator|.
name|batl
operator|=
name|BATL
argument_list|(
literal|0xa0000000
argument_list|,
name|BAT_I
argument_list|,
name|BAT_PP_RW
argument_list|)
expr_stmt|;
name|battable
index|[
literal|0xa
index|]
operator|.
name|batu
operator|=
name|BATU
argument_list|(
literal|0xa0000000
argument_list|,
name|BAT_BL_256M
argument_list|,
name|BAT_Vs
argument_list|)
expr_stmt|;
comment|/* 	 * Map obio devices. 	 */
name|battable
index|[
literal|0xf
index|]
operator|.
name|batl
operator|=
name|BATL
argument_list|(
literal|0xf0000000
argument_list|,
name|BAT_I
argument_list|,
name|BAT_PP_RW
argument_list|)
expr_stmt|;
name|battable
index|[
literal|0xf
index|]
operator|.
name|batu
operator|=
name|BATU
argument_list|(
literal|0xf0000000
argument_list|,
name|BAT_BL_256M
argument_list|,
name|BAT_Vs
argument_list|)
expr_stmt|;
comment|/* 	 * Now setup fixed bat registers 	 * 	 * Note that we still run in real mode, and the BAT 	 * registers were cleared above. 	 */
comment|/* BAT0 used for initial 256 MB segment */
asm|__asm __volatile ("mtibatl 0,%0; mtibatu 0,%1;"
literal|"mtdbatl 0,%0; mtdbatu 0,%1;"
operator|::
literal|"r"
operator|(
name|battable
index|[
literal|0
index|]
operator|.
name|batl
operator|)
operator|,
literal|"r"
operator|(
name|battable
index|[
literal|0
index|]
operator|.
name|batu
operator|)
block|)
function|;
end_function

begin_comment
comment|/* 	 * Set up battable to map all RAM regions. 	 * This is here because mem_regions() call needs bat0 set up. 	 */
end_comment

begin_expr_stmt
name|mem_regions
argument_list|(
operator|&
name|allmem
argument_list|,
operator|&
name|availmem
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Calculate the physical memory in the machine */
end_comment

begin_for
for|for
control|(
name|mp
operator|=
name|allmem
init|;
name|mp
operator|->
name|size
condition|;
name|mp
operator|++
control|)
name|physmem
operator|+=
name|btoc
argument_list|(
name|mp
operator|->
name|size
argument_list|)
expr_stmt|;
end_for

begin_for
for|for
control|(
name|mp
operator|=
name|allmem
init|;
name|mp
operator|->
name|size
condition|;
name|mp
operator|++
control|)
block|{
name|vm_offset_t
name|pa
init|=
name|mp
operator|->
name|start
operator|&
literal|0xf0000000
decl_stmt|;
name|vm_offset_t
name|end
init|=
name|mp
operator|->
name|start
operator|+
name|mp
operator|->
name|size
decl_stmt|;
do|do
block|{
name|u_int
name|n
init|=
name|pa
operator|>>
literal|28
decl_stmt|;
name|battable
index|[
name|n
index|]
operator|.
name|batl
operator|=
name|BATL
argument_list|(
name|pa
argument_list|,
name|BAT_M
argument_list|,
name|BAT_PP_RW
argument_list|)
expr_stmt|;
name|battable
index|[
name|n
index|]
operator|.
name|batu
operator|=
name|BATU
argument_list|(
name|pa
argument_list|,
name|BAT_BL_256M
argument_list|,
name|BAT_Vs
argument_list|)
expr_stmt|;
name|pa
operator|+=
literal|0x10000000
expr_stmt|;
block|}
do|while
condition|(
name|pa
operator|<
name|end
condition|)
do|;
block|}
end_for

begin_expr_stmt
name|chosen
operator|=
name|OF_finddevice
argument_list|(
literal|"/chosen"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|save_ofw_mapping
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pmap_setavailmem
argument_list|(
name|startkernel
argument_list|,
name|endkernel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|proc_linkup
argument_list|(
operator|&
name|proc0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|proc0uarea
operator|=
operator|(
expr|struct
name|user
operator|*
operator|)
name|pmap_steal_memory
argument_list|(
name|UAREA_PAGES
operator|*
name|PAGE_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|proc0kstack
operator|=
name|pmap_steal_memory
argument_list|(
name|KSTACK_PAGES
operator|*
name|PAGE_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|proc0
operator|.
name|p_uarea
operator|=
name|proc0uarea
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|thread0
operator|=
operator|&
name|proc0
operator|.
name|p_thread
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|thread0
operator|->
name|td_kstack
operator|=
name|proc0kstack
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|thread0
operator|->
name|td_pcb
operator|=
operator|(
expr|struct
name|pcb
operator|*
operator|)
operator|(
name|thread0
operator|->
name|td_kstack
operator|+
name|KSTACK_PAGES
operator|*
name|PAGE_SIZE
operator|)
operator|-
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pcpup
operator|=
name|pmap_steal_memory
argument_list|(
name|round_page
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * XXX: Pass 0 as CPU id.  This is bad.  We need to work out 	 * XXX: which CPU we are somehow. 	 */
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_asm
asm|__asm ("mtsprg 0, %0" :: "r"(pcpup));
end_asm

begin_comment
comment|/* Init basic tunables, hz etc */
end_comment

begin_expr_stmt
name|init_param1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|init_param2
argument_list|(
name|physmem
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* setup curproc so the mutexes work */
end_comment

begin_expr_stmt
name|PCPU_SET
argument_list|(
name|curthread
argument_list|,
name|thread0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_INIT
argument_list|(
operator|&
name|thread0
operator|->
name|td_contested
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX: NetBSDism I _think_.  Not sure yet. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|curpm = PCPU_GET(curpcb)->pcb_pmreal = PCPU_GET(curpcb)->pcb_pm = kernel_pmap;
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * Initialise some mutexes. 	 */
end_comment

begin_expr_stmt
name|mtx_init
argument_list|(
operator|&
name|Giant
argument_list|,
literal|"Giant"
argument_list|,
name|MTX_DEF
operator||
name|MTX_RECURSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mtx_init
argument_list|(
operator|&
name|sched_lock
argument_list|,
literal|"sched lock"
argument_list|,
name|MTX_SPIN
operator||
name|MTX_RECURSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mtx_init
argument_list|(
operator|&
name|proc0
operator|.
name|p_mtx
argument_list|,
literal|"process lock"
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mtx_lock
argument_list|(
operator|&
name|Giant
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Initialise console. 	 */
end_comment

begin_expr_stmt
name|cninit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__notyet__
end_ifdef

begin_comment
comment|/* Needs some rethinking regarding real/virtual OFW */
end_comment

begin_expr_stmt
name|OF_set_callback
argument_list|(
name|callback
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * Set up trap vectors 	 */
end_comment

begin_for
for|for
control|(
name|exc
operator|=
name|EXC_RSVD
init|;
name|exc
operator|<=
name|EXC_LAST
condition|;
name|exc
operator|+=
literal|0x100
control|)
block|{
switch|switch
condition|(
name|exc
condition|)
block|{
default|default:
name|bcopy
argument_list|(
operator|&
name|trapcode
argument_list|,
operator|(
name|void
operator|*
operator|)
name|exc
argument_list|,
operator|(
name|size_t
operator|)
operator|&
name|trapsize
argument_list|)
expr_stmt|;
break|break;
case|case
name|EXC_DECR
case|:
name|bcopy
argument_list|(
operator|&
name|decrint
argument_list|,
operator|(
name|void
operator|*
operator|)
name|EXC_DECR
argument_list|,
operator|(
name|size_t
operator|)
operator|&
name|decrsize
argument_list|)
expr_stmt|;
break|break;
if|#
directive|if
literal|0
comment|/* XXX: Not enabling these traps yet. */
block|case EXC_EXI:
comment|/* 			 * This one is (potentially) installed during autoconf 			 */
block|break; 		case EXC_ALI: 			bcopy(&alitrap, (void *)EXC_ALI, (size_t)&alisize); 			break; 		case EXC_DSI: 			bcopy(&dsitrap, (void *)EXC_DSI, (size_t)&dsisize); 			break; 		case EXC_ISI: 			bcopy(&isitrap, (void *)EXC_ISI, (size_t)&isisize); 			break; 		case EXC_IMISS: 			bcopy(&tlbimiss, (void *)EXC_IMISS, (size_t)&tlbimsize); 			break; 		case EXC_DLMISS: 			bcopy(&tlbdlmiss, (void *)EXC_DLMISS, (size_t)&tlbdlmsize); 			break; 		case EXC_DSMISS: 			bcopy(&tlbdsmiss, (void *)EXC_DSMISS, (size_t)&tlbdsmsize); 			break;
if|#
directive|if
name|defined
argument_list|(
name|DDB
argument_list|)
operator|||
name|defined
argument_list|(
name|IPKDB
argument_list|)
block|case EXC_TRC: 		case EXC_PGM: 		case EXC_BPT:
if|#
directive|if
name|defined
argument_list|(
name|DDB
argument_list|)
block|bcopy(&ddblow, (void *)exc, (size_t)&ddbsize);
else|#
directive|else
block|bcopy(&ipkdblow, (void *)exc, (size_t)&ipkdbsize);
endif|#
directive|endif
block|break;
endif|#
directive|endif
comment|/* DDB || IPKDB */
endif|#
directive|endif
block|}
block|}
end_for

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: coming soon... */
end_comment

begin_comment
comment|/* 	 * external interrupt handler install 	 */
end_comment

begin_endif
unit|install_extint(ext_intr);
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__syncicache
argument_list|(
operator|(
name|void
operator|*
operator|)
name|EXC_RST
argument_list|,
name|EXC_LAST
operator|-
name|EXC_RST
operator|+
literal|0x100
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Now enable translation (and machine checks/recoverable interrupts). 	 */
end_comment

begin_asm
asm|__asm ("mfmsr %0" : "=r"(scratch));
end_asm

begin_expr_stmt
name|scratch
operator||=
name|PSL_IR
operator||
name|PSL_DR
operator||
name|PSL_ME
operator||
name|PSL_RI
expr_stmt|;
end_expr_stmt

begin_asm
asm|__asm ("mtmsr %0" :: "r"(scratch));
end_asm

begin_expr_stmt
name|ofmsr
operator|&=
operator|~
name|PSL_IP
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Parse arg string. 	 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_expr_stmt
name|bcopy
argument_list|(
name|args
operator|+
name|strlen
argument_list|(
name|args
argument_list|)
operator|+
literal|1
argument_list|,
operator|&
name|startsym
argument_list|,
sizeof|sizeof
argument_list|(
name|startsym
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bcopy
argument_list|(
name|args
operator|+
name|strlen
argument_list|(
name|args
argument_list|)
operator|+
literal|5
argument_list|,
operator|&
name|endsym
argument_list|,
sizeof|sizeof
argument_list|(
name|endsym
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|startsym
operator|==
name|NULL
operator|||
name|endsym
operator|==
name|NULL
condition|)
name|startsym
operator|=
name|endsym
operator|=
name|NULL
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|strcpy
argument_list|(
name|bootpath
argument_list|,
name|args
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|args
operator|=
name|bootpath
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
operator|*
operator|++
name|args
operator|&&
operator|*
name|args
operator|!=
literal|' '
condition|)
empty_stmt|;
end_while

begin_if
if|if
condition|(
operator|*
name|args
condition|)
block|{
operator|*
name|args
operator|++
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|args
condition|)
block|{
switch|switch
condition|(
operator|*
name|args
operator|++
condition|)
block|{
case|case
literal|'a'
case|:
name|boothowto
operator||=
name|RB_ASKNAME
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|boothowto
operator||=
name|RB_SINGLE
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|boothowto
operator||=
name|RB_KDB
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
name|boothowto
operator||=
name|RB_VERBOSE
expr_stmt|;
break|break;
block|}
block|}
block|}
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_expr_stmt
name|ddb_init
argument_list|(
call|(
name|int
call|)
argument_list|(
operator|(
name|u_int
operator|)
name|endsym
operator|-
operator|(
name|u_int
operator|)
name|startsym
argument_list|)
argument_list|,
name|startsym
argument_list|,
name|endsym
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPKDB
end_ifdef

begin_comment
comment|/* 	 * Now trap to IPKDB 	 */
end_comment

begin_expr_stmt
name|ipkdb_init
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|boothowto
operator|&
name|RB_KDB
condition|)
name|ipkdb_connect
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * Set the page size. 	 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|vm_set_page_size();
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * Initialize pmap module. 	 */
end_comment

begin_expr_stmt
name|pmap_bootstrap
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|restore_ofw_mapping
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PCPU_GET
argument_list|(
name|next_asn
argument_list|)
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 0 used for proc0 pmap */
end_comment

begin_comment
comment|/* setup proc 0's pcb */
end_comment

begin_expr_stmt
name|thread0
operator|->
name|td_pcb
operator|->
name|pcb_flags
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXXKSE */
end_comment

begin_expr_stmt
name|thread0
operator|->
name|td_frame
operator|=
operator|&
name|proc0_tf
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|}  static
name|int
name|N_mapping
decl_stmt|;
end_decl_stmt

begin_struct
specifier|static
struct|struct
block|{
name|vm_offset_t
name|va
decl_stmt|;
name|int
name|len
decl_stmt|;
name|vm_offset_t
name|pa
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|}
name|ofw_mapping
index|[
literal|256
index|]
struct|;
end_struct

begin_function
name|int
name|save_ofw_mapping
parameter_list|()
block|{
name|int
name|mmui
decl_stmt|,
name|mmu
decl_stmt|;
name|OF_getprop
argument_list|(
name|chosen
argument_list|,
literal|"mmu"
argument_list|,
operator|&
name|mmui
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|mmu
operator|=
name|OF_instance_to_package
argument_list|(
name|mmui
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|ofw_mapping
argument_list|,
sizeof|sizeof
argument_list|(
name|ofw_mapping
argument_list|)
argument_list|)
expr_stmt|;
name|N_mapping
operator|=
name|OF_getprop
argument_list|(
name|mmu
argument_list|,
literal|"translations"
argument_list|,
name|ofw_mapping
argument_list|,
sizeof|sizeof
argument_list|(
name|ofw_mapping
argument_list|)
argument_list|)
expr_stmt|;
name|N_mapping
operator|/=
sizeof|sizeof
argument_list|(
name|ofw_mapping
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|restore_ofw_mapping
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|struct
name|vm_page
name|pg
decl_stmt|;
name|pmap_pinit
argument_list|(
operator|&
name|ofw_pmap
argument_list|)
expr_stmt|;
name|ofw_pmap
operator|.
name|pm_sr
index|[
name|KERNEL_SR
index|]
operator|=
name|KERNEL_SEGMENT
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|N_mapping
condition|;
name|i
operator|++
control|)
block|{
name|vm_offset_t
name|pa
init|=
name|ofw_mapping
index|[
name|i
index|]
operator|.
name|pa
decl_stmt|;
name|vm_offset_t
name|va
init|=
name|ofw_mapping
index|[
name|i
index|]
operator|.
name|va
decl_stmt|;
name|int
name|size
init|=
name|ofw_mapping
index|[
name|i
index|]
operator|.
name|len
decl_stmt|;
if|if
condition|(
name|va
operator|<
literal|0x80000000
condition|)
comment|/* XXX */
continue|continue;
while|while
condition|(
name|size
operator|>
literal|0
condition|)
block|{
name|pg
operator|.
name|phys_addr
operator|=
name|pa
expr_stmt|;
name|pmap_enter
argument_list|(
operator|&
name|ofw_pmap
argument_list|,
name|va
argument_list|,
operator|&
name|pg
argument_list|,
name|VM_PROT_ALL
argument_list|,
name|VM_PROT_ALL
argument_list|)
expr_stmt|;
name|pa
operator|+=
name|PAGE_SIZE
expr_stmt|;
name|va
operator|+=
name|PAGE_SIZE
expr_stmt|;
name|size
operator|-=
name|PAGE_SIZE
expr_stmt|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|bzero
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|caddr_t
name|p
decl_stmt|;
name|p
operator|=
name|buf
expr_stmt|;
while|while
condition|(
operator|(
operator|(
name|vm_offset_t
operator|)
name|p
operator|&
operator|(
sizeof|sizeof
argument_list|(
name|u_long
argument_list|)
operator|-
literal|1
operator|)
operator|)
operator|&&
name|len
condition|)
block|{
operator|*
name|p
operator|++
operator|=
literal|0
expr_stmt|;
name|len
operator|--
expr_stmt|;
block|}
while|while
condition|(
name|len
operator|>=
sizeof|sizeof
argument_list|(
name|u_long
argument_list|)
operator|*
literal|8
condition|)
block|{
operator|*
operator|(
name|u_long
operator|*
operator|)
name|p
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
operator|(
name|u_long
operator|*
operator|)
name|p
operator|+
literal|1
operator|)
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
operator|(
name|u_long
operator|*
operator|)
name|p
operator|+
literal|2
operator|)
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
operator|(
name|u_long
operator|*
operator|)
name|p
operator|+
literal|3
operator|)
operator|=
literal|0
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|u_long
argument_list|)
operator|*
literal|8
expr_stmt|;
operator|*
operator|(
operator|(
name|u_long
operator|*
operator|)
name|p
operator|+
literal|4
operator|)
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
operator|(
name|u_long
operator|*
operator|)
name|p
operator|+
literal|5
operator|)
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
operator|(
name|u_long
operator|*
operator|)
name|p
operator|+
literal|6
operator|)
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
operator|(
name|u_long
operator|*
operator|)
name|p
operator|+
literal|7
operator|)
operator|=
literal|0
expr_stmt|;
name|p
operator|+=
sizeof|sizeof
argument_list|(
name|u_long
argument_list|)
operator|*
literal|8
expr_stmt|;
block|}
while|while
condition|(
name|len
operator|>=
sizeof|sizeof
argument_list|(
name|u_long
argument_list|)
condition|)
block|{
operator|*
operator|(
name|u_long
operator|*
operator|)
name|p
operator|=
literal|0
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|u_long
argument_list|)
expr_stmt|;
name|p
operator|+=
sizeof|sizeof
argument_list|(
name|u_long
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|len
condition|)
block|{
operator|*
name|p
operator|++
operator|=
literal|0
expr_stmt|;
name|len
operator|--
expr_stmt|;
block|}
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void delay(unsigned n) { 	u_long tb;  	do { 		__asm __volatile("mftb %0" : "=r" (tb)); 	} while (n> (int)(tb& 0xffffffff)); }
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_43
end_ifdef

begin_function
name|void
name|osendsig
parameter_list|(
name|sig_t
name|catcher
parameter_list|,
name|int
name|sig
parameter_list|,
name|sigset_t
modifier|*
name|mask
parameter_list|,
name|u_long
name|code
parameter_list|)
block|{
comment|/* XXX: To be done */
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|sendsig
parameter_list|(
name|sig_t
name|catcher
parameter_list|,
name|int
name|sig
parameter_list|,
name|sigset_t
modifier|*
name|mask
parameter_list|,
name|u_long
name|code
parameter_list|)
block|{
comment|/* XXX: To be done */
return|return;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_43
end_ifdef

begin_function
name|int
name|osigreturn
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|osigreturn_args
modifier|*
name|uap
parameter_list|)
block|{
comment|/* XXX: To be done */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|sigreturn
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|sigreturn_args
modifier|*
name|uap
parameter_list|)
block|{
comment|/* XXX: To be done */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|void
name|cpu_boot
parameter_list|(
name|int
name|howto
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * Shutdown the CPU as much as possible.  */
end_comment

begin_function
name|void
name|cpu_halt
parameter_list|(
name|void
parameter_list|)
block|{
name|OF_exit
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Set set up registers on exec.  */
end_comment

begin_function
name|void
name|setregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|u_long
name|entry
parameter_list|,
name|u_long
name|stack
parameter_list|,
name|u_long
name|ps_strings
parameter_list|)
block|{
name|struct
name|trapframe
modifier|*
name|tf
decl_stmt|;
name|struct
name|ps_strings
name|arginfo
decl_stmt|;
name|tf
operator|=
name|trapframe
argument_list|(
name|td
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|tf
argument_list|,
sizeof|sizeof
expr|*
name|tf
argument_list|)
expr_stmt|;
name|tf
operator|->
name|fixreg
index|[
literal|1
index|]
operator|=
operator|-
name|roundup
argument_list|(
operator|-
name|stack
operator|+
literal|8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|/* 	 * XXX Machine-independent code has already copied arguments and 	 * XXX environment to userland.  Get them back here. 	 */
operator|(
name|void
operator|)
name|copyin
argument_list|(
operator|(
name|char
operator|*
operator|)
name|PS_STRINGS
argument_list|,
operator|&
name|arginfo
argument_list|,
sizeof|sizeof
argument_list|(
name|arginfo
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Set up arguments for _start(): 	 *	_start(argc, argv, envp, obj, cleanup, ps_strings); 	 * 	 * Notes: 	 *	- obj and cleanup are the auxilliary and termination 	 *	  vectors.  They are fixed up by ld.elf_so. 	 *	- ps_strings is a NetBSD extention, and will be 	 * 	  ignored by executables which are strictly 	 *	  compliant with the SVR4 ABI. 	 * 	 * XXX We have to set both regs and retval here due to different 	 * XXX calling convention in trap.c and init_main.c. 	 */
name|tf
operator|->
name|fixreg
index|[
literal|3
index|]
operator|=
name|arginfo
operator|.
name|ps_nargvstr
expr_stmt|;
name|tf
operator|->
name|fixreg
index|[
literal|4
index|]
operator|=
operator|(
name|register_t
operator|)
name|arginfo
operator|.
name|ps_argvstr
expr_stmt|;
name|tf
operator|->
name|fixreg
index|[
literal|5
index|]
operator|=
operator|(
name|register_t
operator|)
name|arginfo
operator|.
name|ps_envstr
expr_stmt|;
name|tf
operator|->
name|fixreg
index|[
literal|6
index|]
operator|=
literal|0
expr_stmt|;
comment|/* auxillary vector */
name|tf
operator|->
name|fixreg
index|[
literal|7
index|]
operator|=
literal|0
expr_stmt|;
comment|/* termination vector */
name|tf
operator|->
name|fixreg
index|[
literal|8
index|]
operator|=
operator|(
name|register_t
operator|)
name|PS_STRINGS
expr_stmt|;
comment|/* NetBSD extension */
name|tf
operator|->
name|srr0
operator|=
name|entry
expr_stmt|;
name|tf
operator|->
name|srr1
operator|=
name|PSL_MBO
operator||
name|PSL_USERSET
operator||
name|PSL_FE_DFLT
expr_stmt|;
name|td
operator|->
name|td_pcb
operator|->
name|pcb_flags
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|extint
decl_stmt|,
modifier|*
name|extsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|extint_call
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|install_extint
parameter_list|(
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|u_long
name|offset
decl_stmt|;
name|int
name|omsr
decl_stmt|,
name|msr
decl_stmt|;
name|offset
operator|=
operator|(
name|u_long
operator|)
name|handler
operator|-
operator|(
name|u_long
operator|)
operator|&
name|extint_call
expr_stmt|;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
name|offset
operator|>
literal|0x1ffffff
condition|)
name|panic
argument_list|(
literal|"install_extint: too far away"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|msr
operator|=
name|mfmsr
argument_list|()
expr_stmt|;
name|mtmsr
argument_list|(
name|msr
operator|&
operator|~
name|PSL_EE
argument_list|)
expr_stmt|;
name|extint_call
operator|=
operator|(
name|extint_call
operator|&
literal|0xfc000003
operator|)
operator||
name|offset
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|extint
argument_list|,
operator|(
name|void
operator|*
operator|)
name|EXC_EXI
argument_list|,
operator|(
name|size_t
operator|)
operator|&
name|extsize
argument_list|)
expr_stmt|;
name|__syncicache
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|extint_call
argument_list|,
sizeof|sizeof
name|extint_call
argument_list|)
expr_stmt|;
name|__syncicache
argument_list|(
operator|(
name|void
operator|*
operator|)
name|EXC_EXI
argument_list|,
operator|(
name|int
operator|)
operator|&
name|extsize
argument_list|)
expr_stmt|;
name|mtmsr
argument_list|(
name|msr
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DDB
argument_list|)
end_if

begin_function
name|void
name|Debugger
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Debugger(\"%s\") called.\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(DDB) */
end_comment

begin_comment
comment|/* XXX: dummy {fill,set}_[fp]regs */
end_comment

begin_function
name|int
name|fill_regs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|reg
modifier|*
name|regs
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
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
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|fill_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|fpreg
modifier|*
name|fpregs
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|set_regs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|reg
modifier|*
name|regs
parameter_list|)
block|{
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
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|set_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|fpreg
modifier|*
name|fpregs
parameter_list|)
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|ptrace_set_pc
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|)
block|{
comment|/* XXX: coming soon... */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|ptrace_single_step
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
comment|/* XXX: coming soon... */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|ptrace_clear_single_step
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
comment|/* XXX: coming soon... */
return|return
operator|(
name|ENOSYS
operator|)
return|;
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
name|sz
parameter_list|)
block|{
name|pcpu
operator|->
name|pc_current_asngen
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|enable_fpu
parameter_list|(
name|pcb
parameter_list|)
name|struct
name|pcb
modifier|*
name|pcb
decl_stmt|;
block|{
name|int
name|msr
decl_stmt|,
name|scratch
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|pcb
operator|->
name|pcb_flags
operator|&
name|PCB_FPU
operator|)
condition|)
block|{
name|bzero
argument_list|(
operator|&
name|pcb
operator|->
name|pcb_fpu
argument_list|,
sizeof|sizeof
name|pcb
operator|->
name|pcb_fpu
argument_list|)
expr_stmt|;
name|pcb
operator|->
name|pcb_flags
operator||=
name|PCB_FPU
expr_stmt|;
block|}
asm|__asm volatile ("mfmsr %0; ori %1,%0,%2; mtmsr %1; isync"
block|:
literal|"=r"
operator|(
name|msr
operator|)
operator|,
literal|"=r"
operator|(
name|scratch
operator|)
operator|:
literal|"K"
operator|(
name|PSL_FP
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm volatile ("lfd 0,0(%0); mtfsf 0xff,0" :: "b"(&pcb->pcb_fpu.fpscr));
end_asm

begin_asm
asm|__asm ("lfd 0,0(%0);"
end_asm

begin_expr_stmt
literal|"lfd 1,8(%0);"
literal|"lfd 2,16(%0);"
literal|"lfd 3,24(%0);"
literal|"lfd 4,32(%0);"
literal|"lfd 5,40(%0);"
literal|"lfd 6,48(%0);"
literal|"lfd 7,56(%0);"
literal|"lfd 8,64(%0);"
literal|"lfd 9,72(%0);"
literal|"lfd 10,80(%0);"
literal|"lfd 11,88(%0);"
literal|"lfd 12,96(%0);"
literal|"lfd 13,104(%0);"
literal|"lfd 14,112(%0);"
literal|"lfd 15,120(%0);"
literal|"lfd 16,128(%0);"
literal|"lfd 17,136(%0);"
literal|"lfd 18,144(%0);"
literal|"lfd 19,152(%0);"
literal|"lfd 20,160(%0);"
literal|"lfd 21,168(%0);"
literal|"lfd 22,176(%0);"
literal|"lfd 23,184(%0);"
literal|"lfd 24,192(%0);"
literal|"lfd 25,200(%0);"
literal|"lfd 26,208(%0);"
literal|"lfd 27,216(%0);"
literal|"lfd 28,224(%0);"
literal|"lfd 29,232(%0);"
literal|"lfd 30,240(%0);"
literal|"lfd 31,248(%0)"
operator|::
literal|"b"
operator|(
operator|&
name|pcb
operator|->
name|pcb_fpu
operator|.
name|fpr
index|[
literal|0
index|]
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm volatile ("mtmsr %0; isync" :: "r"(msr));
end_asm

begin_macro
unit|}  void
name|save_fpu
argument_list|(
argument|pcb
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|pcb
modifier|*
name|pcb
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|msr
decl_stmt|,
name|scratch
decl_stmt|;
asm|__asm volatile ("mfmsr %0; ori %1,%0,%2; mtmsr %1; isync"
block|:
literal|"=r"
operator|(
name|msr
operator|)
operator|,
literal|"=r"
operator|(
name|scratch
operator|)
operator|:
literal|"K"
operator|(
name|PSL_FP
operator|)
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm ("stfd 0,0(%0);"
end_asm

begin_expr_stmt
literal|"stfd 1,8(%0);"
literal|"stfd 2,16(%0);"
literal|"stfd 3,24(%0);"
literal|"stfd 4,32(%0);"
literal|"stfd 5,40(%0);"
literal|"stfd 6,48(%0);"
literal|"stfd 7,56(%0);"
literal|"stfd 8,64(%0);"
literal|"stfd 9,72(%0);"
literal|"stfd 10,80(%0);"
literal|"stfd 11,88(%0);"
literal|"stfd 12,96(%0);"
literal|"stfd 13,104(%0);"
literal|"stfd 14,112(%0);"
literal|"stfd 15,120(%0);"
literal|"stfd 16,128(%0);"
literal|"stfd 17,136(%0);"
literal|"stfd 18,144(%0);"
literal|"stfd 19,152(%0);"
literal|"stfd 20,160(%0);"
literal|"stfd 21,168(%0);"
literal|"stfd 22,176(%0);"
literal|"stfd 23,184(%0);"
literal|"stfd 24,192(%0);"
literal|"stfd 25,200(%0);"
literal|"stfd 26,208(%0);"
literal|"stfd 27,216(%0);"
literal|"stfd 28,224(%0);"
literal|"stfd 29,232(%0);"
literal|"stfd 30,240(%0);"
literal|"stfd 31,248(%0)"
operator|::
literal|"b"
operator|(
operator|&
name|pcb
operator|->
name|pcb_fpu
operator|.
name|fpr
index|[
literal|0
index|]
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm volatile ("mffs 0; stfd 0,0(%0)" :: "b"(&pcb->pcb_fpu.fpscr));
end_asm

begin_asm
asm|__asm volatile ("mtmsr %0; isync" :: "r"(msr));
end_asm

unit|}
end_unit

