begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only -verify %s
end_comment

begin_comment
comment|// NULL is rdefined in stddef.h
end_comment

begin_define
define|#
directive|define
name|NULL
value|((void*) 0)
end_define

begin_comment
comment|// These are headers bundled with Clang.
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_typedef
typedef|typedef
name|__builtin_va_list
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T
end_ifndef

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T
end_ifndef

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|*
literal|L""
argument_list|)
name|wchar_t
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|(
name|wchar_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bar
parameter_list|(
name|size_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
modifier|*
name|baz
parameter_list|()
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|void
name|quz
parameter_list|()
block|{
name|va_list
name|y
decl_stmt|;
block|}
end_function

end_unit

