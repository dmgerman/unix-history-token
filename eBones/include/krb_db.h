begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * spm		Project Athena  8/85  *  * This file defines data structures for the kerberos  * authentication/authorization database.  *  * They MUST correspond to those defined in *.rel  *  *	from: krb_db.h,v 4.9 89/01/24 17:55:39 jon Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_DB_DEFS
end_ifndef

begin_define
define|#
directive|define
name|KRB_DB_DEFS
end_define

begin_define
define|#
directive|define
name|KERB_M_NAME
value|"K"
end_define

begin_comment
comment|/* Kerberos */
end_comment

begin_define
define|#
directive|define
name|KERB_M_INST
value|"M"
end_define

begin_comment
comment|/* Master */
end_comment

begin_define
define|#
directive|define
name|KERB_DEFAULT_NAME
value|"default"
end_define

begin_define
define|#
directive|define
name|KERB_DEFAULT_INST
value|""
end_define

begin_define
define|#
directive|define
name|DBM_FILE
value|"/etc/kerberosIV/principal"
end_define

begin_comment
comment|/* this also defines the number of queue headers */
end_comment

begin_define
define|#
directive|define
name|KERB_DB_HASH_MODULO
value|64
end_define

begin_comment
comment|/* Arguments to kerb_dbl_lock() */
end_comment

begin_define
define|#
directive|define
name|KERB_DBL_EXCLUSIVE
value|1
end_define

begin_define
define|#
directive|define
name|KERB_DBL_SHARED
value|0
end_define

begin_comment
comment|/* arguments to kerb_db_set_lockmode() */
end_comment

begin_define
define|#
directive|define
name|KERB_DBL_BLOCKING
value|0
end_define

begin_define
define|#
directive|define
name|KERB_DBL_NONBLOCKING
value|1
end_define

begin_comment
comment|/* Principal defines the structure of a principal's name */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
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
name|char
name|exp_date_txt
index|[
name|DATE_SZ
index|]
decl_stmt|;
name|unsigned
name|long
name|mod_date
decl_stmt|;
name|char
name|mod_date_txt
index|[
name|DATE_SZ
index|]
decl_stmt|;
name|unsigned
name|short
name|attributes
decl_stmt|;
name|unsigned
name|char
name|max_life
decl_stmt|;
name|unsigned
name|char
name|kdc_key_ver
decl_stmt|;
name|unsigned
name|char
name|key_version
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
name|char
modifier|*
name|old
decl_stmt|;
comment|/* cast to (Principal *); not in db, 				 * ptr to old vals */
block|}
name|Principal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|cpu
decl_stmt|;
name|long
name|elapsed
decl_stmt|;
name|long
name|dio
decl_stmt|;
name|long
name|pfault
decl_stmt|;
name|long
name|t_stamp
decl_stmt|;
name|long
name|n_retrieve
decl_stmt|;
name|long
name|n_replace
decl_stmt|;
name|long
name|n_append
decl_stmt|;
name|long
name|n_get_stat
decl_stmt|;
name|long
name|n_put_stat
decl_stmt|;
block|}
name|DB_stat
typedef|;
end_typedef

begin_comment
comment|/* Dba defines the structure of a database administrator */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
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
name|short
name|attributes
decl_stmt|;
name|unsigned
name|long
name|exp_date
decl_stmt|;
name|char
name|exp_date_txt
index|[
name|DATE_SZ
index|]
decl_stmt|;
name|char
modifier|*
name|old
decl_stmt|;
comment|/* 			 * cast to (Dba *); not in db, ptr to 			 * old vals 			 */
block|}
name|Dba
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|kerb_get_principal
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|inst
parameter_list|,
name|Principal
modifier|*
name|principal
parameter_list|,
name|unsigned
name|int
name|max
parameter_list|,
name|int
modifier|*
name|more
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kerb_put_principal
parameter_list|(
name|Principal
modifier|*
name|principal
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kerb_db_get_stat
parameter_list|(
name|DB_stat
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kerb_db_put_stat
parameter_list|(
name|DB_stat
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kerb_get_dba
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|inst
parameter_list|,
name|Dba
modifier|*
name|dba
parameter_list|,
name|unsigned
name|int
name|max
parameter_list|,
name|int
modifier|*
name|more
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kerb_db_get_dba
parameter_list|(
name|char
modifier|*
name|dba_name
parameter_list|,
name|char
modifier|*
name|dba_inst
parameter_list|,
name|Dba
modifier|*
name|dba
parameter_list|,
name|unsigned
name|int
name|max
parameter_list|,
name|int
modifier|*
name|more
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|krb_print_principal
parameter_list|(
name|Principal
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kerb_db_get_principal
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|inst
parameter_list|,
name|Principal
modifier|*
name|principal
parameter_list|,
name|unsigned
name|int
name|max
parameter_list|,
name|int
modifier|*
name|more
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kerb_db_put_principal
parameter_list|(
name|Principal
modifier|*
name|principal
parameter_list|,
name|unsigned
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kerb_db_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kerb_db_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KRB_DB_DEFS */
end_comment

end_unit

