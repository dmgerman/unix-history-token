begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * infinity.c  */
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

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/* bytes for +Infinity on a 387 */
end_comment

begin_decl_stmt
name|char
name|__infinity
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0xf0
block|,
literal|0x7f
block|}
decl_stmt|;
end_decl_stmt

end_unit

