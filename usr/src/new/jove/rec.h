begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_struct
struct|struct
name|rec_head
block|{
name|int
name|Uid
decl_stmt|,
comment|/* uid of owner */
name|Pid
decl_stmt|;
comment|/* pid of jove process */
name|time_t
name|UpdTime
decl_stmt|;
comment|/* last time this was updated */
name|int
name|Nbuffers
decl_stmt|;
comment|/* number of buffers */
name|disk_line
name|FreePtr
decl_stmt|;
comment|/* position of DFree */
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
decl_stmt|,
name|r_dotline
decl_stmt|,
comment|/* so we can really save the context */
name|r_dotchar
decl_stmt|;
block|}
struct|;
end_struct

end_unit

