begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* port.h    Header file for routines which manipulate ports.     Copyright (C) 1991, 1992 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o AIRS, P.O. Box 520, Waltham, MA 02254.     $Log: port.h,v $    Revision 1.13  1992/03/12  19:56:10  ian    Debugging based on types rather than number     Revision 1.12  1992/03/10  21:47:39  ian    Added protocol command for ports     Revision 1.11  1992/03/08  04:56:21  ian    Peter da Silva: added ``lockname'' command for ports     Revision 1.10  1992/03/04  00:36:44  ian    Michael Richardson: better chat script debugging     Revision 1.9  1992/02/08  03:54:18  ian    Include<string.h> only in<uucp.h>, added 1992 copyright     Revision 1.8  1991/12/17  23:14:08  ian    T. William Wells: allow dialer complete and abort to be chat scripts     Revision 1.7  1991/12/15  03:42:33  ian    Added tprocess_chat_cmd for all chat commands, and added CMDTABTYPE_PREFIX     Revision 1.6  1991/11/14  03:20:13  ian    Added seven-bit and reliable commands to help when selecting protocols     Revision 1.5  1991/11/13  20:38:00  ian    Added TCP port type for connections over TCP     Revision 1.4  1991/11/11  23:47:24  ian    Added chat-program to run a program to do a chat script     Revision 1.3  1991/11/11  16:59:05  ian    Eliminate fread_port_info, allow NULL pflock arg to ffind_port     Revision 1.2  1991/11/11  00:39:45  ian    Open port in seven bit mode, added fport_set to change to eight bit     Revision 1.1  1991/09/10  19:47:55  ian    Initial revision     */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PORT_H
end_ifndef

begin_define
define|#
directive|define
name|PORT_H
end_define

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_comment
comment|/* Information kept about using stdin as a port.  */
end_comment

begin_struct
struct|struct
name|sstdin_port
block|{
name|struct
name|ssysdep_stdin_port
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The smodem_port structure holds the information we keep about a modem    port.  */
end_comment

begin_struct
struct|struct
name|smodem_port
block|{
comment|/* The device name.  If NULL, use the port name instead.  */
specifier|const
name|char
modifier|*
name|zdevice
decl_stmt|;
comment|/* The device name to output dialer instructions to.  If NULL, use      the normal port.  */
specifier|const
name|char
modifier|*
name|zdial_device
decl_stmt|;
comment|/* The default baud rate.  */
name|long
name|ibaud
decl_stmt|;
comment|/* The low baud rate, if a range is used.  */
name|long
name|ilowbaud
decl_stmt|;
comment|/* The high baud rate, if a range is used.  */
name|long
name|ihighbaud
decl_stmt|;
comment|/* Whether to wait for carrier detect after dialing.  */
name|boolean
name|fcarrier
decl_stmt|;
comment|/* The name of the dialer to use.  */
specifier|const
name|char
modifier|*
name|zdialer
decl_stmt|;
comment|/* Specific dialer information, if zdialer is NULL.  */
name|struct
name|sdialer
modifier|*
name|qdialer
decl_stmt|;
comment|/* System dependent modem port stuff.  */
name|struct
name|ssysdep_modem_port
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information kept about a direct port.  */
end_comment

begin_struct
struct|struct
name|sdirect_port
block|{
comment|/* The device to use (if NULL, use the port name).  */
specifier|const
name|char
modifier|*
name|zdevice
decl_stmt|;
comment|/* The baud rate to communicate at.  */
name|long
name|ibaud
decl_stmt|;
comment|/* System dependent direct port stuff.  */
name|struct
name|ssysdep_direct_port
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|HAVE_TCP
end_if

begin_comment
comment|/* Information kept about a TCP port.  */
end_comment

begin_struct
struct|struct
name|stcp_port
block|{
comment|/* The file descriptor.  */
name|int
name|o
decl_stmt|;
comment|/* The TCP port number to use.  */
specifier|const
name|char
modifier|*
name|zport
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TCP */
end_comment

begin_comment
comment|/* Types of ports.  The order of this enumeration must be the same    as the initializer for asPortcmds and azPtype_names.  */
end_comment

begin_enum
enum|enum
name|tporttype
block|{
name|PORTTYPE_STDIN
block|,
name|PORTTYPE_MODEM
block|,
name|PORTTYPE_DIRECT
if|#
directive|if
name|HAVE_TCP
block|,
name|PORTTYPE_TCP
endif|#
directive|endif
block|}
enum|;
end_enum

begin_comment
comment|/* Port settings.  Currently we only have seven bit and eight bit    ports.  The only real difference between these is that seven bit    ports can do XON/XOFF.  */
end_comment

begin_enum
enum|enum
name|tportsetting
block|{
name|PORTSETTING_EIGHT
block|,
name|PORTSETTING_SEVEN
block|}
enum|;
end_enum

begin_comment
comment|/* Reliability bits.  These bits are used to decide which protocol to    run.  A given protocol will have a set of these bits, and each of    them must be turned on for the port before we will permit that    protocol to be used.  Of course, this can always be overridden by    using the ``protocols'' command in the system file.  Reliability    bits can be specified by both ports and dialers.  */
end_comment

begin_comment
comment|/* Whether a set of reliability bits is given (0 means no    information).  */
end_comment

begin_define
define|#
directive|define
name|RELIABLE_SPECIFIED
value|(01)
end_define

begin_comment
comment|/* Whether the connection is eight bit transparent.  */
end_comment

begin_define
define|#
directive|define
name|RELIABLE_EIGHT
value|(02)
end_define

begin_comment
comment|/* Whether the connection is error-free.  */
end_comment

begin_define
define|#
directive|define
name|RELIABLE_RELIABLE
value|(04)
end_define

begin_comment
comment|/* Whether the connection is end-to-end reliable (e.g. TCP).  */
end_comment

begin_define
define|#
directive|define
name|RELIABLE_ENDTOEND
value|(010)
end_define

begin_comment
comment|/* Information kept about a port.  */
end_comment

begin_struct
struct|struct
name|sport
block|{
comment|/* The name of the port.  */
specifier|const
name|char
modifier|*
name|zname
decl_stmt|;
comment|/* The type of the port.  */
name|enum
name|tporttype
name|ttype
decl_stmt|;
comment|/* The protocol string for the port.  */
specifier|const
name|char
modifier|*
name|zprotocols
decl_stmt|;
comment|/* The number of protocol parameter entries.  */
name|int
name|cproto_params
decl_stmt|;
comment|/* The protocol parameter string.  */
name|struct
name|sproto_param
modifier|*
name|qproto_params
decl_stmt|;
comment|/* The set of reliability bits.  */
name|int
name|ireliable
decl_stmt|;
comment|/* The lock file name to use.  */
specifier|const
name|char
modifier|*
name|zlockname
decl_stmt|;
comment|/* The type specific information.  */
union|union
block|{
name|struct
name|sstdin_port
name|sstdin
decl_stmt|;
name|struct
name|smodem_port
name|smodem
decl_stmt|;
name|struct
name|sdirect_port
name|sdirect
decl_stmt|;
if|#
directive|if
name|HAVE_TCP
name|struct
name|stcp_port
name|stcp
decl_stmt|;
endif|#
directive|endif
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information kept about a dialer.  */
end_comment

begin_struct
struct|struct
name|sdialer
block|{
comment|/* The name.  */
specifier|const
name|char
modifier|*
name|zname
decl_stmt|;
comment|/* Chat script.  */
name|struct
name|schat_info
name|schat
decl_stmt|;
comment|/* The ``wait for dialtone'' string.  */
specifier|const
name|char
modifier|*
name|zdialtone
decl_stmt|;
comment|/* The ``pause'' string.  */
specifier|const
name|char
modifier|*
name|zpause
decl_stmt|;
comment|/* Whether the dialer supports carrier.  */
name|boolean
name|fcarrier
decl_stmt|;
comment|/* How many seconds to wait for carrier (if fcarrier TRUE).  */
name|int
name|ccarrier_wait
decl_stmt|;
comment|/* Whether to toggle DTR.  */
name|boolean
name|fdtr_toggle
decl_stmt|;
comment|/* Whether to wait after toggling DTR.  */
name|boolean
name|fdtr_toggle_wait
decl_stmt|;
comment|/* The chat script to use when a call is complete.  */
name|struct
name|schat_info
name|scomplete
decl_stmt|;
comment|/* The chat script to use when a call is aborted.  */
name|struct
name|schat_info
name|sabort
decl_stmt|;
comment|/* Number of protocol parameters.  */
name|int
name|cproto_params
decl_stmt|;
comment|/* The protocol parameters.  */
name|struct
name|sproto_param
modifier|*
name|qproto_params
decl_stmt|;
comment|/* The set of reliability bits.  */
name|int
name|ireliable
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A command table holds the functions which implement actions for    each different kind of port.  */
end_comment

begin_struct
struct|struct
name|sportcmds
block|{
comment|/* Lock the port.  The fin argument is TRUE if the port is to be      used for an incoming call, FALSE for an outgoing call.  */
name|boolean
argument_list|(
argument|*pflock
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fin
operator|)
argument_list|)
expr_stmt|;
comment|/* Open the port.  */
name|boolean
argument_list|(
argument|*pfopen
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|long
name|ibaud
operator|,
name|boolean
name|fwait
operator|)
argument_list|)
expr_stmt|;
comment|/* Close the port.  */
name|boolean
argument_list|(
argument|*pfclose
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fsuccess
operator|)
argument_list|)
expr_stmt|;
comment|/* Reset the port so that another call may be accepted.  */
name|boolean
argument_list|(
argument|*pfreset
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
expr_stmt|;
comment|/* Dial a number on a port (may be NULL).  This set *pcproto_params      and *pqproto_params to the protocol parameters of the dialer, if      any, and *pireliable to the reliable code of the dialer (a hack      to avoid reading dialer information twice).  */
name|boolean
argument_list|(
argument|*pfdial
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|,
name|int
operator|*
name|pcproto_params
operator|,
expr|struct
name|sproto_param
operator|*
operator|*
name|pqproto_params
operator|,
name|int
operator|*
name|pireliable
operator|)
argument_list|)
expr_stmt|;
comment|/* Read data from the port, with a timeout in seconds.  When called      *pclen is the length of the buffer; on successful return *pclen      is the number of bytes read into the buffer.  The cmin argument      is the minimum number of bytes to read before returning ahead      of a timeout.  */
name|boolean
argument_list|(
argument|*pfread
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|char
operator|*
name|zbuf
operator|,
name|int
operator|*
name|pclen
operator|,
name|int
name|cmin
operator|,
name|int
name|ctimeout
operator|,
name|boolean
name|freport
operator|)
argument_list|)
expr_stmt|;
comment|/* Write data to the port.  */
name|boolean
argument_list|(
argument|*pfwrite
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zbuf
operator|,
name|int
name|clen
operator|)
argument_list|)
expr_stmt|;
comment|/* Read and write data to the port.  This reads and writes data      until either all passed in data has been written or the read      buffer has been filled.  When called *pcread is the size of      the read buffer and *pcwrite is the number of bytes to write;      on successful return *pcread is the number of bytes read and      *pcwrite is the number of bytes written.  */
name|boolean
argument_list|(
argument|*pfio
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|)
argument_list|)
expr_stmt|;
comment|/* Send a break character.  This may be NULL.  */
name|boolean
argument_list|(
argument|*pfbreak
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
expr_stmt|;
comment|/* Change the port setting.  This may be NULL.  */
name|boolean
argument_list|(
argument|*pfset
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
expr|enum
name|tportsetting
name|tset
operator|)
argument_list|)
expr_stmt|;
comment|/* Run a chat program on a port.  */
name|boolean
argument_list|(
argument|*pfchat
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zprog
operator|)
argument_list|)
expr_stmt|;
comment|/* Get the baud rate of a port.  */
name|long
argument_list|(
argument|*pibaud
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Only one port can be open during an execution of uucico, and we    keep it in this global variable.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sport
modifier|*
name|qPort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The table of port functions.  The order of entries in this table    must match the tporttype enumeration.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sportcmds
name|asPortcmds
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Port functions.  */
end_comment

begin_comment
comment|/* Process a port command.  The pvar argument should point to a pointer    to type struct sport.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tcmdtabret
name|tprocess_port_cmd
name|P
argument_list|(
operator|(
name|int
name|cargs
operator|,
name|char
operator|*
operator|*
name|azargs
operator|,
name|pointer
name|pvar
operator|,
specifier|const
name|char
operator|*
name|zerr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read dialer information.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fread_dialer_info
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdialer
operator|,
expr|struct
name|sdialer
operator|*
name|qdialer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HAVE_V2_CONFIG
end_if

begin_comment
comment|/* Read information from the V2 configuration files.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fv2_find_port
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zname
operator|,
name|long
name|ibaud
operator|,
name|long
name|ihighbaud
operator|,
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
argument_list|(
argument|*pflock
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
operator|,
name|boolean
name|fin
operator|)
argument_list|)
operator|,
name|boolean
operator|*
name|pffound
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_V2_CONFIG */
end_comment

begin_if
if|#
directive|if
name|HAVE_BNU_CONFIG
end_if

begin_comment
comment|/* Read information from the BNU configuration files.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fbnu_find_port
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zname
operator|,
name|long
name|ibaud
operator|,
name|long
name|ihighbaud
operator|,
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
argument_list|(
argument|*pflock
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
operator|,
name|boolean
name|fin
operator|)
argument_list|)
operator|,
name|boolean
operator|*
name|pffound
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fbnu_read_dialer_info
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdialer
operator|,
expr|struct
name|sdialer
operator|*
name|qdialer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BNU_CONFIG */
end_comment

begin_comment
comment|/* Lock a port.  The fin argument is TRUE if the port is to be used    for an incoming call; certains type of Unix locking need this    information because they need to open the port.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_lock
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fin
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find and lock a port.  If the port name is NULL, the matching is    done only on the baud rate.  If the baud rate is 0, the matching is    done only on the port name.  Otherwise the port must match both    name and baud rate.  If ihighbaud is not 0, the baud rate of the    port must fall between ibaud and ihighbaud.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|ffind_port
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zname
operator|,
name|long
name|ibaud
operator|,
name|long
name|ihighbaud
operator|,
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
argument_list|(
argument|*pflock
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
operator|,
name|boolean
name|fin
operator|)
argument_list|)
operator|,
name|boolean
name|freport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open a port.  If ibaud is 0, the natural baud rate of the port is    used.  If ihighbaud is not 0, fport_open figures out what baud rate    to use based on the port's baud rate.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_open
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|long
name|ibaud
operator|,
name|long
name|ihighbaud
operator|,
name|boolean
name|fwait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Close and unlock a port.  The fsuccess argument is TRUE if the    conversation on the port was completed normally, FALSE if it is    being aborted.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_close
name|P
argument_list|(
operator|(
name|boolean
name|fsuccess
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reset a port such that another call may be accepted.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_reset
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dial out on a port.  This is permitted to return a set of protocol    parameters and reliability bits for the dialer (yes, it's a hack;    this permits protocol parameters to set for particular modems).  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_dial
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|,
name|int
operator|*
name|pcproto_params
operator|,
expr|struct
name|sproto_param
operator|*
operator|*
name|pqproto_params
operator|,
name|int
operator|*
name|pireliable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read from a port.    zbuf -- buffer to read bytes into    *pclen on call -- length of zbuf    *pclen on successful return -- number of bytes read    cmin -- minimum number of bytes to read before returning ahead of timeout    ctimeout -- timeout in seconds, 0 if none    freport -- whether to report errors.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_read
name|P
argument_list|(
operator|(
name|char
operator|*
name|zbuf
operator|,
name|int
operator|*
name|pclen
operator|,
name|int
name|cmin
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
comment|/* Write to a port.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_write
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zbuf
operator|,
name|int
name|cbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read and write to a port.  This reads and writes data until either    all passed-in data has been written or the read buffer is full.     zwrite -- buffer to write bytes from    *pcwrite on call -- number of bytes to write    *pcwrite on successful return -- number of bytes written    zread -- buffer to read bytes into    *pcread on call -- size of read buffer    *pcread on successful return -- number of bytes read.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_io
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send a break character to a port.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_break
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Change the settings of a port.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_set
name|P
argument_list|(
operator|(
expr|enum
name|tportsetting
name|tset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the baud rate of a port.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|iport_baud
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do a chat script with a system.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fchat
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|schat_info
operator|*
name|qchat
operator|,
specifier|const
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|,
specifier|const
expr|struct
name|sdialer
operator|*
name|qdial
operator|,
specifier|const
name|char
operator|*
name|zphone
operator|,
name|boolean
name|ftranslate
operator|,
specifier|const
name|char
operator|*
name|zport
operator|,
name|long
name|ibaud
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allow no carrier during a chat script.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_no_carrier
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Require carrier during a chat script.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_need_carrier
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run a chat program on a port.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fport_run_chat
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zprog
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Modem routines used when dialing.  */
end_comment

begin_comment
comment|/* Begin dialing out.  This should open the dialer device if there is    one, toggle DTR if requested and possible, and tell the port to    ignore carrier.  It should return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_begin_dial
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
expr|struct
name|sdialer
operator|*
name|qdial
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell the modem to ignore carrier.  This is called when \M is    encountered in a dialer chat script.  It should return FALSE on    error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_no_carrier
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell the modem that carrier is required.  This is called when \m is    encountered in a dialer chat script.  It should return FALSE on    error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_need_carrier
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish dialing out on a modem.  This should close the dialer device    if there is one.  If the dialer and the port both support carrier,    the port should be told to pay attention to carrier.  If it is    possible to wait for carrier to come on, and the dialer and the    port both the port support carrier, it should wait until carrier    comes on.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_end_dial
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
expr|struct
name|sdialer
operator|*
name|qdial
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Port routines for stdin ports.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_lock
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fin
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_open
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|long
name|ibaud
operator|,
name|boolean
name|fwait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_close
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fsuccess
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_reset
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_read
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|,
name|int
name|cmin
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

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_write
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
name|cwrite
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_io
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_break
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_set
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
expr|enum
name|tportsetting
name|tset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_chat
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zprog
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|isysdep_stdin_baud
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Port routines for modem ports.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_lock
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fin
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_open
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|long
name|ibaud
operator|,
name|boolean
name|fwait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_close
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fsuccess
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_reset
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fmodem_dial
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|,
name|int
operator|*
name|pcproto_params
operator|,
expr|struct
name|sproto_param
operator|*
operator|*
name|pqproto_params
operator|,
name|int
operator|*
name|pireliable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_read
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|,
name|int
name|cmin
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

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_write
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
name|cwrite
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_io
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_break
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_set
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
expr|enum
name|tportsetting
name|tset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_chat
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zprog
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|isysdep_modem_baud
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Port routines for direct connections.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_lock
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fin
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_open
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|long
name|ibaud
operator|,
name|boolean
name|fwait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_close
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fsuccess
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_reset
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_read
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|,
name|int
name|cmin
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

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_write
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
name|cwrite
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_io
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_break
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_set
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
expr|enum
name|tportsetting
name|tset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_chat
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zprog
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|isysdep_direct_baud
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HAVE_TCP
end_if

begin_comment
comment|/* Port routines for TCP ports.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|ftcp_lock
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fin
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftcp_open
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|long
name|ibaud
operator|,
name|boolean
name|fwait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftcp_close
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|boolean
name|fsuccess
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftcp_reset
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ftcp_dial
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|,
name|int
operator|*
name|pcproto_params
operator|,
expr|struct
name|sproto_param
operator|*
operator|*
name|pqproto_params
operator|,
name|int
operator|*
name|pireliable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_tcp_read
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|,
name|int
name|cmin
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

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_tcp_write
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
name|cwrite
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_tcp_io
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|int
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|int
operator|*
name|pcread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_tcp_chat
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zprog
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|itcp_baud
name|P
argument_list|(
operator|(
expr|struct
name|sport
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TCP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

