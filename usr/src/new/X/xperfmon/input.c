begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_input_c
init|=
literal|"$Header: input.c,v 10.2 86/02/01 16:02:55 tony Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/* input.c */
end_comment

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_decl_stmt
specifier|extern
name|KeyMapEntry
name|StdMap
index|[]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|mapkey
argument_list|(
name|keycode
argument_list|)
specifier|register
name|int
name|keycode
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|short
name|c
decl_stmt|;
name|c
operator|=
name|StdMap
index|[
name|keycode
operator|&
name|ValueMask
index|]
index|[
name|KeyState
argument_list|(
name|keycode
argument_list|)
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|keycode
operator|&
name|ShiftLockMask
operator|)
operator|&&
name|c
operator|>=
literal|'a'
operator|&&
name|c
operator|<=
literal|'z'
condition|)
name|c
operator|+=
literal|'A'
operator|-
literal|'a'
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
block|}
end_block

end_unit

