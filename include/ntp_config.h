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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RESOURCE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_RESOURCE_H */
end_comment

begin_include
include|#
directive|include
file|"ntp_machine.h"
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
comment|/* list of servers from command line for config_peers() */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cmdline_server_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|cmdline_servers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to zero if admin doesn't want memory locked */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|do_memlock
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|int_range_tag
block|{
name|int
name|first
decl_stmt|;
name|int
name|last
decl_stmt|;
block|}
name|int_range
typedef|;
end_typedef

begin_comment
comment|/* Structure for storing an attribute-value pair  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|attr_val_tag
name|attr_val
typedef|;
end_typedef

begin_struct
struct|struct
name|attr_val_tag
block|{
name|attr_val
modifier|*
name|link
decl_stmt|;
name|int
name|attr
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* T_String, T_Integer, ... */
union|union
name|val
block|{
name|int
name|i
decl_stmt|;
name|u_int
name|u
decl_stmt|;
name|int_range
name|r
decl_stmt|;
name|double
name|d
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|}
name|value
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|attr_val
argument_list|)
name|attr_val_fifo
expr_stmt|;
end_typedef

begin_comment
comment|/* Structure for nodes on the syntax tree */
end_comment

begin_typedef
typedef|typedef
name|struct
name|address_node_tag
name|address_node
typedef|;
end_typedef

begin_struct
struct|struct
name|address_node_tag
block|{
name|address_node
modifier|*
name|link
decl_stmt|;
name|char
modifier|*
name|address
decl_stmt|;
name|u_short
name|type
decl_stmt|;
comment|/* family, AF_UNSPEC (0), AF_INET[6] */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|address_node
argument_list|)
name|address_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|int_node_tag
name|int_node
typedef|;
end_typedef

begin_struct
struct|struct
name|int_node_tag
block|{
name|int_node
modifier|*
name|link
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|int_node
argument_list|)
name|int_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|string_node_tag
name|string_node
typedef|;
end_typedef

begin_struct
struct|struct
name|string_node_tag
block|{
name|string_node
modifier|*
name|link
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|string_node
argument_list|)
name|string_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|restrict_node_tag
name|restrict_node
typedef|;
end_typedef

begin_struct
struct|struct
name|restrict_node_tag
block|{
name|restrict_node
modifier|*
name|link
decl_stmt|;
name|address_node
modifier|*
name|addr
decl_stmt|;
name|address_node
modifier|*
name|mask
decl_stmt|;
name|int_fifo
modifier|*
name|flags
decl_stmt|;
name|int
name|line_no
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|restrict_node
argument_list|)
name|restrict_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|peer_node_tag
name|peer_node
typedef|;
end_typedef

begin_struct
struct|struct
name|peer_node_tag
block|{
name|peer_node
modifier|*
name|link
decl_stmt|;
name|int
name|host_mode
decl_stmt|;
name|address_node
modifier|*
name|addr
decl_stmt|;
name|attr_val_fifo
modifier|*
name|peerflags
decl_stmt|;
name|u_char
name|minpoll
decl_stmt|;
name|u_char
name|maxpoll
decl_stmt|;
name|u_int32
name|ttl
decl_stmt|;
name|u_char
name|peerversion
decl_stmt|;
name|keyid_t
name|peerkey
decl_stmt|;
name|char
modifier|*
name|group
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|peer_node
argument_list|)
name|peer_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|unpeer_node_tag
name|unpeer_node
typedef|;
end_typedef

begin_struct
struct|struct
name|unpeer_node_tag
block|{
name|unpeer_node
modifier|*
name|link
decl_stmt|;
name|associd_t
name|assocID
decl_stmt|;
name|address_node
modifier|*
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|unpeer_node
argument_list|)
name|unpeer_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|auth_node_tag
name|auth_node
typedef|;
end_typedef

begin_struct
struct|struct
name|auth_node_tag
block|{
name|int
name|control_key
decl_stmt|;
name|int
name|cryptosw
decl_stmt|;
name|attr_val_fifo
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
name|attr_val_fifo
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

begin_typedef
typedef|typedef
name|struct
name|filegen_node_tag
name|filegen_node
typedef|;
end_typedef

begin_struct
struct|struct
name|filegen_node_tag
block|{
name|filegen_node
modifier|*
name|link
decl_stmt|;
name|int
name|filegen_token
decl_stmt|;
name|attr_val_fifo
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|filegen_node
argument_list|)
name|filegen_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|setvar_node_tag
name|setvar_node
typedef|;
end_typedef

begin_struct
struct|struct
name|setvar_node_tag
block|{
name|setvar_node
modifier|*
name|link
decl_stmt|;
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
name|DECL_FIFO_ANCHOR
argument_list|(
argument|setvar_node
argument_list|)
name|setvar_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nic_rule_node_tag
name|nic_rule_node
typedef|;
end_typedef

begin_struct
struct|struct
name|nic_rule_node_tag
block|{
name|nic_rule_node
modifier|*
name|link
decl_stmt|;
name|int
name|match_class
decl_stmt|;
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* or numeric address */
name|int
name|action
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|nic_rule_node
argument_list|)
name|nic_rule_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|addr_opts_node_tag
name|addr_opts_node
typedef|;
end_typedef

begin_struct
struct|struct
name|addr_opts_node_tag
block|{
name|addr_opts_node
modifier|*
name|link
decl_stmt|;
name|address_node
modifier|*
name|addr
decl_stmt|;
name|attr_val_fifo
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|addr_opts_node
argument_list|)
name|addr_opts_fifo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sim_node_tag
name|sim_node
typedef|;
end_typedef

begin_struct
struct|struct
name|sim_node_tag
block|{
name|sim_node
modifier|*
name|link
decl_stmt|;
name|attr_val_fifo
modifier|*
name|init_opts
decl_stmt|;
name|server_info_fifo
modifier|*
name|servers
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|sim_node
argument_list|)
name|sim_fifo
expr_stmt|;
end_typedef

begin_comment
comment|/* The syntax tree */
end_comment

begin_typedef
typedef|typedef
name|struct
name|config_tree_tag
name|config_tree
typedef|;
end_typedef

begin_struct
struct|struct
name|config_tree_tag
block|{
name|config_tree
modifier|*
name|link
decl_stmt|;
name|attr_val
name|source
decl_stmt|;
name|time_t
name|timestamp
decl_stmt|;
name|peer_fifo
modifier|*
name|peers
decl_stmt|;
name|unpeer_fifo
modifier|*
name|unpeers
decl_stmt|;
comment|/* Other Modes */
name|int
name|broadcastclient
decl_stmt|;
name|address_fifo
modifier|*
name|manycastserver
decl_stmt|;
name|address_fifo
modifier|*
name|multicastclient
decl_stmt|;
name|attr_val_fifo
modifier|*
name|orphan_cmds
decl_stmt|;
comment|/* s/b renamed tos_options */
comment|/* Monitoring Configuration */
name|int_fifo
modifier|*
name|stats_list
decl_stmt|;
name|char
modifier|*
name|stats_dir
decl_stmt|;
name|filegen_fifo
modifier|*
name|filegen_opts
decl_stmt|;
comment|/* Access Control Configuration */
name|attr_val_fifo
modifier|*
name|discard_opts
decl_stmt|;
name|attr_val_fifo
modifier|*
name|mru_opts
decl_stmt|;
name|restrict_fifo
modifier|*
name|restrict_opts
decl_stmt|;
name|addr_opts_fifo
modifier|*
name|fudge
decl_stmt|;
name|attr_val_fifo
modifier|*
name|rlimit
decl_stmt|;
name|attr_val_fifo
modifier|*
name|tinker
decl_stmt|;
name|attr_val_fifo
modifier|*
name|enable_opts
decl_stmt|;
name|attr_val_fifo
modifier|*
name|disable_opts
decl_stmt|;
name|auth_node
name|auth
decl_stmt|;
name|attr_val_fifo
modifier|*
name|logconfig
decl_stmt|;
name|string_fifo
modifier|*
name|phone
decl_stmt|;
name|setvar_fifo
modifier|*
name|setvar
decl_stmt|;
name|int_fifo
modifier|*
name|ttl
decl_stmt|;
name|addr_opts_fifo
modifier|*
name|trap
decl_stmt|;
name|attr_val_fifo
modifier|*
name|vars
decl_stmt|;
name|nic_rule_fifo
modifier|*
name|nic_rules
decl_stmt|;
name|int_fifo
modifier|*
name|reset_counters
decl_stmt|;
name|sim_fifo
modifier|*
name|sim_details
decl_stmt|;
name|int
name|mdnstries
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
comment|/*  * context for trap_name_resolved() to call ctlsettrap() once the   * name->address resolution completes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|settrap_parms_tag
block|{
name|sockaddr_u
name|ifaddr
decl_stmt|;
name|int
name|ifaddr_nonnull
decl_stmt|;
block|}
name|settrap_parms
typedef|;
end_typedef

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

begin_comment
comment|/* generic fifo routines for structs linked by 1st member */
end_comment

begin_function_decl
name|void
modifier|*
name|append_gen_fifo
parameter_list|(
name|void
modifier|*
name|fifo
parameter_list|,
name|void
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|concat_gen_fifos
parameter_list|(
name|void
modifier|*
name|first
parameter_list|,
name|void
modifier|*
name|second
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|APPEND_G_FIFO
parameter_list|(
name|pf
parameter_list|,
name|pe
parameter_list|)
define|\
value|((pf) = append_gen_fifo((pf), (pe)))
end_define

begin_define
define|#
directive|define
name|CONCAT_G_FIFOS
parameter_list|(
name|first
parameter_list|,
name|second
parameter_list|)
define|\
value|((first) = concat_gen_fifos((first), (second)))
end_define

begin_define
define|#
directive|define
name|HEAD_PFIFO
parameter_list|(
name|pf
parameter_list|)
define|\
value|(((pf) != NULL)			\ 	      ? HEAD_FIFO(*(pf))	\ 	      : NULL)
end_define

begin_function_decl
name|peer_node
modifier|*
name|create_peer_node
parameter_list|(
name|int
name|hmode
parameter_list|,
name|address_node
modifier|*
name|addr
parameter_list|,
name|attr_val_fifo
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unpeer_node
modifier|*
name|create_unpeer_node
parameter_list|(
name|address_node
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|address_node
modifier|*
name|my_node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|attr_val
modifier|*
name|create_attr_uval
parameter_list|(
name|int
name|attr
parameter_list|,
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|attr_val
modifier|*
name|create_attr_rangeval
parameter_list|(
name|int
name|attr
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|attr_val
modifier|*
name|create_attr_sval
parameter_list|(
name|int
name|attr
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|filegen_node
modifier|*
name|create_filegen_node
parameter_list|(
name|int
name|filegen_token
parameter_list|,
name|attr_val_fifo
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|string_node
modifier|*
name|create_string_node
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|restrict_node
modifier|*
name|create_restrict_node
parameter_list|(
name|address_node
modifier|*
name|addr
parameter_list|,
name|address_node
modifier|*
name|mask
parameter_list|,
name|int_fifo
modifier|*
name|flags
parameter_list|,
name|int
name|line_no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int_node
modifier|*
name|create_int_node
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|addr_opts_node
modifier|*
name|create_addr_opts_node
parameter_list|(
name|address_node
modifier|*
name|addr
parameter_list|,
name|attr_val_fifo
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sim_node
modifier|*
name|create_sim_node
parameter_list|(
name|attr_val_fifo
modifier|*
name|init_opts
parameter_list|,
name|server_info_fifo
modifier|*
name|servers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|attr_val_fifo
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
name|address_node
modifier|*
name|addr
parameter_list|,
name|double
name|server_offset
parameter_list|,
name|script_info_fifo
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SETRLIMIT
argument_list|)
end_if

begin_function_decl
name|void
name|ntp_rlimit
parameter_list|(
name|int
parameter_list|,
name|rlim_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
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

