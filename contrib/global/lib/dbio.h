begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1997 Shigio Yamaguchi. All rights reserved.  *  * Redilogibution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redilogibutions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redilogibutions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the dilogibution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	dbio.h					14-Dec-97  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DBIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_DBIO_H_
end_define

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LITTLE_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXKEYLEN
value|300
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|DB
modifier|*
name|db
decl_stmt|;
comment|/* descripter of DB */
name|char
name|dbname
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* dbname */
name|char
name|key
index|[
name|MAXKEYLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* key */
name|int
name|keylen
decl_stmt|;
comment|/* key length */
name|char
name|prev
index|[
name|MAXKEYLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* previous key value */
name|char
modifier|*
name|lastkey
decl_stmt|;
comment|/* the key of last located record */
name|char
modifier|*
name|lastdat
decl_stmt|;
comment|/* the data of last located record */
name|int
name|openflags
decl_stmt|;
comment|/* flags of db_open() */
name|int
name|ioflags
decl_stmt|;
comment|/* flags of db_first() */
name|int
name|perm
decl_stmt|;
comment|/* file permission */
block|}
name|DBIO
typedef|;
end_typedef

begin_comment
comment|/*  * openflags  */
end_comment

begin_define
define|#
directive|define
name|DBIO_DUP
value|1
end_define

begin_comment
comment|/* allow duplicate records	*/
end_comment

begin_define
define|#
directive|define
name|DBIO_REMOVE
value|2
end_define

begin_comment
comment|/* remove file when closed	*/
end_comment

begin_comment
comment|/*  * ioflags  */
end_comment

begin_define
define|#
directive|define
name|DBIO_KEY
value|1
end_define

begin_comment
comment|/* read key part		*/
end_comment

begin_define
define|#
directive|define
name|DBIO_PREFIX
value|2
end_define

begin_comment
comment|/* prefixed read		*/
end_comment

begin_define
define|#
directive|define
name|DBIO_SKIPMETA
value|4
end_define

begin_comment
comment|/* skip META record		*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|DBIO
modifier|*
name|db_open
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|db_get
name|__P
argument_list|(
operator|(
name|DBIO
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_put
name|__P
argument_list|(
operator|(
name|DBIO
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_del
name|__P
argument_list|(
operator|(
name|DBIO
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|db_first
name|__P
argument_list|(
operator|(
name|DBIO
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|db_next
name|__P
argument_list|(
operator|(
name|DBIO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_close
name|__P
argument_list|(
operator|(
name|DBIO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DBIO_H_ */
end_comment

end_unit

