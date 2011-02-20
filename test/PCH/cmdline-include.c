begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -include %S/cmdline-include1.h -x c-header %S/cmdline-include2.h -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t -fsyntax-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c-header %S/cmdline-include1.h -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t -include %S/cmdline-include2.h -fsyntax-only -verify
end_comment

begin_decl_stmt
name|int
name|g
init|=
name|x1
operator|+
name|x2
decl_stmt|;
end_decl_stmt

end_unit

