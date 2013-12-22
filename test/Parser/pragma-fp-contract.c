begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|/* expected-error@+1 {{'#pragma fp_contract' can only appear at file scope or at the start of a compound statement}} */
pragma|#
directive|pragma
name|STDC
name|FP_CONTRACT
name|ON
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
pragma|#
directive|pragma
name|STDC
name|FP_CONTRACT
name|OFF
pragma|#
directive|pragma
name|STDC
name|FP_CONTRACT
name|ON
block|}
end_function

end_unit

