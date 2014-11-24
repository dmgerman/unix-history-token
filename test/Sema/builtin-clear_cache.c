begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-none-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|__clear_cache
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|)
block|{}
end_function

end_unit

