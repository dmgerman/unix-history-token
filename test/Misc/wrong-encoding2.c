begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fmessage-length 100 %s 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// REQUIRES: asserts
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
literal|"É#x#p
literal|)6Ò
literal|)Ñ½$û>U êhÑüÃö| à¦¥Ï»g
literal|Y|`
literal|?ò;
literal|;Æ¿V
literal|jÇ\\
literal|ùûÝªW9úÐ
literal|¢:ÌO EøÛ
literal|y?SKªy¦¹Øài&n"
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-NOT:Assertion
end_comment

end_unit

