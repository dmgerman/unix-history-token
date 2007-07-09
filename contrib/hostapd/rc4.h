begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RC4 stream cipher  * Copyright (c) 2002-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RC4_H
end_ifndef

begin_define
define|#
directive|define
name|RC4_H
end_define

begin_function_decl
name|void
name|rc4_skip
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|,
name|size_t
name|skip
parameter_list|,
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rc4
parameter_list|(
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RC4_H */
end_comment

end_unit

