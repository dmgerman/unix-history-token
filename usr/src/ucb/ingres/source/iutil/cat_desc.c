begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<access.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)cat_desc.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **	SYSTEM RELATION DESCRIPTOR CACHE DEFINITION ** */
end_comment

begin_decl_stmt
name|DESC
name|Reldes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Attdes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Inddes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Treedes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Prodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Intdes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|desxx
name|Desxx
index|[]
init|=
block|{
literal|"relation"
block|,
operator|&
name|Reldes
block|,
operator|&
name|Admin
operator|.
name|adreld
block|,
literal|"attribute"
block|,
operator|&
name|Attdes
block|,
operator|&
name|Admin
operator|.
name|adattd
block|,
literal|"indexes"
block|,
operator|&
name|Inddes
block|,
name|NULL
block|,
literal|"tree"
block|,
operator|&
name|Treedes
block|,
name|NULL
block|,
literal|"protect"
block|,
operator|&
name|Prodes
block|,
name|NULL
block|,
literal|"integrities"
block|,
operator|&
name|Intdes
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

