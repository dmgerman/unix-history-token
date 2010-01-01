begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s
end_comment

begin_comment
comment|// PR2414
end_comment

begin_struct
struct|struct
name|mad_frame
block|{}
struct|;
end_struct

begin_enum
enum|enum
name|mad_flow
block|{}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|mad_flow
name|filter_func_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mad_frame
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|filter_func_t
name|mono_filter
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|addfilter2
parameter_list|(
name|filter_func_t
modifier|*
name|func
parameter_list|)
block|{}
end_function

begin_function
name|void
name|setup_filters
parameter_list|()
block|{
name|addfilter2
argument_list|(
name|mono_filter
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

