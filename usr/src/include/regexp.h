begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 by University of Toronto.  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Henry Spencer.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)regexp.h	1.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions etc. for regexp(3) routines.  *  * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],  * not the System V one.  */
end_comment

begin_define
define|#
directive|define
name|NSUBEXP
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
name|regexp
block|{
name|char
modifier|*
name|startp
index|[
name|NSUBEXP
index|]
decl_stmt|;
name|char
modifier|*
name|endp
index|[
name|NSUBEXP
index|]
decl_stmt|;
name|char
name|regstart
decl_stmt|;
comment|/* Internal use only. */
name|char
name|reganch
decl_stmt|;
comment|/* Internal use only. */
name|char
modifier|*
name|regmust
decl_stmt|;
comment|/* Internal use only. */
name|int
name|regmlen
decl_stmt|;
comment|/* Internal use only. */
name|char
name|program
index|[
literal|1
index|]
decl_stmt|;
comment|/* Unwarranted chumminess with compiler. */
block|}
name|regexp
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|regexp
modifier|*
name|regcomp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|regexec
parameter_list|(
specifier|const
name|regexp
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regsub
parameter_list|(
specifier|const
name|regexp
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|regexp
modifier|*
name|regcomp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|regexec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regerror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

