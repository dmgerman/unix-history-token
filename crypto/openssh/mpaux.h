begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * mpaux.h  *  * Author: Tatu Ylonen<ylo@cs.hut.fi>  *  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * Created: Sun Jul 16 04:29:30 1995 ylo  *  * This file contains various auxiliary functions related to multiple  * precision integers.  */
end_comment

begin_comment
comment|/* RCSID("$Id: mpaux.h,v 1.6 2000/04/14 10:30:32 markus Exp $"); */
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
name|unsigned
name|char
name|session_id
index|[
literal|16
index|]
parameter_list|,
name|unsigned
name|char
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

