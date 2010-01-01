begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -pedantic -std=gnu89 -fsyntax-only -verify %s  rdar://6096838  */
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

begin_comment
comment|/* expected-warning {{ hexadecimal floating constants are a C99 feature }} */
end_comment

end_unit

