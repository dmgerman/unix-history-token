begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch %s -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t %s -verify
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_H
end_define

begin_function_decl
specifier|static
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|h
parameter_list|()
block|{
name|f
argument_list|()
expr_stmt|;
name|g
argument_list|()
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|void
name|g
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning@5{{function 'f' has internal linkage but is not defined}}
end_comment

begin_comment
comment|// expected-note@8{{used here}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

