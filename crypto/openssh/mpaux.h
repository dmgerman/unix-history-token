begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * This file contains various auxiliary functions related to multiple  * precision integers.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: mpaux.h,v 1.9 2000/12/19 23:17:57 markus Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPAUX_H
end_ifndef

begin_define
define|#
directive|define
name|MPAUX_H
end_define

begin_comment
comment|/*  * Computes a 16-byte session id in the global variable session_id. The  * session id is computed by concatenating the linearized, msb first  * representations of host_key_n, session_key_n, and the cookie.  */
end_comment

begin_function_decl
name|void
name|compute_session_id
parameter_list|(
name|u_char
name|session_id
index|[
literal|16
index|]
parameter_list|,
name|u_char
name|cookie
index|[
literal|8
index|]
parameter_list|,
name|BIGNUM
modifier|*
name|host_key_n
parameter_list|,
name|BIGNUM
modifier|*
name|session_key_n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MPAUX_H */
end_comment

end_unit

