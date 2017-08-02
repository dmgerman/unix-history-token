begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
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
comment|/* Define as 1 if you want to enable a loopback console */
end_comment

begin_define
define|#
directive|define
name|ENABLE_OSM_CONSOLE_LOOPBACK
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
comment|/* Define to 1 if the compiler supports __builtin_expect. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BUILTIN_EXPECT
value|1
end_define

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
comment|/* Define a Per Module Logging config file */
end_comment

begin_define
define|#
directive|define
name|HAVE_DEFAULT_PER_MOD_LOGGING_FILE
value|"/etc/opensm/per-module-logging.conf"
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
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `ibumad' library (-libumad). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBIBUMAD
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

begin_comment
comment|/* Define to 1 if you have the `vapi' library (-lvapi). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBVAPI */
end_comment

begin_comment
comment|/* Define to 1 if you have the `wrap' library (-lwrap). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBWRAP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
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
comment|/* define 1 if OpenSM build is in a debug mode */
end_comment

begin_comment
comment|/* #undef OSM_DEBUG */
end_comment

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
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"opensm"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"linux-rdma@vger.kernel.org"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"opensm"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"opensm 3.3.20"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"opensm"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"3.3.20"
end_define

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to 1 if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
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
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"3.3.20"
end_define

begin_comment
comment|/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a    `char[]'. */
end_comment

begin_define
define|#
directive|define
name|YYTEXT_POINTER
value|1
end_define

begin_comment
comment|/* define 1 if OpenSM build is in a debug mode */
end_comment

begin_comment
comment|/* #undef _DEBUG_ */
end_comment

begin_comment
comment|/* mark config.h inclusion */
end_comment

begin_define
define|#
directive|define
name|_OSM_CONFIG_H_
value|1
end_define

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* #undef inline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to empty if the keyword `volatile' does not work. Warning: valid    code using `volatile' can become incorrect without. Disable with care. */
end_comment

begin_comment
comment|/* #undef volatile */
end_comment

end_unit

