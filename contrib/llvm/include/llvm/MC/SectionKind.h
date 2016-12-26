begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/SectionKind.h - Classification of sections ------*- C++ -*-===//
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
name|LLVM_MC_SECTIONKIND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_SECTIONKIND_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SectionKind - This is a simple POD value that classifies the properties of
comment|/// a section.  A section is classified into the deepest possible
comment|/// classification, and then the target maps them onto their sections based on
comment|/// what capabilities they have.
comment|///
comment|/// The comments below describe these as if they were an inheritance hierarchy
comment|/// in order to explain the predicates below.
comment|///
name|class
name|SectionKind
block|{
enum|enum
name|Kind
block|{
comment|/// Metadata - Debug info sections or other metadata.
name|Metadata
block|,
comment|/// Text - Text section, used for functions and other executable code.
name|Text
block|,
comment|/// ReadOnly - Data that is never written to at program runtime by the
comment|/// program or the dynamic linker.  Things in the top-level readonly
comment|/// SectionKind are not mergeable.
name|ReadOnly
block|,
comment|/// MergableCString - Any null-terminated string which allows merging.
comment|/// These values are known to end in a nul value of the specified size,
comment|/// not otherwise contain a nul value, and be mergable.  This allows the
comment|/// linker to unique the strings if it so desires.
comment|/// Mergeable1ByteCString - 1 byte mergable, null terminated, string.
name|Mergeable1ByteCString
block|,
comment|/// Mergeable2ByteCString - 2 byte mergable, null terminated, string.
name|Mergeable2ByteCString
block|,
comment|/// Mergeable4ByteCString - 4 byte mergable, null terminated, string.
name|Mergeable4ByteCString
block|,
comment|/// MergeableConst - These are sections for merging fixed-length
comment|/// constants together.  For example, this can be used to unique
comment|/// constant pool entries etc.
comment|/// MergeableConst4 - This is a section used by 4-byte constants,
comment|/// for example, floats.
name|MergeableConst4
block|,
comment|/// MergeableConst8 - This is a section used by 8-byte constants,
comment|/// for example, doubles.
name|MergeableConst8
block|,
comment|/// MergeableConst16 - This is a section used by 16-byte constants,
comment|/// for example, vectors.
name|MergeableConst16
block|,
comment|/// MergeableConst32 - This is a section used by 32-byte constants,
comment|/// for example, vectors.
name|MergeableConst32
block|,
comment|/// Writeable - This is the base of all segments that need to be written
comment|/// to during program runtime.
comment|/// ThreadLocal - This is the base of all TLS segments.  All TLS
comment|/// objects must be writeable, otherwise there is no reason for them to
comment|/// be thread local!
comment|/// ThreadBSS - Zero-initialized TLS data objects.
name|ThreadBSS
block|,
comment|/// ThreadData - Initialized TLS data objects.
name|ThreadData
block|,
comment|/// GlobalWriteableData - Writeable data that is global (not thread
comment|/// local).
comment|/// BSS - Zero initialized writeable data.
name|BSS
block|,
comment|/// BSSLocal - This is BSS (zero initialized and writable) data
comment|/// which has local linkage.
name|BSSLocal
block|,
comment|/// BSSExtern - This is BSS data with normal external linkage.
name|BSSExtern
block|,
comment|/// Common - Data with common linkage.  These represent tentative
comment|/// definitions, which always have a zero initializer and are never
comment|/// marked 'constant'.
name|Common
block|,
comment|/// This is writeable data that has a non-zero initializer.
name|Data
block|,
comment|/// ReadOnlyWithRel - These are global variables that are never
comment|/// written to by the program, but that have relocations, so they
comment|/// must be stuck in a writeable section so that the dynamic linker
comment|/// can write to them.  If it chooses to, the dynamic linker can
comment|/// mark the pages these globals end up on as read-only after it is
comment|/// done with its relocation phase.
name|ReadOnlyWithRel
block|}
name|K
range|:
literal|8
enum|;
name|public
label|:
name|bool
name|isMetadata
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|Metadata
return|;
block|}
name|bool
name|isText
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|Text
return|;
block|}
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|ReadOnly
operator|||
name|isMergeableCString
argument_list|()
operator|||
name|isMergeableConst
argument_list|()
return|;
block|}
name|bool
name|isMergeableCString
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|Mergeable1ByteCString
operator|||
name|K
operator|==
name|Mergeable2ByteCString
operator|||
name|K
operator|==
name|Mergeable4ByteCString
return|;
block|}
name|bool
name|isMergeable1ByteCString
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|Mergeable1ByteCString
return|;
block|}
name|bool
name|isMergeable2ByteCString
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|Mergeable2ByteCString
return|;
block|}
name|bool
name|isMergeable4ByteCString
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|Mergeable4ByteCString
return|;
block|}
name|bool
name|isMergeableConst
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|MergeableConst4
operator|||
name|K
operator|==
name|MergeableConst8
operator|||
name|K
operator|==
name|MergeableConst16
operator|||
name|K
operator|==
name|MergeableConst32
return|;
block|}
name|bool
name|isMergeableConst4
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|MergeableConst4
return|;
block|}
name|bool
name|isMergeableConst8
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|MergeableConst8
return|;
block|}
name|bool
name|isMergeableConst16
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|MergeableConst16
return|;
block|}
name|bool
name|isMergeableConst32
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|MergeableConst32
return|;
block|}
name|bool
name|isWriteable
argument_list|()
specifier|const
block|{
return|return
name|isThreadLocal
argument_list|()
operator|||
name|isGlobalWriteableData
argument_list|()
return|;
block|}
name|bool
name|isThreadLocal
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|ThreadData
operator|||
name|K
operator|==
name|ThreadBSS
return|;
block|}
name|bool
name|isThreadBSS
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|ThreadBSS
return|;
block|}
name|bool
name|isThreadData
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|ThreadData
return|;
block|}
name|bool
name|isGlobalWriteableData
argument_list|()
specifier|const
block|{
return|return
name|isBSS
argument_list|()
operator|||
name|isCommon
argument_list|()
operator|||
name|isData
argument_list|()
operator|||
name|isReadOnlyWithRel
argument_list|()
return|;
block|}
name|bool
name|isBSS
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|BSS
operator|||
name|K
operator|==
name|BSSLocal
operator|||
name|K
operator|==
name|BSSExtern
return|;
block|}
name|bool
name|isBSSLocal
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|BSSLocal
return|;
block|}
name|bool
name|isBSSExtern
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|BSSExtern
return|;
block|}
name|bool
name|isCommon
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|Common
return|;
block|}
name|bool
name|isData
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|Data
return|;
block|}
name|bool
name|isReadOnlyWithRel
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|ReadOnlyWithRel
return|;
block|}
name|private
label|:
specifier|static
name|SectionKind
name|get
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
name|SectionKind
name|Res
decl_stmt|;
name|Res
operator|.
name|K
operator|=
name|K
expr_stmt|;
return|return
name|Res
return|;
block|}
name|public
label|:
specifier|static
name|SectionKind
name|getMetadata
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|Metadata
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getText
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|Text
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getReadOnly
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|ReadOnly
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getMergeable1ByteCString
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|Mergeable1ByteCString
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getMergeable2ByteCString
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|Mergeable2ByteCString
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getMergeable4ByteCString
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|Mergeable4ByteCString
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getMergeableConst4
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|MergeableConst4
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getMergeableConst8
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|MergeableConst8
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getMergeableConst16
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|MergeableConst16
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getMergeableConst32
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|MergeableConst32
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getThreadBSS
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|ThreadBSS
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getThreadData
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|ThreadData
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getBSS
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|BSS
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getBSSLocal
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|BSSLocal
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getBSSExtern
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|BSSExtern
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getCommon
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|Common
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getData
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|Data
argument_list|)
return|;
block|}
specifier|static
name|SectionKind
name|getReadOnlyWithRel
parameter_list|()
block|{
return|return
name|get
argument_list|(
name|ReadOnlyWithRel
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

