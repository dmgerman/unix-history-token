begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nrs_info.h - attribute structure for representing NRS information */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUNRSINFO
end_ifndef

begin_define
define|#
directive|define
name|QUIPUNRSINFO
end_define

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_struct
struct|struct
name|str_seq
block|{
name|char
modifier|*
name|ss_str
decl_stmt|;
name|struct
name|str_seq
modifier|*
name|ss_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Defined values for contexts */
end_comment

begin_define
define|#
directive|define
name|NRS_Context_UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|NRS_Context_X29
value|0
end_define

begin_define
define|#
directive|define
name|NRS_Context_TS29
value|1
end_define

begin_define
define|#
directive|define
name|NRS_Context_NIFTP
value|2
end_define

begin_define
define|#
directive|define
name|NRS_Context_MAIL_NIFTP
value|3
end_define

begin_define
define|#
directive|define
name|NRS_Context_NOT_USED
value|4
end_define

begin_define
define|#
directive|define
name|NRS_Context_MAIL_TELEX
value|5
end_define

begin_define
define|#
directive|define
name|NRS_Context_JTMP
value|6
end_define

begin_define
define|#
directive|define
name|NRS_Context_JTMP_FILES
value|7
end_define

begin_define
define|#
directive|define
name|NRS_Context_JTMP_REG
value|8
end_define

begin_define
define|#
directive|define
name|NRS_Context_YBTS_NODE
value|9
end_define

begin_define
define|#
directive|define
name|NRS_Context_YBTS
value|10
end_define

begin_define
define|#
directive|define
name|NRS_Context_FTAM
value|11
end_define

begin_define
define|#
directive|define
name|NRS_Context_JTM
value|12
end_define

begin_define
define|#
directive|define
name|NRS_Context_JTM_REG
value|13
end_define

begin_define
define|#
directive|define
name|NRS_Context_VT
value|14
end_define

begin_define
define|#
directive|define
name|NRS_Context_MOTIS
value|15
end_define

begin_comment
comment|/* Defined values for address space identifiers */
end_comment

begin_define
define|#
directive|define
name|NRS_Address_Space_Id_PSS
value|0
end_define

begin_define
define|#
directive|define
name|NRS_Address_Space_Id_JANET
value|1
end_define

begin_define
define|#
directive|define
name|NRS_Address_Space_Id_TELEX
value|2
end_define

begin_define
define|#
directive|define
name|NRS_Address_Space_Id_OSI_CONS
value|3
end_define

begin_struct
struct|struct
name|addr_info
block|{
name|int
name|addr_info_type
decl_stmt|;
define|#
directive|define
name|ADDR_INFO_DTE_ONLY
value|1
define|#
directive|define
name|ADDR_INFO_DTE_APPLIC_INFO
value|2
define|#
directive|define
name|ADDR_INFO_DTE_CUDF
value|3
define|#
directive|define
name|ADDR_INFO_DTE_CUDF_APPLIC_INFO
value|4
define|#
directive|define
name|ADDR_INFO_DTE_YBTS
value|5
define|#
directive|define
name|ADDR_INFO_DTE_YBTS_APPLIC_INFO
value|6
define|#
directive|define
name|ADDR_INFO_DTE_YBTS_APPLIC_RELAY
value|7
define|#
directive|define
name|ADDR_INFO_NONE_NEEDED
value|8
define|#
directive|define
name|ADDR_INFO_OSI_ADDRESSING
value|9
define|#
directive|define
name|ADDR_INFO_OSI_NSAP_ONLY
value|10
define|#
directive|define
name|ADDR_INFO_OSI_NSAP_APPLIC_INFO
value|11
define|#
directive|define
name|ADDR_INFO_OSI_NSAP_APPLIC_RELAY
value|12
define|#
directive|define
name|ADDR_INFO_DTE_YBTS_OSI_ADDRESSING
value|13
name|char
modifier|*
name|dte_number
decl_stmt|;
name|char
modifier|*
name|cudf
decl_stmt|;
name|char
modifier|*
name|ybts_string
decl_stmt|;
name|char
modifier|*
name|nsap
decl_stmt|;
name|char
modifier|*
name|tselector
decl_stmt|;
name|char
modifier|*
name|sselector
decl_stmt|;
name|char
modifier|*
name|pselector
decl_stmt|;
name|PE
name|place_holder
decl_stmt|;
name|PE
name|application_title
decl_stmt|;
name|PE
name|per_app_context_info
decl_stmt|;
name|struct
name|str_seq
modifier|*
name|applic_info
decl_stmt|;
name|struct
name|str_seq
modifier|*
name|applic_relay
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nrs_routes
block|{
name|PE
name|cost
decl_stmt|;
name|struct
name|addr_info
modifier|*
name|addr_info
decl_stmt|;
name|struct
name|nrs_routes
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nrs_info
block|{
name|int
name|context
decl_stmt|;
name|int
name|addr_sp_id
decl_stmt|;
name|struct
name|nrs_routes
modifier|*
name|routes
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

