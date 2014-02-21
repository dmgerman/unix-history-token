begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * HTTP for WPS  * Copyright (c) 2000-2003 Intel Corporation  * Copyright (c) 2006-2007 Sony Corporation  * Copyright (c) 2008-2009 Atheros Communications  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * See wps_upnp.c for more details on licensing and code history.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HTTP_H
end_ifndef

begin_define
define|#
directive|define
name|HTTP_H
end_define

begin_enum
enum|enum
name|http_reply_code
block|{
name|HTTP_OK
init|=
literal|200
block|,
name|HTTP_BAD_REQUEST
init|=
literal|400
block|,
name|UPNP_INVALID_ACTION
init|=
literal|401
block|,
name|UPNP_INVALID_ARGS
init|=
literal|402
block|,
name|HTTP_NOT_FOUND
init|=
literal|404
block|,
name|HTTP_PRECONDITION_FAILED
init|=
literal|412
block|,
name|HTTP_INTERNAL_SERVER_ERROR
init|=
literal|500
block|,
name|HTTP_UNIMPLEMENTED
init|=
literal|501
block|,
name|UPNP_ACTION_FAILED
init|=
literal|501
block|,
name|UPNP_ARG_VALUE_INVALID
init|=
literal|600
block|,
name|UPNP_ARG_VALUE_OUT_OF_RANGE
init|=
literal|601
block|,
name|UPNP_OUT_OF_MEMORY
init|=
literal|603
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HTTP_H */
end_comment

end_unit

