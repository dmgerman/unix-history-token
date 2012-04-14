begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin10 -flto -S -g %s -o - | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|global
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|static
name|int
name|localstatic
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: !14 = metadata !{i32 {{.*}}, i32 0, metadata !5, metadata !"localstatic", metadata !"localstatic", metadata !"", metadata !6, i32 5, metadata !9, i32 1, i32 1, i32* @main.localstatic} ; [ DW_TAG_variable ]
end_comment

begin_comment
comment|// CHECK: !15 = metadata !{i32 {{.*}}, i32 0, null, metadata !"global", metadata !"global", metadata !"", metadata !6, i32 3, metadata !9, i32 0, i32 1, i32* @global} ; [ DW_TAG_variable ]
end_comment

end_unit

