begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * One file structure is allocated  * for each open/creat/pipe call.  * Main use is to hold the read/write  * pointer associated with each open  * file.  */
end_comment

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
comment|/* reference count */
name|int
name|f_inode
decl_stmt|;
comment|/* pointer to inode structure */
name|char
modifier|*
name|f_offset
index|[
literal|2
index|]
decl_stmt|;
comment|/* read/write character pointer */
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

