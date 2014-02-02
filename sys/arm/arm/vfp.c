begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012 Mark Tinguely  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|VFP
end_ifdef

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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/fp.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/undefined.h>
end_include

begin_include
include|#
directive|include
file|<machine/vfp.h>
end_include

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|unsigned
name|int
name|get_coprocessorACR
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfp_bounce
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_discard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_restore
parameter_list|(
name|struct
name|vfp_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_store
parameter_list|(
name|struct
name|vfp_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_coprocessorACR
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|vfp_exists
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|undefined_handler
name|vfp10_uh
decl_stmt|,
name|vfp11_uh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If true the VFP unit has 32 double registers, otherwise it has 16 */
end_comment

begin_decl_stmt
specifier|static
name|int
name|is_d32
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The VFMXR command using coprocessor commands */
end_comment

begin_define
define|#
directive|define
name|fmxr
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|__asm __volatile("mcr p10, 7, %0, " __STRING(reg) " , c0, 0" :: "r"(val));
end_define

begin_comment
comment|/* The VFMRX command using coprocessor commands */
end_comment

begin_define
define|#
directive|define
name|fmrx
parameter_list|(
name|reg
parameter_list|)
define|\
value|({ u_int val = 0;\     __asm __volatile("mrc p10, 7, %0, " __STRING(reg) " , c0, 0" : "=r"(val));\     val; \ })
end_define

begin_function
name|u_int
name|get_coprocessorACR
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|val
decl_stmt|;
asm|__asm __volatile("mrc p15, 0, %0, c1, c0, 2" : "=r" (val) : : "cc");
return|return
name|val
return|;
block|}
end_function

begin_function
name|void
name|set_coprocessorACR
parameter_list|(
name|u_int
name|val
parameter_list|)
block|{
asm|__asm __volatile("mcr p15, 0, %0, c1, c0, 2\n\t"
block|: :
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"cc"
block|)
function|;
end_function

begin_expr_stmt
name|isb
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/* called for each cpu */
end_comment

begin_macro
unit|void
name|vfp_init
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|u_int
name|fpsid
decl_stmt|,
name|fpexc
decl_stmt|,
name|tmp
decl_stmt|;
name|u_int
name|coproc
decl_stmt|,
name|vfp_arch
decl_stmt|;
name|coproc
operator|=
name|get_coprocessorACR
argument_list|()
expr_stmt|;
name|coproc
operator||=
name|COPROC10
operator||
name|COPROC11
expr_stmt|;
name|set_coprocessorACR
argument_list|(
name|coproc
argument_list|)
expr_stmt|;
name|fpsid
operator|=
name|fmrx
argument_list|(
name|VFPSID
argument_list|)
expr_stmt|;
comment|/* read the vfp system id */
name|fpexc
operator|=
name|fmrx
argument_list|(
name|VFPEXC
argument_list|)
expr_stmt|;
comment|/* read the vfp exception reg */
if|if
condition|(
operator|!
operator|(
name|fpsid
operator|&
name|VFPSID_HARDSOFT_IMP
operator|)
condition|)
block|{
name|vfp_exists
operator|=
literal|1
expr_stmt|;
name|is_d32
operator|=
literal|0
expr_stmt|;
name|PCPU_SET
argument_list|(
name|vfpsid
argument_list|,
name|fpsid
argument_list|)
expr_stmt|;
comment|/* save the VFPSID */
name|vfp_arch
operator|=
operator|(
name|fpsid
operator|&
name|VFPSID_SUBVERSION2_MASK
operator|)
operator|>>
name|VFPSID_SUBVERSION_OFF
expr_stmt|;
if|if
condition|(
name|vfp_arch
operator|>=
name|VFP_ARCH3
condition|)
block|{
name|tmp
operator|=
name|fmrx
argument_list|(
name|VMVFR0
argument_list|)
expr_stmt|;
name|PCPU_SET
argument_list|(
name|vfpmvfr0
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|tmp
operator|&
name|VMVFR0_RB_MASK
operator|)
operator|==
literal|2
condition|)
name|is_d32
operator|=
literal|1
expr_stmt|;
name|tmp
operator|=
name|fmrx
argument_list|(
name|VMVFR1
argument_list|)
expr_stmt|;
name|PCPU_SET
argument_list|(
name|vfpmvfr1
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
block|}
comment|/* initialize the coprocess 10 and 11 calls 		 * These are called to restore the registers and enable 		 * the VFP hardware. 		 */
if|if
condition|(
name|vfp10_uh
operator|.
name|uh_handler
operator|==
name|NULL
condition|)
block|{
name|vfp10_uh
operator|.
name|uh_handler
operator|=
name|vfp_bounce
expr_stmt|;
name|vfp11_uh
operator|.
name|uh_handler
operator|=
name|vfp_bounce
expr_stmt|;
name|install_coproc_handler_static
argument_list|(
literal|10
argument_list|,
operator|&
name|vfp10_uh
argument_list|)
expr_stmt|;
name|install_coproc_handler_static
argument_list|(
literal|11
argument_list|,
operator|&
name|vfp11_uh
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

begin_expr_stmt
name|SYSINIT
argument_list|(
name|vfp
argument_list|,
name|SI_SUB_CPU
argument_list|,
name|SI_ORDER_ANY
argument_list|,
name|vfp_init
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* start VFP unit, restore the vfp registers from the PCB  and retry  * the instruction  */
end_comment

begin_function
name|int
name|vfp_bounce
parameter_list|(
name|u_int
name|addr
parameter_list|,
name|u_int
name|insn
parameter_list|,
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|,
name|int
name|code
parameter_list|)
block|{
name|u_int
name|fpexc
decl_stmt|;
name|struct
name|pcb
modifier|*
name|curpcb
decl_stmt|;
name|struct
name|thread
modifier|*
name|vfptd
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|!
name|vfp_exists
condition|)
return|return
literal|1
return|;
comment|/* vfp does not exist */
name|i
operator|=
name|disable_interrupts
argument_list|(
name|I32_bit
operator||
name|F32_bit
argument_list|)
expr_stmt|;
name|fpexc
operator|=
name|fmrx
argument_list|(
name|VFPEXC
argument_list|)
expr_stmt|;
comment|/* read the vfp exception reg */
if|if
condition|(
name|fpexc
operator|&
name|VFPEXC_EN
condition|)
block|{
name|vfptd
operator|=
name|PCPU_GET
argument_list|(
name|vfpcthread
argument_list|)
expr_stmt|;
comment|/* did the kernel call the vfp or exception that expect us 		 * to emulate the command. Newer hardware does not require 		 * emulation, so we don't emulate yet. 		 */
ifdef|#
directive|ifdef
name|SMP
comment|/* don't save if newer registers are on another processor */
if|if
condition|(
name|vfptd
comment|/*&& (vfptd == curthread) */
operator|&&
operator|(
name|vfptd
operator|->
name|td_pcb
operator|->
name|pcb_vfpcpu
operator|==
name|PCPU_GET
argument_list|(
name|cpu
argument_list|)
operator|)
condition|)
else|#
directive|else
comment|/* someone did not save their registers, */
if|if
condition|(
name|vfptd
comment|/*&& (vfptd == curthread) */
condition|)
endif|#
directive|endif
name|vfp_store
argument_list|(
operator|&
name|vfptd
operator|->
name|td_pcb
operator|->
name|pcb_vfpstate
argument_list|)
expr_stmt|;
name|fpexc
operator|&=
operator|~
name|VFPEXC_EN
expr_stmt|;
name|fmxr
argument_list|(
name|VFPEXC
argument_list|,
name|fpexc
argument_list|)
expr_stmt|;
comment|/* turn vfp hardware off */
if|if
condition|(
name|vfptd
operator|==
name|curthread
condition|)
block|{
comment|/* kill the process - we do not handle emulation */
name|restore_interrupts
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|killproc
argument_list|(
name|curthread
operator|->
name|td_proc
argument_list|,
literal|"vfp emulation"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
comment|/* should not happen. someone did not save their context */
name|printf
argument_list|(
literal|"vfp_bounce: vfpcthread: %p curthread: %p\n"
argument_list|,
name|vfptd
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
block|}
name|fpexc
operator||=
name|VFPEXC_EN
expr_stmt|;
name|fmxr
argument_list|(
name|VFPEXC
argument_list|,
name|fpexc
argument_list|)
expr_stmt|;
comment|/* enable the vfp and repeat command */
name|curpcb
operator|=
name|curthread
operator|->
name|td_pcb
expr_stmt|;
comment|/* If we were the last process to use the VFP, the process did not 	 * use a VFP on another processor, then the registers in the VFP 	 * will still be ours and are current. Eventually, we will make the 	 * restore smarter. 	 */
name|vfp_restore
argument_list|(
operator|&
name|curpcb
operator|->
name|pcb_vfpstate
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SMP
name|curpcb
operator|->
name|pcb_vfpcpu
operator|=
name|PCPU_GET
argument_list|(
name|cpu
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|PCPU_SET
argument_list|(
name|vfpcthread
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|restore_interrupts
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* vfs_store is called from from a VFP command to restore the registers and  * turn on the VFP hardware.  * Eventually we will use the information that this process was the last  * to use the VFP hardware and bypass the restore, just turn on the hardware.  */
end_comment

begin_function
name|void
name|vfp_restore
parameter_list|(
name|struct
name|vfp_state
modifier|*
name|vfpsave
parameter_list|)
block|{
name|u_int
name|vfpscr
init|=
literal|0
decl_stmt|;
comment|/* 	 * Work around an issue with GCC where the asm it generates is 	 * not unified syntax and fails to assemble because it expects 	 * the ldcleq instruction in the form ldc<c>l, not in the UAL 	 * form ldcl<c>, and similar for stcleq. 	 */
ifdef|#
directive|ifdef
name|__clang__
define|#
directive|define
name|ldclne
value|"ldclne"
define|#
directive|define
name|stclne
value|"stclne"
else|#
directive|else
define|#
directive|define
name|ldclne
value|"ldcnel"
define|#
directive|define
name|stclne
value|"stcnel"
endif|#
directive|endif
if|if
condition|(
name|vfpsave
condition|)
block|{
asm|__asm __volatile("ldc	p10, c0, [%1], #128\n"
comment|/* d0-d15 */
literal|"cmp	%2, #0\n"
comment|/* -D16 or -D32? */
name|ldclne
literal|"	p11, c0, [%1], #128\n"
comment|/* d16-d31 */
literal|"addeq	%1, %1, #128\n"
comment|/* skip missing regs */
literal|"ldr	%0, [%1]\n"
comment|/* set old vfpscr */
literal|"mcr	p10, 7, %0, cr1, c0, 0\n"
operator|:
literal|"=&r"
operator|(
name|vfpscr
operator|)
operator|:
literal|"r"
operator|(
name|vfpsave
operator|)
operator|,
literal|"r"
operator|(
name|is_d32
operator|)
operator|:
literal|"cc"
block|)
empty_stmt|;
block|}
end_function

begin_comment
unit|}
comment|/* vfs_store is called from switch to save the vfp hardware registers  * into the pcb before switching to another process.  * we already know that the new process is different from this old  * process and that this process last used the VFP registers.  * Below we check to see if the VFP has been enabled since the last  * register save.  * This routine will exit with the VFP turned off. The next VFP user  * will trap to restore its registers and turn on the VFP hardware.  */
end_comment

begin_macro
unit|void
name|vfp_store
argument_list|(
argument|struct vfp_state *vfpsave
argument_list|)
end_macro

begin_block
block|{
name|u_int
name|tmp
decl_stmt|,
name|vfpscr
init|=
literal|0
decl_stmt|;
name|tmp
operator|=
name|fmrx
argument_list|(
name|VFPEXC
argument_list|)
expr_stmt|;
comment|/* Is the vfp enabled? */
if|if
condition|(
name|vfpsave
operator|&&
operator|(
name|tmp
operator|&
name|VFPEXC_EN
operator|)
condition|)
block|{
asm|__asm __volatile("stc	p11, c0, [%1], #128\n"
comment|/* d0-d15 */
literal|"cmp	%2, #0\n"
comment|/* -D16 or -D32? */
name|stclne
literal|"	p11, c0, [%1], #128\n"
comment|/* d16-d31 */
literal|"addeq	%1, %1, #128\n"
comment|/* skip missing regs */
literal|"mrc	p10, 7, %0, cr1, c0, 0\n"
comment|/* fmxr(VFPSCR) */
literal|"str	%0, [%1]\n"
comment|/* save vfpscr */
operator|:
literal|"=&r"
operator|(
name|vfpscr
operator|)
operator|:
literal|"r"
operator|(
name|vfpsave
operator|)
operator|,
literal|"r"
operator|(
name|is_d32
operator|)
operator|:
literal|"cc"
block|)
empty_stmt|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|ldcleq
end_undef

begin_undef
undef|#
directive|undef
name|stcleq
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_comment
comment|/* eventually we will use this information for UP also */
end_comment

begin_expr_stmt
name|PCPU_SET
argument_list|(
name|vfpcthread
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|tmp
operator|&=
operator|~
name|VFPEXC_EN
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* disable the vfp hardware */
end_comment

begin_expr_stmt
name|fmxr
argument_list|(
name|VFPEXC
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/* discard the registers at cpu_thread_free() when fpcurthread == td.  * Turn off the VFP hardware.  */
end_comment

begin_macro
unit|void
name|vfp_discard
argument_list|()
end_macro

begin_block
block|{
name|u_int
name|tmp
init|=
literal|0
decl_stmt|;
comment|/* 	 * No need to protect the access to vfpcthread by disabling 	 * interrupts, since it's called from cpu_throw(), who is called 	 * with interrupts disabled. 	 */
name|PCPU_SET
argument_list|(
name|vfpcthread
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* permanent forget about reg */
name|tmp
operator|=
name|fmrx
argument_list|(
name|VFPEXC
argument_list|)
expr_stmt|;
name|tmp
operator|&=
operator|~
name|VFPEXC_EN
expr_stmt|;
comment|/* turn off VFP hardware */
name|fmxr
argument_list|(
name|VFPEXC
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Enable the VFP hardware without restoring registers.  * Called when the registers are still in the VFP unit  */
end_comment

begin_function
name|void
name|vfp_enable
parameter_list|()
block|{
name|u_int
name|tmp
init|=
literal|0
decl_stmt|;
name|tmp
operator|=
name|fmrx
argument_list|(
name|VFPEXC
argument_list|)
expr_stmt|;
name|tmp
operator||=
name|VFPEXC_EN
expr_stmt|;
name|fmxr
argument_list|(
name|VFPEXC
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

