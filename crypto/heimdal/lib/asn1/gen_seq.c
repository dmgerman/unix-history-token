begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"gen_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|generate_type_seq
parameter_list|(
specifier|const
name|Symbol
modifier|*
name|s
parameter_list|)
block|{
name|char
modifier|*
name|subname
decl_stmt|;
name|Type
modifier|*
name|type
decl_stmt|;
if|if
condition|(
operator|!
name|seq_type
argument_list|(
name|s
operator|->
name|name
argument_list|)
condition|)
return|return;
name|type
operator|=
name|s
operator|->
name|type
expr_stmt|;
while|while
condition|(
name|type
operator|->
name|type
operator|==
name|TTag
condition|)
name|type
operator|=
name|type
operator|->
name|subtype
expr_stmt|;
if|if
condition|(
name|type
operator|->
name|type
operator|!=
name|TSequenceOf
operator|&&
name|type
operator|->
name|type
operator|!=
name|TSetOf
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s not seq of %d\n"
argument_list|,
name|s
operator|->
name|name
argument_list|,
operator|(
name|int
operator|)
name|type
operator|->
name|type
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/*      * Require the subtype to be a type so we can name it and use      * copy_/free_      */
if|if
condition|(
name|type
operator|->
name|subtype
operator|->
name|type
operator|!=
name|TType
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s subtype is not a type, can't generate "
literal|"sequence code for this case: %d\n"
argument_list|,
name|s
operator|->
name|name
argument_list|,
operator|(
name|int
operator|)
name|type
operator|->
name|subtype
operator|->
name|type
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|subname
operator|=
name|type
operator|->
name|subtype
operator|->
name|symbol
operator|->
name|gen_name
expr_stmt|;
name|fprintf
argument_list|(
name|headerfile
argument_list|,
literal|"ASN1EXP int   ASN1CALL add_%s  (%s *, const %s *);\n"
literal|"ASN1EXP int   ASN1CALL remove_%s  (%s *, unsigned int);\n"
argument_list|,
name|s
operator|->
name|gen_name
argument_list|,
name|s
operator|->
name|gen_name
argument_list|,
name|subname
argument_list|,
name|s
operator|->
name|gen_name
argument_list|,
name|s
operator|->
name|gen_name
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"int ASN1CALL\n"
literal|"add_%s(%s *data, const %s *element)\n"
literal|"{\n"
argument_list|,
name|s
operator|->
name|gen_name
argument_list|,
name|s
operator|->
name|gen_name
argument_list|,
name|subname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"int ret;\n"
literal|"void *ptr;\n"
literal|"\n"
literal|"ptr = realloc(data->val, \n"
literal|"\t(data->len + 1) * sizeof(data->val[0]));\n"
literal|"if (ptr == NULL) return ENOMEM;\n"
literal|"data->val = ptr;\n\n"
literal|"ret = copy_%s(element,&data->val[data->len]);\n"
literal|"if (ret) return ret;\n"
literal|"data->len++;\n"
literal|"return 0;\n"
argument_list|,
name|subname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"}\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"int ASN1CALL\n"
literal|"remove_%s(%s *data, unsigned int element)\n"
literal|"{\n"
argument_list|,
name|s
operator|->
name|gen_name
argument_list|,
name|s
operator|->
name|gen_name
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"void *ptr;\n"
literal|"\n"
literal|"if (data->len == 0 || element>= data->len)\n"
literal|"\treturn ASN1_OVERRUN;\n"
literal|"free_%s(&data->val[element]);\n"
literal|"data->len--;\n"
comment|/* don't move if its the last element */
literal|"if (element< data->len)\n"
literal|"\tmemmove(&data->val[element],&data->val[element + 1], \n"
literal|"\t\tsizeof(data->val[0]) * (data->len - element));\n"
comment|/* resize but don't care about failures since it doesn't matter */
literal|"ptr = realloc(data->val, data->len * sizeof(data->val[0]));\n"
literal|"if (ptr != NULL || data->len == 0) data->val = ptr;\n"
literal|"return 0;\n"
argument_list|,
name|subname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"}\n\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

