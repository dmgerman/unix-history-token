begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o /dev/null
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o /dev/null -x c++
end_comment

begin_comment
comment|// This file contains UTF-8; please do not fix!
end_comment

begin_extern
extern|extern void \u00FCber(int
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern void \U000000FCber(int
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// redeclaration, no warning
end_comment

begin_function
name|void
name|goodCalls
parameter_list|()
block|{
operator|\
name|u00FCber
argument_list|(
literal|0
argument_list|)
expr_stmt|;
operator|\
name|u00fcber
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|Ã¼ber
argument_list|(
literal|2
argument_list|)
expr_stmt|;
operator|\
name|U000000FCber
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

