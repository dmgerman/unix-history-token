begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* C9X struct/union member init, with nested union and trailing member */
end_comment

begin_union
union|union
name|node
block|{
name|void
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|foo
block|{
name|int
name|b
decl_stmt|;
name|union
name|node
name|n
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|foo
name|f
init|=
block|{
operator|.
name|b
operator|=
literal|1
block|,
operator|.
name|n
operator|=
block|{
operator|.
name|next
operator|=
literal|0
block|, }
block|,
operator|.
name|c
operator|=
literal|1
block|}
decl_stmt|;
end_decl_stmt

end_unit

