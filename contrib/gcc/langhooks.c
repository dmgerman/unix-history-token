begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default language-specific hooks.    Copyright 2001 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"c-tree.h"
end_include

begin_include
include|#
directive|include
file|"tree-inline.h"
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
file|"langhooks.h"
end_include

begin_include
include|#
directive|include
file|"langhooks-def.h"
end_include

begin_comment
comment|/* Do nothing; in many cases the default hook.  */
end_comment

begin_function
name|void
name|lhd_do_nothing
parameter_list|()
block|{ }
end_function

begin_comment
comment|/* Do nothing (return the tree node passed).  */
end_comment

begin_function
name|tree
name|lhd_return_tree
parameter_list|(
name|t
parameter_list|)
name|tree
name|t
decl_stmt|;
block|{
return|return
name|t
return|;
block|}
end_function

begin_comment
comment|/* Do nothing; the default hook to decode an option.  */
end_comment

begin_function
name|int
name|lhd_decode_option
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
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
name|file
parameter_list|,
name|node
parameter_list|,
name|indent
parameter_list|)
name|FILE
modifier|*
name|file
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|tree
name|node
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|int
name|indent
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/* Called from safe_from_p.  */
end_comment

begin_function
name|int
name|lhd_safe_from_p
parameter_list|(
name|x
parameter_list|,
name|exp
parameter_list|)
name|rtx
name|x
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|tree
name|exp
name|ATTRIBUTE_UNUSED
decl_stmt|;
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
name|int
name|lhd_staticp
parameter_list|(
name|exp
parameter_list|)
name|tree
name|exp
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Called when -dy is given on the command line.  */
end_comment

begin_function
name|void
name|lhd_set_yydebug
parameter_list|(
name|value
parameter_list|)
name|int
name|value
decl_stmt|;
block|{
if|if
condition|(
name|value
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"warning: no yacc/bison-generated output to debug!\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Provide a default routine to clear the binding stack.  This is used    by languages that don't need to do anything special.  */
end_comment

begin_function
name|void
name|lhd_clear_binding_stack
parameter_list|()
block|{
while|while
condition|(
operator|!
name|global_bindings_p
argument_list|()
condition|)
name|poplevel
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Provide a default routine for alias sets that always returns -1.  This    is used by languages that don't need to do anything special.  */
end_comment

begin_function
name|HOST_WIDE_INT
name|lhd_get_alias_set
parameter_list|(
name|t
parameter_list|)
name|tree
name|t
name|ATTRIBUTE_UNUSED
decl_stmt|;
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
name|t
parameter_list|)
name|tree
name|t
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.walk_subtrees is called by walk_tree()    after handling common cases, but before walking code-specific    sub-trees.  If this hook is overridden for a language, it should    handle language-specific tree codes, as well as language-specific    information associated to common tree codes.  If a tree node is    completely handled within this function, it should set *SUBTREES to    0, so that generic handling isn't attempted.  For language-specific    tree codes, generic handling would abort(), so make sure it is set    properly.  Both SUBTREES and *SUBTREES is guaranteed to be non-zero    when the function is called.  */
end_comment

begin_function
name|tree
name|lhd_tree_inlining_walk_subtrees
parameter_list|(
name|tp
parameter_list|,
name|subtrees
parameter_list|,
name|func
parameter_list|,
name|data
parameter_list|,
name|htab
parameter_list|)
name|tree
modifier|*
name|tp
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|int
modifier|*
name|subtrees
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|walk_tree_fn
name|func
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|void
modifier|*
name|data
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|void
modifier|*
name|htab
name|ATTRIBUTE_UNUSED
decl_stmt|;
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
name|fnp
parameter_list|)
name|tree
modifier|*
name|fnp
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
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
name|fn
parameter_list|)
name|tree
name|fn
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
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
name|vafnp
parameter_list|,
name|pfn
parameter_list|)
name|void
modifier|*
name|vafnp
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|tree
name|pfn
decl_stmt|;
block|{
return|return
name|pfn
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.tree_chain_matters_p indicates whether the    TREE_CHAIN of a language-specific tree node is relevant, i.e.,    whether it should be walked, copied and preserved across copies.  */
end_comment

begin_function
name|int
name|lhd_tree_inlining_tree_chain_matters_p
parameter_list|(
name|t
parameter_list|)
name|tree
name|t
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
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
name|var
parameter_list|,
name|fn
parameter_list|)
name|tree
name|var
decl_stmt|,
name|fn
decl_stmt|;
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
comment|/* lang_hooks.tree_inlining.copy_res_decl_for_inlining should return a    declaration for the result RES of function FN to be inlined into    CALLER.  NDP points to an integer that should be set in case a new    declaration wasn't created (presumably because RES was of aggregate    type, such that a TARGET_EXPR is used for the result).  TEXPS is a    pointer to a varray with the stack of TARGET_EXPRs seen while    inlining functions into caller; the top of TEXPS is supposed to    match RES.  */
end_comment

begin_function
name|tree
name|lhd_tree_inlining_copy_res_decl_for_inlining
parameter_list|(
name|res
parameter_list|,
name|fn
parameter_list|,
name|caller
parameter_list|,
name|dm
parameter_list|,
name|ndp
parameter_list|,
name|texps
parameter_list|)
name|tree
name|res
decl_stmt|,
name|fn
decl_stmt|,
name|caller
decl_stmt|;
name|void
modifier|*
name|dm
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|int
modifier|*
name|ndp
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|void
modifier|*
name|texps
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
name|copy_decl_for_inlining
argument_list|(
name|res
argument_list|,
name|fn
argument_list|,
name|caller
argument_list|)
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
name|t
parameter_list|)
name|tree
name|t
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_inlining.start_inlining and end_inlining perform any    language-specific bookkeeping necessary for processing    FN. start_inlining returns non-zero if inlining should proceed, zero if    not.     For instance, the C++ version keeps track of template instantiations to    avoid infinite recursion.  */
end_comment

begin_function
name|int
name|lhd_tree_inlining_start_inlining
parameter_list|(
name|fn
parameter_list|)
name|tree
name|fn
name|ATTRIBUTE_UNUSED
decl_stmt|;
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
name|fn
parameter_list|)
name|tree
name|fn
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/* lang_hooks.tree_dump.dump_tree:  Dump language-specific parts of tree     nodes.  Returns non-zero if it does not want the usual dumping of the     second argument.  */
end_comment

begin_function
name|int
name|lhd_tree_dump_dump_tree
parameter_list|(
name|di
parameter_list|,
name|t
parameter_list|)
name|void
modifier|*
name|di
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|tree
name|t
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* lang_hooks.tree_dump.type_qual:  Determine type qualifiers in a     language-specific way.  */
end_comment

begin_function
name|int
name|lhd_tree_dump_type_quals
parameter_list|(
name|t
parameter_list|)
name|tree
name|t
decl_stmt|;
block|{
return|return
name|TYPE_QUALS
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

end_unit

