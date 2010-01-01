begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s
end_comment

begin_function_decl
name|void
name|functionPromotion
parameter_list|(
name|void
name|f
parameter_list|(
name|char
modifier|*
specifier|const
type|[]
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arrayPromotion
parameter_list|(
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|whatever
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|arrayPromotion
argument_list|(
name|argv
argument_list|)
expr_stmt|;
name|functionPromotion
argument_list|(
name|arrayPromotion
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

