begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o -
end_comment

begin_comment
comment|// PR4610
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_struct
struct|struct
name|ref
block|{
name|struct
name|ref
modifier|*
name|next
decl_stmt|;
block|}
name|refs
struct|;
end_struct

end_unit

