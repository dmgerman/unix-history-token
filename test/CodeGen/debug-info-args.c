begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unk-unk -o - -emit-llvm -g %s | FileCheck %s
end_comment

begin_function
name|int
name|somefunc
parameter_list|(
name|char
modifier|*
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|double
name|z
parameter_list|)
block|{
comment|// CHECK: {{.*metadata !8, i32 0, i32 0}.*DW_TAG_subroutine_type}}
comment|// CHECK: {{!8 = .*metadata ![^,]*, metadata ![^,]*, metadata ![^,]*, metadata ![^,]*}}
return|return
name|y
return|;
block|}
end_function

end_unit

