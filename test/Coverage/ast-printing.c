begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc --fsyntax-only %s
end_comment

begin_comment
comment|// RUN: clang-cc --ast-print %s
end_comment

begin_comment
comment|// RUN: clang-cc --ast-dump %s
end_comment

begin_comment
comment|// RUN: clang-cc --ast-print-xml -o %t %s
end_comment

begin_include
include|#
directive|include
file|"c-language-features.inc"
end_include

end_unit

