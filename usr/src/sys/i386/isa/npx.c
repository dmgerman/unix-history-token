begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 William Jolitz.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)npx.c	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"npx.h"
end_include

begin_if
if|#
directive|if
name|NNPX
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"machine/cpu.h"
end_include

begin_include
include|#
directive|include
file|"machine/pcb.h"
end_include

begin_include
include|#
directive|include
file|"machine/trap.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"machine/specialreg.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/isa_device.h"
end_include

begin_include
include|#
directive|include
file|"icu.h"
end_include

begin_comment
comment|/*  * 387 and 287 Numeric Coprocessor Extension (NPX) Driver.  */
end_comment

begin_decl_stmt
name|int
name|npxprobe
argument_list|()
decl_stmt|,
name|npxattach
argument_list|()
decl_stmt|,
name|npxintr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|isa_driver
name|npxdriver
init|=
block|{
name|npxprobe
block|,
name|npxattach
block|,
literal|"npx"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|npxproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process who owns device, otherwise zero */
end_comment

begin_decl_stmt
name|struct
name|pcb
modifier|*
name|npxpcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* owners context structure */
end_comment

begin_expr_stmt
specifier|static
name|npxexists
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|long
name|npx0mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Probe routine - look device, otherwise set emulator bit  */
end_comment

begin_macro
name|npxprobe
argument_list|(
argument|dvp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|isa_device
modifier|*
name|dvp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|status
operator|,
name|control
expr_stmt|;
ifdef|#
directive|ifdef
name|lint
name|npxintr
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* insure EM bit off */
asm|asm("	fninit ");
comment|/* put device in known state */
comment|/* check for a proper status of zero */
name|status
operator|=
literal|0xa5a5
expr_stmt|;
asm|asm ("	fnstsw	%0 " : "=m" (status) : "m" (status) );
if|if
condition|(
name|status
operator|==
literal|0
condition|)
block|{
comment|/* good, now check for a proper control word */
name|control
operator|=
literal|0xa5a5
expr_stmt|;
asm|asm ("	fnstcw %0 " : "=m" (control) : "m" (control));
if|if
condition|(
operator|(
name|control
operator|&
literal|0x103f
operator|)
operator|==
literal|0x3f
condition|)
block|{
comment|/* then we have a numeric coprocessor */
comment|/* XXX should force an exception here to generate an intr */
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
comment|/* insure EM bit on */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Attach routine - announce which it is, and wire into system  */
end_comment

begin_macro
name|npxattach
argument_list|(
argument|dvp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|isa_device
modifier|*
name|dvp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|npxinit
argument_list|(
literal|0x262
argument_list|)
expr_stmt|;
comment|/* check for ET bit to decide 387/287 */
comment|/*outb(0xb1,0);		/* reset processor */
name|npxexists
operator|++
expr_stmt|;
name|npx0mask
operator|=
name|dvp
operator|->
name|id_irq
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Initialize floating point unit, usually after an error  */
end_comment

begin_macro
name|npxinit
argument_list|(
argument|control
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|npxexists
operator|==
literal|0
condition|)
return|return;
name|load_cr0
argument_list|(
name|rcr0
argument_list|()
operator|&
operator|~
name|CR0_EM
argument_list|)
expr_stmt|;
comment|/* stop emulating */
ifdef|#
directive|ifdef
name|INTEL_COMPAT
asm|asm ("	finit");
asm|asm("	fldcw %0" : : "g" (control));
asm|asm("	fnsave %0 " : : "g" (curpcb->pcb_savefpu) );
else|#
directive|else
asm|asm("fninit");
asm|asm("	fnsave %0 " : : "g" (curpcb->pcb_savefpu) );
endif|#
directive|endif
name|load_cr0
argument_list|(
name|rcr0
argument_list|()
operator||
name|CR0_EM
argument_list|)
expr_stmt|;
comment|/* start emulating */
block|}
end_block

begin_comment
comment|/*  * Load floating point context and record ownership to suite  */
end_comment

begin_macro
name|npxload
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|npxproc
condition|)
name|panic
argument_list|(
literal|"npxload"
argument_list|)
expr_stmt|;
name|npxproc
operator|=
name|curproc
expr_stmt|;
name|npxpcb
operator|=
name|curpcb
expr_stmt|;
asm|asm("	frstor %0 " : : "g" (curpcb->pcb_savefpu) );
block|}
end_block

begin_comment
comment|/*  * Unload floating point context and relinquish ownership  */
end_comment

begin_macro
name|npxunload
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|npxproc
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"npxunload"
argument_list|)
expr_stmt|;
asm|asm("	fsave %0 " : : "g" (npxpcb->pcb_savefpu) );
name|npxproc
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Record information needed in processing an exception and clear status word  */
end_comment

begin_macro
name|npxintr
argument_list|(
argument|frame
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|intrframe
name|frame
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|trapframe
name|tf
decl_stmt|;
name|outb
argument_list|(
literal|0xf0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* reset processor */
comment|/* sync state in process context structure, in advance of debugger/process looking for it */
if|if
condition|(
name|npxproc
operator|==
literal|0
operator|||
name|npxexists
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"npxintr"
argument_list|)
expr_stmt|;
asm|asm ("	fnsave %0 " : : "g" (npxpcb->pcb_savefpu) );
comment|/* 	 * Prepair a trap frame for our generic exception processing routine, trap() 	 */
name|bcopy
argument_list|(
operator|&
name|frame
operator|.
name|if_es
argument_list|,
operator|&
name|tf
argument_list|,
sizeof|sizeof
argument_list|(
name|tf
argument_list|)
argument_list|)
expr_stmt|;
name|tf
operator|.
name|tf_trapno
operator|=
name|T_ARITHTRAP
expr_stmt|;
ifdef|#
directive|ifdef
name|notyet
comment|/* encode the appropriate code for detailed information on this exception */
name|tf
operator|.
name|tf_err
operator|=
operator|???
expr_stmt|;
endif|#
directive|endif
name|trap
argument_list|(
name|tf
argument_list|)
expr_stmt|;
comment|/* 	 * Restore with any changes to superior frame 	 */
name|bcopy
argument_list|(
operator|&
name|tf
argument_list|,
operator|&
name|frame
operator|.
name|if_es
argument_list|,
sizeof|sizeof
argument_list|(
name|tf
argument_list|)
argument_list|)
expr_stmt|;
comment|/* clear the exception so we can catch others like it */
asm|asm ("	fnclex");
block|}
end_block

begin_comment
comment|/*  * Implement device not available (DNA) exception  */
end_comment

begin_macro
name|npxdna
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|npxexists
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|!
operator|(
name|curpcb
operator|->
name|pcb_flags
operator|&
name|FP_WASUSED
operator|)
operator|||
operator|(
name|curpcb
operator|->
name|pcb_flags
operator|&
name|FP_NEEDSRESTORE
operator|)
condition|)
block|{
name|load_cr0
argument_list|(
name|rcr0
argument_list|()
operator|&
operator|~
name|CR0_EM
argument_list|)
expr_stmt|;
comment|/* stop emulating */
asm|asm("	frstor %0 " : : "g" (curpcb->pcb_savefpu));
name|curpcb
operator|->
name|pcb_flags
operator||=
name|FP_WASUSED
operator||
name|FP_NEEDSSAVE
expr_stmt|;
name|curpcb
operator|->
name|pcb_flags
operator|&=
operator|~
name|FP_NEEDSRESTORE
expr_stmt|;
name|npxproc
operator|=
name|curproc
expr_stmt|;
name|npxpcb
operator|=
name|curpcb
expr_stmt|;
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
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

