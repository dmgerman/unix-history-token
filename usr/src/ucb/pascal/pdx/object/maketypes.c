begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)maketypes.c 1.1 1/18/82"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * make symbols  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"sym.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"sym/btypes.h"
end_include

begin_include
include|#
directive|include
file|"sym/classes.h"
end_include

begin_include
include|#
directive|include
file|"sym/sym.rep"
end_include

begin_comment
comment|/*  * point the basic types in the right direction  */
end_comment

begin_macro
name|maketypes
argument_list|()
end_macro

begin_block
block|{
name|t_int
operator|=
name|st_lookup
argument_list|(
name|symtab
argument_list|,
literal|"integer"
argument_list|)
operator|->
name|type
expr_stmt|;
name|t_real
operator|=
name|st_lookup
argument_list|(
name|symtab
argument_list|,
literal|"real"
argument_list|)
operator|->
name|type
expr_stmt|;
name|t_char
operator|=
name|st_lookup
argument_list|(
name|symtab
argument_list|,
literal|"char"
argument_list|)
operator|->
name|type
expr_stmt|;
name|t_boolean
operator|=
name|st_lookup
argument_list|(
name|symtab
argument_list|,
literal|"boolean"
argument_list|)
operator|->
name|type
expr_stmt|;
if|if
condition|(
name|t_int
operator|==
name|NIL
operator|||
name|t_real
operator|==
name|NIL
operator|||
name|t_char
operator|==
name|NIL
operator|||
name|t_boolean
operator|==
name|NIL
condition|)
block|{
name|panic
argument_list|(
literal|"basic types are missing from namelist"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * enter a keyword in the given table  */
end_comment

begin_macro
name|make_keyword
argument_list|(
argument|table
argument_list|,
argument|name
argument_list|,
argument|tnum
argument_list|)
end_macro

begin_decl_stmt
name|SYMTAB
modifier|*
name|table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tnum
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|SYM
modifier|*
name|s
decl_stmt|;
name|s
operator|=
name|st_insert
argument_list|(
name|table
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|s
operator|->
name|class
operator|=
name|BADUSE
expr_stmt|;
name|s
operator|->
name|blkno
operator|=
literal|0
expr_stmt|;
name|s
operator|->
name|symvalue
operator|.
name|token
operator|.
name|toknum
operator|=
name|tnum
expr_stmt|;
block|}
end_block

end_unit

