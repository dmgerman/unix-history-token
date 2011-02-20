begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep llvm.global.annotations
end_comment

begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep llvm.var.annotation | count 3
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Global variable with attribute */
end_comment

begin_decl_stmt
name|int
name|X
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"GlobalValAnnotation"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function with attribute */
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(annotate
parameter_list|(
function_decl|"GlobalValAnnotation"
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|foo
argument_list|(
name|int
name|y
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"LocalValAnnotation"
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"LocalValAnnotation"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|x
operator|=
literal|34
expr_stmt|;
return|return
name|y
operator|+
name|x
return|;
block|}
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|static
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"GlobalValAnnotation"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|a
operator|=
name|foo
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"hello world%d\n"
argument_list|,
name|a
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

