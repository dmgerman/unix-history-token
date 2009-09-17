begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-PEAP common routines  * Copyright (c) 2008, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_PEAP_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_PEAP_COMMON_H
end_define

begin_function_decl
name|void
name|peap_prfplus
parameter_list|(
name|int
name|version
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
specifier|const
name|u8
modifier|*
name|seed
parameter_list|,
name|size_t
name|seed_len
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_PEAP_COMMON_H */
end_comment

end_unit

