begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: echo "#include<stddef.h>"> %t.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -g -include %t.h %s -emit-llvm -o %t.ll
end_comment

begin_comment
comment|// RUN: grep "i32 5" %t.ll
end_comment

begin_comment
comment|// outer is at line number 5.
end_comment

begin_decl_stmt
name|int
name|outer
init|=
literal|42
decl_stmt|;
end_decl_stmt

end_unit

