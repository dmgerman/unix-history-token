begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_decl_stmt
name|long
name|__stack_chk_guard
index|[
literal|8
index|]
init|=
block|{}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|__stack_chk_fail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|__stack_chk_fail
parameter_list|(
name|void
parameter_list|)
block|{
name|panic
argument_list|(
literal|"stack overflow detected; backtrace may be corrupted"
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|__arraycount
parameter_list|(
name|__x
parameter_list|)
value|(sizeof(__x) / sizeof(__x[0]))
end_define

begin_function
specifier|static
name|void
name|__stack_chk_init
parameter_list|(
name|void
modifier|*
name|dummy
name|__unused
parameter_list|)
block|{
name|size_t
name|i
decl_stmt|;
name|long
name|guard
index|[
name|__arraycount
argument_list|(
name|__stack_chk_guard
argument_list|)
index|]
decl_stmt|;
name|arc4rand
argument_list|(
name|guard
argument_list|,
sizeof|sizeof
argument_list|(
name|guard
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|__arraycount
argument_list|(
name|guard
argument_list|)
condition|;
name|i
operator|++
control|)
name|__stack_chk_guard
index|[
name|i
index|]
operator|=
name|guard
index|[
name|i
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/* SI_SUB_EVENTHANDLER is right after SI_SUB_LOCK used by arc4rand() init. */
end_comment

begin_expr_stmt
name|SYSINIT
argument_list|(
name|stack_chk
argument_list|,
name|SI_SUB_EVENTHANDLER
argument_list|,
name|SI_ORDER_ANY
argument_list|,
name|__stack_chk_init
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

