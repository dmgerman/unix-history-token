begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	fblk.h	2.1	1/5/80 */
end_comment

begin_struct
struct|struct
name|fblk
block|{
name|int
name|df_nfree
decl_stmt|;
name|daddr_t
name|df_free
index|[
name|NICFREE
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

