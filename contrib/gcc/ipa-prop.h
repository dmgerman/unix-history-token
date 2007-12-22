begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interprocedural analyses.    Copyright (C) 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPA_PROP_H
end_ifndef

begin_define
define|#
directive|define
name|IPA_PROP_H
end_define

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_comment
comment|/* The following definitions and interfaces are used by    interprocedural analyses.  */
end_comment

begin_comment
comment|/* A jump function for a callsite represents the values passed as actual     arguments of the callsite. There are three main types of values :    Formal - the caller's formal parameter is passed as an actual argument.    Constant - a constant is passed as a an actual argument.    Unknown - neither of the above.    Integer and real constants are represented as CONST_IPATYPE and Fortran     constants are represented as CONST_IPATYPE_REF.  */
end_comment

begin_enum
enum|enum
name|jump_func_type
block|{
name|UNKNOWN_IPATYPE
block|,
name|CONST_IPATYPE
block|,
name|CONST_IPATYPE_REF
block|,
name|FORMAL_IPATYPE
block|}
enum|;
end_enum

begin_comment
comment|/* All formal parameters in the program have a cval computed by     the interprocedural stage of IPCP.      There are three main values of cval :    TOP - unknown.    BOTTOM - non constant.    CONSTANT_TYPE - constant value.    Cval of formal f will have a constant value if all callsites to this    function have the same constant value passed to f.    Integer and real constants are represented as CONST_IPATYPE and Fortran    constants are represented as CONST_IPATYPE_REF.  */
end_comment

begin_enum
enum|enum
name|cvalue_type
block|{
name|BOTTOM
block|,
name|CONST_VALUE
block|,
name|CONST_VALUE_REF
block|,
name|TOP
block|}
enum|;
end_enum

begin_comment
comment|/* Represents the value of either jump function or cval.    value represents a constant.    formal_id is used only in jump function context and represents     pass-through parameter (the formal of caller is passed     as argument).  */
end_comment

begin_union
union|union
name|parameter_info
block|{
name|unsigned
name|int
name|formal_id
decl_stmt|;
name|tree
name|value
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* A jump function for a callsite represents the values passed as actual     arguments of the callsite. See enum jump_func_type for the various     types of jump functions supported.  */
end_comment

begin_struct
struct|struct
name|ipa_jump_func
block|{
name|enum
name|jump_func_type
name|type
decl_stmt|;
name|union
name|parameter_info
name|info_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* All formal parameters in the program have a cval computed by     the interprocedural stage of IPCP. See enum cvalue_type for     the various types of cvals supported */
end_comment

begin_struct
struct|struct
name|ipcp_formal
block|{
name|enum
name|cvalue_type
name|cval_type
decl_stmt|;
name|union
name|parameter_info
name|cvalue
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Represent which DECL tree (or reference to such tree)    will be replaced by another tree while versioning.  */
end_comment

begin_struct
struct|struct
name|ipa_replace_map
block|{
comment|/* The tree that will be replaced.  */
name|tree
name|old_tree
decl_stmt|;
comment|/* The new (replacing) tree.  */
name|tree
name|new_tree
decl_stmt|;
comment|/* True when a substitution should be done, false otherwise.  */
name|bool
name|replace_p
decl_stmt|;
comment|/* True when we replace a reference to old_tree.  */
name|bool
name|ref_p
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Return the field in cgraph_node/cgraph_edge struct that points    to ipa_node/ipa_edge struct.  */
end_comment

begin_define
define|#
directive|define
name|IPA_NODE_REF
parameter_list|(
name|MT
parameter_list|)
value|((struct ipa_node *)(MT)->aux)
end_define

begin_define
define|#
directive|define
name|IPA_EDGE_REF
parameter_list|(
name|EDGE
parameter_list|)
value|((struct ipa_edge *)(EDGE)->aux)
end_define

begin_comment
comment|/* ipa_node stores information related to a method and    its formal parameters. It is pointed to by a field in the    method's corresponding cgraph_node.     ipa_edge stores information related to a callsite and    its arguments. It is pointed to by a field in the    callsite's corresponding cgraph_edge.  */
end_comment

begin_struct
struct|struct
name|ipa_node
block|{
comment|/* Number of formal parameters of this method.  When set to 0,      this method's parameters would not be analyzed by the different      stages of IPA CP.  */
name|int
name|ipa_arg_num
decl_stmt|;
comment|/* Array of cvals.  */
name|struct
name|ipcp_formal
modifier|*
name|ipcp_cval
decl_stmt|;
comment|/* Mapping each parameter to its PARM_DECL tree.  */
name|tree
modifier|*
name|ipa_param_tree
decl_stmt|;
comment|/* Indicating which parameter is modified in its method.  */
name|bool
modifier|*
name|ipa_mod
decl_stmt|;
comment|/* Only for versioned nodes this field would not be NULL,      it points to the node that IPA cp cloned from.  */
name|struct
name|cgraph_node
modifier|*
name|ipcp_orig_node
decl_stmt|;
comment|/* Meaningful only for original methods.  Expresses the       ratio between the direct calls and sum of all invocations of       this function (given by profiling info).  It is used to calculate       the profiling information of the original function and the versioned      one.  */
name|gcov_type
name|count_scale
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipa_edge
block|{
comment|/* Number of actual arguments in this callsite.  When set to 0,      this callsite's parameters would not be analyzed by the different      stages of IPA CP.  */
name|int
name|ipa_param_num
decl_stmt|;
comment|/* Array of the callsite's jump function of each parameter.  */
name|struct
name|ipa_jump_func
modifier|*
name|ipa_param_map
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A methodlist element (referred to also as methodlist node). It is used     to create a temporary worklist used in     the propagation stage of IPCP. (can be used for more IPA     optimizations)  */
end_comment

begin_struct
struct|struct
name|ipa_methodlist
block|{
name|struct
name|cgraph_node
modifier|*
name|method_p
decl_stmt|;
name|struct
name|ipa_methodlist
modifier|*
name|next_method
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A pointer to a methodlist element.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ipa_methodlist
modifier|*
name|ipa_methodlist_p
typedef|;
end_typedef

begin_comment
comment|/* ipa_methodlist interface.  */
end_comment

begin_function_decl
name|ipa_methodlist_p
name|ipa_methodlist_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ipa_methodlist_not_empty
parameter_list|(
name|ipa_methodlist_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_add_method
parameter_list|(
name|ipa_methodlist_p
modifier|*
parameter_list|,
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_node
modifier|*
name|ipa_remove_method
parameter_list|(
name|ipa_methodlist_p
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipa_callsite interface.  */
end_comment

begin_function_decl
name|int
name|ipa_callsite_param_count
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_callsite_param_count_set
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ipa_jump_func
modifier|*
name|ipa_callsite_param
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cgraph_node
modifier|*
name|ipa_callsite_callee
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_callsite_compute_param
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_callsite_compute_count
parameter_list|(
name|struct
name|cgraph_edge
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipa_method interface.  */
end_comment

begin_function_decl
name|int
name|ipa_method_formal_count
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_method_formal_count_set
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ipa_method_get_tree
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_method_compute_tree_map
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_method_formal_compute_count
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_method_compute_modify
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* jump function interface.  */
end_comment

begin_function_decl
name|enum
name|jump_func_type
name|get_type
parameter_list|(
name|struct
name|ipa_jump_func
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|parameter_info
modifier|*
name|ipa_jf_get_info_type
parameter_list|(
name|struct
name|ipa_jump_func
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipa_node and ipa_edge interfaces.  */
end_comment

begin_function_decl
name|void
name|ipa_node_create
parameter_list|(
name|struct
name|cgraph_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_nodes_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_edges_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_edges_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_nodes_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Debugging interface.  */
end_comment

begin_function_decl
name|void
name|ipa_method_tree_print
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipa_method_modify_print
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|ipcp_driver
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
comment|/* IPA_PROP_H */
end_comment

end_unit

