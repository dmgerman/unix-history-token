begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* str2oid.c - string to object identifier */
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
literal|"$Header: /f/osi/psap/RCS/str2oid.c,v 7.1 91/02/22 09:37:04 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/str2oid.c,v 7.1 91/02/22 09:37:04 mrose Interim $  *  *  * $Log:	str2oid.c,v $  * Revision 7.1  91/02/22  09:37:04  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:46  mrose  * Release 6.0  *   */
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
name|OID
name|str2oid
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
specifier|static
name|struct
name|OIDentifier
name|oids
decl_stmt|;
specifier|static
name|unsigned
name|int
name|elements
index|[
name|NELEM
operator|+
literal|1
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|i
operator|=
name|str2elem
argument_list|(
name|s
argument_list|,
name|elements
argument_list|)
operator|)
operator|<
literal|1
condition|)
return|return
name|NULLOID
return|;
name|oids
operator|.
name|oid_elements
operator|=
name|elements
operator|,
name|oids
operator|.
name|oid_nelem
operator|=
name|i
expr_stmt|;
return|return
operator|(
operator|&
name|oids
operator|)
return|;
block|}
end_function

end_unit

