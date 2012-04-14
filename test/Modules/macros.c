begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodule-cache-path %t -fmodule-name=macros %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -verify -fmodule-cache-path %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -fmodules -x objective-c -fmodule-cache-path %t %s | FileCheck -check-prefix CHECK-PREPROCESSED %s
end_comment

begin_comment
comment|// FIXME: When we have a syntax for modules in C, use that.
end_comment

begin_decl_stmt
unit|@
name|__experimental_modules_import
name|macros
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGER
end_ifndef

begin_error
error|#
directive|error
error|INTEGER macro should be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT
end_ifdef

begin_error
error|#
directive|error
error|FLOAT macro should not be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MODULE
end_ifdef

begin_error
error|#
directive|error
error|MODULE macro should not be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-PREPROCESSED: double d
end_comment

begin_decl_stmt
name|double
name|d
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DOUBLE
modifier|*
name|dp
init|=
operator|&
name|d
decl_stmt|;
end_decl_stmt

begin_empty
empty|#__public_macro WIBBLE
end_empty

begin_comment
comment|// expected-error{{no macro named 'WIBBLE'}}
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
comment|// CHECK-PREPROCESSED: int i = INTEGER;
name|int
name|i
init|=
name|INTEGER
decl_stmt|;
comment|// the value was exported, the macro was not.
block|}
end_function

end_unit

