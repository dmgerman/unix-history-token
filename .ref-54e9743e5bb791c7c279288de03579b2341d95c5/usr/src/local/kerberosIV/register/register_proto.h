begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)register_proto.h	8.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|APPEND_DB
value|0x01
end_define

begin_define
define|#
directive|define
name|ABORT
value|0x02
end_define

begin_define
define|#
directive|define
name|GOTKEY_MSG
value|"GOTKEY"
end_define

begin_struct
struct|struct
name|keyfile_data
block|{
name|C_Block
name|kf_key
decl_stmt|;
block|}
struct|;
end_struct

end_unit

