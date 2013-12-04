begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NTP_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_CONFIG_H
end_define

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_include
include|#
directive|include
file|"ntp_data_structures.h"
end_include

begin_include
include|#
directive|include
file|"ntpsim.h"
end_include

begin_comment
comment|/*  * Configuration file name  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_FILE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_FILE
value|"/etc/ntp.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_define
define|#
directive|define
name|CONFIG_FILE
value|"%windir%\\system32\\drivers\\etc\\ntp.conf"
end_define

begin_define
define|#
directive|define
name|ALT_CONFIG_FILE
value|"%windir%\\ntp.conf"
end_define

begin_define
define|#
directive|define
name|NTP_KEYSDIR
value|"%windir%\\system32\\drivers\\etc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CONFIG_FILE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IPTOS_SUPPORT
end_ifdef

begin_comment
comment|/*   * "qos" modified keywords   */
end_comment

begin_define
define|#
directive|define
name|CONF_QOS_LOWDELAY
value|1
end_define

begin_define
define|#
directive|define
name|CONF_QOS_THROUGHPUT
value|2
end_define

begin_define
define|#
directive|define
name|CONF_QOS_RELIABILITY
value|3
end_define

begin_define
define|#
directive|define
name|CONF_QOS_MINCOST
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IPTOS_PREC_INTERNETCONTROL
end_ifdef

begin_define
define|#
directive|define
name|CONF_QOS_CS0
value|5
end_define

begin_define
define|#
directive|define
name|CONF_QOS_CS1
value|6
end_define

begin_define
define|#
directive|define
name|CONF_QOS_CS2
value|7
end_define

begin_define
define|#
directive|define
name|CONF_QOS_CS3
value|8
end_define

begin_define
define|#
directive|define
name|CONF_QOS_CS4
value|9
end_define

begin_define
define|#
directive|define
name|CONF_QOS_CS5
value|10
end_define

begin_define
define|#
directive|define
name|CONF_QOS_CS6
value|11
end_define

begin_define
define|#
directive|define
name|CONF_QOS_CS7
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPTOS_PREC_INTERNETCONTROL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_IPTOS_SUPPORT */
end_comment

begin_comment
comment|/*  * We keep config trees around for possible saveconfig use.  When  * built with configure --disable-saveconfig, and when built with  * debugging enabled, include the free_config_*() routines.  In the  * DEBUG case, they are used in an atexit() cleanup routine to make  * postmortem leak check reports more interesting.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FREE_CFG_T
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|SAVECONFIG
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|FREE_CFG_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Limits */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|1024
end_define

begin_comment
comment|/* Configuration sources */
end_comment

begin_define
define|#
directive|define
name|CONF_SOURCE_FILE
value|0
end_define

begin_define
define|#
directive|define
name|CONF_SOURCE_NTPQ
value|1
end_define

begin_comment
comment|/* Structure for storing an attribute-value pair  */
end_comment

begin_struct
struct|struct
name|attr_val
block|{
name|int
name|attr
decl_stmt|;
union|union
name|val
block|{
name|double
name|d
decl_stmt|;
name|int
name|i
decl_stmt|;
name|u_int
name|u
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
name|void
modifier|*
name|p
decl_stmt|;
block|}
name|value
union|;
name|int
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure for nodes on the syntax tree */
end_comment

begin_struct
struct|struct
name|address_node
block|{
name|char
modifier|*
name|address
decl_stmt|;
name|int
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|restrict_node
block|{
name|struct
name|address_node
modifier|*
name|addr
decl_stmt|;
name|struct
name|address_node
modifier|*
name|mask
decl_stmt|;
name|queue
modifier|*
name|flags
decl_stmt|;
name|int
name|line_no
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|peer_node
block|{
name|int
name|host_mode
decl_stmt|;
name|struct
name|address_node
modifier|*
name|addr
decl_stmt|;
name|queue
modifier|*
name|peerflags
decl_stmt|;
name|int
name|minpoll
decl_stmt|;
name|int
name|maxpoll
decl_stmt|;
name|int
name|ttl
decl_stmt|;
name|int
name|peerversion
decl_stmt|;
name|int
name|peerkey
decl_stmt|;
name|double
name|bias
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unpeer_node
block|{
name|u_int
name|assocID
decl_stmt|;
name|struct
name|address_node
modifier|*
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|auth_node
block|{
name|int
name|control_key
decl_stmt|;
name|int
name|cryptosw
decl_stmt|;
name|queue
modifier|*
name|crypto_cmd_list
decl_stmt|;
name|char
modifier|*
name|keys
decl_stmt|;
name|char
modifier|*
name|keysdir
decl_stmt|;
name|int
name|request_key
decl_stmt|;
name|int
name|revoke
decl_stmt|;
name|queue
modifier|*
name|trusted_key_list
decl_stmt|;
name|char
modifier|*
name|ntp_signd_socket
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|filegen_node
block|{
name|int
name|filegen_token
decl_stmt|;
name|queue
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|setvar_node
block|{
name|char
modifier|*
name|var
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
name|int
name|isdefault
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|nic_rule_node_tag
block|{
name|int
name|match_class
decl_stmt|;
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* interface name or numeric address */
name|int
name|action
decl_stmt|;
block|}
name|nic_rule_node
typedef|;
end_typedef

begin_struct
struct|struct
name|addr_opts_node
block|{
name|struct
name|address_node
modifier|*
name|addr
decl_stmt|;
name|queue
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sim_node
block|{
name|queue
modifier|*
name|init_opts
decl_stmt|;
name|queue
modifier|*
name|servers
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The syntax tree */
end_comment

begin_struct
struct|struct
name|config_tree
block|{
name|struct
name|config_tree
modifier|*
name|link
decl_stmt|;
name|struct
name|attr_val
name|source
decl_stmt|;
name|time_t
name|timestamp
decl_stmt|;
name|queue
modifier|*
name|peers
decl_stmt|;
name|queue
modifier|*
name|unpeers
decl_stmt|;
comment|/* Other Modes */
name|int
name|broadcastclient
decl_stmt|;
name|queue
modifier|*
name|manycastserver
decl_stmt|;
name|queue
modifier|*
name|multicastclient
decl_stmt|;
name|queue
modifier|*
name|orphan_cmds
decl_stmt|;
comment|/* Monitoring Configuration */
name|queue
modifier|*
name|stats_list
decl_stmt|;
name|char
modifier|*
name|stats_dir
decl_stmt|;
name|queue
modifier|*
name|filegen_opts
decl_stmt|;
comment|/* Access Control Configuration */
name|queue
modifier|*
name|discard_opts
decl_stmt|;
name|queue
modifier|*
name|restrict_opts
decl_stmt|;
name|queue
modifier|*
name|fudge
decl_stmt|;
name|queue
modifier|*
name|tinker
decl_stmt|;
name|queue
modifier|*
name|enable_opts
decl_stmt|;
name|queue
modifier|*
name|disable_opts
decl_stmt|;
name|struct
name|auth_node
name|auth
decl_stmt|;
name|queue
modifier|*
name|logconfig
decl_stmt|;
name|queue
modifier|*
name|qos
decl_stmt|;
name|queue
modifier|*
name|phone
decl_stmt|;
name|queue
modifier|*
name|setvar
decl_stmt|;
name|queue
modifier|*
name|ttl
decl_stmt|;
name|queue
modifier|*
name|trap
decl_stmt|;
name|queue
modifier|*
name|vars
decl_stmt|;
name|queue
modifier|*
name|nic_rules
decl_stmt|;
name|struct
name|sim_node
modifier|*
name|sim_details
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure for holding a remote configuration command */
end_comment

begin_struct
struct|struct
name|REMOTE_CONFIG_INFO
block|{
name|char
name|buffer
index|[
name|MAXLINE
index|]
decl_stmt|;
name|char
name|err_msg
index|[
name|MAXLINE
index|]
decl_stmt|;
name|int
name|pos
decl_stmt|;
name|int
name|err_pos
decl_stmt|;
name|int
name|no_errors
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* get text from T_ tokens */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|token_name
parameter_list|(
name|int
name|token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|peer_node
modifier|*
name|create_peer_node
parameter_list|(
name|int
name|hmode
parameter_list|,
name|struct
name|address_node
modifier|*
name|addr
parameter_list|,
name|queue
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|unpeer_node
modifier|*
name|create_unpeer_node
parameter_list|(
name|struct
name|address_node
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|address_node
modifier|*
name|create_address_node
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_address_node
parameter_list|(
name|struct
name|address_node
modifier|*
name|my_node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|queue
modifier|*
name|enqueue_in_new_queue
parameter_list|(
name|void
modifier|*
name|my_node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|attr_val
modifier|*
name|create_attr_dval
parameter_list|(
name|int
name|attr
parameter_list|,
name|double
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|attr_val
modifier|*
name|create_attr_ival
parameter_list|(
name|int
name|attr
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|attr_val
modifier|*
name|create_attr_shorts
parameter_list|(
name|int
parameter_list|,
name|ntp_u_int16_t
parameter_list|,
name|ntp_u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|attr_val
modifier|*
name|create_attr_sval
parameter_list|(
name|int
name|attr
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|attr_val
modifier|*
name|create_attr_pval
parameter_list|(
name|int
name|attr
parameter_list|,
name|void
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|filegen_node
modifier|*
name|create_filegen_node
parameter_list|(
name|int
name|filegen_token
parameter_list|,
name|queue
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
modifier|*
name|create_pval
parameter_list|(
name|void
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|restrict_node
modifier|*
name|create_restrict_node
parameter_list|(
name|struct
name|address_node
modifier|*
name|addr
parameter_list|,
name|struct
name|address_node
modifier|*
name|mask
parameter_list|,
name|queue
modifier|*
name|flags
parameter_list|,
name|int
name|line_no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|create_ival
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|addr_opts_node
modifier|*
name|create_addr_opts_node
parameter_list|(
name|struct
name|address_node
modifier|*
name|addr
parameter_list|,
name|queue
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sim_node
modifier|*
name|create_sim_node
parameter_list|(
name|queue
modifier|*
name|init_opts
parameter_list|,
name|queue
modifier|*
name|servers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|setvar_node
modifier|*
name|create_setvar_node
parameter_list|(
name|char
modifier|*
name|var
parameter_list|,
name|char
modifier|*
name|val
parameter_list|,
name|int
name|isdefault
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nic_rule_node
modifier|*
name|create_nic_rule_node
parameter_list|(
name|int
name|match_class
parameter_list|,
name|char
modifier|*
name|if_name
parameter_list|,
name|int
name|action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|script_info
modifier|*
name|create_sim_script_info
parameter_list|(
name|double
name|duration
parameter_list|,
name|queue
modifier|*
name|script_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|server_info
modifier|*
name|create_sim_server
parameter_list|(
name|struct
name|address_node
modifier|*
name|addr
parameter_list|,
name|double
name|server_offset
parameter_list|,
name|queue
modifier|*
name|script
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|REMOTE_CONFIG_INFO
name|remote_config
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|config_remotely
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SAVECONFIG
end_ifdef

begin_function_decl
name|int
name|dump_config_tree
parameter_list|(
name|struct
name|config_tree
modifier|*
name|ptree
parameter_list|,
name|FILE
modifier|*
name|df
parameter_list|,
name|int
name|comment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dump_all_config_trees
parameter_list|(
name|FILE
modifier|*
name|df
parameter_list|,
name|int
name|comment
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NTP_CONFIG_H) */
end_comment

end_unit

