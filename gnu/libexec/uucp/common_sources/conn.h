begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* conn.h    Header file for routines which manipulate connections.     Copyright (C) 1991, 1992, 1993, 1994 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONN_H
end_ifndef

begin_define
define|#
directive|define
name|CONN_H
end_define

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
name|uuconf_dialer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uuconf_chat
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This structure represents a connection.  */
end_comment

begin_struct
struct|struct
name|sconnection
block|{
comment|/* Pointer to command table for this type of connection.  */
specifier|const
name|struct
name|sconncmds
modifier|*
name|qcmds
decl_stmt|;
comment|/* Pointer to system dependent information.  */
name|pointer
name|psysdep
decl_stmt|;
comment|/* Pointer to system independent information.  */
name|struct
name|uuconf_port
modifier|*
name|qport
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Whether fconn_dial got a dialer.  */
end_comment

begin_enum
enum|enum
name|tdialerfound
block|{
comment|/* Did not find a dialer.  */
name|DIALERFOUND_FALSE
block|,
comment|/* Found a dialer which does not need to be freed.  */
name|DIALERFOUND_TRUE
block|,
comment|/* Found a dialer which does need to be freed.  */
name|DIALERFOUND_FREE
block|}
enum|;
end_enum

begin_comment
comment|/* Parity settings to pass to fconn_set.  */
end_comment

begin_enum
enum|enum
name|tparitysetting
block|{
comment|/* Do not change output parity generation.  */
name|PARITYSETTING_DEFAULT
block|,
comment|/* No parity (all eight output bits used).  */
name|PARITYSETTING_NONE
block|,
comment|/* Even parity.  */
name|PARITYSETTING_EVEN
block|,
comment|/* Odd parity.  */
name|PARITYSETTING_ODD
block|,
comment|/* Mark parity.  */
name|PARITYSETTING_MARK
block|,
comment|/* Space parity.  */
name|PARITYSETTING_SPACE
block|}
enum|;
end_enum

begin_comment
comment|/* Type of strip control argument to fconn_set.  */
end_comment

begin_enum
enum|enum
name|tstripsetting
block|{
comment|/* Do not change the stripping of input characters.  */
name|STRIPSETTING_DEFAULT
block|,
comment|/* Do not strip input characters to seven bits.  */
name|STRIPSETTING_EIGHTBITS
block|,
comment|/* Strip input characters to seven bits.  */
name|STRIPSETTING_SEVENBITS
block|}
enum|;
end_enum

begin_comment
comment|/* Type of XON/XOFF control argument to fconn_set.  */
end_comment

begin_enum
enum|enum
name|txonxoffsetting
block|{
comment|/* Do not change XON/XOFF handshake setting.  */
name|XONXOFF_DEFAULT
block|,
comment|/* Do not do XON/XOFF handshaking.  */
name|XONXOFF_OFF
block|,
comment|/* Do XON/XOFF handshaking.  */
name|XONXOFF_ON
block|}
enum|;
end_enum

begin_comment
comment|/* A command table holds the functions which implement actions for    each different kind of connection.  */
end_comment

begin_struct
struct|struct
name|sconncmds
block|{
comment|/* Free up a connection.  */
name|void
argument_list|(
argument|*pufree
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
expr_stmt|;
comment|/* Lock the connection.  The fin argument is TRUE if the connection      is to be used for an incoming call.  May be NULL.  */
name|boolean
argument_list|(
argument|*pflock
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|boolean
name|fin
operator|)
argument_list|)
expr_stmt|;
comment|/* Unlock the connection.  May be NULL.  */
name|boolean
argument_list|(
argument|*pfunlock
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
expr_stmt|;
comment|/* Open the connection.  */
name|boolean
argument_list|(
argument|*pfopen
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|long
name|ibaud
operator|,
name|boolean
name|fwait
operator|)
argument_list|)
expr_stmt|;
comment|/* Close the connection.  */
name|boolean
argument_list|(
argument|*pfclose
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|pointer
name|puuconf
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
operator|,
name|boolean
name|fsuccess
operator|)
argument_list|)
expr_stmt|;
comment|/* Dial a number on a connection.  This set *qdialer to the dialer      used, if any, and sets *ptdialerfound appropriately.  The qsys      and zphone arguments are for the chat script.  This field may be      NULL.  */
name|boolean
argument_list|(
argument|*pfdial
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|pointer
name|puuconf
operator|,
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zphone
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
operator|,
expr|enum
name|tdialerfound
operator|*
name|ptdialerfound
operator|)
argument_list|)
expr_stmt|;
comment|/* Read data from a connection, with a timeout in seconds.  When      called *pclen is the length of the buffer; on successful return      *pclen is the number of bytes read into the buffer.  The cmin      argument is the minimum number of bytes to read before returning      ahead of a timeout.  */
name|boolean
argument_list|(
argument|*pfread
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
name|zbuf
operator|,
name|size_t
operator|*
name|pclen
operator|,
name|size_t
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
comment|/* Write data to the connection.  */
name|boolean
argument_list|(
argument|*pfwrite
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
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
expr_stmt|;
comment|/* Read and write data to the connection.  This reads and writes      data until either all passed in data has been written or the read      buffer has been filled.  When called *pcread is the size of the      read buffer and *pcwrite is the number of bytes to write; on      successful return *pcread is the number of bytes read and      *pcwrite is the number of bytes written.  */
name|boolean
argument_list|(
argument|*pfio
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|size_t
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|size_t
operator|*
name|pcread
operator|)
argument_list|)
expr_stmt|;
comment|/* Send a break character.  This field may be NULL.  */
name|boolean
argument_list|(
argument|*pfbreak
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
expr_stmt|;
comment|/* Change the connection setting.  This field may be NULL.  */
name|boolean
argument_list|(
argument|*pfset
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
expr|enum
name|tparitysetting
name|tparity
operator|,
expr|enum
name|tstripsetting
name|tstrip
operator|,
expr|enum
name|txonxoffsetting
name|txonxoff
operator|)
argument_list|)
expr_stmt|;
comment|/* Require or ignore carrer.  This field may be NULL.  */
name|boolean
argument_list|(
argument|*pfcarrier
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|boolean
name|fcarrier
operator|)
argument_list|)
expr_stmt|;
comment|/* Run a chat program on a connection.  */
name|boolean
argument_list|(
argument|*pfchat
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
operator|*
name|pzprog
operator|)
argument_list|)
expr_stmt|;
comment|/* Get the baud rate of a connection.  This field may be NULL.  */
name|long
argument_list|(
argument|*pibaud
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Connection functions.  */
end_comment

begin_comment
comment|/* Initialize a connection.  This must be called before any of the    other connection functions are called.  It initializes the fields    of qconn.  If qport is NULL, this opens standard input as a port    using type ttype.  This function returns FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_init
name|P
argument_list|(
operator|(
expr|struct
name|uuconf_port
operator|*
name|qport
operator|,
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
expr|enum
name|uuconf_porttype
name|ttype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free up connection data.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uconn_free
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lock a connection.  The fin argument is TRUE if the port is to be    used for an incoming call; certains type of Unix locking need this    information because they need to open the port.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_lock
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|boolean
name|fin
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unlock a connection.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_unlock
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open a connection.  If ibaud is 0, the natural baud rate of the    port is used.  If ihighbaud is not 0, fconn_open chooses the    highest supported baud rate between ibaud and ihighbaud.  If fwait    is TRUE, this should wait for an incoming call.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_open
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
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
comment|/* Close a connection.  The fsuccess argument is TRUE if the    conversation completed normally, FALSE if it is being aborted.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_close
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|pointer
name|puuconf
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
operator|,
name|boolean
name|fsuccess
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dial out on a connection.  The qsys and zphone arguments are for    the chat scripts; zphone is the phone number to dial.  If qdialer    is not NULL, *qdialer will be set to the dialer information used if    any; *ptdialerfound will be set appropriately.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_dial
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|q
operator|,
name|pointer
name|puuconf
operator|,
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zphone
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
operator|,
expr|enum
name|tdialerfound
operator|*
name|ptdialerfound
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read from a connection.    zbuf -- buffer to read bytes into    *pclen on call -- length of zbuf    *pclen on successful return -- number of bytes read    cmin -- minimum number of bytes to read before returning ahead of timeout    ctimeout -- timeout in seconds, 0 if none    freport -- whether to report errors.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_read
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
name|zbuf
operator|,
name|size_t
operator|*
name|pclen
operator|,
name|size_t
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
comment|/* Write to a connection.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_write
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
specifier|const
name|char
operator|*
name|zbuf
operator|,
name|size_t
name|cbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read and write to a connection.  This reads and writes data until    either all passed-in data has been written or the read buffer is    full.    zwrite -- buffer to write bytes from    *pcwrite on call -- number of bytes to write    *pcwrite on successful return -- number of bytes written    zread -- buffer to read bytes into    *pcread on call -- size of read buffer    *pcread on successful return -- number of bytes read.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_io
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|size_t
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|size_t
operator|*
name|pcread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send a break character to a connection.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_break
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Change the settings of a connection.  This allows independent    control over the parity of output characters, whether to strip    input characters, and whether to do XON/XOFF handshaking.  There is    no explicit control over parity checking of input characters.  This    function returns FALSE on error.  Attempts to set values not    supported by the hardware are silently ignored.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_set
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
expr|enum
name|tparitysetting
name|tparity
operator|,
expr|enum
name|tstripsetting
name|tstrip
operator|,
expr|enum
name|txonxoffsetting
name|txonxoff
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the baud rate of a connection.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|iconn_baud
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
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
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|pointer
name|puuconf
operator|,
specifier|const
expr|struct
name|uuconf_chat
operator|*
name|qchat
operator|,
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
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
comment|/* Tell the connection to either require or ignore carrier as fcarrier    is TRUE or FALSE respectively.  This is called with fcarrier TRUE    when \m is encountered in a chat script, and with fcarrier FALSE    when \M is encountered.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_carrier
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|boolean
name|fcarrier
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run a chat program on a connection.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_run_chat
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
operator|*
name|pzprog
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run through a dialer sequence.  This is a support routine for the    port type specific dialing routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fconn_dial_sequence
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|pointer
name|puuconf
operator|,
name|char
operator|*
operator|*
name|pzdialer
operator|,
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zphone
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
operator|,
expr|enum
name|tdialerfound
operator|*
name|ptdialerfound
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dialing out on a modem is partially system independent.  This is    the modem dialing routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fmodem_dial
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|pointer
name|puuconf
operator|,
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zphone
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
operator|,
expr|enum
name|tdialerfound
operator|*
name|ptdialerfound
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|sconnection
operator|*
name|qconn
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdial
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish dialing out on a modem.  This should close the dialer device    if there is one.  If the dialer and the port both support carrier,    the connection should be told to pay attention to carrier.  If it    is possible to wait for carrier to come on, and the dialer and the    port both the port support carrier, it should wait until carrier    comes on.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_end_dial
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdial
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System dependent initialization routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_stdin_init
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_modem_init
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_direct_init
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HAVE_TCP
end_if

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_tcp_init
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_TLI
end_if

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_tli_init
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_pipe_init
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (CONN_H) */
end_comment

end_unit

