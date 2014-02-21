begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MCInstPrinter.h - Convert an MCInst to target assembly syntax -----===//
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
name|LLVM_MC_MCINSTPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCINSTPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|namespace
name|HexStyle
block|{
enum|enum
name|Style
block|{
name|C
block|,
comment|///< 0xff
name|Asm
comment|///< 0ffh
block|}
enum|;
block|}
comment|/// MCInstPrinter - This is an instance of a target assembly language printer
comment|/// that converts an MCInst to valid target assembly syntax.
name|class
name|MCInstPrinter
block|{
name|protected
label|:
comment|/// CommentStream - a stream that comments can be emitted to if desired.
comment|/// Each comment must end with a newline.  This will be null if verbose
comment|/// assembly emission is disable.
name|raw_ostream
modifier|*
name|CommentStream
decl_stmt|;
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
decl_stmt|;
specifier|const
name|MCInstrInfo
modifier|&
name|MII
decl_stmt|;
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
decl_stmt|;
comment|/// The current set of available features.
name|uint64_t
name|AvailableFeatures
decl_stmt|;
comment|/// True if we are printing marked up assembly.
name|bool
name|UseMarkup
decl_stmt|;
comment|/// True if we are printing immediates as hex.
name|bool
name|PrintImmHex
decl_stmt|;
comment|/// Which style to use for printing hexadecimal values.
name|HexStyle
operator|::
name|Style
name|PrintHexStyle
expr_stmt|;
comment|/// Utility function for printing annotations.
name|void
name|printAnnotation
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|StringRef
name|Annot
parameter_list|)
function_decl|;
name|public
label|:
name|MCInstPrinter
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|mai
argument_list|,
specifier|const
name|MCInstrInfo
operator|&
name|mii
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|mri
argument_list|)
operator|:
name|CommentStream
argument_list|(
literal|0
argument_list|)
operator|,
name|MAI
argument_list|(
name|mai
argument_list|)
operator|,
name|MII
argument_list|(
name|mii
argument_list|)
operator|,
name|MRI
argument_list|(
name|mri
argument_list|)
operator|,
name|AvailableFeatures
argument_list|(
literal|0
argument_list|)
operator|,
name|UseMarkup
argument_list|(
literal|0
argument_list|)
operator|,
name|PrintImmHex
argument_list|(
literal|0
argument_list|)
operator|,
name|PrintHexStyle
argument_list|(
argument|HexStyle::C
argument_list|)
block|{}
name|virtual
operator|~
name|MCInstPrinter
argument_list|()
expr_stmt|;
comment|/// setCommentStream - Specify a stream to emit comments to.
name|void
name|setCommentStream
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
block|{
name|CommentStream
operator|=
operator|&
name|OS
expr_stmt|;
block|}
comment|/// printInst - Print the specified MCInst to the specified raw_ostream.
comment|///
name|virtual
name|void
name|printInst
parameter_list|(
specifier|const
name|MCInst
modifier|*
name|MI
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|StringRef
name|Annot
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// getOpcodeName - Return the name of the specified opcode enum (e.g.
comment|/// "MOV32ri") or empty if we can't resolve it.
name|StringRef
name|getOpcodeName
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
decl_stmt|;
comment|/// printRegName - Print the assembler register name.
name|virtual
name|void
name|printRegName
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|RegNo
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getAvailableFeatures
argument_list|()
specifier|const
block|{
return|return
name|AvailableFeatures
return|;
block|}
name|void
name|setAvailableFeatures
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
name|AvailableFeatures
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|getUseMarkup
argument_list|()
specifier|const
block|{
return|return
name|UseMarkup
return|;
block|}
name|void
name|setUseMarkup
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|UseMarkup
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Utility functions to make adding mark ups simpler.
name|StringRef
name|markup
argument_list|(
name|StringRef
name|s
argument_list|)
decl|const
decl_stmt|;
name|StringRef
name|markup
argument_list|(
name|StringRef
name|a
argument_list|,
name|StringRef
name|b
argument_list|)
decl|const
decl_stmt|;
name|bool
name|getPrintImmHex
argument_list|()
specifier|const
block|{
return|return
name|PrintImmHex
return|;
block|}
name|void
name|setPrintImmHex
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|PrintImmHex
operator|=
name|Value
expr_stmt|;
block|}
name|HexStyle
operator|::
name|Style
name|getPrintHexStyleHex
argument_list|()
specifier|const
block|{
return|return
name|PrintHexStyle
return|;
block|}
name|void
name|setPrintImmHex
argument_list|(
name|HexStyle
operator|::
name|Style
name|Value
argument_list|)
block|{
name|PrintHexStyle
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Utility function to print immediates in decimal or hex.
name|format_object1
operator|<
name|int64_t
operator|>
name|formatImm
argument_list|(
argument|const int64_t Value
argument_list|)
specifier|const
block|{
return|return
name|PrintImmHex
operator|?
name|formatHex
argument_list|(
name|Value
argument_list|)
operator|:
name|formatDec
argument_list|(
name|Value
argument_list|)
return|;
block|}
comment|/// Utility functions to print decimal/hexadecimal values.
name|format_object1
operator|<
name|int64_t
operator|>
name|formatDec
argument_list|(
argument|const int64_t Value
argument_list|)
specifier|const
expr_stmt|;
name|format_object1
operator|<
name|int64_t
operator|>
name|formatHex
argument_list|(
argument|const int64_t Value
argument_list|)
specifier|const
expr_stmt|;
name|format_object1
operator|<
name|uint64_t
operator|>
name|formatHex
argument_list|(
argument|const uint64_t Value
argument_list|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

