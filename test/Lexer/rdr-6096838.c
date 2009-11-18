begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: clang-cc -fsyntax-only -verify %s  * RUN: clang-cc -std=gnu89 -fsyntax-only -verify %s  rdar://6096838  */
end_comment

begin_decl_stmt
name|long
name|double
name|d
init|=
literal|0x0
literal|.0000003ffffffff00000p
operator|-
literal|16357L
decl_stmt|;
end_decl_stmt

end_unit

