begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* prot.h    Protocol header file.     Copyright (C) 1991, 1992 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o AIRS, P.O. Box 520, Waltham, MA 02254.     $Log: prot.h,v $    Revision 1.12  1992/03/13  22:59:25  ian    Have breceive_char go through freceive_data     Revision 1.11  1992/03/07  15:00:28  ian    prot.h is never included more than once     Revision 1.10  1992/02/08  03:54:18  ian    Include<string.h> only in<uucp.h>, added 1992 copyright     Revision 1.9  1992/01/18  22:48:53  ian    Reworked sending of mail and general handling of failed transfers     Revision 1.8  1991/12/31  19:43:13  ian    Added 'e' protocol     Revision 1.7  1991/11/15  21:00:59  ian    Efficiency hacks for 'f' and 't' protocols     Revision 1.6  1991/11/14  03:20:13  ian    Added seven-bit and reliable commands to help when selecting protocols     Revision 1.5  1991/11/12  18:25:33  ian    Added 't' protocol     Revision 1.4  1991/11/11  04:21:16  ian    Added 'f' protocol     Revision 1.3  1991/11/10  19:24:22  ian    Added pffile protocol entry point for file level control     Revision 1.2  1991/11/09  18:53:07  ian    Reworked protocol interface     Revision 1.1  1991/09/10  19:47:55  ian    Initial revision     */
end_comment

begin_comment
comment|/* The sprotocol structure holds information and functions for a specific    protocol (e.g. the 'g' protocol).  */
end_comment

begin_struct
struct|struct
name|sprotocol
block|{
comment|/* The name of the protocol (e.g. 'g').  */
name|char
name|bname
decl_stmt|;
comment|/* Whether the protocol is full-duplex or not; a full-duplex protocol      can transfer files in both directions at once.  */
name|boolean
name|ffullduplex
decl_stmt|;
comment|/* Reliability requirements, an or of RELIABLE_xxx defines from      port.h.  */
name|int
name|ireliable
decl_stmt|;
comment|/* Protocol parameter commands.  */
name|struct
name|scmdtab
modifier|*
name|qcmds
decl_stmt|;
comment|/* A routine to start the protocol; the argument is whether the caller      is the master or the slave.  Returns TRUE if the protocol has been      succesfully started, FALSE otherwise.  */
name|boolean
argument_list|(
argument|*pfstart
argument_list|)
name|P
argument_list|(
operator|(
name|boolean
name|fmaster
operator|)
argument_list|)
expr_stmt|;
comment|/* Shutdown the protocol.  */
name|boolean
argument_list|(
argument|*pfshutdown
argument_list|)
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Send a command to the other side.  */
name|boolean
argument_list|(
argument|*pfsendcmd
argument_list|)
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|z
operator|)
argument_list|)
expr_stmt|;
comment|/* Get buffer to space to fill with data.  This should set *pcdata      to the amount of data desired.  */
name|char
operator|*
operator|(
operator|*
name|pzgetspace
operator|)
name|P
argument_list|(
operator|(
name|int
operator|*
name|pcdata
operator|)
argument_list|)
expr_stmt|;
comment|/* Send data to the other side.  The first argument must be a return      value of pzgetspace.  */
name|boolean
argument_list|(
argument|*pfsenddata
argument_list|)
name|P
argument_list|(
operator|(
name|char
operator|*
name|z
operator|,
name|int
name|c
operator|)
argument_list|)
expr_stmt|;
comment|/* Process received data in abPrecbuf, calling fgot_data as      necessary.  If fgot_data sets *pfexit, it should get passed back      out.  */
name|boolean
argument_list|(
argument|*pfprocess
argument_list|)
name|P
argument_list|(
operator|(
name|boolean
operator|*
name|pfexit
operator|)
argument_list|)
expr_stmt|;
comment|/* Wait for data to come in and call fgot_data with it until      fgot_data sets *pfexit.  */
name|boolean
argument_list|(
argument|*pfwait
argument_list|)
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Handle any file level actions that need to be taken.  If fstart      is TRUE, a file transfer is beginning.  If fstart is FALSE a file      transfer is ending, and *pfredo should be set to TRUE if the file      transfer needs to be redone.  If fstart and fsend are both TRUE,      cbytes holds the size of the file or -1 if it is unknown.  */
name|boolean
argument_list|(
argument|*pffile
argument_list|)
name|P
argument_list|(
operator|(
name|boolean
name|fstart
operator|,
name|boolean
name|fsend
operator|,
name|boolean
operator|*
name|pfredo
operator|,
name|long
name|cbytes
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Send a file.    fmaster -- whether this job is the master    e -- open file (send if fmaster, receive if ! fmaster)    qcmd -- command to execute    zmail -- user to notify on source system.    ztosys -- system the file is being sent to    fnew -- whether the system is running our code or not     If this is called with fmaster TRUE, it is responsible for    informing the slave that it wants to send a file; the slave will    eventually call freceive_file.  The file should then be    transferred.  When the transfer is complete, then if fmaster is    TRUE and zmail is not NULL, mail should be sent to the user zmail;    if fmaster is FALSE and qcmd->znotify is not NULL, mail should be    sent to the user qcmd->znotify.  After the file transfer is    complete, the work queue entry should be removed by calling    fsysdep_did_work (pseq).  Most of the latter stuff is handled by    fsent_file.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsend_file
name|P
argument_list|(
operator|(
name|boolean
name|fmaster
operator|,
name|openfile_t
name|e
operator|,
specifier|const
expr|struct
name|scmd
operator|*
name|qcmd
operator|,
specifier|const
name|char
operator|*
name|zmail
operator|,
specifier|const
name|char
operator|*
name|ztosys
operator|,
name|boolean
name|fnew
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Receive a file.    fmaster -- whether this job is the master    e -- open file (receive if fmaster, send if ! fmaster)    qcmd -- command to execute    zmail -- user to notify on destination system.    zfromsys -- system the file is from    fnew -- whether the system is running our code or not     The field qcmd->znotify will not be meaningful.     If this is called with fmaster TRUE, it is responsible for    informing the slave that it wants to receive a file; the slave will    eventually call pfsend.  The file should then be transferred.  When    the transfer is complete, if fmaster is TRUE and zmail is not NULL,    mail should be sent to the user zmail.  After the file transfer is    complete, the work queue entry should be removed by calling    fsysdep_did_work (pseq).  Most of the latter work is done by    freceived_file.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|freceive_file
name|P
argument_list|(
operator|(
name|boolean
name|fmaster
operator|,
name|openfile_t
name|e
operator|,
specifier|const
expr|struct
name|scmd
operator|*
name|qcmd
operator|,
specifier|const
name|char
operator|*
name|zmail
operator|,
specifier|const
name|char
operator|*
name|zfromsys
operator|,
name|boolean
name|fnew
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Request a transfer.  This is only called by the master.    qcmd -- command (only pseq, zfrom, zto, zuser, zoptions valid)     This function should tell the slave that the master wants to    execute a transfer.  The slave may queue up work to do.  The return    value is FALSE if some error occurred.  This always does its work    immediately, so it does not use qcmd->pseq.  It sets *pfnever to    TRUE if the request was denied.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fxcmd
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|scmd
operator|*
name|qcmd
operator|,
name|boolean
operator|*
name|pfnever
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Confirm a transfer.  This is only called by the slave.  This is    called after a transfer request has been received to confirm that    it was successful.  If it was not successful, pffail will be    called with a first argument of 'X'.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fxcmd_confirm
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fail.  This is called by the slave if it is unable to execute some    request by the master.  The argument bcmd is the request which    failed ('S' or 'R').  The argument twhy indicates the reason.  The    return value is FALSE if some error occurred.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|ftransfer_fail
name|P
argument_list|(
operator|(
name|int
name|bcmd
operator|,
expr|enum
name|tfailure
name|twhy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a command from the master.  The strings in the command argument    are set to point into a static buffer.  If fmaster is TRUE, this    should not wait if there is no command pending; if fmaster is FALSE    it should wait until a command is received.  The field qcmd->pseq    will be set to NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fgetcmd
name|P
argument_list|(
operator|(
name|boolean
name|fmaster
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
comment|/* Get a command string from the other system, where the nature of a    command string is defined by the protocol.  The return value is    fragile, and must be saved if any other protocol related calls are    made.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zgetcmd
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hangup.  This is only called by the master, and indicates that the    master is ready to relinquish control; after calling it, the master    becomes the slave.  If the original slave has no work to do, it    confirms the hangup (the new slave will wind up getting a 'Y'    command from fgetcmd).  If the the original slave has work to do,    it becomes the master (it also denies the hangup, but this is not    seen outside the protocol code).  The return value of fhangup is    FALSE if some error occurred.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fhangup_request
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hangup reply.  This is only called by the slave if the master has    sent a hangup request.  If fconfirm is TRUE, the slave is    confirming the hangup, in which case the protocol should be shut    down.  If fconfirm is FALSE, the slave will become the master.  The    return value is FALSE if some error occurred.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fhangup_reply
name|P
argument_list|(
operator|(
name|boolean
name|fconfirm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Handle data received by a protocol.  This is called by the protocol    specific routines as data comes in.  The protocol specific routines    may know that the data is destined for a command or a file, in    which case they should pass fcmd and ffile appropriately.    Otherwise they may both be passed as FALSE, in which case if a file    recieve is in progress the data will be sent to the file, otherwise    to a command.  This will set *pfexit to TRUE if the file or command    is finished.  A file is finished when a zero length buffer is    passed.  A command is finished when a string containing a null byte    is passed.  This will return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fgot_data
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdata
operator|,
name|int
name|cdata
operator|,
name|boolean
name|fcmd
operator|,
name|boolean
name|ffile
operator|,
name|boolean
operator|*
name|pfexit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send data to the other system.  If the fread argument is TRUE, this    will also receive data into the receive buffer abPrecbuf; fread is    passed as TRUE if the protocol expects data to be coming back, to    make sure the input buffer does not fill up.  Returns FALSE on    error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsend_data
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsend
operator|,
name|int
name|csend
operator|,
name|boolean
name|fdoread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Receive data from the other system when there is no data to send.    The cneed argument is the amount of data desired and the ctimeout    argument is the timeout in seconds.  This will set *pcrec to the    amount of data received.  It will return FALSE on error.  If a    timeout occurs, it will return TRUE with *pcrec set to zero.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|freceive_data
name|P
argument_list|(
operator|(
name|int
name|cneed
operator|,
name|int
operator|*
name|pcrec
operator|,
name|int
name|ctimeout
operator|,
name|boolean
name|freport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Protocol in use.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sprotocol
modifier|*
name|qProto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The size of the receive buffer.  */
end_comment

begin_define
define|#
directive|define
name|CRECBUFLEN
value|(16384)
end_define

begin_comment
comment|/* Buffer to hold received data.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|abPrecbuf
index|[
name|CRECBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index of start of data in abPrecbuf.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iPrecstart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index of end of data (first byte not included in data) in abPrecbuf.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iPrecend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether an unexpected shutdown is OK now; this is used to avoid    giving a warning for systems that hang up in a hurry.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fPerror_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prototypes for 'g' protocol functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|scmdtab
name|asGproto_params
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fgstart
name|P
argument_list|(
operator|(
name|boolean
name|fmaster
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fgshutdown
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fgsendcmd
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zggetspace
name|P
argument_list|(
operator|(
name|int
operator|*
name|pcdata
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fgsenddata
name|P
argument_list|(
operator|(
name|char
operator|*
name|z
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fgprocess
name|P
argument_list|(
operator|(
name|boolean
operator|*
name|pfexit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fgwait
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prototypes for 'f' protocol functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|scmdtab
name|asFproto_params
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ffstart
name|P
argument_list|(
operator|(
name|boolean
name|fmaster
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ffshutdown
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ffsendcmd
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zfgetspace
name|P
argument_list|(
operator|(
name|int
operator|*
name|pcdata
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ffsenddata
name|P
argument_list|(
operator|(
name|char
operator|*
name|z
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ffprocess
name|P
argument_list|(
operator|(
name|boolean
operator|*
name|pfexit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ffwait
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fffile
name|P
argument_list|(
operator|(
name|boolean
name|fstart
operator|,
name|boolean
name|fsend
operator|,
name|boolean
operator|*
name|pfredo
operator|,
name|long
name|cbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prototypes for 't' protocol functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|scmdtab
name|asTproto_params
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftstart
name|P
argument_list|(
operator|(
name|boolean
name|fmaster
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftshutdown
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftsendcmd
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ztgetspace
name|P
argument_list|(
operator|(
name|int
operator|*
name|pcdata
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftsenddata
name|P
argument_list|(
operator|(
name|char
operator|*
name|z
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftprocess
name|P
argument_list|(
operator|(
name|boolean
operator|*
name|pfexit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftwait
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftfile
name|P
argument_list|(
operator|(
name|boolean
name|fstart
operator|,
name|boolean
name|fsend
operator|,
name|boolean
operator|*
name|pfredo
operator|,
name|long
name|cbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prototypes for 'e' protocol functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|scmdtab
name|asEproto_params
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|festart
name|P
argument_list|(
operator|(
name|boolean
name|fmaster
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|feshutdown
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fesendcmd
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zegetspace
name|P
argument_list|(
operator|(
name|int
operator|*
name|pcdata
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fesenddata
name|P
argument_list|(
operator|(
name|char
operator|*
name|z
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|feprocess
name|P
argument_list|(
operator|(
name|boolean
operator|*
name|pfexit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fewait
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fefile
name|P
argument_list|(
operator|(
name|boolean
name|fstart
operator|,
name|boolean
name|fsend
operator|,
name|boolean
operator|*
name|pfredo
operator|,
name|long
name|cbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

