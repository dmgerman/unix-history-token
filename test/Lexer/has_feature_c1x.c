begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -std=c1x %s -o - | FileCheck --check-prefix=CHECK-1X %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s -o - | FileCheck --check-prefix=CHECK-NO-1X %s
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

end_unit

