begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -f %t.pch
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.pch %S/Inputs/chain-decls1.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t.pch -fsyntax-only -MT %s.o -dependency-file - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: chain-decls1.h
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|f
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

