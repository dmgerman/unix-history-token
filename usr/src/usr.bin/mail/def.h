begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_undef
undef|#
directive|undef
name|isalpha
end_undef

begin_undef
undef|#
directive|undef
name|isdigit
end_undef

begin_comment
comment|/*  * Sccs Id = "@(#)def.h	2.12 %G%";  */
end_comment

begin_comment
comment|/*  * Mail -- a mail program  *  * Commands are:  *	t<message list>		print out these messages  *	r<message list>		reply to messages  *	m<user list>			mail to users (analogous to send)  *	e<message list>		edit messages  *	c [directory]			chdir to dir or home if none  *	x				exit quickly  *	w<message list> file		save messages in file  *	q				quit, save remaining stuff in mbox  *	d<message list>		delete messages  *	u<message list>		undelete messages  *	h				print message headers  *  * Author: Kurt Shoens (UCB) March 25, 1978  */
end_comment

begin_define
define|#
directive|define
name|ESCAPE
value|'~'
end_define

begin_comment
comment|/* Default escape for sending */
end_comment

begin_define
define|#
directive|define
name|NMLSIZE
value|20
end_define

begin_comment
comment|/* max names in a message list */
end_comment

begin_define
define|#
directive|define
name|PATHSIZE
value|100
end_define

begin_comment
comment|/* Size of pathnames throughout */
end_comment

begin_define
define|#
directive|define
name|NAMESIZE
value|20
end_define

begin_comment
comment|/* Max size of user name */
end_comment

begin_define
define|#
directive|define
name|HSHSIZE
value|19
end_define

begin_comment
comment|/* Hash size for aliases and vars */
end_comment

begin_define
define|#
directive|define
name|HDRFIELDS
value|3
end_define

begin_comment
comment|/* Number of header fields */
end_comment

begin_define
define|#
directive|define
name|LINESIZE
value|BUFSIZ
end_define

begin_comment
comment|/* max readable line width */
end_comment

begin_define
define|#
directive|define
name|STRINGSIZE
value|((unsigned) 128)
end_define

begin_comment
comment|/* Dynamic allocation units */
end_comment

begin_define
define|#
directive|define
name|MAXARGC
value|20
end_define

begin_comment
comment|/* Maximum list of raw strings */
end_comment

begin_define
define|#
directive|define
name|NOSTR
value|((char *) 0)
end_define

begin_comment
comment|/* Null string pointer */
end_comment

begin_define
define|#
directive|define
name|MAXEXP
value|25
end_define

begin_comment
comment|/* Maximum expansion of aliases */
end_comment

begin_define
define|#
directive|define
name|equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a,b)==0)
end_define

begin_comment
comment|/* A nice function to string compare */
end_comment

begin_struct
struct|struct
name|message
block|{
name|short
name|m_flag
decl_stmt|;
comment|/* flags, see below */
name|short
name|m_block
decl_stmt|;
comment|/* block number of this message */
name|short
name|m_offset
decl_stmt|;
comment|/* offset in block of message */
name|long
name|m_size
decl_stmt|;
comment|/* Bytes in the message */
name|short
name|m_lines
decl_stmt|;
comment|/* Lines in the message */
block|}
struct|;
end_struct

begin_comment
comment|/*  * flag bits.  */
end_comment

begin_define
define|#
directive|define
name|MUSED
value|(1<<0)
end_define

begin_comment
comment|/* entry is used, but this bit isn't */
end_comment

begin_define
define|#
directive|define
name|MDELETED
value|(1<<1)
end_define

begin_comment
comment|/* entry has been deleted */
end_comment

begin_define
define|#
directive|define
name|MSAVED
value|(1<<2)
end_define

begin_comment
comment|/* entry has been saved */
end_comment

begin_define
define|#
directive|define
name|MTOUCH
value|(1<<3)
end_define

begin_comment
comment|/* entry has been noticed */
end_comment

begin_define
define|#
directive|define
name|MPRESERVE
value|(1<<4)
end_define

begin_comment
comment|/* keep entry in sys mailbox */
end_comment

begin_define
define|#
directive|define
name|MMARK
value|(1<<5)
end_define

begin_comment
comment|/* message is marked! */
end_comment

begin_define
define|#
directive|define
name|MODIFY
value|(1<<6)
end_define

begin_comment
comment|/* message has been modified */
end_comment

begin_define
define|#
directive|define
name|MNEW
value|(1<<7)
end_define

begin_comment
comment|/* message has never been seen */
end_comment

begin_define
define|#
directive|define
name|MREAD
value|(1<<8)
end_define

begin_comment
comment|/* message has been read sometime. */
end_comment

begin_define
define|#
directive|define
name|MSTATUS
value|(1<<9)
end_define

begin_comment
comment|/* message status has changed */
end_comment

begin_define
define|#
directive|define
name|MBOX
value|(1<<10)
end_define

begin_comment
comment|/* Send this to mbox, regardless */
end_comment

begin_comment
comment|/*  * Format of the command description table.  * The actual table is declared and initialized  * in lex.c  */
end_comment

begin_struct
struct|struct
name|cmd
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* Name of command */
name|int
function_decl|(
modifier|*
name|c_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* Implementor of the command */
name|short
name|c_argtype
decl_stmt|;
comment|/* Type of arglist (see below) */
name|short
name|c_msgflag
decl_stmt|;
comment|/* Required flags of messages */
name|short
name|c_msgmask
decl_stmt|;
comment|/* Relevant flags of messages */
block|}
struct|;
end_struct

begin_comment
comment|/* Yechh, can't initialize unions */
end_comment

begin_define
define|#
directive|define
name|c_minargs
value|c_msgflag
end_define

begin_comment
comment|/* Minimum argcount for RAWLIST */
end_comment

begin_define
define|#
directive|define
name|c_maxargs
value|c_msgmask
end_define

begin_comment
comment|/* Max argcount for RAWLIST */
end_comment

begin_comment
comment|/*  * Argument types.  */
end_comment

begin_define
define|#
directive|define
name|MSGLIST
value|0
end_define

begin_comment
comment|/* Message list type */
end_comment

begin_define
define|#
directive|define
name|STRLIST
value|1
end_define

begin_comment
comment|/* A pure string */
end_comment

begin_define
define|#
directive|define
name|RAWLIST
value|2
end_define

begin_comment
comment|/* Shell string list */
end_comment

begin_define
define|#
directive|define
name|NOLIST
value|3
end_define

begin_comment
comment|/* Just plain 0 */
end_comment

begin_define
define|#
directive|define
name|NDMLIST
value|4
end_define

begin_comment
comment|/* Message list, no defaults */
end_comment

begin_define
define|#
directive|define
name|P
value|040
end_define

begin_comment
comment|/* Autoprint dot after command */
end_comment

begin_define
define|#
directive|define
name|I
value|0100
end_define

begin_comment
comment|/* Interactive command bit */
end_comment

begin_define
define|#
directive|define
name|M
value|0200
end_define

begin_comment
comment|/* Legal from send mode bit */
end_comment

begin_define
define|#
directive|define
name|W
value|0400
end_define

begin_comment
comment|/* Illegal when read only bit */
end_comment

begin_define
define|#
directive|define
name|F
value|01000
end_define

begin_comment
comment|/* Is a conditional command */
end_comment

begin_define
define|#
directive|define
name|T
value|02000
end_define

begin_comment
comment|/* Is a transparent command */
end_comment

begin_define
define|#
directive|define
name|R
value|04000
end_define

begin_comment
comment|/* Cannot be called from collect */
end_comment

begin_comment
comment|/*  * Oft-used mask values  */
end_comment

begin_define
define|#
directive|define
name|MMNORM
value|(MDELETED|MSAVED)
end_define

begin_comment
comment|/* Look at both save and delete bits */
end_comment

begin_define
define|#
directive|define
name|MMNDEL
value|MDELETED
end_define

begin_comment
comment|/* Look only at deleted bit */
end_comment

begin_comment
comment|/*  * Structure used to return a break down of a head  * line (hats off to Bill Joy!)  */
end_comment

begin_struct
struct|struct
name|headline
block|{
name|char
modifier|*
name|l_from
decl_stmt|;
comment|/* The name of the sender */
name|char
modifier|*
name|l_tty
decl_stmt|;
comment|/* His tty string (if any) */
name|char
modifier|*
name|l_date
decl_stmt|;
comment|/* The entire date string */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GTO
value|1
end_define

begin_comment
comment|/* Grab To: line */
end_comment

begin_define
define|#
directive|define
name|GSUBJECT
value|2
end_define

begin_comment
comment|/* Likewise, Subject: line */
end_comment

begin_define
define|#
directive|define
name|GCC
value|4
end_define

begin_comment
comment|/* And the Cc: line */
end_comment

begin_define
define|#
directive|define
name|GBCC
value|8
end_define

begin_comment
comment|/* And also the Bcc: line */
end_comment

begin_define
define|#
directive|define
name|GMASK
value|(GTO|GSUBJECT|GCC|GBCC)
end_define

begin_comment
comment|/* Mask of places from whence */
end_comment

begin_define
define|#
directive|define
name|GNL
value|16
end_define

begin_comment
comment|/* Print blank line after */
end_comment

begin_define
define|#
directive|define
name|GDEL
value|32
end_define

begin_comment
comment|/* Entity removed from list */
end_comment

begin_define
define|#
directive|define
name|GCOMMA
value|64
end_define

begin_comment
comment|/* detract puts in commas */
end_comment

begin_comment
comment|/*  * Structure used to pass about the current  * state of the user-typed message header.  */
end_comment

begin_struct
struct|struct
name|header
block|{
name|char
modifier|*
name|h_to
decl_stmt|;
comment|/* Dynamic "To:" string */
name|char
modifier|*
name|h_subject
decl_stmt|;
comment|/* Subject string */
name|char
modifier|*
name|h_cc
decl_stmt|;
comment|/* Carbon copies string */
name|char
modifier|*
name|h_bcc
decl_stmt|;
comment|/* Blind carbon copies */
name|int
name|h_seq
decl_stmt|;
comment|/* Sequence for optimization */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of namelist nodes used in processing  * the recipients of mail and aliases and all that  * kind of stuff.  */
end_comment

begin_struct
struct|struct
name|name
block|{
name|struct
name|name
modifier|*
name|n_flink
decl_stmt|;
comment|/* Forward link in list. */
name|struct
name|name
modifier|*
name|n_blink
decl_stmt|;
comment|/* Backward list link */
name|short
name|n_type
decl_stmt|;
comment|/* From which list it came */
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* This fella's name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a variable node.  All variables are  * kept on a singly-linked list of these, rooted by  * "variables"  */
end_comment

begin_struct
struct|struct
name|var
block|{
name|struct
name|var
modifier|*
name|v_link
decl_stmt|;
comment|/* Forward link to next variable */
name|char
modifier|*
name|v_name
decl_stmt|;
comment|/* The variable's name */
name|char
modifier|*
name|v_value
decl_stmt|;
comment|/* And it's current value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|group
block|{
name|struct
name|group
modifier|*
name|ge_link
decl_stmt|;
comment|/* Next person in this group */
name|char
modifier|*
name|ge_name
decl_stmt|;
comment|/* This person's user name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|grouphead
block|{
name|struct
name|grouphead
modifier|*
name|g_link
decl_stmt|;
comment|/* Next grouphead in list */
name|char
modifier|*
name|g_name
decl_stmt|;
comment|/* Name of this group */
name|struct
name|group
modifier|*
name|g_list
decl_stmt|;
comment|/* Users in group. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NIL
value|((struct name *) 0)
end_define

begin_comment
comment|/* The nil pointer for namelists */
end_comment

begin_define
define|#
directive|define
name|NONE
value|((struct cmd *) 0)
end_define

begin_comment
comment|/* The nil pointer to command tab */
end_comment

begin_define
define|#
directive|define
name|NOVAR
value|((struct var *) 0)
end_define

begin_comment
comment|/* The nil pointer to variables */
end_comment

begin_define
define|#
directive|define
name|NOGRP
value|((struct grouphead *) 0)
end_define

begin_comment
comment|/* The nil grouphead pointer */
end_comment

begin_define
define|#
directive|define
name|NOGE
value|((struct group *) 0)
end_define

begin_comment
comment|/* The nil group pointer */
end_comment

begin_comment
comment|/*  * Structure of the hash table of ignored header fields  */
end_comment

begin_struct
struct|struct
name|ignore
block|{
name|struct
name|ignore
modifier|*
name|i_link
decl_stmt|;
comment|/* Next ignored field in bucket */
name|char
modifier|*
name|i_field
decl_stmt|;
comment|/* This ignored field */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Token values returned by the scanner used for argument lists.  * Also, sizes of scanner-related things.  */
end_comment

begin_define
define|#
directive|define
name|TEOL
value|0
end_define

begin_comment
comment|/* End of the command line */
end_comment

begin_define
define|#
directive|define
name|TNUMBER
value|1
end_define

begin_comment
comment|/* A message number */
end_comment

begin_define
define|#
directive|define
name|TDASH
value|2
end_define

begin_comment
comment|/* A simple dash */
end_comment

begin_define
define|#
directive|define
name|TSTRING
value|3
end_define

begin_comment
comment|/* A string (possibly containing -) */
end_comment

begin_define
define|#
directive|define
name|TDOT
value|4
end_define

begin_comment
comment|/* A "." */
end_comment

begin_define
define|#
directive|define
name|TUP
value|5
end_define

begin_comment
comment|/* An "^" */
end_comment

begin_define
define|#
directive|define
name|TDOLLAR
value|6
end_define

begin_comment
comment|/* A "$" */
end_comment

begin_define
define|#
directive|define
name|TSTAR
value|7
end_define

begin_comment
comment|/* A "*" */
end_comment

begin_define
define|#
directive|define
name|TOPEN
value|8
end_define

begin_comment
comment|/* An '(' */
end_comment

begin_define
define|#
directive|define
name|TCLOSE
value|9
end_define

begin_comment
comment|/* A ')' */
end_comment

begin_define
define|#
directive|define
name|TPLUS
value|10
end_define

begin_comment
comment|/* A '+' */
end_comment

begin_define
define|#
directive|define
name|REGDEP
value|2
end_define

begin_comment
comment|/* Maximum regret depth. */
end_comment

begin_define
define|#
directive|define
name|STRINGLEN
value|64
end_define

begin_comment
comment|/* Maximum length of string token */
end_comment

begin_comment
comment|/*  * Constants for conditional commands.  These describe whether  * we should be executing stuff or not.  */
end_comment

begin_define
define|#
directive|define
name|CANY
value|0
end_define

begin_comment
comment|/* Execute in send or receive mode */
end_comment

begin_define
define|#
directive|define
name|CRCV
value|1
end_define

begin_comment
comment|/* Execute in receive mode only */
end_comment

begin_define
define|#
directive|define
name|CSEND
value|2
end_define

begin_comment
comment|/* Execute in send mode only */
end_comment

begin_comment
comment|/*  * Kludges to handle the change from setexit / reset to setjmp / longjmp  */
end_comment

begin_define
define|#
directive|define
name|setexit
parameter_list|()
value|setjmp(srbuf)
end_define

begin_define
define|#
directive|define
name|reset
parameter_list|(
name|x
parameter_list|)
value|longjmp(srbuf, x)
end_define

begin_comment
comment|/*  * VM/UNIX has a vfork system call which is faster than forking.  If we  * don't have it, fork(2) will do . . .  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_define
define|#
directive|define
name|vfork
parameter_list|()
value|fork()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGRETRO
end_ifndef

begin_define
define|#
directive|define
name|sigchild
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 4.2bsd signal interface help...  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|sigset
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|signal(s, a)
end_define

begin_define
define|#
directive|define
name|mask
parameter_list|(
name|s
parameter_list|)
value|(1<< ((s) - 1))
end_define

begin_define
define|#
directive|define
name|sigsys
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|signal(s, a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Truncate a file to the last character written. This is  * useful just before closing an old file that was opened  * for read/write.  */
end_comment

begin_define
define|#
directive|define
name|trunc
parameter_list|(
name|stream
parameter_list|)
value|ftruncate(fileno(stream), (long) ftell(stream))
end_define

begin_comment
comment|/*  * Forward declarations of routine types to keep lint and cc happy.  */
end_comment

begin_function_decl
name|FILE
modifier|*
name|Fdopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|collect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|infix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|mesedit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|mespipe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|setinput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|unpack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|addto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|arpafix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|copyin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|detract
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|expand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|hfield
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|name1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|nameof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|nextword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getfilename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|hcontents
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|netmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|netname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|readtty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|reedit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|revarpa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rpair
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|salloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|skin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|snarf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|yankword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|fsize
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_expr_stmt
name|int
argument_list|(
operator|*
name|sigset
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|cmd
modifier|*
name|lex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|grouphead
modifier|*
name|findgroup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|delname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|elide
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|extract
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|gexpand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|map
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|outof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|put
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|usermap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|name
modifier|*
name|verify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|var
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|transmit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|icequal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmpdomain
parameter_list|()
function_decl|;
end_function_decl

end_unit

