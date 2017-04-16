begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-apple-darwin10 -analyzer-checker=core,debug.ExprInspection -analyzer-config ipa=none -fblocks -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-apple-darwin10 -analyzer-checker=core,debug.ExprInspection -analyzer-config ipa=none -fblocks -verify -x c++ %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|testInvalidation
parameter_list|()
block|{
specifier|__block
name|int
name|i
init|=
literal|0
decl_stmt|;
lambda|^
block|{
operator|++
name|i
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
comment|// Under inlining, we will know that i == 1.
name|clang_analyzer_eval
argument_list|(
name|i
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

begin_decl_stmt
specifier|const
name|int
name|globalConstant
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|testCapturedConstants
parameter_list|()
block|{
specifier|const
name|int
name|localConstant
init|=
literal|2
decl_stmt|;
specifier|static
specifier|const
name|int
name|staticConstant
init|=
literal|3
decl_stmt|;
lambda|^
block|{
name|clang_analyzer_eval
argument_list|(
name|globalConstant
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
name|localConstant
operator|==
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
name|staticConstant
operator|==
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
specifier|const
name|int
name|constInt
typedef|;
end_typedef

begin_decl_stmt
name|constInt
name|anotherGlobalConstant
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|testCapturedConstantsTypedef
parameter_list|()
block|{
name|constInt
name|localConstant
init|=
literal|2
decl_stmt|;
specifier|static
name|constInt
name|staticConstant
init|=
literal|3
decl_stmt|;
lambda|^
block|{
name|clang_analyzer_eval
argument_list|(
name|anotherGlobalConstant
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
name|localConstant
operator|==
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
name|staticConstant
operator|==
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

