begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)input.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* PEOF (the end of file marker) is defined in syntax.h */
end_comment

begin_comment
comment|/*  * The input line number.  Input.c just defines this variable, and saves  * and restores it when files are pushed and popped.  The user of this  * package must set its value.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|plinno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parsenleft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of characters left in input buffer */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|parsenextc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next character in input buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|init_editline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 == not setup, 1 == OK, -1 == failed */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pfgets
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pgetc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|preadbuffer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pungetc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushstring
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|popstring
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setinputfile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setinputfd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setinputstring
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|popfile
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|popallfiles
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|closescript
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pgetc_macro
parameter_list|()
value|(--parsenleft>= 0? *parsenextc++ : preadbuffer())
end_define

end_unit

