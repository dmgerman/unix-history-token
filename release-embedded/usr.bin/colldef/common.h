begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|CHARMAP_SYMBOL_LEN
value|64
end_define

begin_define
define|#
directive|define
name|BUFSIZE
value|80
end_define

begin_decl_stmt
specifier|extern
name|int
name|line_no
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|charmap_table
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
index|[
name|CHARMAP_SYMBOL_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|map_name
index|[
name|FILENAME_MAX
index|]
decl_stmt|;
end_decl_stmt

end_unit

