begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ubsan_type_hash.h ---------------------------------------*- C++ -*-===//
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
comment|// Hashing of types for Clang's undefined behavior checker.
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
name|UBSAN_TYPE_HASH_H
end_ifndef

begin_define
define|#
directive|define
name|UBSAN_TYPE_HASH_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__ubsan
block|{
typedef|typedef
name|uptr
name|HashValue
typedef|;
comment|/// \brief Information about the dynamic type of an object (extracted from its
comment|/// vptr).
name|class
name|DynamicTypeInfo
block|{
specifier|const
name|char
modifier|*
name|MostDerivedTypeName
decl_stmt|;
name|sptr
name|Offset
decl_stmt|;
specifier|const
name|char
modifier|*
name|SubobjectTypeName
decl_stmt|;
name|public
label|:
name|DynamicTypeInfo
argument_list|(
argument|const char *MDTN
argument_list|,
argument|sptr Offset
argument_list|,
argument|const char *STN
argument_list|)
block|:
name|MostDerivedTypeName
argument_list|(
name|MDTN
argument_list|)
operator|,
name|Offset
argument_list|(
name|Offset
argument_list|)
operator|,
name|SubobjectTypeName
argument_list|(
argument|STN
argument_list|)
block|{}
comment|/// Determine whether the object had a valid dynamic type.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|MostDerivedTypeName
return|;
block|}
comment|/// Get the name of the most-derived type of the object.
specifier|const
name|char
operator|*
name|getMostDerivedTypeName
argument_list|()
specifier|const
block|{
return|return
name|MostDerivedTypeName
return|;
block|}
comment|/// Get the offset from the most-derived type to this base class.
name|sptr
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
comment|/// Get the name of the most-derived type at the specified offset.
specifier|const
name|char
operator|*
name|getSubobjectTypeName
argument_list|()
specifier|const
block|{
return|return
name|SubobjectTypeName
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Get information about the dynamic type of an object.
name|DynamicTypeInfo
name|getDynamicTypeInfo
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
function_decl|;
comment|/// \brief Check whether the dynamic type of \p Object has a \p Type subobject
comment|/// at offset 0.
comment|/// \return \c true if the type matches, \c false if not.
name|bool
name|checkDynamicType
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|,
name|void
modifier|*
name|Type
parameter_list|,
name|HashValue
name|Hash
parameter_list|)
function_decl|;
specifier|const
name|unsigned
name|VptrTypeCacheSize
init|=
literal|128
decl_stmt|;
comment|/// \brief A cache of the results of checkDynamicType. \c checkDynamicType would
comment|/// return \c true (modulo hash collisions) if
comment|/// \code
comment|///   __ubsan_vptr_type_cache[Hash % VptrTypeCacheSize] == Hash
comment|/// \endcode
extern|extern
literal|"C"
name|SANITIZER_INTERFACE_ATTRIBUTE
name|HashValue
name|__ubsan_vptr_type_cache
index|[
name|VptrTypeCacheSize
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __ubsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// UBSAN_TYPE_HASH_H
end_comment

end_unit

