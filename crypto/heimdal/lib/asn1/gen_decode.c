begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"gen_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: gen_decode.c,v 1.17 2001/09/25 13:39:26 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|decode_primitive
parameter_list|(
specifier|const
name|char
modifier|*
name|typename
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"e = decode_%s(p, len, %s,&l);\n"
literal|"FORW;\n"
argument_list|,
name|typename
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|decode_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|Type
modifier|*
name|t
parameter_list|)
block|{
switch|switch
condition|(
name|t
operator|->
name|type
condition|)
block|{
case|case
name|TType
case|:
if|#
directive|if
literal|0
block|decode_type (name, t->symbol->type);
endif|#
directive|endif
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"e = decode_%s(p, len, %s,&l);\n"
literal|"FORW;\n"
argument_list|,
name|t
operator|->
name|symbol
operator|->
name|gen_name
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
name|TInteger
case|:
if|if
condition|(
name|t
operator|->
name|members
operator|==
name|NULL
condition|)
name|decode_primitive
argument_list|(
literal|"integer"
argument_list|,
name|name
argument_list|)
expr_stmt|;
else|else
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|asprintf
argument_list|(
operator|&
name|s
argument_list|,
literal|"(int*)%s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"out of memory"
argument_list|)
expr_stmt|;
name|decode_primitive
argument_list|(
literal|"integer"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|TUInteger
case|:
name|decode_primitive
argument_list|(
literal|"unsigned"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
name|TEnumerated
case|:
name|decode_primitive
argument_list|(
literal|"enumerated"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
name|TOctetString
case|:
name|decode_primitive
argument_list|(
literal|"octet_string"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
name|TOID
case|:
name|decode_primitive
argument_list|(
literal|"oid"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
name|TBitString
case|:
block|{
name|Member
modifier|*
name|m
decl_stmt|;
name|int
name|tag
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|pos
decl_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"e = der_match_tag_and_length (p, len, UNIV, PRIM, UT_BitString,"
literal|"&reallen,&l);\n"
literal|"FORW;\n"
literal|"if(len< reallen)\n"
literal|"return ASN1_OVERRUN;\n"
literal|"p++;\n"
literal|"len--;\n"
literal|"reallen--;\n"
literal|"ret++;\n"
argument_list|)
expr_stmt|;
name|pos
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|m
operator|=
name|t
operator|->
name|members
init|;
name|m
operator|&&
name|tag
operator|!=
name|m
operator|->
name|val
condition|;
name|m
operator|=
name|m
operator|->
name|next
control|)
block|{
while|while
condition|(
name|m
operator|->
name|val
operator|/
literal|8
operator|>
name|pos
operator|/
literal|8
condition|)
block|{
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"p++; len--; reallen--; ret++;\n"
argument_list|)
expr_stmt|;
name|pos
operator|+=
literal|8
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"%s->%s = (*p>> %d)& 1;\n"
argument_list|,
name|name
argument_list|,
name|m
operator|->
name|gen_name
argument_list|,
literal|7
operator|-
name|m
operator|->
name|val
operator|%
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|tag
operator|==
operator|-
literal|1
condition|)
name|tag
operator|=
name|m
operator|->
name|val
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"p += reallen; len -= reallen; ret += reallen;\n"
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|TSequence
case|:
block|{
name|Member
modifier|*
name|m
decl_stmt|;
name|int
name|tag
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|t
operator|->
name|members
operator|==
name|NULL
condition|)
break|break;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"e = der_match_tag_and_length (p, len, UNIV, CONS, UT_Sequence,"
literal|"&reallen,&l);\n"
literal|"FORW;\n"
literal|"{\n"
literal|"int dce_fix;\n"
literal|"if((dce_fix = fix_dce(reallen,&len))< 0)\n"
literal|"return ASN1_BAD_FORMAT;\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|m
operator|=
name|t
operator|->
name|members
init|;
name|m
operator|&&
name|tag
operator|!=
name|m
operator|->
name|val
condition|;
name|m
operator|=
name|m
operator|->
name|next
control|)
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|asprintf
argument_list|(
operator|&
name|s
argument_list|,
literal|"%s(%s)->%s"
argument_list|,
name|m
operator|->
name|optional
condition|?
literal|""
else|:
literal|"&"
argument_list|,
name|name
argument_list|,
name|m
operator|->
name|gen_name
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|&&
name|m
operator|->
name|type
operator|->
name|type
operator|==
name|TType
condition|)
block|{
if|if
condition|(
name|m
operator|->
name|optional
condition|)
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"%s = malloc(sizeof(*%s));\n"
literal|"if(%s == NULL) return ENOMEM;\n"
argument_list|,
name|s
argument_list|,
name|s
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"e = decode_seq_%s(p, len, %d, %d, %s,&l);\n"
argument_list|,
name|m
operator|->
name|type
operator|->
name|symbol
operator|->
name|gen_name
argument_list|,
name|m
operator|->
name|val
argument_list|,
name|m
operator|->
name|optional
argument_list|,
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|optional
condition|)
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"if (e == ASN1_MISSING_FIELD) {\n"
literal|"free(%s);\n"
literal|"%s = NULL;\n"
literal|"e = l = 0;\n"
literal|"}\n"
argument_list|,
name|s
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"FORW;\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"{\n"
literal|"size_t newlen, oldlen;\n\n"
literal|"e = der_match_tag (p, len, CONTEXT, CONS, %d,&l);\n"
argument_list|,
name|m
operator|->
name|val
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"if (e)\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|optional
condition|)
comment|/* XXX should look at e */
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"%s = NULL;\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"return e;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"else {\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"p += l;\n"
literal|"len -= l;\n"
literal|"ret += l;\n"
literal|"e = der_get_length (p, len,&newlen,&l);\n"
literal|"FORW;\n"
literal|"{\n"
literal|"int dce_fix;\n"
literal|"oldlen = len;\n"
literal|"if((dce_fix = fix_dce(newlen,&len))< 0)"
literal|"return ASN1_BAD_FORMAT;\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|optional
condition|)
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"%s = malloc(sizeof(*%s));\n"
literal|"if(%s == NULL) return ENOMEM;\n"
argument_list|,
name|s
argument_list|,
name|s
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|decode_type
argument_list|(
name|s
argument_list|,
name|m
operator|->
name|type
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"if(dce_fix){\n"
literal|"e = der_match_tag_and_length (p, len, "
literal|"(Der_class)0, (Der_type)0, 0,&reallen,&l);\n"
literal|"FORW;\n"
literal|"}else \n"
literal|"len = oldlen - newlen;\n"
literal|"}\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"}\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tag
operator|==
operator|-
literal|1
condition|)
name|tag
operator|=
name|m
operator|->
name|val
expr_stmt|;
name|free
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"if(dce_fix){\n"
literal|"e = der_match_tag_and_length (p, len, "
literal|"(Der_class)0, (Der_type)0, 0,&reallen,&l);\n"
literal|"FORW;\n"
literal|"}\n"
literal|"}\n"
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|TSequenceOf
case|:
block|{
name|char
modifier|*
name|n
decl_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"e = der_match_tag_and_length (p, len, UNIV, CONS, UT_Sequence,"
literal|"&reallen,&l);\n"
literal|"FORW;\n"
literal|"if(len< reallen)\n"
literal|"return ASN1_OVERRUN;\n"
literal|"len = reallen;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"{\n"
literal|"size_t origlen = len;\n"
literal|"int oldret = ret;\n"
literal|"ret = 0;\n"
literal|"(%s)->len = 0;\n"
literal|"(%s)->val = NULL;\n"
literal|"while(ret< origlen) {\n"
literal|"(%s)->len++;\n"
literal|"(%s)->val = realloc((%s)->val, sizeof(*((%s)->val)) * (%s)->len);\n"
argument_list|,
name|name
argument_list|,
name|name
argument_list|,
name|name
argument_list|,
name|name
argument_list|,
name|name
argument_list|,
name|name
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|asprintf
argument_list|(
operator|&
name|n
argument_list|,
literal|"&(%s)->val[(%s)->len-1]"
argument_list|,
name|name
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|decode_type
argument_list|(
name|n
argument_list|,
name|t
operator|->
name|subtype
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"len = origlen - ret;\n"
literal|"}\n"
literal|"ret += oldret;\n"
literal|"}\n"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|n
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|TGeneralizedTime
case|:
name|decode_primitive
argument_list|(
literal|"generalized_time"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
name|TGeneralString
case|:
name|decode_primitive
argument_list|(
literal|"general_string"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
name|TApplication
case|:
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"e = der_match_tag_and_length (p, len, APPL, CONS, %d, "
literal|"&reallen,&l);\n"
literal|"FORW;\n"
literal|"{\n"
literal|"int dce_fix;\n"
literal|"if((dce_fix = fix_dce(reallen,&len))< 0)\n"
literal|"return ASN1_BAD_FORMAT;\n"
argument_list|,
name|t
operator|->
name|application
argument_list|)
expr_stmt|;
name|decode_type
argument_list|(
name|name
argument_list|,
name|t
operator|->
name|subtype
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"if(dce_fix){\n"
literal|"e = der_match_tag_and_length (p, len, "
literal|"(Der_class)0, (Der_type)0, 0,&reallen,&l);\n"
literal|"FORW;\n"
literal|"}\n"
literal|"}\n"
argument_list|)
expr_stmt|;
break|break;
default|default :
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|generate_type_decode
parameter_list|(
specifier|const
name|Symbol
modifier|*
name|s
parameter_list|)
block|{
name|fprintf
argument_list|(
name|headerfile
argument_list|,
literal|"int    "
literal|"decode_%s(const unsigned char *, size_t, %s *, size_t *);\n"
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
literal|"#define FORW "
literal|"if(e) goto fail; "
literal|"p += l; "
literal|"len -= l; "
literal|"ret += l\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"int\n"
literal|"decode_%s(const unsigned char *p,"
literal|" size_t len, %s *data, size_t *size)\n"
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
switch|switch
condition|(
name|s
operator|->
name|type
operator|->
name|type
condition|)
block|{
case|case
name|TInteger
case|:
case|case
name|TUInteger
case|:
case|case
name|TOctetString
case|:
case|case
name|TOID
case|:
case|case
name|TGeneralizedTime
case|:
case|case
name|TGeneralString
case|:
case|case
name|TBitString
case|:
case|case
name|TSequence
case|:
case|case
name|TSequenceOf
case|:
case|case
name|TApplication
case|:
case|case
name|TType
case|:
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"size_t ret = 0, reallen;\n"
literal|"size_t l;\n"
literal|"int i, e;\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"memset(data, 0, sizeof(*data));\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"i = 0;\n"
argument_list|)
expr_stmt|;
comment|/* hack to avoid `unused variable' */
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"reallen = 0;\n"
argument_list|)
expr_stmt|;
comment|/* hack to avoid `unused variable' */
name|decode_type
argument_list|(
literal|"data"
argument_list|,
name|s
operator|->
name|type
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"if(size) *size = ret;\n"
literal|"return 0;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"fail:\n"
literal|"free_%s(data);\n"
literal|"return e;\n"
argument_list|,
name|s
operator|->
name|gen_name
argument_list|)
expr_stmt|;
break|break;
default|default:
name|abort
argument_list|()
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"}\n\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|generate_seq_type_decode
parameter_list|(
specifier|const
name|Symbol
modifier|*
name|s
parameter_list|)
block|{
name|fprintf
argument_list|(
name|headerfile
argument_list|,
literal|"int decode_seq_%s(const unsigned char *, size_t, int, int, "
literal|"%s *, size_t *);\n"
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
literal|"int\n"
literal|"decode_seq_%s(const unsigned char *p, size_t len, int tag, "
literal|"int optional, %s *data, size_t *size)\n"
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
literal|"size_t newlen, oldlen;\n"
literal|"size_t l, ret = 0;\n"
literal|"int e;\n"
literal|"int dce_fix;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"e = der_match_tag(p, len, CONTEXT, CONS, tag,&l);\n"
literal|"if (e)\n"
literal|"return e;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|codefile
argument_list|,
literal|"p += l;\n"
literal|"len -= l;\n"
literal|"ret += l;\n"
literal|"e = der_get_length(p, len,&newlen,&l);\n"
literal|"if (e)\n"
literal|"return e;\n"
literal|"p += l;\n"
literal|"len -= l;\n"
literal|"ret += l;\n"
literal|"oldlen = len;\n"
literal|"if ((dce_fix = fix_dce(newlen,&len))< 0)\n"
literal|"return ASN1_BAD_FORMAT;\n"
literal|"e = decode_%s(p, len, data,&l);\n"
literal|"if (e)\n"
literal|"return e;\n"
literal|"p += l;\n"
literal|"len -= l;\n"
literal|"ret += l;\n"
literal|"if (dce_fix) {\n"
literal|"size_t reallen;\n\n"
literal|"e = der_match_tag_and_length(p, len, "
literal|"(Der_class)0, (Der_type)0, 0,&reallen,&l);\n"
literal|"if (e)\n"
literal|"return e;\n"
literal|"ret += l;\n"
literal|"}\n"
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
literal|"if(size) *size = ret;\n"
literal|"return 0;\n"
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

