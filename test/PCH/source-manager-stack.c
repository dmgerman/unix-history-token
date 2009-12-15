begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that the source manager has the "proper" idea about the include stack
end_comment

begin_comment
comment|// when using PCH.
end_comment

begin_comment
comment|// RUN: echo 'int x;'> %t.prefix.h
end_comment

begin_comment
comment|// RUN: not clang-cc -fsyntax-only -include %t.prefix.h %s 2> %t.diags.no_pch.txt
end_comment

begin_comment
comment|// RUN: clang-cc -emit-pch -o %t.prefix.pch %t.prefix.h
end_comment

begin_comment
comment|// RUN: not clang-cc -fsyntax-only -include-pch %t.prefix.pch %s 2> %t.diags.pch.txt
end_comment

begin_comment
comment|// RUN: diff %t.diags.no_pch.txt %t.diags.pch.txt
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// PR5662
end_comment

begin_decl_stmt
name|float
name|x
decl_stmt|;
end_decl_stmt

end_unit

