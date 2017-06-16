begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ast-print %s -o %t.1.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ast-print %t.1.c -o %t.2.c
end_comment

begin_comment
comment|// RUN: diff %t.1.c %t.2.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ast-dump %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ast-dump-all %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -print-decl-contexts %s
end_comment

begin_include
include|#
directive|include
file|"c-language-features.inc"
end_include

end_unit

