begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)redir.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* flags passed to redirect */
end_comment

begin_define
define|#
directive|define
name|REDIR_PUSH
value|01
end_define

begin_comment
comment|/* save previous values of file descriptors */
end_comment

begin_define
define|#
directive|define
name|REDIR_BACKQ
value|02
end_define

begin_comment
comment|/* save the command output in memory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_union_decl
union_decl|union
name|node
union_decl|;
end_union_decl

begin_function_decl
name|void
name|redirect
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|popredir
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clearredir
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyfd
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fd0_redirected_p
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
name|void
name|redirect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|popredir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clearredir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyfd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fd0_redirected_p
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

