begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetAsmInfo.h - Asm info ------------------*- C++ -*-===//
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
comment|// DWARF encoding query type
name|namespace
name|DwarfEncoding
block|{
enum|enum
name|Target
block|{
name|Data
init|=
literal|0
block|,
name|CodeLabels
init|=
literal|1
block|,
name|Functions
init|=
literal|2
block|}
enum|;
block|}
name|namespace
name|SectionKind
block|{
enum|enum
name|Kind
block|{
name|Unknown
init|=
literal|0
block|,
comment|///< Custom section
name|Text
block|,
comment|///< Text section
name|Data
block|,
comment|///< Data section
name|DataRel
block|,
comment|///< Contains data that has relocations
name|DataRelLocal
block|,
comment|///< Contains data that has only local relocations
name|BSS
block|,
comment|///< BSS section
name|ROData
block|,
comment|///< Readonly data section
name|DataRelRO
block|,
comment|///< Contains data that is otherwise readonly
name|DataRelROLocal
block|,
comment|///< Contains r/o data with only local relocations
name|RODataMergeStr
block|,
comment|///< Readonly data section (mergeable strings)
name|RODataMergeConst
block|,
comment|///< Readonly data section (mergeable constants)
name|SmallData
block|,
comment|///< Small data section
name|SmallBSS
block|,
comment|///< Small bss section
name|SmallROData
block|,
comment|///< Small readonly section
name|ThreadData
block|,
comment|///< Initialized TLS data objects
name|ThreadBSS
comment|///< Uninitialized TLS data objects
block|}
enum|;
specifier|static
specifier|inline
name|bool
name|isReadOnly
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
operator|(
name|K
operator|==
name|SectionKind
operator|::
name|ROData
operator|||
name|K
operator|==
name|SectionKind
operator|::
name|RODataMergeConst
operator|||
name|K
operator|==
name|SectionKind
operator|::
name|RODataMergeStr
operator|||
name|K
operator|==
name|SectionKind
operator|::
name|SmallROData
operator|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isBSS
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
operator|(
name|K
operator|==
name|SectionKind
operator|::
name|BSS
operator|||
name|K
operator|==
name|SectionKind
operator|::
name|SmallBSS
operator|)
return|;
block|}
block|}
name|namespace
name|SectionFlags
block|{
specifier|const
name|unsigned
name|Invalid
init|=
operator|-
literal|1U
decl_stmt|;
specifier|const
name|unsigned
name|None
init|=
literal|0
decl_stmt|;
specifier|const
name|unsigned
name|Code
init|=
literal|1
operator|<<
literal|0
decl_stmt|;
comment|///< Section contains code
specifier|const
name|unsigned
name|Writeable
init|=
literal|1
operator|<<
literal|1
decl_stmt|;
comment|///< Section is writeable
specifier|const
name|unsigned
name|BSS
init|=
literal|1
operator|<<
literal|2
decl_stmt|;
comment|///< Section contains only zeroes
specifier|const
name|unsigned
name|Mergeable
init|=
literal|1
operator|<<
literal|3
decl_stmt|;
comment|///< Section contains mergeable data
specifier|const
name|unsigned
name|Strings
init|=
literal|1
operator|<<
literal|4
decl_stmt|;
comment|///< Section contains C-type strings
specifier|const
name|unsigned
name|TLS
init|=
literal|1
operator|<<
literal|5
decl_stmt|;
comment|///< Section contains thread-local data
specifier|const
name|unsigned
name|Debug
init|=
literal|1
operator|<<
literal|6
decl_stmt|;
comment|///< Section contains debug data
specifier|const
name|unsigned
name|Linkonce
init|=
literal|1
operator|<<
literal|7
decl_stmt|;
comment|///< Section is linkonce
specifier|const
name|unsigned
name|Small
init|=
literal|1
operator|<<
literal|8
decl_stmt|;
comment|///< Section is small
specifier|const
name|unsigned
name|TypeFlags
init|=
literal|0xFF
decl_stmt|;
comment|// Some gap for future flags
specifier|const
name|unsigned
name|Named
init|=
literal|1
operator|<<
literal|23
decl_stmt|;
comment|///< Section is named
specifier|const
name|unsigned
name|EntitySize
init|=
literal|0xFF
operator|<<
literal|24
decl_stmt|;
comment|///< Entity size for mergeable stuff
specifier|static
specifier|inline
name|unsigned
name|getEntitySize
parameter_list|(
name|unsigned
name|Flags
parameter_list|)
block|{
return|return
operator|(
name|Flags
operator|>>
literal|24
operator|)
operator|&
literal|0xFF
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|setEntitySize
parameter_list|(
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|Size
parameter_list|)
block|{
return|return
operator|(
operator|(
name|Flags
operator|&
operator|~
name|EntitySize
operator|)
operator||
operator|(
operator|(
name|Size
operator|&
literal|0xFF
operator|)
operator|<<
literal|24
operator|)
operator|)
return|;
block|}
struct|struct
name|KeyInfo
block|{
specifier|static
specifier|inline
name|unsigned
name|getEmptyKey
parameter_list|()
block|{
return|return
name|Invalid
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|getTombstoneKey
parameter_list|()
block|{
return|return
name|Invalid
operator|-
literal|1
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|unsigned
modifier|&
name|Key
parameter_list|)
block|{
return|return
name|Key
return|;
block|}
specifier|static
name|bool
name|isEqual
parameter_list|(
name|unsigned
name|LHS
parameter_list|,
name|unsigned
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
specifier|static
name|bool
name|isPod
parameter_list|()
block|{
return|return
name|true
return|;
block|}
block|}
struct|;
typedef|typedef
name|DenseMap
operator|<
name|unsigned
operator|,
name|std
operator|::
name|string
operator|,
name|KeyInfo
operator|>
name|FlagsStringsMapType
expr_stmt|;
block|}
name|class
name|TargetMachine
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|Section
block|{
name|friend
name|class
name|TargetAsmInfo
decl_stmt|;
name|friend
name|class
name|StringMapEntry
operator|<
name|Section
operator|>
expr_stmt|;
name|friend
name|class
name|StringMap
operator|<
name|Section
operator|>
expr_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|unsigned
name|Flags
decl_stmt|;
name|explicit
name|Section
argument_list|(
argument|unsigned F = SectionFlags::Invalid
argument_list|)
block|:
name|Flags
argument_list|(
argument|F
argument_list|)
block|{ }
name|public
label|:
name|bool
name|isNamed
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|SectionFlags
operator|::
name|Named
return|;
block|}
name|unsigned
name|getEntitySize
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|>>
literal|24
operator|)
operator|&
literal|0xFF
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
block|}
empty_stmt|;
comment|/// TargetAsmInfo - This class is intended to be used as a base class for asm
comment|/// properties and features specific to the target.
name|class
name|TargetAsmInfo
block|{
name|private
label|:
name|mutable
name|StringMap
operator|<
name|Section
operator|>
name|Sections
expr_stmt|;
name|mutable
name|SectionFlags
operator|::
name|FlagsStringsMapType
name|FlagsStrings
expr_stmt|;
name|protected
label|:
comment|/// TM - The current TargetMachine.
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Properties to be set by the target writer, used to configure asm printer.
comment|//
comment|/// TextSection - Section directive for standard text.
comment|///
specifier|const
name|Section
modifier|*
name|TextSection
decl_stmt|;
comment|// Defaults to ".text".
comment|/// DataSection - Section directive for standard data.
comment|///
specifier|const
name|Section
modifier|*
name|DataSection
decl_stmt|;
comment|// Defaults to ".data".
comment|/// BSSSection - Section directive for uninitialized data.  Null if this
comment|/// target doesn't support a BSS section.
comment|///
specifier|const
name|char
modifier|*
name|BSSSection
decl_stmt|;
comment|// Default to ".bss".
specifier|const
name|Section
modifier|*
name|BSSSection_
decl_stmt|;
comment|/// ReadOnlySection - This is the directive that is emitted to switch to a
comment|/// read-only section for constant data (e.g. data declared const,
comment|/// jump tables).
specifier|const
name|Section
modifier|*
name|ReadOnlySection
decl_stmt|;
comment|// Defaults to NULL
comment|/// SmallDataSection - This is the directive that is emitted to switch to a
comment|/// small data section.
comment|///
specifier|const
name|Section
modifier|*
name|SmallDataSection
decl_stmt|;
comment|// Defaults to NULL
comment|/// SmallBSSSection - This is the directive that is emitted to switch to a
comment|/// small bss section.
comment|///
specifier|const
name|Section
modifier|*
name|SmallBSSSection
decl_stmt|;
comment|// Defaults to NULL
comment|/// SmallRODataSection - This is the directive that is emitted to switch to
comment|/// a small read-only data section.
comment|///
specifier|const
name|Section
modifier|*
name|SmallRODataSection
decl_stmt|;
comment|// Defaults to NULL
comment|/// TLSDataSection - Section directive for Thread Local data.
comment|///
specifier|const
name|Section
modifier|*
name|TLSDataSection
decl_stmt|;
comment|// Defaults to ".tdata".
comment|/// TLSBSSSection - Section directive for Thread Local uninitialized data.
comment|/// Null if this target doesn't support a BSS section.
comment|///
specifier|const
name|Section
modifier|*
name|TLSBSSSection
decl_stmt|;
comment|// Defaults to ".tbss".
comment|/// ZeroFillDirective - Directive for emitting a global to the ZeroFill
comment|/// section on this target.  Null if this target doesn't support zerofill.
specifier|const
name|char
modifier|*
name|ZeroFillDirective
decl_stmt|;
comment|// Default is null.
comment|/// NonexecutableStackDirective - Directive for declaring to the
comment|/// linker and beyond that the emitted code does not require stack
comment|/// memory to be executable.
specifier|const
name|char
modifier|*
name|NonexecutableStackDirective
decl_stmt|;
comment|// Default is null.
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
comment|/// LessPrivateGlobalPrefix - This prefix is used for symbols that should
comment|/// be passed through the assembler but be removed by the linker.  This
comment|/// is "l" on Darwin, currently used for some ObjC metadata.
specifier|const
name|char
modifier|*
name|LessPrivateGlobalPrefix
decl_stmt|;
comment|// Defaults to ""
comment|/// JumpTableSpecialLabelPrefix - If not null, a extra (dead) label is
comment|/// emitted before jump tables with the specified prefix.
specifier|const
name|char
modifier|*
name|JumpTableSpecialLabelPrefix
decl_stmt|;
comment|// Default to null.
comment|/// GlobalVarAddrPrefix/Suffix - If these are nonempty, these strings
comment|/// will enclose any GlobalVariable (that isn't a function)
comment|///
specifier|const
name|char
modifier|*
name|GlobalVarAddrPrefix
decl_stmt|;
comment|// Defaults to ""
specifier|const
name|char
modifier|*
name|GlobalVarAddrSuffix
decl_stmt|;
comment|// Defaults to ""
comment|/// FunctionAddrPrefix/Suffix - If these are nonempty, these strings
comment|/// will enclose any GlobalVariable that points to a function.
comment|/// For example, this is used by the IA64 backend to materialize
comment|/// function descriptors, by decorating the ".data8" object with the
comment|/// @verbatim @fptr( ) @endverbatim
comment|/// link-relocation operator.
comment|///
specifier|const
name|char
modifier|*
name|FunctionAddrPrefix
decl_stmt|;
comment|// Defaults to ""
specifier|const
name|char
modifier|*
name|FunctionAddrSuffix
decl_stmt|;
comment|// Defaults to ""
comment|/// PersonalityPrefix/Suffix - If these are nonempty, these strings will
comment|/// enclose any personality function in the common frame section.
comment|///
specifier|const
name|char
modifier|*
name|PersonalityPrefix
decl_stmt|;
comment|// Defaults to ""
specifier|const
name|char
modifier|*
name|PersonalitySuffix
decl_stmt|;
comment|// Defaults to ""
comment|/// NeedsIndirectEncoding - If set, we need to set the indirect encoding bit
comment|/// for EH in Dwarf.
comment|///
name|bool
name|NeedsIndirectEncoding
decl_stmt|;
comment|// Defaults to false
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
comment|/// StringConstantPrefix - Prefix for FEs to use when generating unnamed
comment|/// constant strings.  These names get run through the Mangler later; if
comment|/// you want the Mangler not to add the GlobalPrefix as well,
comment|/// use '\1' as the first character.
specifier|const
name|char
modifier|*
name|StringConstantPrefix
decl_stmt|;
comment|// Defaults to ".str"
comment|/// AllowQuotesInName - This is true if the assembler allows for complex
comment|/// symbol names to be surrounded in quotes.  This defaults to false.
name|bool
name|AllowQuotesInName
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
specifier|const
name|char
modifier|*
name|ZeroDirectiveSuffix
decl_stmt|;
comment|// Defaults to ""
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
comment|/// getASDirective - Targets can override it to provide different data
comment|/// directives for various sizes and non-default address spaces.
name|virtual
specifier|const
name|char
modifier|*
name|getASDirective
argument_list|(
name|unsigned
name|size
argument_list|,
name|unsigned
name|AS
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|AS
operator|>
literal|0
operator|&&
literal|"Dont know the directives for default addr space"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
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
comment|//===--- Section Switching Directives ---------------------------------===//
comment|/// SwitchToSectionDirective - This is the directive used when we want to
comment|/// emit a global to an arbitrary section.  The section name is emited after
comment|/// this.
specifier|const
name|char
modifier|*
name|SwitchToSectionDirective
decl_stmt|;
comment|// Defaults to "\t.section\t"
comment|/// TextSectionStartSuffix - This is printed after each start of section
comment|/// directive for text sections.
specifier|const
name|char
modifier|*
name|TextSectionStartSuffix
decl_stmt|;
comment|// Defaults to "".
comment|/// DataSectionStartSuffix - This is printed after each start of section
comment|/// directive for data sections.
specifier|const
name|char
modifier|*
name|DataSectionStartSuffix
decl_stmt|;
comment|// Defaults to "".
comment|/// SectionEndDirectiveSuffix - If non-null, the asm printer will close each
comment|/// section with the section name and this suffix printed.
specifier|const
name|char
modifier|*
name|SectionEndDirectiveSuffix
decl_stmt|;
comment|// Defaults to null.
comment|/// ConstantPoolSection - This is the section that we SwitchToSection right
comment|/// before emitting the constant pool for a function.
specifier|const
name|char
modifier|*
name|ConstantPoolSection
decl_stmt|;
comment|// Defaults to "\t.section .rodata"
comment|/// JumpTableDataSection - This is the section that we SwitchToSection right
comment|/// before emitting the jump tables for a function when the relocation model
comment|/// is not PIC.
specifier|const
name|char
modifier|*
name|JumpTableDataSection
decl_stmt|;
comment|// Defaults to "\t.section .rodata"
comment|/// JumpTableDirective - if non-null, the directive to emit before a jump
comment|/// table.
specifier|const
name|char
modifier|*
name|JumpTableDirective
decl_stmt|;
comment|/// CStringSection - If not null, this allows for special handling of
comment|/// cstring constants (null terminated string that does not contain any
comment|/// other null bytes) on this target. This is commonly supported as
comment|/// ".cstring".
specifier|const
name|char
modifier|*
name|CStringSection
decl_stmt|;
comment|// Defaults to NULL
specifier|const
name|Section
modifier|*
name|CStringSection_
decl_stmt|;
comment|/// StaticCtorsSection - This is the directive that is emitted to switch to
comment|/// a section to emit the static constructor list.
comment|/// Defaults to "\t.section .ctors,\"aw\",@progbits".
specifier|const
name|char
modifier|*
name|StaticCtorsSection
decl_stmt|;
comment|/// StaticDtorsSection - This is the directive that is emitted to switch to
comment|/// a section to emit the static destructor list.
comment|/// Defaults to "\t.section .dtors,\"aw\",@progbits".
specifier|const
name|char
modifier|*
name|StaticDtorsSection
decl_stmt|;
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
comment|/// LCOMMDirective - This is the name of a directive (if supported) that can
comment|/// be used to efficiently declare a local (internal) block of zero
comment|/// initialized data in the .bss/.data section.  The syntax expected is:
comment|/// @verbatim<LCOMMDirective> SYMBOLNAME LENGTHINBYTES, ALIGNMENT
comment|/// @endverbatim
specifier|const
name|char
modifier|*
name|LCOMMDirective
decl_stmt|;
comment|// Defaults to null.
specifier|const
name|char
modifier|*
name|COMMDirective
decl_stmt|;
comment|// Defaults to "\t.comm\t".
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
comment|/// UsedDirective - This directive, if non-null, is used to declare a global
comment|/// as being used somehow that the assembler can't see.  This prevents dead
comment|/// code elimination on some targets.
specifier|const
name|char
modifier|*
name|UsedDirective
decl_stmt|;
comment|// Defaults to null.
comment|/// WeakRefDirective - This directive, if non-null, is used to declare a
comment|/// global as being a weak undefined symbol.
specifier|const
name|char
modifier|*
name|WeakRefDirective
decl_stmt|;
comment|// Defaults to null.
comment|/// WeakDefDirective - This directive, if non-null, is used to declare a
comment|/// global as being a weak defined symbol.
specifier|const
name|char
modifier|*
name|WeakDefDirective
decl_stmt|;
comment|// Defaults to null.
comment|/// HiddenDirective - This directive, if non-null, is used to declare a
comment|/// global or function as having hidden visibility.
specifier|const
name|char
modifier|*
name|HiddenDirective
decl_stmt|;
comment|// Defaults to "\t.hidden\t".
comment|/// ProtectedDirective - This directive, if non-null, is used to declare a
comment|/// global or function as having protected visibility.
specifier|const
name|char
modifier|*
name|ProtectedDirective
decl_stmt|;
comment|// Defaults to "\t.protected\t".
comment|//===--- Dwarf Emission Directives -----------------------------------===//
comment|/// AbsoluteDebugSectionOffsets - True if we should emit abolute section
comment|/// offsets for debug information. Defaults to false.
name|bool
name|AbsoluteDebugSectionOffsets
decl_stmt|;
comment|/// AbsoluteEHSectionOffsets - True if we should emit abolute section
comment|/// offsets for EH information. Defaults to false.
name|bool
name|AbsoluteEHSectionOffsets
decl_stmt|;
comment|/// HasLEB128 - True if target asm supports leb128 directives.
comment|///
name|bool
name|HasLEB128
decl_stmt|;
comment|// Defaults to false.
comment|/// hasDotLocAndDotFile - True if target asm supports .loc and .file
comment|/// directives for emitting debugging information.
comment|///
name|bool
name|HasDotLocAndDotFile
decl_stmt|;
comment|// Defaults to false.
comment|/// SupportsDebugInformation - True if target supports emission of debugging
comment|/// information.
name|bool
name|SupportsDebugInformation
decl_stmt|;
comment|/// SupportsExceptionHandling - True if target supports
comment|/// exception handling.
comment|///
name|bool
name|SupportsExceptionHandling
decl_stmt|;
comment|// Defaults to false.
comment|/// RequiresFrameSection - true if the Dwarf2 output needs a frame section
comment|///
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
comment|/// NonLocalEHFrameLabel - If set, the EH_frame label needs to be non-local.
comment|///
name|bool
name|NonLocalEHFrameLabel
decl_stmt|;
comment|// Defaults to false.
comment|/// GlobalEHDirective - This is the directive used to make exception frame
comment|/// tables globally visible.
comment|///
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
comment|/// DwarfAbbrevSection - Section directive for Dwarf abbrev.
comment|///
specifier|const
name|char
modifier|*
name|DwarfAbbrevSection
decl_stmt|;
comment|// Defaults to ".debug_abbrev".
comment|/// DwarfInfoSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfInfoSection
decl_stmt|;
comment|// Defaults to ".debug_info".
comment|/// DwarfLineSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfLineSection
decl_stmt|;
comment|// Defaults to ".debug_line".
comment|/// DwarfFrameSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfFrameSection
decl_stmt|;
comment|// Defaults to ".debug_frame".
comment|/// DwarfPubNamesSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfPubNamesSection
decl_stmt|;
comment|// Defaults to ".debug_pubnames".
comment|/// DwarfPubTypesSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfPubTypesSection
decl_stmt|;
comment|// Defaults to ".debug_pubtypes".
comment|/// DwarfDebugInlineSection - Section directive for inline info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfDebugInlineSection
decl_stmt|;
comment|// Defaults to ".debug_inlined"
comment|/// DwarfStrSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfStrSection
decl_stmt|;
comment|// Defaults to ".debug_str".
comment|/// DwarfLocSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfLocSection
decl_stmt|;
comment|// Defaults to ".debug_loc".
comment|/// DwarfARangesSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfARangesSection
decl_stmt|;
comment|// Defaults to ".debug_aranges".
comment|/// DwarfRangesSection - Section directive for Dwarf info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfRangesSection
decl_stmt|;
comment|// Defaults to ".debug_ranges".
comment|/// DwarfMacroInfoSection - Section directive for DWARF macro info.
comment|///
specifier|const
name|char
modifier|*
name|DwarfMacroInfoSection
decl_stmt|;
comment|// Defaults to ".debug_macinfo".
comment|/// DwarfEHFrameSection - Section directive for Exception frames.
comment|///
specifier|const
name|char
modifier|*
name|DwarfEHFrameSection
decl_stmt|;
comment|// Defaults to ".eh_frame".
comment|/// DwarfExceptionSection - Section directive for Exception table.
comment|///
specifier|const
name|char
modifier|*
name|DwarfExceptionSection
decl_stmt|;
comment|// Defaults to ".gcc_except_table".
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
name|TargetAsmInfo
parameter_list|(
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|virtual
operator|~
name|TargetAsmInfo
argument_list|()
expr_stmt|;
specifier|const
name|Section
modifier|*
name|getNamedSection
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|,
name|unsigned
name|Flags
operator|=
name|SectionFlags
operator|::
name|None
argument_list|,
name|bool
name|Override
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|Section
modifier|*
name|getUnnamedSection
argument_list|(
specifier|const
name|char
operator|*
name|Directive
argument_list|,
name|unsigned
name|Flags
operator|=
name|SectionFlags
operator|::
name|None
argument_list|,
name|bool
name|Override
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// Measure the specified inline asm to determine an approximation of its
comment|/// length.
name|virtual
name|unsigned
name|getInlineAsmLength
argument_list|(
specifier|const
name|char
operator|*
name|Str
argument_list|)
decl|const
decl_stmt|;
comment|/// ExpandInlineAsm - This hook allows the target to expand an inline asm
comment|/// call to be explicit llvm code if it wants to.  This is useful for
comment|/// turning simple inline asms into LLVM intrinsics, which gives the
comment|/// compiler more information about the behavior of the code.
name|virtual
name|bool
name|ExpandInlineAsm
argument_list|(
name|CallInst
operator|*
name|CI
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// emitUsedDirectiveFor - This hook allows targets to selectively decide
comment|/// not to emit the UsedDirective for some symbols in llvm.used.
name|virtual
name|bool
name|emitUsedDirectiveFor
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|Mangler
operator|*
name|Mang
argument_list|)
decl|const
block|{
return|return
operator|(
name|GV
operator|!=
literal|0
operator|)
return|;
block|}
comment|/// PreferredEHDataFormat - This hook allows the target to select data
comment|/// format used for encoding pointers in exception handling data. Reason is
comment|/// 0 for data, 1 for code labels, 2 for function pointers. Global is true
comment|/// if the symbol can be relocated.
name|virtual
name|unsigned
name|PreferredEHDataFormat
argument_list|(
name|DwarfEncoding
operator|::
name|Target
name|Reason
argument_list|,
name|bool
name|Global
argument_list|)
decl|const
decl_stmt|;
comment|/// SectionKindForGlobal - This hook allows the target to select proper
comment|/// section kind used for global emission.
name|virtual
name|SectionKind
operator|::
name|Kind
name|SectionKindForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
expr_stmt|;
comment|/// RelocBehaviour - Describes how relocations should be treated when
comment|/// selecting sections. Reloc::Global bit should be set if global
comment|/// relocations should force object to be placed in read-write
comment|/// sections. Reloc::Local bit should be set if local relocations should
comment|/// force object to be placed in read-write sections.
name|virtual
name|unsigned
name|RelocBehaviour
argument_list|()
specifier|const
expr_stmt|;
comment|/// SectionFlagsForGlobal - This hook allows the target to select proper
comment|/// section flags either for given global or for section.
name|virtual
name|unsigned
name|SectionFlagsForGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
operator|=
name|NULL
argument_list|,
specifier|const
name|char
operator|*
name|name
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
comment|/// SectionForGlobal - This hooks returns proper section name for given
comment|/// global with all necessary flags and marks.
name|virtual
specifier|const
name|Section
modifier|*
name|SectionForGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
decl|const
decl_stmt|;
comment|// Helper methods for SectionForGlobal
name|virtual
name|std
operator|::
name|string
name|UniqueSectionForGlobal
argument_list|(
argument|const GlobalValue* GV
argument_list|,
argument|SectionKind::Kind kind
argument_list|)
specifier|const
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getSectionFlags
argument_list|(
argument|unsigned Flags
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|std
operator|::
name|string
name|printSectionFlags
argument_list|(
argument|unsigned flags
argument_list|)
specifier|const
block|{
return|return
literal|""
return|;
block|}
name|virtual
specifier|const
name|Section
modifier|*
name|SelectSectionForGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
decl|const
decl_stmt|;
name|virtual
specifier|const
name|Section
modifier|*
name|SelectSectionForMachineConst
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getSLEB128Size - Compute the number of bytes required for a signed
comment|/// leb128 value.
specifier|static
name|unsigned
name|getSLEB128Size
parameter_list|(
name|int
name|Value
parameter_list|)
function_decl|;
comment|/// getULEB128Size - Compute the number of bytes required for an unsigned
comment|/// leb128 value.
specifier|static
name|unsigned
name|getULEB128Size
parameter_list|(
name|unsigned
name|Value
parameter_list|)
function_decl|;
comment|// Data directive accessors
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
name|getASDirective
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
name|getASDirective
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
name|getASDirective
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
name|getASDirective
argument_list|(
literal|64
argument_list|,
name|AS
argument_list|)
return|;
block|}
comment|// Accessors.
comment|//
specifier|const
name|Section
operator|*
name|getTextSection
argument_list|()
specifier|const
block|{
return|return
name|TextSection
return|;
block|}
specifier|const
name|Section
operator|*
name|getDataSection
argument_list|()
specifier|const
block|{
return|return
name|DataSection
return|;
block|}
specifier|const
name|char
operator|*
name|getBSSSection
argument_list|()
specifier|const
block|{
return|return
name|BSSSection
return|;
block|}
specifier|const
name|Section
operator|*
name|getBSSSection_
argument_list|()
specifier|const
block|{
return|return
name|BSSSection_
return|;
block|}
specifier|const
name|Section
operator|*
name|getReadOnlySection
argument_list|()
specifier|const
block|{
return|return
name|ReadOnlySection
return|;
block|}
specifier|const
name|Section
operator|*
name|getSmallDataSection
argument_list|()
specifier|const
block|{
return|return
name|SmallDataSection
return|;
block|}
specifier|const
name|Section
operator|*
name|getSmallBSSSection
argument_list|()
specifier|const
block|{
return|return
name|SmallBSSSection
return|;
block|}
specifier|const
name|Section
operator|*
name|getSmallRODataSection
argument_list|()
specifier|const
block|{
return|return
name|SmallRODataSection
return|;
block|}
specifier|const
name|Section
operator|*
name|getTLSDataSection
argument_list|()
specifier|const
block|{
return|return
name|TLSDataSection
return|;
block|}
specifier|const
name|Section
operator|*
name|getTLSBSSSection
argument_list|()
specifier|const
block|{
return|return
name|TLSBSSSection
return|;
block|}
specifier|const
name|char
operator|*
name|getZeroFillDirective
argument_list|()
specifier|const
block|{
return|return
name|ZeroFillDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getNonexecutableStackDirective
argument_list|()
specifier|const
block|{
return|return
name|NonexecutableStackDirective
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
comment|/// EHGlobalPrefix - Prefix for EH_frame and the .eh symbols.
comment|/// This is normally PrivateGlobalPrefix, but some targets want
comment|/// these symbols to be visible.
name|virtual
specifier|const
name|char
operator|*
name|getEHGlobalPrefix
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
name|getLessPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
return|return
name|LessPrivateGlobalPrefix
return|;
block|}
specifier|const
name|char
operator|*
name|getJumpTableSpecialLabelPrefix
argument_list|()
specifier|const
block|{
return|return
name|JumpTableSpecialLabelPrefix
return|;
block|}
specifier|const
name|char
operator|*
name|getGlobalVarAddrPrefix
argument_list|()
specifier|const
block|{
return|return
name|GlobalVarAddrPrefix
return|;
block|}
specifier|const
name|char
operator|*
name|getGlobalVarAddrSuffix
argument_list|()
specifier|const
block|{
return|return
name|GlobalVarAddrSuffix
return|;
block|}
specifier|const
name|char
operator|*
name|getFunctionAddrPrefix
argument_list|()
specifier|const
block|{
return|return
name|FunctionAddrPrefix
return|;
block|}
specifier|const
name|char
operator|*
name|getFunctionAddrSuffix
argument_list|()
specifier|const
block|{
return|return
name|FunctionAddrSuffix
return|;
block|}
specifier|const
name|char
operator|*
name|getPersonalityPrefix
argument_list|()
specifier|const
block|{
return|return
name|PersonalityPrefix
return|;
block|}
specifier|const
name|char
operator|*
name|getPersonalitySuffix
argument_list|()
specifier|const
block|{
return|return
name|PersonalitySuffix
return|;
block|}
name|bool
name|getNeedsIndirectEncoding
argument_list|()
specifier|const
block|{
return|return
name|NeedsIndirectEncoding
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
specifier|const
name|char
operator|*
name|getStringConstantPrefix
argument_list|()
specifier|const
block|{
return|return
name|StringConstantPrefix
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
name|getZeroDirectiveSuffix
argument_list|()
specifier|const
block|{
return|return
name|ZeroDirectiveSuffix
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
name|getJumpTableDirective
argument_list|()
specifier|const
block|{
return|return
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
name|getSwitchToSectionDirective
argument_list|()
specifier|const
block|{
return|return
name|SwitchToSectionDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getTextSectionStartSuffix
argument_list|()
specifier|const
block|{
return|return
name|TextSectionStartSuffix
return|;
block|}
specifier|const
name|char
operator|*
name|getDataSectionStartSuffix
argument_list|()
specifier|const
block|{
return|return
name|DataSectionStartSuffix
return|;
block|}
specifier|const
name|char
operator|*
name|getSectionEndDirectiveSuffix
argument_list|()
specifier|const
block|{
return|return
name|SectionEndDirectiveSuffix
return|;
block|}
specifier|const
name|char
operator|*
name|getConstantPoolSection
argument_list|()
specifier|const
block|{
return|return
name|ConstantPoolSection
return|;
block|}
specifier|const
name|char
operator|*
name|getJumpTableDataSection
argument_list|()
specifier|const
block|{
return|return
name|JumpTableDataSection
return|;
block|}
specifier|const
name|char
operator|*
name|getCStringSection
argument_list|()
specifier|const
block|{
return|return
name|CStringSection
return|;
block|}
specifier|const
name|Section
operator|*
name|getCStringSection_
argument_list|()
specifier|const
block|{
return|return
name|CStringSection_
return|;
block|}
specifier|const
name|char
operator|*
name|getStaticCtorsSection
argument_list|()
specifier|const
block|{
return|return
name|StaticCtorsSection
return|;
block|}
specifier|const
name|char
operator|*
name|getStaticDtorsSection
argument_list|()
specifier|const
block|{
return|return
name|StaticDtorsSection
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
specifier|const
name|char
operator|*
name|getLCOMMDirective
argument_list|()
specifier|const
block|{
return|return
name|LCOMMDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getCOMMDirective
argument_list|()
specifier|const
block|{
return|return
name|COMMDirective
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
specifier|const
name|char
operator|*
name|getUsedDirective
argument_list|()
specifier|const
block|{
return|return
name|UsedDirective
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
name|getHiddenDirective
argument_list|()
specifier|const
block|{
return|return
name|HiddenDirective
return|;
block|}
specifier|const
name|char
operator|*
name|getProtectedDirective
argument_list|()
specifier|const
block|{
return|return
name|ProtectedDirective
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
name|SupportsExceptionHandling
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
name|doesRequireNonLocalEHFrameLabel
argument_list|()
specifier|const
block|{
return|return
name|NonLocalEHFrameLabel
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
name|getDwarfAbbrevSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfAbbrevSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfInfoSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfInfoSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfLineSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfLineSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfFrameSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfFrameSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfPubNamesSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfPubNamesSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfPubTypesSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfPubTypesSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfDebugInlineSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfDebugInlineSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfStrSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfStrSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfLocSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfLocSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfARangesSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfARangesSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfRangesSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfRangesSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfMacroInfoSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfMacroInfoSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfEHFrameSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfEHFrameSection
return|;
block|}
specifier|const
name|char
operator|*
name|getDwarfExceptionSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfExceptionSection
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

