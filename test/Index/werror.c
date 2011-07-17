begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
specifier|inline
name|int
modifier|*
name|get_int_ptr
parameter_list|(
name|float
modifier|*
name|fp
parameter_list|)
block|{
return|return
name|fp
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|FATAL
end_ifdef

begin_function_decl
name|void
name|fatal
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-FATAL: translation errors
end_comment

begin_comment
comment|// RUN: c-index-test -write-pch %t.pch -Werror %s
end_comment

begin_comment
comment|// RUN: not c-index-test -write-pch %t.pch -DFATAL -Werror %s 2>%t.err
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-FATAL %s< %t.err
end_comment

end_unit

