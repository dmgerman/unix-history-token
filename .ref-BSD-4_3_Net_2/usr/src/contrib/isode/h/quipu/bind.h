begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bind.h - bind parameters */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/bind.h,v 7.2 91/02/22 09:25:27 mrose Interim $  *  *  * $Log:	bind.h,v $  * Revision 7.2  91/02/22  09:25:27  mrose  * Interim 6.8  *   * Revision 7.1  90/11/20  15:30:24  mrose  * cjr  *   * Revision 7.0  89/11/23  21:56:24  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUBIND
end_ifndef

begin_define
define|#
directive|define
name|QUIPUBIND
end_define

begin_include
include|#
directive|include
file|"quipu/name.h"
end_include

begin_include
include|#
directive|include
file|"quipu/authen.h"
end_include

begin_comment
comment|/* THIS SECTION GIVES BIND PARAMETERS */
end_comment

begin_comment
comment|/* Directory Bind Argument */
end_comment

begin_struct
struct|struct
name|ds_bind_arg
block|{
name|int
name|dba_version
decl_stmt|;
comment|/* Treat INT as bitstring */
define|#
directive|define
name|DBA_VERSION_V1988
value|0
name|int
name|dba_auth_type
decl_stmt|;
define|#
directive|define
name|DBA_AUTH_NONE
value|0
define|#
directive|define
name|DBA_AUTH_SIMPLE
value|1
define|#
directive|define
name|DBA_AUTH_STRONG
value|2
define|#
directive|define
name|DBA_AUTH_EXTERNAL
value|3
define|#
directive|define
name|DBA_AUTH_PROTECTED
value|4
comment|/* special case of simple */
name|char
modifier|*
name|dba_time1
decl_stmt|;
comment|/* Timestamps for protected    */
name|char
modifier|*
name|dba_time2
decl_stmt|;
comment|/* simple authentication.      */
name|struct
name|random_number
name|dba_r1
decl_stmt|;
name|struct
name|random_number
name|dba_r2
decl_stmt|;
name|DN
name|dba_dn
decl_stmt|;
name|int
name|dba_passwd_len
decl_stmt|;
comment|/* len = 0 means no password    */
define|#
directive|define
name|DBA_MAX_PASSWD_LEN
value|512
name|char
name|dba_passwd
index|[
name|DBA_MAX_PASSWD_LEN
index|]
decl_stmt|;
name|struct
name|signature
modifier|*
name|dba_sig
decl_stmt|;
comment|/* signature for strong authen	*/
name|struct
name|certificate_list
modifier|*
name|dba_cpath
decl_stmt|;
comment|/* certification path		*/
name|char
modifier|*
name|dba_vtmp
decl_stmt|;
comment|/* pepsy */
name|int
name|dba_vlen
decl_stmt|;
comment|/* pepsy */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ds_bind_error
block|{
name|int
name|dbe_version
decl_stmt|;
name|int
name|dbe_type
decl_stmt|;
define|#
directive|define
name|DBE_TYPE_SERVICE
value|1
define|#
directive|define
name|DBE_TYPE_SECURITY
value|2
name|int
name|dbe_value
decl_stmt|;
comment|/* takes on values as define in */
comment|/* DSE_service or DSE_security  */
comment|/* according to dbe_type        */
name|char
modifier|*
name|dbe_vtmp
decl_stmt|;
comment|/* pepsy */
name|int
name|dbe_vlen
decl_stmt|;
comment|/* pepsy */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

