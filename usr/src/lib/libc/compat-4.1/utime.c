begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	utime.c	4.2	83/05/31	*/
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * Backwards compatible utime.  */
end_comment

begin_macro
name|utime
argument_list|(
argument|name
argument_list|,
argument|otv
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|otv
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|timeval
name|tv
index|[
literal|2
index|]
decl_stmt|;
name|tv
index|[
literal|0
index|]
operator|.
name|tv_sec
operator|=
name|otv
index|[
literal|0
index|]
expr_stmt|;
name|tv
index|[
literal|0
index|]
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|tv
index|[
literal|1
index|]
operator|.
name|tv_sec
operator|=
name|otv
index|[
literal|1
index|]
expr_stmt|;
name|tv
index|[
literal|1
index|]
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|utimes
argument_list|(
name|name
argument_list|,
name|tv
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

