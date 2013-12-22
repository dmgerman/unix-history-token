begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_enum
enum|enum
name|X
block|{
name|x
block|}
enum|;
end_enum

begin_enum
enum|enum
name|Y
block|{
name|y
block|}
enum|;
end_enum

begin_enum_decl
enum_decl|enum
end_enum_decl

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-at=-:4:6< %s -o - | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: X
end_comment

begin_comment
comment|// CHECK-CC1: Y
end_comment

end_unit

