begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1997, 1998 Shigio Yamaguchi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	defined.c				12-Nov-98  *  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"die.h"
end_include

begin_include
include|#
directive|include
file|"dbop.h"
end_include

begin_include
include|#
directive|include
file|"defined.h"
end_include

begin_include
include|#
directive|include
file|"makepath.h"
end_include

begin_decl_stmt
specifier|static
name|DBOP
modifier|*
name|dbop
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Tag command that supports referenced tag must call this function  * to decide whether or not the tag is defined.  */
end_comment

begin_function
name|int
name|defined
parameter_list|(
name|name
parameter_list|)
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|{
if|if
condition|(
name|dbop
operator|==
name|NULL
condition|)
block|{
specifier|const
name|char
modifier|*
name|dbpath
decl_stmt|;
comment|/* 		 * gtags(1) set GTAGSDBPATH to the path GTAGS exist. 		 */
if|if
condition|(
operator|!
operator|(
name|dbpath
operator|=
name|getenv
argument_list|(
literal|"GTAGSDBPATH"
argument_list|)
operator|)
condition|)
name|dbpath
operator|=
literal|"."
expr_stmt|;
name|dbop
operator|=
name|dbop_open
argument_list|(
name|makepath
argument_list|(
name|dbpath
argument_list|,
literal|"GTAGS"
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|dbop
operator|==
name|NULL
condition|)
name|die1
argument_list|(
literal|"GTAGS not found. (%s)"
argument_list|,
name|makepath
argument_list|(
name|dbpath
argument_list|,
literal|"GTAGS"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dbop_get
argument_list|(
name|dbop
argument_list|,
name|name
argument_list|)
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

