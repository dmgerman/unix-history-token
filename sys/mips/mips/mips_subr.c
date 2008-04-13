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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/cp0.h>
end_include

begin_function
specifier|static
name|void
name|mips_setwatchlo
parameter_list|(
name|u_int32_t
name|watchlo
parameter_list|)
block|{
asm|__asm __volatile ("mtc0 %0, $18, 0" : : "r" (watchlo));
block|}
end_function

begin_function
specifier|static
name|void
name|mips_setwatchhi
parameter_list|(
name|u_int32_t
name|watchhi
parameter_list|)
block|{
asm|__asm __volatile ("mtc0 %0, $19, 0" : : "r" (watchhi));
block|}
end_function

begin_comment
comment|/*  * mips_watchpoint -- set/clear a watchpoint  */
end_comment

begin_function_decl
name|void
name|mips_watchpoint
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|access
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//XXX kludge
end_comment

begin_function
name|void
name|mips_watchpoint
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|access
parameter_list|)
block|{
name|u_int32_t
name|watchlo
init|=
literal|0
decl_stmt|;
name|u_int32_t
name|watchhi
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|addr
operator|!=
name|NULL
condition|)
block|{
comment|/* 		 * Set a new watchpoint. 		 * Parameter addr points to the address we'd like to monitor. 		 */
name|watchhi
operator|=
name|WATCHHI_GLOBAL_BIT
expr_stmt|;
name|watchlo
operator|=
operator|(
name|u_int32_t
operator|)
name|addr
operator|&
name|WATCHLO_PADDR0_MASK
expr_stmt|;
name|access
operator|&=
name|WATCHLO_STORE
operator||
name|WATCHLO_LOAD
operator||
name|WATCHLO_FETCH
expr_stmt|;
name|watchlo
operator||=
name|access
expr_stmt|;
block|}
name|mips_setwatchlo
argument_list|(
name|watchlo
argument_list|)
expr_stmt|;
name|mips_setwatchhi
argument_list|(
name|watchhi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

