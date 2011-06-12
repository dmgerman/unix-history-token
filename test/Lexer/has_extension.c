begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s -o - | FileCheck --check-prefix=CHECK-PED-NONE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pedantic-errors -E %s -o - | FileCheck --check-prefix=CHECK-PED-ERR %s
end_comment

begin_comment
comment|// CHECK-PED-NONE: no_dummy_extension
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_extension
argument_list|(
name|dummy_extension
argument_list|)
end_if

begin_function_decl
name|int
name|no_dummy_extension
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Arbitrary feature to test that has_extension is a superset of has_feature
end_comment

begin_comment
comment|// CHECK-PED-NONE: attribute_overloadable
end_comment

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|attribute_overloadable
argument_list|)
end_if

begin_function_decl
name|int
name|attribute_overloadable
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-PED-NONE: has_c_static_assert
end_comment

begin_comment
comment|// CHECK-PED-ERR: no_c_static_assert
end_comment

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|c_static_assert
argument_list|)
end_if

begin_function_decl
name|int
name|has_c_static_assert
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_c_static_assert
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-PED-NONE: has_c_generic_selections
end_comment

begin_comment
comment|// CHECK-PED-ERR: no_c_generic_selections
end_comment

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|c_generic_selections
argument_list|)
end_if

begin_function_decl
name|int
name|has_c_generic_selections
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_c_generic_selections
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

