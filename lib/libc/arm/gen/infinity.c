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
specifier|const
name|union
name|__infinity_un
name|__infinity
init|=
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
block|{
literal|0x7f
block|,
literal|0xf0
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
literal|0
block|}
else|#
directive|else
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
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bytes for NaN */
end_comment

begin_decl_stmt
specifier|const
name|union
name|__nan_un
name|__nan
init|=
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
block|{
literal|0xff
block|,
literal|0xc0
block|,
literal|0
block|,
literal|0
block|}
else|#
directive|else
block|{
literal|0
block|,
literal|0
block|,
literal|0xc0
block|,
literal|0xff
block|}
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

end_unit

