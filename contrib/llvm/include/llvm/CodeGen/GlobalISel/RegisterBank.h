begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/CodeGen/GlobalISel/RegisterBank.h - Register Bank ----*- C++ -*-==//
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
comment|/// \file This file declares the API of register banks.
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
name|LLVM_CODEGEN_GLOBALISEL_REGBANK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_REGBANK_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations.
name|class
name|RegisterBankInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|/// This class implements the register bank concept.
comment|/// Two instances of RegisterBank must have different ID.
comment|/// This property is enforced by the RegisterBankInfo class.
name|class
name|RegisterBank
block|{
name|private
label|:
name|unsigned
name|ID
decl_stmt|;
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
name|BitVector
name|ContainedRegClasses
decl_stmt|;
comment|/// Sentinel value used to recognize register bank not properly
comment|/// initialized yet.
specifier|static
specifier|const
name|unsigned
name|InvalidID
decl_stmt|;
comment|/// Only the RegisterBankInfo can initialize RegisterBank properly.
name|friend
name|RegisterBankInfo
decl_stmt|;
name|public
label|:
name|RegisterBank
argument_list|(
argument|unsigned ID
argument_list|,
argument|const char *Name
argument_list|,
argument|unsigned Size
argument_list|,
argument|const uint32_t *ContainedRegClasses
argument_list|,
argument|unsigned NumRegClasses
argument_list|)
empty_stmt|;
comment|/// Get the identifier of this register bank.
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
comment|/// Get a user friendly name of this register bank.
comment|/// Should be used only for debugging purposes.
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// Get the maximal size in bits that fits in this register bank.
name|unsigned
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
comment|/// Check whether this instance is ready to be used.
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
comment|/// Check if this register bank is valid. In other words,
comment|/// if it has been properly constructed.
comment|///
comment|/// \note This method does not check anything when assertions are disabled.
comment|///
comment|/// \return True is the check was successful.
name|bool
name|verify
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
decl|const
decl_stmt|;
comment|/// Check whether this register bank covers \p RC.
comment|/// In other words, check if this register bank fully covers
comment|/// the registers that \p RC contains.
comment|/// \pre isValid()
name|bool
name|covers
argument_list|(
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
decl|const
decl_stmt|;
comment|/// Check whether \p OtherRB is the same as this.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RegisterBank
operator|&
name|OtherRB
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|RegisterBank
operator|&
name|OtherRB
operator|)
specifier|const
block|{
return|return
operator|!
name|this
operator|->
name|operator
operator|==
operator|(
name|OtherRB
operator|)
return|;
block|}
comment|/// Dump the register mask on dbgs() stream.
comment|/// The dump is verbose.
name|void
name|dump
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Print the register mask on OS.
comment|/// If IsForDebug is false, then only the name of the register bank
comment|/// is printed. Otherwise, all the fields are printing.
comment|/// TRI is then used to print the name of the register classes that
comment|/// this register bank covers.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|bool
name|IsForDebug
operator|=
name|false
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
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
name|RegisterBank
operator|&
name|RegBank
operator|)
block|{
name|RegBank
operator|.
name|print
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

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

