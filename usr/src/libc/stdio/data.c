begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|char
name|_sibuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|_sobuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|_iobuf
name|_iob
index|[
name|_NFILE
index|]
init|=
block|{
block|{
literal|0
block|,
name|_sibuf
block|,
name|_sibuf
block|,
name|_IOREAD
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|,
name|NULL
block|,
name|_IOWRT
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|,
name|NULL
block|,
name|_IOWRT
operator|+
name|_IONBF
block|,
literal|2
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Ptr to end of buffers  */
end_comment

begin_decl_stmt
name|struct
name|_iobuf
modifier|*
name|_lastbuf
init|=
block|{
operator|&
name|_iob
index|[
name|_NFILE
index|]
block|}
decl_stmt|;
end_decl_stmt

end_unit

