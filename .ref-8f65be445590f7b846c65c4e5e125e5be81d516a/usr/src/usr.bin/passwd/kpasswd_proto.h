begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)kpasswd_proto.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * kpasswd_proto  *  * definitions for the kpasswd "protocol"  * (We hope this to be temporary until a real admin protocol is worked out.)  */
end_comment

begin_struct
struct|struct
name|kpasswd_data
block|{
name|des_cblock
name|random_key
decl_stmt|;
name|char
name|secure_msg
index|[
name|_PASSWORD_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|update_data
block|{
name|char
name|pw
index|[
name|_PASSWORD_LEN
index|]
decl_stmt|;
name|char
name|secure_msg
index|[
name|_PASSWORD_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SERVICE
value|"kpasswd"
end_define

begin_define
define|#
directive|define
name|SECURE_STRING
define|\
value|"Kerberos password update program -- 12/9/88 UC Berkeley"
end_define

end_unit

