begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uudefs.h    Miscellaneous definitions for the UUCP package.     Copyright (C) 1991, 1992, 1993, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_if
if|#
directive|if
name|ANSI_C
end_if

begin_comment
comment|/* These structures are used in prototypes but are not defined in this    header file.  */
end_comment

begin_struct_decl
struct_decl|struct
name|uuconf_system
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uuconf_timespan
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The tlog enumeration holds the different types of logging.  */
end_comment

begin_enum
enum|enum
name|tlog
block|{
comment|/* Normal log entry.  */
name|LOG_NORMAL
block|,
comment|/* Error log entry.  */
name|LOG_ERROR
block|,
comment|/* Fatal log entry.  */
name|LOG_FATAL
if|#
directive|if
name|DEBUG
operator|>
literal|1
block|,
comment|/* Debugging log entry.  */
name|LOG_DEBUG
block|,
comment|/* Start debugging log entry.  */
name|LOG_DEBUG_START
block|,
comment|/* Continue debugging log entry.  */
name|LOG_DEBUG_CONTINUE
block|,
comment|/* End debugging log entry.  */
name|LOG_DEBUG_END
endif|#
directive|endif
block|}
enum|;
end_enum

begin_comment
comment|/* The tstatus_type enumeration holds the kinds of status information    we put in the status file.  The order of entries here corresponds    to the order of entries in the azStatus array.  */
end_comment

begin_enum
enum|enum
name|tstatus_type
block|{
comment|/* Conversation complete.  */
name|STATUS_COMPLETE
block|,
comment|/* Port unavailable.  */
name|STATUS_PORT_FAILED
block|,
comment|/* Dial failed.  */
name|STATUS_DIAL_FAILED
block|,
comment|/* Login failed.  */
name|STATUS_LOGIN_FAILED
block|,
comment|/* Handshake failed.  */
name|STATUS_HANDSHAKE_FAILED
block|,
comment|/* Failed after logging in.  */
name|STATUS_FAILED
block|,
comment|/* Talking to remote system.  */
name|STATUS_TALKING
block|,
comment|/* Wrong time to call.  */
name|STATUS_WRONG_TIME
block|,
comment|/* Number of status values.  */
name|STATUS_VALUES
block|}
enum|;
end_enum

begin_comment
comment|/* An array to convert status entries to strings.  If more status entries    are added, this array must be extended.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|azStatus
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The sstatus structure holds the contents of a system status file.  */
end_comment

begin_struct
struct|struct
name|sstatus
block|{
comment|/* Current status of conversation.  */
name|enum
name|tstatus_type
name|ttype
decl_stmt|;
comment|/* Number of failed retries.  */
name|int
name|cretries
decl_stmt|;
comment|/* Time of last call in seconds since epoch (determined by      ixsysdep_time).  */
name|long
name|ilast
decl_stmt|;
comment|/* Number of seconds until a retry is permitted.  */
name|int
name|cwait
decl_stmt|;
comment|/* String in status file.  Only used when reading status file, not      when writing.  May be NULL.  Should be freed with ubuffree.  */
name|char
modifier|*
name|zstring
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* How long we have to wait for the next call, given the number of retries    we have already made.  This should probably be configurable.  */
end_comment

begin_define
define|#
directive|define
name|CRETRY_WAIT
parameter_list|(
name|c
parameter_list|)
value|((c) * 10 * 60)
end_define

begin_comment
comment|/* The scmd structure holds a complete UUCP command.  */
end_comment

begin_struct
struct|struct
name|scmd
block|{
comment|/* Command ('S' for send, 'R' for receive, 'X' for execute, 'E' for      simple execution, 'H' for hangup, 'Y' for hangup confirm, 'N' for      hangup deny).  */
name|char
name|bcmd
decl_stmt|;
comment|/* Grade of the command ('\0' if from remote system).  */
name|char
name|bgrade
decl_stmt|;
comment|/* Sequence handle for fsysdep_did_work.  */
name|pointer
name|pseq
decl_stmt|;
comment|/* File name to transfer from.  */
specifier|const
name|char
modifier|*
name|zfrom
decl_stmt|;
comment|/* File name to transfer to.  */
specifier|const
name|char
modifier|*
name|zto
decl_stmt|;
comment|/* User who requested transfer.  */
specifier|const
name|char
modifier|*
name|zuser
decl_stmt|;
comment|/* Options.  */
specifier|const
name|char
modifier|*
name|zoptions
decl_stmt|;
comment|/* Temporary file name ('S' and 'E').  */
specifier|const
name|char
modifier|*
name|ztemp
decl_stmt|;
comment|/* Mode to give newly created file ('S' and 'E').  */
name|unsigned
name|int
name|imode
decl_stmt|;
comment|/* User to notify on remote system (optional; 'S' and 'E').  */
specifier|const
name|char
modifier|*
name|znotify
decl_stmt|;
comment|/* File size (-1 if not supplied) ('S', 'E' and 'R').  */
name|long
name|cbytes
decl_stmt|;
comment|/* Command to execute ('E').  */
specifier|const
name|char
modifier|*
name|zcmd
decl_stmt|;
comment|/* Position to restart from ('R').  */
name|long
name|ipos
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|DEBUG
operator|>
literal|1
end_if

begin_comment
comment|/* We allow independent control over several different types of    debugging output, using a bit string with individual bits dedicated    to particular debugging types.  */
end_comment

begin_comment
comment|/* The bit string is stored in iDebug.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iDebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug abnormal events.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_ABNORMAL
value|(01)
end_define

begin_comment
comment|/* Debug chat scripts.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_CHAT
value|(02)
end_define

begin_comment
comment|/* Debug initial handshake.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_HANDSHAKE
value|(04)
end_define

begin_comment
comment|/* Debug UUCP protocol.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_UUCP_PROTO
value|(010)
end_define

begin_comment
comment|/* Debug protocols.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_PROTO
value|(020)
end_define

begin_comment
comment|/* Debug port actions.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_PORT
value|(040)
end_define

begin_comment
comment|/* Debug configuration files.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_CONFIG
value|(0100)
end_define

begin_comment
comment|/* Debug spool directory actions.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_SPOOLDIR
value|(0200)
end_define

begin_comment
comment|/* Debug executions.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_EXECUTE
value|(0400)
end_define

begin_comment
comment|/* Debug incoming data.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_INCOMING
value|(01000)
end_define

begin_comment
comment|/* Debug outgoing data.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_OUTGOING
value|(02000)
end_define

begin_comment
comment|/* Maximum possible value for iDebug.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MAX
value|(03777)
end_define

begin_comment
comment|/* Intializer for array of debug names.  The index of the name in the    array is the corresponding bit position in iDebug.  We only check    for prefixes, so these names only need to be long enough to    distinguish each name from every other.  The last entry must be    NULL.  The string "all" is also recognized to turn on all    debugging.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_NAMES
define|\
value|{ "a", "ch", "h", "u", "pr", "po", "co", "s", "e", "i", "o", NULL }
end_define

begin_comment
comment|/* The prefix to use to turn off all debugging.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_NONE
value|"n"
end_define

begin_comment
comment|/* Check whether a particular type of debugging is being done.  */
end_comment

begin_define
define|#
directive|define
name|FDEBUGGING
parameter_list|(
name|i
parameter_list|)
value|((iDebug& (i)) != 0)
end_define

begin_comment
comment|/* These macros are used to output debugging information.  I use    several different macros depending on the number of arguments    because no macro can take a variable number of arguments and I    don't want to use double parentheses.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MESSAGE0
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|)
define|\
value|do { if (FDEBUGGING (i)) ulog (LOG_DEBUG, (z)); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE1
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|)
define|\
value|do { if (FDEBUGGING (i)) ulog (LOG_DEBUG, (z), (a1)); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE2
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|do { if (FDEBUGGING (i)) ulog (LOG_DEBUG, (z), (a1), (a2)); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE3
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|do \     { \       if (FDEBUGGING (i)) \ 	ulog (LOG_DEBUG, (z), (a1), (a2), (a3)); \     } \   while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE4
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
define|\
value|do \     { \       if (FDEBUGGING (i)) \ 	ulog (LOG_DEBUG, (z), (a1), (a2), (a3), (a4)); \     } \   while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG<= 1 */
end_comment

begin_comment
comment|/* If debugging information is not being compiled, provide versions of    the debugging macros which just disappear.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MESSAGE0
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE1
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE2
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE3
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE4
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG<= 1 */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Functions.  */
end_comment

begin_comment
comment|/* Given an unknown system name, return information for an unknown    system.  If unknown systems are not permitted, this returns FALSE.    Otherwise, it translates the name as necessary for the spool    directory, and fills in *qsys.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|funknown_system
name|P
argument_list|(
operator|(
name|pointer
name|puuconf
operator|,
specifier|const
name|char
operator|*
name|zsystem
operator|,
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether a file belongs in the spool directory.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fspool_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See if the current time matches a time span.  If not, return FALSE.    Otherwise, return TRUE and set *pival and *pcretry to the values    from the matching element of the span.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|ftimespan_match
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_timespan
operator|*
name|qspan
operator|,
name|long
operator|*
name|pival
operator|,
name|int
operator|*
name|pcretry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove all occurrences of the local system name followed by an    exclamation point from the start of the argument.  Return the    possibly shortened argument.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zremove_local_sys
name|P
argument_list|(
operator|(
expr|struct
name|uuconf_system
operator|*
name|qlocalsys
operator|,
name|char
operator|*
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine the maximum size that may ever be transferred, given a    timesize span.  If there are any time gaps larger than 1 hour not    described by the timesize span, this returns -1.  Otherwise it    returns the largest size that may be transferred at some time.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|cmax_size_ever
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_timespan
operator|*
name|qtimesize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send mail about a file transfer.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fmail_transfer
name|P
argument_list|(
operator|(
name|boolean
name|fok
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|,
specifier|const
name|char
operator|*
name|zmail
operator|,
specifier|const
name|char
operator|*
name|zwhy
operator|,
specifier|const
name|char
operator|*
name|zfrom
operator|,
specifier|const
name|char
operator|*
name|zfromsys
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|ztosys
operator|,
specifier|const
name|char
operator|*
name|zsaved
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether a file is in one of a list of directories.  The zpubdir    argument is used to pass the directory names to zsysdep_local_file.    If fcheck is FALSE, this does not check accessibility.  Otherwise,    if freadable is TRUE, the user zuser must have read access to the    file and all appropriate directories; if freadable is FALSE zuser    must have write access to the appropriate directories.  The zuser    argument may be NULL, in which case all users must have the    appropriate access (this is used for a remote request).  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fin_directory_list
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
name|char
operator|*
operator|*
name|pzdirs
operator|,
specifier|const
name|char
operator|*
name|zpubdir
operator|,
name|boolean
name|fcheck
operator|,
name|boolean
name|freadable
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a command string.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fparse_cmd
name|P
argument_list|(
operator|(
name|char
operator|*
name|zcmd
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a log entry.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|GNUC_VERSION
value|__GNUC__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GNUC_VERSION
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ANSI_C
operator|&&
name|HAVE_VFPRINTF
end_if

begin_decl_stmt
specifier|extern
name|void
name|ulog
name|P
argument_list|(
operator|(
expr|enum
name|tlog
name|ttype
operator|,
specifier|const
name|char
operator|*
name|zfmt
operator|,
operator|...
operator|)
argument_list|)
if|#
directive|if
name|GNUC_VERSION
operator|>
literal|1
ifdef|#
directive|ifdef
name|__printf0like
name|__printf0like
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
else|#
directive|else
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|ulog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|GNUC_VERSION
end_undef

begin_comment
comment|/* Report an error returned by one of the uuconf routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_uuconf
name|P
argument_list|(
operator|(
expr|enum
name|tlog
name|ttype
operator|,
name|pointer
name|puuconf
operator|,
name|int
name|iuuconf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the function to call if a fatal error occurs.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_fatal_fn
name|P
argument_list|(
operator|(
name|void
argument_list|(
argument|*pfn
argument_list|)
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If ffile is TRUE, send log entries to the log file rather than to    stderr.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_to_file
name|P
argument_list|(
operator|(
name|pointer
name|puuconf
operator|,
name|boolean
name|ffile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the ID number used by the logging functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_id
name|P
argument_list|(
operator|(
name|int
name|iid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the system name used by the logging functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_system
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the system and user name used by the logging functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_user
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zuser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the device name used by the logging functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_device
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdevice
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Close the log file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_close
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make an entry in the statistics file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ustats
name|P
argument_list|(
operator|(
name|boolean
name|fsucceeded
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|,
specifier|const
name|char
operator|*
name|zsystem
operator|,
name|boolean
name|fsent
operator|,
name|long
name|cbytes
operator|,
name|long
name|csecs
operator|,
name|long
name|cmicros
operator|,
name|boolean
name|fcaller
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Close the statistics file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ustats_close
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DEBUG
operator|>
literal|1
end_if

begin_comment
comment|/* A debugging routine to output a buffer.  This outputs zhdr, the    buffer length clen, and the contents of the buffer in quotation    marks.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|udebug_buffer
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zhdr
operator|,
specifier|const
name|char
operator|*
name|zbuf
operator|,
name|size_t
name|clen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A debugging routine to make a readable version of a character.    This takes a buffer at least 5 bytes long, and returns the length    of the string it put into it (not counting the null byte).  */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|cdebug_char
name|P
argument_list|(
operator|(
name|char
operator|*
name|z
operator|,
name|int
name|ichar
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a debugging option string.  This can either be a number or a    comma separated list of debugging names.  This returns a value for    iDebug.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|idebug_parse
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG<= 1 */
end_comment

begin_comment
comment|/* Copy one file to another.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fcopy_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfrom
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
name|boolean
name|fpublic
operator|,
name|boolean
name|fmkdirs
operator|,
name|boolean
name|fsignals
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy an open file to another.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fcopy_open_file
name|P
argument_list|(
operator|(
name|openfile_t
name|efrom
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
name|boolean
name|fpublic
operator|,
name|boolean
name|fmkdirs
operator|,
name|boolean
name|fsignals
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate escape sequences in a buffer, leaving the result in the    same buffer and returning the length.  */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|cescape
name|P
argument_list|(
operator|(
name|char
operator|*
name|zbuf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a buffer to hold a string of a given size.  The buffer should    be freed with ubuffree.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zbufalc
name|P
argument_list|(
operator|(
name|size_t
name|csize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Call zbufalc to allocate a buffer and copy a string into it.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zbufcpy
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free up a buffer returned by zbufalc or zbufcpy.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ubuffree
name|P
argument_list|(
operator|(
name|char
operator|*
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate memory without fail.  */
end_comment

begin_decl_stmt
specifier|extern
name|pointer
name|xmalloc
name|P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Realloc memory without fail.  */
end_comment

begin_decl_stmt
specifier|extern
name|pointer
name|xrealloc
name|P
argument_list|(
operator|(
name|pointer
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free memory (accepts NULL pointers, which some libraries erroneously    do not).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|xfree
name|P
argument_list|(
operator|(
name|pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Global variables.  */
end_comment

begin_comment
comment|/* The name of the program being run.  Set from argv[0].  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zProgram
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When a signal occurs, the signal handlers sets the appropriate    element of the arrays afSignal and afLog_signal to TRUE.  The    afSignal array is used to check whether a signal occurred.  The    afLog_signal array tells ulog to log the signal; ulog will clear    the element after logging it, which means that if a signal comes in    at just the right moment it will not be logged.  It will always be    recorded in afSignal, though.  At the moment we handle 5 signals:    SIGHUP, SIGINT, SIGQUIT, SIGTERM and SIGPIPE (the Unix code also    handles SIGALRM).  If we want to handle more, the afSignal array    must be extended; I see little point to handling any of the other    ANSI C or POSIX signals, as they are either unlikely to occur    (SIGABRT, SIGUSR1) or nearly impossible to handle cleanly (SIGILL,    SIGSEGV).  SIGHUP is only logged if fLog_sighup is TRUE.  */
end_comment

begin_define
define|#
directive|define
name|INDEXSIG_SIGHUP
value|(0)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_SIGINT
value|(1)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_SIGQUIT
value|(2)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_SIGTERM
value|(3)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_SIGPIPE
value|(4)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_COUNT
value|(5)
end_define

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|afSignal
index|[
name|INDEXSIG_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|afLog_signal
index|[
name|INDEXSIG_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fLog_sighup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The names of the signals to use in error messages, as an    initializer for an array.  */
end_comment

begin_define
define|#
directive|define
name|INDEXSIG_NAMES
define|\
value|{ "hangup", "interrupt", "quit", "termination", "SIGPIPE" }
end_define

begin_comment
comment|/* Check to see whether we've received a signal.  It would be nice if    we could use a single variable for this, but we sometimes want to    clear our knowledge of a signal and that would cause race    conditions (clearing a single element of the array is not a race    assuming that we don't care about a particular signal, even if it    occurs after we've examined the array).  */
end_comment

begin_define
define|#
directive|define
name|FGOT_SIGNAL
parameter_list|()
define|\
value|(afSignal[INDEXSIG_SIGHUP] || afSignal[INDEXSIG_SIGINT] \    || afSignal[INDEXSIG_SIGQUIT] || afSignal[INDEXSIG_SIGTERM] \    || afSignal[INDEXSIG_SIGPIPE])
end_define

begin_comment
comment|/* If we get a SIGINT in uucico, we continue the current communication    session but don't start any new ones.  This macros checks for any    signal other than SIGINT, which means we should get out    immediately.  */
end_comment

begin_define
define|#
directive|define
name|FGOT_QUIT_SIGNAL
parameter_list|()
define|\
value|(afSignal[INDEXSIG_SIGHUP] || afSignal[INDEXSIG_SIGQUIT] \    || afSignal[INDEXSIG_SIGTERM] || afSignal[INDEXSIG_SIGPIPE])
end_define

begin_comment
comment|/* Device name to log.  This is set by fconn_open.  It may be NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zLdevice
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If not NULL, ulog calls this function before outputting anything.    This is used to support cu.  */
end_comment

begin_extern
extern|extern void (*pfLstart
end_extern

begin_expr_stmt
unit|)
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* If not NULL, ulog calls this function after outputting everything.    This is used to support cu.  */
end_comment

begin_extern
extern|extern void (*pfLend
end_extern

begin_expr_stmt
unit|)
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

