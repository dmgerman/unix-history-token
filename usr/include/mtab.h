begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|mtab
block|{
name|char
name|m_path
index|[
literal|32
index|]
decl_stmt|;
comment|/* mounted on pathname */
name|char
name|m_dname
index|[
literal|32
index|]
decl_stmt|;
comment|/* block device pathname */
block|}
struct|;
end_struct

end_unit

