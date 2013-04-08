begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-freebsd10.0 -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|/* Define a size_t as expected for FreeBSD ARM */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_comment
comment|/* Declare a builtin function that uses size_t */
end_comment

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

