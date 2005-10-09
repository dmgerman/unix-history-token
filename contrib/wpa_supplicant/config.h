begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_CTRL_IFACE_UDP
end_ifndef

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_CTRL_IFACE_UDP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_CTRL_IFACE */
end_comment

begin_include
include|#
directive|include
file|"config_ssid.h"
end_include

begin_struct
struct|struct
name|wpa_config
block|{
name|struct
name|wpa_ssid
modifier|*
name|ssid
decl_stmt|;
comment|/* global network list */
name|struct
name|wpa_ssid
modifier|*
modifier|*
name|pssid
decl_stmt|;
comment|/* per priority network lists (in priority 				  * order) */
name|int
name|num_prio
decl_stmt|;
comment|/* number of different priorities */
name|int
name|eapol_version
decl_stmt|;
name|int
name|ap_scan
decl_stmt|;
name|char
modifier|*
name|ctrl_interface
decl_stmt|;
comment|/* directory for UNIX domain sockets */
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE
ifndef|#
directive|ifndef
name|CONFIG_CTRL_IFACE_UDP
name|gid_t
name|ctrl_interface_gid
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_CTRL_IFACE_UDP */
name|int
name|ctrl_interface_gid_set
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_CTRL_IFACE */
name|int
name|fast_reauth
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|wpa_config
modifier|*
name|wpa_config_read
parameter_list|(
specifier|const
name|char
modifier|*
name|config_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_config_free
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_H */
end_comment

end_unit

