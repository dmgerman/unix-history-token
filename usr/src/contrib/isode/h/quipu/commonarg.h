begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* commonarg.h - directory operation common arguments */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/commonarg.h,v 7.2 91/02/22 09:25:30 mrose Interim $  *  *  * $Log:	commonarg.h,v $  * Revision 7.2  91/02/22  09:25:30  mrose  * Interim 6.8  *   * Revision 7.1  90/11/20  15:30:32  mrose  * cjr  *   * Revision 7.0  89/11/23  21:56:25  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMMONARG
end_ifndef

begin_define
define|#
directive|define
name|COMMONARG
end_define

begin_include
include|#
directive|include
file|"quipu/attrvalue.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dsp.h"
end_include

begin_include
include|#
directive|include
file|"quipu/authen.h"
end_include

begin_define
define|#
directive|define
name|OP_READ
value|1
end_define

begin_define
define|#
directive|define
name|OP_COMPARE
value|2
end_define

begin_define
define|#
directive|define
name|OP_ABANDON
value|3
end_define

begin_define
define|#
directive|define
name|OP_LIST
value|4
end_define

begin_define
define|#
directive|define
name|OP_SEARCH
value|5
end_define

begin_define
define|#
directive|define
name|OP_ADDENTRY
value|6
end_define

begin_define
define|#
directive|define
name|OP_REMOVEENTRY
value|7
end_define

begin_define
define|#
directive|define
name|OP_MODIFYENTRY
value|8
end_define

begin_define
define|#
directive|define
name|OP_MODIFYRDN
value|9
end_define

begin_define
define|#
directive|define
name|OP_GETEDB
value|10
end_define

begin_struct
struct|struct
name|security_parms
block|{
name|struct
name|certificate_list
modifier|*
name|sp_path
decl_stmt|;
name|DN
name|sp_name
decl_stmt|;
name|char
modifier|*
name|sp_time
decl_stmt|;
name|struct
name|random_number
modifier|*
name|sp_random
decl_stmt|;
name|int
name|sp_target
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|extension
block|{
name|int
name|ext_id
decl_stmt|;
name|char
name|ext_critical
decl_stmt|;
name|PE
name|ext_item
decl_stmt|;
name|struct
name|extension
modifier|*
name|ext_next
decl_stmt|;
block|}
typedef|*
name|Extension
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLEXT
value|((Extension) 0)
end_define

begin_define
define|#
directive|define
name|ext_alloc
parameter_list|()
value|(Extension) smalloc(sizeof(struct extension))
end_define

begin_typedef
typedef|typedef
struct|struct
name|common_args
block|{
comment|/* Common arguments for operations      */
name|ServiceControl
name|ca_servicecontrol
decl_stmt|;
name|DN
name|ca_requestor
decl_stmt|;
name|struct
name|op_progress
name|ca_progress
decl_stmt|;
name|int
name|ca_aliased_rdns
decl_stmt|;
define|#
directive|define
name|CA_NO_ALIASDEREFERENCED
value|-1
name|struct
name|security_parms
modifier|*
name|ca_security
decl_stmt|;
name|struct
name|signature
modifier|*
name|ca_sig
decl_stmt|;
name|struct
name|extension
modifier|*
name|ca_extensions
decl_stmt|;
block|}
name|common_args
operator|,
name|CommonArgs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULL_COMMONARG
value|((struct common_args *) NULL)
end_define

begin_typedef
typedef|typedef
struct|struct
name|common_results
block|{
name|DN
name|cr_requestor
decl_stmt|;
comment|/* Secuity stuff to go here.  The       */
comment|/* is not relevant until this is added  */
name|char
name|cr_aliasdereferenced
decl_stmt|;
comment|/* set to TRUE or FALSE                 */
comment|/* essentially for pepsy, but may be used for real later */
name|struct
name|security_parms
modifier|*
name|cr_security
decl_stmt|;
name|struct
name|alg_id
modifier|*
name|cr_alg
decl_stmt|;
name|char
modifier|*
name|cr_tmp
decl_stmt|;
name|int
name|cr_len
decl_stmt|;
block|}
name|common_results
operator|,
name|CommonResults
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|entrystruct
block|{
comment|/* Represents EntryInformation           */
name|DN
name|ent_dn
decl_stmt|;
name|Attr_Sequence
name|ent_attr
decl_stmt|;
name|char
name|ent_iscopy
decl_stmt|;
define|#
directive|define
name|INFO_MASTER
value|0x001
define|#
directive|define
name|INFO_COPY
value|0x002
comment|/* This is the only info derivable by   */
comment|/* protocol                             */
comment|/* INCA also distingusihes local cached */
define|#
directive|define
name|INFO_CACHE
value|0x003
name|char
name|ent_pepsycopy
decl_stmt|;
name|time_t
name|ent_age
decl_stmt|;
comment|/* age of chaced info                   */
name|struct
name|entrystruct
modifier|*
name|ent_next
decl_stmt|;
block|}
name|entrystruct
operator|,
name|EntryInfo
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLENTRYINFO
value|((EntryInfo *) 0)
end_define

begin_define
define|#
directive|define
name|entryinfo_alloc
parameter_list|()
value|(EntryInfo *) smalloc(sizeof(EntryInfo))
end_define

begin_define
define|#
directive|define
name|entryinfo_cmp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((dn_cmp (x.ent_dn ,y.ent_dn) == OK)&& (as_cmp (x.ent_attr ,y.ent_attr) == OK)) ? OK : NOTOK)
end_define

begin_typedef
typedef|typedef
struct|struct
name|entryinfoselection
block|{
comment|/* Rerpesents EntryInformationSelection */
name|char
name|eis_allattributes
decl_stmt|;
comment|/* if set to TRUE, all attributes       */
comment|/* returned, if not as per next arg     */
name|Attr_Sequence
name|eis_select
decl_stmt|;
comment|/* Sequence of attributes used to show  */
comment|/* which TYPES are wanted               */
name|int
name|eis_infotypes
decl_stmt|;
define|#
directive|define
name|EIS_ATTRIBUTETYPESONLY
value|0
define|#
directive|define
name|EIS_ATTRIBUTESANDVALUES
value|1
block|}
name|entryinfoselection
operator|,
name|EntryInfoSelection
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LSR_NOLIMITPROBLEM
value|-1
end_define

begin_define
define|#
directive|define
name|LSR_TIMELIMITEXCEEDED
value|0
end_define

begin_define
define|#
directive|define
name|LSR_SIZELIMITEXCEEDED
value|1
end_define

begin_define
define|#
directive|define
name|LSR_ADMINSIZEEXCEEDED
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|part_outcome
block|{
name|int
name|poq_limitproblem
decl_stmt|;
name|ContinuationRef
name|poq_cref
decl_stmt|;
name|char
name|poq_no_ext
decl_stmt|;
block|}
name|POQ
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

