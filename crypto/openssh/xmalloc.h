begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Created: Mon Mar 20 22:09:17 1995 ylo  *  * Versions of malloc and friends that check their results, and never return  * failure (they call fatal if they encounter an error).  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: xmalloc.h,v 1.5 2000/09/07 20:27:56 deraadt Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XMALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|XMALLOC_H
end_define

begin_comment
comment|/* Like malloc, but calls fatal() if out of memory. */
end_comment

begin_function_decl
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like realloc, but calls fatal() if out of memory. */
end_comment

begin_function_decl
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|new_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Frees memory allocated using xmalloc or xrealloc. */
end_comment

begin_function_decl
name|void
name|xfree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocates memory using xmalloc, and copies the string into that memory. */
end_comment

begin_function_decl
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XMALLOC_H */
end_comment

end_unit

