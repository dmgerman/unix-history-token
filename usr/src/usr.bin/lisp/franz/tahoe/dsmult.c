begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982, Regents, University of California */
end_comment

begin_comment
comment|/*  * dsmult(top,bot,mul) --  * multiply an array of longs on the stack, by mul.  * the element top through bot (inclusive) get changed.  * if you expect a carry out of the most significant,  * it is up to you to provide a space for it to overflow.  */
end_comment

begin_struct
struct|struct
name|vl
block|{
name|long
name|high
decl_stmt|;
name|long
name|low
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|dsmult
argument_list|(
argument|top
argument_list|,
argument|bot
argument_list|,
argument|mul
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|top
decl_stmt|,
modifier|*
name|bot
decl_stmt|,
name|mul
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|long
modifier|*
name|p
decl_stmt|;
name|struct
name|vl
name|work
decl_stmt|;
name|long
name|add
init|=
literal|0
decl_stmt|;
for|for
control|(
name|p
operator|=
name|top
init|;
name|p
operator|>=
name|bot
condition|;
name|p
operator|--
control|)
block|{
asm|asm("emul	(r12),12(fp),-64(fp),-60(fp)");
comment|/* *p has 30 bits of info, mul has 32 yielding a 62 bit product. */
operator|*
name|p
operator|=
name|work
operator|.
name|low
operator|&
literal|0x3fffffff
expr_stmt|;
comment|/* the stack gets the low 30 bits */
name|add
operator|=
name|work
operator|.
name|high
expr_stmt|;
comment|/* we want add to get the next 32 bits. 					   on a 68k you might better be able to 					   do this by shifts and tests on the 					   carry but I don't know how to do this 					   from C, and the code generated here 					   will not be much worse.  Far less 					   bad than shifting work.low to the 					   right 30 bits just to get the top 2. 					   */
name|add
operator|<<=
literal|2
expr_stmt|;
if|if
condition|(
name|work
operator|.
name|low
operator|<
literal|0
condition|)
name|add
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
name|work
operator|.
name|low
operator|&
literal|0x40000000
condition|)
name|add
operator|+=
literal|1
expr_stmt|;
block|}
name|p
index|[
literal|1
index|]
operator|=
name|work
operator|.
name|low
expr_stmt|;
comment|/* on the final store want all 32 bits. */
block|}
end_block

end_unit

