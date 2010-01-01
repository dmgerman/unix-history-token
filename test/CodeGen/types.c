begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm<%s
end_comment

begin_struct
struct|struct
name|FileName
block|{
name|struct
name|FileName
modifier|*
name|next
decl_stmt|;
block|}
modifier|*
name|fnhead
struct|;
end_struct

begin_struct
struct|struct
name|ieeeExternal
block|{
name|struct
name|ieeeExternal
modifier|*
name|next
decl_stmt|;
block|}
modifier|*
name|exthead
struct|;
end_struct

begin_function
name|void
name|test1
parameter_list|()
block|{
name|struct
name|ieeeExternal
modifier|*
name|exttmp
init|=
name|exthead
decl_stmt|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|MpegEncContext
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|MpegEncContext
block|{
name|int
name|pb
decl_stmt|;
block|}
name|MpegEncContext
typedef|;
end_typedef

begin_function
specifier|static
name|void
name|test2
parameter_list|(
name|void
parameter_list|)
block|{
name|MpegEncContext
name|s
decl_stmt|;
name|s
operator|.
name|pb
expr_stmt|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|Village
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|List
block|{
name|struct
name|Village
modifier|*
name|v
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Village
block|{
name|struct
name|List
name|returned
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test3
parameter_list|(
name|struct
name|List
name|a
parameter_list|)
block|{ }
end_function

end_unit

