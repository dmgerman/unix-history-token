begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * exit(status) - exit process with status.  */
end_comment

begin_macro
name|Xexit
argument_list|(
argument|nargs
argument_list|,
argument|arg1
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|arg1
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|defshort
argument_list|(
operator|&
name|arg1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|c_exit
argument_list|(
name|arg1
operator|.
name|value
operator|.
name|integer
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
name|struct
name|b_iproc
name|Bexit
init|=
block|{
name|T_PROC
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_proc
argument_list|)
block|,
name|EntryPoint
argument_list|(
name|Xexit
argument_list|)
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
block|{
literal|4
block|,
literal|"exit"
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

