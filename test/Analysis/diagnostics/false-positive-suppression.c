begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -I %S/Inputs -analyzer-checker=core,unix -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|"include/sys/queue.h"
end_include

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|radar12491259
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|FREE_POINTER
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|FREE_POINTER
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// no-warning: we are suppressing errors coming from sys/queue macros.
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|MYMACRO
parameter_list|(
name|p
parameter_list|)
value|FREE_POINTER(p)
end_define

begin_function
name|int
name|radar12491259_inside_macro
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|MYMACRO
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|MYMACRO
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// no-warning: we are suppressing errors coming from sys/queue macros.
return|return
literal|0
return|;
block|}
end_function

end_unit

