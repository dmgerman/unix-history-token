begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -E %s "-DX=A
end_comment

begin_comment
comment|// RUN: THIS_SHOULD_NOT_EXIST_IN_THE_OUTPUT"> %t
end_comment

begin_comment
comment|// RUN: grep "GOOD: A" %t
end_comment

begin_comment
comment|// RUN: not grep THIS_SHOULD_NOT_EXIST_IN_THE_OUTPUT %t
end_comment

begin_comment
comment|// rdar://6762183
end_comment

begin_label
name|GOOD
label|:
end_label

begin_macro
name|X
end_macro

end_unit

