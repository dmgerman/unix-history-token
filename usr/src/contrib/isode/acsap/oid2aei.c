begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* oid2aei.c - application entity titles -- OID to AE info  */
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
literal|"$Header: /f/osi/acsap/RCS/oid2aei.c,v 7.1 91/02/22 09:14:48 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/acsap/RCS/oid2aei.c,v 7.1 91/02/22 09:14:48 mrose Interim $  *  *  * $Log:	oid2aei.c,v $  * Revision 7.1  91/02/22  09:14:48  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:22:18  mrose  * Release 6.0  *   */
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

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|AEI
name|oid2aei
parameter_list|(
name|oid
parameter_list|)
name|OID
name|oid
decl_stmt|;
block|{
specifier|static
name|AEInfo
name|aeinfo
decl_stmt|;
name|AEI
name|aei
init|=
operator|&
name|aeinfo
decl_stmt|;
specifier|static
name|PE
name|pe
init|=
name|NULLPE
decl_stmt|;
if|if
condition|(
name|pe
condition|)
name|pe_free
argument_list|(
name|pe
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|aei
argument_list|,
sizeof|sizeof
expr|*
name|aei
argument_list|)
expr_stmt|;
name|aei
operator|->
name|aei_ap_title
operator|=
name|pe
operator|=
name|obj2prim
argument_list|(
name|oid
argument_list|,
name|PE_CLASS_UNIV
argument_list|,
name|PE_PRIM_OID
argument_list|)
expr_stmt|;
return|return
name|aei
return|;
block|}
end_function

end_unit

