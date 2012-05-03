begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s 2>&1 | FileCheck -strict-whitespace %s
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
comment|/*ð¿*/
literal|1
operator|)
condition|)
empty_stmt|;
comment|// CHECK: {{^    if\(\(i==/\*<U\+1F47F>\*/1\)\);}}
comment|// CHECK: {{^        ~\^~~~~~~~~~~~~~~~}}
comment|// CHECK: {{^       ~ \^               ~}}
comment|/* ð¿ */
literal|"ð¿berhund"
expr_stmt|;
comment|// CHECK: {{^    /\*<U\+1F47F> \*/ "<U\+1F47F>berhund";}}
comment|// CHECK: {{^                    \^~~~~~~~~~~~~~~~~~}}
block|}
end_function

end_unit

