begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* oid.h - object identifier stuff */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/oid.h,v 7.4 91/02/22 09:26:01 mrose Interim $  *  *  * $Log:	oid.h,v $  * Revision 7.4  91/02/22  09:26:01  mrose  * Interim 6.8  *   * Revision 7.3  90/11/20  15:30:55  mrose  * cjr  *   * Revision 7.2  90/10/17  11:46:34  mrose  * sync  *   * Revision 7.1  90/07/09  14:38:37  mrose  * sync  *   * Revision 7.0  89/11/23  21:56:41  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUOID
end_ifndef

begin_define
define|#
directive|define
name|QUIPUOID
end_define

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_comment
comment|/* Definitions of OID's the DSA needs to know */
end_comment

begin_comment
comment|/* X500 defined attributes */
end_comment

begin_define
define|#
directive|define
name|OBJECTCLASS_OID
value|"2.5.4.0"
end_define

begin_define
define|#
directive|define
name|ALIAS_OID
value|"2.5.4.1"
end_define

begin_define
define|#
directive|define
name|CN_OID
value|"2.5.4.3"
end_define

begin_define
define|#
directive|define
name|DSAADDRESS_OID
value|"2.5.4.29"
end_define

begin_define
define|#
directive|define
name|APPLCTX_OID
value|"2.5.4.30"
end_define

begin_define
define|#
directive|define
name|PASSWORD_OID
value|"2.5.4.35"
end_define

begin_define
define|#
directive|define
name|CERTIFICATE_OID
value|"2.5.4.36"
end_define

begin_comment
comment|/* QUIPU defined attributes */
end_comment

begin_define
define|#
directive|define
name|SCHEMA_OID
value|"0.9.2342.19200300.99.1.1"
end_define

begin_define
define|#
directive|define
name|ACL_OID
value|"0.9.2342.19200300.99.1.2"
end_define

begin_define
define|#
directive|define
name|EDBINFO_OID
value|"0.9.2342.19200300.99.1.3"
end_define

begin_define
define|#
directive|define
name|MASTERDSA_OID
value|"0.9.2342.19200300.99.1.4"
end_define

begin_define
define|#
directive|define
name|SLAVEDSA_OID
value|"0.9.2342.19200300.99.1.5"
end_define

begin_define
define|#
directive|define
name|CONTROL_OID
value|"0.9.2342.19200300.99.1.15"
end_define

begin_define
define|#
directive|define
name|VERSION_OID
value|"0.9.2342.19200300.99.1.16"
end_define

begin_define
define|#
directive|define
name|PROTECTED_OID
value|"0.9.2342.19200300.99.1.17"
end_define

begin_define
define|#
directive|define
name|INHERIT_OID
value|"0.9.2342.19200300.99.1.21"
end_define

begin_define
define|#
directive|define
name|RELAYDSA_OID
value|"0.9.2342.19200300.99.1.23"
end_define

begin_define
define|#
directive|define
name|SUBORD_OID
value|"0.9.2342.19200300.99.1.25"
end_define

begin_define
define|#
directive|define
name|XREF_OID
value|"0.9.2342.19200300.99.1.26"
end_define

begin_define
define|#
directive|define
name|NSSR_OID
value|"0.9.2342.19200300.99.1.27"
end_define

begin_define
define|#
directive|define
name|LISTEN_OID
value|"0.9.2342.19200300.99.1.28"
end_define

begin_comment
comment|/* THORN defined attribute */
end_comment

begin_define
define|#
directive|define
name|MANAGER_OID
value|"0.9.2342.19200300.100.1.10"
end_define

begin_define
define|#
directive|define
name|LAST_MOD_OID
value|"0.9.2342.19200300.100.1.23"
end_define

begin_define
define|#
directive|define
name|MOD_BY_OID
value|"0.9.2342.19200300.100.1.24"
end_define

begin_comment
comment|/* NON leaf object class */
end_comment

begin_define
define|#
directive|define
name|QUIPU_DSA
value|"0.9.2342.19200300.99.3.1"
end_define

begin_define
define|#
directive|define
name|NONLEAFOBJECT
value|"0.9.2342.19200300.99.3.6"
end_define

begin_define
define|#
directive|define
name|EXTERNOBJECT
value|"0.9.2342.19200300.99.3.9"
end_define

begin_comment
comment|/* alias objectclass */
end_comment

begin_define
define|#
directive|define
name|ALIAS_OC
value|"2.5.6.1"
end_define

begin_define
define|#
directive|define
name|TOP_OC
value|"2.5.6.0"
end_define

begin_comment
comment|/* X500 defined protocol oids */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_BUILTIN_OIDS
end_ifdef

begin_define
define|#
directive|define
name|DIR_ACCESS_AC
value|str2oid("2.5.3.1")
end_define

begin_define
define|#
directive|define
name|DIR_SYSTEM_AC
value|str2oid("2.5.3.2")
end_define

begin_define
define|#
directive|define
name|DIR_QUIPU_AC
value|str2oid("0.9.2342.19200300.99.4")
end_define

begin_define
define|#
directive|define
name|DIR_ACCESS_AS
value|str2oid("2.5.9.1")
end_define

begin_define
define|#
directive|define
name|DIR_SYSTEM_AS
value|str2oid("2.5.9.2")
end_define

begin_define
define|#
directive|define
name|DIR_QUIPU_AS
value|str2oid("0.9.2342.19200300.99.5")
end_define

begin_define
define|#
directive|define
name|DIR_ACSE
value|str2oid("2.2.1.0.1")
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* use isobjects */
end_comment

begin_define
define|#
directive|define
name|DIR_ACCESS_AC
value|ode2oid("directory directoryAccessAC")
end_define

begin_define
define|#
directive|define
name|DIR_SYSTEM_AC
value|ode2oid("directory directorySystemAC")
end_define

begin_define
define|#
directive|define
name|DIR_QUIPU_AC
value|str2oid("0.9.2342.19200300.99.4")
end_define

begin_define
define|#
directive|define
name|DIR_ACCESS_AS
value|ode2oid("directory directoryAccessAS")
end_define

begin_define
define|#
directive|define
name|DIR_SYSTEM_AS
value|ode2oid("directory directorySystemAS")
end_define

begin_define
define|#
directive|define
name|DIR_QUIPU_AS
value|str2oid("0.9.2342.19200300.99.5")
end_define

begin_define
define|#
directive|define
name|DIR_ACSE
value|ode2oid("acse pci version 1")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Wrong file for the following, but they are connected to the above so... */
end_comment

begin_define
define|#
directive|define
name|DIR_ACCESS_PC_ID
value|1
end_define

begin_define
define|#
directive|define
name|DIR_SYSTEM_PC_ID
value|1
end_define

begin_define
define|#
directive|define
name|DIR_QUIPU_PC_ID
value|1
end_define

begin_define
define|#
directive|define
name|DIR_ACSE_PC_ID
value|3
end_define

begin_comment
comment|/* oid table lookup definitions */
end_comment

begin_define
define|#
directive|define
name|SEPERATOR
value|':'
end_define

begin_define
define|#
directive|define
name|DOT
value|'.'
end_define

begin_define
define|#
directive|define
name|COMMA
value|','
end_define

begin_define
define|#
directive|define
name|COMMENT
value|'#'
end_define

begin_define
define|#
directive|define
name|BUFSIZE
value|40
end_define

begin_define
define|#
directive|define
name|TABLESIZE
value|300
end_define

begin_define
define|#
directive|define
name|OIDPART
value|1
end_define

begin_define
define|#
directive|define
name|OIDFULL
value|2
end_define

begin_define
define|#
directive|define
name|OIDNUM
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|ot_name
decl_stmt|;
name|char
modifier|*
name|ot_stroid
decl_stmt|;
name|OID
name|ot_oid
decl_stmt|;
name|OID
name|ot_aliasoid
decl_stmt|;
block|}
name|oid_table
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLTABLE
value|((oid_table * )0)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|oid_table
name|oa_ot
decl_stmt|;
name|short
name|oa_syntax
decl_stmt|;
block|}
name|oid_table_attr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLTABLE_ATTR
value|((oid_table_attr *)0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|seq_tab
block|{
name|oid_table_attr
modifier|*
name|ts_oa
decl_stmt|;
name|struct
name|seq_tab
modifier|*
name|ts_next
decl_stmt|;
block|}
typedef|*
name|table_seq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLTABLE_SEQ
value|((table_seq)0)
end_define

begin_struct
struct|struct
name|oc_seq
block|{
name|struct
name|_objclass
modifier|*
name|os_oc
decl_stmt|;
name|struct
name|oc_seq
modifier|*
name|os_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLOCSEQ
value|((struct oc_seq*) 0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_objclass
block|{
name|oid_table
name|oc_ot
decl_stmt|;
name|struct
name|oc_seq
modifier|*
name|oc_hierachy
decl_stmt|;
name|table_seq
name|oc_must
decl_stmt|;
name|table_seq
name|oc_may
decl_stmt|;
block|}
name|objectclass
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLOBJECTCLASS
value|((objectclass * )0)
end_define

begin_define
define|#
directive|define
name|objclass_cmp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|( x == y ? 0 : ( x> y ? -1 : 1 ))
end_define

begin_function_decl
name|oid_table_attr
modifier|*
name|oid2attr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|oid_table_attr
modifier|*
name|name2attr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|attr2name
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|attr2name_aux
parameter_list|(
name|x
parameter_list|)
value|((x) ? (x)->oa_ot.ot_name : NULLCP)
end_define

begin_function_decl
name|objectclass
modifier|*
name|oid2oc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|objectclass
modifier|*
name|name2oc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|oc2name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|oid2name
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find oid wherever it is hiding !!! */
end_comment

begin_function_decl
name|OID
name|name2oid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|SkipSpace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StripSpace
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

