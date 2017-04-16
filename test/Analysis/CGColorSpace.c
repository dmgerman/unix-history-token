begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,osx.cocoa.RetainCount -analyzer-store=region -verify %s
end_comment

begin_typedef
typedef|typedef
name|struct
name|CGColorSpace
modifier|*
name|CGColorSpaceRef
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|CGColorSpaceRef
name|CGColorSpaceCreateDeviceRGB
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CGColorSpaceRef
name|CGColorSpaceRetain
parameter_list|(
name|CGColorSpaceRef
name|space
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CGColorSpaceRelease
parameter_list|(
name|CGColorSpaceRef
name|space
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|()
block|{
name|CGColorSpaceRef
name|X
init|=
name|CGColorSpaceCreateDeviceRGB
argument_list|()
decl_stmt|;
comment|// expected-warning{{leak}}
name|CGColorSpaceRetain
argument_list|(
name|X
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fb
parameter_list|()
block|{
name|CGColorSpaceRef
name|X
init|=
name|CGColorSpaceCreateDeviceRGB
argument_list|()
decl_stmt|;
name|CGColorSpaceRetain
argument_list|(
name|X
argument_list|)
expr_stmt|;
name|CGColorSpaceRelease
argument_list|(
name|X
argument_list|)
expr_stmt|;
name|CGColorSpaceRelease
argument_list|(
name|X
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

