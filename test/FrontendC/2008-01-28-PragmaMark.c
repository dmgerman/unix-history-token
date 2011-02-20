begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -Werror -S %s -o /dev/null
end_comment

begin_pragma
pragma|#
directive|pragma
name|mark
name|LLVM
literal|'s world
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|DO_ERROR
end_ifdef

begin_error
error|#
directive|error
error|LLVM's world
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

end_unit

