begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_preamble.h"
end_include

begin_comment
comment|/*  * The hooks are a little bit screwy -- they're not genuinely exported in the  * sense that we want them available to end-users, but we do want them visible  * from outside the generated library, so that we can use them in test code.  */
end_comment

begin_function_decl
name|JEMALLOC_EXPORT
name|void
function_decl|(
modifier|*
name|hooks_arena_new_hook
function_decl|)
parameter_list|()
init|=
name|NULL
function_decl|;
end_function_decl

begin_function_decl
name|JEMALLOC_EXPORT
name|void
function_decl|(
modifier|*
name|hooks_libc_hook
function_decl|)
parameter_list|()
init|=
name|NULL
function_decl|;
end_function_decl

end_unit

