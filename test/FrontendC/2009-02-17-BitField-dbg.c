begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check bitfields.
end_comment

begin_comment
comment|// RUN: %llvmgcc -S -O0 -g %s -o - | llvm-as | \
end_comment

begin_comment
comment|// RUN: llc --disable-fp-elim -o 2009-02-17-BitField-dbg.s
end_comment

begin_comment
comment|// RUN: %compile_c 2009-02-17-BitField-dbg.s -o 2009-02-17-BitField-dbg.o
end_comment

begin_comment
comment|// RUN: echo {ptype mystruct}> %t2
end_comment

begin_comment
comment|// RUN: gdb -q -batch -n -x %t2 2009-02-17-BitField-dbg.o | \
end_comment

begin_comment
comment|// RUN:   tee 2009-02-17-BitField-dbg.out | grep "int a : 4"
end_comment

begin_struct
struct|struct
block|{
name|int
name|a
range|:
literal|4
decl_stmt|;
name|int
name|b
range|:
literal|2
decl_stmt|;
block|}
name|mystruct
struct|;
end_struct

end_unit

