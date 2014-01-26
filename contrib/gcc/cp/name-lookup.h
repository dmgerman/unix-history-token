begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for C++ name lookup routines.    Copyright (C) 2003, 2004, 2005  Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@integrable-solutions.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CP_NAME_LOOKUP_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CP_NAME_LOOKUP_H
end_define

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_comment
comment|/* The type of dictionary used to map names to types declared at    a given scope.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|binding_table_s
modifier|*
name|binding_table
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|binding_entry_s
modifier|*
name|binding_entry
typedef|;
end_typedef

begin_comment
comment|/* The type of a routine repeatedly called by binding_table_foreach.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bt_foreach_proc
function_decl|)
parameter_list|(
name|binding_entry
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|struct
name|binding_entry_s
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|binding_entry
name|chain
decl_stmt|;
name|tree
name|name
decl_stmt|;
name|tree
name|type
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* These macros indicate the initial chains count for binding_table.  */
end_comment

begin_define
define|#
directive|define
name|SCOPE_DEFAULT_HT_SIZE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CLASS_SCOPE_HT_SIZE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|NAMESPACE_ORDINARY_HT_SIZE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|NAMESPACE_STD_HT_SIZE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|GLOBAL_SCOPE_HT_SIZE
value|(1<< 8)
end_define

begin_function_decl
specifier|extern
name|void
name|binding_table_foreach
parameter_list|(
name|binding_table
parameter_list|,
name|bt_foreach_proc
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|binding_entry
name|binding_table_find
parameter_list|(
name|binding_table
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Datatype that represents binding established by a declaration between    a name and a C++ entity.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cxx_binding
name|cxx_binding
typedef|;
end_typedef

begin_comment
comment|/* The datatype used to implement C++ scope.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cp_binding_level
name|cxx_scope
typedef|;
end_typedef

begin_comment
comment|/* Nonzero if this binding is for a local scope, as opposed to a class    or namespace scope.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_BINDING_P
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->is_local)
end_define

begin_comment
comment|/* True if NODE->value is from a base class of the class which is    currently being defined.  */
end_comment

begin_define
define|#
directive|define
name|INHERITED_VALUE_BINDING_P
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->value_is_inherited)
end_define

begin_decl_stmt
name|struct
name|cxx_binding
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Link to chain together various bindings for this name.  */
name|cxx_binding
modifier|*
name|previous
decl_stmt|;
comment|/* The non-type entity this name is bound to.  */
name|tree
name|value
decl_stmt|;
comment|/* The type entity this name is bound to.  */
name|tree
name|type
decl_stmt|;
comment|/* The scope at which this binding was made.  */
name|cxx_scope
modifier|*
name|scope
decl_stmt|;
name|unsigned
name|value_is_inherited
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_local
range|:
literal|1
decl_stmt|;
comment|/* APPLE LOCAL blocks 6040305 (ch) */
name|unsigned
name|declared_in_block
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Datatype used to temporarily save C++ bindings (for implicit    instantiations purposes and like).  Implemented in decl.c.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cxx_saved_binding
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The name of the current binding.  */
name|tree
name|identifier
block|;
comment|/* The binding we're saving.  */
name|cxx_binding
modifier|*
name|binding
block|;
name|tree
name|real_type_value
block|; }
end_typedef

begin_expr_stmt
name|cxx_saved_binding
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_O
argument_list|(
name|cxx_saved_binding
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_O
argument_list|(
name|cxx_saved_binding
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|tree
name|identifier_type_value
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_identifier_type_value
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_binding
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|constructor_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|constructor_name_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* The kinds of scopes we recognize.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|scope_kind
block|{
name|sk_block
init|=
literal|0
block|,
comment|/* An ordinary block scope.  This enumerator must 			have the value zero because "cp_binding_level" 			is initialized by using "memset" to set the 			contents to zero, and the default scope kind 			is "sk_block".  */
name|sk_cleanup
block|,
comment|/* A scope for (pseudo-)scope for cleanup.  It is 			pseudo in that it is transparent to name lookup 			activities.  */
name|sk_try
block|,
comment|/* A try-block.  */
name|sk_catch
block|,
comment|/* A catch-block.  */
name|sk_for
block|,
comment|/* The scope of the variable declared in a 			for-init-statement.  */
name|sk_function_parms
block|,
comment|/* The scope containing function parameters.  */
name|sk_class
block|,
comment|/* The scope containing the members of a class.  */
name|sk_namespace
block|,
comment|/* The scope containing the members of a 			namespace, including the global scope.  */
name|sk_template_parms
block|,
comment|/* A scope for template parameters.  */
name|sk_template_spec
block|,
comment|/* Like sk_template_parms, but for an explicit 			specialization.  Since, by definition, an 			explicit specialization is introduced by 			"template<>", this scope is always empty.  */
name|sk_omp
comment|/* An OpenMP structured block.  */
block|}
name|scope_kind
typedef|;
end_typedef

begin_comment
comment|/* The scope where the class/struct/union/enum tag applies.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|tag_scope
block|{
name|ts_current
init|=
literal|0
block|,
comment|/* Current scope only.  This is for the 			     class-key identifier; 			   case mentioned in [basic.lookup.elab]/2, 			   or the class/enum definition 			     class-key identifier { ... };  */
name|ts_global
init|=
literal|1
block|,
comment|/* All scopes.  This is the 3.4.1 			   [basic.lookup.unqual] lookup mentioned 			   in [basic.lookup.elab]/2.  */
name|ts_within_enclosing_non_class
init|=
literal|2
comment|/* Search within enclosing non-class 					   only, for friend class lookup 					   according to [namespace.memdef]/3 					   and [class.friend]/9.  */
block|}
name|tag_scope
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cp_class_binding
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|cxx_binding
name|base
block|;
comment|/* The bound name.  */
name|tree
name|identifier
block|; }
end_typedef

begin_expr_stmt
name|cp_class_binding
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_O
argument_list|(
name|cp_class_binding
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_O
argument_list|(
name|cp_class_binding
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* For each binding contour we allocate a binding_level structure    which records the names defined in that contour.    Contours include:     0) the global one     1) one for each function definition,        where internal declarations of the parameters appear.     2) one for each compound statement,        to record its declarations.     The current meaning of a name can be found by searching the levels    from the current one out to the global one.     Off to the side, may be the class_binding_level.  This exists only    to catch class-local declarations.  It is otherwise nonexistent.     Also there may be binding levels that catch cleanups that must be    run when exceptions occur.  Thus, to see whether a name is bound in    the current scope, it is not enough to look in the    CURRENT_BINDING_LEVEL.  You should use lookup_name_current_level    instead.  */
end_comment

begin_comment
comment|/* Note that the information in the `names' component of the global contour    is duplicated in the IDENTIFIER_GLOBAL_VALUEs of all identifiers.  */
end_comment

begin_decl_stmt
name|struct
name|cp_binding_level
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* A chain of _DECL nodes for all variables, constants, functions,        and typedef types.  These are in the reverse of the order        supplied.  There may be OVERLOADs on this list, too, but they        are wrapped in TREE_LISTs; the TREE_VALUE is the OVERLOAD.  */
name|tree
name|names
decl_stmt|;
comment|/* Count of elements in names chain.  */
name|size_t
name|names_size
decl_stmt|;
comment|/* A chain of NAMESPACE_DECL nodes.  */
name|tree
name|namespaces
decl_stmt|;
comment|/* An array of static functions and variables (for namespaces only) */
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|static_decls
expr_stmt|;
comment|/* A chain of VTABLE_DECL nodes.  */
name|tree
name|vtables
decl_stmt|;
comment|/* A list of USING_DECL nodes.  */
name|tree
name|usings
decl_stmt|;
comment|/* A list of used namespaces. PURPOSE is the namespace,        VALUE the common ancestor with this binding_level's namespace.  */
name|tree
name|using_directives
decl_stmt|;
comment|/* For the binding level corresponding to a class, the entities        declared in the class or its base classes.  */
name|VEC
argument_list|(
name|cp_class_binding
argument_list|,
name|gc
argument_list|)
operator|*
name|class_shadowed
expr_stmt|;
comment|/* Similar to class_shadowed, but for IDENTIFIER_TYPE_VALUE, and        is used for all binding levels. The TREE_PURPOSE is the name of        the entity, the TREE_TYPE is the associated type.  In addition        the TREE_VALUE is the IDENTIFIER_TYPE_VALUE before we entered        the class.  */
name|tree
name|type_shadowed
decl_stmt|;
comment|/* A TREE_LIST.  Each TREE_VALUE is the LABEL_DECL for a local        label in this scope.  The TREE_PURPOSE is the previous value of        the IDENTIFIER_LABEL VALUE.  */
name|tree
name|shadowed_labels
decl_stmt|;
comment|/* For each level (except not the global one),        a chain of BLOCK nodes for all the levels        that were entered and exited one level down.  */
name|tree
name|blocks
decl_stmt|;
comment|/* The entity (namespace, class, function) the scope of which this        binding contour corresponds to.  Otherwise NULL.  */
name|tree
name|this_entity
decl_stmt|;
comment|/* The binding level which this one is contained in (inherits from).  */
name|struct
name|cp_binding_level
modifier|*
name|level_chain
decl_stmt|;
comment|/* List of VAR_DECLS saved from a previous for statement.        These would be dead in ISO-conforming code, but might        be referenced in ARM-era code.  These are stored in a        TREE_LIST; the TREE_VALUE is the actual declaration.  */
name|tree
name|dead_vars_from_for
decl_stmt|;
comment|/* STATEMENT_LIST for statements in this binding contour.        Only used at present for SK_CLEANUP temporary bindings.  */
name|tree
name|statement_list
decl_stmt|;
comment|/* Binding depth at which this level began.  */
name|int
name|binding_depth
decl_stmt|;
comment|/* The kind of scope that this object represents.  However, a        SK_TEMPLATE_SPEC scope is represented with KIND set to        SK_TEMPLATE_PARMS and EXPLICIT_SPEC_P set to true.  */
name|ENUM_BITFIELD
argument_list|(
argument|scope_kind
argument_list|)
name|kind
label|:
literal|4
expr_stmt|;
comment|/* True if this scope is an SK_TEMPLATE_SPEC scope.  This field is        only valid if KIND == SK_TEMPLATE_PARMS.  */
name|BOOL_BITFIELD
name|explicit_spec_p
range|:
literal|1
decl_stmt|;
comment|/* true means make a BLOCK for this level regardless of all else.  */
name|unsigned
name|keep
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this level can safely have additional        cleanup-needing variables added to it.  */
name|unsigned
name|more_cleanups_ok
range|:
literal|1
decl_stmt|;
name|unsigned
name|have_cleanups
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this level has associated visibility which we should pop        when leaving the scope. */
name|unsigned
name|has_visibility
range|:
literal|1
decl_stmt|;
comment|/* 23 bits left to fill a 32-bit word.  */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The binding level currently in effect.  */
end_comment

begin_define
define|#
directive|define
name|current_binding_level
define|\
value|(*(cfun&& cp_function_chain->bindings	\    ?&cp_function_chain->bindings		\    :&scope_chain->bindings))
end_define

begin_comment
comment|/* The binding level of the current class, if any.  */
end_comment

begin_define
define|#
directive|define
name|class_binding_level
value|scope_chain->class_bindings
end_define

begin_comment
comment|/* The tree node representing the global scope.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|global_namespace
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|global_scope_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indicates that there is a type value in some namespace, although    that is not necessarily in scope at the moment.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|global_type_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if SCOPE designates the global scope binding contour.  */
end_comment

begin_define
define|#
directive|define
name|global_scope_p
parameter_list|(
name|SCOPE
parameter_list|)
define|\
value|((SCOPE) == NAMESPACE_LEVEL (global_namespace))
end_define

begin_function_decl
specifier|extern
name|cxx_scope
modifier|*
name|leave_scope
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|kept_level_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|global_bindings_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|toplevel_bindings_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|namespace_bindings_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|template_parm_scope_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|scope_kind
name|innermost_scope_kind
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cxx_scope
modifier|*
name|begin_scope
parameter_list|(
name|scope_kind
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_binding_stack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_to_top_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_from_top_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_everything
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|keep_next_level
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_ancestor
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|push_scope
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_scope
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|push_inner_scope
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_inner_scope
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_binding_level
parameter_list|(
name|struct
name|cp_binding_level
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_function_decl
specifier|extern
name|void
name|push_namespace
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_namespace_with_attribs
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_namespace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_nested_namespace
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_nested_namespace
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushlevel_class
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|poplevel_class
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushdecl_with_scope
parameter_list|(
name|tree
parameter_list|,
name|cxx_scope
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_name_prefer_type
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_name_real
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_type_scope
parameter_list|(
name|tree
parameter_list|,
name|tag_scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|namespace_binding
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_namespace_binding
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|hidden_name_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|remove_hidden_names
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_qualified_name
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_name_nonclass
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_function_nonclass
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_local_binding
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|pushdecl_class_level
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushdecl_namespace_level
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|push_class_level_binding
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|getdecls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_namespace_decls
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_decl_namespace
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_decl_namespace
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_decl_namespace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_namespace_alias
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_toplevel_using_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_local_using_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|do_class_using_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_using_directive
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_arg_dependent
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_associated_namespace
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|parse_using_directive
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|innermost_non_namespace_value
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cxx_binding
modifier|*
name|outer_binding
parameter_list|(
name|tree
parameter_list|,
name|cxx_binding
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_emit_debug_info_for_using
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *DECL to the (non-hidden) declaration for ID at global scope,    if present and return true; otherwise return false.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|get_global_value_if_present
parameter_list|(
name|tree
name|id
parameter_list|,
name|tree
modifier|*
name|decl
parameter_list|)
block|{
name|tree
name|global_value
init|=
name|namespace_binding
argument_list|(
name|id
argument_list|,
name|global_namespace
argument_list|)
decl_stmt|;
if|if
condition|(
name|global_value
condition|)
operator|*
name|decl
operator|=
name|global_value
expr_stmt|;
return|return
name|global_value
operator|!=
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* True is the binding of IDENTIFIER at global scope names a type.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|is_typename_at_global_scope
parameter_list|(
name|tree
name|id
parameter_list|)
block|{
name|tree
name|global_value
init|=
name|namespace_binding
argument_list|(
name|id
argument_list|,
name|global_namespace
argument_list|)
decl_stmt|;
return|return
name|global_value
operator|&&
name|TREE_CODE
argument_list|(
name|global_value
argument_list|)
operator|==
name|TYPE_DECL
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_CP_NAME_LOOKUP_H */
end_comment

end_unit

