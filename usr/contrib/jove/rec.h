begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  * This program is copyright (C) 1985, 1986 by Jonathan Payne.  It is    *  * provided to you without charge for use only on a licensed Unix        *  * system.  You may copy JOVE provided that this notice is included with *  * the copy.  You may not sell copies of this program or versions        *  * modified for use on microcomputer systems, unless the copies are      *  * included with a Unix system distribution and the source is provided.  *  *************************************************************************/
end_comment

begin_struct
struct|struct
name|rec_head
block|{
name|int
name|Uid
decl_stmt|,
comment|/* Uid of owner. */
name|Pid
decl_stmt|;
comment|/* Pid of jove process. */
name|time_t
name|UpdTime
decl_stmt|;
comment|/* Last time this was updated. */
name|int
name|Nbuffers
decl_stmt|;
comment|/* Number of buffers. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rec_entry
block|{
name|char
name|r_bname
index|[
literal|128
index|]
decl_stmt|,
name|r_fname
index|[
literal|128
index|]
decl_stmt|;
name|int
name|r_nlines
decl_stmt|;
block|}
struct|;
end_struct

end_unit

