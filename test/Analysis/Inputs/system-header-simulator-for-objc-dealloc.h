begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_define
define|#
directive|define
name|nil
value|((id)0)
end_define

begin_typedef
typedef|typedef
name|signed
name|char
name|BOOL
typedef|;
end_typedef

begin_expr_stmt
unit|@
name|protocol
name|NSObject
operator|-
operator|(
name|BOOL
operator|)
name|isEqual
operator|:
operator|(
name|id
operator|)
name|object
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|Class
operator|)
name|class
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|NSObject
operator|<
name|NSObject
operator|>
block|{}
operator|+
operator|(
name|instancetype
operator|)
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|dealloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|init
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|retain
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|oneway
name|void
operator|)
name|release
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|NSRunLoop
operator|:
name|NSObject
operator|+
operator|(
name|NSRunLoop
operator|*
operator|)
name|currentRunLoop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|cancelPerformSelectorsWithTarget
operator|:
operator|(
name|id
operator|)
name|target
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|NSNotificationCenter
operator|:
name|NSObject
operator|+
operator|(
name|NSNotificationCenter
operator|*
operator|)
name|defaultCenter
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|removeObserver
operator|:
operator|(
name|id
operator|)
name|observer
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_typedef
typedef|typedef
name|struct
name|objc_selector
modifier|*
name|SEL
typedef|;
end_typedef

begin_function_decl
name|void
name|_Block_release
parameter_list|(
specifier|const
name|void
modifier|*
name|aBlock
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|Block_release
parameter_list|(
modifier|...
parameter_list|)
value|_Block_release((const void *)(__VA_ARGS__))
end_define

begin_decl_stmt
unit|@
name|interface
name|CIFilter
range|:
name|NSObject
expr|@
name|end
end_decl_stmt

end_unit

