begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 387 and 287 Numeric Coprocessor Extension (NPX) Driver.  * @(#)npx.c	1.1 (Berkeley) %G%  */
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
name|driver
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
name|user
modifier|*
name|npxutl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* owners user structure */
end_comment

begin_decl_stmt
name|struct
name|pte
modifier|*
name|Npxmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel ptes mapping owner's user structure */
end_comment

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
name|device
modifier|*
name|dvp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|status
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
asm|asm("	fninit");
comment|/* put device in known state */
comment|/* check for a proper status of zero */
name|status
operator|=
literal|0xa5a5
expr_stmt|;
asm|asm("	movw	%1,%%ax ; fnstsw %%ax ;  movw %%ax, %0" 		: "=g" (status) : "g" (status) : "ax");
if|if
condition|(
name|status
operator|==
literal|0
condition|)
block|{
specifier|register
name|control
expr_stmt|;
comment|/* good, now check for a proper control word */
name|control
operator|=
literal|0xa5a5
expr_stmt|;
asm|asm("	movw	%1,%%ax ; fnstcw %%ax ;  movw %%ax, %0" 			: "=g" (control) : "g" (control) : "ax");
if|if
condition|(
name|control
operator|&
literal|0x103f
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
name|device
modifier|*
name|dvp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|unit
init|=
name|dvp
operator|->
name|unit
decl_stmt|;
name|npxinit
argument_list|()
expr_stmt|;
comment|/* check for ET bit to decide 387/287 */
name|INTREN
argument_list|(
name|IRQ13
argument_list|)
expr_stmt|;
comment|/*outb(0xb1,0);		/* reset processor */
block|}
end_block

begin_comment
comment|/*  * Initialize floating point unit, usually after an error  */
end_comment

begin_macro
name|npxinit
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|control
expr_stmt|;
asm|asm ("	fninit");
name|control
operator|=
name|XXX
expr_stmt|;
asm|asm("	movw	%0,%%ax ; fldcw %%ax " 			: "g" (control) : "ax");
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
name|u
operator|.
name|u_procp
expr_stmt|;
name|uaccess
argument_list|(
name|npxproc
argument_list|,
name|Npxmap
argument_list|,
operator|&
name|npxutl
argument_list|)
expr_stmt|;
asm|asm("	frstor %0 " : "g" (u.u_pcb.pcb_savefpu) );
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
asm|asm("	fsave %0 " : "g" (npxutl.u_pcb.pcb_savefpu) );
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
name|npxexcept
argument_list|()
end_macro

begin_block
block|{
comment|/* save state in appropriate user structure */
if|if
condition|(
name|npxproc
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"npxexcept"
argument_list|)
expr_stmt|;
asm|asm ("	fsave %0 " : "g" (npxutl.u_pcb.pcb_savefpu) );
comment|/* 	 * encode the appropriate u_code for detailed information          * on this exception 	 */
comment|/* signal appropriate process */
name|psignal
argument_list|(
name|npxproc
argument_list|,
name|SIGFPE
argument_list|)
expr_stmt|;
comment|/* clear the exception so we can catch others like it */
asm|asm ("	fnclex");
block|}
end_block

begin_comment
comment|/*  * Catch AT/386 interrupt used to signal exception, and simulate trap()  */
end_comment

begin_macro
name|npxintr
argument_list|()
end_macro

begin_block
block|{
name|outb
argument_list|(
literal|0xf0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pg
argument_list|(
literal|"npxintr"
argument_list|)
expr_stmt|;
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
block|{ }
end_block

end_unit

