begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|XPX
end_ifdef

begin_comment
comment|/*  * seq(e1,e2)  - generate e1, e1+e2, e1+e2+e2, ... .  */
end_comment

begin_macro
name|Xseq
argument_list|(
argument|nargs
argument_list|,
argument|arg2
argument_list|,
argument|arg1
argument_list|,
argument|arg0
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|arg2
decl_stmt|,
name|arg1
decl_stmt|,
name|arg0
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|from
decl_stmt|,
name|by
decl_stmt|;
comment|/*     * Default e1 and e2 to 1.     */
name|defint
argument_list|(
operator|&
name|arg1
argument_list|,
operator|&
name|from
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|defint
argument_list|(
operator|&
name|arg2
argument_list|,
operator|&
name|by
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/*     * Produce error if e2 is 0, i.e., infinite sequence of e1's.     */
if|if
condition|(
name|by
operator|==
literal|0
condition|)
name|runerr
argument_list|(
literal|211
argument_list|,
operator|&
name|arg2
argument_list|)
expr_stmt|;
comment|/*     * Suspend sequence, stopping when largest or smallest integer     *  is reached.     */
while|while
condition|(
operator|(
name|from
operator|<=
name|MAXLONG
operator|&&
name|by
operator|>
literal|0
operator|)
operator|||
operator|(
name|from
operator|>=
name|MINLONG
operator|&&
name|by
operator|<
literal|0
operator|)
condition|)
block|{
name|mkint
argument_list|(
name|from
argument_list|,
operator|&
name|arg0
argument_list|)
expr_stmt|;
name|suspend
argument_list|()
expr_stmt|;
name|from
operator|+=
name|by
expr_stmt|;
block|}
name|fail
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|seq
argument_list|,
literal|2
argument_list|)
end_macro

begin_else
else|#
directive|else
else|XPX
end_else

begin_decl_stmt
name|char
name|junk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prevent null object file */
end_comment

begin_endif
endif|#
directive|endif
endif|XPX
end_endif

end_unit

