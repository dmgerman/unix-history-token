begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XGetFProp.c,v 11.7 91/01/06 11:45:56 rws Exp $ */
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

begin_function
name|Bool
name|XGetFontProperty
parameter_list|(
name|fs
parameter_list|,
name|name
parameter_list|,
name|valuePtr
parameter_list|)
name|XFontStruct
modifier|*
name|fs
decl_stmt|;
specifier|register
name|Atom
name|name
decl_stmt|;
name|unsigned
name|long
modifier|*
name|valuePtr
decl_stmt|;
block|{
comment|/* XXX this is a simple linear search for now.  If the       protocol is changed to sort the property list, this should       become a binary search. */
specifier|register
name|XFontProp
modifier|*
name|prop
init|=
name|fs
operator|->
name|properties
decl_stmt|;
specifier|register
name|XFontProp
modifier|*
name|last
init|=
name|prop
operator|+
name|fs
operator|->
name|n_properties
decl_stmt|;
while|while
condition|(
name|prop
operator|!=
name|last
condition|)
block|{
if|if
condition|(
name|prop
operator|->
name|name
operator|==
name|name
condition|)
block|{
operator|*
name|valuePtr
operator|=
name|prop
operator|->
name|card32
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|prop
operator|++
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

