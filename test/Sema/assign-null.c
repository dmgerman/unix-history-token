begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|hookfunc
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|hookfunc
name|hook
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|clear_hook
parameter_list|()
block|{
name|hook
operator|=
name|NULL
expr_stmt|;
block|}
end_function

end_unit

