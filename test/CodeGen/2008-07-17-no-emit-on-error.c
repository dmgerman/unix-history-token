begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -f %t1.bc
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DPASS %s -emit-llvm-bc -o %t1.bc
end_comment

begin_comment
comment|// RUN: test -f %t1.bc
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -emit-llvm-bc -o %t1.bc
end_comment

begin_comment
comment|// RUN: not test -f %t1.bc
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|PASS
end_ifndef

begin_function
name|void
name|g
parameter_list|()
block|{
operator|*
literal|10
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

