begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for PasswordLookup.  */
end_comment

begin_include
include|#
directive|include
file|<courier/courier.h>
end_include

begin_include
include|#
directive|include
file|<courier/courierconnection.h>
end_include

begin_define
define|#
directive|define
name|PasswordLookup_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|PasswordLookup_NUMBER
value|754
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|String
name|pw_name
decl_stmt|;
name|String
name|pw_passwd
decl_stmt|;
name|LongCardinal
name|pw_uid
decl_stmt|;
name|LongCardinal
name|pw_gid
decl_stmt|;
name|LongCardinal
name|pw_quota
decl_stmt|;
name|String
name|pw_comment
decl_stmt|;
name|String
name|pw_gecos
decl_stmt|;
name|String
name|pw_dir
decl_stmt|;
name|String
name|pw_shell
decl_stmt|;
block|}
name|Passwd
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NoSuchUser
value|(ERROR_OFFSET+0)
end_define

begin_define
define|#
directive|define
name|NoSuchUserArgs
value|T_cn754_1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|String
name|errorstring
decl_stmt|;
block|}
name|T_cn754_2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OtherError
value|(ERROR_OFFSET+1)
end_define

begin_define
define|#
directive|define
name|OtherErrorArgs
value|T_cn754_2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Passwd
name|passwd
decl_stmt|;
block|}
name|LookupUidResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|LookupUidResults
name|LookupUid
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Passwd
name|passwd
decl_stmt|;
block|}
name|LookupUserResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|LookupUserResults
name|LookupUser
parameter_list|()
function_decl|;
end_function_decl

end_unit

