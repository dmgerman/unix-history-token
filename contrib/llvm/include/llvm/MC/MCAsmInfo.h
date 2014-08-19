begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCAsmInfo.h - Asm info --------------------------*- C++ -*-===//
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
comment|// This file contains a class to be used as the basis for target specific
end_comment

begin_comment
comment|// asm writers.  This class primarily takes care of global printing constants,
end_comment

begin_comment
comment|// which are used in very similar ways across all targets.
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
name|LLVM_MC_MCASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCDirectives.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MachineLocation.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|namespace
name|ExceptionHandling
block|{
enum|enum
name|ExceptionsType
block|{
name|None
block|,
name|DwarfCFI
block|,
name|SjLj
block|,
name|ARM
block|,
name|Win64
block|}
enum|;
block|}
name|namespace
name|LCOMM
block|{
enum|enum
name|LCOMMType
block|{
name|NoAlignment
block|,
name|ByteAlignment
block|,
name|Log2Alignment
block|}
enum|;
block|}
comment|/// MCAsmInfo - This class is intended to be used as a base class for asm
comment|/// properties and features specific to the target.
name|class
name|MCAsmInfo
block|{
name|protected
label|:
comment|//===------------------------------------------------------------------===//
comment|// Properties to be set by the target writer, used to configure asm printer.
comment|//
comment|/// PointerSize - Pointer size in bytes.
comment|///               Default is 4.
name|unsigned
name|PointerSize
decl_stmt|;
comment|/// CalleeSaveStackSlotSize - Size of the stack slot reserved for
comment|///                           callee-saved registers, in bytes.
comment|///                           Default is same as pointer size.
name|unsigned
name|CalleeSaveStackSlotSize
decl_stmt|;
comment|/// IsLittleEndian - True if target is little endian.
comment|///                  Default is true.
name|bool
name|IsLittleEndian
decl_stmt|;
comment|/// StackGrowsUp - True if target stack grow up.
comment|///                Default is false.
name|bool
name|StackGrowsUp
decl_stmt|;
comment|/// HasSubsectionsViaSymbols - True if this target has the MachO
comment|/// .subsections_via_symbols directive.
name|bool
name|HasSubsectionsViaSymbols
decl_stmt|;
comment|// Default is false.
comment|/// HasMachoZeroFillDirective - True if this is a MachO target that supports
comment|/// the macho-specific .zerofill directive for emitting BSS Symbols.
name|bool
name|HasMachoZeroFillDirective
decl_stmt|;
comment|// Default is false.
comment|/// HasMachoTBSSDirective - True if this is a MachO target that supports
comment|/// the macho-specific .tbss directive for emitting thread local BSS Symbols
name|bool
name|HasMachoTBSSDirective
decl_stmt|;
comment|// Default is false.
comment|/// HasStaticCtorDtorReferenceInStaticMode - True if the compiler should
comment|/// emit a ".reference .constructors_used" or ".reference .destructors_used"
comment|/// directive after the a static ctor/dtor list.  This directive is only
comment|/// emitted in Static relocation model.
name|bool
name|HasStaticCtorDtorReferenceInStaticMode
decl_stmt|;
comment|// Default is false.
comment|/// LinkerRequiresNonEmptyDwarfLines - True if the linker has a bug and
comment|/// requires that the debug_line section be of a minimum size. In practice
comment|/// such a linker requires a non empty line sequence if a file is present.
name|bool
name|LinkerRequiresNonEmptyDwarfLines
decl_stmt|;
comment|// Default to false.
comment|/// MaxInstLength - This is the maximum possible length of an instruction,
comment|/// which is needed to compute the size of an inline asm.
name|unsigned
name|MaxInstLength
decl_stmt|;
comment|// Defaults to 4.
comment|/// MinInstAlignment - Every possible instruction length is a multiple of
comment|/// this value.  Factored out in .debug_frame and .debug_line.
name|unsigned
name|MinInstAlignment
decl_stmt|;
comment|// Defaults to 1.
comment|/// DollarIsPC - The '$' token, when not referencing an identifier or
comment|/// constant, refers to the current PC.
name|bool
name|DollarIsPC
decl_stmt|;
comment|// Defaults to false.
comment|/// SeparatorString - This string, if specified, is used to separate
comment|/// instructions from each other when on the same line.
specifier|const
name|char
modifier|*
name|SeparatorString
decl_stmt|;
comment|// Defaults to ';'
comment|/// CommentColumn - This indicates the comment num (zero-based) at
comment|/// which asm comments should be printed.
name|unsigned
name|CommentColumn
decl_stmt|;
comment|// Defaults to 40
comment|/// CommentString - This indicates the comment character used by the
comment|/// assembler.
specifier|const
name|char
modifier|*
name|CommentString
decl_stmt|;
comment|// Defaults to "#"
comment|/// LabelSuffix - This is appended to emitted labels.
specifier|const
name|char
modifier|*
name|LabelSuffix
decl_stmt|;
comment|// Defaults to ":"
comment|/// LabelSuffix - This is appended to emitted labels.
specifier|const
name|char
modifier|*
name|DebugLabelSuffix
decl_stmt|;
comment|// Defaults to ":"
comment|/// GlobalPrefix - If this is set to a non-empty string, it is prepended
comment|/// onto all global symbols.  This is often used for "_" or ".".
specifier|const
name|char
modifier|*
name|GlobalPrefix
decl_stmt|;
comment|// Defaults to ""
comment|/// PrivateGlobalPrefix - This prefix is used for globals like constant
comment|/// pool entries that are completely private to the .s file and should not
comment|/// have names in the .o file.  This is often "." or "L".
specifier|const
name|char
modifier|*
name|PrivateGlobalPrefix
decl_stmt|;
comment|// Defaults to "."
comment|/// LinkerPrivateGlobalPrefix - This prefix is used for symbols that should
comment|/// be passed through the assembler but be removed by the linker.  This
comment|/// is "l" on Darwin, currently used for some ObjC metadata.
specifier|const
name|char
modifier|*
name|LinkerPrivateGlobalPrefix
decl_stmt|;
comment|// Defaults to ""
comment|/// InlineAsmStart/End - If these are nonempty, they contain a directive to
comment|/// emit before and after an inline assembly statement.
specifier|const
name|char
modifier|*
name|InlineAsmStart
decl_stmt|;
comment|// Defaults to "#APP\n"
specifier|const
name|char
modifier|*
name|InlineAsmEnd
decl_stmt|;
comment|// Defaults to "#NO_APP\n"
comment|/// Code16Directive, Code32Directive, Code64Directive - These are assembly
comment|/// directives that tells the assembler to interpret the following
comment|/// instructions differently.
specifier|const
name|char
modifier|*
name|Code16Directive
decl_stmt|;
comment|// Defaults to ".code16"
specifier|const
name|char
modifier|*
name|Code32Directive
decl_stmt|;
comment|// Defaults to ".code32"
specifier|const
name|char
modifier|*
name|Code64Directive
decl_stmt|;
comment|// Defaults to ".code64"
comment|/// AssemblerDialect - Which dialect of an assembler variant to use.
name|unsigned
name|AssemblerDialect
decl_stmt|;
comment|// Defaults to 0
comment|/// \brief This is true if the assembler allows @ characters in symbol
comment|/// names. Defaults to false.
name|bool
name|AllowAtInName
decl_stmt|;
comment|/// UseDataRegionDirectives - This is true if data region markers should
comment|/// be printed as ".data_region/.end_data_region" directives. If false,
comment|/// use "$d/$a" labels instead.
name|bool
name|UseDataRegionDirectives
decl_stmt|;
comment|//===--- Data Emission Directives -------------------------------------===//
comment|/// ZeroDirective - this should be set to the directive used to get some
comment|/// number of zero bytes emitted to the current section.  Common cases are
comment|/// "\t.zero\t" and "\t.space\t".  If this is set to null, the
comment|/// Data*bitsDirective's will be used to emit zero bytes.
specifier|const
name|char
modifier|*
name|ZeroDirective
decl_stmt|;
comment|// Defaults to "\t.zero\t"
comment|/// AsciiDirective - This directive allows emission of an ascii string with
comment|/// the standard C escape characters embedded into it.
specifier|const
name|char
modifier|*
name|AsciiDirective
decl_stmt|;
comment|// Defaults to "\t.ascii\t"
comment|/// AscizDirective - If not null, this allows for special handling of
comment|/// zero terminated strings on this target.  This is commonly supported as
comment|/// ".asciz".  If a target doesn't support this, it can be set to null.
specifier|const
name|char
modifier|*
name|AscizDirective
decl_stmt|;
comment|// Defaults to "\t.asciz\t"
comment|/// DataDirectives - These directives are used to output some unit of
comment|/// integer data to the current section.  If a data directive is set to
comment|/// null, smaller data directives will be used to emit the large sizes.
specifier|const
name|char
modifier|*
name|Data8bitsDirective
decl_stmt|;
comment|// Defaults to "\t.byte\t"
specifier|const
name|char
modifier|*
name|Data16bitsDirective
decl_stmt|;
comment|// Defaults to "\t.short\t"
specifier|const
name|char
modifier|*
name|Data32bitsDirective
decl_stmt|;
comment|// Defaults to "\t.long\t"
specifier|const
name|char
modifier|*
name|Data64bitsDirective
decl_stmt|;
comment|// Defaults to "\t.quad\t"
comment|/// GPRel64Directive - if non-null, a directive that is used to emit a word
comment|/// which should be relocated as a 64-bit GP-relative offset, e.g. .gpdword
comment|/// on Mips.
specifier|const
name|char
modifier|*
name|GPRel64Directive
decl_stmt|;
comment|// Defaults to NULL.
comment|/// GPRel32Directive - if non-null, a directive that is used to emit a word
comment|/// which should be relocated as a 32-bit GP-relative offset, e.g. .gpword
comment|/// on Mips or .gprel32 on Alpha.
specifier|const
name|char
modifier|*
name|GPRel32Directive
decl_stmt|;
comment|// Defaults to NULL.
comment|/// SunStyleELFSectionSwitchSyntax - This is true if this target uses "Sun
comment|/// Style" syntax for section switching ("#alloc,#write" etc) instead of the
comment|/// normal ELF syntax (,"a,w") in .section directives.
name|bool
name|SunStyleELFSectionSwitchSyntax
decl_stmt|;
comment|// Defaults to false.
comment|/// UsesELFSectionDirectiveForBSS - This is true if this target uses ELF
comment|/// '.section' directive before the '.bss' one. It's used for PPC/Linux
comment|/// which doesn't support the '.bss' directive only.
name|bool
name|UsesELFSectionDirectiveForBSS
decl_stmt|;
comment|// Defaults to false.
comment|/// HasMicrosoftFastStdCallMangling - True if this target uses microsoft
comment|/// style mangling for functions with X86_StdCall/X86_FastCall calling
comment|/// convention.
name|bool
name|HasMicrosoftFastStdCallMangling
decl_stmt|;
comment|// Defaults to false.
name|bool
name|NeedsDwarfSectionOffsetDirective
decl_stmt|;
comment|//===--- Alignment Information ----------------------------------------===//
comment|/// AlignDirective - The directive used to emit round up to an alignment
comment|/// boundary.
comment|///
specifier|const
name|char
modifier|*
name|AlignDirective
decl_stmt|;
comment|// Defaults to "\t.align\t"
comment|/// AlignmentIsInBytes - If this is true (the default) then the asmprinter
comment|/// emits ".align N" directives, where N is the number of bytes to align to.
comment|/// Otherwise, it emits ".align log2(N)", e.g. 3 to align to an 8 byte
comment|/// boundary.
name|bool
name|AlignmentIsInBytes
decl_stmt|;
comment|// Defaults to true
comment|/// TextAlignFillValue - If non-zero, this is used to fill the executable
comment|/// space created as the result of a alignment directive.
name|unsigned
name|TextAlignFillValue
decl_stmt|;
comment|// Defaults to 0
comment|//===--- Global Variable Emission Directives --------------------------===//
comment|/// GlobalDirective - This is the directive used to declare a global entity.
comment|///
specifier|const
name|char
modifier|*
name|GlobalDirective
decl_stmt|;
comment|// Defaults to NULL.
comment|/// HasSetDirective - True if the assembler supports the .set directive.
name|bool
name|HasSetDirective
decl_stmt|;
comment|// Defaults to true.
comment|/// HasAggressiveSymbolFolding - False if the assembler requires that we use
comment|/// Lc = a - b
comment|/// .long Lc
comment|/// instead of
comment|/// .long a - b
name|bool
name|HasAggressiveSymbolFolding
decl_stmt|;
comment|// Defaults to true.
comment|/// COMMDirectiveAlignmentIsInBytes - True is .comm's and .lcomms optional
comment|/// alignment is to be specified in bytes instead of log2(n).
name|bool
name|COMMDirectiveAlignmentIsInBytes
decl_stmt|;
comment|// Defaults to true;
comment|/// LCOMMDirectiveAlignment - Describes if the .lcomm directive for the
comment|/// target supports an alignment argument and how it is interpreted.
name|LCOMM
operator|::
name|LCOMMType
name|LCOMMDirectiveAlignmentType
expr_stmt|;
comment|// Defaults to NoAlignment.
comment|/// HasDotTypeDotSizeDirective - True if the target has .type and .size
comment|/// directives, this is true for most ELF targets.
name|bool
name|HasDotTypeDotSizeDirective
decl_stmt|;
comment|// Defaults to true.
comment|/// HasSingleParameterDotFile - True if the target has a single parameter
comment|/// .file directive, this is true for ELF targets.
name|bool
name|HasSingleParameterDotFile
decl_stmt|;
comment|// Defaults to true.
comment|/// hasIdentDirective - True if the target has a .ident directive, this is
comment|/// true for ELF targets.
name|bool
name|HasIdentDirective
decl_stmt|;
comment|// Defaults to false.
comment|/// HasNoDeadStrip - True if this target supports the MachO .no_dead_strip
comment|/// directive.
name|bool
name|HasNoDeadStrip
decl_stmt|;
comment|// Defaults to false.
comment|/// WeakRefDirective - This directive, if non-null, is used to declare a
comment|/// global as being a weak undefined symbol.
specifier|const
name|char
modifier|*
name|WeakRefDirective
decl_stmt|;
comment|// Defaults to NULL.
comment|/// True if we have a directive to declare a global as being a weak
comment|/// defined symbol.
name|bool
name|HasWeakDefDirective
decl_stmt|;
comment|// Defaults to false.
comment|/// True if we have a directive to declare a global as being a weak
comment|/// defined symbol that can be hidden (unexported).
name|bool
name|HasWeakDefCanBeHiddenDirective
decl_stmt|;
comment|// Defaults to false.
comment|/// True if we have a .linkonce directive.  This is used on cygwin/mingw.
name|bool
name|HasLinkOnceDirective
decl_stmt|;
comment|// Defaults to false.
comment|/// HiddenVisibilityAttr - This attribute, if not MCSA_Invalid, is used to
comment|/// declare a symbol as having hidden visibility.
name|MCSymbolAttr
name|HiddenVisibilityAttr
decl_stmt|;
comment|// Defaults to MCSA_Hidden.
comment|/// HiddenDeclarationVisibilityAttr - This attribute, if not MCSA_Invalid,
comment|/// is used to declare an undefined symbol as having hidden visibility.
name|MCSymbolAttr
name|HiddenDeclarationVisibilityAttr
decl_stmt|;
comment|// Defaults to MCSA_Hidden.
comment|/// ProtectedVisibilityAttr - This attribute, if not MCSA_Invalid, is used
comment|/// to declare a symbol as having protected visibility.
name|MCSymbolAttr
name|ProtectedVisibilityAttr
decl_stmt|;
comment|// Defaults to MCSA_Protected
comment|//===--- Dwarf Emission Directives -----------------------------------===//
comment|/// HasLEB128 - True if target asm supports leb128 directives.
name|bool
name|HasLEB128
decl_stmt|;
comment|// Defaults to false.
comment|/// SupportsDebugInformation - True if target supports emission of debugging
comment|/// information.
name|bool
name|SupportsDebugInformation
decl_stmt|;
comment|// Defaults to false.
comment|/// SupportsExceptionHandling - True if target supports exception handling.
name|ExceptionHandling
operator|::
name|ExceptionsType
name|ExceptionsType
expr_stmt|;
comment|// Defaults to None
comment|/// DwarfUsesRelocationsAcrossSections - True if Dwarf2 output generally
comment|/// uses relocations for references to other .debug_* sections.
name|bool
name|DwarfUsesRelocationsAcrossSections
decl_stmt|;
comment|/// DwarfFDESymbolsUseAbsDiff - true if DWARF FDE symbol reference
comment|/// relocations should be replaced by an absolute difference.
name|bool
name|DwarfFDESymbolsUseAbsDiff
decl_stmt|;
comment|/// DwarfRegNumForCFI - True if dwarf register numbers are printed
comment|/// instead of symbolic register names in .cfi_* directives.
name|bool
name|DwarfRegNumForCFI
decl_stmt|;
comment|// Defaults to false;
comment|//===--- Prologue State ----------------------------------------------===//
name|std
operator|::
name|vector
operator|<
name|MCCFIInstruction
operator|>
name|InitialFrameState
expr_stmt|;
name|public
label|:
name|explicit
name|MCAsmInfo
parameter_list|()
function_decl|;
name|virtual
operator|~
name|MCAsmInfo
argument_list|()
expr_stmt|;
comment|// FIXME: move these methods to DwarfPrinter when the JIT stops using them.
specifier|static
name|unsigned
name|getSLEB128Size
parameter_list|(
name|int64_t
name|Value
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|getULEB128Size
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
function_decl|;
comment|/// getPointerSize - Get the pointer size in bytes.
name|unsigned
name|getPointerSize
argument_list|()
specifier|const
block|{
return|return
name|PointerSize
return|;
block|}
comment|/// getCalleeSaveStackSlotSize - Get the callee-saved register stack slot
comment|/// size in bytes.
name|unsigned
name|getCalleeSaveStackSlotSize
argument_list|()
specifier|const
block|{
return|return
name|CalleeSaveStackSlotSize
return|;
block|}
comment|/// isLittleEndian - True if the target is little endian.
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|IsLittleEndian
return|;
block|}
comment|/// isStackGrowthDirectionUp - True if target stack grow up.
name|bool
name|isStackGrowthDirectionUp
argument_list|()
specifier|const
block|{
return|return
name|StackGrowsUp
return|;
block|}
name|bool
name|hasSubsectionsViaSymbols
argument_list|()
specifier|const
block|{
return|return
name|HasSubsectionsViaSymbols
return|;
block|}
comment|// Data directive accessors.
comment|//
specifier|const
name|char
operator|*
name|getData8bitsDirective
argument_list|()
specifier|const
block|{
return|return
name|Data8bitsDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getData16bitsDirective
argument_list|()
specifier|const
block|{
return|return
name|Data16bitsDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getData32bitsDirective
argument_list|()
specifier|const
block|{
return|return
name|Data32bitsDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getData64bitsDirective
argument_list|()
specifier|const
block|{
return|return
name|Data64bitsDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getGPRel64Directive
argument_list|()
specifier|const
block|{
return|return
name|GPRel64Directive
return|;
block|}
specifier|const
name|char
operator|*
name|getGPRel32Directive
argument_list|()
specifier|const
block|{
return|return
name|GPRel32Directive
return|;
block|}
comment|/// getNonexecutableStackSection - Targets can implement this method to
comment|/// specify a section to switch to if the translation unit doesn't have any
comment|/// trampolines that require an executable stack.
name|virtual
specifier|const
name|MCSection
modifier|*
name|getNonexecutableStackSection
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
specifier|const
name|MCExpr
modifier|*
name|getExprForPersonalitySymbol
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Sym
argument_list|,
name|unsigned
name|Encoding
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
decl|const
decl_stmt|;
name|virtual
specifier|const
name|MCExpr
modifier|*
name|getExprForFDESymbol
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Sym
argument_list|,
name|unsigned
name|Encoding
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
decl|const
decl_stmt|;
name|bool
name|usesSunStyleELFSectionSwitchSyntax
argument_list|()
specifier|const
block|{
return|return
name|SunStyleELFSectionSwitchSyntax
return|;
block|}
name|bool
name|usesELFSectionDirectiveForBSS
argument_list|()
specifier|const
block|{
return|return
name|UsesELFSectionDirectiveForBSS
return|;
block|}
name|bool
name|hasMicrosoftFastStdCallMangling
argument_list|()
specifier|const
block|{
return|return
name|HasMicrosoftFastStdCallMangling
return|;
block|}
name|bool
name|needsDwarfSectionOffsetDirective
argument_list|()
specifier|const
block|{
return|return
name|NeedsDwarfSectionOffsetDirective
return|;
block|}
comment|// Accessors.
comment|//
name|bool
name|hasMachoZeroFillDirective
argument_list|()
specifier|const
block|{
return|return
name|HasMachoZeroFillDirective
return|;
block|}
name|bool
name|hasMachoTBSSDirective
argument_list|()
specifier|const
block|{
return|return
name|HasMachoTBSSDirective
return|;
block|}
name|bool
name|hasStaticCtorDtorReferenceInStaticMode
argument_list|()
specifier|const
block|{
return|return
name|HasStaticCtorDtorReferenceInStaticMode
return|;
block|}
name|bool
name|getLinkerRequiresNonEmptyDwarfLines
argument_list|()
specifier|const
block|{
return|return
name|LinkerRequiresNonEmptyDwarfLines
return|;
block|}
name|unsigned
name|getMaxInstLength
argument_list|()
specifier|const
block|{
return|return
name|MaxInstLength
return|;
block|}
name|unsigned
name|getMinInstAlignment
argument_list|()
specifier|const
block|{
return|return
name|MinInstAlignment
return|;
block|}
name|bool
name|getDollarIsPC
argument_list|()
specifier|const
block|{
return|return
name|DollarIsPC
return|;
block|}
specifier|const
name|char
operator|*
name|getSeparatorString
argument_list|()
specifier|const
block|{
return|return
name|SeparatorString
return|;
block|}
name|unsigned
name|getCommentColumn
argument_list|()
specifier|const
block|{
return|return
name|CommentColumn
return|;
block|}
specifier|const
name|char
operator|*
name|getCommentString
argument_list|()
specifier|const
block|{
return|return
name|CommentString
return|;
block|}
specifier|const
name|char
operator|*
name|getLabelSuffix
argument_list|()
specifier|const
block|{
return|return
name|LabelSuffix
return|;
block|}
specifier|const
name|char
operator|*
name|getDebugLabelSuffix
argument_list|()
specifier|const
block|{
return|return
name|DebugLabelSuffix
return|;
block|}
specifier|const
name|char
operator|*
name|getGlobalPrefix
argument_list|()
specifier|const
block|{
return|return
name|GlobalPrefix
return|;
block|}
specifier|const
name|char
operator|*
name|getPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
return|return
name|PrivateGlobalPrefix
return|;
block|}
specifier|const
name|char
operator|*
name|getLinkerPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
return|return
name|LinkerPrivateGlobalPrefix
return|;
block|}
specifier|const
name|char
operator|*
name|getInlineAsmStart
argument_list|()
specifier|const
block|{
return|return
name|InlineAsmStart
return|;
block|}
specifier|const
name|char
operator|*
name|getInlineAsmEnd
argument_list|()
specifier|const
block|{
return|return
name|InlineAsmEnd
return|;
block|}
specifier|const
name|char
operator|*
name|getCode16Directive
argument_list|()
specifier|const
block|{
return|return
name|Code16Directive
return|;
block|}
specifier|const
name|char
operator|*
name|getCode32Directive
argument_list|()
specifier|const
block|{
return|return
name|Code32Directive
return|;
block|}
specifier|const
name|char
operator|*
name|getCode64Directive
argument_list|()
specifier|const
block|{
return|return
name|Code64Directive
return|;
block|}
name|unsigned
name|getAssemblerDialect
argument_list|()
specifier|const
block|{
return|return
name|AssemblerDialect
return|;
block|}
name|bool
name|doesAllowAtInName
argument_list|()
specifier|const
block|{
return|return
name|AllowAtInName
return|;
block|}
name|bool
name|doesSupportDataRegionDirectives
argument_list|()
specifier|const
block|{
return|return
name|UseDataRegionDirectives
return|;
block|}
specifier|const
name|char
operator|*
name|getZeroDirective
argument_list|()
specifier|const
block|{
return|return
name|ZeroDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getAsciiDirective
argument_list|()
specifier|const
block|{
return|return
name|AsciiDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getAscizDirective
argument_list|()
specifier|const
block|{
return|return
name|AscizDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getAlignDirective
argument_list|()
specifier|const
block|{
return|return
name|AlignDirective
return|;
block|}
name|bool
name|getAlignmentIsInBytes
argument_list|()
specifier|const
block|{
return|return
name|AlignmentIsInBytes
return|;
block|}
name|unsigned
name|getTextAlignFillValue
argument_list|()
specifier|const
block|{
return|return
name|TextAlignFillValue
return|;
block|}
specifier|const
name|char
operator|*
name|getGlobalDirective
argument_list|()
specifier|const
block|{
return|return
name|GlobalDirective
return|;
block|}
name|bool
name|hasSetDirective
argument_list|()
specifier|const
block|{
return|return
name|HasSetDirective
return|;
block|}
name|bool
name|hasAggressiveSymbolFolding
argument_list|()
specifier|const
block|{
return|return
name|HasAggressiveSymbolFolding
return|;
block|}
name|bool
name|getCOMMDirectiveAlignmentIsInBytes
argument_list|()
specifier|const
block|{
return|return
name|COMMDirectiveAlignmentIsInBytes
return|;
block|}
name|LCOMM
operator|::
name|LCOMMType
name|getLCOMMDirectiveAlignmentType
argument_list|()
specifier|const
block|{
return|return
name|LCOMMDirectiveAlignmentType
return|;
block|}
name|bool
name|hasDotTypeDotSizeDirective
argument_list|()
specifier|const
block|{
return|return
name|HasDotTypeDotSizeDirective
return|;
block|}
name|bool
name|hasSingleParameterDotFile
argument_list|()
specifier|const
block|{
return|return
name|HasSingleParameterDotFile
return|;
block|}
name|bool
name|hasIdentDirective
argument_list|()
specifier|const
block|{
return|return
name|HasIdentDirective
return|;
block|}
name|bool
name|hasNoDeadStrip
argument_list|()
specifier|const
block|{
return|return
name|HasNoDeadStrip
return|;
block|}
specifier|const
name|char
operator|*
name|getWeakRefDirective
argument_list|()
specifier|const
block|{
return|return
name|WeakRefDirective
return|;
block|}
name|bool
name|hasWeakDefDirective
argument_list|()
specifier|const
block|{
return|return
name|HasWeakDefDirective
return|;
block|}
name|bool
name|hasWeakDefCanBeHiddenDirective
argument_list|()
specifier|const
block|{
return|return
name|HasWeakDefCanBeHiddenDirective
return|;
block|}
name|bool
name|hasLinkOnceDirective
argument_list|()
specifier|const
block|{
return|return
name|HasLinkOnceDirective
return|;
block|}
name|MCSymbolAttr
name|getHiddenVisibilityAttr
argument_list|()
specifier|const
block|{
return|return
name|HiddenVisibilityAttr
return|;
block|}
name|MCSymbolAttr
name|getHiddenDeclarationVisibilityAttr
argument_list|()
specifier|const
block|{
return|return
name|HiddenDeclarationVisibilityAttr
return|;
block|}
name|MCSymbolAttr
name|getProtectedVisibilityAttr
argument_list|()
specifier|const
block|{
return|return
name|ProtectedVisibilityAttr
return|;
block|}
name|bool
name|hasLEB128
argument_list|()
specifier|const
block|{
return|return
name|HasLEB128
return|;
block|}
name|bool
name|doesSupportDebugInformation
argument_list|()
specifier|const
block|{
return|return
name|SupportsDebugInformation
return|;
block|}
name|bool
name|doesSupportExceptionHandling
argument_list|()
specifier|const
block|{
return|return
name|ExceptionsType
operator|!=
name|ExceptionHandling
operator|::
name|None
return|;
block|}
name|ExceptionHandling
operator|::
name|ExceptionsType
name|getExceptionHandlingType
argument_list|()
specifier|const
block|{
return|return
name|ExceptionsType
return|;
block|}
name|bool
name|isExceptionHandlingDwarf
argument_list|()
specifier|const
block|{
return|return
operator|(
name|ExceptionsType
operator|==
name|ExceptionHandling
operator|::
name|DwarfCFI
operator|||
name|ExceptionsType
operator|==
name|ExceptionHandling
operator|::
name|ARM
operator|||
name|ExceptionsType
operator|==
name|ExceptionHandling
operator|::
name|Win64
operator|)
return|;
block|}
name|bool
name|doesDwarfUseRelocationsAcrossSections
argument_list|()
specifier|const
block|{
return|return
name|DwarfUsesRelocationsAcrossSections
return|;
block|}
name|bool
name|doDwarfFDESymbolsUseAbsDiff
argument_list|()
specifier|const
block|{
return|return
name|DwarfFDESymbolsUseAbsDiff
return|;
block|}
name|bool
name|useDwarfRegNumForCFI
argument_list|()
specifier|const
block|{
return|return
name|DwarfRegNumForCFI
return|;
block|}
name|void
name|addInitialFrameState
parameter_list|(
specifier|const
name|MCCFIInstruction
modifier|&
name|Inst
parameter_list|)
block|{
name|InitialFrameState
operator|.
name|push_back
argument_list|(
name|Inst
argument_list|)
expr_stmt|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|MCCFIInstruction
operator|>
operator|&
name|getInitialFrameState
argument_list|()
specifier|const
block|{
return|return
name|InitialFrameState
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

