begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s -o -
end_comment

begin_comment
comment|// PR2419
end_comment

begin_struct
struct|struct
name|Mem
block|{
union|union
block|{         }
name|u
union|;
block|}
struct|;
end_struct

begin_function
name|struct
name|Mem
modifier|*
name|columnMem
parameter_list|()
block|{
specifier|static
specifier|const
name|struct
name|Mem
name|nullMem
init|=
block|{
block|{}
block|}
decl_stmt|;
block|}
end_function

end_unit

