begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************  *									*  *	dlpt	- download a CCI POWERTERMINAL or POWERTERMINAL II	*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/************************************************************************  *	Compilation Notes --						*  *									*  *	- The symbol  V7  must be defined when compiling for Version 7	*  *	  or Berkeley 4.2.						*  *	- No flags are needed when compiling for S3.			*  *	- This file contains the changes to support the new Berkeley	*  *	  4.2 signaling mechanism that were present at one point, then	*  *	  deleted, and were restored in version 2.3.1.  These changes	*  *	  are required to make timed-out reads work correctly.		*  *	  Compile with NEWSEG set to get these changes.			*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/************************************************************************ Version 1.2.1 changes:  MDS	3/13/84		Implemented logic to circumvent 5/20 CPU port 			  problem.  CPU port loses input characters 			  transmitted by the terminal at 9600 baud. 			  Therefore, if this program receives an invalid 			  DA response and it is talking to a cpu port, 			  then act as if a valid ROM DA response was 			  received. 			Implemented "force" option.  If specicified at 			  execution time the receipt of an invalid DA 			  response will be treated as a valid ROM DA 			  response.  *************************************************************************  Version 2.0.0 changes:  MDS	11/6/84		Implemented logic to support CCI POWERTERMINAL II.  *************************************************************************  Version 2.1.0 changes:  			Version 2.1 is an interim version of dlpt created 			by OSG.  *************************************************************************  Version 2.2.0 changes:  SP& BM @osg MDS	2/20/85		1) -a prompt came up twice on PT1 when 'n' 			given.  Fixed. 			2) If tty is tty01 or console, and dlpt 			cannot determine terminal type, message is 			given for user to manually 'dlpt -f[12]'. 			3) Added argument check to -t option to prevent 			core dump if no arguments given with -t. 			4) In function whoisit() changed fputs to write. 			Fputs did not work on PERPOS-S. 			5) Removed CR1 from ttyinit() for System 3. 			CR1 caused a NULL,ACK to be output after CR 			in Terminal loaded message. 			6) Added XOFF/XON recognition to download by 			adding IXON to ttyinit(). 			7) Changed source to default compile for S3 			instead of V7.  For V7 need to set V7 flag.  *************************************************************************  Version 2.3.0 changes:  BJM @osg BJM	3/6/85		Added XON/XOFF recognition to download for 			Version 7 and Berkeley 4.2 version by setting 			port to CBREAK mode for 'normal' download and 			RAW mode for download in reliability mode.  			Added conditional compilation statements for 			19.2K baud.  *************************************************************************  Version 2.3.1 changes:  woe@ccicpg WOE	6/17/85		Restored changes for new Berkeley 4.2 signalling 			mechanisms under the compile-time define NEWSIG. 			Timed-out reads require these changes since the 			read system call is "automatically" retried when 			interrupted by a SIGALRM (or any other handled/ 			ignored signal).  *************************************************************************/
end_comment

begin_comment
comment|/************************************************************************  *									*  *	Include files.							*  *									*  ************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_comment
comment|/********* if Version 7				*********/
end_comment

begin_include
include|#
directive|include
file|"sgtty.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/********* else assume System 3 		*********/
end_comment

begin_include
include|#
directive|include
file|"termio.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********* end of System 3			*********/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEWSIG
end_ifdef

begin_comment
comment|/* new signal mechanism */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************************  *									*  *	Defines.							*  *									*  ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"2.3.1"
end_define

begin_comment
comment|/* version to be displayed by -v option	*/
end_comment

begin_typedef
typedef|typedef
name|int
name|BOOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PT1_DEFLD
value|"/lib/pt/DEFAULT.LD"
end_define

begin_comment
comment|/* default download file	*/
end_comment

begin_define
define|#
directive|define
name|PT2_DEFLD
value|"/lib/pt/PT2DEF.LD"
end_define

begin_comment
comment|/* default download file	*/
end_comment

begin_define
define|#
directive|define
name|TTY_PREFIX
value|"/dev/"
end_define

begin_comment
comment|/* appended to -t field		*/
end_comment

begin_define
define|#
directive|define
name|STX
value|0x02
end_define

begin_comment
comment|/* cntrl b */
end_comment

begin_define
define|#
directive|define
name|ENQ
value|0x05
end_define

begin_comment
comment|/* cntrl e */
end_comment

begin_define
define|#
directive|define
name|ACK
value|0x06
end_define

begin_comment
comment|/* cntrl f */
end_comment

begin_define
define|#
directive|define
name|CAN
value|0x18
end_define

begin_comment
comment|/* cntrl x */
end_comment

begin_define
define|#
directive|define
name|BELL
value|0x07
end_define

begin_comment
comment|/* cntrl g */
end_comment

begin_define
define|#
directive|define
name|INVRESP
value|0
end_define

begin_comment
comment|/* signal no valid DA response from tty	*/
end_comment

begin_define
define|#
directive|define
name|PT1ROM
value|1
end_define

begin_comment
comment|/* signal that PT1 ROM responded to DA	*/
end_comment

begin_define
define|#
directive|define
name|PT1RAM
value|2
end_define

begin_comment
comment|/* signal that PT1 RAM responded to DA	*/
end_comment

begin_define
define|#
directive|define
name|PT2ROM
value|3
end_define

begin_comment
comment|/* signal that PT2 ROM responded to DA	*/
end_comment

begin_define
define|#
directive|define
name|PT2RAM
value|4
end_define

begin_comment
comment|/* signal that PT2 RAM responded to DA	*/
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|STX_TIMES
value|3
end_define

begin_comment
comment|/* Number of times to send STX block	*/
end_comment

begin_define
define|#
directive|define
name|NRETRIES
value|10
end_define

begin_comment
comment|/* Number of retries for load block	*/
end_comment

begin_define
define|#
directive|define
name|LD_TIMEOUT
value|2
end_define

begin_comment
comment|/* Loading timeout period		*/
end_comment

begin_comment
comment|/************************************************************************  *									*  *	Local functions and variables.					*  *									*  ************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEWSIG
end_ifdef

begin_comment
comment|/* new signal mechanism */
end_comment

begin_decl_stmt
name|jmp_buf
name|jb
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|timoread
value|read
end_define

begin_define
define|#
directive|define
name|timowrite
value|write
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|stxrec
index|[]
init|=
block|{
name|STX
block|,
name|STX
block|,
name|STX
block|,
name|STX
block|,
name|STX
block|,
name|STX
block|,
name|STX
block|,
name|STX
block|,
name|STX
block|,
name|STX
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|nulls
index|[
literal|15
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|can
init|=
name|CAN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|enq
init|=
name|ENQ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ack
init|=
name|ACK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|devname
index|[
literal|25
index|]
init|=
name|TTY_PREFIX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nullcnt
init|=
literal|14
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|timout
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|bailout
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|toterm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to terminal file descriptor		*/
end_comment

begin_decl_stmt
name|int
name|fromterm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from terminal file descriptor	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_comment
comment|/********* if Version 7				*********/
end_comment

begin_decl_stmt
name|char
name|baudrate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* baudrate , set by ttysave or main	*/
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/********* else assume System 3 		*********/
end_comment

begin_decl_stmt
name|unsigned
name|short
name|baudrate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* baudrate , set by ttysave or main	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********* end of System 3			*********/
end_comment

begin_decl_stmt
name|char
modifier|*
name|myname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of this program			*/
end_comment

begin_decl_stmt
name|BOOL
name|rflag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reliability mode			*/
end_comment

begin_decl_stmt
name|char
name|fflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force mode (used if inv DA response	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|intro
index|[]
init|=
block|{
literal|"\n"
block|,
literal|"DO YOU WANT A TERMINAL LOAD SEQUENCE?"
block|,
literal|" "
block|,
literal|"  If you do not answer within 15 seconds,"
block|,
literal|"  the terminal load sequence will begin."
block|,
literal|" "
block|,
literal|"ENTER: y<return>  or<return>  to load "
block|,
literal|"            n<return>  to avoid load :"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|wrong
index|[]
init|=
block|{
literal|"INVALID ANSWER"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|loading
index|[]
init|=
block|{
literal|"\n"
block|,
literal|"Terminal load in progress"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************************************************************  *									*  *	main	- Do it.						*  *									*  ************************************************************************/
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|char
modifier|*
name|pt1file
decl_stmt|;
name|char
modifier|*
name|pt2file
decl_stmt|;
name|int
name|who
decl_stmt|;
comment|/* who is responding			*/
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
name|BOOL
name|aflag
init|=
name|FALSE
decl_stmt|;
comment|/* TRUE if inquire wanted before load 	*/
name|myname
operator|=
operator|*
name|argv
operator|++
expr_stmt|;
comment|/* get the name of this program 	*/
operator|--
name|argc
expr_stmt|;
name|ttysave
argument_list|()
expr_stmt|;
comment|/* save ioctl params and init default baudrate */
name|pt1file
operator|=
name|PT1_DEFLD
expr_stmt|;
comment|/* set default hex file for load	*/
name|pt2file
operator|=
name|PT2_DEFLD
expr_stmt|;
comment|/* set default hex file for load	*/
while|while
condition|(
name|argc
operator|--
condition|)
comment|/* while there are arguments to process */
block|{
if|if
condition|(
operator|*
operator|*
name|argv
operator|==
literal|'-'
condition|)
comment|/* while flags left */
block|{
name|char
modifier|*
name|fptr
init|=
operator|*
name|argv
decl_stmt|;
comment|/* get ptr to flags */
while|while
condition|(
operator|*
operator|++
name|fptr
condition|)
comment|/* while flags left */
block|{
name|char
name|atobaud
parameter_list|()
function_decl|;
switch|switch
condition|(
operator|*
name|fptr
condition|)
comment|/* process a flag  */
block|{
case|case
literal|'a'
case|:
comment|/* ask if load wanted */
name|aflag
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
comment|/* specific baud rate */
if|if
condition|(
name|fptr
index|[
literal|1
index|]
operator|!=
literal|'\0'
condition|)
block|{
name|baudrate
operator|=
name|atobaud
argument_list|(
operator|++
name|fptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|baudrate
operator|==
operator|(
name|char
operator|)
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s - invalid baud\n"
argument_list|,
name|myname
argument_list|,
name|fptr
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
block|}
name|fptr
operator|=
literal|"x"
expr_stmt|;
comment|/* fake out */
break|break;
block|}
else|else
block|{
if|if
condition|(
name|argc
operator|<
literal|1
condition|)
name|usage
argument_list|()
expr_stmt|;
name|baudrate
operator|=
name|atobaud
argument_list|(
operator|*
operator|++
name|argv
argument_list|)
expr_stmt|;
operator|--
name|argc
expr_stmt|;
if|if
condition|(
name|baudrate
operator|==
operator|(
name|char
operator|)
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s - invalid baud\n"
argument_list|,
name|myname
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|'f'
case|:
comment|/* force mode		* 						 * to force load if	* 						 * invalid DA response	*/
comment|/* get type '1' or '2' for	* 					 *   PT1 or PT2			*/
name|fflag
operator|=
operator|*
operator|++
name|fptr
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
comment|/*reliability mode */
name|rflag
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
comment|/* specific port	*/
if|if
condition|(
name|fptr
index|[
literal|1
index|]
operator|!=
literal|0
condition|)
block|{
name|strcat
argument_list|(
name|devname
argument_list|,
operator|++
name|fptr
argument_list|)
expr_stmt|;
name|fptr
operator|=
literal|"x"
expr_stmt|;
comment|/* fake out	*/
block|}
else|else
block|{
if|if
condition|(
name|argc
operator|<
literal|1
condition|)
name|usage
argument_list|()
expr_stmt|;
name|strcat
argument_list|(
name|devname
argument_list|,
operator|*
operator|++
name|argv
argument_list|)
expr_stmt|;
operator|--
name|argc
expr_stmt|;
block|}
if|if
condition|(
name|freopen
argument_list|(
name|devname
argument_list|,
literal|"w"
argument_list|,
name|stdout
argument_list|)
operator|==
operator|(
name|FILE
operator|*
operator|)
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: cannot open port for write - %s\n"
argument_list|,
name|myname
argument_list|,
name|devname
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|freopen
argument_list|(
name|devname
argument_list|,
literal|"r"
argument_list|,
name|stdin
argument_list|)
operator|==
operator|(
name|FILE
operator|*
operator|)
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: cannot open port for read - %s\n"
argument_list|,
name|myname
argument_list|,
name|devname
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
literal|'v'
case|:
comment|/* display version */
name|printf
argument_list|(
literal|"%s: Version %s\n"
argument_list|,
name|myname
argument_list|,
name|VERSION
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %c - unknown flag\n"
argument_list|,
name|myname
argument_list|,
operator|*
name|fptr
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
else|else
block|{
name|pt1file
operator|=
operator|*
name|argv
expr_stmt|;
name|pt2file
operator|=
operator|*
name|argv
expr_stmt|;
block|}
operator|++
name|argv
expr_stmt|;
block|}
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|bailout
argument_list|)
expr_stmt|;
name|toterm
operator|=
literal|1
expr_stmt|;
comment|/* standard output		*/
name|fromterm
operator|=
literal|0
expr_stmt|;
comment|/* standard input		*/
name|who
operator|=
name|whoisit
argument_list|()
expr_stmt|;
comment|/* find out who is there	*/
if|if
condition|(
name|who
operator|==
name|INVRESP
condition|)
comment|/* if an invalid or no response		*/
switch|switch
condition|(
name|fflag
condition|)
block|{
comment|/* check for force wanted		*/
case|case
literal|'1'
case|:
comment|/* if PT1 force wanted		*/
name|who
operator|=
name|PT1ROM
expr_stmt|;
comment|/* force a PT1 download		*/
break|break;
case|case
literal|'2'
case|:
comment|/* if PT2 force wanted		*/
name|who
operator|=
name|PT2ROM
expr_stmt|;
comment|/* force a PT2 download		*/
break|break;
default|default:
block|{
comment|/* else no force		*/
name|char
modifier|*
name|devwho
decl_stmt|;
name|devwho
operator|=
name|ttyname
argument_list|(
name|toterm
argument_list|)
expr_stmt|;
comment|/* get name of port	*/
if|if
condition|(
operator|(
name|strcmp
argument_list|(
name|devwho
argument_list|,
literal|"/dev/console"
argument_list|)
operator|==
literal|0
operator|)
operator|||
operator|(
name|strcmp
argument_list|(
name|devwho
argument_list|,
literal|"/dev/tty01"
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"%s: from console or tty01, enter 'dlpt -f#'\n-f1 for PT1, -f2 for PT2\n"
argument_list|,
name|myname
argument_list|)
expr_stmt|;
name|ttyrestore
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
switch|switch
condition|(
name|who
condition|)
comment|/* depending on who responded		*/
block|{
case|case
name|PT1RAM
case|:
comment|/* is a downloaded PT1 ( CT )	*/
case|case
name|PT2RAM
case|:
comment|/* is a downloaded PT2		*/
name|ttytalk
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\r\nTerminal loaded\r\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|PT1ROM
case|:
comment|/* is a non-downloaded PT1	*/
if|if
condition|(
operator|(
operator|!
name|aflag
operator|)
operator|||
operator|(
operator|(
name|aflag
operator|)
operator|&&
operator|(
name|wantptload
argument_list|()
operator|)
operator|)
condition|)
block|{
name|ttytalk
argument_list|()
expr_stmt|;
name|putmsg
argument_list|(
name|loading
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dlpt1
argument_list|(
name|pt1file
argument_list|)
expr_stmt|;
comment|/* load terminal	*/
comment|/************************************************ 			 * NOTE: If terminal DTR is tied to CPU DCD	* 			 *   AND the terminal firmware re-initializes	* 			 *   the 8251 I/O chip, DCD is dropped which	* 			 *   causes this program to get killed at this	* 			 *   point.  This is the case for the PT	* 			 *   terminal as of 10/25/83.			* 			 ************************************************/
name|sleep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|/* wait for terminal to initialize	*/
name|printf
argument_list|(
literal|"Terminal download complete\r\n"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|PT2ROM
case|:
comment|/* is a non-downloaded PT2	*/
if|if
condition|(
operator|(
operator|!
name|aflag
operator|)
operator|||
operator|(
operator|(
name|aflag
operator|)
operator|&&
operator|(
name|wantptload
argument_list|()
operator|)
operator|)
condition|)
block|{
name|ttytalk
argument_list|()
expr_stmt|;
name|putmsg
argument_list|(
name|loading
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dlpt2
argument_list|(
name|pt2file
argument_list|)
expr_stmt|;
comment|/* load terminal	*/
name|sleep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|/* wait for terminal to initialize	*/
name|printf
argument_list|(
literal|"Terminal download complete\r\n"
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
name|ttyrestore
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/************************************************************************  *									*  *	usage - print usage statement and abort				*  *									*  ************************************************************************/
end_comment

begin_macro
name|usage
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: %s [-a] [-fTermNo] [-r] [-b BaudRate] [-t ttyXX] [load file]\n"
argument_list|,
name|myname
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/************************************************************************  *									*  *	PT down-load rtn						*  *									*  ************************************************************************/
end_comment

begin_macro
name|dlpt1
argument_list|(
argument|hexfile
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|hexfile
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|in
decl_stmt|;
comment|/* input file			*/
name|int
name|i
decl_stmt|;
comment|/* counter			*/
name|int
name|rs
decl_stmt|;
comment|/* record size			*/
name|char
name|record
index|[
literal|524
index|]
decl_stmt|;
comment|/* record			*/
name|int
name|cs
decl_stmt|;
comment|/* checksum			*/
name|char
modifier|*
name|rp
decl_stmt|;
comment|/* record pointer		*/
name|char
name|csum
index|[
literal|2
index|]
decl_stmt|;
comment|/* received checksum		*/
name|in
operator|=
name|stdin
expr_stmt|;
name|timout
operator|=
literal|0
expr_stmt|;
comment|/* Alarm time-out flag		*/
if|if
condition|(
operator|(
name|in
operator|=
name|fopen
argument_list|(
name|hexfile
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
operator|(
name|FILE
operator|*
operator|)
name|NULL
condition|)
name|fatal
argument_list|(
literal|"Can't open input file."
argument_list|)
expr_stmt|;
name|ttyinit
argument_list|()
expr_stmt|;
comment|/* set up port for load 			*/
for|for
control|(
name|i
operator|=
name|STX_TIMES
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
if|if
condition|(
name|write
argument_list|(
name|toterm
argument_list|,
name|stxrec
argument_list|,
sizeof|sizeof
argument_list|(
name|stxrec
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|stxrec
argument_list|)
condition|)
name|fatal
argument_list|(
literal|"1. Can't write STX to terminal."
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|rs
operator|=
name|getrec1
argument_list|(
name|in
argument_list|,
name|record
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
for|for
control|(
name|cs
operator|=
literal|0
operator|,
name|i
operator|=
name|rs
operator|,
name|rp
operator|=
name|record
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
name|cs
operator|+=
operator|*
name|rp
operator|++
expr_stmt|;
for|for
control|(
name|i
operator|=
name|NRETRIES
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
block|{
if|if
condition|(
name|write
argument_list|(
name|toterm
argument_list|,
name|record
argument_list|,
name|rs
argument_list|)
operator|!=
name|rs
condition|)
name|derror
argument_list|(
literal|"3. Can't write record to terminal."
argument_list|)
expr_stmt|;
if|if
condition|(
name|write
argument_list|(
name|toterm
argument_list|,
name|nulls
argument_list|,
name|nullcnt
argument_list|)
operator|!=
name|nullcnt
condition|)
name|derror
argument_list|(
literal|"4. Can't write NULLS to terminal."
argument_list|)
expr_stmt|;
if|if
condition|(
name|rflag
operator|==
name|TRUE
condition|)
block|{
name|alarm
argument_list|(
name|LD_TIMEOUT
argument_list|)
expr_stmt|;
comment|/*  time limit */
name|timout
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|timowrite
argument_list|(
name|toterm
argument_list|,
operator|&
name|ack
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
operator|||
operator|(
name|timout
operator|)
condition|)
block|{
name|derror
argument_list|(
literal|"6. Can't write ACK to terminal."
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|alarm
argument_list|(
name|LD_TIMEOUT
argument_list|)
expr_stmt|;
comment|/* time limit */
name|timout
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|timoread
argument_list|(
name|fromterm
argument_list|,
name|csum
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
operator|||
operator|(
name|timout
operator|)
condition|)
block|{
name|derror
argument_list|(
literal|"7. Can't read ACK from terminal."
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|alarm
argument_list|(
name|LD_TIMEOUT
argument_list|)
expr_stmt|;
comment|/* time limit */
name|timout
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|timoread
argument_list|(
name|fromterm
argument_list|,
name|csum
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
operator|||
operator|(
name|timout
operator|)
condition|)
block|{
name|derror
argument_list|(
literal|"8. Can't read csum count from terminal."
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|csum
index|[
literal|0
index|]
operator|!=
name|ACK
condition|)
block|{
name|derror
argument_list|(
literal|"9. Protocol violation not ACK."
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|(
operator|(
name|cs
operator|&
literal|0x3f
operator|)
operator|+
literal|0x20
operator|)
operator|==
name|csum
index|[
literal|1
index|]
condition|)
break|break;
block|}
comment|/* end of reliabilaty logic */
else|else
break|break;
block|}
comment|/* end of for loop */
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|fatal
argument_list|(
literal|"10. Number of retries exceeded."
argument_list|)
expr_stmt|;
if|if
condition|(
name|rs
operator|==
literal|11
condition|)
comment|/* Last record			*/
return|return;
block|}
if|if
condition|(
name|rs
operator|==
literal|0
condition|)
name|fatal
argument_list|(
literal|"11. End of file reached before end-of-load record."
argument_list|)
expr_stmt|;
else|else
name|fatal
argument_list|(
literal|"12. Bad record read."
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/************************************************************************  *									*  * TITLE:	dlpt2 - down load CCI POWERTERMINAL II			*  *									*  * RETURNS:	nothing							*  *									*  ************************************************************************/
end_comment

begin_macro
name|dlpt2
argument_list|(
argument|hexfile
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|hexfile
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|in
decl_stmt|;
comment|/* input file			*/
name|int
name|i
decl_stmt|;
comment|/* counter			*/
name|int
name|rs
decl_stmt|;
comment|/* record size			*/
name|char
name|record
index|[
literal|524
index|]
decl_stmt|;
comment|/* record			*/
name|in
operator|=
name|stdin
expr_stmt|;
name|timout
operator|=
literal|0
expr_stmt|;
comment|/* Alarm time-out flag		*/
if|if
condition|(
operator|(
name|in
operator|=
name|fopen
argument_list|(
name|hexfile
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
operator|(
name|FILE
operator|*
operator|)
name|NULL
condition|)
name|fatal
argument_list|(
literal|"Can't open input file."
argument_list|)
expr_stmt|;
name|ttyinit
argument_list|()
expr_stmt|;
comment|/* set up port for load 			*/
name|ttyflush
argument_list|()
expr_stmt|;
comment|/* flush port before attempting com		*/
for|for
control|(
name|i
operator|=
name|STX_TIMES
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
if|if
condition|(
name|write
argument_list|(
name|toterm
argument_list|,
name|stxrec
argument_list|,
sizeof|sizeof
argument_list|(
name|stxrec
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|stxrec
argument_list|)
condition|)
name|fatal
argument_list|(
literal|"1. Can't write STX to terminal."
argument_list|)
expr_stmt|;
if|if
condition|(
name|rflag
operator|==
name|TRUE
condition|)
comment|/* if rel mode wanted - tell PT2	*/
block|{
if|if
condition|(
name|write
argument_list|(
name|toterm
argument_list|,
operator|&
name|enq
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
condition|)
block|{
name|d2error
argument_list|(
literal|"16. Can't write ENQ to terminal."
argument_list|)
expr_stmt|;
block|}
block|}
while|while
condition|(
operator|(
name|rs
operator|=
name|getrec2
argument_list|(
name|in
argument_list|,
name|record
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
for|for
control|(
name|i
operator|=
name|NRETRIES
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
block|{
if|if
condition|(
name|write
argument_list|(
name|toterm
argument_list|,
name|record
argument_list|,
name|rs
argument_list|)
operator|!=
name|rs
condition|)
name|d2error
argument_list|(
literal|"3. Can't write record to terminal."
argument_list|)
expr_stmt|;
comment|/* 		if( write ( toterm, nulls, nullcnt ) != nullcnt ) 			d2error ("4. Can't write NULLS to terminal."); */
if|if
condition|(
name|rflag
operator|==
name|TRUE
condition|)
block|{
name|char
name|resp
decl_stmt|;
comment|/* resp char		*/
name|alarm
argument_list|(
name|LD_TIMEOUT
argument_list|)
expr_stmt|;
comment|/* time limit */
name|timout
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|timoread
argument_list|(
name|fromterm
argument_list|,
operator|&
name|resp
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
operator|)
operator|||
operator|(
name|timout
operator|)
condition|)
block|{
name|d2error
argument_list|(
literal|"17. Can't read ACK from terminal."
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|resp
operator|==
name|ACK
condition|)
break|break;
comment|/* get txmit next char	*/
name|d2error
argument_list|(
literal|"19. Protocol violation not ACK."
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/* end of reliabilaty logic	*/
else|else
break|break;
comment|/* no verification wanted	*/
block|}
comment|/* end of error retry loop	*/
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|fatal
argument_list|(
literal|"20. Number of retries exceeded."
argument_list|)
expr_stmt|;
comment|/* a complete record has been transmitted		*/
comment|/* check if it was the last record			*/
if|if
condition|(
name|record
index|[
literal|1
index|]
operator|==
literal|'8'
condition|)
comment|/* was it an S8 record?	*/
return|return;
comment|/* if so, done !!	*/
block|}
if|if
condition|(
name|rs
operator|==
literal|0
condition|)
name|fatal
argument_list|(
literal|"21. End of file reached before end-of-load record."
argument_list|)
expr_stmt|;
else|else
name|fatal
argument_list|(
literal|"22. Bad record read."
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/************************************************************************  *									*  *	derror - have an error handle and return			*  *									*  ************************************************************************/
end_comment

begin_function
name|int
name|derror
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* cancel alarms */
name|write
argument_list|(
name|toterm
argument_list|,
operator|&
name|can
argument_list|,
sizeof|sizeof
argument_list|(
name|can
argument_list|)
argument_list|)
expr_stmt|;
comment|/* cancel */
name|write
argument_list|(
name|toterm
argument_list|,
name|nulls
argument_list|,
name|nullcnt
argument_list|)
expr_stmt|;
comment|/* pad for next write */
name|fputs
argument_list|(
name|s
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\r\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/************************************************************************  *									*  *	d2error - have an error handle and return			*  *									*  ************************************************************************/
end_comment

begin_function
name|int
name|d2error
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* cancel alarms */
name|fputs
argument_list|(
name|s
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\r\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/************************************************************************  *									*  *	getrec1	- Get a PT1 (CT) record to transmit.			*  *									*  *	Returns:							*  *		-1	Error in file format.				*  *		0	End of file reached.				*  *> 0	Size of record to transmit.			*  *									*  ************************************************************************/
end_comment

begin_function
name|int
name|getrec1
parameter_list|(
name|fd
parameter_list|,
name|rp
parameter_list|)
name|FILE
modifier|*
name|fd
decl_stmt|;
name|char
modifier|*
name|rp
decl_stmt|;
block|{
name|int
name|c
decl_stmt|;
name|int
name|nc
decl_stmt|;
comment|/* number of characters		*/
name|int
name|l
decl_stmt|;
comment|/* length of record bytes	*/
name|int
name|cc
decl_stmt|;
comment|/* checksum			*/
name|int
name|i
decl_stmt|;
comment|/* counter			*/
name|int
name|a
decl_stmt|;
comment|/* address piece		*/
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|fd
argument_list|)
operator|)
operator|!=
literal|':'
condition|)
comment|/* Look for start of record	*/
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
return|return
literal|0
return|;
comment|/* End of file			*/
comment|/*****	Start record off.					*/
comment|/*%%%	printf("At record start\n");/*%%*/
operator|*
name|rp
operator|++
operator|=
literal|':'
expr_stmt|;
name|nc
operator|=
literal|1
expr_stmt|;
comment|/*****	Get number of hex bytes in record.			*/
if|if
condition|(
operator|(
name|l
operator|=
name|getxb
argument_list|(
name|fd
argument_list|,
name|rp
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/*%%%	printf("%d data bytes\n", l);/*%%*/
name|cc
operator|=
name|l
expr_stmt|;
comment|/* Start checksum		*/
name|rp
operator|+=
literal|2
expr_stmt|;
comment|/* Past two characters		*/
name|nc
operator|+=
literal|2
expr_stmt|;
comment|/* Two more characters		*/
comment|/*****	Get address portion of data record.			*/
for|for
control|(
name|i
operator|=
literal|2
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
comment|/* Two hex bytes		*/
block|{
if|if
condition|(
operator|(
name|a
operator|=
name|getxb
argument_list|(
name|fd
argument_list|,
name|rp
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|cc
operator|+=
name|a
expr_stmt|;
comment|/* Figure address into checksum	*/
name|rp
operator|+=
literal|2
expr_stmt|;
comment|/* Past two characters		*/
name|nc
operator|+=
literal|2
expr_stmt|;
comment|/* Two more characters		*/
block|}
comment|/*****	Read type byte, which should be zero.			*/
if|if
condition|(
operator|(
name|i
operator|=
name|getxb
argument_list|(
name|fd
argument_list|,
name|rp
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|cc
operator|+=
name|i
expr_stmt|;
comment|/* Figure type into checksum	*/
name|rp
operator|+=
literal|2
expr_stmt|;
comment|/* Past two characters		*/
name|nc
operator|+=
literal|2
expr_stmt|;
comment|/* Two more characters		*/
comment|/*****	Read in the data record.				*/
while|while
condition|(
name|l
operator|--
operator|>
literal|0
condition|)
comment|/* Count down			*/
block|{
if|if
condition|(
operator|(
name|i
operator|=
name|getxb
argument_list|(
name|fd
argument_list|,
name|rp
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/*%%%	printf ("Read %d\n", i);/*%%*/
name|cc
operator|+=
name|i
expr_stmt|;
comment|/* Checksum			*/
name|rp
operator|+=
literal|2
expr_stmt|;
comment|/* Pointer			*/
name|nc
operator|+=
literal|2
expr_stmt|;
comment|/* Number of characters		*/
block|}
name|cc
operator|=
operator|(
operator|-
name|cc
operator|)
operator|&
literal|0377
expr_stmt|;
comment|/* Two's complement byte	*/
comment|/*%%%	printf ("Checksum = %x\n", cc);/*%%*/
operator|*
name|rp
operator|=
name|cc
operator|>>
literal|4
expr_stmt|;
operator|*
name|rp
operator|+=
operator|*
name|rp
operator|<
literal|10
condition|?
literal|'0'
else|:
literal|'A'
operator|-
literal|10
expr_stmt|;
operator|*
operator|++
name|rp
operator|=
name|cc
operator|&
literal|0xF
expr_stmt|;
operator|*
name|rp
operator|+=
operator|*
name|rp
operator|<
literal|10
condition|?
literal|'0'
else|:
literal|'A'
operator|-
literal|10
expr_stmt|;
comment|/*%%%	printf ("record size = %d\n", nc + 2);/*%%*/
return|return
name|nc
operator|+
literal|2
return|;
block|}
end_function

begin_comment
comment|/************************************************************************  *									*  * TITLE:	getrec2 - Get a POWERTERMINAL II record to transmit	*  *									*  * RETURNS:								*  *		-1	Error in file format.				*  *		0	End of file reached.				*  *> 0	Size of record to transmit.			*  *									*  ************************************************************************/
end_comment

begin_function
name|int
name|getrec2
parameter_list|(
name|fd
parameter_list|,
name|rp
parameter_list|)
name|FILE
modifier|*
name|fd
decl_stmt|;
name|char
modifier|*
name|rp
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|rrp
decl_stmt|;
comment|/* register copy of record ptr	*/
name|char
name|c
decl_stmt|;
comment|/* temp store of read char	*/
name|int
name|nc
decl_stmt|;
comment|/* number of characters		*/
name|int
name|l
decl_stmt|;
comment|/* length of record bytes	*/
name|rrp
operator|=
name|rp
expr_stmt|;
comment|/* get addr in a register	*/
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|fd
argument_list|)
operator|)
operator|!=
literal|'S'
condition|)
comment|/* Look for start of record	*/
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* End of file			*/
operator|*
name|rrp
operator|++
operator|=
name|c
expr_stmt|;
comment|/* put first char of record	*/
name|nc
operator|=
literal|1
expr_stmt|;
comment|/* start the char counter	*/
if|if
condition|(
operator|(
operator|*
name|rrp
operator|++
operator|=
name|getc
argument_list|(
name|fd
argument_list|)
operator|)
operator|<
literal|0
condition|)
comment|/* get S-record type	*/
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* if EOF, return		*/
name|nc
operator|++
expr_stmt|;
comment|/* incre num of chars		*/
if|if
condition|(
operator|(
name|l
operator|=
name|getxb
argument_list|(
name|fd
argument_list|,
name|rrp
argument_list|)
operator|)
operator|<
literal|0
condition|)
comment|/* get num of bytes		*/
return|return
operator|-
literal|1
return|;
name|rrp
operator|+=
literal|2
expr_stmt|;
comment|/* Past two characters		*/
name|nc
operator|+=
literal|2
expr_stmt|;
comment|/* Two more characters		*/
comment|/* get address, data, and checksum fields			*/
name|l
operator|<<=
literal|1
expr_stmt|;
comment|/* chg to num nibbles (times 2)	*/
while|while
condition|(
name|l
operator|--
operator|>
literal|0
condition|)
block|{
comment|/* l now contains num of nibbles*/
if|if
condition|(
operator|(
operator|*
name|rrp
operator|++
operator|=
name|getc
argument_list|(
name|fd
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|nc
operator|++
expr_stmt|;
comment|/* bump char counter		*/
block|}
return|return
operator|(
name|nc
operator|)
return|;
comment|/* return num of chars in rec	*/
block|}
end_function

begin_comment
comment|/************************************************************************  *									*  *	getxb	- Get a hex byte.					*  *									*  *	Returns:							*  *		-1	Error in file format or end of file reached.	*  *>= 0	Integer value of byte.				*  *									*  ************************************************************************/
end_comment

begin_function
name|int
name|getxb
parameter_list|(
name|fd
parameter_list|,
name|sp
parameter_list|)
name|FILE
modifier|*
name|fd
decl_stmt|;
name|char
modifier|*
name|sp
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
if|if
condition|(
operator|(
name|i
operator|=
name|getxn
argument_list|(
name|fd
argument_list|,
name|sp
operator|++
argument_list|)
operator|)
operator|<
literal|0
operator|||
operator|(
name|j
operator|=
name|getxn
argument_list|(
name|fd
argument_list|,
name|sp
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
return|return
operator|(
name|i
operator|<<
literal|4
operator|)
operator||
name|j
return|;
block|}
end_function

begin_comment
comment|/************************************************************************  *									*  *	getxn	- Get a hex nibble.					*  *									*  *	Returns:							*  *		-1	Error in file format or end of file reached.	*  *>= 0	Integer value of nibble.			*  *									*  ************************************************************************/
end_comment

begin_function
name|int
name|getxn
parameter_list|(
name|fd
parameter_list|,
name|sp
parameter_list|)
name|FILE
modifier|*
name|fd
decl_stmt|;
name|char
modifier|*
name|sp
decl_stmt|;
block|{
specifier|register
name|int
name|c
decl_stmt|;
operator|*
name|sp
operator|=
name|c
operator|=
name|getc
argument_list|(
name|fd
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|>=
literal|'0'
operator|&&
name|c
operator|<=
literal|'9'
condition|)
return|return
name|c
operator|-
literal|'0'
return|;
elseif|else
if|if
condition|(
name|c
operator|>=
literal|'A'
operator|&&
name|c
operator|<=
literal|'F'
condition|)
return|return
name|c
operator|-
literal|'A'
operator|+
literal|10
return|;
elseif|else
if|if
condition|(
name|c
operator|>=
literal|'a'
operator|&&
name|c
operator|<=
literal|'f'
condition|)
return|return
name|c
operator|-
literal|'a'
operator|+
literal|10
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|NEWSIG
end_ifdef

begin_comment
comment|/* new signal mechanism */
end_comment

begin_comment
comment|/************************************************************************  *									*  *	timoread/timowrite - read/write with timeout			*  *									*  ************************************************************************/
end_comment

begin_macro
name|timoread
argument_list|(
argument|fd
argument_list|,
argument|ptr
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|setjmp
argument_list|(
name|jb
argument_list|)
operator|==
literal|0
condition|)
return|return
name|read
argument_list|(
name|fd
argument_list|,
name|ptr
argument_list|,
name|size
argument_list|)
return|;
return|return
operator|-
literal|1
return|;
block|}
end_block

begin_macro
name|timowrite
argument_list|(
argument|fd
argument_list|,
argument|ptr
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|setjmp
argument_list|(
name|jb
argument_list|)
operator|==
literal|0
condition|)
return|return
name|write
argument_list|(
name|fd
argument_list|,
name|ptr
argument_list|,
name|size
argument_list|)
return|;
return|return
operator|-
literal|1
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************************  *									*  *	fatal - display error message and abort				*  *									*  ************************************************************************/
end_comment

begin_function
name|int
name|fatal
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|write
argument_list|(
name|toterm
argument_list|,
operator|&
name|can
argument_list|,
sizeof|sizeof
argument_list|(
name|can
argument_list|)
argument_list|)
expr_stmt|;
comment|/* write cancel to terminal */
name|write
argument_list|(
name|toterm
argument_list|,
name|nulls
argument_list|,
name|nullcnt
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|s
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\r\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|ttyrestore
argument_list|()
expr_stmt|;
comment|/* put terminal back to orig state	*/
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/************************************************************************  *									*  *	wantptload - inquire if the user wants a download		*  *									*  ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|80
end_define

begin_comment
comment|/* size of answer buffers		*/
end_comment

begin_define
define|#
directive|define
name|WANT_WAIT
value|15
end_define

begin_comment
comment|/* time to wait for answer 		*/
end_comment

begin_macro
name|wantptload
argument_list|()
end_macro

begin_block
block|{
name|char
name|answer
index|[
name|BUFSIZE
index|]
decl_stmt|;
name|ttytalk
argument_list|()
expr_stmt|;
comment|/* talk slow - do not lose chars    */
while|while
condition|(
literal|1
condition|)
block|{
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* allow time to prevent truncation */
name|putmsg
argument_list|(
name|intro
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* output msg, 0 pad null per line */
name|alarm
argument_list|(
name|WANT_WAIT
argument_list|)
expr_stmt|;
name|timout
operator|=
literal|0
expr_stmt|;
operator|*
name|answer
operator|=
literal|'\0'
expr_stmt|;
name|timoread
argument_list|(
literal|0
argument_list|,
name|answer
argument_list|,
sizeof|sizeof
name|answer
argument_list|)
expr_stmt|;
if|if
condition|(
name|timout
condition|)
return|return
operator|(
name|TRUE
operator|)
return|;
else|else
block|{
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* reset the alarm */
switch|switch
condition|(
operator|*
name|answer
condition|)
block|{
case|case
literal|'y'
case|:
case|case
literal|'Y'
case|:
case|case
literal|'\n'
case|:
return|return
operator|(
name|TRUE
operator|)
return|;
case|case
literal|'n'
case|:
case|case
literal|'N'
case|:
return|return
operator|(
name|FALSE
operator|)
return|;
default|default:
name|putmsg
argument_list|(
name|wrong
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_block

begin_comment
comment|/************************************************************************  *									*  *	putmsg - put a msg to terminal with null padding at end of line	*  *									*  ************************************************************************/
end_comment

begin_macro
name|putmsg
argument_list|(
argument|text
argument_list|,
argument|pad
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
modifier|*
name|text
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to list of string pointers */
end_comment

begin_decl_stmt
name|int
name|pad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of nulls to output after each line */
end_comment

begin_block
block|{
while|while
condition|(
operator|*
name|text
operator|!=
name|NULL
condition|)
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|ptr
init|=
operator|*
name|text
decl_stmt|;
while|while
condition|(
operator|*
name|ptr
condition|)
block|{
name|putchar
argument_list|(
operator|*
name|ptr
operator|++
argument_list|)
expr_stmt|;
block|}
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|pad
condition|;
name|i
operator|++
control|)
name|putchar
argument_list|(
literal|'\0'
argument_list|)
expr_stmt|;
name|text
operator|++
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/************************************************************************  *									*  *	whoisit - Determine if the PT terminal is already downloaded	*  *									*  *		returns PT1ROM if ROM responds to DA command		*  *		returns PT1RAM if RAM responds to DA command		*  *		returns INVRESP if no or invalid response received	*  *									*  ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DA
value|"\033[c"
end_define

begin_comment
comment|/* ANSI DA ESC seq to send to terminal	*/
end_comment

begin_comment
comment|/* Note that in the following expected DA response sequences, only the 	first 7 chars are used to match.  This allows for future 	changes in the software version number without having to change 	this program. (The PT ROM& RAM respond with version number(s) 	in addition to the following characters.)			 */
end_comment

begin_define
define|#
directive|define
name|RAM1RSP
value|"\033[=0;1;"
end_define

begin_comment
comment|/* ANSI DA ESC response from PT (CT) RAM	*/
end_comment

begin_define
define|#
directive|define
name|ROM1RSP
value|"\033[=0;0;"
end_define

begin_comment
comment|/* ANSI DA ESC response from PT (CT) ROM	*/
end_comment

begin_define
define|#
directive|define
name|RAM2RSP
value|"\033[=1;1;"
end_define

begin_comment
comment|/* ANSI DA ESC response from PT2 RAM	*/
end_comment

begin_define
define|#
directive|define
name|ROM2RSP
value|"\033[=1;0;"
end_define

begin_comment
comment|/* ANSI DA ESC response from PT2 ROM	*/
end_comment

begin_define
define|#
directive|define
name|DATERM
value|'c'
end_define

begin_comment
comment|/* ANSI DA ESC sequence terminator		*/
end_comment

begin_define
define|#
directive|define
name|ASK_WAIT
value|3
end_define

begin_comment
comment|/* time to wait for ESC response	*/
end_comment

begin_define
define|#
directive|define
name|ASK_TIMES
value|3
end_define

begin_comment
comment|/* number of times to send DA req block	*/
end_comment

begin_define
define|#
directive|define
name|MAX_WRONG_CHARS
value|30
end_define

begin_comment
comment|/* max number of chars to wait for ESC	*/
end_comment

begin_macro
name|whoisit
argument_list|()
end_macro

begin_block
block|{
name|char
name|response
index|[
name|MAX_WRONG_CHARS
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|ttyinit
argument_list|()
expr_stmt|;
comment|/* make port raw for ESC sequence	*/
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|ASK_TIMES
condition|;
name|j
operator|++
control|)
comment|/* allow retries */
block|{
name|ttyflush
argument_list|()
expr_stmt|;
comment|/* flush port before attempting com	*/
comment|/* send DA cmd, is terminal loaded ?			*/
name|write
argument_list|(
name|toterm
argument_list|,
name|DA
argument_list|,
sizeof|sizeof
argument_list|(
name|DA
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
name|ASK_WAIT
argument_list|)
expr_stmt|;
name|timout
operator|=
literal|0
expr_stmt|;
name|response
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Synchronize on first character of expected response	*/
while|while
condition|(
name|response
index|[
literal|0
index|]
operator|!=
operator|*
name|ROM1RSP
condition|)
block|{
if|if
condition|(
name|timoread
argument_list|(
literal|0
argument_list|,
operator|&
name|response
index|[
literal|0
index|]
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|char
argument_list|)
condition|)
block|{
if|if
condition|(
name|timout
condition|)
break|break;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\n\rDA ESC char read error\n\r"
argument_list|)
expr_stmt|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
block|}
if|if
condition|(
name|timout
condition|)
comment|/* time-out here means no good response	*/
continue|continue;
comment|/* try again			*/
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* make sure alarm is cleared	*/
comment|/* At this point we have the first char of expected 		   response.  Now get the rest of it.			*/
for|for
control|(
name|i
operator|=
literal|1
init|;
operator|(
operator|(
name|response
index|[
name|i
operator|-
literal|1
index|]
operator|!=
name|DATERM
operator|)
operator|&&
operator|(
name|i
operator|<
name|MAX_WRONG_CHARS
operator|-
literal|1
operator|)
operator|)
condition|;
name|i
operator|++
control|)
block|{
name|alarm
argument_list|(
name|ASK_WAIT
argument_list|)
expr_stmt|;
name|timout
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|timoread
argument_list|(
literal|0
argument_list|,
operator|&
name|response
index|[
name|i
index|]
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|char
argument_list|)
condition|)
block|{
if|if
condition|(
name|timout
condition|)
break|break;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\n\rDA string read error\n\r"
argument_list|)
expr_stmt|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* make sure alarm is cleared	*/
block|}
if|if
condition|(
name|timout
condition|)
comment|/* if time-out, did not get enough chars*/
continue|continue;
comment|/* retry DA command		*/
comment|/* At this point we have at least a matching first char 		   in response.  Now compare the complete string read in 		   with the expected response.				*/
if|if
condition|(
name|strncmp
argument_list|(
name|ROM1RSP
argument_list|,
name|response
argument_list|,
sizeof|sizeof
argument_list|(
name|ROM1RSP
argument_list|)
operator|-
literal|1
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|PT1ROM
operator|)
return|;
if|if
condition|(
name|strncmp
argument_list|(
name|RAM1RSP
argument_list|,
name|response
argument_list|,
sizeof|sizeof
argument_list|(
name|RAM1RSP
argument_list|)
operator|-
literal|1
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|PT1RAM
operator|)
return|;
if|if
condition|(
name|strncmp
argument_list|(
name|ROM2RSP
argument_list|,
name|response
argument_list|,
sizeof|sizeof
argument_list|(
name|ROM2RSP
argument_list|)
operator|-
literal|1
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|PT2ROM
operator|)
return|;
if|if
condition|(
name|strncmp
argument_list|(
name|RAM2RSP
argument_list|,
name|response
argument_list|,
sizeof|sizeof
argument_list|(
name|RAM2RSP
argument_list|)
operator|-
literal|1
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|PT2RAM
operator|)
return|;
block|}
return|return
operator|(
name|INVRESP
operator|)
return|;
block|}
end_block

begin_comment
comment|/************************************************************************  *									*  * atobaud - convert an ascii number to a baud rate ala B50, B1200, ...	*  *	returns -1 if invalid baud rate is specified.			*  *									*  ************************************************************************/
end_comment

begin_struct
struct|struct
name|baud
block|{
name|char
modifier|*
name|abaud
decl_stmt|;
comment|/* name of baud rate */
name|char
name|ibaud
decl_stmt|;
comment|/* baud rate for ioclt(2) */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|baud
name|baudtbl
index|[]
init|=
block|{
block|{
literal|"110"
block|,
name|B110
block|}
block|,
block|{
literal|"300"
block|,
name|B300
block|}
block|,
block|{
literal|"600"
block|,
name|B600
block|}
block|,
block|{
literal|"1200"
block|,
name|B1200
block|}
block|,
block|{
literal|"2400"
block|,
name|B2400
block|}
block|,
block|{
literal|"4800"
block|,
name|B4800
block|}
block|,
block|{
literal|"9600"
block|,
name|B9600
block|}
block|,
ifdef|#
directive|ifdef
name|B19200
block|{
literal|"19200"
block|,
name|B19200
block|}
block|,
endif|#
directive|endif
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|char
name|atobaud
parameter_list|(
name|string
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
block|{
name|struct
name|baud
modifier|*
name|bptr
init|=
name|baudtbl
decl_stmt|;
comment|/* index in baud rate table */
while|while
condition|(
name|bptr
operator|->
name|abaud
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|bptr
operator|->
name|abaud
argument_list|,
name|string
argument_list|)
operator|==
literal|0
condition|)
block|{
switch|switch
condition|(
name|atoi
argument_list|(
name|string
argument_list|)
condition|)
block|{
case|case
literal|19200
case|:
name|nullcnt
operator|=
literal|14
expr_stmt|;
break|break;
case|case
literal|9600
case|:
name|nullcnt
operator|=
literal|9
expr_stmt|;
break|break;
case|case
literal|4800
case|:
name|nullcnt
operator|=
literal|8
expr_stmt|;
break|break;
case|case
literal|2400
case|:
name|nullcnt
operator|=
literal|6
expr_stmt|;
break|break;
case|case
literal|1200
case|:
name|nullcnt
operator|=
literal|5
expr_stmt|;
break|break;
case|case
literal|300
case|:
case|case
literal|110
case|:
name|nullcnt
operator|=
literal|3
expr_stmt|;
break|break;
default|default:
name|nullcnt
operator|=
literal|14
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|bptr
operator|->
name|ibaud
operator|)
return|;
block|}
operator|++
name|bptr
expr_stmt|;
block|}
return|return
operator|(
operator|(
name|char
operator|)
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/************************************************************************  *									*  *	bailout - alarm interrupt handler				*  *									*  ************************************************************************/
end_comment

begin_macro
name|bailout
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|NEWSIG
comment|/* new signal mechanism */
name|timout
operator|=
literal|1
expr_stmt|;
name|longjmp
argument_list|(
name|jb
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|bailout
argument_list|)
expr_stmt|;
name|timout
operator|=
literal|1
expr_stmt|;
return|return;
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/************************************************************************  *									*  *	tty utilities for performing get& put ioctl's			*  *									*  ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IOC_DELAY
value|1
end_define

begin_comment
comment|/* Delay is needed after ioctl to allow baud- 			   rate change to take effect.  This requirement 			   discovered on 2/21/84 when xmit of the DA 			   seq would result in the first DA attempt to 			   be sent at 9600 baud (irregardless of 			   intended setting) and the second DA to go 			   out at the intended (set by ioctl) rate.	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_comment
comment|/********* if Version 7 tty routines		*********/
end_comment

begin_decl_stmt
name|struct
name|sgttyb
name|tp_new
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sgttyb
name|tp_orig
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tchars
name|tc_new
init|=
block|{
literal|'\177'
block|,
literal|'\034'
block|,
literal|'\021'
block|,
literal|'\023'
block|,
literal|'\004'
block|,
literal|'\377'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tchars
name|tc_orig
decl_stmt|;
end_decl_stmt

begin_macro
name|ttysave
argument_list|()
end_macro

begin_block
block|{
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|tp_orig
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETC
argument_list|,
operator|&
name|tc_orig
argument_list|)
expr_stmt|;
name|baudrate
operator|=
name|tp_orig
operator|.
name|sg_ospeed
expr_stmt|;
block|}
end_block

begin_macro
name|ttyrestore
argument_list|()
end_macro

begin_block
block|{
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETP
argument_list|,
operator|&
name|tp_orig
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|tc_orig
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
name|IOC_DELAY
argument_list|)
expr_stmt|;
comment|/* allow baud to settle		*/
block|}
end_block

begin_macro
name|ttyinit
argument_list|()
end_macro

begin_block
block|{
comment|/* 	 *	Use CBREAK mode for 'normal' download so that the Dow Jones 	 *	mux which generates XON/XOFF will be happy.  XON/XOFF appears 	 *	to screw up reliability mode, however, so stick with RAW 	 *	mode for that. 	 */
name|ttysetup
argument_list|(
operator|(
name|short
operator|)
name|ANYP
operator|+
operator|(
operator|(
name|rflag
operator|)
condition|?
name|RAW
else|:
name|CBREAK
operator|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ttytalk
argument_list|()
end_macro

begin_block
block|{
name|ttysetup
argument_list|(
operator|(
name|short
operator|)
name|ANYP
operator|+
name|ECHO
operator|+
name|CRMOD
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ttysetup
argument_list|(
argument|flags
argument_list|)
end_macro

begin_decl_stmt
name|short
name|flags
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|tp_new
operator|.
name|sg_flags
operator|=
name|flags
expr_stmt|;
name|tp_new
operator|.
name|sg_ispeed
operator|=
name|baudrate
expr_stmt|;
name|tp_new
operator|.
name|sg_ospeed
operator|=
name|baudrate
expr_stmt|;
name|tp_new
operator|.
name|sg_stopbits
operator|=
name|tp_orig
operator|.
name|sg_stopbits
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETP
argument_list|,
operator|&
name|tp_new
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|tc_new
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
name|IOC_DELAY
argument_list|)
expr_stmt|;
comment|/* allow baud to settle		*/
block|}
end_block

begin_macro
name|ttyflush
argument_list|()
end_macro

begin_block
block|{
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCFLUSH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/********* else assume System 3 tty routines	*********/
end_comment

begin_decl_stmt
name|struct
name|termio
name|term_orig
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save area for orig port state	*/
end_comment

begin_decl_stmt
name|struct
name|termio
name|term_new
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new port state			*/
end_comment

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used for 19200 baud delay			*/
end_comment

begin_macro
name|ttysave
argument_list|()
end_macro

begin_block
block|{
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|term_orig
argument_list|)
expr_stmt|;
comment|/* save the initial port state	*/
name|baudrate
operator|=
name|term_orig
operator|.
name|c_cflag
operator|&
name|CBAUD
expr_stmt|;
comment|/* get orig baud	*/
block|}
end_block

begin_macro
name|ttyrestore
argument_list|()
end_macro

begin_block
block|{
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETAF
argument_list|,
operator|&
name|term_orig
argument_list|)
expr_stmt|;
comment|/* restore saved port state	*/
name|sleep
argument_list|(
name|IOC_DELAY
argument_list|)
expr_stmt|;
comment|/* allow baud to settle		*/
block|}
end_block

begin_macro
name|ttyinit
argument_list|()
end_macro

begin_block
block|{
name|term_new
operator|.
name|c_iflag
operator|=
name|ICRNL
operator||
name|ISTRIP
operator||
name|IXON
expr_stmt|;
name|term_new
operator|.
name|c_oflag
operator|=
name|ONLRET
operator||
name|OPOST
expr_stmt|;
name|term_new
operator|.
name|c_cflag
operator|=
name|baudrate
operator||
name|CREAD
operator||
name|CS8
expr_stmt|;
name|term_new
operator|.
name|c_lflag
operator|=
literal|0
expr_stmt|;
name|term_new
operator|.
name|c_line
operator|=
literal|0
expr_stmt|;
name|term_new
operator|.
name|c_cc
index|[
name|VINTR
index|]
operator|=
name|CINTR
expr_stmt|;
name|term_new
operator|.
name|c_cc
index|[
name|VQUIT
index|]
operator|=
name|CQUIT
expr_stmt|;
name|term_new
operator|.
name|c_cc
index|[
name|VERASE
index|]
operator|=
literal|0x08
expr_stmt|;
name|term_new
operator|.
name|c_cc
index|[
name|VKILL
index|]
operator|=
name|CKILL
expr_stmt|;
name|term_new
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
name|term_new
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|1
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETAF
argument_list|,
operator|&
name|term_new
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
name|IOC_DELAY
argument_list|)
expr_stmt|;
comment|/* allow baud to settle		*/
block|}
end_block

begin_macro
name|ttytalk
argument_list|()
end_macro

begin_block
block|{
name|term_new
operator|.
name|c_iflag
operator|=
name|ICRNL
operator||
name|IXON
expr_stmt|;
name|term_new
operator|.
name|c_oflag
operator|=
name|ONLCR
operator||
name|OPOST
expr_stmt|;
name|term_new
operator|.
name|c_cflag
operator|=
name|baudrate
operator||
name|CREAD
operator||
name|CS8
expr_stmt|;
name|term_new
operator|.
name|c_lflag
operator|=
name|ECHO
operator||
name|ECHOE
operator||
name|ECHOK
operator||
name|ICANON
operator||
name|ISIG
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETAF
argument_list|,
operator|&
name|term_new
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
name|IOC_DELAY
argument_list|)
expr_stmt|;
comment|/* allow baud to settle		*/
block|}
end_block

begin_macro
name|ttyflush
argument_list|()
end_macro

begin_block
block|{
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCFLSH
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|/* flush input& output queues	*/
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********* end of System 3 tty routines		*********/
end_comment

end_unit

