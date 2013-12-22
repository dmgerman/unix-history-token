begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -pedantic -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -pedantic -verify -DPREDECLARE
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PREDECLARE
end_ifdef

begin_comment
comment|// PR16344
end_comment

begin_comment
comment|// Clang has defined 'vfprint' in builtin list. If the following line occurs before any other
end_comment

begin_comment
comment|// `vfprintf' in this file, and we getPreviousDecl()->getTypeSourceInfo() on it, then we will
end_comment

begin_comment
comment|// get a null pointer since the one in builtin list doesn't has valid TypeSourceInfo.
end_comment

begin_function
name|int
name|vfprintf
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR4290
end_comment

begin_comment
comment|// The following declaration is compatible with vfprintf, so we shouldn't
end_comment

begin_comment
comment|// warn.
end_comment

begin_function_decl
name|int
name|vfprintf
parameter_list|()
function_decl|;
end_function_decl

end_unit

