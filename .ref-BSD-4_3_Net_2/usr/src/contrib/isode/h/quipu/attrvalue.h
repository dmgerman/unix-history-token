begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* attrvalue.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/attrvalue.h,v 7.3 91/02/22 09:25:25 mrose Interim $  *  *  *  * $Log:	attrvalue.h,v $  * Revision 7.3  91/02/22  09:25:25  mrose  * Interim 6.8  *   * Revision 7.2  90/11/20  15:30:18  mrose  * cjr  *   * Revision 7.1  90/10/17  11:46:14  mrose  * sync  *   * Revision 7.0  89/11/23  21:56:22  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRVALUE
end_ifndef

begin_define
define|#
directive|define
name|ATTRVALUE
end_define

begin_include
include|#
directive|include
file|"quipu/name.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|avseqcomp
block|{
comment|/* attribute may have multiple values   */
comment|/* respresents SET OF AttributeValue    */
name|attrVal
name|avseq_av
decl_stmt|;
name|struct
name|avseqcomp
modifier|*
name|avseq_next
decl_stmt|;
block|}
name|avseqcomp
operator|,
typedef|*
name|AV_Sequence
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLAV
value|((AV_Sequence) 0)
end_define

begin_define
define|#
directive|define
name|avs_comp_alloc
parameter_list|()
value|(AV_Sequence) smalloc(sizeof(avseqcomp))
end_define

begin_define
define|#
directive|define
name|avs_comp_print
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|AttrV_print (x,&(y)->avseq_av,z)
end_define

begin_define
define|#
directive|define
name|avs_cmp_comp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|AttrV_cmp (&x->avseq_av ,&y->avseq_av)
end_define

begin_function_decl
name|AV_Sequence
name|avs_comp_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|AV_Sequence
name|avs_comp_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|AV_Sequence
name|avs_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|AV_Sequence
name|avs_merge
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|AV_Sequence
name|str2avs
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
name|attrcomp
block|{
comment|/* A sequence of attributes             */
comment|/* represents Attribute                 */
comment|/* and SET OF Attribute                 */
name|attrType
name|attr_type
decl_stmt|;
name|AV_Sequence
name|attr_value
decl_stmt|;
name|struct
name|attrcomp
modifier|*
name|attr_link
decl_stmt|;
comment|/* ACL is NOT for use by DUA            */
comment|/* this must be done by use of ACL      */
comment|/* attribute                            */
name|struct
name|acl_info
modifier|*
name|attr_acl
decl_stmt|;
block|}
name|attrcomp
operator|,
typedef|*
name|Attr_Sequence
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLATTR
value|((Attr_Sequence) 0)
end_define

begin_define
define|#
directive|define
name|as_comp_alloc
parameter_list|()
value|(Attr_Sequence) smalloc(sizeof(attrcomp))
end_define

begin_define
define|#
directive|define
name|as_comp_cmp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((oid_cmp (&x->attr_type ,&y->attr_type) == OK)&& (avs_cmp (x->attr_value ,y->attr_value) == OK)) ? OK : NOTOK)
end_define

begin_function_decl
name|Attr_Sequence
name|as_comp_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Attr_Sequence
name|as_comp_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Attr_Sequence
name|as_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Attr_Sequence
name|as_find_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Attr_Sequence
name|as_merge
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Attr_Sequence
name|str2as
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ACL is defined here as it is         */
end_comment

begin_comment
comment|/* referenced.   it is only used by     */
end_comment

begin_comment
comment|/* DSA                                  */
end_comment

begin_comment
comment|/* represents ACLInfo defined by INCA   */
end_comment

begin_struct
struct|struct
name|acl_info
block|{
name|int
name|acl_categories
decl_stmt|;
define|#
directive|define
name|ACL_NONE
value|0
define|#
directive|define
name|ACL_DETECT
value|1
define|#
directive|define
name|ACL_COMPARE
value|2
define|#
directive|define
name|ACL_READ
value|3
define|#
directive|define
name|ACL_ADD
value|4
define|#
directive|define
name|ACL_WRITE
value|5
name|int
name|acl_selector_type
decl_stmt|;
define|#
directive|define
name|ACL_ENTRY
value|1
define|#
directive|define
name|ACL_OTHER
value|2
define|#
directive|define
name|ACL_PREFIX
value|3
define|#
directive|define
name|ACL_GROUP
value|4
name|struct
name|dn_seq
modifier|*
name|acl_name
decl_stmt|;
comment|/* prefix and group only         */
name|struct
name|acl_info
modifier|*
name|acl_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLACL_INFO
value|(struct acl_info *) NULL
end_define

begin_define
define|#
directive|define
name|acl_info_alloc
parameter_list|()
value|(struct acl_info *) smalloc (sizeof  (struct acl_info))
end_define

begin_define
define|#
directive|define
name|acl_info_fill
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|w -> acl_categories = x ;  \ 				  w -> acl_selector_type = y; \ 				  w -> acl_name = z;
end_define

begin_function_decl
name|struct
name|acl_info
modifier|*
name|acl_info_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|acl_info
modifier|*
name|acl_info_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|acl_info
modifier|*
name|acl_default
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|acl_info
modifier|*
name|acl_dflt
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|mailbox
block|{
name|char
modifier|*
name|mtype
decl_stmt|;
name|char
modifier|*
name|mbox
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fax
block|{
name|char
modifier|*
name|number
decl_stmt|;
name|PE
name|bits
decl_stmt|;
name|char
modifier|*
name|fax_bits
decl_stmt|;
name|int
name|fax_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|postaddr
block|{
name|int
name|addrtype
decl_stmt|;
comment|/* 1 == T61, 2 == Printstr */
name|char
modifier|*
name|addrcomp
decl_stmt|;
name|struct
name|postaddr
modifier|*
name|pa_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|telex
block|{
name|char
modifier|*
name|telexnumber
decl_stmt|;
name|char
modifier|*
name|countrycode
decl_stmt|;
name|char
modifier|*
name|answerback
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|teletex
block|{
name|char
modifier|*
name|terminal
decl_stmt|;
name|char
modifier|*
name|graphic
decl_stmt|;
name|char
modifier|*
name|control
decl_stmt|;
name|char
modifier|*
name|page
decl_stmt|;
name|char
modifier|*
name|misc
decl_stmt|;
name|char
modifier|*
name|t_private
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pref_deliv
block|{
name|int
name|deliv
decl_stmt|;
name|struct
name|pref_deliv
modifier|*
name|pd_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Guide
block|{
name|OID
name|objectClass
decl_stmt|;
name|struct
name|Criteria
modifier|*
name|criteria
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Criteria
block|{
name|int
name|offset
decl_stmt|;
define|#
directive|define
name|Criteria_type
value|1
define|#
directive|define
name|Criteria_and
value|2
define|#
directive|define
name|Criteria_or
value|3
define|#
directive|define
name|Criteria_not
value|4
union|union
block|{
name|struct
name|CriteriaItem
modifier|*
name|type
decl_stmt|;
struct|struct
name|and_or_set
block|{
name|struct
name|Criteria
modifier|*
name|and_or_comp
decl_stmt|;
name|struct
name|and_or_set
modifier|*
name|and_or_next
decl_stmt|;
block|}
modifier|*
name|and_or
struct|;
name|struct
name|Criteria
modifier|*
name|not
decl_stmt|;
block|}
name|un
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|CriteriaItem
block|{
name|int
name|offset
decl_stmt|;
define|#
directive|define
name|choice_equality
value|1
define|#
directive|define
name|choice_substrings
value|2
define|#
directive|define
name|choice_greaterOrEqual
value|3
define|#
directive|define
name|choice_lessOrEqual
value|4
define|#
directive|define
name|choice_approximateMatch
value|5
name|AttributeType
name|attrib
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Upper bounds */
end_comment

begin_define
define|#
directive|define
name|UB_POSTAL_LINE
value|6
end_define

begin_define
define|#
directive|define
name|UB_POSTAL_STRING
value|30
end_define

begin_define
define|#
directive|define
name|UB_TELETEX_TERMINAL_ID
value|1024
end_define

begin_define
define|#
directive|define
name|UB_TELEPHONE_NUMBER
value|32
end_define

begin_define
define|#
directive|define
name|UB_TELEX_NUMBER
value|14
end_define

begin_define
define|#
directive|define
name|UB_ANSWERBACK
value|8
end_define

begin_define
define|#
directive|define
name|UB_COUNTRY_CODE
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|_InheritAttr
block|{
name|Attr_Sequence
name|i_default
decl_stmt|;
name|Attr_Sequence
name|i_always
decl_stmt|;
name|OID
name|i_oid
decl_stmt|;
block|}
typedef|*
name|InheritAttr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLINHERIT
value|((InheritAttr)NULL)
end_define

begin_struct
struct|struct
name|CIList
block|{
name|char
modifier|*
name|l_str
decl_stmt|;
name|struct
name|CIList
modifier|*
name|l_next
decl_stmt|;
name|int
name|l_type
decl_stmt|;
comment|/* 1 == T61, 2 == Printstr */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLCILIST
value|(struct CIList *)NULL
end_define

begin_struct
struct|struct
name|documentStore
block|{
name|int
name|ds_method
decl_stmt|;
define|#
directive|define
name|DS_UNK
value|(-1)
define|#
directive|define
name|DS_FTP
value|0
define|#
directive|define
name|DS_FTAM
value|1
name|char
modifier|*
name|ds_host
decl_stmt|;
name|char
modifier|*
name|ds_dir
decl_stmt|;
name|char
modifier|*
name|ds_file
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

