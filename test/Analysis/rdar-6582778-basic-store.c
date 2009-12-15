begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=basic -verify %s
end_comment

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|CFTypeRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|CFTimeInterval
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CFTimeInterval
name|CFAbsoluteTime
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFAllocator
modifier|*
name|CFAllocatorRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFDate
modifier|*
name|CFDateRef
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|CFDateRef
name|CFDateCreate
parameter_list|(
name|CFAllocatorRef
name|allocator
parameter_list|,
name|CFAbsoluteTime
name|at
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CFAbsoluteTime
name|CFAbsoluteTimeGetCurrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|CFAbsoluteTime
name|t
init|=
name|CFAbsoluteTimeGetCurrent
argument_list|()
decl_stmt|;
name|CFTypeRef
name|vals
index|[]
init|=
block|{
name|CFDateCreate
argument_list|(
literal|0
argument_list|,
argument|t
argument_list|)
block|}
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_decl_stmt
name|CFTypeRef
name|global
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{
name|CFAbsoluteTime
name|t
init|=
name|CFAbsoluteTimeGetCurrent
argument_list|()
decl_stmt|;
name|global
operator|=
name|CFDateCreate
argument_list|(
literal|0
argument_list|,
name|t
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

