begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|map
block|{
name|short
name|m_size
decl_stmt|;
name|unsigned
name|short
name|m_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|map
name|coremap
index|[
name|CMAPSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space for core allocation */
end_comment

begin_decl_stmt
name|struct
name|map
name|swapmap
index|[
name|SMAPSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space for swap allocation */
end_comment

begin_comment
comment|/* 	uba */
end_comment

begin_decl_stmt
name|char
name|bdpwant
decl_stmt|,
name|umrwant
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|ubamap
index|[
name|UAMSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|bdpmap
index|[
literal|15
index|]
decl_stmt|;
end_decl_stmt

end_unit

