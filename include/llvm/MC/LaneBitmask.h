begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/LaneBitmask.h ------------------------------------*- C++ -*-===//
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
comment|/// A common definition of LaneBitmask for use in TableGen and CodeGen.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A lane mask is a bitmask representing the covering of a register with
end_comment

begin_comment
comment|/// sub-registers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is typically used to track liveness at sub-register granularity.
end_comment

begin_comment
comment|/// Lane masks for sub-register indices are similar to register units for
end_comment

begin_comment
comment|/// physical registers. The individual bits in a lane mask can't be assigned
end_comment

begin_comment
comment|/// any specific meaning. They can be used to check if two sub-register
end_comment

begin_comment
comment|/// indices overlap.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Iff the target has a register such that:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   getSubReg(Reg, A) overlaps getSubReg(Reg, B)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// then:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   (getSubRegIndexLaneMask(A)& getSubRegIndexLaneMask(B)) != 0
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_LANEBITMASK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_LANEBITMASK_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Printable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct|struct
name|LaneBitmask
block|{
comment|// When changing the underlying type, change the format string as well.
name|using
name|Type
init|=
name|unsigned
decl_stmt|;
enum_decl|enum :
name|unsigned
block|{
name|BitWidth
init|=
literal|8
operator|*
expr|sizeof
operator|(
name|Type
operator|)
block|}
enum_decl|;
name|constexpr
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|FormatStr
init|=
literal|"%08X"
decl_stmt|;
name|constexpr
name|LaneBitmask
parameter_list|()
init|=
init|default
function_decl|;
name|explicit
name|constexpr
name|LaneBitmask
argument_list|(
argument|Type V
argument_list|)
block|:
name|Mask
argument_list|(
argument|V
argument_list|)
block|{}
name|constexpr
name|bool
name|operator
operator|==
operator|(
name|LaneBitmask
name|M
operator|)
specifier|const
block|{
return|return
name|Mask
operator|==
name|M
operator|.
name|Mask
return|;
block|}
name|constexpr
name|bool
name|operator
operator|!=
operator|(
name|LaneBitmask
name|M
operator|)
specifier|const
block|{
return|return
name|Mask
operator|!=
name|M
operator|.
name|Mask
return|;
block|}
name|constexpr
name|bool
name|operator
operator|<
operator|(
name|LaneBitmask
name|M
operator|)
specifier|const
block|{
return|return
name|Mask
operator|<
name|M
operator|.
name|Mask
return|;
block|}
name|constexpr
name|bool
name|none
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|==
literal|0
return|;
block|}
name|constexpr
name|bool
name|any
argument_list|()
specifier|const
block|{
return|return
name|Mask
operator|!=
literal|0
return|;
block|}
name|constexpr
name|bool
name|all
argument_list|()
specifier|const
block|{
return|return
operator|~
name|Mask
operator|==
literal|0
return|;
block|}
name|constexpr
name|LaneBitmask
name|operator
operator|~
operator|(
operator|)
specifier|const
block|{
return|return
name|LaneBitmask
argument_list|(
operator|~
name|Mask
argument_list|)
return|;
block|}
name|constexpr
name|LaneBitmask
name|operator
operator||
operator|(
name|LaneBitmask
name|M
operator|)
specifier|const
block|{
return|return
name|LaneBitmask
argument_list|(
name|Mask
operator||
name|M
operator|.
name|Mask
argument_list|)
return|;
block|}
name|constexpr
name|LaneBitmask
name|operator
modifier|&
argument_list|(
name|LaneBitmask
name|M
argument_list|)
decl|const
block|{
return|return
name|LaneBitmask
argument_list|(
name|Mask
operator|&
name|M
operator|.
name|Mask
argument_list|)
return|;
block|}
name|LaneBitmask
operator|&
name|operator
operator||=
operator|(
name|LaneBitmask
name|M
operator|)
block|{
name|Mask
operator||=
name|M
operator|.
name|Mask
block|;
return|return
operator|*
name|this
return|;
block|}
name|LaneBitmask
operator|&
name|operator
operator|&=
operator|(
name|LaneBitmask
name|M
operator|)
block|{
name|Mask
operator|&=
name|M
operator|.
name|Mask
block|;
return|return
operator|*
name|this
return|;
block|}
name|constexpr
name|Type
name|getAsInteger
argument_list|()
specifier|const
block|{
return|return
name|Mask
return|;
block|}
specifier|static
name|LaneBitmask
name|getNone
parameter_list|()
block|{
return|return
name|LaneBitmask
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|LaneBitmask
name|getAll
parameter_list|()
block|{
return|return
operator|~
name|LaneBitmask
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|private
label|:
name|Type
name|Mask
init|=
literal|0
decl_stmt|;
block|}
struct|;
comment|/// Create Printable object to print LaneBitmasks on a \ref raw_ostream.
specifier|static
name|LLVM_ATTRIBUTE_UNUSED
name|Printable
name|PrintLaneMask
parameter_list|(
name|LaneBitmask
name|LaneMask
parameter_list|)
block|{
return|return
name|Printable
argument_list|(
index|[
name|LaneMask
index|]
operator|(
name|raw_ostream
operator|&
name|OS
operator|)
block|{
name|OS
operator|<<
name|format
argument_list|(
name|LaneBitmask
operator|::
name|FormatStr
argument_list|,
name|LaneMask
operator|.
name|getAsInteger
argument_list|()
argument_list|)
block|;     }
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_LANEBITMASK_H
end_comment

end_unit

