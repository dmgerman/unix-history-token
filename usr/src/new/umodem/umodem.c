begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)umodem.c	1.1	(Berkeley)	11/2/84"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  *  UMODEM Version 3.7  *  *  UMODEM -- Implements the "CP/M User's Group XMODEM" protocol,   *	      the TERM II File Transfer Protocol (FTP) Number 1,  *	      and the TERM II File Transfer Protocol Number 4 for  *            packetized file up/downloading.      *  *    Note: UNIX System-Dependent values are indicated by the string [SD]  *          in a comment field on the same line as the values.  *  *  *         -- Lauren Weinstein, 6/81  *	   -- (Version 2.0) Modified for JHU/UNIX by Richard Conn, 8/1/81  *	   -- Version 2.1 Mods by Richard Conn, 8/2/81  *		. File Size Included on Send Option  *	   -- Version 2.2 Mods by Richard Conn, 8/2/81  *		. Log File Generation and Option Incorporated  *	   -- Version 2.3 Mods by Richard Conn, 8/3/81  *		. TERM II FTP 1 Supported  *		. Error Log Reports Enhanced  *		. CAN Function Added to FTP 3  *		. 'd' Option Added to Delete umodem.log File before starting  *	   -- Version 2.4 Mods by Richard Conn, 8/4/81  *		. 16K-extent sector number check error corrected  *		. Count of number of received sectors added  *	   -- Version 2.5 Mods by Richard Conn, 8/5/81  *		. ARPA Net Flag added  *		. ARPA Net parameter ('a') added to command line  *		. ARPA Net BIS, BIE, BOS, BOE added  *		. ARPA Net FFH escape added  *	   -- Version 2.6 Mods by Bennett Marks, 8/21/81 (Bucky @ CCA-UNIX)  *		. mods for UNIX V7 (Note: for JHU compilation define  *		  the variable JHU  during 'cc'  *		. added 'mungmode' flag to protect from inadvertant  *		  overwrite on file receive  *		. changed timeout handling prior to issuing checksum  *	   -- Version 2.7 Mods by Richard Conn, 8/25/81 (rconn @ BRL)  *		. correct minor "ifndef" error in which ifndef had no arg  *		. restructured "ifdef" references so that other versions  *		  of UNIX than Version 7 and JHU can be easily incorporated;  *		  previous ifdef references were for JHU/not JHU;  *		  to compile under Version 7 or JHU UNIX, the following  *		  command lines are recommended:  *			"cc umodem.c -o umodem -DVER7" for Version 7  *			"cc -7 umodem.c -o umodem -DJHU" for JHU  *		. added 'y' file status display option; this option gives  *		  the user an estimate of the size of the target file to  *		  send from the UNIX system in terms of CP/M records (128  *		  bytes) and Kbytes (1024 byte units)  *		. added '7' option which modifies the transmission protocols  *		  for 7 significant bits rather than 8; modifies both FTP 1  *		  and FTP 3  *	   -- Version 2.8 Mods by Richard Conn, 8/28/81  *		. corrected system-dependent reference to TIOCSSCR (for  *		  disabling page mode) and created the PAGEMODE flag which  *		  is to be set to TRUE to enable this  *		. added -4 option which engages TERM II, FTP 4 (new release)  *	   -- Version 2.9 Mods by Richard Conn, 9/1/81  *		. internal documentation on ARPA Net protocols expanded  *		. possible operator precedence problem with BITMASK corrected  *		  by redundant parentheses  *	   -- Version 3.0 Mods by Lauren Weinstein, 9/14/81  *              . fixed bug in PAGEMODE defines (removed PAGEMODE define  *	          line; now should be compiled with "-DPAGEMODE" if  *		  Page Mode is desired)  *		. included forward declaration of ttyname() to avoid problems  *		  with newer V7 C compilers  *         -- Version 3.1 Mods by Lauren Weinstein, 4/17/82  *		. avoids sending extraneous last sector when file EOF  *	          occurs on an exact sector boundary  *	   -- Version 3.2 Mods by Michael M Rubenstein, 5/26/83  *	        . fixed bug in readbyte.  assumed that int's are ordered  *		  from low significance to high  *		. added LOGDEFAULT define to allow default logging to be  *		  off.  compile with -DLOGDEFAULT=0 to set default to no  *		  logging.  *	   -- Version 3.3 Mod by Ben Goldfarb, 07/02/83  *		. Corrected problem with above implementation of "LOGDEFAULT".  *		  A bitwise, instead of a logical negation operator was  *		  used to complement LOGFLAG when the '-l' command line  *		  flag was specified.  This can cause LOGFLAG to be true  *		  when it should be false.  *	   -- Version 3.4 Mods by David F. Hinnant, NCECS, 7/15/83  *		. placed log file in HOME directory in case user doesn't  *		  have write permission in working directory.  *		. added DELDEFAULT define to allow default purge/no purge  *		  of logfile before starting.  Compile with -DDELDEFAULT=0  *		  to set default to NOT delete the log file before starting.  *		. check log file for sucessful fopen().  *		. buffer disk read for sfile().  *		. turn messages off (standard v7) before starting.  *	   -- Version 3.5 Mods by Richard Conn, 08/27/83  *		. added equates for compilation under UNIX SYSTEM III  *			to compile for SYSTEM III, use -DSYS3 instead of  *			-DJHU or -DVER7  *		. added command mode (-c option) for continuous entry  *			of commands  * 	   -- Version 3.6 Mods by Ben Goldfarb (ucf-cs!goldfarb), 09/03/83  *		. added '#include<ctype.h>' since tolower() is used, but  *		  is not defined in umodem.  This is necessary to compile  *		  on V7 systems.  Also added a isupper() test because   *		  tolower() in /usr/include/ctype.h doesn't do that.  *		. cleaned up all the improper bitwise complementation of  *		  logical constants and variables.  *	   -- Version 3.7 Mods by Noel J. Bergman, 02/27/84  *		. Corrected problem with ALARM signal in 4.2 BSD Unix.  *		  BSD Unix restarts system calls after signal is handled,  *		  so setjmp() and longjmp() are used to handle I/O timeout.  *		  Since this will work with all Unix systems, and is a lot  *		  cleaner than depending on side effects, there is no need  *		  to make this code conditional.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/*  JHU UNIX tty parameter file  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JHU
end_ifdef

begin_include
include|#
directive|include
file|<stty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  Version 7 UNIX tty parameter file  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VER7
end_ifdef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  UNIX SYSTEM III tty parameter file  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS3
end_ifdef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* log default define */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOGDEFAULT
end_ifndef

begin_define
define|#
directive|define
name|LOGDEFAULT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Delete logfile define.  Useful on small systems with limited  * filesystem space and careless users.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DELDEFAULT
end_ifndef

begin_define
define|#
directive|define
name|DELDEFAULT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|VERSION
value|37
end_define

begin_comment
comment|/* Version Number */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/*  Compile with "-DPAGEMODE" if Page Mode (TIOCSSCR) is supported on your  *  UNIX system.  If it is supported, make sure that TIOCSSCR is the  *  correct name for Page Mode engagement.  */
end_comment

begin_comment
comment|/*  ASCII Constants  */
end_comment

begin_define
define|#
directive|define
name|SOH
value|001
end_define

begin_define
define|#
directive|define
name|STX
value|002
end_define

begin_define
define|#
directive|define
name|ETX
value|003
end_define

begin_define
define|#
directive|define
name|EOT
value|004
end_define

begin_define
define|#
directive|define
name|ENQ
value|005
end_define

begin_define
define|#
directive|define
name|ACK
value|006
end_define

begin_define
define|#
directive|define
name|LF
value|012
end_define

begin_comment
comment|/* Unix LF/NL */
end_comment

begin_define
define|#
directive|define
name|CR
value|015
end_define

begin_define
define|#
directive|define
name|NAK
value|025
end_define

begin_define
define|#
directive|define
name|SYN
value|026
end_define

begin_define
define|#
directive|define
name|CAN
value|030
end_define

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_define
define|#
directive|define
name|CTRLZ
value|032
end_define

begin_comment
comment|/* CP/M EOF for text (usually!) */
end_comment

begin_comment
comment|/*  UMODEM Constants  */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT
value|-1
end_define

begin_define
define|#
directive|define
name|ERRORMAX
value|10
end_define

begin_comment
comment|/* maximum errors tolerated */
end_comment

begin_define
define|#
directive|define
name|RETRYMAX
value|10
end_define

begin_comment
comment|/* maximum retries to be made */
end_comment

begin_define
define|#
directive|define
name|BBUFSIZ
value|128
end_define

begin_comment
comment|/* buffer size -- do not change! */
end_comment

begin_comment
comment|/*  [SD] Mode for Created Files  */
end_comment

begin_define
define|#
directive|define
name|CREATMODE
value|0600
end_define

begin_comment
comment|/* mode for created files */
end_comment

begin_comment
comment|/*  ARPA Net Constants  */
end_comment

begin_comment
comment|/*	The following constants are used to communicate with the ARPA  *	Net SERVER TELNET and TIP programs.  These constants are defined  *	as follows:  *		IAC<-- Is A Command; indicates that  *						a command follows  *		WILL/WONT<-- Command issued to SERVER TELNET  *						(Host); WILL issues command  *						and WONT issues negative of  *						the command  *		DO/DONT<-- Command issued to TIP; DO issues  *						command and DONT issues  *						negative of the command  *		TRBIN<-- Transmit Binary Command  *	Examples:  *		IAC WILL TRBIN<-- Host is configured to transmit Binary  *		IAC WONT TRBIN<-- Host is configured NOT to transmit binary  *		IAC DO TRBIN<-- TIP is configured to transmit Binary  *		IAC DONT TRBIN<-- TIP is configured NOT to transmit binary  */
end_comment

begin_define
define|#
directive|define
name|IAC
value|0377
end_define

begin_comment
comment|/* Is A Command */
end_comment

begin_define
define|#
directive|define
name|DO
value|0375
end_define

begin_comment
comment|/* Command to TIP */
end_comment

begin_define
define|#
directive|define
name|DONT
value|0376
end_define

begin_comment
comment|/* Negative of Command to TIP */
end_comment

begin_define
define|#
directive|define
name|WILL
value|0373
end_define

begin_comment
comment|/* Command to SERVER TELNET (Host) */
end_comment

begin_define
define|#
directive|define
name|WONT
value|0374
end_define

begin_comment
comment|/* Negative of Command to SERVER TELNET */
end_comment

begin_define
define|#
directive|define
name|TRBIN
value|0
end_define

begin_comment
comment|/* Transmit Binary Command */
end_comment

begin_comment
comment|/*  JHU UNIX structures  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JHU
end_ifdef

begin_decl_stmt
name|struct
name|sttybuf
name|ttys
decl_stmt|,
name|ttysnew
decl_stmt|,
name|ttystemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for stty terminal mode calls */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  Version 7 UNIX structures  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VER7
end_ifdef

begin_decl_stmt
name|struct
name|sgttyb
name|ttys
decl_stmt|,
name|ttysnew
decl_stmt|,
name|ttystemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for stty terminal mode calls */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  UNIX SYSTEM III structures  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS3
end_ifdef

begin_decl_stmt
name|struct
name|sgttyb
name|ttys
decl_stmt|,
name|ttysnew
decl_stmt|,
name|ttystemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for stty terminal mode calls */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|stat
name|statbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for terminal message on/off control */
end_comment

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|FILE
modifier|*
name|LOGFP
decl_stmt|,
modifier|*
name|fopen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|buff
index|[
name|BBUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nbchr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of chars read so far for buffered read */
end_comment

begin_decl_stmt
name|int
name|wason
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VER7
end_ifdef

begin_decl_stmt
name|int
name|pagelen
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* forward declaration for C */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS3
end_ifdef

begin_decl_stmt
name|int
name|pagelen
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* forward declaration for C */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|tty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|XMITTYPE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ARPA
decl_stmt|,
name|CMNDFLAG
decl_stmt|,
name|RECVFLAG
decl_stmt|,
name|SENDFLAG
decl_stmt|,
name|FTP1
decl_stmt|,
name|PMSG
decl_stmt|,
name|DELFLAG
decl_stmt|,
name|LOGFLAG
decl_stmt|,
name|MUNGMODE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|STATDISP
decl_stmt|,
name|BIT7
decl_stmt|,
name|BITMASK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|delay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|filename
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|env
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|alarmfunc
parameter_list|()
function_decl|;
end_function_decl

begin_function
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
name|getenv
parameter_list|()
function_decl|;
name|char
modifier|*
name|fname
init|=
name|filename
decl_stmt|;
name|char
modifier|*
name|logfile
decl_stmt|;
name|int
name|index
decl_stmt|;
name|char
name|flag
decl_stmt|;
name|logfile
operator|=
literal|"umodem.log"
expr_stmt|;
comment|/* Name of LOG File */
name|printf
argument_list|(
literal|"\nUMODEM Version %d.%d"
argument_list|,
name|VERSION
operator|/
literal|10
argument_list|,
name|VERSION
operator|%
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -- UNIX-Based Remote File Transfer Facility\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
operator|||
operator|*
name|argv
index|[
literal|1
index|]
operator|!=
literal|'-'
condition|)
block|{
name|help
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|index
operator|=
literal|1
expr_stmt|;
comment|/* set index for loop */
name|delay
operator|=
literal|3
expr_stmt|;
comment|/* assume FTP 3 delay */
name|PMSG
operator|=
name|FALSE
expr_stmt|;
comment|/* turn off flags */
name|FTP1
operator|=
name|FALSE
expr_stmt|;
comment|/* assume FTP 3 (CP/M UG XMODEM2) */
name|RECVFLAG
operator|=
name|FALSE
expr_stmt|;
comment|/* not receive */
name|SENDFLAG
operator|=
name|FALSE
expr_stmt|;
comment|/* not send either */
name|CMNDFLAG
operator|=
name|FALSE
expr_stmt|;
comment|/* not command either */
name|XMITTYPE
operator|=
literal|'t'
expr_stmt|;
comment|/* assume text */
name|DELFLAG
operator|=
name|DELDEFAULT
expr_stmt|;
name|LOGFLAG
operator|=
name|LOGDEFAULT
expr_stmt|;
name|ARPA
operator|=
name|FALSE
expr_stmt|;
comment|/* assume not on ARPA Net */
name|MUNGMODE
operator|=
name|FALSE
expr_stmt|;
comment|/* protect files from overwriting */
name|STATDISP
operator|=
name|FALSE
expr_stmt|;
comment|/* assume not a status display */
name|BIT7
operator|=
name|FALSE
expr_stmt|;
comment|/* assume 8-bit communication */
while|while
condition|(
operator|(
name|flag
operator|=
name|argv
index|[
literal|1
index|]
index|[
name|index
operator|++
index|]
operator|)
operator|!=
literal|'\0'
condition|)
switch|switch
condition|(
name|flag
condition|)
block|{
case|case
literal|'1'
case|:
name|FTP1
operator|=
name|TRUE
expr_stmt|;
comment|/* select FTP 1 */
name|delay
operator|=
literal|5
expr_stmt|;
comment|/* FTP 1 delay constant */
name|printf
argument_list|(
literal|"\nUMODEM:  TERM II FTP 1 Selected\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'4'
case|:
name|FTP1
operator|=
name|TRUE
expr_stmt|;
comment|/* select FTP 1 (varient) */
name|BIT7
operator|=
name|TRUE
expr_stmt|;
comment|/* transfer only 7 bits */
name|delay
operator|=
literal|5
expr_stmt|;
comment|/* FTP 1 delay constant */
name|printf
argument_list|(
literal|"\nUMODEM:  TERM II FTP 4 Selected\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'7'
case|:
name|BIT7
operator|=
name|TRUE
expr_stmt|;
comment|/* transfer only 7 bits */
break|break;
case|case
literal|'a'
case|:
name|ARPA
operator|=
name|TRUE
expr_stmt|;
comment|/* set ARPA Net */
break|break;
case|case
literal|'c'
case|:
name|CMNDFLAG
operator|=
name|TRUE
expr_stmt|;
comment|/* command mode */
break|break;
case|case
literal|'d'
case|:
name|DELFLAG
operator|=
operator|!
name|DELDEFAULT
expr_stmt|;
comment|/* delete log file ? */
break|break;
case|case
literal|'l'
case|:
name|LOGFLAG
operator|=
operator|!
name|LOGDEFAULT
expr_stmt|;
comment|/* turn off log ? */
break|break;
case|case
literal|'m'
case|:
name|MUNGMODE
operator|=
name|TRUE
expr_stmt|;
comment|/* allow overwriting of files */
break|break;
case|case
literal|'p'
case|:
name|PMSG
operator|=
name|TRUE
expr_stmt|;
comment|/* print all messages */
break|break;
case|case
literal|'r'
case|:
name|RECVFLAG
operator|=
name|TRUE
expr_stmt|;
comment|/* receive file */
name|XMITTYPE
operator|=
name|gettype
argument_list|(
name|argv
index|[
literal|1
index|]
index|[
name|index
operator|++
index|]
argument_list|)
expr_stmt|;
comment|/* get t/b */
break|break;
case|case
literal|'s'
case|:
name|SENDFLAG
operator|=
name|TRUE
expr_stmt|;
comment|/* send file */
name|XMITTYPE
operator|=
name|gettype
argument_list|(
name|argv
index|[
literal|1
index|]
index|[
name|index
operator|++
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'y'
case|:
name|STATDISP
operator|=
name|TRUE
expr_stmt|;
comment|/* display file status */
break|break;
default|default  :
name|error
argument_list|(
literal|"Invalid Flag"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|BIT7
operator|&&
operator|(
name|XMITTYPE
operator|==
literal|'b'
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"\nUMODEM:  Fatal Error -- Both 7-Bit Transfer and "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Binary Transfer Selected"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* error exit to UNIX */
block|}
if|if
condition|(
name|BIT7
condition|)
comment|/* set MASK value */
name|BITMASK
operator|=
literal|0177
expr_stmt|;
comment|/* 7 significant bits */
else|else
name|BITMASK
operator|=
literal|0377
expr_stmt|;
comment|/* 8 significant bits */
if|if
condition|(
name|PMSG
condition|)
block|{
name|printf
argument_list|(
literal|"\nSupported File Transfer Protocols:"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\tTERM II FTP 1"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\tCP/M UG XMODEM2 (TERM II FTP 3)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\tTERM II FTP 4"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|CMNDFLAG
condition|)
name|LOGFLAG
operator|=
name|TRUE
expr_stmt|;
comment|/* if command mode, always log */
if|if
condition|(
name|LOGFLAG
condition|)
block|{
if|if
condition|(
operator|(
name|fname
operator|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
operator|)
operator|==
literal|0
condition|)
comment|/* Get HOME variable */
name|error
argument_list|(
literal|"Can't get Environment!"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|fname
operator|=
name|strcat
argument_list|(
name|fname
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
name|fname
operator|=
name|strcat
argument_list|(
name|fname
argument_list|,
name|logfile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|DELFLAG
condition|)
name|LOGFP
operator|=
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
comment|/* append to LOG file */
else|else
name|LOGFP
operator|=
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
comment|/* new LOG file */
if|if
condition|(
operator|!
name|LOGFP
condition|)
name|error
argument_list|(
literal|"Can't Open Log File"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"\n\n++++++++\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"\nUMODEM Version %d.%d\n"
argument_list|,
name|VERSION
operator|/
literal|10
argument_list|,
name|VERSION
operator|%
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nUMODEM:  LOG File '%s' is Open\n"
argument_list|,
name|fname
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|STATDISP
condition|)
block|{
name|yfile
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|/* status of a file */
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* exit to UNIX */
block|}
if|if
condition|(
name|RECVFLAG
operator|&&
name|SENDFLAG
condition|)
name|error
argument_list|(
literal|"Both Send and Receive Functions Specified"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|RECVFLAG
operator|&&
operator|!
name|SENDFLAG
operator|&&
operator|!
name|CMNDFLAG
condition|)
name|error
argument_list|(
literal|"Send, Receive, or Command Functions NOT Given"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|RECVFLAG
condition|)
block|{
if|if
condition|(
name|open
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|,
literal|0
argument_list|)
operator|!=
operator|-
literal|1
condition|)
comment|/* possible abort if file exists */
block|{
name|printf
argument_list|(
literal|"\nUMODEM:  Warning -- Target File Exists\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|MUNGMODE
operator|==
name|FALSE
condition|)
name|error
argument_list|(
literal|"Fatal - Can't overwrite file\n"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"UMODEM:  Overwriting Target File\n"
argument_list|)
expr_stmt|;
block|}
name|rfile
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|/* receive file */
block|}
else|else
block|{
if|if
condition|(
name|SENDFLAG
condition|)
name|sfile
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|/* send file */
else|else
name|command
argument_list|()
expr_stmt|;
comment|/* command mode */
block|}
if|if
condition|(
name|CMNDFLAG
condition|)
name|LOGFLAG
operator|=
name|TRUE
expr_stmt|;
comment|/* for closing log file */
if|if
condition|(
name|LOGFLAG
condition|)
name|fclose
argument_list|(
name|LOGFP
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  Major Command Mode  */
end_comment

begin_macro
name|command
argument_list|()
end_macro

begin_block
block|{
name|char
name|cmd
decl_stmt|,
modifier|*
name|fname
decl_stmt|;
name|char
modifier|*
name|infile
parameter_list|()
function_decl|;
name|printf
argument_list|(
literal|"\nUMODEM Command Mode -- Type ? for Help"
argument_list|)
expr_stmt|;
do|do
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|FTP1
condition|?
literal|"1"
else|:
literal|"3"
argument_list|)
expr_stmt|;
comment|/* FTP 1 or 3? */
name|printf
argument_list|(
name|BIT7
condition|?
literal|"7"
else|:
literal|" "
argument_list|)
expr_stmt|;
comment|/* BIT 7 or not? */
name|printf
argument_list|(
name|ARPA
condition|?
literal|"A"
else|:
literal|" "
argument_list|)
expr_stmt|;
comment|/* ARPA Net or not? */
name|printf
argument_list|(
name|LOGFLAG
condition|?
literal|"L"
else|:
literal|" "
argument_list|)
expr_stmt|;
comment|/* Log Entries or not? */
name|printf
argument_list|(
name|MUNGMODE
condition|?
literal|"M"
else|:
literal|" "
argument_list|)
expr_stmt|;
comment|/* Mung Files or not? */
name|printf
argument_list|(
literal|" UMODEM> "
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%s"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|cmd
operator|=
name|isupper
argument_list|(
name|filename
index|[
literal|0
index|]
argument_list|)
condition|?
name|tolower
argument_list|(
name|filename
index|[
literal|0
index|]
argument_list|)
else|:
name|filename
index|[
literal|0
index|]
expr_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
literal|'1'
case|:
name|FTP1
operator|=
name|TRUE
expr_stmt|;
comment|/* select FTP 1 */
name|delay
operator|=
literal|5
expr_stmt|;
comment|/* FTP 1 delay constant */
name|printf
argument_list|(
literal|"\nTERM FTP 1 Selected"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'3'
case|:
name|FTP1
operator|=
name|FALSE
expr_stmt|;
comment|/* select FTP 3 */
name|delay
operator|=
literal|3
expr_stmt|;
comment|/* FTP 3 delay constant */
name|printf
argument_list|(
literal|"\nTERM FTP 3 Selected"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'7'
case|:
name|BIT7
operator|=
operator|!
name|BIT7
expr_stmt|;
comment|/* toggle 7 bit transfer */
name|printf
argument_list|(
literal|"\n7-Bit Transfer %s Selected"
argument_list|,
name|BIT7
condition|?
literal|""
else|:
literal|"NOT"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
name|ARPA
operator|=
operator|!
name|ARPA
expr_stmt|;
comment|/* toggle ARPA Net */
name|printf
argument_list|(
literal|"\nDDN Interface %s Selected"
argument_list|,
name|ARPA
condition|?
literal|""
else|:
literal|"NOT"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
name|LOGFLAG
operator|=
operator|!
name|LOGFLAG
expr_stmt|;
comment|/* toggle log flag */
name|printf
argument_list|(
literal|"\nEntry Logging %s Enabled"
argument_list|,
name|LOGFLAG
condition|?
literal|""
else|:
literal|"NOT"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
name|MUNGMODE
operator|=
operator|!
name|MUNGMODE
expr_stmt|;
comment|/* toggle file overwrite */
name|printf
argument_list|(
literal|"\nFile Overwriting %s Enabled"
argument_list|,
name|MUNGMODE
condition|?
literal|""
else|:
literal|"NOT"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|RECVFLAG
operator|=
name|TRUE
expr_stmt|;
comment|/* receive file */
name|XMITTYPE
operator|=
name|tolower
argument_list|(
name|filename
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|fname
operator|=
name|infile
argument_list|()
expr_stmt|;
comment|/* get file name */
if|if
condition|(
operator|*
name|fname
operator|!=
literal|'\0'
condition|)
name|rfile
argument_list|(
name|fname
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|SENDFLAG
operator|=
name|TRUE
expr_stmt|;
comment|/* send file */
name|XMITTYPE
operator|=
name|tolower
argument_list|(
name|filename
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|fname
operator|=
name|infile
argument_list|()
expr_stmt|;
comment|/* get file name */
if|if
condition|(
operator|*
name|fname
operator|!=
literal|'\0'
condition|)
name|sfile
argument_list|(
name|fname
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
break|break;
case|case
literal|'y'
case|:
name|fname
operator|=
name|infile
argument_list|()
expr_stmt|;
comment|/* get file name */
if|if
condition|(
operator|*
name|fname
operator|!=
literal|'\0'
condition|)
name|yfile
argument_list|(
name|fname
argument_list|)
expr_stmt|;
break|break;
default|default  :
name|help
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
name|cmd
operator|!=
literal|'x'
condition|)
do|;
block|}
end_block

begin_comment
comment|/*  Get file name from user  */
end_comment

begin_function
name|char
modifier|*
name|infile
parameter_list|()
block|{
name|char
modifier|*
name|startptr
init|=
name|filename
decl_stmt|;
name|scanf
argument_list|(
literal|"%s"
argument_list|,
name|startptr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|startptr
operator|==
literal|'.'
condition|)
operator|*
name|startptr
operator|=
literal|'\0'
expr_stmt|;
comment|/* set NULL */
return|return
operator|(
name|startptr
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Print Help Message  */
end_comment

begin_macro
name|help
argument_list|(
argument|caller
argument_list|)
end_macro

begin_decl_stmt
name|int
name|caller
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|caller
condition|)
block|{
name|printf
argument_list|(
literal|"\nUsage:  \n\tumodem "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-[c!rb!rt!sb!st][options]"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" filename\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"\nUsage: r or s or option"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\nMajor Commands --"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|caller
condition|)
name|printf
argument_list|(
literal|"\n\tc<-- Enter Command Mode"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\trb<-- Receive Binary"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\trt<-- Receive Text"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\tsb<-- Send Binary"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\tst<-- Send Text"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nOptions --"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\t1<-- (one) Employ TERM II FTP 1"
argument_list|)
expr_stmt|;
if|if
condition|(
name|caller
condition|)
name|printf
argument_list|(
literal|"\n\t3<-- Enable TERM FTP 3 (CP/M UG)"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|caller
condition|)
name|printf
argument_list|(
literal|"\n\t4<-- Enable TERM FTP 4"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\t7<-- Enable 7-bit transfer mask"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\ta<-- Turn ON ARPA Net Flag"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|caller
condition|)
if|#
directive|if
name|DELDEFAULT
operator|==
literal|1
name|printf
argument_list|(
literal|"\n\td<-- Do not delete umodem.log file before starting"
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"\n\td<-- Delete umodem.log file before starting"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|caller
condition|)
if|#
directive|if
name|LOGDEFAULT
operator|==
literal|1
name|printf
argument_list|(
literal|"\n\tl<-- (ell) Turn OFF LOG File Entries"
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"\n\tl<-- (ell) Turn ON LOG File Entries"
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|else
name|printf
argument_list|(
literal|"\n\tl<-- Toggle LOG File Entries"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\tm<-- Allow file overwiting on receive"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|caller
condition|)
name|printf
argument_list|(
literal|"\n\tp<-- Turn ON Parameter Display"
argument_list|)
expr_stmt|;
if|if
condition|(
name|caller
condition|)
name|printf
argument_list|(
literal|"\n\tx<-- Exit"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\ty<-- Display file status (size) information only"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|gettype
argument_list|(
argument|ichar
argument_list|)
end_macro

begin_decl_stmt
name|char
name|ichar
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|ichar
operator|==
literal|'t'
condition|)
return|return
operator|(
name|ichar
operator|)
return|;
if|if
condition|(
name|ichar
operator|==
literal|'b'
condition|)
return|return
operator|(
name|ichar
operator|)
return|;
name|error
argument_list|(
literal|"Invalid Send/Receive Parameter - not t or b"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* set tty modes for UMODEM transfers */
end_comment

begin_macro
name|setmodes
argument_list|()
end_macro

begin_block
block|{
comment|/*  Device characteristics for JHU UNIX  */
ifdef|#
directive|ifdef
name|JHU
if|if
condition|(
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|ttys
argument_list|)
operator|<
literal|0
condition|)
comment|/* get current tty params */
name|error
argument_list|(
literal|"Can't get TTY Parameters"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|tty
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* identify current tty */
comment|/* duplicate current modes in ttysnew structure */
name|ttysnew
operator|.
name|ispeed
operator|=
name|ttys
operator|.
name|ispeed
expr_stmt|;
comment|/* copy input speed */
name|ttysnew
operator|.
name|ospeed
operator|=
name|ttys
operator|.
name|ospeed
expr_stmt|;
comment|/* copy output speed */
name|ttysnew
operator|.
name|xflags
operator|=
name|ttys
operator|.
name|xflags
expr_stmt|;
comment|/* copy JHU/UNIX extended flags */
name|ttysnew
operator|.
name|mode
operator|=
name|ttys
operator|.
name|mode
expr_stmt|;
comment|/* copy standard terminal flags */
name|ttysnew
operator|.
name|mode
operator||=
name|RAW
expr_stmt|;
comment|/* set for RAW Mode */
comment|/* This ORs in the RAW mode value, thereby 			   setting RAW mode and leaving the other 			   mode settings unchanged */
name|ttysnew
operator|.
name|mode
operator|&=
operator|~
name|ECHO
expr_stmt|;
comment|/* set for no echoing */
comment|/* This ANDs in the complement of the ECHO 			   setting (for NO echo), thereby leaving all 			   current parameters unchanged and turning 			   OFF ECHO only */
name|ttysnew
operator|.
name|mode
operator|&=
operator|~
name|XTABS
expr_stmt|;
comment|/* set for no tab expansion */
name|ttysnew
operator|.
name|mode
operator|&=
operator|~
name|LCASE
expr_stmt|;
comment|/* set for no upper-to-lower case xlate */
name|ttysnew
operator|.
name|mode
operator||=
name|ANYP
expr_stmt|;
comment|/* set for ANY Parity */
name|ttysnew
operator|.
name|mode
operator|&=
operator|~
name|NL3
expr_stmt|;
comment|/* turn off ALL delays - new line */
name|ttysnew
operator|.
name|mode
operator|&=
operator|~
name|TAB3
expr_stmt|;
comment|/* turn off tab delays */
name|ttysnew
operator|.
name|mode
operator|&=
operator|~
name|CR3
expr_stmt|;
comment|/* turn off CR delays */
name|ttysnew
operator|.
name|mode
operator|&=
operator|~
name|FF1
expr_stmt|;
comment|/* turn off FF delays */
name|ttysnew
operator|.
name|mode
operator|&=
operator|~
name|BS1
expr_stmt|;
comment|/* turn off BS delays */
comment|/* the following are JHU/UNIX xflags settings; they are [SD] */
name|ttysnew
operator|.
name|xflags
operator|&=
operator|~
name|PAGE
expr_stmt|;
comment|/* turn off paging */
name|ttysnew
operator|.
name|xflags
operator|&=
operator|~
name|STALL
expr_stmt|;
comment|/* turn off ^S/^Q recognition */
name|ttysnew
operator|.
name|xflags
operator|&=
operator|~
name|TAPE
expr_stmt|;
comment|/* turn off ^S/^Q input control */
name|ttysnew
operator|.
name|xflags
operator|&=
operator|~
name|FOLD
expr_stmt|;
comment|/* turn off CR/LF folding at col 72 */
name|ttysnew
operator|.
name|xflags
operator||=
name|NB8
expr_stmt|;
comment|/* turn on 8-bit input/output */
if|if
condition|(
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|ttysnew
argument_list|)
operator|<
literal|0
condition|)
comment|/* set new params */
name|error
argument_list|(
literal|"Can't set new TTY Parameters"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|tty
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|<
literal|0
condition|)
comment|/* get tty status */
name|error
argument_list|(
literal|"Can't get your TTY Status"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|statbuf
operator|.
name|st_mode
operator|&
literal|011
condition|)
comment|/* messages are on [SD] */
block|{
name|wason
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|chmod
argument_list|(
name|tty
argument_list|,
literal|020600
argument_list|)
operator|<
literal|0
condition|)
comment|/* turn off tty messages [SD] */
name|error
argument_list|(
literal|"Can't change TTY Mode"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
else|else
name|wason
operator|=
name|FALSE
expr_stmt|;
comment|/* messages are already off */
endif|#
directive|endif
comment|/*  Device characteristics for Version 7 UNIX  */
ifdef|#
directive|ifdef
name|VER7
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|ttys
argument_list|)
operator|<
literal|0
condition|)
comment|/* get tty params [V7] */
name|error
argument_list|(
literal|"Can't get TTY Parameters"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|tty
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* identify current tty */
comment|/* transfer current modes to new structure */
name|ttysnew
operator|.
name|sg_ispeed
operator|=
name|ttys
operator|.
name|sg_ispeed
expr_stmt|;
comment|/* copy input speed */
name|ttysnew
operator|.
name|sg_ospeed
operator|=
name|ttys
operator|.
name|sg_ospeed
expr_stmt|;
comment|/* copy output speed */
name|ttysnew
operator|.
name|sg_erase
operator|=
name|ttys
operator|.
name|sg_erase
expr_stmt|;
comment|/* copy erase flags */
name|ttysnew
operator|.
name|sg_flags
operator|=
name|ttys
operator|.
name|sg_flags
expr_stmt|;
comment|/* copy flags */
name|ttysnew
operator|.
name|sg_kill
operator|=
name|ttys
operator|.
name|sg_kill
expr_stmt|;
comment|/* copy std terminal flags */
name|ttysnew
operator|.
name|sg_flags
operator||=
name|RAW
expr_stmt|;
comment|/* set for RAW Mode */
comment|/* This ORs in the RAW mode value, thereby 			   setting RAW mode and leaving the other 			   mode settings unchanged */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|ECHO
expr_stmt|;
comment|/* set for no echoing */
comment|/* This ANDs in the complement of the ECHO 			   setting (for NO echo), thereby leaving all 			   current parameters unchanged and turning 			   OFF ECHO only */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|XTABS
expr_stmt|;
comment|/* set for no tab expansion */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|LCASE
expr_stmt|;
comment|/* set for no upper-to-lower case xlate */
name|ttysnew
operator|.
name|sg_flags
operator||=
name|ANYP
expr_stmt|;
comment|/* set for ANY Parity */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|NL3
expr_stmt|;
comment|/* turn off ALL delays - new line */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|TAB2
expr_stmt|;
comment|/* turn off tab delays */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|CR3
expr_stmt|;
comment|/* turn off CR delays */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|FF1
expr_stmt|;
comment|/* turn off FF delays */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|BS1
expr_stmt|;
comment|/* turn off BS delays */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|TANDEM
expr_stmt|;
comment|/* turn off flow control */
ifdef|#
directive|ifdef
name|PAGEMODE
comment|/* make sure page mode is off */
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSSCR
argument_list|,
operator|&
name|pagelen
argument_list|)
expr_stmt|;
comment|/*  [SD]  */
endif|#
directive|endif
comment|/* set new paramters */
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETP
argument_list|,
operator|&
name|ttysnew
argument_list|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"Can't set new TTY Parameters"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|tty
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|<
literal|0
condition|)
comment|/* get tty status */
name|error
argument_list|(
literal|"Can't get your TTY Status"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|statbuf
operator|.
name|st_mode
operator|&
literal|022
condition|)
comment|/* Need to turn messages off */
if|if
condition|(
name|chmod
argument_list|(
name|tty
argument_list|,
name|statbuf
operator|.
name|st_mode
operator|&
operator|~
literal|022
argument_list|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"Can't change  TTY mode"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
else|else
name|wason
operator|=
name|TRUE
expr_stmt|;
else|else
name|wason
operator|=
name|FALSE
expr_stmt|;
endif|#
directive|endif
comment|/*  Device Characteristics for UNIX SYSTEM III  */
ifdef|#
directive|ifdef
name|SYS3
if|if
condition|(
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|ttys
argument_list|)
operator|<
literal|0
condition|)
comment|/* get current tty params */
name|error
argument_list|(
literal|"Can't get TTY Parameters"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|tty
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* identify current tty */
comment|/* transfer current modes to new structure */
name|ttysnew
operator|.
name|sg_ispeed
operator|=
name|ttys
operator|.
name|sg_ispeed
expr_stmt|;
comment|/* copy input speed */
name|ttysnew
operator|.
name|sg_ospeed
operator|=
name|ttys
operator|.
name|sg_ospeed
expr_stmt|;
comment|/* copy output speed */
name|ttysnew
operator|.
name|sg_erase
operator|=
name|ttys
operator|.
name|sg_erase
expr_stmt|;
comment|/* copy erase flags */
name|ttysnew
operator|.
name|sg_flags
operator|=
name|ttys
operator|.
name|sg_flags
expr_stmt|;
comment|/* copy flags */
name|ttysnew
operator|.
name|sg_kill
operator|=
name|ttys
operator|.
name|sg_kill
expr_stmt|;
comment|/* copy std terminal flags */
name|ttysnew
operator|.
name|sg_flags
operator||=
name|RAW
expr_stmt|;
comment|/* set for RAW Mode */
comment|/* This ORs in the RAW mode value, thereby 			   setting RAW mode and leaving the other 			   mode settings unchanged */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|ECHO
expr_stmt|;
comment|/* set for no echoing */
comment|/* This ANDs in the complement of the ECHO 			   setting (for NO echo), thereby leaving all 			   current parameters unchanged and turning 			   OFF ECHO only */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|XTABS
expr_stmt|;
comment|/* set for no tab expansion */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|LCASE
expr_stmt|;
comment|/* set for no upper-to-lower case xlate */
name|ttysnew
operator|.
name|sg_flags
operator||=
name|ANYP
expr_stmt|;
comment|/* set for ANY Parity */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|NL3
expr_stmt|;
comment|/* turn off ALL delays - new line */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|TAB0
expr_stmt|;
comment|/* turn off tab delays */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|TAB1
expr_stmt|;
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|CR3
expr_stmt|;
comment|/* turn off CR delays */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|FF1
expr_stmt|;
comment|/* turn off FF delays */
name|ttysnew
operator|.
name|sg_flags
operator|&=
operator|~
name|BS1
expr_stmt|;
comment|/* turn off BS delays */
if|if
condition|(
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|ttysnew
argument_list|)
operator|<
literal|0
condition|)
comment|/* set new params */
name|error
argument_list|(
literal|"Can't set new TTY Parameters"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|tty
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|<
literal|0
condition|)
comment|/* get tty status */
name|error
argument_list|(
literal|"Can't get your TTY Status"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|statbuf
operator|.
name|st_mode
operator|&
literal|022
condition|)
comment|/* Need to turn messages off */
if|if
condition|(
name|chmod
argument_list|(
name|tty
argument_list|,
name|statbuf
operator|.
name|st_mode
operator|&
operator|~
literal|022
argument_list|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"Can't change  TTY mode"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
else|else
name|wason
operator|=
name|TRUE
expr_stmt|;
else|else
name|wason
operator|=
name|FALSE
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|PMSG
condition|)
block|{
name|printf
argument_list|(
literal|"\nUMODEM:  TTY Device Parameters Altered"
argument_list|)
expr_stmt|;
name|ttyparams
argument_list|()
expr_stmt|;
comment|/* print tty params */
block|}
if|if
condition|(
name|ARPA
condition|)
comment|/* set 8-bit on ARPA Net */
name|setarpa
argument_list|()
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/*  set ARPA Net for 8-bit transfers  */
end_comment

begin_macro
name|setarpa
argument_list|()
end_macro

begin_block
block|{
name|sendbyte
argument_list|(
name|IAC
argument_list|)
expr_stmt|;
comment|/* Is A Command */
name|sendbyte
argument_list|(
name|WILL
argument_list|)
expr_stmt|;
comment|/* Command to SERVER TELNET (Host) */
name|sendbyte
argument_list|(
name|TRBIN
argument_list|)
expr_stmt|;
comment|/* Command is:  Transmit Binary */
name|sendbyte
argument_list|(
name|IAC
argument_list|)
expr_stmt|;
comment|/* Is A Command */
name|sendbyte
argument_list|(
name|DO
argument_list|)
expr_stmt|;
comment|/* Command to TIP */
name|sendbyte
argument_list|(
name|TRBIN
argument_list|)
expr_stmt|;
comment|/* Command is:  Transmit Binary */
name|sleep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|/* wait for TIP to configure */
return|return;
block|}
end_block

begin_comment
comment|/* restore normal tty modes */
end_comment

begin_macro
name|restoremodes
argument_list|(
argument|errcall
argument_list|)
end_macro

begin_decl_stmt
name|int
name|errcall
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|ARPA
condition|)
comment|/* if ARPA Net, reconfigure */
name|resetarpa
argument_list|()
expr_stmt|;
comment|/*  Device characteristic restoration for JHU UNIX  */
ifdef|#
directive|ifdef
name|JHU
if|if
condition|(
name|wason
condition|)
comment|/* if messages were on originally */
if|if
condition|(
name|chmod
argument_list|(
name|tty
argument_list|,
literal|020611
argument_list|)
operator|<
literal|0
condition|)
comment|/*  [SD]  */
name|error
argument_list|(
literal|"Can't change TTY Mode"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|ttys
argument_list|)
operator|<
literal|0
condition|)
comment|/* restore original tty modes */
block|{
if|if
condition|(
operator|!
name|errcall
condition|)
name|error
argument_list|(
literal|"RESET - Can't restore normal TTY Params"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
else|else
block|{
name|printf
argument_list|(
literal|"UMODEM:  "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"RESET - Can't restore normal TTY Params\n"
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/*  Device characteristic restoration for Version 7 UNIX  */
ifdef|#
directive|ifdef
name|VER7
if|if
condition|(
name|wason
condition|)
if|if
condition|(
name|chmod
argument_list|(
name|tty
argument_list|,
name|statbuf
operator|.
name|st_mode
operator||
literal|022
argument_list|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"Can't change TTY mode"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETP
argument_list|,
operator|&
name|ttys
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|errcall
condition|)
name|error
argument_list|(
literal|"RESET - Can't restore normal TTY Params"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
else|else
block|{
name|printf
argument_list|(
literal|"UMODEM:  "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"RESET - Can't restore normal TTY Params\n"
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/*  Device characteristic restoration for UNIX SYSTEM III  */
ifdef|#
directive|ifdef
name|SYS3
if|if
condition|(
name|wason
condition|)
if|if
condition|(
name|chmod
argument_list|(
name|tty
argument_list|,
name|statbuf
operator|.
name|st_mode
operator||
literal|022
argument_list|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"Can't change TTY mode"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|ttys
argument_list|)
operator|<
literal|0
condition|)
comment|/* restore original tty modes */
block|{
if|if
condition|(
operator|!
name|errcall
condition|)
name|error
argument_list|(
literal|"RESET - Can't restore normal TTY Params"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
else|else
block|{
name|printf
argument_list|(
literal|"UMODEM:  "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"RESET - Can't restore normal TTY Params\n"
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
if|if
condition|(
name|PMSG
condition|)
block|{
name|printf
argument_list|(
literal|"\nUMODEM:  TTY Device Parameters Restored"
argument_list|)
expr_stmt|;
name|ttyparams
argument_list|()
expr_stmt|;
comment|/* print tty params */
block|}
return|return;
block|}
end_block

begin_comment
comment|/* reset the ARPA Net */
end_comment

begin_macro
name|resetarpa
argument_list|()
end_macro

begin_block
block|{
name|sendbyte
argument_list|(
name|IAC
argument_list|)
expr_stmt|;
comment|/* Is A Command */
name|sendbyte
argument_list|(
name|WONT
argument_list|)
expr_stmt|;
comment|/* Negative Command to SERVER TELNET (Host) */
name|sendbyte
argument_list|(
name|TRBIN
argument_list|)
expr_stmt|;
comment|/* Command is:  Don't Transmit Binary */
name|sendbyte
argument_list|(
name|IAC
argument_list|)
expr_stmt|;
comment|/* Is A Command */
name|sendbyte
argument_list|(
name|DONT
argument_list|)
expr_stmt|;
comment|/* Negative Command to TIP */
name|sendbyte
argument_list|(
name|TRBIN
argument_list|)
expr_stmt|;
comment|/* Command is:  Don't Transmit Binary */
return|return;
block|}
end_block

begin_comment
comment|/* print error message and exit; if mode == TRUE, restore normal tty modes */
end_comment

begin_macro
name|error
argument_list|(
argument|msg
argument_list|,
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|mode
condition|)
name|restoremodes
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
comment|/* put back normal tty modes */
name|printf
argument_list|(
literal|"UMODEM:  %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
if|if
condition|(
name|LOGFLAG
operator|&
operator|(
name|int
operator|)
name|LOGFP
condition|)
block|{
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"UMODEM Fatal Error:  %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|LOGFP
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/**  print status (size) of a file  **/
end_comment

begin_macro
name|yfile
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"\nUMODEM File Status Display for %s\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|open
argument_list|(
name|name
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"File %s does not exist\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return;
block|}
name|prfilestat
argument_list|(
name|name
argument_list|)
expr_stmt|;
comment|/* print status */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|getbyte
argument_list|(
argument|fildes
argument_list|,
argument|ch
argument_list|)
end_macro

begin_comment
comment|/* Buffered disk read */
end_comment

begin_decl_stmt
name|int
name|fildes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  *	Get a byte from the specified file.  Buffer the read so we don't  *	have to use a system call for each character.  *  */
end_comment

begin_block
block|{
specifier|static
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* Remember buffer */
specifier|static
name|char
modifier|*
name|bufp
init|=
name|buf
decl_stmt|;
comment|/* Remember where we are in buffer */
if|if
condition|(
name|nbchr
operator|==
literal|0
condition|)
comment|/* Buffer exausted; read some more */
block|{
if|if
condition|(
operator|(
name|nbchr
operator|=
name|read
argument_list|(
name|fildes
argument_list|,
name|buf
argument_list|,
name|BUFSIZ
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"File Read Error"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|bufp
operator|=
name|buf
expr_stmt|;
comment|/* Set pointer to start of array */
block|}
if|if
condition|(
operator|--
name|nbchr
operator|>=
literal|0
condition|)
block|{
operator|*
name|ch
operator|=
operator|*
name|bufp
operator|++
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
return|return
operator|(
name|EOF
operator|)
return|;
block|}
end_block

begin_comment
comment|/**  receive a file  **/
end_comment

begin_macro
name|rfile
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|mode
decl_stmt|;
name|int
name|fd
decl_stmt|,
name|j
decl_stmt|,
name|firstchar
decl_stmt|,
name|sectnum
decl_stmt|,
name|sectcurr
decl_stmt|,
name|tmode
decl_stmt|;
name|int
name|sectcomp
decl_stmt|,
name|errors
decl_stmt|,
name|errorflag
decl_stmt|,
name|recfin
decl_stmt|;
specifier|register
name|int
name|bufctr
decl_stmt|,
name|checksum
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|;
name|int
name|errorchar
decl_stmt|,
name|fatalerror
decl_stmt|,
name|startstx
decl_stmt|,
name|inchecksum
decl_stmt|,
name|endetx
decl_stmt|,
name|endenq
decl_stmt|;
name|long
name|recvsectcnt
decl_stmt|;
name|mode
operator|=
name|XMITTYPE
expr_stmt|;
comment|/* set t/b mode */
if|if
condition|(
operator|(
name|fd
operator|=
name|creat
argument_list|(
name|name
argument_list|,
name|CREATMODE
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"Can't create file for receive"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|setmodes
argument_list|()
expr_stmt|;
comment|/* setup tty modes for xfer */
name|printf
argument_list|(
literal|"\r\nUMODEM:  File Name: %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|LOGFLAG
condition|)
block|{
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"\n----\nUMODEM Receive Function\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"File Name: %s\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|FTP1
condition|)
if|if
condition|(
operator|!
name|BIT7
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"TERM II File Transfer Protocol 1 Selected\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"TERM II File Transfer Protocol 4 Selected\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"TERM II File Transfer Protocol 3 (CP/M UG) Selected\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|BIT7
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"7-Bit Transmission Enabled\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"8-Bit Transmission Enabled\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\r\nUMODEM:  "
argument_list|)
expr_stmt|;
if|if
condition|(
name|BIT7
condition|)
name|printf
argument_list|(
literal|"7-Bit"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"8-Bit"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Transmission Enabled"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\nUMODEM:  Ready to RECEIVE File\r\n"
argument_list|)
expr_stmt|;
name|recfin
operator|=
name|FALSE
expr_stmt|;
name|sectnum
operator|=
name|errors
operator|=
literal|0
expr_stmt|;
name|fatalerror
operator|=
name|FALSE
expr_stmt|;
comment|/* NO fatal errors */
name|recvsectcnt
operator|=
literal|0
expr_stmt|;
comment|/* number of received sectors */
if|if
condition|(
name|mode
operator|==
literal|'t'
condition|)
name|tmode
operator|=
name|TRUE
expr_stmt|;
else|else
name|tmode
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
name|FTP1
condition|)
block|{
while|while
condition|(
name|readbyte
argument_list|(
literal|4
argument_list|)
operator|!=
name|SYN
condition|)
empty_stmt|;
name|sendbyte
argument_list|(
name|ACK
argument_list|)
expr_stmt|;
comment|/* FTP 1 Sync */
block|}
else|else
name|sendbyte
argument_list|(
name|NAK
argument_list|)
expr_stmt|;
comment|/* FTP 3 Sync */
do|do
block|{
name|errorflag
operator|=
name|FALSE
expr_stmt|;
do|do
block|{
name|firstchar
operator|=
name|readbyte
argument_list|(
literal|6
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|firstchar
operator|!=
name|SOH
operator|)
operator|&&
operator|(
name|firstchar
operator|!=
name|EOT
operator|)
operator|&&
operator|(
name|firstchar
operator|!=
name|TIMEOUT
operator|)
condition|)
do|;
if|if
condition|(
name|firstchar
operator|==
name|TIMEOUT
condition|)
block|{
if|if
condition|(
name|LOGFLAG
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Timeout on Sector %d\n"
argument_list|,
name|sectnum
argument_list|)
expr_stmt|;
name|errorflag
operator|=
name|TRUE
expr_stmt|;
block|}
if|if
condition|(
name|firstchar
operator|==
name|SOH
condition|)
block|{
if|if
condition|(
name|FTP1
condition|)
name|readbyte
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|/* discard leading zero */
name|sectcurr
operator|=
name|readbyte
argument_list|(
name|delay
argument_list|)
expr_stmt|;
name|sectcomp
operator|=
name|readbyte
argument_list|(
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|FTP1
condition|)
name|startstx
operator|=
name|readbyte
argument_list|(
name|delay
argument_list|)
expr_stmt|;
comment|/* get leading STX */
if|if
condition|(
operator|(
name|sectcurr
operator|+
name|sectcomp
operator|)
operator|==
name|BITMASK
condition|)
block|{
if|if
condition|(
name|sectcurr
operator|==
operator|(
operator|(
name|sectnum
operator|+
literal|1
operator|)
operator|&
name|BITMASK
operator|)
condition|)
block|{
name|checksum
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|j
operator|=
name|bufctr
operator|=
literal|0
init|;
name|j
operator|<
name|BBUFSIZ
condition|;
name|j
operator|++
control|)
block|{
name|buff
index|[
name|bufctr
index|]
operator|=
name|c
operator|=
name|readbyte
argument_list|(
name|delay
argument_list|)
expr_stmt|;
name|checksum
operator|=
operator|(
operator|(
name|checksum
operator|+
name|c
operator|)
operator|&
name|BITMASK
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|tmode
condition|)
comment|/* binary mode */
block|{
name|bufctr
operator|++
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|c
operator|==
name|CR
condition|)
continue|continue;
comment|/* skip CR's */
if|if
condition|(
name|c
operator|==
name|CTRLZ
condition|)
comment|/* skip CP/M EOF char */
block|{
name|recfin
operator|=
name|TRUE
expr_stmt|;
comment|/* flag EOF */
continue|continue;
block|}
if|if
condition|(
operator|!
name|recfin
condition|)
name|bufctr
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|FTP1
condition|)
name|endetx
operator|=
name|readbyte
argument_list|(
name|delay
argument_list|)
expr_stmt|;
comment|/* get ending ETX */
name|inchecksum
operator|=
name|readbyte
argument_list|(
name|delay
argument_list|)
expr_stmt|;
comment|/* get checksum */
if|if
condition|(
name|FTP1
condition|)
name|endenq
operator|=
name|readbyte
argument_list|(
name|delay
argument_list|)
expr_stmt|;
comment|/* get ENQ */
if|if
condition|(
name|checksum
operator|==
name|inchecksum
condition|)
comment|/* good checksum */
block|{
name|errors
operator|=
literal|0
expr_stmt|;
name|recvsectcnt
operator|++
expr_stmt|;
name|sectnum
operator|=
name|sectcurr
expr_stmt|;
comment|/* update sector counter */
if|if
condition|(
name|write
argument_list|(
name|fd
argument_list|,
name|buff
argument_list|,
name|bufctr
argument_list|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"File Write Error"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|FTP1
condition|)
name|sendbyte
argument_list|(
name|ESC
argument_list|)
expr_stmt|;
comment|/* FTP 1 requires<ESC> */
name|sendbyte
argument_list|(
name|ACK
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|LOGFLAG
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Checksum Error on Sector %d\n"
argument_list|,
name|sectnum
argument_list|)
expr_stmt|;
name|errorflag
operator|=
name|TRUE
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|sectcurr
operator|==
name|sectnum
condition|)
block|{
while|while
condition|(
name|readbyte
argument_list|(
literal|3
argument_list|)
operator|!=
name|TIMEOUT
condition|)
empty_stmt|;
if|if
condition|(
name|FTP1
condition|)
name|sendbyte
argument_list|(
name|ESC
argument_list|)
expr_stmt|;
comment|/* FTP 1 requires<ESC> */
name|sendbyte
argument_list|(
name|ACK
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|LOGFLAG
condition|)
block|{
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Phase Error - Received Sector is "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"%d while Expected Sector is %d\n"
argument_list|,
name|sectcurr
argument_list|,
operator|(
operator|(
name|sectnum
operator|+
literal|1
operator|)
operator|&
name|BITMASK
operator|)
argument_list|)
expr_stmt|;
block|}
name|errorflag
operator|=
name|TRUE
expr_stmt|;
name|fatalerror
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|FTP1
condition|)
name|sendbyte
argument_list|(
name|ESC
argument_list|)
expr_stmt|;
comment|/* FTP 1 requires<ESC> */
name|sendbyte
argument_list|(
name|CAN
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
if|if
condition|(
name|LOGFLAG
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Header Sector Number Error on Sector %d\n"
argument_list|,
name|sectnum
argument_list|)
expr_stmt|;
name|errorflag
operator|=
name|TRUE
expr_stmt|;
block|}
block|}
if|if
condition|(
name|FTP1
operator|&&
operator|!
name|errorflag
condition|)
block|{
if|if
condition|(
name|startstx
operator|!=
name|STX
condition|)
block|{
name|errorflag
operator|=
name|TRUE
expr_stmt|;
comment|/* FTP 1 STX missing */
name|errorchar
operator|=
name|STX
expr_stmt|;
block|}
if|if
condition|(
name|endetx
operator|!=
name|ETX
condition|)
block|{
name|errorflag
operator|=
name|TRUE
expr_stmt|;
comment|/* FTP 1 ETX missing */
name|errorchar
operator|=
name|ETX
expr_stmt|;
block|}
if|if
condition|(
name|endenq
operator|!=
name|ENQ
condition|)
block|{
name|errorflag
operator|=
name|TRUE
expr_stmt|;
comment|/* FTP 1 ENQ missing */
name|errorchar
operator|=
name|ENQ
expr_stmt|;
block|}
if|if
condition|(
name|errorflag
operator|&&
name|LOGFLAG
condition|)
block|{
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Invalid Packet-Control Character:  "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|errorchar
condition|)
block|{
case|case
name|STX
case|:
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"STX"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ETX
case|:
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"ETX"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ENQ
case|:
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"ENQ"
argument_list|)
expr_stmt|;
break|break;
default|default  :
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Error"
argument_list|)
expr_stmt|;
break|break;
block|}
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|errorflag
operator|==
name|TRUE
condition|)
block|{
name|errors
operator|++
expr_stmt|;
while|while
condition|(
name|readbyte
argument_list|(
literal|3
argument_list|)
operator|!=
name|TIMEOUT
condition|)
empty_stmt|;
name|sendbyte
argument_list|(
name|NAK
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
operator|(
name|firstchar
operator|!=
name|EOT
operator|)
operator|&&
operator|(
name|errors
operator|!=
name|ERRORMAX
operator|)
operator|&&
operator|!
name|fatalerror
condition|)
do|;
if|if
condition|(
operator|(
name|firstchar
operator|==
name|EOT
operator|)
operator|&&
operator|(
name|errors
operator|<
name|ERRORMAX
operator|)
condition|)
block|{
if|if
condition|(
operator|!
name|FTP1
condition|)
name|sendbyte
argument_list|(
name|ACK
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|restoremodes
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
comment|/* restore normal tty modes */
if|if
condition|(
name|FTP1
condition|)
while|while
condition|(
name|readbyte
argument_list|(
literal|3
argument_list|)
operator|!=
name|TIMEOUT
condition|)
empty_stmt|;
comment|/* flush EOT's */
name|sleep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|/* give other side time to return to terminal mode */
if|if
condition|(
name|LOGFLAG
condition|)
block|{
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"\nReceive Complete\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Number of Received CP/M Records is %ld\n"
argument_list|,
name|recvsectcnt
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|LOGFLAG
operator|&&
name|FTP1
operator|&&
name|fatalerror
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Synchronization Error"
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"TIMEOUT -- Too Many Errors"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/**  send a file  **/
end_comment

begin_macro
name|sfile
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|mode
decl_stmt|;
name|int
name|fd
decl_stmt|,
name|attempts
decl_stmt|;
name|int
name|nlflag
decl_stmt|,
name|sendfin
decl_stmt|,
name|tmode
decl_stmt|;
specifier|register
name|int
name|bufctr
decl_stmt|,
name|checksum
decl_stmt|,
name|sectnum
decl_stmt|;
name|char
name|c
decl_stmt|;
name|int
name|sendresp
decl_stmt|;
comment|/* response char to sent block */
name|nbchr
operator|=
literal|0
expr_stmt|;
comment|/* clear buffered read char count */
name|mode
operator|=
name|XMITTYPE
expr_stmt|;
comment|/* set t/b mode */
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|name
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|LOGFLAG
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Can't Open File\n"
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"Can't open file for send"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
name|setmodes
argument_list|()
expr_stmt|;
comment|/* setup tty modes for xfer */
name|printf
argument_list|(
literal|"\r\nUMODEM:  File Name: %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|LOGFLAG
condition|)
block|{
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"\n----\nUMODEM Send Function\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"File Name: %s\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
name|prfilestat
argument_list|(
name|name
argument_list|)
expr_stmt|;
comment|/* print file size statistics */
if|if
condition|(
name|LOGFLAG
condition|)
block|{
if|if
condition|(
name|FTP1
condition|)
if|if
condition|(
operator|!
name|BIT7
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"TERM II File Transfer Protocol 1 Selected\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"TERM II File Transfer Protocol 4 Selected\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"TERM II File Transfer Protocol 3 (CP/M UG) Selected\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|BIT7
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"7-Bit Transmission Enabled\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"8-Bit Transmission Enabled\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\r\nUMODEM:  "
argument_list|)
expr_stmt|;
if|if
condition|(
name|BIT7
condition|)
name|printf
argument_list|(
literal|"7-Bit"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"8-Bit"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Transmission Enabled"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\nUMODEM:  Ready to SEND File\r\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mode
operator|==
literal|'t'
condition|)
name|tmode
operator|=
name|TRUE
expr_stmt|;
else|else
name|tmode
operator|=
name|FALSE
expr_stmt|;
name|sendfin
operator|=
name|nlflag
operator|=
name|FALSE
expr_stmt|;
name|attempts
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|FTP1
condition|)
block|{
name|sendbyte
argument_list|(
name|SYN
argument_list|)
expr_stmt|;
comment|/* FTP 1 Synchronize with Receiver */
while|while
condition|(
name|readbyte
argument_list|(
literal|5
argument_list|)
operator|!=
name|ACK
condition|)
block|{
if|if
condition|(
operator|++
name|attempts
operator|>
name|RETRYMAX
operator|*
literal|6
condition|)
name|error
argument_list|(
literal|"Remote System Not Responding"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|sendbyte
argument_list|(
name|SYN
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
while|while
condition|(
name|readbyte
argument_list|(
literal|30
argument_list|)
operator|!=
name|NAK
condition|)
comment|/* FTP 3 Synchronize with Receiver */
if|if
condition|(
operator|++
name|attempts
operator|>
name|RETRYMAX
condition|)
name|error
argument_list|(
literal|"Remote System Not Responding"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
name|sectnum
operator|=
literal|1
expr_stmt|;
comment|/* first sector number */
name|attempts
operator|=
literal|0
expr_stmt|;
do|do
block|{
for|for
control|(
name|bufctr
operator|=
literal|0
init|;
name|bufctr
operator|<
name|BBUFSIZ
condition|;
control|)
block|{
if|if
condition|(
name|nlflag
condition|)
block|{
name|buff
index|[
name|bufctr
operator|++
index|]
operator|=
name|LF
expr_stmt|;
comment|/* leftover newline */
name|nlflag
operator|=
name|FALSE
expr_stmt|;
block|}
if|if
condition|(
name|getbyte
argument_list|(
name|fd
argument_list|,
operator|&
name|c
argument_list|)
operator|==
name|EOF
condition|)
block|{
name|sendfin
operator|=
name|TRUE
expr_stmt|;
comment|/* this is the last sector */
if|if
condition|(
operator|!
name|bufctr
condition|)
comment|/* if EOF on sector boundary */
break|break;
comment|/* avoid sending extra sector */
if|if
condition|(
name|tmode
condition|)
name|buff
index|[
name|bufctr
operator|++
index|]
operator|=
name|CTRLZ
expr_stmt|;
comment|/* Control-Z for CP/M EOF */
else|else
name|bufctr
operator|++
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|tmode
operator|&&
name|c
operator|==
name|LF
condition|)
comment|/* text mode& Unix newline? */
block|{
if|if
condition|(
name|c
operator|==
name|LF
condition|)
comment|/* Unix newline? */
block|{
name|buff
index|[
name|bufctr
operator|++
index|]
operator|=
name|CR
expr_stmt|;
comment|/* insert carriage return */
if|if
condition|(
name|bufctr
operator|<
name|BBUFSIZ
condition|)
name|buff
index|[
name|bufctr
operator|++
index|]
operator|=
name|LF
expr_stmt|;
comment|/* insert Unix newline */
else|else
name|nlflag
operator|=
name|TRUE
expr_stmt|;
comment|/* insert newline on next sector */
block|}
continue|continue;
block|}
name|buff
index|[
name|bufctr
operator|++
index|]
operator|=
name|c
expr_stmt|;
comment|/* copy the char without change */
block|}
name|attempts
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|bufctr
condition|)
comment|/* if EOF on sector boundary */
break|break;
comment|/* avoid sending empty sector */
do|do
block|{
name|sendbyte
argument_list|(
name|SOH
argument_list|)
expr_stmt|;
comment|/* send start of packet header */
if|if
condition|(
name|FTP1
condition|)
name|sendbyte
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* FTP 1 Type 0 Packet */
name|sendbyte
argument_list|(
name|sectnum
argument_list|)
expr_stmt|;
comment|/* send current sector number */
name|sendbyte
argument_list|(
operator|-
name|sectnum
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* and its complement */
if|if
condition|(
name|FTP1
condition|)
name|sendbyte
argument_list|(
name|STX
argument_list|)
expr_stmt|;
comment|/* send STX */
name|checksum
operator|=
literal|0
expr_stmt|;
comment|/* init checksum */
for|for
control|(
name|bufctr
operator|=
literal|0
init|;
name|bufctr
operator|<
name|BBUFSIZ
condition|;
name|bufctr
operator|++
control|)
block|{
name|sendbyte
argument_list|(
name|buff
index|[
name|bufctr
index|]
argument_list|)
expr_stmt|;
comment|/* send the byte */
if|if
condition|(
name|ARPA
operator|&&
operator|(
name|buff
index|[
name|bufctr
index|]
operator|==
literal|0xff
operator|)
condition|)
comment|/* ARPA Net FFH esc */
name|sendbyte
argument_list|(
name|buff
index|[
name|bufctr
index|]
argument_list|)
expr_stmt|;
comment|/* send 2 FFH's for one */
name|checksum
operator|=
operator|(
operator|(
name|checksum
operator|+
name|buff
index|[
name|bufctr
index|]
operator|)
operator|&
name|BITMASK
operator|)
expr_stmt|;
block|}
comment|/*		while (readbyte(3) != TIMEOUT);   flush chars from line */
if|if
condition|(
name|FTP1
condition|)
name|sendbyte
argument_list|(
name|ETX
argument_list|)
expr_stmt|;
comment|/* send ETX */
name|sendbyte
argument_list|(
name|checksum
argument_list|)
expr_stmt|;
comment|/* send the checksum */
if|if
condition|(
name|FTP1
condition|)
name|sendbyte
argument_list|(
name|ENQ
argument_list|)
expr_stmt|;
comment|/* send ENQ */
name|attempts
operator|++
expr_stmt|;
if|if
condition|(
name|FTP1
condition|)
block|{
name|sendresp
operator|=
name|NAK
expr_stmt|;
comment|/* prepare for NAK */
if|if
condition|(
name|readbyte
argument_list|(
literal|10
argument_list|)
operator|==
name|ESC
condition|)
name|sendresp
operator|=
name|readbyte
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
else|else
name|sendresp
operator|=
name|readbyte
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|/* get response */
if|if
condition|(
operator|(
name|sendresp
operator|!=
name|ACK
operator|)
operator|&&
name|LOGFLAG
condition|)
block|{
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Non-ACK Received on Sector %d\n"
argument_list|,
name|sectnum
argument_list|)
expr_stmt|;
if|if
condition|(
name|sendresp
operator|==
name|TIMEOUT
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"This Non-ACK was a TIMEOUT\n"
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
operator|(
name|sendresp
operator|!=
name|ACK
operator|)
operator|&&
operator|(
name|attempts
operator|!=
name|RETRYMAX
operator|)
condition|)
do|;
name|sectnum
operator|++
expr_stmt|;
comment|/* increment to next sector number */
block|}
do|while
condition|(
operator|!
name|sendfin
operator|&&
operator|(
name|attempts
operator|!=
name|RETRYMAX
operator|)
condition|)
do|;
if|if
condition|(
name|attempts
operator|==
name|RETRYMAX
condition|)
name|error
argument_list|(
literal|"Remote System Not Responding"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|attempts
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|FTP1
condition|)
while|while
condition|(
name|attempts
operator|++
operator|<
literal|10
condition|)
name|sendbyte
argument_list|(
name|EOT
argument_list|)
expr_stmt|;
else|else
block|{
name|sendbyte
argument_list|(
name|EOT
argument_list|)
expr_stmt|;
comment|/* send 1st EOT */
while|while
condition|(
operator|(
name|readbyte
argument_list|(
literal|15
argument_list|)
operator|!=
name|ACK
operator|)
operator|&&
operator|(
name|attempts
operator|++
operator|<
name|RETRYMAX
operator|)
condition|)
name|sendbyte
argument_list|(
name|EOT
argument_list|)
expr_stmt|;
if|if
condition|(
name|attempts
operator|>=
name|RETRYMAX
condition|)
name|error
argument_list|(
literal|"Remote System Not Responding on Completion"
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|restoremodes
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|/* give other side time to return to terminal mode */
if|if
condition|(
name|LOGFLAG
condition|)
block|{
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"\nSend Complete\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  print file size status information  */
end_comment

begin_macro
name|prfilestat
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|stat
name|filestatbuf
decl_stmt|;
comment|/* file status info */
name|stat
argument_list|(
name|name
argument_list|,
operator|&
name|filestatbuf
argument_list|)
expr_stmt|;
comment|/* get file status bytes */
name|printf
argument_list|(
literal|"  Estimated File Size %ldK, %ld Records, %ld Bytes"
argument_list|,
operator|(
name|filestatbuf
operator|.
name|st_size
operator|/
literal|1024
operator|)
operator|+
literal|1
argument_list|,
operator|(
name|filestatbuf
operator|.
name|st_size
operator|/
literal|128
operator|)
operator|+
literal|1
argument_list|,
name|filestatbuf
operator|.
name|st_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|LOGFLAG
condition|)
name|fprintf
argument_list|(
name|LOGFP
argument_list|,
literal|"Estimated File Size %ldK, %ld Records, %ld Bytes\n"
argument_list|,
operator|(
name|filestatbuf
operator|.
name|st_size
operator|/
literal|1024
operator|)
operator|+
literal|1
argument_list|,
operator|(
name|filestatbuf
operator|.
name|st_size
operator|/
literal|128
operator|)
operator|+
literal|1
argument_list|,
name|filestatbuf
operator|.
name|st_size
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* get a byte from data stream -- timeout if "seconds" elapses */
end_comment

begin_macro
name|readbyte
argument_list|(
argument|seconds
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|seconds
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|c
decl_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|alarmfunc
argument_list|)
expr_stmt|;
comment|/* catch alarms */
name|alarm
argument_list|(
operator|(
name|unsigned
operator|)
name|seconds
argument_list|)
expr_stmt|;
comment|/* set the alarm clock */
if|if
condition|(
name|setjmp
argument_list|(
name|env
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* if<> 0 then returned from timeout */
if|if
condition|(
name|read
argument_list|(
literal|0
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
operator|<
literal|0
condition|)
comment|/* get a char; error means time out */
block|{
return|return
operator|(
name|TIMEOUT
operator|)
return|;
block|}
block|}
else|else
return|return
operator|(
name|TIMEOUT
operator|)
return|;
name|alarm
argument_list|(
operator|(
name|unsigned
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|/* turn off the alarm */
return|return
operator|(
operator|(
name|c
operator|&
name|BITMASK
operator|)
operator|)
return|;
comment|/* return the char */
block|}
end_block

begin_comment
comment|/* send a byte to data stream */
end_comment

begin_macro
name|sendbyte
argument_list|(
argument|data
argument_list|)
end_macro

begin_decl_stmt
name|char
name|data
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|dataout
decl_stmt|;
name|dataout
operator|=
operator|(
name|data
operator|&
name|BITMASK
operator|)
expr_stmt|;
comment|/* mask for 7 or 8 bits */
name|write
argument_list|(
literal|1
argument_list|,
operator|&
name|dataout
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* write the byte */
return|return;
block|}
end_block

begin_comment
comment|/* function for alarm clock timeouts */
end_comment

begin_function
name|void
name|alarmfunc
parameter_list|()
block|{
name|longjmp
argument_list|(
name|env
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* this is basically a dummy function to force error */
comment|/* status return on the "read" call in "readbyte"    */
block|}
end_function

begin_comment
comment|/* print data on TTY setting */
end_comment

begin_macro
name|ttyparams
argument_list|()
end_macro

begin_block
block|{
comment|/*  Obtain TTY parameters for JHU UNIX  */
ifdef|#
directive|ifdef
name|JHU
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|ttystemp
argument_list|)
expr_stmt|;
comment|/* get current tty params */
endif|#
directive|endif
comment|/*  Obtain TTY parameters for Version 7 UNIX  */
ifdef|#
directive|ifdef
name|VER7
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|ttystemp
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*  Obtain TTY parameters for UNIX SYSTEM III  */
ifdef|#
directive|ifdef
name|SYS3
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|ttystemp
argument_list|)
expr_stmt|;
comment|/* get current tty params */
endif|#
directive|endif
name|tty
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* get name of tty */
name|stat
argument_list|(
name|tty
argument_list|,
operator|&
name|statbuf
argument_list|)
expr_stmt|;
comment|/* get more tty params */
name|printf
argument_list|(
literal|"\r\n\nTTY Device Parameter Display"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\n\tTTY Device Name is %s\r\n\n"
argument_list|,
name|tty
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tAny Parity Allowed "
argument_list|)
expr_stmt|;
name|pryn
argument_list|(
name|ANYP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tEven Parity Allowed"
argument_list|)
expr_stmt|;
name|pryn
argument_list|(
name|EVENP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tOdd Parity Allowed "
argument_list|)
expr_stmt|;
name|pryn
argument_list|(
name|ODDP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tEcho Enabled       "
argument_list|)
expr_stmt|;
name|pryn
argument_list|(
name|ECHO
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tLower Case Map     "
argument_list|)
expr_stmt|;
name|pryn
argument_list|(
name|LCASE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tTabs Expanded      "
argument_list|)
expr_stmt|;
name|pryn
argument_list|(
name|XTABS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tCR Mode Enabled    "
argument_list|)
expr_stmt|;
name|pryn
argument_list|(
name|CRMOD
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tRAW Mode Enabled   "
argument_list|)
expr_stmt|;
name|pryn
argument_list|(
name|RAW
argument_list|)
expr_stmt|;
comment|/*  Print extended terminal characteristics for JHU UNIX  */
ifdef|#
directive|ifdef
name|JHU
name|printf
argument_list|(
literal|"\tBinary Mode Enabled"
argument_list|)
expr_stmt|;
name|pryn1
argument_list|(
name|NB8
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tCR/LF in Col 72    "
argument_list|)
expr_stmt|;
name|pryn1
argument_list|(
name|FOLD
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tRecognize ^S/^Q    "
argument_list|)
expr_stmt|;
name|pryn1
argument_list|(
name|STALL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tSend ^S/^Q         "
argument_list|)
expr_stmt|;
name|pryn1
argument_list|(
name|TAPE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tTerminal can BS    "
argument_list|)
expr_stmt|;
name|pryn1
argument_list|(
name|SCOPE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
comment|/* New line to separate topics */
name|printf
argument_list|(
literal|"\tTerminal Paging is "
argument_list|)
expr_stmt|;
name|pryn1
argument_list|(
name|PAGE
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttystemp
operator|.
name|xflags
operator|&
name|PAGE
condition|)
name|printf
argument_list|(
literal|"\t  Lines/Page is %d\r\n"
argument_list|,
name|ttystemp
operator|.
name|xflags
operator|&
name|PAGE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
comment|/* New line to separate topics */
name|printf
argument_list|(
literal|"\tTTY Input Rate     :   "
argument_list|)
expr_stmt|;
name|prbaud
argument_list|(
name|ttystemp
operator|.
name|ispeed
argument_list|)
expr_stmt|;
comment|/* print baud rate */
name|printf
argument_list|(
literal|"\tTTY Output Rate    :   "
argument_list|)
expr_stmt|;
name|prbaud
argument_list|(
name|ttystemp
operator|.
name|ospeed
argument_list|)
expr_stmt|;
comment|/* print output baud rate */
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
comment|/* New line to separate topics */
name|printf
argument_list|(
literal|"\tMessages Enabled   "
argument_list|)
expr_stmt|;
if|if
condition|(
name|statbuf
operator|.
name|st_mode
operator|&
literal|011
condition|)
name|printf
argument_list|(
literal|":   Yes\r\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|":   No\r\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*  Print extended characteristics for Version 7 UNIX  */
ifdef|#
directive|ifdef
name|VER7
name|printf
argument_list|(
literal|"\tTTY Input Rate     :   "
argument_list|)
expr_stmt|;
name|prbaud
argument_list|(
name|ttystemp
operator|.
name|sg_ispeed
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tTTY Output Rate    :   "
argument_list|)
expr_stmt|;
name|prbaud
argument_list|(
name|ttystemp
operator|.
name|sg_ospeed
argument_list|)
expr_stmt|;
comment|/* print output baud rate */
endif|#
directive|endif
comment|/*  Print extended characteristics for UNIX SYSTEM III  */
ifdef|#
directive|ifdef
name|SYS3
name|printf
argument_list|(
literal|"\tTTY Input Rate     :   "
argument_list|)
expr_stmt|;
name|prbaud
argument_list|(
name|ttystemp
operator|.
name|sg_ispeed
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tTTY Output Rate    :   "
argument_list|)
expr_stmt|;
name|prbaud
argument_list|(
name|ttystemp
operator|.
name|sg_ospeed
argument_list|)
expr_stmt|;
comment|/* print output baud rate */
endif|#
directive|endif
block|}
end_block

begin_macro
name|pryn
argument_list|(
argument|iflag
argument_list|)
end_macro

begin_decl_stmt
name|int
name|iflag
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*  JHU UNIX flag test  */
ifdef|#
directive|ifdef
name|JHU
if|if
condition|(
name|ttystemp
operator|.
name|mode
operator|&
name|iflag
condition|)
endif|#
directive|endif
comment|/*  Version 7 UNIX flag test  */
ifdef|#
directive|ifdef
name|VER7
if|if
condition|(
name|ttystemp
operator|.
name|sg_flags
operator|&
name|iflag
condition|)
endif|#
directive|endif
comment|/*  UNIX SYSTEM III flag test  */
ifdef|#
directive|ifdef
name|SYS3
if|if
condition|(
name|ttystemp
operator|.
name|sg_flags
operator|&
name|iflag
condition|)
endif|#
directive|endif
name|printf
argument_list|(
literal|":   Yes\r\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|":   No\r\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  Extended flag test for JHU UNIX only  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JHU
end_ifdef

begin_macro
name|pryn1
argument_list|(
argument|iflag
argument_list|)
end_macro

begin_decl_stmt
name|int
name|iflag
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|ttystemp
operator|.
name|xflags
operator|&
name|iflag
condition|)
name|printf
argument_list|(
literal|":   Yes\r\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|":   No\r\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|prbaud
argument_list|(
argument|speed
argument_list|)
end_macro

begin_decl_stmt
name|char
name|speed
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|speed
condition|)
block|{
comment|/*  JHU UNIX speed flag cases  */
ifdef|#
directive|ifdef
name|JHU
case|case
name|B0050
case|:
name|printf
argument_list|(
literal|"50"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B0075
case|:
name|printf
argument_list|(
literal|"75"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B0110
case|:
name|printf
argument_list|(
literal|"110"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B0134
case|:
name|printf
argument_list|(
literal|"134.5"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B0150
case|:
name|printf
argument_list|(
literal|"150"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B0200
case|:
name|printf
argument_list|(
literal|"200"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B0300
case|:
name|printf
argument_list|(
literal|"300"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B0600
case|:
name|printf
argument_list|(
literal|"600"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B1200
case|:
name|printf
argument_list|(
literal|"1200"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B1800
case|:
name|printf
argument_list|(
literal|"1800"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B2400
case|:
name|printf
argument_list|(
literal|"2400"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B4800
case|:
name|printf
argument_list|(
literal|"4800"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B9600
case|:
name|printf
argument_list|(
literal|"9600"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EXT_A
case|:
name|printf
argument_list|(
literal|"External A"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EXT_B
case|:
name|printf
argument_list|(
literal|"External B"
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/*  Version 7 UNIX speed flag cases  */
ifdef|#
directive|ifdef
name|VER7
case|case
name|B50
case|:
name|printf
argument_list|(
literal|"50"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B75
case|:
name|printf
argument_list|(
literal|"75"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B110
case|:
name|printf
argument_list|(
literal|"110"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B134
case|:
name|printf
argument_list|(
literal|"134.5"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B150
case|:
name|printf
argument_list|(
literal|"150"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B200
case|:
name|printf
argument_list|(
literal|"200"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B300
case|:
name|printf
argument_list|(
literal|"300"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B600
case|:
name|printf
argument_list|(
literal|"600"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B1200
case|:
name|printf
argument_list|(
literal|"1200"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B1800
case|:
name|printf
argument_list|(
literal|"1800"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B2400
case|:
name|printf
argument_list|(
literal|"2400"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B4800
case|:
name|printf
argument_list|(
literal|"4800"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B9600
case|:
name|printf
argument_list|(
literal|"9600"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EXTA
case|:
name|printf
argument_list|(
literal|"External A"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EXTB
case|:
name|printf
argument_list|(
literal|"External B"
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/*  UNIX SYSTEM III speed flag cases  */
ifdef|#
directive|ifdef
name|SYS3
case|case
name|B50
case|:
name|printf
argument_list|(
literal|"50"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B75
case|:
name|printf
argument_list|(
literal|"75"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B110
case|:
name|printf
argument_list|(
literal|"110"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B134
case|:
name|printf
argument_list|(
literal|"134.5"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B150
case|:
name|printf
argument_list|(
literal|"150"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B200
case|:
name|printf
argument_list|(
literal|"200"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B300
case|:
name|printf
argument_list|(
literal|"300"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B600
case|:
name|printf
argument_list|(
literal|"600"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B1200
case|:
name|printf
argument_list|(
literal|"1200"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B1800
case|:
name|printf
argument_list|(
literal|"1800"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B2400
case|:
name|printf
argument_list|(
literal|"2400"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B4800
case|:
name|printf
argument_list|(
literal|"4800"
argument_list|)
expr_stmt|;
break|break;
case|case
name|B9600
case|:
name|printf
argument_list|(
literal|"9600"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EXTA
case|:
name|printf
argument_list|(
literal|"External A"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EXTB
case|:
name|printf
argument_list|(
literal|"External B"
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
default|default    :
name|printf
argument_list|(
literal|"Error"
argument_list|)
expr_stmt|;
break|break;
block|}
name|printf
argument_list|(
literal|" Baud\r\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

