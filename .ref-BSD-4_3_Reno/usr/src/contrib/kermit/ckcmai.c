begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|versio
init|=
literal|"C-Kermit, 4C(057) 31 Jul 85"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K C M A I  --  C-Kermit Main program  */
end_comment

begin_comment
comment|/*  Authors: Frank da Cruz, Bill Catchings, Jeff Damens;  Columbia University Center for Computing Activities, 1984-85.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_comment
comment|/*  The Kermit file transfer protocol was developed at Columbia University.  It is named after Kermit the Frog, star of the television series THE  MUPPET SHOW; the name is used by permission of Henson Associates, Inc.  "Kermit" is also Celtic for "free". */
end_comment

begin_comment
comment|/*  Thanks to Herm Fischer of Encino CA for extensive contributions to version 4,  and to the following people for their contributions over the years:     Larry Afrin, Clemson U    Charles Brooks, EDN    Bob Cattani, Columbia CS Dept    Alan Crosswell, CUCCA    Carl Fongheiser, CWRU    Yekta Gursel, MIT    Jim Guyton, Rand Corp    Stan Hanks, Rice U.    Ken Harrenstein, SRI    Steve Hemminger, Tektronix    Randy Huntziger, NLM    Chris Maio, Columbia CS Dept    Martin Minow, DEC    Tony Movshon, NYU    Ken Poulton, HP Labs    Frank Prindle, NADC    Stew Rubenstein, Harvard    Dan Schullman, DEC    Bradley Smith, UCLA    Dave Tweten, AMES-NAS    Walter Underwood, Ford Aerospace    Pieter Van Der Linden, Centre Mondial (Paris)    Mark Vasoll& Gregg Wonderly, Oklahoma State University    Lauren Weinstein, Vortex   and many others. */
end_comment

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Text message definitions.. each should be 256 chars long, or less. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"C-Kermit Server Commands:\n\ \n\ GET filespec, SEND filespec, FINISH, REMOTE HELP\n\ \n\0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"C-Kermit Server Commands Supported:\n\ \n\ GET filespec	REMOTE CWD [directory]		REMOTE SPACE [directory]\n\ SEND filespec	REMOTE DIRECTORY [filespec]	REMOTE HOST command\n\ FINISH		REMOTE DELETE filespec		REMOTE WHO [user]\n\ REMOTE HELP	REMOTE TYPE filespec		BYE\n\ \n\0"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|srvtxt
init|=
literal|"\r\n\ C-Kermit server starting.  Return to your local machine by typing\r\n\ its escape sequence for closing the connection, and issue further\r\n\ commands from there.  To shut down the C-Kermit server, issue the\r\n\ FINISH or BYE command and then reconnect.\n\ \r\n\0"
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Declarations for Send-Init Parameters */
end_comment

begin_decl_stmt
name|int
name|spsiz
init|=
name|DSPSIZ
decl_stmt|,
comment|/* Biggest packet size we can send */
name|spsizf
init|=
literal|0
decl_stmt|,
comment|/* Flag to override what you ask for */
name|rpsiz
init|=
name|DRPSIZ
decl_stmt|,
comment|/* Biggest we want to receive */
name|timint
init|=
name|DMYTIM
decl_stmt|,
comment|/* Timeout interval I use */
name|rtimo
init|=
name|URTIME
decl_stmt|,
comment|/* Timeout I want you to use */
name|timef
init|=
literal|0
decl_stmt|,
comment|/* Flag to override what you ask */
name|npad
init|=
name|MYPADN
decl_stmt|,
comment|/* How much padding to send */
name|mypadn
init|=
name|MYPADN
decl_stmt|,
comment|/* How much padding to ask for */
name|chklen
init|=
literal|1
decl_stmt|,
comment|/* Length of block check */
name|bctr
init|=
literal|1
decl_stmt|,
comment|/* Block check type requested */
name|bctu
init|=
literal|1
decl_stmt|,
comment|/* Block check type used */
name|ebq
init|=
name|MYEBQ
decl_stmt|,
comment|/* 8th bit prefix */
name|ebqflg
init|=
literal|0
decl_stmt|,
comment|/* 8th-bit quoting flag */
name|rpt
init|=
literal|0
decl_stmt|,
comment|/* Repeat count */
name|rptq
init|=
name|MYRPTQ
decl_stmt|,
comment|/* Repeat prefix */
name|rptflg
init|=
literal|0
decl_stmt|,
comment|/* Repeat processing flag */
name|capas
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Capabilities */
end_comment

begin_decl_stmt
name|CHAR
name|padch
init|=
name|MYPADC
decl_stmt|,
comment|/* Padding character to send */
name|mypadc
init|=
name|MYPADC
decl_stmt|,
comment|/* Padding character to ask for */
name|seol
init|=
name|MYEOL
decl_stmt|,
comment|/* End-Of-Line character to send */
name|eol
init|=
name|MYEOL
decl_stmt|,
comment|/* End-Of-Line character to look for */
name|ctlq
init|=
name|CTLQ
decl_stmt|,
comment|/* Control prefix in incoming data */
name|myctlq
init|=
name|CTLQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Outbound control character prefix */
end_comment

begin_comment
comment|/* Packet-related variables */
end_comment

begin_decl_stmt
name|int
name|pktnum
init|=
literal|0
decl_stmt|,
comment|/* Current packet number */
name|prvpkt
init|=
operator|-
literal|1
decl_stmt|,
comment|/* Previous packet number */
name|sndtyp
decl_stmt|,
comment|/* Type of packet just sent */
name|size
decl_stmt|,
comment|/* Current size of output pkt data */
name|osize
decl_stmt|,
comment|/* Previous output packet data size */
name|maxsize
decl_stmt|,
comment|/* Max size for building data field */
name|spktl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length packet being sent */
end_comment

begin_decl_stmt
name|CHAR
name|sndpkt
index|[
name|MAXPACK
operator|*
literal|2
index|]
decl_stmt|,
comment|/* Entire packet being sent */
name|recpkt
index|[
name|RBUFL
index|]
decl_stmt|,
comment|/* Packet most recently received */
name|data
index|[
name|MAXPACK
operator|+
literal|4
index|]
decl_stmt|,
comment|/* Packet data buffer */
name|srvcmd
index|[
name|MAXPACK
operator|*
literal|2
index|]
decl_stmt|,
comment|/* Where to decode server command */
modifier|*
name|srvptr
decl_stmt|,
comment|/* Pointer to above */
name|mystch
init|=
name|SOH
decl_stmt|,
comment|/* Outbound packet-start character */
name|stchr
init|=
name|SOH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Incoming packet-start character */
end_comment

begin_escape
end_escape

begin_comment
comment|/* File-related variables */
end_comment

begin_decl_stmt
name|CHAR
name|filnam
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of current file. */
end_comment

begin_decl_stmt
name|int
name|nfils
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of files in file group */
end_comment

begin_decl_stmt
name|long
name|fsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of current file */
end_comment

begin_comment
comment|/* Communication line variables */
end_comment

begin_decl_stmt
name|CHAR
name|ttname
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of communication line. */
end_comment

begin_decl_stmt
name|int
name|parity
decl_stmt|,
comment|/* Parity specified, 0,'e','o',etc */
name|flow
decl_stmt|,
comment|/* Flow control, 1 = xon/xoff */
name|speed
init|=
operator|-
literal|1
decl_stmt|,
comment|/* Line speed */
name|turn
init|=
literal|0
decl_stmt|,
comment|/* Line turnaround handshake flag */
name|turnch
init|=
name|XON
decl_stmt|,
comment|/* Line turnaround character */
name|duplex
init|=
literal|0
decl_stmt|,
comment|/* Duplex, full by default */
name|escape
init|=
literal|034
decl_stmt|,
comment|/* Escape character for connect */
name|delay
init|=
name|DDELAY
decl_stmt|,
comment|/* Initial delay before sending */
name|mdmtyp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Modem type (initially none)  */
end_comment

begin_comment
comment|/* Statistics variables */
end_comment

begin_decl_stmt
name|long
name|filcnt
decl_stmt|,
comment|/* Number of files in transaction */
name|flci
decl_stmt|,
comment|/* Characters from line, current file */
name|flco
decl_stmt|,
comment|/* Chars to line, current file  */
name|tlci
decl_stmt|,
comment|/* Chars from line in transaction */
name|tlco
decl_stmt|,
comment|/* Chars to line in transaction */
name|ffc
decl_stmt|,
comment|/* Chars to/from current file */
name|tfc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chars to/from files in transaction */
end_comment

begin_decl_stmt
name|int
name|tsecs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Seconds for transaction */
end_comment

begin_comment
comment|/* Flags */
end_comment

begin_decl_stmt
name|int
name|deblog
init|=
literal|0
decl_stmt|,
comment|/* Flag for debug logging */
name|pktlog
init|=
literal|0
decl_stmt|,
comment|/* Flag for packet logging */
name|seslog
init|=
literal|0
decl_stmt|,
comment|/* Session logging */
name|tralog
init|=
literal|0
decl_stmt|,
comment|/* Transaction logging */
name|displa
init|=
literal|0
decl_stmt|,
comment|/* File transfer display on/off */
name|stdouf
init|=
literal|0
decl_stmt|,
comment|/* Flag for output to stdout */
name|xflg
init|=
literal|0
decl_stmt|,
comment|/* Flag for X instead of F packet */
name|hcflg
init|=
literal|0
decl_stmt|,
comment|/* Doing Host command */
name|fncnv
init|=
literal|1
decl_stmt|,
comment|/* Flag for file name conversion */
name|binary
init|=
literal|0
decl_stmt|,
comment|/* Flag for binary file */
name|savmod
init|=
literal|0
decl_stmt|,
comment|/* Saved file mode */
name|warn
init|=
literal|0
decl_stmt|,
comment|/* Flag for file warning */
name|quiet
init|=
literal|0
decl_stmt|,
comment|/* Be quiet during file transfer */
name|local
init|=
literal|0
decl_stmt|,
comment|/* Flag for external tty vs stdout */
name|server
init|=
literal|0
decl_stmt|,
comment|/* Flag for being a server */
name|cnflg
init|=
literal|0
decl_stmt|,
comment|/* Connect after transaction */
name|cxseen
init|=
literal|0
decl_stmt|,
comment|/* Flag for cancelling a file */
name|czseen
init|=
literal|0
decl_stmt|,
comment|/* Flag for cancelling file group */
name|keep
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keep incomplete files */
end_comment

begin_comment
comment|/* Variables passed from command parser to protocol module */
end_comment

begin_function_decl
name|char
name|parser
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The parser itself */
end_comment

begin_decl_stmt
name|char
name|sstate
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Starting state for automaton */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cmarg
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to command data */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cmarg2
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to 2nd command data */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|cmlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to file list in argv */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Miscellaneous */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|xargv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global copies of argv */
end_comment

begin_decl_stmt
name|int
name|xargc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and argc  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dftty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default tty name from ckx???.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dfloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default location: remote/local */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dfprty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default parity */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dfflow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default flow control */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  M A I N  --  C-Kermit main program  */
end_comment

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
name|strcpy
parameter_list|()
function_decl|;
comment|/* Do some initialization */
name|xargc
operator|=
name|argc
expr_stmt|;
comment|/* Make global copies of argc */
name|xargv
operator|=
name|argv
expr_stmt|;
comment|/* ...and argv. */
name|sstate
operator|=
literal|0
expr_stmt|;
comment|/* No default start state. */
name|strcpy
argument_list|(
name|ttname
argument_list|,
name|dftty
argument_list|)
expr_stmt|;
comment|/* Set up default tty name. */
name|local
operator|=
name|dfloc
expr_stmt|;
comment|/* And whether it's local or remote. */
name|parity
operator|=
name|dfprty
expr_stmt|;
comment|/* Set initial parity, */
name|flow
operator|=
name|dfflow
expr_stmt|;
comment|/* and flow control. */
name|sysinit
argument_list|()
expr_stmt|;
comment|/* And any system-dependent things. */
comment|/* Look for a UNIX-style command line... */
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
comment|/* Command line arguments? */
name|sstate
operator|=
name|cmdlin
argument_list|()
expr_stmt|;
comment|/* Yes, parse. */
if|if
condition|(
name|sstate
condition|)
block|{
name|proto
argument_list|()
expr_stmt|;
comment|/* Take any requested action, then */
if|if
condition|(
operator|!
name|quiet
condition|)
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|/* put cursor back at left margin, */
if|if
condition|(
name|cnflg
condition|)
name|conect
argument_list|()
expr_stmt|;
comment|/* connect if requested, */
name|doexit
argument_list|(
name|GOOD_EXIT
argument_list|)
expr_stmt|;
comment|/* and then exit with status 0. */
block|}
block|}
comment|/* If no action requested on command line, enter interactive parser */
name|cmdini
argument_list|()
expr_stmt|;
comment|/* Initialize command parser */
while|while
condition|(
name|sstate
operator|=
name|parser
argument_list|()
condition|)
block|{
comment|/* Loop getting commands. */
if|if
condition|(
name|sstate
condition|)
name|proto
argument_list|()
expr_stmt|;
comment|/* Enter protocol if requested. */
block|}
block|}
end_function

end_unit

