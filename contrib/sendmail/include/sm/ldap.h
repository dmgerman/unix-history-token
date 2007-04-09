begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003, 2005, 2006 Sendmail, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: ldap.h,v 1.32 2006/08/30 22:56:58 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_LDAP_H
end_ifndef

begin_define
define|#
directive|define
name|SM_LDAP_H
end_define

begin_include
include|#
directive|include
file|<sm/conf.h>
end_include

begin_include
include|#
directive|include
file|<sm/rpool.h>
end_include

begin_comment
comment|/* **  NOTE: These should be changed from LDAPMAP_* to SM_LDAP_* **	in the next major release (8.x+1) of sendmail. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDAPMAP_MAX_ATTR
end_ifndef

begin_define
define|#
directive|define
name|LDAPMAP_MAX_ATTR
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LDAPMAP_MAX_ATTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDAPMAP_MAX_FILTER
end_ifndef

begin_define
define|#
directive|define
name|LDAPMAP_MAX_FILTER
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LDAPMAP_MAX_FILTER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDAPMAP_MAX_PASSWD
end_ifndef

begin_define
define|#
directive|define
name|LDAPMAP_MAX_PASSWD
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LDAPMAP_MAX_PASSWD */
end_comment

begin_if
if|#
directive|if
name|LDAPMAP
end_if

begin_comment
comment|/* maximum number of arguments in a map lookup, see sendmail.h: MAX_MAP_ARGS */
end_comment

begin_define
define|#
directive|define
name|SM_LDAP_ARGS
value|10
end_define

begin_comment
comment|/* error codes from sm_ldap_search*() */
end_comment

begin_define
define|#
directive|define
name|SM_LDAP_ERR
value|(-1)
end_define

begin_comment
comment|/* generic error: ldap_search(3) */
end_comment

begin_define
define|#
directive|define
name|SM_LDAP_ERR_ARG_MISS
value|(-2)
end_define

begin_comment
comment|/* an argument is missing */
end_comment

begin_comment
comment|/* Attribute types */
end_comment

begin_define
define|#
directive|define
name|SM_LDAP_ATTR_NONE
value|(-1)
end_define

begin_define
define|#
directive|define
name|SM_LDAP_ATTR_OBJCLASS
value|0
end_define

begin_define
define|#
directive|define
name|SM_LDAP_ATTR_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|SM_LDAP_ATTR_DN
value|2
end_define

begin_define
define|#
directive|define
name|SM_LDAP_ATTR_FILTER
value|3
end_define

begin_define
define|#
directive|define
name|SM_LDAP_ATTR_URL
value|4
end_define

begin_comment
comment|/* sm_ldap_results() flags */
end_comment

begin_define
define|#
directive|define
name|SM_LDAP_SINGLEMATCH
value|0x0001
end_define

begin_define
define|#
directive|define
name|SM_LDAP_MATCHONLY
value|0x0002
end_define

begin_define
define|#
directive|define
name|SM_LDAP_USE_ALLATTR
value|0x0004
end_define

begin_define
define|#
directive|define
name|SM_LDAP_SINGLEDN
value|0x0008
end_define

begin_struct
struct|struct
name|sm_ldap_struct
block|{
comment|/* needed for ldap_open or ldap_init */
name|char
modifier|*
name|ldap_uri
decl_stmt|;
name|char
modifier|*
name|ldap_host
decl_stmt|;
name|int
name|ldap_port
decl_stmt|;
name|int
name|ldap_version
decl_stmt|;
name|pid_t
name|ldap_pid
decl_stmt|;
comment|/* options set in ld struct before ldap_bind_s */
name|int
name|ldap_deref
decl_stmt|;
name|time_t
name|ldap_timelimit
decl_stmt|;
name|int
name|ldap_sizelimit
decl_stmt|;
name|int
name|ldap_options
decl_stmt|;
comment|/* args for ldap_bind_s */
name|LDAP
modifier|*
name|ldap_ld
decl_stmt|;
name|char
modifier|*
name|ldap_binddn
decl_stmt|;
name|char
modifier|*
name|ldap_secret
decl_stmt|;
name|int
name|ldap_method
decl_stmt|;
comment|/* args for ldap_search */
name|char
modifier|*
name|ldap_base
decl_stmt|;
name|int
name|ldap_scope
decl_stmt|;
name|char
modifier|*
name|ldap_filter
decl_stmt|;
name|char
modifier|*
name|ldap_attr
index|[
name|LDAPMAP_MAX_ATTR
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|ldap_attr_type
index|[
name|LDAPMAP_MAX_ATTR
operator|+
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|ldap_attr_needobjclass
index|[
name|LDAPMAP_MAX_ATTR
operator|+
literal|1
index|]
decl_stmt|;
name|bool
name|ldap_attrsonly
decl_stmt|;
name|bool
name|ldap_multi_args
decl_stmt|;
comment|/* args for ldap_result */
name|struct
name|timeval
name|ldap_timeout
decl_stmt|;
name|LDAPMessage
modifier|*
name|ldap_res
decl_stmt|;
comment|/* ldapmap_lookup options */
name|char
name|ldap_attrsep
decl_stmt|;
comment|/* Linked list of maps sharing the same LDAP binding */
name|void
modifier|*
name|ldap_next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sm_ldap_struct
name|SM_LDAP_STRUCT
typedef|;
end_typedef

begin_struct
struct|struct
name|sm_ldap_recurse_entry
block|{
name|char
modifier|*
name|lr_search
decl_stmt|;
name|int
name|lr_type
decl_stmt|;
name|LDAPURLDesc
modifier|*
name|lr_ludp
decl_stmt|;
name|char
modifier|*
modifier|*
name|lr_attrs
decl_stmt|;
name|bool
name|lr_done
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sm_ldap_recurse_list
block|{
name|int
name|lrl_size
decl_stmt|;
name|int
name|lrl_cnt
decl_stmt|;
name|struct
name|sm_ldap_recurse_entry
modifier|*
modifier|*
name|lrl_data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sm_ldap_recurse_entry
name|SM_LDAP_RECURSE_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sm_ldap_recurse_list
name|SM_LDAP_RECURSE_LIST
typedef|;
end_typedef

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sm_ldap_clear
name|__P
argument_list|(
operator|(
name|SM_LDAP_STRUCT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|sm_ldap_start
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|SM_LDAP_STRUCT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_ldap_search
name|__P
argument_list|(
operator|(
name|SM_LDAP_STRUCT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_ldap_search_m
name|__P
argument_list|(
operator|(
name|SM_LDAP_STRUCT
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_ldap_results
name|__P
argument_list|(
operator|(
name|SM_LDAP_STRUCT
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|SM_RPOOL_T
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|SM_LDAP_RECURSE_LIST
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_ldap_setopts
name|__P
argument_list|(
operator|(
name|LDAP
operator|*
operator|,
name|SM_LDAP_STRUCT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_ldap_geterrno
name|__P
argument_list|(
operator|(
name|LDAP
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_ldap_close
name|__P
argument_list|(
operator|(
name|SM_LDAP_STRUCT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Portability defines */
end_comment

begin_if
if|#
directive|if
operator|!
name|SM_CONF_LDAP_MEMFREE
end_if

begin_define
define|#
directive|define
name|ldap_memfree
parameter_list|(
name|x
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_LDAP_MEMFREE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDAPMAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_LDAP_H */
end_comment

end_unit

