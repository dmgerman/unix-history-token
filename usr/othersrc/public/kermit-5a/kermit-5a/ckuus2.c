begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K U U S 2  --  User interface STRINGS& help module for C-Kermit  */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_comment
comment|/*  This module separates long strings from the body of the other ckuus* modules. */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_include
include|#
directive|include
file|"ckcnet.h"
end_include

begin_include
include|#
directive|include
file|"ckcasc.h"
end_include

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_include
include|#
directive|include
file|"ckuusr.h"
end_include

begin_include
include|#
directive|include
file|"ckcxla.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NOICP
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DCMDBUF
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmdbuf
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
name|cmdbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCMDBUF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOICP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|debfil
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TLOG
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|trafil
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xarg0
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
decl_stmt|,
name|local
decl_stmt|,
name|parity
decl_stmt|,
name|duplex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|turn
decl_stmt|,
name|flow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|binary
decl_stmt|,
name|warn
decl_stmt|,
name|quiet
decl_stmt|,
name|keep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|success
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|speed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dftty
decl_stmt|,
modifier|*
name|versio
decl_stmt|,
modifier|*
name|ckxsys
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

begin_comment
comment|/* Command-Line help (Unix command-line arguments) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOCMDL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hlp1
index|[]
init|=
block|{
ifndef|#
directive|ifndef
name|NOICP
literal|"[cmdfile] [-x arg [-x arg]...[-yyy]..] [ = text ] ]\n"
block|,
else|#
directive|else
literal|"[-x arg [-x arg]...[-yyy]..]\n"
block|,
endif|#
directive|endif
literal|"  -x is an option requiring an argument, -y an option with no argument.\n"
block|,
ifndef|#
directive|ifndef
name|NOICP
ifndef|#
directive|ifndef
name|NOSPL
literal|"     = means ignore following words, but place in array \\&@[].\n"
block|,
else|#
directive|else
literal|"     = means ignore following material.\n"
block|,
endif|#
directive|endif
comment|/* NOSPL */
else|#
directive|else
literal|"     = means ignore following material.\n"
block|,
endif|#
directive|endif
comment|/* NOICP */
literal|"actions:\n"
block|,
literal|"  -s files  send files                    -r  receive files\n"
block|,
literal|"  -s -      send files from stdin         -k  receive files to stdout\n"
block|,
ifndef|#
directive|ifndef
name|NOSERVER
literal|"  -x        enter server mode             -f  finish remote server\n\n"
block|,
else|#
directive|else
literal|"  -f        finish remote server\n\n"
block|,
endif|#
directive|endif
comment|/* NOSERVER */
literal|"  -g files  get remote files from server (quote wildcards)\n"
block|,
literal|"  -a name   alternate file name, used with -s, -r, -g\n"
block|,
literal|"  -c        connect (before file transfer), used with -l and -b\n"
block|,
literal|"  -n        connect (after file transfer), used with -l and -b\n\n"
block|,
literal|"settings:\n"
block|,
literal|"  -l line   communication line device     -q   quiet during file transfer\n"
block|,
ifdef|#
directive|ifdef
name|NETCONN
literal|"  -j host   network host name             -i   binary file transfer\n"
block|,
else|#
directive|else
literal|"  -i        binary file transfer\n"
block|,
endif|#
directive|endif
comment|/* NETCONN */
literal|"  -b bps    line speed, e.g. 2400         -t   half duplex, xon handshake\n"
block|,
ifdef|#
directive|ifdef
name|DEBUG
literal|"  -p x      parity, x = e,o,m,s, or n     -d   log debug info to debug.log\n"
block|,
else|#
directive|else
literal|"  -p x      parity, x = e,o,m,s, or n\n"
block|,
endif|#
directive|endif
comment|/* DEBUG */
ifndef|#
directive|ifndef
name|NOICP
literal|"  -y name   alternate init file name      -w   write over files\n"
block|,
else|#
directive|else
literal|"  -w        write over files\n"
block|,
endif|#
directive|endif
comment|/* NOICP */
literal|"  -e n      receive packet length         -v n window size\n"
block|,
ifndef|#
directive|ifndef
name|NODIAL
literal|"  -m name   modem type                    -z   force foreground\n"
block|,
else|#
directive|else
literal|"  -z        force foreground\n"
block|,
endif|#
directive|endif
comment|/* NODIAL */
ifdef|#
directive|ifdef
name|SUNX25
literal|"  -X  X.25 address              -o index  X.25 closed user group call\n"
block|,
literal|"  -u  X.25 reverse charge call  -U string X.25 call user data\n"
block|,
endif|#
directive|endif
comment|/* SUNX25 */
ifdef|#
directive|ifdef
name|NOICP
literal|"Interactive command parser removed.\n"
block|,
else|#
directive|else
literal|"If no action command is included, or -S is, enter interactive dialog.\n"
block|,
endif|#
directive|endif
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  U S A G E */
end_comment

begin_function
name|VOID
name|usage
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|MINIX
ifdef|#
directive|ifdef
name|NOICP
endif|#
directive|endif
comment|/* NOICP */
name|conol
argument_list|(
literal|"Usage: "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|xarg0
argument_list|)
expr_stmt|;
name|conola
argument_list|(
name|hlp1
argument_list|)
expr_stmt|;
else|#
directive|else
name|conol
argument_list|(
literal|"Usage: "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|xarg0
argument_list|)
expr_stmt|;
name|conol
argument_list|(
literal|" [-x arg [-x arg]...[-yyy]..] ]\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MINIX */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCMDL */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|NOICP
end_ifndef

begin_comment
comment|/*  Interactive help strings  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|tophlp
index|[]
init|=
block|{
literal|"Trustees of Columbia University in the City of New York.\n"
block|,
ifndef|#
directive|ifndef
name|NOHELP
literal|"Type ? for a list of commands, type HELP x for any command x."
block|,
else|#
directive|else
literal|"Type ? for a list of commands; see documentation for detailed descriptions."
block|,
endif|#
directive|endif
comment|/* NOHELP */
literal|"While typing commands, you may use the following special characters:\n"
block|,
literal|" DEL, RUBOUT, BACKSPACE, CTRL-H: Delete the most recent character typed."
block|,
literal|" CTRL-W:  Delete the most recent word typed."
block|,
literal|" CTRL-U:  Delete the current line."
block|,
literal|" CTRL-R:  Redisplay the current line."
block|,
literal|" ?        (question mark) Display a menu for the current command field."
block|,
literal|" ESC      (or TAB) Attempt to complete the current field."
block|,
literal|" \\        (backslash) include the following character literally"
block|,
ifndef|#
directive|ifndef
name|NOSPL
literal|"          or introduce a numeric backslash code, variable, or function.\n"
block|,
else|#
directive|else
literal|"          or introduce a numeric backslash code.\n"
block|,
endif|#
directive|endif
comment|/* NOSPL */
literal|"Command words other than filenames can be abbreviated in most contexts."
block|,
literal|"Commands may be continued onto subsequent lines by ending them with - (dash)"
block|,
literal|"and commands may have trailing comments introduced by ; (semicolon)."
block|,
ifndef|#
directive|ifndef
name|NOFRILLS
literal|"The BUG command tells you how to report bugs."
block|,
endif|#
directive|endif
comment|/* NOFRILLS */
ifndef|#
directive|ifndef
name|NOCMDL
literal|"\nFrom system level, type 'kermit -h' for help about command line options."
block|,
endif|#
directive|endif
comment|/* NOCMDL */
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOHELP
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxbye
init|=
literal|"Syntax: BYE\n\ Shut down and log out a remote Kermit server"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxclo
index|[]
init|=
block|{
literal|"Syntax:  CLOSE name"
block|,
literal|"Example: CLOSE SESSION\n"
block|,
literal|"Close one of the following logs or files:"
block|,
literal|"SESSION, TRANSACTION, PACKET, DEBUGGING, READ, WRITE"
block|,
literal|"Type HELP LOG and HELP OPEN for further info."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxcon
init|=
literal|"Syntax: CONNECT (or C)\n\n\ Connect to a remote computer via the tty device given in the most recent\n\ SET LINE command, or the network host named in the most recent SET HOST\n\ command.  Type the escape character (normally Ctrl-\\) followed by C to\n\ get back, or followed by ? for help."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxget
init|=
literal|"Syntax: GET filespec\n\ Tell the remote Kermit server to send the named file or files.\n\ If the filespec is omitted, then you are prompted for the remote and\n\ local filenames separately."
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
literal|"Syntax: LOG (or L) name [ { NEW, APPEND } ]"
block|,
literal|"Record information in a log file:\n"
block|,
literal|"DEBUGGING     Debugging information, to help track down bugs in the C-Kermit"
block|,
literal|"              program (default log name is debug.log).\n"
block|,
literal|"PACKETS       Kermit packets, to help with protocol problems (packet.log)"
block|,
literal|"SESSION       Terminal session, during CONNECT command (session.log)"
block|,
literal|"TRANSACTIONS  Names and statistics about files transferred (transact.log)\n"
block|,
literal|"If you include the APPEND keyword after the filename, the existing log, if"
block|,
literal|"any, is appended to; otherwise a new file is created."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOSCRIPT
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxlogi
index|[]
init|=
block|{
literal|"\ Syntax: SCRIPT text\n"
block|,
literal|"Login to a remote system using the text provided.  The login script"
block|,
literal|"is intended to operate similarly to uucp \"L.sys\" entries."
block|,
literal|"A login script is a sequence of the form:\n"
block|,
literal|"  expect send [expect send] . . .\n"
block|,
literal|"where 'expect' is a prompt or message to be issued by the remote site, and"
block|,
literal|"'send' is the names, numbers, etc, to return.  The send may also be the"
block|,
literal|"keyword EOT, to send control-d, or BREAK (or \\\\b), to send a break signal."
block|,
literal|"Letters in send may be prefixed by ~ to send special characters.  These are:"
block|,
literal|"~b backspace, ~s space, ~q '?', ~n linefeed, ~r return, ~c don\'t"
block|,
literal|"append a return, and ~o[o[o]] for octal of a character.  As with some"
block|,
literal|"uucp systems, sent strings are followed by ~r unless they end with ~c.\n"
block|,
literal|"Only the last 7 characters in each expect are matched.  A null expect,"
block|,
literal|"e.g. ~0 or two adjacent dashes, causes a short delay.  If you expect"
block|,
literal|"that a sequence might not arrive, as with uucp, conditional sequences"
block|,
literal|"may be expressed in the form:\n"
block|,
literal|"  -send-expect[-send-expect[...]]\n"
block|,
literal|"where dashed sequences are followed as long as previous expects fail."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxrc
index|[]
init|=
block|{
literal|"Syntax: RECEIVE (or R) [filespec]\n"
block|,
literal|"Wait for a file to arrive from the other Kermit, which must be given a"
block|,
literal|"SEND command.  If the optional filespec is given, the (first) incoming"
block|,
literal|"file will be stored under that name, otherwise it will be stored under"
block|,
literal|"the name it arrives with."
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
literal|"\ Syntax: SEND (or S) filespec [name]\n\n\ Send the file or files specified by filespec.\n\ filespec may contain wildcard characters '*' or '?'.  If no wildcards,\n\ then 'name' may be used to specify the name 'filespec' is sent under; if\n\ 'name' is omitted, the file is sent under its own name."
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOMSEND
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmssmse
init|=
literal|"\ Syntax: MSEND filespec [ filespec [ ... ] ]\n\n\ Send the files specified by the filespecs.  One or more filespecs may be\n\ listed, separated by spaces.  Any or all filespecs may contain wildcards\n\ and they may be in different directories.  An alternate name cannot be given."
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOMSEND */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSERVER
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxxser
init|=
literal|"Syntax: SERVER\n\n\ Enter server mode on the currently selected line.  All further commands\n\ will be taken in packet form from the other Kermit program.  Use FINISH\n\ or BYE to get C-Kermit out of server mode."
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSERVER */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmhset
index|[]
init|=
block|{
literal|"\ The SET command is used to establish various communication or file"
block|,
literal|"parameters.  The SHOW command can be used to display the values of"
block|,
literal|"SET parameters.  Help is available for each individual parameter;"
block|,
literal|"type HELP SET ? to see what's available."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOSETKEY
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmhskey
index|[]
init|=
block|{
literal|"Syntax: SET KEY k text\n"
block|,
literal|"Map the key k to send 'text' when pressed during CONNECT mode."
block|,
literal|"K can be expressed as decimal number or backslash code, 'text'"
block|,
literal|"can also contain any backslash code.  If 'text' has the length 1"
block|,
literal|"it is treated specially.  In some environments (OS/2, for example)"
block|,
literal|"that single character may be wider than 8 bits, if specified in"
block|,
literal|"backslash notation.  In this case, a scan code mapping takes place,"
block|,
literal|"i.e. key k takes over the function of the key whose scan code is"
block|,
literal|"assigned to k.  This may even be a controlling key for the CONNECT"
block|,
literal|"mode.  If 'text' is empty, the default key binding is restored for"
block|,
literal|"the key k.  SET KEY mappings take place before terminal character-set"
block|,
literal|"translation."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSETKEY */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxychkt
index|[]
init|=
block|{
literal|"Syntax: SET BLOCK-CHECK n\n"
block|,
literal|"Type of packet block check to be used for error detection, 1, 2, or 3."
block|,
literal|"Type 1 is standard, and catches most errors.  Types 2 and 3 specify more"
block|,
literal|"rigorous checking at the cost of higher overhead."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxydial
index|[]
init|=
block|{
literal|"SET DIAL DISPLAY {ON, OFF}"
block|,
literal|"Whether to display dialing progress on the screen.\n"
block|,
literal|"SET DIAL HANGUP {ON, OFF}"
block|,
literal|"Whether the DIAL command should hang up the phone before dialing.\n"
block|,
literal|"SET DIAL INIT-STRING text"
block|,
literal|"The 'text' is a replacement for Kermit's built-in initialization command"
block|,
literal|"for the modem.\n"
block|,
literal|"SET DIAL KERMIT-SPOOF {ON, OFF}"
block|,
literal|"If the selected modem type supports the Kermit protocol directly,"
block|,
literal|"use this command to turn its Kermit protocol function on or off.\n"
block|,
literal|"SET DIAL MNP-ENABLE {ON, OFF}"
block|,
literal|"Enable or disable MNP negotiation by the modem.  Currently works only"
block|,
literal|"for Telebits.\n"
block|,
literal|"SET DIAL SPEED-MATCHING {ON, OFF}"
block|,
literal|"If selected, the modem locks its interface speed, even if it connects"
block|,
literal|"to a slower modem.  Default is OFF (modem changes speed).\n"
block|,
literal|"SET DIAL TIMEOUT number"
block|,
literal|"How many seconds to wait for a dialed call to complete.  Use this"
block|,
literal|"to override the DIAL command's automatic timeout calculation.  A value"
block|,
literal|"of 0 turns off this feature and returns to Kermit's automatic dial"
block|,
literal|"timeout calculation."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxyf
index|[]
init|=
block|{
literal|"Syntax: SET FILE parameter value"
block|,
literal|"Parameters are:\n"
block|,
literal|"TYPE is normally TEXT, with conversion of record format and character set."
block|,
literal|"BINARY means to do no conversion.  Use BINARY for executable programs or"
block|,
literal|"binary data.  Example: SET FILE TYPE BINARY.\n"
block|,
ifdef|#
directive|ifdef
name|VMS
literal|"For VAX/VMS, you may include an optional record-format after the word"
block|,
literal|"BINARY.  This may be FIXED (the default) or UNDEFINED."
block|,
literal|"Two additional VMS file types are also supported: IMAGE and LABELED.  IMAGE"
block|,
literal|"means raw block i/o, no interference from RMS, and applies to file transmis-"
block|,
literal|"sion only.  LABELED means to send or interpret RMS attributes with the file."
block|,
literal|"\n"
block|,
endif|#
directive|endif
comment|/* VMS */
ifndef|#
directive|ifndef
name|NOCSETS
literal|"CHARACTER-SET: tells the encoding of the local file, ASCII by default."
block|,
literal|"The names ITALIAN, PORTUGUESE, NORWEGIAN, etc, refer to 7-bit ISO-646"
block|,
literal|"national replacement character (NRC) sets.  Latin-1 is the 8-bit ISO 8859"
block|,
literal|"Latin Alphabet 1.  Next is the 8-bit character set of the NeXT workstation."
block|,
literal|"The CPnnn sets are for IBM PCs.  Apple-Quickdraw is for the Macintosh."
block|,
ifdef|#
directive|ifdef
name|CYRILLIC
literal|"KOI-CYRILLIC, CYRILLIC-ISO, and CP866 are 8-bit Cyrillic character sets."
block|,
literal|"SHORT-KOI is a 7-bit ASCII coding for Cyrillic."
block|,
endif|#
directive|endif
comment|/* CYRILLIC */
ifdef|#
directive|ifdef
name|KANJI
literal|"JAPANESE-EUC, JIS7-KANJI, DEC-KANJI, and SHIFT-JIS-KANJI are Japanese"
block|,
literal|"Kanji character sets."
block|,
endif|#
directive|endif
comment|/* KANJI */
literal|"Type SET FILE CHAR ? for a complete list of file character sets.\n"
block|,
endif|#
directive|endif
comment|/* NOCSETS */
literal|"BYTESIZE { 7, 8 }: normally 8.  If 7, truncate the 8th bit of all file \ bytes.\n"
block|,
literal|"NAMES are normally CONVERTED to 'common form' during transmission; LITERAL"
block|,
literal|"means use filenames literally (useful between like systems).\n"
block|,
literal|"COLLISION tells what to do when a file arrives that has the same name as"
block|,
literal|"an existing file.  The options are:"
block|,
literal|"  BACKUP (default) - Rename the old file to a new, unique name and store"
block|,
literal|"    the incoming file under the name it was sent with."
block|,
literal|"  OVERWRITE - Overwrite (replace) the existing file."
block|,
literal|"  APPEND - Append the incoming file to the end of the existing file."
block|,
literal|"  DISCARD - Refuse and/or discard the incoming file."
block|,
literal|"  RENAME - Give the incoming file a unique name."
block|,
literal|"  UPDATE - Accept the incoming file only if it is newer than the existing"
block|,
literal|"    file."
block|,
literal|"Example: SET FILE COLLISION UPDATE\n"
block|,
ifdef|#
directive|ifdef
name|VMS
literal|"RECORD-LENGTH sets the record length for received files of type BINARY. Use"
block|,
literal|"this to receive VMS BACKUP savesets or other fixed-format files. The default"
block|,
literal|"of 512 is suitable for executable (.EXE) files, etc.\n"
block|,
literal|"Example: SET FILE REC 8192\n"
block|,
endif|#
directive|endif
literal|"DISPLAY is normally ON, causing file transfer progress to be displayed"
block|,
literal|"on your screen when in local mode.  SET DISPLAY OFF is useful for"
block|,
literal|"allowing local-mode file transfers to proceed in the background.\n"
block|,
literal|"WARNING.  SET FILE WARNING is superseded by the newer command, SET FILE"
block|,
literal|"COLLISION.  SET FILE WARNING ON is equivalent to SET FILE COLLISION RENAME"
block|,
literal|"and SET FILE WARNING OFF is equivalent to SET FILE COLLISION OVERWRITE.\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxyhsh
index|[]
init|=
block|{
literal|"Syntax: SET HANDSHAKE value\n"
block|,
literal|"Character to use for half duplex line turnaround handshake during file"
block|,
literal|"transfer.  C-Kermit waits for this character from the other computer before"
block|,
literal|"sending its next packet.  Default is NONE, others are XON, LF, BELL, ESC,"
block|,
literal|"etc.  SET HANDSHAKE CODE<n> lets you specify the numeric ASCII value of the"
block|,
literal|"handshake character.  Type SET HANDSH ? for a list."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOSERVER
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hsetsrv
index|[]
init|=
block|{
literal|"\ SET SERVER DISPLAY {ON,OFF}"
block|,
literal|"Tell whether local-mode C-Kermit during server operation should put a"
block|,
literal|"file transfer display on the screen.  Default is OFF.\n"
block|,
literal|"SET SERVER TIMEOUT n"
block|,
literal|"Server command wait timeout interval, how often the C-Kermit server issues"
block|,
literal|"a NAK while waiting for a command packet.  Specify 0 for no NAKs at all."
block|,
literal|"Default is 0."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSERVER */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmhrmt
index|[]
init|=
block|{
literal|"\ The REMOTE command is used to send file management instructions to a"
block|,
literal|"remote Kermit server.  There should already be a Kermit running in server"
block|,
literal|"mode on the other end of the currently selected line.  Type REMOTE ? to"
block|,
literal|"see a list of available remote commands.  Type HELP REMOTE x to get"
block|,
literal|"further information about a particular remote command 'x'."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ifhlp
index|[]
init|=
block|{
literal|"Syntax: IF [NOT] condition command\n"
block|,
literal|"If the condition is (is not) true, do the command.  Only one command may"
block|,
literal|"be given, and it must appear on the same line as the IF.  Conditions are:\n"
block|,
literal|"  SUCCESS - the previous command succeeded"
block|,
literal|"  FAILURE - the previous command failed"
block|,
literal|"  DEFINED variablename or macroname - The named variable or macro is defined"
block|,
literal|"  NUMERIC variable or constant      - The variable or constant is numeric"
block|,
literal|"  EXIST filename                    - The named file exists"
block|,
literal|"  COUNT   - subtract one from COUNT, execute the command if the result is"
block|,
literal|"            greater than zero (see SET COUNT)"
block|,
literal|"  EQUAL s1 s2 - s1 and s2 (character strings or variables) are equal"
block|,
literal|"  LLT s1 s2   - s1 is lexically (alphabetically) less than s2"
block|,
literal|"  LGT s1 s1   - s1 is lexically (alphabetically) greater than s2"
block|,
literal|"  = n1 n1 - n1 and n2 (numbers or variables containing numbers) are equal"
block|,
literal|"< n1 n2 - n1 is arithmetically less than n2"
block|,
literal|"> n1 n2 - n1 is arithmetically greater than n2\n"
block|,
literal|"The IF command may be followed on the next line by an ELSE command. Example:"
block|,
literal|"  IF< \\%x 10 ECHO It's less"
block|,
literal|"  ELSE echo It's not less"
block|,
literal|"See also XIF."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ifxhlp
index|[]
init|=
block|{
literal|"\ Syntax: XIF condition { commandlist } [ ELSE { commandlist } ]\n"
block|,
literal|"Extended IF command.  The conditions are the same as for IF (type HELP IF)"
block|,
literal|"but multiple comma-separated commands may be grouped within braces in both"
block|,
literal|"the IF and ELSE parts.  The ELSE part, if any, must be on the same line as"
block|,
literal|"the XIF (or use dash for line continuation).  Example:\n"
block|,
literal|"  XIF equal \\%a YES { echo OK, goto begin } ELSE { echo Not OK, stop }"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|forhlp
index|[]
init|=
block|{
literal|"\ Syntax: FOR variablename initial-value final-value increment { commandlist }"
block|,
literal|"\nFOR loop.  Execute the comma-separated commands in the commandlist the"
block|,
literal|"number of times given by the initial value, final value and increment."
block|,
literal|"Example:  FOR \\%i 10 1 -1 { pause 1, echo \\%i }"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|whihlp
index|[]
init|=
block|{
literal|"\ Syntax: WHILE condition { commandlist }\n"
block|,
literal|"\nWHILE loop.  Execute the comma-separated commands in the commandlist while"
block|,
literal|"the condition is true.  Conditions are the same as for IF commands.\n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|openhlp
index|[]
init|=
block|{
literal|"Syntax:  OPEN mode filename\n"
block|,
literal|"For use with READ and WRITE commands.  Open the local file in the specified"
block|,
literal|"mode: READ, WRITE, or APPEND.  !READ and !WRITE mean to read from or write"
block|,
literal|"to a system command rather than a file.  Examples:\n"
block|,
literal|"  OPEN READ oofa.txt"
block|,
literal|"  OPEN !READ sort foo.bar"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxaskq
index|[]
init|=
block|{
literal|"Syntax:  ASKQ variablename prompt"
block|,
literal|"Example: ASKQ %p Password:\n"
block|,
literal|"Issues the prompt and defines the variable to be whatever you type in."
block|,
literal|"The characters that you type do not echo on the screen."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxdef
index|[]
init|=
block|{
literal|"Syntax: DEFINE name [ definition ]\n"
block|,
literal|"Defines a macro or variable.  Its value is the definition, taken literally."
block|,
literal|"No expansion or evaluation of the definition is done.  Thus if the"
block|,
literal|"definition includes any variable or function references, their names are"
block|,
literal|"included, rather than their values (compare with ASSIGN).  If the definition"
block|,
literal|"is omitted, then the named variable or macro is undefined.\n"
block|,
literal|"A typical macro definition looks like this:\n"
block|,
literal|"  DEFINE name command, command, command, ...\n"
block|,
literal|"for example:\n"
block|,
literal|"  DEFINE vax set parity even, set duplex full, set flow xon/xoff\n"
block|,
literal|"which defines a Kermit command macro called 'vax'.  The definition is a"
block|,
literal|"comma-separated list of Kermit commands.  Use the DO command to execute"
block|,
literal|"the macro, or just type its name, followed optionally by arguments.\n"
block|,
literal|"The definition of a variable can be anything at all, for example:\n"
block|,
literal|"  DEFINE \\%a Monday"
block|,
literal|"  DEFINE \\%b 3\n"
block|,
literal|"These variables can be used almost anywhere, for example:\n"
block|,
literal|"  ECHO Today is \\%a"
block|,
literal|"  SET BLOCK-CHECK \\%b"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxass
index|[]
init|=
block|{
literal|"Syntax:  ASSIGN variablename string."
block|,
literal|"Example: ASSIGN \\%a My name is \\%b.\n"
block|,
literal|"Assigns the current value of the string to the variable (or macro)."
block|,
literal|"The definition string is fully evaluated before it is assigned, so that"
block|,
literal|"the values of any variables are contained are used, rather than their"
block|,
literal|"names.  Compare with DEFINE.  To illustrate the difference, try this:\n"
block|,
literal|"  DEFINE \\%a hello"
block|,
literal|"  DEFINE \\%x \\%a"
block|,
literal|"  ASSIGN \\%y \\%a"
block|,
literal|"  DEFINE \\%a goodbye"
block|,
literal|"  ECHO \\%x \\%y\n"
block|,
literal|"This will print 'goodbye hello'."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxdec
index|[]
init|=
block|{
literal|"Syntax: DECREMENT variablename [ number ]\n"
block|,
literal|"Decrement (subtract one from) the value of a variable if the current value"
block|,
literal|"is numeric.  If the number argument is given, subtract that number instead."
block|,
literal|"\nExamples: DECR \\%a, DECR \\%a 7, DECR \\%a \\%n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxinc
index|[]
init|=
block|{
literal|"Syntax: INCREMENT variablename [ number ]\n"
block|,
literal|"Increment (add one to) the value of a variable if the current value is"
block|,
literal|"numeric.  If the number argument is given, add that number instead.\n"
block|,
literal|"Examples: INCR \\%a, INCR \\%a 7, INCR \\%a \\%n"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNX25
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxpad
index|[]
init|=
block|{
literal|"Syntax: PAD command"
block|,
literal|"Execute a PAD command. Examples:\n"
block|,
literal|"    PAD clear - clear the virtual call"
block|,
literal|"    PAD status - return the status of virtual call"
block|,
literal|"    PAD reset - send a reset packet"
block|,
literal|"    PAD interrupt - send an interrupt packet"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxyx25
index|[]
init|=
block|{
literal|"Syntax: SET X.25 call-option on [index,string]/off\n"
block|,
literal|"Set X.25 call option.  Options are:"
block|,
literal|"  closed-user-group on index/off - to enable/disable closed user group call,"
block|,
literal|"    where index is the group index and can range from 0 to 99"
block|,
literal|"  reverse-charge on/off - to enable/disable reverse charge call"
block|,
literal|"  call-user-data on string/off - to specify call user data in X.25 call."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNX25 */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxpau
index|[]
init|=
block|{
literal|"Syntax:  PAUSE [ number ]"
block|,
literal|"Example: PAUSE 3\n"
block|,
literal|"Do nothing for the specified number of seconds; if no number given, one"
block|,
literal|"second.  If interrupted from the keyboard, set FAILURE, otherwise SUCCESS."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOPUSH
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxshe
index|[]
init|=
block|{
literal|"Syntax: ! [ command ] or RUN [ command ] or PUSH [ command ]\n"
block|,
literal|"Give a command to the local operating system's command processor, and"
block|,
literal|"display the results on the screen.\n"
block|,
literal|"If the command is omitted, enter interactive mode; return to Kermit"
block|,
literal|"by exiting from the system's command parser.  The command is usually"
block|,
literal|"EXIT or QUIT or LOGOUT."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOPUSH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOXMIT
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxxmit
index|[]
init|=
block|{
literal|"Syntax: TRANSMIT file\n"
block|,
literal|"The TRANSMIT command is used for sending single files to other computers"
block|,
literal|"that don't have Kermit.  Text files are sent a line at a time; binary files"
block|,
literal|"are sent a character at a time.  There is no guarantee that the other"
block|,
literal|"computer will receive the file correctly and completely.  Before you start"
block|,
literal|"the TRANSMIT command, you must put the other computer in data collection"
block|,
literal|"mode, for example by starting a text editor.  TRANSMIT may be interrupted by"
block|,
literal|"Ctrl-C.  Synonym: XMIT."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOXMIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOCSETS
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxxla
index|[]
init|=
block|{
literal|"Syntax: TRANSLATE file1 cs1 cs2 [ file2 ]\n"
block|,
literal|"Translates file1 from the character set cs1 into the character set cs2"
block|,
literal|"and stores the result in file2.  The character sets can be any of"
block|,
literal|"C-Kermit's file character sets.  If file2 is omitted, the translation"
block|,
literal|"is displayed on the screen.  Uses Latin-1 as intermediate character set"
block|,
literal|"unless LANGUAGE is set to RUSSIAN, in which case it uses Latin-Cyrillic."
block|,
literal|"Synonym: XLATE.  Example:\n"
block|,
literal|"TRANSLATE lasagna.lat latin1 italian lasagna.nrc"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCSETS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxwai
index|[]
init|=
block|{
literal|"Syntax:  WAIT number [modem-signal(s)]"
block|,
literal|"Example: WAIT 5 \\cd\\cts\n"
block|,
literal|"Waits up to the given number of seconds for all of the specified signals."
block|,
literal|"Sets FAILURE if signals do not appear in given time or if interrupted by"
block|,
literal|"typing anything at the keyboard during the waiting period.\n"
block|,
literal|"Signals: \\cd = Carrier Detect, \\dsr = Dataset Ready, \\cts = Clear To Send"
block|,
literal|"Warning: This command does not work yet, signals are ignored."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxwri
index|[]
init|=
block|{
literal|"Syntax: WRITE name text\n"
block|,
literal|"Writes the given text to the named log or file.  The text text may include"
block|,
literal|"backslash codes, and is not terminated by a newline unless you include the"
block|,
literal|"appropriate code.  The name parameter can be any of the following:\n"
block|,
literal|"  DEBUG-LOG"
block|,
ifndef|#
directive|ifndef
name|NOSPL
literal|"  FILE (the OPEN WRITE, OPEN !WRITE, or OPEN APPEND file, see HELP OPEN)"
block|,
endif|#
directive|endif
comment|/* NOSPL */
literal|"  PACKET-LOG"
block|,
literal|"  SCREEN (compare with ECHO)"
block|,
literal|"  SESSION-LOG"
block|,
literal|"  TRANSACTION-LOG"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NODIAL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxdial
index|[]
init|=
block|{
literal|"Syntax:  DIAL phonenumber"
block|,
literal|"Example: DIAL 7654321\n"
block|,
literal|"Dial a number using a modem autodialer.  First you must SET MODEM, then"
block|,
literal|"SET LINE and SET SPEED.  Then give the DIAL command, including the phone"
block|,
literal|"number.  See also SET DIAL, SET MODEM, SET LINE, SET SPEED, REDIAL."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIAL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOHELP */
end_comment

begin_comment
comment|/*  D O H L P  --  Give a help message  */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int dohset
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|dohlp
parameter_list|(
name|xx
parameter_list|)
name|int
name|xx
decl_stmt|;
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
ifdef|#
directive|ifdef
name|NOHELP
case|case
name|XXHLP
case|:
if|if
condition|(
operator|(
name|x
operator|=
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
literal|"%s, Copyright (C) 1985, 1992,\n"
argument_list|,
name|versio
argument_list|)
expr_stmt|;
for|for
control|(
name|x
operator|=
literal|0
init|;
operator|*
name|tophlp
index|[
name|x
index|]
condition|;
name|x
operator|++
control|)
comment|/* Print lines */
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|tophlp
index|[
name|x
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
comment|/* End with blank line */
return|return
operator|(
literal|1
operator|)
return|;
else|#
directive|else
comment|/* help is available */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXASS
case|:
comment|/* assign */
return|return
operator|(
name|hmsga
argument_list|(
name|hxxass
argument_list|)
operator|)
return|;
case|case
name|XXASK
case|:
comment|/* ask */
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Syntax:  ASK variablename prompt\n\ Example: ASK \\%n What is your name\\63\\32\n\n\ Issues the prompt and defines the variable to be whatever you type in."
argument_list|)
operator|)
return|;
case|case
name|XXASKQ
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxaskq
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXBUG
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Describe how to report C-Kermit bugs."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
case|case
name|XXBYE
case|:
comment|/* bye */
return|return
operator|(
name|hmsg
argument_list|(
name|hmxxbye
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXCLE
case|:
comment|/* clear */
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Syntax: CLEAR\n\ Clear the serial port input buffer."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
case|case
name|XXCLO
case|:
comment|/* close */
return|return
operator|(
name|hmsga
argument_list|(
name|hmxxclo
argument_list|)
operator|)
return|;
case|case
name|XXCOM
case|:
comment|/* comment */
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Syntax: COMMENT text\n\ Example: COMMENT - this is a comment.\n\n\ Introduce a comment.  Beginning of command line only.  Commands may also\n\ have trailing comments, introduced by ; (semicolon)."
argument_list|)
operator|)
return|;
case|case
name|XXCON
case|:
comment|/* connect */
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
comment|/* cd / cwd */
ifdef|#
directive|ifdef
name|vms
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: CD [ directory or device:directory ]\n\ Change Working Directory, equivalent to VMS SET DEFAULT command"
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|datageneral
return|return
operator|(
name|hmsg
argument_list|(
literal|"Change Working Directory, equivalent to DG 'dir' command"
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|OS2
return|return
operator|(
name|hmsg
argument_list|(
literal|"Change Working Directory, equivalent to OS/2 'chdir' command"
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: CD [ directoryname ]\n\n\ Change Working Directory, equivalent to UNIX cd command."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* datageneral */
endif|#
directive|endif
comment|/* vms */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXDCL
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax:  DECLARE arrayname[size]\n\ Example: DECLARE \\&a[20]\n\n\ Declares an array of the given size.  Array elements can be used just like\n\ any other variables."
argument_list|)
operator|)
return|;
case|case
name|XXDEF
case|:
comment|/* define */
return|return
operator|(
name|hmsga
argument_list|(
name|hxxdef
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXDEL
case|:
comment|/* delete */
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: DELETE filespec\n\n\ Delete a local file or files.  RM is a synonym for DELETE."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
ifndef|#
directive|ifndef
name|NODIAL
case|case
name|XXDIAL
case|:
comment|/* dial */
return|return
operator|(
name|hmsga
argument_list|(
name|hxxdial
argument_list|)
operator|)
return|;
endif|#
directive|endif
case|case
name|XXDIR
case|:
comment|/* directory */
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: DIRECTORY [ filespec ]\n\ Display a directory listing of local files."
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSERVER
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXDIS
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: DISABLE command\n\n\ Security for the C-Kermit server.  Prevent the client Kermit program from\n\ executing the named REMOTE command, such as CD, DELETE, RECEIVE, etc."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
endif|#
directive|endif
comment|/* NOSERVER */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXDO
case|:
comment|/* do */
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: [ DO ] macroname [ arguments ]\n\n\ Execute a macro that was defined by the DEFINE command.  The word DO\n\ can be omitted.  Trailing argument words, if any, are automatically\n\ assigned to the macro argument variables \\%1, \\%2, etc."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXDEC
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxdec
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
case|case
name|XXECH
case|:
comment|/* echo */
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: ECHO text\n\ Display the text on the screen, followed by a newline.  The ECHO text may\n\ contain backslash codes.  Example: ECHO \\7Wake up!\\7"
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSERVER
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXENA
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: ENABLE capability\n\n\ For use with server mode.  Allow the client Kermit program access to the\n\ named capability, such as CD, DELETE, RECEIVE, etc.  Opposite of DISABLE."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
endif|#
directive|endif
comment|/* NOSERVER */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXEND
case|:
comment|/* end */
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: END\n\ Exit from the current macro or TAKE file, back to wherever invoked from."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXERR
case|:
comment|/* error */
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: ERROR\n\ Send an Error packet to the other Kermit."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
case|case
name|XXEXI
case|:
comment|/* exit */
case|case
name|XXQUI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: QUIT (or EXIT)\n\ Exit from the Kermit program, closing all open files and devices."
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
literal|"Syntax: FINISH\n\ Tell the remote Kermit server to shut down without logging out."
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXFOR
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|forhlp
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
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
ifndef|#
directive|ifndef
name|NOSPL
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXGOK
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: GETOK prompt\n\ Print the prompt, make user type 'yes', 'no', or 'ok', and set SUCCESS or\n\ FAILURE accordingly."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXGOTO
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: GOTO label\n\ In a TAKE file or macro, go to the given label.  A label is a word on the\n\ left margin that starts with a colon (:).  Example:\n\n\ :oofa\n\ echo Hello!\n\ goto oofa"
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
case|case
name|XXHAN
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: HANGUP\n\ Hang up the phone or network connection."
argument_list|)
operator|)
return|;
case|case
name|XXHLP
case|:
name|printf
argument_list|(
literal|"%s, Copyright (C) 1985, 1992,"
argument_list|,
name|versio
argument_list|)
expr_stmt|;
return|return
operator|(
name|hmsga
argument_list|(
name|tophlp
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXIF
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|ifhlp
argument_list|)
operator|)
return|;
case|case
name|XXINC
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxinc
argument_list|)
operator|)
return|;
case|case
name|XXINP
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Syntax:  INPUT n text\n\ Example: INPUT 5 Login:\n\n\ Wait up to n seconds for the given text to arrive on the communication line.\n\ For use in script programs with IF FAILURE and IF SUCCESS."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NODIAL
case|case
name|XXRED
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Redial the number given in the most recent DIAL commnd."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NODIAL */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXREI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: REINPUT n string\n\n\ Look for the string in the text that has recently been INPUT, set SUCCESS\n\ or FAILURE accordingly.  Timeout, n, must be specified but is ignored."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXREN
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: RENAME oldname newname\n\n\ Change the name of file 'oldname' to 'newname'."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXLBL
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Introduce a label, like :loop, for use with GOTO in TAKE files or macros.\n\ See GOTO."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
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
ifndef|#
directive|ifndef
name|NOSCRIPT
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
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXMAI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: MAIL filename address\n\n\ Send the file to the remote Kermit, which must be in RECEIVE or SERVER mode,\n\ and request that the remote host deliver the file as electronic mail to the\n\ given address.  Example: MAIL BUG.TXT KERMIT@CUVMA"
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
ifndef|#
directive|ifndef
name|NOMSEND
case|case
name|XXMSE
case|:
return|return
operator|(
name|hmsg
argument_list|(
name|hmssmse
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOMSEND */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXOPE
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|openhlp
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXOUT
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: OUTPUT text\n\n\ Send the text out the currently selected line, as if you had typed it\n\ during CONNECT mode.  The text may contain backslash codes.  Example:\n\n\   OUTPUT help\\13"
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifdef|#
directive|ifdef
name|SUNX25
case|case
name|XXPAD
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxpad
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* SUNX25 */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXPAU
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxpau
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXPRI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: PRINT file [ options ]\n\n\ Print the local file on a local printer with the given options."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
case|case
name|XXPWD
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: PWD\n\ Print the name of the current working directory."
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXREA
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: READ variablename\n\ Read a line from the currently open READ or !READ file into the variable\n\ (see OPEN)."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
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
argument_list|,
name|xxstring
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
operator|(
name|x
operator|=
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
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXRET
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: RETURN [ value ]\n\ Return from a macro.  An optional return value can be given for use with\n\ with \\fexecute(macro), which allows macros to be used like functions."
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
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOSERVER
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
endif|#
directive|endif
comment|/* NOSERVER */
ifndef|#
directive|ifndef
name|NOJC
case|case
name|XXSUS
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SUSPEND or Z\n\ Suspend Kermit.  Continue Kermit with the appropriate system command,\n\ such as fg."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOJC */
case|case
name|XXSET
case|:
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
argument_list|,
name|xxstring
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|==
operator|-
literal|3
condition|)
return|return
operator|(
name|dohset
argument_list|(
name|y
argument_list|)
operator|)
return|;
if|if
condition|(
name|y
operator|<
literal|0
condition|)
return|return
operator|(
name|y
operator|)
return|;
if|if
condition|(
operator|(
name|x
operator|=
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
ifndef|#
directive|ifndef
name|NOPUSH
case|case
name|XXSHE
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxshe
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOPUSH */
ifndef|#
directive|ifndef
name|NOSHOW
case|case
name|XXSHO
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Display current values of various items (SET parameters, variables, etc).\n\ Type SHOW ? for a list of categories."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSHOW */
case|case
name|XXSPA
case|:
ifdef|#
directive|ifdef
name|datageneral
return|return
operator|(
name|hmsg
argument_list|(
literal|"\ Display disk usage in current device, directory,\n\ or return space for a specified device, directory."
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SPACE\n\ Display disk usage in current device and/or directory"
argument_list|)
operator|)
return|;
endif|#
directive|endif
case|case
name|XXSTA
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: STATISTICS\n\ Display statistics about most recent file transfer"
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXSTO
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: STOP\n\ Stop executing the current macro or TAKE file and return immediately\n\ to the C-Kermit prompt."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
case|case
name|XXTAK
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: TAKE filename\n\ Take Kermit commands from the named file.  Kermit command files may\n\ themselves contain TAKE commands, up to a reasonable depth of nesting."
argument_list|)
operator|)
return|;
ifdef|#
directive|ifdef
name|NETCONN
case|case
name|XXTEL
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: TELNET [ host ]\n\ Equivalent to SET HOST host, followed by CONNECT.  If hostname omitted,\n\ previous connection (if any) is resumed."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NETCONN */
ifndef|#
directive|ifndef
name|NOXMIT
case|case
name|XXTRA
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxxmit
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOXMIT */
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXTYP
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: TYPE file\n\ Display a file on the screen.  Pauses if you type Ctrl-S, resumes if you\n\ type Ctrl-Q, returns immediately to C-Kermit prompt if you type Ctrl-C."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXWHI
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|whihlp
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOCSETS
case|case
name|XXXLA
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxxla
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOCSETS */
case|case
name|XXVER
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: VERSION\nDisplays the program version number."
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXWAI
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxwai
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XXWHO
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: WHO [ user ]\nDisplays info about the user."
argument_list|)
operator|)
return|;
case|case
name|XXWRI
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxwri
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XXIFX
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|ifxhlp
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
endif|#
directive|endif
comment|/* NOHELP */
default|default:
if|if
condition|(
operator|(
name|x
operator|=
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
literal|"Help not available - %s\n"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|success
operator|=
literal|0
operator|)
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|NOHELP
end_ifndef

begin_comment
comment|/*  H M S G  --  Get confirmation, then print the given message  */
end_comment

begin_function
name|int
name|hmsg
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
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
literal|"\n%s\n\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|hmsga
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
index|[]
decl_stmt|;
block|{
comment|/* Same function, but for arrays */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|,
name|n
decl_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
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
literal|"\n"
argument_list|)
expr_stmt|;
comment|/* Start off with a blank line */
name|n
operator|=
literal|1
expr_stmt|;
comment|/* Line counter */
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
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|s
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* Print a line. */
name|y
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|k
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|y
condition|;
name|j
operator|++
control|)
comment|/* See how many newlines were */
if|if
condition|(
name|s
index|[
name|i
index|]
index|[
name|j
index|]
operator|==
literal|'\n'
condition|)
name|k
operator|++
expr_stmt|;
comment|/* in the string... */
name|n
operator|+=
name|k
expr_stmt|;
if|if
condition|(
name|n
operator|>
literal|21
condition|)
comment|/* After a screenful, give them */
if|if
condition|(
operator|!
name|askmore
argument_list|()
condition|)
return|return
operator|(
operator|-
literal|9
operator|)
return|;
else|else
name|n
operator|=
literal|0
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|NOXMIT
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hsetxmit
index|[]
init|=
block|{
literal|"Syntax: SET TRANSMIT parameter value\n"
block|,
literal|"Controls the behavior of the TRANSMIT command, used for uploading files"
block|,
literal|"to computers that don't have Kermit programs.  Parameters are:\n"
block|,
literal|"ECHO ON/OFF:     Whether to echo text as it is being transmitted."
block|,
literal|"EOF text:        Text to send after end of file is reached."
block|,
literal|"FILL number:     ASCII value of character to insert into blank lines."
block|,
literal|"LINEFEED ON/OFF: Transmit LF as well as CR at the end of each line."
block|,
literal|"                 Normally, only CR is sent."
block|,
literal|"LOCKING-SHIFT ON/OFF: Whether to use SO/SI for transmitting 8-bit data"
block|,
literal|"                 when PARITY is not NONE."
block|,
literal|"PAUSE number:    How many milliseconds to pause after transmitting each line"
block|,
literal|"                 (text mode), or each character (binary mode)."
block|,
literal|"PROMPT number:   ASCII value of character to look for from host before"
block|,
literal|"                 sending next line, normally LF (10)."
block|,
literal|"Synonym: SET XMIT."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOXMIT */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hsetbkg
index|[]
init|=
block|{
literal|"Syntax: SET BACKGROUND { OFF, ON }\n"
block|,
literal|"SET BACKGROUND OFF forces prompts and messages to appear on your screen"
block|,
literal|"even though Kermit thinks it is running in the background."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hsetbuf
index|[]
init|=
block|{
literal|"Syntax: SET BUFFERS n1 n2\n"
block|,
literal|"Change the overall amount of memory allocated for SEND and RECEIVE packet"
block|,
literal|"buffers, respectively.  Bigger numbers let you have longer packets and more"
block|,
literal|"window slots"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hsetcmd
index|[]
init|=
block|{
literal|"Syntax: SET COMMAND BYTESIZE { 7, 8 }\n"
block|,
literal|"SET COMMAND BYTE 8 allows you to use an 8-bit (international) character set"
block|,
literal|"in the commands you type at the C-Kermit> prompt.  7 is the default."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hsetcar
index|[]
init|=
block|{
literal|"Syntax: SET CARRIER ON, AUTO, or OFF\n"
block|,
literal|"Attempts to control treatment of carrier on the communication device."
block|,
literal|"ON means that carrier is required at all times except during the DIAL"
block|,
literal|"command.  OFF means that carrier is never required.  AUTO (the default)"
block|,
literal|"means that carrier is required only during CONNECT."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hsetat
index|[]
init|=
block|{
literal|"Syntax: SET ATTRIBUTES name ON or OFF\n"
block|,
literal|"Use this command to enable (ON) or disable (OFF) the transmission of"
block|,
literal|"selected file attributes along with each file, and to handle or ignore"
block|,
literal|"selected incoming file attributes, including:\n"
block|,
literal|"  CHARACTER-SET:  The transfer character set for text files"
block|,
literal|"  DATE:           The file's creation date"
block|,
literal|"  DISPOSITION:    Unusual things to do with the file, like MAIL or PRINT"
block|,
literal|"  LENGTH:         The file's length"
block|,
literal|"  SYSTEM-ID:      Machine/Operating system of origin"
block|,
literal|"  TYPE:           The file's type (text or binary)\n"
block|,
literal|"You can also specify ALL to select all of them.  Examples:\n"
block|,
literal|"  SET ATTR DATE OFF\n  SET ATTR SIZE ON\n  SET ATTR ALL OFF"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxxinp
index|[]
init|=
block|{
literal|"Syntax: SET INPUT parameter value\n"
block|,
literal|"The SET INPUT command controls the behavior of the INPUT command:\n"
block|,
literal|"SET INPUT CASE { IGNORE, OBSERVE }"
block|,
literal|"Tells whether alphabetic case is to be significant in string comparisons.\n"
block|,
literal|"SET INPUT DEFAULT-TIMEOUT secs"
block|,
literal|"Establishes default timeout for INPUT commands.  Currently has no effect.\n"
block|,
literal|"SET INPUT ECHO { ON, OFF }"
block|,
literal|"Tells whether to display arriving characters read by INPUT on the screen.\n"
block|,
literal|"SET INPUT TIMEOUT-ACTION { PROCEED, QUIT }"
block|,
literal|"Tells whether to proceed or quit from a script program if an INPUT command"
block|,
literal|"fails.  PROCEED (default) allows use of IF SUCCESS and IF FAILURE commands."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxytak
index|[]
init|=
block|{
literal|"Syntax: SET TAKE parameter value\n"
block|,
literal|"Controls behavior of TAKE command.\n"
block|,
literal|"SET TAKE ECHO { ON, OFF } tells whether commands read from a TAKE file"
block|,
literal|"should be displayed on the screen.\n"
block|,
literal|"SET TAKE ERROR { ON, OFF } tells whether a TAKE command file should be"
block|,
literal|"automatically terminated when a command fails."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxyterm
index|[]
init|=
block|{
literal|"Syntax: SET TERMINAL parameter value\n"
block|,
literal|"SET TERMINAL BYTESIZE 7 or 8, to use 7- or 8-bit terminal characters"
block|,
literal|"between C-Kermit and the remote host during CONNECT.\n"
block|,
literal|"SET TERMINAL CHARACTER-SET<remote-cs> [<local-cs> ] to specify the"
block|,
literal|"character set used by the remote host,<remote-cs>, and the character"
block|,
literal|"set used by C-Kermit locally,<local-cs>.  If you don't specify the"
block|,
literal|"local character set, the current FILE CHARACTER-SET is used.  When you"
block|,
literal|"specify two different character sets, C-Kermit translates between them"
block|,
literal|"during CONNECT.  By default, both character sets are ASCII.\n"
block|,
ifdef|#
directive|ifdef
name|OS2PM
literal|"SET TERMINAL VT100 or TEK4014, to set terminal emulation mode."
block|,
endif|#
directive|endif
comment|/* OS2 */
ifdef|#
directive|ifdef
name|OS2
literal|"SET TERMINAL COLOR<screenpart><foreground><background>, to set"
block|,
literal|"the colors of the terminal emulation screen.<screenpart> may be one"
block|,
literal|"of NORMAL, REVERSE, UNDERLINED, STATUS and HELP.<foreground> and"
block|,
literal|"<background> may be one of BLACK, BLUE, GREEN, CYAN, RED, MAGENTA,"
block|,
literal|"BROWN, LGRAY, DGRAY, LBLUE, LGREEN, LCYAN, LRED, LMAGENTA, YELLOW"
block|,
literal|"or WHITE.  The L prefix for the color names means Light.\n"
block|,
endif|#
directive|endif
comment|/* OS2 */
literal|"SET TERMINAL LOCKING-SHIFT { OFF, ON } tells C-Kermit whether to use"
block|,
literal|"Shift-In/Shift-Out (Ctrl-O and Ctrl-N) to switch between 7-bit and 8-bit"
block|,
literal|"characters during CONNECT.  OFF by default.\n"
block|,
literal|"SET TERMINAL NEWLINE-MODE { OFF, ON } tells whether to send CRLF when you"
block|,
literal|"type CR during CONNECT mode.\n"
block|,
literal|"Type SHOW TERMINAL to see current terminal settings."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NETCONN
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxyhost
index|[]
init|=
block|{
literal|"Syntax:  SET HOST hostname-or-number\n"
block|,
literal|"Select a network host.  Use this command instead of SET LINE."
block|,
literal|"After SET HOST give the host name or number.  TCP/IP Examples:\n"
block|,
literal|"  SET HOST watsun.cc.columbia.edu"
block|,
literal|"  SET HOST 128.59.39.2"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxynet
index|[]
init|=
block|{
literal|"Syntax: SET NETWORK network-type\n"
block|,
ifdef|#
directive|ifdef
name|SUNX25
literal|"Select TCP/IP or X.25 network communication."
block|,
else|#
directive|else
literal|"Select TCP/IP network communication."
block|,
endif|#
directive|endif
comment|/* SUNX25 */
literal|"After SET NETWORK give the type of network to use. Examples:\n"
block|,
literal|"  SET NETWORK tcp/ip"
block|,
ifdef|#
directive|ifdef
name|SUNX25
literal|"  SET NETWORK x.25"
block|,
endif|#
directive|endif
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETCONN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxymacr
index|[]
init|=
block|{
literal|"Syntax: SET MACRO parameter value\n"
block|,
literal|"Controls the behavior of macros.\n"
block|,
literal|"SET MACRO ECHO { ON, OFF } tells whether commands executed from a macro"
block|,
literal|"definition should be displayed on the screen.\n"
block|,
literal|"SET MACRO ERROR { ON, OFF } tells whether a macro should be automatically"
block|,
literal|"terminated upon a command error."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxymodm
index|[]
init|=
block|{
literal|"Syntax: SET MODEM-DIALER name\n"
block|,
literal|"Type of modem for dialing remote connections.  Indicates that modem can"
block|,
literal|"be commanded to dial without Carrier Detect signal from modem, and selects"
block|,
literal|"the appropriate dialing protocol to be used by the DIAL command.  Many modem"
block|,
literal|"models are supported.  Type SET MODEM ? for a list.  DIRECT or NONE means"
block|,
literal|"a direct connection, with no modem at all.  Also see HELP DIAL, HELP CARRIER"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hmxyprm
index|[]
init|=
block|{
literal|"Syntax: SET PROMPT [ text ]\n"
block|,
literal|"Prompt text for this program, normally 'C-Kermit>'.  May contain backslash"
block|,
literal|"codes for special effects.  Surround by { } to preserve leading or trailing"
block|,
literal|"spaces.  If text omitted, prompt reverts to C-Kermit>."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxywind
index|[]
init|=
block|{
literal|"Syntax: SET WINDOW-SIZE number\n"
block|,
literal|"Specify number of window slots for sliding windows, the number of packets"
block|,
literal|"that can be transmitted before pausing for acknowledgement.  The default"
block|,
literal|"is one, the maximum is 31.  Increased window size may result in reduced"
block|,
literal|"maximum packet length.  Use sliding windows for improved efficiency on"
block|,
literal|"connections with long delays.  A full duplex connection is required."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxysr
index|[]
init|=
block|{
literal|"END-OF-PACKET number"
block|,
literal|"ASCII value of control character, normally 13 (carriage return).\n"
block|,
literal|"PACKET-LENGTH number"
block|,
literal|"2000 or less.\n"
block|,
literal|"PADDING number"
block|,
literal|"number of prepacket padding characters, 94 or less (rarely used).\n"
block|,
literal|"PAD-CHARACTER number"
block|,
literal|"ASCII value of control character to use for padding (typically 0).\n"
block|,
literal|"START-OF-PACKET number"
block|,
literal|"ASCII value of control character to mark start of packet (normally 1).\n"
block|,
literal|"TIMEOUT number"
block|,
literal|"Number of seconds to wait for a packet before sending NAK or retransmitting"
block|,
literal|"(94 seconds or less)"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hxyxfer
index|[]
init|=
block|{
literal|"Syntax: SET TRANSFER LOCKING-SHIFT { OFF, ON, FORCED }\n"
block|,
literal|"Tell whether locking-shift protocol should be used during file transfer"
block|,
literal|"to achieve 8-bit transparency on a 7-bit connection.  ON means to request"
block|,
literal|"its use if PARITY is not NONE and to use it if the other Kermit agrees,"
block|,
literal|"OFF means not to use it, FORCED means to use it even if the other Kermit"
block|,
literal|"does not agree."
block|,
ifndef|#
directive|ifndef
name|NOCSETS
literal|"\nSyntax: SET TRANSFER CHARACTER-SET name\n"
block|,
literal|"Select the character set used to represent textual data in Kermit packets."
block|,
literal|"Text characters are translated to/from the FILE CHARACTER-SET."
block|,
literal|"The choices are TRANSPARENT (no translation, the default), ASCII,"
block|,
ifdef|#
directive|ifdef
name|CYRILLIC
ifdef|#
directive|ifdef
name|KANJI
literal|"LATIN1 (ISO Latin Alphabet 1), CYRILLIC-ISO (ISO Latin/Cyrillic),"
block|,
literal|"and JAPANESE-EUC."
block|,
else|#
directive|else
literal|"LATIN1 (ISO Latin Alphabet 1), and CYRILLIC-ISO (ISO Latin/Cyrillic)."
block|,
endif|#
directive|endif
comment|/* KANJI */
else|#
directive|else
comment|/* No CYRILLIC */
ifdef|#
directive|ifdef
name|KANJI
literal|"LATIN1 (ISO Latin Alphabet 1), and JAPANESE-EUC."
block|,
else|#
directive|else
literal|"and LATIN1 (ISO Latin Alphabet 1)."
block|,
endif|#
directive|endif
comment|/* KANJI */
endif|#
directive|endif
comment|/* CYRILLIC */
literal|"Synonym: SET XFER CHARACTER-SET."
block|,
endif|#
directive|endif
comment|/* NOCSETS */
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  D O H S E T  --  Give help for SET command  */
end_comment

begin_function
name|int
name|dohset
parameter_list|(
name|xx
parameter_list|)
name|int
name|xx
decl_stmt|;
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
name|XYATTR
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hsetat
argument_list|)
operator|)
return|;
case|case
name|XYBACK
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hsetbkg
argument_list|)
operator|)
return|;
ifdef|#
directive|ifdef
name|DYNAMIC
case|case
name|XYBUF
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hsetbuf
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* DYNAMIC */
case|case
name|XYCARR
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hsetcar
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XYCASE
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET CASE { ON, OFF }\n\ Tells whether alphabetic case is significant in string comparisons\n\ done by INPUT, IF, and other commands."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
case|case
name|XYCMD
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hsetcmd
argument_list|)
operator|)
return|;
case|case
name|XYIFD
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET INCOMPLETE { DISCARD, KEEP }\n\ Discard or Keep incompletely received files, default is DISCARD."
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XYINPU
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxxinp
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
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
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XYCOUN
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax:  SET COUNT number\n\ Example: SET COUNT 5\n\ Set up a loop counter, for use with IF COUNT."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
case|case
name|XYDFLT
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET DEFAULT directory\n\ Change directory.  Equivalent to CD command."
argument_list|)
operator|)
return|;
case|case
name|XYDELA
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET DELAY number\n\ Number of seconds to wait before sending first packet after SEND command."
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NODIAL
case|case
name|XYDIAL
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hmxydial
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NODIAL */
ifdef|#
directive|ifdef
name|UNIX
case|case
name|XYSUSP
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET SUSPEND { OFF, ON }\n\n\ Disables SUSPEND command, suspend signals, and<esc-char>Z during CONNECT."
argument_list|)
operator|)
return|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NOSCRIPT
case|case
name|XYSCRI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET SCRIPT ECHO { OFF, ON }\n\n\ Disables/Enables echoing of SCRIPT command operation."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSCRIPT */
case|case
name|XYTAKE
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxytak
argument_list|)
operator|)
return|;
case|case
name|XYTERM
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxyterm
argument_list|)
operator|)
return|;
case|case
name|XYDUPL
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET DUPLEX { FULL, HALF }\n\n\ During CONNECT: FULL means remote host echoes, HALF means C-Kermit\n\ does its own echoing."
argument_list|)
operator|)
return|;
case|case
name|XYESC
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET ESCAPE number\n\n\ Decimal ASCII value for escape character during CONNECT, normally 28\n\ (Control-\\).  Type the escape character followed by C to get back to the\n\ C-Kermit prompt."
argument_list|)
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
ifdef|#
directive|ifdef
name|UTEK
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET FLOW value\n\ Type of flow control to be used during file transfer and connect mode.\n\ The choices are XON/XOFF (default), IDTR/OCTS, and NONE."
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET FLOW value\n\ Type of flow control to be used during file transfer.\n\ The choices are XON/XOFF (default) and NONE."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* UTEK */
case|case
name|XYHAND
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hmxyhsh
argument_list|)
operator|)
return|;
ifdef|#
directive|ifdef
name|NETCONN
case|case
name|XYHOST
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxyhost
argument_list|)
operator|)
return|;
case|case
name|XYNET
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxynet
argument_list|)
operator|)
return|;
ifdef|#
directive|ifdef
name|SUNX25
case|case
name|XYX25
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxyx25
argument_list|)
operator|)
return|;
case|case
name|XYPAD
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET PAD name value\n\ Set a PAD X.3 parameter with a desired value."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* SUNX25 */
endif|#
directive|endif
comment|/* NETCONN */
ifndef|#
directive|ifndef
name|NOSETKEY
case|case
name|XYKEY
case|:
comment|/* SET KEY */
return|return
operator|(
name|hmsga
argument_list|(
name|hmhskey
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSETKEY */
ifndef|#
directive|ifndef
name|NOCSETS
case|case
name|XYLANG
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET LANGUAGE name\n\ Selects language-specific translation rules for text-mode file transfers.\n\ Used with SET FILE CHARACTER-SET and SET TRANSFER CHARACTER-SET."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOCSETS */
case|case
name|XYLINE
case|:
name|printf
argument_list|(
literal|"\nSyntax: SET LINE devicename\n\n\ Select communication device to use.  Normally %s.\n"
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
literal|"\ If you SET LINE to other than %s, then Kermit\n"
argument_list|,
name|dftty
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\ will be in 'local' mode; SET LINE alone will reset Kermit to remote mode.\n\ To use the modem to dial out, first SET MODEM-DIALER (e.g., to HAYES), then"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\nSET LINE xxx, next issue the DIAL command, and finally CONNECT.\n"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSPL
case|case
name|XYMACR
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxymacr
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSPL */
case|case
name|XYMODM
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxymodm
argument_list|)
operator|)
return|;
case|case
name|XYPARI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET PARITY name\n\n\ Parity to use during terminal connection and file transfer: EVEN, ODD, MARK,\n\ SPACE, or NONE.  Normally NONE."
argument_list|)
operator|)
return|;
case|case
name|XYPROM
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hmxyprm
argument_list|)
operator|)
return|;
case|case
name|XYQUIE
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET QUIET {ON, OFF}\n\n\ Normally ON.  OFF disables most information messages during interactive\n\ operation."
argument_list|)
operator|)
return|;
case|case
name|XYRETR
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET RETRY number\n\n\ How many times to retransmit a particular packet before giving up."
argument_list|)
operator|)
return|;
ifdef|#
directive|ifdef
name|UNIX
case|case
name|XYSESS
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET SESSION-LOG { BINARY, TEXT }\n\n\ If BINARY, record all CONNECT characters in session log.  If TEXT, strip\n\ out carriage returns."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* UNIX */
case|case
name|XYSPEE
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET SPEED number\n\n\ Communication line speed for external tty line specified in most recent\n\ SET LINE command, in bits per second.  Type SET SPEED ? for a list of\n\ possible speeds."
argument_list|)
operator|)
return|;
case|case
name|XYRECV
case|:
case|case
name|XYSEND
case|:
if|if
condition|(
name|xx
operator|==
name|XYRECV
condition|)
name|puts
argument_list|(
literal|"\nSyntax: SET RECEIVE parameter value\n\n\ Specify parameters for inbound packets:"
argument_list|)
expr_stmt|;
else|else
name|puts
argument_list|(
literal|"\nSyntax: SET SEND parameter value\n\n\ Specify parameters for outbound packets.  This command should be used only\n\ to override the normal negotiated parameters."
argument_list|)
expr_stmt|;
return|return
operator|(
name|hmsga
argument_list|(
name|hxysr
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOSERVER
case|case
name|XYSERV
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hsetsrv
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOSERVER */
ifndef|#
directive|ifndef
name|NOXMIT
case|case
name|XYXMIT
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hsetxmit
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOXMIT */
ifndef|#
directive|ifndef
name|NOCSETS
case|case
name|XYUNCS
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET UNKNOWN-CHAR-SET action\n\n\ DISCARD (default) means reject any arriving files encoded in unknown\n\ character sets.  KEEP means to accept them anyway."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOCSETS */
ifdef|#
directive|ifdef
name|UNIX
case|case
name|XYWILD
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: SET WILDCARD-EXPANSION { KERMIT, SHELL }\n\n\ KERMIT (the default) means C-Kermit expands filename wildcards in SEND\n\ and MSEND commands and incoming GET commands.  SHELL means your shell does \ it."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* UNIX */
case|case
name|XYWIND
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxywind
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOCSETS
case|case
name|XYXFER
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hxyxfer
argument_list|)
operator|)
return|;
endif|#
directive|endif
default|default:
name|printf
argument_list|(
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
end_function

begin_escape
end_escape

begin_comment
comment|/*  D O H R M T  --  Give help about REMOTE command  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hrset
index|[]
init|=
block|{
literal|"Syntax:  REMOTE SET parameter value"
block|,
literal|"Example: REMOTE SET FILE TYPE BINARY\n"
block|,
literal|"Ask the remote Kermit server to set the named parameter to the given value."
block|,
literal|"Equivalent to typing the corresponding SET command directly to the other"
block|,
literal|"Kermit if it were in interactive mode."
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|dohrmt
parameter_list|(
name|xx
parameter_list|)
name|int
name|xx
decl_stmt|;
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
literal|"Syntax: REMOTE CD [ name ]\n\n\ Ask remote Kermit server to change its working directory or device.\n\ If the device or directory name is omitted, restore the default."
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
literal|"Syntax: REMOTE DELETE filespec\n\n\ Ask the remote Kermit server to delete the named file(s)."
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
literal|"Syntax: REMOTE DIRECTORY [ filespec ]\n\n\ Ask the remote Kermit server to provide a directory listing of the named\n\ file(s) or if no file specification is given, of all files in the current\n\ directory."
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
literal|"Syntax: REMOTE HELP\n\n\ Ask the remote Kermit server to list the services it provides."
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
literal|"Syntax: REMOTE HOST command\n\n\ Send a command to the remote host computer in its own command language\n\ through the remote Kermit server."
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XZKER
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: REMOTE KERMIT command\n\n\ Send a command to the remote Kermit server in its own command language."
argument_list|)
operator|)
return|;
case|case
name|XZLGI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: REMOTE LOGIN user password [ account ]\n\n\ Log in to a remote Kermit server that requires you login."
argument_list|)
operator|)
return|;
case|case
name|XZLGO
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: REMOTE LOGOUT\n\n\ Log out from a remote Kermit server to which you have previously logged in."
argument_list|)
operator|)
return|;
case|case
name|XZPRI
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: REMOTE PRINT filespec [ options ]\n\n\ Send the specified file(s) to the remote Kermit and ask it to have the\n\ file printed on the remote system's printer, using any specified options."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
case|case
name|XZSET
case|:
return|return
operator|(
name|hmsga
argument_list|(
name|hrset
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
literal|"Syntax: REMOTE SPACE [ name ]\n\n\ Ask the remote Kermit server to tell you about its disk space on the current\n\ disk or directory, or in the one that you name."
argument_list|)
operator|)
return|;
ifndef|#
directive|ifndef
name|NOFRILLS
case|case
name|XZTYP
case|:
return|return
operator|(
name|hmsg
argument_list|(
literal|"Syntax: REMOTE TYPE file\n\n\ Ask the remote Kermit server to type the named file(s) on your screen."
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
literal|"Syntax: REMOTE WHO [ name ]\n\n\ Ask the remote Kermit server to list who's logged in, or to give information\n\ about the named user."
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* NOFRILLS */
default|default:
if|if
condition|(
operator|(
name|x
operator|=
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
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOHELP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOICP */
end_comment

end_unit

