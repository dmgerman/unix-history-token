begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* taddr2str.c - TSAPaddr to string value */
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
literal|"$Header: /f/osi/compat/RCS/taddr2str.c,v 7.1 91/02/22 09:16:08 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/taddr2str.c,v 7.1 91/02/22 09:16:08 mrose Interim $  *  *  * $Log:	taddr2str.c,v $  * Revision 7.1  91/02/22  09:16:08  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:23:44  mrose  * Release 6.0  *   */
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
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_include
include|#
directive|include
file|"isoaddrs.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|taddr2str
parameter_list|(
name|ta
parameter_list|)
specifier|register
name|struct
name|TSAPaddr
modifier|*
name|ta
decl_stmt|;
block|{
name|struct
name|PSAPaddr
name|pas
decl_stmt|;
specifier|register
name|struct
name|PSAPaddr
modifier|*
name|pa
init|=
operator|&
name|pas
decl_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pa
argument_list|,
sizeof|sizeof
expr|*
name|pa
argument_list|)
expr_stmt|;
name|pa
operator|->
name|pa_addr
operator|.
name|sa_addr
operator|=
operator|*
name|ta
expr_stmt|;
comment|/* struct copy */
return|return
name|paddr2str
argument_list|(
name|pa
argument_list|,
name|NULLNA
argument_list|)
return|;
block|}
end_function

end_unit

