begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Credentials.  */
end_comment

begin_struct
struct|struct
name|ucred
block|{
name|u_short
name|cr_ref
decl_stmt|;
comment|/* reference count */
name|uid_t
name|cr_uid
decl_stmt|;
comment|/* effective user id */
name|short
name|cr_ngroups
decl_stmt|;
comment|/* number of groups */
name|gid_t
name|cr_groups
index|[
name|NGROUPS
index|]
decl_stmt|;
comment|/* groups */
comment|/* 	 * The following either should not be here, 	 * or should be treated as opaque. 	 */
name|uid_t
name|cr_ruid
decl_stmt|;
comment|/* real user id */
name|gid_t
name|cr_svgid
decl_stmt|;
comment|/* saved set-group id */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|crhold
parameter_list|(
name|cr
parameter_list|)
value|(cr)->cr_ref++
end_define

begin_function_decl
name|struct
name|ucred
modifier|*
name|crget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ucred
modifier|*
name|crcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ucred
modifier|*
name|crdup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

