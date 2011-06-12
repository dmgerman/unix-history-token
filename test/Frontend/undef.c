begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -undef -x assembler-with-cpp -E %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_error
error|#
directive|error
literal|"Must be preprocessed as assembler."
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

