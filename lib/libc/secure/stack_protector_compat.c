begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Alexander Kabaev<kan@FreeBSD.org>  * The file is in public domain.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|__stack_chk_fail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_function
name|void
name|__stack_chk_fail_local_hidden
parameter_list|(
name|void
parameter_list|)
block|{
name|__stack_chk_fail
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|__sym_compat
argument_list|(
name|__stack_chk_fail_local
argument_list|,
name|__stack_chk_fail_local_hidden
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

