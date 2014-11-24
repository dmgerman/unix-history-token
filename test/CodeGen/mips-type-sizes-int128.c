begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -triple mips-none-linux-gnu -emit-llvm -w -o - %s 2> %t1
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=O32 %s< %t1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-none-linux-gnu -emit-llvm -w -target-abi n32 -o - %s | FileCheck --check-prefix=NEW %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-none-linux-gnu -emit-llvm -w -o - %s | FileCheck --check-prefix=NEW %s
end_comment

begin_comment
comment|// O32 does not support __int128 so it must be tested separately
end_comment

begin_comment
comment|// N32/N64 behave the same way so their tests have been combined into NEW
end_comment

begin_function
name|int
name|check_int128
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|__int128
argument_list|)
return|;
comment|// O32: :[[@LINE]]:17: error: __int128 is not supported on this target
comment|// NEW: ret i32 16
block|}
end_function

end_unit

