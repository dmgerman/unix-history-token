begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	clist.h	4.1	%G%	*/
end_comment

begin_comment
comment|/*  * Raw structures for the character list routines.  */
end_comment

begin_struct
struct|struct
name|cblock
block|{
name|struct
name|cblock
modifier|*
name|c_next
decl_stmt|;
name|char
name|c_info
index|[
name|CBSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|cblock
name|cfree
index|[]
decl_stmt|;
end_decl_stmt

end_unit

