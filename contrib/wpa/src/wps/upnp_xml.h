begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * UPnP XML helper routines  * Copyright (c) 2000-2003 Intel Corporation  * Copyright (c) 2006-2007 Sony Corporation  * Copyright (c) 2008-2009 Atheros Communications  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * See wps_upnp.c for more details on licensing and code history.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UPNP_XML_H
end_ifndef

begin_define
define|#
directive|define
name|UPNP_XML_H
end_define

begin_include
include|#
directive|include
file|"http.h"
end_include

begin_function_decl
name|void
name|xml_data_encode
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xml_add_tagged_data
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|tag
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xml_next_tag
parameter_list|(
specifier|const
name|char
modifier|*
name|in
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|out
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|out_tagname
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xml_get_first_item
parameter_list|(
specifier|const
name|char
modifier|*
name|doc
parameter_list|,
specifier|const
name|char
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|xml_get_base64_item
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|enum
name|http_reply_code
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UPNP_XML_H */
end_comment

end_unit

