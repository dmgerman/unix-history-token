begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nbtool_config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/*	$NetBSD: nbtool_config.h.in,v 1.4 2004/06/20 22:20:15 jmc Exp $	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NETBSD_NBTOOL_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|__NETBSD_NBTOOL_CONFIG_H__
end_define

begin_comment
comment|/* Values set by "configure" based on available functions in the host. */
end_comment

begin_define
define|#
directive|define
name|PATH_BSHELL
value|"/bin/sh"
end_define

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERR_H
value|1
end_define

begin_comment
comment|/* #undef HAVE_FEATURES_H */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIBGEN_H
value|1
end_define

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* #undef HAVE_MACHINE_BSWAP_H */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_POLL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_ENDIAN_H
value|1
end_define

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SYSLIMITS_H */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SYSMACROS_H */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ID_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SOCKLEN_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_LONG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_SHORT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_QUAD_T
value|1
end_define

begin_comment
comment|/* #undef HAVE_BSWAP16 */
end_comment

begin_comment
comment|/* #undef HAVE_BSWAP32 */
end_comment

begin_comment
comment|/* #undef HAVE_BSWAP64 */
end_comment

begin_comment
comment|/* #undef HAVE_HTOBE16 */
end_comment

begin_comment
comment|/* #undef HAVE_HTOBE32 */
end_comment

begin_comment
comment|/* #undef HAVE_HTOBE64 */
end_comment

begin_comment
comment|/* #undef HAVE_HTOLE16 */
end_comment

begin_comment
comment|/* #undef HAVE_HTOLE32 */
end_comment

begin_comment
comment|/* #undef HAVE_HTOLE64 */
end_comment

begin_comment
comment|/* #undef HAVE_BE16TOH */
end_comment

begin_comment
comment|/* #undef HAVE_BE32TOH */
end_comment

begin_comment
comment|/* #undef HAVE_BE64TOH */
end_comment

begin_comment
comment|/* #undef HAVE_LE16TOH */
end_comment

begin_comment
comment|/* #undef HAVE_LE32TOH */
end_comment

begin_comment
comment|/* #undef HAVE_LE64TOH */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIR_DD_FD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_DIRENT_D_NAMLEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_FLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_GEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BIRTHTIME
value|1
end_define

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_ATIM */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_MTIMENSEC */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STATFS_F_IOSIZE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_OPTIND
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_OPTRESET
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_SYS_SIGNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_comment
comment|/* #undef HAVE_ASNPRINTF */
end_comment

begin_define
define|#
directive|define
name|HAVE_BASENAME
value|1
end_define

begin_comment
comment|/* #undef HAVE_CGETNEXT */
end_comment

begin_define
define|#
directive|define
name|HAVE_DEVNAME
value|1
end_define

begin_comment
comment|/* #undef HAVE_DIRFD */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FGETLN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FLOCK
value|1
end_define

begin_comment
comment|/* #undef HAVE_FPARSELN */
end_comment

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETOPT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETOPT_LONG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GROUP_FROM_GID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ISBLANK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ISSETUGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHFLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHMOD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LUTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKDTEMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PREAD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PUTC_UNLOCKED
value|1
end_define

begin_comment
comment|/* #undef HAVE_PWCACHE_USERDB */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWRITE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RANDOM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETGROUPENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETPASSENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETPROGNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_comment
comment|/* #undef HAVE_STRSUFTOULL */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOLL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_USER_FROM_UID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
value|1
end_define

begin_comment
comment|/* #undef HAVE_VASNPRINTF */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_SETGROUPENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_SETPASSENT
value|1
end_define

begin_comment
comment|/* #undef WORDS_BIGENDIAN */
end_comment

begin_comment
comment|/* Typedefs that might be missing. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* #undef uint8_t */
end_comment

begin_comment
comment|/* #undef uint16_t */
end_comment

begin_comment
comment|/* #undef uint32_t */
end_comment

begin_comment
comment|/* #undef uint64_t */
end_comment

begin_comment
comment|/* #undef u_int8_t */
end_comment

begin_comment
comment|/* #undef u_int16_t */
end_comment

begin_comment
comment|/* #undef u_int32_t */
end_comment

begin_comment
comment|/* #undef u_int64_t */
end_comment

begin_comment
comment|/* Now pull in the compatibility definitions. */
end_comment

begin_include
include|#
directive|include
file|"compat_defs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__NETBSD_NBTOOL_CONFIG_H__ */
end_comment

end_unit

