begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*       ________________________________________________________        */
end_comment

begin_comment
comment|/*      /                                                        \       */
end_comment

begin_comment
comment|/*     |          AAA          CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*     |         AAAAA        CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     |        AAAAAAA       CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |       AAAA AAAA      CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |      AAAA   AAAA     CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |     AAAA     AAAA    CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |    AAAA       AAAA   CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |   AAAA  AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |  AAAA    AAAAAAAAAAA CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     | AAAA      AAAAAAAAA   CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*      \________________________________________________________/       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  	Copyright (c) 1988 by Advanced Computer Communications           */
end_comment

begin_comment
comment|/*  	720 Santa Barbara Street, Santa Barbara, California  93101       */
end_comment

begin_comment
comment|/*  	(805) 963-9431                                                   */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  File:		if_pivar.h                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Author:		Brad Engstrom.                                   */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Project:		UNIX DDA-X.25 Network Programmers                */
end_comment

begin_comment
comment|/*                      Interface for ACP 5250 and ACP 6250              */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Function:		This file contains definitions of the PI         */
end_comment

begin_comment
comment|/*			data structures and ioctl indicators.            */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Revision History:                                                    */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  06-Sep-1988: V1.0 - Brad Engstrom					 */
end_comment

begin_comment
comment|/*		 First generated	                                 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*  * Ioctl's have the command encoded in the lower word,  * and the size of any in or out parameters in the upper  * word.  The high 2 bits of the upper word are used  * to encode the in/out status of the parameter; for now  * we restrict parameters to at most 128 bytes.  */
end_comment

begin_comment
comment|/* this structure is used when writing or reading data data */
end_comment

begin_struct
struct|struct
name|pi_dblock
block|{
name|caddr_t
name|dataptr
decl_stmt|;
comment|/* pointer to user data to be written */
name|u_int
name|length
decl_stmt|;
comment|/* length of data pointed to by dataptr */
name|u_short
name|lcn
decl_stmt|;
comment|/* logical channel to send data out on */
name|u_char
name|func
decl_stmt|;
comment|/* read status , write function value */
name|u_char
name|subfunc
decl_stmt|;
comment|/* read substatus, write subfunction value */
name|u_short
name|flags
decl_stmt|;
comment|/* special flags */
block|}
struct|;
end_struct

begin_comment
comment|/* pi_dblock.flags:  The follwing values can be used to set bits */
end_comment

begin_define
define|#
directive|define
name|DB_NONBLOCK
value|0x01
end_define

begin_comment
comment|/* non-blocking read or write */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|proto_range
block|{
name|u_char
name|lower
decl_stmt|;
comment|/* lower bound on protocol range (inclusive) */
name|u_char
name|upper
decl_stmt|;
comment|/* upper bound on protocol range (inclusive) */
block|}
name|proto_range
typedef|;
end_typedef

begin_comment
comment|/* data write */
end_comment

begin_define
define|#
directive|define
name|XIOWRITE
value|_IOWR(t, 1, struct pi_dblock)
end_define

begin_comment
comment|/* data read */
end_comment

begin_define
define|#
directive|define
name|XIOREAD
value|_IOWR(t, 2, struct pi_dblock)
end_define

begin_comment
comment|/* see if data is ready to be read on a particular channel.    * The field will return the number of pending data bytes.  */
end_comment

begin_define
define|#
directive|define
name|XIORPEND
value|_IOR(t, 3, int)
end_define

begin_comment
comment|/* allow rings on this minor device.  The proto_range structure specifies  * the lower and upper bounds on the protocol byte of incomming calls  */
end_comment

begin_define
define|#
directive|define
name|XIOACCRING
value|_IOW(t, 4, proto_range)
end_define

begin_comment
comment|/* specify that a protocol not requested by anyone else will be accepted on  * this channel.  */
end_comment

begin_define
define|#
directive|define
name|XIOANYPROTO
value|_IO(t, 5)
end_define

begin_comment
comment|/* reserve an lcn for use by this channel (minor device).  The number of the  * lcn is returned the the character passed  */
end_comment

begin_define
define|#
directive|define
name|XIOGETLCN
value|_IOR(t, 6, u_char)
end_define

begin_comment
comment|/* free an lcn specified by the u_char parameter.  This should be called for all  * lcn's obtained with XIOGETLCN before the channel is closed.  */
end_comment

begin_define
define|#
directive|define
name|XIOFREELCN
value|_IOW(t, 11, u_char)
end_define

begin_comment
comment|/* clear any data associated with a channel.  The lcn is passed.  Note that  * this does not clear the circut.  It only flushes queued data stored in the  * driver  */
end_comment

begin_define
define|#
directive|define
name|XIOCLRCHAN
value|_IO(t, 7)
end_define

begin_comment
comment|/* disallow incomming calls on this channel */
end_comment

begin_define
define|#
directive|define
name|XIONORING
value|_IO(t, 9)
end_define

begin_comment
comment|/* specify a signal to be sent to the process when there  is data ready to  * be read on a particular channel.  The u_int specifies the signal to be  * sent.  */
end_comment

begin_define
define|#
directive|define
name|XIORSIG
value|_IOW(t, 10, u_int)
end_define

begin_comment
comment|/* abort all output for the given lcn. */
end_comment

begin_define
define|#
directive|define
name|XIOABORT
value|_IOW(t, 12, u_char)
end_define

begin_comment
comment|/*  Revision history:  06-Jun-1988 Brad	Initial implementation  */
end_comment

end_unit

