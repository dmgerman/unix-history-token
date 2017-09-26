begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Flags.h -------------------------------------------------*- C++ -*-===//
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
name|LLDB_UTILITY_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_FLAGS_H
end_define

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Flags Flags.h "lldb/Utility/Flags.h"
comment|/// @brief A class to manage flags.
comment|///
comment|/// The Flags class managed flag bits and allows testing and
comment|/// modification of individual or multiple flag bits.
comment|//----------------------------------------------------------------------
name|class
name|Flags
block|{
name|public
label|:
comment|//----------------------------------------------------------------------
comment|/// The value type for flags is a 32 bit unsigned integer type.
comment|//----------------------------------------------------------------------
typedef|typedef
name|uint32_t
name|ValueType
typedef|;
comment|//----------------------------------------------------------------------
comment|/// Construct with initial flag bit values.
comment|///
comment|/// Constructs this object with \a mask as the initial value for all
comment|/// of the flags.
comment|///
comment|/// @param[in] mask
comment|///     The initial value for all flags.
comment|//----------------------------------------------------------------------
name|Flags
argument_list|(
argument|ValueType flags =
literal|0
argument_list|)
block|:
name|m_flags
argument_list|(
argument|flags
argument_list|)
block|{}
comment|//----------------------------------------------------------------------
comment|/// Copy constructor.
comment|///
comment|/// Construct and copy the flags from \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const Flags object reference to copy.
comment|//----------------------------------------------------------------------
name|Flags
argument_list|(
specifier|const
name|Flags
operator|&
name|rhs
argument_list|)
operator|:
name|m_flags
argument_list|(
argument|rhs.m_flags
argument_list|)
block|{}
comment|//----------------------------------------------------------------------
comment|/// Destructor.
comment|//----------------------------------------------------------------------
operator|~
name|Flags
argument_list|()
block|{}
comment|//----------------------------------------------------------------------
comment|/// Get accessor for all flags.
comment|///
comment|/// @return
comment|///     Returns all of the flags as a Flags::ValueType.
comment|//----------------------------------------------------------------------
name|ValueType
name|Get
argument_list|()
specifier|const
block|{
return|return
name|m_flags
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Return the number of flags that can be represented in this
comment|/// object.
comment|///
comment|/// @return
comment|///     The maximum number bits in this flag object.
comment|//----------------------------------------------------------------------
name|size_t
name|GetBitSize
argument_list|()
specifier|const
block|{
return|return
sizeof|sizeof
argument_list|(
name|ValueType
argument_list|)
operator|*
literal|8
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Set accessor for all flags.
comment|///
comment|/// @param[in] flags
comment|///     The bits with which to replace all of the current flags.
comment|//----------------------------------------------------------------------
name|void
name|Reset
parameter_list|(
name|ValueType
name|flags
parameter_list|)
block|{
name|m_flags
operator|=
name|flags
expr_stmt|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Clear one or more flags.
comment|///
comment|/// @param[in] mask
comment|///     A bitfield containing one or more flags.
comment|///
comment|/// @return
comment|///     The new flags after clearing all bits from \a mask.
comment|//----------------------------------------------------------------------
name|ValueType
name|Clear
parameter_list|(
name|ValueType
name|mask
init|=
operator|~
operator|(
name|ValueType
operator|)
literal|0
parameter_list|)
block|{
name|m_flags
operator|&=
operator|~
name|mask
expr_stmt|;
return|return
name|m_flags
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Set one or more flags by logical OR'ing \a mask with the current
comment|/// flags.
comment|///
comment|/// @param[in] mask
comment|///     A bitfield containing one or more flags.
comment|///
comment|/// @return
comment|///     The new flags after setting all bits from \a mask.
comment|//----------------------------------------------------------------------
name|ValueType
name|Set
parameter_list|(
name|ValueType
name|mask
parameter_list|)
block|{
name|m_flags
operator||=
name|mask
expr_stmt|;
return|return
name|m_flags
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Test if all bits in \a mask are 1 in the current flags
comment|///
comment|/// @return
comment|///     \b true if all flags in \a mask are 1, \b false
comment|///     otherwise.
comment|//----------------------------------------------------------------------
name|bool
name|AllSet
argument_list|(
name|ValueType
name|mask
argument_list|)
decl|const
block|{
return|return
operator|(
name|m_flags
operator|&
name|mask
operator|)
operator|==
name|mask
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Test one or more flags.
comment|///
comment|/// @return
comment|///     \b true if any flags in \a mask are 1, \b false
comment|///     otherwise.
comment|//----------------------------------------------------------------------
name|bool
name|AnySet
argument_list|(
name|ValueType
name|mask
argument_list|)
decl|const
block|{
return|return
operator|(
name|m_flags
operator|&
name|mask
operator|)
operator|!=
literal|0
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Test a single flag bit.
comment|///
comment|/// @return
comment|///     \b true if \a bit is set, \b false otherwise.
comment|//----------------------------------------------------------------------
name|bool
name|Test
argument_list|(
name|ValueType
name|bit
argument_list|)
decl|const
block|{
return|return
operator|(
name|m_flags
operator|&
name|bit
operator|)
operator|!=
literal|0
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Test if all bits in \a mask are clear.
comment|///
comment|/// @return
comment|///     \b true if \b all flags in \a mask are clear, \b false
comment|///     otherwise.
comment|//----------------------------------------------------------------------
name|bool
name|AllClear
argument_list|(
name|ValueType
name|mask
argument_list|)
decl|const
block|{
return|return
operator|(
name|m_flags
operator|&
name|mask
operator|)
operator|==
literal|0
return|;
block|}
name|bool
name|AnyClear
argument_list|(
name|ValueType
name|mask
argument_list|)
decl|const
block|{
return|return
operator|(
name|m_flags
operator|&
name|mask
operator|)
operator|!=
name|mask
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Test a single flag bit to see if it is clear (zero).
comment|///
comment|/// @return
comment|///     \b true if \a bit is 0, \b false otherwise.
comment|//----------------------------------------------------------------------
name|bool
name|IsClear
argument_list|(
name|ValueType
name|bit
argument_list|)
decl|const
block|{
return|return
operator|(
name|m_flags
operator|&
name|bit
operator|)
operator|==
literal|0
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Get the number of zero bits in \a m_flags.
comment|///
comment|/// @return
comment|///     The number of bits that are set to 0 in the current flags.
comment|//----------------------------------------------------------------------
name|size_t
name|ClearCount
argument_list|()
specifier|const
block|{
name|size_t
name|count
operator|=
literal|0
block|;
for|for
control|(
name|ValueType
name|shift
init|=
literal|0
init|;
name|shift
operator|<
sizeof|sizeof
argument_list|(
name|ValueType
argument_list|)
operator|*
literal|8
condition|;
operator|++
name|shift
control|)
block|{
if|if
condition|(
operator|(
name|m_flags
operator|&
operator|(
literal|1u
operator|<<
name|shift
operator|)
operator|)
operator|==
literal|0
condition|)
operator|++
name|count
expr_stmt|;
block|}
return|return
name|count
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Get the number of one bits in \a m_flags.
comment|///
comment|/// @return
comment|///     The number of bits that are set to 1 in the current flags.
comment|//----------------------------------------------------------------------
name|size_t
name|SetCount
argument_list|()
specifier|const
block|{
name|size_t
name|count
operator|=
literal|0
block|;
for|for
control|(
name|ValueType
name|mask
init|=
name|m_flags
init|;
name|mask
condition|;
name|mask
operator|>>=
literal|1
control|)
block|{
if|if
condition|(
name|mask
operator|&
literal|1u
condition|)
operator|++
name|count
expr_stmt|;
block|}
return|return
name|count
return|;
block|}
name|protected
label|:
name|ValueType
name|m_flags
decl_stmt|;
comment|///< The flags.
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
comment|// liblldb_Flags_h_
end_comment

end_unit

