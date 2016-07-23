begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This test checks the patch for the compilation error / crash described in D18557.
end_comment

begin_comment
comment|// Test as a C source
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -x c-header -o %t %S/Inputs/__va_list_tag-typedef.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -include-pch %t %s
end_comment

begin_comment
comment|// Test as a C++ source
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -x c++-header -o %t %S/Inputs/__va_list_tag-typedef.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -fsyntax-only -include-pch %t %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_typedef
typedef|typedef
name|__builtin_va_list
name|va_list_2
typedef|;
end_typedef

begin_function
name|void
name|test
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

