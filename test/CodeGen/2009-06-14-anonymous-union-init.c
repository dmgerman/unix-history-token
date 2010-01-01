begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep "zeroinitializer, i16 16877"
end_comment

begin_comment
comment|// PR4390
end_comment

begin_struct
struct|struct
name|sysfs_dirent
block|{
union|union
block|{
struct|struct
name|sysfs_elem_dir
block|{}
name|s_dir
struct|;
block|}
union|;
name|unsigned
name|short
name|s_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|sysfs_dirent
name|sysfs_root
init|=
block|{
block|{}
block|,
literal|16877
block|}
decl_stmt|;
end_decl_stmt

end_unit

