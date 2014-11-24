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
comment|// This test checks some of the same things as macros.c, but imports modules in
end_comment

begin_comment
comment|// a different order.
end_comment

begin_decl_stmt
unit|@
name|import
name|macros_other
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n0
init|=
name|TOP_OTHER_DEF_RIGHT_UNDEF
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ok
end_comment

begin_decl_stmt
unit|@
name|import
name|macros_top
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TOP_OTHER_DEF_RIGHT_UNDEF
modifier|*
name|n0b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{ambiguous expansion of macro 'TOP_OTHER_DEF_RIGHT_UNDEF'}}
end_comment

begin_comment
comment|// expected-note@macros_top.h:22 {{expanding this definition of 'TOP_OTHER_DEF_RIGHT_UNDEF'}}
end_comment

begin_comment
comment|// expected-note@macros_other.h:6 {{other definition of 'TOP_OTHER_DEF_RIGHT_UNDEF'}}
end_comment

begin_decl_stmt
unit|@
name|import
name|macros_right
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|import
name|macros_left
decl_stmt|;
end_decl_stmt

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

begin_function
name|void
name|test
parameter_list|()
block|{
name|float
name|f
decl_stmt|;
name|TOP_RIGHT_REDEF
modifier|*
name|fp
init|=
operator|&
name|f
decl_stmt|;
comment|// ok, right's definition overrides top's definition
comment|// Note, left's definition wins here, whereas right's definition wins in
comment|// macros.c.
name|int
name|i
decl_stmt|;
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
name|f
decl_stmt|;
comment|// expected-warning{{ambiguous expansion of macro 'LEFT_RIGHT_DIFFERENT'}}
comment|// expected-note@macros_left.h:14 {{expanding this}}
comment|// expected-note@macros_right.h:12 {{other}}
name|LEFT_RIGHT_DIFFERENT2
modifier|*
name|ip3
init|=
operator|&
name|f
decl_stmt|;
comment|// expected-warning{{ambiguous expansion of macro 'LEFT_RIGHT_DIFFERENT2}}
comment|// expected-note@macros_left.h:11 {{expanding this}}
comment|// expected-note@macros_right.h:13 {{other}}
undef|#
directive|undef
name|LEFT_RIGHT_DIFFERENT3
name|int
name|LEFT_RIGHT_DIFFERENT3
decl_stmt|;
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

begin_comment
comment|// FIXME: See macros.c.
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

begin_decl_stmt
name|int
name|top_redef_in_submodules
init|=
name|TOP_REDEF_IN_SUBMODULES
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|import
name|macros_top
operator|.
name|c
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test2
parameter_list|()
block|{
name|int
name|TOP_REDEF_IN_SUBMODULES
init|=
name|top_redef_in_submodules
decl_stmt|;
block|}
end_function

end_unit

