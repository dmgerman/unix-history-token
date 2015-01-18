begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -triple x86_64-linux-gnu -std=c89 %s -o - | FileCheck --check-prefix=CHECK-NO-1X %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -triple x86_64-linux-gnu -std=iso9899:199409 %s -o - | FileCheck --check-prefix=CHECK-NO-1X %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -triple x86_64-linux-gnu -std=c99 %s -o - | FileCheck --check-prefix=CHECK-NO-1X %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -triple x86_64-linux-gnu -std=c11 %s -o - | FileCheck --check-prefix=CHECK-1X %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -triple x86_64-linux-gnu -std=gnu89 %s -o - | FileCheck --check-prefix=CHECK-NO-1X %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -triple x86_64-linux-gnu -std=gnu99 %s -o - | FileCheck --check-prefix=CHECK-NO-1X %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -triple x86_64-linux-gnu -std=gnu11 %s -o - | FileCheck --check-prefix=CHECK-1X %s
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|c_atomic
argument_list|)
end_if

begin_function_decl
name|int
name|has_atomic
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_atomic
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-1X: has_atomic
end_comment

begin_comment
comment|// CHECK-NO-1X: no_atomic
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|c_static_assert
argument_list|)
end_if

begin_function_decl
name|int
name|has_static_assert
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_static_assert
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-1X: has_static_assert
end_comment

begin_comment
comment|// CHECK-NO-1X: no_static_assert
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|c_generic_selections
argument_list|)
end_if

begin_function_decl
name|int
name|has_generic_selections
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_generic_selections
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-1X: has_generic_selections
end_comment

begin_comment
comment|// CHECK-NO-1X: no_generic_selections
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|c_alignas
argument_list|)
end_if

begin_function_decl
name|int
name|has_alignas
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_alignas
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-1X: has_alignas
end_comment

begin_comment
comment|// CHECK-NO-1X: no_alignas
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|c_alignof
argument_list|)
end_if

begin_function_decl
name|int
name|has_alignof
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_alignof
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-1X: has_alignof
end_comment

begin_comment
comment|// CHECK-NO-1X: no_alignof
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|c_thread_local
argument_list|)
end_if

begin_function_decl
name|int
name|has_thread_local
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_thread_local
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-1X: has_thread_local
end_comment

begin_comment
comment|// CHECK-NO-1X: no_thread_local
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>
literal|199901L
end_if

begin_function_decl
name|int
name|is_c1x
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|is_not_c1x
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-1X: is_c1x
end_comment

begin_comment
comment|// CHECK-NO-1X: is_not_c1x
end_comment

end_unit

