begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)f_errlist.c	5.2	7/30/85  */
end_comment

begin_comment
comment|/*  * f77 I/O error messages  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|f_errlist
index|[]
init|=
block|{
comment|/* 100 */
literal|"error in format"
block|,
comment|/* 101 */
literal|"illegal unit number"
block|,
comment|/* 102 */
literal|"formatted i/o not allowed"
block|,
comment|/* 103 */
literal|"unformatted i/o not allowed"
block|,
comment|/* 104 */
literal|"direct i/o not allowed"
block|,
comment|/* 105 */
literal|"sequential i/o not allowed"
block|,
comment|/* 106 */
literal|"can't backspace file"
block|,
comment|/* 107 */
literal|"off beginning of record"
block|,
comment|/* 108 */
literal|"can't stat file"
block|,
comment|/* 109 */
literal|"no * after repeat count"
block|,
comment|/* 110 */
literal|"off end of record"
block|,
comment|/* 111 */
literal|"truncation failed"
block|,
comment|/* 112 */
literal|"incomprehensible list input"
block|,
comment|/* 113 */
literal|"out of free space"
block|,
comment|/* 114 */
literal|"unit not connected"
block|,
comment|/* 115 */
literal|"invalid data for integer format term"
block|,
comment|/* 116 */
literal|"invalid data for logical format term"
block|,
comment|/* 117 */
literal|"'new' file exists"
block|,
comment|/* 118 */
literal|"can't find 'old' file"
block|,
comment|/* 119 */
literal|"opening too many files or unknown system error"
block|,
comment|/* 120 */
literal|"requires seek ability"
block|,
comment|/* 121 */
literal|"illegal argument"
block|,
comment|/* 122 */
literal|"negative repeat count"
block|,
comment|/* 123 */
literal|"illegal operation for unit"
block|,
comment|/* 124 */
literal|"invalid data for d,e,f, or g format term"
block|,
comment|/* 125 */
literal|"illegal input for namelist"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|f_nerr
init|=
operator|(
sizeof|sizeof
argument_list|(
name|f_errlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

end_unit

