begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-linux -E %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: always_inline
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|always_inline
argument_list|)
end_if

begin_function_decl
name|int
name|always_inline
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: __always_inline__
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|__always_inline__
argument_list|)
end_if

begin_function_decl
name|int
name|__always_inline__
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: no_dummy_attribute
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_attribute
argument_list|(
name|dummy_attribute
argument_list|)
end_if

begin_function_decl
name|int
name|no_dummy_attribute
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: has_has_attribute
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__has_attribute
end_ifdef

begin_function_decl
name|int
name|has_has_attribute
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: has_something_we_dont_have
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_attribute
argument_list|(
name|something_we_dont_have
argument_list|)
end_if

begin_function_decl
name|int
name|has_something_we_dont_have
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// rdar://10253857
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|__const
argument_list|)
end_if

begin_function_decl
name|int
name|fn3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
specifier|const
argument_list|)
end_if

begin_function_decl
specifier|static
name|int
name|constFunction
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: has_no_volatile_attribute
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_attribute
argument_list|(
specifier|volatile
argument_list|)
end_if

begin_function_decl
name|int
name|has_no_volatile_attribute
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: has_arm_interrupt
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|interrupt
argument_list|)
end_if

begin_function_decl
name|int
name|has_arm_interrupt
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: does_not_have_dllexport
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_attribute
argument_list|(
name|dllexport
argument_list|)
end_if

begin_function_decl
name|int
name|does_not_have_dllexport
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

