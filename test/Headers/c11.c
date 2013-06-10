begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only -Xclang -verify -std=c11 %s
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -Xclang -verify -std=c11 -fmodules %s
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -Xclang -verify -std=c11 -ffreestanding %s
end_comment

begin_function_decl
name|noreturn
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error 1+{{}}
end_comment

begin_include
include|#
directive|include
file|<stdnoreturn.h>
end_include

begin_include
include|#
directive|include
file|<stdnoreturn.h>
end_include

begin_include
include|#
directive|include
file|<stdnoreturn.h>
end_include

begin_function_decl
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|noreturn
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|noreturn
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<stdalign.h>
end_include

begin_assert
assert|_Static_assert
argument_list|(
name|__alignas_is_defined
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof_is_defined
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_macro
name|alignas
argument_list|(
argument|alignof(int)
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof
argument_list|(
name|c
argument_list|)
operator|==
literal|4
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_define
define|#
directive|define
name|__STDC_WANT_LIB_EXT1__
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_decl_stmt
name|rsize_t
name|x
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If we are freestanding, then also check RSIZE_MAX (in a hosted implementation
end_comment

begin_comment
comment|// we will use the host stdint.h, which may not yet have C11 support).
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC_HOSTED__
end_ifndef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|rsize_t
name|x2
init|=
name|RSIZE_MAX
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

