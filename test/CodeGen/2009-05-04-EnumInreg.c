begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple i686-apple-darwin -mregparm 3 %s -o - | FileCheck %s
end_comment

begin_comment
comment|// PR3967
end_comment

begin_enum
enum|enum
name|kobject_action
block|{
name|KOBJ_ADD
block|,
name|KOBJ_REMOVE
block|,
name|KOBJ_CHANGE
block|,
name|KOBJ_MOVE
block|,
name|KOBJ_ONLINE
block|,
name|KOBJ_OFFLINE
block|,
name|KOBJ_MAX
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|kobject
struct_decl|;
end_struct_decl

begin_comment
comment|// CHECK: i32 inreg %action
end_comment

begin_function
name|int
name|kobject_uevent
parameter_list|(
name|struct
name|kobject
modifier|*
name|kobj
parameter_list|,
name|enum
name|kobject_action
name|action
parameter_list|)
block|{}
end_function

end_unit

