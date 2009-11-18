begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -include %S/asm.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-pch -o %t %S/asm.h
end_comment

begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -include-pch %t -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|call_f
parameter_list|(
name|void
parameter_list|)
block|{
name|f
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|call_clobbers
parameter_list|(
name|void
parameter_list|)
block|{
name|clobbers
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

