begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1992 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Functions for computing 32-bit CRC.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: crc32.h,v 1.10 2001/03/02 18:54:31 deraadt Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CRC32_H
end_ifndef

begin_define
define|#
directive|define
name|CRC32_H
end_define

begin_comment
comment|/*  * This computes a 32 bit CRC of the data in the buffer, and returns the CRC.  * The polynomial used is 0xedb88320.  */
end_comment

begin_function_decl
name|u_int
name|ssh_crc32
parameter_list|(
specifier|const
name|u_char
modifier|*
name|buf
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRC32_H */
end_comment

end_unit

