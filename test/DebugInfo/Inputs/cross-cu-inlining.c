begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// To generate the test file:
end_comment

begin_comment
comment|// clang cross-cu-inlining.c -DA_C -g -emit-llvm -S -o a.ll
end_comment

begin_comment
comment|// clang cross-cu-inlining.c -DB_C -g -emit-llvm -S -o b.ll
end_comment

begin_comment
comment|// llvm-link a.ll b.ll -o ab.bc
end_comment

begin_comment
comment|// opt -inline ab.bc -o cross-cu-inlining.bc
end_comment

begin_comment
comment|// clang -c cross-cu-inlining.bc -o cross-cu-inlining.o
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|A_C
end_ifdef

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|func
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|func
argument_list|(
name|i
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|B_C
end_ifdef

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
name|func
argument_list|(
name|int
name|x
argument_list|)
block|{
return|return
name|x
operator|*
literal|2
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

