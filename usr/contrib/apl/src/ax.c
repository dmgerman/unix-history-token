begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"ax.c @(#)ax.c	1.1	10/1/82 Berkeley "
decl_stmt|;
end_decl_stmt

begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	Floating-point initialization and trap service  *  *	On the PDP-11's the code in "ax.pdp.s" is preferred  *	since it enables the FPP for all floating exception  *	traps and fishes out the cause of an exception from  *	the FPP error register.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|fpelist
index|[]
init|=
block|{
literal|"floating exception"
block|,
literal|"integer overflow"
block|,
literal|"integer divide by zero"
block|,
literal|"floating overflow"
block|,
literal|"floating divide by zero"
block|,
literal|"floating underflow"
block|,
literal|"decimal overflow"
block|,
literal|"subscript range"
block|,
literal|"floating overflow"
block|,
literal|"floating divide by zero"
block|,
literal|"floating underflow"
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|fpe
argument_list|(
argument|signo
argument_list|,
argument|param
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|param
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|fpe
argument_list|)
expr_stmt|;
if|if
condition|(
name|param
operator|>=
sizeof|sizeof
name|fpelist
operator|/
sizeof|sizeof
name|fpelist
index|[
literal|0
index|]
condition|)
name|error
argument_list|(
literal|"floating exception"
argument_list|)
expr_stmt|;
else|else
name|error
argument_list|(
name|fpelist
index|[
name|param
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|fpe
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|fpe
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"floating exception"
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|fppinit
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|fpe
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

