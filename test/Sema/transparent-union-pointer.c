begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|union
name|wait
modifier|*
name|__uptr
decl_stmt|;
name|int
modifier|*
name|__iptr
decl_stmt|;
block|}
name|__WAIT_STATUS
name|__attribute__
typedef|((
name|__transparent_union__
typedef|));
end_typedef

begin_function_decl
specifier|extern
name|int
name|wait
parameter_list|(
name|__WAIT_STATUS
name|__stat_loc
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|fastcgi_cleanup
parameter_list|()
block|{
name|int
name|status
init|=
literal|0
decl_stmt|;
name|wait
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

