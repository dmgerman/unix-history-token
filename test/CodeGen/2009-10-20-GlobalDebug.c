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
comment|// CHECK:  !"0x34\00localstatic\00localstatic\00\005\001\001", !{{.*}}, !{{.*}}, !{{.*}}, i32* @main.localstatic, null} ; [ DW_TAG_variable ]
end_comment

begin_comment
comment|// CHECK:  !"0x34\00global\00global\00\003\000\001", null, !{{.*}}, !{{.*}}, i32* @global, null} ; [ DW_TAG_variable ]
end_comment

end_unit

