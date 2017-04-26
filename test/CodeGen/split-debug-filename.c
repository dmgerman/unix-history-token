begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=limited -split-dwarf-file foo.dwo -S -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=limited -enable-split-dwarf -split-dwarf-file foo.dwo -S -emit-llvm -o - %s | FileCheck --check-prefix=VANILLA %s
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Testing to ensure that the dwo name gets output into the compile unit.
end_comment

begin_comment
comment|// CHECK: !DICompileUnit({{.*}}, splitDebugFilename: "foo.dwo"
end_comment

begin_comment
comment|// Testing to ensure that the dwo name is not output into the compile unit if
end_comment

begin_comment
comment|// it's for vanilla split-dwarf rather than split-dwarf for implicit modules.
end_comment

begin_comment
comment|// VANILLA-NOT: splitDebugFilename
end_comment

end_unit

