begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  * Ex - a text editor  * Bill Joy UCB September, 1977  *  * We use these routines here instead of libS.a because  * we need a printf which prints through putchar().  */
end_comment

begin_include
include|#
directive|include
file|"ex.h"
end_include

begin_macro
name|strcpy
argument_list|(
argument|oto
argument_list|,
argument|from
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|oto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|from
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|to
decl_stmt|;
name|to
operator|=
name|oto
expr_stmt|;
while|while
condition|(
operator|*
name|to
operator|++
operator|=
operator|*
name|from
operator|++
condition|)
continue|continue;
return|return
operator|(
name|oto
operator|)
return|;
block|}
end_block

begin_macro
name|strcat
argument_list|(
argument|to
argument_list|,
argument|from
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|to
decl_stmt|,
modifier|*
name|from
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|strcpy
argument_list|(
name|strend
argument_list|(
name|to
argument_list|)
argument_list|,
name|from
argument_list|)
expr_stmt|;
return|return
operator|(
name|to
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|strend
argument_list|(
name|cp
argument_list|)
specifier|register
name|char
operator|*
name|cp
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
operator|*
name|cp
condition|)
name|cp
operator|++
expr_stmt|;
return|return
operator|(
name|cp
operator|)
return|;
block|}
end_block

begin_macro
name|strcLIN
argument_list|(
argument|dp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|dp
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|strcpy
argument_list|(
name|linebuf
argument_list|,
name|dp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

