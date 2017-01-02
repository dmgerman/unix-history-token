begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DataBuffer.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_DataBuffer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DataBuffer_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class DataBuffer DataBuffer.h "lldb/Core/DataBuffer.h"
comment|/// @brief A pure virtual protocol class for abstracted data buffers.
comment|///
comment|/// DataBuffer is an abstract class that gets packaged into a shared pointer
comment|/// that can use to implement various ways to store data (on the heap,
comment|/// memory mapped, cached inferior memory). It gets used by DataExtractor
comment|/// so many DataExtractor objects can share the same data and sub-ranges
comment|/// of that shared data, and the last object that contains a reference
comment|/// to the shared data will free it.
comment|///
comment|/// Subclasses can implement as many different constructors or member
comment|/// functions that allow data to be stored in the object's buffer prior
comment|/// to handing the shared data to clients that use these buffers.
comment|///
comment|/// All subclasses must override all of the pure virtual functions as
comment|/// they are used by clients to access the data. Having a common
comment|/// interface allows different ways of storing data, yet using it in
comment|/// one common way.
comment|///
comment|/// This class currently expects all data to be available without any
comment|/// extra calls being made, but we can modify it to optionally get
comment|/// data on demand with some extra function calls to load the data
comment|/// before it gets accessed.
comment|//----------------------------------------------------------------------
name|class
name|DataBuffer
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|///
comment|/// The destructor is virtual as other classes will inherit from
comment|/// this class and be downcast to the DataBuffer pure virtual
comment|/// interface. The virtual destructor ensures that destructing the
comment|/// base class will destruct the class that inherited from it
comment|/// correctly.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|DataBuffer
argument_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Get a pointer to the data.
comment|///
comment|/// @return
comment|///     A pointer to the bytes owned by this object, or NULL if the
comment|///     object contains no bytes.
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|GetBytes
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get a const pointer to the data.
comment|///
comment|/// @return
comment|///     A const pointer to the bytes owned by this object, or NULL
comment|///     if the object contains no bytes.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|uint8_t
operator|*
name|GetBytes
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the number of bytes in the data buffer.
comment|///
comment|/// @return
comment|///     The number of bytes this object currently contains.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|offset_t
name|GetByteSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|GetData
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
name|GetBytes
argument_list|()
operator|,
name|GetByteSize
argument_list|()
operator|)
return|;
block|}
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|GetData
argument_list|()
block|{
return|return
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|(
name|GetBytes
argument_list|()
operator|,
name|GetByteSize
argument_list|()
operator|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// lldb_DataBuffer_h_
end_comment

end_unit

