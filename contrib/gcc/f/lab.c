begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lab.c -- Implementation File (module.c template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Related Modules:     Description:       Complex data abstraction for Fortran labels.  Maintains a single master       list for all labels; it is expected initialization and termination of       this list will occur on program-unit boundaries.     Modifications:       22-Aug-89	 JCB  1.1 	 Change ffelab_new for new ffewhere interface. */
end_comment

begin_comment
comment|/* Include files. */
end_comment

begin_include
include|#
directive|include
file|"proj.h"
end_include

begin_include
include|#
directive|include
file|"lab.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_comment
comment|/* Externals defined here. */
end_comment

begin_decl_stmt
name|ffelab
name|ffelab_list_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ffelabNumber
name|ffelab_num_news_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Internal typedefs. */
end_comment

begin_comment
comment|/* Private include files. */
end_comment

begin_comment
comment|/* Internal structure definitions. */
end_comment

begin_comment
comment|/* Static objects accessed by functions in this module. */
end_comment

begin_comment
comment|/* Static functions (internal). */
end_comment

begin_comment
comment|/* Internal macros. */
end_comment

begin_escape
end_escape

begin_comment
comment|/* ffelab_find -- Find the ffelab object having the desired label value     ffelab l;    ffelabValue v;    l = ffelab_find(v);     If the desired ffelab object doesn't exist, returns NULL.     Straightforward search of list of ffelabs.  */
end_comment

begin_function
name|ffelab
name|ffelab_find
parameter_list|(
name|ffelabValue
name|v
parameter_list|)
block|{
name|ffelab
name|l
decl_stmt|;
for|for
control|(
name|l
operator|=
name|ffelab_list_
init|;
operator|(
name|l
operator|!=
name|NULL
operator|)
operator|&&
operator|(
name|ffelab_value
argument_list|(
name|l
argument_list|)
operator|!=
name|v
operator|)
condition|;
name|l
operator|=
name|l
operator|->
name|next
control|)
empty_stmt|;
return|return
name|l
return|;
block|}
end_function

begin_comment
comment|/* ffelab_finish -- Shut down label management     ffelab_finish();     At the end of processing a program unit, call this routine to shut down    label management.     Kill all the labels on the list.  */
end_comment

begin_function
name|void
name|ffelab_finish
parameter_list|()
block|{
name|ffelab
name|l
decl_stmt|;
name|ffelab
name|pl
decl_stmt|;
for|for
control|(
name|pl
operator|=
name|NULL
operator|,
name|l
operator|=
name|ffelab_list_
init|;
name|l
operator|!=
name|NULL
condition|;
name|pl
operator|=
name|l
operator|,
name|l
operator|=
name|l
operator|->
name|next
control|)
if|if
condition|(
name|pl
operator|!=
name|NULL
condition|)
name|malloc_kill_ks
argument_list|(
name|ffe_pool_any_unit
argument_list|()
argument_list|,
name|pl
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|pl
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|pl
operator|!=
name|NULL
condition|)
name|malloc_kill_ks
argument_list|(
name|ffe_pool_any_unit
argument_list|()
argument_list|,
name|pl
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|pl
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffelab_init_3 -- Initialize label management system     ffelab_init_3();     Initialize the label management system.  Do this before a new program    unit is going to be processed.  */
end_comment

begin_function
name|void
name|ffelab_init_3
parameter_list|()
block|{
name|ffelab_list_
operator|=
name|NULL
expr_stmt|;
name|ffelab_num_news_
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffelab_new -- Create an ffelab object.     ffelab l;    ffelabValue v;    l = ffelab_new(v);     Create a label having a given value.	 If the value isn't known, pass    FFELAB_valueNONE, and set it later with ffelab_set_value.     Allocate, initialize, and stick at top of label list.     22-Aug-89  JCB  1.1       Change for new ffewhere interface.  */
end_comment

begin_function
name|ffelab
name|ffelab_new
parameter_list|(
name|ffelabValue
name|v
parameter_list|)
block|{
name|ffelab
name|l
decl_stmt|;
operator|++
name|ffelab_num_news_
expr_stmt|;
name|l
operator|=
operator|(
name|ffelab
operator|)
name|malloc_new_ks
argument_list|(
name|ffe_pool_any_unit
argument_list|()
argument_list|,
literal|"FFELAB label"
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|l
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|next
operator|=
name|ffelab_list_
expr_stmt|;
ifdef|#
directive|ifdef
name|FFECOM_labelHOOK
name|l
operator|->
name|hook
operator|=
name|FFECOM_labelNULL
expr_stmt|;
endif|#
directive|endif
name|l
operator|->
name|value
operator|=
name|v
expr_stmt|;
name|l
operator|->
name|firstref_line
operator|=
name|ffewhere_line_unknown
argument_list|()
expr_stmt|;
name|l
operator|->
name|firstref_col
operator|=
name|ffewhere_column_unknown
argument_list|()
expr_stmt|;
name|l
operator|->
name|doref_line
operator|=
name|ffewhere_line_unknown
argument_list|()
expr_stmt|;
name|l
operator|->
name|doref_col
operator|=
name|ffewhere_column_unknown
argument_list|()
expr_stmt|;
name|l
operator|->
name|definition_line
operator|=
name|ffewhere_line_unknown
argument_list|()
expr_stmt|;
name|l
operator|->
name|definition_col
operator|=
name|ffewhere_column_unknown
argument_list|()
expr_stmt|;
name|l
operator|->
name|type
operator|=
name|FFELAB_typeUNKNOWN
expr_stmt|;
name|ffelab_list_
operator|=
name|l
expr_stmt|;
return|return
name|l
return|;
block|}
end_function

end_unit

