begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|node
block|{
name|struct
name|node
modifier|*
name|p1
decl_stmt|;
name|struct
name|node
modifier|*
name|p2
decl_stmt|;
name|char
name|typ
decl_stmt|;
name|char
name|ch
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|freesize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|lookf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|looks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|lookend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|lookstart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|lookdef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|lookret
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|lookfret
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cfail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rfail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|freelist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|namelist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
modifier|*
name|schar
decl_stmt|;
end_decl_stmt

end_unit

