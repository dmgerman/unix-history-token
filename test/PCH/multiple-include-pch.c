begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t1.pch %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t2.pch %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t1.pch -include-pch %t2.pch -verify
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

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_warning
warning|#
directive|warning
warning|parsed this
end_warning

begin_comment
comment|// expected-warning@-1 {{parsed this}}
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
name|x
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

