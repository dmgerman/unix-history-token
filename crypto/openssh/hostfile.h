begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HOSTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|HOSTFILE_H
end_define

begin_comment
comment|/*  * Checks whether the given host is already in the list of our known hosts.  * Returns HOST_OK if the host is known and has the specified key, HOST_NEW  * if the host is not known, and HOST_CHANGED if the host is known but used  * to have a different host key.  The host must be in all lowercase.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HOST_OK
block|,
name|HOST_NEW
block|,
name|HOST_CHANGED
block|}
name|HostStatus
typedef|;
end_typedef

begin_function_decl
name|HostStatus
name|check_host_in_hostfile
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|Key
modifier|*
name|key
parameter_list|,
name|Key
modifier|*
name|found
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Appends an entry to the host file.  Returns false if the entry could not  * be appended.  */
end_comment

begin_function_decl
name|int
name|add_host_to_hostfile
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|Key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

