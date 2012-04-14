begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// rdar://10961370
end_comment

begin_typedef
typedef|typedef
name|struct
name|__CFError
modifier|*
name|CFErrorRef
typedef|;
end_typedef

begin_comment
comment|// expected-note {{forward declaration of 'struct __CFError'}}
end_comment

begin_function_decl
name|void
name|junk
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|CFErrorRef
name|error
decl_stmt|;
name|junk
argument_list|(
literal|1
argument_list|,
operator|*
name|error
argument_list|,
operator|(
name|void
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{argument type 'struct __CFError' is incomplete}} \
comment|// expected-error {{argument type 'void' is incomplete}}
block|}
end_function

end_unit

