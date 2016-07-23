begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: llvm-dsymutil -f -oso-prepend-path=%p/.. %p/../Inputs/thumb.armv7m -o - | llvm-dwarfdump - | FileCheck %s
end_comment

begin_comment
comment|// RUN: llvm-dsymutil -arch armv7m -f -oso-prepend-path=%p/.. %p/../Inputs/thumb.armv7m -o - | llvm-dwarfdump - | FileCheck %s
end_comment

begin_comment
comment|/* Compile with:    clang -c thumb.c -arch armv7m -g    clang thumb.o -o thumb.armv7m -arch armv7m -nostdlib -static -Wl,-e,_start */
end_comment

begin_function
name|void
name|start
parameter_list|()
block|{ }
end_function

begin_label
name|CHECK
label|:
end_label

begin_macro
name|DW_AT_name
end_macro

begin_block
block|{
block|{
operator|.*
block|}
block|}
end_block

begin_expr_stmt
literal|"thumb.c"
name|CHECK
operator|:
name|DW_AT_name
block|{
block|{
operator|.*
block|}
block|}
literal|"start"
end_expr_stmt

end_unit

