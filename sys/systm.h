begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
name|canonb
index|[
name|CANBSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|coremap
index|[
name|CMAPSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|swapmap
index|[
name|SMAPSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|rootdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lbolt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|time
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tout
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|callo
block|{
name|int
name|c_time
decl_stmt|;
name|int
name|c_arg
decl_stmt|;
name|int
function_decl|(
modifier|*
name|c_func
function_decl|)
parameter_list|()
function_decl|;
block|}
name|callout
index|[
name|NCALL
index|]
struct|;
end_struct

begin_struct
struct|struct
name|mount
block|{
name|int
name|m_dev
decl_stmt|;
name|int
modifier|*
name|m_bufp
decl_stmt|;
name|int
modifier|*
name|m_inodp
decl_stmt|;
block|}
name|mount
index|[
name|NMOUNT
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|mpid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|runin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|runout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|runrun
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ssr
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

end_unit

