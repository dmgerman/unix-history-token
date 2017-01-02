begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_COLORPRINT_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_COLORPRINT_H_
end_define

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_include
include|#
directive|include
file|<iostream>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|benchmark
block|{
enum|enum
name|LogColor
block|{
name|COLOR_DEFAULT
block|,
name|COLOR_RED
block|,
name|COLOR_GREEN
block|,
name|COLOR_YELLOW
block|,
name|COLOR_BLUE
block|,
name|COLOR_MAGENTA
block|,
name|COLOR_CYAN
block|,
name|COLOR_WHITE
block|}
enum|;
name|std
operator|::
name|string
name|FormatString
argument_list|(
argument|const char* msg
argument_list|,
argument|va_list args
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|FormatString
argument_list|(
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
expr_stmt|;
name|void
name|ColorPrintf
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|out
argument_list|,
name|LogColor
name|color
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
name|va_list
name|args
argument_list|)
decl_stmt|;
name|void
name|ColorPrintf
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|out
argument_list|,
name|LogColor
name|color
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
decl_stmt|;
comment|// Returns true if stdout appears to be a terminal that supports colored
comment|// output, false otherwise.
name|bool
name|IsColorTerminal
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace benchmark
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BENCHMARK_COLORPRINT_H_
end_comment

end_unit

