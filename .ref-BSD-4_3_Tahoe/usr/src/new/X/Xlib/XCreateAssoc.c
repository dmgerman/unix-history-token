begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XCreateAssoc.c,v 10.7 86/12/16 17:12:11 tony Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * XCreateAssocTable - Create an XAssocTable.  The size argument should be  * a power of two for efficiency reasons.  Some size suggestions: use 32  * buckets per 100 objects;  a reasonable maximum number of object per  * buckets is 8.  If there is an error creating the XAssocTable, a NULL  * pointer is returned.  */
end_comment

begin_function
name|XAssocTable
modifier|*
name|XCreateAssocTable
parameter_list|(
name|size
parameter_list|)
specifier|register
name|int
name|size
decl_stmt|;
comment|/* Desired size of the table. */
block|{
specifier|register
name|XAssocTable
modifier|*
name|table
decl_stmt|;
comment|/* XAssocTable to be initialized. */
specifier|register
name|XAssoc
modifier|*
name|buckets
decl_stmt|;
comment|/* Pointer to the first bucket in */
comment|/* the bucket array. */
comment|/* Malloc the XAssocTable. */
if|if
condition|(
operator|(
name|table
operator|=
operator|(
name|XAssocTable
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|XAssocTable
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* Malloc call failed! */
name|errno
operator|=
name|ENOMEM
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* Malloc the buckets (actually just their headers). */
name|buckets
operator|=
operator|(
name|XAssoc
operator|*
operator|)
name|calloc
argument_list|(
name|size
argument_list|,
sizeof|sizeof
argument_list|(
name|XAssoc
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|buckets
operator|==
name|NULL
condition|)
block|{
comment|/* Calloc call failed! */
name|errno
operator|=
name|ENOMEM
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* Insert table data into the XAssocTable structure. */
name|table
operator|->
name|buckets
operator|=
name|buckets
expr_stmt|;
name|table
operator|->
name|size
operator|=
name|size
expr_stmt|;
while|while
condition|(
operator|--
name|size
operator|>=
literal|0
condition|)
block|{
comment|/* Initialize each bucket. */
name|buckets
operator|->
name|prev
operator|=
name|buckets
expr_stmt|;
name|buckets
operator|->
name|next
operator|=
name|buckets
expr_stmt|;
name|buckets
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|table
operator|)
return|;
block|}
end_function

end_unit

