begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)qsort_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * quick sort interface  *  * calling sequence:  *	external compar  *	call qsort (array, len, isize, compar)  *	----  *	integer*2 function compar (obj1, obj2)  * where:  *	array contains the elements to be sorted  *	len is the number of elements in the array  *	isize is the size of an element, typically -  *		4 for integer, float  *		8 for double precision  *		(length of character object) for character arrays  *	compar is the name of an integer*2 function that will return -  *<0 if object 1 is logically less than object 2  *		=0 if object 1 is logically equal to object 2  *>0 if object 1 is logically greater than object 2  */
end_comment

begin_macro
name|qsort_
argument_list|(
argument|array
argument_list|,
argument|len
argument_list|,
argument|isize
argument_list|,
argument|compar
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|len
decl_stmt|,
modifier|*
name|isize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
modifier|*
name|array
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|compar
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* may be problematical */
end_comment

begin_block
block|{
name|qsort
argument_list|(
name|array
argument_list|,
operator|(
name|int
operator|)
operator|*
name|len
argument_list|,
operator|(
name|int
operator|)
operator|*
name|isize
argument_list|,
name|compar
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

