begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -Xclang -verify -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: clang -emit-llvm -S -o %t %s
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
name|int
name|no_vars
name|__attribute
argument_list|(
operator|(
name|malloc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{functions returning a pointer type}}
end_comment

begin_function_decl
name|void
name|returns_void
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(malloc
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{functions returning a pointer type}}
end_comment

begin_function_decl
name|int
name|returns_int
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(malloc
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{functions returning a pointer type}}
end_comment

begin_function_decl
name|int
modifier|*
name|returns_intptr
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(malloc
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|iptr
typedef|;
end_typedef

begin_function_decl
name|iptr
name|returns_iptr
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(malloc
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(malloc)
argument_list|)
end_macro

begin_function_decl
name|void
modifier|*
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//  expected-warning{{'malloc' attribute only applies to functions returning a pointer type}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(malloc)
argument_list|)
end_macro

begin_function_decl
name|int
function_decl|(
modifier|*
name|g
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{'malloc' attribute only applies to functions returning a pointer type}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(malloc)
argument_list|)
end_macro

begin_function
name|void
modifier|*
name|xalloc
parameter_list|(
name|unsigned
name|n
parameter_list|)
block|{
return|return
name|malloc
argument_list|(
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// no-warning
end_comment

begin_comment
comment|// RUN: grep 'define noalias .* @xalloc(' %t
end_comment

begin_define
define|#
directive|define
name|malloc_like
value|__attribute((__malloc__))
end_define

begin_decl_stmt
name|void
modifier|*
name|xalloc2
argument_list|(
name|unsigned
argument_list|)
name|malloc_like
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|xalloc2
parameter_list|(
name|unsigned
name|n
parameter_list|)
block|{
return|return
name|malloc
argument_list|(
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// RUN: grep 'define noalias .* @xalloc2(' %t
end_comment

end_unit

