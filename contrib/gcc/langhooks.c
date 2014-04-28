begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default language-specific hooks.    Copyright 2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"intl.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"tree-inline.h"
end_include

begin_include
include|#
directive|include
file|"tree-gimple.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"insn-config.h"
end_include

begin_include
include|#
directive|include
file|"integrate.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"langhooks.h"
end_include

begin_include
include|#
directive|include
file|"langhooks-def.h"
end_include

begin_include
include|#
directive|include
file|"ggc.h"
end_include

begin_include
include|#
directive|include
file|"diagnostic.h"
end_include

begin_comment
comment|/* Do nothing; in many cases the default hook.  */
end_comment

begin_function
name|void
name|lhd_do_nothing
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Do nothing (tree).  */
end_comment

begin_function
name|void
name|lhd_do_nothing_t
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|t
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Do nothing (int).  */
end_comment

begin_function
name|void
name|lhd_do_nothing_i
parameter_list|(
name|int
name|ARG_UNUSED
parameter_list|(
name|i
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Do nothing (int, int, int).  Return NULL_TREE.  */
end_comment

begin_function
name|tree
name|lhd_do_nothing_iii_return_null_tree
parameter_list|(
name|int
name|ARG_UNUSED
parameter_list|(
name|i
parameter_list|)
parameter_list|,
name|int
name|ARG_UNUSED
parameter_list|(
name|j
parameter_list|)
parameter_list|,
name|int
name|ARG_UNUSED
parameter_list|(
name|k
parameter_list|)
parameter_list|)
block|{
return|return
name|NULL_TREE
return|;
block|}
end_function

begin_comment
comment|/* Do nothing (function).  */
end_comment

begin_decl_stmt
name|void
name|lhd_do_nothing_f
argument_list|(
expr|struct
name|function
operator|*
name|ARG_UNUSED
argument_list|(
name|f
argument_list|)
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|/* Do nothing (return the tree node passed).  */
end_comment

begin_function
name|tree
name|lhd_return_tree
parameter_list|(
name|tree
name|t
parameter_list|)
block|{
return|return
name|t
return|;
block|}
end_function

begin_comment
comment|/* Do nothing (return NULL_TREE).  */
end_comment

begin_function
name|tree
name|lhd_return_null_tree_v
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|NULL_TREE
return|;
block|}
end_function

begin_comment
comment|/* Do nothing (return NULL_TREE).  */
end_comment

begin_function
name|tree
name|lhd_return_null_tree
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|t
parameter_list|)
parameter_list|)
block|{
return|return
name|NULL_TREE
return|;
block|}
end_function

begin_comment
comment|/* The default post options hook.  */
end_comment

begin_function
name|bool
name|lhd_post_options
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|ARG_UNUSED
parameter_list|(
name|pfilename
parameter_list|)
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Called from by print-tree.c.  */
end_comment

begin_function
name|void
name|lhd_print_tree_nothing
parameter_list|(
name|FILE
modifier|*
name|ARG_UNUSED
parameter_list|(
name|file
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|node
parameter_list|)
parameter_list|,
name|int
name|ARG_UNUSED
parameter_list|(
name|indent
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Called from safe_from_p.  */
end_comment

begin_function
name|int
name|lhd_safe_from_p
parameter_list|(
name|rtx
name|ARG_UNUSED
parameter_list|(
name|x
parameter_list|)
parameter_list|,
name|tree
name|ARG_UNUSED
parameter_list|(
name|exp
parameter_list|)
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Called from staticp.  */
end_comment

begin_function
name|tree
name|lhd_staticp
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|exp
parameter_list|)
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Called from check_global_declarations.  */
end_comment

begin_function
name|bool
name|lhd_warn_unused_global_decl
parameter_list|(
name|tree
name|decl
parameter_list|)
block|{
comment|/* This is what used to exist in check_global_declarations.  Probably      not many of these actually apply to non-C languages.  */
if|if
condition|(
name|TREE_CODE
argument_list|(
name|decl
argument_list|)
operator|==
name|FUNCTION_DECL
operator|&&
name|DECL_INLINE
argument_list|(
name|decl
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|TREE_CODE
argument_list|(
name|decl
argument_list|)
operator|==
name|VAR_DECL
operator|&&
name|TREE_READONLY
argument_list|(
name|decl
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|DECL_IN_SYSTEM_HEADER
argument_list|(
name|decl
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Set the DECL_ASSEMBLER_NAME for DECL.  */
end_comment

begin_function
name|void
name|lhd_set_decl_assembler_name
parameter_list|(
name|tree
name|decl
parameter_list|)
block|{
comment|/* The language-independent code should never use the      DECL_ASSEMBLER_NAME for lots of DECLs.  Only FUNCTION_DECLs and      VAR_DECLs for variables with static storage duration need a real      DECL_ASSEMBLER_NAME.  */
name|gcc_assert
argument_list|(
name|TREE_CODE
argument_list|(
name|decl
argument_list|)
operator|==
name|FUNCTION_DECL
operator|||
operator|(
name|TREE_CODE
argument_list|(
name|decl
argument_list|)
operator|==
name|VAR_DECL
operator|&&
operator|(
name|TREE_STATIC
argument_list|(
name|decl
argument_list|)
operator|||
name|DECL_EXTERNAL
argument_list|(
name|decl
argument_list|)
operator|||
name|TREE_PUBLIC
argument_list|(
name|decl
argument_list|)
operator|)
operator|)
argument_list|)
expr_stmt|;
comment|/* By default, assume the name to use in assembly code is the same      as that used in the source language.  (That's correct for C, and      GCC used to set DECL_ASSEMBLER_NAME to the same value as      DECL_NAME in build_decl, so this choice provides backwards      compatibility with existing front-ends.             Can't use just the variable's own name for a variable whose scope      is less than the whole compilation.  Concatenate a distinguishing      number - we use the DECL_UID.  */
if|if
condition|(
name|TREE_PUBLIC
argument_list|(
name|decl
argument_list|)
operator|||
name|DECL_CONTEXT
argument_list|(
name|decl
argument_list|)
operator|==
name|NULL_TREE
condition|)
name|SET_DECL_ASSEMBLER_NAME
argument_list|(
name|decl
argument_list|,
name|DECL_NAME
argument_list|(
name|decl
argument_list|)
argument_list|)
expr_stmt|;
else|else
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|IDENTIFIER_POINTER
argument_list|(
name|DECL_NAME
argument_list|(
name|decl
argument_list|)
argument_list|)
decl_stmt|;
name|char
modifier|*
name|label
decl_stmt|;
name|ASM_FORMAT_PRIVATE_NAME
argument_list|(
name|label
argument_list|,
name|name
argument_list|,
name|DECL_UID
argument_list|(
name|decl
argument_list|)
argument_list|)
expr_stmt|;
name|SET_DECL_ASSEMBLER_NAME
argument_list|(
name|decl
argument_list|,
name|get_identifier
argument_list|(
name|label
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* By default we always allow bit-field based optimizations.  */
end_comment

begin_function
name|bool
name|lhd_can_use_bit_fields_p
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Type promotion for variable arguments.  */
end_comment

begin_function
name|tree
name|lhd_type_promotes_to
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|type
parameter_list|)
parameter_list|)
block|{
name|gcc_unreachable
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Registration of machine- or os-specific builtin types.  */
end_comment

begin_function
name|void
name|lhd_register_builtin_type
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|type
parameter_list|)
parameter_list|,
specifier|const
name|char
modifier|*
name|ARG_UNUSED
parameter_list|(
name|name
parameter_list|)
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Invalid use of an incomplete type.  */
end_comment

begin_function
name|void
name|lhd_incomplete_type_error
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|value
parameter_list|)
parameter_list|,
name|tree
name|type
parameter_list|)
block|{
name|gcc_assert
argument_list|(
name|TREE_CODE
argument_list|(
name|type
argument_list|)
operator|==
name|ERROR_MARK
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* Provide a default routine for alias sets that always returns -1.  This    is used by languages that don't need to do anything special.  */
end_comment

begin_function
name|HOST_WIDE_INT
name|lhd_get_alias_set
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|t
parameter_list|)
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Provide a hook routine for alias sets that always returns 0.  This is    used by languages that haven't deal with alias sets yet.  */
end_comment

begin_function
name|HOST_WIDE_INT
name|hook_get_alias_set_0
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|t
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* This is the default expand_expr function.  */
end_comment

begin_decl_stmt
name|rtx
name|lhd_expand_expr
argument_list|(
name|tree
name|ARG_UNUSED
argument_list|(
name|t
argument_list|)
argument_list|,
name|rtx
name|ARG_UNUSED
argument_list|(
name|r
argument_list|)
argument_list|,
expr|enum
name|machine_mode
name|ARG_UNUSED
argument_list|(
name|mm
argument_list|)
argument_list|,
name|int
name|ARG_UNUSED
argument_list|(
name|em
argument_list|)
argument_list|,
name|rtx
operator|*
name|ARG_UNUSED
argument_list|(
name|a
argument_list|)
argument_list|)
block|{
name|gcc_unreachable
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/* The default language-specific function for expanding a decl.  After    the language-independent cases are handled, this function will be    called.  If this function is not defined, it is assumed that    declarations other than those for variables and labels do not require    any RTL generation.  */
end_comment

begin_function
name|int
name|lhd_expand_decl
parameter_list|(
name|tree
name|ARG_UNUSED
parameter_list|(
name|t
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* This is the default decl_printable_name function.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|lhd_decl_printable_name
parameter_list|(
name|tree
name|decl
parameter_list|,
name|int
name|ARG_UNUSED
parameter_list|(
name|verbosity
parameter_list|)
parameter_list|)
block|{
name|gcc_assert
argument_list|(
name|decl
operator|&&
name|DECL_NAME
argument_list|(
name|decl
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|IDENTIFIER_POINTER
argument_list|(
name|DECL_NAME
argument_list|(
name|decl
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* This is the default dwarf_name function.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|lhd_dwarf_name
parameter_list|(
name|tree
name|t
parameter_list|,
name|int
name|verbosity
parameter_list|)
block|{
name|gcc_assert
argument_list|(
name|DECL_P
argument_list|(
name|t
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|lang_hooks
operator|.
name|decl_printable_name
argument_list|(
name|t
argument_list|,
name|verbosity
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* This compares two types for equivalence ("compatible" in C-based languages).    This routine should only return 1 if it is sure.  It should not be used    in contexts where erroneously returning 0 causes problems.  */
end_comment

begin_function
name|int
name|lhd_types_compatible_p
parameter_list|(
name|tree
name|x
parameter_list|,
name|tree
name|y
parameter_list|)
block|{
return|return
name|TYPE_MAIN_VARIANT
argument_list|(
name|x
argument_list|)
operator|==
name|TYPE_MAIN_VARIANT
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.walk_subtrees is called by walk_tree()    after handling common cases, but before walking code-specific    sub-trees.  If this hook is overridden for a language, it should    handle language-specific tree codes, as well as language-specific    information associated to common tree codes.  If a tree node is    completely handled within this function, it should set *SUBTREES to    0, so that generic handling isn't attempted.  The generic handling    cannot deal with language-specific tree codes, so make sure it is    set properly.  Both SUBTREES and *SUBTREES is guaranteed to be    nonzero when the function is called.  */
end_comment

begin_function
name|tree
name|lhd_tree_inlining_walk_subtrees
parameter_list|(
name|tree
modifier|*
name|tp
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
modifier|*
name|subtrees
name|ATTRIBUTE_UNUSED
parameter_list|,
name|walk_tree_fn
name|func
name|ATTRIBUTE_UNUSED
parameter_list|,
name|void
modifier|*
name|data
name|ATTRIBUTE_UNUSED
parameter_list|,
name|struct
name|pointer_set_t
modifier|*
name|pset
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL_TREE
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.cannot_inline_tree_fn is called to    determine whether there are language-specific reasons for not    inlining a given function.  */
end_comment

begin_function
name|int
name|lhd_tree_inlining_cannot_inline_tree_fn
parameter_list|(
name|tree
modifier|*
name|fnp
parameter_list|)
block|{
if|if
condition|(
name|flag_really_no_inline
operator|&&
name|lookup_attribute
argument_list|(
literal|"always_inline"
argument_list|,
name|DECL_ATTRIBUTES
argument_list|(
operator|*
name|fnp
argument_list|)
argument_list|)
operator|==
name|NULL
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.disregard_inline_limits is called to    determine whether a function should be considered for inlining even    if it would exceed inlining limits.  */
end_comment

begin_function
name|int
name|lhd_tree_inlining_disregard_inline_limits
parameter_list|(
name|tree
name|fn
parameter_list|)
block|{
if|if
condition|(
name|lookup_attribute
argument_list|(
literal|"always_inline"
argument_list|,
name|DECL_ATTRIBUTES
argument_list|(
name|fn
argument_list|)
argument_list|)
operator|!=
name|NULL
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.add_pending_fn_decls is called before    starting to inline a function, to push any language-specific    functions that should not be inlined into the current function,    into VAFNP.  PFN is the top of varray, and should be returned if no    functions are pushed into VAFNP.  The top of the varray should be    returned.  */
end_comment

begin_function
name|tree
name|lhd_tree_inlining_add_pending_fn_decls
parameter_list|(
name|void
modifier|*
name|vafnp
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|pfn
parameter_list|)
block|{
return|return
name|pfn
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.auto_var_in_fn_p is called to determine    whether VT is an automatic variable defined in function FT.  */
end_comment

begin_function
name|int
name|lhd_tree_inlining_auto_var_in_fn_p
parameter_list|(
name|tree
name|var
parameter_list|,
name|tree
name|fn
parameter_list|)
block|{
return|return
operator|(
name|DECL_P
argument_list|(
name|var
argument_list|)
operator|&&
name|DECL_CONTEXT
argument_list|(
name|var
argument_list|)
operator|==
name|fn
operator|&&
operator|(
operator|(
operator|(
name|TREE_CODE
argument_list|(
name|var
argument_list|)
operator|==
name|VAR_DECL
operator|||
name|TREE_CODE
argument_list|(
name|var
argument_list|)
operator|==
name|PARM_DECL
operator|)
operator|&&
operator|!
name|TREE_STATIC
argument_list|(
name|var
argument_list|)
operator|)
operator|||
name|TREE_CODE
argument_list|(
name|var
argument_list|)
operator|==
name|LABEL_DECL
operator|||
name|TREE_CODE
argument_list|(
name|var
argument_list|)
operator|==
name|RESULT_DECL
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.anon_aggr_type_p determines whether T is a    type node representing an anonymous aggregate (union, struct, etc),    i.e., one whose members are in the same scope as the union itself.  */
end_comment

begin_function
name|int
name|lhd_tree_inlining_anon_aggr_type_p
parameter_list|(
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.start_inlining and end_inlining perform any    language-specific bookkeeping necessary for processing    FN. start_inlining returns nonzero if inlining should proceed, zero if    not.     For instance, the C++ version keeps track of template instantiations to    avoid infinite recursion.  */
end_comment

begin_function
name|int
name|lhd_tree_inlining_start_inlining
parameter_list|(
name|tree
name|fn
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|lhd_tree_inlining_end_inlining
parameter_list|(
name|tree
name|fn
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.convert_parm_for_inlining performs any    language-specific conversion before assigning VALUE to PARM.  */
end_comment

begin_function
name|tree
name|lhd_tree_inlining_convert_parm_for_inlining
parameter_list|(
name|tree
name|parm
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|value
parameter_list|,
name|tree
name|fndecl
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|argnum
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|value
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_dump.dump_tree:  Dump language-specific parts of tree    nodes.  Returns nonzero if it does not want the usual dumping of the    second argument.  */
end_comment

begin_function
name|bool
name|lhd_tree_dump_dump_tree
parameter_list|(
name|void
modifier|*
name|di
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_dump.type_qual:  Determine type qualifiers in a    language-specific way.  */
end_comment

begin_function
name|int
name|lhd_tree_dump_type_quals
parameter_list|(
name|tree
name|t
parameter_list|)
block|{
return|return
name|TYPE_QUALS
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.expr_size: Determine the size of the value of an expression T    in a language-specific way.  Returns a tree for the size in bytes.  */
end_comment

begin_function
name|tree
name|lhd_expr_size
parameter_list|(
name|tree
name|exp
parameter_list|)
block|{
if|if
condition|(
name|DECL_P
argument_list|(
name|exp
argument_list|)
operator|&&
name|DECL_SIZE_UNIT
argument_list|(
name|exp
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|DECL_SIZE_UNIT
argument_list|(
name|exp
argument_list|)
return|;
else|else
return|return
name|size_in_bytes
argument_list|(
name|TREE_TYPE
argument_list|(
name|exp
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.gimplify_expr re-writes *EXPR_P into GIMPLE form.  */
end_comment

begin_function
name|int
name|lhd_gimplify_expr
parameter_list|(
name|tree
modifier|*
name|expr_p
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
modifier|*
name|pre_p
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
modifier|*
name|post_p
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|GS_UNHANDLED
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_size: Determine the size of a tree with code C,    which is a language-specific tree code in category tcc_constant or    tcc_exceptional.  The default expects never to be called.  */
end_comment

begin_function
name|size_t
name|lhd_tree_size
parameter_list|(
name|enum
name|tree_code
name|c
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|gcc_unreachable
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Return true if decl, which is a function decl, may be called by a    sibcall.  */
end_comment

begin_function
name|bool
name|lhd_decl_ok_for_sibcall
parameter_list|(
name|tree
name|decl
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Return the COMDAT group into which DECL should be placed.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|lhd_comdat_group
parameter_list|(
name|tree
name|decl
parameter_list|)
block|{
return|return
name|IDENTIFIER_POINTER
argument_list|(
name|DECL_ASSEMBLER_NAME
argument_list|(
name|decl
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.decls.final_write_globals: perform final processing on    global variables.  */
end_comment

begin_function
name|void
name|write_global_declarations
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Really define vars that have had only a tentative definition.      Really output inline functions that must actually be callable      and have not been output so far.  */
name|tree
name|globals
init|=
name|lang_hooks
operator|.
name|decls
operator|.
name|getdecls
argument_list|()
decl_stmt|;
name|int
name|len
init|=
name|list_length
argument_list|(
name|globals
argument_list|)
decl_stmt|;
name|tree
modifier|*
name|vec
init|=
name|XNEWVEC
argument_list|(
name|tree
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|int
name|i
decl_stmt|;
name|tree
name|decl
decl_stmt|;
comment|/* Process the decls in reverse order--earliest first.      Put them into VEC from back to front, then take out from front.  */
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|decl
operator|=
name|globals
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
operator|,
name|decl
operator|=
name|TREE_CHAIN
argument_list|(
name|decl
argument_list|)
control|)
name|vec
index|[
name|len
operator|-
name|i
operator|-
literal|1
index|]
operator|=
name|decl
expr_stmt|;
name|wrapup_global_declarations
argument_list|(
name|vec
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|check_global_declarations
argument_list|(
name|vec
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|emit_debug_global_declarations
argument_list|(
name|vec
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|/* Clean up.  */
name|free
argument_list|(
name|vec
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Called to perform language-specific initialization of CTX.  */
end_comment

begin_function
name|void
name|lhd_initialize_diagnostics
parameter_list|(
name|struct
name|diagnostic_context
modifier|*
name|ctx
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* The default function to print out name of current function that caused    an error.  */
end_comment

begin_function
name|void
name|lhd_print_error_function
parameter_list|(
name|diagnostic_context
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
block|{
if|if
condition|(
name|diagnostic_last_function_changed
argument_list|(
name|context
argument_list|)
condition|)
block|{
specifier|const
name|char
modifier|*
name|old_prefix
init|=
name|context
operator|->
name|printer
operator|->
name|prefix
decl_stmt|;
name|char
modifier|*
name|new_prefix
init|=
name|file
condition|?
name|file_name_as_prefix
argument_list|(
name|file
argument_list|)
else|:
name|NULL
decl_stmt|;
name|pp_set_prefix
argument_list|(
name|context
operator|->
name|printer
argument_list|,
name|new_prefix
argument_list|)
expr_stmt|;
if|if
condition|(
name|current_function_decl
operator|==
name|NULL
condition|)
name|pp_printf
argument_list|(
name|context
operator|->
name|printer
argument_list|,
name|_
argument_list|(
literal|"At top level:"
argument_list|)
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|TREE_CODE
argument_list|(
name|TREE_TYPE
argument_list|(
name|current_function_decl
argument_list|)
argument_list|)
operator|==
name|METHOD_TYPE
condition|)
name|pp_printf
argument_list|(
name|context
operator|->
name|printer
argument_list|,
name|_
argument_list|(
literal|"In member function %qs:"
argument_list|)
argument_list|,
name|lang_hooks
operator|.
name|decl_printable_name
argument_list|(
name|current_function_decl
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|pp_printf
argument_list|(
name|context
operator|->
name|printer
argument_list|,
name|_
argument_list|(
literal|"In function %qs:"
argument_list|)
argument_list|,
name|lang_hooks
operator|.
name|decl_printable_name
argument_list|(
name|current_function_decl
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|diagnostic_set_last_function
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|pp_flush
argument_list|(
name|context
operator|->
name|printer
argument_list|)
expr_stmt|;
name|context
operator|->
name|printer
operator|->
name|prefix
operator|=
name|old_prefix
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|new_prefix
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|tree
name|lhd_callgraph_analyze_expr
parameter_list|(
name|tree
modifier|*
name|tp
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
modifier|*
name|walk_subtrees
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|decl
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|tree
name|lhd_make_node
parameter_list|(
name|enum
name|tree_code
name|code
parameter_list|)
block|{
return|return
name|make_node
argument_list|(
name|code
argument_list|)
return|;
block|}
end_function

begin_function
name|HOST_WIDE_INT
name|lhd_to_target_charset
parameter_list|(
name|HOST_WIDE_INT
name|c
parameter_list|)
block|{
return|return
name|c
return|;
block|}
end_function

begin_function
name|tree
name|lhd_expr_to_decl
parameter_list|(
name|tree
name|expr
parameter_list|,
name|bool
modifier|*
name|tc
name|ATTRIBUTE_UNUSED
parameter_list|,
name|bool
modifier|*
name|ti
name|ATTRIBUTE_UNUSED
parameter_list|,
name|bool
modifier|*
name|se
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|expr
return|;
block|}
end_function

begin_comment
comment|/* Return sharing kind if OpenMP sharing attribute of DECL is    predetermined, OMP_CLAUSE_DEFAULT_UNSPECIFIED otherwise.  */
end_comment

begin_function
name|enum
name|omp_clause_default_kind
name|lhd_omp_predetermined_sharing
parameter_list|(
name|tree
name|decl
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
if|if
condition|(
name|DECL_ARTIFICIAL
argument_list|(
name|decl
argument_list|)
condition|)
return|return
name|OMP_CLAUSE_DEFAULT_SHARED
return|;
return|return
name|OMP_CLAUSE_DEFAULT_UNSPECIFIED
return|;
block|}
end_function

begin_comment
comment|/* Generate code to copy SRC to DST.  */
end_comment

begin_function
name|tree
name|lhd_omp_assignment
parameter_list|(
name|tree
name|clause
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|dst
parameter_list|,
name|tree
name|src
parameter_list|)
block|{
return|return
name|build2
argument_list|(
name|MODIFY_EXPR
argument_list|,
name|void_type_node
argument_list|,
name|dst
argument_list|,
name|src
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Register language specific type size variables as potentially OpenMP    firstprivate variables.  */
end_comment

begin_function
name|void
name|lhd_omp_firstprivatize_type_sizes
parameter_list|(
name|struct
name|gimplify_omp_ctx
modifier|*
name|c
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* APPLE LOCAL begin radar 6353006  */
end_comment

begin_function
name|tree
name|lhd_build_generic_block_struct_type
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|NULL_TREE
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 6353006  */
end_comment

begin_comment
comment|/* APPLE LOCAL begin radar 6386976  */
end_comment

begin_function
name|bool
name|lhd_is_runtime_specific_type
parameter_list|(
name|tree
name|type
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* APPLE LOCAL end radar 6386976  */
end_comment

end_unit

