begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pl_tables.c - tables for presentation lists */
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
literal|"$Header: /f/osi/psap/RCS/pl_tables.c,v 7.1 91/02/22 09:36:19 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/pl_tables.c,v 7.1 91/02/22 09:36:19 mrose Interim $  *  *  * $Log:	pl_tables.c,v $  * Revision 7.1  91/02/22  09:36:19  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:08  mrose  * Release 6.0  *   */
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
comment|DATA */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pe_classlist
index|[]
init|=
block|{
literal|"UNIV"
block|,
literal|"APPL"
block|,
literal|"CONT"
block|,
literal|"PRIV"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pe_maxclass
init|=
sizeof|sizeof
name|pe_classlist
operator|/
sizeof|sizeof
name|pe_classlist
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pe_univlist
index|[]
init|=
block|{
literal|"EOC"
block|,
literal|"BOOL"
block|,
literal|"INT"
block|,
literal|"BITS"
block|,
literal|"OCTS"
block|,
literal|"NULL"
block|,
literal|"OID"
block|,
literal|"ODE"
block|,
literal|"EXTN"
block|,
literal|"REAL"
block|,
literal|"ENUM"
block|,
literal|"ENCR"
block|,
name|NULLCP
block|,
name|NULLCP
block|,
name|NULLCP
block|,
name|NULLCP
block|,
literal|"SEQ"
block|,
literal|"SET"
block|,
literal|"NUMS"
block|,
literal|"PRTS"
block|,
literal|"T61S"
block|,
literal|"VTXS"
block|,
literal|"IA5S"
block|,
literal|"UTCT"
block|,
literal|"GENT"
block|,
literal|"GFXS"
block|,
literal|"VISS"
block|,
literal|"GENS"
block|,
literal|"CHRS"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pe_maxuniv
init|=
sizeof|sizeof
name|pe_univlist
operator|/
sizeof|sizeof
name|pe_univlist
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pe_maxappl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|pe_applist
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pe_maxpriv
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|pe_privlist
init|=
name|NULL
decl_stmt|;
end_decl_stmt

end_unit

