begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This is where the lock files are kept.  It MUST be on the same  * file system as the "mailboxes" directory.  It also must be read/  * write by the world.  When a mailbox needs locking (while being  * read and cleared by inc, or written by deliver), a link to the  * mailbox is made in this directory, under the same name (i.e., the  * users name).  Links are one of the few things even a privileged  * process (deliver) cannot over-ride.  The deliver process waits  * for lockwait seconds for the lock to clear, then it over-rides  * the lock.  This number should be set around 15-30 seconds in the  * case of a VERY loaded system.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lockdir
init|=
literal|"/usr/spool/mail/"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lockwait
init|=
literal|15
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Seconds */
end_comment

end_unit

