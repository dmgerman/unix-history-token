begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_struct
struct|struct
block|{
name|wchar_t
modifier|*
name|name
decl_stmt|;
block|}
name|syms
init|=
block|{
literal|L"NUL"
block|}
struct|;
end_struct

end_unit

