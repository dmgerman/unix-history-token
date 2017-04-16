begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,unix -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Testing core functionality of the SValBuilder.
end_comment

begin_function
name|int
name|SValBuilderLogicNoCrash
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
return|return
literal|3
operator|-
call|(
name|int
call|)
argument_list|(
name|x
operator|+
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// http://llvm.org/bugs/show_bug.cgi?id=15863
end_comment

begin_comment
comment|// Don't crash when mixing 'bool' and 'int' in implicit comparisons to 0.
end_comment

begin_function
name|void
name|pr15863
parameter_list|()
block|{
specifier|extern
name|int
name|getBool
parameter_list|()
function_decl|;
name|_Bool
name|a
init|=
name|getBool
argument_list|()
decl_stmt|;
operator|(
name|void
operator|)
operator|!
name|a
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

