begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* turbo.h - your comments here */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/turbo.h,v 7.2 91/03/09 11:54:10 mrose Exp $  *  *  * $Log:	turbo.h,v $  * Revision 7.2  91/03/09  11:54:10  mrose  * update  *   * Revision 7.1  91/02/22  09:26:08  mrose  * Interim 6.8  *   * Revision 7.0  90/12/19  09:42:48  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUTURBO
end_ifndef

begin_define
define|#
directive|define
name|QUIPUTURBO
end_define

begin_include
include|#
directive|include
file|"quipu/config.h"
end_include

begin_include
include|#
directive|include
file|"quipu/name.h"
end_include

begin_comment
comment|/*  * this structure represents a generic avl tree node.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|avlnode
block|{
name|caddr_t
name|avl_data
decl_stmt|;
name|char
name|avl_bf
decl_stmt|;
name|struct
name|avlnode
modifier|*
name|avl_left
decl_stmt|;
name|struct
name|avlnode
modifier|*
name|avl_right
decl_stmt|;
block|}
name|Avlnode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLAVL
value|((Avlnode *) NULL)
end_define

begin_comment
comment|/* balance factor values */
end_comment

begin_define
define|#
directive|define
name|LH
value|-1
end_define

begin_define
define|#
directive|define
name|EH
value|0
end_define

begin_define
define|#
directive|define
name|RH
value|1
end_define

begin_comment
comment|/* avl routines */
end_comment

begin_define
define|#
directive|define
name|avl_getone
parameter_list|(
name|x
parameter_list|)
value|(x == 0 ? 0 : (x)->avl_data)
end_define

begin_define
define|#
directive|define
name|avl_onenode
parameter_list|(
name|x
parameter_list|)
value|(x == 0 || ((x)->avl_left == 0&& (x)->avl_right == 0))
end_define

begin_function_decl
specifier|extern
name|int
name|avl_insert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|avl_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|avl_find
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|avl_getfirst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|avl_getnext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|avl_dup_error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|avl_apply
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* apply traversal types */
end_comment

begin_define
define|#
directive|define
name|AVL_PREORDER
value|1
end_define

begin_define
define|#
directive|define
name|AVL_INORDER
value|2
end_define

begin_define
define|#
directive|define
name|AVL_POSTORDER
value|3
end_define

begin_comment
comment|/* what apply returns if it ran out of nodes */
end_comment

begin_define
define|#
directive|define
name|AVL_NOMORE
value|-6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TURBO_INDEX
end_ifdef

begin_comment
comment|/*  * this structure represents an attribute index.  the index is composed  * of the attribute type, a count of the number of different values in  * the tree, and a pointer to the root of the tree of attribute values.  * these nodes are linked together (one node for each attribute type being  * optimized) in an avl tree in each index node.  there is also  * a tree and count for soundex values of the attribute.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|index
block|{
comment|/* entry associated with this index */
comment|/* sibling => parent		    */
name|DN
name|i_dn
decl_stmt|;
comment|/* subtree => base		    */
comment|/* for subtree index: descendants   */
comment|/* not held locally		    */
name|struct
name|entry
modifier|*
modifier|*
name|i_nonleafkids
decl_stmt|;
comment|/* for both: aliases that escape    */
comment|/* the scope of the index	    */
name|struct
name|entry
modifier|*
modifier|*
name|i_nonlocalaliases
decl_stmt|;
name|AttributeType
name|i_attr
decl_stmt|;
comment|/* the attribute type		    */
name|int
name|i_count
decl_stmt|;
comment|/* number of entries in this tree   */
name|int
name|i_scount
decl_stmt|;
comment|/* number of ents in soundex tree   */
name|Avlnode
modifier|*
name|i_root
decl_stmt|;
comment|/* tree of values		    */
name|Avlnode
modifier|*
name|i_sroot
decl_stmt|;
comment|/* tree of soundex values	    */
block|}
name|Index
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLINDEX
value|((Index *) 0)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|entry
modifier|*
name|ep_entry
decl_stmt|;
name|int
name|ep_count
decl_stmt|;
block|}
name|eptr_node
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|index_node
block|{
name|caddr_t
name|in_value
decl_stmt|;
name|struct
name|entry
modifier|*
modifier|*
name|in_entries
decl_stmt|;
name|int
name|in_num
decl_stmt|;
block|}
name|Index_node
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLINDEXNODE
value|((Index_node *) 0)
end_define

begin_define
define|#
directive|define
name|get_subtree_index
parameter_list|(
name|x
parameter_list|)
define|\
value|((Index *) avl_find( subtree_index, (caddr_t) (x), idn_cmp ))
end_define

begin_define
define|#
directive|define
name|get_sibling_index
parameter_list|(
name|x
parameter_list|)
define|\
value|((Index *) avl_find( sibling_index, (caddr_t) (x), idn_cmp ))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TURBO_INDEX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* QUIPUTURBO */
end_comment

end_unit

