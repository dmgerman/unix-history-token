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

begin_struct
struct|struct
name|Z
block|{ }
struct|;
end_struct

begin_function_decl
name|void
name|X
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
enum|enum
name|X
block|{
name|x
block|}
enum|;
enum_decl|enum
end_function

begin_comment
comment|// RUN: clang-cc -fsyntax-only -code-completion-at=%s:9:7 %s -o - | FileCheck -check-prefix=CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: X : 0
end_comment

begin_comment
comment|// CHECK-CC1: Y : 2
end_comment

end_unit

