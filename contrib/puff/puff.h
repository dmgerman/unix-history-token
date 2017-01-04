begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* puff.h   Copyright (C) 2002-2013 Mark Adler, all rights reserved   version 2.3, 21 Jan 2013    This software is provided 'as-is', without any express or implied   warranty.  In no event will the author be held liable for any damages   arising from the use of this software.    Permission is granted to anyone to use this software for any purpose,   including commercial applications, and to alter it and redistribute it   freely, subject to the following restrictions:    1. The origin of this software must not be misrepresented; you must not      claim that you wrote the original software. If you use this software      in a product, an acknowledgment in the product documentation would be      appreciated but is not required.   2. Altered source versions must be plainly marked as such, and must not be      misrepresented as being the original software.   3. This notice may not be removed or altered from any source distribution.    Mark Adler    madler@alumni.caltech.edu  */
end_comment

begin_comment
comment|/*  * See puff.c for purpose and usage.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NIL
end_ifndef

begin_define
define|#
directive|define
name|NIL
value|((unsigned char *)0)
end_define

begin_comment
comment|/* for no output option */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|puff
parameter_list|(
name|unsigned
name|char
modifier|*
name|dest
parameter_list|,
comment|/* pointer to destination pointer */
name|unsigned
name|long
modifier|*
name|destlen
parameter_list|,
comment|/* amount of output space */
specifier|const
name|unsigned
name|char
modifier|*
name|source
parameter_list|,
comment|/* pointer to source data pointer */
name|unsigned
name|long
modifier|*
name|sourcelen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* amount of input available */
end_comment

end_unit

