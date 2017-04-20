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
file|"llvm/ADT/StringRef.h"
end_include

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
file|"llvm/MC/MCTargetOptions.h"
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
name|MCContext
decl_stmt|;
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
name|namespace
name|WinEH
block|{
name|enum
name|class
name|EncodingType
block|{
name|Invalid
operator|,
comment|/// Invalid
name|Alpha
operator|,
comment|/// Windows Alpha
name|Alpha64
operator|,
comment|/// Windows AXP64
name|ARM
operator|,
comment|/// Windows NT (Windows on ARM)
name|CE
operator|,
comment|/// Windows CE ARM, PowerPC, SH3, SH4
name|Itanium
operator|,
comment|/// Windows x64, Windows Itanium (IA-64)
name|X86
operator|,
comment|/// Windows x86, uses no CFI, just EH tables
name|MIPS
operator|=
name|Alpha
operator|,
block|}
empty_stmt|;
block|}
comment|// end namespace WinEH
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
comment|// end namespace LCOMM
name|enum
name|class
name|DebugCompressionType
block|{
name|DCT_None
operator|,
comment|// no compression
name|DCT_Zlib
operator|,
comment|// zlib style complession
name|DCT_ZlibGnu
comment|// zlib-gnu style compression
block|}
empty_stmt|;
comment|/// This class is intended to be used as a base class for asm
comment|/// properties and features specific to the target.
name|class
name|MCAsmInfo
block|{
name|protected
label|:
comment|//===------------------------------------------------------------------===//
comment|// Properties to be set by the target writer, used to configure asm printer.
comment|//
comment|/// Code pointer size in bytes.  Default is 4.
name|unsigned
name|CodePointerSize
init|=
literal|4
decl_stmt|;
comment|/// Size of the stack slot reserved for callee-saved registers, in bytes.
comment|/// Default is same as pointer size.
name|unsigned
name|CalleeSaveStackSlotSize
init|=
literal|4
decl_stmt|;
comment|/// True if target is little endian.  Default is true.
name|bool
name|IsLittleEndian
init|=
name|true
decl_stmt|;
comment|/// True if target stack grow up.  Default is false.
name|bool
name|StackGrowsUp
init|=
name|false
decl_stmt|;
comment|/// True if this target has the MachO .subsections_via_symbols directive.
comment|/// Default is false.
name|bool
name|HasSubsectionsViaSymbols
init|=
name|false
decl_stmt|;
comment|/// True if this is a MachO target that supports the macho-specific .zerofill
comment|/// directive for emitting BSS Symbols.  Default is false.
name|bool
name|HasMachoZeroFillDirective
init|=
name|false
decl_stmt|;
comment|/// True if this is a MachO target that supports the macho-specific .tbss
comment|/// directive for emitting thread local BSS Symbols.  Default is false.
name|bool
name|HasMachoTBSSDirective
init|=
name|false
decl_stmt|;
comment|/// This is the maximum possible length of an instruction, which is needed to
comment|/// compute the size of an inline asm.  Defaults to 4.
name|unsigned
name|MaxInstLength
init|=
literal|4
decl_stmt|;
comment|/// Every possible instruction length is a multiple of this value.  Factored
comment|/// out in .debug_frame and .debug_line.  Defaults to 1.
name|unsigned
name|MinInstAlignment
init|=
literal|1
decl_stmt|;
comment|/// The '$' token, when not referencing an identifier or constant, refers to
comment|/// the current PC.  Defaults to false.
name|bool
name|DollarIsPC
init|=
name|false
decl_stmt|;
comment|/// This string, if specified, is used to separate instructions from each
comment|/// other when on the same line.  Defaults to ';'
specifier|const
name|char
modifier|*
name|SeparatorString
decl_stmt|;
comment|/// This indicates the comment character used by the assembler.  Defaults to
comment|/// "#"
name|StringRef
name|CommentString
decl_stmt|;
comment|/// This is appended to emitted labels.  Defaults to ":"
specifier|const
name|char
modifier|*
name|LabelSuffix
decl_stmt|;
comment|// Print the EH begin symbol with an assignment. Defaults to false.
name|bool
name|UseAssignmentForEHBegin
init|=
name|false
decl_stmt|;
comment|// Do we need to create a local symbol for .size?
name|bool
name|NeedsLocalForSize
init|=
name|false
decl_stmt|;
comment|/// This prefix is used for globals like constant pool entries that are
comment|/// completely private to the .s file and should not have names in the .o
comment|/// file.  Defaults to "L"
name|StringRef
name|PrivateGlobalPrefix
decl_stmt|;
comment|/// This prefix is used for labels for basic blocks. Defaults to the same as
comment|/// PrivateGlobalPrefix.
name|StringRef
name|PrivateLabelPrefix
decl_stmt|;
comment|/// This prefix is used for symbols that should be passed through the
comment|/// assembler but be removed by the linker.  This is 'l' on Darwin, currently
comment|/// used for some ObjC metadata.  The default of "" meast that for this system
comment|/// a plain private symbol should be used.  Defaults to "".
name|StringRef
name|LinkerPrivateGlobalPrefix
decl_stmt|;
comment|/// If these are nonempty, they contain a directive to emit before and after
comment|/// an inline assembly statement.  Defaults to "#APP\n", "#NO_APP\n"
specifier|const
name|char
modifier|*
name|InlineAsmStart
decl_stmt|;
specifier|const
name|char
modifier|*
name|InlineAsmEnd
decl_stmt|;
comment|/// These are assembly directives that tells the assembler to interpret the
comment|/// following instructions differently.  Defaults to ".code16", ".code32",
comment|/// ".code64".
specifier|const
name|char
modifier|*
name|Code16Directive
decl_stmt|;
specifier|const
name|char
modifier|*
name|Code32Directive
decl_stmt|;
specifier|const
name|char
modifier|*
name|Code64Directive
decl_stmt|;
comment|/// Which dialect of an assembler variant to use.  Defaults to 0
name|unsigned
name|AssemblerDialect
init|=
literal|0
decl_stmt|;
comment|/// This is true if the assembler allows @ characters in symbol names.
comment|/// Defaults to false.
name|bool
name|AllowAtInName
init|=
name|false
decl_stmt|;
comment|/// If this is true, symbol names with invalid characters will be printed in
comment|/// quotes.
name|bool
name|SupportsQuotedNames
init|=
name|true
decl_stmt|;
comment|/// This is true if data region markers should be printed as
comment|/// ".data_region/.end_data_region" directives. If false, use "$d/$a" labels
comment|/// instead.
name|bool
name|UseDataRegionDirectives
init|=
name|false
decl_stmt|;
comment|//===--- Data Emission Directives -------------------------------------===//
comment|/// This should be set to the directive used to get some number of zero bytes
comment|/// emitted to the current section.  Common cases are "\t.zero\t" and
comment|/// "\t.space\t".  If this is set to null, the Data*bitsDirective's will be
comment|/// used to emit zero bytes.  Defaults to "\t.zero\t"
specifier|const
name|char
modifier|*
name|ZeroDirective
decl_stmt|;
comment|/// This directive allows emission of an ascii string with the standard C
comment|/// escape characters embedded into it.  Defaults to "\t.ascii\t"
specifier|const
name|char
modifier|*
name|AsciiDirective
decl_stmt|;
comment|/// If not null, this allows for special handling of zero terminated strings
comment|/// on this target.  This is commonly supported as ".asciz".  If a target
comment|/// doesn't support this, it can be set to null.  Defaults to "\t.asciz\t"
specifier|const
name|char
modifier|*
name|AscizDirective
decl_stmt|;
comment|/// These directives are used to output some unit of integer data to the
comment|/// current section.  If a data directive is set to null, smaller data
comment|/// directives will be used to emit the large sizes.  Defaults to "\t.byte\t",
comment|/// "\t.short\t", "\t.long\t", "\t.quad\t"
specifier|const
name|char
modifier|*
name|Data8bitsDirective
decl_stmt|;
specifier|const
name|char
modifier|*
name|Data16bitsDirective
decl_stmt|;
specifier|const
name|char
modifier|*
name|Data32bitsDirective
decl_stmt|;
specifier|const
name|char
modifier|*
name|Data64bitsDirective
decl_stmt|;
comment|/// If non-null, a directive that is used to emit a word which should be
comment|/// relocated as a 64-bit GP-relative offset, e.g. .gpdword on Mips.  Defaults
comment|/// to nullptr.
specifier|const
name|char
modifier|*
name|GPRel64Directive
init|=
name|nullptr
decl_stmt|;
comment|/// If non-null, a directive that is used to emit a word which should be
comment|/// relocated as a 32-bit GP-relative offset, e.g. .gpword on Mips or .gprel32
comment|/// on Alpha.  Defaults to nullptr.
specifier|const
name|char
modifier|*
name|GPRel32Directive
init|=
name|nullptr
decl_stmt|;
comment|/// If non-null, directives that are used to emit a word/dword which should
comment|/// be relocated as a 32/64-bit DTP/TP-relative offset, e.g. .dtprelword/
comment|/// .dtpreldword/.tprelword/.tpreldword on Mips.
specifier|const
name|char
modifier|*
name|DTPRel32Directive
init|=
name|nullptr
decl_stmt|;
specifier|const
name|char
modifier|*
name|DTPRel64Directive
init|=
name|nullptr
decl_stmt|;
specifier|const
name|char
modifier|*
name|TPRel32Directive
init|=
name|nullptr
decl_stmt|;
specifier|const
name|char
modifier|*
name|TPRel64Directive
init|=
name|nullptr
decl_stmt|;
comment|/// This is true if this target uses "Sun Style" syntax for section switching
comment|/// ("#alloc,#write" etc) instead of the normal ELF syntax (,"a,w") in
comment|/// .section directives.  Defaults to false.
name|bool
name|SunStyleELFSectionSwitchSyntax
init|=
name|false
decl_stmt|;
comment|/// This is true if this target uses ELF '.section' directive before the
comment|/// '.bss' one. It's used for PPC/Linux which doesn't support the '.bss'
comment|/// directive only.  Defaults to false.
name|bool
name|UsesELFSectionDirectiveForBSS
init|=
name|false
decl_stmt|;
name|bool
name|NeedsDwarfSectionOffsetDirective
init|=
name|false
decl_stmt|;
comment|//===--- Alignment Information ----------------------------------------===//
comment|/// If this is true (the default) then the asmprinter emits ".align N"
comment|/// directives, where N is the number of bytes to align to.  Otherwise, it
comment|/// emits ".align log2(N)", e.g. 3 to align to an 8 byte boundary.  Defaults
comment|/// to true.
name|bool
name|AlignmentIsInBytes
init|=
name|true
decl_stmt|;
comment|/// If non-zero, this is used to fill the executable space created as the
comment|/// result of a alignment directive.  Defaults to 0
name|unsigned
name|TextAlignFillValue
init|=
literal|0
decl_stmt|;
comment|//===--- Global Variable Emission Directives --------------------------===//
comment|/// This is the directive used to declare a global entity. Defaults to
comment|/// ".globl".
specifier|const
name|char
modifier|*
name|GlobalDirective
decl_stmt|;
comment|/// True if the expression
comment|///   .long f - g
comment|/// uses a relocation but it can be suppressed by writing
comment|///   a = f - g
comment|///   .long a
name|bool
name|SetDirectiveSuppressesReloc
init|=
name|false
decl_stmt|;
comment|/// False if the assembler requires that we use
comment|/// \code
comment|///   Lc = a - b
comment|///   .long Lc
comment|/// \endcode
comment|//
comment|/// instead of
comment|//
comment|/// \code
comment|///   .long a - b
comment|/// \endcode
comment|///
comment|///  Defaults to true.
name|bool
name|HasAggressiveSymbolFolding
init|=
name|true
decl_stmt|;
comment|/// True is .comm's and .lcomms optional alignment is to be specified in bytes
comment|/// instead of log2(n).  Defaults to true.
name|bool
name|COMMDirectiveAlignmentIsInBytes
init|=
name|true
decl_stmt|;
comment|/// Describes if the .lcomm directive for the target supports an alignment
comment|/// argument and how it is interpreted.  Defaults to NoAlignment.
name|LCOMM
operator|::
name|LCOMMType
name|LCOMMDirectiveAlignmentType
operator|=
name|LCOMM
operator|::
name|NoAlignment
expr_stmt|;
comment|// True if the target allows .align directives on functions. This is true for
comment|// most targets, so defaults to true.
name|bool
name|HasFunctionAlignment
init|=
name|true
decl_stmt|;
comment|/// True if the target has .type and .size directives, this is true for most
comment|/// ELF targets.  Defaults to true.
name|bool
name|HasDotTypeDotSizeDirective
init|=
name|true
decl_stmt|;
comment|/// True if the target has a single parameter .file directive, this is true
comment|/// for ELF targets.  Defaults to true.
name|bool
name|HasSingleParameterDotFile
init|=
name|true
decl_stmt|;
comment|/// True if the target has a .ident directive, this is true for ELF targets.
comment|/// Defaults to false.
name|bool
name|HasIdentDirective
init|=
name|false
decl_stmt|;
comment|/// True if this target supports the MachO .no_dead_strip directive.  Defaults
comment|/// to false.
name|bool
name|HasNoDeadStrip
init|=
name|false
decl_stmt|;
comment|/// True if this target supports the MachO .alt_entry directive.  Defaults to
comment|/// false.
name|bool
name|HasAltEntry
init|=
name|false
decl_stmt|;
comment|/// Used to declare a global as being a weak symbol. Defaults to ".weak".
specifier|const
name|char
modifier|*
name|WeakDirective
decl_stmt|;
comment|/// This directive, if non-null, is used to declare a global as being a weak
comment|/// undefined symbol.  Defaults to nullptr.
specifier|const
name|char
modifier|*
name|WeakRefDirective
init|=
name|nullptr
decl_stmt|;
comment|/// True if we have a directive to declare a global as being a weak defined
comment|/// symbol.  Defaults to false.
name|bool
name|HasWeakDefDirective
init|=
name|false
decl_stmt|;
comment|/// True if we have a directive to declare a global as being a weak defined
comment|/// symbol that can be hidden (unexported).  Defaults to false.
name|bool
name|HasWeakDefCanBeHiddenDirective
init|=
name|false
decl_stmt|;
comment|/// True if we have a .linkonce directive.  This is used on cygwin/mingw.
comment|/// Defaults to false.
name|bool
name|HasLinkOnceDirective
init|=
name|false
decl_stmt|;
comment|/// This attribute, if not MCSA_Invalid, is used to declare a symbol as having
comment|/// hidden visibility.  Defaults to MCSA_Hidden.
name|MCSymbolAttr
name|HiddenVisibilityAttr
init|=
name|MCSA_Hidden
decl_stmt|;
comment|/// This attribute, if not MCSA_Invalid, is used to declare an undefined
comment|/// symbol as having hidden visibility. Defaults to MCSA_Hidden.
name|MCSymbolAttr
name|HiddenDeclarationVisibilityAttr
init|=
name|MCSA_Hidden
decl_stmt|;
comment|/// This attribute, if not MCSA_Invalid, is used to declare a symbol as having
comment|/// protected visibility.  Defaults to MCSA_Protected
name|MCSymbolAttr
name|ProtectedVisibilityAttr
init|=
name|MCSA_Protected
decl_stmt|;
comment|//===--- Dwarf Emission Directives -----------------------------------===//
comment|/// True if target supports emission of debugging information.  Defaults to
comment|/// false.
name|bool
name|SupportsDebugInformation
init|=
name|false
decl_stmt|;
comment|/// Exception handling format for the target.  Defaults to None.
name|ExceptionHandling
name|ExceptionsType
init|=
name|ExceptionHandling
operator|::
name|None
decl_stmt|;
comment|/// Windows exception handling data (.pdata) encoding.  Defaults to Invalid.
name|WinEH
operator|::
name|EncodingType
name|WinEHEncodingType
operator|=
name|WinEH
operator|::
name|EncodingType
operator|::
name|Invalid
expr_stmt|;
comment|/// True if Dwarf2 output generally uses relocations for references to other
comment|/// .debug_* sections.
name|bool
name|DwarfUsesRelocationsAcrossSections
init|=
name|true
decl_stmt|;
comment|/// True if DWARF FDE symbol reference relocations should be replaced by an
comment|/// absolute difference.
name|bool
name|DwarfFDESymbolsUseAbsDiff
init|=
name|false
decl_stmt|;
comment|/// True if dwarf register numbers are printed instead of symbolic register
comment|/// names in .cfi_* directives.  Defaults to false.
name|bool
name|DwarfRegNumForCFI
init|=
name|false
decl_stmt|;
comment|/// True if target uses parens to indicate the symbol variant instead of @.
comment|/// For example, foo(plt) instead of foo@plt.  Defaults to false.
name|bool
name|UseParensForSymbolVariant
init|=
name|false
decl_stmt|;
comment|//===--- Prologue State ----------------------------------------------===//
name|std
operator|::
name|vector
operator|<
name|MCCFIInstruction
operator|>
name|InitialFrameState
expr_stmt|;
comment|//===--- Integrated Assembler Information ----------------------------===//
comment|/// Should we use the integrated assembler?
comment|/// The integrated assembler should be enabled by default (by the
comment|/// constructors) when failing to parse a valid piece of assembly (inline
comment|/// or otherwise) is considered a bug. It may then be overridden after
comment|/// construction (see LLVMTargetMachine::initAsmInfo()).
name|bool
name|UseIntegratedAssembler
decl_stmt|;
comment|/// Preserve Comments in assembly
name|bool
name|PreserveAsmComments
decl_stmt|;
comment|/// Compress DWARF debug sections. Defaults to no compression.
name|DebugCompressionType
name|CompressDebugSections
init|=
name|DebugCompressionType
operator|::
name|DCT_None
decl_stmt|;
comment|/// True if the integrated assembler should interpret 'a>> b' constant
comment|/// expressions as logical rather than arithmetic.
name|bool
name|UseLogicalShr
init|=
name|true
decl_stmt|;
comment|// If true, emit GOTPCRELX/REX_GOTPCRELX instead of GOTPCREL, on
comment|// X86_64 ELF.
name|bool
name|RelaxELFRelocations
init|=
name|true
decl_stmt|;
comment|// If true, then the lexer and expression parser will support %neg(),
comment|// %hi(), and similar unary operators.
name|bool
name|HasMipsExpressions
init|=
name|false
decl_stmt|;
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
comment|/// Get the code pointer size in bytes.
name|unsigned
name|getCodePointerSize
argument_list|()
specifier|const
block|{
return|return
name|CodePointerSize
return|;
block|}
comment|/// Get the callee-saved register stack slot
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
comment|/// True if the target is little endian.
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|IsLittleEndian
return|;
block|}
comment|/// True if target stack grow up.
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
specifier|const
name|char
operator|*
name|getDTPRel64Directive
argument_list|()
specifier|const
block|{
return|return
name|DTPRel64Directive
return|;
block|}
specifier|const
name|char
operator|*
name|getDTPRel32Directive
argument_list|()
specifier|const
block|{
return|return
name|DTPRel32Directive
return|;
block|}
specifier|const
name|char
operator|*
name|getTPRel64Directive
argument_list|()
specifier|const
block|{
return|return
name|TPRel64Directive
return|;
block|}
specifier|const
name|char
operator|*
name|getTPRel32Directive
argument_list|()
specifier|const
block|{
return|return
name|TPRel32Directive
return|;
block|}
comment|/// Targets can implement this method to specify a section to switch to if the
comment|/// translation unit doesn't have any trampolines that require an executable
comment|/// stack.
name|virtual
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
name|nullptr
return|;
block|}
comment|/// \brief True if the section is atomized using the symbols in it.
comment|/// This is false if the section is not atomized at all (most ELF sections) or
comment|/// if it is atomized based on its contents (MachO' __TEXT,__cstring for
comment|/// example).
name|virtual
name|bool
name|isSectionAtomizableBySymbols
argument_list|(
specifier|const
name|MCSection
operator|&
name|Section
argument_list|)
decl|const
decl_stmt|;
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
comment|/// Return true if the identifier \p Name does not need quotes to be
comment|/// syntactically correct.
name|virtual
name|bool
name|isValidUnquotedName
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if the .section directive should be omitted when
comment|/// emitting \p SectionName.  For example:
comment|///
comment|/// shouldOmitSectionDirective(".text")
comment|///
comment|/// returns false => .section .text,#alloc,#execinstr
comment|/// returns true  => .text
name|virtual
name|bool
name|shouldOmitSectionDirective
argument_list|(
name|StringRef
name|SectionName
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
name|needsDwarfSectionOffsetDirective
argument_list|()
specifier|const
block|{
return|return
name|NeedsDwarfSectionOffsetDirective
return|;
block|}
comment|// Accessors.
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
comment|/// This indicates the column (zero-based) at which asm comments should be
comment|/// printed.
name|unsigned
name|getCommentColumn
argument_list|()
specifier|const
block|{
return|return
literal|40
return|;
block|}
name|StringRef
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
name|bool
name|useAssignmentForEHBegin
argument_list|()
specifier|const
block|{
return|return
name|UseAssignmentForEHBegin
return|;
block|}
name|bool
name|needsLocalForSize
argument_list|()
specifier|const
block|{
return|return
name|NeedsLocalForSize
return|;
block|}
name|StringRef
name|getPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
return|return
name|PrivateGlobalPrefix
return|;
block|}
name|StringRef
name|getPrivateLabelPrefix
argument_list|()
specifier|const
block|{
return|return
name|PrivateLabelPrefix
return|;
block|}
name|bool
name|hasLinkerPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
return|return
name|LinkerPrivateGlobalPrefix
index|[
literal|0
index|]
operator|!=
literal|'\0'
return|;
block|}
name|StringRef
name|getLinkerPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
if|if
condition|(
name|hasLinkerPrivateGlobalPrefix
argument_list|()
condition|)
return|return
name|LinkerPrivateGlobalPrefix
return|;
return|return
name|getPrivateGlobalPrefix
argument_list|()
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
name|supportsNameQuoting
argument_list|()
specifier|const
block|{
return|return
name|SupportsQuotedNames
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
name|doesSetDirectiveSuppressReloc
argument_list|()
specifier|const
block|{
return|return
name|SetDirectiveSuppressesReloc
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
name|hasFunctionAlignment
argument_list|()
specifier|const
block|{
return|return
name|HasFunctionAlignment
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
name|bool
name|hasAltEntry
argument_list|()
specifier|const
block|{
return|return
name|HasAltEntry
return|;
block|}
specifier|const
name|char
operator|*
name|getWeakDirective
argument_list|()
specifier|const
block|{
return|return
name|WeakDirective
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
name|getExceptionHandlingType
argument_list|()
specifier|const
block|{
return|return
name|ExceptionsType
return|;
block|}
name|WinEH
operator|::
name|EncodingType
name|getWinEHEncodingType
argument_list|()
specifier|const
block|{
return|return
name|WinEHEncodingType
return|;
block|}
name|void
name|setExceptionsType
parameter_list|(
name|ExceptionHandling
name|EH
parameter_list|)
block|{
name|ExceptionsType
operator|=
name|EH
expr_stmt|;
block|}
comment|/// Returns true if the exception handling method for the platform uses call
comment|/// frame information to unwind.
name|bool
name|usesCFIForEH
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
name|usesWindowsCFI
argument_list|()
operator|)
return|;
block|}
name|bool
name|usesWindowsCFI
argument_list|()
specifier|const
block|{
return|return
name|ExceptionsType
operator|==
name|ExceptionHandling
operator|::
name|WinEH
operator|&&
operator|(
name|WinEHEncodingType
operator|!=
name|WinEH
operator|::
name|EncodingType
operator|::
name|Invalid
operator|&&
name|WinEHEncodingType
operator|!=
name|WinEH
operator|::
name|EncodingType
operator|::
name|X86
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
name|bool
name|useParensForSymbolVariant
argument_list|()
specifier|const
block|{
return|return
name|UseParensForSymbolVariant
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
comment|/// Return true if assembly (inline or otherwise) should be parsed.
name|bool
name|useIntegratedAssembler
argument_list|()
specifier|const
block|{
return|return
name|UseIntegratedAssembler
return|;
block|}
comment|/// Set whether assembly (inline or otherwise) should be parsed.
name|virtual
name|void
name|setUseIntegratedAssembler
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|UseIntegratedAssembler
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Return true if assembly (inline or otherwise) should be parsed.
name|bool
name|preserveAsmComments
argument_list|()
specifier|const
block|{
return|return
name|PreserveAsmComments
return|;
block|}
comment|/// Set whether assembly (inline or otherwise) should be parsed.
name|virtual
name|void
name|setPreserveAsmComments
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|PreserveAsmComments
operator|=
name|Value
expr_stmt|;
block|}
name|DebugCompressionType
name|compressDebugSections
argument_list|()
specifier|const
block|{
return|return
name|CompressDebugSections
return|;
block|}
name|void
name|setCompressDebugSections
parameter_list|(
name|DebugCompressionType
name|CompressDebugSections
parameter_list|)
block|{
name|this
operator|->
name|CompressDebugSections
operator|=
name|CompressDebugSections
expr_stmt|;
block|}
name|bool
name|shouldUseLogicalShr
argument_list|()
specifier|const
block|{
return|return
name|UseLogicalShr
return|;
block|}
name|bool
name|canRelaxRelocations
argument_list|()
specifier|const
block|{
return|return
name|RelaxELFRelocations
return|;
block|}
name|void
name|setRelaxELFRelocations
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|RelaxELFRelocations
operator|=
name|V
expr_stmt|;
block|}
name|bool
name|hasMipsExpressions
argument_list|()
specifier|const
block|{
return|return
name|HasMipsExpressions
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCASMINFO_H
end_comment

end_unit

