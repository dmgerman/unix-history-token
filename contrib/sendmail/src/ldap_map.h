begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Sendmail, Inc.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_comment
comment|/* **  Support for LDAP. ** **	Contributed by Booker C. Bense<bbense+ldap@stanford.edu>. **	Please go to him for support -- since I (Eric) don't run LDAP, I **	can't help you at all. ** **	@(#)ldap_map.h	8.12 (Berkeley) 2/2/1999 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LDAP_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|_LDAP_MAP_H
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_struct
struct|struct
name|ldap_map_struct
block|{
comment|/* needed for ldap_open */
name|char
modifier|*
name|ldaphost
decl_stmt|;
name|int
name|ldapport
decl_stmt|;
comment|/* Options set in ld struct before ldap_bind_s */
name|int
name|deref
decl_stmt|;
name|int
name|timelimit
decl_stmt|;
name|int
name|sizelimit
decl_stmt|;
name|int
name|ldap_options
decl_stmt|;
comment|/* args for ldap_bind_s */
name|LDAP
modifier|*
name|ld
decl_stmt|;
name|char
modifier|*
name|binddn
decl_stmt|;
name|char
modifier|*
name|passwd
decl_stmt|;
name|int
name|method
decl_stmt|;
comment|/* args for ldap_search_st */
name|char
modifier|*
name|base
decl_stmt|;
name|int
name|scope
decl_stmt|;
name|char
modifier|*
name|filter
decl_stmt|;
name|char
modifier|*
name|attr
index|[
literal|2
index|]
decl_stmt|;
name|int
name|attrsonly
decl_stmt|;
name|struct
name|timeval
name|timeout
decl_stmt|;
name|LDAPMessage
modifier|*
name|res
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ldap_map_struct
name|LDAP_MAP_STRUCT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_PORT
value|LDAP_PORT
end_define

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_SCOPE
value|LDAP_SCOPE_SUBTREE
end_define

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_BINDDN
value|NULL
end_define

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_PASSWD
value|NULL
end_define

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_METHOD
value|LDAP_AUTH_SIMPLE
end_define

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_TIMELIMIT
value|5
end_define

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_DEREF
value|LDAP_DEREF_NEVER
end_define

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_SIZELIMIT
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_ATTRSONLY
value|0
end_define

begin_define
define|#
directive|define
name|LDAP_MAP_MAX_FILTER
value|1024
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LDAP_REFERRALS
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_LDAP_OPTIONS
value|LDAP_OPT_REFERRALS
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LDAP_REFERRALS */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_LDAP_MAP_LDAP_OPTIONS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDAP_REFERRALS */
end_comment

begin_comment
comment|/* **  ldap_init(3) is broken in Umich 3.x and OpenLDAP 1.0/1.1. **  Use the lack of LDAP_OPT_SIZELIMIT to detect old API implementations **  and assume (falsely) that all old API implementations are broken. **  (OpenLDAP 1.2 and later have a working ldap_init(), add -DUSE_LDAP_INIT) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LDAP_OPT_SIZELIMIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_LDAP_INIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LDAP_INIT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  LDAP_OPT_SIZELIMIT is not defined under Umich 3.x nor OpenLDAP 1.x, **  hence ldap_set_option() must not exist. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LDAP_OPT_SIZELIMIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_LDAP_SET_OPTION
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LDAP_SET_OPTION
value|1
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
comment|/* _LDAP_MAP_H */
end_comment

end_unit

