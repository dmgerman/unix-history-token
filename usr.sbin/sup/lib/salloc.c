begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  **********************************************************************  * HISTORY  * 09-Apr-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Changed to save length and use bcopy instead of strcpy.  *  * 02-Nov-85  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Created from routine by same name in Steve Shafer's sup program.  *  **********************************************************************  */
end_comment

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|salloc
parameter_list|(
name|p
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|q
decl_stmt|;
specifier|register
name|int
name|l
decl_stmt|;
name|q
operator|=
name|malloc
argument_list|(
name|l
operator|=
name|strlen
argument_list|(
name|p
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|!=
literal|0
condition|)
name|bcopy
argument_list|(
name|p
argument_list|,
name|q
argument_list|,
name|l
argument_list|)
expr_stmt|;
return|return
operator|(
name|q
operator|)
return|;
block|}
end_function

end_unit

