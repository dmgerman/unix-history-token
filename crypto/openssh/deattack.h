begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: deattack.h,v 1.7 2001/06/26 17:27:23 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Cryptographic attack detector for ssh - Header file  *  * Copyright (c) 1998 CORE SDI S.A., Buenos Aires, Argentina.  *  * All rights reserved. Redistribution and use in source and binary  * forms, with or without modification, are permitted provided that  * this copyright notice is retained.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES ARE DISCLAIMED. IN NO EVENT SHALL CORE SDI S.A. BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY OR  * CONSEQUENTIAL DAMAGES RESULTING FROM THE USE OR MISUSE OF THIS  * SOFTWARE.  *  * Ariel Futoransky<futo@core-sdi.com>  *<http://www.core-sdi.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEATTACK_H
end_ifndef

begin_define
define|#
directive|define
name|_DEATTACK_H
end_define

begin_comment
comment|/* Return codes */
end_comment

begin_define
define|#
directive|define
name|DEATTACK_OK
value|0
end_define

begin_define
define|#
directive|define
name|DEATTACK_DETECTED
value|1
end_define

begin_function_decl
name|int
name|detect_attack
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_char
index|[
literal|8
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

