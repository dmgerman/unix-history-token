begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check for GNUMode = 1 by looking for the "linux" define which only exists
end_comment

begin_comment
comment|// for GNUMode = 1.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_error
error|#
directive|error
literal|"Submodule has GNUMode=1"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

