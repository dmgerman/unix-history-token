begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file describes the structures passed back and forth  * between the API client and API server on a Unix-based  * tn3270 implementation.  */
end_comment

begin_define
define|#
directive|define
name|EXCH_CONNECT
value|23
end_define

begin_comment
comment|/* Connect request [client->server] */
end_comment

begin_define
define|#
directive|define
name|EXCH_SEND_AUTH
value|44
end_define

begin_comment
comment|/* Send auth (password) [server->client] */
end_comment

begin_comment
comment|/* 	 * struct storeage_desc 	 * char prompt[] 	 * struct storeage_desc 	 * char seed[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_AUTH
value|65
end_define

begin_comment
comment|/* Authorization [client->server] */
end_comment

begin_comment
comment|/* 	 * struct storeage_desc 	 * char authenticator[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_CONNECTED
value|78
end_define

begin_comment
comment|/* You are now connected [server->client] */
end_comment

begin_define
define|#
directive|define
name|EXCH_REJECTED
value|93
end_define

begin_comment
comment|/* Too bad [server->client] */
end_comment

begin_comment
comment|/* 	 * struct storeage_desc 	 * char message[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_REQUEST
value|19
end_define

begin_comment
comment|/* A request [client->server] */
end_comment

begin_comment
comment|/* struct regs, 	 * struct sregs, 	 * struct storage_desc 	 * char bytes[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_GIMME
value|20
end_define

begin_comment
comment|/* I need client storage [server->client] */
end_comment

begin_comment
comment|/* 	 * struct storage_desc 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_HEREIS
value|49
end_define

begin_comment
comment|/* Here is some storage [BOTH WAYS] */
end_comment

begin_comment
comment|/* 	 * struct storage_desc 	 * char bytes[] 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_REPLY
value|87
end_define

begin_comment
comment|/* End of discussion */
end_comment

begin_comment
comment|/* 	 * struct regs, 	 * struct sregs, 	 */
end_comment

begin_define
define|#
directive|define
name|EXCH_TYPE_REGS
value|13
end_define

begin_define
define|#
directive|define
name|EXCH_TYPE_SREGS
value|27
end_define

begin_define
define|#
directive|define
name|EXCH_TYPE_STORE_DESC
value|33
end_define

begin_define
define|#
directive|define
name|EXCH_TYPE_BYTES
value|67
end_define

begin_comment
comment|/*  * each structure that comes over looks like:  *  *	char			type of following  *	short (2 bytes)		length of following (network byte order)  *	following  */
end_comment

begin_struct
struct|struct
name|storage_descriptor
block|{
name|long
name|location
decl_stmt|;
comment|/* In network byte order */
name|short
name|length
decl_stmt|;
comment|/* In network byte order */
block|}
struct|;
end_struct

end_unit

