begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)ingresname.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  MAKE INGRES FILE NAME ** **	The null-terminated string 'iname' is converted to a **	file name as used by the ingres relations.  The name **	of the relation is padded out to be MAXNAME bytes long, **	and the two-character id 'id' is appended.  The whole **	thing will be null-terminated and put into 'outname'. ** **	'Outname' must be at least MAXNAME + 3 bytes long. */
end_comment

begin_macro
name|ingresname
argument_list|(
argument|iname
argument_list|,
argument|id
argument_list|,
argument|outname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|iname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|outname
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|extern
name|char
modifier|*
name|pmove
parameter_list|()
function_decl|;
name|p
operator|=
name|outname
expr_stmt|;
name|p
operator|=
name|pmove
argument_list|(
name|iname
argument_list|,
name|p
argument_list|,
name|MAXNAME
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
name|bmove
argument_list|(
name|id
argument_list|,
name|p
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|p
index|[
literal|2
index|]
operator|=
name|NULL
expr_stmt|;
block|}
end_block

end_unit

