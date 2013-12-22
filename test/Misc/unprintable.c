begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 %s -fmessage-length 40 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|(
name|i
operator|==
comment|/*ï¿¾*/
literal|1
operator|)
condition|)
empty_stmt|;
comment|// CHECK: {{^    if\(\(i==/\*<U\+FFFE>\*/1\)\);}}
comment|// CHECK: {{^        ~\^~~~~~~~~~~~~~~}}
comment|// CHECK: {{^       ~ \^              ~}}
operator|(
name|void
operator|)
literal|"Êï¿¾ô"
expr_stmt|;
comment|// CHECK: {{^    \(void\)"<CA><U\+FFFE><F4>";}}
comment|// CHECK: {{^           \^~~~}}
name|Â 
name|int
name|n
init|=
literal|0
decl_stmt|;
comment|// CHECK: {{ int n = 0;}}
comment|// CHECK: {{^\^}}
literal|"ï¿¾                                                               \z"
expr_stmt|;
comment|// CHECK: {{^  \.\.\.\\z";}}
comment|// CHECK: {{^     \^~}}
comment|/* ï¿¾ */
literal|"ï¿¾berhund"
expr_stmt|;
comment|// CHECK: {{^    /\*<U\+FFFE> \*/ "<U\+FFFE>berhund";}}
comment|// CHECK: {{^                   \^~~~~~~~~~~~~~~~~}}
comment|// PR14292
literal|"x°xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
comment|// CHECK: {{^    "x<B0>}}
comment|// CHECK: {{^    \^}}
block|}
end_function

end_unit

