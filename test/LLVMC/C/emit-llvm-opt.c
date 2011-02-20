begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -emit-llvm [-S] works with -opt.
end_comment

begin_comment
comment|// RUN: llvmc -c -opt -emit-llvm -o - %s | llvm-dis | grep "@f0()" | count 1
end_comment

begin_comment
comment|// RUN: llvmc -c -opt -emit-llvm -S -o - %s | grep "@f0()" | count 1
end_comment

begin_comment
comment|// RUN: llvmc --dry-run -c -opt -emit-llvm %s |& grep "^opt"
end_comment

begin_comment
comment|// XFAIL: vg_leak
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

