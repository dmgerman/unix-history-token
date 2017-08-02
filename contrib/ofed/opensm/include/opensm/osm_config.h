begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/opensm/osm_config.h.  Generated from osm_config.h.in by configure.  */
end_comment

begin_comment
comment|/* include/osm_config.h.in  *  * Defines various OpenSM configuration parameters to be used by various  * plugins and third party tools.  *  * NOTE: Defines used in header files MUST be included here to ensure plugin  * compatibility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_CONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_CONFIG_H_
value|1
end_define

begin_comment
comment|/* define 1 if OpenSM build is in a debug mode */
end_comment

begin_comment
comment|/* #undef OSM_DEBUG */
end_comment

begin_comment
comment|/* #undef _DEBUG_ */
end_comment

begin_comment
comment|/* Define as 1 if you want Dual Sided RMPP Support */
end_comment

begin_define
define|#
directive|define
name|DUAL_SIDED_RMPP
value|1
end_define

begin_comment
comment|/* Define as 1 if you want to enable a console on a socket connection */
end_comment

begin_comment
comment|/* #undef ENABLE_OSM_CONSOLE_SOCKET */
end_comment

begin_comment
comment|/* Define as 1 if you want to enable the event plugin */
end_comment

begin_comment
comment|/* #undef ENABLE_OSM_DEFAULT_EVENT_PLUGIN */
end_comment

begin_comment
comment|/* Define as 1 if you want to enable the performance manager */
end_comment

begin_define
define|#
directive|define
name|ENABLE_OSM_PERF_MGR
value|1
end_define

begin_comment
comment|/* Define as 1 if you want to enable the performance manager profiling code */
end_comment

begin_comment
comment|/* #undef ENABLE_OSM_PERF_MGR_PROFILE */
end_comment

begin_comment
comment|/* Define a default node name map file */
end_comment

begin_define
define|#
directive|define
name|HAVE_DEFAULT_NODENAME_MAP
value|"/etc/opensm/ib-node-name-map"
end_define

begin_comment
comment|/* Define a default OpenSM config file */
end_comment

begin_define
define|#
directive|define
name|HAVE_DEFAULT_OPENSM_CONFIG_FILE
value|"/etc/opensm/opensm.conf"
end_define

begin_comment
comment|/* Define a Partition config file */
end_comment

begin_define
define|#
directive|define
name|HAVE_DEFAULT_PARTITION_CONFIG_FILE
value|"/etc/opensm/partitions.conf"
end_define

begin_comment
comment|/* Define a Prefix Routes config file */
end_comment

begin_define
define|#
directive|define
name|HAVE_DEFAULT_PREFIX_ROUTES_FILE
value|"/etc/opensm/prefix-routes.conf"
end_define

begin_comment
comment|/* Define a QOS policy config file */
end_comment

begin_define
define|#
directive|define
name|HAVE_DEFAULT_QOS_POLICY_FILE
value|"/etc/opensm/qos-policy.conf"
end_define

begin_comment
comment|/* Define OpenSM config directory */
end_comment

begin_define
define|#
directive|define
name|OPENSM_CONFIG_DIR
value|"/etc/opensm"
end_define

begin_comment
comment|/* Define as 1 for vapi vendor */
end_comment

begin_comment
comment|/* #undef OSM_VENDOR_INTF_MTL */
end_comment

begin_comment
comment|/* Define as 1 for OpenIB vendor */
end_comment

begin_define
define|#
directive|define
name|OSM_VENDOR_INTF_OPENIB
value|1
end_define

begin_comment
comment|/* Define as 1 for sim vendor */
end_comment

begin_comment
comment|/* #undef OSM_VENDOR_INTF_SIM */
end_comment

begin_comment
comment|/* Define as 1 for ts vendor */
end_comment

begin_comment
comment|/* #undef OSM_VENDOR_INTF_TS */
end_comment

begin_comment
comment|/* Define as 1 if you want Vendor RMPP Support */
end_comment

begin_define
define|#
directive|define
name|VENDOR_RMPP_SUPPORT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread' library (-lpthread). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBPTHREAD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_CONFIG_H_ */
end_comment

end_unit

