begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1987 Xerox Corporation.  */
end_comment

begin_comment
comment|/* $Log:	filing_server.h,v $  * Revision 1.2  87/03/17  16:33:00  ed  * Added defines for classes of attributes.  *   * Revision 1.1  87/01/06  16:29:06  ed  * Initial revision  *   *   */
end_comment

begin_define
define|#
directive|define
name|MAX_HANDLES
value|10
end_define

begin_comment
comment|/* maximum number of open files */
end_comment

begin_define
define|#
directive|define
name|MAX_FILE_NAME_LENGTH
value|256
end_define

begin_comment
comment|/* maximum length of file name */
end_comment

begin_define
define|#
directive|define
name|SUPPORTEDATTRIBUTES
value|8
end_define

begin_comment
comment|/* see make_attribute_sequence */
end_comment

begin_define
define|#
directive|define
name|REQUIREDATTRIBUTES
value|6
end_define

begin_comment
comment|/* see make_attribute_sequence */
end_comment

begin_define
define|#
directive|define
name|OPTIONALATTRIBUTES
value|50
end_define

begin_comment
comment|/* for Viewpoint files */
end_comment

begin_comment
comment|/*  * file handle  *	one per open file  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|state
decl_stmt|;
comment|/* current state */
define|#
directive|define
name|FILE_CLOSED
value|0
define|#
directive|define
name|FILE_OPEN
value|1
name|char
modifier|*
name|pathname
decl_stmt|;
comment|/* ptr to pathname value */
name|LongCardinal
name|type
decl_stmt|;
comment|/* client requested type (from Open) */
name|LongCardinal
name|truetype
decl_stmt|;
comment|/* file system file type */
name|Cardinal
name|datasize
decl_stmt|;
comment|/* dataSize value */
name|Boolean
name|isdirectory
decl_stmt|;
comment|/* isDirectory */
name|LongCardinal
name|createdon
decl_stmt|;
comment|/* createdOn */
name|LongCardinal
name|modifiedon
decl_stmt|;
comment|/* modifiedOn */
name|FILE
modifier|*
name|file_desc
decl_stmt|;
comment|/* ptr to file descriptor for open file */
block|}
name|file_handle
typedef|;
end_typedef

begin_comment
comment|/*  * session handle  *	one per session  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|state
decl_stmt|;
comment|/* current state */
define|#
directive|define
name|SESSION_CLOSED
value|0
define|#
directive|define
name|SESSION_OPEN
value|1
name|CourierConnection
modifier|*
name|connection
decl_stmt|;
comment|/* connection id */
name|FILING_Credentials
name|credentials
decl_stmt|;
comment|/* user credentials */
name|AUTHENTICATION_SimpleVerifier
name|verifier
decl_stmt|;
comment|/* user verifier */
name|file_handle
name|handle
index|[
name|MAX_HANDLES
index|]
decl_stmt|;
comment|/* array of open files */
block|}
name|session_handle
typedef|;
end_typedef

end_unit

