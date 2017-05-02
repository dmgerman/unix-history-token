begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Type.h - C Language Family Type Representation ---------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief C Language Family Type Representation
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file defines the clang::Type interface and subclasses, used to
end_comment

begin_comment
comment|/// represent types for languages in the C family.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_AST_TYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_TYPE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/NestedNameSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateName.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/AddressSpaces.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ExceptionSpecificationType.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Linkage.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/PartialDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Visibility.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
enum|enum
block|{
name|TypeAlignmentInBits
init|=
literal|4
block|,
name|TypeAlignment
init|=
literal|1
operator|<<
name|TypeAlignmentInBits
block|}
enum|;
name|class
name|Type
decl_stmt|;
name|class
name|ExtQuals
decl_stmt|;
name|class
name|QualType
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|PointerLikeTypeTraits
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
operator|::
name|clang
operator|::
name|Type
operator|*
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|::clang::Type *P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
operator|::
name|clang
operator|::
name|Type
operator|*
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
operator|::
name|clang
operator|::
name|Type
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
name|clang
operator|::
name|TypeAlignmentInBits
block|}
block|;   }
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
operator|::
name|clang
operator|::
name|ExtQuals
operator|*
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|::clang::ExtQuals *P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
operator|::
name|clang
operator|::
name|ExtQuals
operator|*
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
operator|::
name|clang
operator|::
name|ExtQuals
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
name|clang
operator|::
name|TypeAlignmentInBits
block|}
block|;   }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|QualType
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|TypedefNameDecl
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|TemplateTypeParmDecl
decl_stmt|;
name|class
name|NonTypeTemplateParmDecl
decl_stmt|;
name|class
name|TemplateTemplateParmDecl
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|EnumDecl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCTypeParamDecl
decl_stmt|;
name|class
name|UnresolvedUsingTypenameDecl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|StmtIteratorBase
decl_stmt|;
name|class
name|TemplateArgument
decl_stmt|;
name|class
name|TemplateArgumentLoc
decl_stmt|;
name|class
name|TemplateArgumentListInfo
decl_stmt|;
name|class
name|ElaboratedType
decl_stmt|;
name|class
name|ExtQuals
decl_stmt|;
name|class
name|ExtQualsTypeCommonBase
decl_stmt|;
struct_decl|struct
name|PrintingPolicy
struct_decl|;
name|template
operator|<
name|typename
operator|>
name|class
name|CanQual
expr_stmt|;
typedef|typedef
name|CanQual
operator|<
name|Type
operator|>
name|CanQualType
expr_stmt|;
comment|// Provide forward declarations for all of the *Type classes
define|#
directive|define
name|TYPE
parameter_list|(
name|Class
parameter_list|,
name|Base
parameter_list|)
value|class Class##Type;
include|#
directive|include
file|"clang/AST/TypeNodes.def"
comment|/// The collection of all-type qualifiers we support.
comment|/// Clang supports five independent qualifiers:
comment|/// * C99: const, volatile, and restrict
comment|/// * MS: __unaligned
comment|/// * Embedded C (TR18037): address spaces
comment|/// * Objective C: the GC attributes (none, weak, or strong)
name|class
name|Qualifiers
block|{
name|public
label|:
enum|enum
name|TQ
block|{
comment|// NOTE: These flags must be kept in sync with DeclSpec::TQ.
name|Const
init|=
literal|0x1
block|,
name|Restrict
init|=
literal|0x2
block|,
name|Volatile
init|=
literal|0x4
block|,
name|CVRMask
init|=
name|Const
operator||
name|Volatile
operator||
name|Restrict
block|}
enum|;
enum|enum
name|GC
block|{
name|GCNone
init|=
literal|0
block|,
name|Weak
block|,
name|Strong
block|}
enum|;
enum|enum
name|ObjCLifetime
block|{
comment|/// There is no lifetime qualification on this type.
name|OCL_None
block|,
comment|/// This object can be modified without requiring retains or
comment|/// releases.
name|OCL_ExplicitNone
block|,
comment|/// Assigning into this object requires the old value to be
comment|/// released and the new value to be retained.  The timing of the
comment|/// release of the old value is inexact: it may be moved to
comment|/// immediately after the last known point where the value is
comment|/// live.
name|OCL_Strong
block|,
comment|/// Reading or writing from this object requires a barrier call.
name|OCL_Weak
block|,
comment|/// Assigning into this object requires a lifetime extension.
name|OCL_Autoreleasing
block|}
enum|;
enum|enum
block|{
comment|/// The maximum supported address space number.
comment|/// 23 bits should be enough for anyone.
name|MaxAddressSpace
init|=
literal|0x7fffffu
block|,
comment|/// The width of the "fast" qualifier mask.
name|FastWidth
init|=
literal|3
block|,
comment|/// The fast qualifier mask.
name|FastMask
init|=
operator|(
literal|1
operator|<<
name|FastWidth
operator|)
operator|-
literal|1
block|}
enum|;
name|Qualifiers
argument_list|()
operator|:
name|Mask
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Returns the common set of qualifiers while removing them from
comment|/// the given sets.
specifier|static
name|Qualifiers
name|removeCommonQualifiers
argument_list|(
argument|Qualifiers&L
argument_list|,
argument|Qualifiers&R
argument_list|)
block|{
comment|// If both are only CVR-qualified, bit operations are sufficient.
if|if
condition|(
operator|!
operator|(
name|L
operator|.
name|Mask
operator|&
operator|~
name|CVRMask
operator|)
operator|&&
operator|!
operator|(
name|R
operator|.
name|Mask
operator|&
operator|~
name|CVRMask
operator|)
condition|)
block|{
name|Qualifiers
name|Q
decl_stmt|;
name|Q
operator|.
name|Mask
operator|=
name|L
operator|.
name|Mask
operator|&
name|R
operator|.
name|Mask
expr_stmt|;
name|L
operator|.
name|Mask
operator|&=
operator|~
name|Q
operator|.
name|Mask
expr_stmt|;
name|R
operator|.
name|Mask
operator|&=
operator|~
name|Q
operator|.
name|Mask
expr_stmt|;
return|return
name|Q
return|;
block|}
name|Qualifiers
name|Q
decl_stmt|;
name|unsigned
name|CommonCRV
operator|=
name|L
operator|.
name|getCVRQualifiers
argument_list|()
operator|&
name|R
operator|.
name|getCVRQualifiers
argument_list|()
expr_stmt|;
name|Q
operator|.
name|addCVRQualifiers
argument_list|(
name|CommonCRV
argument_list|)
expr_stmt|;
name|L
operator|.
name|removeCVRQualifiers
argument_list|(
name|CommonCRV
argument_list|)
expr_stmt|;
name|R
operator|.
name|removeCVRQualifiers
argument_list|(
name|CommonCRV
argument_list|)
expr_stmt|;
if|if
condition|(
name|L
operator|.
name|getObjCGCAttr
argument_list|()
operator|==
name|R
operator|.
name|getObjCGCAttr
argument_list|()
condition|)
block|{
name|Q
operator|.
name|setObjCGCAttr
argument_list|(
name|L
operator|.
name|getObjCGCAttr
argument_list|()
argument_list|)
expr_stmt|;
name|L
operator|.
name|removeObjCGCAttr
argument_list|()
expr_stmt|;
name|R
operator|.
name|removeObjCGCAttr
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|L
operator|.
name|getObjCLifetime
argument_list|()
operator|==
name|R
operator|.
name|getObjCLifetime
argument_list|()
condition|)
block|{
name|Q
operator|.
name|setObjCLifetime
argument_list|(
name|L
operator|.
name|getObjCLifetime
argument_list|()
argument_list|)
expr_stmt|;
name|L
operator|.
name|removeObjCLifetime
argument_list|()
expr_stmt|;
name|R
operator|.
name|removeObjCLifetime
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|L
operator|.
name|getAddressSpace
argument_list|()
operator|==
name|R
operator|.
name|getAddressSpace
argument_list|()
condition|)
block|{
name|Q
operator|.
name|setAddressSpace
argument_list|(
name|L
operator|.
name|getAddressSpace
argument_list|()
argument_list|)
expr_stmt|;
name|L
operator|.
name|removeAddressSpace
argument_list|()
expr_stmt|;
name|R
operator|.
name|removeAddressSpace
argument_list|()
expr_stmt|;
block|}
return|return
name|Q
return|;
block|}
specifier|static
name|Qualifiers
name|fromFastMask
parameter_list|(
name|unsigned
name|Mask
parameter_list|)
block|{
name|Qualifiers
name|Qs
decl_stmt|;
name|Qs
operator|.
name|addFastQualifiers
argument_list|(
name|Mask
argument_list|)
expr_stmt|;
return|return
name|Qs
return|;
block|}
specifier|static
name|Qualifiers
name|fromCVRMask
parameter_list|(
name|unsigned
name|CVR
parameter_list|)
block|{
name|Qualifiers
name|Qs
decl_stmt|;
name|Qs
operator|.
name|addCVRQualifiers
argument_list|(
name|CVR
argument_list|)
expr_stmt|;
return|return
name|Qs
return|;
block|}
specifier|static
name|Qualifiers
name|fromCVRUMask
parameter_list|(
name|unsigned
name|CVRU
parameter_list|)
block|{
name|Qualifiers
name|Qs
decl_stmt|;
name|Qs
operator|.
name|addCVRUQualifiers
argument_list|(
name|CVRU
argument_list|)
expr_stmt|;
return|return
name|Qs
return|;
block|}
comment|// Deserialize qualifiers from an opaque representation.
specifier|static
name|Qualifiers
name|fromOpaqueValue
parameter_list|(
name|unsigned
name|opaque
parameter_list|)
block|{
name|Qualifiers
name|Qs
decl_stmt|;
name|Qs
operator|.
name|Mask
operator|=
name|opaque
expr_stmt|;
return|return
name|Qs
return|;
block|}
comment|// Serialize these qualifiers into an opaque representation.
name|unsigned
name|getAsOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|Mask
return|;
block|}
name|bool
name|hasConst
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|Const
return|;
block|}
name|void
name|setConst
parameter_list|(
name|bool
name|flag
parameter_list|)
block|{
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|Const
operator|)
operator||
operator|(
name|flag
condition|?
name|Const
else|:
literal|0
operator|)
expr_stmt|;
block|}
name|void
name|removeConst
parameter_list|()
block|{
name|Mask
operator|&=
operator|~
name|Const
expr_stmt|;
block|}
name|void
name|addConst
parameter_list|()
block|{
name|Mask
operator||=
name|Const
expr_stmt|;
block|}
name|bool
name|hasVolatile
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|Volatile
return|;
block|}
name|void
name|setVolatile
parameter_list|(
name|bool
name|flag
parameter_list|)
block|{
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|Volatile
operator|)
operator||
operator|(
name|flag
condition|?
name|Volatile
else|:
literal|0
operator|)
expr_stmt|;
block|}
name|void
name|removeVolatile
parameter_list|()
block|{
name|Mask
operator|&=
operator|~
name|Volatile
expr_stmt|;
block|}
name|void
name|addVolatile
parameter_list|()
block|{
name|Mask
operator||=
name|Volatile
expr_stmt|;
block|}
name|bool
name|hasRestrict
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|Restrict
return|;
block|}
name|void
name|setRestrict
parameter_list|(
name|bool
name|flag
parameter_list|)
block|{
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|Restrict
operator|)
operator||
operator|(
name|flag
condition|?
name|Restrict
else|:
literal|0
operator|)
expr_stmt|;
block|}
name|void
name|removeRestrict
parameter_list|()
block|{
name|Mask
operator|&=
operator|~
name|Restrict
expr_stmt|;
block|}
name|void
name|addRestrict
parameter_list|()
block|{
name|Mask
operator||=
name|Restrict
expr_stmt|;
block|}
name|bool
name|hasCVRQualifiers
argument_list|()
specifier|const
block|{
return|return
name|getCVRQualifiers
argument_list|()
return|;
block|}
name|unsigned
name|getCVRQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|CVRMask
return|;
block|}
name|void
name|setCVRQualifiers
parameter_list|(
name|unsigned
name|mask
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|mask
operator|&
operator|~
name|CVRMask
operator|)
operator|&&
literal|"bitmask contains non-CVR bits"
argument_list|)
expr_stmt|;
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|CVRMask
operator|)
operator||
name|mask
expr_stmt|;
block|}
name|void
name|removeCVRQualifiers
parameter_list|(
name|unsigned
name|mask
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|mask
operator|&
operator|~
name|CVRMask
operator|)
operator|&&
literal|"bitmask contains non-CVR bits"
argument_list|)
expr_stmt|;
name|Mask
operator|&=
operator|~
name|mask
expr_stmt|;
block|}
name|void
name|removeCVRQualifiers
parameter_list|()
block|{
name|removeCVRQualifiers
argument_list|(
name|CVRMask
argument_list|)
expr_stmt|;
block|}
name|void
name|addCVRQualifiers
parameter_list|(
name|unsigned
name|mask
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|mask
operator|&
operator|~
name|CVRMask
operator|)
operator|&&
literal|"bitmask contains non-CVR bits"
argument_list|)
expr_stmt|;
name|Mask
operator||=
name|mask
expr_stmt|;
block|}
name|void
name|addCVRUQualifiers
parameter_list|(
name|unsigned
name|mask
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|mask
operator|&
operator|~
name|CVRMask
operator|&
operator|~
name|UMask
operator|)
operator|&&
literal|"bitmask contains non-CVRU bits"
argument_list|)
expr_stmt|;
name|Mask
operator||=
name|mask
expr_stmt|;
block|}
name|bool
name|hasUnaligned
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|UMask
return|;
block|}
name|void
name|setUnaligned
parameter_list|(
name|bool
name|flag
parameter_list|)
block|{
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|UMask
operator|)
operator||
operator|(
name|flag
condition|?
name|UMask
else|:
literal|0
operator|)
expr_stmt|;
block|}
name|void
name|removeUnaligned
parameter_list|()
block|{
name|Mask
operator|&=
operator|~
name|UMask
expr_stmt|;
block|}
name|void
name|addUnaligned
parameter_list|()
block|{
name|Mask
operator||=
name|UMask
expr_stmt|;
block|}
name|bool
name|hasObjCGCAttr
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|GCAttrMask
return|;
block|}
name|GC
name|getObjCGCAttr
argument_list|()
specifier|const
block|{
return|return
name|GC
argument_list|(
operator|(
name|Mask
operator|&
name|GCAttrMask
operator|)
operator|>>
name|GCAttrShift
argument_list|)
return|;
block|}
name|void
name|setObjCGCAttr
parameter_list|(
name|GC
name|type
parameter_list|)
block|{
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|GCAttrMask
operator|)
operator||
operator|(
name|type
operator|<<
name|GCAttrShift
operator|)
expr_stmt|;
block|}
name|void
name|removeObjCGCAttr
parameter_list|()
block|{
name|setObjCGCAttr
argument_list|(
name|GCNone
argument_list|)
expr_stmt|;
block|}
name|void
name|addObjCGCAttr
parameter_list|(
name|GC
name|type
parameter_list|)
block|{
name|assert
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|setObjCGCAttr
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
name|Qualifiers
name|withoutObjCGCAttr
argument_list|()
specifier|const
block|{
name|Qualifiers
name|qs
operator|=
operator|*
name|this
block|;
name|qs
operator|.
name|removeObjCGCAttr
argument_list|()
block|;
return|return
name|qs
return|;
block|}
name|Qualifiers
name|withoutObjCLifetime
argument_list|()
specifier|const
block|{
name|Qualifiers
name|qs
operator|=
operator|*
name|this
block|;
name|qs
operator|.
name|removeObjCLifetime
argument_list|()
block|;
return|return
name|qs
return|;
block|}
name|bool
name|hasObjCLifetime
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|LifetimeMask
return|;
block|}
name|ObjCLifetime
name|getObjCLifetime
argument_list|()
specifier|const
block|{
return|return
name|ObjCLifetime
argument_list|(
operator|(
name|Mask
operator|&
name|LifetimeMask
operator|)
operator|>>
name|LifetimeShift
argument_list|)
return|;
block|}
name|void
name|setObjCLifetime
parameter_list|(
name|ObjCLifetime
name|type
parameter_list|)
block|{
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|LifetimeMask
operator|)
operator||
operator|(
name|type
operator|<<
name|LifetimeShift
operator|)
expr_stmt|;
block|}
name|void
name|removeObjCLifetime
parameter_list|()
block|{
name|setObjCLifetime
argument_list|(
name|OCL_None
argument_list|)
expr_stmt|;
block|}
name|void
name|addObjCLifetime
parameter_list|(
name|ObjCLifetime
name|type
parameter_list|)
block|{
name|assert
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|hasObjCLifetime
argument_list|()
argument_list|)
expr_stmt|;
name|Mask
operator||=
operator|(
name|type
operator|<<
name|LifetimeShift
operator|)
expr_stmt|;
block|}
comment|/// True if the lifetime is neither None or ExplicitNone.
name|bool
name|hasNonTrivialObjCLifetime
argument_list|()
specifier|const
block|{
name|ObjCLifetime
name|lifetime
operator|=
name|getObjCLifetime
argument_list|()
block|;
return|return
operator|(
name|lifetime
operator|>
name|OCL_ExplicitNone
operator|)
return|;
block|}
comment|/// True if the lifetime is either strong or weak.
name|bool
name|hasStrongOrWeakObjCLifetime
argument_list|()
specifier|const
block|{
name|ObjCLifetime
name|lifetime
operator|=
name|getObjCLifetime
argument_list|()
block|;
return|return
operator|(
name|lifetime
operator|==
name|OCL_Strong
operator|||
name|lifetime
operator|==
name|OCL_Weak
operator|)
return|;
block|}
name|bool
name|hasAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|AddressSpaceMask
return|;
block|}
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|>>
name|AddressSpaceShift
return|;
block|}
comment|/// Get the address space attribute value to be printed by diagnostics.
name|unsigned
name|getAddressSpaceAttributePrintValue
argument_list|()
specifier|const
block|{
name|auto
name|Addr
operator|=
name|getAddressSpace
argument_list|()
block|;
comment|// This function is not supposed to be used with language specific
comment|// address spaces. If that happens, the diagnostic message should consider
comment|// printing the QualType instead of the address space value.
name|assert
argument_list|(
name|Addr
operator|==
literal|0
operator|||
name|Addr
operator|>=
name|LangAS
operator|::
name|Count
argument_list|)
block|;
if|if
condition|(
name|Addr
condition|)
return|return
name|Addr
operator|-
name|LangAS
operator|::
name|Count
return|;
comment|// TODO: The diagnostic messages where Addr may be 0 should be fixed
comment|// since it cannot differentiate the situation where 0 denotes the default
comment|// address space or user specified __attribute__((address_space(0))).
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setAddressSpace
parameter_list|(
name|unsigned
name|space
parameter_list|)
block|{
name|assert
argument_list|(
name|space
operator|<=
name|MaxAddressSpace
argument_list|)
expr_stmt|;
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|AddressSpaceMask
operator|)
operator||
operator|(
operator|(
operator|(
name|uint32_t
operator|)
name|space
operator|)
operator|<<
name|AddressSpaceShift
operator|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|removeAddressSpace
parameter_list|()
block|{
name|setAddressSpace
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|addAddressSpace
parameter_list|(
name|unsigned
name|space
parameter_list|)
block|{
name|assert
argument_list|(
name|space
argument_list|)
expr_stmt|;
name|setAddressSpace
argument_list|(
name|space
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Fast qualifiers are those that can be allocated directly
end_comment

begin_comment
comment|// on a QualType object.
end_comment

begin_expr_stmt
name|bool
name|hasFastQualifiers
argument_list|()
specifier|const
block|{
return|return
name|getFastQualifiers
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getFastQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
name|FastMask
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setFastQualifiers
parameter_list|(
name|unsigned
name|mask
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|mask
operator|&
operator|~
name|FastMask
operator|)
operator|&&
literal|"bitmask contains non-fast qualifier bits"
argument_list|)
expr_stmt|;
name|Mask
operator|=
operator|(
name|Mask
operator|&
operator|~
name|FastMask
operator|)
operator||
name|mask
expr_stmt|;
block|}
end_function

begin_function
name|void
name|removeFastQualifiers
parameter_list|(
name|unsigned
name|mask
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|mask
operator|&
operator|~
name|FastMask
operator|)
operator|&&
literal|"bitmask contains non-fast qualifier bits"
argument_list|)
expr_stmt|;
name|Mask
operator|&=
operator|~
name|mask
expr_stmt|;
block|}
end_function

begin_function
name|void
name|removeFastQualifiers
parameter_list|()
block|{
name|removeFastQualifiers
argument_list|(
name|FastMask
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|addFastQualifiers
parameter_list|(
name|unsigned
name|mask
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|mask
operator|&
operator|~
name|FastMask
operator|)
operator|&&
literal|"bitmask contains non-fast qualifier bits"
argument_list|)
expr_stmt|;
name|Mask
operator||=
name|mask
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Return true if the set contains any qualifiers which require an ExtQuals
end_comment

begin_comment
comment|/// node to be allocated.
end_comment

begin_expr_stmt
name|bool
name|hasNonFastQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|&
operator|~
name|FastMask
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Qualifiers
name|getNonFastQualifiers
argument_list|()
specifier|const
block|{
name|Qualifiers
name|Quals
operator|=
operator|*
name|this
block|;
name|Quals
operator|.
name|setFastQualifiers
argument_list|(
literal|0
argument_list|)
block|;
return|return
name|Quals
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return true if the set contains any qualifiers.
end_comment

begin_expr_stmt
name|bool
name|hasQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Mask
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Mask
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Add the qualifiers from the given set to this set.
end_comment

begin_function
name|void
name|addQualifiers
parameter_list|(
name|Qualifiers
name|Q
parameter_list|)
block|{
comment|// If the other set doesn't have any non-boolean qualifiers, just
comment|// bit-or it in.
if|if
condition|(
operator|!
operator|(
name|Q
operator|.
name|Mask
operator|&
operator|~
name|CVRMask
operator|)
condition|)
name|Mask
operator||=
name|Q
operator|.
name|Mask
expr_stmt|;
else|else
block|{
name|Mask
operator||=
operator|(
name|Q
operator|.
name|Mask
operator|&
name|CVRMask
operator|)
expr_stmt|;
if|if
condition|(
name|Q
operator|.
name|hasAddressSpace
argument_list|()
condition|)
name|addAddressSpace
argument_list|(
name|Q
operator|.
name|getAddressSpace
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q
operator|.
name|hasObjCGCAttr
argument_list|()
condition|)
name|addObjCGCAttr
argument_list|(
name|Q
operator|.
name|getObjCGCAttr
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q
operator|.
name|hasObjCLifetime
argument_list|()
condition|)
name|addObjCLifetime
argument_list|(
name|Q
operator|.
name|getObjCLifetime
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// \brief Remove the qualifiers from the given set from this set.
end_comment

begin_function
name|void
name|removeQualifiers
parameter_list|(
name|Qualifiers
name|Q
parameter_list|)
block|{
comment|// If the other set doesn't have any non-boolean qualifiers, just
comment|// bit-and the inverse in.
if|if
condition|(
operator|!
operator|(
name|Q
operator|.
name|Mask
operator|&
operator|~
name|CVRMask
operator|)
condition|)
name|Mask
operator|&=
operator|~
name|Q
operator|.
name|Mask
expr_stmt|;
else|else
block|{
name|Mask
operator|&=
operator|~
operator|(
name|Q
operator|.
name|Mask
operator|&
name|CVRMask
operator|)
expr_stmt|;
if|if
condition|(
name|getObjCGCAttr
argument_list|()
operator|==
name|Q
operator|.
name|getObjCGCAttr
argument_list|()
condition|)
name|removeObjCGCAttr
argument_list|()
expr_stmt|;
if|if
condition|(
name|getObjCLifetime
argument_list|()
operator|==
name|Q
operator|.
name|getObjCLifetime
argument_list|()
condition|)
name|removeObjCLifetime
argument_list|()
expr_stmt|;
if|if
condition|(
name|getAddressSpace
argument_list|()
operator|==
name|Q
operator|.
name|getAddressSpace
argument_list|()
condition|)
name|removeAddressSpace
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// Add the qualifiers from the given set to this set, given that
end_comment

begin_comment
comment|/// they don't conflict.
end_comment

begin_function
name|void
name|addConsistentQualifiers
parameter_list|(
name|Qualifiers
name|qs
parameter_list|)
block|{
name|assert
argument_list|(
name|getAddressSpace
argument_list|()
operator|==
name|qs
operator|.
name|getAddressSpace
argument_list|()
operator|||
operator|!
name|hasAddressSpace
argument_list|()
operator|||
operator|!
name|qs
operator|.
name|hasAddressSpace
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|getObjCGCAttr
argument_list|()
operator|==
name|qs
operator|.
name|getObjCGCAttr
argument_list|()
operator|||
operator|!
name|hasObjCGCAttr
argument_list|()
operator|||
operator|!
name|qs
operator|.
name|hasObjCGCAttr
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|getObjCLifetime
argument_list|()
operator|==
name|qs
operator|.
name|getObjCLifetime
argument_list|()
operator|||
operator|!
name|hasObjCLifetime
argument_list|()
operator|||
operator|!
name|qs
operator|.
name|hasObjCLifetime
argument_list|()
argument_list|)
expr_stmt|;
name|Mask
operator||=
name|qs
operator|.
name|Mask
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Returns true if this address space is a superset of the other one.
end_comment

begin_comment
comment|/// OpenCL v2.0 defines conversion rules (OpenCLC v2.0 s6.5.5) and notion of
end_comment

begin_comment
comment|/// overlapping address spaces.
end_comment

begin_comment
comment|/// CL1.1 or CL1.2:
end_comment

begin_comment
comment|///   every address space is a superset of itself.
end_comment

begin_comment
comment|/// CL2.0 adds:
end_comment

begin_comment
comment|///   __generic is a superset of any address space except for __constant.
end_comment

begin_decl_stmt
name|bool
name|isAddressSpaceSupersetOf
argument_list|(
name|Qualifiers
name|other
argument_list|)
decl|const
block|{
return|return
comment|// Address spaces must match exactly.
name|getAddressSpace
argument_list|()
operator|==
name|other
operator|.
name|getAddressSpace
argument_list|()
operator|||
comment|// Otherwise in OpenCLC v2.0 s6.5.5: every address space except
comment|// for __constant can be used as __generic.
operator|(
name|getAddressSpace
argument_list|()
operator|==
name|LangAS
operator|::
name|opencl_generic
operator|&&
name|other
operator|.
name|getAddressSpace
argument_list|()
operator|!=
name|LangAS
operator|::
name|opencl_constant
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determines if these qualifiers compatibly include another set.
end_comment

begin_comment
comment|/// Generally this answers the question of whether an object with the other
end_comment

begin_comment
comment|/// qualifiers can be safely used as an object with these qualifiers.
end_comment

begin_decl_stmt
name|bool
name|compatiblyIncludes
argument_list|(
name|Qualifiers
name|other
argument_list|)
decl|const
block|{
return|return
name|isAddressSpaceSupersetOf
argument_list|(
name|other
argument_list|)
operator|&&
comment|// ObjC GC qualifiers can match, be added, or be removed, but can't
comment|// be changed.
operator|(
name|getObjCGCAttr
argument_list|()
operator|==
name|other
operator|.
name|getObjCGCAttr
argument_list|()
operator|||
operator|!
name|hasObjCGCAttr
argument_list|()
operator|||
operator|!
name|other
operator|.
name|hasObjCGCAttr
argument_list|()
operator|)
operator|&&
comment|// ObjC lifetime qualifiers must match exactly.
name|getObjCLifetime
argument_list|()
operator|==
name|other
operator|.
name|getObjCLifetime
argument_list|()
operator|&&
comment|// CVR qualifiers may subset.
operator|(
operator|(
operator|(
name|Mask
operator|&
name|CVRMask
operator|)
operator||
operator|(
name|other
operator|.
name|Mask
operator|&
name|CVRMask
operator|)
operator|)
operator|==
operator|(
name|Mask
operator|&
name|CVRMask
operator|)
operator|)
operator|&&
comment|// U qualifier may superset.
operator|(
operator|!
name|other
operator|.
name|hasUnaligned
argument_list|()
operator|||
name|hasUnaligned
argument_list|()
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determines if these qualifiers compatibly include another set of
end_comment

begin_comment
comment|/// qualifiers from the narrow perspective of Objective-C ARC lifetime.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// One set of Objective-C lifetime qualifiers compatibly includes the other
end_comment

begin_comment
comment|/// if the lifetime qualifiers match, or if both are non-__weak and the
end_comment

begin_comment
comment|/// including set also contains the 'const' qualifier, or both are non-__weak
end_comment

begin_comment
comment|/// and one is None (which can only happen in non-ARC modes).
end_comment

begin_decl_stmt
name|bool
name|compatiblyIncludesObjCLifetime
argument_list|(
name|Qualifiers
name|other
argument_list|)
decl|const
block|{
if|if
condition|(
name|getObjCLifetime
argument_list|()
operator|==
name|other
operator|.
name|getObjCLifetime
argument_list|()
condition|)
return|return
name|true
return|;
if|if
condition|(
name|getObjCLifetime
argument_list|()
operator|==
name|OCL_Weak
operator|||
name|other
operator|.
name|getObjCLifetime
argument_list|()
operator|==
name|OCL_Weak
condition|)
return|return
name|false
return|;
if|if
condition|(
name|getObjCLifetime
argument_list|()
operator|==
name|OCL_None
operator|||
name|other
operator|.
name|getObjCLifetime
argument_list|()
operator|==
name|OCL_None
condition|)
return|return
name|true
return|;
return|return
name|hasConst
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this set of qualifiers is a strict superset of
end_comment

begin_comment
comment|/// another set of qualifiers, not considering qualifier compatibility.
end_comment

begin_decl_stmt
name|bool
name|isStrictSupersetOf
argument_list|(
name|Qualifiers
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
name|Qualifiers
name|Other
operator|)
specifier|const
block|{
return|return
name|Mask
operator|==
name|Other
operator|.
name|Mask
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
name|Qualifiers
name|Other
operator|)
specifier|const
block|{
return|return
name|Mask
operator|!=
name|Other
operator|.
name|Mask
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|hasQualifiers
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Qualifiers
operator|&
name|operator
operator|+=
operator|(
name|Qualifiers
name|R
operator|)
block|{
name|addQualifiers
argument_list|(
name|R
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|// Union two qualifier sets.  If an enumerated qualifier appears
end_comment

begin_comment
comment|// in both sets, use the one from the right.
end_comment

begin_expr_stmt
name|friend
name|Qualifiers
name|operator
operator|+
operator|(
name|Qualifiers
name|L
operator|,
name|Qualifiers
name|R
operator|)
block|{
name|L
operator|+=
name|R
block|;
return|return
name|L
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Qualifiers
operator|&
name|operator
operator|-=
operator|(
name|Qualifiers
name|R
operator|)
block|{
name|removeQualifiers
argument_list|(
name|R
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Compute the difference between two qualifier sets.
end_comment

begin_expr_stmt
name|friend
name|Qualifiers
name|operator
operator|-
operator|(
name|Qualifiers
name|L
operator|,
name|Qualifiers
name|R
operator|)
block|{
name|L
operator|-=
name|R
block|;
return|return
name|L
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|isEmptyWhenPrinted
argument_list|(
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
name|bool
name|appendSpaceIfNonEmpty
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|Mask
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// bits:     |0 1 2|3|4 .. 5|6  ..  8|9   ...   31|
end_comment

begin_comment
comment|//           |C R V|U|GCAttr|Lifetime|AddressSpace|
end_comment

begin_decl_stmt
name|uint32_t
name|Mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|UMask
init|=
literal|0x8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|UShift
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|GCAttrMask
init|=
literal|0x30
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|GCAttrShift
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|LifetimeMask
init|=
literal|0x1C0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|LifetimeShift
init|=
literal|6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|AddressSpaceMask
init|=
operator|~
operator|(
name|CVRMask
operator||
name|UMask
operator||
name|GCAttrMask
operator||
name|LifetimeMask
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|AddressSpaceShift
init|=
literal|9
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// A std::pair-like structure for storing a qualified type split
end_comment

begin_comment
comment|/// into its local qualifiers and its locally-unqualified type.
end_comment

begin_struct
struct|struct
name|SplitQualType
block|{
comment|/// The locally-unqualified type.
specifier|const
name|Type
modifier|*
name|Ty
decl_stmt|;
comment|/// The local qualifiers.
name|Qualifiers
name|Quals
decl_stmt|;
name|SplitQualType
argument_list|()
operator|:
name|Ty
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Quals
argument_list|()
block|{}
name|SplitQualType
argument_list|(
argument|const Type *ty
argument_list|,
argument|Qualifiers qs
argument_list|)
operator|:
name|Ty
argument_list|(
name|ty
argument_list|)
operator|,
name|Quals
argument_list|(
argument|qs
argument_list|)
block|{}
name|SplitQualType
name|getSingleStepDesugaredType
argument_list|()
specifier|const
expr_stmt|;
comment|// end of this file
comment|// Make std::tie work.
name|std
operator|::
name|pair
operator|<
specifier|const
name|Type
operator|*
operator|,
name|Qualifiers
operator|>
name|asPair
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|pair
operator|<
specifier|const
name|Type
operator|*
operator|,
name|Qualifiers
operator|>
operator|(
name|Ty
operator|,
name|Quals
operator|)
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|SplitQualType
name|a
operator|,
name|SplitQualType
name|b
operator|)
block|{
return|return
name|a
operator|.
name|Ty
operator|==
name|b
operator|.
name|Ty
operator|&&
name|a
operator|.
name|Quals
operator|==
name|b
operator|.
name|Quals
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|SplitQualType
name|a
operator|,
name|SplitQualType
name|b
operator|)
block|{
return|return
name|a
operator|.
name|Ty
operator|!=
name|b
operator|.
name|Ty
operator|||
name|a
operator|.
name|Quals
operator|!=
name|b
operator|.
name|Quals
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// The kind of type we are substituting Objective-C type arguments into.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The kind of substitution affects the replacement of type parameters when
end_comment

begin_comment
comment|/// no concrete type information is provided, e.g., when dealing with an
end_comment

begin_comment
comment|/// unspecialized type.
end_comment

begin_decl_stmt
name|enum
name|class
name|ObjCSubstitutionContext
block|{
comment|/// An ordinary type.
name|Ordinary
operator|,
comment|/// The result type of a method or function.
name|Result
operator|,
comment|/// The parameter type of a method or function.
name|Parameter
operator|,
comment|/// The type of a property.
name|Property
operator|,
comment|/// The superclass of a type.
name|Superclass
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A (possibly-)qualified type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For efficiency, we don't store CV-qualified types as nodes on their
end_comment

begin_comment
comment|/// own: instead each reference to a type stores the qualifiers.  This
end_comment

begin_comment
comment|/// greatly reduces the number of nodes we need to allocate for types (for
end_comment

begin_comment
comment|/// example we only need one for 'int', 'const int', 'volatile int',
end_comment

begin_comment
comment|/// 'const volatile int', etc).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// As an added efficiency bonus, instead of making this a pair, we
end_comment

begin_comment
comment|/// just store the two bits we care about in the low bits of the
end_comment

begin_comment
comment|/// pointer.  To handle the packing/unpacking, we make QualType be a
end_comment

begin_comment
comment|/// simple wrapper class that acts like a smart pointer.  A third bit
end_comment

begin_comment
comment|/// indicates whether there are extended qualifiers present, in which
end_comment

begin_comment
comment|/// case the pointer points to a special structure.
end_comment

begin_decl_stmt
name|class
name|QualType
block|{
comment|// Thankfully, these are efficiently composable.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|PointerUnion
operator|<
specifier|const
name|Type
operator|*
operator|,
specifier|const
name|ExtQuals
operator|*
operator|>
operator|,
name|Qualifiers
operator|::
name|FastWidth
operator|>
name|Value
expr_stmt|;
specifier|const
name|ExtQuals
operator|*
name|getExtQualsUnsafe
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getPointer
argument_list|()
operator|.
name|get
operator|<
specifier|const
name|ExtQuals
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|Type
operator|*
name|getTypePtrUnsafe
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getPointer
argument_list|()
operator|.
name|get
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|ExtQualsTypeCommonBase
operator|*
name|getCommonPtr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isNull
argument_list|()
operator|&&
literal|"Cannot retrieve a NULL type pointer"
argument_list|)
block|;
name|uintptr_t
name|CommonPtrVal
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Value
operator|.
name|getOpaqueValue
argument_list|()
operator|)
block|;
name|CommonPtrVal
operator|&=
operator|~
call|(
name|uintptr_t
call|)
argument_list|(
operator|(
literal|1
operator|<<
name|TypeAlignmentInBits
operator|)
operator|-
literal|1
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|ExtQualsTypeCommonBase
operator|*
operator|>
operator|(
name|CommonPtrVal
operator|)
return|;
block|}
name|friend
name|class
name|QualifierCollector
decl_stmt|;
name|public
label|:
name|QualType
argument_list|()
block|{}
name|QualType
argument_list|(
argument|const Type *Ptr
argument_list|,
argument|unsigned Quals
argument_list|)
block|:
name|Value
argument_list|(
argument|Ptr
argument_list|,
argument|Quals
argument_list|)
block|{}
name|QualType
argument_list|(
argument|const ExtQuals *Ptr
argument_list|,
argument|unsigned Quals
argument_list|)
block|:
name|Value
argument_list|(
argument|Ptr
argument_list|,
argument|Quals
argument_list|)
block|{}
name|unsigned
name|getLocalFastQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getInt
argument_list|()
return|;
block|}
name|void
name|setLocalFastQualifiers
parameter_list|(
name|unsigned
name|Quals
parameter_list|)
block|{
name|Value
operator|.
name|setInt
argument_list|(
name|Quals
argument_list|)
expr_stmt|;
block|}
comment|/// Retrieves a pointer to the underlying (unqualified) type.
comment|///
comment|/// This function requires that the type not be NULL. If the type might be
comment|/// NULL, use the (slightly less efficient) \c getTypePtrOrNull().
specifier|const
name|Type
operator|*
name|getTypePtr
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|Type
operator|*
name|getTypePtrOrNull
argument_list|()
specifier|const
expr_stmt|;
comment|/// Retrieves a pointer to the name of the base type.
specifier|const
name|IdentifierInfo
operator|*
name|getBaseTypeIdentifier
argument_list|()
specifier|const
expr_stmt|;
comment|/// Divides a QualType into its unqualified type and a set of local
comment|/// qualifiers.
name|SplitQualType
name|split
argument_list|()
specifier|const
expr_stmt|;
name|void
operator|*
name|getAsOpaquePtr
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
specifier|static
name|QualType
name|getFromOpaquePtr
parameter_list|(
specifier|const
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
name|QualType
name|T
decl_stmt|;
name|T
operator|.
name|Value
operator|.
name|setFromOpaqueValue
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|Ptr
operator|)
argument_list|)
expr_stmt|;
return|return
name|T
return|;
block|}
specifier|const
name|Type
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|getTypePtr
argument_list|()
return|;
block|}
specifier|const
name|Type
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|getTypePtr
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|isCanonical
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isCanonicalAsParam
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return true if this QualType doesn't point to a type yet.
end_comment

begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getPointer
argument_list|()
operator|.
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this particular QualType instance has the
end_comment

begin_comment
comment|/// "const" qualifier set, without looking through typedefs that may have
end_comment

begin_comment
comment|/// added "const" at a different level.
end_comment

begin_expr_stmt
name|bool
name|isLocalConstQualified
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getLocalFastQualifiers
argument_list|()
operator|&
name|Qualifiers
operator|::
name|Const
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this type is const-qualified.
end_comment

begin_expr_stmt
name|bool
name|isConstQualified
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this particular QualType instance has the
end_comment

begin_comment
comment|/// "restrict" qualifier set, without looking through typedefs that may have
end_comment

begin_comment
comment|/// added "restrict" at a different level.
end_comment

begin_expr_stmt
name|bool
name|isLocalRestrictQualified
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getLocalFastQualifiers
argument_list|()
operator|&
name|Qualifiers
operator|::
name|Restrict
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this type is restrict-qualified.
end_comment

begin_expr_stmt
name|bool
name|isRestrictQualified
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this particular QualType instance has the
end_comment

begin_comment
comment|/// "volatile" qualifier set, without looking through typedefs that may have
end_comment

begin_comment
comment|/// added "volatile" at a different level.
end_comment

begin_expr_stmt
name|bool
name|isLocalVolatileQualified
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getLocalFastQualifiers
argument_list|()
operator|&
name|Qualifiers
operator|::
name|Volatile
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this type is volatile-qualified.
end_comment

begin_expr_stmt
name|bool
name|isVolatileQualified
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this particular QualType instance has any
end_comment

begin_comment
comment|/// qualifiers, without looking through any typedefs that might add
end_comment

begin_comment
comment|/// qualifiers at a different level.
end_comment

begin_expr_stmt
name|bool
name|hasLocalQualifiers
argument_list|()
specifier|const
block|{
return|return
name|getLocalFastQualifiers
argument_list|()
operator|||
name|hasLocalNonFastQualifiers
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this type has any qualifiers.
end_comment

begin_expr_stmt
name|bool
name|hasQualifiers
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this particular QualType instance has any
end_comment

begin_comment
comment|/// "non-fast" qualifiers, e.g., those that are stored in an ExtQualType
end_comment

begin_comment
comment|/// instance.
end_comment

begin_expr_stmt
name|bool
name|hasLocalNonFastQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getPointer
argument_list|()
operator|.
name|is
operator|<
specifier|const
name|ExtQuals
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the set of qualifiers local to this particular QualType
end_comment

begin_comment
comment|/// instance, not including any qualifiers acquired through typedefs or
end_comment

begin_comment
comment|/// other sugar.
end_comment

begin_expr_stmt
name|Qualifiers
name|getLocalQualifiers
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the set of qualifiers applied to this type.
end_comment

begin_expr_stmt
name|Qualifiers
name|getQualifiers
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the set of CVR (const-volatile-restrict) qualifiers
end_comment

begin_comment
comment|/// local to this particular QualType instance, not including any qualifiers
end_comment

begin_comment
comment|/// acquired through typedefs or other sugar.
end_comment

begin_expr_stmt
name|unsigned
name|getLocalCVRQualifiers
argument_list|()
specifier|const
block|{
return|return
name|getLocalFastQualifiers
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the set of CVR (const-volatile-restrict) qualifiers
end_comment

begin_comment
comment|/// applied to this type.
end_comment

begin_expr_stmt
name|unsigned
name|getCVRQualifiers
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|isConstant
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
block|{
return|return
name|QualType
operator|::
name|isConstant
argument_list|(
operator|*
name|this
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this is a Plain Old Data (POD) type (C++ 3.9p10).
end_comment

begin_decl_stmt
name|bool
name|isPODType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true if this is a POD type according to the rules of the C++98
end_comment

begin_comment
comment|/// standard, regardless of the current compilation's language.
end_comment

begin_decl_stmt
name|bool
name|isCXX98PODType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true if this is a POD type according to the more relaxed rules
end_comment

begin_comment
comment|/// of the C++11 standard, regardless of the current compilation's language.
end_comment

begin_comment
comment|/// (C++0x [basic.types]p9)
end_comment

begin_decl_stmt
name|bool
name|isCXX11PODType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true if this is a trivial type per (C++0x [basic.types]p9)
end_comment

begin_decl_stmt
name|bool
name|isTrivialType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true if this is a trivially copyable type (C++0x [basic.types]p9)
end_comment

begin_decl_stmt
name|bool
name|isTriviallyCopyableType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Don't promise in the API that anything besides 'const' can be
end_comment

begin_comment
comment|// easily added.
end_comment

begin_comment
comment|/// Add the `const` type qualifier to this QualType.
end_comment

begin_function
name|void
name|addConst
parameter_list|()
block|{
name|addFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Const
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|QualType
name|withConst
argument_list|()
specifier|const
block|{
return|return
name|withFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Const
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Add the `volatile` type qualifier to this QualType.
end_comment

begin_function
name|void
name|addVolatile
parameter_list|()
block|{
name|addFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Volatile
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|QualType
name|withVolatile
argument_list|()
specifier|const
block|{
return|return
name|withFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Volatile
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Add the `restrict` qualifier to this QualType.
end_comment

begin_function
name|void
name|addRestrict
parameter_list|()
block|{
name|addFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Restrict
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|QualType
name|withRestrict
argument_list|()
specifier|const
block|{
return|return
name|withFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Restrict
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|QualType
name|withCVRQualifiers
argument_list|(
name|unsigned
name|CVR
argument_list|)
decl|const
block|{
return|return
name|withFastQualifiers
argument_list|(
name|CVR
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|void
name|addFastQualifiers
parameter_list|(
name|unsigned
name|TQs
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|TQs
operator|&
operator|~
name|Qualifiers
operator|::
name|FastMask
operator|)
operator|&&
literal|"non-fast qualifier bits set in mask!"
argument_list|)
expr_stmt|;
name|Value
operator|.
name|setInt
argument_list|(
name|Value
operator|.
name|getInt
argument_list|()
operator||
name|TQs
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|removeLocalConst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|removeLocalVolatile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|removeLocalRestrict
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|removeLocalCVRQualifiers
parameter_list|(
name|unsigned
name|Mask
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|removeLocalFastQualifiers
parameter_list|()
block|{
name|Value
operator|.
name|setInt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|removeLocalFastQualifiers
parameter_list|(
name|unsigned
name|Mask
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|Mask
operator|&
operator|~
name|Qualifiers
operator|::
name|FastMask
operator|)
operator|&&
literal|"mask has non-fast qualifiers"
argument_list|)
expr_stmt|;
name|Value
operator|.
name|setInt
argument_list|(
name|Value
operator|.
name|getInt
argument_list|()
operator|&
operator|~
name|Mask
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Creates a type with the given qualifiers in addition to any
end_comment

begin_comment
comment|// qualifiers already on this type.
end_comment

begin_decl_stmt
name|QualType
name|withFastQualifiers
argument_list|(
name|unsigned
name|TQs
argument_list|)
decl|const
block|{
name|QualType
name|T
init|=
operator|*
name|this
decl_stmt|;
name|T
operator|.
name|addFastQualifiers
argument_list|(
name|TQs
argument_list|)
expr_stmt|;
return|return
name|T
return|;
block|}
end_decl_stmt

begin_comment
comment|// Creates a type with exactly the given fast qualifiers, removing
end_comment

begin_comment
comment|// any existing fast qualifiers.
end_comment

begin_decl_stmt
name|QualType
name|withExactLocalFastQualifiers
argument_list|(
name|unsigned
name|TQs
argument_list|)
decl|const
block|{
return|return
name|withoutLocalFastQualifiers
argument_list|()
operator|.
name|withFastQualifiers
argument_list|(
name|TQs
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Removes fast qualifiers, but leaves any extended qualifiers in place.
end_comment

begin_expr_stmt
name|QualType
name|withoutLocalFastQualifiers
argument_list|()
specifier|const
block|{
name|QualType
name|T
operator|=
operator|*
name|this
block|;
name|T
operator|.
name|removeLocalFastQualifiers
argument_list|()
block|;
return|return
name|T
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|QualType
name|getCanonicalType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return this type with all of the instance-specific qualifiers
end_comment

begin_comment
comment|/// removed, but without removing any qualifiers that may have been applied
end_comment

begin_comment
comment|/// through typedefs.
end_comment

begin_expr_stmt
name|QualType
name|getLocalUnqualifiedType
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|getTypePtr
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the unqualified variant of the given type,
end_comment

begin_comment
comment|/// removing as little sugar as possible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine looks through various kinds of sugar to find the
end_comment

begin_comment
comment|/// least-desugared type that is unqualified. For example, given:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// typedef int Integer;
end_comment

begin_comment
comment|/// typedef const Integer CInteger;
end_comment

begin_comment
comment|/// typedef CInteger DifferenceType;
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Executing \c getUnqualifiedType() on the type \c DifferenceType will
end_comment

begin_comment
comment|/// desugar until we hit the type \c Integer, which has no qualifiers on it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resulting type might still be qualified if it's sugar for an array
end_comment

begin_comment
comment|/// type.  To strip qualifiers even from within a sugared array type, use
end_comment

begin_comment
comment|/// ASTContext::getUnqualifiedArrayType.
end_comment

begin_expr_stmt
specifier|inline
name|QualType
name|getUnqualifiedType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Retrieve the unqualified variant of the given type, removing as little
end_comment

begin_comment
comment|/// sugar as possible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Like getUnqualifiedType(), but also returns the set of
end_comment

begin_comment
comment|/// qualifiers that were built up.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resulting type might still be qualified if it's sugar for an array
end_comment

begin_comment
comment|/// type.  To strip qualifiers even from within a sugared array type, use
end_comment

begin_comment
comment|/// ASTContext::getUnqualifiedArrayType.
end_comment

begin_expr_stmt
specifier|inline
name|SplitQualType
name|getSplitUnqualifiedType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this type is more qualified than the other
end_comment

begin_comment
comment|/// given type, requiring exact equality for non-CVR qualifiers.
end_comment

begin_decl_stmt
name|bool
name|isMoreQualifiedThan
argument_list|(
name|QualType
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this type is at least as qualified as the other
end_comment

begin_comment
comment|/// given type, requiring exact equality for non-CVR qualifiers.
end_comment

begin_decl_stmt
name|bool
name|isAtLeastAsQualifiedAs
argument_list|(
name|QualType
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|QualType
name|getNonReferenceType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine the type of a (typically non-lvalue) expression with the
end_comment

begin_comment
comment|/// specified result type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine should be used for expressions for which the return type is
end_comment

begin_comment
comment|/// explicitly specified (e.g., in a cast or call) and isn't necessarily
end_comment

begin_comment
comment|/// an lvalue. It removes a top-level reference (since there are no
end_comment

begin_comment
comment|/// expressions of reference type) and deletes top-level cvr-qualifiers
end_comment

begin_comment
comment|/// from non-class types (in C++) or all types (in C).
end_comment

begin_decl_stmt
name|QualType
name|getNonLValueExprType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the specified type with any "sugar" removed from
end_comment

begin_comment
comment|/// the type.  This takes off typedefs, typeof's etc.  If the outer level of
end_comment

begin_comment
comment|/// the type is already concrete, it returns it unmodified.  This is similar
end_comment

begin_comment
comment|/// to getting the canonical type, but it doesn't remove *all* typedefs.  For
end_comment

begin_comment
comment|/// example, it returns "T*" as "T*", (not as "int*"), because the pointer is
end_comment

begin_comment
comment|/// concrete.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Qualifiers are left in place.
end_comment

begin_decl_stmt
name|QualType
name|getDesugaredType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
block|{
return|return
name|getDesugaredType
argument_list|(
operator|*
name|this
argument_list|,
name|Context
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|SplitQualType
name|getSplitDesugaredType
argument_list|()
specifier|const
block|{
return|return
name|getSplitDesugaredType
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the specified type with one level of "sugar" removed from
end_comment

begin_comment
comment|/// the type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine takes off the first typedef, typeof, etc. If the outer level
end_comment

begin_comment
comment|/// of the type is already concrete, it returns it unmodified.
end_comment

begin_decl_stmt
name|QualType
name|getSingleStepDesugaredType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
block|{
return|return
name|getSingleStepDesugaredTypeImpl
argument_list|(
operator|*
name|this
argument_list|,
name|Context
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Returns the specified type after dropping any
end_comment

begin_comment
comment|/// outer-level parentheses.
end_comment

begin_expr_stmt
name|QualType
name|IgnoreParens
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isa
operator|<
name|ParenType
operator|>
operator|(
operator|*
name|this
operator|)
condition|)
return|return
name|QualType
operator|::
name|IgnoreParens
argument_list|(
operator|*
name|this
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// Indicate whether the specified types and qualifiers are identical.
end_comment

begin_expr_stmt
unit|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QualType
operator|&
name|LHS
operator|,
specifier|const
name|QualType
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Value
operator|==
name|RHS
operator|.
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QualType
operator|&
name|LHS
operator|,
specifier|const
name|QualType
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Value
operator|!=
name|RHS
operator|.
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
block|{
return|return
name|getAsString
argument_list|(
name|split
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|SplitQualType split
argument_list|)
block|{
return|return
name|getAsString
argument_list|(
name|split
operator|.
name|Ty
argument_list|,
name|split
operator|.
name|Quals
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|const Type *ty
argument_list|,
argument|Qualifiers qs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
specifier|const
name|Twine
operator|&
name|PlaceHolder
operator|=
name|Twine
argument_list|()
argument_list|,
name|unsigned
name|Indentation
operator|=
literal|0
argument_list|)
decl|const
block|{
name|print
argument_list|(
name|split
argument_list|()
argument_list|,
name|OS
argument_list|,
name|Policy
argument_list|,
name|PlaceHolder
argument_list|,
name|Indentation
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
specifier|static
name|void
name|print
parameter_list|(
name|SplitQualType
name|split
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|PrintingPolicy
modifier|&
name|policy
parameter_list|,
specifier|const
name|Twine
modifier|&
name|PlaceHolder
parameter_list|,
name|unsigned
name|Indentation
init|=
literal|0
parameter_list|)
block|{
return|return
name|print
argument_list|(
name|split
operator|.
name|Ty
argument_list|,
name|split
operator|.
name|Quals
argument_list|,
name|OS
argument_list|,
name|policy
argument_list|,
name|PlaceHolder
argument_list|,
name|Indentation
argument_list|)
return|;
block|}
end_function

begin_function_decl
specifier|static
name|void
name|print
parameter_list|(
specifier|const
name|Type
modifier|*
name|ty
parameter_list|,
name|Qualifiers
name|qs
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|PrintingPolicy
modifier|&
name|policy
parameter_list|,
specifier|const
name|Twine
modifier|&
name|PlaceHolder
parameter_list|,
name|unsigned
name|Indentation
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|getAsStringInternal
argument_list|(
name|std
operator|::
name|string
operator|&
name|Str
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|)
decl|const
block|{
return|return
name|getAsStringInternal
argument_list|(
name|split
argument_list|()
argument_list|,
name|Str
argument_list|,
name|Policy
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|getAsStringInternal
argument_list|(
name|SplitQualType
name|split
argument_list|,
name|std
operator|::
name|string
operator|&
name|out
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|policy
argument_list|)
block|{
return|return
name|getAsStringInternal
argument_list|(
name|split
operator|.
name|Ty
argument_list|,
name|split
operator|.
name|Quals
argument_list|,
name|out
argument_list|,
name|policy
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|getAsStringInternal
argument_list|(
specifier|const
name|Type
operator|*
name|ty
argument_list|,
name|Qualifiers
name|qs
argument_list|,
name|std
operator|::
name|string
operator|&
name|out
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|policy
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|StreamedQualTypeHelper
block|{
specifier|const
name|QualType
modifier|&
name|T
decl_stmt|;
specifier|const
name|PrintingPolicy
modifier|&
name|Policy
decl_stmt|;
specifier|const
name|Twine
modifier|&
name|PlaceHolder
decl_stmt|;
name|unsigned
name|Indentation
decl_stmt|;
name|public
label|:
name|StreamedQualTypeHelper
argument_list|(
argument|const QualType&T
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|,
argument|const Twine&PlaceHolder
argument_list|,
argument|unsigned Indentation
argument_list|)
block|:
name|T
argument_list|(
name|T
argument_list|)
operator|,
name|Policy
argument_list|(
name|Policy
argument_list|)
operator|,
name|PlaceHolder
argument_list|(
name|PlaceHolder
argument_list|)
operator|,
name|Indentation
argument_list|(
argument|Indentation
argument_list|)
block|{ }
name|friend
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
name|StreamedQualTypeHelper
operator|&
name|SQT
operator|)
block|{
name|SQT
operator|.
name|T
operator|.
name|print
argument_list|(
name|OS
argument_list|,
name|SQT
operator|.
name|Policy
argument_list|,
name|SQT
operator|.
name|PlaceHolder
argument_list|,
name|SQT
operator|.
name|Indentation
argument_list|)
block|;
return|return
name|OS
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|StreamedQualTypeHelper
name|stream
argument_list|(
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
specifier|const
name|Twine
operator|&
name|PlaceHolder
operator|=
name|Twine
argument_list|()
argument_list|,
name|unsigned
name|Indentation
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|StreamedQualTypeHelper
argument_list|(
operator|*
name|this
argument_list|,
name|Policy
argument_list|,
name|PlaceHolder
argument_list|,
name|Indentation
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|dump
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|dump
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|getAsOpaquePtr
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Return the address space of this type.
end_comment

begin_expr_stmt
specifier|inline
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns gc attribute of this type.
end_comment

begin_expr_stmt
specifier|inline
name|Qualifiers
operator|::
name|GC
name|getObjCGCAttr
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// true when Type is objc's weak.
end_comment

begin_expr_stmt
name|bool
name|isObjCGCWeak
argument_list|()
specifier|const
block|{
return|return
name|getObjCGCAttr
argument_list|()
operator|==
name|Qualifiers
operator|::
name|Weak
return|;
block|}
end_expr_stmt

begin_comment
comment|/// true when Type is objc's strong.
end_comment

begin_expr_stmt
name|bool
name|isObjCGCStrong
argument_list|()
specifier|const
block|{
return|return
name|getObjCGCAttr
argument_list|()
operator|==
name|Qualifiers
operator|::
name|Strong
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns lifetime attribute of this type.
end_comment

begin_expr_stmt
name|Qualifiers
operator|::
name|ObjCLifetime
name|getObjCLifetime
argument_list|()
specifier|const
block|{
return|return
name|getQualifiers
argument_list|()
operator|.
name|getObjCLifetime
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasNonTrivialObjCLifetime
argument_list|()
specifier|const
block|{
return|return
name|getQualifiers
argument_list|()
operator|.
name|hasNonTrivialObjCLifetime
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasStrongOrWeakObjCLifetime
argument_list|()
specifier|const
block|{
return|return
name|getQualifiers
argument_list|()
operator|.
name|hasStrongOrWeakObjCLifetime
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// true when Type is objc's weak and weak is enabled but ARC isn't.
end_comment

begin_decl_stmt
name|bool
name|isNonWeakInMRRWithObjCWeak
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|DestructionKind
block|{
name|DK_none
block|,
name|DK_cxx_destructor
block|,
name|DK_objc_strong_lifetime
block|,
name|DK_objc_weak_lifetime
block|}
enum|;
end_enum

begin_comment
comment|/// Returns a nonzero value if objects of this type require
end_comment

begin_comment
comment|/// non-trivial work to clean up after.  Non-zero because it's
end_comment

begin_comment
comment|/// conceivable that qualifiers (objc_gc(weak)?) could make
end_comment

begin_comment
comment|/// something require destruction.
end_comment

begin_expr_stmt
name|DestructionKind
name|isDestructedType
argument_list|()
specifier|const
block|{
return|return
name|isDestructedTypeImpl
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Determine whether expressions of the given type are forbidden
end_comment

begin_comment
comment|/// from being lvalues in C.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The expression types that are forbidden to be lvalues are:
end_comment

begin_comment
comment|///   - 'void', but not qualified void
end_comment

begin_comment
comment|///   - function types
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The exact rule here is C99 6.3.2.1:
end_comment

begin_comment
comment|///   An lvalue is an expression with an object type or an incomplete
end_comment

begin_comment
comment|///   type other than void.
end_comment

begin_expr_stmt
name|bool
name|isCForbiddenLValueType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Substitute type arguments for the Objective-C type parameters used in the
end_comment

begin_comment
comment|/// subject type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ctx ASTContext in which the type exists.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param typeArgs The type arguments that will be substituted for the
end_comment

begin_comment
comment|/// Objective-C type parameters in the subject type, which are generally
end_comment

begin_comment
comment|/// computed via \c Type::getObjCSubstitutions. If empty, the type
end_comment

begin_comment
comment|/// parameters will be replaced with their bounds or id/Class, as appropriate
end_comment

begin_comment
comment|/// for the context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param context The context in which the subject type was written.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the resulting type.
end_comment

begin_decl_stmt
name|QualType
name|substObjCTypeArgs
argument_list|(
name|ASTContext
operator|&
name|ctx
argument_list|,
name|ArrayRef
operator|<
name|QualType
operator|>
name|typeArgs
argument_list|,
name|ObjCSubstitutionContext
name|context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Substitute type arguments from an object type for the Objective-C type
end_comment

begin_comment
comment|/// parameters used in the subject type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operation combines the computation of type arguments for
end_comment

begin_comment
comment|/// substitution (\c Type::getObjCSubstitutions) with the actual process of
end_comment

begin_comment
comment|/// substitution (\c QualType::substObjCTypeArgs) for the convenience of
end_comment

begin_comment
comment|/// callers that need to perform a single substitution in isolation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param objectType The type of the object whose member type we're
end_comment

begin_comment
comment|/// substituting into. For example, this might be the receiver of a message
end_comment

begin_comment
comment|/// or the base of a property access.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param dc The declaration context from which the subject type was
end_comment

begin_comment
comment|/// retrieved, which indicates (for example) which type parameters should
end_comment

begin_comment
comment|/// be substituted.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param context The context in which the subject type was written.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the subject type after replacing all of the Objective-C type
end_comment

begin_comment
comment|/// parameters with their corresponding arguments.
end_comment

begin_decl_stmt
name|QualType
name|substObjCMemberType
argument_list|(
name|QualType
name|objectType
argument_list|,
specifier|const
name|DeclContext
operator|*
name|dc
argument_list|,
name|ObjCSubstitutionContext
name|context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Strip Objective-C "__kindof" types from the given type.
end_comment

begin_decl_stmt
name|QualType
name|stripObjCKindOfType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|ctx
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Remove all qualifiers including _Atomic.
end_comment

begin_expr_stmt
name|QualType
name|getAtomicUnqualifiedType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// These methods are implemented in a separate translation unit;
end_comment

begin_comment
comment|// "static"-ize them to avoid creating temporary QualTypes in the
end_comment

begin_comment
comment|// caller.
end_comment

begin_function_decl
specifier|static
name|bool
name|isConstant
parameter_list|(
name|QualType
name|T
parameter_list|,
specifier|const
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|QualType
name|getDesugaredType
parameter_list|(
name|QualType
name|T
parameter_list|,
specifier|const
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|SplitQualType
name|getSplitDesugaredType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|SplitQualType
name|getSplitUnqualifiedTypeImpl
parameter_list|(
name|QualType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|QualType
name|getSingleStepDesugaredTypeImpl
parameter_list|(
name|QualType
name|type
parameter_list|,
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|QualType
name|IgnoreParens
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|DestructionKind
name|isDestructedTypeImpl
parameter_list|(
name|QualType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// end clang.
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
comment|/// Implement simplify_type for QualType, so that we can dyn_cast from QualType
comment|/// to a specific Type class.
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
operator|::
name|clang
operator|::
name|QualType
operator|>
block|{
typedef|typedef
specifier|const
operator|::
name|clang
operator|::
name|Type
operator|*
name|SimpleType
expr_stmt|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|::clang::QualType Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getTypePtr
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|// Teach SmallPtrSet that QualType is "basically a pointer".
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|clang
operator|::
name|QualType
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|clang::QualType P
argument_list|)
block|{
return|return
name|P
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|QualType
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|clang
operator|::
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|P
argument_list|)
return|;
block|}
comment|// Various qualifiers go in low bits.
enum|enum
block|{
name|NumLowBitsAvailable
init|=
literal|0
block|}
enum|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_macro
unit|namespace
name|clang
end_macro

begin_block
block|{
comment|/// \brief Base class that is common to both the \c ExtQuals and \c Type
comment|/// classes, which allows \c QualType to access the common fields between the
comment|/// two.
comment|///
name|class
name|ExtQualsTypeCommonBase
block|{
name|ExtQualsTypeCommonBase
argument_list|(
argument|const Type *baseType
argument_list|,
argument|QualType canon
argument_list|)
block|:
name|BaseType
argument_list|(
name|baseType
argument_list|)
operator|,
name|CanonicalType
argument_list|(
argument|canon
argument_list|)
block|{}
comment|/// \brief The "base" type of an extended qualifiers type (\c ExtQuals) or
comment|/// a self-referential pointer (for \c Type).
comment|///
comment|/// This pointer allows an efficient mapping from a QualType to its
comment|/// underlying type pointer.
specifier|const
name|Type
operator|*
specifier|const
name|BaseType
expr_stmt|;
comment|/// \brief The canonical type of this type.  A QualType.
name|QualType
name|CanonicalType
decl_stmt|;
name|friend
name|class
name|QualType
decl_stmt|;
name|friend
name|class
name|Type
decl_stmt|;
name|friend
name|class
name|ExtQuals
decl_stmt|;
block|}
empty_stmt|;
comment|/// We can encode up to four bits in the low bits of a
comment|/// type pointer, but there are many more type qualifiers that we want
comment|/// to be able to apply to an arbitrary type.  Therefore we have this
comment|/// struct, intended to be heap-allocated and used by QualType to
comment|/// store qualifiers.
comment|///
comment|/// The current design tags the 'const', 'restrict', and 'volatile' qualifiers
comment|/// in three low bits on the QualType pointer; a fourth bit records whether
comment|/// the pointer is an ExtQuals node. The extended qualifiers (address spaces,
comment|/// Objective-C GC attributes) are much more rare.
name|class
name|ExtQuals
range|:
name|public
name|ExtQualsTypeCommonBase
decl_stmt|,
name|public
name|llvm
decl|::
name|FoldingSetNode
block|{
comment|// NOTE: changing the fast qualifiers should be straightforward as
comment|// long as you don't make 'const' non-fast.
comment|// 1. Qualifiers:
comment|//    a) Modify the bitmasks (Qualifiers::TQ and DeclSpec::TQ).
comment|//       Fast qualifiers must occupy the low-order bits.
comment|//    b) Update Qualifiers::FastWidth and FastMask.
comment|// 2. QualType:
comment|//    a) Update is{Volatile,Restrict}Qualified(), defined inline.
comment|//    b) Update remove{Volatile,Restrict}, defined near the end of
comment|//       this header.
comment|// 3. ASTContext:
comment|//    a) Update get{Volatile,Restrict}Type.
comment|/// The immutable set of qualifiers applied by this node. Always contains
comment|/// extended qualifiers.
name|Qualifiers
name|Quals
decl_stmt|;
name|ExtQuals
modifier|*
name|this_
parameter_list|()
block|{
return|return
name|this
return|;
block|}
name|public
label|:
name|ExtQuals
argument_list|(
argument|const Type *baseType
argument_list|,
argument|QualType canon
argument_list|,
argument|Qualifiers quals
argument_list|)
block|:
name|ExtQualsTypeCommonBase
argument_list|(
name|baseType
argument_list|,
name|canon
operator|.
name|isNull
argument_list|()
condition|?
name|QualType
argument_list|(
name|this_
argument_list|()
argument_list|,
literal|0
argument_list|)
else|:
name|canon
argument_list|)
operator|,
name|Quals
argument_list|(
argument|quals
argument_list|)
block|{
name|assert
argument_list|(
name|Quals
operator|.
name|hasNonFastQualifiers
argument_list|()
operator|&&
literal|"ExtQuals created with no fast qualifiers"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|Quals
operator|.
name|hasFastQualifiers
argument_list|()
operator|&&
literal|"ExtQuals created with fast qualifiers"
argument_list|)
block|;   }
name|Qualifiers
name|getQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Quals
return|;
block|}
name|bool
name|hasObjCGCAttr
argument_list|()
specifier|const
block|{
return|return
name|Quals
operator|.
name|hasObjCGCAttr
argument_list|()
return|;
block|}
name|Qualifiers
operator|::
name|GC
name|getObjCGCAttr
argument_list|()
specifier|const
block|{
return|return
name|Quals
operator|.
name|getObjCGCAttr
argument_list|()
return|;
block|}
name|bool
name|hasObjCLifetime
argument_list|()
specifier|const
block|{
return|return
name|Quals
operator|.
name|hasObjCLifetime
argument_list|()
return|;
block|}
name|Qualifiers
operator|::
name|ObjCLifetime
name|getObjCLifetime
argument_list|()
specifier|const
block|{
return|return
name|Quals
operator|.
name|getObjCLifetime
argument_list|()
return|;
block|}
name|bool
name|hasAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|Quals
operator|.
name|hasAddressSpace
argument_list|()
return|;
block|}
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|Quals
operator|.
name|getAddressSpace
argument_list|()
return|;
block|}
specifier|const
name|Type
operator|*
name|getBaseType
argument_list|()
specifier|const
block|{
return|return
name|BaseType
return|;
block|}
name|public
label|:
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getBaseType
argument_list|()
argument_list|,
name|Quals
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
specifier|const
name|Type
operator|*
name|BaseType
argument_list|,
name|Qualifiers
name|Quals
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|Quals
operator|.
name|hasFastQualifiers
argument_list|()
operator|&&
literal|"fast qualifiers in ExtQuals hash!"
argument_list|)
expr_stmt|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|BaseType
argument_list|)
expr_stmt|;
name|Quals
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// The kind of C++11 ref-qualifier associated with a function type.
comment|/// This determines whether a member function's "this" object can be an
comment|/// lvalue, rvalue, or neither.
enum|enum
name|RefQualifierKind
block|{
comment|/// \brief No ref-qualifier was provided.
name|RQ_None
init|=
literal|0
block|,
comment|/// \brief An lvalue ref-qualifier was provided (\c&).
name|RQ_LValue
block|,
comment|/// \brief An rvalue ref-qualifier was provided (\c&&).
name|RQ_RValue
block|}
enum|;
comment|/// Which keyword(s) were used to create an AutoType.
name|enum
name|class
name|AutoTypeKeyword
block|{
comment|/// \brief auto
name|Auto
operator|,
comment|/// \brief decltype(auto)
name|DecltypeAuto
operator|,
comment|/// \brief __auto_type (GNU extension)
name|GNUAutoType
block|}
empty_stmt|;
comment|/// The base class of the type hierarchy.
comment|///
comment|/// A central concept with types is that each type always has a canonical
comment|/// type.  A canonical type is the type with any typedef names stripped out
comment|/// of it or the types it references.  For example, consider:
comment|///
comment|///  typedef int  foo;
comment|///  typedef foo* bar;
comment|///    'int *'    'foo *'    'bar'
comment|///
comment|/// There will be a Type object created for 'int'.  Since int is canonical, its
comment|/// CanonicalType pointer points to itself.  There is also a Type for 'foo' (a
comment|/// TypedefType).  Its CanonicalType pointer points to the 'int' Type.  Next
comment|/// there is a PointerType that represents 'int*', which, like 'int', is
comment|/// canonical.  Finally, there is a PointerType type for 'foo*' whose canonical
comment|/// type is 'int*', and there is a TypedefType for 'bar', whose canonical type
comment|/// is also 'int*'.
comment|///
comment|/// Non-canonical types are useful for emitting diagnostics, without losing
comment|/// information about typedefs being used.  Canonical types are useful for type
comment|/// comparisons (they allow by-pointer equality tests) and useful for reasoning
comment|/// about whether something has a particular form (e.g. is a function type),
comment|/// because they implicitly, recursively, strip all typedefs out of a type.
comment|///
comment|/// Types, once created, are immutable.
comment|///
name|class
name|Type
range|:
name|public
name|ExtQualsTypeCommonBase
block|{
name|public
operator|:
expr|enum
name|TypeClass
block|{
define|#
directive|define
name|TYPE
parameter_list|(
name|Class
parameter_list|,
name|Base
parameter_list|)
value|Class,
define|#
directive|define
name|LAST_TYPE
parameter_list|(
name|Class
parameter_list|)
value|TypeLast = Class,
define|#
directive|define
name|ABSTRACT_TYPE
parameter_list|(
name|Class
parameter_list|,
name|Base
parameter_list|)
include|#
directive|include
file|"clang/AST/TypeNodes.def"
name|TagFirst
operator|=
name|Record
block|,
name|TagLast
operator|=
name|Enum
block|}
block|;
name|private
operator|:
name|Type
argument_list|(
specifier|const
name|Type
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|Type
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// Bitfields required by the Type class.
name|class
name|TypeBitfields
block|{
name|friend
name|class
name|Type
block|;
name|template
operator|<
name|class
name|T
operator|>
name|friend
name|class
name|TypePropertyCache
block|;
comment|/// TypeClass bitfield - Enum that specifies what subclass this belongs to.
name|unsigned
name|TC
operator|:
literal|8
block|;
comment|/// Whether this type is a dependent type (C++ [temp.dep.type]).
name|unsigned
name|Dependent
operator|:
literal|1
block|;
comment|/// Whether this type somehow involves a template parameter, even
comment|/// if the resolution of the type does not depend on a template parameter.
name|unsigned
name|InstantiationDependent
operator|:
literal|1
block|;
comment|/// Whether this type is a variably-modified type (C99 6.7.5).
name|unsigned
name|VariablyModified
operator|:
literal|1
block|;
comment|/// \brief Whether this type contains an unexpanded parameter pack
comment|/// (for C++11 variadic templates).
name|unsigned
name|ContainsUnexpandedParameterPack
operator|:
literal|1
block|;
comment|/// \brief True if the cache (i.e. the bitfields here starting with
comment|/// 'Cache') is valid.
name|mutable
name|unsigned
name|CacheValid
operator|:
literal|1
block|;
comment|/// \brief Linkage of this type.
name|mutable
name|unsigned
name|CachedLinkage
operator|:
literal|3
block|;
comment|/// \brief Whether this type involves and local or unnamed types.
name|mutable
name|unsigned
name|CachedLocalOrUnnamed
operator|:
literal|1
block|;
comment|/// \brief Whether this type comes from an AST file.
name|mutable
name|unsigned
name|FromAST
operator|:
literal|1
block|;
name|bool
name|isCacheValid
argument_list|()
specifier|const
block|{
return|return
name|CacheValid
return|;
block|}
name|Linkage
name|getLinkage
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isCacheValid
argument_list|()
operator|&&
literal|"getting linkage from invalid cache"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Linkage
operator|>
operator|(
name|CachedLinkage
operator|)
return|;
block|}
name|bool
name|hasLocalOrUnnamedType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isCacheValid
argument_list|()
operator|&&
literal|"getting linkage from invalid cache"
argument_list|)
block|;
return|return
name|CachedLocalOrUnnamed
return|;
block|}
expr|}
block|;   enum
block|{
name|NumTypeBits
operator|=
literal|18
block|}
block|;
name|protected
operator|:
comment|// These classes allow subclasses to somewhat cleanly pack bitfields
comment|// into Type.
name|class
name|ArrayTypeBitfields
block|{
name|friend
name|class
name|ArrayType
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// CVR qualifiers from declarations like
comment|/// 'int X[static restrict 4]'. For function parameters only.
name|unsigned
name|IndexTypeQuals
operator|:
literal|3
block|;
comment|/// Storage class qualifiers from declarations like
comment|/// 'int X[static restrict 4]'. For function parameters only.
comment|/// Actually an ArrayType::ArraySizeModifier.
name|unsigned
name|SizeModifier
operator|:
literal|3
block|;   }
block|;
name|class
name|BuiltinTypeBitfields
block|{
name|friend
name|class
name|BuiltinType
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// The kind (BuiltinType::Kind) of builtin type this is.
name|unsigned
name|Kind
operator|:
literal|8
block|;   }
block|;
name|class
name|FunctionTypeBitfields
block|{
name|friend
name|class
name|FunctionType
block|;
name|friend
name|class
name|FunctionProtoType
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// Extra information which affects how the function is called, like
comment|/// regparm and the calling convention.
name|unsigned
name|ExtInfo
operator|:
literal|11
block|;
comment|/// Used only by FunctionProtoType, put here to pack with the
comment|/// other bitfields.
comment|/// The qualifiers are part of FunctionProtoType because...
comment|///
comment|/// C++ 8.3.5p4: The return type, the parameter type list and the
comment|/// cv-qualifier-seq, [...], are part of the function type.
name|unsigned
name|TypeQuals
operator|:
literal|4
block|;
comment|/// \brief The ref-qualifier associated with a \c FunctionProtoType.
comment|///
comment|/// This is a value of type \c RefQualifierKind.
name|unsigned
name|RefQualifier
operator|:
literal|2
block|;   }
block|;
name|class
name|ObjCObjectTypeBitfields
block|{
name|friend
name|class
name|ObjCObjectType
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// The number of type arguments stored directly on this object type.
name|unsigned
name|NumTypeArgs
operator|:
literal|7
block|;
comment|/// The number of protocols stored directly on this object type.
name|unsigned
name|NumProtocols
operator|:
literal|6
block|;
comment|/// Whether this is a "kindof" type.
name|unsigned
name|IsKindOf
operator|:
literal|1
block|;   }
block|;
name|static_assert
argument_list|(
name|NumTypeBits
operator|+
literal|7
operator|+
literal|6
operator|+
literal|1
operator|<=
literal|32
argument_list|,
literal|"Does not fit in an unsigned"
argument_list|)
block|;
name|class
name|ReferenceTypeBitfields
block|{
name|friend
name|class
name|ReferenceType
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// True if the type was originally spelled with an lvalue sigil.
comment|/// This is never true of rvalue references but can also be false
comment|/// on lvalue references because of C++0x [dcl.typedef]p9,
comment|/// as follows:
comment|///
comment|///   typedef int&ref;    // lvalue, spelled lvalue
comment|///   typedef int&&rvref; // rvalue
comment|///   ref&a;              // lvalue, inner ref, spelled lvalue
comment|///   ref&&a;             // lvalue, inner ref
comment|///   rvref&a;            // lvalue, inner ref, spelled lvalue
comment|///   rvref&&a;           // rvalue, inner ref
name|unsigned
name|SpelledAsLValue
operator|:
literal|1
block|;
comment|/// True if the inner type is a reference type.  This only happens
comment|/// in non-canonical forms.
name|unsigned
name|InnerRef
operator|:
literal|1
block|;   }
block|;
name|class
name|TypeWithKeywordBitfields
block|{
name|friend
name|class
name|TypeWithKeyword
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// An ElaboratedTypeKeyword.  8 bits for efficient access.
name|unsigned
name|Keyword
operator|:
literal|8
block|;   }
block|;
name|class
name|VectorTypeBitfields
block|{
name|friend
name|class
name|VectorType
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// The kind of vector, either a generic vector type or some
comment|/// target-specific vector type such as for AltiVec or Neon.
name|unsigned
name|VecKind
operator|:
literal|3
block|;
comment|/// The number of elements in the vector.
name|unsigned
name|NumElements
operator|:
literal|29
operator|-
name|NumTypeBits
block|;      enum
block|{
name|MaxNumElements
operator|=
operator|(
literal|1
operator|<<
operator|(
literal|29
operator|-
name|NumTypeBits
operator|)
operator|)
operator|-
literal|1
block|}
block|;   }
block|;
name|class
name|AttributedTypeBitfields
block|{
name|friend
name|class
name|AttributedType
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// An AttributedType::Kind
name|unsigned
name|AttrKind
operator|:
literal|32
operator|-
name|NumTypeBits
block|;   }
block|;
name|class
name|AutoTypeBitfields
block|{
name|friend
name|class
name|AutoType
block|;
name|unsigned
operator|:
name|NumTypeBits
block|;
comment|/// Was this placeholder type spelled as 'auto', 'decltype(auto)',
comment|/// or '__auto_type'?  AutoTypeKeyword value.
name|unsigned
name|Keyword
operator|:
literal|2
block|;   }
block|;
expr|union
block|{
name|TypeBitfields
name|TypeBits
block|;
name|ArrayTypeBitfields
name|ArrayTypeBits
block|;
name|AttributedTypeBitfields
name|AttributedTypeBits
block|;
name|AutoTypeBitfields
name|AutoTypeBits
block|;
name|BuiltinTypeBitfields
name|BuiltinTypeBits
block|;
name|FunctionTypeBitfields
name|FunctionTypeBits
block|;
name|ObjCObjectTypeBitfields
name|ObjCObjectTypeBits
block|;
name|ReferenceTypeBitfields
name|ReferenceTypeBits
block|;
name|TypeWithKeywordBitfields
name|TypeWithKeywordBits
block|;
name|VectorTypeBitfields
name|VectorTypeBits
block|;   }
block|;
name|private
operator|:
comment|/// \brief Set whether this type comes from an AST file.
name|void
name|setFromAST
argument_list|(
argument|bool V = true
argument_list|)
specifier|const
block|{
name|TypeBits
operator|.
name|FromAST
operator|=
name|V
block|;   }
name|template
operator|<
name|class
name|T
operator|>
name|friend
name|class
name|TypePropertyCache
block|;
name|protected
operator|:
comment|// silence VC++ warning C4355: 'this' : used in base member initializer list
name|Type
operator|*
name|this_
argument_list|()
block|{
return|return
name|this
return|;
block|}
name|Type
argument_list|(
argument|TypeClass tc
argument_list|,
argument|QualType canon
argument_list|,
argument|bool Dependent
argument_list|,
argument|bool InstantiationDependent
argument_list|,
argument|bool VariablyModified
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|)
operator|:
name|ExtQualsTypeCommonBase
argument_list|(
argument|this
argument_list|,
argument|canon.isNull() ? QualType(this_(),
literal|0
argument|) : canon
argument_list|)
block|{
name|TypeBits
operator|.
name|TC
operator|=
name|tc
block|;
name|TypeBits
operator|.
name|Dependent
operator|=
name|Dependent
block|;
name|TypeBits
operator|.
name|InstantiationDependent
operator|=
name|Dependent
operator|||
name|InstantiationDependent
block|;
name|TypeBits
operator|.
name|VariablyModified
operator|=
name|VariablyModified
block|;
name|TypeBits
operator|.
name|ContainsUnexpandedParameterPack
operator|=
name|ContainsUnexpandedParameterPack
block|;
name|TypeBits
operator|.
name|CacheValid
operator|=
name|false
block|;
name|TypeBits
operator|.
name|CachedLocalOrUnnamed
operator|=
name|false
block|;
name|TypeBits
operator|.
name|CachedLinkage
operator|=
name|NoLinkage
block|;
name|TypeBits
operator|.
name|FromAST
operator|=
name|false
block|;   }
name|friend
name|class
name|ASTContext
block|;
name|void
name|setDependent
argument_list|(
argument|bool D = true
argument_list|)
block|{
name|TypeBits
operator|.
name|Dependent
operator|=
name|D
block|;
if|if
condition|(
name|D
condition|)
name|TypeBits
operator|.
name|InstantiationDependent
operator|=
name|true
expr_stmt|;
block|}
name|void
name|setInstantiationDependent
argument_list|(
argument|bool D = true
argument_list|)
block|{
name|TypeBits
operator|.
name|InstantiationDependent
operator|=
name|D
block|; }
name|void
name|setVariablyModified
argument_list|(
argument|bool VM = true
argument_list|)
block|{
name|TypeBits
operator|.
name|VariablyModified
operator|=
name|VM
block|;   }
name|void
name|setContainsUnexpandedParameterPack
argument_list|(
argument|bool PP = true
argument_list|)
block|{
name|TypeBits
operator|.
name|ContainsUnexpandedParameterPack
operator|=
name|PP
block|;   }
name|public
operator|:
name|TypeClass
name|getTypeClass
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|TypeClass
operator|>
operator|(
name|TypeBits
operator|.
name|TC
operator|)
return|;
block|}
comment|/// \brief Whether this type comes from an AST file.
name|bool
name|isFromAST
argument_list|()
specifier|const
block|{
return|return
name|TypeBits
operator|.
name|FromAST
return|;
block|}
comment|/// \brief Whether this type is or contains an unexpanded parameter
comment|/// pack, used to support C++0x variadic templates.
comment|///
comment|/// A type that contains a parameter pack shall be expanded by the
comment|/// ellipsis operator at some point. For example, the typedef in the
comment|/// following example contains an unexpanded parameter pack 'T':
comment|///
comment|/// \code
comment|/// template<typename ...T>
comment|/// struct X {
comment|///   typedef T* pointer_types; // ill-formed; T is a parameter pack.
comment|/// };
comment|/// \endcode
comment|///
comment|/// Note that this routine does not specify which
name|bool
name|containsUnexpandedParameterPack
argument_list|()
specifier|const
block|{
return|return
name|TypeBits
operator|.
name|ContainsUnexpandedParameterPack
return|;
block|}
comment|/// Determines if this type would be canonical if it had no further
comment|/// qualification.
name|bool
name|isCanonicalUnqualified
argument_list|()
specifier|const
block|{
return|return
name|CanonicalType
operator|==
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// Pull a single level of sugar off of this locally-unqualified type.
comment|/// Users should generally prefer SplitQualType::getSingleStepDesugaredType()
comment|/// or QualType::getSingleStepDesugaredType(const ASTContext&).
name|QualType
name|getLocallyUnqualifiedSingleStepDesugaredType
argument_list|()
specifier|const
block|;
comment|/// Types are partitioned into 3 broad categories (C99 6.2.5p1):
comment|/// object types, function types, and incomplete types.
comment|/// Return true if this is an incomplete type.
comment|/// A type that can describe objects, but which lacks information needed to
comment|/// determine its size (e.g. void, or a fwd declared struct). Clients of this
comment|/// routine will need to determine if the size is actually required.
comment|///
comment|/// \brief Def If non-null, and the type refers to some kind of declaration
comment|/// that can be completed (such as a C struct, C++ class, or Objective-C
comment|/// class), will be set to the declaration.
name|bool
name|isIncompleteType
argument_list|(
argument|NamedDecl **Def = nullptr
argument_list|)
specifier|const
block|;
comment|/// Return true if this is an incomplete or object
comment|/// type, in other words, not a function type.
name|bool
name|isIncompleteOrObjectType
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isFunctionType
argument_list|()
return|;
block|}
comment|/// \brief Determine whether this type is an object type.
name|bool
name|isObjectType
argument_list|()
specifier|const
block|{
comment|// C++ [basic.types]p8:
comment|//   An object type is a (possibly cv-qualified) type that is not a
comment|//   function type, not a reference type, and not a void type.
return|return
operator|!
name|isReferenceType
argument_list|()
operator|&&
operator|!
name|isFunctionType
argument_list|()
operator|&&
operator|!
name|isVoidType
argument_list|()
return|;
block|}
comment|/// Return true if this is a literal type
comment|/// (C++11 [basic.types]p10)
name|bool
name|isLiteralType
argument_list|(
argument|const ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// Test if this type is a standard-layout type.
comment|/// (C++0x [basic.type]p9)
name|bool
name|isStandardLayoutType
argument_list|()
specifier|const
block|;
comment|/// Helper methods to distinguish type categories. All type predicates
comment|/// operate on the canonical type, ignoring typedefs and qualifiers.
comment|/// Returns true if the type is a builtin type.
name|bool
name|isBuiltinType
argument_list|()
specifier|const
block|;
comment|/// Test for a particular builtin type.
name|bool
name|isSpecificBuiltinType
argument_list|(
argument|unsigned K
argument_list|)
specifier|const
block|;
comment|/// Test for a type which does not represent an actual type-system type but
comment|/// is instead used as a placeholder for various convenient purposes within
comment|/// Clang.  All such types are BuiltinTypes.
name|bool
name|isPlaceholderType
argument_list|()
specifier|const
block|;
specifier|const
name|BuiltinType
operator|*
name|getAsPlaceholderType
argument_list|()
specifier|const
block|;
comment|/// Test for a specific placeholder type.
name|bool
name|isSpecificPlaceholderType
argument_list|(
argument|unsigned K
argument_list|)
specifier|const
block|;
comment|/// Test for a placeholder type other than Overload; see
comment|/// BuiltinType::isNonOverloadPlaceholderType.
name|bool
name|isNonOverloadPlaceholderType
argument_list|()
specifier|const
block|;
comment|/// isIntegerType() does *not* include complex integers (a GCC extension).
comment|/// isComplexIntegerType() can be used to test for complex integers.
name|bool
name|isIntegerType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p17 (int, char, bool, enum)
name|bool
name|isEnumeralType
argument_list|()
specifier|const
block|;
name|bool
name|isBooleanType
argument_list|()
specifier|const
block|;
name|bool
name|isCharType
argument_list|()
specifier|const
block|;
name|bool
name|isWideCharType
argument_list|()
specifier|const
block|;
name|bool
name|isChar16Type
argument_list|()
specifier|const
block|;
name|bool
name|isChar32Type
argument_list|()
specifier|const
block|;
name|bool
name|isAnyCharacterType
argument_list|()
specifier|const
block|;
name|bool
name|isIntegralType
argument_list|(
argument|const ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// Determine whether this type is an integral or enumeration type.
name|bool
name|isIntegralOrEnumerationType
argument_list|()
specifier|const
block|;
comment|/// Determine whether this type is an integral or unscoped enumeration type.
name|bool
name|isIntegralOrUnscopedEnumerationType
argument_list|()
specifier|const
block|;
comment|/// Floating point categories.
name|bool
name|isRealFloatingType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p10 (float, double, long double)
comment|/// isComplexType() does *not* include complex integers (a GCC extension).
comment|/// isComplexIntegerType() can be used to test for complex integers.
name|bool
name|isComplexType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p11 (complex)
name|bool
name|isAnyComplexType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p11 (complex) + Complex Int.
name|bool
name|isFloatingType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p11 (real floating + complex)
name|bool
name|isHalfType
argument_list|()
specifier|const
block|;
comment|// OpenCL 6.1.1.1, NEON (IEEE 754-2008 half)
name|bool
name|isRealType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p17 (real floating + integer)
name|bool
name|isArithmeticType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p18 (integer + floating)
name|bool
name|isVoidType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p19
name|bool
name|isScalarType
argument_list|()
specifier|const
block|;
comment|// C99 6.2.5p21 (arithmetic + pointers)
name|bool
name|isAggregateType
argument_list|()
specifier|const
block|;
name|bool
name|isFundamentalType
argument_list|()
specifier|const
block|;
name|bool
name|isCompoundType
argument_list|()
specifier|const
block|;
comment|// Type Predicates: Check to see if this type is structurally the specified
comment|// type, ignoring typedefs and qualifiers.
name|bool
name|isFunctionType
argument_list|()
specifier|const
block|;
name|bool
name|isFunctionNoProtoType
argument_list|()
specifier|const
block|{
return|return
name|getAs
operator|<
name|FunctionNoProtoType
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|isFunctionProtoType
argument_list|()
specifier|const
block|{
return|return
name|getAs
operator|<
name|FunctionProtoType
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|isPointerType
argument_list|()
specifier|const
block|;
name|bool
name|isAnyPointerType
argument_list|()
specifier|const
block|;
comment|// Any C pointer or ObjC object pointer
name|bool
name|isBlockPointerType
argument_list|()
specifier|const
block|;
name|bool
name|isVoidPointerType
argument_list|()
specifier|const
block|;
name|bool
name|isReferenceType
argument_list|()
specifier|const
block|;
name|bool
name|isLValueReferenceType
argument_list|()
specifier|const
block|;
name|bool
name|isRValueReferenceType
argument_list|()
specifier|const
block|;
name|bool
name|isFunctionPointerType
argument_list|()
specifier|const
block|;
name|bool
name|isMemberPointerType
argument_list|()
specifier|const
block|;
name|bool
name|isMemberFunctionPointerType
argument_list|()
specifier|const
block|;
name|bool
name|isMemberDataPointerType
argument_list|()
specifier|const
block|;
name|bool
name|isArrayType
argument_list|()
specifier|const
block|;
name|bool
name|isConstantArrayType
argument_list|()
specifier|const
block|;
name|bool
name|isIncompleteArrayType
argument_list|()
specifier|const
block|;
name|bool
name|isVariableArrayType
argument_list|()
specifier|const
block|;
name|bool
name|isDependentSizedArrayType
argument_list|()
specifier|const
block|;
name|bool
name|isRecordType
argument_list|()
specifier|const
block|;
name|bool
name|isClassType
argument_list|()
specifier|const
block|;
name|bool
name|isStructureType
argument_list|()
specifier|const
block|;
name|bool
name|isObjCBoxableRecordType
argument_list|()
specifier|const
block|;
name|bool
name|isInterfaceType
argument_list|()
specifier|const
block|;
name|bool
name|isStructureOrClassType
argument_list|()
specifier|const
block|;
name|bool
name|isUnionType
argument_list|()
specifier|const
block|;
name|bool
name|isComplexIntegerType
argument_list|()
specifier|const
block|;
comment|// GCC _Complex integer type.
name|bool
name|isVectorType
argument_list|()
specifier|const
block|;
comment|// GCC vector type.
name|bool
name|isExtVectorType
argument_list|()
specifier|const
block|;
comment|// Extended vector type.
name|bool
name|isObjCObjectPointerType
argument_list|()
specifier|const
block|;
comment|// pointer to ObjC object
name|bool
name|isObjCRetainableType
argument_list|()
specifier|const
block|;
comment|// ObjC object or block pointer
name|bool
name|isObjCLifetimeType
argument_list|()
specifier|const
block|;
comment|// (array of)* retainable type
name|bool
name|isObjCIndirectLifetimeType
argument_list|()
specifier|const
block|;
comment|// (pointer to)* lifetime type
name|bool
name|isObjCNSObjectType
argument_list|()
specifier|const
block|;
comment|// __attribute__((NSObject))
name|bool
name|isObjCIndependentClassType
argument_list|()
specifier|const
block|;
comment|// __attribute__((objc_independent_class))
comment|// FIXME: change this to 'raw' interface type, so we can used 'interface' type
comment|// for the common case.
name|bool
name|isObjCObjectType
argument_list|()
specifier|const
block|;
comment|// NSString or typeof(*(id)0)
name|bool
name|isObjCQualifiedInterfaceType
argument_list|()
specifier|const
block|;
comment|// NSString<foo>
name|bool
name|isObjCQualifiedIdType
argument_list|()
specifier|const
block|;
comment|// id<foo>
name|bool
name|isObjCQualifiedClassType
argument_list|()
specifier|const
block|;
comment|// Class<foo>
name|bool
name|isObjCObjectOrInterfaceType
argument_list|()
specifier|const
block|;
name|bool
name|isObjCIdType
argument_list|()
specifier|const
block|;
comment|// id
name|bool
name|isObjCInertUnsafeUnretainedType
argument_list|()
specifier|const
block|;
comment|/// Whether the type is Objective-C 'id' or a __kindof type of an
comment|/// object type, e.g., __kindof NSView * or __kindof id
comment|///<NSCopying>.
comment|///
comment|/// \param bound Will be set to the bound on non-id subtype types,
comment|/// which will be (possibly specialized) Objective-C class type, or
comment|/// null for 'id.
name|bool
name|isObjCIdOrObjectKindOfType
argument_list|(
argument|const ASTContext&ctx
argument_list|,
argument|const ObjCObjectType *&bound
argument_list|)
specifier|const
block|;
name|bool
name|isObjCClassType
argument_list|()
specifier|const
block|;
comment|// Class
comment|/// Whether the type is Objective-C 'Class' or a __kindof type of an
comment|/// Class type, e.g., __kindof Class<NSCopying>.
comment|///
comment|/// Unlike \c isObjCIdOrObjectKindOfType, there is no relevant bound
comment|/// here because Objective-C's type system cannot express "a class
comment|/// object for a subclass of NSFoo".
name|bool
name|isObjCClassOrClassKindOfType
argument_list|()
specifier|const
block|;
name|bool
name|isBlockCompatibleObjCPointerType
argument_list|(
argument|ASTContext&ctx
argument_list|)
specifier|const
block|;
name|bool
name|isObjCSelType
argument_list|()
specifier|const
block|;
comment|// Class
name|bool
name|isObjCBuiltinType
argument_list|()
specifier|const
block|;
comment|// 'id' or 'Class'
name|bool
name|isObjCARCBridgableType
argument_list|()
specifier|const
block|;
name|bool
name|isCARCBridgableType
argument_list|()
specifier|const
block|;
name|bool
name|isTemplateTypeParmType
argument_list|()
specifier|const
block|;
comment|// C++ template type parameter
name|bool
name|isNullPtrType
argument_list|()
specifier|const
block|;
comment|// C++11 std::nullptr_t
name|bool
name|isAlignValT
argument_list|()
specifier|const
block|;
comment|// C++17 std::align_val_t
name|bool
name|isAtomicType
argument_list|()
specifier|const
block|;
comment|// C11 _Atomic()
define|#
directive|define
name|IMAGE_TYPE
parameter_list|(
name|ImgType
parameter_list|,
name|Id
parameter_list|,
name|SingletonId
parameter_list|,
name|Access
parameter_list|,
name|Suffix
parameter_list|)
define|\
value|bool is##Id##Type() const;
include|#
directive|include
file|"clang/Basic/OpenCLImageTypes.def"
name|bool
name|isImageType
argument_list|()
specifier|const
block|;
comment|// Any OpenCL image type
name|bool
name|isSamplerT
argument_list|()
specifier|const
block|;
comment|// OpenCL sampler_t
name|bool
name|isEventT
argument_list|()
specifier|const
block|;
comment|// OpenCL event_t
name|bool
name|isClkEventT
argument_list|()
specifier|const
block|;
comment|// OpenCL clk_event_t
name|bool
name|isQueueT
argument_list|()
specifier|const
block|;
comment|// OpenCL queue_t
name|bool
name|isReserveIDT
argument_list|()
specifier|const
block|;
comment|// OpenCL reserve_id_t
name|bool
name|isPipeType
argument_list|()
specifier|const
block|;
comment|// OpenCL pipe type
name|bool
name|isOpenCLSpecificType
argument_list|()
specifier|const
block|;
comment|// Any OpenCL specific type
comment|/// Determines if this type, which must satisfy
comment|/// isObjCLifetimeType(), is implicitly __unsafe_unretained rather
comment|/// than implicitly __strong.
name|bool
name|isObjCARCImplicitlyUnretainedType
argument_list|()
specifier|const
block|;
comment|/// Return the implicit lifetime for this type, which must not be dependent.
name|Qualifiers
operator|::
name|ObjCLifetime
name|getObjCARCImplicitLifetime
argument_list|()
specifier|const
block|;    enum
name|ScalarTypeKind
block|{
name|STK_CPointer
block|,
name|STK_BlockPointer
block|,
name|STK_ObjCObjectPointer
block|,
name|STK_MemberPointer
block|,
name|STK_Bool
block|,
name|STK_Integral
block|,
name|STK_Floating
block|,
name|STK_IntegralComplex
block|,
name|STK_FloatingComplex
block|}
block|;
comment|/// Given that this is a scalar type, classify it.
name|ScalarTypeKind
name|getScalarTypeKind
argument_list|()
specifier|const
block|;
comment|/// Whether this type is a dependent type, meaning that its definition
comment|/// somehow depends on a template parameter (C++ [temp.dep.type]).
name|bool
name|isDependentType
argument_list|()
specifier|const
block|{
return|return
name|TypeBits
operator|.
name|Dependent
return|;
block|}
comment|/// \brief Determine whether this type is an instantiation-dependent type,
comment|/// meaning that the type involves a template parameter (even if the
comment|/// definition does not actually depend on the type substituted for that
comment|/// template parameter).
name|bool
name|isInstantiationDependentType
argument_list|()
specifier|const
block|{
return|return
name|TypeBits
operator|.
name|InstantiationDependent
return|;
block|}
comment|/// \brief Determine whether this type is an undeduced type, meaning that
comment|/// it somehow involves a C++11 'auto' type or similar which has not yet been
comment|/// deduced.
name|bool
name|isUndeducedType
argument_list|()
specifier|const
block|;
comment|/// \brief Whether this type is a variably-modified type (C99 6.7.5).
name|bool
name|isVariablyModifiedType
argument_list|()
specifier|const
block|{
return|return
name|TypeBits
operator|.
name|VariablyModified
return|;
block|}
comment|/// \brief Whether this type involves a variable-length array type
comment|/// with a definite size.
name|bool
name|hasSizedVLAType
argument_list|()
specifier|const
block|;
comment|/// \brief Whether this type is or contains a local or unnamed type.
name|bool
name|hasUnnamedOrLocalType
argument_list|()
specifier|const
block|;
name|bool
name|isOverloadableType
argument_list|()
specifier|const
block|;
comment|/// \brief Determine wither this type is a C++ elaborated-type-specifier.
name|bool
name|isElaboratedTypeSpecifier
argument_list|()
specifier|const
block|;
name|bool
name|canDecayToPointerType
argument_list|()
specifier|const
block|;
comment|/// Whether this type is represented natively as a pointer.  This includes
comment|/// pointers, references, block pointers, and Objective-C interface,
comment|/// qualified id, and qualified interface types, as well as nullptr_t.
name|bool
name|hasPointerRepresentation
argument_list|()
specifier|const
block|;
comment|/// Whether this type can represent an objective pointer type for the
comment|/// purpose of GC'ability
name|bool
name|hasObjCPointerRepresentation
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this type has an integer representation
comment|/// of some sort, e.g., it is an integer type or a vector.
name|bool
name|hasIntegerRepresentation
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this type has an signed integer representation
comment|/// of some sort, e.g., it is an signed integer type or a vector.
name|bool
name|hasSignedIntegerRepresentation
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this type has an unsigned integer representation
comment|/// of some sort, e.g., it is an unsigned integer type or a vector.
name|bool
name|hasUnsignedIntegerRepresentation
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this type has a floating-point representation
comment|/// of some sort, e.g., it is a floating-point type or a vector thereof.
name|bool
name|hasFloatingRepresentation
argument_list|()
specifier|const
block|;
comment|// Type Checking Functions: Check to see if this type is structurally the
comment|// specified type, ignoring typedefs and qualifiers, and return a pointer to
comment|// the best type we can.
specifier|const
name|RecordType
operator|*
name|getAsStructureType
argument_list|()
specifier|const
block|;
comment|/// NOTE: getAs*ArrayType are methods on ASTContext.
specifier|const
name|RecordType
operator|*
name|getAsUnionType
argument_list|()
specifier|const
block|;
specifier|const
name|ComplexType
operator|*
name|getAsComplexIntegerType
argument_list|()
specifier|const
block|;
comment|// GCC complex int type.
specifier|const
name|ObjCObjectType
operator|*
name|getAsObjCInterfaceType
argument_list|()
specifier|const
block|;
comment|// The following is a convenience method that returns an ObjCObjectPointerType
comment|// for object declared using an interface.
specifier|const
name|ObjCObjectPointerType
operator|*
name|getAsObjCInterfacePointerType
argument_list|()
specifier|const
block|;
specifier|const
name|ObjCObjectPointerType
operator|*
name|getAsObjCQualifiedIdType
argument_list|()
specifier|const
block|;
specifier|const
name|ObjCObjectPointerType
operator|*
name|getAsObjCQualifiedClassType
argument_list|()
specifier|const
block|;
specifier|const
name|ObjCObjectType
operator|*
name|getAsObjCQualifiedInterfaceType
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieves the CXXRecordDecl that this type refers to, either
comment|/// because the type is a RecordType or because it is the injected-class-name
comment|/// type of a class template or class template partial specialization.
name|CXXRecordDecl
operator|*
name|getAsCXXRecordDecl
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieves the TagDecl that this type refers to, either
comment|/// because the type is a TagType or because it is the injected-class-name
comment|/// type of a class template or class template partial specialization.
name|TagDecl
operator|*
name|getAsTagDecl
argument_list|()
specifier|const
block|;
comment|/// If this is a pointer or reference to a RecordType, return the
comment|/// CXXRecordDecl that that type refers to.
comment|///
comment|/// If this is not a pointer or reference, or the type being pointed to does
comment|/// not refer to a CXXRecordDecl, returns NULL.
specifier|const
name|CXXRecordDecl
operator|*
name|getPointeeCXXRecordDecl
argument_list|()
specifier|const
block|;
comment|/// Get the DeducedType whose type will be deduced for a variable with
comment|/// an initializer of this type. This looks through declarators like pointer
comment|/// types, but not through decltype or typedefs.
name|DeducedType
operator|*
name|getContainedDeducedType
argument_list|()
specifier|const
block|;
comment|/// Get the AutoType whose type will be deduced for a variable with
comment|/// an initializer of this type. This looks through declarators like pointer
comment|/// types, but not through decltype or typedefs.
name|AutoType
operator|*
name|getContainedAutoType
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|AutoType
operator|>
operator|(
name|getContainedDeducedType
argument_list|()
operator|)
return|;
block|}
comment|/// Determine whether this type was written with a leading 'auto'
comment|/// corresponding to a trailing return type (possibly for a nested
comment|/// function type within a pointer to function type or similar).
name|bool
name|hasAutoForTrailingReturnType
argument_list|()
specifier|const
block|;
comment|/// Member-template getAs<specific type>'.  Look through sugar for
comment|/// an instance of \<specific type>.   This scheme will eventually
comment|/// replace the specific getAsXXXX methods above.
comment|///
comment|/// There are some specializations of this member template listed
comment|/// immediately following this class.
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|getAs
argument_list|()
specifier|const
block|;
comment|/// Member-template getAsAdjusted<specific type>. Look through specific kinds
comment|/// of sugar (parens, attributes, etc) for an instance of \<specific type>.
comment|/// This is used when you need to walk over sugar nodes that represent some
comment|/// kind of type adjustment from a type that was written as a \<specific type>
comment|/// to another type that is still canonically a \<specific type>.
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|getAsAdjusted
argument_list|()
specifier|const
block|;
comment|/// A variant of getAs<> for array types which silently discards
comment|/// qualifiers from the outermost type.
specifier|const
name|ArrayType
operator|*
name|getAsArrayTypeUnsafe
argument_list|()
specifier|const
block|;
comment|/// Member-template castAs<specific type>.  Look through sugar for
comment|/// the underlying instance of \<specific type>.
comment|///
comment|/// This method has the same relationship to getAs<T> as cast<T> has
comment|/// to dyn_cast<T>; which is to say, the underlying type *must*
comment|/// have the intended type, and this method will never return null.
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|castAs
argument_list|()
specifier|const
block|;
comment|/// A variant of castAs<> for array type which silently discards
comment|/// qualifiers from the outermost type.
specifier|const
name|ArrayType
operator|*
name|castAsArrayTypeUnsafe
argument_list|()
specifier|const
block|;
comment|/// Get the base element type of this type, potentially discarding type
comment|/// qualifiers.  This should never be used when type qualifiers
comment|/// are meaningful.
specifier|const
name|Type
operator|*
name|getBaseElementTypeUnsafe
argument_list|()
specifier|const
block|;
comment|/// If this is an array type, return the element type of the array,
comment|/// potentially with type qualifiers missing.
comment|/// This should never be used when type qualifiers are meaningful.
specifier|const
name|Type
operator|*
name|getArrayElementTypeNoTypeQual
argument_list|()
specifier|const
block|;
comment|/// If this is a pointer type, return the pointee type.
comment|/// If this is an array type, return the array element type.
comment|/// This should never be used when type qualifiers are meaningful.
specifier|const
name|Type
operator|*
name|getPointeeOrArrayElementType
argument_list|()
specifier|const
block|;
comment|/// If this is a pointer, ObjC object pointer, or block
comment|/// pointer, this returns the respective pointee.
name|QualType
name|getPointeeType
argument_list|()
specifier|const
block|;
comment|/// Return the specified type with any "sugar" removed from the type,
comment|/// removing any typedefs, typeofs, etc., as well as any qualifiers.
specifier|const
name|Type
operator|*
name|getUnqualifiedDesugaredType
argument_list|()
specifier|const
block|;
comment|/// More type predicates useful for type checking/promotion
name|bool
name|isPromotableIntegerType
argument_list|()
specifier|const
block|;
comment|// C99 6.3.1.1p2
comment|/// Return true if this is an integer type that is
comment|/// signed, according to C99 6.2.5p4 [char, signed char, short, int, long..],
comment|/// or an enum decl which has a signed representation.
name|bool
name|isSignedIntegerType
argument_list|()
specifier|const
block|;
comment|/// Return true if this is an integer type that is
comment|/// unsigned, according to C99 6.2.5p6 [which returns true for _Bool],
comment|/// or an enum decl which has an unsigned representation.
name|bool
name|isUnsignedIntegerType
argument_list|()
specifier|const
block|;
comment|/// Determines whether this is an integer type that is signed or an
comment|/// enumeration types whose underlying type is a signed integer type.
name|bool
name|isSignedIntegerOrEnumerationType
argument_list|()
specifier|const
block|;
comment|/// Determines whether this is an integer type that is unsigned or an
comment|/// enumeration types whose underlying type is a unsigned integer type.
name|bool
name|isUnsignedIntegerOrEnumerationType
argument_list|()
specifier|const
block|;
comment|/// Return true if this is not a variable sized type,
comment|/// according to the rules of C99 6.7.5p3.  It is not legal to call this on
comment|/// incomplete types.
name|bool
name|isConstantSizeType
argument_list|()
specifier|const
block|;
comment|/// Returns true if this type can be represented by some
comment|/// set of type specifiers.
name|bool
name|isSpecifierType
argument_list|()
specifier|const
block|;
comment|/// Determine the linkage of this type.
name|Linkage
name|getLinkage
argument_list|()
specifier|const
block|;
comment|/// Determine the visibility of this type.
name|Visibility
name|getVisibility
argument_list|()
specifier|const
block|{
return|return
name|getLinkageAndVisibility
argument_list|()
operator|.
name|getVisibility
argument_list|()
return|;
block|}
comment|/// Return true if the visibility was explicitly set is the code.
name|bool
name|isVisibilityExplicit
argument_list|()
specifier|const
block|{
return|return
name|getLinkageAndVisibility
argument_list|()
operator|.
name|isVisibilityExplicit
argument_list|()
return|;
block|}
comment|/// Determine the linkage and visibility of this type.
name|LinkageInfo
name|getLinkageAndVisibility
argument_list|()
specifier|const
block|;
comment|/// True if the computed linkage is valid. Used for consistency
comment|/// checking. Should always return true.
name|bool
name|isLinkageValid
argument_list|()
specifier|const
block|;
comment|/// Determine the nullability of the given type.
comment|///
comment|/// Note that nullability is only captured as sugar within the type
comment|/// system, not as part of the canonical type, so nullability will
comment|/// be lost by canonicalization and desugaring.
name|Optional
operator|<
name|NullabilityKind
operator|>
name|getNullability
argument_list|(
argument|const ASTContext&context
argument_list|)
specifier|const
block|;
comment|/// Determine whether the given type can have a nullability
comment|/// specifier applied to it, i.e., if it is any kind of pointer type
comment|/// or a dependent type that could instantiate to any kind of
comment|/// pointer type.
name|bool
name|canHaveNullability
argument_list|()
specifier|const
block|;
comment|/// Retrieve the set of substitutions required when accessing a member
comment|/// of the Objective-C receiver type that is declared in the given context.
comment|///
comment|/// \c *this is the type of the object we're operating on, e.g., the
comment|/// receiver for a message send or the base of a property access, and is
comment|/// expected to be of some object or object pointer type.
comment|///
comment|/// \param dc The declaration context for which we are building up a
comment|/// substitution mapping, which should be an Objective-C class, extension,
comment|/// category, or method within.
comment|///
comment|/// \returns an array of type arguments that can be substituted for
comment|/// the type parameters of the given declaration context in any type described
comment|/// within that context, or an empty optional to indicate that no
comment|/// substitution is required.
name|Optional
operator|<
name|ArrayRef
operator|<
name|QualType
operator|>>
name|getObjCSubstitutions
argument_list|(
argument|const DeclContext *dc
argument_list|)
specifier|const
block|;
comment|/// Determines if this is an ObjC interface type that may accept type
comment|/// parameters.
name|bool
name|acceptsObjCTypeParams
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|getTypeClassName
argument_list|()
specifier|const
block|;
name|QualType
name|getCanonicalTypeInternal
argument_list|()
specifier|const
block|{
return|return
name|CanonicalType
return|;
block|}
name|CanQualType
name|getCanonicalTypeUnqualified
argument_list|()
specifier|const
block|;
comment|// in CanonicalType.h
name|void
name|dump
argument_list|()
specifier|const
block|;
name|void
name|dump
argument_list|(
argument|llvm::raw_ostream&OS
argument_list|)
specifier|const
block|;
name|friend
name|class
name|ASTReader
block|;
name|friend
name|class
name|ASTWriter
block|; }
block|;
comment|/// \brief This will check for a TypedefType by removing any existing sugar
comment|/// until it reaches a TypedefType or a non-sugared type.
name|template
operator|<
operator|>
specifier|const
name|TypedefType
operator|*
name|Type
operator|::
name|getAs
argument_list|()
specifier|const
block|;
comment|/// \brief This will check for a TemplateSpecializationType by removing any
comment|/// existing sugar until it reaches a TemplateSpecializationType or a
comment|/// non-sugared type.
name|template
operator|<
operator|>
specifier|const
name|TemplateSpecializationType
operator|*
name|Type
operator|::
name|getAs
argument_list|()
specifier|const
block|;
comment|/// \brief This will check for an AttributedType by removing any existing sugar
comment|/// until it reaches an AttributedType or a non-sugared type.
name|template
operator|<
operator|>
specifier|const
name|AttributedType
operator|*
name|Type
operator|::
name|getAs
argument_list|()
specifier|const
block|;
comment|// We can do canonical leaf types faster, because we don't have to
comment|// worry about preserving child type decoration.
define|#
directive|define
name|TYPE
parameter_list|(
name|Class
parameter_list|,
name|Base
parameter_list|)
define|#
directive|define
name|LEAF_TYPE
parameter_list|(
name|Class
parameter_list|)
define|\
value|template<> inline const Class##Type *Type::getAs() const { \   return dyn_cast<Class##Type>(CanonicalType); \ } \ template<> inline const Class##Type *Type::castAs() const { \   return cast<Class##Type>(CanonicalType); \ }
include|#
directive|include
file|"clang/AST/TypeNodes.def"
comment|/// This class is used for builtin types like 'int'.  Builtin
comment|/// types are always canonical and have a literal name field.
name|class
name|BuiltinType
operator|:
name|public
name|Type
block|{
name|public
operator|:
expr|enum
name|Kind
block|{
comment|// OpenCL image types
define|#
directive|define
name|IMAGE_TYPE
parameter_list|(
name|ImgType
parameter_list|,
name|Id
parameter_list|,
name|SingletonId
parameter_list|,
name|Access
parameter_list|,
name|Suffix
parameter_list|)
value|Id,
include|#
directive|include
file|"clang/Basic/OpenCLImageTypes.def"
comment|// All other builtin types
define|#
directive|define
name|BUILTIN_TYPE
parameter_list|(
name|Id
parameter_list|,
name|SingletonId
parameter_list|)
value|Id,
define|#
directive|define
name|LAST_BUILTIN_TYPE
parameter_list|(
name|Id
parameter_list|)
value|LastKind = Id
include|#
directive|include
file|"clang/AST/BuiltinTypes.def"
block|}
block|;
name|public
operator|:
name|BuiltinType
argument_list|(
argument|Kind K
argument_list|)
operator|:
name|Type
argument_list|(
argument|Builtin
argument_list|,
argument|QualType()
argument_list|,
comment|/*Dependent=*/
argument|(K == Dependent)
argument_list|,
comment|/*InstantiationDependent=*/
argument|(K == Dependent)
argument_list|,
comment|/*VariablyModified=*/
argument|false
argument_list|,
comment|/*Unexpanded parameter pack=*/
argument|false
argument_list|)
block|{
name|BuiltinTypeBits
operator|.
name|Kind
operator|=
name|K
block|;   }
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Kind
operator|>
operator|(
name|BuiltinTypeBits
operator|.
name|Kind
operator|)
return|;
block|}
name|StringRef
name|getName
argument_list|(
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
block|;
specifier|const
name|char
operator|*
name|getNameAsCString
argument_list|(
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
block|{
comment|// The StringRef is null-terminated.
name|StringRef
name|str
operator|=
name|getName
argument_list|(
name|Policy
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|str
operator|.
name|empty
argument_list|()
operator|&&
name|str
operator|.
name|data
argument_list|()
index|[
name|str
operator|.
name|size
argument_list|()
index|]
operator|==
literal|'\0'
argument_list|)
block|;
return|return
name|str
operator|.
name|data
argument_list|()
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|bool
name|isInteger
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|>=
name|Bool
operator|&&
name|getKind
argument_list|()
operator|<=
name|Int128
return|;
block|}
name|bool
name|isSignedInteger
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|>=
name|Char_S
operator|&&
name|getKind
argument_list|()
operator|<=
name|Int128
return|;
block|}
name|bool
name|isUnsignedInteger
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|>=
name|Bool
operator|&&
name|getKind
argument_list|()
operator|<=
name|UInt128
return|;
block|}
name|bool
name|isFloatingPoint
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|>=
name|Half
operator|&&
name|getKind
argument_list|()
operator|<=
name|Float128
return|;
block|}
comment|/// Determines whether the given kind corresponds to a placeholder type.
specifier|static
name|bool
name|isPlaceholderTypeKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|>=
name|Overload
return|;
block|}
comment|/// Determines whether this type is a placeholder type, i.e. a type
comment|/// which cannot appear in arbitrary positions in a fully-formed
comment|/// expression.
name|bool
name|isPlaceholderType
argument_list|()
specifier|const
block|{
return|return
name|isPlaceholderTypeKind
argument_list|(
name|getKind
argument_list|()
argument_list|)
return|;
block|}
comment|/// Determines whether this type is a placeholder type other than
comment|/// Overload.  Most placeholder types require only syntactic
comment|/// information about their context in order to be resolved (e.g.
comment|/// whether it is a call expression), which means they can (and
comment|/// should) be resolved in an earlier "phase" of analysis.
comment|/// Overload expressions sometimes pick up further information
comment|/// from their context, like whether the context expects a
comment|/// specific function-pointer type, and so frequently need
comment|/// special treatment.
name|bool
name|isNonOverloadPlaceholderType
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|>
name|Overload
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Builtin
return|;
block|}
expr|}
block|;
comment|/// Complex values, per C99 6.2.5p11.  This supports the C99 complex
comment|/// types (_Complex float etc) as well as the GCC integer complex extensions.
comment|///
name|class
name|ComplexType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|ElementType
block|;
name|ComplexType
argument_list|(
argument|QualType Element
argument_list|,
argument|QualType CanonicalPtr
argument_list|)
operator|:
name|Type
argument_list|(
name|Complex
argument_list|,
name|CanonicalPtr
argument_list|,
name|Element
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Element
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|Element
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|Element
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|ElementType
argument_list|(
argument|Element
argument_list|)
block|{   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|ElementType
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getElementType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Element
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Element
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Complex
return|;
block|}
expr|}
block|;
comment|/// Sugar for parentheses used when specifying types.
comment|///
name|class
name|ParenType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|Inner
block|;
name|ParenType
argument_list|(
argument|QualType InnerType
argument_list|,
argument|QualType CanonType
argument_list|)
operator|:
name|Type
argument_list|(
name|Paren
argument_list|,
name|CanonType
argument_list|,
name|InnerType
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|InnerType
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|InnerType
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|InnerType
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Inner
argument_list|(
argument|InnerType
argument_list|)
block|{   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getInnerType
argument_list|()
specifier|const
block|{
return|return
name|Inner
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|getInnerType
argument_list|()
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getInnerType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Inner
argument_list|)
block|{
name|Inner
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Paren
return|;
block|}
expr|}
block|;
comment|/// PointerType - C99 6.7.5.1 - Pointer Declarators.
comment|///
name|class
name|PointerType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|PointeeType
block|;
name|PointerType
argument_list|(
argument|QualType Pointee
argument_list|,
argument|QualType CanonicalPtr
argument_list|)
operator|:
name|Type
argument_list|(
name|Pointer
argument_list|,
name|CanonicalPtr
argument_list|,
name|Pointee
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|PointeeType
argument_list|(
argument|Pointee
argument_list|)
block|{   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getPointeeType
argument_list|()
specifier|const
block|{
return|return
name|PointeeType
return|;
block|}
comment|/// Returns true if address spaces of pointers overlap.
comment|/// OpenCL v2.0 defines conversion rules for pointers to different
comment|/// address spaces (OpenCLC v2.0 s6.5.5) and notion of overlapping
comment|/// address spaces.
comment|/// CL1.1 or CL1.2:
comment|///   address spaces overlap iff they are they same.
comment|/// CL2.0 adds:
comment|///   __generic overlaps with any address space except for __constant.
name|bool
name|isAddressSpaceOverlapping
argument_list|(
argument|const PointerType&other
argument_list|)
specifier|const
block|{
name|Qualifiers
name|thisQuals
operator|=
name|PointeeType
operator|.
name|getQualifiers
argument_list|()
block|;
name|Qualifiers
name|otherQuals
operator|=
name|other
operator|.
name|getPointeeType
argument_list|()
operator|.
name|getQualifiers
argument_list|()
block|;
comment|// Address spaces overlap if at least one of them is a superset of another
return|return
name|thisQuals
operator|.
name|isAddressSpaceSupersetOf
argument_list|(
name|otherQuals
argument_list|)
operator|||
name|otherQuals
operator|.
name|isAddressSpaceSupersetOf
argument_list|(
name|thisQuals
argument_list|)
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getPointeeType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Pointee
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Pointee
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Pointer
return|;
block|}
expr|}
block|;
comment|/// Represents a type which was implicitly adjusted by the semantic
comment|/// engine for arbitrary reasons.  For example, array and function types can
comment|/// decay, and function types can have their calling conventions adjusted.
name|class
name|AdjustedType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|OriginalTy
block|;
name|QualType
name|AdjustedTy
block|;
name|protected
operator|:
name|AdjustedType
argument_list|(
argument|TypeClass TC
argument_list|,
argument|QualType OriginalTy
argument_list|,
argument|QualType AdjustedTy
argument_list|,
argument|QualType CanonicalPtr
argument_list|)
operator|:
name|Type
argument_list|(
name|TC
argument_list|,
name|CanonicalPtr
argument_list|,
name|OriginalTy
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|OriginalTy
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|OriginalTy
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|OriginalTy
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|OriginalTy
argument_list|(
name|OriginalTy
argument_list|)
block|,
name|AdjustedTy
argument_list|(
argument|AdjustedTy
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getOriginalType
argument_list|()
specifier|const
block|{
return|return
name|OriginalTy
return|;
block|}
name|QualType
name|getAdjustedType
argument_list|()
specifier|const
block|{
return|return
name|AdjustedTy
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|AdjustedTy
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|OriginalTy
argument_list|,
name|AdjustedTy
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Orig
argument_list|,
argument|QualType New
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Orig
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|New
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Adjusted
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Decayed
return|;
block|}
expr|}
block|;
comment|/// Represents a pointer type decayed from an array or function type.
name|class
name|DecayedType
operator|:
name|public
name|AdjustedType
block|{
specifier|inline
name|DecayedType
argument_list|(
argument|QualType OriginalType
argument_list|,
argument|QualType Decayed
argument_list|,
argument|QualType Canonical
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getDecayedType
argument_list|()
specifier|const
block|{
return|return
name|getAdjustedType
argument_list|()
return|;
block|}
specifier|inline
name|QualType
name|getPointeeType
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Decayed
return|;
block|}
expr|}
block|;
comment|/// Pointer to a block type.
comment|/// This type is to represent types syntactically represented as
comment|/// "void (^)(int)", etc. Pointee is required to always be a function type.
comment|///
name|class
name|BlockPointerType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|PointeeType
block|;
comment|// Block is some kind of pointer type
name|BlockPointerType
argument_list|(
argument|QualType Pointee
argument_list|,
argument|QualType CanonicalCls
argument_list|)
operator|:
name|Type
argument_list|(
name|BlockPointer
argument_list|,
name|CanonicalCls
argument_list|,
name|Pointee
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|PointeeType
argument_list|(
argument|Pointee
argument_list|)
block|{   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
comment|// Get the pointee type. Pointee is required to always be a function type.
name|QualType
name|getPointeeType
argument_list|()
specifier|const
block|{
return|return
name|PointeeType
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getPointeeType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Pointee
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Pointee
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|BlockPointer
return|;
block|}
expr|}
block|;
comment|/// Base for LValueReferenceType and RValueReferenceType
comment|///
name|class
name|ReferenceType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|PointeeType
block|;
name|protected
operator|:
name|ReferenceType
argument_list|(
argument|TypeClass tc
argument_list|,
argument|QualType Referencee
argument_list|,
argument|QualType CanonicalRef
argument_list|,
argument|bool SpelledAsLValue
argument_list|)
operator|:
name|Type
argument_list|(
name|tc
argument_list|,
name|CanonicalRef
argument_list|,
name|Referencee
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Referencee
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|Referencee
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|Referencee
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|PointeeType
argument_list|(
argument|Referencee
argument_list|)
block|{
name|ReferenceTypeBits
operator|.
name|SpelledAsLValue
operator|=
name|SpelledAsLValue
block|;
name|ReferenceTypeBits
operator|.
name|InnerRef
operator|=
name|Referencee
operator|->
name|isReferenceType
argument_list|()
block|;   }
name|public
operator|:
name|bool
name|isSpelledAsLValue
argument_list|()
specifier|const
block|{
return|return
name|ReferenceTypeBits
operator|.
name|SpelledAsLValue
return|;
block|}
name|bool
name|isInnerRef
argument_list|()
specifier|const
block|{
return|return
name|ReferenceTypeBits
operator|.
name|InnerRef
return|;
block|}
name|QualType
name|getPointeeTypeAsWritten
argument_list|()
specifier|const
block|{
return|return
name|PointeeType
return|;
block|}
name|QualType
name|getPointeeType
argument_list|()
specifier|const
block|{
comment|// FIXME: this might strip inner qualifiers; okay?
specifier|const
name|ReferenceType
operator|*
name|T
operator|=
name|this
block|;
while|while
condition|(
name|T
operator|->
name|isInnerRef
argument_list|()
condition|)
name|T
operator|=
name|T
operator|->
name|PointeeType
operator|->
name|castAs
operator|<
name|ReferenceType
operator|>
operator|(
operator|)
expr_stmt|;
return|return
name|T
operator|->
name|PointeeType
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|PointeeType
argument_list|,
name|isSpelledAsLValue
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Referencee
argument_list|,
argument|bool SpelledAsLValue
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Referencee
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|SpelledAsLValue
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|LValueReference
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|RValueReference
return|;
block|}
expr|}
block|;
comment|/// An lvalue reference type, per C++11 [dcl.ref].
comment|///
name|class
name|LValueReferenceType
operator|:
name|public
name|ReferenceType
block|{
name|LValueReferenceType
argument_list|(
argument|QualType Referencee
argument_list|,
argument|QualType CanonicalRef
argument_list|,
argument|bool SpelledAsLValue
argument_list|)
operator|:
name|ReferenceType
argument_list|(
argument|LValueReference
argument_list|,
argument|Referencee
argument_list|,
argument|CanonicalRef
argument_list|,
argument|SpelledAsLValue
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|LValueReference
return|;
block|}
expr|}
block|;
comment|/// An rvalue reference type, per C++11 [dcl.ref].
comment|///
name|class
name|RValueReferenceType
operator|:
name|public
name|ReferenceType
block|{
name|RValueReferenceType
argument_list|(
argument|QualType Referencee
argument_list|,
argument|QualType CanonicalRef
argument_list|)
operator|:
name|ReferenceType
argument_list|(
argument|RValueReference
argument_list|,
argument|Referencee
argument_list|,
argument|CanonicalRef
argument_list|,
argument|false
argument_list|)
block|{   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|RValueReference
return|;
block|}
expr|}
block|;
comment|/// A pointer to member type per C++ 8.3.3 - Pointers to members.
comment|///
comment|/// This includes both pointers to data members and pointer to member functions.
comment|///
name|class
name|MemberPointerType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|PointeeType
block|;
comment|/// The class of which the pointee is a member. Must ultimately be a
comment|/// RecordType, but could be a typedef or a template parameter too.
specifier|const
name|Type
operator|*
name|Class
block|;
name|MemberPointerType
argument_list|(
argument|QualType Pointee
argument_list|,
argument|const Type *Cls
argument_list|,
argument|QualType CanonicalPtr
argument_list|)
operator|:
name|Type
argument_list|(
name|MemberPointer
argument_list|,
name|CanonicalPtr
argument_list|,
name|Cls
operator|->
name|isDependentType
argument_list|()
operator|||
name|Pointee
operator|->
name|isDependentType
argument_list|()
argument_list|,
operator|(
name|Cls
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
name|Pointee
operator|->
name|isInstantiationDependentType
argument_list|()
operator|)
argument_list|,
name|Pointee
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
operator|(
name|Cls
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|Pointee
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
block|,
name|PointeeType
argument_list|(
name|Pointee
argument_list|)
block|,
name|Class
argument_list|(
argument|Cls
argument_list|)
block|{   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getPointeeType
argument_list|()
specifier|const
block|{
return|return
name|PointeeType
return|;
block|}
comment|/// Returns true if the member type (i.e. the pointee type) is a
comment|/// function type rather than a data-member type.
name|bool
name|isMemberFunctionPointer
argument_list|()
specifier|const
block|{
return|return
name|PointeeType
operator|->
name|isFunctionProtoType
argument_list|()
return|;
block|}
comment|/// Returns true if the member type (i.e. the pointee type) is a
comment|/// data type rather than a function type.
name|bool
name|isMemberDataPointer
argument_list|()
specifier|const
block|{
return|return
operator|!
name|PointeeType
operator|->
name|isFunctionProtoType
argument_list|()
return|;
block|}
specifier|const
name|Type
operator|*
name|getClass
argument_list|()
specifier|const
block|{
return|return
name|Class
return|;
block|}
name|CXXRecordDecl
operator|*
name|getMostRecentCXXRecordDecl
argument_list|()
specifier|const
block|;
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getPointeeType
argument_list|()
argument_list|,
name|getClass
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Pointee
argument_list|,
argument|const Type *Class
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Pointee
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|Class
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|MemberPointer
return|;
block|}
expr|}
block|;
comment|/// Represents an array type, per C99 6.7.5.2 - Array Declarators.
comment|///
name|class
name|ArrayType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|public
operator|:
comment|/// Capture whether this is a normal array (e.g. int X[4])
comment|/// an array with a static size (e.g. int X[static 4]), or an array
comment|/// with a star size (e.g. int X[*]).
comment|/// 'static' is only allowed on function parameters.
expr|enum
name|ArraySizeModifier
block|{
name|Normal
block|,
name|Static
block|,
name|Star
block|}
block|;
name|private
operator|:
comment|/// The element type of the array.
name|QualType
name|ElementType
block|;
name|protected
operator|:
comment|// C++ [temp.dep.type]p1:
comment|//   A type is dependent if it is...
comment|//     - an array type constructed from any dependent type or whose
comment|//       size is specified by a constant expression that is
comment|//       value-dependent,
name|ArrayType
argument_list|(
argument|TypeClass tc
argument_list|,
argument|QualType et
argument_list|,
argument|QualType can
argument_list|,
argument|ArraySizeModifier sm
argument_list|,
argument|unsigned tq
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|)
operator|:
name|Type
argument_list|(
name|tc
argument_list|,
name|can
argument_list|,
name|et
operator|->
name|isDependentType
argument_list|()
operator|||
name|tc
operator|==
name|DependentSizedArray
argument_list|,
name|et
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
name|tc
operator|==
name|DependentSizedArray
argument_list|,
operator|(
name|tc
operator|==
name|VariableArray
operator|||
name|et
operator|->
name|isVariablyModifiedType
argument_list|()
operator|)
argument_list|,
name|ContainsUnexpandedParameterPack
argument_list|)
block|,
name|ElementType
argument_list|(
argument|et
argument_list|)
block|{
name|ArrayTypeBits
operator|.
name|IndexTypeQuals
operator|=
name|tq
block|;
name|ArrayTypeBits
operator|.
name|SizeModifier
operator|=
name|sm
block|;   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|ElementType
return|;
block|}
name|ArraySizeModifier
name|getSizeModifier
argument_list|()
specifier|const
block|{
return|return
name|ArraySizeModifier
argument_list|(
name|ArrayTypeBits
operator|.
name|SizeModifier
argument_list|)
return|;
block|}
name|Qualifiers
name|getIndexTypeQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Qualifiers
operator|::
name|fromCVRMask
argument_list|(
name|getIndexTypeCVRQualifiers
argument_list|()
argument_list|)
return|;
block|}
name|unsigned
name|getIndexTypeCVRQualifiers
argument_list|()
specifier|const
block|{
return|return
name|ArrayTypeBits
operator|.
name|IndexTypeQuals
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ConstantArray
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|VariableArray
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|IncompleteArray
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|DependentSizedArray
return|;
block|}
expr|}
block|;
comment|/// Represents the canonical version of C arrays with a specified constant size.
comment|/// For example, the canonical type for 'int A[4 + 4*100]' is a
comment|/// ConstantArrayType where the element type is 'int' and the size is 404.
name|class
name|ConstantArrayType
operator|:
name|public
name|ArrayType
block|{
name|llvm
operator|::
name|APInt
name|Size
block|;
comment|// Allows us to unique the type.
name|ConstantArrayType
argument_list|(
argument|QualType et
argument_list|,
argument|QualType can
argument_list|,
argument|const llvm::APInt&size
argument_list|,
argument|ArraySizeModifier sm
argument_list|,
argument|unsigned tq
argument_list|)
operator|:
name|ArrayType
argument_list|(
name|ConstantArray
argument_list|,
name|et
argument_list|,
name|can
argument_list|,
name|sm
argument_list|,
name|tq
argument_list|,
name|et
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Size
argument_list|(
argument|size
argument_list|)
block|{}
name|protected
operator|:
name|ConstantArrayType
argument_list|(
argument|TypeClass tc
argument_list|,
argument|QualType et
argument_list|,
argument|QualType can
argument_list|,
argument|const llvm::APInt&size
argument_list|,
argument|ArraySizeModifier sm
argument_list|,
argument|unsigned tq
argument_list|)
operator|:
name|ArrayType
argument_list|(
name|tc
argument_list|,
name|et
argument_list|,
name|can
argument_list|,
name|sm
argument_list|,
name|tq
argument_list|,
name|et
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Size
argument_list|(
argument|size
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
specifier|const
name|llvm
operator|::
name|APInt
operator|&
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// \brief Determine the number of bits required to address a member of
comment|// an array with the given element type and number of elements.
specifier|static
name|unsigned
name|getNumAddressingBits
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|QualType ElementType
argument_list|,
argument|const llvm::APInt&NumElements
argument_list|)
block|;
comment|/// \brief Determine the maximum number of active bits that an array's size
comment|/// can require, which limits the maximum size of the array.
specifier|static
name|unsigned
name|getMaxSizeBits
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getElementType
argument_list|()
argument_list|,
name|getSize
argument_list|()
argument_list|,
name|getSizeModifier
argument_list|()
argument_list|,
name|getIndexTypeCVRQualifiers
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType ET
argument_list|,
argument|const llvm::APInt&ArraySize
argument_list|,
argument|ArraySizeModifier SizeMod
argument_list|,
argument|unsigned TypeQuals
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|ET
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|ArraySize
operator|.
name|getZExtValue
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|SizeMod
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|TypeQuals
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ConstantArray
return|;
block|}
expr|}
block|;
comment|/// Represents a C array with an unspecified size.  For example 'int A[]' has
comment|/// an IncompleteArrayType where the element type is 'int' and the size is
comment|/// unspecified.
name|class
name|IncompleteArrayType
operator|:
name|public
name|ArrayType
block|{
name|IncompleteArrayType
argument_list|(
argument|QualType et
argument_list|,
argument|QualType can
argument_list|,
argument|ArraySizeModifier sm
argument_list|,
argument|unsigned tq
argument_list|)
operator|:
name|ArrayType
argument_list|(
argument|IncompleteArray
argument_list|,
argument|et
argument_list|,
argument|can
argument_list|,
argument|sm
argument_list|,
argument|tq
argument_list|,
argument|et->containsUnexpandedParameterPack()
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|IncompleteArray
return|;
block|}
name|friend
name|class
name|StmtIteratorBase
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getElementType
argument_list|()
argument_list|,
name|getSizeModifier
argument_list|()
argument_list|,
name|getIndexTypeCVRQualifiers
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType ET
argument_list|,
argument|ArraySizeModifier SizeMod
argument_list|,
argument|unsigned TypeQuals
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|ET
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|SizeMod
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|TypeQuals
argument_list|)
block|;   }
block|}
block|;
comment|/// Represents a C array with a specified size that is not an
comment|/// integer-constant-expression.  For example, 'int s[x+foo()]'.
comment|/// Since the size expression is an arbitrary expression, we store it as such.
comment|///
comment|/// Note: VariableArrayType's aren't uniqued (since the expressions aren't) and
comment|/// should not be: two lexically equivalent variable array types could mean
comment|/// different things, for example, these variables do not have the same type
comment|/// dynamically:
comment|///
comment|/// void foo(int x) {
comment|///   int Y[x];
comment|///   ++x;
comment|///   int Z[x];
comment|/// }
comment|///
name|class
name|VariableArrayType
operator|:
name|public
name|ArrayType
block|{
comment|/// An assignment-expression. VLA's are only permitted within
comment|/// a function block.
name|Stmt
operator|*
name|SizeExpr
block|;
comment|/// The range spanned by the left and right array brackets.
name|SourceRange
name|Brackets
block|;
name|VariableArrayType
argument_list|(
argument|QualType et
argument_list|,
argument|QualType can
argument_list|,
argument|Expr *e
argument_list|,
argument|ArraySizeModifier sm
argument_list|,
argument|unsigned tq
argument_list|,
argument|SourceRange brackets
argument_list|)
operator|:
name|ArrayType
argument_list|(
name|VariableArray
argument_list|,
name|et
argument_list|,
name|can
argument_list|,
name|sm
argument_list|,
name|tq
argument_list|,
name|et
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|SizeExpr
argument_list|(
operator|(
name|Stmt
operator|*
operator|)
name|e
argument_list|)
block|,
name|Brackets
argument_list|(
argument|brackets
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|Expr
operator|*
name|getSizeExpr
argument_list|()
specifier|const
block|{
comment|// We use C-style casts instead of cast<> here because we do not wish
comment|// to have a dependency of Type.h on Stmt.h/Expr.h.
return|return
operator|(
name|Expr
operator|*
operator|)
name|SizeExpr
return|;
block|}
name|SourceRange
name|getBracketsRange
argument_list|()
specifier|const
block|{
return|return
name|Brackets
return|;
block|}
name|SourceLocation
name|getLBracketLoc
argument_list|()
specifier|const
block|{
return|return
name|Brackets
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getRBracketLoc
argument_list|()
specifier|const
block|{
return|return
name|Brackets
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|VariableArray
return|;
block|}
name|friend
name|class
name|StmtIteratorBase
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Cannot unique VariableArrayTypes."
argument_list|)
block|;   }
block|}
block|;
comment|/// Represents an array type in C++ whose size is a value-dependent expression.
comment|///
comment|/// For example:
comment|/// \code
comment|/// template<typename T, int Size>
comment|/// class array {
comment|///   T data[Size];
comment|/// };
comment|/// \endcode
comment|///
comment|/// For these types, we won't actually know what the array bound is
comment|/// until template instantiation occurs, at which point this will
comment|/// become either a ConstantArrayType or a VariableArrayType.
name|class
name|DependentSizedArrayType
operator|:
name|public
name|ArrayType
block|{
specifier|const
name|ASTContext
operator|&
name|Context
block|;
comment|/// \brief An assignment expression that will instantiate to the
comment|/// size of the array.
comment|///
comment|/// The expression itself might be null, in which case the array
comment|/// type will have its size deduced from an initializer.
name|Stmt
operator|*
name|SizeExpr
block|;
comment|/// The range spanned by the left and right array brackets.
name|SourceRange
name|Brackets
block|;
name|DependentSizedArrayType
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|QualType et
argument_list|,
argument|QualType can
argument_list|,
argument|Expr *e
argument_list|,
argument|ArraySizeModifier sm
argument_list|,
argument|unsigned tq
argument_list|,
argument|SourceRange brackets
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|Expr
operator|*
name|getSizeExpr
argument_list|()
specifier|const
block|{
comment|// We use C-style casts instead of cast<> here because we do not wish
comment|// to have a dependency of Type.h on Stmt.h/Expr.h.
return|return
operator|(
name|Expr
operator|*
operator|)
name|SizeExpr
return|;
block|}
name|SourceRange
name|getBracketsRange
argument_list|()
specifier|const
block|{
return|return
name|Brackets
return|;
block|}
name|SourceLocation
name|getLBracketLoc
argument_list|()
specifier|const
block|{
return|return
name|Brackets
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getRBracketLoc
argument_list|()
specifier|const
block|{
return|return
name|Brackets
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|DependentSizedArray
return|;
block|}
name|friend
name|class
name|StmtIteratorBase
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|,
name|getElementType
argument_list|()
argument_list|,
name|getSizeModifier
argument_list|()
argument_list|,
name|getIndexTypeCVRQualifiers
argument_list|()
argument_list|,
name|getSizeExpr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|const ASTContext&Context
argument_list|,
argument|QualType ET
argument_list|,
argument|ArraySizeModifier SizeMod
argument_list|,
argument|unsigned TypeQuals
argument_list|,
argument|Expr *E
argument_list|)
block|; }
block|;
comment|/// Represents an extended vector type where either the type or size is
comment|/// dependent.
comment|///
comment|/// For example:
comment|/// \code
comment|/// template<typename T, int Size>
comment|/// class vector {
comment|///   typedef T __attribute__((ext_vector_type(Size))) type;
comment|/// }
comment|/// \endcode
name|class
name|DependentSizedExtVectorType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
specifier|const
name|ASTContext
operator|&
name|Context
block|;
name|Expr
operator|*
name|SizeExpr
block|;
comment|/// The element type of the array.
name|QualType
name|ElementType
block|;
name|SourceLocation
name|loc
block|;
name|DependentSizedExtVectorType
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|QualType ElementType
argument_list|,
argument|QualType can
argument_list|,
argument|Expr *SizeExpr
argument_list|,
argument|SourceLocation loc
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
name|public
operator|:
name|Expr
operator|*
name|getSizeExpr
argument_list|()
specifier|const
block|{
return|return
name|SizeExpr
return|;
block|}
name|QualType
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|ElementType
return|;
block|}
name|SourceLocation
name|getAttributeLoc
argument_list|()
specifier|const
block|{
return|return
name|loc
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|DependentSizedExtVector
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|,
name|getElementType
argument_list|()
argument_list|,
name|getSizeExpr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|const ASTContext&Context
argument_list|,
argument|QualType ElementType
argument_list|,
argument|Expr *SizeExpr
argument_list|)
block|; }
block|;
comment|/// Represents a GCC generic vector type. This type is created using
comment|/// __attribute__((vector_size(n)), where "n" specifies the vector size in
comment|/// bytes; or from an Altivec __vector or vector declaration.
comment|/// Since the constructor takes the number of vector elements, the
comment|/// client is responsible for converting the size into the number of elements.
name|class
name|VectorType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|public
operator|:
expr|enum
name|VectorKind
block|{
name|GenericVector
block|,
comment|///< not a target-specific vector type
name|AltiVecVector
block|,
comment|///< is AltiVec vector
name|AltiVecPixel
block|,
comment|///< is AltiVec 'vector Pixel'
name|AltiVecBool
block|,
comment|///< is AltiVec 'vector bool ...'
name|NeonVector
block|,
comment|///< is ARM Neon vector
name|NeonPolyVector
comment|///< is ARM Neon polynomial vector
block|}
block|;
name|protected
operator|:
comment|/// The element type of the vector.
name|QualType
name|ElementType
block|;
name|VectorType
argument_list|(
argument|QualType vecType
argument_list|,
argument|unsigned nElements
argument_list|,
argument|QualType canonType
argument_list|,
argument|VectorKind vecKind
argument_list|)
block|;
name|VectorType
argument_list|(
argument|TypeClass tc
argument_list|,
argument|QualType vecType
argument_list|,
argument|unsigned nElements
argument_list|,
argument|QualType canonType
argument_list|,
argument|VectorKind vecKind
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|ElementType
return|;
block|}
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|VectorTypeBits
operator|.
name|NumElements
return|;
block|}
specifier|static
name|bool
name|isVectorSizeTooLarge
argument_list|(
argument|unsigned NumElements
argument_list|)
block|{
return|return
name|NumElements
operator|>
name|VectorTypeBitfields
operator|::
name|MaxNumElements
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|VectorKind
name|getVectorKind
argument_list|()
specifier|const
block|{
return|return
name|VectorKind
argument_list|(
name|VectorTypeBits
operator|.
name|VecKind
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getElementType
argument_list|()
argument_list|,
name|getNumElements
argument_list|()
argument_list|,
name|getTypeClass
argument_list|()
argument_list|,
name|getVectorKind
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType ElementType
argument_list|,
argument|unsigned NumElements
argument_list|,
argument|TypeClass TypeClass
argument_list|,
argument|VectorKind VecKind
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|ElementType
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|NumElements
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|TypeClass
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|VecKind
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Vector
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ExtVector
return|;
block|}
expr|}
block|;
comment|/// ExtVectorType - Extended vector type. This type is created using
comment|/// __attribute__((ext_vector_type(n)), where "n" is the number of elements.
comment|/// Unlike vector_size, ext_vector_type is only allowed on typedef's. This
comment|/// class enables syntactic extensions, like Vector Components for accessing
comment|/// points (as .xyzw), colors (as .rgba), and textures (modeled after OpenGL
comment|/// Shading Language).
name|class
name|ExtVectorType
operator|:
name|public
name|VectorType
block|{
name|ExtVectorType
argument_list|(
argument|QualType vecType
argument_list|,
argument|unsigned nElements
argument_list|,
argument|QualType canonType
argument_list|)
operator|:
name|VectorType
argument_list|(
argument|ExtVector
argument_list|,
argument|vecType
argument_list|,
argument|nElements
argument_list|,
argument|canonType
argument_list|,
argument|GenericVector
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
specifier|static
name|int
name|getPointAccessorIdx
argument_list|(
argument|char c
argument_list|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
default|default:
return|return
operator|-
literal|1
return|;
case|case
literal|'x'
case|:
case|case
literal|'r'
case|:
return|return
literal|0
return|;
case|case
literal|'y'
case|:
case|case
literal|'g'
case|:
return|return
literal|1
return|;
case|case
literal|'z'
case|:
case|case
literal|'b'
case|:
return|return
literal|2
return|;
case|case
literal|'w'
case|:
case|case
literal|'a'
case|:
return|return
literal|3
return|;
block|}
block|}
specifier|static
name|int
name|getNumericAccessorIdx
argument_list|(
argument|char c
argument_list|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
default|default:
return|return
operator|-
literal|1
return|;
case|case
literal|'0'
case|:
return|return
literal|0
return|;
case|case
literal|'1'
case|:
return|return
literal|1
return|;
case|case
literal|'2'
case|:
return|return
literal|2
return|;
case|case
literal|'3'
case|:
return|return
literal|3
return|;
case|case
literal|'4'
case|:
return|return
literal|4
return|;
case|case
literal|'5'
case|:
return|return
literal|5
return|;
case|case
literal|'6'
case|:
return|return
literal|6
return|;
case|case
literal|'7'
case|:
return|return
literal|7
return|;
case|case
literal|'8'
case|:
return|return
literal|8
return|;
case|case
literal|'9'
case|:
return|return
literal|9
return|;
case|case
literal|'A'
case|:
case|case
literal|'a'
case|:
return|return
literal|10
return|;
case|case
literal|'B'
case|:
case|case
literal|'b'
case|:
return|return
literal|11
return|;
case|case
literal|'C'
case|:
case|case
literal|'c'
case|:
return|return
literal|12
return|;
case|case
literal|'D'
case|:
case|case
literal|'d'
case|:
return|return
literal|13
return|;
case|case
literal|'E'
case|:
case|case
literal|'e'
case|:
return|return
literal|14
return|;
case|case
literal|'F'
case|:
case|case
literal|'f'
case|:
return|return
literal|15
return|;
block|}
block|}
specifier|static
name|int
name|getAccessorIdx
argument_list|(
argument|char c
argument_list|,
argument|bool isNumericAccessor
argument_list|)
block|{
if|if
condition|(
name|isNumericAccessor
condition|)
return|return
name|getNumericAccessorIdx
argument_list|(
name|c
argument_list|)
return|;
else|else
return|return
name|getPointAccessorIdx
argument_list|(
name|c
argument_list|)
return|;
block|}
name|bool
name|isAccessorWithinNumElements
argument_list|(
argument|char c
argument_list|,
argument|bool isNumericAccessor
argument_list|)
specifier|const
block|{
if|if
condition|(
name|int
name|idx
init|=
name|getAccessorIdx
argument_list|(
name|c
argument_list|,
name|isNumericAccessor
argument_list|)
operator|+
literal|1
condition|)
return|return
name|unsigned
argument_list|(
name|idx
operator|-
literal|1
argument_list|)
operator|<
name|getNumElements
argument_list|()
return|;
return|return
name|false
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ExtVector
return|;
block|}
expr|}
block|;
comment|/// FunctionType - C99 6.7.5.3 - Function Declarators.  This is the common base
comment|/// class of FunctionNoProtoType and FunctionProtoType.
comment|///
name|class
name|FunctionType
operator|:
name|public
name|Type
block|{
comment|// The type returned by the function.
name|QualType
name|ResultType
block|;
name|public
operator|:
comment|/// A class which abstracts out some details necessary for
comment|/// making a call.
comment|///
comment|/// It is not actually used directly for storing this information in
comment|/// a FunctionType, although FunctionType does currently use the
comment|/// same bit-pattern.
comment|///
comment|// If you add a field (say Foo), other than the obvious places (both,
comment|// constructors, compile failures), what you need to update is
comment|// * Operator==
comment|// * getFoo
comment|// * withFoo
comment|// * functionType. Add Foo, getFoo.
comment|// * ASTContext::getFooType
comment|// * ASTContext::mergeFunctionTypes
comment|// * FunctionNoProtoType::Profile
comment|// * FunctionProtoType::Profile
comment|// * TypePrinter::PrintFunctionProto
comment|// * AST read and write
comment|// * Codegen
name|class
name|ExtInfo
block|{
comment|// Feel free to rearrange or add bits, but if you go over 11,
comment|// you'll need to adjust both the Bits field below and
comment|// Type::FunctionTypeBitfields.
comment|//   |  CC  |noreturn|produces|nocallersavedregs|regparm|
comment|//   |0 .. 4|   5    |    6   |       7         |8 .. 10|
comment|//
comment|// regparm is either 0 (no regparm attribute) or the regparm value+1.
block|enum
block|{
name|CallConvMask
operator|=
literal|0x1F
block|}
block|;     enum
block|{
name|NoReturnMask
operator|=
literal|0x20
block|}
block|;     enum
block|{
name|ProducesResultMask
operator|=
literal|0x40
block|}
block|;     enum
block|{
name|NoCallerSavedRegsMask
operator|=
literal|0x80
block|}
block|;     enum
block|{
name|RegParmMask
operator|=
operator|~
operator|(
name|CallConvMask
operator||
name|NoReturnMask
operator||
name|ProducesResultMask
operator||
name|NoCallerSavedRegsMask
operator|)
block|,
name|RegParmOffset
operator|=
literal|8
block|}
block|;
comment|// Assumed to be the last field
name|uint16_t
name|Bits
block|;
name|ExtInfo
argument_list|(
argument|unsigned Bits
argument_list|)
operator|:
name|Bits
argument_list|(
argument|static_cast<uint16_t>(Bits)
argument_list|)
block|{}
name|friend
name|class
name|FunctionType
block|;
name|public
operator|:
comment|// Constructor with no defaults. Use this when you know that you
comment|// have all the elements (when reading an AST file for example).
name|ExtInfo
argument_list|(
argument|bool noReturn
argument_list|,
argument|bool hasRegParm
argument_list|,
argument|unsigned regParm
argument_list|,
argument|CallingConv cc
argument_list|,
argument|bool producesResult
argument_list|,
argument|bool noCallerSavedRegs
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|hasRegParm
operator|||
name|regParm
operator|<
literal|7
operator|)
operator|&&
literal|"Invalid regparm value"
argument_list|)
block|;
name|Bits
operator|=
operator|(
operator|(
name|unsigned
operator|)
name|cc
operator|)
operator||
operator|(
name|noReturn
condition|?
name|NoReturnMask
else|:
literal|0
operator|)
operator||
operator|(
name|producesResult
condition|?
name|ProducesResultMask
else|:
literal|0
operator|)
operator||
operator|(
name|noCallerSavedRegs
condition|?
name|NoCallerSavedRegsMask
else|:
literal|0
operator|)
operator||
operator|(
name|hasRegParm
condition|?
operator|(
operator|(
name|regParm
operator|+
literal|1
operator|)
operator|<<
name|RegParmOffset
operator|)
else|:
literal|0
operator|)
block|;     }
comment|// Constructor with all defaults. Use when for example creating a
comment|// function known to use defaults.
name|ExtInfo
argument_list|()
operator|:
name|Bits
argument_list|(
argument|CC_C
argument_list|)
block|{ }
comment|// Constructor with just the calling convention, which is an important part
comment|// of the canonical type.
name|ExtInfo
argument_list|(
argument|CallingConv CC
argument_list|)
operator|:
name|Bits
argument_list|(
argument|CC
argument_list|)
block|{ }
name|bool
name|getNoReturn
argument_list|()
specifier|const
block|{
return|return
name|Bits
operator|&
name|NoReturnMask
return|;
block|}
name|bool
name|getProducesResult
argument_list|()
specifier|const
block|{
return|return
name|Bits
operator|&
name|ProducesResultMask
return|;
block|}
name|bool
name|getNoCallerSavedRegs
argument_list|()
specifier|const
block|{
return|return
name|Bits
operator|&
name|NoCallerSavedRegsMask
return|;
block|}
name|bool
name|getHasRegParm
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Bits
operator|>>
name|RegParmOffset
operator|)
operator|!=
literal|0
return|;
block|}
name|unsigned
name|getRegParm
argument_list|()
specifier|const
block|{
name|unsigned
name|RegParm
operator|=
name|Bits
operator|>>
name|RegParmOffset
block|;
if|if
condition|(
name|RegParm
operator|>
literal|0
condition|)
operator|--
name|RegParm
expr_stmt|;
return|return
name|RegParm
return|;
block|}
name|CallingConv
name|getCC
argument_list|()
specifier|const
block|{
return|return
name|CallingConv
argument_list|(
name|Bits
operator|&
name|CallConvMask
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
name|ExtInfo
name|Other
operator|)
specifier|const
block|{
return|return
name|Bits
operator|==
name|Other
operator|.
name|Bits
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
name|ExtInfo
name|Other
operator|)
specifier|const
block|{
return|return
name|Bits
operator|!=
name|Other
operator|.
name|Bits
return|;
block|}
comment|// Note that we don't have setters. That is by design, use
comment|// the following with methods instead of mutating these objects.
name|ExtInfo
name|withNoReturn
argument_list|(
argument|bool noReturn
argument_list|)
specifier|const
block|{
if|if
condition|(
name|noReturn
condition|)
return|return
name|ExtInfo
argument_list|(
name|Bits
operator||
name|NoReturnMask
argument_list|)
return|;
else|else
return|return
name|ExtInfo
argument_list|(
name|Bits
operator|&
operator|~
name|NoReturnMask
argument_list|)
return|;
block|}
name|ExtInfo
name|withProducesResult
argument_list|(
argument|bool producesResult
argument_list|)
specifier|const
block|{
if|if
condition|(
name|producesResult
condition|)
return|return
name|ExtInfo
argument_list|(
name|Bits
operator||
name|ProducesResultMask
argument_list|)
return|;
else|else
return|return
name|ExtInfo
argument_list|(
name|Bits
operator|&
operator|~
name|ProducesResultMask
argument_list|)
return|;
block|}
name|ExtInfo
name|withNoCallerSavedRegs
argument_list|(
argument|bool noCallerSavedRegs
argument_list|)
specifier|const
block|{
if|if
condition|(
name|noCallerSavedRegs
condition|)
return|return
name|ExtInfo
argument_list|(
name|Bits
operator||
name|NoCallerSavedRegsMask
argument_list|)
return|;
else|else
return|return
name|ExtInfo
argument_list|(
name|Bits
operator|&
operator|~
name|NoCallerSavedRegsMask
argument_list|)
return|;
block|}
name|ExtInfo
name|withRegParm
argument_list|(
argument|unsigned RegParm
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|RegParm
operator|<
literal|7
operator|&&
literal|"Invalid regparm value"
argument_list|)
block|;
return|return
name|ExtInfo
argument_list|(
operator|(
name|Bits
operator|&
operator|~
name|RegParmMask
operator|)
operator||
operator|(
operator|(
name|RegParm
operator|+
literal|1
operator|)
operator|<<
name|RegParmOffset
operator|)
argument_list|)
return|;
block|}
name|ExtInfo
name|withCallingConv
argument_list|(
argument|CallingConv cc
argument_list|)
specifier|const
block|{
return|return
name|ExtInfo
argument_list|(
operator|(
name|Bits
operator|&
operator|~
name|CallConvMask
operator|)
operator||
operator|(
name|unsigned
operator|)
name|cc
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|Bits
argument_list|)
block|;     }
expr|}
block|;
name|protected
operator|:
name|FunctionType
argument_list|(
argument|TypeClass tc
argument_list|,
argument|QualType res
argument_list|,
argument|QualType Canonical
argument_list|,
argument|bool Dependent
argument_list|,
argument|bool InstantiationDependent
argument_list|,
argument|bool VariablyModified
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|,
argument|ExtInfo Info
argument_list|)
operator|:
name|Type
argument_list|(
name|tc
argument_list|,
name|Canonical
argument_list|,
name|Dependent
argument_list|,
name|InstantiationDependent
argument_list|,
name|VariablyModified
argument_list|,
name|ContainsUnexpandedParameterPack
argument_list|)
block|,
name|ResultType
argument_list|(
argument|res
argument_list|)
block|{
name|FunctionTypeBits
operator|.
name|ExtInfo
operator|=
name|Info
operator|.
name|Bits
block|;   }
name|unsigned
name|getTypeQuals
argument_list|()
specifier|const
block|{
return|return
name|FunctionTypeBits
operator|.
name|TypeQuals
return|;
block|}
name|public
operator|:
name|QualType
name|getReturnType
argument_list|()
specifier|const
block|{
return|return
name|ResultType
return|;
block|}
name|bool
name|getHasRegParm
argument_list|()
specifier|const
block|{
return|return
name|getExtInfo
argument_list|()
operator|.
name|getHasRegParm
argument_list|()
return|;
block|}
name|unsigned
name|getRegParmType
argument_list|()
specifier|const
block|{
return|return
name|getExtInfo
argument_list|()
operator|.
name|getRegParm
argument_list|()
return|;
block|}
comment|/// Determine whether this function type includes the GNU noreturn
comment|/// attribute. The C++11 [[noreturn]] attribute does not affect the function
comment|/// type.
name|bool
name|getNoReturnAttr
argument_list|()
specifier|const
block|{
return|return
name|getExtInfo
argument_list|()
operator|.
name|getNoReturn
argument_list|()
return|;
block|}
name|CallingConv
name|getCallConv
argument_list|()
specifier|const
block|{
return|return
name|getExtInfo
argument_list|()
operator|.
name|getCC
argument_list|()
return|;
block|}
name|ExtInfo
name|getExtInfo
argument_list|()
specifier|const
block|{
return|return
name|ExtInfo
argument_list|(
name|FunctionTypeBits
operator|.
name|ExtInfo
argument_list|)
return|;
block|}
name|bool
name|isConst
argument_list|()
specifier|const
block|{
return|return
name|getTypeQuals
argument_list|()
operator|&
name|Qualifiers
operator|::
name|Const
return|;
block|}
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|getTypeQuals
argument_list|()
operator|&
name|Qualifiers
operator|::
name|Volatile
return|;
block|}
name|bool
name|isRestrict
argument_list|()
specifier|const
block|{
return|return
name|getTypeQuals
argument_list|()
operator|&
name|Qualifiers
operator|::
name|Restrict
return|;
block|}
comment|/// \brief Determine the type of an expression that calls a function of
comment|/// this type.
name|QualType
name|getCallResultType
argument_list|(
argument|const ASTContext&Context
argument_list|)
specifier|const
block|{
return|return
name|getReturnType
argument_list|()
operator|.
name|getNonLValueExprType
argument_list|(
name|Context
argument_list|)
return|;
block|}
specifier|static
name|StringRef
name|getNameForCallConv
argument_list|(
argument|CallingConv CC
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|FunctionNoProto
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|FunctionProto
return|;
block|}
expr|}
block|;
comment|/// Represents a K&R-style 'int foo()' function, which has
comment|/// no information available about its arguments.
name|class
name|FunctionNoProtoType
operator|:
name|public
name|FunctionType
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|FunctionNoProtoType
argument_list|(
argument|QualType Result
argument_list|,
argument|QualType Canonical
argument_list|,
argument|ExtInfo Info
argument_list|)
operator|:
name|FunctionType
argument_list|(
argument|FunctionNoProto
argument_list|,
argument|Result
argument_list|,
argument|Canonical
argument_list|,
comment|/*Dependent=*/
argument|false
argument_list|,
comment|/*InstantiationDependent=*/
argument|false
argument_list|,
argument|Result->isVariablyModifiedType()
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
argument|false
argument_list|,
argument|Info
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
comment|// No additional state past what FunctionType provides.
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getReturnType
argument_list|()
argument_list|,
name|getExtInfo
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType ResultType
argument_list|,
argument|ExtInfo Info
argument_list|)
block|{
name|Info
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|ResultType
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|FunctionNoProto
return|;
block|}
expr|}
block|;
comment|/// Represents a prototype with parameter type info, e.g.
comment|/// 'int foo(int)' or 'int foo(void)'.  'void' is represented as having no
comment|/// parameters, not as having a single void parameter. Such a type can have an
comment|/// exception specification, but this specification is not part of the canonical
comment|/// type.
name|class
name|FunctionProtoType
operator|:
name|public
name|FunctionType
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|public
operator|:
comment|/// Interesting information about a specific parameter that can't simply
comment|/// be reflected in parameter's type.
comment|///
comment|/// It makes sense to model language features this way when there's some
comment|/// sort of parameter-specific override (such as an attribute) that
comment|/// affects how the function is called.  For example, the ARC ns_consumed
comment|/// attribute changes whether a parameter is passed at +0 (the default)
comment|/// or +1 (ns_consumed).  This must be reflected in the function type,
comment|/// but isn't really a change to the parameter type.
comment|///
comment|/// One serious disadvantage of modelling language features this way is
comment|/// that they generally do not work with language features that attempt
comment|/// to destructure types.  For example, template argument deduction will
comment|/// not be able to match a parameter declared as
comment|///   T (*)(U)
comment|/// against an argument of type
comment|///   void (*)(__attribute__((ns_consumed)) id)
comment|/// because the substitution of T=void, U=id into the former will
comment|/// not produce the latter.
name|class
name|ExtParameterInfo
block|{     enum
block|{
name|ABIMask
operator|=
literal|0x0F
block|,
name|IsConsumed
operator|=
literal|0x10
block|,
name|HasPassObjSize
operator|=
literal|0x20
block|,     }
block|;
name|unsigned
name|char
name|Data
block|;
name|public
operator|:
name|ExtParameterInfo
argument_list|()
operator|:
name|Data
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Return the ABI treatment of this parameter.
name|ParameterABI
name|getABI
argument_list|()
specifier|const
block|{
return|return
name|ParameterABI
argument_list|(
name|Data
operator|&
name|ABIMask
argument_list|)
return|;
block|}
name|ExtParameterInfo
name|withABI
argument_list|(
argument|ParameterABI kind
argument_list|)
specifier|const
block|{
name|ExtParameterInfo
name|copy
operator|=
operator|*
name|this
block|;
name|copy
operator|.
name|Data
operator|=
operator|(
name|copy
operator|.
name|Data
operator|&
operator|~
name|ABIMask
operator|)
operator||
name|unsigned
argument_list|(
name|kind
argument_list|)
block|;
return|return
name|copy
return|;
block|}
comment|/// Is this parameter considered "consumed" by Objective-C ARC?
comment|/// Consumed parameters must have retainable object type.
name|bool
name|isConsumed
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Data
operator|&
name|IsConsumed
operator|)
return|;
block|}
name|ExtParameterInfo
name|withIsConsumed
argument_list|(
argument|bool consumed
argument_list|)
specifier|const
block|{
name|ExtParameterInfo
name|copy
operator|=
operator|*
name|this
block|;
if|if
condition|(
name|consumed
condition|)
block|{
name|copy
operator|.
name|Data
operator||=
name|IsConsumed
expr_stmt|;
block|}
else|else
block|{
name|copy
operator|.
name|Data
operator|&=
operator|~
name|IsConsumed
expr_stmt|;
block|}
return|return
name|copy
return|;
block|}
name|bool
name|hasPassObjectSize
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|&
name|HasPassObjSize
return|;
block|}
name|ExtParameterInfo
name|withHasPassObjectSize
argument_list|()
specifier|const
block|{
name|ExtParameterInfo
name|Copy
operator|=
operator|*
name|this
block|;
name|Copy
operator|.
name|Data
operator||=
name|HasPassObjSize
block|;
return|return
name|Copy
return|;
block|}
name|unsigned
name|char
name|getOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
specifier|static
name|ExtParameterInfo
name|getFromOpaqueValue
argument_list|(
argument|unsigned char data
argument_list|)
block|{
name|ExtParameterInfo
name|result
block|;
name|result
operator|.
name|Data
operator|=
name|data
block|;
return|return
name|result
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|ExtParameterInfo
name|lhs
expr|,
name|ExtParameterInfo
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|Data
operator|==
name|rhs
operator|.
name|Data
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|ExtParameterInfo
name|lhs
expr|,
name|ExtParameterInfo
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|Data
operator|!=
name|rhs
operator|.
name|Data
return|;
block|}
expr|}
block|;    struct
name|ExceptionSpecInfo
block|{
name|ExceptionSpecInfo
argument_list|()
operator|:
name|Type
argument_list|(
name|EST_None
argument_list|)
block|,
name|NoexceptExpr
argument_list|(
name|nullptr
argument_list|)
block|,
name|SourceDecl
argument_list|(
name|nullptr
argument_list|)
block|,
name|SourceTemplate
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|ExceptionSpecInfo
argument_list|(
argument|ExceptionSpecificationType EST
argument_list|)
operator|:
name|Type
argument_list|(
name|EST
argument_list|)
block|,
name|NoexceptExpr
argument_list|(
name|nullptr
argument_list|)
block|,
name|SourceDecl
argument_list|(
name|nullptr
argument_list|)
block|,
name|SourceTemplate
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// The kind of exception specification this is.
name|ExceptionSpecificationType
name|Type
block|;
comment|/// Explicitly-specified list of exception types.
name|ArrayRef
operator|<
name|QualType
operator|>
name|Exceptions
block|;
comment|/// Noexcept expression, if this is EST_ComputedNoexcept.
name|Expr
operator|*
name|NoexceptExpr
block|;
comment|/// The function whose exception specification this is, for
comment|/// EST_Unevaluated and EST_Uninstantiated.
name|FunctionDecl
operator|*
name|SourceDecl
block|;
comment|/// The function template whose exception specification this is instantiated
comment|/// from, for EST_Uninstantiated.
name|FunctionDecl
operator|*
name|SourceTemplate
block|;   }
block|;
comment|/// Extra information about a function prototype.
block|struct
name|ExtProtoInfo
block|{
name|ExtProtoInfo
argument_list|()
operator|:
name|Variadic
argument_list|(
name|false
argument_list|)
block|,
name|HasTrailingReturn
argument_list|(
name|false
argument_list|)
block|,
name|TypeQuals
argument_list|(
literal|0
argument_list|)
block|,
name|RefQualifier
argument_list|(
name|RQ_None
argument_list|)
block|,
name|ExtParameterInfos
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|ExtProtoInfo
argument_list|(
argument|CallingConv CC
argument_list|)
operator|:
name|ExtInfo
argument_list|(
name|CC
argument_list|)
block|,
name|Variadic
argument_list|(
name|false
argument_list|)
block|,
name|HasTrailingReturn
argument_list|(
name|false
argument_list|)
block|,
name|TypeQuals
argument_list|(
literal|0
argument_list|)
block|,
name|RefQualifier
argument_list|(
name|RQ_None
argument_list|)
block|,
name|ExtParameterInfos
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|ExtProtoInfo
name|withExceptionSpec
argument_list|(
argument|const ExceptionSpecInfo&O
argument_list|)
block|{
name|ExtProtoInfo
name|Result
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|Result
operator|.
name|ExceptionSpec
operator|=
name|O
block|;
return|return
name|Result
return|;
block|}
name|FunctionType
operator|::
name|ExtInfo
name|ExtInfo
block|;
name|bool
name|Variadic
operator|:
literal|1
block|;
name|bool
name|HasTrailingReturn
operator|:
literal|1
block|;
name|unsigned
name|char
name|TypeQuals
block|;
name|RefQualifierKind
name|RefQualifier
block|;
name|ExceptionSpecInfo
name|ExceptionSpec
block|;
specifier|const
name|ExtParameterInfo
operator|*
name|ExtParameterInfos
block|;   }
block|;
name|private
operator|:
comment|/// \brief Determine whether there are any argument types that
comment|/// contain an unexpanded parameter pack.
specifier|static
name|bool
name|containsAnyUnexpandedParameterPack
argument_list|(
argument|const QualType *ArgArray
argument_list|,
argument|unsigned numArgs
argument_list|)
block|{
for|for
control|(
name|unsigned
name|Idx
init|=
literal|0
init|;
name|Idx
operator|<
name|numArgs
condition|;
operator|++
name|Idx
control|)
if|if
condition|(
name|ArgArray
index|[
name|Idx
index|]
operator|->
name|containsUnexpandedParameterPack
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
name|FunctionProtoType
argument_list|(
argument|QualType result
argument_list|,
argument|ArrayRef<QualType> params
argument_list|,
argument|QualType canonical
argument_list|,
argument|const ExtProtoInfo&epi
argument_list|)
block|;
comment|/// The number of parameters this function has, not counting '...'.
name|unsigned
name|NumParams
operator|:
literal|15
block|;
comment|/// The number of types in the exception spec, if any.
name|unsigned
name|NumExceptions
operator|:
literal|9
block|;
comment|/// The type of exception specification this function has.
name|unsigned
name|ExceptionSpecType
operator|:
literal|4
block|;
comment|/// Whether this function has extended parameter information.
name|unsigned
name|HasExtParameterInfos
operator|:
literal|1
block|;
comment|/// Whether the function is variadic.
name|unsigned
name|Variadic
operator|:
literal|1
block|;
comment|/// Whether this function has a trailing return type.
name|unsigned
name|HasTrailingReturn
operator|:
literal|1
block|;
comment|// ParamInfo - There is an variable size array after the class in memory that
comment|// holds the parameter types.
comment|// Exceptions - There is another variable size array after ArgInfo that
comment|// holds the exception types.
comment|// NoexceptExpr - Instead of Exceptions, there may be a single Expr* pointing
comment|// to the expression in the noexcept() specifier.
comment|// ExceptionSpecDecl, ExceptionSpecTemplate - Instead of Exceptions, there may
comment|// be a pair of FunctionDecl* pointing to the function which should be used to
comment|// instantiate this function type's exception specification, and the function
comment|// from which it should be instantiated.
comment|// ExtParameterInfos - A variable size array, following the exception
comment|// specification and of length NumParams, holding an ExtParameterInfo
comment|// for each of the parameters.  This only appears if HasExtParameterInfos
comment|// is true.
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
specifier|const
name|ExtParameterInfo
operator|*
name|getExtParameterInfosBuffer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasExtParameterInfos
argument_list|()
argument_list|)
block|;
comment|// Find the end of the exception specification.
specifier|const
name|char
operator|*
name|ptr
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|exception_begin
argument_list|()
operator|)
block|;
name|ptr
operator|+=
name|getExceptionSpecSize
argument_list|()
block|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|ExtParameterInfo
operator|*
operator|>
operator|(
name|ptr
operator|)
return|;
block|}
name|size_t
name|getExceptionSpecSize
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getExceptionSpecType
argument_list|()
condition|)
block|{
case|case
name|EST_None
case|:
return|return
literal|0
return|;
case|case
name|EST_DynamicNone
case|:
return|return
literal|0
return|;
case|case
name|EST_MSAny
case|:
return|return
literal|0
return|;
case|case
name|EST_BasicNoexcept
case|:
return|return
literal|0
return|;
case|case
name|EST_Unparsed
case|:
return|return
literal|0
return|;
case|case
name|EST_Dynamic
case|:
return|return
name|getNumExceptions
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|QualType
argument_list|)
return|;
case|case
name|EST_ComputedNoexcept
case|:
return|return
sizeof|sizeof
argument_list|(
name|Expr
operator|*
argument_list|)
return|;
case|case
name|EST_Uninstantiated
case|:
return|return
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|FunctionDecl
operator|*
argument_list|)
return|;
case|case
name|EST_Unevaluated
case|:
return|return
sizeof|sizeof
argument_list|(
name|FunctionDecl
operator|*
argument_list|)
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"bad exception specification kind"
argument_list|)
expr_stmt|;
block|}
name|public
operator|:
name|unsigned
name|getNumParams
argument_list|()
specifier|const
block|{
return|return
name|NumParams
return|;
block|}
name|QualType
name|getParamType
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumParams
operator|&&
literal|"invalid parameter index"
argument_list|)
block|;
return|return
name|param_type_begin
argument_list|()
index|[
name|i
index|]
return|;
block|}
name|ArrayRef
operator|<
name|QualType
operator|>
name|getParamTypes
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|param_type_begin
argument_list|()
argument_list|,
name|param_type_end
argument_list|()
argument_list|)
return|;
block|}
name|ExtProtoInfo
name|getExtProtoInfo
argument_list|()
specifier|const
block|{
name|ExtProtoInfo
name|EPI
block|;
name|EPI
operator|.
name|ExtInfo
operator|=
name|getExtInfo
argument_list|()
block|;
name|EPI
operator|.
name|Variadic
operator|=
name|isVariadic
argument_list|()
block|;
name|EPI
operator|.
name|HasTrailingReturn
operator|=
name|hasTrailingReturn
argument_list|()
block|;
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|Type
operator|=
name|getExceptionSpecType
argument_list|()
block|;
name|EPI
operator|.
name|TypeQuals
operator|=
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|getTypeQuals
argument_list|()
operator|)
block|;
name|EPI
operator|.
name|RefQualifier
operator|=
name|getRefQualifier
argument_list|()
block|;
if|if
condition|(
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|Type
operator|==
name|EST_Dynamic
condition|)
block|{
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|Exceptions
operator|=
name|exceptions
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|Type
operator|==
name|EST_ComputedNoexcept
condition|)
block|{
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|NoexceptExpr
operator|=
name|getNoexceptExpr
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|Type
operator|==
name|EST_Uninstantiated
condition|)
block|{
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|SourceDecl
operator|=
name|getExceptionSpecDecl
argument_list|()
expr_stmt|;
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|SourceTemplate
operator|=
name|getExceptionSpecTemplate
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|Type
operator|==
name|EST_Unevaluated
condition|)
block|{
name|EPI
operator|.
name|ExceptionSpec
operator|.
name|SourceDecl
operator|=
name|getExceptionSpecDecl
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|hasExtParameterInfos
argument_list|()
condition|)
name|EPI
operator|.
name|ExtParameterInfos
operator|=
name|getExtParameterInfosBuffer
argument_list|()
expr_stmt|;
return|return
name|EPI
return|;
block|}
comment|/// Get the kind of exception specification on this function.
name|ExceptionSpecificationType
name|getExceptionSpecType
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ExceptionSpecificationType
operator|>
operator|(
name|ExceptionSpecType
operator|)
return|;
block|}
comment|/// Return whether this function has any kind of exception spec.
name|bool
name|hasExceptionSpec
argument_list|()
specifier|const
block|{
return|return
name|getExceptionSpecType
argument_list|()
operator|!=
name|EST_None
return|;
block|}
comment|/// Return whether this function has a dynamic (throw) exception spec.
name|bool
name|hasDynamicExceptionSpec
argument_list|()
specifier|const
block|{
return|return
name|isDynamicExceptionSpec
argument_list|(
name|getExceptionSpecType
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return whether this function has a noexcept exception spec.
name|bool
name|hasNoexceptExceptionSpec
argument_list|()
specifier|const
block|{
return|return
name|isNoexceptExceptionSpec
argument_list|(
name|getExceptionSpecType
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return whether this function has a dependent exception spec.
name|bool
name|hasDependentExceptionSpec
argument_list|()
specifier|const
block|;
comment|/// Return whether this function has an instantiation-dependent exception
comment|/// spec.
name|bool
name|hasInstantiationDependentExceptionSpec
argument_list|()
specifier|const
block|;
comment|/// Result type of getNoexceptSpec().
block|enum
name|NoexceptResult
block|{
name|NR_NoNoexcept
block|,
comment|///< There is no noexcept specifier.
name|NR_BadNoexcept
block|,
comment|///< The noexcept specifier has a bad expression.
name|NR_Dependent
block|,
comment|///< The noexcept specifier is dependent.
name|NR_Throw
block|,
comment|///< The noexcept specifier evaluates to false.
name|NR_Nothrow
comment|///< The noexcept specifier evaluates to true.
block|}
block|;
comment|/// Get the meaning of the noexcept spec on this function, if any.
name|NoexceptResult
name|getNoexceptSpec
argument_list|(
argument|const ASTContext&Ctx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumExceptions
argument_list|()
specifier|const
block|{
return|return
name|NumExceptions
return|;
block|}
name|QualType
name|getExceptionType
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumExceptions
operator|&&
literal|"Invalid exception number!"
argument_list|)
block|;
return|return
name|exception_begin
argument_list|()
index|[
name|i
index|]
return|;
block|}
name|Expr
operator|*
name|getNoexceptExpr
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getExceptionSpecType
argument_list|()
operator|!=
name|EST_ComputedNoexcept
condition|)
return|return
name|nullptr
return|;
comment|// NoexceptExpr sits where the arguments end.
return|return
operator|*
name|reinterpret_cast
operator|<
name|Expr
operator|*
specifier|const
operator|*
operator|>
operator|(
name|param_type_end
argument_list|()
operator|)
return|;
block|}
comment|/// \brief If this function type has an exception specification which hasn't
comment|/// been determined yet (either because it has not been evaluated or because
comment|/// it has not been instantiated), this is the function whose exception
comment|/// specification is represented by this type.
name|FunctionDecl
operator|*
name|getExceptionSpecDecl
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getExceptionSpecType
argument_list|()
operator|!=
name|EST_Uninstantiated
operator|&&
name|getExceptionSpecType
argument_list|()
operator|!=
name|EST_Unevaluated
condition|)
return|return
name|nullptr
return|;
return|return
name|reinterpret_cast
operator|<
name|FunctionDecl
operator|*
specifier|const
operator|*
operator|>
operator|(
name|param_type_end
argument_list|()
operator|)
index|[
literal|0
index|]
return|;
block|}
comment|/// \brief If this function type has an uninstantiated exception
comment|/// specification, this is the function whose exception specification
comment|/// should be instantiated to find the exception specification for
comment|/// this type.
name|FunctionDecl
operator|*
name|getExceptionSpecTemplate
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getExceptionSpecType
argument_list|()
operator|!=
name|EST_Uninstantiated
condition|)
return|return
name|nullptr
return|;
return|return
name|reinterpret_cast
operator|<
name|FunctionDecl
operator|*
specifier|const
operator|*
operator|>
operator|(
name|param_type_end
argument_list|()
operator|)
index|[
literal|1
index|]
return|;
block|}
comment|/// Determine whether this function type has a non-throwing exception
comment|/// specification.
name|CanThrowResult
name|canThrow
argument_list|(
argument|const ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// Determine whether this function type has a non-throwing exception
comment|/// specification. If this depends on template arguments, returns
comment|/// \c ResultIfDependent.
name|bool
name|isNothrow
argument_list|(
argument|const ASTContext&Ctx
argument_list|,
argument|bool ResultIfDependent = false
argument_list|)
specifier|const
block|{
return|return
name|ResultIfDependent
operator|?
name|canThrow
argument_list|(
name|Ctx
argument_list|)
operator|!=
name|CT_Can
operator|:
name|canThrow
argument_list|(
name|Ctx
argument_list|)
operator|==
name|CT_Cannot
return|;
block|}
name|bool
name|isVariadic
argument_list|()
specifier|const
block|{
return|return
name|Variadic
return|;
block|}
comment|/// Determines whether this function prototype contains a
comment|/// parameter pack at the end.
comment|///
comment|/// A function template whose last parameter is a parameter pack can be
comment|/// called with an arbitrary number of arguments, much like a variadic
comment|/// function.
name|bool
name|isTemplateVariadic
argument_list|()
specifier|const
block|;
name|bool
name|hasTrailingReturn
argument_list|()
specifier|const
block|{
return|return
name|HasTrailingReturn
return|;
block|}
name|unsigned
name|getTypeQuals
argument_list|()
specifier|const
block|{
return|return
name|FunctionType
operator|::
name|getTypeQuals
argument_list|()
return|;
block|}
comment|/// Retrieve the ref-qualifier associated with this function type.
name|RefQualifierKind
name|getRefQualifier
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|RefQualifierKind
operator|>
operator|(
name|FunctionTypeBits
operator|.
name|RefQualifier
operator|)
return|;
block|}
typedef|typedef
specifier|const
name|QualType
modifier|*
name|param_type_iterator
typedef|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|param_type_iterator
operator|>
name|param_type_range
expr_stmt|;
name|param_type_range
name|param_types
argument_list|()
specifier|const
block|{
return|return
name|param_type_range
argument_list|(
name|param_type_begin
argument_list|()
argument_list|,
name|param_type_end
argument_list|()
argument_list|)
return|;
block|}
name|param_type_iterator
name|param_type_begin
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|QualType
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|param_type_iterator
name|param_type_end
argument_list|()
specifier|const
block|{
return|return
name|param_type_begin
argument_list|()
operator|+
name|NumParams
return|;
block|}
typedef|typedef
specifier|const
name|QualType
modifier|*
name|exception_iterator
typedef|;
name|ArrayRef
operator|<
name|QualType
operator|>
name|exceptions
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|exception_begin
argument_list|()
argument_list|,
name|exception_end
argument_list|()
argument_list|)
return|;
block|}
name|exception_iterator
name|exception_begin
argument_list|()
specifier|const
block|{
comment|// exceptions begin where arguments end
return|return
name|param_type_end
argument_list|()
return|;
block|}
name|exception_iterator
name|exception_end
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getExceptionSpecType
argument_list|()
operator|!=
name|EST_Dynamic
condition|)
return|return
name|exception_begin
argument_list|()
return|;
return|return
name|exception_begin
argument_list|()
operator|+
name|NumExceptions
return|;
block|}
comment|/// Is there any interesting extra information for any of the parameters
comment|/// of this function type?
name|bool
name|hasExtParameterInfos
argument_list|()
specifier|const
block|{
return|return
name|HasExtParameterInfos
return|;
block|}
name|ArrayRef
operator|<
name|ExtParameterInfo
operator|>
name|getExtParameterInfos
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasExtParameterInfos
argument_list|()
argument_list|)
block|;
return|return
name|ArrayRef
operator|<
name|ExtParameterInfo
operator|>
operator|(
name|getExtParameterInfosBuffer
argument_list|()
expr|,
name|getNumParams
argument_list|()
operator|)
return|;
block|}
comment|/// Return a pointer to the beginning of the array of extra parameter
comment|/// information, if present, or else null if none of the parameters
comment|/// carry it.  This is equivalent to getExtProtoInfo().ExtParameterInfos.
specifier|const
name|ExtParameterInfo
operator|*
name|getExtParameterInfosOrNull
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasExtParameterInfos
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|getExtParameterInfosBuffer
argument_list|()
return|;
block|}
name|ExtParameterInfo
name|getExtParameterInfo
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"parameter index out of range"
argument_list|)
block|;
if|if
condition|(
name|hasExtParameterInfos
argument_list|()
condition|)
return|return
name|getExtParameterInfosBuffer
argument_list|()
index|[
name|I
index|]
return|;
return|return
name|ExtParameterInfo
argument_list|()
return|;
block|}
name|ParameterABI
name|getParameterABI
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"parameter index out of range"
argument_list|)
block|;
if|if
condition|(
name|hasExtParameterInfos
argument_list|()
condition|)
return|return
name|getExtParameterInfosBuffer
argument_list|()
index|[
name|I
index|]
operator|.
name|getABI
argument_list|()
return|;
return|return
name|ParameterABI
operator|::
name|Ordinary
return|;
block|}
name|bool
name|isParamConsumed
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"parameter index out of range"
argument_list|)
block|;
if|if
condition|(
name|hasExtParameterInfos
argument_list|()
condition|)
return|return
name|getExtParameterInfosBuffer
argument_list|()
index|[
name|I
index|]
operator|.
name|isConsumed
argument_list|()
return|;
return|return
name|false
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|printExceptionSpecification
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|FunctionProto
return|;
block|}
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
block|;
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Result
argument_list|,
argument|param_type_iterator ArgTys
argument_list|,
argument|unsigned NumArgs
argument_list|,
argument|const ExtProtoInfo&EPI
argument_list|,
argument|const ASTContext&Context
argument_list|,
argument|bool Canonical
argument_list|)
block|; }
block|;
comment|/// \brief Represents the dependent type named by a dependently-scoped
comment|/// typename using declaration, e.g.
comment|///   using typename Base<T>::foo;
comment|///
comment|/// Template instantiation turns these into the underlying type.
name|class
name|UnresolvedUsingType
operator|:
name|public
name|Type
block|{
name|UnresolvedUsingTypenameDecl
operator|*
name|Decl
block|;
name|UnresolvedUsingType
argument_list|(
specifier|const
name|UnresolvedUsingTypenameDecl
operator|*
name|D
argument_list|)
operator|:
name|Type
argument_list|(
name|UnresolvedUsing
argument_list|,
name|QualType
argument_list|()
argument_list|,
name|true
argument_list|,
name|true
argument_list|,
name|false
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|Decl
argument_list|(
argument|const_cast<UnresolvedUsingTypenameDecl*>(D)
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|UnresolvedUsingTypenameDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|Decl
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|UnresolvedUsing
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
return|return
name|Profile
argument_list|(
name|ID
argument_list|,
name|Decl
argument_list|)
return|;
block|}
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|UnresolvedUsingTypenameDecl *D
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
name|class
name|TypedefType
operator|:
name|public
name|Type
block|{
name|TypedefNameDecl
operator|*
name|Decl
block|;
name|protected
operator|:
name|TypedefType
argument_list|(
argument|TypeClass tc
argument_list|,
argument|const TypedefNameDecl *D
argument_list|,
argument|QualType can
argument_list|)
operator|:
name|Type
argument_list|(
name|tc
argument_list|,
name|can
argument_list|,
name|can
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|can
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|can
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|Decl
argument_list|(
argument|const_cast<TypedefNameDecl*>(D)
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|TypedefType
operator|>
operator|(
name|can
operator|)
operator|&&
literal|"Invalid canonical type"
argument_list|)
block|;   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|TypedefNameDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|Decl
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Typedef
return|;
block|}
expr|}
block|;
comment|/// Represents a `typeof` (or __typeof__) expression (a GCC extension).
name|class
name|TypeOfExprType
operator|:
name|public
name|Type
block|{
name|Expr
operator|*
name|TOExpr
block|;
name|protected
operator|:
name|TypeOfExprType
argument_list|(
argument|Expr *E
argument_list|,
argument|QualType can = QualType()
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|Expr
operator|*
name|getUnderlyingExpr
argument_list|()
specifier|const
block|{
return|return
name|TOExpr
return|;
block|}
comment|/// \brief Remove a single level of sugar.
name|QualType
name|desugar
argument_list|()
specifier|const
block|;
comment|/// \brief Returns whether this type directly provides sugar.
name|bool
name|isSugared
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|TypeOfExpr
return|;
block|}
expr|}
block|;
comment|/// \brief Internal representation of canonical, dependent
comment|/// `typeof(expr)` types.
comment|///
comment|/// This class is used internally by the ASTContext to manage
comment|/// canonical, dependent types, only. Clients will only see instances
comment|/// of this class via TypeOfExprType nodes.
name|class
name|DependentTypeOfExprType
operator|:
name|public
name|TypeOfExprType
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
specifier|const
name|ASTContext
operator|&
name|Context
block|;
name|public
operator|:
name|DependentTypeOfExprType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|Expr
operator|*
name|E
argument_list|)
operator|:
name|TypeOfExprType
argument_list|(
name|E
argument_list|)
block|,
name|Context
argument_list|(
argument|Context
argument_list|)
block|{ }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|,
name|getUnderlyingExpr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|Expr
operator|*
name|E
argument_list|)
block|; }
block|;
comment|/// Represents `typeof(type)`, a GCC extension.
name|class
name|TypeOfType
operator|:
name|public
name|Type
block|{
name|QualType
name|TOType
block|;
name|TypeOfType
argument_list|(
argument|QualType T
argument_list|,
argument|QualType can
argument_list|)
operator|:
name|Type
argument_list|(
name|TypeOf
argument_list|,
name|can
argument_list|,
name|T
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|T
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|T
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|T
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|TOType
argument_list|(
argument|T
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|TypedefType
operator|>
operator|(
name|can
operator|)
operator|&&
literal|"Invalid canonical type"
argument_list|)
block|;   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getUnderlyingType
argument_list|()
specifier|const
block|{
return|return
name|TOType
return|;
block|}
comment|/// \brief Remove a single level of sugar.
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|getUnderlyingType
argument_list|()
return|;
block|}
comment|/// \brief Returns whether this type directly provides sugar.
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|TypeOf
return|;
block|}
expr|}
block|;
comment|/// Represents the type `decltype(expr)` (C++11).
name|class
name|DecltypeType
operator|:
name|public
name|Type
block|{
name|Expr
operator|*
name|E
block|;
name|QualType
name|UnderlyingType
block|;
name|protected
operator|:
name|DecltypeType
argument_list|(
argument|Expr *E
argument_list|,
argument|QualType underlyingType
argument_list|,
argument|QualType can = QualType()
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|Expr
operator|*
name|getUnderlyingExpr
argument_list|()
specifier|const
block|{
return|return
name|E
return|;
block|}
name|QualType
name|getUnderlyingType
argument_list|()
specifier|const
block|{
return|return
name|UnderlyingType
return|;
block|}
comment|/// \brief Remove a single level of sugar.
name|QualType
name|desugar
argument_list|()
specifier|const
block|;
comment|/// \brief Returns whether this type directly provides sugar.
name|bool
name|isSugared
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Decltype
return|;
block|}
expr|}
block|;
comment|/// \brief Internal representation of canonical, dependent
comment|/// decltype(expr) types.
comment|///
comment|/// This class is used internally by the ASTContext to manage
comment|/// canonical, dependent types, only. Clients will only see instances
comment|/// of this class via DecltypeType nodes.
name|class
name|DependentDecltypeType
operator|:
name|public
name|DecltypeType
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
specifier|const
name|ASTContext
operator|&
name|Context
block|;
name|public
operator|:
name|DependentDecltypeType
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|Expr
operator|*
name|E
argument_list|)
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|,
name|getUnderlyingExpr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|Expr
operator|*
name|E
argument_list|)
block|; }
block|;
comment|/// A unary type transform, which is a type constructed from another.
name|class
name|UnaryTransformType
operator|:
name|public
name|Type
block|{
name|public
operator|:
expr|enum
name|UTTKind
block|{
name|EnumUnderlyingType
block|}
block|;
name|private
operator|:
comment|/// The untransformed type.
name|QualType
name|BaseType
block|;
comment|/// The transformed type if not dependent, otherwise the same as BaseType.
name|QualType
name|UnderlyingType
block|;
name|UTTKind
name|UKind
block|;
name|protected
operator|:
name|UnaryTransformType
argument_list|(
argument|QualType BaseTy
argument_list|,
argument|QualType UnderlyingTy
argument_list|,
argument|UTTKind UKind
argument_list|,
argument|QualType CanonicalTy
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
name|public
operator|:
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isDependentType
argument_list|()
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|UnderlyingType
return|;
block|}
name|QualType
name|getUnderlyingType
argument_list|()
specifier|const
block|{
return|return
name|UnderlyingType
return|;
block|}
name|QualType
name|getBaseType
argument_list|()
specifier|const
block|{
return|return
name|BaseType
return|;
block|}
name|UTTKind
name|getUTTKind
argument_list|()
specifier|const
block|{
return|return
name|UKind
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|UnaryTransform
return|;
block|}
expr|}
block|;
comment|/// \brief Internal representation of canonical, dependent
comment|/// __underlying_type(type) types.
comment|///
comment|/// This class is used internally by the ASTContext to manage
comment|/// canonical, dependent types, only. Clients will only see instances
comment|/// of this class via UnaryTransformType nodes.
name|class
name|DependentUnaryTransformType
operator|:
name|public
name|UnaryTransformType
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|public
operator|:
name|DependentUnaryTransformType
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|QualType BaseType
argument_list|,
argument|UTTKind UKind
argument_list|)
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getBaseType
argument_list|()
argument_list|,
name|getUTTKind
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType BaseType
argument_list|,
argument|UTTKind UKind
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|BaseType
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|UKind
argument_list|)
block|;   }
block|}
block|;
name|class
name|TagType
operator|:
name|public
name|Type
block|{
comment|/// Stores the TagDecl associated with this type. The decl may point to any
comment|/// TagDecl that declares the entity.
name|TagDecl
operator|*
name|decl
block|;
name|friend
name|class
name|ASTReader
block|;
name|protected
operator|:
name|TagType
argument_list|(
argument|TypeClass TC
argument_list|,
argument|const TagDecl *D
argument_list|,
argument|QualType can
argument_list|)
block|;
name|public
operator|:
name|TagDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|;
comment|/// Determines whether this type is in the process of being defined.
name|bool
name|isBeingDefined
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|>=
name|TagFirst
operator|&&
name|T
operator|->
name|getTypeClass
argument_list|()
operator|<=
name|TagLast
return|;
block|}
expr|}
block|;
comment|/// A helper class that allows the use of isa/cast/dyncast
comment|/// to detect TagType objects of structs/unions/classes.
name|class
name|RecordType
operator|:
name|public
name|TagType
block|{
name|protected
operator|:
name|explicit
name|RecordType
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|D
argument_list|)
operator|:
name|TagType
argument_list|(
argument|Record
argument_list|,
argument|reinterpret_cast<const TagDecl*>(D)
argument_list|,
argument|QualType()
argument_list|)
block|{ }
name|explicit
name|RecordType
argument_list|(
argument|TypeClass TC
argument_list|,
argument|RecordDecl *D
argument_list|)
operator|:
name|TagType
argument_list|(
argument|TC
argument_list|,
argument|reinterpret_cast<const TagDecl*>(D)
argument_list|,
argument|QualType()
argument_list|)
block|{ }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|RecordDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|RecordDecl
operator|*
operator|>
operator|(
name|TagType
operator|::
name|getDecl
argument_list|()
operator|)
return|;
block|}
comment|// FIXME: This predicate is a helper to QualType/Type. It needs to
comment|// recursively check all fields for const-ness. If any field is declared
comment|// const, it needs to return false.
name|bool
name|hasConstFields
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Record
return|;
block|}
expr|}
block|;
comment|/// A helper class that allows the use of isa/cast/dyncast
comment|/// to detect TagType objects of enums.
name|class
name|EnumType
operator|:
name|public
name|TagType
block|{
name|explicit
name|EnumType
argument_list|(
specifier|const
name|EnumDecl
operator|*
name|D
argument_list|)
operator|:
name|TagType
argument_list|(
argument|Enum
argument_list|,
argument|reinterpret_cast<const TagDecl*>(D)
argument_list|,
argument|QualType()
argument_list|)
block|{ }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|EnumDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|EnumDecl
operator|*
operator|>
operator|(
name|TagType
operator|::
name|getDecl
argument_list|()
operator|)
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Enum
return|;
block|}
expr|}
block|;
comment|/// An attributed type is a type to which a type attribute has been applied.
comment|///
comment|/// The "modified type" is the fully-sugared type to which the attributed
comment|/// type was applied; generally it is not canonically equivalent to the
comment|/// attributed type. The "equivalent type" is the minimally-desugared type
comment|/// which the type is canonically equivalent to.
comment|///
comment|/// For example, in the following attributed type:
comment|///     int32_t __attribute__((vector_size(16)))
comment|///   - the modified type is the TypedefType for int32_t
comment|///   - the equivalent type is VectorType(16, int32_t)
comment|///   - the canonical type is VectorType(16, int)
name|class
name|AttributedType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|public
operator|:
comment|// It is really silly to have yet another attribute-kind enum, but
comment|// clang::attr::Kind doesn't currently cover the pure type attrs.
expr|enum
name|Kind
block|{
comment|// Expression operand.
name|attr_address_space
block|,
name|attr_regparm
block|,
name|attr_vector_size
block|,
name|attr_neon_vector_type
block|,
name|attr_neon_polyvector_type
block|,
name|FirstExprOperandKind
operator|=
name|attr_address_space
block|,
name|LastExprOperandKind
operator|=
name|attr_neon_polyvector_type
block|,
comment|// Enumerated operand (string or keyword).
name|attr_objc_gc
block|,
name|attr_objc_ownership
block|,
name|attr_pcs
block|,
name|attr_pcs_vfp
block|,
name|FirstEnumOperandKind
operator|=
name|attr_objc_gc
block|,
name|LastEnumOperandKind
operator|=
name|attr_pcs_vfp
block|,
comment|// No operand.
name|attr_noreturn
block|,
name|attr_cdecl
block|,
name|attr_fastcall
block|,
name|attr_stdcall
block|,
name|attr_thiscall
block|,
name|attr_regcall
block|,
name|attr_pascal
block|,
name|attr_swiftcall
block|,
name|attr_vectorcall
block|,
name|attr_inteloclbicc
block|,
name|attr_ms_abi
block|,
name|attr_sysv_abi
block|,
name|attr_preserve_most
block|,
name|attr_preserve_all
block|,
name|attr_ptr32
block|,
name|attr_ptr64
block|,
name|attr_sptr
block|,
name|attr_uptr
block|,
name|attr_nonnull
block|,
name|attr_nullable
block|,
name|attr_null_unspecified
block|,
name|attr_objc_kindof
block|,
name|attr_objc_inert_unsafe_unretained
block|,   }
block|;
name|private
operator|:
name|QualType
name|ModifiedType
block|;
name|QualType
name|EquivalentType
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// creates these
name|AttributedType
argument_list|(
argument|QualType canon
argument_list|,
argument|Kind attrKind
argument_list|,
argument|QualType modified
argument_list|,
argument|QualType equivalent
argument_list|)
operator|:
name|Type
argument_list|(
name|Attributed
argument_list|,
name|canon
argument_list|,
name|equivalent
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|equivalent
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|equivalent
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|equivalent
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|ModifiedType
argument_list|(
name|modified
argument_list|)
block|,
name|EquivalentType
argument_list|(
argument|equivalent
argument_list|)
block|{
name|AttributedTypeBits
operator|.
name|AttrKind
operator|=
name|attrKind
block|;   }
name|public
operator|:
name|Kind
name|getAttrKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Kind
operator|>
operator|(
name|AttributedTypeBits
operator|.
name|AttrKind
operator|)
return|;
block|}
name|QualType
name|getModifiedType
argument_list|()
specifier|const
block|{
return|return
name|ModifiedType
return|;
block|}
name|QualType
name|getEquivalentType
argument_list|()
specifier|const
block|{
return|return
name|EquivalentType
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|getEquivalentType
argument_list|()
return|;
block|}
comment|/// Does this attribute behave like a type qualifier?
comment|///
comment|/// A type qualifier adjusts a type to provide specialized rules for
comment|/// a specific object, like the standard const and volatile qualifiers.
comment|/// This includes attributes controlling things like nullability,
comment|/// address spaces, and ARC ownership.  The value of the object is still
comment|/// largely described by the modified type.
comment|///
comment|/// In contrast, many type attributes "rewrite" their modified type to
comment|/// produce a fundamentally different type, not necessarily related in any
comment|/// formalizable way to the original type.  For example, calling convention
comment|/// and vector attributes are not simple type qualifiers.
comment|///
comment|/// Type qualifiers are often, but not always, reflected in the canonical
comment|/// type.
name|bool
name|isQualifier
argument_list|()
specifier|const
block|;
name|bool
name|isMSTypeSpec
argument_list|()
specifier|const
block|;
name|bool
name|isCallingConv
argument_list|()
specifier|const
block|;
name|llvm
operator|::
name|Optional
operator|<
name|NullabilityKind
operator|>
name|getImmediateNullability
argument_list|()
specifier|const
block|;
comment|/// Retrieve the attribute kind corresponding to the given
comment|/// nullability kind.
specifier|static
name|Kind
name|getNullabilityAttrKind
argument_list|(
argument|NullabilityKind kind
argument_list|)
block|{
switch|switch
condition|(
name|kind
condition|)
block|{
case|case
name|NullabilityKind
operator|::
name|NonNull
case|:
return|return
name|attr_nonnull
return|;
case|case
name|NullabilityKind
operator|::
name|Nullable
case|:
return|return
name|attr_nullable
return|;
case|case
name|NullabilityKind
operator|::
name|Unspecified
case|:
return|return
name|attr_null_unspecified
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown nullability kind."
argument_list|)
expr_stmt|;
block|}
comment|/// Strip off the top-level nullability annotation on the given
comment|/// type, if it's there.
comment|///
comment|/// \param T The type to strip. If the type is exactly an
comment|/// AttributedType specifying nullability (without looking through
comment|/// type sugar), the nullability is returned and this type changed
comment|/// to the underlying modified type.
comment|///
comment|/// \returns the top-level nullability, if present.
specifier|static
name|Optional
operator|<
name|NullabilityKind
operator|>
name|stripOuterNullability
argument_list|(
name|QualType
operator|&
name|T
argument_list|)
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getAttrKind
argument_list|()
argument_list|,
name|ModifiedType
argument_list|,
name|EquivalentType
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|Kind attrKind
argument_list|,
argument|QualType modified
argument_list|,
argument|QualType equivalent
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|attrKind
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|modified
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|equivalent
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Attributed
return|;
block|}
expr|}
block|;
name|class
name|TemplateTypeParmType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|// Helper data collector for canonical types.
block|struct
name|CanonicalTTPTInfo
block|{
name|unsigned
name|Depth
operator|:
literal|15
block|;
name|unsigned
name|ParameterPack
operator|:
literal|1
block|;
name|unsigned
name|Index
operator|:
literal|16
block|;   }
block|;
expr|union
block|{
comment|// Info for the canonical type.
name|CanonicalTTPTInfo
name|CanTTPTInfo
block|;
comment|// Info for the non-canonical type.
name|TemplateTypeParmDecl
operator|*
name|TTPDecl
block|;   }
block|;
comment|/// Build a non-canonical type.
name|TemplateTypeParmType
argument_list|(
argument|TemplateTypeParmDecl *TTPDecl
argument_list|,
argument|QualType Canon
argument_list|)
operator|:
name|Type
argument_list|(
name|TemplateTypeParm
argument_list|,
name|Canon
argument_list|,
comment|/*Dependent=*/
name|true
argument_list|,
comment|/*InstantiationDependent=*/
name|true
argument_list|,
comment|/*VariablyModified=*/
name|false
argument_list|,
name|Canon
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|TTPDecl
argument_list|(
argument|TTPDecl
argument_list|)
block|{ }
comment|/// Build the canonical type.
name|TemplateTypeParmType
argument_list|(
argument|unsigned D
argument_list|,
argument|unsigned I
argument_list|,
argument|bool PP
argument_list|)
operator|:
name|Type
argument_list|(
argument|TemplateTypeParm
argument_list|,
argument|QualType(this,
literal|0
argument|)
argument_list|,
comment|/*Dependent=*/
argument|true
argument_list|,
comment|/*InstantiationDependent=*/
argument|true
argument_list|,
comment|/*VariablyModified=*/
argument|false
argument_list|,
argument|PP
argument_list|)
block|{
name|CanTTPTInfo
operator|.
name|Depth
operator|=
name|D
block|;
name|CanTTPTInfo
operator|.
name|Index
operator|=
name|I
block|;
name|CanTTPTInfo
operator|.
name|ParameterPack
operator|=
name|PP
block|;   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
specifier|const
name|CanonicalTTPTInfo
operator|&
name|getCanTTPTInfo
argument_list|()
specifier|const
block|{
name|QualType
name|Can
operator|=
name|getCanonicalTypeInternal
argument_list|()
block|;
return|return
name|Can
operator|->
name|castAs
operator|<
name|TemplateTypeParmType
operator|>
operator|(
operator|)
operator|->
name|CanTTPTInfo
return|;
block|}
name|public
operator|:
name|unsigned
name|getDepth
argument_list|()
specifier|const
block|{
return|return
name|getCanTTPTInfo
argument_list|()
operator|.
name|Depth
return|;
block|}
name|unsigned
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|getCanTTPTInfo
argument_list|()
operator|.
name|Index
return|;
block|}
name|bool
name|isParameterPack
argument_list|()
specifier|const
block|{
return|return
name|getCanTTPTInfo
argument_list|()
operator|.
name|ParameterPack
return|;
block|}
name|TemplateTypeParmDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|isCanonicalUnqualified
argument_list|()
operator|?
name|nullptr
operator|:
name|TTPDecl
return|;
block|}
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|;
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getDepth
argument_list|()
argument_list|,
name|getIndex
argument_list|()
argument_list|,
name|isParameterPack
argument_list|()
argument_list|,
name|getDecl
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|unsigned Depth
argument_list|,
argument|unsigned Index
argument_list|,
argument|bool ParameterPack
argument_list|,
argument|TemplateTypeParmDecl *TTPDecl
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|Depth
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|Index
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|ParameterPack
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|TTPDecl
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|TemplateTypeParm
return|;
block|}
expr|}
block|;
comment|/// \brief Represents the result of substituting a type for a template
comment|/// type parameter.
comment|///
comment|/// Within an instantiated template, all template type parameters have
comment|/// been replaced with these.  They are used solely to record that a
comment|/// type was originally written as a template type parameter;
comment|/// therefore they are never canonical.
name|class
name|SubstTemplateTypeParmType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|// The original type parameter.
specifier|const
name|TemplateTypeParmType
operator|*
name|Replaced
block|;
name|SubstTemplateTypeParmType
argument_list|(
argument|const TemplateTypeParmType *Param
argument_list|,
argument|QualType Canon
argument_list|)
operator|:
name|Type
argument_list|(
name|SubstTemplateTypeParm
argument_list|,
name|Canon
argument_list|,
name|Canon
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Canon
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|Canon
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|Canon
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Replaced
argument_list|(
argument|Param
argument_list|)
block|{ }
name|friend
name|class
name|ASTContext
block|;
name|public
operator|:
comment|/// Gets the template parameter that was substituted for.
specifier|const
name|TemplateTypeParmType
operator|*
name|getReplacedParameter
argument_list|()
specifier|const
block|{
return|return
name|Replaced
return|;
block|}
comment|/// Gets the type that was substituted for the template
comment|/// parameter.
name|QualType
name|getReplacementType
argument_list|()
specifier|const
block|{
return|return
name|getCanonicalTypeInternal
argument_list|()
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|getReplacementType
argument_list|()
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getReplacedParameter
argument_list|()
argument_list|,
name|getReplacementType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|const TemplateTypeParmType *Replaced
argument_list|,
argument|QualType Replacement
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Replaced
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|Replacement
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|SubstTemplateTypeParm
return|;
block|}
expr|}
block|;
comment|/// \brief Represents the result of substituting a set of types for a template
comment|/// type parameter pack.
comment|///
comment|/// When a pack expansion in the source code contains multiple parameter packs
comment|/// and those parameter packs correspond to different levels of template
comment|/// parameter lists, this type node is used to represent a template type
comment|/// parameter pack from an outer level, which has already had its argument pack
comment|/// substituted but that still lives within a pack expansion that itself
comment|/// could not be instantiated. When actually performing a substitution into
comment|/// that pack expansion (e.g., when all template parameters have corresponding
comment|/// arguments), this type will be replaced with the \c SubstTemplateTypeParmType
comment|/// at the current pack substitution index.
name|class
name|SubstTemplateTypeParmPackType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief The original type parameter.
specifier|const
name|TemplateTypeParmType
operator|*
name|Replaced
block|;
comment|/// \brief A pointer to the set of template arguments that this
comment|/// parameter pack is instantiated with.
specifier|const
name|TemplateArgument
operator|*
name|Arguments
block|;
comment|/// \brief The number of template arguments in \c Arguments.
name|unsigned
name|NumArguments
block|;
name|SubstTemplateTypeParmPackType
argument_list|(
argument|const TemplateTypeParmType *Param
argument_list|,
argument|QualType Canon
argument_list|,
argument|const TemplateArgument&ArgPack
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
name|public
operator|:
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
return|return
name|Replaced
operator|->
name|getIdentifier
argument_list|()
return|;
block|}
comment|/// Gets the template parameter that was substituted for.
specifier|const
name|TemplateTypeParmType
operator|*
name|getReplacedParameter
argument_list|()
specifier|const
block|{
return|return
name|Replaced
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|TemplateArgument
name|getArgumentPack
argument_list|()
specifier|const
block|;
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
block|;
specifier|static
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
specifier|const
name|TemplateTypeParmType
operator|*
name|Replaced
argument_list|,
specifier|const
name|TemplateArgument
operator|&
name|ArgPack
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|SubstTemplateTypeParmPack
return|;
block|}
expr|}
block|;
comment|/// \brief Common base class for placeholders for types that get replaced by
comment|/// placeholder type deduction: C++11 auto, C++14 decltype(auto), C++17 deduced
comment|/// class template types, and (eventually) constrained type names from the C++
comment|/// Concepts TS.
comment|///
comment|/// These types are usually a placeholder for a deduced type. However, before
comment|/// the initializer is attached, or (usually) if the initializer is
comment|/// type-dependent, there is no deduced type and the type is canonical. In
comment|/// the latter case, it is also a dependent type.
name|class
name|DeducedType
operator|:
name|public
name|Type
block|{
name|protected
operator|:
name|DeducedType
argument_list|(
argument|TypeClass TC
argument_list|,
argument|QualType DeducedAsType
argument_list|,
argument|bool IsDependent
argument_list|,
argument|bool IsInstantiationDependent
argument_list|,
argument|bool ContainsParameterPack
argument_list|)
operator|:
name|Type
argument_list|(
argument|TC
argument_list|,
comment|// FIXME: Retain the sugared deduced type?
argument|DeducedAsType.isNull() ? QualType(this,
literal|0
argument|)                                     : DeducedAsType.getCanonicalType()
argument_list|,
argument|IsDependent
argument_list|,
argument|IsInstantiationDependent
argument_list|,
comment|/*VariablyModified=*/
argument|false
argument_list|,
argument|ContainsParameterPack
argument_list|)
block|{
if|if
condition|(
operator|!
name|DeducedAsType
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|if
condition|(
name|DeducedAsType
operator|->
name|isDependentType
argument_list|()
condition|)
name|setDependent
argument_list|()
expr_stmt|;
if|if
condition|(
name|DeducedAsType
operator|->
name|isInstantiationDependentType
argument_list|()
condition|)
name|setInstantiationDependent
argument_list|()
expr_stmt|;
if|if
condition|(
name|DeducedAsType
operator|->
name|containsUnexpandedParameterPack
argument_list|()
condition|)
name|setContainsUnexpandedParameterPack
argument_list|()
expr_stmt|;
block|}
block|}
name|public
operator|:
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isCanonicalUnqualified
argument_list|()
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|getCanonicalTypeInternal
argument_list|()
return|;
block|}
comment|/// \brief Get the type deduced for this placeholder type, or null if it's
comment|/// either not been deduced or was deduced to a dependent type.
name|QualType
name|getDeducedType
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isCanonicalUnqualified
argument_list|()
operator|?
name|getCanonicalTypeInternal
argument_list|()
operator|:
name|QualType
argument_list|()
return|;
block|}
name|bool
name|isDeduced
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isCanonicalUnqualified
argument_list|()
operator|||
name|isDependentType
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Auto
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|DeducedTemplateSpecialization
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a C++11 auto or C++14 decltype(auto) type.
name|class
name|AutoType
operator|:
name|public
name|DeducedType
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|AutoType
argument_list|(
argument|QualType DeducedAsType
argument_list|,
argument|AutoTypeKeyword Keyword
argument_list|,
argument|bool IsDeducedAsDependent
argument_list|)
operator|:
name|DeducedType
argument_list|(
argument|Auto
argument_list|,
argument|DeducedAsType
argument_list|,
argument|IsDeducedAsDependent
argument_list|,
argument|IsDeducedAsDependent
argument_list|,
comment|/*ContainsPack=*/
argument|false
argument_list|)
block|{
name|AutoTypeBits
operator|.
name|Keyword
operator|=
operator|(
name|unsigned
operator|)
name|Keyword
block|;   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
name|bool
name|isDecltypeAuto
argument_list|()
specifier|const
block|{
return|return
name|getKeyword
argument_list|()
operator|==
name|AutoTypeKeyword
operator|::
name|DecltypeAuto
return|;
block|}
name|AutoTypeKeyword
name|getKeyword
argument_list|()
specifier|const
block|{
return|return
operator|(
name|AutoTypeKeyword
operator|)
name|AutoTypeBits
operator|.
name|Keyword
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getDeducedType
argument_list|()
argument_list|,
name|getKeyword
argument_list|()
argument_list|,
name|isDependentType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Deduced
argument_list|,
argument|AutoTypeKeyword Keyword
argument_list|,
argument|bool IsDependent
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Deduced
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|Keyword
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|IsDependent
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Auto
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a C++17 deduced template specialization type.
name|class
name|DeducedTemplateSpecializationType
operator|:
name|public
name|DeducedType
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// The name of the template whose arguments will be deduced.
name|TemplateName
name|Template
block|;
name|DeducedTemplateSpecializationType
argument_list|(
argument|TemplateName Template
argument_list|,
argument|QualType DeducedAsType
argument_list|,
argument|bool IsDeducedAsDependent
argument_list|)
operator|:
name|DeducedType
argument_list|(
name|DeducedTemplateSpecialization
argument_list|,
name|DeducedAsType
argument_list|,
name|IsDeducedAsDependent
operator|||
name|Template
operator|.
name|isDependent
argument_list|()
argument_list|,
name|IsDeducedAsDependent
operator|||
name|Template
operator|.
name|isInstantiationDependent
argument_list|()
argument_list|,
name|Template
operator|.
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Template
argument_list|(
argument|Template
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
comment|/// Retrieve the name of the template that we are deducing.
name|TemplateName
name|getTemplateName
argument_list|()
specifier|const
block|{
return|return
name|Template
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getTemplateName
argument_list|()
argument_list|,
name|getDeducedType
argument_list|()
argument_list|,
name|isDependentType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|TemplateName Template
argument_list|,
argument|QualType Deduced
argument_list|,
argument|bool IsDependent
argument_list|)
block|{
name|Template
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|Deduced
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|IsDependent
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|DeducedTemplateSpecialization
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a type template specialization; the template
comment|/// must be a class template, a type alias template, or a template
comment|/// template parameter.  A template which cannot be resolved to one of
comment|/// these, e.g. because it is written with a dependent scope
comment|/// specifier, is instead represented as a
comment|/// @c DependentTemplateSpecializationType.
comment|///
comment|/// A non-dependent template specialization type is always "sugar",
comment|/// typically for a \c RecordType.  For example, a class template
comment|/// specialization type of \c vector<int> will refer to a tag type for
comment|/// the instantiation \c std::vector<int, std::allocator<int>>
comment|///
comment|/// Template specializations are dependent if either the template or
comment|/// any of the template arguments are dependent, in which case the
comment|/// type may also be canonical.
comment|///
comment|/// Instances of this type are allocated with a trailing array of
comment|/// TemplateArguments, followed by a QualType representing the
comment|/// non-canonical aliased type when the template is a type alias
comment|/// template.
name|class
name|LLVM_ALIGNAS
argument_list|(
comment|/*alignof(uint64_t)*/
literal|8
argument_list|)
name|TemplateSpecializationType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// The name of the template being specialized.  This is
comment|/// either a TemplateName::Template (in which case it is a
comment|/// ClassTemplateDecl*, a TemplateTemplateParmDecl*, or a
comment|/// TypeAliasTemplateDecl*), a
comment|/// TemplateName::SubstTemplateTemplateParmPack, or a
comment|/// TemplateName::SubstTemplateTemplateParm (in which case the
comment|/// replacement must, recursively, be one of these).
name|TemplateName
name|Template
block|;
comment|/// The number of template arguments named in this class template
comment|/// specialization.
name|unsigned
name|NumArgs
operator|:
literal|31
block|;
comment|/// Whether this template specialization type is a substituted type alias.
name|unsigned
name|TypeAlias
operator|:
literal|1
block|;
name|TemplateSpecializationType
argument_list|(
argument|TemplateName T
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|QualType Canon
argument_list|,
argument|QualType Aliased
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
comment|/// Determine whether any of the given template arguments are dependent.
specifier|static
name|bool
name|anyDependentTemplateArguments
argument_list|(
name|ArrayRef
operator|<
name|TemplateArgumentLoc
operator|>
name|Args
argument_list|,
name|bool
operator|&
name|InstantiationDependent
argument_list|)
block|;
specifier|static
name|bool
name|anyDependentTemplateArguments
argument_list|(
specifier|const
name|TemplateArgumentListInfo
operator|&
argument_list|,
name|bool
operator|&
name|InstantiationDependent
argument_list|)
block|;
comment|/// \brief Print a template argument list, including the '<' and '>'
comment|/// enclosing the template arguments.
specifier|static
name|void
name|PrintTemplateArgumentList
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|,
argument|bool SkipBrackets = false
argument_list|)
block|;
specifier|static
name|void
name|PrintTemplateArgumentList
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|ArrayRef
operator|<
name|TemplateArgumentLoc
operator|>
name|Args
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|)
block|;
specifier|static
name|void
name|PrintTemplateArgumentList
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|)
block|;
comment|/// True if this template specialization type matches a current
comment|/// instantiation in the context in which it is found.
name|bool
name|isCurrentInstantiation
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|InjectedClassNameType
operator|>
operator|(
name|getCanonicalTypeInternal
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Determine if this template specialization type is for a type alias
comment|/// template that has been substituted.
comment|///
comment|/// Nearly every template specialization type whose template is an alias
comment|/// template will be substituted. However, this is not the case when
comment|/// the specialization contains a pack expansion but the template alias
comment|/// does not have a corresponding parameter pack, e.g.,
comment|///
comment|/// \code
comment|/// template<typename T, typename U, typename V> struct S;
comment|/// template<typename T, typename U> using A = S<T, int, U>;
comment|/// template<typename... Ts> struct X {
comment|///   typedef A<Ts...> type; // not a type alias
comment|/// };
comment|/// \endcode
name|bool
name|isTypeAlias
argument_list|()
specifier|const
block|{
return|return
name|TypeAlias
return|;
block|}
comment|/// Get the aliased type, if this is a specialization of a type alias
comment|/// template.
name|QualType
name|getAliasedType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isTypeAlias
argument_list|()
operator|&&
literal|"not a type alias template specialization"
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|QualType
operator|*
operator|>
operator|(
name|end
argument_list|()
operator|)
return|;
block|}
typedef|typedef
specifier|const
name|TemplateArgument
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|getArgs
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|;
comment|// defined inline in TemplateBase.h
comment|/// Retrieve the name of the template that we are specializing.
name|TemplateName
name|getTemplateName
argument_list|()
specifier|const
block|{
return|return
name|Template
return|;
block|}
comment|/// Retrieve the template arguments.
specifier|const
name|TemplateArgument
operator|*
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|TemplateArgument
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// Retrieve the number of template arguments.
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
comment|/// Retrieve a specific template argument as a type.
comment|/// \pre \c isArgType(Arg)
specifier|const
name|TemplateArgument
operator|&
name|getArg
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
comment|// in TemplateBase.h
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|template_arguments
argument_list|()
specifier|const
block|{
return|return
block|{
name|getArgs
argument_list|()
block|,
name|NumArgs
block|}
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isDependentType
argument_list|()
operator|||
name|isCurrentInstantiation
argument_list|()
operator|||
name|isTypeAlias
argument_list|()
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|getCanonicalTypeInternal
argument_list|()
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|const ASTContext&Ctx
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Template
argument_list|,
name|template_arguments
argument_list|()
argument_list|,
name|Ctx
argument_list|)
block|;
if|if
condition|(
name|isTypeAlias
argument_list|()
condition|)
name|getAliasedType
argument_list|()
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|TemplateName T
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|const ASTContext&Context
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|TemplateSpecialization
return|;
block|}
expr|}
block|;
comment|/// The injected class name of a C++ class template or class
comment|/// template partial specialization.  Used to record that a type was
comment|/// spelled with a bare identifier rather than as a template-id; the
comment|/// equivalent for non-templated classes is just RecordType.
comment|///
comment|/// Injected class name types are always dependent.  Template
comment|/// instantiation turns these into RecordTypes.
comment|///
comment|/// Injected class name types are always canonical.  This works
comment|/// because it is impossible to compare an injected class name type
comment|/// with the corresponding non-injected template type, for the same
comment|/// reason that it is impossible to directly compare template
comment|/// parameters from different dependent contexts: injected class name
comment|/// types can only occur within the scope of a particular templated
comment|/// declaration, and within that scope every template specialization
comment|/// will canonicalize to the injected class name (when appropriate
comment|/// according to the rules of the language).
name|class
name|InjectedClassNameType
operator|:
name|public
name|Type
block|{
name|CXXRecordDecl
operator|*
name|Decl
block|;
comment|/// The template specialization which this type represents.
comment|/// For example, in
comment|///   template<class T> class A { ... };
comment|/// this is A<T>, whereas in
comment|///   template<class X, class Y> class A<B<X,Y>> { ... };
comment|/// this is A<B<X,Y>>.
comment|///
comment|/// It is always unqualified, always a template specialization type,
comment|/// and always dependent.
name|QualType
name|InjectedType
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|friend
name|class
name|ASTReader
block|;
comment|// FIXME: ASTContext::getInjectedClassNameType is not
comment|// currently suitable for AST reading, too much
comment|// interdependencies.
name|friend
name|class
name|ASTNodeImporter
block|;
name|InjectedClassNameType
argument_list|(
argument|CXXRecordDecl *D
argument_list|,
argument|QualType TST
argument_list|)
operator|:
name|Type
argument_list|(
name|InjectedClassName
argument_list|,
name|QualType
argument_list|()
argument_list|,
comment|/*Dependent=*/
name|true
argument_list|,
comment|/*InstantiationDependent=*/
name|true
argument_list|,
comment|/*VariablyModified=*/
name|false
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|Decl
argument_list|(
name|D
argument_list|)
block|,
name|InjectedType
argument_list|(
argument|TST
argument_list|)
block|{
name|assert
argument_list|(
name|isa
operator|<
name|TemplateSpecializationType
operator|>
operator|(
name|TST
operator|)
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|TST
operator|.
name|hasQualifiers
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
name|TST
operator|->
name|isDependentType
argument_list|()
argument_list|)
block|;   }
name|public
operator|:
name|QualType
name|getInjectedSpecializationType
argument_list|()
specifier|const
block|{
return|return
name|InjectedType
return|;
block|}
specifier|const
name|TemplateSpecializationType
operator|*
name|getInjectedTST
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|TemplateSpecializationType
operator|>
operator|(
name|InjectedType
operator|.
name|getTypePtr
argument_list|()
operator|)
return|;
block|}
name|TemplateName
name|getTemplateName
argument_list|()
specifier|const
block|{
return|return
name|getInjectedTST
argument_list|()
operator|->
name|getTemplateName
argument_list|()
return|;
block|}
name|CXXRecordDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|;
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|InjectedClassName
return|;
block|}
expr|}
block|;
comment|/// \brief The kind of a tag type.
block|enum
name|TagTypeKind
block|{
comment|/// \brief The "struct" keyword.
name|TTK_Struct
block|,
comment|/// \brief The "__interface" keyword.
name|TTK_Interface
block|,
comment|/// \brief The "union" keyword.
name|TTK_Union
block|,
comment|/// \brief The "class" keyword.
name|TTK_Class
block|,
comment|/// \brief The "enum" keyword.
name|TTK_Enum
block|}
block|;
comment|/// \brief The elaboration keyword that precedes a qualified type name or
comment|/// introduces an elaborated-type-specifier.
block|enum
name|ElaboratedTypeKeyword
block|{
comment|/// \brief The "struct" keyword introduces the elaborated-type-specifier.
name|ETK_Struct
block|,
comment|/// \brief The "__interface" keyword introduces the elaborated-type-specifier.
name|ETK_Interface
block|,
comment|/// \brief The "union" keyword introduces the elaborated-type-specifier.
name|ETK_Union
block|,
comment|/// \brief The "class" keyword introduces the elaborated-type-specifier.
name|ETK_Class
block|,
comment|/// \brief The "enum" keyword introduces the elaborated-type-specifier.
name|ETK_Enum
block|,
comment|/// \brief The "typename" keyword precedes the qualified type name, e.g.,
comment|/// \c typename T::type.
name|ETK_Typename
block|,
comment|/// \brief No keyword precedes the qualified type name.
name|ETK_None
block|}
block|;
comment|/// A helper class for Type nodes having an ElaboratedTypeKeyword.
comment|/// The keyword in stored in the free bits of the base class.
comment|/// Also provides a few static helpers for converting and printing
comment|/// elaborated type keyword and tag type kind enumerations.
name|class
name|TypeWithKeyword
operator|:
name|public
name|Type
block|{
name|protected
operator|:
name|TypeWithKeyword
argument_list|(
argument|ElaboratedTypeKeyword Keyword
argument_list|,
argument|TypeClass tc
argument_list|,
argument|QualType Canonical
argument_list|,
argument|bool Dependent
argument_list|,
argument|bool InstantiationDependent
argument_list|,
argument|bool VariablyModified
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|)
operator|:
name|Type
argument_list|(
argument|tc
argument_list|,
argument|Canonical
argument_list|,
argument|Dependent
argument_list|,
argument|InstantiationDependent
argument_list|,
argument|VariablyModified
argument_list|,
argument|ContainsUnexpandedParameterPack
argument_list|)
block|{
name|TypeWithKeywordBits
operator|.
name|Keyword
operator|=
name|Keyword
block|;   }
name|public
operator|:
name|ElaboratedTypeKeyword
name|getKeyword
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ElaboratedTypeKeyword
operator|>
operator|(
name|TypeWithKeywordBits
operator|.
name|Keyword
operator|)
return|;
block|}
comment|/// Converts a type specifier (DeclSpec::TST) into an elaborated type keyword.
specifier|static
name|ElaboratedTypeKeyword
name|getKeywordForTypeSpec
argument_list|(
argument|unsigned TypeSpec
argument_list|)
block|;
comment|/// Converts a type specifier (DeclSpec::TST) into a tag type kind.
comment|/// It is an error to provide a type specifier which *isn't* a tag kind here.
specifier|static
name|TagTypeKind
name|getTagTypeKindForTypeSpec
argument_list|(
argument|unsigned TypeSpec
argument_list|)
block|;
comment|/// Converts a TagTypeKind into an elaborated type keyword.
specifier|static
name|ElaboratedTypeKeyword
name|getKeywordForTagTypeKind
argument_list|(
argument|TagTypeKind Tag
argument_list|)
block|;
comment|/// Converts an elaborated type keyword into a TagTypeKind.
comment|/// It is an error to provide an elaborated type keyword
comment|/// which *isn't* a tag kind here.
specifier|static
name|TagTypeKind
name|getTagTypeKindForKeyword
argument_list|(
argument|ElaboratedTypeKeyword Keyword
argument_list|)
block|;
specifier|static
name|bool
name|KeywordIsTagTypeKind
argument_list|(
argument|ElaboratedTypeKeyword Keyword
argument_list|)
block|;
specifier|static
name|StringRef
name|getKeywordName
argument_list|(
argument|ElaboratedTypeKeyword Keyword
argument_list|)
block|;
specifier|static
name|StringRef
name|getTagTypeKindName
argument_list|(
argument|TagTypeKind Kind
argument_list|)
block|{
return|return
name|getKeywordName
argument_list|(
name|getKeywordForTagTypeKind
argument_list|(
name|Kind
argument_list|)
argument_list|)
return|;
block|}
name|class
name|CannotCastToThisType
block|{}
block|;
specifier|static
name|CannotCastToThisType
name|classof
argument_list|(
specifier|const
name|Type
operator|*
argument_list|)
block|; }
block|;
comment|/// \brief Represents a type that was referred to using an elaborated type
comment|/// keyword, e.g., struct S, or via a qualified name, e.g., N::M::type,
comment|/// or both.
comment|///
comment|/// This type is used to keep track of a type name as written in the
comment|/// source code, including tag keywords and any nested-name-specifiers.
comment|/// The type itself is always "sugar", used to express what was written
comment|/// in the source code but containing no additional semantic information.
name|class
name|ElaboratedType
operator|:
name|public
name|TypeWithKeyword
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// The nested name specifier containing the qualifier.
name|NestedNameSpecifier
operator|*
name|NNS
block|;
comment|/// The type that this qualified name refers to.
name|QualType
name|NamedType
block|;
name|ElaboratedType
argument_list|(
argument|ElaboratedTypeKeyword Keyword
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|,
argument|QualType NamedType
argument_list|,
argument|QualType CanonType
argument_list|)
operator|:
name|TypeWithKeyword
argument_list|(
name|Keyword
argument_list|,
name|Elaborated
argument_list|,
name|CanonType
argument_list|,
name|NamedType
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|NamedType
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|NamedType
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|NamedType
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|NNS
argument_list|(
name|NNS
argument_list|)
block|,
name|NamedType
argument_list|(
argument|NamedType
argument_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|Keyword
operator|==
name|ETK_None
operator|&&
name|NNS
operator|==
name|nullptr
operator|)
operator|&&
literal|"ElaboratedType cannot have elaborated type keyword "
literal|"and name qualifier both null."
argument_list|)
block|;   }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
operator|~
name|ElaboratedType
argument_list|()
block|;
comment|/// Retrieve the qualification on this type.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|NNS
return|;
block|}
comment|/// Retrieve the type named by the qualified-id.
name|QualType
name|getNamedType
argument_list|()
specifier|const
block|{
return|return
name|NamedType
return|;
block|}
comment|/// Remove a single level of sugar.
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|getNamedType
argument_list|()
return|;
block|}
comment|/// Returns whether this type directly provides sugar.
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getKeyword
argument_list|()
argument_list|,
name|NNS
argument_list|,
name|NamedType
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|ElaboratedTypeKeyword Keyword
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|,
argument|QualType NamedType
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|Keyword
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|NNS
argument_list|)
block|;
name|NamedType
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Elaborated
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a qualified type name for which the type name is
comment|/// dependent.
comment|///
comment|/// DependentNameType represents a class of dependent types that involve a
comment|/// possibly dependent nested-name-specifier (e.g., "T::") followed by a
comment|/// name of a type. The DependentNameType may start with a "typename" (for a
comment|/// typename-specifier), "class", "struct", "union", or "enum" (for a
comment|/// dependent elaborated-type-specifier), or nothing (in contexts where we
comment|/// know that we must be referring to a type, e.g., in a base class specifier).
comment|/// Typically the nested-name-specifier is dependent, but in MSVC compatibility
comment|/// mode, this type is used with non-dependent names to delay name lookup until
comment|/// instantiation.
name|class
name|DependentNameType
operator|:
name|public
name|TypeWithKeyword
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief The nested name specifier containing the qualifier.
name|NestedNameSpecifier
operator|*
name|NNS
block|;
comment|/// \brief The type that this typename specifier refers to.
specifier|const
name|IdentifierInfo
operator|*
name|Name
block|;
name|DependentNameType
argument_list|(
argument|ElaboratedTypeKeyword Keyword
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|,
argument|const IdentifierInfo *Name
argument_list|,
argument|QualType CanonType
argument_list|)
operator|:
name|TypeWithKeyword
argument_list|(
name|Keyword
argument_list|,
name|DependentName
argument_list|,
name|CanonType
argument_list|,
comment|/*Dependent=*/
name|true
argument_list|,
comment|/*InstantiationDependent=*/
name|true
argument_list|,
comment|/*VariablyModified=*/
name|false
argument_list|,
name|NNS
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|NNS
argument_list|(
name|NNS
argument_list|)
block|,
name|Name
argument_list|(
argument|Name
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
comment|/// Retrieve the qualification on this type.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|NNS
return|;
block|}
comment|/// Retrieve the type named by the typename specifier as an identifier.
comment|///
comment|/// This routine will return a non-NULL identifier pointer when the
comment|/// form of the original typename was terminated by an identifier,
comment|/// e.g., "typename T::type".
specifier|const
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getKeyword
argument_list|()
argument_list|,
name|NNS
argument_list|,
name|Name
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|ElaboratedTypeKeyword Keyword
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|,
argument|const IdentifierInfo *Name
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|Keyword
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|NNS
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|Name
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|DependentName
return|;
block|}
expr|}
block|;
comment|/// Represents a template specialization type whose template cannot be
comment|/// resolved, e.g.
comment|///   A<T>::template B<T>
name|class
name|LLVM_ALIGNAS
argument_list|(
comment|/*alignof(uint64_t)*/
literal|8
argument_list|)
name|DependentTemplateSpecializationType
operator|:
name|public
name|TypeWithKeyword
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// The nested name specifier containing the qualifier.
name|NestedNameSpecifier
operator|*
name|NNS
block|;
comment|/// The identifier of the template.
specifier|const
name|IdentifierInfo
operator|*
name|Name
block|;
comment|/// \brief The number of template arguments named in this class template
comment|/// specialization.
name|unsigned
name|NumArgs
block|;
specifier|const
name|TemplateArgument
operator|*
name|getArgBuffer
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|TemplateArgument
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|TemplateArgument
operator|*
name|getArgBuffer
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|TemplateArgument
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|DependentTemplateSpecializationType
argument_list|(
argument|ElaboratedTypeKeyword Keyword
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|,
argument|const IdentifierInfo *Name
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|QualType Canon
argument_list|)
block|;
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|NNS
return|;
block|}
specifier|const
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// \brief Retrieve the template arguments.
specifier|const
name|TemplateArgument
operator|*
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|getArgBuffer
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the number of template arguments.
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
specifier|const
name|TemplateArgument
operator|&
name|getArg
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
comment|// in TemplateBase.h
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|template_arguments
argument_list|()
specifier|const
block|{
return|return
block|{
name|getArgs
argument_list|()
block|,
name|NumArgs
block|}
return|;
block|}
typedef|typedef
specifier|const
name|TemplateArgument
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|getArgs
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|;
comment|// inline in TemplateBase.h
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|const ASTContext&Context
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|,
name|getKeyword
argument_list|()
argument_list|,
name|NNS
argument_list|,
name|Name
argument_list|,
block|{
name|getArgs
argument_list|()
operator|,
name|NumArgs
block|}
block|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|const ASTContext&Context
argument_list|,
argument|ElaboratedTypeKeyword Keyword
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|const IdentifierInfo *Name
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|DependentTemplateSpecialization
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a pack expansion of types.
comment|///
comment|/// Pack expansions are part of C++11 variadic templates. A pack
comment|/// expansion contains a pattern, which itself contains one or more
comment|/// "unexpanded" parameter packs. When instantiated, a pack expansion
comment|/// produces a series of types, each instantiated from the pattern of
comment|/// the expansion, where the Ith instantiation of the pattern uses the
comment|/// Ith arguments bound to each of the unexpanded parameter packs. The
comment|/// pack expansion is considered to "expand" these unexpanded
comment|/// parameter packs.
comment|///
comment|/// \code
comment|/// template<typename ...Types> struct tuple;
comment|///
comment|/// template<typename ...Types>
comment|/// struct tuple_of_references {
comment|///   typedef tuple<Types&...> type;
comment|/// };
comment|/// \endcode
comment|///
comment|/// Here, the pack expansion \c Types&... is represented via a
comment|/// PackExpansionType whose pattern is Types&.
name|class
name|PackExpansionType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief The pattern of the pack expansion.
name|QualType
name|Pattern
block|;
comment|/// \brief The number of expansions that this pack expansion will
comment|/// generate when substituted (+1), or indicates that
comment|///
comment|/// This field will only have a non-zero value when some of the parameter
comment|/// packs that occur within the pattern have been substituted but others have
comment|/// not.
name|unsigned
name|NumExpansions
block|;
name|PackExpansionType
argument_list|(
argument|QualType Pattern
argument_list|,
argument|QualType Canon
argument_list|,
argument|Optional<unsigned> NumExpansions
argument_list|)
operator|:
name|Type
argument_list|(
name|PackExpansion
argument_list|,
name|Canon
argument_list|,
comment|/*Dependent=*/
name|Pattern
operator|->
name|isDependentType
argument_list|()
argument_list|,
comment|/*InstantiationDependent=*/
name|true
argument_list|,
comment|/*VariablyModified=*/
name|Pattern
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|Pattern
argument_list|(
name|Pattern
argument_list|)
block|,
name|NumExpansions
argument_list|(
argument|NumExpansions? *NumExpansions +
literal|1
argument|:
literal|0
argument_list|)
block|{ }
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these
name|public
operator|:
comment|/// \brief Retrieve the pattern of this pack expansion, which is the
comment|/// type that will be repeatedly instantiated when instantiating the
comment|/// pack expansion itself.
name|QualType
name|getPattern
argument_list|()
specifier|const
block|{
return|return
name|Pattern
return|;
block|}
comment|/// \brief Retrieve the number of expansions that this pack expansion will
comment|/// generate, if known.
name|Optional
operator|<
name|unsigned
operator|>
name|getNumExpansions
argument_list|()
specifier|const
block|{
if|if
condition|(
name|NumExpansions
condition|)
return|return
name|NumExpansions
operator|-
literal|1
return|;
return|return
name|None
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Pattern
operator|->
name|isDependentType
argument_list|()
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|isSugared
argument_list|()
operator|?
name|Pattern
operator|:
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getPattern
argument_list|()
argument_list|,
name|getNumExpansions
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Pattern
argument_list|,
argument|Optional<unsigned> NumExpansions
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Pattern
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|NumExpansions
operator|.
name|hasValue
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|NumExpansions
condition|)
name|ID
operator|.
name|AddInteger
argument_list|(
operator|*
name|NumExpansions
argument_list|)
expr_stmt|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|PackExpansion
return|;
block|}
expr|}
block|;
comment|/// This class wraps the list of protocol qualifiers. For types that can
comment|/// take ObjC protocol qualifers, they can subclass this class.
name|template
operator|<
name|class
name|T
operator|>
name|class
name|ObjCProtocolQualifiers
block|{
name|protected
operator|:
name|ObjCProtocolQualifiers
argument_list|()
block|{}
name|ObjCProtocolDecl
operator|*
specifier|const
operator|*
name|getProtocolStorage
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ObjCProtocolQualifiers
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getProtocolStorage
argument_list|()
return|;
block|}
name|ObjCProtocolDecl
operator|*
operator|*
name|getProtocolStorage
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getProtocolStorageImpl
argument_list|()
return|;
block|}
name|void
name|setNumProtocols
argument_list|(
argument|unsigned N
argument_list|)
block|{
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|setNumProtocolsImpl
argument_list|(
name|N
argument_list|)
block|;   }
name|void
name|initialize
argument_list|(
argument|ArrayRef<ObjCProtocolDecl *> protocols
argument_list|)
block|{
name|setNumProtocols
argument_list|(
name|protocols
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
name|getNumProtocols
argument_list|()
operator|==
name|protocols
operator|.
name|size
argument_list|()
operator|&&
literal|"bitfield overflow in protocol count"
argument_list|)
block|;
if|if
condition|(
operator|!
name|protocols
operator|.
name|empty
argument_list|()
condition|)
name|memcpy
argument_list|(
name|getProtocolStorage
argument_list|()
argument_list|,
name|protocols
operator|.
name|data
argument_list|()
argument_list|,
name|protocols
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|ObjCProtocolDecl
operator|*
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|public
operator|:
typedef|typedef
name|ObjCProtocolDecl
modifier|*
specifier|const
modifier|*
name|qual_iterator
typedef|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|qual_iterator
operator|>
name|qual_range
expr_stmt|;
name|qual_range
name|quals
argument_list|()
specifier|const
block|{
return|return
name|qual_range
argument_list|(
name|qual_begin
argument_list|()
argument_list|,
name|qual_end
argument_list|()
argument_list|)
return|;
block|}
name|qual_iterator
name|qual_begin
argument_list|()
specifier|const
block|{
return|return
name|getProtocolStorage
argument_list|()
return|;
block|}
name|qual_iterator
name|qual_end
argument_list|()
specifier|const
block|{
return|return
name|qual_begin
argument_list|()
operator|+
name|getNumProtocols
argument_list|()
return|;
block|}
name|bool
name|qual_empty
argument_list|()
specifier|const
block|{
return|return
name|getNumProtocols
argument_list|()
operator|==
literal|0
return|;
block|}
comment|/// Return the number of qualifying protocols in this type, or 0 if
comment|/// there are none.
name|unsigned
name|getNumProtocols
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getNumProtocolsImpl
argument_list|()
return|;
block|}
comment|/// Fetch a protocol by index.
name|ObjCProtocolDecl
operator|*
name|getProtocol
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumProtocols
argument_list|()
operator|&&
literal|"Out-of-range protocol access"
argument_list|)
block|;
return|return
name|qual_begin
argument_list|()
index|[
name|I
index|]
return|;
block|}
comment|/// Retrieve all of the protocol qualifiers.
name|ArrayRef
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
name|getProtocols
argument_list|()
specifier|const
block|{
return|return
name|ArrayRef
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
operator|(
name|qual_begin
argument_list|()
expr|,
name|getNumProtocols
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
comment|/// Represents a type parameter type in Objective C. It can take
comment|/// a list of protocols.
name|class
name|ObjCTypeParamType
operator|:
name|public
name|Type
block|,
name|public
name|ObjCProtocolQualifiers
operator|<
name|ObjCTypeParamType
operator|>
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|friend
name|class
name|ASTContext
block|;
name|friend
name|class
name|ObjCProtocolQualifiers
operator|<
name|ObjCTypeParamType
operator|>
block|;
comment|/// The number of protocols stored on this type.
name|unsigned
name|NumProtocols
operator|:
literal|6
block|;
name|ObjCTypeParamDecl
operator|*
name|OTPDecl
block|;
comment|/// The protocols are stored after the ObjCTypeParamType node. In the
comment|/// canonical type, the list of protocols are sorted alphabetically
comment|/// and uniqued.
name|ObjCProtocolDecl
operator|*
operator|*
name|getProtocolStorageImpl
argument_list|()
block|;
comment|/// Return the number of qualifying protocols in this interface type,
comment|/// or 0 if there are none.
name|unsigned
name|getNumProtocolsImpl
argument_list|()
specifier|const
block|{
return|return
name|NumProtocols
return|;
block|}
name|void
name|setNumProtocolsImpl
argument_list|(
argument|unsigned N
argument_list|)
block|{
name|NumProtocols
operator|=
name|N
block|;   }
name|ObjCTypeParamType
argument_list|(
argument|const ObjCTypeParamDecl *D
argument_list|,
argument|QualType can
argument_list|,
argument|ArrayRef<ObjCProtocolDecl *> protocols
argument_list|)
block|;
name|public
operator|:
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|getCanonicalTypeInternal
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ObjCTypeParam
return|;
block|}
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
block|;
specifier|static
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
specifier|const
name|ObjCTypeParamDecl
operator|*
name|OTPDecl
argument_list|,
name|ArrayRef
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
name|protocols
argument_list|)
block|;
name|ObjCTypeParamDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|OTPDecl
return|;
block|}
expr|}
block|;
comment|/// Represents a class type in Objective C.
comment|///
comment|/// Every Objective C type is a combination of a base type, a set of
comment|/// type arguments (optional, for parameterized classes) and a list of
comment|/// protocols.
comment|///
comment|/// Given the following declarations:
comment|/// \code
comment|///   \@class C<T>;
comment|///   \@protocol P;
comment|/// \endcode
comment|///
comment|/// 'C' is an ObjCInterfaceType C.  It is sugar for an ObjCObjectType
comment|/// with base C and no protocols.
comment|///
comment|/// 'C<P>' is an unspecialized ObjCObjectType with base C and protocol list [P].
comment|/// 'C<C*>' is a specialized ObjCObjectType with type arguments 'C*' and no
comment|/// protocol list.
comment|/// 'C<C*><P>' is a specialized ObjCObjectType with base C, type arguments 'C*',
comment|/// and protocol list [P].
comment|///
comment|/// 'id' is a TypedefType which is sugar for an ObjCObjectPointerType whose
comment|/// pointee is an ObjCObjectType with base BuiltinType::ObjCIdType
comment|/// and no protocols.
comment|///
comment|/// 'id<P>' is an ObjCObjectPointerType whose pointee is an ObjCObjectType
comment|/// with base BuiltinType::ObjCIdType and protocol list [P].  Eventually
comment|/// this should get its own sugar class to better represent the source.
name|class
name|ObjCObjectType
operator|:
name|public
name|Type
block|,
name|public
name|ObjCProtocolQualifiers
operator|<
name|ObjCObjectType
operator|>
block|{
name|friend
name|class
name|ObjCProtocolQualifiers
operator|<
name|ObjCObjectType
operator|>
block|;
comment|// ObjCObjectType.NumTypeArgs - the number of type arguments stored
comment|// after the ObjCObjectPointerType node.
comment|// ObjCObjectType.NumProtocols - the number of protocols stored
comment|// after the type arguments of ObjCObjectPointerType node.
comment|//
comment|// These protocols are those written directly on the type.  If
comment|// protocol qualifiers ever become additive, the iterators will need
comment|// to get kindof complicated.
comment|//
comment|// In the canonical object type, these are sorted alphabetically
comment|// and uniqued.
comment|/// Either a BuiltinType or an InterfaceType or sugar for either.
name|QualType
name|BaseType
block|;
comment|/// Cached superclass type.
name|mutable
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|ObjCObjectType
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|CachedSuperClassType
block|;
name|QualType
operator|*
name|getTypeArgStorage
argument_list|()
block|;
specifier|const
name|QualType
operator|*
name|getTypeArgStorage
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ObjCObjectType
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getTypeArgStorage
argument_list|()
return|;
block|}
name|ObjCProtocolDecl
operator|*
operator|*
name|getProtocolStorageImpl
argument_list|()
block|;
comment|/// Return the number of qualifying protocols in this interface type,
comment|/// or 0 if there are none.
name|unsigned
name|getNumProtocolsImpl
argument_list|()
specifier|const
block|{
return|return
name|ObjCObjectTypeBits
operator|.
name|NumProtocols
return|;
block|}
name|void
name|setNumProtocolsImpl
argument_list|(
argument|unsigned N
argument_list|)
block|{
name|ObjCObjectTypeBits
operator|.
name|NumProtocols
operator|=
name|N
block|;   }
name|protected
operator|:
name|ObjCObjectType
argument_list|(
argument|QualType Canonical
argument_list|,
argument|QualType Base
argument_list|,
argument|ArrayRef<QualType> typeArgs
argument_list|,
argument|ArrayRef<ObjCProtocolDecl *> protocols
argument_list|,
argument|bool isKindOf
argument_list|)
block|;    enum
name|Nonce_ObjCInterface
block|{
name|Nonce_ObjCInterface
block|}
block|;
name|ObjCObjectType
argument_list|(
expr|enum
name|Nonce_ObjCInterface
argument_list|)
operator|:
name|Type
argument_list|(
name|ObjCInterface
argument_list|,
name|QualType
argument_list|()
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|BaseType
argument_list|(
argument|QualType(this_(),
literal|0
argument|)
argument_list|)
block|{
name|ObjCObjectTypeBits
operator|.
name|NumProtocols
operator|=
literal|0
block|;
name|ObjCObjectTypeBits
operator|.
name|NumTypeArgs
operator|=
literal|0
block|;
name|ObjCObjectTypeBits
operator|.
name|IsKindOf
operator|=
literal|0
block|;   }
name|void
name|computeSuperClassTypeSlow
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Gets the base type of this object type.  This is always (possibly
comment|/// sugar for) one of:
comment|///  - the 'id' builtin type (as opposed to the 'id' type visible to the
comment|///    user, which is a typedef for an ObjCObjectPointerType)
comment|///  - the 'Class' builtin type (same caveat)
comment|///  - an ObjCObjectType (currently always an ObjCInterfaceType)
name|QualType
name|getBaseType
argument_list|()
specifier|const
block|{
return|return
name|BaseType
return|;
block|}
name|bool
name|isObjCId
argument_list|()
specifier|const
block|{
return|return
name|getBaseType
argument_list|()
operator|->
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|ObjCId
argument_list|)
return|;
block|}
name|bool
name|isObjCClass
argument_list|()
specifier|const
block|{
return|return
name|getBaseType
argument_list|()
operator|->
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|ObjCClass
argument_list|)
return|;
block|}
name|bool
name|isObjCUnqualifiedId
argument_list|()
specifier|const
block|{
return|return
name|qual_empty
argument_list|()
operator|&&
name|isObjCId
argument_list|()
return|;
block|}
name|bool
name|isObjCUnqualifiedClass
argument_list|()
specifier|const
block|{
return|return
name|qual_empty
argument_list|()
operator|&&
name|isObjCClass
argument_list|()
return|;
block|}
name|bool
name|isObjCUnqualifiedIdOrClass
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|qual_empty
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|T
init|=
name|getBaseType
argument_list|()
operator|->
name|getAs
operator|<
name|BuiltinType
operator|>
operator|(
operator|)
condition|)
return|return
name|T
operator|->
name|getKind
argument_list|()
operator|==
name|BuiltinType
operator|::
name|ObjCId
operator|||
name|T
operator|->
name|getKind
argument_list|()
operator|==
name|BuiltinType
operator|::
name|ObjCClass
return|;
return|return
name|false
return|;
block|}
name|bool
name|isObjCQualifiedId
argument_list|()
specifier|const
block|{
return|return
operator|!
name|qual_empty
argument_list|()
operator|&&
name|isObjCId
argument_list|()
return|;
block|}
name|bool
name|isObjCQualifiedClass
argument_list|()
specifier|const
block|{
return|return
operator|!
name|qual_empty
argument_list|()
operator|&&
name|isObjCClass
argument_list|()
return|;
block|}
comment|/// Gets the interface declaration for this object type, if the base type
comment|/// really is an interface.
name|ObjCInterfaceDecl
operator|*
name|getInterface
argument_list|()
specifier|const
block|;
comment|/// Determine whether this object type is "specialized", meaning
comment|/// that it has type arguments.
name|bool
name|isSpecialized
argument_list|()
specifier|const
block|;
comment|/// Determine whether this object type was written with type arguments.
name|bool
name|isSpecializedAsWritten
argument_list|()
specifier|const
block|{
return|return
name|ObjCObjectTypeBits
operator|.
name|NumTypeArgs
operator|>
literal|0
return|;
block|}
comment|/// Determine whether this object type is "unspecialized", meaning
comment|/// that it has no type arguments.
name|bool
name|isUnspecialized
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isSpecialized
argument_list|()
return|;
block|}
comment|/// Determine whether this object type is "unspecialized" as
comment|/// written, meaning that it has no type arguments.
name|bool
name|isUnspecializedAsWritten
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isSpecializedAsWritten
argument_list|()
return|;
block|}
comment|/// Retrieve the type arguments of this object type (semantically).
name|ArrayRef
operator|<
name|QualType
operator|>
name|getTypeArgs
argument_list|()
specifier|const
block|;
comment|/// Retrieve the type arguments of this object type as they were
comment|/// written.
name|ArrayRef
operator|<
name|QualType
operator|>
name|getTypeArgsAsWritten
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getTypeArgStorage
argument_list|()
argument_list|,
name|ObjCObjectTypeBits
operator|.
name|NumTypeArgs
argument_list|)
return|;
block|}
comment|/// Whether this is a "__kindof" type as written.
name|bool
name|isKindOfTypeAsWritten
argument_list|()
specifier|const
block|{
return|return
name|ObjCObjectTypeBits
operator|.
name|IsKindOf
return|;
block|}
comment|/// Whether this ia a "__kindof" type (semantically).
name|bool
name|isKindOfType
argument_list|()
specifier|const
block|;
comment|/// Retrieve the type of the superclass of this object type.
comment|///
comment|/// This operation substitutes any type arguments into the
comment|/// superclass of the current class type, potentially producing a
comment|/// specialization of the superclass type. Produces a null type if
comment|/// there is no superclass.
name|QualType
name|getSuperClassType
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|CachedSuperClassType
operator|.
name|getInt
argument_list|()
condition|)
name|computeSuperClassTypeSlow
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|CachedSuperClassType
operator|.
name|getInt
argument_list|()
operator|&&
literal|"Superclass not set?"
argument_list|)
block|;
return|return
name|QualType
argument_list|(
name|CachedSuperClassType
operator|.
name|getPointer
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// Strip off the Objective-C "kindof" type and (with it) any
comment|/// protocol qualifiers.
name|QualType
name|stripObjCKindOfTypeAndQuals
argument_list|(
argument|const ASTContext&ctx
argument_list|)
specifier|const
block|;
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ObjCObject
operator|||
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ObjCInterface
return|;
block|}
expr|}
block|;
comment|/// A class providing a concrete implementation
comment|/// of ObjCObjectType, so as to not increase the footprint of
comment|/// ObjCInterfaceType.  Code outside of ASTContext and the core type
comment|/// system should not reference this type.
name|class
name|ObjCObjectTypeImpl
operator|:
name|public
name|ObjCObjectType
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|friend
name|class
name|ASTContext
block|;
comment|// If anyone adds fields here, ObjCObjectType::getProtocolStorage()
comment|// will need to be modified.
name|ObjCObjectTypeImpl
argument_list|(
argument|QualType Canonical
argument_list|,
argument|QualType Base
argument_list|,
argument|ArrayRef<QualType> typeArgs
argument_list|,
argument|ArrayRef<ObjCProtocolDecl *> protocols
argument_list|,
argument|bool isKindOf
argument_list|)
operator|:
name|ObjCObjectType
argument_list|(
argument|Canonical
argument_list|,
argument|Base
argument_list|,
argument|typeArgs
argument_list|,
argument|protocols
argument_list|,
argument|isKindOf
argument_list|)
block|{}
name|public
operator|:
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
block|;
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType Base
argument_list|,
argument|ArrayRef<QualType> typeArgs
argument_list|,
argument|ArrayRef<ObjCProtocolDecl *> protocols
argument_list|,
argument|bool isKindOf
argument_list|)
block|; }
block|;
specifier|inline
name|QualType
operator|*
name|ObjCObjectType
operator|::
name|getTypeArgStorage
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QualType
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|ObjCObjectTypeImpl
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
operator|)
return|;
block|}
specifier|inline
name|ObjCProtocolDecl
operator|*
operator|*
name|ObjCObjectType
operator|::
name|getProtocolStorageImpl
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|ObjCProtocolDecl
operator|*
operator|*
operator|>
operator|(
name|getTypeArgStorage
argument_list|()
operator|+
name|ObjCObjectTypeBits
operator|.
name|NumTypeArgs
operator|)
return|;
block|}
specifier|inline
name|ObjCProtocolDecl
operator|*
operator|*
name|ObjCTypeParamType
operator|::
name|getProtocolStorageImpl
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|ObjCProtocolDecl
operator|*
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|ObjCTypeParamType
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
operator|)
return|;
block|}
comment|/// Interfaces are the core concept in Objective-C for object oriented design.
comment|/// They basically correspond to C++ classes.  There are two kinds of interface
comment|/// types: normal interfaces like `NSString`, and qualified interfaces, which
comment|/// are qualified with a protocol list like `NSString<NSCopyable, NSAmazing>`.
comment|///
comment|/// ObjCInterfaceType guarantees the following properties when considered
comment|/// as a subtype of its superclass, ObjCObjectType:
comment|///   - There are no protocol qualifiers.  To reinforce this, code which
comment|///     tries to invoke the protocol methods via an ObjCInterfaceType will
comment|///     fail to compile.
comment|///   - It is its own base type.  That is, if T is an ObjCInterfaceType*,
comment|///     T->getBaseType() == QualType(T, 0).
name|class
name|ObjCInterfaceType
operator|:
name|public
name|ObjCObjectType
block|{
name|mutable
name|ObjCInterfaceDecl
operator|*
name|Decl
block|;
name|ObjCInterfaceType
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|D
argument_list|)
operator|:
name|ObjCObjectType
argument_list|(
name|Nonce_ObjCInterface
argument_list|)
block|,
name|Decl
argument_list|(
argument|const_cast<ObjCInterfaceDecl*>(D)
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|friend
name|class
name|ASTReader
block|;
name|friend
name|class
name|ObjCInterfaceDecl
block|;
name|public
operator|:
comment|/// Get the declaration of this interface.
name|ObjCInterfaceDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|Decl
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ObjCInterface
return|;
block|}
comment|// Nonsense to "hide" certain members of ObjCObjectType within this
comment|// class.  People asking for protocols on an ObjCInterfaceType are
comment|// not going to get what they want: ObjCInterfaceTypes are
comment|// guaranteed to have no protocols.
expr|enum
block|{
name|qual_iterator
block|,
name|qual_begin
block|,
name|qual_end
block|,
name|getNumProtocols
block|,
name|getProtocol
block|}
block|; }
block|;
specifier|inline
name|ObjCInterfaceDecl
operator|*
name|ObjCObjectType
operator|::
name|getInterface
argument_list|()
specifier|const
block|{
name|QualType
name|baseType
operator|=
name|getBaseType
argument_list|()
block|;
while|while
condition|(
specifier|const
name|ObjCObjectType
modifier|*
name|ObjT
init|=
name|baseType
operator|->
name|getAs
operator|<
name|ObjCObjectType
operator|>
operator|(
operator|)
condition|)
block|{
if|if
condition|(
specifier|const
name|ObjCInterfaceType
modifier|*
name|T
init|=
name|dyn_cast
operator|<
name|ObjCInterfaceType
operator|>
operator|(
name|ObjT
operator|)
condition|)
return|return
name|T
operator|->
name|getDecl
argument_list|()
return|;
name|baseType
operator|=
name|ObjT
operator|->
name|getBaseType
argument_list|()
expr_stmt|;
block|}
return|return
name|nullptr
return|;
block|}
comment|/// Represents a pointer to an Objective C object.
comment|///
comment|/// These are constructed from pointer declarators when the pointee type is
comment|/// an ObjCObjectType (or sugar for one).  In addition, the 'id' and 'Class'
comment|/// types are typedefs for these, and the protocol-qualified types 'id<P>'
comment|/// and 'Class<P>' are translated into these.
comment|///
comment|/// Pointers to pointers to Objective C objects are still PointerTypes;
comment|/// only the first level of pointer gets it own type implementation.
name|class
name|ObjCObjectPointerType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|PointeeType
block|;
name|ObjCObjectPointerType
argument_list|(
argument|QualType Canonical
argument_list|,
argument|QualType Pointee
argument_list|)
operator|:
name|Type
argument_list|(
name|ObjCObjectPointer
argument_list|,
name|Canonical
argument_list|,
name|Pointee
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|Pointee
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|PointeeType
argument_list|(
argument|Pointee
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
comment|/// Gets the type pointed to by this ObjC pointer.
comment|/// The result will always be an ObjCObjectType or sugar thereof.
name|QualType
name|getPointeeType
argument_list|()
specifier|const
block|{
return|return
name|PointeeType
return|;
block|}
comment|/// Gets the type pointed to by this ObjC pointer.  Always returns non-null.
comment|///
comment|/// This method is equivalent to getPointeeType() except that
comment|/// it discards any typedefs (or other sugar) between this
comment|/// type and the "outermost" object type.  So for:
comment|/// \code
comment|///   \@class A; \@protocol P; \@protocol Q;
comment|///   typedef A<P> AP;
comment|///   typedef A A1;
comment|///   typedef A1<P> A1P;
comment|///   typedef A1P<Q> A1PQ;
comment|/// \endcode
comment|/// For 'A*', getObjectType() will return 'A'.
comment|/// For 'A<P>*', getObjectType() will return 'A<P>'.
comment|/// For 'AP*', getObjectType() will return 'A<P>'.
comment|/// For 'A1*', getObjectType() will return 'A'.
comment|/// For 'A1<P>*', getObjectType() will return 'A1<P>'.
comment|/// For 'A1P*', getObjectType() will return 'A1<P>'.
comment|/// For 'A1PQ*', getObjectType() will return 'A1<Q>', because
comment|///   adding protocols to a protocol-qualified base discards the
comment|///   old qualifiers (for now).  But if it didn't, getObjectType()
comment|///   would return 'A1P<Q>' (and we'd have to make iterating over
comment|///   qualifiers more complicated).
specifier|const
name|ObjCObjectType
operator|*
name|getObjectType
argument_list|()
specifier|const
block|{
return|return
name|PointeeType
operator|->
name|castAs
operator|<
name|ObjCObjectType
operator|>
operator|(
operator|)
return|;
block|}
comment|/// If this pointer points to an Objective C
comment|/// \@interface type, gets the type for that interface.  Any protocol
comment|/// qualifiers on the interface are ignored.
comment|///
comment|/// \return null if the base type for this pointer is 'id' or 'Class'
specifier|const
name|ObjCInterfaceType
operator|*
name|getInterfaceType
argument_list|()
specifier|const
block|;
comment|/// If this pointer points to an Objective \@interface
comment|/// type, gets the declaration for that interface.
comment|///
comment|/// \return null if the base type for this pointer is 'id' or 'Class'
name|ObjCInterfaceDecl
operator|*
name|getInterfaceDecl
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|getInterface
argument_list|()
return|;
block|}
comment|/// True if this is equivalent to the 'id' type, i.e. if
comment|/// its object type is the primitive 'id' type with no protocols.
name|bool
name|isObjCIdType
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isObjCUnqualifiedId
argument_list|()
return|;
block|}
comment|/// True if this is equivalent to the 'Class' type,
comment|/// i.e. if its object tive is the primitive 'Class' type with no protocols.
name|bool
name|isObjCClassType
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isObjCUnqualifiedClass
argument_list|()
return|;
block|}
comment|/// True if this is equivalent to the 'id' or 'Class' type,
name|bool
name|isObjCIdOrClassType
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isObjCUnqualifiedIdOrClass
argument_list|()
return|;
block|}
comment|/// True if this is equivalent to 'id<P>' for some non-empty set of
comment|/// protocols.
name|bool
name|isObjCQualifiedIdType
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isObjCQualifiedId
argument_list|()
return|;
block|}
comment|/// True if this is equivalent to 'Class<P>' for some non-empty set of
comment|/// protocols.
name|bool
name|isObjCQualifiedClassType
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isObjCQualifiedClass
argument_list|()
return|;
block|}
comment|/// Whether this is a "__kindof" type.
name|bool
name|isKindOfType
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isKindOfType
argument_list|()
return|;
block|}
comment|/// Whether this type is specialized, meaning that it has type arguments.
name|bool
name|isSpecialized
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isSpecialized
argument_list|()
return|;
block|}
comment|/// Whether this type is specialized, meaning that it has type arguments.
name|bool
name|isSpecializedAsWritten
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isSpecializedAsWritten
argument_list|()
return|;
block|}
comment|/// Whether this type is unspecialized, meaning that is has no type arguments.
name|bool
name|isUnspecialized
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|isUnspecialized
argument_list|()
return|;
block|}
comment|/// Determine whether this object type is "unspecialized" as
comment|/// written, meaning that it has no type arguments.
name|bool
name|isUnspecializedAsWritten
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isSpecializedAsWritten
argument_list|()
return|;
block|}
comment|/// Retrieve the type arguments for this type.
name|ArrayRef
operator|<
name|QualType
operator|>
name|getTypeArgs
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|getTypeArgs
argument_list|()
return|;
block|}
comment|/// Retrieve the type arguments for this type.
name|ArrayRef
operator|<
name|QualType
operator|>
name|getTypeArgsAsWritten
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|getTypeArgsAsWritten
argument_list|()
return|;
block|}
comment|/// An iterator over the qualifiers on the object type.  Provided
comment|/// for convenience.  This will always iterate over the full set of
comment|/// protocols on a type, not just those provided directly.
typedef|typedef
name|ObjCObjectType
operator|::
name|qual_iterator
name|qual_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|qual_iterator
operator|>
name|qual_range
expr_stmt|;
name|qual_range
name|quals
argument_list|()
specifier|const
block|{
return|return
name|qual_range
argument_list|(
name|qual_begin
argument_list|()
argument_list|,
name|qual_end
argument_list|()
argument_list|)
return|;
block|}
name|qual_iterator
name|qual_begin
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|qual_begin
argument_list|()
return|;
block|}
name|qual_iterator
name|qual_end
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|qual_end
argument_list|()
return|;
block|}
name|bool
name|qual_empty
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|qual_empty
argument_list|()
return|;
block|}
comment|/// Return the number of qualifying protocols on the object type.
name|unsigned
name|getNumProtocols
argument_list|()
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|getNumProtocols
argument_list|()
return|;
block|}
comment|/// Retrieve a qualifying protocol by index on the object type.
name|ObjCProtocolDecl
operator|*
name|getProtocol
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
return|return
name|getObjectType
argument_list|()
operator|->
name|getProtocol
argument_list|(
name|I
argument_list|)
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// Retrieve the type of the superclass of this object pointer type.
comment|///
comment|/// This operation substitutes any type arguments into the
comment|/// superclass of the current class type, potentially producing a
comment|/// pointer to a specialization of the superclass type. Produces a
comment|/// null type if there is no superclass.
name|QualType
name|getSuperClassType
argument_list|()
specifier|const
block|;
comment|/// Strip off the Objective-C "kindof" type and (with it) any
comment|/// protocol qualifiers.
specifier|const
name|ObjCObjectPointerType
operator|*
name|stripObjCKindOfTypeAndQuals
argument_list|(
argument|const ASTContext&ctx
argument_list|)
specifier|const
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getPointeeType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType T
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|ObjCObjectPointer
return|;
block|}
expr|}
block|;
name|class
name|AtomicType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|ValueType
block|;
name|AtomicType
argument_list|(
argument|QualType ValTy
argument_list|,
argument|QualType Canonical
argument_list|)
operator|:
name|Type
argument_list|(
name|Atomic
argument_list|,
name|Canonical
argument_list|,
name|ValTy
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|ValTy
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|ValTy
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|ValTy
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|ValueType
argument_list|(
argument|ValTy
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
comment|/// Gets the type contained by this atomic type, i.e.
comment|/// the type returned by performing an atomic load of this atomic type.
name|QualType
name|getValueType
argument_list|()
specifier|const
block|{
return|return
name|ValueType
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getValueType
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType T
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Atomic
return|;
block|}
expr|}
block|;
comment|/// PipeType - OpenCL20.
name|class
name|PipeType
operator|:
name|public
name|Type
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|QualType
name|ElementType
block|;
name|bool
name|isRead
block|;
name|PipeType
argument_list|(
argument|QualType elemType
argument_list|,
argument|QualType CanonicalPtr
argument_list|,
argument|bool isRead
argument_list|)
operator|:
name|Type
argument_list|(
name|Pipe
argument_list|,
name|CanonicalPtr
argument_list|,
name|elemType
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|elemType
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|elemType
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|elemType
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|ElementType
argument_list|(
name|elemType
argument_list|)
block|,
name|isRead
argument_list|(
argument|isRead
argument_list|)
block|{}
name|friend
name|class
name|ASTContext
block|;
comment|// ASTContext creates these.
name|public
operator|:
name|QualType
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|ElementType
return|;
block|}
name|bool
name|isSugared
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QualType
name|desugar
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getElementType
argument_list|()
argument_list|,
name|isReadOnly
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|QualType T
argument_list|,
argument|bool isRead
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|isRead
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
name|Pipe
return|;
block|}
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|{
return|return
name|isRead
return|;
block|}
expr|}
block|;
comment|/// A qualifier set is used to build a set of qualifiers.
name|class
name|QualifierCollector
operator|:
name|public
name|Qualifiers
block|{
name|public
operator|:
name|QualifierCollector
argument_list|(
argument|Qualifiers Qs = Qualifiers()
argument_list|)
operator|:
name|Qualifiers
argument_list|(
argument|Qs
argument_list|)
block|{}
comment|/// Collect any qualifiers on the given type and return an
comment|/// unqualified type.  The qualifiers are assumed to be consistent
comment|/// with those already in the type.
specifier|const
name|Type
operator|*
name|strip
argument_list|(
argument|QualType type
argument_list|)
block|{
name|addFastQualifiers
argument_list|(
name|type
operator|.
name|getLocalFastQualifiers
argument_list|()
argument_list|)
block|;
if|if
condition|(
operator|!
name|type
operator|.
name|hasLocalNonFastQualifiers
argument_list|()
condition|)
return|return
name|type
operator|.
name|getTypePtrUnsafe
argument_list|()
return|;
specifier|const
name|ExtQuals
operator|*
name|extQuals
operator|=
name|type
operator|.
name|getExtQualsUnsafe
argument_list|()
block|;
name|addConsistentQualifiers
argument_list|(
name|extQuals
operator|->
name|getQualifiers
argument_list|()
argument_list|)
block|;
return|return
name|extQuals
operator|->
name|getBaseType
argument_list|()
return|;
block|}
comment|/// Apply the collected qualifiers to the given type.
name|QualType
name|apply
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|QualType QT
argument_list|)
specifier|const
block|;
comment|/// Apply the collected qualifiers to the given type.
name|QualType
name|apply
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|const Type* T
argument_list|)
specifier|const
block|; }
block|;
comment|// Inline function definitions.
specifier|inline
name|SplitQualType
name|SplitQualType
operator|::
name|getSingleStepDesugaredType
argument_list|()
specifier|const
block|{
name|SplitQualType
name|desugar
operator|=
name|Ty
operator|->
name|getLocallyUnqualifiedSingleStepDesugaredType
argument_list|()
operator|.
name|split
argument_list|()
block|;
name|desugar
operator|.
name|Quals
operator|.
name|addConsistentQualifiers
argument_list|(
name|Quals
argument_list|)
block|;
return|return
name|desugar
return|;
block|}
specifier|inline
specifier|const
name|Type
operator|*
name|QualType
operator|::
name|getTypePtr
argument_list|()
specifier|const
block|{
return|return
name|getCommonPtr
argument_list|()
operator|->
name|BaseType
return|;
block|}
specifier|inline
specifier|const
name|Type
operator|*
name|QualType
operator|::
name|getTypePtrOrNull
argument_list|()
specifier|const
block|{
return|return
operator|(
name|isNull
argument_list|()
operator|?
name|nullptr
operator|:
name|getCommonPtr
argument_list|()
operator|->
name|BaseType
operator|)
return|;
block|}
specifier|inline
name|SplitQualType
name|QualType
operator|::
name|split
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasLocalNonFastQualifiers
argument_list|()
condition|)
return|return
name|SplitQualType
argument_list|(
name|getTypePtrUnsafe
argument_list|()
argument_list|,
name|Qualifiers
operator|::
name|fromFastMask
argument_list|(
name|getLocalFastQualifiers
argument_list|()
argument_list|)
argument_list|)
return|;
specifier|const
name|ExtQuals
operator|*
name|eq
operator|=
name|getExtQualsUnsafe
argument_list|()
block|;
name|Qualifiers
name|qs
operator|=
name|eq
operator|->
name|getQualifiers
argument_list|()
block|;
name|qs
operator|.
name|addFastQualifiers
argument_list|(
name|getLocalFastQualifiers
argument_list|()
argument_list|)
block|;
return|return
name|SplitQualType
argument_list|(
name|eq
operator|->
name|getBaseType
argument_list|()
argument_list|,
name|qs
argument_list|)
return|;
block|}
specifier|inline
name|Qualifiers
name|QualType
operator|::
name|getLocalQualifiers
argument_list|()
specifier|const
block|{
name|Qualifiers
name|Quals
block|;
if|if
condition|(
name|hasLocalNonFastQualifiers
argument_list|()
condition|)
name|Quals
operator|=
name|getExtQualsUnsafe
argument_list|()
operator|->
name|getQualifiers
argument_list|()
expr_stmt|;
name|Quals
operator|.
name|addFastQualifiers
argument_list|(
name|getLocalFastQualifiers
argument_list|()
argument_list|)
block|;
return|return
name|Quals
return|;
block|}
specifier|inline
name|Qualifiers
name|QualType
operator|::
name|getQualifiers
argument_list|()
specifier|const
block|{
name|Qualifiers
name|quals
operator|=
name|getCommonPtr
argument_list|()
operator|->
name|CanonicalType
operator|.
name|getLocalQualifiers
argument_list|()
block|;
name|quals
operator|.
name|addFastQualifiers
argument_list|(
name|getLocalFastQualifiers
argument_list|()
argument_list|)
block|;
return|return
name|quals
return|;
block|}
specifier|inline
name|unsigned
name|QualType
operator|::
name|getCVRQualifiers
argument_list|()
specifier|const
block|{
name|unsigned
name|cvr
operator|=
name|getCommonPtr
argument_list|()
operator|->
name|CanonicalType
operator|.
name|getLocalCVRQualifiers
argument_list|()
block|;
name|cvr
operator||=
name|getLocalCVRQualifiers
argument_list|()
block|;
return|return
name|cvr
return|;
block|}
specifier|inline
name|QualType
name|QualType
operator|::
name|getCanonicalType
argument_list|()
specifier|const
block|{
name|QualType
name|canon
operator|=
name|getCommonPtr
argument_list|()
operator|->
name|CanonicalType
block|;
return|return
name|canon
operator|.
name|withFastQualifiers
argument_list|(
name|getLocalFastQualifiers
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|QualType
operator|::
name|isCanonical
argument_list|()
specifier|const
block|{
return|return
name|getTypePtr
argument_list|()
operator|->
name|isCanonicalUnqualified
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|QualType
operator|::
name|isCanonicalAsParam
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isCanonical
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|hasLocalQualifiers
argument_list|()
condition|)
return|return
name|false
return|;
specifier|const
name|Type
operator|*
name|T
operator|=
name|getTypePtr
argument_list|()
block|;
if|if
condition|(
name|T
operator|->
name|isVariablyModifiedType
argument_list|()
operator|&&
name|T
operator|->
name|hasSizedVLAType
argument_list|()
condition|)
return|return
name|false
return|;
return|return
operator|!
name|isa
operator|<
name|FunctionType
operator|>
operator|(
name|T
operator|)
operator|&&
operator|!
name|isa
operator|<
name|ArrayType
operator|>
operator|(
name|T
operator|)
return|;
block|}
specifier|inline
name|bool
name|QualType
operator|::
name|isConstQualified
argument_list|()
specifier|const
block|{
return|return
name|isLocalConstQualified
argument_list|()
operator|||
name|getCommonPtr
argument_list|()
operator|->
name|CanonicalType
operator|.
name|isLocalConstQualified
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|QualType
operator|::
name|isRestrictQualified
argument_list|()
specifier|const
block|{
return|return
name|isLocalRestrictQualified
argument_list|()
operator|||
name|getCommonPtr
argument_list|()
operator|->
name|CanonicalType
operator|.
name|isLocalRestrictQualified
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|QualType
operator|::
name|isVolatileQualified
argument_list|()
specifier|const
block|{
return|return
name|isLocalVolatileQualified
argument_list|()
operator|||
name|getCommonPtr
argument_list|()
operator|->
name|CanonicalType
operator|.
name|isLocalVolatileQualified
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|QualType
operator|::
name|hasQualifiers
argument_list|()
specifier|const
block|{
return|return
name|hasLocalQualifiers
argument_list|()
operator|||
name|getCommonPtr
argument_list|()
operator|->
name|CanonicalType
operator|.
name|hasLocalQualifiers
argument_list|()
return|;
block|}
specifier|inline
name|QualType
name|QualType
operator|::
name|getUnqualifiedType
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|getTypePtr
argument_list|()
operator|->
name|getCanonicalTypeInternal
argument_list|()
operator|.
name|hasLocalQualifiers
argument_list|()
condition|)
return|return
name|QualType
argument_list|(
name|getTypePtr
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
return|return
name|QualType
argument_list|(
name|getSplitUnqualifiedTypeImpl
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|Ty
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|inline
name|SplitQualType
name|QualType
operator|::
name|getSplitUnqualifiedType
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|getTypePtr
argument_list|()
operator|->
name|getCanonicalTypeInternal
argument_list|()
operator|.
name|hasLocalQualifiers
argument_list|()
condition|)
return|return
name|split
argument_list|()
return|;
return|return
name|getSplitUnqualifiedTypeImpl
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
specifier|inline
name|void
name|QualType
operator|::
name|removeLocalConst
argument_list|()
block|{
name|removeLocalFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Const
argument_list|)
block|; }
specifier|inline
name|void
name|QualType
operator|::
name|removeLocalRestrict
argument_list|()
block|{
name|removeLocalFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Restrict
argument_list|)
block|; }
specifier|inline
name|void
name|QualType
operator|::
name|removeLocalVolatile
argument_list|()
block|{
name|removeLocalFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Volatile
argument_list|)
block|; }
specifier|inline
name|void
name|QualType
operator|::
name|removeLocalCVRQualifiers
argument_list|(
argument|unsigned Mask
argument_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|Mask
operator|&
operator|~
name|Qualifiers
operator|::
name|CVRMask
operator|)
operator|&&
literal|"mask has non-CVR bits"
argument_list|)
block|;
name|static_assert
argument_list|(
operator|(
name|int
operator|)
name|Qualifiers
operator|::
name|CVRMask
operator|==
operator|(
name|int
operator|)
name|Qualifiers
operator|::
name|FastMask
argument_list|,
literal|"Fast bits differ from CVR bits!"
argument_list|)
block|;
comment|// Fast path: we don't need to touch the slow qualifiers.
name|removeLocalFastQualifiers
argument_list|(
name|Mask
argument_list|)
block|; }
comment|/// Return the address space of this type.
specifier|inline
name|unsigned
name|QualType
operator|::
name|getAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getQualifiers
argument_list|()
operator|.
name|getAddressSpace
argument_list|()
return|;
block|}
comment|/// Return the gc attribute of this type.
specifier|inline
name|Qualifiers
operator|::
name|GC
name|QualType
operator|::
name|getObjCGCAttr
argument_list|()
specifier|const
block|{
return|return
name|getQualifiers
argument_list|()
operator|.
name|getObjCGCAttr
argument_list|()
return|;
block|}
specifier|inline
name|FunctionType
operator|::
name|ExtInfo
name|getFunctionExtInfo
argument_list|(
argument|const Type&t
argument_list|)
block|{
if|if
condition|(
specifier|const
name|PointerType
modifier|*
name|PT
init|=
name|t
operator|.
name|getAs
operator|<
name|PointerType
operator|>
operator|(
operator|)
condition|)
block|{
if|if
condition|(
specifier|const
name|FunctionType
modifier|*
name|FT
init|=
name|PT
operator|->
name|getPointeeType
argument_list|()
operator|->
name|getAs
operator|<
name|FunctionType
operator|>
operator|(
operator|)
condition|)
return|return
name|FT
operator|->
name|getExtInfo
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
specifier|const
name|FunctionType
modifier|*
name|FT
init|=
name|t
operator|.
name|getAs
operator|<
name|FunctionType
operator|>
operator|(
operator|)
condition|)
return|return
name|FT
operator|->
name|getExtInfo
argument_list|()
return|;
return|return
name|FunctionType
operator|::
name|ExtInfo
argument_list|()
return|;
block|}
specifier|inline
name|FunctionType
operator|::
name|ExtInfo
name|getFunctionExtInfo
argument_list|(
argument|QualType t
argument_list|)
block|{
return|return
name|getFunctionExtInfo
argument_list|(
operator|*
name|t
argument_list|)
return|;
block|}
comment|/// Determine whether this type is more
comment|/// qualified than the Other type. For example, "const volatile int"
comment|/// is more qualified than "const int", "volatile int", and
comment|/// "int". However, it is not more qualified than "const volatile
comment|/// int".
specifier|inline
name|bool
name|QualType
operator|::
name|isMoreQualifiedThan
argument_list|(
argument|QualType other
argument_list|)
specifier|const
block|{
name|Qualifiers
name|MyQuals
operator|=
name|getQualifiers
argument_list|()
block|;
name|Qualifiers
name|OtherQuals
operator|=
name|other
operator|.
name|getQualifiers
argument_list|()
block|;
return|return
operator|(
name|MyQuals
operator|!=
name|OtherQuals
operator|&&
name|MyQuals
operator|.
name|compatiblyIncludes
argument_list|(
name|OtherQuals
argument_list|)
operator|)
return|;
block|}
comment|/// Determine whether this type is at last
comment|/// as qualified as the Other type. For example, "const volatile
comment|/// int" is at least as qualified as "const int", "volatile int",
comment|/// "int", and "const volatile int".
specifier|inline
name|bool
name|QualType
operator|::
name|isAtLeastAsQualifiedAs
argument_list|(
argument|QualType other
argument_list|)
specifier|const
block|{
name|Qualifiers
name|OtherQuals
operator|=
name|other
operator|.
name|getQualifiers
argument_list|()
block|;
comment|// Ignore __unaligned qualifier if this type is a void.
if|if
condition|(
name|getUnqualifiedType
argument_list|()
operator|->
name|isVoidType
argument_list|()
condition|)
name|OtherQuals
operator|.
name|removeUnaligned
argument_list|()
expr_stmt|;
return|return
name|getQualifiers
argument_list|()
operator|.
name|compatiblyIncludes
argument_list|(
name|OtherQuals
argument_list|)
return|;
block|}
comment|/// If Type is a reference type (e.g., const
comment|/// int&), returns the type that the reference refers to ("const
comment|/// int"). Otherwise, returns the type itself. This routine is used
comment|/// throughout Sema to implement C++ 5p6:
comment|///
comment|///   If an expression initially has the type "reference to T" (8.3.2,
comment|///   8.5.3), the type is adjusted to "T" prior to any further
comment|///   analysis, the expression designates the object or function
comment|///   denoted by the reference, and the expression is an lvalue.
specifier|inline
name|QualType
name|QualType
operator|::
name|getNonReferenceType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ReferenceType
modifier|*
name|RefType
init|=
operator|(
operator|*
name|this
operator|)
operator|->
name|getAs
operator|<
name|ReferenceType
operator|>
operator|(
operator|)
condition|)
return|return
name|RefType
operator|->
name|getPointeeType
argument_list|()
return|;
else|else
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|bool
name|QualType
operator|::
name|isCForbiddenLValueType
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|getTypePtr
argument_list|()
operator|->
name|isVoidType
argument_list|()
operator|&&
operator|!
name|hasQualifiers
argument_list|()
operator|)
operator|||
name|getTypePtr
argument_list|()
operator|->
name|isFunctionType
argument_list|()
operator|)
return|;
block|}
comment|/// Tests whether the type is categorized as a fundamental type.
comment|///
comment|/// \returns True for types specified in C++0x [basic.fundamental].
specifier|inline
name|bool
name|Type
operator|::
name|isFundamentalType
argument_list|()
specifier|const
block|{
return|return
name|isVoidType
argument_list|()
operator|||
comment|// FIXME: It's really annoying that we don't have an
comment|// 'isArithmeticType()' which agrees with the standard definition.
operator|(
name|isArithmeticType
argument_list|()
operator|&&
operator|!
name|isEnumeralType
argument_list|()
operator|)
return|;
block|}
comment|/// Tests whether the type is categorized as a compound type.
comment|///
comment|/// \returns True for types specified in C++0x [basic.compound].
specifier|inline
name|bool
name|Type
operator|::
name|isCompoundType
argument_list|()
specifier|const
block|{
comment|// C++0x [basic.compound]p1:
comment|//   Compound types can be constructed in the following ways:
comment|//    -- arrays of objects of a given type [...];
return|return
name|isArrayType
argument_list|()
operator|||
comment|//    -- functions, which have parameters of given types [...];
name|isFunctionType
argument_list|()
operator|||
comment|//    -- pointers to void or objects or functions [...];
name|isPointerType
argument_list|()
operator|||
comment|//    -- references to objects or functions of a given type. [...]
name|isReferenceType
argument_list|()
operator|||
comment|//    -- classes containing a sequence of objects of various types, [...];
name|isRecordType
argument_list|()
operator|||
comment|//    -- unions, which are classes capable of containing objects of different
comment|//               types at different times;
name|isUnionType
argument_list|()
operator|||
comment|//    -- enumerations, which comprise a set of named constant values. [...];
name|isEnumeralType
argument_list|()
operator|||
comment|//    -- pointers to non-static class members, [...].
name|isMemberPointerType
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isFunctionType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|FunctionType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isPointerType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|PointerType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isAnyPointerType
argument_list|()
specifier|const
block|{
return|return
name|isPointerType
argument_list|()
operator|||
name|isObjCObjectPointerType
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isBlockPointerType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|BlockPointerType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isReferenceType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ReferenceType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isLValueReferenceType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|LValueReferenceType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isRValueReferenceType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|RValueReferenceType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isFunctionPointerType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|PointerType
modifier|*
name|T
init|=
name|getAs
operator|<
name|PointerType
operator|>
operator|(
operator|)
condition|)
return|return
name|T
operator|->
name|getPointeeType
argument_list|()
operator|->
name|isFunctionType
argument_list|()
return|;
else|else
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isMemberPointerType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|MemberPointerType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isMemberFunctionPointerType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|MemberPointerType
modifier|*
name|T
init|=
name|getAs
operator|<
name|MemberPointerType
operator|>
operator|(
operator|)
condition|)
return|return
name|T
operator|->
name|isMemberFunctionPointer
argument_list|()
return|;
else|else
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isMemberDataPointerType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|MemberPointerType
modifier|*
name|T
init|=
name|getAs
operator|<
name|MemberPointerType
operator|>
operator|(
operator|)
condition|)
return|return
name|T
operator|->
name|isMemberDataPointer
argument_list|()
return|;
else|else
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isArrayType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ArrayType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isConstantArrayType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ConstantArrayType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isIncompleteArrayType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|IncompleteArrayType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isVariableArrayType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|VariableArrayType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isDependentSizedArrayType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|DependentSizedArrayType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isBuiltinType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|BuiltinType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isRecordType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|RecordType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isEnumeralType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|EnumType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isAnyComplexType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ComplexType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isVectorType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|VectorType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isExtVectorType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ExtVectorType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCObjectPointerType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ObjCObjectPointerType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCObjectType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ObjCObjectType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCObjectOrInterfaceType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ObjCInterfaceType
operator|>
operator|(
name|CanonicalType
operator|)
operator|||
name|isa
operator|<
name|ObjCObjectType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isAtomicType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|AtomicType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCQualifiedIdType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ObjCObjectPointerType
modifier|*
name|OPT
init|=
name|getAs
operator|<
name|ObjCObjectPointerType
operator|>
operator|(
operator|)
condition|)
return|return
name|OPT
operator|->
name|isObjCQualifiedIdType
argument_list|()
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCQualifiedClassType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ObjCObjectPointerType
modifier|*
name|OPT
init|=
name|getAs
operator|<
name|ObjCObjectPointerType
operator|>
operator|(
operator|)
condition|)
return|return
name|OPT
operator|->
name|isObjCQualifiedClassType
argument_list|()
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCIdType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ObjCObjectPointerType
modifier|*
name|OPT
init|=
name|getAs
operator|<
name|ObjCObjectPointerType
operator|>
operator|(
operator|)
condition|)
return|return
name|OPT
operator|->
name|isObjCIdType
argument_list|()
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCClassType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ObjCObjectPointerType
modifier|*
name|OPT
init|=
name|getAs
operator|<
name|ObjCObjectPointerType
operator|>
operator|(
operator|)
condition|)
return|return
name|OPT
operator|->
name|isObjCClassType
argument_list|()
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCSelType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|PointerType
modifier|*
name|OPT
init|=
name|getAs
operator|<
name|PointerType
operator|>
operator|(
operator|)
condition|)
return|return
name|OPT
operator|->
name|getPointeeType
argument_list|()
operator|->
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|ObjCSel
argument_list|)
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isObjCBuiltinType
argument_list|()
specifier|const
block|{
return|return
name|isObjCIdType
argument_list|()
operator|||
name|isObjCClassType
argument_list|()
operator|||
name|isObjCSelType
argument_list|()
return|;
block|}
define|#
directive|define
name|IMAGE_TYPE
parameter_list|(
name|ImgType
parameter_list|,
name|Id
parameter_list|,
name|SingletonId
parameter_list|,
name|Access
parameter_list|,
name|Suffix
parameter_list|)
define|\
value|inline bool Type::is##Id##Type() const { \     return isSpecificBuiltinType(BuiltinType::Id); \   }
include|#
directive|include
file|"clang/Basic/OpenCLImageTypes.def"
specifier|inline
name|bool
name|Type
operator|::
name|isSamplerT
argument_list|()
specifier|const
block|{
return|return
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|OCLSampler
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isEventT
argument_list|()
specifier|const
block|{
return|return
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|OCLEvent
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isClkEventT
argument_list|()
specifier|const
block|{
return|return
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|OCLClkEvent
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isQueueT
argument_list|()
specifier|const
block|{
return|return
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|OCLQueue
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isReserveIDT
argument_list|()
specifier|const
block|{
return|return
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|OCLReserveID
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isImageType
argument_list|()
specifier|const
block|{
define|#
directive|define
name|IMAGE_TYPE
parameter_list|(
name|ImgType
parameter_list|,
name|Id
parameter_list|,
name|SingletonId
parameter_list|,
name|Access
parameter_list|,
name|Suffix
parameter_list|)
value|is##Id##Type() ||
return|return
include|#
directive|include
file|"clang/Basic/OpenCLImageTypes.def"
literal|0
return|;
comment|// end boolean or operation
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isPipeType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|PipeType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isOpenCLSpecificType
argument_list|()
specifier|const
block|{
return|return
name|isSamplerT
argument_list|()
operator|||
name|isEventT
argument_list|()
operator|||
name|isImageType
argument_list|()
operator|||
name|isClkEventT
argument_list|()
operator|||
name|isQueueT
argument_list|()
operator|||
name|isReserveIDT
argument_list|()
operator|||
name|isPipeType
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isTemplateTypeParmType
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|TemplateTypeParmType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isSpecificBuiltinType
argument_list|(
argument|unsigned K
argument_list|)
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|getAs
operator|<
name|BuiltinType
operator|>
operator|(
operator|)
condition|)
if|if
condition|(
name|BT
operator|->
name|getKind
argument_list|()
operator|==
operator|(
name|BuiltinType
operator|::
name|Kind
operator|)
name|K
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isPlaceholderType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|BT
operator|->
name|isPlaceholderType
argument_list|()
return|;
return|return
name|false
return|;
block|}
specifier|inline
specifier|const
name|BuiltinType
operator|*
name|Type
operator|::
name|getAsPlaceholderType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|this
operator|)
condition|)
if|if
condition|(
name|BT
operator|->
name|isPlaceholderType
argument_list|()
condition|)
return|return
name|BT
return|;
return|return
name|nullptr
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isSpecificPlaceholderType
argument_list|(
argument|unsigned K
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|BuiltinType
operator|::
name|isPlaceholderTypeKind
argument_list|(
operator|(
name|BuiltinType
operator|::
name|Kind
operator|)
name|K
argument_list|)
argument_list|)
block|;
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|this
operator|)
condition|)
return|return
operator|(
name|BT
operator|->
name|getKind
argument_list|()
operator|==
operator|(
name|BuiltinType
operator|::
name|Kind
operator|)
name|K
operator|)
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isNonOverloadPlaceholderType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|BT
operator|->
name|isNonOverloadPlaceholderType
argument_list|()
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isVoidType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|BT
operator|->
name|getKind
argument_list|()
operator|==
name|BuiltinType
operator|::
name|Void
return|;
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|Type
operator|::
name|isHalfType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|BT
operator|->
name|getKind
argument_list|()
operator|==
name|BuiltinType
operator|::
name|Half
return|;
comment|// FIXME: Should we allow complex __fp16? Probably not.
return|return
name|false
return|;
block|}
end_block

begin_expr_stmt
specifier|inline
name|bool
name|Type
operator|::
name|isNullPtrType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|getAs
operator|<
name|BuiltinType
operator|>
operator|(
operator|)
condition|)
return|return
name|BT
operator|->
name|getKind
argument_list|()
operator|==
name|BuiltinType
operator|::
name|NullPtr
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}  bool
name|IsEnumDeclComplete
argument_list|(
name|EnumDecl
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|IsEnumDeclScoped
parameter_list|(
name|EnumDecl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|inline
name|bool
name|Type
operator|::
name|isIntegerType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|BT
operator|->
name|getKind
argument_list|()
operator|>=
name|BuiltinType
operator|::
name|Bool
operator|&&
name|BT
operator|->
name|getKind
argument_list|()
operator|<=
name|BuiltinType
operator|::
name|Int128
return|;
end_expr_stmt

begin_if
if|if
condition|(
specifier|const
name|EnumType
modifier|*
name|ET
init|=
name|dyn_cast
operator|<
name|EnumType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
block|{
comment|// Incomplete enum types are not treated as integer types.
comment|// FIXME: In C++, enum types are never integer types.
return|return
name|IsEnumDeclComplete
argument_list|(
name|ET
operator|->
name|getDecl
argument_list|()
argument_list|)
operator|&&
operator|!
name|IsEnumDeclScoped
argument_list|(
name|ET
operator|->
name|getDecl
argument_list|()
argument_list|)
return|;
block|}
end_if

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}  inline
name|bool
name|Type
operator|::
name|isScalarType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|BT
operator|->
name|getKind
argument_list|()
operator|>
name|BuiltinType
operator|::
name|Void
operator|&&
name|BT
operator|->
name|getKind
argument_list|()
operator|<=
name|BuiltinType
operator|::
name|NullPtr
return|;
end_expr_stmt

begin_if
if|if
condition|(
specifier|const
name|EnumType
modifier|*
name|ET
init|=
name|dyn_cast
operator|<
name|EnumType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
comment|// Enums are scalar types, but only if they are defined.  Incomplete enums
comment|// are not treated as scalar types.
return|return
name|IsEnumDeclComplete
argument_list|(
name|ET
operator|->
name|getDecl
argument_list|()
argument_list|)
return|;
end_if

begin_return
return|return
name|isa
operator|<
name|PointerType
operator|>
operator|(
name|CanonicalType
operator|)
operator|||
name|isa
operator|<
name|BlockPointerType
operator|>
operator|(
name|CanonicalType
operator|)
operator|||
name|isa
operator|<
name|MemberPointerType
operator|>
operator|(
name|CanonicalType
operator|)
operator|||
name|isa
operator|<
name|ComplexType
operator|>
operator|(
name|CanonicalType
operator|)
operator|||
name|isa
operator|<
name|ObjCObjectPointerType
operator|>
operator|(
name|CanonicalType
operator|)
return|;
end_return

begin_expr_stmt
unit|}  inline
name|bool
name|Type
operator|::
name|isIntegralOrEnumerationType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|BT
operator|->
name|getKind
argument_list|()
operator|>=
name|BuiltinType
operator|::
name|Bool
operator|&&
name|BT
operator|->
name|getKind
argument_list|()
operator|<=
name|BuiltinType
operator|::
name|Int128
return|;
end_expr_stmt

begin_comment
comment|// Check for a complete enum type; incomplete enum types are not properly an
end_comment

begin_comment
comment|// enumeration type in the sense required here.
end_comment

begin_if
if|if
condition|(
specifier|const
name|EnumType
modifier|*
name|ET
init|=
name|dyn_cast
operator|<
name|EnumType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|IsEnumDeclComplete
argument_list|(
name|ET
operator|->
name|getDecl
argument_list|()
argument_list|)
return|;
end_if

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}  inline
name|bool
name|Type
operator|::
name|isBooleanType
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|BT
operator|->
name|getKind
argument_list|()
operator|==
name|BuiltinType
operator|::
name|Bool
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}  inline
name|bool
name|Type
operator|::
name|isUndeducedType
argument_list|()
specifier|const
block|{
name|auto
operator|*
name|DT
operator|=
name|getContainedDeducedType
argument_list|()
block|;
return|return
name|DT
operator|&&
operator|!
name|DT
operator|->
name|isDeduced
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determines whether this is a type for which one can define
end_comment

begin_comment
comment|/// an overloaded operator.
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|Type
operator|::
name|isOverloadableType
argument_list|()
specifier|const
block|{
return|return
name|isDependentType
argument_list|()
operator|||
name|isRecordType
argument_list|()
operator|||
name|isEnumeralType
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determines whether this type can decay to a pointer type.
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|Type
operator|::
name|canDecayToPointerType
argument_list|()
specifier|const
block|{
return|return
name|isFunctionType
argument_list|()
operator|||
name|isArrayType
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|Type
operator|::
name|hasPointerRepresentation
argument_list|()
specifier|const
block|{
return|return
operator|(
name|isPointerType
argument_list|()
operator|||
name|isReferenceType
argument_list|()
operator|||
name|isBlockPointerType
argument_list|()
operator|||
name|isObjCObjectPointerType
argument_list|()
operator|||
name|isNullPtrType
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|Type
operator|::
name|hasObjCPointerRepresentation
argument_list|()
specifier|const
block|{
return|return
name|isObjCObjectPointerType
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|Type
operator|*
name|Type
operator|::
name|getBaseElementTypeUnsafe
argument_list|()
specifier|const
block|{
specifier|const
name|Type
operator|*
name|type
operator|=
name|this
block|;
while|while
condition|(
specifier|const
name|ArrayType
modifier|*
name|arrayType
init|=
name|type
operator|->
name|getAsArrayTypeUnsafe
argument_list|()
condition|)
name|type
operator|=
name|arrayType
operator|->
name|getElementType
argument_list|()
operator|.
name|getTypePtr
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|type
return|;
end_return

begin_expr_stmt
unit|}  inline
specifier|const
name|Type
operator|*
name|Type
operator|::
name|getPointeeOrArrayElementType
argument_list|()
specifier|const
block|{
specifier|const
name|Type
operator|*
name|type
operator|=
name|this
block|;
if|if
condition|(
name|type
operator|->
name|isAnyPointerType
argument_list|()
condition|)
return|return
name|type
operator|->
name|getPointeeType
argument_list|()
operator|.
name|getTypePtr
argument_list|()
return|;
elseif|else
if|if
condition|(
name|type
operator|->
name|isArrayType
argument_list|()
condition|)
return|return
name|type
operator|->
name|getBaseElementTypeUnsafe
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|type
return|;
end_return

begin_comment
unit|}
comment|/// Insertion operator for diagnostics.  This allows sending QualType's into a
end_comment

begin_comment
comment|/// diagnostic with<<.
end_comment

begin_expr_stmt
unit|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|QualType
name|T
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
operator|)
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_qualtype
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Insertion operator for partial diagnostics.  This allows sending QualType's
end_comment

begin_comment
comment|/// into a diagnostic with<<.
end_comment

begin_expr_stmt
specifier|inline
specifier|const
name|PartialDiagnostic
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|PartialDiagnostic
operator|&
name|PD
operator|,
name|QualType
name|T
operator|)
block|{
name|PD
operator|.
name|AddTaggedVal
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
operator|)
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_qualtype
argument_list|)
block|;
return|return
name|PD
return|;
block|}
end_expr_stmt

begin_comment
comment|// Helper class template that is used by Type::getAs to ensure that one does
end_comment

begin_comment
comment|// not try to look through a qualified type to get to an array type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|using
name|TypeIsArrayType
operator|=
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
name|std
operator|::
name|is_same
operator|<
name|T
operator|,
name|ArrayType
operator|>
operator|::
name|value
operator|||
name|std
operator|::
name|is_base_of
operator|<
name|ArrayType
operator|,
name|T
operator|>
operator|::
name|value
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Member-template getAs<specific type>'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|Type
operator|::
name|getAs
argument_list|()
specifier|const
block|{
name|static_assert
argument_list|(
operator|!
name|TypeIsArrayType
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"ArrayType cannot be used with getAs!"
argument_list|)
block|;
comment|// If this is directly a T type, return it.
if|if
condition|(
specifier|const
name|T
modifier|*
name|Ty
init|=
name|dyn_cast
operator|<
name|T
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|Ty
return|;
end_expr_stmt

begin_comment
comment|// If the canonical form of this type isn't the right kind, reject it.
end_comment

begin_if
if|if
condition|(
operator|!
name|isa
operator|<
name|T
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|nullptr
return|;
end_if

begin_comment
comment|// If this is a typedef for the type, strip the typedef off without
end_comment

begin_comment
comment|// losing all typedef information.
end_comment

begin_return
return|return
name|cast
operator|<
name|T
operator|>
operator|(
name|getUnqualifiedDesugaredType
argument_list|()
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|Type
operator|::
name|getAsAdjusted
argument_list|()
specifier|const
block|{
name|static_assert
argument_list|(
operator|!
name|TypeIsArrayType
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"ArrayType cannot be used with getAsAdjusted!"
argument_list|)
block|;
comment|// If this is directly a T type, return it.
if|if
condition|(
specifier|const
name|T
modifier|*
name|Ty
init|=
name|dyn_cast
operator|<
name|T
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|Ty
return|;
end_expr_stmt

begin_comment
comment|// If the canonical form of this type isn't the right kind, reject it.
end_comment

begin_if
if|if
condition|(
operator|!
name|isa
operator|<
name|T
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|nullptr
return|;
end_if

begin_comment
comment|// Strip off type adjustments that do not modify the underlying nature of the
end_comment

begin_comment
comment|// type.
end_comment

begin_decl_stmt
specifier|const
name|Type
modifier|*
name|Ty
init|=
name|this
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
name|Ty
condition|)
block|{
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|A
init|=
name|dyn_cast
operator|<
name|AttributedType
operator|>
operator|(
name|Ty
operator|)
condition|)
name|Ty
operator|=
name|A
operator|->
name|getModifiedType
argument_list|()
operator|.
name|getTypePtr
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|E
init|=
name|dyn_cast
operator|<
name|ElaboratedType
operator|>
operator|(
name|Ty
operator|)
condition|)
name|Ty
operator|=
name|E
operator|->
name|desugar
argument_list|()
operator|.
name|getTypePtr
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|P
init|=
name|dyn_cast
operator|<
name|ParenType
operator|>
operator|(
name|Ty
operator|)
condition|)
name|Ty
operator|=
name|P
operator|->
name|desugar
argument_list|()
operator|.
name|getTypePtr
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|A
init|=
name|dyn_cast
operator|<
name|AdjustedType
operator|>
operator|(
name|Ty
operator|)
condition|)
name|Ty
operator|=
name|A
operator|->
name|desugar
argument_list|()
operator|.
name|getTypePtr
argument_list|()
expr_stmt|;
else|else
break|break;
block|}
end_while

begin_comment
comment|// Just because the canonical type is correct does not mean we can use cast<>,
end_comment

begin_comment
comment|// since we may not have stripped off all the sugar down to the base type.
end_comment

begin_return
return|return
name|dyn_cast
operator|<
name|T
operator|>
operator|(
name|Ty
operator|)
return|;
end_return

begin_expr_stmt
unit|}  inline
specifier|const
name|ArrayType
operator|*
name|Type
operator|::
name|getAsArrayTypeUnsafe
argument_list|()
specifier|const
block|{
comment|// If this is directly an array type, return it.
if|if
condition|(
specifier|const
name|ArrayType
modifier|*
name|arr
init|=
name|dyn_cast
operator|<
name|ArrayType
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|arr
return|;
end_expr_stmt

begin_comment
comment|// If the canonical form of this type isn't the right kind, reject it.
end_comment

begin_if
if|if
condition|(
operator|!
name|isa
operator|<
name|ArrayType
operator|>
operator|(
name|CanonicalType
operator|)
condition|)
return|return
name|nullptr
return|;
end_if

begin_comment
comment|// If this is a typedef for the type, strip the typedef off without
end_comment

begin_comment
comment|// losing all typedef information.
end_comment

begin_return
return|return
name|cast
operator|<
name|ArrayType
operator|>
operator|(
name|getUnqualifiedDesugaredType
argument_list|()
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|Type
operator|::
name|castAs
argument_list|()
specifier|const
block|{
name|static_assert
argument_list|(
operator|!
name|TypeIsArrayType
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"ArrayType cannot be used with castAs!"
argument_list|)
block|;
if|if
condition|(
specifier|const
name|T
modifier|*
name|ty
init|=
name|dyn_cast
operator|<
name|T
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|ty
return|;
name|assert
argument_list|(
name|isa
operator|<
name|T
operator|>
operator|(
name|CanonicalType
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|cast
operator|<
name|T
operator|>
operator|(
name|getUnqualifiedDesugaredType
argument_list|()
operator|)
return|;
end_return

begin_expr_stmt
unit|}  inline
specifier|const
name|ArrayType
operator|*
name|Type
operator|::
name|castAsArrayTypeUnsafe
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isa
operator|<
name|ArrayType
operator|>
operator|(
name|CanonicalType
operator|)
argument_list|)
block|;
if|if
condition|(
specifier|const
name|ArrayType
modifier|*
name|arr
init|=
name|dyn_cast
operator|<
name|ArrayType
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|arr
return|;
end_expr_stmt

begin_return
return|return
name|cast
operator|<
name|ArrayType
operator|>
operator|(
name|getUnqualifiedDesugaredType
argument_list|()
operator|)
return|;
end_return

begin_expr_stmt
unit|}  DecayedType
operator|::
name|DecayedType
argument_list|(
argument|QualType OriginalType
argument_list|,
argument|QualType DecayedPtr
argument_list|,
argument|QualType CanonicalPtr
argument_list|)
operator|:
name|AdjustedType
argument_list|(
argument|Decayed
argument_list|,
argument|OriginalType
argument_list|,
argument|DecayedPtr
argument_list|,
argument|CanonicalPtr
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|QualType
name|Adjusted
operator|=
name|getAdjustedType
argument_list|()
block|;
operator|(
name|void
operator|)
name|AttributedType
operator|::
name|stripOuterNullability
argument_list|(
name|Adjusted
argument_list|)
block|;
name|assert
argument_list|(
name|isa
operator|<
name|PointerType
operator|>
operator|(
name|Adjusted
operator|)
argument_list|)
block|;
endif|#
directive|endif
block|}
name|QualType
name|DecayedType
operator|::
name|getPointeeType
argument_list|()
specifier|const
block|{
name|QualType
name|Decayed
operator|=
name|getDecayedType
argument_list|()
block|;
operator|(
name|void
operator|)
name|AttributedType
operator|::
name|stripOuterNullability
argument_list|(
name|Decayed
argument_list|)
block|;
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Decayed
operator|)
operator|->
name|getPointeeType
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

