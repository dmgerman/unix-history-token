begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* is2taddr.c - old-style T-ADDR lookup */
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
literal|"$Header: /f/osi/acsap/RCS/is2taddr.c,v 7.2 91/02/22 09:14:40 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/acsap/RCS/is2taddr.c,v 7.2 91/02/22 09:14:40 mrose Interim $  *  *  * $Log:	is2taddr.c,v $  * Revision 7.2  91/02/22  09:14:40  mrose  * Interim 6.8  *   * Revision 7.1  90/03/05  23:02:24  mrose  * touch-up  *   * Revision 7.0  89/11/23  21:22:11  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_include
include|#
directive|include
file|"isoaddrs.h"
end_include

begin_include
include|#
directive|include
file|"isoservent.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|struct
name|TSAPaddr
modifier|*
name|is2taddr
parameter_list|(
name|host
parameter_list|,
name|service
parameter_list|,
name|is
parameter_list|)
name|char
modifier|*
name|host
decl_stmt|,
decl|*
name|service
decl_stmt|;
end_function

begin_decl_stmt
name|struct
name|isoservent
modifier|*
name|is
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|AEI
name|aei
decl_stmt|;
name|struct
name|PSAPaddr
modifier|*
name|pa
decl_stmt|;
name|struct
name|TSAPaddr
modifier|*
name|ta
decl_stmt|;
if|if
condition|(
operator|(
name|aei
operator|=
name|str2aei
argument_list|(
name|host
argument_list|,
name|service
argument_list|)
operator|)
operator|==
name|NULLAEI
operator|||
operator|(
name|pa
operator|=
name|aei2addr
argument_list|(
name|aei
argument_list|)
operator|)
operator|==
name|NULLPA
condition|)
return|return
name|NULLTA
return|;
name|ta
operator|=
operator|&
name|pa
operator|->
name|pa_addr
operator|.
name|sa_addr
expr_stmt|;
if|if
condition|(
name|is
operator|&&
name|strcmp
argument_list|(
name|is
operator|->
name|is_provider
argument_list|,
literal|"tsap"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|is
operator|->
name|is_selectlen
operator|>
name|TSSIZE
condition|)
comment|/* XXX */
return|return
name|NULLTA
return|;
name|bcopy
argument_list|(
name|is
operator|->
name|is_selector
argument_list|,
name|ta
operator|->
name|ta_selector
argument_list|,
name|ta
operator|->
name|ta_selectlen
operator|=
name|is
operator|->
name|is_selectlen
argument_list|)
expr_stmt|;
block|}
return|return
name|ta
return|;
block|}
end_block

end_unit

