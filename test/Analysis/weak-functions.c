begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core,debug.ExprInspection,unix.Malloc,unix.cstring,alpha.unix.cstring,unix.API,osx.API,osx.cocoa.RetainCount -Wno-null-dereference -Wno-tautological-compare -analyzer-store=region -fblocks -verify %s
end_comment

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|myFunc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|myWeakFunc
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|testWeakFuncIsNull
parameter_list|()
block|{
name|clang_analyzer_eval
argument_list|(
name|myFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
if|if
condition|(
name|myWeakFunc
operator|==
name|NULL
condition|)
block|{
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
else|else
block|{
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
block|}
block|}
end_function

begin_function
name|void
name|testWeakFuncIsNot
parameter_list|()
block|{
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
if|if
condition|(
operator|!
name|myWeakFunc
condition|)
block|{
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
else|else
block|{
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
block|}
block|}
end_function

begin_function
name|void
name|testWeakFuncIsTrue
parameter_list|()
block|{
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
if|if
condition|(
name|myWeakFunc
condition|)
block|{
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
block|}
else|else
block|{
name|clang_analyzer_eval
argument_list|(
name|myWeakFunc
operator|==
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// func.c
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|g
parameter_list|(
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|p
operator|=
name|f
expr_stmt|;
name|p
operator|=
operator|&
name|f
expr_stmt|;
name|p
argument_list|()
expr_stmt|;
call|(
modifier|*
name|p
call|)
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|g
parameter_list|(
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f2
parameter_list|()
block|{
name|g
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f3
parameter_list|(
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|g
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|clang_analyzer_eval
argument_list|(
operator|!
name|f
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
name|f
argument_list|()
expr_stmt|;
name|clang_analyzer_eval
argument_list|(
operator|!
name|f
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
name|clang_analyzer_eval
argument_list|(
operator|!
name|g
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
call|(
modifier|*
name|g
call|)
argument_list|()
expr_stmt|;
name|clang_analyzer_eval
argument_list|(
operator|!
name|g
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// free.c
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t10
parameter_list|()
block|{
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|t10
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is the address of the function 't10', which is not memory allocated by malloc()}}
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// string.c : strnlen()
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|size_t
name|strlen_fn
parameter_list|()
block|{
return|return
name|strlen
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|strlen_fn
argument_list|)
return|;
comment|// expected-warning{{Argument to string length function is the address of the function 'strlen_fn', which is not a null-terminated string}}
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// unix-fns.c : dispatch_once
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|dispatch_block_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|dispatch_once_t
typedef|;
end_typedef

begin_function_decl
name|void
name|dispatch_once
parameter_list|(
name|dispatch_once_t
modifier|*
name|predicate
parameter_list|,
name|dispatch_block_t
name|block
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_dispatch_once
parameter_list|()
block|{
name|dispatch_once_t
name|pred
init|=
literal|0
decl_stmt|;
do|do
block|{
if|if
condition|(
name|__builtin_expect
argument_list|(
operator|*
operator|(
operator|&
name|pred
operator|)
argument_list|,
operator|~
literal|0l
argument_list|)
operator|!=
operator|~
literal|0l
condition|)
name|dispatch_once
argument_list|(
operator|(
operator|&
name|pred
operator|)
argument_list|,
operator|(
lambda|^
parameter_list|()
block|{}
operator|)
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|// expected-warning{{Call to 'dispatch_once' uses the local variable 'pred' for the predicate value}}
block|}
end_function

begin_function
name|void
name|test_dispatch_once_neg
parameter_list|()
block|{
specifier|static
name|dispatch_once_t
name|pred
init|=
literal|0
decl_stmt|;
do|do
block|{
if|if
condition|(
name|__builtin_expect
argument_list|(
operator|*
operator|(
operator|&
name|pred
operator|)
argument_list|,
operator|~
literal|0l
argument_list|)
operator|!=
operator|~
literal|0l
condition|)
name|dispatch_once
argument_list|(
operator|(
operator|&
name|pred
operator|)
argument_list|,
operator|(
lambda|^
parameter_list|()
block|{}
operator|)
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|// no-warning
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// retain-release-path-notes.m
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_typedef
typedef|typedef
name|struct
name|CFType
modifier|*
name|CFTypeRef
typedef|;
end_typedef

begin_function_decl
name|CFTypeRef
name|CFCreateSomething
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|CFTypeRef
name|CFGetSomething
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|CFTypeRef
name|CFCopyRuleViolation
parameter_list|()
block|{
name|CFTypeRef
name|object
init|=
name|CFGetSomething
argument_list|()
decl_stmt|;
return|return
name|object
return|;
comment|// expected-warning{{Object with a +0 retain count returned to caller where a +1 (owning) retain count is expected}}
block|}
end_function

begin_function
name|CFTypeRef
name|CFGetRuleViolation
parameter_list|()
block|{
name|CFTypeRef
name|object
init|=
name|CFCreateSomething
argument_list|()
decl_stmt|;
comment|// expected-warning{{Potential leak of an object stored into 'object'}}
return|return
name|object
return|;
block|}
end_function

end_unit

