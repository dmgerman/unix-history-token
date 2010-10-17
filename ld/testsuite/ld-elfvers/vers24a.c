begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Test whether .symver x, x@foo    causes relocations against x within the same shared library    to become dynamic relocations against x@foo.  */
end_comment

begin_decl_stmt
name|int
name|x
init|=
literal|12
decl_stmt|;
end_decl_stmt

begin_asm
asm|__asm__ (".symver x, x@VERS.0");
end_asm

end_unit

