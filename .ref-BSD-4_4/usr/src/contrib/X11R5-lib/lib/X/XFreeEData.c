begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XFreeEData.c,v 11.13 91/01/06 11:45:47 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1986	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_macro
name|_XFreeExtData
argument_list|(
argument|extension
argument_list|)
end_macro

begin_decl_stmt
name|XExtData
modifier|*
name|extension
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|XExtData
modifier|*
name|temp
decl_stmt|;
while|while
condition|(
name|extension
condition|)
block|{
if|if
condition|(
name|extension
operator|->
name|free_private
condition|)
call|(
modifier|*
name|extension
operator|->
name|free_private
call|)
argument_list|(
name|extension
argument_list|)
expr_stmt|;
else|else
name|Xfree
argument_list|(
operator|(
name|char
operator|*
operator|)
name|extension
operator|->
name|private_data
argument_list|)
expr_stmt|;
name|temp
operator|=
name|extension
operator|->
name|next
expr_stmt|;
name|Xfree
argument_list|(
operator|(
name|char
operator|*
operator|)
name|extension
argument_list|)
expr_stmt|;
name|extension
operator|=
name|temp
expr_stmt|;
block|}
return|return;
block|}
end_block

end_unit

