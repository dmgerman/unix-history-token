begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994 Henry Spencer.  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Henry Spencer of the University of Toronto.  *  * %sccs.include.redist.c%  *  *	@(#)cclass.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* character-class table */
end_comment

begin_struct
specifier|static
struct|struct
name|cclass
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|chars
decl_stmt|;
name|char
modifier|*
name|multis
decl_stmt|;
block|}
name|cclasses
index|[]
init|=
block|{
literal|"alnum"
block|,
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\ 0123456789"
block|,
literal|""
block|,
literal|"alpha"
block|,
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
block|,
literal|""
block|,
literal|"blank"
block|,
literal|" \t"
block|,
literal|""
block|,
literal|"cntrl"
block|,
literal|"\007\b\t\n\v\f\r\1\2\3\4\5\6\16\17\20\21\22\23\24\ \25\26\27\30\31\32\33\34\35\36\37\177"
block|,
literal|""
block|,
literal|"digit"
block|,
literal|"0123456789"
block|,
literal|""
block|,
literal|"graph"
block|,
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\ 0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
block|,
literal|""
block|,
literal|"lower"
block|,
literal|"abcdefghijklmnopqrstuvwxyz"
block|,
literal|""
block|,
literal|"print"
block|,
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\ 0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ "
block|,
literal|""
block|,
literal|"punct"
block|,
literal|"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
block|,
literal|""
block|,
literal|"space"
block|,
literal|"\t\n\v\f\r "
block|,
literal|""
block|,
literal|"upper"
block|,
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
block|,
literal|""
block|,
literal|"xdigit"
block|,
literal|"0123456789ABCDEFabcdef"
block|,
literal|""
block|,
name|NULL
block|,
literal|0
block|,
literal|""
block|}
struct|;
end_struct

end_unit

