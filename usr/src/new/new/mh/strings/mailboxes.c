begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This is where the user mailboxes are kept.  On our 11/70 they were  * kept in each users $HOME directory.  This is where the VAX login  * program is looking for them, as well as the old BELL mail.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mailboxes
init|=
literal|"/usr/spool/mail/"
decl_stmt|;
end_decl_stmt

end_unit

