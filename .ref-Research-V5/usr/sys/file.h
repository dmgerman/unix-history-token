begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|file
block|{
name|char
name|f_flag
decl_stmt|;
name|char
name|f_count
decl_stmt|;
name|int
name|f_inode
decl_stmt|;
name|char
modifier|*
name|f_offset
index|[
literal|2
index|]
decl_stmt|;
block|}
name|file
index|[
name|NFILE
index|]
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|FREAD
value|01
end_define

begin_define
define|#
directive|define
name|FWRITE
value|02
end_define

begin_define
define|#
directive|define
name|FPIPE
value|04
end_define

end_unit

