begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)chpass.h	5.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|entry
block|{
name|char
modifier|*
name|prompt
decl_stmt|;
name|int
argument_list|(
operator|*
name|func
argument_list|)
argument_list|()
decl_stmt|,
name|restricted
decl_stmt|,
name|len
decl_stmt|;
name|char
modifier|*
name|except
decl_stmt|,
modifier|*
name|save
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|uid_t
name|uid
decl_stmt|;
end_decl_stmt

end_unit

