begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uuconf.h    Header file for UUCP configuration routines.     Copyright (C) 1992, 1993, 1994, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The use of an object file which uses material from this header    file, and from no other portion of the uuconf library, is    unrestricted, as described in paragraph 4 of section 5 of version 2    of the GNU Library General Public License (this sentence is merely    informative, and does not modify the License in any way).     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UUCONF_H
end_ifndef

begin_define
define|#
directive|define
name|UUCONF_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* The macro UUCONF_ANSI_C may be used to override __STDC__.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UUCONF_ANSI_C
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|UUCONF_ANSI_C
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__STDC__) */
end_comment

begin_define
define|#
directive|define
name|UUCONF_ANSI_C
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__STDC__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (UUCONF_ANSI_C) */
end_comment

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_define
define|#
directive|define
name|UUCONF_CONST
value|const
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|UUCONF_POINTER
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_typedef
typedef|typedef
name|size_t
name|UUCONF_SIZE_T
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UUCONF_CONST
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|UUCONF_POINTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UUCONF_SIZE_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* The field names of each of the following structures begin with    "uuconf_".  This is to avoid any conflicts with user defined    macros.  The first character following the "uuconf_" string    indicates the type of the field.     z -- a string (char *)    c -- a count (normally int)    i -- an integer value (normally int)    f -- a boolean value (normally int)    b -- a single character value (char or int)    t -- an enum (enum XX)    s -- a structure (struct XX)    u -- a union (union XX)    q -- a pointer to a structure (struct XX *)    p -- a pointer to something other than a string    */
end_comment

begin_escape
end_escape

begin_comment
comment|/* The information which is kept for a chat script.  */
end_comment

begin_struct
struct|struct
name|uuconf_chat
block|{
comment|/* The script itself.  This is a NULL terminated list of expect/send      pairs.  The first string is an expect string.  A string starting      with a '-' indicates subsend string; the following strings which      start with '-' are subexpect/subsend strings.  This field may be      NULL, in which case there is no chat script (but pzprogram may      hold a program to run).  */
name|char
modifier|*
modifier|*
name|uuconf_pzchat
decl_stmt|;
comment|/* The chat program to run.  This is a NULL terminated list of      arguments; element 0 if the program.  May be NULL, in which case      there is no program.  */
name|char
modifier|*
modifier|*
name|uuconf_pzprogram
decl_stmt|;
comment|/* The timeout in seconds to use for expect strings in the chat      script.  */
name|int
name|uuconf_ctimeout
decl_stmt|;
comment|/* The NULL terminated list of failure strings.  If any of these      strings appear, the chat script is aborted.  May be NULL, in      which case there are no failure strings.  */
name|char
modifier|*
modifier|*
name|uuconf_pzfail
decl_stmt|;
comment|/* Non-zero if incoming characters should be stripped to seven bits      (by anding with 0x7f).  */
name|int
name|uuconf_fstrip
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* The information which is kept for a time specification.  This is a    linked list of structures.  Each element of the list represents a    span of time, giving a starting time and an ending time.  The time    only depends on the day of the week, not on the day of the month or    of the year.  The time is only specified down to the minute, not    down to the second or below.  The list is sorted by starting time.     The starting and ending time are expressed in minutes since the    beginning of the week, which is considered to be 12 midnight on    Sunday.  Thus 60 is 1 am on Sunday, 1440 (== 60 * 24) is 12    midnight on Monday, and the largest possible value is 10080 (== 60    * 24 * 7) which is 12 midnight on the following Sunday.     Each span of time has a value associated with it.  This is the    lowest grade or the largest file size that may be transferred    during that time, depending on the source of the time span.  When    time specifications overlap, the value used for the overlap is the    higher grade or the smaller file size.  Thus specifying    ``call-timegrade z Any'' and ``call-timegrade Z Mo'' means that    only grade Z or higher may be sent on Monday, since Z is the higer    grade of the overlapping spans.  The final array wil have no    overlaps.     Each span also has a retry time associated with it.  This permits    different retry times to be used at different times of day.  The    retry time is only relevant if the span came from a ``time'' or    ``timegrade'' command for a system.  */
end_comment

begin_struct
struct|struct
name|uuconf_timespan
block|{
comment|/* Next element in list.  */
name|struct
name|uuconf_timespan
modifier|*
name|uuconf_qnext
decl_stmt|;
comment|/* Starting minute (-1 at the end of the array).  */
name|int
name|uuconf_istart
decl_stmt|;
comment|/* Ending minute.  */
name|int
name|uuconf_iend
decl_stmt|;
comment|/* Value for this span (lowest grade or largest file that may be      transferred at this time).  */
name|long
name|uuconf_ival
decl_stmt|;
comment|/* Retry time.  */
name|int
name|uuconf_cretry
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* The information which is kept for protocol parameters.  Protocol    parameter information is stored as an array of the following    structures.  */
end_comment

begin_struct
struct|struct
name|uuconf_proto_param
block|{
comment|/* The name of the protocol to which this entry applies.  This is      '\0' for the last element of the array.  */
name|int
name|uuconf_bproto
decl_stmt|;
comment|/* Specific entries for this protocol.  This points to an array      ending in an element with a uuconf_cargs field of 0.  */
name|struct
name|uuconf_proto_param_entry
modifier|*
name|uuconf_qentries
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Each particular protocol parameter entry is one of the following    structures.  */
end_comment

begin_struct
struct|struct
name|uuconf_proto_param_entry
block|{
comment|/* The number of arguments to the ``protocol-parameter'' command      (not counting ``protocol-parameter'' itself).  This is 0 for the      last element of the array.  */
name|int
name|uuconf_cargs
decl_stmt|;
comment|/* The actual arguments to the ``protocol-parameter'' command; this      is an array with cargs entries.  */
name|char
modifier|*
modifier|*
name|uuconf_pzargs
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* The information which is kept for a system.  The zname and zalias    fields will be the same for all alternates.  Every other fields is    specific to the particular alternate in which it appears (although    most will be the same for all alternates).  */
end_comment

begin_struct
struct|struct
name|uuconf_system
block|{
comment|/* The name of the system.  */
name|char
modifier|*
name|uuconf_zname
decl_stmt|;
comment|/* A list of aliases for the system.  This is a NULL terminated list      of strings.  May be NULL, in which case there are no aliases.  */
name|char
modifier|*
modifier|*
name|uuconf_pzalias
decl_stmt|;
comment|/* A linked list of alternate call in or call out information.  Each      alternative way to call this system occupies an element of this      list.  May be NULL, in which case there are no alternates.  */
name|struct
name|uuconf_system
modifier|*
name|uuconf_qalternate
decl_stmt|;
comment|/* The name for this particular alternate.  May be NULL, in which      case this alternate does not have a name.  */
name|char
modifier|*
name|uuconf_zalternate
decl_stmt|;
comment|/* If non-zero, this alternate may be used for calling out.  */
name|int
name|uuconf_fcall
decl_stmt|;
comment|/* If non-zero, this alternate may be used for accepting a call.  */
name|int
name|uuconf_fcalled
decl_stmt|;
comment|/* The times at which this system may be called.  The ival field of      each uuconf_timespan structure is the lowest grade which may be      transferred at that time.  The cretry field is the number of      minutes to wait before retrying the call, or 0 if it was not      specified.  May be NULL, in which case the system may never be      called.  */
name|struct
name|uuconf_timespan
modifier|*
name|uuconf_qtimegrade
decl_stmt|;
comment|/* The times at which to request a particular grade of the system      when calling it, and the grades to request.  The ival field of      each uuconf_timespan structure is the lowest grade which the      other system should transfer at that time.  May be NULL, in which      case there are no grade restrictions.  */
name|struct
name|uuconf_timespan
modifier|*
name|uuconf_qcalltimegrade
decl_stmt|;
comment|/* The times at which to allow a particular grade of work to be      transferred to the system, when it calls in.  The ival field of      each uuconf_timespan structure is the lowest grade which should      be transferred at that time.  May be NULL, in which case there      are no grade restrictions.  */
name|struct
name|uuconf_timespan
modifier|*
name|uuconf_qcalledtimegrade
decl_stmt|;
comment|/* The maximum number of times to retry calling this system.  If      this is 0, there is no limit.  */
name|int
name|uuconf_cmax_retries
decl_stmt|;
comment|/* The number of minutes to wait between successful calls to a      system.  */
name|int
name|uuconf_csuccess_wait
decl_stmt|;
comment|/* The size restrictions by time for local requests during a locally      placed call.  The ival field of each uuconf_timespan structure is      the size in bytes of the largest file which may be transferred at      that time.  May be NULL, in which case there are no size      restrictions.  */
name|struct
name|uuconf_timespan
modifier|*
name|uuconf_qcall_local_size
decl_stmt|;
comment|/* The size restrictions by time for remote requests during a      locally placed call.  May be NULL.  */
name|struct
name|uuconf_timespan
modifier|*
name|uuconf_qcall_remote_size
decl_stmt|;
comment|/* The size restrictions by time for local requests during a      remotely placed call.  May be NULL.  */
name|struct
name|uuconf_timespan
modifier|*
name|uuconf_qcalled_local_size
decl_stmt|;
comment|/* The size restrictions by time for remote requests during a      remotely placed call.  May be NULL.  */
name|struct
name|uuconf_timespan
modifier|*
name|uuconf_qcalled_remote_size
decl_stmt|;
comment|/* Baud rate, or speed.  Zero means any baud rate.  If ihighbaud is      non-zero, this is the low baud rate of a range.  */
name|long
name|uuconf_ibaud
decl_stmt|;
comment|/* If non-zero, ibaud is the low baud rate of a range and ihighbaud      is the high baud rate.  */
name|long
name|uuconf_ihighbaud
decl_stmt|;
comment|/* Port name to use.  May be NULL.  If an HDB configuration file      contains a modem class (alphabetic characters preceeding the baud      rate), the class is appended to the port name.  */
name|char
modifier|*
name|uuconf_zport
decl_stmt|;
comment|/* Specific port information, if the system entry includes port      information.  May be NULL.  */
name|struct
name|uuconf_port
modifier|*
name|uuconf_qport
decl_stmt|;
comment|/* Phone number to call, or address to use for a TCP connection.      May be NULL, in which case a dialer script may not use \D or \T      for this system, and a TCP port will use the system name.  */
name|char
modifier|*
name|uuconf_zphone
decl_stmt|;
comment|/* Chat script to use when logging in to the system.  */
name|struct
name|uuconf_chat
name|uuconf_schat
decl_stmt|;
comment|/* Login name to use for \L in the login chat script.  This should      normally be accessed via uuconf_callout.  If it is "*",      uuconf_callout will look it up in the call out file.  This may be      NULL, in which case the login script may not use \L.  */
name|char
modifier|*
name|uuconf_zcall_login
decl_stmt|;
comment|/* Password to use for \P in the login chat script.  This should      normally be accessed via uuconf_callout.  If it is "*",      uuconf_callout will look it up in the call out file.  This may be      NULL, in which case the login script may not use \P.  */
name|char
modifier|*
name|uuconf_zcall_password
decl_stmt|;
comment|/* The login name this system must use when calling in.  This may be      different for different alternates.  This should only be examined      if uuconf_fcalled is TRUE.  If this is NULL or "ANY" then      uuconf_validate must be called to make sure that whatever login      name was used is permitted for this machine.  */
name|char
modifier|*
name|uuconf_zcalled_login
decl_stmt|;
comment|/* If non-zero, then when this system calls in the call should not      be allowed to proceed and the system should be called back.  */
name|int
name|uuconf_fcallback
decl_stmt|;
comment|/* If non-zero, then conversation sequence numbers should be used      with this system.  */
name|int
name|uuconf_fsequence
decl_stmt|;
comment|/* A list of protocols to use with this system.  Each protocol has a      single character name.  May be NULL, in which case any known      protocol may be used.  */
name|char
modifier|*
name|uuconf_zprotocols
decl_stmt|;
comment|/* Array of protocol parameters.  Ends in an entry with a      uuconf_bproto field of '\0'.  May be NULL.  */
name|struct
name|uuconf_proto_param
modifier|*
name|uuconf_qproto_params
decl_stmt|;
comment|/* Chat script to run when called by this system.  */
name|struct
name|uuconf_chat
name|uuconf_scalled_chat
decl_stmt|;
comment|/* Debugging level to set during a conversation.  May be NULL.  */
name|char
modifier|*
name|uuconf_zdebug
decl_stmt|;
comment|/* Maximum remote debugging level this system may request.  May be      NULL.  */
name|char
modifier|*
name|uuconf_zmax_remote_debug
decl_stmt|;
comment|/* Non-zero if the remote system may request us to send files from      the local system to the remote.  */
name|int
name|uuconf_fsend_request
decl_stmt|;
comment|/* Non-zero if the remote system may request us to receive files      from the remote system to the local.  */
name|int
name|uuconf_frec_request
decl_stmt|;
comment|/* Non-zero if local requests are permitted when calling this      system.  */
name|int
name|uuconf_fcall_transfer
decl_stmt|;
comment|/* Non-zero if local requests are permitted when this system calls      in.  */
name|int
name|uuconf_fcalled_transfer
decl_stmt|;
comment|/* NULL terminated list of directories from which files may be sent      by local request.  */
name|char
modifier|*
modifier|*
name|uuconf_pzlocal_send
decl_stmt|;
comment|/* NULL terminated list of directories from which files may be sent      by remote request.  */
name|char
modifier|*
modifier|*
name|uuconf_pzremote_send
decl_stmt|;
comment|/* NULL terminated list of directories into which files may be      received by local request.  */
name|char
modifier|*
modifier|*
name|uuconf_pzlocal_receive
decl_stmt|;
comment|/* NULL terminated list of directories into which files may be      received by remote request.  */
name|char
modifier|*
modifier|*
name|uuconf_pzremote_receive
decl_stmt|;
comment|/* Path to use for command execution.  This is a NULL terminated      list of directories.  */
name|char
modifier|*
modifier|*
name|uuconf_pzpath
decl_stmt|;
comment|/* NULL terminated List of commands that may be executed.  */
name|char
modifier|*
modifier|*
name|uuconf_pzcmds
decl_stmt|;
comment|/* Amount of free space to leave when accepting a file from this      system, in bytes.  */
name|long
name|uuconf_cfree_space
decl_stmt|;
comment|/* NULL terminated list of systems that this system may forward      from.  May be NULL if there are no systems from which files may      be forwarded.  The list may include "ANY".  */
name|char
modifier|*
modifier|*
name|uuconf_pzforward_from
decl_stmt|;
comment|/* NULL terminated list of systems that this system may forward to.      May be NULL if there are no systems to which files may be      forwarded.  The list may include "ANY".  */
name|char
modifier|*
modifier|*
name|uuconf_pzforward_to
decl_stmt|;
comment|/* The public directory to use for this sytem.  */
specifier|const
name|char
modifier|*
name|uuconf_zpubdir
decl_stmt|;
comment|/* The local name to use for this remote system.  May be NULL if the      usual local name should be used.  */
name|char
modifier|*
name|uuconf_zlocalname
decl_stmt|;
comment|/* Memory allocation block for the system.  */
name|UUCONF_POINTER
name|uuconf_palloc
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Types of ports.  */
end_comment

begin_enum
enum|enum
name|uuconf_porttype
block|{
comment|/* Unknown port type.  A port of this type should never be returned      by the uuconf functions.  */
name|UUCONF_PORTTYPE_UNKNOWN
block|,
comment|/* Read from standard input and write to standard output.  Not      normally used.  */
name|UUCONF_PORTTYPE_STDIN
block|,
comment|/* A modem port.  */
name|UUCONF_PORTTYPE_MODEM
block|,
comment|/* A direct connect port.  */
name|UUCONF_PORTTYPE_DIRECT
block|,
comment|/* A TCP port.  Not supported on all systems.  */
name|UUCONF_PORTTYPE_TCP
block|,
comment|/* A TLI port.  Not supported on all systems.  */
name|UUCONF_PORTTYPE_TLI
block|,
comment|/* A pipe port.  Not supported on all systems.  */
name|UUCONF_PORTTYPE_PIPE
block|}
enum|;
end_enum

begin_comment
comment|/* Additional information for a stdin port (there is none).  */
end_comment

begin_struct
struct|struct
name|uuconf_stdin_port
block|{
name|int
name|uuconf_idummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional information for a modem port.  */
end_comment

begin_struct
struct|struct
name|uuconf_modem_port
block|{
comment|/* The device name.  May be NULL, in which case the port name is      used instead.  */
name|char
modifier|*
name|uuconf_zdevice
decl_stmt|;
comment|/* The device name to send the dialer chat script to.  May be NULL,      in which case the chat script is sent to the usual device.  */
name|char
modifier|*
name|uuconf_zdial_device
decl_stmt|;
comment|/* The default baud rate (speed).  If zero, there is no default.  */
name|long
name|uuconf_ibaud
decl_stmt|;
comment|/* The low baud rate, if a range is used.  If zero, a range is not      used and ihighbaud should be ignored.  */
name|long
name|uuconf_ilowbaud
decl_stmt|;
comment|/* The high baud rate, if ilowbaud is non-zero.  */
name|long
name|uuconf_ihighbaud
decl_stmt|;
comment|/* Non-zero if the port supports carrier detect.  */
name|int
name|uuconf_fcarrier
decl_stmt|;
comment|/* Non-zero if the port supports hardware flow control.  */
name|int
name|uuconf_fhardflow
decl_stmt|;
comment|/* A NULL terminated sequence of dialer/token pairs (element 0 is a      dialer name, element 1 is a token, etc.)  May be NULL, in which      case qdialer should not be NULL.  */
name|char
modifier|*
modifier|*
name|uuconf_pzdialer
decl_stmt|;
comment|/* Specific dialer information.  Only used if pzdialer is NULL.  */
name|struct
name|uuconf_dialer
modifier|*
name|uuconf_qdialer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional information for a direct connect port.  */
end_comment

begin_struct
struct|struct
name|uuconf_direct_port
block|{
comment|/* The device name.  May be NULL, in which case the port name is      used instead.  */
name|char
modifier|*
name|uuconf_zdevice
decl_stmt|;
comment|/* The baud rate (speed).  */
name|long
name|uuconf_ibaud
decl_stmt|;
comment|/* Non-zero if the port uses carrier detect.  */
name|int
name|uuconf_fcarrier
decl_stmt|;
comment|/* Non-zero if the port supports hardware flow control.  */
name|int
name|uuconf_fhardflow
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional information for a TCP port.  */
end_comment

begin_struct
struct|struct
name|uuconf_tcp_port
block|{
comment|/* The TCP port number to use.  May be a name or a number.  May be      NULL, in which case "uucp" is looked up using getservbyname.  */
name|char
modifier|*
name|uuconf_zport
decl_stmt|;
comment|/* Address family to use for a TCP connection.  */
name|int
name|uuconf_zfamily
decl_stmt|;
comment|/* A NULL terminated sequence of dialer/token pairs (element 0 is a      dialer name, element 1 is a token, etc.)  May be NULL.  */
name|char
modifier|*
modifier|*
name|uuconf_pzdialer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional information for a TLI port.  */
end_comment

begin_struct
struct|struct
name|uuconf_tli_port
block|{
comment|/* Device name to open.  May be NULL, in which case the port name is      used.  */
name|char
modifier|*
name|uuconf_zdevice
decl_stmt|;
comment|/* Whether this port should be turned into a stream, permitting the      read and write calls instead of the t_rcv and t_send calls.  */
name|int
name|uuconf_fstream
decl_stmt|;
comment|/* A NULL terminated list of modules to push after making the      connection.  May be NULL, in which case if fstream is non-zero,      then "tirdwr" is pushed onto the stream, and otherwise nothing is      pushed.  */
name|char
modifier|*
modifier|*
name|uuconf_pzpush
decl_stmt|;
comment|/* A NULL terminated sequence of dialer/token pairs (element 0 is a      dialer name, element 1 is a token, etc.)  May be NULL.  If      element 0 is TLI or TLIS, element 1 is used as the address to      connect to; otherwise uuconf_zphone from the system information      is used.  */
name|char
modifier|*
modifier|*
name|uuconf_pzdialer
decl_stmt|;
comment|/* Address to use when operating as a server.  This may contain      escape sequences.  */
name|char
modifier|*
name|uuconf_zservaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional information for a pipe port.  */
end_comment

begin_struct
struct|struct
name|uuconf_pipe_port
block|{
comment|/* The command and its arguments.  */
name|char
modifier|*
modifier|*
name|uuconf_pzcmd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information kept for a port.  */
end_comment

begin_struct
struct|struct
name|uuconf_port
block|{
comment|/* The name of the port.  */
name|char
modifier|*
name|uuconf_zname
decl_stmt|;
comment|/* The type of the port.  */
name|enum
name|uuconf_porttype
name|uuconf_ttype
decl_stmt|;
comment|/* The list of protocols supported by the port.  The name of each      protocol is a single character.  May be NULL, in which case any      protocol is permitted.  */
name|char
modifier|*
name|uuconf_zprotocols
decl_stmt|;
comment|/* Array of protocol parameters.  Ends in an entry with a      uuconf_bproto field of '\0'.  May be NULL.  */
name|struct
name|uuconf_proto_param
modifier|*
name|uuconf_qproto_params
decl_stmt|;
comment|/* The set of reliability bits.  */
name|int
name|uuconf_ireliable
decl_stmt|;
comment|/* The lock file name to use.  */
name|char
modifier|*
name|uuconf_zlockname
decl_stmt|;
comment|/* Memory allocation block for the port.  */
name|UUCONF_POINTER
name|uuconf_palloc
decl_stmt|;
comment|/* The type specific information.  */
union|union
block|{
name|struct
name|uuconf_stdin_port
name|uuconf_sstdin
decl_stmt|;
name|struct
name|uuconf_modem_port
name|uuconf_smodem
decl_stmt|;
name|struct
name|uuconf_direct_port
name|uuconf_sdirect
decl_stmt|;
name|struct
name|uuconf_tcp_port
name|uuconf_stcp
decl_stmt|;
name|struct
name|uuconf_tli_port
name|uuconf_stli
decl_stmt|;
name|struct
name|uuconf_pipe_port
name|uuconf_spipe
decl_stmt|;
block|}
name|uuconf_u
union|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Information kept about a dialer.  */
end_comment

begin_struct
struct|struct
name|uuconf_dialer
block|{
comment|/* The name of the dialer.  */
name|char
modifier|*
name|uuconf_zname
decl_stmt|;
comment|/* The chat script to use when dialing out.  */
name|struct
name|uuconf_chat
name|uuconf_schat
decl_stmt|;
comment|/* The string to send when a `=' appears in the phone number.  */
name|char
modifier|*
name|uuconf_zdialtone
decl_stmt|;
comment|/* The string to send when a `-' appears in the phone number.  */
name|char
modifier|*
name|uuconf_zpause
decl_stmt|;
comment|/* Non-zero if the dialer supports carrier detect.  */
name|int
name|uuconf_fcarrier
decl_stmt|;
comment|/* The number of seconds to wait for carrier after the chat script      is complete.  Only used if fcarrier is non-zero.  Only supported      on some systems.  */
name|int
name|uuconf_ccarrier_wait
decl_stmt|;
comment|/* If non-zero, DTR should be toggled before dialing.  Only      supported on some systems.  */
name|int
name|uuconf_fdtr_toggle
decl_stmt|;
comment|/* If non-zero, sleep for 1 second after toggling DTR.  Ignored if      fdtr_toggle is zero.  */
name|int
name|uuconf_fdtr_toggle_wait
decl_stmt|;
comment|/* The chat script to use when a call is complete.  */
name|struct
name|uuconf_chat
name|uuconf_scomplete
decl_stmt|;
comment|/* The chat script to use when a call is aborted.  */
name|struct
name|uuconf_chat
name|uuconf_sabort
decl_stmt|;
comment|/* Array of protocol parameters.  Ends in an entry with a      uuconf_bproto field of '\0'.  May be NULL.  */
name|struct
name|uuconf_proto_param
modifier|*
name|uuconf_qproto_params
decl_stmt|;
comment|/* The set of reliability bits.  */
name|int
name|uuconf_ireliable
decl_stmt|;
comment|/* Memory allocation block for the dialer.  */
name|UUCONF_POINTER
name|uuconf_palloc
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Reliability bits for the ireliable field of ports and dialers.    These bits are used to decide which protocol to run.  A given    protocol will have a set of these bits, and each of them must be    turned on for the port before we will permit that protocol to be    used.  This will be overridden by the zprotocols field.  */
end_comment

begin_comment
comment|/* Whether a set of reliability bits is given.  If this bit is not    set, then there is no reliability information.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_RELIABLE_SPECIFIED
value|(01)
end_define

begin_comment
comment|/* Set if the connection is eight bit transparent.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_RELIABLE_EIGHT
value|(02)
end_define

begin_comment
comment|/* Set if the connection is error-free.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_RELIABLE_RELIABLE
value|(04)
end_define

begin_comment
comment|/* Set if the connection is end-to-end reliable (e.g. TCP).  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_RELIABLE_ENDTOEND
value|(010)
end_define

begin_comment
comment|/* Set if the connection is full-duplex; that is, no time consuming    line turnaround is required before sending data in the reverse    direction.  If the connection is truly half-duplex, in the sense    that communication can only flow in one direction, UUCP can not be    used.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_RELIABLE_FULLDUPLEX
value|(020)
end_define

begin_escape
end_escape

begin_comment
comment|/* UUCP grades range from 0 to 9, A to Z, a to z in order from highest    to lowest (work of higher grades is done before work of lower    grades).  */
end_comment

begin_comment
comment|/* The highest grade.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_GRADE_HIGH
value|('0')
end_define

begin_comment
comment|/* The lowest grade.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_GRADE_LOW
value|('z')
end_define

begin_comment
comment|/* Whether a character is a legal grade (requires<ctype.h>).  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_GRADE_LEGAL
parameter_list|(
name|b
parameter_list|)
value|(isalnum (BUCHAR (b)))
end_define

begin_comment
comment|/* Return< 0 if the first grade should be done before the second    grade, == 0 if they are the same, or> 0 if the first grade should    be done after the second grade.  On an ASCII system, this can just    be b1 - b2.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_GRADE_CMP
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|)
value|(uuconf_grade_cmp ((b1), (b2)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Definitions for bits returned by uuconf_strip.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_STRIP_LOGIN
value|(01)
end_define

begin_define
define|#
directive|define
name|UUCONF_STRIP_PROTO
value|(02)
end_define

begin_escape
end_escape

begin_comment
comment|/* uuconf_runuuxqt returns either a positive number (the number of    execution files to receive between uuxqt invocations) or one of    these constant values.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_RUNUUXQT_NEVER
value|(0)
end_define

begin_define
define|#
directive|define
name|UUCONF_RUNUUXQT_ONCE
value|(-1)
end_define

begin_define
define|#
directive|define
name|UUCONF_RUNUUXQT_PERCALL
value|(-2)
end_define

begin_escape
end_escape

begin_comment
comment|/* Most of the uuconf functions returns an error code.  A value of    zero (UUCONF_SUCCESS) indicates success.  */
end_comment

begin_comment
comment|/* If this bit is set in the returned error code, then the    uuconf_errno function may be used to obtain the errno value as set    by the function which caused the failure.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_ERROR_ERRNO
value|(0x100)
end_define

begin_comment
comment|/* If this bit is set in the returned error code, then the    uuconf_filename function may be used to get the name of a file    associated with the error.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_ERROR_FILENAME
value|(0x200)
end_define

begin_comment
comment|/* If this bit is set in the returned error code, then the    uuconf_lineno function may be used to get a line number associated    with the error; normally if this is set UUCONF_ERROR_FILENAME will    also be set.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_ERROR_LINENO
value|(0x400)
end_define

begin_comment
comment|/* There are two UUCONF_CMDTABRET bits that may be set in the return    value of uuconf_cmd_line or uuconf_cmd_args, described below.  They    do not indicate an error, but instead give instructions to the    calling function, often uuconf_cmd_file.  They may also be set in    the return value of a user function listed in a uuconf_cmdtab    table, in which case they will be honored by uuconf_cmd_file.  */
end_comment

begin_comment
comment|/* This bit means that the memory occupied by the arguments passed to    the function should be preserved, and not overwritten or freed.  It    refers only to the contents of the arguments; the contents of the    argv array itself may always be destroyed.  If this bit is set in    the return value of uuconf_cmd_line or uuconf_cmd_args, it must be    honored.  It will be honored by uuconf_cmd_file.  This may be    combined with an error code or with UUCONF_CMDTABRET_EXIT, although    neither uuconf_cmd_file or uuconf_cmd_line will do so.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABRET_KEEP
value|(0x800)
end_define

begin_comment
comment|/* This bit means that uuconf_cmd_file should exit, rather than go on    to read and process the next line.  If uuconf_cmd_line or    uuconf_cmd_args encounter an error, the return value will have this    bit set along with the error code.  A user function may set this    bit with or without an error; the return value of the user function    will be returned by uuconf_cmd_file, except that the    UUCONF_CMDTABRET_KEEP and UUCONF_CMDTABRET_EXIT bits will be    cleared.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABRET_EXIT
value|(0x1000)
end_define

begin_comment
comment|/* This macro may be used to extract the specific error value.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_ERROR_VALUE
parameter_list|(
name|i
parameter_list|)
value|((i)& 0xff)
end_define

begin_comment
comment|/* UUCONF_ERROR_VALUE will return one of the following values.  */
end_comment

begin_comment
comment|/* Function succeeded.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_SUCCESS
value|(0)
end_define

begin_comment
comment|/* Named item not found.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_NOT_FOUND
value|(1)
end_define

begin_comment
comment|/* A call to fopen failed.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_FOPEN_FAILED
value|(2)
end_define

begin_comment
comment|/* A call to fseek failed.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_FSEEK_FAILED
value|(3)
end_define

begin_comment
comment|/* A call to malloc or realloc failed.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_MALLOC_FAILED
value|(4)
end_define

begin_comment
comment|/* Syntax error in file.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_SYNTAX_ERROR
value|(5)
end_define

begin_comment
comment|/* Unknown command.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_UNKNOWN_COMMAND
value|(6)
end_define

begin_escape
end_escape

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_comment
comment|/* For each type of configuration file (Taylor, V2, HDB), there are    separate routines to read various sorts of information.  There are    also generic routines, which call on the appropriate type specific    routines.  The library can be compiled to read any desired    combination of the configuration file types.  This affects only the    generic routines, as it determines which type specific routines    they call.  Thus, on a system which, for example, does not have any    V2 configuration files, there is no need to include the overhead of    the code to parse the files and the time to look for them.    However, a program which specifically wants to be able to parse    them can call the V2 specific routines.     The uuconf functions all take as an argument a pointer to uuconf    global information.  This must be initialized by any the    initialization routines (the generic one and the three file type    specific ones) before any of the other uuconf functions may be    called.  */
end_comment

begin_comment
comment|/* Initialize the configuration file reading routines.  The ppglobal    argument should point to a generic pointer (a void *, or, on older    compilers, a char *) which will be initialized and may then be    passed to the other uuconf routines.  The zprogram argument is the    name of the program for which files should be read.  A NULL is    taken as "uucp", and reads the standard UUCP configuration files.    The only other common argument is "cu", but any string is    permitted.  The zname argument is the name of the Taylor UUCP    config file; if it is NULL, the default config file will be read.    If not reading Taylor UUCP configuration information, the argument    is ignored.  This function must be called before any of the other    uuconf functions.     Note that if the zname argument is obtained from the user running    the program, the program should be careful to revoke any special    privileges it may have (e.g. on Unix call setuid (getuid ()) and    setgid (getgid ())).  Otherwise various sorts of spoofing become    possible.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_init
parameter_list|(
name|void
modifier|*
modifier|*
name|uuconf_ppglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zprogram
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Adjust the configuration file global pointer for a new thread.  The    library is fully reentrant (with the exception of the function    uuconf_error_string, which calls strerror, which on some systems is    not reentrant), provided that each new thread that wishes to call    the library calls this function and uses the new global pointer    value.  The ppglobal argument should be set to the address of the    global pointer set by any of the init functions; it will be    modified to become a new global pointer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_init_thread
parameter_list|(
name|void
modifier|*
modifier|*
name|uuconf_ppglobal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the names of all known systems.  This sets sets *ppzsystems to    point to an array of system names.  The list of names is NULL    terminated.  The array is allocated using malloc, as is each    element of the array, and they may all be passed to free when they    are no longer needed.  If the falias argument is 0, the list will    not include any aliases; otherwise, it will.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_system_names
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|uuconf_ppzsystems
parameter_list|,
name|int
name|uuconf_falias
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the information for the system zsystem.  This sets the fields    in *qsys.  This will work whether zsystem is the official name of    the system or merely an alias.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_system_info
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zsystem
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get information for an unknown (anonymous) system.  The    uuconf_zname field of the returned system information will be NULL.    If no information is available for unknown systems, this will    return UUCONF_NOT_FOUND.  This does not run the HDB remote.unknown    shell script.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_system_unknown
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get information for the local system.  Normally the local system    name should first be looked up using uuconf_system_info.  If that    returns UUCONF_NOT_FOUND, this function may be used to get an    appropriate set of defaults.  The uuconf_zname field of the    returned system information may be NULL.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_system_local
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free the memory occupied by system information returned by    uuconf_system_info, uuconf_system_unknown, uuconf_system_local, or    any of the configuration file type specific routines described    below.  After this is called, the contents of the structure shall    not be referred to.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_system_free
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_define
define|#
directive|define
name|uuconf_system_free
parameter_list|(
name|qglob
parameter_list|,
name|q
parameter_list|)
define|\
value|(uuconf_free_block ((q)->uuconf_palloc), UUCONF_SUCCESS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Find a matching port.  This will consider each port in turn.     If the zname argument is not NULL, the port's uuconf_zname field    must match it.     If the ibaud argument is not zero and the ihighbaud argument is    zero, the port's baud rate, if defined, must be the same (if the    port has a range of baud rates, ibaud must be within the range).    If ibaud and ihighbaud are both not zero, the port's baud rate, if    defined, must be between ibaud and ihighbaud inclusive (if the port    has a range of baud rates, the ranges must intersect).  If the port    has no baud rate, either because it is a type of port for which    baud rate is not defined (e.g. a TCP port) or because the    uuconf_ibaud field is 0, the ibaud and ihighbaud arguments are    ignored.     If the pifn argument is not NULL, the port is passed to pifn, along    with the pinfo argument (which is otherwise ignored).  If pifn    returns UUCONF_SUCCESS, the port matches.  If pifn returns    UUCONF_NOT_FOUND, a new port is sought.  Otherwise the return value    of pifn is returned from uuconf_find_port.  The pifn function may    be used to further restrict the port, such as by modem class or    device name.  It may also be used to lock the port, if appropriate;    in this case, if the lock fails, pifn may return UUCONF_NOT_FOUND    to force uuconf_find_port to continue searching for a port.     If the port matches, the information is set into uuconf_qport, and    uuconf_find_port returns UUCONF_SUCCESS.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_find_port
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zname
parameter_list|,
name|long
name|uuconf_ibaud
parameter_list|,
name|long
name|uuconf_ihighbaud
parameter_list|,
name|int
function_decl|(
modifier|*
name|uuconf_pifn
function_decl|)
parameter_list|(
name|struct
name|uuconf_port
modifier|*
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|)
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|,
name|struct
name|uuconf_port
modifier|*
name|uuconf_qport
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free the memory occupied by system information returned by    uuconf_find_port (or any of the configuration file specific    routines described below).  After this is called, the contents of    the structure shall not be referred to.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_port_free
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|struct
name|uuconf_port
modifier|*
name|uuconf_qport
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_define
define|#
directive|define
name|uuconf_port_free
parameter_list|(
name|qglob
parameter_list|,
name|q
parameter_list|)
define|\
value|(uuconf_free_block ((q)->uuconf_palloc), UUCONF_SUCCESS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the names of all known dialers.  This sets sets *ppzdialers to    point to an array of dialer names.  The list of names is NULL    terminated.  The array is allocated using malloc, as is each    element of the array, and they may all be passed to free when they    are no longer needed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_dialer_names
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|uuconf_ppzdialers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the information for the dialer zdialer.  This sets the fields    in *qdialer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_dialer_info
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zdialer
parameter_list|,
name|struct
name|uuconf_dialer
modifier|*
name|uuconf_qdialer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free the memory occupied by system information returned by    uuconf_dialer_info (or any of the configuration file specific    routines described below).  After this is called, the contents of    the structure shall not be referred to.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_dialer_free
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|struct
name|uuconf_dialer
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_define
define|#
directive|define
name|uuconf_dialer_free
parameter_list|(
name|qglob
parameter_list|,
name|q
parameter_list|)
define|\
value|(uuconf_free_block ((q)->uuconf_palloc), UUCONF_SUCCESS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the local node name.  If the node name is not specified    (because no ``nodename'' command appeared in the config file) this    will return UUCONF_NOT_FOUND, and some system dependent function    must be used to determine the node name.  Otherwise it will return    a pointer to a constant string, which should not be freed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_localname
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|pzname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the local node name that should be used, given a login name.    This function will check for any special local name that may be    associated with the login name zlogin (as set by the ``myname''    command in a Taylor configuration file, or the MYNAME field in a    Permissions entry).  This will set *pzname to the node name.  If no    node name can be determined, *pzname will be set to NULL and the    function will return UUCONF_NOT_FOUND; in this case some system    dependent function must be used to determine the node name.  If the    function returns UUCONF_SUCCESS, *pzname will be point to an    malloced buffer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_login_localname
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zlogin
parameter_list|,
name|char
modifier|*
modifier|*
name|pzname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the name of the UUCP spool directory.  This will set *pzspool    to a constant string, which should not be freed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_spooldir
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|uuconf_pzspool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the name of the default UUCP public directory.  This will set    *pzpub to a constant string, which should not be freed.  Note that    particular systems may use a different public directory.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_pubdir
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|uuconf_pzpub
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the name of the UUCP lock directory.  This will set *pzlock to    a constant string, which should not be freed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_lockdir
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|uuconf_pzlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the name of the UUCP log file.  This will set *pzlog to a    constant string, which should not be freed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_logfile
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|uuconf_pzlog
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the name of the UUCP statistics file.  This will set *pzstats    to a constant string, which should not be freed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_statsfile
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|uuconf_pzstats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the name of the UUCP debugging file.  This will set *pzdebug to    a constant string, which should not be freed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_debugfile
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|uuconf_pzdebug
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the default debugging level to use.  This basically gets the    argument of the ``debug'' command from the Taylor UUCP config file.    It will set *pzdebug to a constant string, which should not be    freed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_debuglevel
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|uuconf_pzdebug
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get a combination of UUCONF_STRIP bits indicating what types of    global information should be stripped on input.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_strip
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|int
modifier|*
name|uuconf_pistrip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the maximum number of simultaneous uuxqt executions.  This will    set *pcmaxuuxqt to the number.  Zero indicates no maximum.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_maxuuxqts
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|int
modifier|*
name|uuconf_pcmaxuuxqt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the frequency with which to spawn a uuxqt process.  This    returns an integer.  A positive number is the number of execution    files that should be received between spawns.  Other values are one    of the UUCONF_RUNUUXQT constants listed above.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_runuuxqt
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|int
modifier|*
name|uuconf_pirunuuxqt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check a login name and password.  This checks the Taylor UUCP    password file (not /etc/passwd).  It will work even if    uuconf_taylor_init was not called.  All comparisons are done via a    callback function.  The first argument to the function will be zero    when comparing login names, non-zero when comparing passwords.  The    second argument to the function will be the pinfo argument passed    to uuconf_callin.  The third argument will be the login name or    password from the UUCP password file.  The comparison function    should return non-zero for a match, or zero for a non-match.  If    the login name is found and the password compares correctly,    uuconf_callin will return UUCONF_SUCCESS.  If the login is not    found, or the password does not compare correctly, uuconf_callin    will return UUCONF_NOT_FOUND.  Other errors are also possible.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_callin
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|int
function_decl|(
modifier|*
name|uuconf_cmp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the callout login name and password for a system.  This will    set both *pzlog and *pzpass to a string allocated by malloc, or to    NULL if the value is not found.  If neither value is found, the    function will return UUCONF_NOT_FOUND.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_callout
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|,
name|char
modifier|*
modifier|*
name|uuconf_pzlog
parameter_list|,
name|char
modifier|*
modifier|*
name|uuconf_pzpass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* See if a login name is permitted for a system.  This will return    UUCONF_SUCCESS if it is permitted or UUCONF_NOT_FOUND if it is    invalid.  This simply calls uuconf_taylor_validate or returns    UUCONF_SUCCESS, depending on the value of HAVE_TAYLOR_CONFIG.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_validate
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zlogin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the name of the HDB remote.unknown shell script, if using    HAVE_HDB_CONFIG.  This does not actually run the shell script.  If    the function returns UUCONF_SUCCESS, the name will be in *pzname,    which will point to an malloced buffer.  If it returns    UUCONF_NOT_FOUND, then there is no script to run.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_remote_unknown
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
name|pzname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Translate a dial code.  This sets *pznum to an malloced string.    This will look up the entire zdial string in the dialcode file, so    for normal use the alphabetic prefix should be separated.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_dialcode
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zdial
parameter_list|,
name|char
modifier|*
modifier|*
name|uuconf_pznum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compare two grades, returning< 0 if b1 should be executed before    b2, == 0 if they are the same, or> 0 if b1 should be executed    after b2.  This can not fail, and does not return a standard uuconf    error code; it is normally called via the macro UUCONF_GRADE_CMP,    defined above.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_grade_cmp
parameter_list|(
name|int
name|uuconf_b1
parameter_list|,
name|int
name|uuconf_b2
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_init_thread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_system_names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_system_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_system_unknown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_system_local
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_system_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_find_port
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_port_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_dialer_names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_dialer_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_dialer_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_localname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_login_localname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_spooldir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_lockdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_pubdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_logfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_statsfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_debugfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_debuglevel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_maxuuxqts
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_runuuxqt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_callin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_callout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_remote_unknown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_validate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_grade_cmp
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_define
define|#
directive|define
name|uuconf_system_free
parameter_list|(
name|qglob
parameter_list|,
name|q
parameter_list|)
define|\
value|(uuconf_free_block ((q)->uuconf_palloc), UUCONF_SUCCESS)
end_define

begin_define
define|#
directive|define
name|uuconf_port_free
parameter_list|(
name|qglob
parameter_list|,
name|q
parameter_list|)
define|\
value|(uuconf_free_block ((q)->uuconf_palloc), UUCONF_SUCCESS)
end_define

begin_define
define|#
directive|define
name|uuconf_dialer_free
parameter_list|(
name|qglob
parameter_list|,
name|q
parameter_list|)
define|\
value|(uuconf_free_block ((q)->uuconf_palloc), UUCONF_SUCCESS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_comment
comment|/* Initialize the Taylor UUCP configuration file reading routines.    This must be called before calling any of the Taylor UUCP    configuration file specific routines.  The ppglobal argument should    point to a generic pointer.  Moreover, before calling this function    the pointer either must be set to NULL, or must have been passed to    one of the other uuconf init routines.  The zprogram argument is    the name of the program for which files should be read.  If NULL,    it is taken as "uucp", which means to read the standard UUCP files.    The zname argument is the name of the config file.  If it is NULL,    the default config file will be used.     Note that if the zname argument is obtained from the user running    the program, the program should be careful to revoke any special    privileges it may have (e.g. on Unix call setuid (getuid ()) and    setgid (getgid ())).  Otherwise various sorts of spoofing become    possible.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_init
parameter_list|(
name|void
modifier|*
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zprogram
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the names of all systems listed in the Taylor UUCP    configuration files.  This sets *ppzsystems to point to an array of    system names.  The list of names is NULL terminated.  The array is    allocated using malloc, as is each element of the array.  If the    falias argument is 0, the list will not include any aliases;    otherwise, it will.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_system_names
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|uuconf_ppzsystems
parameter_list|,
name|int
name|uuconf_falias
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the information for system zsystem from the Taylor UUCP    configuration files.  This will set *qsys.   */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_system_info
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zsystem
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get information for an unknown (anonymous) system.  This returns    the values set by the ``unknown'' command in the main configuration    file.  If the ``unknown'' command was not used, this will return    UUCONF_NOT_FOUND.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_system_unknown
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find a port from the Taylor UUCP configuration files.  The    arguments and return values are identical to those of    uuconf_find_port.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_find_port
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zname
parameter_list|,
name|long
name|uuconf_ibaud
parameter_list|,
name|long
name|uuconf_ihighbaud
parameter_list|,
name|int
function_decl|(
modifier|*
name|uuconf_pifn
function_decl|)
parameter_list|(
name|struct
name|uuconf_port
modifier|*
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|)
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|,
name|struct
name|uuconf_port
modifier|*
name|uuconf_qport
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the names of all dialers listed in the Taylor UUCP    configuration files.  This sets *ppzdialers to point to an array of    dialer names.  The list of names is NULL terminated.  The array is    allocated using malloc, as is each element of the array.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_dialer_names
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|uuconf_ppzdialers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the information for the dialer zdialer from the Taylor UUCP    configuration files.  This sets the fields in *qdialer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_dialer_info
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zdialer
parameter_list|,
name|struct
name|uuconf_dialer
modifier|*
name|uuconf_qdialer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the local node name that should be used, given a login name,    considering only the ``myname'' command in the Taylor UUCP    configuration files.  If the function returns UUCONF_SUCCESS,    *pzname will point to an malloced buffer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_login_localname
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zlogin
parameter_list|,
name|char
modifier|*
modifier|*
name|pzname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the callout login name and password for a system from the    Taylor UUCP configuration files.  This will set both *pzlog and    *pzpass to a string allocated by malloc, or to NULL if the value is    not found.  If neither value is found, the function will return    UUCONF_NOT_FOUND.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_callout
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|,
name|char
modifier|*
modifier|*
name|uuconf_pzlog
parameter_list|,
name|char
modifier|*
modifier|*
name|uuconf_pzpass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* See if a login name is permitted for a system.  This will return    UUCONF_SUCCESS if it is permitted or UUCONF_NOT_FOUND if it is    invalid.  This checks whether the login name appears in a    called-login command with a list of system which does not include    the system qsys.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_validate
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zlogin
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_system_names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_system_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_system_unknown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_find_port
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_dialer_names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_dialer_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_login_localname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_callout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_taylor_validate
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_comment
comment|/* Initialize the V2 configuration file reading routines.  This must    be called before any of the other V2 routines are called.  The    ppglobal argument should point to a generic pointer.  Moreover,    before calling this function the pointer either must be set to    NULL, or must have been passed to one of the other uuconf init    routines.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_v2_init
parameter_list|(
name|void
modifier|*
modifier|*
name|uuconf_ppglobal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the names of all systems listed in the V2 configuration files.    This sets *ppzsystems to point to an array of system names.  The    list of names is NULL terminated.  The array is allocated using    malloc, as is each element of the array.  If the falias argument is    0, the list will not include any aliases; otherwise, it will.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_v2_system_names
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|uuconf_ppzsystems
parameter_list|,
name|int
name|uuconf_falias
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the information for system zsystem from the V2 configuration    files.  This will set *qsys.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_v2_system_info
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zsystem
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find a port from the V2 configuration files.  The arguments and    return values are identical to those of uuconf_find_port.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_v2_find_port
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zname
parameter_list|,
name|long
name|uuconf_ibaud
parameter_list|,
name|long
name|uuconf_ihighbaud
parameter_list|,
name|int
function_decl|(
modifier|*
name|uuconf_pifn
function_decl|)
parameter_list|(
name|struct
name|uuconf_port
modifier|*
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|)
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|,
name|struct
name|uuconf_port
modifier|*
name|uuconf_qport
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_v2_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_v2_system_names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_v2_system_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_v2_find_port
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_comment
comment|/* Initialize the HDB configuration file reading routines.  This    should be called before any of the other HDB routines are called.    The ppglobal argument should point to a generic pointer.  Moreover,    before calling this function the pointer either must be set to    NULL, or must have been passed to one of the other uuconf init    routines.  The zprogram argument is used to match against a    "services" string in Sysfiles.  A NULL or "uucp" argument is taken    as "uucico".  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_init
parameter_list|(
name|void
modifier|*
modifier|*
name|uuconf_ppglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zprogram
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the names of all systems listed in the HDB configuration files.    This sets *ppzsystems to point to an array of system names.  The    list of names is NULL terminated.  The array is allocated using    malloc, as is each element of the array.  If the falias argument is    0, the list will not include any aliases; otherwise, it will (an    alias is created by using the ALIAS= keyword in the Permissions    file).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_system_names
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|uuconf_ppzsystems
parameter_list|,
name|int
name|uuconf_falias
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the information for system zsystem from the HDB configuration    files.  This will set *qsys.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_system_info
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zsystem
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get information for an unknown (anonymous) system.  If no    information is available for unknown systems, this will return    UUCONF_NOT_FOUND.  This does not run the remote.unknown shell    script.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_system_unknown
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|struct
name|uuconf_system
modifier|*
name|uuconf_qsys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find a port from the HDB configuration files.  The arguments and    return values are identical to those of uuconf_find_port.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_find_port
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zname
parameter_list|,
name|long
name|uuconf_ibaud
parameter_list|,
name|long
name|uuconf_ihighbaud
parameter_list|,
name|int
function_decl|(
modifier|*
name|uuconf_pifn
function_decl|)
parameter_list|(
name|struct
name|uuconf_port
modifier|*
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|)
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|,
name|struct
name|uuconf_port
modifier|*
name|uuconf_qport
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the names of all dialers listed in the HDB configuration files.    This sets *ppzdialers to point to an array of dialer names.  The    list of names is NULL terminated.  The array is allocated using    malloc, as is each element of the array.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_dialer_names
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|uuconf_ppzdialers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the information for the dialer zdialer from the HDB    configuration files.  This sets the fields in *qdialer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_dialer_info
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zdialer
parameter_list|,
name|struct
name|uuconf_dialer
modifier|*
name|uuconf_qdialer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the local node name that should be used, given a login name,    considering only the MYNAME field in the HDB Permissions file.  If    the function returns UUCONF_SUCCESS, *pzname will point to an    malloced buffer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_login_localname
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
specifier|const
name|char
modifier|*
name|uuconf_zlogin
parameter_list|,
name|char
modifier|*
modifier|*
name|pzname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the name of the HDB remote.unknown shell script.  This does not    actually run the shell script.  If the function returns    UUCONF_SUCCESS, the name will be in *pzname, which will point to an    malloced buffer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_remote_unknown
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
modifier|*
name|pzname
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_system_names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_system_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_system_unknown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_find_port
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_dialer_names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_dialer_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_localname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_hdb_remote_unknown
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_comment
comment|/* This function will set an appropriate error message into the buffer    zbuf, given a uuconf error code.  The buffer will always be null    terminated, and will never be accessed beyond the length cbuf.    This function will return the number of characters needed for the    complete message, including the null byte.  If this is less than    the cbytes argument, the buffer holds a truncated string.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_error_string
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|int
name|ierror
parameter_list|,
name|char
modifier|*
name|zbuf
parameter_list|,
name|UUCONF_SIZE_T
name|cbuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If UUCONF_ERROR_ERRNO is set in a return value, this function may    be used to retrieve the errno value.  This will be the value of    errno as set by the system function which failed.  However, some    system functions, notably some stdio routines, may not set errno,    in which case the value will be meaningless.  This function does    not return a uuconf error code, and it cannot fail.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_error_errno
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If UUCONF_ERROR_FILENAME is set in a return value, this function    may be used to retrieve the file name.  This function does not    return a uuconf error code, and it cannot fail.  The string that it    returns a pointer to is not guaranteed to remain allocated across    the next call to a uuconf function (other than one of the three    error retrieving functions).  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|uuconf_error_filename
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If UUCONF_ERROR_LINENO is set in a return value, this function may    be used to retrieve the line number.  This function does not return    a uuconf error code, and it cannot fail.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_error_lineno
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_error_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_error_errno
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UUCONF_CONST
name|char
modifier|*
name|uuconf_error_filename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_error_lineno
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_escape
end_escape

begin_comment
comment|/* The uuconf package also provides a few functions which can accept    commands and parcel them out according to a table.  These are    publically visible, partially in the hopes that they will be    useful, but mostly because the rest of the Taylor UUCP package uses    them.  */
end_comment

begin_comment
comment|/* The types of entries allowed in a command table (struct    uuconf_cmdtab).  Each type defines how a particular command is    interpreted.  Each type will either assign a value to a variable or    call a function.  In all cases, a line of input is parsed into    separate fields, separated by whitespace; comments beginning with    '#' are discarded, except that a '#' preceeded by a backslash is    retained.  The first field is taken as the command to execute, and    the remaining fields are its arguments.  */
end_comment

begin_comment
comment|/* A boolean value.  Used for a command which accepts a single    argument, which must begin with 'y', 'Y', 't', or 'T' for true (1)    or 'n', 'N', 'f', or 'F' for false (0).  The corresponding variable    must be an int.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABTYPE_BOOLEAN
value|(0x12)
end_define

begin_comment
comment|/* An integer value.  Used for a command which accepts a single    argument, which must be an integer.  The corresponding variable    must be an int.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABTYPE_INT
value|(0x22)
end_define

begin_comment
comment|/* A long value.  Used for a command which accepts a single value,    which must be an integer.  The corresponding variable must be a    long.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABTYPE_LONG
value|(0x32)
end_define

begin_comment
comment|/* A string value.  Used for a command which accepts a string    argument.  If there is no argument, the variable will be set to    point to a zero byte.  Otherwise the variable will be set to point    to the string.  The corresponding variable must be a char *.  The    memory pointed to by the variable after it is set must not be    modified.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABTYPE_STRING
value|(0x40)
end_define

begin_comment
comment|/* A full string value.  Used for a command which accepts a series of    string arguments separated by whitespace.  The corresponding    variable must be a char **.  It will be set to an NULL terminated    array of the arguments.  The memory occupied by the array itself,    and by the strings within it, must not be modified.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABTYPE_FULLSTRING
value|(0x50)
end_define

begin_comment
comment|/* A function.  If this command is encountered, the command and its    arguments are passed to the corresponding function.  They are    passed as an array of strings, in which the first string is the    command itself, along with a count of strings.  This value may be    or'red with a specific number of required arguments;    UUCONF_CMDTABTYPE_FN | 1 accepts no additional arguments besides    the command itself, UUCONF_CMDTABTYPE_FN | 2 accepts 1 argument,    etc.  UUCONF_CMDTABTYPE_FN | 0, accepts any number of additional    arguments.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABTYPE_FN
value|(0x60)
end_define

begin_comment
comment|/* A prefix function.  The string in the table is a prefix; if a    command is encountered with the same prefix, the corresponding    function will be called as for UUCONF_CMDTABTYPE_FN.  The number of    arguments may be or'red in as with UUCONF_CMDTABTYPE_FN.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABTYPE_PREFIX
value|(0x70)
end_define

begin_comment
comment|/* This macro will return the particular type of a CMDTABTYPE.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_TTYPE_CMDTABTYPE
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x70)
end_define

begin_comment
comment|/* This macro will return the required number of arguments of a    CMDTABTYPE.  If it is zero, there is no restriction.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CARGS_CMDTABTYPE
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x0f)
end_define

begin_comment
comment|/* When a function is called via UUCONF_CMDTABTYPE_FN or    UUCONF_CMDTABTYPE_PREFIX, it may return any uuconf error code (see    above).  However, it will normally return one of the following:     UUCONF_CMDTABRET_CONTINUE: Take no special action.  In particular,    the arguments passed to the function may be overwritten or freed.     UUCONF_CMDTABRET_KEEP: The memory occupied by the arguments passed    to the function must be preserved.  Continue processing commands.     UUCONF_CMDTABRET_EXIT: If reading commands from a file, stop    processing.  The arguments passed to the function may be    overwritten or freed.     UUCONF_CMDTABRET_KEEP_AND_EXIT: Stop processing any file.  The    memory occupied by the arguments passed to the function must be    preserved.     These values are interpreted by uuconf_cmd_file.  The    uuconf_cmd_line and uuconf_cmd_args functions may return    UUCONF_CMDTABRET_KEEP.  It they get an error, they will return an    error code with UUCONF_CMDTABRET_EXIT set.  Also, of course, they    may return any value that is returned by one of the user functions    in the uuconf_cmdtab table.  */
end_comment

begin_comment
comment|/* UUCONF_CMDTABRET_KEEP and UUCONF_CMDTABRET_EXIT are defined above,    with the error codes.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABRET_CONTINUE
value|UUCONF_SUCCESS
end_define

begin_define
define|#
directive|define
name|UUCONF_CMDTABRET_KEEP_AND_EXIT
define|\
value|(UUCONF_CMDTABRET_KEEP | UUCONF_CMDTABRET_EXIT)
end_define

begin_comment
comment|/* When a function is called via CMDTABTYPE_FN or CMDTABTYPE_PREFIX,    it is passed five arguments.  This is the type of a pointer to such    a function.  The uuconf global information structure is passed in    for convenience in calling another uuconf function.  The arguments    to the command are passed in (the command itself is the first    argument) along with a count and the value of the pvar field from    the uuconf_cmdtab structure in which the function pointer was    found.  The pinfo argument to the function is taken from the    argument to uuconf_cmd_*.  */
end_comment

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uuconf_cmdtabfn
function_decl|)
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|int
name|uuconf_argc
parameter_list|,
name|char
modifier|*
modifier|*
name|uuconf_argv
parameter_list|,
name|void
modifier|*
name|uuconf_pvar
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|)
function_decl|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uuconf_cmdtabfn
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A table of commands is an array of the following structures.  The    final element of the table should have uuconf_zcmd == NULL.  */
end_comment

begin_struct
struct|struct
name|uuconf_cmdtab
block|{
comment|/* Command name.  */
name|UUCONF_CONST
name|char
modifier|*
name|uuconf_zcmd
decl_stmt|;
comment|/* Command type (one of CMDTABTYPE_*).  */
name|int
name|uuconf_itype
decl_stmt|;
comment|/* If not CMDTABTYPE_FN or CMDTABTYPE_PREFIX, the address of the      associated variable.  Otherwise, a pointer value to pass to the      function pifn.  */
name|UUCONF_POINTER
name|uuconf_pvar
decl_stmt|;
comment|/* The function to call if CMDTABTYPE_FN or CMDTABTYPE_PREFIX.  */
name|uuconf_cmdtabfn
name|uuconf_pifn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Bit flags to pass to uuconf_processcmds.  */
end_comment

begin_comment
comment|/* If set, case is significant when checking commands.  Normally case    is ignored.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABFLAG_CASE
value|(0x1)
end_define

begin_comment
comment|/* If set, a backslash at the end of a line may be used to include the    next physical line in the logical line.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABFLAG_BACKSLASH
value|(0x2)
end_define

begin_comment
comment|/* If set, the comment character (#) is treated as a normal character,    rather than as starting a comment.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_CMDTABFLAG_NOCOMMENTS
value|(0x4)
end_define

begin_escape
end_escape

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_comment
comment|/* Read commands from a file, look them up in a table, and take the    appropriate action.  This continues reading lines from the file    until EOF, or until a function returns with UUCONF_CMDTABRET_EXIT    set, or until an error occurs.  The qtab argument must point to a    table of struct uuconf_cmdtab; the last element in the table should    have uuconf_zcmd == NULL.  When a UUCONF_CMDTABTYPE_FN or    UUCONF_CMDTABTYPE_PREFIX command is found, the pinfo argument will    be passed to the called function.  If an a command is found that is    not in the table, then if pfiunknownfn is NULL the unknown command    is ignored; otherwise it is passed to pfiunknownfn, which should    return a uuconf return code which is handled as for any other    function (the pvar argument to pfiunknownfn will always be NULL).    The iflags argument is any combination of the above    UUCONF_CMDTABFLAG bits.  The pblock argument may also be a memory    block, as returned by uuconf_malloc_block (described below), in    which case all memory preserved because of UUCONF_CMDTABRET_KEEP    will be added to the block so that it may be freed later; it may    also be NULL, in which case any such memory is permanently lost.     This function initially sets the internal line number to 0, and    then increments it as each line is read.  It is permitted for any    called function to use the uuconf_lineno function to obtain it.  If    this function is called when not at the start of a file, the value    returned by uuconf_lineno (which is, in any case, only valid if an    error code with UUCONF_ERROR_LINENO set is returned) must be    adjusted by the caller.     This returns a normal uuconf return value, as described above.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_cmd_file
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|FILE
modifier|*
name|uuconf_e
parameter_list|,
specifier|const
name|struct
name|uuconf_cmdtab
modifier|*
name|uuconf_qtab
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|,
name|uuconf_cmdtabfn
name|uuconf_pfiunknownfn
parameter_list|,
name|int
name|uuconf_iflags
parameter_list|,
name|void
modifier|*
name|pblock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This utility function is just like uuconf_cmd_file, except that it    only operates on a single string.  If a function is called via    qtab, its return value will be the return value of this function.    UUCONF_CMDTABFLAG_BACKSLASH is ignored in iflags.  The string z is    modified in place.  The return value may include the    UUCONF_CMDTABRET_KEEP and, on error, the UUCONF_CMDTABRET_EXIT    bits, which should be honored by the calling code.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_cmd_line
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|char
modifier|*
name|uuconf_z
parameter_list|,
specifier|const
name|struct
name|uuconf_cmdtab
modifier|*
name|uuconf_qtab
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|,
name|uuconf_cmdtabfn
name|uuconf_pfiunknownfn
parameter_list|,
name|int
name|uuconf_iflags
parameter_list|,
name|void
modifier|*
name|pblock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This utility function is just like uuconf_cmd_line, except it is    given a list of already parsed arguments.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_cmd_args
parameter_list|(
name|void
modifier|*
name|uuconf_pglobal
parameter_list|,
name|int
name|uuconf_cargs
parameter_list|,
name|char
modifier|*
modifier|*
name|uuconf_pzargs
parameter_list|,
specifier|const
name|struct
name|uuconf_cmdtab
modifier|*
name|uuconf_qtab
parameter_list|,
name|void
modifier|*
name|uuconf_pinfo
parameter_list|,
name|uuconf_cmdtabfn
name|uuconf_pfiunknownfn
parameter_list|,
name|int
name|uuconf_iflags
parameter_list|,
name|void
modifier|*
name|pblock
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_cmd_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_cmd_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_cmd_args
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|UUCONF_ANSI_C
end_if

begin_comment
comment|/* The uuconf_cmd_file function may allocate memory permanently, as    for setting a UUCONF_CMDTABTYPE_STRING value, in ways which are    difficult to free up.  A memory block may be used to record all    allocated memory, so that it can all be freed up at once at some    later time.  These functions do not take a uuconf global pointer,    and are independent of the rest of the uuconf library.  */
end_comment

begin_comment
comment|/* Allocate a block of memory.  If this returns NULL, then malloc    returned NULL, and errno is whatever malloc set it to.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|uuconf_malloc_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate memory within a memory block.  If this returns NULL, then    malloc returned NULL, and errno is whatever malloc set it to.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|uuconf_malloc
parameter_list|(
name|void
modifier|*
name|uuconf_pblock
parameter_list|,
name|UUCONF_SIZE_T
name|uuconf_cbytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a block returned by the generic malloc routine to a memory    block.  This returns zero on success, non-zero on failure.  If this    fails (returns non-zero), then malloc returned NULL, and errno is    whatever malloc set it to.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|uuconf_add_block
parameter_list|(
name|void
modifier|*
name|uuconf_pblock
parameter_list|,
name|void
modifier|*
name|uuconf_padd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a value returned by uuconf_malloc from a memory block.  In the    current implementation, this will normally not do anything, but it    doesn't hurt.  No errors can occur.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|uuconf_free
parameter_list|(
name|void
modifier|*
name|uuconf_pblock
parameter_list|,
name|void
modifier|*
name|uuconf_pfree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free an entire memory block, including all values returned by    uuconf_malloc from it and all values added to it with    uuconf_add_block.  No errors can occur.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|uuconf_free_block
parameter_list|(
name|void
modifier|*
name|uuconf_pblock
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_function_decl
specifier|extern
name|UUCONF_POINTER
name|uuconf_malloc_block
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UUCONF_POINTER
name|uuconf_malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uuconf_add_block
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern
comment|/* void */
extern|uuconf_free (
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern
comment|/* void */
extern|uuconf_free_block (
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! UUCONF_ANSI_C */
end_comment

begin_escape
end_escape

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (UUCONF_H) */
end_comment

end_unit

