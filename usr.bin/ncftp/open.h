begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* open.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_open_h_
end_ifndef

begin_define
define|#
directive|define
name|_open_h_
value|1
end_define

begin_comment
comment|/* Variables for Open() that can be changed from the command line. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|OpenOptions
block|{
name|int
name|openmode
decl_stmt|;
name|int
name|ignore_rc
decl_stmt|;
name|unsigned
name|int
name|port
decl_stmt|;
name|int
name|redial_delay
decl_stmt|;
name|int
name|max_dials
decl_stmt|;
name|int
name|ftpcat
decl_stmt|;
name|Hostname
name|hostname
decl_stmt|;
name|longstring
name|cdpath
decl_stmt|;
name|longstring
name|colonmodepath
decl_stmt|;
block|}
name|OpenOptions
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RemoteSiteInfo
block|{
name|int
name|hasSIZE
decl_stmt|;
name|int
name|hasMDTM
decl_stmt|;
block|}
name|RemoteSiteInfo
typedef|;
end_typedef

begin_comment
comment|/* Open modes. */
end_comment

begin_define
define|#
directive|define
name|openImplicitAnon
value|1
end_define

begin_define
define|#
directive|define
name|openImplicitUser
value|4
end_define

begin_define
define|#
directive|define
name|openExplicitAnon
value|3
end_define

begin_define
define|#
directive|define
name|openExplicitUser
value|2
end_define

begin_define
define|#
directive|define
name|ISUSEROPEN
parameter_list|(
name|a
parameter_list|)
value|((a==openImplicitUser)||(a==openExplicitUser))
end_define

begin_define
define|#
directive|define
name|ISANONOPEN
parameter_list|(
name|a
parameter_list|)
value|(!ISUSEROPEN(a))
end_define

begin_define
define|#
directive|define
name|ISEXPLICITOPEN
parameter_list|(
name|a
parameter_list|)
value|((a==openExplicitAnon)||(a==openExplicitUser))
end_define

begin_define
define|#
directive|define
name|ISIMPLICITOPEN
parameter_list|(
name|a
parameter_list|)
value|(!ISEXPLICITOPEN(a))
end_define

begin_comment
comment|/* ftpcat modes. */
end_comment

begin_define
define|#
directive|define
name|NO_FTPCAT
value|0
end_define

begin_define
define|#
directive|define
name|FTPCAT
value|1
end_define

begin_define
define|#
directive|define
name|FTPMORE
value|2
end_define

begin_comment
comment|/* Protos: */
end_comment

begin_function_decl
name|void
name|InitOpenOptions
parameter_list|(
name|OpenOptions
modifier|*
name|openopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetOpenOptions
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|OpenOptions
modifier|*
name|openopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CheckForColonMode
parameter_list|(
name|OpenOptions
modifier|*
name|openopt
parameter_list|,
name|int
modifier|*
name|login_verbosity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|HookupToRemote
parameter_list|(
name|OpenOptions
modifier|*
name|openopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckRemoteSystemType
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ColonMode
parameter_list|(
name|OpenOptions
modifier|*
name|openopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Open
parameter_list|(
name|OpenOptions
modifier|*
name|openopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmdOpen
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _open_h_ */
end_comment

end_unit

