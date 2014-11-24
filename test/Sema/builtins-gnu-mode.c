begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -std=c99 %s
end_comment

begin_comment
comment|// PR16138
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_decl_stmt
name|int
name|alloca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stpcpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stpncpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strdup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strndup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rindex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bzero
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strcasecmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strncasecmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_exit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_longjmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|siglongjmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strlcpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strlcat
decl_stmt|;
end_decl_stmt

end_unit

