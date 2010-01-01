begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep "@pipe()" %t | count 0
end_comment

begin_comment
comment|// RUN: grep '_thisIsNotAPipe' %t | count 3
end_comment

begin_comment
comment|// RUN: grep 'g0' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '_renamed' %t | count 2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DUSE_DEF -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep "@pipe()" %t | count 0
end_comment

begin_comment
comment|// RUN: grep '_thisIsNotAPipe' %t | count 3
end_comment

begin_comment
comment|//<rdr://6116729>
end_comment

begin_expr_stmt
name|void
name|pipe
argument_list|()
end_expr_stmt

begin_asm
asm|asm("_thisIsNotAPipe");
end_asm

begin_function
name|void
name|f0
parameter_list|()
block|{
name|pipe
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|pipe
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f1
parameter_list|()
block|{
name|pipe
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|USE_DEF
end_ifdef

begin_function
name|void
name|pipe
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
name|int
name|x
init|=
literal|10
decl_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR3698
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g0
name|asm
argument_list|(
literal|"_renamed"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f2
parameter_list|()
block|{
return|return
name|g0
return|;
block|}
end_function

end_unit

