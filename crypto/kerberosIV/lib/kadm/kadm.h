begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: kadm.h,v 1.17 1998/10/23 14:25:55 joda Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Definitions for Kerberos administration server& client  */
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

begin_comment
comment|/*  * kadm.h  * Header file for the fourth attempt at an admin server  * Doug Church, December 28, 1989, MIT Project Athena  */
end_comment

begin_include
include|#
directive|include
file|<krb_db.h>
end_include

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
comment|/* Minimum allowed password length */
end_comment

begin_define
define|#
directive|define
name|MIN_KPW_LEN
value|6
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
name|KADM_PORT
value|751
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

begin_comment
comment|/* XXX enable new extended kadm fields */
end_comment

begin_define
define|#
directive|define
name|EXTENDED_KADM
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
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
name|u_int32_t
name|key_low
decl_stmt|;
name|u_int32_t
name|key_high
decl_stmt|;
name|u_int32_t
name|exp_date
decl_stmt|;
name|u_int16_t
name|attributes
decl_stmt|;
name|u_int8_t
name|max_life
decl_stmt|;
ifdef|#
directive|ifdef
name|EXTENDED_KADM
name|u_int32_t
name|mod_date
decl_stmt|;
name|char
name|mod_name
index|[
name|ANAME_SZ
index|]
decl_stmt|;
name|char
name|mod_instance
index|[
name|INST_SZ
index|]
decl_stmt|;
name|u_int8_t
name|key_version
decl_stmt|;
endif|#
directive|endif
block|}
name|Kadm_vals
typedef|;
end_typedef

begin_comment
comment|/* The basic values structure in Kadm */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|EXTENDED_KADM
end_ifdef

begin_define
define|#
directive|define
name|KADM_MODDATE
value|25
end_define

begin_define
define|#
directive|define
name|KADM_MODNAME
value|24
end_define

begin_define
define|#
directive|define
name|KADM_MODINST
value|23
end_define

begin_define
define|#
directive|define
name|KADM_KVNO
value|22
end_define

begin_endif
endif|#
directive|endif
end_endif

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
block|,
name|STABACL
block|,
comment|/* not used */
name|DELACL
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

begin_define
define|#
directive|define
name|CHECK_PW
value|6
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|CHG_STAB
value|7
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|DEL_ENT
value|8
end_define

begin_decl_stmt
name|void
name|prin_vals
name|__P
argument_list|(
operator|(
name|Kadm_vals
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stv_long
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_int32_t
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vts_long
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
name|u_char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vts_string
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stv_string
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stream_to_vals
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|Kadm_vals
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vals_to_stream
name|__P
argument_list|(
operator|(
name|Kadm_vals
operator|*
operator|,
name|u_char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kadm_init_link
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kadm_change_pw
name|__P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kadm_change_pw_plain
name|__P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|char
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
name|int
name|kadm_change_pw2
name|__P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|char
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
name|int
name|kadm_mod
name|__P
argument_list|(
operator|(
name|Kadm_vals
operator|*
operator|,
name|Kadm_vals
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kadm_get
name|__P
argument_list|(
operator|(
name|Kadm_vals
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kadm_add
name|__P
argument_list|(
operator|(
name|Kadm_vals
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kadm_del
name|__P
argument_list|(
operator|(
name|Kadm_vals
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kadm_vals_to_prin
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|Principal
operator|*
operator|,
name|Kadm_vals
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kadm_prin_to_vals
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|Kadm_vals
operator|*
operator|,
name|Principal
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kadm_check_pw
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KADM_DEFS */
end_comment

end_unit

