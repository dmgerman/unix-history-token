begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: match.h,v 1.7 2001/03/10 17:51:04 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * This file contains various auxiliary functions related to multiple  * precision integers.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MATCH_H
end_ifndef

begin_define
define|#
directive|define
name|MATCH_H
end_define

begin_comment
comment|/*  * Returns true if the given string matches the pattern (which may contain ?  * and * as wildcards), and zero if it does not match.  */
end_comment

begin_function_decl
name|int
name|match_pattern
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Tries to match the host name (which must be in all lowercase) against the  * comma-separated sequence of subpatterns (each possibly preceded by ! to  * indicate negation).  Returns -1 if negation matches, 1 if there is  * a positive match, 0 if there is no match at all.  */
end_comment

begin_function_decl
name|int
name|match_hostname
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns first item from client-list that is also supported by server-list,  * caller must xfree() returned string.  */
end_comment

begin_function_decl
name|char
modifier|*
name|match_list
parameter_list|(
specifier|const
name|char
modifier|*
name|client
parameter_list|,
specifier|const
name|char
modifier|*
name|server
parameter_list|,
name|u_int
modifier|*
name|next
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

