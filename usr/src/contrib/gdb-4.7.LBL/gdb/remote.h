begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1992 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Lawrence Berkeley Laboratory,  * Berkeley, CA.  The name of the University may not be used to  * endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: remote.h,v 1.4 92/01/20 15:12:42 mccanne Exp $ (LBL)  */
end_comment

begin_struct
struct|struct
name|remote_fn
block|{
name|int
function_decl|(
modifier|*
name|send
function_decl|)
parameter_list|()
function_decl|;
comment|/* send an rpc message */
name|int
function_decl|(
modifier|*
name|recv
function_decl|)
parameter_list|()
function_decl|;
comment|/* receive an rpc message */
name|void
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|()
function_decl|;
comment|/* shutdown the link layer */
name|int
name|maxdata
decl_stmt|;
comment|/* maximum number of read/write bytes */
name|int
name|rpcsize
decl_stmt|;
comment|/* size of rpc msg buffers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Error codes.  */
end_comment

begin_define
define|#
directive|define
name|EKGDB_CSUM
value|1
end_define

begin_comment
comment|/* failed checksum */
end_comment

begin_define
define|#
directive|define
name|EKGDB_2BIG
value|2
end_define

begin_comment
comment|/* "giant" packet */
end_comment

begin_define
define|#
directive|define
name|EKGDB_RUNT
value|3
end_define

begin_comment
comment|/* short packet */
end_comment

begin_define
define|#
directive|define
name|EKGDB_BADOP
value|4
end_define

begin_comment
comment|/* bad op code in packet */
end_comment

begin_define
define|#
directive|define
name|EKGDB_TIMEOUT
value|5
end_define

begin_comment
comment|/* request timed out */
end_comment

begin_define
define|#
directive|define
name|EKGDB_IO
value|6
end_define

begin_comment
comment|/* generic I/O error */
end_comment

end_unit

