begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)genassym.c	5.11 (Berkeley) 5/10/91  *	$Id: genassym.c,v 1.50 1997/10/10 12:38:27 peter Exp $  */
end_comment

begin_include
include|#
directive|include
file|"opt_vm86.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/tss.h>
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
file|<vm/vm_param.h>
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

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_comment
comment|/* XXX avoid user headers */
end_comment

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfsv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/rpcv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfsdiskless.h>
end_include

begin_decl_stmt
name|int
decl|main
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
name|printf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|struct
name|proc
modifier|*
name|p
init|=
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|vmmeter
modifier|*
name|vm
init|=
operator|(
expr|struct
name|vmmeter
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|user
modifier|*
name|up
init|=
operator|(
expr|struct
name|user
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|rusage
modifier|*
name|rup
init|=
operator|(
expr|struct
name|rusage
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|uprof
modifier|*
name|uprof
init|=
operator|(
expr|struct
name|uprof
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|vmspace
modifier|*
name|vms
init|=
operator|(
expr|struct
name|vmspace
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|pcb
modifier|*
name|pcb
init|=
operator|(
expr|struct
name|pcb
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|i386tss
modifier|*
name|tss
init|=
operator|(
expr|struct
name|i386tss
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|trapframe
modifier|*
name|tf
init|=
operator|(
expr|struct
name|trapframe
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|sigframe
modifier|*
name|sigf
init|=
operator|(
expr|struct
name|sigframe
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|bootinfo
modifier|*
name|bootinfo
init|=
operator|(
expr|struct
name|bootinfo
operator|*
operator|)
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"#define\tP_FORW %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_procq
operator|.
name|tqe_next
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_BACK %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_procq
operator|.
name|tqe_prev
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_VMSPACE %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_vmspace
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tVM_PMAP %p\n"
argument_list|,
operator|&
name|vms
operator|->
name|vm_pmap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_ADDR %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_addr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_PRI %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_priority
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_RTPRIO_TYPE %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_rtprio
operator|.
name|type
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_RTPRIO_PRIO %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_rtprio
operator|.
name|prio
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_STAT %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_stat
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_WCHAN %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_wchan
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_FLAG %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_flag
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_PID %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_pid
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SMP
name|printf
argument_list|(
literal|"#define\tP_ONCPU %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_oncpu
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_LASTCPU %p\n"
argument_list|,
operator|&
name|p
operator|->
name|p_lastcpu
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"#define\tSSLEEP %d\n"
argument_list|,
name|SSLEEP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSRUN %d\n"
argument_list|,
name|SRUN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_TRAP %p\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_trap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_SYSCALL %p\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_syscall
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_INTR %p\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_intr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUPAGES %d\n"
argument_list|,
name|UPAGES
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPAGE_SIZE %d\n"
argument_list|,
name|PAGE_SIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNPTEPG %d\n"
argument_list|,
name|NPTEPG
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNPDEPG %d\n"
argument_list|,
name|NPDEPG
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPDESIZE %d\n"
argument_list|,
name|PDESIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPTESIZE %d\n"
argument_list|,
name|PTESIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNKPDE %d\n"
argument_list|,
name|NKPDE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNKPT %d\n"
argument_list|,
name|NKPT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPAGE_SHIFT %d\n"
argument_list|,
name|PAGE_SHIFT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPAGE_MASK %d\n"
argument_list|,
name|PAGE_MASK
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPDRSHIFT %d\n"
argument_list|,
name|PDRSHIFT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUSRSTACK 0x%lx\n"
argument_list|,
name|USRSTACK
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tVM_MAXUSER_ADDRESS 0x%lx\n"
argument_list|,
name|VM_MAXUSER_ADDRESS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tKERNBASE 0x%x\n"
argument_list|,
name|KERNBASE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMCLBYTES %d\n"
argument_list|,
name|MCLBYTES
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_CR3 %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_cr3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EDI %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_edi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ESI %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_esi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EBP %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ebp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ESP %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_esp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EBX %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ebx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EIP %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_eip
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTSS_ESP0 %p\n"
argument_list|,
operator|&
name|tss
operator|->
name|tss_esp0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_USERLDT %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ldt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_FS %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_fs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_GS %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_gs
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VM86
name|printf
argument_list|(
literal|"#define\tPCB_EXT %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ext
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VM86 */
ifdef|#
directive|ifdef
name|SMP
name|printf
argument_list|(
literal|"#define\tPCB_MPNEST %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_mpnest
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"#define\tU_PROF %p\n"
argument_list|,
operator|&
name|up
operator|->
name|u_stats
operator|.
name|p_prof
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PROFSCALE %p\n"
argument_list|,
operator|&
name|up
operator|->
name|u_stats
operator|.
name|p_prof
operator|.
name|pr_scale
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPR_BASE %p\n"
argument_list|,
operator|&
name|uprof
operator|->
name|pr_base
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPR_SIZE %p\n"
argument_list|,
operator|&
name|uprof
operator|->
name|pr_size
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPR_OFF %p\n"
argument_list|,
operator|&
name|uprof
operator|->
name|pr_off
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPR_SCALE %p\n"
argument_list|,
operator|&
name|uprof
operator|->
name|pr_scale
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tRU_MINFLT %p\n"
argument_list|,
operator|&
name|rup
operator|->
name|ru_minflt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_FLAGS %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_flags
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SAVEFPU %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_savefpu
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SAVEFPU_SIZE %d\n"
argument_list|,
sizeof|sizeof
name|pcb
operator|->
name|pcb_savefpu
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ONFAULT %p\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_onfault
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ES %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_es
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_DS %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ds
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EDI %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_edi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ESI %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_esi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EBP %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ebp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ISP %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_isp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EBX %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ebx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EDX %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_edx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ECX %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ecx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EAX %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_eax
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_TRAPNO %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_trapno
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ERR %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_err
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EIP %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_eip
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_CS %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_cs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EFLAGS %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_eflags
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ESP %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_esp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_SS %p\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ss
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_SIGNUM %p\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_signum
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_CODE %p\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_code
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_SCP %p\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_scp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_HANDLER %p\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_handler
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_SC %p\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_sc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tB_READ %d\n"
argument_list|,
name|B_READ
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tENOENT %d\n"
argument_list|,
name|ENOENT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tEFAULT %d\n"
argument_list|,
name|EFAULT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tENAMETOOLONG %d\n"
argument_list|,
name|ENAMETOOLONG
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMAXPATHLEN %d\n"
argument_list|,
name|MAXPATHLEN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tBOOTINFO_SIZE %d\n"
argument_list|,
sizeof|sizeof
expr|*
name|bootinfo
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tBI_VERSION %p\n"
argument_list|,
operator|&
name|bootinfo
operator|->
name|bi_version
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tBI_KERNELNAME %p\n"
argument_list|,
operator|&
name|bootinfo
operator|->
name|bi_kernelname
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tBI_NFS_DISKLESS %p\n"
argument_list|,
operator|&
name|bootinfo
operator|->
name|bi_nfs_diskless
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tBI_ENDCOMMON %p\n"
argument_list|,
operator|&
name|bootinfo
operator|->
name|bi_endcommon
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNFSDISKLESS_SIZE %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|nfs_diskless
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tBI_SIZE %p\n"
argument_list|,
operator|&
name|bootinfo
operator|->
name|bi_size
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tBI_SYMTAB %p\n"
argument_list|,
operator|&
name|bootinfo
operator|->
name|bi_symtab
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tBI_ESYMTAB %p\n"
argument_list|,
operator|&
name|bootinfo
operator|->
name|bi_esymtab
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

