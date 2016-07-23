begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TOOLS_LLVM_DWP_DWPERROR
end_ifndef

begin_define
define|#
directive|define
name|TOOLS_LLVM_DWP_DWPERROR
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DWPError
range|:
name|public
name|ErrorInfo
operator|<
name|DWPError
operator|>
block|{
name|public
operator|:
name|DWPError
argument_list|(
argument|std::string Info
argument_list|)
operator|:
name|Info
argument_list|(
argument|std::move(Info)
argument_list|)
block|{}
name|void
name|log
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|{
name|OS
operator|<<
name|Info
block|; }
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"Not implemented"
argument_list|)
block|;   }
specifier|static
name|char
name|ID
block|;
name|private
operator|:
name|std
operator|::
name|string
name|Info
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

