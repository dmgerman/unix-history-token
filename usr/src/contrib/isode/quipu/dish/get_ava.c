begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* get_ava.c - */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/quipu/dish/RCS/get_ava.c,v 7.1 91/02/22 09:40:38 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/quipu/dish/RCS/get_ava.c,v 7.1 91/02/22 09:40:38 mrose Interim $  *  *  * $Log:	get_ava.c,v $  * Revision 7.1  91/02/22  09:40:38  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:20:09  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/commonarg.h"
end_include

begin_define
define|#
directive|define
name|OPT
value|(!frompipe || rps -> ps_byteno == 0 ? opt : rps)
end_define

begin_define
define|#
directive|define
name|RPS
value|(!frompipe || opt -> ps_byteno == 0 ? rps : opt)
end_define

begin_decl_stmt
specifier|extern
name|char
name|frompipe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PS
name|opt
decl_stmt|,
name|rps
decl_stmt|;
end_decl_stmt

begin_macro
name|get_ava
argument_list|(
argument|avasert
argument_list|,
argument|type
argument_list|,
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|AVA
modifier|*
name|avasert
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|TidyString
parameter_list|()
function_decl|;
if|if
condition|(
name|type
operator|==
name|NULLCP
operator|||
operator|*
name|type
operator|==
literal|0
condition|)
return|return
operator|(
name|NOTOK
operator|)
return|;
name|avasert
operator|->
name|ava_type
operator|=
name|AttrT_new
argument_list|(
name|TidyString
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|avasert
operator|->
name|ava_type
operator|==
name|NULLAttrT
condition|)
block|{
name|ps_printf
argument_list|(
name|OPT
argument_list|,
literal|"Invalid at %s\n"
argument_list|,
name|type
argument_list|)
expr_stmt|;
return|return
operator|(
name|NOTOK
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|avasert
operator|->
name|ava_value
operator|=
name|str_at2AttrV
argument_list|(
name|TidyString
argument_list|(
name|value
argument_list|)
argument_list|,
name|avasert
operator|->
name|ava_type
argument_list|)
operator|)
operator|==
name|NULLAttrV
condition|)
block|{
name|ps_print
argument_list|(
name|OPT
argument_list|,
literal|"Invalid attribute value value\n"
argument_list|)
expr_stmt|;
name|AttrT_free
argument_list|(
name|avasert
operator|->
name|ava_type
argument_list|)
expr_stmt|;
return|return
operator|(
name|NOTOK
operator|)
return|;
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

end_unit

