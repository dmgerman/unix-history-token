begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify< %s
end_comment

begin_typedef
typedef|typedef
name|float
name|CGFloat
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NSPoint
block|{
name|CGFloat
name|x
decl_stmt|;
name|CGFloat
name|y
decl_stmt|;
block|}
name|NSPoint
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NSSize
block|{
name|CGFloat
name|width
decl_stmt|;
name|CGFloat
name|height
decl_stmt|;
block|}
name|NSSize
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NSRect
block|{
name|NSPoint
name|origin
decl_stmt|;
name|NSSize
name|size
decl_stmt|;
block|}
name|NSRect
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|NSPoint
name|NSZeroPoint
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|NSSize
name|canvasSize
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|func
parameter_list|()
block|{
specifier|const
name|NSRect
name|canvasRect
init|=
block|{
name|NSZeroPoint
block|,
name|canvasSize
argument_list|()
block|}
decl_stmt|;
block|}
end_function

end_unit

