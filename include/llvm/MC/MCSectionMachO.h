begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSectionMachO.h - MachO Machine Code Sections -----------*- C++ -*-===//
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
comment|// This file declares the MCSectionMachO class.
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
name|LLVM_MC_MCSECTIONMACHO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTIONMACHO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCSectionMachO - This represents a section on a Mach-O system (used by
comment|/// Mac OS X).  On a Mac system, these are also described in
comment|/// /usr/include/mach-o/loader.h.
name|class
name|MCSectionMachO
range|:
name|public
name|MCSection
block|{
name|char
name|SegmentName
index|[
literal|16
index|]
block|;
comment|// Not necessarily null terminated!
name|char
name|SectionName
index|[
literal|16
index|]
block|;
comment|// Not necessarily null terminated!
comment|/// TypeAndAttributes - This is the SECTION_TYPE and SECTION_ATTRIBUTES
comment|/// field of a section, drawn from the enums below.
name|unsigned
name|TypeAndAttributes
block|;
comment|/// Reserved2 - The 'reserved2' field of a section, used to represent the
comment|/// size of stubs, for example.
name|unsigned
name|Reserved2
block|;
name|MCSectionMachO
argument_list|(
argument|StringRef Segment
argument_list|,
argument|StringRef Section
argument_list|,
argument|unsigned TAA
argument_list|,
argument|unsigned reserved2
argument_list|,
argument|SectionKind K
argument_list|)
operator|:
name|MCSection
argument_list|(
name|K
argument_list|)
block|,
name|TypeAndAttributes
argument_list|(
name|TAA
argument_list|)
block|,
name|Reserved2
argument_list|(
argument|reserved2
argument_list|)
block|{
name|assert
argument_list|(
name|Segment
operator|.
name|size
argument_list|()
operator|<=
literal|16
operator|&&
name|Section
operator|.
name|size
argument_list|()
operator|<=
literal|16
operator|&&
literal|"Segment or section string too long"
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
literal|16
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|<
name|Segment
operator|.
name|size
argument_list|()
condition|)
name|SegmentName
index|[
name|i
index|]
operator|=
name|Segment
index|[
name|i
index|]
expr_stmt|;
else|else
name|SegmentName
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|i
operator|<
name|Section
operator|.
name|size
argument_list|()
condition|)
name|SectionName
index|[
name|i
index|]
operator|=
name|Section
index|[
name|i
index|]
expr_stmt|;
else|else
name|SectionName
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
name|public
operator|:
specifier|static
name|MCSectionMachO
operator|*
name|Create
argument_list|(
argument|StringRef Segment
argument_list|,
argument|StringRef Section
argument_list|,
argument|unsigned TypeAndAttributes
argument_list|,
argument|unsigned Reserved2
argument_list|,
argument|SectionKind K
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// These are the section type and attributes fields.  A MachO section can
comment|/// have only one Type, but can have any of the attributes specified.
block|enum
block|{
comment|// TypeAndAttributes bitmasks.
name|SECTION_TYPE
operator|=
literal|0x000000FFU
block|,
name|SECTION_ATTRIBUTES
operator|=
literal|0xFFFFFF00U
block|,
comment|// Valid section types.
comment|/// S_REGULAR - Regular section.
name|S_REGULAR
operator|=
literal|0x00U
block|,
comment|/// S_ZEROFILL - Zero fill on demand section.
name|S_ZEROFILL
operator|=
literal|0x01U
block|,
comment|/// S_CSTRING_LITERALS - Section with literal C strings.
name|S_CSTRING_LITERALS
operator|=
literal|0x02U
block|,
comment|/// S_4BYTE_LITERALS - Section with 4 byte literals.
name|S_4BYTE_LITERALS
operator|=
literal|0x03U
block|,
comment|/// S_8BYTE_LITERALS - Section with 8 byte literals.
name|S_8BYTE_LITERALS
operator|=
literal|0x04U
block|,
comment|/// S_LITERAL_POINTERS - Section with pointers to literals.
name|S_LITERAL_POINTERS
operator|=
literal|0x05U
block|,
comment|/// S_NON_LAZY_SYMBOL_POINTERS - Section with non-lazy symbol pointers.
name|S_NON_LAZY_SYMBOL_POINTERS
operator|=
literal|0x06U
block|,
comment|/// S_LAZY_SYMBOL_POINTERS - Section with lazy symbol pointers.
name|S_LAZY_SYMBOL_POINTERS
operator|=
literal|0x07U
block|,
comment|/// S_SYMBOL_STUBS - Section with symbol stubs, byte size of stub in
comment|/// the Reserved2 field.
name|S_SYMBOL_STUBS
operator|=
literal|0x08U
block|,
comment|/// S_SYMBOL_STUBS - Section with only function pointers for
comment|/// initialization.
name|S_MOD_INIT_FUNC_POINTERS
operator|=
literal|0x09U
block|,
comment|/// S_MOD_INIT_FUNC_POINTERS - Section with only function pointers for
comment|/// termination.
name|S_MOD_TERM_FUNC_POINTERS
operator|=
literal|0x0AU
block|,
comment|/// S_COALESCED - Section contains symbols that are to be coalesced.
name|S_COALESCED
operator|=
literal|0x0BU
block|,
comment|/// S_GB_ZEROFILL - Zero fill on demand section (that can be larger than 4
comment|/// gigabytes).
name|S_GB_ZEROFILL
operator|=
literal|0x0CU
block|,
comment|/// S_INTERPOSING - Section with only pairs of function pointers for
comment|/// interposing.
name|S_INTERPOSING
operator|=
literal|0x0DU
block|,
comment|/// S_16BYTE_LITERALS - Section with only 16 byte literals.
name|S_16BYTE_LITERALS
operator|=
literal|0x0EU
block|,
comment|/// S_DTRACE_DOF - Section contains DTrace Object Format.
name|S_DTRACE_DOF
operator|=
literal|0x0FU
block|,
comment|/// S_LAZY_DYLIB_SYMBOL_POINTERS - Section with lazy symbol pointers to
comment|/// lazy loaded dylibs.
name|S_LAZY_DYLIB_SYMBOL_POINTERS
operator|=
literal|0x10U
block|,
name|LAST_KNOWN_SECTION_TYPE
operator|=
name|S_LAZY_DYLIB_SYMBOL_POINTERS
block|,
comment|// Valid section attributes.
comment|/// S_ATTR_PURE_INSTRUCTIONS - Section contains only true machine
comment|/// instructions.
name|S_ATTR_PURE_INSTRUCTIONS
operator|=
literal|1U
operator|<<
literal|31
block|,
comment|/// S_ATTR_NO_TOC - Section contains coalesced symbols that are not to be
comment|/// in a ranlib table of contents.
name|S_ATTR_NO_TOC
operator|=
literal|1U
operator|<<
literal|30
block|,
comment|/// S_ATTR_STRIP_STATIC_SYMS - Ok to strip static symbols in this section
comment|/// in files with the MY_DYLDLINK flag.
name|S_ATTR_STRIP_STATIC_SYMS
operator|=
literal|1U
operator|<<
literal|29
block|,
comment|/// S_ATTR_NO_DEAD_STRIP - No dead stripping.
name|S_ATTR_NO_DEAD_STRIP
operator|=
literal|1U
operator|<<
literal|28
block|,
comment|/// S_ATTR_LIVE_SUPPORT - Blocks are live if they reference live blocks.
name|S_ATTR_LIVE_SUPPORT
operator|=
literal|1U
operator|<<
literal|27
block|,
comment|/// S_ATTR_SELF_MODIFYING_CODE - Used with i386 code stubs written on by
comment|/// dyld.
name|S_ATTR_SELF_MODIFYING_CODE
operator|=
literal|1U
operator|<<
literal|26
block|,
comment|/// S_ATTR_DEBUG - A debug section.
name|S_ATTR_DEBUG
operator|=
literal|1U
operator|<<
literal|25
block|,
comment|/// S_ATTR_SOME_INSTRUCTIONS - Section contains some machine instructions.
name|S_ATTR_SOME_INSTRUCTIONS
operator|=
literal|1U
operator|<<
literal|10
block|,
comment|/// S_ATTR_EXT_RELOC - Section has external relocation entries.
name|S_ATTR_EXT_RELOC
operator|=
literal|1U
operator|<<
literal|9
block|,
comment|/// S_ATTR_LOC_RELOC - Section has local relocation entries.
name|S_ATTR_LOC_RELOC
operator|=
literal|1U
operator|<<
literal|8
block|}
block|;
name|StringRef
name|getSegmentName
argument_list|()
specifier|const
block|{
comment|// SegmentName is not necessarily null terminated!
if|if
condition|(
name|SegmentName
index|[
literal|15
index|]
condition|)
return|return
name|StringRef
argument_list|(
name|SegmentName
argument_list|,
literal|16
argument_list|)
return|;
return|return
name|StringRef
argument_list|(
name|SegmentName
argument_list|)
return|;
block|}
name|StringRef
name|getSectionName
argument_list|()
specifier|const
block|{
comment|// SectionName is not necessarily null terminated!
if|if
condition|(
name|SectionName
index|[
literal|15
index|]
condition|)
return|return
name|StringRef
argument_list|(
name|SectionName
argument_list|,
literal|16
argument_list|)
return|;
return|return
name|StringRef
argument_list|(
name|SectionName
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getTypeAndAttributes
argument_list|()
specifier|const
block|{
return|return
name|TypeAndAttributes
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getStubSize
argument_list|()
specifier|const
block|{
return|return
name|Reserved2
return|;
block|}
end_expr_stmt

begin_comment
comment|/// ParseSectionSpecifier - Parse the section specifier indicated by "Spec".
end_comment

begin_comment
comment|/// This is a string that can appear after a .section directive in a mach-o
end_comment

begin_comment
comment|/// flavored .s file.  If successful, this fills in the specified Out
end_comment

begin_comment
comment|/// parameters and returns an empty string.  When an invalid section
end_comment

begin_comment
comment|/// specifier is present, this returns a string indicating the problem.
end_comment

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|ParseSectionSpecifier
argument_list|(
argument|StringRef Spec
argument_list|,
comment|// In.
argument|StringRef&Segment
argument_list|,
comment|// Out.
argument|StringRef&Section
argument_list|,
comment|// Out.
argument|unsigned&TAA
argument_list|,
comment|// Out.
argument|unsigned&StubSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Out.
end_comment

begin_decl_stmt
name|virtual
name|void
name|PrintSwitchToSection
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

