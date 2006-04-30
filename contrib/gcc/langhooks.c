begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default language-specific hooks.    Copyright 2001, 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|t
name|ATTRIBUTE_UNUSED
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
name|i
name|ATTRIBUTE_UNUSED
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
name|i
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|j
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|k
name|ATTRIBUTE_UNUSED
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

begin_function
name|void
name|lhd_do_nothing_f
parameter_list|(
name|struct
name|function
modifier|*
name|f
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

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
name|t
name|ATTRIBUTE_UNUSED
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
name|pfilename
name|ATTRIBUTE_UNUSED
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
name|file
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|node
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|indent
name|ATTRIBUTE_UNUSED
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
name|x
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|exp
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Called from unsafe_for_reeval.  */
end_comment

begin_function
name|int
name|lhd_unsafe_for_reeval
parameter_list|(
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
operator|-
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
name|tree
name|exp
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
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
comment|/* Number for making the label on the next    static variable internal to a function.  */
end_comment

begin_expr_stmt
specifier|static
name|GTY
argument_list|(
argument|()
argument_list|)
name|int
name|var_labelno
expr_stmt|;
end_expr_stmt

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
if|if
condition|(
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
condition|)
block|{
comment|/* By default, assume the name to use in assembly code is the 	 same as that used in the source language.  (That's correct 	 for C, and GCC used to set DECL_ASSEMBLER_NAME to the same 	 value as DECL_NAME in build_decl, so this choice provides 	 backwards compatibility with existing front-ends.             Can't use just the variable's own name for a variable whose 	 scope is less than the whole compilation.  Concatenate a 	 distinguishing number.  */
if|if
condition|(
operator|!
name|TREE_PUBLIC
argument_list|(
name|decl
argument_list|)
operator|&&
name|DECL_CONTEXT
argument_list|(
name|decl
argument_list|)
condition|)
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
name|var_labelno
argument_list|)
expr_stmt|;
name|var_labelno
operator|++
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
else|else
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
block|}
else|else
comment|/* Nobody should ever be asking for the DECL_ASSEMBLER_NAME of        these DECLs -- unless they're in language-dependent code, in        which case set_decl_assembler_name hook should handle things.  */
name|abort
argument_list|()
expr_stmt|;
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
comment|/* Provide a default routine to clear the binding stack.  This is used    by languages that don't need to do anything special.  */
end_comment

begin_function
name|void
name|lhd_clear_binding_stack
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
operator|!
call|(
modifier|*
name|lang_hooks
operator|.
name|decls
operator|.
name|global_bindings_p
call|)
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
comment|/* Type promotion for variable arguments.  */
end_comment

begin_function
name|tree
name|lhd_type_promotes_to
parameter_list|(
name|tree
name|type
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|abort
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
name|type
name|ATTRIBUTE_UNUSED
parameter_list|,
specifier|const
name|char
modifier|*
name|name
name|ATTRIBUTE_UNUSED
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
name|value
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|type
parameter_list|)
block|{
if|if
condition|(
name|TREE_CODE
argument_list|(
name|type
argument_list|)
operator|==
name|ERROR_MARK
condition|)
return|return;
name|abort
argument_list|()
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
name|tree
name|t
name|ATTRIBUTE_UNUSED
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
comment|/* This is the default expand_expr function.  */
end_comment

begin_function
name|rtx
name|lhd_expand_expr
parameter_list|(
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|,
name|rtx
name|r
name|ATTRIBUTE_UNUSED
parameter_list|,
name|enum
name|machine_mode
name|mm
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|em
name|ATTRIBUTE_UNUSED
parameter_list|,
name|rtx
modifier|*
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|abort
argument_list|()
expr_stmt|;
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
name|verbosity
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
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
comment|/* lang_hooks.tree_inlining.walk_subtrees is called by walk_tree()    after handling common cases, but before walking code-specific    sub-trees.  If this hook is overridden for a language, it should    handle language-specific tree codes, as well as language-specific    information associated to common tree codes.  If a tree node is    completely handled within this function, it should set *SUBTREES to    0, so that generic handling isn't attempted.  For language-specific    tree codes, generic handling would abort(), so make sure it is set    properly.  Both SUBTREES and *SUBTREES is guaranteed to be nonzero    when the function is called.  */
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
name|void
modifier|*
name|htab
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
comment|/* lang_hooks.tree_inlining.tree_chain_matters_p indicates whether the    TREE_CHAIN of a language-specific tree node is relevant, i.e.,    whether it should be walked, copied and preserved across copies.  */
end_comment

begin_function
name|int
name|lhd_tree_inlining_tree_chain_matters_p
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
comment|/* lang_hooks.tree_inlining.copy_res_decl_for_inlining should return a    declaration for the result RES of function FN to be inlined into    CALLER.  NDP points to an integer that should be set in case a new    declaration wasn't created (presumably because RES was of aggregate    type, such that a TARGET_EXPR is used for the result).  TEXPS is a    pointer to a varray with the stack of TARGET_EXPRs seen while    inlining functions into caller; the top of TEXPS is supposed to    match RES.  */
end_comment

begin_function
name|tree
name|lhd_tree_inlining_copy_res_decl_for_inlining
parameter_list|(
name|tree
name|res
parameter_list|,
name|tree
name|fn
parameter_list|,
name|tree
name|caller
parameter_list|,
name|void
modifier|*
name|dm
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
modifier|*
name|ndp
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|return_slot_addr
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
if|if
condition|(
name|return_slot_addr
condition|)
return|return
name|build1
argument_list|(
name|INDIRECT_REF
argument_list|,
name|TREE_TYPE
argument_list|(
name|TREE_TYPE
argument_list|(
name|return_slot_addr
argument_list|)
argument_list|)
argument_list|,
name|return_slot_addr
argument_list|)
return|;
else|else
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
name|TREE_CODE_CLASS
argument_list|(
name|TREE_CODE
argument_list|(
name|exp
argument_list|)
argument_list|)
operator|==
literal|'d'
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
comment|/* lang_hooks.decl_uninit: Find out if a variable is uninitialized based    on DECL_INITIAL.  */
end_comment

begin_function
name|bool
name|lhd_decl_uninit
parameter_list|(
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
comment|/* lang_hooks.tree_size: Determine the size of a tree with code C,    which is a language-specific tree code in category 'x'.  The    default expects never to be called.  */
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
name|abort
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
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
call|(
modifier|*
name|lang_hooks
operator|.
name|decls
operator|.
name|getdecls
call|)
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
name|xmalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|tree
argument_list|)
operator|*
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
literal|"At top level:"
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
literal|"In member function `%s':"
argument_list|,
call|(
modifier|*
name|lang_hooks
operator|.
name|decl_printable_name
call|)
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
literal|"In function `%s':"
argument_list|,
call|(
modifier|*
name|lang_hooks
operator|.
name|decl_printable_name
call|)
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

begin_include
include|#
directive|include
file|"gt-langhooks.h"
end_include

end_unit

