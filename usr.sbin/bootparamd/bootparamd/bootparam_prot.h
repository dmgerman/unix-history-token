begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_define
define|#
directive|define
name|MAX_MACHINE_NAME
value|255
end_define

begin_define
define|#
directive|define
name|MAX_PATH_LEN
value|1024
end_define

begin_define
define|#
directive|define
name|MAX_FILEID
value|32
end_define

begin_define
define|#
directive|define
name|IP_ADDR_TYPE
value|1
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|bp_machine_name_t
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_bp_machine_name_t
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|char
modifier|*
name|bp_path_t
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_bp_path_t
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|char
modifier|*
name|bp_fileid_t
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_bp_fileid_t
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ip_addr_t
block|{
name|char
name|net
decl_stmt|;
name|char
name|host
decl_stmt|;
name|char
name|lh
decl_stmt|;
name|char
name|impno
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ip_addr_t
name|ip_addr_t
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_ip_addr_t
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bp_address
block|{
name|int
name|address_type
decl_stmt|;
union|union
block|{
name|ip_addr_t
name|ip_addr
decl_stmt|;
block|}
name|bp_address_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bp_address
name|bp_address
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_bp_address
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bp_whoami_arg
block|{
name|bp_address
name|client_address
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bp_whoami_arg
name|bp_whoami_arg
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_bp_whoami_arg
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bp_whoami_res
block|{
name|bp_machine_name_t
name|client_name
decl_stmt|;
name|bp_machine_name_t
name|domain_name
decl_stmt|;
name|bp_address
name|router_address
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bp_whoami_res
name|bp_whoami_res
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_bp_whoami_res
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bp_getfile_arg
block|{
name|bp_machine_name_t
name|client_name
decl_stmt|;
name|bp_fileid_t
name|file_id
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bp_getfile_arg
name|bp_getfile_arg
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_bp_getfile_arg
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bp_getfile_res
block|{
name|bp_machine_name_t
name|server_name
decl_stmt|;
name|bp_address
name|server_address
decl_stmt|;
name|bp_path_t
name|server_path
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bp_getfile_res
name|bp_getfile_res
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_bp_getfile_res
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BOOTPARAMPROG
value|((u_long)100026)
end_define

begin_define
define|#
directive|define
name|BOOTPARAMVERS
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|BOOTPARAMPROC_WHOAMI
value|((u_long)1)
end_define

begin_function_decl
specifier|extern
name|bp_whoami_res
modifier|*
name|bootparamproc_whoami_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BOOTPARAMPROC_GETFILE
value|((u_long)2)
end_define

begin_function_decl
specifier|extern
name|bp_getfile_res
modifier|*
name|bootparamproc_getfile_1
parameter_list|()
function_decl|;
end_function_decl

end_unit

