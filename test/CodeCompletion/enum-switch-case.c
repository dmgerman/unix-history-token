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
block|}
name|unsigned
name|c2
decl_stmt|;
switch|switch
condition|(
name|c2
condition|)
block|{
case|case
block|}
end_function

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-at=%s:19:10 %s -o - | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: Blue
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Green
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Indigo
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Orange
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Violet
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-at=%s:25:10 %s -o - | FileCheck -check-prefix=CHECK-CC2 %s
end_comment

begin_comment
comment|// CHECK-CC2: COMPLETION: Blue : [#enum Color#]Blue
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: c2 : [#unsigned int#]c2
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: color : [#enum Color#]color
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: Green : [#enum Color#]Green
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: Indigo : [#enum Color#]Indigo
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: Orange : [#enum Color#]Orange
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: Red : [#enum Color#]Red
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: Pattern : [#size_t#]sizeof(<#expression-or-type#>)
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: Violet : [#enum Color#]Violet
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: COMPLETION: Yellow : [#enum Color#]Yellow
end_comment

end_unit

