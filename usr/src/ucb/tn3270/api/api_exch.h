begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)api_exch.h	3.2 (Berkeley) 3/28/88  */
end_comment

begin_comment
comment|/*  * This file describes the structures passed back and forth  * between the API client and API server on a Unix-based  * tn3270 implementation.  */
end_comment

begin_comment
comment|/*  * The following are the low-level opcodes exchanged between the  * two sides.  These are designed to allow for type, sequence number,  * and direction checking.  *  * We enforce conversation flow.  There are three states: CONTENTION,  * SEND, and RECEIVE.  Both sides start in CONTENTION.  * We never leave RECEIVE state without first reading a TURNAROUND  * opcode.  We never leave SEND state without first writing a TURNAROUND  * opcode.  This scheme ensures that we always have conversation flowing  * in a synchronized direction (or detect an application error), and that  * we never hang with both sides trying to read from the "wire".  *  * State	event			action  *  * CONTENTION	read request		send TURNAROUND  *					read RTS  *					enter RECEIVE  * CONTENTION	write request		send RTS  *					read TURNAROUND  *					enter SEND  *  * RECEIVE	read request		read whatever  * RECEIVE	write request		read TURNAROUND  *  * SEND		read request		send TURNAROUND  * SEND		write			write whatever  */
end_comment

begin_define
define|#
directive|define
name|EXCH_EXCH_COMMAND
value|0
end_define

begin_comment
comment|/* The following is a command */
end_comment

begin_define
define|#
directive|define
name|EXCH_EXCH_TURNAROUND
value|1
end_define

begin_comment
comment|/* Your turn to send */
end_comment

begin_define
define|#
directive|define
name|EXCH_EXCH_RTS
value|2
end_define

begin_comment
comment|/* Request to send */
end_comment

begin_define
define|#
directive|define
name|EXCH_EXCH_TYPE
value|3
end_define

begin_comment
comment|/* The following is a type */
end_comment

begin_struct
struct|struct
name|exch_exch
block|{
name|unsigned
name|char
name|opcode
decl_stmt|,
comment|/* COMMAND, TURNAROUND, or TYPE */
name|my_sequence
decl_stmt|,
comment|/* 0-ff, initially zero */
name|your_sequence
decl_stmt|,
comment|/* 0-ff, initially zero */
name|command_or_type
decl_stmt|;
comment|/* Application level command or type */
name|unsigned
name|short
name|length
decl_stmt|;
comment|/* The length of any following data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following are the command codes which the higher level protocols  * send and receive.  */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_ASSOCIATE
value|0
end_define

begin_comment
comment|/* Connect [client->server] */
end_comment

begin_comment
comment|/* 	 * struct storage_desc 	 * char key[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_DISASSOCIATE
value|1
end_define

begin_comment
comment|/* Disconnect [client->server] */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_SEND_AUTH
value|2
end_define

begin_comment
comment|/* Send password [server->client] */
end_comment

begin_comment
comment|/* 	 * struct storage_desc 	 * char prompt[] 	 * struct storage_desc 	 * char seed[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_AUTH
value|3
end_define

begin_comment
comment|/* Authorization [client->server] */
end_comment

begin_comment
comment|/* 	 * struct storage_desc 	 * char authenticator[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_ASSOCIATED
value|4
end_define

begin_comment
comment|/* Connected [server->client] */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_REJECTED
value|5
end_define

begin_comment
comment|/* Too bad [server->client] */
end_comment

begin_comment
comment|/* 	 * struct storage_desc 	 * char message[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_REQUEST
value|6
end_define

begin_comment
comment|/* A request [client->server] */
end_comment

begin_comment
comment|/* struct regs, 	 * struct sregs, 	 * struct storage_desc 	 * char bytes[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_GIMME
value|7
end_define

begin_comment
comment|/* Send storage [server->client] */
end_comment

begin_comment
comment|/* 	 * struct storage_desc 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_HEREIS
value|8
end_define

begin_comment
comment|/* Here is storage [BOTH WAYS] */
end_comment

begin_comment
comment|/* 	 * struct storage_desc 	 * char bytes[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_CMD_REPLY
value|9
end_define

begin_comment
comment|/* End of discussion */
end_comment

begin_comment
comment|/* 	 * struct regs, 	 * struct sregs, 	 */
end_comment

begin_comment
comment|/*  * The following are typed parameters sent across the wire.  *  * This should be done much more generally, with some form of  * XDR or mapped conversation ability.  */
end_comment

begin_define
define|#
directive|define
name|EXCH_TYPE_REGS
value|0
end_define

begin_define
define|#
directive|define
name|EXCH_TYPE_SREGS
value|1
end_define

begin_define
define|#
directive|define
name|EXCH_TYPE_STORE_DESC
value|2
end_define

begin_define
define|#
directive|define
name|EXCH_TYPE_BYTES
value|3
end_define

begin_comment
comment|/*  * each parameter that comes over looks like:  *  *	char			type of following  *	short (2 bytes)		length of following (network byte order)  *	following  */
end_comment

begin_struct
struct|struct
name|storage_descriptor
block|{
name|long
name|location
decl_stmt|;
comment|/* In network byte order */
name|short
name|length
decl_stmt|;
comment|/* In network byte order */
block|}
struct|;
end_struct

end_unit

