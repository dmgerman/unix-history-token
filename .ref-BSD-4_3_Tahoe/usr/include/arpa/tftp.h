begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)tftp.h	5.2 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Trivial File Transfer Protocol (IEN-133)  */
end_comment

begin_define
define|#
directive|define
name|SEGSIZE
value|512
end_define

begin_comment
comment|/* data segment size */
end_comment

begin_comment
comment|/*  * Packet types.  */
end_comment

begin_define
define|#
directive|define
name|RRQ
value|01
end_define

begin_comment
comment|/* read request */
end_comment

begin_define
define|#
directive|define
name|WRQ
value|02
end_define

begin_comment
comment|/* write request */
end_comment

begin_define
define|#
directive|define
name|DATA
value|03
end_define

begin_comment
comment|/* data packet */
end_comment

begin_define
define|#
directive|define
name|ACK
value|04
end_define

begin_comment
comment|/* acknowledgement */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|05
end_define

begin_comment
comment|/* error code */
end_comment

begin_struct
struct|struct
name|tftphdr
block|{
name|short
name|th_opcode
decl_stmt|;
comment|/* packet type */
union|union
block|{
name|short
name|tu_block
decl_stmt|;
comment|/* block # */
name|short
name|tu_code
decl_stmt|;
comment|/* error code */
name|char
name|tu_stuff
index|[
literal|1
index|]
decl_stmt|;
comment|/* request packet stuff */
block|}
name|th_u
union|;
name|char
name|th_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* data or error string */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|th_block
value|th_u.tu_block
end_define

begin_define
define|#
directive|define
name|th_code
value|th_u.tu_code
end_define

begin_define
define|#
directive|define
name|th_stuff
value|th_u.tu_stuff
end_define

begin_define
define|#
directive|define
name|th_msg
value|th_data
end_define

begin_comment
comment|/*  * Error codes.  */
end_comment

begin_define
define|#
directive|define
name|EUNDEF
value|0
end_define

begin_comment
comment|/* not defined */
end_comment

begin_define
define|#
directive|define
name|ENOTFOUND
value|1
end_define

begin_comment
comment|/* file not found */
end_comment

begin_define
define|#
directive|define
name|EACCESS
value|2
end_define

begin_comment
comment|/* access violation */
end_comment

begin_define
define|#
directive|define
name|ENOSPACE
value|3
end_define

begin_comment
comment|/* disk full or allocation exceeded */
end_comment

begin_define
define|#
directive|define
name|EBADOP
value|4
end_define

begin_comment
comment|/* illegal TFTP operation */
end_comment

begin_define
define|#
directive|define
name|EBADID
value|5
end_define

begin_comment
comment|/* unknown transfer ID */
end_comment

begin_define
define|#
directive|define
name|EEXISTS
value|6
end_define

begin_comment
comment|/* file already exists */
end_comment

begin_define
define|#
directive|define
name|ENOUSER
value|7
end_define

begin_comment
comment|/* no such user */
end_comment

end_unit

