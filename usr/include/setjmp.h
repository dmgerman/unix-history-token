begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)setjmp.h	5.2 (Berkeley) 5/29/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SETJMP_
end_ifndef

begin_define
define|#
directive|define
name|_SETJMP_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * sigsetjmp/siglongjmp use the first int to decide if the  * signal mask was saved or not.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|sigjmp_buf
index|[
name|_JBLEN
operator|+
literal|1
index|]
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_typedef
typedef|typedef
name|int
name|jmp_buf
index|[
name|_JBLEN
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|int
name|sigsetjmp
parameter_list|(
name|sigjmp_buf
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siglongjmp
parameter_list|(
name|sigjmp_buf
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_function_decl
specifier|extern
name|int
name|setjmp
parameter_list|(
name|jmp_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_setjmp
parameter_list|(
name|jmp_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|longjmp
parameter_list|(
name|jmp_buf
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_longjmp
parameter_list|(
name|jmp_buf
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|sigsetjmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siglongjmp
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_function_decl
specifier|extern
name|int
name|setjmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_setjmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|longjmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_longjmp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

