begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Timeout.h -----------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_Timeout_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Timeout_h_
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatProviders.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// A general purpose class for representing timeouts for various APIs. It's
comment|// basically an llvm::Optional<std::chrono::duration<int64_t, Ratio>>, but we
comment|// customize it a bit to enable the standard chrono implicit conversions (e.g.
comment|// from Timeout<std::milli> to Timeout<std::micro>.
comment|//
comment|// The intended meaning of the values is:
comment|// - llvm::None - no timeout, the call should wait forever
comment|// - 0 - poll, only complete the call if it will not block
comment|// ->0 - wait for a given number of units for the result
name|template
operator|<
name|typename
name|Ratio
operator|>
name|class
name|Timeout
operator|:
name|public
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|chrono
operator|::
name|duration
operator|<
name|int64_t
operator|,
name|Ratio
operator|>>
block|{
name|private
operator|:
name|template
operator|<
name|typename
name|Ratio2
operator|>
name|using
name|Dur
operator|=
name|std
operator|::
name|chrono
operator|::
name|duration
operator|<
name|int64_t
block|,
name|Ratio2
operator|>
block|;
name|template
operator|<
name|typename
name|Rep2
block|,
name|typename
name|Ratio2
operator|>
name|using
name|EnableIf
operator|=
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_convertible
operator|<
name|std
operator|::
name|chrono
operator|::
name|duration
operator|<
name|Rep2
block|,
name|Ratio2
operator|>
block|,
name|std
operator|::
name|chrono
operator|::
name|duration
operator|<
name|int64_t
block|,
name|Ratio
operator|>>
operator|::
name|value
operator|>
block|;
name|using
name|Base
operator|=
name|llvm
operator|::
name|Optional
operator|<
name|Dur
operator|<
name|Ratio
operator|>>
block|;
name|public
operator|:
name|Timeout
argument_list|(
argument|llvm::NoneType none
argument_list|)
operator|:
name|Base
argument_list|(
argument|none
argument_list|)
block|{}
name|Timeout
argument_list|(
specifier|const
name|Timeout
operator|&
name|other
argument_list|)
operator|=
expr|default
block|;
name|template
operator|<
name|typename
name|Ratio2
block|,
name|typename
operator|=
name|typename
name|EnableIf
operator|<
name|int64_t
block|,
name|Ratio2
operator|>
operator|::
name|type
operator|>
name|Timeout
argument_list|(
specifier|const
name|Timeout
operator|<
name|Ratio2
operator|>
operator|&
name|other
argument_list|)
operator|:
name|Base
argument_list|(
argument|other ? Base(Dur<Ratio>(*other)) : llvm::None
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Rep2
block|,
name|typename
name|Ratio2
block|,
name|typename
operator|=
name|typename
name|EnableIf
operator|<
name|Rep2
block|,
name|Ratio2
operator|>
operator|::
name|type
operator|>
name|Timeout
argument_list|(
specifier|const
name|std
operator|::
name|chrono
operator|::
name|duration
operator|<
name|Rep2
argument_list|,
name|Ratio2
operator|>
operator|&
name|other
argument_list|)
operator|:
name|Base
argument_list|(
argument|Dur<Ratio>(other)
argument_list|)
block|{}
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|Ratio
operator|>
expr|struct
name|format_provider
operator|<
name|lldb_private
operator|::
name|Timeout
operator|<
name|Ratio
operator|>
operator|,
name|void
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const lldb_private::Timeout<Ratio>&timeout
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|StringRef Options
argument_list|)
block|{
typedef|typedef
name|typename
name|lldb_private
operator|::
name|Timeout
operator|<
name|Ratio
operator|>
operator|::
name|value_type
name|Dur
expr_stmt|;
if|if
condition|(
operator|!
name|timeout
condition|)
name|OS
operator|<<
literal|"<infinite>"
expr_stmt|;
else|else
name|format_provider
operator|<
name|Dur
operator|>
operator|::
name|format
argument_list|(
operator|*
name|timeout
argument_list|,
name|OS
argument_list|,
name|Options
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Timeout_h_
end_comment

end_unit

