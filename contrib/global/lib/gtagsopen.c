begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1997 Shigio Yamaguchi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	gtagsopen.c				20-Oct-97  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"dbio.h"
end_include

begin_include
include|#
directive|include
file|"dbname.h"
end_include

begin_include
include|#
directive|include
file|"die.h"
end_include

begin_include
include|#
directive|include
file|"gtagsopen.h"
end_include

begin_include
include|#
directive|include
file|"makepath.h"
end_include

begin_define
define|#
directive|define
name|VERSIONKEY
value|" __.VERSION"
end_define

begin_decl_stmt
specifier|static
name|int
name|support_version
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accept this format version	*/
end_comment

begin_comment
comment|/*  * gtagsopen: open global database.  *  *	i)	dbpath	dbpath directory  *	i)	db	GTAGS, GRTAGS, GSYMS  *	i)	mode	0: read only  *			1: write only  *			2: read and write  *	r)		DB structure  *  * when error occurred, gtagopen doesn't return.  */
end_comment

begin_function
name|DBIO
modifier|*
name|gtagsopen
parameter_list|(
name|dbpath
parameter_list|,
name|db
parameter_list|,
name|mode
parameter_list|)
name|char
modifier|*
name|dbpath
decl_stmt|;
name|int
name|db
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|{
name|DBIO
modifier|*
name|dbio
decl_stmt|;
name|int
name|version_number
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
comment|/* 	 * allow duplicate records. 	 */
name|dbio
operator|=
name|db_open
argument_list|(
name|makepath
argument_list|(
name|dbpath
argument_list|,
name|dbname
argument_list|(
name|db
argument_list|)
argument_list|)
argument_list|,
name|mode
argument_list|,
literal|0644
argument_list|,
name|DBIO_DUP
argument_list|)
expr_stmt|;
if|if
condition|(
name|dbio
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|mode
operator|==
literal|1
condition|)
name|die1
argument_list|(
literal|"cannot make database (%s)."
argument_list|,
name|makepath
argument_list|(
name|dbpath
argument_list|,
name|dbname
argument_list|(
name|db
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|die1
argument_list|(
literal|"database not found (%s)."
argument_list|,
name|makepath
argument_list|(
name|dbpath
argument_list|,
name|dbname
argument_list|(
name|db
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mode
operator|==
literal|1
condition|)
block|{
comment|/* nothing to do now */
block|}
else|else
block|{
comment|/* 		 * recognize format version of GTAGS. 'format version record' 		 * is saved as a META record in GTAGS and GRTAGS. 		 * if 'format version record' is not found, it's assumed 		 * version 1. 		 */
if|if
condition|(
operator|(
name|p
operator|=
name|db_get
argument_list|(
name|dbio
argument_list|,
name|VERSIONKEY
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
for|for
control|(
name|p
operator|+=
name|strlen
argument_list|(
name|VERSIONKEY
argument_list|)
init|;
operator|*
name|p
operator|&&
name|isspace
argument_list|(
operator|*
name|p
argument_list|)
condition|;
name|p
operator|++
control|)
empty_stmt|;
name|version_number
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
else|else
name|version_number
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|version_number
operator|>
name|support_version
condition|)
name|die
argument_list|(
literal|"GTAGS seems new format. Please install the latest GLOBAL."
argument_list|)
expr_stmt|;
block|}
return|return
name|dbio
return|;
block|}
end_function

end_unit

