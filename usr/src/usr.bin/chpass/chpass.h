begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)chpass.h	5.2 (Berkeley) %G%  */
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

