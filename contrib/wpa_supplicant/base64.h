begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Base64 encoding/decoding (RFC1341)  * Copyright (c) 2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BASE64_H
end_ifndef

begin_define
define|#
directive|define
name|BASE64_h
end_define

begin_function_decl
name|unsigned
name|char
modifier|*
name|base64_encode
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
modifier|*
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|base64_decode
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
modifier|*
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BASE64_H */
end_comment

end_unit

