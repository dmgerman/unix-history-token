begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-module -o %t/macros.pcm -DMODULE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -fmodule-cache-path %t -fdisable-module-hash %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -fmodule-cache-path %t -fdisable-module-hash %s | FileCheck -check-prefix CHECK-PREPROCESSED %s
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MODULE
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTEGER
parameter_list|(
name|X
parameter_list|)
value|int
end_define

begin_define
define|#
directive|define
name|FLOAT
value|float
end_define

begin_define
define|#
directive|define
name|DOUBLE
value|double
end_define

begin_empty
empty|#__export_macro__ INTEGER
end_empty

begin_empty
empty|#__export_macro__ DOUBLE
end_empty

begin_expr_stmt
name|int
argument_list|(
name|INTEGER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|__import_module__
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
empty|#__export_macro__ WIBBLE
end_empty

begin_comment
comment|// expected-error{{no macro named 'WIBBLE' to export}}
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

