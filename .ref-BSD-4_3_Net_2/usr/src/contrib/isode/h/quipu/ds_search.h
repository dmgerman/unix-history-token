begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ds_search.h - structures for searching */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/ds_search.h,v 7.6 91/03/09 11:54:05 mrose Exp $  *  *  * $Log:	ds_search.h,v $  * Revision 7.6  91/03/09  11:54:05  mrose  * update  *   * Revision 7.5  91/02/22  09:25:45  mrose  * Interim 6.8  *   * Revision 7.4  90/11/20  15:30:35  mrose  * cjr  *   * Revision 7.3  90/10/17  11:46:24  mrose  * sync  *   * Revision 7.2  90/07/09  14:38:27  mrose  * sync  *   * Revision 7.1  90/03/15  11:18:05  mrose  * quipu-sync  *   * Revision 7.0  89/11/23  21:56:31  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUSRCH
end_ifndef

begin_define
define|#
directive|define
name|QUIPUSRCH
end_define

begin_include
include|#
directive|include
file|"quipu/config.h"
end_include

begin_include
include|#
directive|include
file|"quipu/commonarg.h"
end_include

begin_include
include|#
directive|include
file|"quipu/ds_error.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dap.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|AttributeType
name|fi_sub_type
decl_stmt|;
name|AV_Sequence
name|fi_sub_initial
decl_stmt|;
name|AV_Sequence
name|fi_sub_any
decl_stmt|;
name|AV_Sequence
name|fi_sub_final
decl_stmt|;
comment|/* initial and final should be zero or  */
comment|/* one components only                  */
name|char
modifier|*
name|fi_sub_match
decl_stmt|;
comment|/* for DSA use */
block|}
name|Filter_Substrings
typedef|;
end_typedef

begin_struct
struct|struct
name|filter_item
block|{
name|int
name|fi_type
decl_stmt|;
define|#
directive|define
name|FILTERITEM_EQUALITY
value|1
define|#
directive|define
name|FILTERITEM_SUBSTRINGS
value|2
define|#
directive|define
name|FILTERITEM_GREATEROREQUAL
value|3
define|#
directive|define
name|FILTERITEM_LESSOREQUAL
value|4
define|#
directive|define
name|FILTERITEM_PRESENT
value|5
define|#
directive|define
name|FILTERITEM_APPROX
value|6
union|union
block|{
name|AttributeType
name|fi_un_type
decl_stmt|;
name|AVA
name|fi_un_ava
decl_stmt|;
name|Filter_Substrings
name|fi_un_substrings
decl_stmt|;
block|}
name|fi_un
union|;
comment|/* field for DSA use - no need to fill is DUA */
name|IFP
name|fi_ifp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLFITEM
value|(struct filter_item *) NULL
end_define

begin_define
define|#
directive|define
name|UNSUB
value|fi_un.fi_un_substrings
end_define

begin_define
define|#
directive|define
name|UNAVA
value|fi_un.fi_un_ava
end_define

begin_define
define|#
directive|define
name|UNTYPE
value|fi_un.fi_un_type
end_define

begin_define
define|#
directive|define
name|filter_item_alloc
parameter_list|()
value|(struct filter_item *) smalloc (sizeof (struct filter_item));
end_define

begin_typedef
typedef|typedef
struct|struct
name|filter
block|{
name|int
name|flt_type
decl_stmt|;
define|#
directive|define
name|FILTER_ITEM
value|1
define|#
directive|define
name|FILTER_AND
value|2
define|#
directive|define
name|FILTER_OR
value|3
define|#
directive|define
name|FILTER_NOT
value|4
name|struct
name|filter
modifier|*
name|flt_next
decl_stmt|;
union|union
block|{
name|struct
name|filter_item
name|flt_un_item
decl_stmt|;
comment|/* a basic item                 */
name|struct
name|filter
modifier|*
name|flt_un_filter
decl_stmt|;
comment|/* or a pointer to a chain of   */
comment|/* filters                      */
block|}
name|flt_un
union|;
block|}
name|filter
operator|,
typedef|*
name|Filter
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLFILTER
value|(Filter)NULL
end_define

begin_define
define|#
directive|define
name|FUITEM
value|flt_un.flt_un_item
end_define

begin_define
define|#
directive|define
name|FUFILT
value|flt_un.flt_un_filter
end_define

begin_define
define|#
directive|define
name|filter_alloc
parameter_list|()
value|(Filter) smalloc (sizeof (filter));
end_define

begin_struct
struct|struct
name|ds_search_arg
block|{
name|CommonArgs
name|sra_common
decl_stmt|;
name|DN
name|sra_baseobject
decl_stmt|;
name|int
name|sra_subset
decl_stmt|;
define|#
directive|define
name|SRA_BASEOBJECT
value|0
define|#
directive|define
name|SRA_ONELEVEL
value|1
define|#
directive|define
name|SRA_WHOLESUBTREE
value|2
name|Filter
name|sra_filter
decl_stmt|;
name|char
name|sra_searchaliases
decl_stmt|;
name|EntryInfoSelection
name|sra_eis
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ds_search_unit
block|{
name|CommonResults
name|srr_common
decl_stmt|;
name|DN
name|srr_object
decl_stmt|;
name|EntryInfo
modifier|*
name|srr_entries
decl_stmt|;
name|POQ
name|srr_poq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ds_search_result
block|{
name|char
name|srr_correlated
decl_stmt|;
union|union
block|{
name|struct
name|ds_search_unit
modifier|*
name|srr_unit
decl_stmt|;
name|struct
name|ds_search_result
modifier|*
name|srr_parts
decl_stmt|;
block|}
name|srr_un
union|;
define|#
directive|define
name|CSR_common
value|srr_un.srr_unit->srr_common
define|#
directive|define
name|CSR_object
value|srr_un.srr_unit->srr_object
define|#
directive|define
name|CSR_entries
value|srr_un.srr_unit->srr_entries
define|#
directive|define
name|CSR_limitproblem
value|srr_un.srr_unit->srr_poq.poq_limitproblem
define|#
directive|define
name|srr_limitproblem
value|srr_poq.poq_limitproblem
define|#
directive|define
name|CSR_cr
value|srr_un.srr_unit->srr_poq.poq_cref
define|#
directive|define
name|srr_cr
value|srr_poq.poq_cref
name|struct
name|ds_search_result
modifier|*
name|srr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLSRR
value|((struct ds_search_result *) 0)
end_define

begin_comment
comment|/* following used by search for scheduling */
end_comment

begin_struct
struct|struct
name|ds_search_task
block|{
name|DN
name|st_baseobject
decl_stmt|;
name|DN
name|st_alias
decl_stmt|;
name|DN
name|st_bind
decl_stmt|;
name|int
name|st_subset
decl_stmt|;
name|int
name|st_size
decl_stmt|;
ifdef|#
directive|ifdef
name|TURBO_INDEX
name|int
name|st_optimized
decl_stmt|;
endif|#
directive|endif
name|struct
name|di_block
modifier|*
name|st_di
decl_stmt|;
name|struct
name|ds_search_task
modifier|*
name|st_next
decl_stmt|;
name|ContinuationRef
name|st_cr
decl_stmt|;
name|struct
name|ds_search_task
modifier|*
name|st_save
decl_stmt|;
name|char
name|st_entryonly
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULL_ST
value|((struct ds_search_task *) NULL)
end_define

begin_define
define|#
directive|define
name|st_alloc
parameter_list|()
value|(struct ds_search_task *) smalloc (sizeof(struct ds_search_task));
end_define

begin_comment
comment|/* search max 1000 entries before worrying about time limits */
end_comment

begin_define
define|#
directive|define
name|SEARCH_DELTA_SIZE
value|1000
end_define

begin_comment
comment|/* character used to mark T.61 strings */
end_comment

begin_define
define|#
directive|define
name|T61_MARK
value|'$'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TURBO_AVL
end_ifdef

begin_comment
comment|/* used by search to pass info to routines called by avl routines */
end_comment

begin_struct
struct|struct
name|search_kid_arg
block|{
name|EntryInfo
modifier|*
modifier|*
name|ska_einfo
decl_stmt|;
name|struct
name|ds_search_arg
modifier|*
name|ska_arg
decl_stmt|;
name|struct
name|ds_search_task
modifier|*
modifier|*
name|ska_local
decl_stmt|;
name|struct
name|ds_search_task
modifier|*
modifier|*
name|ska_refer
decl_stmt|;
name|int
name|ska_extent
decl_stmt|;
name|int
name|ska_tmp
decl_stmt|;
name|int
name|ska_domore
decl_stmt|;
name|DN
name|ska_path
decl_stmt|;
name|DN
name|ska_dnend
decl_stmt|;
name|DN
name|ska_bind
decl_stmt|;
name|int
name|ska_ismanager
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

