begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=macros_top %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=macros_left %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=macros_right %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=macros %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -verify -fmodules-cache-path=%t -I %S/Inputs %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -E -fmodules -x objective-c -fmodules-cache-path=%t -I %S/Inputs %s | FileCheck -check-prefix CHECK-PREPROCESSED %s
end_comment

begin_comment
comment|// FIXME: When we have a syntax for modules in C, use that.
end_comment

begin_comment
comment|// These notes come from headers in modules, and are bogus.
end_comment

begin_comment
comment|// FIXME: expected-note@Inputs/macros_left.h:11{{previous definition is here}}
end_comment

begin_comment
comment|// FIXME: expected-note@Inputs/macros_right.h:12{{previous definition is here}}
end_comment

begin_comment
comment|// expected-note@Inputs/macros_right.h:12{{expanding this definition of 'LEFT_RIGHT_DIFFERENT'}}
end_comment

begin_comment
comment|// expected-note@Inputs/macros_right.h:13{{expanding this definition of 'LEFT_RIGHT_DIFFERENT2'}}
end_comment

begin_comment
comment|// expected-note@Inputs/macros_left.h:14{{other definition of 'LEFT_RIGHT_DIFFERENT'}}
end_comment

begin_decl_stmt
unit|@
name|import
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
name|i
operator|+=
name|macros
expr_stmt|;
comment|// expanded from __MODULE__ within the 'macros' module.
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__MODULE__
end_ifdef

begin_error
error|#
directive|error
error|Not building a module!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__building_module
argument_list|(
name|macros
argument_list|)
end_if

begin_error
error|#
directive|error
error|Not building a module
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// None of the modules we depend on have been imported, and therefore
end_comment

begin_comment
comment|// their macros should not be visible.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LEFT
end_ifdef

begin_error
error|#
directive|error
error|LEFT should not be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RIGHT
end_ifdef

begin_error
error|#
directive|error
error|RIGHT should not be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TOP
end_ifdef

begin_error
error|#
directive|error
error|TOP should not be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Import left module (which also imports top)
end_comment

begin_decl_stmt
unit|@
name|import
name|macros_left
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|LEFT
end_ifndef

begin_error
error|#
directive|error
error|LEFT should be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RIGHT
end_ifdef

begin_error
error|#
directive|error
error|RIGHT should not be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TOP
end_ifndef

begin_error
error|#
directive|error
error|TOP should be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TOP_LEFT_UNDEF
end_ifdef

begin_error
error|#
directive|error
error|TOP_LEFT_UNDEF should not be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|test1
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|TOP_RIGHT_REDEF
modifier|*
name|ip
init|=
operator|&
name|i
decl_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|LEFT_RIGHT_DIFFERENT2
value|double
end_define

begin_comment
comment|// FIXME: expected-warning{{'LEFT_RIGHT_DIFFERENT2' macro redefined}} \
end_comment

begin_comment
comment|// expected-note{{other definition of 'LEFT_RIGHT_DIFFERENT2'}}
end_comment

begin_comment
comment|// Import right module (which also imports top)
end_comment

begin_decl_stmt
unit|@
name|import
name|macros_right
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|LEFT_RIGHT_DIFFERENT3
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|LEFT
end_ifndef

begin_error
error|#
directive|error
error|LEFT should be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RIGHT
end_ifndef

begin_error
error|#
directive|error
error|RIGHT should be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TOP
end_ifndef

begin_error
error|#
directive|error
error|TOP should be visible
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|test2
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
name|double
name|d
decl_stmt|;
name|TOP_RIGHT_REDEF
modifier|*
name|fp
init|=
operator|&
name|f
decl_stmt|;
comment|// ok, right's definition overrides top's definition
name|LEFT_RIGHT_IDENTICAL
modifier|*
name|ip
init|=
operator|&
name|i
decl_stmt|;
name|LEFT_RIGHT_DIFFERENT
modifier|*
name|ip2
init|=
operator|&
name|i
decl_stmt|;
comment|// expected-warning{{ambiguous expansion of macro 'LEFT_RIGHT_DIFFERENT'}}
name|LEFT_RIGHT_DIFFERENT2
modifier|*
name|ip3
init|=
operator|&
name|i
decl_stmt|;
comment|// expected-warning{{ambiguous expansion of macro 'LEFT_RIGHT_DIFFERENT2}}
name|int
name|LEFT_RIGHT_DIFFERENT3
decl_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|LEFT_RIGHT_DIFFERENT
value|double
end_define

begin_comment
comment|// FIXME: expected-warning{{'LEFT_RIGHT_DIFFERENT' macro redefined}}
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
name|double
name|d
decl_stmt|;
name|LEFT_RIGHT_DIFFERENT
modifier|*
name|dp
init|=
operator|&
name|d
decl_stmt|;
comment|// okay
name|int
name|x
init|=
name|FN_ADD
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|TOP_RIGHT_UNDEF
end_ifndef

begin_error
error|#
directive|error
error|TOP_RIGHT_UNDEF should still be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
unit|@
name|import
name|macros_bottom
decl_stmt|;
end_decl_stmt

begin_function
name|TOP_DEF_RIGHT_UNDEF
modifier|*
name|TDRUf
parameter_list|()
block|{
return|return
name|TDRUp
return|;
block|}
end_function

begin_decl_stmt
unit|@
name|import
name|macros_right
operator|.
name|undef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|TOP_DEF_RIGHT_UNDEF
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ok, no longer defined
end_comment

begin_comment
comment|// FIXME: When macros_right.undef is built, macros_top is visible because
end_comment

begin_comment
comment|// the state from building macros_right leaks through, so macros_right.undef
end_comment

begin_comment
comment|// undefines macros_top's macro.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TOP_RIGHT_UNDEF
end_ifdef

begin_error
error|#
directive|error
error|TOP_RIGHT_UNDEF should not be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
unit|@
name|import
name|macros_other
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TOP_OTHER_UNDEF1
end_ifndef

begin_error
error|#
directive|error
error|TOP_OTHER_UNDEF1 should still be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TOP_OTHER_UNDEF2
end_ifndef

begin_error
error|#
directive|error
error|TOP_OTHER_UNDEF2 should still be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TOP_OTHER_REDEF1
end_ifndef

begin_error
error|#
directive|error
error|TOP_OTHER_REDEF1 should still be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|n1
init|=
name|TOP_OTHER_REDEF1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{ambiguous expansion of macro 'TOP_OTHER_REDEF1'}}
end_comment

begin_comment
comment|// expected-note@macros_top.h:19 {{expanding this definition}}
end_comment

begin_comment
comment|// expected-note@macros_other.h:4 {{other definition}}
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TOP_OTHER_REDEF2
end_ifndef

begin_error
error|#
directive|error
error|TOP_OTHER_REDEF2 should still be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|n2
init|=
name|TOP_OTHER_REDEF2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ok
end_comment

begin_decl_stmt
name|int
name|n3
init|=
name|TOP_OTHER_DEF_RIGHT_UNDEF
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ok
end_comment

end_unit

