begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-apple-darwin9 -analyzer-checker=core,alpha.core -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// PR 4164: http://llvm.org/bugs/show_bug.cgi?id=4164
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Eventually this should be pulled into misc-ps.m.  This is in a separate test
end_comment

begin_comment
comment|// file for now to play around with the specific issues for BasicStoreManager
end_comment

begin_comment
comment|// and StoreManager (i.e., we can make a copy of this file for either
end_comment

begin_comment
comment|// StoreManager should one start to fail in the near future).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The basic issue is that the VarRegion for 'size' is casted to (char*),
end_comment

begin_comment
comment|// resulting in an ElementRegion.  'getsockopt' is an unknown function that
end_comment

begin_comment
comment|// takes a void*, which means the ElementRegion should get stripped off.
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__darwin_socklen_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__darwin_socklen_t
name|socklen_t
typedef|;
end_typedef

begin_function_decl
name|int
name|getsockopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
specifier|restrict
parameter_list|,
name|socklen_t
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test1
parameter_list|()
block|{
name|int
name|s
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|size
decl_stmt|;
name|socklen_t
name|size_len
init|=
sizeof|sizeof
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|getsockopt
argument_list|(
name|s
argument_list|,
literal|0xffff
argument_list|,
literal|0x1001
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|size
argument_list|,
operator|&
name|size_len
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|size
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Similar case: instead of passing a 'void*', we pass 'char*'.  In this
end_comment

begin_comment
comment|// case we pass an ElementRegion to the invalidation logic.  Since it is
end_comment

begin_comment
comment|// an ElementRegion that just layers on top of another typed region and the
end_comment

begin_comment
comment|// ElementRegion itself has elements whose type are integral (essentially raw
end_comment

begin_comment
comment|// data) we strip off the ElementRegion when doing the invalidation.
end_comment

begin_function_decl
name|int
name|takes_charptr
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test2
parameter_list|()
block|{
name|int
name|size
decl_stmt|;
if|if
condition|(
name|takes_charptr
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|size
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|size
return|;
comment|// no-warning
block|}
end_function

end_unit

