begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-check-objc-mem %s -analyzer-store=region
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-check-objc-mem %s -analyzer-store=basic
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_CREAT
end_ifndef

begin_define
define|#
directive|define
name|O_CREAT
value|0x0200
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|0x0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_open
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
name|int
name|fd
decl_stmt|;
name|fd
operator|=
name|open
argument_list|(
name|path
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
comment|// no-warning
if|if
condition|(
operator|!
name|fd
condition|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|fd
operator|=
name|open
argument_list|(
name|path
argument_list|,
name|O_CREAT
argument_list|)
expr_stmt|;
comment|// expected-warning{{Call to 'open' requires a third argument when the 'O_CREAT' flag is set}}
if|if
condition|(
operator|!
name|fd
condition|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

