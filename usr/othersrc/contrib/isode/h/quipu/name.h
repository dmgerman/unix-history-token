begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* name.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/name.h,v 7.1 91/02/22 09:26:00 mrose Interim $  *  *  * $Log:	name.h,v $  * Revision 7.1  91/02/22  09:26:00  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:40  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUNAME
end_ifndef

begin_define
define|#
directive|define
name|QUIPUNAME
end_define

begin_include
include|#
directive|include
file|"quipu/attr.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|ava
block|{
comment|/* represents AttributeValueAssertion */
name|AttributeType
name|ava_type
decl_stmt|;
name|AttributeValue
name|ava_value
decl_stmt|;
block|}
name|ava
operator|,
name|AVA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rdncomp
block|{
comment|/* RDN is sequence of attribute value   */
comment|/* assertions                           */
comment|/* represents RelativeDistinguishedName */
name|attrType
name|rdn_at
decl_stmt|;
name|attrVal
name|rdn_av
decl_stmt|;
name|struct
name|rdncomp
modifier|*
name|rdn_next
decl_stmt|;
block|}
name|rdncomp
operator|,
typedef|*
name|RDN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLRDN
value|((RDN) 0)
end_define

begin_define
define|#
directive|define
name|rdn_comp_alloc
parameter_list|()
value|(RDN) smalloc(sizeof(rdncomp))
end_define

begin_function_decl
name|RDN
name|rdn_comp_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|RDN
name|rdn_comp_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|RDN
name|str2rdn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|RDN
name|rdn_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|RDN
name|rdn_merge
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
name|dncomp
block|{
comment|/* DN is sequence of RDNs.              */
comment|/* represents RDNSequence which is      */
comment|/* equivalent to DistinguishedName      */
name|RDN
name|dn_rdn
decl_stmt|;
name|struct
name|dncomp
modifier|*
name|dn_parent
decl_stmt|;
block|}
name|dncomp
operator|,
typedef|*
name|DN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLDN
value|((DN) 0)
end_define

begin_define
define|#
directive|define
name|dn_comp_alloc
parameter_list|()
value|(DN) smalloc(sizeof(dncomp))
end_define

begin_define
define|#
directive|define
name|dn_comp_print
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|if (y!=NULLDN) rdn_print(x,y->dn_rdn,z)
end_define

begin_define
define|#
directive|define
name|dn_comp_fill
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x -> dn_rdn = y
end_define

begin_define
define|#
directive|define
name|dn_comp_cmp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((rdn_cmp (x->dn_rdn ,y->dn_rdn) == OK) ? OK : NOTOK )
end_define

begin_function_decl
name|DN
name|dn_comp_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DN
name|dn_comp_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DN
name|dn_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DN
name|str2dn
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

