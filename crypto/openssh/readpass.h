begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: readpass.h,v 1.7 2002/03/26 15:58:46 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_define
define|#
directive|define
name|RP_ECHO
value|0x0001
end_define

begin_define
define|#
directive|define
name|RP_ALLOW_STDIN
value|0x0002
end_define

begin_define
define|#
directive|define
name|RP_ALLOW_EOF
value|0x0004
end_define

begin_function_decl
name|char
modifier|*
name|read_passphrase
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

