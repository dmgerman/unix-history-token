begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)chpass.h	5.3 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_entry
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
name|ENTRY
typedef|;
end_typedef

begin_comment
comment|/* Field numbers. */
end_comment

begin_define
define|#
directive|define
name|E_BPHONE
value|8
end_define

begin_define
define|#
directive|define
name|E_HPHONE
value|9
end_define

begin_define
define|#
directive|define
name|E_LOCATE
value|10
end_define

begin_define
define|#
directive|define
name|E_NAME
value|7
end_define

begin_define
define|#
directive|define
name|E_SHELL
value|12
end_define

begin_decl_stmt
specifier|extern
name|ENTRY
name|list
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uid_t
name|uid
decl_stmt|;
end_decl_stmt

end_unit

