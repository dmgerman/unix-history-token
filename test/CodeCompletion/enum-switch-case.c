begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_enum
enum|enum
name|Color
block|{
name|Red
block|,
name|Orange
block|,
name|Yellow
block|,
name|Green
block|,
name|Blue
block|,
name|Indigo
block|,
name|Violet
block|}
enum|;
end_enum

begin_function
name|void
name|test
parameter_list|(
name|enum
name|Color
name|color
parameter_list|)
block|{
switch|switch
condition|(
name|color
condition|)
block|{
case|case
name|Red
case|:
break|break;
case|case
name|Yellow
case|:
break|break;
case|case
name|Green
case|:
break|break;
end_function

begin_comment
comment|// RUN: clang-cc -fsyntax-only -code-completion-at=%s:19:10 %s -o - | FileCheck -check-prefix=CC1 %s&&
end_comment

begin_comment
comment|// CHECK-CC1: Blue : 0
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Green : 0
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Indigo : 0
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Orange : 0
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Violet : 0
end_comment

begin_comment
comment|// RUN: true
end_comment

end_unit

