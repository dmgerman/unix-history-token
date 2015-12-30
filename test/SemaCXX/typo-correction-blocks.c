begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-macosx -fblocks -fsyntax-only -verify %s
end_comment

begin_function_decl
specifier|extern
name|int
name|h
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|g
parameter_list|(
name|int
parameter_list|,
name|void
function_decl|(
modifier|^
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|fuzzys
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{'fuzzys' declared here}}
end_comment

begin_function
specifier|static
name|void
name|f
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
block|{
name|g
argument_list|(
name|fuzzy
argument_list|,
lambda|^
block|{
comment|// expected-error {{did you mean 'fuzzys'}}
name|int
name|i
init|=
name|h
argument_list|(
name|v
argument_list|)
decl_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

