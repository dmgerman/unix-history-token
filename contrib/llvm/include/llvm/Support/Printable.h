begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Printable.h - Print function helpers -------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file defines the Printable struct.
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
name|LLVM_SUPPORT_PRINTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_PRINTABLE_H
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// Simple wrapper around std::function<void(raw_ostream&)>.
comment|/// This class is usefull to construct print helpers for raw_ostream.
comment|///
comment|/// Example:
comment|///     Printable PrintRegister(unsigned Register) {
comment|///       return Printable([Register](raw_ostream&OS) {
comment|///         OS<< getRegisterName(Register);
comment|///       }
comment|///     }
comment|///     ... OS<< PrintRegister(Register); ...
comment|///
comment|/// Implementation note: Ideally this would just be a typedef, but doing so
comment|/// leads to operator<< being ambiguous as function has matching constructors
comment|/// in some STL versions. I have seen the problem on gcc 4.6 libstdc++ and
comment|/// microsoft STL.
name|class
name|Printable
block|{
name|public
label|:
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|>
name|Print
expr_stmt|;
name|Printable
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|>
name|Print
argument_list|)
operator|:
name|Print
argument_list|(
argument|Print
argument_list|)
block|{}
block|}
empty_stmt|;
specifier|static
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|Printable
operator|&
name|P
operator|)
block|{
name|P
operator|.
name|Print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

