begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K U U S 2  --  "User Interface" STRINGS module for Unix Kermit  */
end_comment

begin_comment
comment|/*  Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_comment
comment|/*  This module separates long strings from the body of the ckuser module. */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_include
include|#
directive|include
file|"ckucmd.h"
end_include

begin_include
include|#
directive|include
file|"ckuusr.h"
end_include

begin_decl_stmt
specifier|extern
name|char
name|cmdbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nrmt
decl_stmt|,
name|nprm
decl_stmt|,
name|dfloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dftty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|keytab
name|prmtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|keytab
name|remcmd
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hlp1
index|[]
init|=
block|{
literal|"\n"
block|,
literal|"  Usage: kermit [-x arg [-x arg]...[-yyy]..]]\n"
block|,
literal|"   x is an option that requires an argument, y an option with no argument:\n"
block|,
literal|"     actions (* options also require -l and -b) --\n"
block|,
literal|"       -s file(s)   send (use '-s -' to send from stdin)\n"
block|,
literal|"       -r           receive\n"
block|,
literal|"       -k           receive to stdout\n"
block|,
literal|"     * -g file(s)   get remote file(s) from server (quote wildcards)\n"
block|,
literal|"       -a name      alternate name, used with -s, -r, -g\n"
block|,
literal|"       -x           enter server mode\n"
block|,
literal|"     * -f           finish remote server\n"
block|,
literal|"     * -c           connect before transaction\n"
block|,
literal|"     * -n           connect after transaction\n"
block|,
literal|"       -h           help - print this message\n"
block|,
literal|"     settings --\n"
block|,
literal|"       -l line      communication line device\n"
block|,
literal|"       -b baud      line speed, e.g. 1200\n"
block|,
literal|"       -i           binary file or Unix-to-Unix\n"
block|,
literal|"       -p x         parity, x is one of e,o,m,s,n\n"
block|,
literal|"       -t           line turnaround handshake = xon, half duplex\n"
block|,
literal|"       -w           don't write over preexisting files\n"
block|,
literal|"       -q           be quiet during file transfer\n"
block|,
literal|"       -d           log debugging info to debug.log\n"
block|,
literal|" If no action command is included, enter interactive dialog.\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  U S A G E */
end_comment

begin_macro
name|usage
argument_list|()
end_macro

begin_block
block|{
name|conola
argument_list|(
name|hlp1
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  Help string definitions  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|tophlp
index|[]
init|=
block|{
literal|"\n\ Type ? for a list of commands, type 'help x' for any command x.\n\ While typing commands, use the following special characters:\n\n\  DEL, RUBOUT, BACKSPACE, CTRL-H: Delete the most recent character typed.\n\  CTRL-W: Delete the most recent word typed.\n"
block|,
literal|"\  CTRL-U: Delete the current line.\n\  CTRL-R: Redisplay the current line.\n\  ?       (question mark) display help on the current command or field.\n\  ESC     (Escape or Altmode) Attempt to complete the current field.\n"
block|,
literal|"\  \\       (backslash) include the following character literally.\n\n\ From system level, type 'kermit -h' to get help about command line args.\ \n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxbye
init|=
literal|"\ Shut down and log out a remote Kermit server"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxclo
init|=
literal|"\ Close one of the following logs:\n\  session, transaction, packet, debugging -- 'help log' for further info."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxcon
init|=
literal|"\ Connect to a remote system via the tty device given in the\n\ most recent 'set line' command"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxget
init|=
literal|"\ Format: 'get filespec'.  Tell the remote Kermit server to send the named\n\ files.  If filespec is omitted, then you are prompted for the remote and\n\ local filenames separately."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxlg
index|[]
init|=
block|{
literal|"\ Record information in a log file:\n\n\  debugging             Debugging information, to help track down\n\   (default debug.log)  bugs in the C-Kermit program.\n\n\  packets               Kermit packets, to help track down protocol problems.\n\   (packet.log)\n\n"
block|,
literal|" session               Terminal session, during CONNECT command.\n\   (session.log)\n\n\  transactions          Names and statistics about files transferred.\n\   (transact.log)\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxlogi
index|[]
init|=
block|{
literal|"\ Syntax: script text\n\n"
block|,
literal|"Login to a remote system using the text provided.  The login script\n"
block|,
literal|"is intended to operate similarly to uucp \"L.sys\" entries.\n"
block|,
literal|"A login script is a sequence of the form:\n\n"
block|,
literal|"	expect send [expect send] . . .\n\n"
block|,
literal|"where 'expect' is a prompt or message to be issued by the remote site, and\n"
block|,
literal|"'send' is the names, numbers, etc, to return.  The send may also be the\n"
block|,
literal|"keyword EOT, to send control-d, or BREAK, to send a break.  Letters in\n"
block|,
literal|"send may be prefixed by ~ to send special characters.  These are:\n"
block|,
literal|"~b backspace, ~s space, ~q '?', ~n linefeed, ~r return, ~c don\'t\n"
block|,
literal|"append a return, and ~o[o[o]] for octal of a character.  As with some \n"
block|,
literal|"uucp systems, sent strings are followed by ~r unless they end with ~c.\n\n"
block|,
literal|"Only the last 7 characters in each expect are matched.  A null expect,\n"
block|,
literal|"e.g. ~0 or two adjacent dashes, causes a short delay.  If you expect\n"
block|,
literal|"that a sequence might not arrive, as with uucp, conditional sequences\n"
block|,
literal|"may be expressed in the form:\n\n"
block|,
literal|"	-send-expect[-send-expect[...]]\n\n"
block|,
literal|"where dashed sequences are followed as long as previous expects fail.\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxrc
index|[]
init|=
block|{
literal|"\ Format: 'receive [filespec]'.  Wait for a file to arrive from the other\n\ Kermit, which must be given a 'send' command.  If the optional filespec is\n"
block|,
literal|"given, the (first) incoming file will be stored under that name, otherwise\n\ it will be stored under the name it arrives with."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxsen
init|=
literal|"\ Format: 'send file1 [file2]'.  File1 may contain wildcard characters '*' or\n\ '?'.  If no wildcards, then file2 may be used to specify the name file1 is\n\ sent under; if file2 is omitted, file1 is sent under its own name."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxser
init|=
literal|"\ Enter server mode on the currently selected line.  All further commands\n\ will be taken in packet form from the other Kermit program."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmhset
index|[]
init|=
block|{
literal|"\ The 'set' command is used to establish various communication or file\n"
block|,
literal|"parameters.  The 'show' command can be used to display the values of\n"
block|,
literal|"'set' parameters.  Help is available for each individual parameter;\n"
block|,
literal|"type 'help set ?' to see what's available.\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxychkt
index|[]
init|=
block|{
literal|"\ Type of packet block check to be used for error detection, 1, 2, or 3.\n"
block|,
literal|"Type 1 is standard, and catches most errors.  Types 2 and 3 specify more\n"
block|,
literal|"rigorous checking at the cost of higher overhead.  Not all Kermit programs\n"
block|,
literal|"support types 2 and 3.\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxyf
index|[]
init|=
block|{
literal|"\set file: names, type, warning, display.\n\n"
block|,
literal|"'names' are normally 'converted', which means file names are converted\n"
block|,
literal|"to 'common form' during transmission; 'literal' means use filenames\n"
block|,
literal|"literally (useful between like systems).\n\n"
block|,
literal|"'type' is normally 'text', in which conversion is done between Unix\n"
block|,
literal|"newlines and CRLF line delimiters; 'binary' means to do no conversion.\n"
block|,
literal|"Use 'binary' for executable programs or binary data.\n\n"
block|,
literal|"'warning' is 'on' or 'off', normally off.  When off, incoming files will\n"
block|,
literal|"overwrite existing files of the same name.  When on, new names will be\n"
block|,
literal|"given to incoming files whose names are the same as existing files.\n"
block|,
literal|"\n\ 'display' is normally 'on', causing file transfer progress to be displayed\n"
block|,
literal|"on your screen when in local mode.  'set display off' is useful for\n"
block|,
literal|"allowing file transfers to proceed in the background.\n\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmhrmt
index|[]
init|=
block|{
literal|"\ The 'remote' command is used to send file management instructions to a\n"
block|,
literal|"remote Kermit server.  There should already be a Kermit running in server\n"
block|,
literal|"mode on the other end of the currently selected line.  Type 'remote ?' to\n"
block|,
literal|"see a list of available remote commands.  Type 'help remote x' to get\n"
block|,
literal|"further information about a particular remote command 'x'.\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  D O H L P  --  Give a help message  */
end_comment

begin_macro
name|dohlp
argument_list|(
argument|xx
argument_list|)
end_macro

begin_decl_stmt
name|int
name|xx
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
if|if
condition|(
name|xx
operator|<
literal|0
condition|)
return|return
operator|(
name|xx
operator|)
return|;
switch|switch
condition|(
name|xx
condition|)
block|{
case|case
name|XXBYE
case|:
return|return
operator|(
name|hmsg
argument_list|(
name|hmxxbye
argument_list|)
operator|)
return|;
case|case
name|XXCLO
case|:
return|return
operator|(
name|hmsg
argument_list|(
name|hmxxclo
argument_list|)
operator|)
return|;
case|case
name|XXCON
case|:
return|return
operator|(
name|hmsg
argument_list|(
name|hmxxcon
argument_list|)
operator|)
return|;
case|case
name|XXCWD
case|:
ifdef|#
directive|ifdef
name|vms
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Change Working Directory, equivalent to VMS SET DEFAULT command"
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|hmsg
argument_list|(
literal|"Change Working Directory, equivalent to Unix 'cd' command"
argument_list|)
operator|)
return|;
endif|#
directive|endif
case|case
name|XXDEL
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Delete a local file or files"
argument_list|)
operator|)
return|;
case|case
name|XXDIAL
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Dial a number using modem autodialer"
argument_list|)
operator|)
return|;
case|case
name|XXDIR
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Display a directory of local files"
argument_list|)
operator|)
return|;
case|case
name|XXECH
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Display the rest of the command on the terminal,\n\ useful in command files."
argument_list|)
operator|)
return|;
case|case
name|XXEXI
case|:
case|case
name|XXQUI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Exit from the Kermit program, closing any open logs."
argument_list|)
operator|)
return|;
case|case
name|XXFIN
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Tell the remote Kermit server to shut down without logging out."
argument_list|)
operator|)
return|;
case|case
name|XXGET
case|:
return|return
operator|(
name|hmsg
argument_list|(
name|hmxxget
argument_list|)
operator|)
return|;
case|case
name|XXHLP
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|tophlp
argument_list|)
operator|)
return|;
case|case
name|XXLOG
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hmxxlg
argument_list|)
operator|)
return|;
case|case
name|XXLOGI
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hmxxlogi
argument_list|)
operator|)
return|;
case|case
name|XXREC
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hmxxrc
argument_list|)
operator|)
return|;
case|case
name|XXREM
case|:
if|if
condition|(
operator|(
name|y
operator|=
name|cmkey
argument_list|(
name|remcmd
argument_list|,
name|nrmt
argument_list|,
literal|"Remote command"
argument_list|,
literal|""
argument_list|)
operator|)
operator|==
operator|-
literal|2
condition|)
return|return
operator|(
name|y
operator|)
return|;
if|if
condition|(
name|y
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|y
operator|)
return|;
if|if
condition|(
name|x
operator|=
operator|(
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
return|return
operator|(
name|dohrmt
argument_list|(
name|y
argument_list|)
operator|)
return|;
case|case
name|XXSEN
case|:
return|return
operator|(
name|hmsg
argument_list|(
name|hmxxsen
argument_list|)
operator|)
return|;
case|case
name|XXSER
case|:
return|return
operator|(
name|hmsg
argument_list|(
name|hmxxser
argument_list|)
operator|)
return|;
case|case
name|XXSET
case|:
if|if
condition|(
operator|(
name|y
operator|=
name|cmkey
argument_list|(
name|prmtab
argument_list|,
name|nprm
argument_list|,
literal|"Parameter"
argument_list|,
literal|""
argument_list|)
operator|)
operator|==
operator|-
literal|2
condition|)
return|return
operator|(
name|y
operator|)
return|;
if|if
condition|(
name|y
operator|==
operator|-
literal|2
condition|)
return|return
operator|(
name|y
operator|)
return|;
if|if
condition|(
name|x
operator|=
operator|(
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
return|return
operator|(
name|dohset
argument_list|(
name|y
argument_list|)
operator|)
return|;
case|case
name|XXSHE
case|:
ifdef|#
directive|ifdef
name|vms
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Issue a command to VMS (space required after '!')"
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Issue a command to the Unix shell (space required after '!')"
argument_list|)
operator|)
return|;
endif|#
directive|endif
case|case
name|XXSHO
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Display current values of 'set' parameters; 'show version' will display\n\ program version information for each of the C-Kermit modules."
argument_list|)
operator|)
return|;
case|case
name|XXSPA
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Display disk usage in current device, directory"
argument_list|)
operator|)
return|;
case|case
name|XXSTA
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Display statistics about most recent file transfer"
argument_list|)
operator|)
return|;
case|case
name|XXTAK
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Take Kermit commands from the named file.  Kermit command files may\n\ themselves contain 'take' commands, up to a reasonable depth of nesting."
argument_list|)
operator|)
return|;
default|default:
if|if
condition|(
name|x
operator|=
operator|(
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
name|printf
argument_list|(
literal|"Not available yet - %s\n"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  H M S G  --  Get confirmation, then print the given message  */
end_comment

begin_macro
name|hmsg
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|x
operator|=
operator|(
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
name|puts
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|hmsga
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Same function, but for arrays */
name|int
name|x
decl_stmt|,
name|i
decl_stmt|;
if|if
condition|(
name|x
operator|=
operator|(
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|*
name|s
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
name|fputs
argument_list|(
name|s
index|[
name|i
index|]
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  D O H S E T  --  Give help for SET command  */
end_comment

begin_macro
name|dohset
argument_list|(
argument|xx
argument_list|)
end_macro

begin_decl_stmt
name|int
name|xx
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|xx
operator|==
operator|-
literal|3
condition|)
return|return
operator|(
name|hmsga
argument_list|(
name|hmhset
argument_list|)
operator|)
return|;
if|if
condition|(
name|xx
operator|<
literal|0
condition|)
return|return
operator|(
name|xx
operator|)
return|;
switch|switch
condition|(
name|xx
condition|)
block|{
case|case
name|XYCHKT
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hmxychkt
argument_list|)
operator|)
return|;
case|case
name|XYDELA
case|:
name|puts
argument_list|(
literal|"\ Number of seconds to wait before sending first packet after 'send' command."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYDUPL
case|:
name|puts
argument_list|(
literal|"\ During 'connect': 'full' means remote host echoes, 'half' means this program"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"does its own echoing."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYESC
case|:
name|printf
argument_list|(
literal|"%s"
argument_list|,
literal|"\ Decimal ASCII value for escape character during 'connect', normally 28\n\ (Control-\\)\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYFILE
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hmxyf
argument_list|)
operator|)
return|;
case|case
name|XYFLOW
case|:
name|puts
argument_list|(
literal|"\ Type of flow control to be used.  Choices are 'xon/xoff' and 'none'."
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"normally xon/xoff."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYHAND
case|:
name|puts
argument_list|(
literal|"\ Decimal ASCII value for character to use for half duplex line turnaround"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"handshake.  Normally, handshaking is not done."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYIFD
case|:
name|puts
argument_list|(
literal|"\ Incomplete file disposition: discard or keep.  Normally discard."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYLINE
case|:
name|printf
argument_list|(
literal|"\ Device name of communication line to use.  Normally %s.\n"
argument_list|,
name|dftty
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dfloc
condition|)
block|{
name|printf
argument_list|(
literal|"\ If you set the line to other than %s, then Kermit\n"
argument_list|,
name|dftty
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\ will be in 'local' mode; 'set line' will reset Kermit to its default mode.\n"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|vms
name|printf
argument_list|(
literal|"\ 'set line /dev/tty' will always put Kermit in remote mode.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|puts
argument_list|(
literal|"\ If the line has a modem, and if the modem-dialer is set to direct, this"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ command causes waiting for a carrier detect (e.g. on a hayes type modem)."
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ This can be used to wait for incoming calls."
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ To use the modem to dial out, first set modem-dialer (e.g., to hayes), then"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"set line, next issue the dial command, and finally connect."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYMODM
case|:
name|puts
argument_list|(
literal|"\ Type of modem for dialing remote connections.  Needed to indicate modem can"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ be commanded to dial without 'carrier detect' from modem.  Many recently"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ manufactured modems use 'hayes' protocol.  Type 'set modem ?' to see what"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ types of modems are supported by this program."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYPARI
case|:
name|puts
argument_list|(
literal|"Parity to use during terminal connection and file transfer:"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"even, odd, mark, space, or none.  Normally none."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYPROM
case|:
name|puts
argument_list|(
literal|"Prompt string for this program, normally 'C-Kermit>'."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYSPEE
case|:
name|puts
argument_list|(
literal|"\ Communication line speed for external tty line specified in most recent"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ 'set line' command.  Any of the common baud rates:"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" 0, 110, 150, 300, 600, 1200, 1800, 2400, 4800, 9600."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYRECV
case|:
name|puts
argument_list|(
literal|"\ Specify parameters for inbound packets:"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ End-Of-Packet (ASCII value), Packet-Length (94 or less),"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ Padding (amount, 94 or less), Pad-Character (ASCII value),"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ Start-Of-Packet (ASCII value), and Timeout (94 seconds or less),"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ all specified as decimal numbers."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|XYSEND
case|:
name|puts
argument_list|(
literal|"\ Specify parameters for outbound packets:"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ End-Of-Packet (ASCII value), Packet-Length (94 or less),"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ Padding (amount, 94 or less), Pad-Character (ASCII value),"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ Start-Of-Packet (ASCII value), and Timeout (94 seconds or less),"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ all specified as decimal numbers."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
default|default:
name|printf
argument_list|(
literal|"%s"
argument_list|,
literal|"Not available yet - %s\n"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  D O H R M T  --  Give help about REMOTE command  */
end_comment

begin_macro
name|dohrmt
argument_list|(
argument|xx
argument_list|)
end_macro

begin_decl_stmt
name|int
name|xx
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|xx
operator|==
operator|-
literal|3
condition|)
return|return
operator|(
name|hmsga
argument_list|(
name|hmhrmt
argument_list|)
operator|)
return|;
if|if
condition|(
name|xx
operator|<
literal|0
condition|)
return|return
operator|(
name|xx
operator|)
return|;
switch|switch
condition|(
name|xx
condition|)
block|{
case|case
name|XZCWD
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Ask remote Kermit server to change its working directory."
argument_list|)
operator|)
return|;
case|case
name|XZDEL
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Ask remote Kermit server to delete the named file(s)."
argument_list|)
operator|)
return|;
case|case
name|XZDIR
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Ask remote Kermit server to provide directory listing of the named file(s)."
argument_list|)
operator|)
return|;
case|case
name|XZHLP
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Ask remote Kermit server to tell you what services it provides."
argument_list|)
operator|)
return|;
case|case
name|XZHOS
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Send a command to the remote system in its own command language\n\ through the remote Kermit server."
argument_list|)
operator|)
return|;
case|case
name|XZSPA
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Ask the remote Kermit server to tell you about its disk space."
argument_list|)
operator|)
return|;
case|case
name|XZTYP
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Ask the remote Kermit server to type the named file(s) on your screen."
argument_list|)
operator|)
return|;
case|case
name|XZWHO
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Ask the remote Kermit server to list who's logged in, or to give information\n\ about the specified user."
argument_list|)
operator|)
return|;
default|default:
if|if
condition|(
name|x
operator|=
operator|(
name|cmcfm
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
name|printf
argument_list|(
literal|"%s"
argument_list|,
literal|"not working yet - %s\n"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
block|}
end_block

end_unit

