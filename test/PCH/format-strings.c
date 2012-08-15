begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -D FOOBAR="\"\"" %s -emit-pch -o %t.pch
end_comment

begin_comment
comment|// RUN: %clang_cc1 -D FOOBAR="\"\"" %s -include-pch %t.pch
end_comment

begin_comment
comment|// rdar://11418366
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LOG
value|printf(FOOBAR "%f", __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|foo
parameter_list|()
block|{
name|LOG
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

