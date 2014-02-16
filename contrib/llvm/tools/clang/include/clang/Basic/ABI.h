begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- ABI.h - ABI related declarations ---------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Enums/classes describing ABI related information about constructors,
end_comment

begin_comment
comment|/// destructors and thunks.
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
name|CLANG_BASIC_ABI_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_BASIC_ABI_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief C++ constructor types.
enum|enum
name|CXXCtorType
block|{
name|Ctor_Complete
block|,
comment|///< Complete object ctor
name|Ctor_Base
block|,
comment|///< Base object ctor
name|Ctor_CompleteAllocating
comment|///< Complete object allocating ctor
block|}
enum|;
comment|/// \brief C++ destructor types.
enum|enum
name|CXXDtorType
block|{
name|Dtor_Deleting
block|,
comment|///< Deleting dtor
name|Dtor_Complete
block|,
comment|///< Complete object dtor
name|Dtor_Base
comment|///< Base object dtor
block|}
enum|;
comment|/// \brief A return adjustment.
struct|struct
name|ReturnAdjustment
block|{
comment|/// \brief The non-virtual adjustment from the derived object to its
comment|/// nearest virtual base.
name|int64_t
name|NonVirtual
decl_stmt|;
comment|/// \brief Holds the ABI-specific information about the virtual return
comment|/// adjustment, if needed.
union|union
name|VirtualAdjustment
block|{
comment|// Itanium ABI
struct|struct
block|{
comment|/// \brief The offset (in bytes), relative to the address point
comment|/// of the virtual base class offset.
name|int64_t
name|VBaseOffsetOffset
decl_stmt|;
block|}
name|Itanium
struct|;
comment|// Microsoft ABI
struct|struct
block|{
comment|/// \brief The offset (in bytes) of the vbptr, relative to the beginning
comment|/// of the derived class.
name|uint32_t
name|VBPtrOffset
decl_stmt|;
comment|/// \brief Index of the virtual base in the vbtable.
name|uint32_t
name|VBIndex
decl_stmt|;
block|}
name|Microsoft
struct|;
name|VirtualAdjustment
argument_list|()
block|{
name|memset
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|bool
name|Equals
argument_list|(
specifier|const
name|VirtualAdjustment
operator|&
name|Other
argument_list|)
decl|const
block|{
return|return
name|memcmp
argument_list|(
name|this
argument_list|,
operator|&
name|Other
argument_list|,
sizeof|sizeof
argument_list|(
name|Other
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
name|VirtualAdjustment
name|Zero
block|;
return|return
name|Equals
argument_list|(
name|Zero
argument_list|)
return|;
block|}
name|bool
name|Less
argument_list|(
specifier|const
name|VirtualAdjustment
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
name|memcmp
argument_list|(
name|this
argument_list|,
operator|&
name|RHS
argument_list|,
sizeof|sizeof
argument_list|(
name|RHS
argument_list|)
argument_list|)
operator|<
literal|0
return|;
block|}
block|}
name|Virtual
union|;
name|ReturnAdjustment
argument_list|()
operator|:
name|NonVirtual
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|NonVirtual
operator|&&
name|Virtual
operator|.
name|isEmpty
argument_list|()
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ReturnAdjustment
operator|&
name|LHS
operator|,
specifier|const
name|ReturnAdjustment
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|NonVirtual
operator|==
name|RHS
operator|.
name|NonVirtual
operator|&&
name|LHS
operator|.
name|Virtual
operator|.
name|Equals
argument_list|(
name|RHS
operator|.
name|Virtual
argument_list|)
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ReturnAdjustment
operator|&
name|LHS
operator|,
specifier|const
name|ReturnAdjustment
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ReturnAdjustment
operator|&
name|LHS
operator|,
specifier|const
name|ReturnAdjustment
operator|&
name|RHS
operator|)
block|{
if|if
condition|(
name|LHS
operator|.
name|NonVirtual
operator|<
name|RHS
operator|.
name|NonVirtual
condition|)
return|return
name|true
return|;
return|return
name|LHS
operator|.
name|NonVirtual
operator|==
name|RHS
operator|.
name|NonVirtual
operator|&&
name|LHS
operator|.
name|Virtual
operator|.
name|Less
argument_list|(
name|RHS
operator|.
name|Virtual
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A \c this pointer adjustment.
end_comment

begin_struct
struct|struct
name|ThisAdjustment
block|{
comment|/// \brief The non-virtual adjustment from the derived object to its
comment|/// nearest virtual base.
name|int64_t
name|NonVirtual
decl_stmt|;
comment|/// \brief Holds the ABI-specific information about the virtual this
comment|/// adjustment, if needed.
union|union
name|VirtualAdjustment
block|{
comment|// Itanium ABI
struct|struct
block|{
comment|/// \brief The offset (in bytes), relative to the address point,
comment|/// of the virtual call offset.
name|int64_t
name|VCallOffsetOffset
decl_stmt|;
block|}
name|Itanium
struct|;
struct|struct
block|{
comment|/// \brief The offset of the vtordisp (in bytes), relative to the ECX.
name|int32_t
name|VtordispOffset
decl_stmt|;
comment|/// \brief The offset of the vbptr of the derived class (in bytes),
comment|/// relative to the ECX after vtordisp adjustment.
name|int32_t
name|VBPtrOffset
decl_stmt|;
comment|/// \brief The offset (in bytes) of the vbase offset in the vbtable.
name|int32_t
name|VBOffsetOffset
decl_stmt|;
block|}
name|Microsoft
struct|;
name|VirtualAdjustment
argument_list|()
block|{
name|memset
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|bool
name|Equals
argument_list|(
specifier|const
name|VirtualAdjustment
operator|&
name|Other
argument_list|)
decl|const
block|{
return|return
name|memcmp
argument_list|(
name|this
argument_list|,
operator|&
name|Other
argument_list|,
sizeof|sizeof
argument_list|(
name|Other
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
name|VirtualAdjustment
name|Zero
block|;
return|return
name|Equals
argument_list|(
name|Zero
argument_list|)
return|;
block|}
name|bool
name|Less
argument_list|(
specifier|const
name|VirtualAdjustment
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
name|memcmp
argument_list|(
name|this
argument_list|,
operator|&
name|RHS
argument_list|,
sizeof|sizeof
argument_list|(
name|RHS
argument_list|)
argument_list|)
operator|<
literal|0
return|;
block|}
block|}
name|Virtual
union|;
name|ThisAdjustment
argument_list|()
operator|:
name|NonVirtual
argument_list|(
literal|0
argument_list|)
block|{ }
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|NonVirtual
operator|&&
name|Virtual
operator|.
name|isEmpty
argument_list|()
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ThisAdjustment
operator|&
name|LHS
operator|,
specifier|const
name|ThisAdjustment
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|NonVirtual
operator|==
name|RHS
operator|.
name|NonVirtual
operator|&&
name|LHS
operator|.
name|Virtual
operator|.
name|Equals
argument_list|(
name|RHS
operator|.
name|Virtual
argument_list|)
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ThisAdjustment
operator|&
name|LHS
operator|,
specifier|const
name|ThisAdjustment
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ThisAdjustment
operator|&
name|LHS
operator|,
specifier|const
name|ThisAdjustment
operator|&
name|RHS
operator|)
block|{
if|if
condition|(
name|LHS
operator|.
name|NonVirtual
operator|<
name|RHS
operator|.
name|NonVirtual
condition|)
return|return
name|true
return|;
return|return
name|LHS
operator|.
name|NonVirtual
operator|==
name|RHS
operator|.
name|NonVirtual
operator|&&
name|LHS
operator|.
name|Virtual
operator|.
name|Less
argument_list|(
name|RHS
operator|.
name|Virtual
argument_list|)
return|;
block|}
end_struct

begin_decl_stmt
unit|};
name|class
name|CXXMethodDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The \c this pointer adjustment as well as an optional return
end_comment

begin_comment
comment|/// adjustment for a thunk.
end_comment

begin_struct
struct|struct
name|ThunkInfo
block|{
comment|/// \brief The \c this pointer adjustment.
name|ThisAdjustment
name|This
decl_stmt|;
comment|/// \brief The return adjustment.
name|ReturnAdjustment
name|Return
decl_stmt|;
comment|/// \brief Holds a pointer to the overridden method this thunk is for,
comment|/// if needed by the ABI to distinguish different thunks with equal
comment|/// adjustments. Otherwise, null.
comment|/// CAUTION: In the unlikely event you need to sort ThunkInfos, consider using
comment|/// an ABI-specific comparator.
specifier|const
name|CXXMethodDecl
modifier|*
name|Method
decl_stmt|;
name|ThunkInfo
argument_list|()
operator|:
name|Method
argument_list|(
literal|0
argument_list|)
block|{ }
name|ThunkInfo
argument_list|(
specifier|const
name|ThisAdjustment
operator|&
name|This
argument_list|,
specifier|const
name|ReturnAdjustment
operator|&
name|Return
argument_list|,
specifier|const
name|CXXMethodDecl
operator|*
name|Method
operator|=
literal|0
argument_list|)
operator|:
name|This
argument_list|(
name|This
argument_list|)
operator|,
name|Return
argument_list|(
name|Return
argument_list|)
operator|,
name|Method
argument_list|(
argument|Method
argument_list|)
block|{}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ThunkInfo
operator|&
name|LHS
operator|,
specifier|const
name|ThunkInfo
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|This
operator|==
name|RHS
operator|.
name|This
operator|&&
name|LHS
operator|.
name|Return
operator|==
name|RHS
operator|.
name|Return
operator|&&
name|LHS
operator|.
name|Method
operator|==
name|RHS
operator|.
name|Method
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|This
operator|.
name|isEmpty
argument_list|()
operator|&&
name|Return
operator|.
name|isEmpty
argument_list|()
operator|&&
name|Method
operator|==
literal|0
return|;
block|}
block|}
struct|;
end_struct

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CLANG_BASIC_ABI_H
end_comment

end_unit

