begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 2000 Free Software Foundation, Inc.  *  *  Gaius Mulley (gaius@glam.ac.uk) wrote output.cc  *  but it owes a huge amount of ideas and raw code from  *  James Clark (jjc@jclark.com) grops/ps.cc.  *  *  html_chars.h  *  *  provides a diacritical character combination table for html  */
end_comment

begin_struct
struct|struct
name|diacritical_desc
block|{
name|char
modifier|*
name|mark
decl_stmt|;
name|char
modifier|*
name|second_troff_char
decl_stmt|;
name|char
name|translation
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|diacritical_desc
name|diacritical_table
index|[]
init|=
block|{
block|{
literal|"ad"
block|,
literal|"aeiouyAEIOU"
block|,
literal|':'
block|, }
block|,
comment|/* */
block|{
literal|"ac"
block|,
literal|"cC"
block|,
literal|','
block|, }
block|,
comment|/* cedilla */
block|{
literal|"aa"
block|,
literal|"aeiouyAEIOU"
block|,
literal|'\''
block|, }
block|,
comment|/* acute */
block|{
name|NULL
block|,
name|NULL
block|,
operator|(
name|char
operator|)
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

end_unit

