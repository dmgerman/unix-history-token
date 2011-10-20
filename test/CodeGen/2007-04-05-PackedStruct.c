begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
end_pragma

begin_enum
enum|enum
block|{
name|tA
init|=
literal|0
block|,
name|tB
init|=
literal|1
block|}
enum|;
end_enum

begin_struct
struct|struct
name|MyStruct
block|{
name|unsigned
name|long
name|A
decl_stmt|;
name|char
name|C
decl_stmt|;
name|void
modifier|*
name|B
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|bar
parameter_list|()
block|{
name|struct
name|MyStruct
name|MS
init|=
block|{
name|tB
block|,
literal|0
block|}
decl_stmt|;
block|}
end_function

end_unit

