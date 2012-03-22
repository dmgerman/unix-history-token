begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2005 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"der_locl.h"
end_include

begin_include
include|#
directive|include
file|<com_err.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<getarg.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|class_names
index|[]
init|=
block|{
literal|"UNIV"
block|,
comment|/* 0 */
literal|"APPL"
block|,
comment|/* 1 */
literal|"CONTEXT"
block|,
comment|/* 2 */
literal|"PRIVATE"
comment|/* 3 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|type_names
index|[]
init|=
block|{
literal|"PRIM"
block|,
comment|/* 0 */
literal|"CONS"
comment|/* 1 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|tag_names
index|[]
init|=
block|{
literal|"EndOfContent"
block|,
comment|/* 0 */
literal|"Boolean"
block|,
comment|/* 1 */
literal|"Integer"
block|,
comment|/* 2 */
literal|"BitString"
block|,
comment|/* 3 */
literal|"OctetString"
block|,
comment|/* 4 */
literal|"Null"
block|,
comment|/* 5 */
literal|"ObjectID"
block|,
comment|/* 6 */
name|NULL
block|,
comment|/* 7 */
name|NULL
block|,
comment|/* 8 */
name|NULL
block|,
comment|/* 9 */
literal|"Enumerated"
block|,
comment|/* 10 */
name|NULL
block|,
comment|/* 11 */
name|NULL
block|,
comment|/* 12 */
name|NULL
block|,
comment|/* 13 */
name|NULL
block|,
comment|/* 14 */
name|NULL
block|,
comment|/* 15 */
literal|"Sequence"
block|,
comment|/* 16 */
literal|"Set"
block|,
comment|/* 17 */
name|NULL
block|,
comment|/* 18 */
literal|"PrintableString"
block|,
comment|/* 19 */
name|NULL
block|,
comment|/* 20 */
name|NULL
block|,
comment|/* 21 */
literal|"IA5String"
block|,
comment|/* 22 */
literal|"UTCTime"
block|,
comment|/* 23 */
literal|"GeneralizedTime"
block|,
comment|/* 24 */
name|NULL
block|,
comment|/* 25 */
literal|"VisibleString"
block|,
comment|/* 26 */
literal|"GeneralString"
block|,
comment|/* 27 */
name|NULL
block|,
comment|/* 28 */
name|NULL
block|,
comment|/* 29 */
literal|"BMPString"
comment|/* 30 */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|get_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|list
index|[]
parameter_list|,
name|unsigned
name|len
parameter_list|)
block|{
name|unsigned
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|list
index|[
name|i
index|]
operator|&&
name|strcasecmp
argument_list|(
name|list
index|[
name|i
index|]
argument_list|,
name|name
argument_list|)
operator|==
literal|0
condition|)
return|return
name|i
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_define
define|#
directive|define
name|SIZEOF_ARRAY
parameter_list|(
name|a
parameter_list|)
value|(sizeof((a))/sizeof((a)[0]))
end_define

begin_function
specifier|const
name|char
modifier|*
name|der_get_class_name
parameter_list|(
name|unsigned
name|num
parameter_list|)
block|{
if|if
condition|(
name|num
operator|>=
name|SIZEOF_ARRAY
argument_list|(
name|class_names
argument_list|)
condition|)
return|return
name|NULL
return|;
return|return
name|class_names
index|[
name|num
index|]
return|;
block|}
end_function

begin_function
name|int
name|der_get_class_num
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|get_type
argument_list|(
name|name
argument_list|,
name|class_names
argument_list|,
name|SIZEOF_ARRAY
argument_list|(
name|class_names
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|der_get_type_name
parameter_list|(
name|unsigned
name|num
parameter_list|)
block|{
if|if
condition|(
name|num
operator|>=
name|SIZEOF_ARRAY
argument_list|(
name|type_names
argument_list|)
condition|)
return|return
name|NULL
return|;
return|return
name|type_names
index|[
name|num
index|]
return|;
block|}
end_function

begin_function
name|int
name|der_get_type_num
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|get_type
argument_list|(
name|name
argument_list|,
name|type_names
argument_list|,
name|SIZEOF_ARRAY
argument_list|(
name|type_names
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|der_get_tag_name
parameter_list|(
name|unsigned
name|num
parameter_list|)
block|{
if|if
condition|(
name|num
operator|>=
name|SIZEOF_ARRAY
argument_list|(
name|tag_names
argument_list|)
condition|)
return|return
name|NULL
return|;
return|return
name|tag_names
index|[
name|num
index|]
return|;
block|}
end_function

begin_function
name|int
name|der_get_tag_num
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|get_type
argument_list|(
name|name
argument_list|,
name|tag_names
argument_list|,
name|SIZEOF_ARRAY
argument_list|(
name|tag_names
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

