begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c99 -E %s -o - | FileCheck --check-prefix=CHECK-PED-NONE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -pedantic-errors -E %s -o - | FileCheck --check-prefix=CHECK-PED-ERR %s
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

begin_comment
comment|// CHECK-PED-NONE: has_c_alignas
end_comment

begin_comment
comment|// CHECK-PED-ERR: no_c_alignas
end_comment

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|c_alignas
argument_list|)
end_if

begin_function_decl
name|int
name|has_c_alignas
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_c_alignas
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-PED-NONE: has_c_alignof
end_comment

begin_comment
comment|// CHECK-PED-ERR: no_c_alignof
end_comment

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|c_alignof
argument_list|)
end_if

begin_function_decl
name|int
name|has_c_alignof
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|no_c_alignof
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Arbitrary feature to test that the extension name can be surrounded with
end_comment

begin_comment
comment|// double underscores.
end_comment

begin_comment
comment|// CHECK-PED-NONE: has_double_underscores
end_comment

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|__c_alignas__
argument_list|)
end_if

begin_function_decl
name|int
name|has_double_underscores
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

