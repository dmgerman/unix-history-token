begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)input.h	8.1 (Berkeley) %G%  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|char
modifier|*
name|pfgets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pgetc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|preadbuffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pungetc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pushstring
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinputfile
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinputfd
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinputstring
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|popfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|popallfiles
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closescript
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|pfgets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pgetc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|preadbuffer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pungetc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinputfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinputfd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinputstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|popfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|popallfiles
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pushstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closescript
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pgetc_macro
parameter_list|()
value|(--parsenleft>= 0? *parsenextc++ : preadbuffer())
end_define

end_unit

