begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)move.c	4.1 (Berkeley) 6/27/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern vti;
end_extern

begin_extern
extern|extern xnow
operator|,
extern|ynow;
end_extern

begin_macro
name|move
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|)
end_macro

begin_block
block|{
struct|struct
block|{
name|char
name|pad
decl_stmt|,
name|c
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|p
struct|;
name|p
operator|.
name|c
operator|=
literal|9
expr_stmt|;
name|p
operator|.
name|x
operator|=
name|xnow
operator|=
name|xsc
argument_list|(
name|xi
argument_list|)
expr_stmt|;
name|p
operator|.
name|y
operator|=
name|ynow
operator|=
name|ysc
argument_list|(
name|yi
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|vti
argument_list|,
operator|&
name|p
operator|.
name|c
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

