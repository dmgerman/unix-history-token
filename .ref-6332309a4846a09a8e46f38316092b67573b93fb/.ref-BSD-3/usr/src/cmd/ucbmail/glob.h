begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A bunch of global variable declarations lie herein.  * def.h must be included first.  */
end_comment

begin_decl_stmt
name|int
name|msgCount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count of messages read in */
end_comment

begin_decl_stmt
name|int
name|mypid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current process id */
end_comment

begin_decl_stmt
name|int
name|rcvmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if receiving mail */
end_comment

begin_decl_stmt
name|int
name|sawcom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set after first command */
end_comment

begin_decl_stmt
name|int
name|hflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sequence number for network -h */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -r address for network */
end_comment

begin_decl_stmt
name|int
name|selfsent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User sent self something */
end_comment

begin_decl_stmt
name|int
name|senderr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An error while checking */
end_comment

begin_decl_stmt
name|int
name|edit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indicates editing a file */
end_comment

begin_decl_stmt
name|int
name|sourcing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Currently reading variant file */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|itf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input temp file buffer */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|otf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output temp file buffer */
end_comment

begin_decl_stmt
name|int
name|image
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor for image of msg */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|input
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current command input file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|editfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of file being edited */
end_comment

begin_decl_stmt
name|int
name|outtty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if standard output a tty */
end_comment

begin_decl_stmt
name|int
name|intty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if standard input a tty */
end_comment

begin_decl_stmt
name|char
name|mbox
index|[
name|PATHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of mailbox file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mailname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of system mailbox */
end_comment

begin_decl_stmt
name|char
name|mailspace
index|[
name|PATHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Space norm alloc'd for name */
end_comment

begin_decl_stmt
name|int
name|uid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The invoker's user id */
end_comment

begin_decl_stmt
name|char
name|mailrc
index|[
name|PATHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of startup file */
end_comment

begin_decl_stmt
name|char
name|deadletter
index|[
name|PATHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of #/dead.letter */
end_comment

begin_decl_stmt
name|char
name|homedir
index|[
name|PATHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Path name of home directory */
end_comment

begin_decl_stmt
name|char
name|myname
index|[
literal|9
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* My login id */
end_comment

begin_decl_stmt
name|off_t
name|mailsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of system mailbox */
end_comment

begin_decl_stmt
name|int
name|lexnumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of TNUMBER from scan() */
end_comment

begin_decl_stmt
name|char
name|lexstring
index|[
name|STRINGLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String from TSTRING, scan() */
end_comment

begin_decl_stmt
name|int
name|regretp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to TOS of regret tokens */
end_comment

begin_decl_stmt
name|int
name|regretstack
index|[
name|REGDEP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack of regretted tokens */
end_comment

begin_decl_stmt
name|char
modifier|*
name|stringstack
index|[
name|REGDEP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack of regretted strings */
end_comment

begin_decl_stmt
name|int
name|numberstack
index|[
name|REGDEP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack of regretted numbers */
end_comment

begin_decl_stmt
name|struct
name|message
modifier|*
name|dot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to current message */
end_comment

begin_decl_stmt
name|struct
name|message
modifier|*
name|message
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The actual message structure */
end_comment

begin_decl_stmt
name|struct
name|var
modifier|*
name|variables
index|[
name|HSHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to active var list */
end_comment

begin_decl_stmt
name|struct
name|grouphead
modifier|*
name|groups
index|[
name|HSHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to active groups */
end_comment

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug flag set */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|jmp_buf
name|srbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The pointers for the string allocation routines,  * there are NSPACE independent areas.  * The first holds STRINGSIZE bytes, the next  * twice as much, and so on.  */
end_comment

begin_define
define|#
directive|define
name|NSPACE
value|8
end_define

begin_comment
comment|/* Total number of string spaces */
end_comment

begin_struct
struct|struct
name|strings
block|{
name|char
modifier|*
name|s_topFree
decl_stmt|;
comment|/* Beginning of this area */
name|char
modifier|*
name|s_nextFree
decl_stmt|;
comment|/* Next alloctable place here */
name|unsigned
name|s_nleft
decl_stmt|;
comment|/* Number of bytes left here */
block|}
name|stringdope
index|[
name|NSPACE
index|]
struct|;
end_struct

end_unit

