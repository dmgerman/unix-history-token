begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/*  * kpasswd_proto  *  * definitions for the kpasswd "protocol"  * (We hope this to be temporary until a real admin protocol is worked out)  */
end_comment

begin_define
define|#
directive|define
name|MSGSIZE
value|255
end_define

begin_struct
struct|struct
name|kpasswd_data
block|{
name|C_Block
name|random_key
decl_stmt|;
name|char
name|secure_msg
index|[
name|MSGSIZE
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
literal|255
index|]
decl_stmt|;
name|char
name|secure_msg
index|[
name|MSGSIZE
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
value|"Kerberos password update program -- 12/9/88 UC Berkeley"
end_define

end_unit

