begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* trans.h    Header file for file and command transfer routines.     Copyright (C) 1992, 1993, 1994 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* The maximum possible number of channels.  */
end_comment

begin_define
define|#
directive|define
name|IMAX_CHAN
value|(16)
end_define

begin_comment
comment|/* The ifeatures field of the sdaemon structure is an or of the    following values.  These values are sent during the uucico    handshake, and MUST NOT CHANGE.  */
end_comment

begin_comment
comment|/* File size negotiation.  */
end_comment

begin_define
define|#
directive|define
name|FEATURE_SIZES
value|(01)
end_define

begin_comment
comment|/* File transfer restart.  */
end_comment

begin_define
define|#
directive|define
name|FEATURE_RESTART
value|(02)
end_define

begin_comment
comment|/* The E (execute) command.  */
end_comment

begin_define
define|#
directive|define
name|FEATURE_EXEC
value|(04)
end_define

begin_comment
comment|/* Version 1.03: requires decimal size in S and R command.  Needless    to say, this should not be used by any new programs.  */
end_comment

begin_define
define|#
directive|define
name|FEATURE_V103
value|(010)
end_define

begin_comment
comment|/* SVR4 UUCP: expects dummy string between notify field and size field    in send command.  There is probably some meaning to this string,    but I don't know what it is.  If I ever find out, this flag will    still be used to indicate it.  */
end_comment

begin_define
define|#
directive|define
name|FEATURE_SVR4
value|(020)
end_define

begin_comment
comment|/* This structure is used to hold information concerning the    communication link established with the remote system.  */
end_comment

begin_struct
struct|struct
name|sdaemon
block|{
comment|/* Global uuconf pointer.  */
name|pointer
name|puuconf
decl_stmt|;
comment|/* Configuration file name argument (from -I option).  */
specifier|const
name|char
modifier|*
name|zconfig
decl_stmt|;
comment|/* How often to spawn uuxqt (from uuconf_runuuxqt).  */
name|int
name|irunuuxqt
decl_stmt|;
comment|/* Remote system information.  */
specifier|const
name|struct
name|uuconf_system
modifier|*
name|qsys
decl_stmt|;
comment|/* Local name being used.  */
specifier|const
name|char
modifier|*
name|zlocalname
decl_stmt|;
comment|/* Connection structure.  */
name|struct
name|sconnection
modifier|*
name|qconn
decl_stmt|;
comment|/* Protocol being used.  */
specifier|const
name|struct
name|sprotocol
modifier|*
name|qproto
decl_stmt|;
comment|/* Number of channels being used.  */
name|int
name|cchans
decl_stmt|;
comment|/* The largest file size permitted for a local request.  */
name|long
name|clocal_size
decl_stmt|;
comment|/* The largest file size permitted for a remote request.  */
name|long
name|cremote_size
decl_stmt|;
comment|/* The largest file size that may ever be transferred.  */
name|long
name|cmax_ever
decl_stmt|;
comment|/* The remote system ulimit.  */
name|long
name|cmax_receive
decl_stmt|;
comment|/* Number of bytes sent.  */
name|long
name|csent
decl_stmt|;
comment|/* Number of bytes received.  */
name|long
name|creceived
decl_stmt|;
comment|/* Number of execution files received since the last time we spawned      uuxqt.  */
name|long
name|cxfiles_received
decl_stmt|;
comment|/* Features supported by the remote side.  */
name|int
name|ifeatures
decl_stmt|;
comment|/* TRUE if we should request the remote side to hang up.  */
name|boolean
name|frequest_hangup
decl_stmt|;
comment|/* TRUE if the remote side requested a hangup.  */
name|boolean
name|fhangup_requested
decl_stmt|;
comment|/* TRUE if we are hanging up.  */
name|boolean
name|fhangup
decl_stmt|;
comment|/* TRUE if the local system is currently the master.  */
name|boolean
name|fmaster
decl_stmt|;
comment|/* TRUE if the local system placed the call.  */
name|boolean
name|fcaller
decl_stmt|;
comment|/* UUCONF_RELIABLE_* flags for the connection.  */
name|int
name|ireliable
decl_stmt|;
comment|/* If fcaller is FALSE, the lowest grade which may be transferred      during this call.  */
name|char
name|bgrade
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is used to hold a file or command transfer which is    in progress.  */
end_comment

begin_struct
struct|struct
name|stransfer
block|{
comment|/* Next file transfer in queue.  */
name|struct
name|stransfer
modifier|*
name|qnext
decl_stmt|;
comment|/* Previous file transfer in queue.  */
name|struct
name|stransfer
modifier|*
name|qprev
decl_stmt|;
comment|/* Points to the queue this structure is on.  */
name|struct
name|stransfer
modifier|*
modifier|*
name|pqqueue
decl_stmt|;
comment|/* The function to call to send some data.  */
name|boolean
argument_list|(
argument|*psendfn
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|stransfer
operator|*
name|qtrans
operator|,
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|)
argument_list|)
expr_stmt|;
comment|/* The function to call when data is received.  */
name|boolean
argument_list|(
argument|*precfn
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|stransfer
operator|*
name|qtrans
operator|,
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
specifier|const
name|char
operator|*
name|zdata
operator|,
name|size_t
name|cdata
operator|)
argument_list|)
expr_stmt|;
comment|/* Type specific information.   */
name|pointer
name|pinfo
decl_stmt|;
comment|/* TRUE if we are sending the file e (this is used to avoid a call      to psendfn).  */
name|boolean
name|fsendfile
decl_stmt|;
comment|/* TRUE if we are receiving the file e (this is used to avoid a call      to precfn).  */
name|boolean
name|frecfile
decl_stmt|;
comment|/* The file to read or write.  */
name|openfile_t
name|e
decl_stmt|;
comment|/* The position we are at in the file.  */
name|long
name|ipos
decl_stmt|;
comment|/* TRUE if we are waiting for a command string.  */
name|boolean
name|fcmd
decl_stmt|;
comment|/* The command string we have so far.  */
name|char
modifier|*
name|zcmd
decl_stmt|;
comment|/* The length of the command string we have so far.  */
name|size_t
name|ccmd
decl_stmt|;
comment|/* Local destination number.  */
name|int
name|ilocal
decl_stmt|;
comment|/* Remote destination number.  */
name|int
name|iremote
decl_stmt|;
comment|/* The command.  */
name|struct
name|scmd
name|s
decl_stmt|;
comment|/* A message to log when work starts.  */
name|char
modifier|*
name|zlog
decl_stmt|;
comment|/* The process time; imicros can be negative.  */
name|long
name|isecs
decl_stmt|;
name|long
name|imicros
decl_stmt|;
comment|/* Number of bytes sent or received.  */
name|long
name|cbytes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Reasons that a file transfer might fail.  */
end_comment

begin_enum
enum|enum
name|tfailure
block|{
comment|/* No failure.  */
name|FAILURE_NONE
block|,
comment|/* No permission for operation.  */
name|FAILURE_PERM
block|,
comment|/* Can't open necessary file.  */
name|FAILURE_OPEN
block|,
comment|/* Not enough space to receive file.  */
name|FAILURE_SIZE
block|,
comment|/* File was received in a previous conversation.  */
name|FAILURE_RECEIVED
block|}
enum|;
end_enum

begin_comment
comment|/* The main loop which talks to the remote system, passing transfer    requests and file back and forth.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|floop
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate a new transfer structure.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|stransfer
modifier|*
name|qtransalc
name|P
argument_list|(
operator|(
expr|struct
name|scmd
operator|*
name|qcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a transfer structure.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|utransfree
name|P
argument_list|(
operator|(
expr|struct
name|stransfer
operator|*
name|qtrans
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue up local requests.  If pfany is not NULL, this sets *pfany to    TRUE if there are, in fact, any local requests which can be done at    this point.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fqueue
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
name|boolean
operator|*
name|pfany
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear away any queued requests.  This may be called more than once    at the end of a call.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uclear_queue
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue a new transfer request made by the local system.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fqueue_local
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|stransfer
operator|*
name|qtrans
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue a new transfer request made by the remote system.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fqueue_remote
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|stransfer
operator|*
name|qtrans
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue a transfer request which wants to send something.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fqueue_send
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|stransfer
operator|*
name|qtrans
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue a transfer request which wants to receiving something.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fqueue_receive
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|stransfer
operator|*
name|qtrans
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prepare to send a file by local or remote request.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|flocal_send_file_init
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fremote_send_file_init
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|,
name|int
name|iremote
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prepare to receive a file by local or remote request.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|flocal_rec_file_init
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fremote_rec_file_init
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|,
name|int
name|iremote
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prepare to request work by local or remote request.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|flocal_xcmd_init
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fremote_xcmd_init
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|,
name|int
name|iremote
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We have lost the connection; record any in progress file transfers    in the statistics file and discard any temporary files.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ufailed
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check that there is enough disk space for a file receive.  Return    FALSE if there is not.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|frec_check_free
name|P
argument_list|(
operator|(
expr|struct
name|stransfer
operator|*
name|qtrans
operator|,
name|long
name|cfree_space
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Discard the temporary file being used to receive a file, if    appropriate.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|frec_discard_temp
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|stransfer
operator|*
name|qtrans
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Handle data received by a protocol.  This is called by the protocol    specific routines as data comes in.  The data is passed as two    buffers because that is convenient for packet based protocols, but    normally csecond will be 0.  The ilocal argument is the local    channel number, and the iremote argument is the remote channel    number.  Either may be -1, if the protocol does not have channels.    The ipos argument is the position in the file, if the protocol    knows it; for most protocols, this will be -1.  The fallacked    argument should be set to TRUE if the remote has acknowledged all    outstanding data; see uwindow_acked, below, for details. This will    set *pfexit to TRUE if there is something for the main loop to do.    A file is complete is when a zero length buffer is passed (cfirst    == 0).  A command is complete when data containing a null byte is    passed.  This will return FALSE on error.  If the protocol pfwait    entry point should exit and let the top level loop continue,    *pfexit will be set to TRUE (if pfexit is not NULL).  This will not    set *pfexit to FALSE, so the caller must do that.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fgot_data
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
specifier|const
name|char
operator|*
name|zfirst
operator|,
name|size_t
name|cfirst
operator|,
specifier|const
name|char
operator|*
name|zsecond
operator|,
name|size_t
name|csecond
operator|,
name|int
name|ilocal
operator|,
name|int
name|iremote
operator|,
name|long
name|ipos
operator|,
name|boolean
name|fallacked
operator|,
name|boolean
operator|*
name|pfexit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This routine is called when an ack is sent for a file receive.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usent_receive_ack
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
expr|struct
name|stransfer
operator|*
name|qtrans
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A protocol may call this routine to indicate the packets have been    acknowledged by the remote system.  If the fallacked argument is    TRUE, then all outstanding packets have been acknowledged; for    convenience, this may also be indicated by passing fallacked as    TRUE to fgot_data, above.  Otherwise this routine should be called    each time a complete window is acked by the remote system.  The    transfer code uses this information to keep track of when an    acknowledgement of a file receive has been seen by the other side,    so that file receives may be handled cleanly if the connection is    lost.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uwindow_acked
name|P
argument_list|(
operator|(
expr|struct
name|sdaemon
operator|*
name|qdaemon
operator|,
name|boolean
name|fallacked
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Spawn a uuxqt process.  The ffork argument is passed to    fsysdep_run.  If the zsys argument is not NULL, then -s zsys is    passed to uuxqt.  The zconfig argument is the name of the    configuration file, from the -I option.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fspawn_uuxqt
name|P
argument_list|(
operator|(
name|boolean
name|ffork
operator|,
specifier|const
name|char
operator|*
name|zsys
operator|,
specifier|const
name|char
operator|*
name|zconfig
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

