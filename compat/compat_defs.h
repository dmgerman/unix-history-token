begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: compat_defs.h,v 1.43 2004/06/23 11:08:01 tron Exp $	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NETBSD_COMPAT_DEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__NETBSD_COMPAT_DEFS_H__
end_define

begin_comment
comment|/* Work around some complete brain damage. */
end_comment

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

begin_undef
undef|#
directive|undef
name|_POSIX_C_SOURCE
end_undef

begin_comment
comment|/* System headers needed for (re)definitions below. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* time.h needs to be pulled in first at least on netbsd w/o _NETBSD_SOURCE */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_CDEFS_H
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SYSLIMITS_H
end_if

begin_include
include|#
directive|include
file|<sys/syslimits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SYSMACROS_H
end_if

begin_comment
comment|/* major(), minor() on SVR4 */
end_comment

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDDEF_H
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We don't include<pwd.h> here, so that "compat_pwd.h" works. */
end_comment

begin_struct_decl
struct_decl|struct
name|passwd
struct_decl|;
end_struct_decl

begin_comment
comment|/* Some things usually in BSD<sys/cdefs.h>. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RENAME
end_ifndef

begin_define
define|#
directive|define
name|__RENAME
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Dirent support. */
end_comment

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_define
define|#
directive|define
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|(strlen((dirent)->d_name))
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_FPARSELN
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|FPARSELN_UNESCESC
value|0x01
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCCONT
value|0x02
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCCOMM
value|0x04
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCREST
value|0x08
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCALL
value|0x0f
end_define

begin_function_decl
name|char
modifier|*
name|fparseln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|char
index|[
literal|3
index|]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__nbcompat_bswap16
parameter_list|(
name|x
parameter_list|)
value|((((x)<< 8)& 0xff00) | (((x)>> 8)& 0x00ff))
end_define

begin_define
define|#
directive|define
name|__nbcompat_bswap32
parameter_list|(
name|x
parameter_list|)
value|((((x)<< 24)& 0xff000000) | \ 				 (((x)<<  8)& 0x00ff0000) | \ 				 (((x)>>  8)& 0x0000ff00) | \ 				 (((x)>> 24)& 0x000000ff))
end_define

begin_define
define|#
directive|define
name|__nbcompat_bswap64
parameter_list|(
name|x
parameter_list|)
value|(((u_int64_t)bswap32((x))<< 32) | \ 				 ((u_int64_t)bswap32((x)>> 32)))
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_BSWAP16
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|bswap16
end_ifdef

begin_undef
undef|#
directive|undef
name|bswap16
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bswap16
parameter_list|(
name|x
parameter_list|)
value|__nbcompat_bswap16(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_BSWAP32
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|bswap32
end_ifdef

begin_undef
undef|#
directive|undef
name|bswap32
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bswap32
parameter_list|(
name|x
parameter_list|)
value|__nbcompat_bswap32(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_BSWAP64
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|bswap64
end_ifdef

begin_undef
undef|#
directive|undef
name|bswap64
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bswap64
parameter_list|(
name|x
parameter_list|)
value|__nbcompat_bswap64(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_PWCACHE_USERDB
end_if

begin_function_decl
name|int
name|uid_from_user
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|pwcache_userdb
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
argument_list|,
expr|struct
name|passwd
operator|*
call|(
modifier|*
call|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
argument_list|,
expr|struct
name|passwd
operator|*
call|(
modifier|*
call|)
argument_list|(
name|uid_t
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|gid_from_group
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|pwcache_groupdb
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
argument_list|,
expr|struct
name|group
operator|*
call|(
modifier|*
call|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
argument_list|,
expr|struct
name|group
operator|*
call|(
modifier|*
call|)
argument_list|(
name|gid_t
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make them use our version */
end_comment

begin_define
define|#
directive|define
name|user_from_uid
value|__nbcompat_user_from_uid
end_define

begin_comment
comment|/* Make them use our version */
end_comment

begin_define
define|#
directive|define
name|group_from_gid
value|__nbcompat_group_from_gid
end_define

begin_if
if|#
directive|if
name|HAVE_GROUP_FROM_GID
end_if

begin_function_decl
specifier|const
name|char
modifier|*
name|group_from_gid
parameter_list|(
name|gid_t
parameter_list|,
name|int
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
operator|!
name|HAVE_SETENV
end_if

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
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
operator|!
name|HAVE_STRSUFTOLL
end_if

begin_function_decl
name|long
name|long
name|strsuftoll
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|strsuftollx
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
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
operator|!
name|HAVE_USER_FROM_UID
end_if

begin_function_decl
specifier|const
name|char
modifier|*
name|user_from_uid
parameter_list|(
name|uid_t
parameter_list|,
name|int
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
operator|!
name|HAVE_GROUP_FROM_GID
end_if

begin_function_decl
specifier|const
name|char
modifier|*
name|group_from_gid
parameter_list|(
name|gid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * getmode() and setmode() are always defined, as these function names  * exist but with very different meanings on other OS's.  The compat  * versions here simply accept an octal mode number; the "u+x,g-w" type  * of syntax is not accepted.  */
end_comment

begin_define
define|#
directive|define
name|getmode
value|__nbcompat_getmode
end_define

begin_define
define|#
directive|define
name|setmode
value|__nbcompat_setmode
end_define

begin_function_decl
name|mode_t
name|getmode
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|setmode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Eliminate assertions embedded in binaries. */
end_comment

begin_undef
undef|#
directive|undef
name|_DIAGASSERT
end_undef

begin_define
define|#
directive|define
name|_DIAGASSERT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* Various sources use this */
end_comment

begin_undef
undef|#
directive|undef
name|__RCSID
end_undef

begin_define
define|#
directive|define
name|__RCSID
parameter_list|(
name|x
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|__SCCSID
end_undef

begin_define
define|#
directive|define
name|__SCCSID
parameter_list|(
name|x
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|__COPYRIGHT
end_undef

begin_define
define|#
directive|define
name|__COPYRIGHT
parameter_list|(
name|x
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|__KERNEL_RCSID
end_undef

begin_define
define|#
directive|define
name|__KERNEL_RCSID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_comment
comment|/* Heimdal expects this one. */
end_comment

begin_undef
undef|#
directive|undef
name|RCSID
end_undef

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|x
parameter_list|)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXFRAG
end_ifndef

begin_define
define|#
directive|define
name|MAXFRAG
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__NETBSD_COMPAT_DEFS_H__ */
end_comment

end_unit

