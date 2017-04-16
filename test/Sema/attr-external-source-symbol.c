begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fblocks -verify %s
end_comment

begin_function_decl
name|void
name|threeClauses
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(external_source_symbol
parameter_list|(
name|language
init|=
literal|"Swift"
parameter_list|,
name|defined_in
init|=
literal|"module"
parameter_list|,
name|generated_declaration
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|twoClauses
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(external_source_symbol
parameter_list|(
name|language
init|=
literal|"Swift"
parameter_list|,
name|defined_in
init|=
literal|"module"
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|fourClauses
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(external_source_symbol
parameter_list|(
name|language
init|=
literal|"Swift"
parameter_list|,
name|defined_in
init|=
literal|"module"
parameter_list|,
name|generated_declaration
parameter_list|,
name|generated_declaration
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{duplicate 'generated_declaration' clause in an 'external_source_symbol' attribute}}
end_comment

begin_function_decl
name|void
name|oneClause
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(external_source_symbol
parameter_list|(
name|generated_declaration
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|noArguments
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(external_source_symbol
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'external_source_symbol' attribute takes at least 1 argument}}
end_comment

begin_function
name|void
name|namedDeclsOnly
parameter_list|()
block|{
name|int
function_decl|(
modifier|^
name|block
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|^
operator|(
name|void
operator|)
name|__attribute__
argument_list|(
argument|(external_source_symbol(language=
literal|"Swift"
argument|))
argument_list|)
block|{
comment|// expected-warning {{'external_source_symbol' attribute only applies to named declarations}}
return|return
literal|1
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

unit|}
end_unit

