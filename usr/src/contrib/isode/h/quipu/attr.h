begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* attr.h - directory service interface definition */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/attr.h,v 7.3 91/02/22 09:25:24 mrose Interim $  *  *  * $Log:	attr.h,v $  * Revision 7.3  91/02/22  09:25:24  mrose  * Interim 6.8  *   * Revision 7.2  90/10/17  11:46:13  mrose  * sync  *   * Revision 7.1  90/07/09  14:38:15  mrose  * sync  *   * Revision 7.0  89/11/23  21:56:21  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUATTR
end_ifndef

begin_define
define|#
directive|define
name|QUIPUATTR
end_define

begin_include
include|#
directive|include
file|"quipu/oid.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIRST SECTION DEFINES STRUCTURES FOR ADDRESSING */
end_comment

begin_typedef
typedef|typedef
name|oid_table_attr
modifier|*
name|attrType
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|oid_table_attr
modifier|*
name|AttributeType
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLAttrT
value|(AttributeType) NULL
end_define

begin_define
define|#
directive|define
name|AttrT_alloc
parameter_list|()
end_define

begin_define
define|#
directive|define
name|AttrT_cmp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|( x == y ? 0 : ( x> y ? -1 : 1 ))
end_define

begin_define
define|#
directive|define
name|AttrT_decode
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AttrT_free
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AttrT_cpy
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|grab_oid
parameter_list|(
name|x
parameter_list|)
value|(x ? x->oa_ot.ot_oid : NULLOID)
end_define

begin_function_decl
name|AttributeType
name|AttrT_new
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|str2AttrT
parameter_list|(
name|x
parameter_list|)
value|AttrT_new(x)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|av_syntax
decl_stmt|;
comment|/* Specifies the syntax of the      */
comment|/* attribute  that follows.         */
name|caddr_t
name|av_struct
decl_stmt|;
block|}
name|attrVal
operator|,
typedef|*
name|AttributeValue
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AV_WRITE_FILE
value|256
end_define

begin_define
define|#
directive|define
name|AV_FILE
value|128
end_define

begin_define
define|#
directive|define
name|MAX_AV_SYNTAX
value|100
end_define

begin_define
define|#
directive|define
name|NULLAttrV
value|(AttributeValue) NULL
end_define

begin_define
define|#
directive|define
name|AttrV_alloc
parameter_list|()
value|(AttributeValue) smalloc (sizeof (attrVal));
end_define

begin_function_decl
name|AttributeValue
name|AttrV_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|AttributeValue
name|str_at2AttrV
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|AttributeValue
name|str2AttrV
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|short
name|str2syntax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|short
name|add_attribute_syntax
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|file_syntax
block|{
name|short
name|fs_real_syntax
decl_stmt|;
name|char
modifier|*
name|fs_name
decl_stmt|;
name|char
name|fs_mode
decl_stmt|;
name|char
name|fs_ref
decl_stmt|;
name|AttributeValue
name|fs_attr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FS_DEFAULT
value|0x01
end_define

begin_comment
comment|/* default file name */
end_comment

begin_define
define|#
directive|define
name|FS_CREATE
value|0x02
end_define

begin_comment
comment|/* created thus remove file */
end_comment

begin_define
define|#
directive|define
name|EDBOUT
value|1
end_define

begin_define
define|#
directive|define
name|FILEOUT
value|2
end_define

begin_comment
comment|/* for writing to files only */
end_comment

begin_define
define|#
directive|define
name|READOUT
value|3
end_define

begin_define
define|#
directive|define
name|DIROUT
value|4
end_define

begin_comment
comment|/* for dn and rdn print only */
end_comment

begin_define
define|#
directive|define
name|RDNOUT
value|5
end_define

begin_define
define|#
directive|define
name|UFNOUT
value|6
end_define

begin_comment
comment|/* user-friendly naming */
end_comment

begin_define
define|#
directive|define
name|ps_print
parameter_list|(
name|ps
parameter_list|,
name|data
parameter_list|)
value|(void)ps_write(ps,(PElementData)data,strlen(data))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|s_sntx
decl_stmt|;
comment|/* String defining syntax */
name|IFP
name|s_encode
decl_stmt|;
name|IFP
name|s_decode
decl_stmt|;
name|IFP
name|s_parse
decl_stmt|;
name|IFP
name|s_print
decl_stmt|;
name|IFP
name|s_copy
decl_stmt|;
name|IFP
name|s_compare
decl_stmt|;
name|IFP
name|s_free
decl_stmt|;
name|char
modifier|*
name|s_pe_print
decl_stmt|;
comment|/* process to handle raw PE */
name|IFP
name|s_approx
decl_stmt|;
comment|/* approx match routine */
name|char
name|s_multiline
decl_stmt|;
comment|/* if true print each value on new line */
block|}
name|sntx_table
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

