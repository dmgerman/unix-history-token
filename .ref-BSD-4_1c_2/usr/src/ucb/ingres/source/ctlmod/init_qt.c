begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ctlmod.h"
end_include

begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)init_qt.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  INIT_QT -- initialize query tree ** **	This routine saves and initializes the global portion **	of a query tree.  It must be called before doing any **	creation of a query tree which depends on or modifies **	the global portion of a query tree. ** **	The global portion of a query tree includes the range **	table, the query mode, etc. ** **	The algorithm for saving the query tree global portion **	("Qt") is somewhat obscure.  To understand it, it is **	critical to be clear that every query tree is associated **	with a context, but not every context is associated with **	a query tree.  We further constrain that a context **	is associated with at most one query tree; if more than **	one is needed in a single context, it is always safe **	to reuse the previous one. ** **	When we allocate a new context (in 'initp'), the current **	Qt (if in use) is associated with the save image of the **	context.  When we call init_qt, we check to see if such **	an association exists.  If so, we save Qt, and adjust **	the old context to point to the save image of Qt.  When **	we call init_qt again, Qt will be active, but not **	associated with a context save image; thus, we do not **	save Qt.  On context restore, if it has a pointer to a **	saved Qt, we restore that also. ** **	Parameters: **		none. **	 **	Returns: **		none **	 **	Side Effects: **		Qt possibly gets saved in an area set up by **			calling malloc. **	 **	Trace Flags: **		none */
end_comment

begin_macro
name|init_qt
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
comment|/* 	**  Save Qt if associated with a saved context. 	*/
if|if
condition|(
name|Qt
operator|.
name|qt_ctx
operator|!=
name|NULL
condition|)
block|{
name|p
operator|=
name|malloc
argument_list|(
sizeof|sizeof
name|Qt
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
name|syserr
argument_list|(
literal|"init_qt: no mem"
argument_list|)
expr_stmt|;
name|bmove
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|Qt
argument_list|,
name|p
argument_list|,
sizeof|sizeof
name|Qt
argument_list|)
expr_stmt|;
operator|(
operator|(
name|ctx_t
operator|*
operator|)
name|Qt
operator|.
name|qt_ctx
operator|)
operator|->
name|ctx_qt
operator|=
name|p
expr_stmt|;
name|Qt
operator|.
name|qt_ctx
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* mark the Qt as active */
name|Qt
operator|.
name|qt_active
operator|++
expr_stmt|;
block|}
end_block

end_unit

