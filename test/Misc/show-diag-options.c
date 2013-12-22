begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=BASE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fdiagnostics-show-option %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=OPTION
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-show-option -Werror %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=OPTION_ERROR
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c89 -pedantic -fdiagnostics-show-option %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=OPTION_PEDANTIC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fdiagnostics-show-category id %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CATEGORY_ID
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fdiagnostics-show-category name %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CATEGORY_NAME
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-show-option -fdiagnostics-show-category name -Werror %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=OPTION_ERROR_CATEGORY
end_comment

begin_function
name|void
name|test
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
if|if
condition|(
name|x
operator|=
name|y
condition|)
operator|++
name|x
expr_stmt|;
comment|// BASE: {{.*}}: warning: {{[a-z ]+$}}
comment|// OPTION: {{.*}}: warning: {{[a-z ]+}} [-Wparentheses]
comment|// OPTION_ERROR: {{.*}}: error: {{[a-z ]+}} [-Werror,-Wparentheses]
comment|// CATEGORY_ID: {{.*}}: warning: {{[a-z ]+}} [2]
comment|// CATEGORY_NAME: {{.*}}: warning: {{[a-z ]+}} [Semantic Issue]
comment|// OPTION_ERROR_CATEGORY: {{.*}}: error: {{[a-z ]+}} [-Werror,-Wparentheses,Semantic Issue]
comment|// Leverage the fact that all these '//'s get warned about in C89 pedantic.
comment|// OPTION_PEDANTIC: {{.*}}: warning: {{[/a-z ]+}} [-Wcomment]
block|}
end_function

end_unit

