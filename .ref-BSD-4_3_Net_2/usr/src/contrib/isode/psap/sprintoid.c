begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sprintoid.c - object identifier to string */
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
literal|"$Header: /f/osi/psap/RCS/sprintoid.c,v 7.2 91/02/22 09:37:00 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/sprintoid.c,v 7.2 91/02/22 09:37:00 mrose Interim $  *  *  * $Log:	sprintoid.c,v $  * Revision 7.2  91/02/22  09:37:00  mrose  * Interim 6.8  *   * Revision 7.1  90/08/18  00:44:34  mrose  * touch-up  *   * Revision 7.0  89/11/23  22:13:42  mrose  * Release 6.0  *   */
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

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|sprintoid
parameter_list|(
name|oid
parameter_list|)
specifier|register
name|OID
name|oid
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|unsigned
name|int
modifier|*
name|ip
decl_stmt|;
specifier|register
name|char
modifier|*
name|bp
decl_stmt|,
modifier|*
name|cp
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
name|oid
operator|==
name|NULLOID
operator|||
name|oid
operator|->
name|oid_nelem
operator|<
literal|1
condition|)
return|return
literal|""
return|;
name|bp
operator|=
name|buffer
expr_stmt|;
for|for
control|(
name|ip
operator|=
name|oid
operator|->
name|oid_elements
operator|,
name|i
operator|=
name|oid
operator|->
name|oid_nelem
operator|,
name|cp
operator|=
literal|""
init|;
name|i
operator|--
operator|>
literal|0
condition|;
name|ip
operator|++
operator|,
name|cp
operator|=
literal|"."
control|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|bp
argument_list|,
literal|"%s%u"
argument_list|,
name|cp
argument_list|,
operator|*
name|ip
argument_list|)
expr_stmt|;
name|bp
operator|+=
name|strlen
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
return|return
name|buffer
return|;
block|}
end_function

end_unit

