begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test core -print-source-symbols -- %s -target x86_64-apple-macosx10.7 | FileCheck %s
end_comment

begin_struct
struct|struct
name|MyStruct
block|{
name|int
name|myfield
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|MyValToSet
block|}
enum|;
end_enum

begin_comment
comment|// CHECK: [[@LINE+1]]:14 | struct/C | MyStruct |
end_comment

begin_decl_stmt
specifier|const
name|struct
name|MyStruct
name|_MyStruct
index|[]
index|[
literal|16
index|]
index|[
literal|3
index|]
index|[
literal|3
index|]
index|[
literal|2
index|]
index|[
literal|2
index|]
init|=
block|{
index|[
literal|0
index|]
operator|=
block|{
index|[
literal|0
index|]
operator|=
block|{
index|[
literal|0
index|]
operator|=
block|{
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
block|{
index|[
literal|0
index|]
operator|=
block|{
comment|// CHECK: [[@LINE+2]]:14 | field/C | myfield | {{.*}} | Ref,RelCont |
comment|// CHECK: [[@LINE+1]]:24 | enumerator/C | MyValToSet |
operator|.
name|myfield
operator|=
name|MyValToSet
block|,
comment|// CHECK-NOT: | field/C | myfield |
comment|// CHECK-NOT: | enumerator/C | MyValToSet |
block|}
block|,         }
block|,       }
block|,     }
block|,   }
block|, }
decl_stmt|;
end_decl_stmt

end_unit

