begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)crt0.c	4.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	C start up routine.  *	Robert Henry, UCB, 20 Oct 81  *  *	We make the following (true) assumptions:  *	1) when the kernel calls start, it does a jump to location 2,  *	and thus avoids the register save mask.  We are NOT called  *	with a calls!  see sys1.c:setregs().  *	2) The only register variable that we can trust is sp,  *	which points to the base of the kernel calling frame.  *	Do NOT believe the documentation in exec(2) regarding the  *	values of fp and ap.  *	3) We can allocate as many register variables as we want,  *	and don't have to save them for anybody.  *	4) Because of the ways that asm's work, we can't have  *	any automatic variables allocated on the stack, because  *	we must catch the value of sp before any automatics are  *	allocated.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm("#define _start start");
end_asm

begin_macro
name|start
argument_list|()
end_macro

begin_block
block|{
struct|struct
name|kframe
block|{
name|int
name|kargc
decl_stmt|;
name|char
modifier|*
name|kargv
index|[
literal|1
index|]
decl_stmt|;
comment|/* size depends on kargc */
name|char
name|kargstr
index|[
literal|1
index|]
decl_stmt|;
comment|/* size varies */
name|char
name|kenvstr
index|[
literal|1
index|]
decl_stmt|;
comment|/* size varies */
block|}
struct|;
comment|/* 	 *	ALL REGISTER VARIABLES!!! 	 */
specifier|register
name|struct
name|kframe
modifier|*
name|kfp
decl_stmt|;
comment|/* r11 */
specifier|register
name|char
modifier|*
modifier|*
name|targv
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
ifdef|#
directive|ifdef
name|lint
name|kfp
operator|=
literal|0
expr_stmt|;
else|#
directive|else
else|not lint
asm|asm("	movl	sp,r11");
comment|/* catch it quick */
endif|#
directive|endif
endif|not lint
for|for
control|(
name|argv
operator|=
name|targv
operator|=
operator|&
name|kfp
operator|->
name|kargv
index|[
literal|0
index|]
init|;
operator|*
name|targv
operator|++
condition|;
comment|/* void */
control|)
comment|/* void */
empty_stmt|;
if|if
condition|(
name|targv
operator|>=
operator|(
name|char
operator|*
operator|*
operator|)
operator|(
operator|*
name|argv
operator|)
condition|)
operator|--
name|targv
expr_stmt|;
name|environ
operator|=
name|targv
expr_stmt|;
name|exit
argument_list|(
name|main
argument_list|(
name|kfp
operator|->
name|kargc
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * null mcount, just in case some routine is compiled for profiling  */
end_comment

begin_asm
asm|asm("	.globl	mcount");
end_asm

begin_asm
asm|asm("mcount:	rsb");
end_asm

end_unit

