begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	gmon.h	4.1	82/06/27	*/
end_comment

begin_struct
struct|struct
name|phdr
block|{
name|char
modifier|*
name|lpc
decl_stmt|;
name|char
modifier|*
name|hpc
decl_stmt|;
name|int
name|ncnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tostruct
block|{
name|char
modifier|*
name|selfpc
decl_stmt|;
name|long
name|count
decl_stmt|;
name|u_short
name|link
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * a raw arc,  *	with pointers to the calling site and the called site  *	and a count.  */
end_comment

begin_struct
struct|struct
name|rawarc
block|{
name|u_long
name|raw_frompc
decl_stmt|;
name|u_long
name|raw_selfpc
decl_stmt|;
name|long
name|raw_count
decl_stmt|;
block|}
struct|;
end_struct

end_unit

