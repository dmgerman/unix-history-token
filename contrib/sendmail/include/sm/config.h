begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: config.h,v 1.44 2002/01/23 17:47:15 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  libsm configuration macros. **  The values of these macros are platform dependent. **  The default values are given here. **  If the default is incorrect, then the correct value can be specified **  in the m4 configuration file in devtools/OS. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|SM_CONFIG_H
end_define

begin_include
include|#
directive|include
file|"sm_os.h"
end_include

begin_comment
comment|/* **  SM_CONF_STDBOOL_H is 1 if<stdbool.h> exists */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_STDBOOL_H
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_define
define|#
directive|define
name|SM_CONF_STDBOOL_H
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__STDC_VERSION__)&& __STDC_VERSION__>= 199901L */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_STDBOOL_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC_VERSION__)&& __STDC_VERSION__>= 199901L */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_STDBOOL_H */
end_comment

begin_comment
comment|/* **  Configuration macros that specify how __P is defined. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SYS_CDEFS_H
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SYS_CDEFS_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_SYS_CDEFS_H */
end_comment

begin_comment
comment|/* **  SM_CONF_STDDEF_H is 1 if<stddef.h> exists */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_STDDEF_H
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_STDDEF_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_STDDEF_H */
end_comment

begin_comment
comment|/* **  Configuration macro that specifies whether strlcpy/strlcat are available. **  Note: this is the default so that the libsm version (optimized) will **  be used by default (sm_strlcpy/sm_strlcat). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_STRL
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_STRL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_STRL */
end_comment

begin_comment
comment|/* **  Configuration macro indicating that setitimer is available */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SETITIMER
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SETITIMER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_SETITIMER */
end_comment

begin_comment
comment|/* **  Does<sys/types.h> define uid_t and gid_t? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_UID_GID
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_UID_GID
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_UID_GID */
end_comment

begin_comment
comment|/* **  Does<sys/types.h> define ssize_t? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SSIZE_T
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SSIZE_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_SSIZE_T */
end_comment

begin_comment
comment|/* **  Does the C compiler support long long? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_LONGLONG
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_define
define|#
directive|define
name|SM_CONF_LONGLONG
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__STDC_VERSION__)&& __STDC_VERSION__>= 199901L */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_CONF_LONGLONG
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__GNUC__) */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_LONGLONG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GNUC__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC_VERSION__)&& __STDC_VERSION__>= 199901L */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_LONGLONG */
end_comment

begin_comment
comment|/* **  Does<sys/types.h> define quad_t and u_quad_t? **  We only care if long long is not available. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_QUAD_T
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_QUAD_T
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_QUAD_T */
end_comment

begin_comment
comment|/* **  Configuration macro indicating that shared memory is available */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SHM
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SHM
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_SHM */
end_comment

begin_comment
comment|/* **  Does<setjmp.h> define sigsetjmp? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SIGSETJMP
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SIGSETJMP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_SIGSETJMP */
end_comment

begin_comment
comment|/* **  Does<sysexits.h> exist, and define the EX_* macros with values **  that differ from the default BSD values in<sm/sysexits.h>? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SYSEXITS_H
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SYSEXITS_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_SYSEXITS_H */
end_comment

begin_comment
comment|/* has memchr() prototype? (if not: needs memory.h) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_MEMCHR
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_MEMCHR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_MEMCHR */
end_comment

begin_comment
comment|/* try LLONG tests in libsm/t-types.c? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_TEST_LLONG
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_TEST_LLONG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_TEST_LLONG */
end_comment

begin_comment
comment|/* Does LDAP library have ldap_memfree()? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_LDAP_MEMFREE
end_ifndef

begin_comment
comment|/* **  The new LDAP C API (draft-ietf-ldapext-ldap-c-api-04.txt) includes **  ldap_memfree() in the API.  That draft states to use LDAP_API_VERSION **  of 2004 to identify the API. */
end_comment

begin_if
if|#
directive|if
name|USING_NETSCAPE_LDAP
operator|||
name|LDAP_API_VERSION
operator|>=
literal|2004
end_if

begin_define
define|#
directive|define
name|SM_CONF_LDAP_MEMFREE
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USING_NETSCAPE_LDAP || LDAP_API_VERSION>= 2004 */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_LDAP_MEMFREE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USING_NETSCAPE_LDAP || LDAP_API_VERSION>= 2004 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_LDAP_MEMFREE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONFIG_H */
end_comment

end_unit

