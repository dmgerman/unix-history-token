begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/include/RCS/kadm.h,v $  * $Author: kfall $  * $Header: /usr/src/kerberosIV/include/RCS/kadm.h,v 4.3 90/06/25 20:49:12 kfall Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Definitions for Kerberos administration server& client  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KADM_DEFS
end_ifndef

begin_define
define|#
directive|define
name|KADM_DEFS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATHENA
end_ifdef

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * kadm.h  * Header file for the fourth attempt at an admin server  * Doug Church, December 28, 1989, MIT Project Athena  */
end_comment

begin_comment
comment|/* for those broken Unixes without this defined... should be in sys/param.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ATHENA
end_ifdef

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The global structures for the client and server */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|sockaddr_in
name|admin_addr
decl_stmt|;
name|struct
name|sockaddr_in
name|my_addr
decl_stmt|;
name|int
name|my_addr_len
decl_stmt|;
name|int
name|admin_fd
decl_stmt|;
comment|/* file descriptor for link to admin server */
name|char
name|sname
index|[
name|ANAME_SZ
index|]
decl_stmt|;
comment|/* the service name */
name|char
name|sinst
index|[
name|INST_SZ
index|]
decl_stmt|;
comment|/* the services instance */
name|char
name|krbrlm
index|[
name|REALM_SZ
index|]
decl_stmt|;
block|}
name|Kadm_Client
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* status of the server, i.e the parameters */
name|int
name|inter
decl_stmt|;
comment|/* Space for command line flags */
name|char
modifier|*
name|sysfile
decl_stmt|;
comment|/* filename of server */
block|}
name|admin_params
typedef|;
end_typedef

begin_comment
comment|/* Well... it's the admin's parameters */
end_comment

begin_comment
comment|/* Largest password length to be supported */
end_comment

begin_define
define|#
directive|define
name|MAX_KPW_LEN
value|128
end_define

begin_comment
comment|/* Largest packet the admin server will ever allow itself to return */
end_comment

begin_define
define|#
directive|define
name|KADM_RET_MAX
value|2048
end_define

begin_comment
comment|/* That's right, versions are 8 byte strings */
end_comment

begin_define
define|#
directive|define
name|KADM_VERSTR
value|"KADM0.0A"
end_define

begin_define
define|#
directive|define
name|KADM_ULOSE
value|"KYOULOSE"
end_define

begin_comment
comment|/* sent back when server can't 					   decrypt client's msg */
end_comment

begin_define
define|#
directive|define
name|KADM_VERSIZE
value|strlen(KADM_VERSTR)
end_define

begin_comment
comment|/* the lookups for the server instances */
end_comment

begin_define
define|#
directive|define
name|PWSERV_NAME
value|"changepw"
end_define

begin_define
define|#
directive|define
name|KADM_SNAME
value|"kerberos_master"
end_define

begin_define
define|#
directive|define
name|KADM_SINST
value|"kerberos"
end_define

begin_comment
comment|/* Attributes fields constants and macros */
end_comment

begin_define
define|#
directive|define
name|ALLOC
value|2
end_define

begin_define
define|#
directive|define
name|RESERVED
value|3
end_define

begin_define
define|#
directive|define
name|DEALLOC
value|4
end_define

begin_define
define|#
directive|define
name|DEACTIVATED
value|5
end_define

begin_define
define|#
directive|define
name|ACTIVE
value|6
end_define

begin_comment
comment|/* Kadm_vals structure for passing db fields into the server routines */
end_comment

begin_define
define|#
directive|define
name|FLDSZ
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|fields
index|[
name|FLDSZ
index|]
decl_stmt|;
comment|/* The active fields in this struct */
name|char
name|name
index|[
name|ANAME_SZ
index|]
decl_stmt|;
name|char
name|instance
index|[
name|INST_SZ
index|]
decl_stmt|;
name|unsigned
name|long
name|key_low
decl_stmt|;
name|unsigned
name|long
name|key_high
decl_stmt|;
name|unsigned
name|long
name|exp_date
decl_stmt|;
name|unsigned
name|short
name|attributes
decl_stmt|;
name|unsigned
name|char
name|max_life
decl_stmt|;
block|}
name|Kadm_vals
typedef|;
end_typedef

begin_comment
comment|/* The basic values structure in Kadm */
end_comment

begin_comment
comment|/* Kadm_vals structure for passing db fields into the server routines */
end_comment

begin_define
define|#
directive|define
name|FLDSZ
value|4
end_define

begin_comment
comment|/* Need to define fields types here */
end_comment

begin_define
define|#
directive|define
name|KADM_NAME
value|31
end_define

begin_define
define|#
directive|define
name|KADM_INST
value|30
end_define

begin_define
define|#
directive|define
name|KADM_EXPDATE
value|29
end_define

begin_define
define|#
directive|define
name|KADM_ATTR
value|28
end_define

begin_define
define|#
directive|define
name|KADM_MAXLIFE
value|27
end_define

begin_define
define|#
directive|define
name|KADM_DESKEY
value|26
end_define

begin_comment
comment|/* To set a field entry f in a fields structure d */
end_comment

begin_define
define|#
directive|define
name|SET_FIELD
parameter_list|(
name|f
parameter_list|,
name|d
parameter_list|)
value|(d[3-(f/8)]|=(1<<(f%8)))
end_define

begin_comment
comment|/* To set a field entry f in a fields structure d */
end_comment

begin_define
define|#
directive|define
name|CLEAR_FIELD
parameter_list|(
name|f
parameter_list|,
name|d
parameter_list|)
value|(d[3-(f/8)]&=(~(1<<(f%8))))
end_define

begin_comment
comment|/* Is field f in fields structure d */
end_comment

begin_define
define|#
directive|define
name|IS_FIELD
parameter_list|(
name|f
parameter_list|,
name|d
parameter_list|)
value|(d[3-(f/8)]&(1<<(f%8)))
end_define

begin_comment
comment|/* Various return codes */
end_comment

begin_define
define|#
directive|define
name|KADM_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|WILDCARD_STR
value|"*"
end_define

begin_enum
enum|enum
name|acl_types
block|{
name|ADDACL
block|,
name|GETACL
block|,
name|MODACL
block|}
enum|;
end_enum

begin_comment
comment|/* Various opcodes for the admin server's functions */
end_comment

begin_define
define|#
directive|define
name|CHANGE_PW
value|2
end_define

begin_define
define|#
directive|define
name|ADD_ENT
value|3
end_define

begin_define
define|#
directive|define
name|MOD_ENT
value|4
end_define

begin_define
define|#
directive|define
name|GET_ENT
value|5
end_define

begin_function_decl
specifier|extern
name|long
name|kdb_get_master_key
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX should be in krb_db.h */
end_comment

begin_function_decl
specifier|extern
name|long
name|kdb_verify_master_key
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX ditto */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|krb_mk_priv
argument_list|()
decl_stmt|,
name|krb_rd_priv
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX should be in krb.h */
end_comment

begin_function_decl
specifier|extern
name|void
name|krb_set_tkt_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX ditto */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|quad_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX should be in des.h */
end_comment

begin_comment
comment|/* XXX This doesn't belong here!!! */
end_comment

begin_decl_stmt
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_typedef
typedef|typedef
name|void
name|sigtype
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|sigtype
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|KADM_DEFS
end_endif

end_unit

