begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	reset.c	4.2	90/06/23	*/
end_comment

begin_comment
comment|/*  * This can't be written in C.  You have to longjmp from a context  * below (stackwise) the call to setjmp:  *  *	/* test reset/setexit *(/  *	main()  *	{  *		int i = setexit();  *		printf("i=%d\n", i);  *		if (i == 0)  *			reset(1);  *	}  *  * The above prints `longjmp botch' and dumps core.  */
end_comment

begin_comment
comment|/*  * Backwards compatible setexit/reset.  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
specifier|static
name|jmp_buf
name|save
decl_stmt|;
end_decl_stmt

begin_macro
name|setexit
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|setjmp
argument_list|(
name|save
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|reset
argument_list|(
argument|x
argument_list|)
end_macro

begin_block
block|{
name|longjmp
argument_list|(
name|save
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

