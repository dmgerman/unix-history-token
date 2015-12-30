begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c99 -E %s -o - | FileCheck --check-prefix=CHECK-NONE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=gnu89 -E %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-GNU-KEYWORDS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fgnu-keywords -E %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-GNU-KEYWORDS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=gnu89 -fno-gnu-keywords -E %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-NONE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fms-extensions -E %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-MS-KEYWORDS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fdeclspec -E %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-DECLSPEC-KEYWORD %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fms-extensions -fno-declspec -E %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-MS-KEYWORDS-WITHOUT-DECLSPEC %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
comment|// CHECK-NONE: int asm
comment|// CHECK-GNU-KEYWORDS: asm ("ret" : :)
if|#
directive|if
name|__is_identifier
argument_list|(
name|asm
argument_list|)
name|int
name|asm
decl_stmt|;
else|#
directive|else
asm|asm ("ret" : :);
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// CHECK-NONE: no_ms_wchar
end_comment

begin_comment
comment|// CHECK-MS-KEYWORDS: has_ms_wchar
end_comment

begin_comment
comment|// CHECK-MS-KEYWORDS-WITHOUT-DECLSPEC: has_ms_wchar
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|(
name|__wchar_t
argument_list|)
end_if

begin_function_decl
name|void
name|no_ms_wchar
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|has_ms_wchar
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-NONE: no_declspec
end_comment

begin_comment
comment|// CHECK-MS-KEYWORDS: has_declspec
end_comment

begin_comment
comment|// CHECK-MS-KEYWORDS-WITHOUT-DECLSPEC: no_declspec
end_comment

begin_comment
comment|// CHECK-DECLSPEC-KEYWORD: has_declspec
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|(
name|__declspec
argument_list|)
end_if

begin_function_decl
name|void
name|no_declspec
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|has_declspec
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

