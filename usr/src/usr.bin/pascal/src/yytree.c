begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)yytree.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|spacep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * LIST MANIPULATION ROUTINES  *  * The grammar for Pascal is written left recursively.  * Because of this, the portions of parse trees which are to resemble  * lists are in the somewhat inconvenient position of having  * the nodes built from left to right, while we want to eventually  * have as semantic value the leftmost node.  * We could carry the leftmost node as semantic value, but this  * would be inefficient as to add a new node to the list we would  * have to chase down to the end.  Other solutions involving a head  * and tail pointer waste space.  *  * The simple solution to this apparent dilemma is to carry along  * a pointer to the leftmost node in a list in the rightmost node  * which is the current semantic value of the list.  * When we have completed building the list, we can retrieve this  * left end pointer very easily; neither adding new elements to the list  * nor finding the left end is thus expensive.  As the bottommost node  * has an unused next pointer in it, no space is wasted either.  *  * The nodes referred to here are of the T_LISTPP type and have  * the form:  *  *	T_LISTPP	some_pointer		next_element  *  * Here some_pointer points to the things of interest in the list,  * and next_element to the next thing in the list except for the  * rightmost node, in which case it points to the leftmost node.  * The next_element of the rightmost node is of course zapped to the  * NIL pointer when the list is completed.  *  * Thinking of the lists as tree we heceforth refer to the leftmost  * node as the "top", and the rightmost node as the "bottom" or as  * the "virtual root".  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * Make a new list  */
end_comment

begin_expr_stmt
name|newlist
argument_list|(
name|new
argument_list|)
specifier|register
name|int
operator|*
name|new
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|new
operator|==
name|NIL
condition|)
return|return
operator|(
name|NIL
operator|)
return|;
return|return
operator|(
name|tree3
argument_list|(
name|T_LISTPP
argument_list|,
name|new
argument_list|,
name|spacep
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Add a new element to an existing list  */
end_comment

begin_expr_stmt
name|addlist
argument_list|(
name|vroot
argument_list|,
name|new
argument_list|)
specifier|register
name|int
operator|*
name|vroot
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
modifier|*
name|new
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
modifier|*
name|top
decl_stmt|;
if|if
condition|(
name|new
operator|==
name|NIL
condition|)
return|return
operator|(
name|vroot
operator|)
return|;
if|if
condition|(
name|vroot
operator|==
name|NIL
condition|)
return|return
operator|(
name|newlist
argument_list|(
name|new
argument_list|)
operator|)
return|;
name|top
operator|=
name|vroot
index|[
literal|2
index|]
expr_stmt|;
name|vroot
index|[
literal|2
index|]
operator|=
name|spacep
expr_stmt|;
return|return
operator|(
name|tree3
argument_list|(
name|T_LISTPP
argument_list|,
name|new
argument_list|,
name|top
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Fix up the list which has virtual root vroot.  * We grab the top pointer and return it, zapping the spot  * where it was so that the tree is not circular.  */
end_comment

begin_expr_stmt
name|fixlist
argument_list|(
name|vroot
argument_list|)
specifier|register
name|int
operator|*
name|vroot
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
modifier|*
name|top
decl_stmt|;
if|if
condition|(
name|vroot
operator|==
name|NIL
condition|)
return|return
operator|(
name|NIL
operator|)
return|;
name|top
operator|=
name|vroot
index|[
literal|2
index|]
expr_stmt|;
name|vroot
index|[
literal|2
index|]
operator|=
name|NIL
expr_stmt|;
return|return
operator|(
name|top
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  * Set up a T_VAR node for a qualified variable.  * Init is the initial entry in the qualification,  * or NIL if there is none.  *  * if we are building pTrees, there has to be an extra slot for   * a pointer to the namelist entry of a field, if this T_VAR refers  * to a field name within a WITH statement.  * this extra field is set in lvalue, and used in VarCopy.  */
end_comment

begin_macro
name|setupvar
argument_list|(
argument|var
argument_list|,
argument|init
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|var
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
modifier|*
name|init
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|init
operator|!=
name|NIL
condition|)
name|init
operator|=
name|newlist
argument_list|(
name|init
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|PTREE
return|return
operator|(
name|tree4
argument_list|(
name|T_VAR
argument_list|,
name|NOCON
argument_list|,
name|var
argument_list|,
name|init
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
name|tree5
argument_list|(
name|T_VAR
argument_list|,
name|NOCON
argument_list|,
name|var
argument_list|,
name|init
argument_list|,
name|NIL
argument_list|)
return|;
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/*      *	set up a T_TYREC node for a record      *      *	if we are building pTrees, there has to be an extra slot for       *	a pointer to the namelist entry of the record.      *	this extra field is filled in in gtype, and used in RecTCopy.      */
end_comment

begin_macro
name|setuptyrec
argument_list|(
argument|line
argument_list|,
argument|fldlst
argument_list|)
end_macro

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|fldlst
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifndef|#
directive|ifndef
name|PTREE
return|return
name|tree3
argument_list|(
name|T_TYREC
argument_list|,
name|line
argument_list|,
name|fldlst
argument_list|)
return|;
else|#
directive|else
return|return
name|tree4
argument_list|(
name|T_TYREC
argument_list|,
name|line
argument_list|,
name|fldlst
argument_list|,
name|NIL
argument_list|)
return|;
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/*      *	set up a T_FIELD node for a field.      *      *	if we are building pTrees, there has to be an extra slot for      *	a pointer to the namelist entry of the field.      *	this extra field is set in lvalue, and used in SelCopy.      */
end_comment

begin_macro
name|setupfield
argument_list|(
argument|field
argument_list|,
argument|other
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|field
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|other
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifndef|#
directive|ifndef
name|PTREE
return|return
name|tree3
argument_list|(
name|T_FIELD
argument_list|,
name|field
argument_list|,
name|other
argument_list|)
return|;
else|#
directive|else
return|return
name|tree4
argument_list|(
name|T_FIELD
argument_list|,
name|field
argument_list|,
name|other
argument_list|,
name|NIL
argument_list|)
return|;
endif|#
directive|endif
block|}
end_block

end_unit

