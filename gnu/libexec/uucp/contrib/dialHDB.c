begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* # File:		dialHDB.c # Author:	Daniel Hagerty , hag@eddie.mit.edu #		Copyright (C) 1993 # Date:		Fri Nov 26 19:22:31 1993 # Description:	Program for using HDB dialers for dialing modems, exiting 		with 0 on success, else failure. # Version:	1.0 # Revision History: ###### ### 11/26/93 Hag - File creation ###### ### 1/5/94 Hag - Finally got around to finishing this damn thing. ###### */
end_comment

begin_comment
comment|/* Basic theory behind this program-    dialHDB forks into two processes, a monitor parent, and a child    that does the exec of the dialer. Child pretty much just execs the    dialer program, unless there's an exec problem, in which case the    child sends the parent a SIGUSR1 to indicate failed execution. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|kUsage
value|"Usage:\n\t%s dialerPath device number speed\n\ %s dialer -h device speed\n"
end_define

begin_define
define|#
directive|define
name|kExitErrFlag
value|0x80
end_define

begin_comment
comment|/*& in with exit code to determine error */
end_comment

begin_define
define|#
directive|define
name|kErrorMask
value|0x0f
end_define

begin_comment
comment|/* Mask to determine error code */
end_comment

begin_comment
comment|/* Error code defines as lifted from an HDB dialer */
end_comment

begin_define
define|#
directive|define
name|RCE_NULL
value|0
end_define

begin_comment
comment|/* general purpose or unknown error code */
end_comment

begin_define
define|#
directive|define
name|RCE_INUSE
value|1
end_define

begin_comment
comment|/* line in use */
end_comment

begin_define
define|#
directive|define
name|RCE_SIG
value|2
end_define

begin_comment
comment|/* signal aborted dialer */
end_comment

begin_define
define|#
directive|define
name|RCE_ARGS
value|3
end_define

begin_comment
comment|/* invalid arguments */
end_comment

begin_define
define|#
directive|define
name|RCE_PHNO
value|4
end_define

begin_comment
comment|/* invalid phone number */
end_comment

begin_define
define|#
directive|define
name|RCE_SPEED
value|5
end_define

begin_comment
comment|/* invalid baud rate -or- bad connect baud */
end_comment

begin_define
define|#
directive|define
name|RCE_OPEN
value|6
end_define

begin_comment
comment|/* can't open line */
end_comment

begin_define
define|#
directive|define
name|RCE_IOCTL
value|7
end_define

begin_comment
comment|/* ioctl error */
end_comment

begin_define
define|#
directive|define
name|RCE_TIMOUT
value|8
end_define

begin_comment
comment|/* timeout */
end_comment

begin_define
define|#
directive|define
name|RCE_NOTONE
value|9
end_define

begin_comment
comment|/* no dial tone */
end_comment

begin_define
define|#
directive|define
name|RCE_BUSY
value|13
end_define

begin_comment
comment|/* phone is busy */
end_comment

begin_define
define|#
directive|define
name|RCE_NOCARR
value|14
end_define

begin_comment
comment|/* no carrier */
end_comment

begin_define
define|#
directive|define
name|RCE_ANSWER
value|15
end_define

begin_comment
comment|/* no answer */
end_comment

begin_comment
comment|/* Structure definition to map error codes to strings */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|errNum
decl_stmt|;
name|char
modifier|*
name|errString
decl_stmt|;
block|}
name|errTable
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|errTable
name|errors
index|[]
init|=
block|{
block|{
name|RCE_NULL
block|,
literal|"Unknown Error"
block|}
block|,
block|{
name|RCE_INUSE
block|,
literal|"Line is being used"
block|}
block|,
block|{
name|RCE_SIG
block|,
literal|"Recieved fatal signal"
block|}
block|,
block|{
name|RCE_ARGS
block|,
literal|"Bad arguments"
block|}
block|,
block|{
name|RCE_PHNO
block|,
literal|"Invalid phone number"
block|}
block|,
block|{
name|RCE_SPEED
block|,
literal|"Invalid baud rate or bad connection"
block|}
block|,
block|{
name|RCE_OPEN
block|,
literal|"Unable to open line"
block|}
block|,
block|{
name|RCE_IOCTL
block|,
literal|"ioctl error"
block|}
block|,
block|{
name|RCE_TIMOUT
block|,
literal|"Timed out"
block|}
block|,
block|{
name|RCE_NOTONE
block|,
literal|"No dialtone"
block|}
block|,
block|{
name|RCE_BUSY
block|,
literal|"Phone number is busy"
block|}
block|,
block|{
name|RCE_NOCARR
block|,
literal|"No carrier"
block|}
block|,
block|{
name|RCE_ANSWER
block|,
literal|"No answer"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function Prototypes */
end_comment

begin_function_decl
name|int
name|figureStat
parameter_list|(
name|int
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|findInTable
parameter_list|(
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|badExec
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|dialerName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* basename of our dialer program */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dialerPath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* full path of dialer program */
end_comment

begin_function
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|parent
decl_stmt|;
comment|/* pid of parent process */
name|int
name|child
decl_stmt|;
comment|/* pid of child process */
name|int
name|stat
decl_stmt|;
comment|/* exit status of child process */
name|char
modifier|*
name|temp
decl_stmt|;
comment|/* used to get basename of dialer */
if|if
condition|(
name|argc
operator|!=
literal|5
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|kUsage
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|dialerPath
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
name|dialerName
operator|=
operator|(
name|temp
operator|=
name|strrchr
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|!=
name|NULL
condition|?
name|temp
operator|+
literal|1
else|:
name|argv
index|[
literal|1
index|]
expr_stmt|;
name|parent
operator|=
name|getpid
argument_list|()
expr_stmt|;
name|signal
argument_list|(
name|SIGUSR1
argument_list|,
name|badExec
argument_list|)
expr_stmt|;
comment|/* set up for possible failed exec */
if|if
condition|(
operator|(
name|child
operator|=
name|fork
argument_list|()
operator|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"fork"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|child
operator|>
literal|0
condition|)
comment|/* We're parent, wait for child to exit */
block|{
comment|/* Set up to ignore signals so we can report them on stderror */
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|wait
argument_list|(
operator|&
name|stat
argument_list|)
expr_stmt|;
comment|/* wait for child to exit */
name|exit
argument_list|(
name|figureStat
argument_list|(
name|stat
argument_list|)
argument_list|)
expr_stmt|;
comment|/* figure out our exit code and die */
block|}
else|else
comment|/* child process */
block|{
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* close of modem file desc, since HDB */
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* doesn't use them */
name|dup2
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* and remap stdout to stderr, just in case */
if|if
condition|(
name|execvp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
name|argv
operator|+
literal|1
argument_list|)
operator|<
literal|0
condition|)
comment|/* exec program with argv shifted by 1 */
block|{
comment|/* if exec fails, send SIGUSR1 to parent */
name|kill
argument_list|(
name|parent
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Figure out whether or not dialer ran succesfully, and return with 0 if it worked, otherwise error */
end_comment

begin_function
name|int
name|figureStat
parameter_list|(
name|int
name|stat
parameter_list|)
block|{
name|int
name|exit
decl_stmt|;
name|int
name|errFlag
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
name|WIFSIGNALED
argument_list|(
name|stat
argument_list|)
condition|)
comment|/* determine if exit was from signal or what */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error: Dialer %s recieved signal %d.\n"
argument_list|,
name|dialerName
argument_list|,
name|WTERMSIG
argument_list|(
name|stat
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|WIFSTOPPED
argument_list|(
name|stat
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error: Dialer %s recieved signal %d.\n"
argument_list|,
name|dialerName
argument_list|,
name|WSTOPSIG
argument_list|(
name|stat
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|exit
operator|=
name|WEXITSTATUS
argument_list|(
name|stat
argument_list|)
expr_stmt|;
name|errFlag
operator|=
name|exit
operator|&
name|kExitErrFlag
expr_stmt|;
comment|/* Is the error flag set? */
if|if
condition|(
name|errFlag
condition|)
block|{
name|char
modifier|*
name|errString
decl_stmt|;
name|error
operator|=
name|exit
operator|&
name|kErrorMask
expr_stmt|;
name|errString
operator|=
name|findInTable
argument_list|(
name|error
argument_list|)
expr_stmt|;
comment|/* find it's string, print it on stderr */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error: %s - %s.\n"
argument_list|,
name|dialerName
argument_list|,
name|errString
argument_list|)
expr_stmt|;
comment|/* and return */
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Support routine, look up exit code in error table, and return pointer to proper string */
end_comment

begin_function
name|char
modifier|*
name|findInTable
parameter_list|(
name|int
name|error
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|errors
index|[
name|i
index|]
operator|.
name|errString
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|errors
index|[
name|i
index|]
operator|.
name|errNum
operator|==
name|error
condition|)
return|return
operator|(
name|errors
index|[
name|i
index|]
operator|.
name|errString
operator|)
return|;
block|}
comment|/* Still here, return the top entry, for unknown error */
return|return
operator|(
name|errors
index|[
literal|0
index|]
operator|.
name|errString
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Called by signal if we recieve SIGUSR 1 */
end_comment

begin_function
name|void
name|badExec
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error: %s - Execution problem.\n"
argument_list|,
name|dialerPath
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

