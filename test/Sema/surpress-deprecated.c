begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only -Wno-deprecated-declarations -verify %s
end_comment

begin_function_decl
specifier|extern
name|void
name|OldFunction
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|OldFunction
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

