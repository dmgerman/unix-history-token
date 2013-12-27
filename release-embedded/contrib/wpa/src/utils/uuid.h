begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Universally Unique IDentifier (UUID)  * Copyright (c) 2008, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UUID_H
end_ifndef

begin_define
define|#
directive|define
name|UUID_H
end_define

begin_define
define|#
directive|define
name|UUID_LEN
value|16
end_define

begin_function_decl
name|int
name|uuid_str2bin
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|u8
modifier|*
name|bin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uuid_bin2str
parameter_list|(
specifier|const
name|u8
modifier|*
name|bin
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|max_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_nil_uuid
parameter_list|(
specifier|const
name|u8
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UUID_H */
end_comment

end_unit

