begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1997 Shigio Yamaguchi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	lookup.c				20-Oct-97  *  */
end_comment

begin_include
include|#
directive|include
file|"gtagsopen.h"
end_include

begin_include
include|#
directive|include
file|"lookup.h"
end_include

begin_include
include|#
directive|include
file|"dbio.h"
end_include

begin_include
include|#
directive|include
file|"die.h"
end_include

begin_include
include|#
directive|include
file|"dbname.h"
end_include

begin_decl_stmt
specifier|static
name|DBIO
modifier|*
name|dbio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|opened
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|lookupopen
parameter_list|(
name|dbpath
parameter_list|)
name|char
modifier|*
name|dbpath
decl_stmt|;
block|{
if|if
condition|(
name|opened
condition|)
name|die
argument_list|(
literal|"nested call to lookupopen."
argument_list|)
expr_stmt|;
name|opened
operator|=
literal|1
expr_stmt|;
name|dbio
operator|=
name|gtagsopen
argument_list|(
name|dbpath
argument_list|,
name|GTAGS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|lookup
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|char
modifier|*
name|p
init|=
name|db_get
argument_list|(
name|dbio
argument_list|,
name|name
argument_list|)
decl_stmt|;
return|return
operator|(
name|p
operator|)
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function

begin_function
name|void
name|lookupclose
parameter_list|(
name|void
parameter_list|)
block|{
name|db_close
argument_list|(
name|dbio
argument_list|)
expr_stmt|;
name|opened
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

