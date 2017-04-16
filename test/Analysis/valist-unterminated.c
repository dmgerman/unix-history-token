begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple hexagon-unknown-linux -analyzer-checker=core,valist.Unterminated,valist.CopyToSelf -analyzer-output=text -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-pc-linux-gnu -analyzer-checker=core,valist.Unterminated,valist.CopyToSelf -analyzer-output=text -analyzer-store=region -verify %s
end_comment

begin_include
include|#
directive|include
file|"Inputs/system-header-simulator-for-valist.h"
end_include

begin_function
name|void
name|f1
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
return|return;
comment|// expected-warning{{Initialized va_list 'va' is leaked}}
comment|// expected-note@-1{{Initialized va_list 'va' is leaked}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
comment|// expected-note{{Ended va_list}}
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
block|}
end_function

begin_comment
comment|// expected-warning{{Initialized va_list 'va' is leaked}}
end_comment

begin_comment
comment|// expected-note@-1{{Initialized va_list 'va' is leaked}}
end_comment

begin_function
name|void
name|f3
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|,
name|va2
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
name|va_copy
argument_list|(
name|va2
argument_list|,
name|va
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
comment|// expected-warning{{Initialized va_list 'va2' is leaked}}
comment|// expected-note@-1{{Initialized va_list 'va2' is leaked}}
block|}
end_function

begin_function
name|void
name|f4
parameter_list|(
name|va_list
modifier|*
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_start
argument_list|(
operator|*
name|fst
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
return|return;
comment|// expected-warning{{Initialized va_list is leaked}}
comment|// expected-note@-1{{Initialized va_list is leaked}}
block|}
end_function

begin_function
name|void
name|f5
parameter_list|(
name|va_list
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_start
argument_list|(
name|fst
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
block|}
end_function

begin_comment
comment|// expected-warning{{Initialized va_list}}
end_comment

begin_comment
comment|// expected-note@-1{{Initialized va_list}}
end_comment

begin_function
name|void
name|f6
parameter_list|(
name|va_list
modifier|*
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_start
argument_list|(
operator|*
name|fst
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
operator|(
name|void
operator|)
name|va_arg
argument_list|(
operator|*
name|fst
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|//FIXME: this should NOT cause a warning
name|va_end
argument_list|(
operator|*
name|fst
argument_list|)
expr_stmt|;
comment|// expected-warning{{Initialized va_list is leaked}}
comment|// expected-note@-1{{Initialized va_list is leaked}}
block|}
end_function

begin_function
name|void
name|f7
parameter_list|(
name|int
modifier|*
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|x
decl_stmt|;
name|va_list
modifier|*
name|y
init|=
operator|&
name|x
decl_stmt|;
name|va_start
argument_list|(
operator|*
name|y
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
block|}
end_function

begin_comment
comment|// expected-warning{{Initialized va_list 'x' is leaked}}
end_comment

begin_comment
comment|// expected-note@-1{{Initialized va_list 'x' is leaked}}
end_comment

begin_function
name|void
name|f8
parameter_list|(
name|int
modifier|*
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|x
decl_stmt|;
name|va_list
modifier|*
name|y
init|=
operator|&
name|x
decl_stmt|;
name|va_start
argument_list|(
operator|*
name|y
argument_list|,
name|fst
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// no-warning
end_comment

begin_function
name|void
name|reinit
parameter_list|(
name|int
modifier|*
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
comment|// expected-note@-1{{Initialized va_list}}
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-warning{{Initialized va_list 'va' is initialized again}}
comment|// expected-note@-1{{Initialized va_list 'va' is initialized again}}
block|}
end_function

begin_comment
comment|// expected-warning{{Initialized va_list 'va' is leaked}}
end_comment

begin_comment
comment|// expected-note@-1{{Initialized va_list 'va' is leaked}}
end_comment

begin_function
name|void
name|reinitOk
parameter_list|(
name|int
modifier|*
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// no-warning
end_comment

begin_function
name|void
name|copyself
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
name|va_copy
argument_list|(
name|va
argument_list|,
name|va
argument_list|)
expr_stmt|;
comment|// expected-warning{{va_list 'va' is copied onto itself}}
comment|// expected-note@-1{{va_list 'va' is copied onto itself}}
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|copyselfUninit
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_copy
argument_list|(
name|va
argument_list|,
name|va
argument_list|)
expr_stmt|;
comment|// expected-warning{{va_list 'va' is copied onto itself}}
comment|// expected-note@-1{{va_list 'va' is copied onto itself}}
block|}
end_function

begin_function
name|void
name|copyOverwrite
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|,
name|va2
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
name|va_copy
argument_list|(
name|va
argument_list|,
name|va2
argument_list|)
expr_stmt|;
comment|// expected-warning{{Initialized va_list 'va' is overwritten by an uninitialized one}}
comment|// expected-note@-1{{Initialized va_list 'va' is overwritten by an uninitialized one}}
block|}
end_function

begin_comment
comment|//This only generates a warning for the valist.Uninitialized checker
end_comment

begin_function
name|void
name|copyUnint
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|,
name|va2
decl_stmt|;
name|va_copy
argument_list|(
name|va
argument_list|,
name|va2
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// no-warning
end_comment

begin_function
name|void
name|recopy
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|,
name|va2
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
expr_stmt|;
name|va_copy
argument_list|(
name|va2
argument_list|,
name|va
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
name|va_copy
argument_list|(
name|va2
argument_list|,
name|va
argument_list|)
expr_stmt|;
comment|// expected-warning{{Initialized va_list 'va2' is initialized again}}
comment|// expected-note@-1{{Initialized va_list 'va2' is initialized again}}
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|va2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|doublemsg
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|,
name|va2
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fst
argument_list|)
operator|,
name|va_start
argument_list|(
name|va2
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-warning{{Initialized va_list 'va' is leaked}}
comment|// expected-warning@-1{{Initialized va_list 'va2' is leaked}}
comment|// expected-note@-2{{Initialized va_list}}
comment|// expected-note@-3{{Initialized va_list}}
comment|// expected-note@-4{{Initialized va_list}}
comment|// expected-note@-5{{Initialized va_list 'va' is leaked}}
block|}
end_function

begin_function
name|void
name|in_array
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va_array
index|[
literal|8
index|]
decl_stmt|;
name|va_start
argument_list|(
name|va_array
index|[
literal|3
index|]
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
block|}
end_function

begin_comment
comment|// expected-warning{{Initialized va_list 'va_array[3]' is leaked}}
end_comment

begin_comment
comment|// expected-note@-1{{Initialized va_list 'va_array[3]' is leaked}}
end_comment

begin_struct
struct|struct
name|containing_a_valist
block|{
name|va_list
name|vafield
decl_stmt|;
name|int
name|foobar
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|in_struct
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|struct
name|containing_a_valist
name|s
decl_stmt|;
name|va_start
argument_list|(
name|s
operator|.
name|vafield
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
block|}
end_function

begin_comment
comment|// expected-warning{{Initialized va_list 's.vafield' is leaked}}
end_comment

begin_comment
comment|// expected-note@-1{{Initialized va_list 's.vafield' is leaked}}
end_comment

begin_function
name|void
name|casting
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|char
name|mem
index|[
sizeof|sizeof
argument_list|(
name|va_list
argument_list|)
index|]
decl_stmt|;
name|va_start
argument_list|(
operator|*
operator|(
name|va_list
operator|*
operator|)
name|mem
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
block|}
end_function

begin_comment
comment|// expected-warning{{Initialized va_list 'mem[0]' is leaked}}
end_comment

begin_comment
comment|// expected-note@-1{{Initialized va_list 'mem[0]' is leaked}}
end_comment

begin_function
name|void
name|castingOk
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|char
name|mem
index|[
sizeof|sizeof
argument_list|(
name|va_list
argument_list|)
index|]
decl_stmt|;
name|va_start
argument_list|(
operator|*
operator|(
name|va_list
operator|*
operator|)
name|mem
argument_list|,
name|fst
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
operator|*
operator|(
name|va_list
operator|*
operator|)
name|mem
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// no-warning
end_comment

end_unit

