begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that fopen(NULL, "r") is ok.
end_comment

begin_comment
comment|// RUN: %clang -O2 %s -o %t&& %run %t
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|fn
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|f
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|f
operator|=
name|fopen
argument_list|(
name|fn
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

