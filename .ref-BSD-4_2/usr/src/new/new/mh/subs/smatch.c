begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"mh.h"
end_include

begin_comment
comment|/* switch match, or any unambiguous abbreviation */
end_comment

begin_comment
comment|/* exact match always wins, even if shares same root */
end_comment

begin_comment
comment|/* returns subscript in zero-terminated tbl[] of strings */
end_comment

begin_comment
comment|/* returns -1 if no match, -2 if ambiguous */
end_comment

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|i
parameter_list|)
value|(i< 0 ? -i : i)
end_define

begin_macro
name|smatch
argument_list|(
argument|string
argument_list|,
argument|swp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|swit
modifier|*
name|swp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|sp
decl_stmt|,
modifier|*
name|tcp
decl_stmt|;
name|struct
name|swit
modifier|*
name|tp
decl_stmt|;
name|int
name|firstone
decl_stmt|,
name|stringlen
decl_stmt|;
name|firstone
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|stringlen
operator|=
name|strlen
argument_list|(
name|string
argument_list|)
operator|,
name|tp
operator|=
name|swp
init|;
name|tcp
operator|=
name|tp
operator|->
name|sw
condition|;
name|tp
operator|++
control|)
block|{
if|if
condition|(
name|stringlen
operator|<
name|abs
argument_list|(
name|tp
operator|->
name|minchars
argument_list|)
condition|)
continue|continue;
comment|/* no match */
for|for
control|(
name|sp
operator|=
name|string
init|;
operator|*
name|sp
operator|==
operator|*
name|tcp
operator|++
condition|;
control|)
block|{
if|if
condition|(
operator|*
name|sp
operator|++
operator|==
literal|0
condition|)
return|return
operator|(
name|tp
operator|-
name|swp
operator|)
return|;
comment|/* exact match */
block|}
if|if
condition|(
operator|*
name|sp
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|sp
operator|!=
literal|' '
condition|)
continue|continue;
comment|/* no match */
if|if
condition|(
operator|*
operator|--
name|tcp
operator|==
literal|0
condition|)
return|return
operator|(
name|tp
operator|-
name|swp
operator|)
return|;
comment|/* exact match */
block|}
if|if
condition|(
name|firstone
operator|==
operator|-
literal|1
condition|)
name|firstone
operator|=
name|tp
operator|-
name|swp
expr_stmt|;
comment|/* possible match */
else|else
name|firstone
operator|=
operator|-
literal|2
expr_stmt|;
comment|/* ambiguous */
block|}
return|return
operator|(
name|firstone
operator|)
return|;
block|}
end_block

end_unit

