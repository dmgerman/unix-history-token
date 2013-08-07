begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * httpread - Manage reading file(s) from HTTP/TCP socket  * Author: Ted Merrill  * Copyright 2008 Atheros Communications  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HTTPREAD_H
end_ifndef

begin_define
define|#
directive|define
name|HTTPREAD_H
end_define

begin_comment
comment|/* event types (passed to callback) */
end_comment

begin_enum
enum|enum
name|httpread_event
block|{
name|HTTPREAD_EVENT_FILE_READY
init|=
literal|1
block|,
comment|/* including reply ready */
name|HTTPREAD_EVENT_TIMEOUT
init|=
literal|2
block|,
name|HTTPREAD_EVENT_ERROR
init|=
literal|3
comment|/* misc. error, esp malloc error */
block|}
enum|;
end_enum

begin_comment
comment|/* header type detected  * available to callback via call to httpread_reply_code_get()  */
end_comment

begin_enum
enum|enum
name|httpread_hdr_type
block|{
name|HTTPREAD_HDR_TYPE_UNKNOWN
init|=
literal|0
block|,
comment|/* none of the following */
name|HTTPREAD_HDR_TYPE_REPLY
init|=
literal|1
block|,
comment|/* hdr begins w/ HTTP/ */
name|HTTPREAD_HDR_TYPE_GET
init|=
literal|2
block|,
comment|/* hdr begins with GET<sp> */
name|HTTPREAD_HDR_TYPE_HEAD
init|=
literal|3
block|,
comment|/* hdr begins with HEAD<sp> */
name|HTTPREAD_HDR_TYPE_POST
init|=
literal|4
block|,
comment|/* hdr begins with POST<sp> */
name|HTTPREAD_HDR_TYPE_PUT
init|=
literal|5
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_HDR_TYPE_DELETE
init|=
literal|6
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_HDR_TYPE_TRACE
init|=
literal|7
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_HDR_TYPE_CONNECT
init|=
literal|8
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_HDR_TYPE_NOTIFY
init|=
literal|9
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_HDR_TYPE_M_SEARCH
init|=
literal|10
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_HDR_TYPE_M_POST
init|=
literal|11
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_HDR_TYPE_SUBSCRIBE
init|=
literal|12
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_HDR_TYPE_UNSUBSCRIBE
init|=
literal|13
block|,
comment|/* hdr begins with ... */
name|HTTPREAD_N_HDR_TYPES
comment|/* keep last */
block|}
enum|;
end_enum

begin_comment
comment|/* control instance -- opaque struct declaration  */
end_comment

begin_struct_decl
struct_decl|struct
name|httpread
struct_decl|;
end_struct_decl

begin_comment
comment|/* httpread_destroy -- if h is non-NULL, clean up  * This must eventually be called by the application following  * call of the application's callback and may be called  * earlier if desired.  */
end_comment

begin_function_decl
name|void
name|httpread_destroy
parameter_list|(
name|struct
name|httpread
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* httpread_create -- start a new reading session making use of eloop.  * The new instance will use the socket descriptor for reading (until  * it gets a file and not after) but will not close the socket, even  * when the instance is destroyed (the application must do that).  * Return NULL on error.  *  * Provided that httpread_create successfully returns a handle,  * the callback fnc is called to handle httpread_event events.  * The caller should do destroy on any errors or unknown events.  *  * Pass max_bytes == 0 to not read body at all (required for e.g.  * reply to HEAD request).  */
end_comment

begin_function_decl
name|struct
name|httpread
modifier|*
name|httpread_create
parameter_list|(
name|int
name|sd
parameter_list|,
comment|/* descriptor of TCP socket to read from */
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|httpread
modifier|*
name|handle
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|enum
name|httpread_event
name|e
parameter_list|)
parameter_list|,
comment|/* call on event */
name|void
modifier|*
name|cookie
parameter_list|,
comment|/* pass to callback */
name|int
name|max_bytes
parameter_list|,
comment|/* maximum file size else abort it */
name|int
name|timeout_seconds
comment|/* 0; or total duration timeout period */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* httpread_hdr_type_get -- When file is ready, returns header type.  */
end_comment

begin_function_decl
name|enum
name|httpread_hdr_type
name|httpread_hdr_type_get
parameter_list|(
name|struct
name|httpread
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* httpread_uri_get -- When file is ready, uri_get returns (translated) URI  * or possibly NULL (which would be an error).  */
end_comment

begin_function_decl
name|char
modifier|*
name|httpread_uri_get
parameter_list|(
name|struct
name|httpread
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* httpread_reply_code_get -- When reply is ready, returns reply code */
end_comment

begin_function_decl
name|int
name|httpread_reply_code_get
parameter_list|(
name|struct
name|httpread
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* httpread_length_get -- When file is ready, returns file length. */
end_comment

begin_function_decl
name|int
name|httpread_length_get
parameter_list|(
name|struct
name|httpread
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* httpread_data_get -- When file is ready, returns file content  * with null byte appened.  * Might return NULL in some error condition.  */
end_comment

begin_function_decl
name|void
modifier|*
name|httpread_data_get
parameter_list|(
name|struct
name|httpread
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* httpread_hdr_get -- When file is ready, returns header content  * with null byte appended.  * Might return NULL in some error condition.  */
end_comment

begin_function_decl
name|char
modifier|*
name|httpread_hdr_get
parameter_list|(
name|struct
name|httpread
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* httpread_hdr_line_get -- When file is ready, returns pointer  * to line within header content matching the given tag  * (after the tag itself and any spaces/tabs).  *  * The tag should end with a colon for reliable matching.  *  * If not found, returns NULL;  */
end_comment

begin_function_decl
name|char
modifier|*
name|httpread_hdr_line_get
parameter_list|(
name|struct
name|httpread
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HTTPREAD_H */
end_comment

end_unit

