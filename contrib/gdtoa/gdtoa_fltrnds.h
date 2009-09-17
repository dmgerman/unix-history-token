begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|FPI
modifier|*
name|fpi
decl_stmt|,
name|fpi1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Rounding
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|Trust_FLT_ROUNDS
end_ifdef

begin_comment
comment|/*{{ only define this if FLT_ROUNDS really works! */
end_comment

begin_expr_stmt
name|Rounding
operator|=
name|Flt_Rounds
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*}{*/
end_comment

begin_expr_stmt
name|Rounding
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|fegetround
argument_list|()
condition|)
block|{
case|case
name|FE_TOWARDZERO
case|:
name|Rounding
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|FE_UPWARD
case|:
name|Rounding
operator|=
literal|2
expr_stmt|;
break|break;
case|case
name|FE_DOWNWARD
case|:
name|Rounding
operator|=
literal|3
expr_stmt|;
block|}
end_switch

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*}}*/
end_comment

begin_expr_stmt
name|fpi
operator|=
operator|&
name|fpi0
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Rounding
operator|!=
literal|1
condition|)
block|{
name|fpi1
operator|=
name|fpi0
expr_stmt|;
name|fpi
operator|=
operator|&
name|fpi1
expr_stmt|;
name|fpi1
operator|.
name|rounding
operator|=
name|Rounding
expr_stmt|;
block|}
end_if

end_unit

