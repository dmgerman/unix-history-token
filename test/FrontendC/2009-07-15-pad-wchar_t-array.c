begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function
name|signed
name|short
name|_iodbcdm_sqlerror
parameter_list|( )
block|{
name|wchar_t
name|_sqlState
index|[
literal|6
index|]
init|=
block|{
literal|L"\0"
block|}
decl_stmt|;
block|}
end_function

end_unit

