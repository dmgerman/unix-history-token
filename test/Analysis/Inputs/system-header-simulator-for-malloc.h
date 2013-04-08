begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Like the compiler, the static analyzer treats some functions differently if
end_comment

begin_comment
comment|// they come from a system header -- for example, it is assumed that system
end_comment

begin_comment
comment|// functions do not arbitrarily free() their parameters, and that some bugs
end_comment

begin_comment
comment|// found in system headers cannot be fixed by the user and should be
end_comment

begin_comment
comment|// suppressed.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__OBJC__
end_if

begin_empty
empty|#import "system-header-simulator-objc.h"
end_empty

begin_decl_stmt
unit|@
name|interface
name|Wrapper
range|:
name|NSData
operator|-
operator|(
name|id
operator|)
name|initWithBytesNoCopy
operator|:
operator|(
name|void
operator|*
operator|)
name|bytes
name|length
operator|:
operator|(
name|NSUInteger
operator|)
name|len
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|implementation
name|Wrapper
operator|-
operator|(
name|id
operator|)
name|initWithBytesNoCopy
operator|:
operator|(
name|void
operator|*
operator|)
name|bytes
name|length
operator|:
operator|(
name|NSUInteger
operator|)
name|len
block|{
return|return
index|[
name|self
name|initWithBytesNoCopy
operator|:
name|bytes
name|length
operator|:
name|len
name|freeWhenDone
operator|:
literal|1
index|]
return|;
comment|// no-warning
block|}
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|CustomData
operator|:
name|NSData
operator|+
operator|(
name|id
operator|)
name|somethingNoCopy
operator|:
operator|(
name|char
operator|*
operator|)
name|bytes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|id
operator|)
name|somethingNoCopy
operator|:
operator|(
name|void
operator|*
operator|)
name|bytes
name|length
operator|:
operator|(
name|NSUInteger
operator|)
name|length
name|freeWhenDone
operator|:
operator|(
name|BOOL
operator|)
name|freeBuffer
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|id
operator|)
name|something
operator|:
operator|(
name|char
operator|*
operator|)
name|bytes
name|freeWhenDone
operator|:
operator|(
name|BOOL
operator|)
name|freeBuffer
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

