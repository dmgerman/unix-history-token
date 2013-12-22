begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_decl_stmt
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|returns_twice
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'returns_twice' attribute only applies to functions}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(returns_twice)
argument_list|)
end_macro

begin_function
name|void
name|t0
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(returns_twice
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|t2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(returns_twice
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'returns_twice' attribute takes no arguments}}
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|t3
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(returns_twice
typedef|));
end_typedef

begin_comment
comment|// expected-warning {{'returns_twice' attribute only applies to functions}}
end_comment

end_unit

