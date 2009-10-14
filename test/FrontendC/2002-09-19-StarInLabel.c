begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_extern
extern|extern void start(
end_extern

begin_asm
unit|)
asm|__asm__("start");
end_asm

begin_extern
extern|extern void _start(
end_extern

begin_asm
unit|)
asm|__asm__("_start");
end_asm

begin_extern
extern|extern void __start(
end_extern

begin_asm
unit|)
asm|__asm__("__start");
end_asm

begin_function
name|void
name|start
parameter_list|()
block|{}
end_function

begin_function
name|void
name|_start
parameter_list|()
block|{}
end_function

begin_function
name|void
name|__start
parameter_list|()
block|{}
end_function

end_unit

