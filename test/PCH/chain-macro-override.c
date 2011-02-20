begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/Inputs/chain-macro-override1.h -include %S/Inputs/chain-macro-override2.h -fsyntax-only -verify -detailed-preprocessing-record %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t1 %S/Inputs/chain-macro-override1.h -detailed-preprocessing-record
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t2 %S/Inputs/chain-macro-override2.h -include-pch %t1 -chained-pch -detailed-preprocessing-record
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t2 -fsyntax-only -verify %s
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
name|f
argument_list|()
expr_stmt|;
name|g
argument_list|()
expr_stmt|;
name|h
argument_list|()
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

