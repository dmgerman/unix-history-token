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
name|LLVM_TARGET_ASM_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_ASM_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCDirectives.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSection
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
comment|/// MCAsmInfo - This class is intended to be used as a base class for asm
comment|/// properties and features specific to the target.
name|namespace
name|ExceptionHandling
block|{
enum|enum
name|ExceptionsType
block|{
name|None
block|,
name|Dwarf
block|,
name|SjLj
block|}
enum|;
block|}
name|class
name|MCAsmInfo
block|{
name|protected
label|:
comment|//===------------------------------------------------------------------===//
comment|// Properties to be set by the target writer, used to configure asm printer.
comment|//
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
comment|/// HasStaticCtorDtorReferenceInStaticMode - True if the compiler should
comment|/// emit a ".reference .constructors_used" or ".reference .destructors_used"
comment|/// directive after the a static ctor/dtor list.  This directive is only
comment|/// emitted in Static relocation model.
name|bool
name|HasStaticCtorDtorReferenceInStaticMode
decl_stmt|;
comment|// Default is false.
comment|/// NeedsSet - True if target asm treats expressions in data directives
comment|/// as linktime-relocatable.  For assembly-time computation, we need to
comment|/// use a .set.  Thus:
comment|/// .set w, x-y
comment|/// .long w
comment|/// is computed at assembly time, while
comment|/// .long x-y
comment|/// is relocated if the relative locations of x and y change at linktime.
comment|/// We want both these things in different places.
name|bool
name|NeedsSet
decl_stmt|;
comment|// Defaults to false.
comment|/// MaxInstLength - This is the maximum possible length of an instruction,
comment|/// which is needed to compute the size of an inline asm.
name|unsigned
name|MaxInstLength
decl_stmt|;
comment|// Defaults to 4.
comment|/// PCSymbol - The symbol used to represent the current PC.  Used in PC
comment|/// relative expressions.
specifier|const
name|char
modifier|*
name|PCSymbol
decl_stmt|;
comment|// Defaults to "$".
comment|/// SeparatorChar - This character, if specified, is used to separate
comment|/// instructions from each other when on the same line.  This is used to
comment|/// measure inline asm instructions.
name|char
name|SeparatorChar
decl_stmt|;
comment|// Defaults to ';'
comment|/// CommentColumn - This indicates the comment num (zero-based) at
comment|/// which asm comments should be printed.
name|unsigned
name|CommentColumn
decl_stmt|;
comment|// Defaults to 60
comment|/// CommentString - This indicates the comment character used by the
comment|/// assembler.
specifier|const
name|char
modifier|*
name|CommentString
decl_stmt|;
comment|// Defaults to "#"
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
comment|/// AssemblerDialect - Which dialect of an assembler variant to use.
name|unsigned
name|AssemblerDialect
decl_stmt|;
comment|// Defaults to 0
comment|/// AllowQuotesInName - This is true if the assembler allows for complex
comment|/// symbol names to be surrounded in quotes.  This defaults to false.
name|bool
name|AllowQuotesInName
decl_stmt|;
comment|/// AllowNameToStartWithDigit - This is true if the assembler allows symbol
comment|/// names to start with a digit (e.g., "0x0021").  This defaults to false.
name|bool
name|AllowNameToStartWithDigit
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
comment|/// getDataASDirective - Return the directive that should be used to emit
comment|/// data of the specified size to the specified numeric address space.
name|virtual
specifier|const
name|char
modifier|*
name|getDataASDirective
argument_list|(
name|unsigned
name|Size
argument_list|,
name|unsigned
name|AS
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|AS
operator|!=
literal|0
operator|&&
literal|"Don't know the directives for default addr space"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
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
comment|//===--- Section Switching Directives ---------------------------------===//
comment|/// JumpTableDirective - if non-null, the directive to emit before jump
comment|/// table entries.  FIXME: REMOVE THIS.
specifier|const
name|char
modifier|*
name|JumpTableDirective
decl_stmt|;
comment|// Defaults to NULL.
specifier|const
name|char
modifier|*
name|PICJumpTableDirective
decl_stmt|;
comment|// Defaults to NULL.
comment|//===--- Global Variable Emission Directives --------------------------===//
comment|/// GlobalDirective - This is the directive used to declare a global entity.
comment|///
specifier|const
name|char
modifier|*
name|GlobalDirective
decl_stmt|;
comment|// Defaults to NULL.
comment|/// ExternDirective - This is the directive used to declare external
comment|/// globals.
comment|///
specifier|const
name|char
modifier|*
name|ExternDirective
decl_stmt|;
comment|// Defaults to NULL.
comment|/// SetDirective - This is the name of a directive that can be used to tell
comment|/// the assembler to set the value of a variable to some expression.
specifier|const
name|char
modifier|*
name|SetDirective
decl_stmt|;
comment|// Defaults to null.
comment|/// HasLCOMMDirective - This is true if the target supports the .lcomm
comment|/// directive.
name|bool
name|HasLCOMMDirective
decl_stmt|;
comment|// Defaults to false.
comment|/// COMMDirectiveTakesAlignment - True if COMMDirective take a third
comment|/// argument that specifies the alignment of the declaration.
name|bool
name|COMMDirectiveTakesAlignment
decl_stmt|;
comment|// Defaults to true.
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
comment|/// WeakDefDirective - This directive, if non-null, is used to declare a
comment|/// global as being a weak defined symbol.
specifier|const
name|char
modifier|*
name|WeakDefDirective
decl_stmt|;
comment|// Defaults to NULL.
comment|/// LinkOnceDirective - This directive, if non-null is used to declare a
comment|/// global as being a weak defined symbol.  This is used on cygwin/mingw.
specifier|const
name|char
modifier|*
name|LinkOnceDirective
decl_stmt|;
comment|// Defaults to NULL.
comment|/// HiddenVisibilityAttr - This attribute, if not MCSA_Invalid, is used to
comment|/// declare a symbol as having hidden visibility.
name|MCSymbolAttr
name|HiddenVisibilityAttr
decl_stmt|;
comment|// Defaults to MCSA_Hidden.
comment|/// ProtectedVisibilityAttr - This attribute, if not MCSA_Invalid, is used
comment|/// to declare a symbol as having protected visibility.
name|MCSymbolAttr
name|ProtectedVisibilityAttr
decl_stmt|;
comment|// Defaults to MCSA_Protected
comment|//===--- Dwarf Emission Directives -----------------------------------===//
comment|/// AbsoluteDebugSectionOffsets - True if we should emit abolute section
comment|/// offsets for debug information.
name|bool
name|AbsoluteDebugSectionOffsets
decl_stmt|;
comment|// Defaults to false.
comment|/// AbsoluteEHSectionOffsets - True if we should emit abolute section
comment|/// offsets for EH information. Defaults to false.
name|bool
name|AbsoluteEHSectionOffsets
decl_stmt|;
comment|/// HasLEB128 - True if target asm supports leb128 directives.
name|bool
name|HasLEB128
decl_stmt|;
comment|// Defaults to false.
comment|/// hasDotLocAndDotFile - True if target asm supports .loc and .file
comment|/// directives for emitting debugging information.
name|bool
name|HasDotLocAndDotFile
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
comment|/// RequiresFrameSection - true if the Dwarf2 output needs a frame section
name|bool
name|DwarfRequiresFrameSection
decl_stmt|;
comment|// Defaults to true.
comment|/// DwarfUsesInlineInfoSection - True if DwarfDebugInlineSection is used to
comment|/// encode inline subroutine information.
name|bool
name|DwarfUsesInlineInfoSection
decl_stmt|;
comment|// Defaults to false.
comment|/// Is_EHSymbolPrivate - If set, the "_foo.eh" is made private so that it
comment|/// doesn't show up in the symbol table of the object file.
name|bool
name|Is_EHSymbolPrivate
decl_stmt|;
comment|// Defaults to true.
comment|/// GlobalEHDirective - This is the directive used to make exception frame
comment|/// tables globally visible.
specifier|const
name|char
modifier|*
name|GlobalEHDirective
decl_stmt|;
comment|// Defaults to NULL.
comment|/// SupportsWeakEmptyEHFrame - True if target assembler and linker will
comment|/// handle a weak_definition of constant 0 for an omitted EH frame.
name|bool
name|SupportsWeakOmittedEHFrame
decl_stmt|;
comment|// Defaults to true.
comment|/// DwarfSectionOffsetDirective - Special section offset directive.
specifier|const
name|char
modifier|*
name|DwarfSectionOffsetDirective
decl_stmt|;
comment|// Defaults to NULL
comment|//===--- CBE Asm Translation Table -----------------------------------===//
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|AsmTransCBE
decl_stmt|;
comment|// Defaults to empty
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
name|int
name|Value
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|getULEB128Size
parameter_list|(
name|unsigned
name|Value
parameter_list|)
function_decl|;
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
modifier|*
name|getData8bitsDirective
argument_list|(
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|AS
operator|==
literal|0
condition|?
name|Data8bitsDirective
else|:
name|getDataASDirective
argument_list|(
literal|8
argument_list|,
name|AS
argument_list|)
return|;
block|}
specifier|const
name|char
modifier|*
name|getData16bitsDirective
argument_list|(
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|AS
operator|==
literal|0
condition|?
name|Data16bitsDirective
else|:
name|getDataASDirective
argument_list|(
literal|16
argument_list|,
name|AS
argument_list|)
return|;
block|}
specifier|const
name|char
modifier|*
name|getData32bitsDirective
argument_list|(
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|AS
operator|==
literal|0
condition|?
name|Data32bitsDirective
else|:
name|getDataASDirective
argument_list|(
literal|32
argument_list|,
name|AS
argument_list|)
return|;
block|}
specifier|const
name|char
modifier|*
name|getData64bitsDirective
argument_list|(
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|AS
operator|==
literal|0
condition|?
name|Data64bitsDirective
else|:
name|getDataASDirective
argument_list|(
literal|64
argument_list|,
name|AS
argument_list|)
return|;
block|}
comment|/// getNonexecutableStackSection - Targets can implement this method to
comment|/// specify a section to switch to if the translation unit doesn't have any
comment|/// trampolines that require an executable stack.
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
literal|0
return|;
block|}
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
name|hasStaticCtorDtorReferenceInStaticMode
argument_list|()
specifier|const
block|{
return|return
name|HasStaticCtorDtorReferenceInStaticMode
return|;
block|}
name|bool
name|needsSet
argument_list|()
specifier|const
block|{
return|return
name|NeedsSet
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
specifier|const
name|char
operator|*
name|getPCSymbol
argument_list|()
specifier|const
block|{
return|return
name|PCSymbol
return|;
block|}
name|char
name|getSeparatorChar
argument_list|()
specifier|const
block|{
return|return
name|SeparatorChar
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
name|doesAllowQuotesInName
argument_list|()
specifier|const
block|{
return|return
name|AllowQuotesInName
return|;
block|}
name|bool
name|doesAllowNameToStartWithDigit
argument_list|()
specifier|const
block|{
return|return
name|AllowNameToStartWithDigit
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
modifier|*
name|getJumpTableDirective
argument_list|(
name|bool
name|isPIC
argument_list|)
decl|const
block|{
return|return
name|isPIC
condition|?
name|PICJumpTableDirective
else|:
name|JumpTableDirective
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
specifier|const
name|char
operator|*
name|getExternDirective
argument_list|()
specifier|const
block|{
return|return
name|ExternDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getSetDirective
argument_list|()
specifier|const
block|{
return|return
name|SetDirective
return|;
block|}
name|bool
name|hasLCOMMDirective
argument_list|()
specifier|const
block|{
return|return
name|HasLCOMMDirective
return|;
block|}
name|bool
name|getCOMMDirectiveTakesAlignment
argument_list|()
specifier|const
block|{
return|return
name|COMMDirectiveTakesAlignment
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
specifier|const
name|char
operator|*
name|getWeakDefDirective
argument_list|()
specifier|const
block|{
return|return
name|WeakDefDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getLinkOnceDirective
argument_list|()
specifier|const
block|{
return|return
name|LinkOnceDirective
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
name|getProtectedVisibilityAttr
argument_list|()
specifier|const
block|{
return|return
name|ProtectedVisibilityAttr
return|;
block|}
name|bool
name|isAbsoluteDebugSectionOffsets
argument_list|()
specifier|const
block|{
return|return
name|AbsoluteDebugSectionOffsets
return|;
block|}
name|bool
name|isAbsoluteEHSectionOffsets
argument_list|()
specifier|const
block|{
return|return
name|AbsoluteEHSectionOffsets
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
name|hasDotLocAndDotFile
argument_list|()
specifier|const
block|{
return|return
name|HasDotLocAndDotFile
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
name|doesDwarfRequireFrameSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfRequiresFrameSection
return|;
block|}
name|bool
name|doesDwarfUsesInlineInfoSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfUsesInlineInfoSection
return|;
block|}
name|bool
name|is_EHSymbolPrivate
argument_list|()
specifier|const
block|{
return|return
name|Is_EHSymbolPrivate
return|;
block|}
specifier|const
name|char
operator|*
name|getGlobalEHDirective
argument_list|()
specifier|const
block|{
return|return
name|GlobalEHDirective
return|;
block|}
name|bool
name|getSupportsWeakOmittedEHFrame
argument_list|()
specifier|const
block|{
return|return
name|SupportsWeakOmittedEHFrame
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfSectionOffsetDirective
argument_list|()
specifier|const
block|{
return|return
name|DwarfSectionOffsetDirective
return|;
block|}
specifier|const
name|char
operator|*
specifier|const
operator|*
name|getAsmCBE
argument_list|()
specifier|const
block|{
return|return
name|AsmTransCBE
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

