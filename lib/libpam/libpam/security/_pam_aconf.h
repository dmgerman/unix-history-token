begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* _pam_aconf.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/*  * $Id: _pam_aconf.h.in,v 1.4 2000/12/04 20:56:10 baggins Exp $  * $FreeBSD$  *  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_ACONF_H
end_ifndef

begin_define
define|#
directive|define
name|PAM_ACONF_H
end_define

begin_comment
comment|/* lots of stuff gets written to /tmp/pam-debug.log */
end_comment

begin_comment
comment|/* #undef DEBUG */
end_comment

begin_comment
comment|/* build libraries with different names (suffixed with 'd') */
end_comment

begin_comment
comment|/* #undef WITH_LIBDEBUG */
end_comment

begin_comment
comment|/* provide a global locking facility within libpam */
end_comment

begin_comment
comment|/* #undef PAM_LOCKING */
end_comment

begin_comment
comment|/* GNU systems as a class, all have the feature.h file */
end_comment

begin_comment
comment|/* #undef HAVE_FEATURES_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FEATURES_H
end_ifdef

begin_define
define|#
directive|define
name|_SVID_SOURCE
end_define

begin_define
define|#
directive|define
name|_BSD_SOURCE
end_define

begin_define
define|#
directive|define
name|__USE_BSD
end_define

begin_define
define|#
directive|define
name|__USE_SVID
end_define

begin_define
define|#
directive|define
name|__USE_MISC
end_define

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_include
include|#
directive|include
file|<features.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FEATURES_H */
end_comment

begin_comment
comment|/* we have libcrack available */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCRACK */
end_comment

begin_comment
comment|/* we have libcrypt - its not part of libc (do we need both definitions?) */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCRYPT */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPT_H */
end_comment

begin_comment
comment|/* we have libndbm and/or libdb */
end_comment

begin_define
define|#
directive|define
name|HAVE_DB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NDBM_H
value|1
end_define

begin_comment
comment|/* have libfl (Flex) */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBFL
value|1
end_define

begin_comment
comment|/* have libnsl - instead of libc support */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL */
end_comment

begin_comment
comment|/* have libpwdb - don't expect this to be important for much longer */
end_comment

begin_comment
comment|/* #undef HAVE_LIBPWDB */
end_comment

begin_comment
comment|/* ugly hack to partially support old pam_strerror syntax */
end_comment

begin_comment
comment|/* #undef UGLY_HACK_FOR_PRIOR_BEHAVIOR_SUPPORT */
end_comment

begin_comment
comment|/* read both confs - read /etc/pam.d and /etc/pam.conf in serial */
end_comment

begin_comment
comment|/* #undef PAM_READ_BOTH_CONFS */
end_comment

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PATHS_H
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* location of the mail spool directory */
end_comment

begin_define
define|#
directive|define
name|PAM_PATH_MAILDIR
value|_PATH_MAILDIR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAM_ACONF_H */
end_comment

end_unit

