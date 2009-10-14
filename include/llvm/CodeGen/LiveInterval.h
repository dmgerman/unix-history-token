begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/LiveInterval.h - Interval representation ---*- C++ -*-===//
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
comment|// This file implements the LiveRange and LiveInterval classes.  Given some
end_comment

begin_comment
comment|// numbering of each the machine instructions an interval [i, j) is said to be a
end_comment

begin_comment
comment|// live interval for register v if there is no instruction with number j'>= j
end_comment

begin_comment
comment|// such that v is live at j' and there is no instruction with number i'< i such
end_comment

begin_comment
comment|// that v is live at i'. In this implementation intervals can have holes,
end_comment

begin_comment
comment|// i.e. an interval might look like [1,20), [50,65), [1000,1001).  Each
end_comment

begin_comment
comment|// individual range is represented as an instance of LiveRange, and the whole
end_comment

begin_comment
comment|// interval is represented as an instance of LiveInterval.
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
name|LLVM_CODEGEN_LIVEINTERVAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEINTERVAL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// LiveIndex - An opaque wrapper around machine indexes.
name|class
name|LiveIndex
block|{
name|friend
name|class
name|VNInfo
decl_stmt|;
name|friend
name|class
name|LiveInterval
decl_stmt|;
name|friend
name|class
name|LiveIntervals
decl_stmt|;
name|friend
block|struct
name|DenseMapInfo
operator|<
name|LiveIndex
operator|>
expr_stmt|;
name|public
label|:
enum|enum
name|Slot
block|{
name|LOAD
block|,
name|USE
block|,
name|DEF
block|,
name|STORE
block|,
name|NUM
block|}
enum|;
name|private
label|:
name|unsigned
name|index
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|PHI_BIT
init|=
literal|1
operator|<<
literal|31
decl_stmt|;
name|public
label|:
comment|/// Construct a default LiveIndex pointing to a reserved index.
name|LiveIndex
argument_list|()
operator|:
name|index
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Construct an index from the given index, pointing to the given slot.
name|LiveIndex
argument_list|(
argument|LiveIndex m
argument_list|,
argument|Slot s
argument_list|)
operator|:
name|index
argument_list|(
argument|(m.index / NUM) * NUM + s
argument_list|)
block|{}
comment|/// Print this index to the given raw_ostream.
name|void
name|print
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
expr_stmt|;
comment|/// Compare two LiveIndex objects for equality.
name|bool
name|operator
operator|==
operator|(
name|LiveIndex
name|other
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|==
operator|(
name|other
operator|.
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|)
return|;
block|}
comment|/// Compare two LiveIndex objects for inequality.
name|bool
name|operator
operator|!=
operator|(
name|LiveIndex
name|other
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|!=
operator|(
name|other
operator|.
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|)
return|;
block|}
comment|/// Compare two LiveIndex objects. Return true if the first index
comment|/// is strictly lower than the second.
name|bool
name|operator
operator|<
operator|(
name|LiveIndex
name|other
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|<
operator|(
name|other
operator|.
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|)
return|;
block|}
comment|/// Compare two LiveIndex objects. Return true if the first index
comment|/// is lower than, or equal to, the second.
name|bool
name|operator
operator|<=
operator|(
name|LiveIndex
name|other
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|<=
operator|(
name|other
operator|.
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|)
return|;
block|}
comment|/// Compare two LiveIndex objects. Return true if the first index
comment|/// is greater than the second.
name|bool
name|operator
operator|>
operator|(
name|LiveIndex
name|other
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|>
operator|(
name|other
operator|.
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|)
return|;
block|}
comment|/// Compare two LiveIndex objects. Return true if the first index
comment|/// is greater than, or equal to, the second.
name|bool
name|operator
operator|>=
operator|(
name|LiveIndex
name|other
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|>=
operator|(
name|other
operator|.
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|)
return|;
block|}
comment|/// Returns true if this index represents a load.
name|bool
name|isLoad
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|%
name|NUM
operator|)
operator|==
name|LOAD
operator|)
return|;
block|}
comment|/// Returns true if this index represents a use.
name|bool
name|isUse
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|%
name|NUM
operator|)
operator|==
name|USE
operator|)
return|;
block|}
comment|/// Returns true if this index represents a def.
name|bool
name|isDef
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|%
name|NUM
operator|)
operator|==
name|DEF
operator|)
return|;
block|}
comment|/// Returns true if this index represents a store.
name|bool
name|isStore
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|%
name|NUM
operator|)
operator|==
name|STORE
operator|)
return|;
block|}
comment|/// Returns the slot for this LiveIndex.
name|Slot
name|getSlot
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Slot
operator|>
operator|(
name|index
operator|%
name|NUM
operator|)
return|;
block|}
comment|/// Returns true if this index represents a non-PHI use/def.
name|bool
name|isNonPHIIndex
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|&
name|PHI_BIT
operator|)
operator|==
literal|0
operator|)
return|;
block|}
comment|/// Returns true if this index represents a PHI use/def.
name|bool
name|isPHIIndex
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|index
operator|&
name|PHI_BIT
operator|)
operator|==
name|PHI_BIT
operator|)
return|;
block|}
name|private
label|:
comment|/// Construct an index from the given index, with its PHI kill marker set.
name|LiveIndex
argument_list|(
argument|bool phi
argument_list|,
argument|LiveIndex o
argument_list|)
block|:
name|index
argument_list|(
argument|o.index
argument_list|)
block|{
if|if
condition|(
name|phi
condition|)
name|index
operator||=
name|PHI_BIT
expr_stmt|;
else|else
name|index
operator|&=
operator|~
name|PHI_BIT
expr_stmt|;
block|}
name|explicit
name|LiveIndex
argument_list|(
argument|unsigned idx
argument_list|)
block|:
name|index
argument_list|(
argument|idx& ~PHI_BIT
argument_list|)
block|{}
name|LiveIndex
argument_list|(
argument|bool phi
argument_list|,
argument|unsigned idx
argument_list|)
block|:
name|index
argument_list|(
argument|idx& ~PHI_BIT
argument_list|)
block|{
if|if
condition|(
name|phi
condition|)
name|index
operator||=
name|PHI_BIT
expr_stmt|;
block|}
name|LiveIndex
argument_list|(
argument|bool phi
argument_list|,
argument|unsigned idx
argument_list|,
argument|Slot slot
argument_list|)
block|:
name|index
argument_list|(
argument|((idx / NUM) * NUM + slot)& ~PHI_BIT
argument_list|)
block|{
if|if
condition|(
name|phi
condition|)
name|index
operator||=
name|PHI_BIT
expr_stmt|;
block|}
name|LiveIndex
name|nextSlot_
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|index
operator|&
name|PHI_BIT
operator|)
operator|==
operator|(
operator|(
name|index
operator|+
literal|1
operator|)
operator|&
name|PHI_BIT
operator|)
operator|&&
literal|"Index out of bounds."
argument_list|)
block|;
return|return
name|LiveIndex
argument_list|(
name|index
operator|+
literal|1
argument_list|)
return|;
block|}
name|LiveIndex
name|nextIndex_
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|index
operator|&
name|PHI_BIT
operator|)
operator|==
operator|(
operator|(
name|index
operator|+
name|NUM
operator|)
operator|&
name|PHI_BIT
operator|)
operator|&&
literal|"Index out of bounds."
argument_list|)
block|;
return|return
name|LiveIndex
argument_list|(
name|index
operator|+
name|NUM
argument_list|)
return|;
block|}
name|LiveIndex
name|prevSlot_
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|index
operator|&
name|PHI_BIT
operator|)
operator|==
operator|(
operator|(
name|index
operator|-
literal|1
operator|)
operator|&
name|PHI_BIT
operator|)
operator|&&
literal|"Index out of bounds."
argument_list|)
block|;
return|return
name|LiveIndex
argument_list|(
name|index
operator|-
literal|1
argument_list|)
return|;
block|}
name|LiveIndex
name|prevIndex_
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|index
operator|&
name|PHI_BIT
operator|)
operator|==
operator|(
operator|(
name|index
operator|-
name|NUM
operator|)
operator|&
name|PHI_BIT
operator|)
operator|&&
literal|"Index out of bounds."
argument_list|)
block|;
return|return
name|LiveIndex
argument_list|(
name|index
operator|-
name|NUM
argument_list|)
return|;
block|}
name|int
name|distance
argument_list|(
name|LiveIndex
name|other
argument_list|)
decl|const
block|{
return|return
operator|(
name|other
operator|.
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|-
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
return|;
block|}
comment|/// Returns an unsigned number suitable as an index into a
comment|/// vector over all instructions.
name|unsigned
name|getVecIndex
argument_list|()
specifier|const
block|{
return|return
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|/
name|NUM
return|;
block|}
comment|/// Scale this index by the given factor.
name|LiveIndex
name|scale
argument_list|(
name|unsigned
name|factor
argument_list|)
decl|const
block|{
name|unsigned
name|i
init|=
operator|(
name|index
operator|&
operator|~
name|PHI_BIT
operator|)
operator|/
name|NUM
decl_stmt|,
name|o
init|=
operator|(
name|index
operator|%
operator|~
name|PHI_BIT
operator|)
operator|%
name|NUM
decl_stmt|;
name|assert
argument_list|(
name|index
operator|<=
operator|(
operator|~
literal|0U
operator|&
operator|~
name|PHI_BIT
operator|)
operator|/
operator|(
name|factor
operator|*
name|NUM
operator|)
operator|&&
literal|"Rescaled interval would overflow"
argument_list|)
expr_stmt|;
return|return
name|LiveIndex
argument_list|(
name|i
operator|*
name|NUM
operator|*
name|factor
argument_list|,
name|o
argument_list|)
return|;
block|}
specifier|static
name|LiveIndex
name|emptyKey
parameter_list|()
block|{
return|return
name|LiveIndex
argument_list|(
name|true
argument_list|,
literal|0x7fffffff
argument_list|)
return|;
block|}
specifier|static
name|LiveIndex
name|tombstoneKey
parameter_list|()
block|{
return|return
name|LiveIndex
argument_list|(
name|true
argument_list|,
literal|0x7ffffffe
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|LiveIndex
modifier|&
name|v
parameter_list|)
block|{
return|return
name|v
operator|.
name|index
operator|*
literal|37
return|;
block|}
block|}
empty_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|os
operator|,
name|LiveIndex
name|mi
operator|)
block|{
name|mi
operator|.
name|print
argument_list|(
name|os
argument_list|)
block|;
return|return
name|os
return|;
block|}
comment|/// Densemap specialization for LiveIndex.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|LiveIndex
operator|>
block|{
specifier|static
specifier|inline
name|LiveIndex
name|getEmptyKey
argument_list|()
block|{
return|return
name|LiveIndex
operator|::
name|emptyKey
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|LiveIndex
name|getTombstoneKey
argument_list|()
block|{
return|return
name|LiveIndex
operator|::
name|tombstoneKey
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|getHashValue
argument_list|(
argument|const LiveIndex&v
argument_list|)
block|{
return|return
name|LiveIndex
operator|::
name|getHashValue
argument_list|(
name|v
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isEqual
argument_list|(
argument|const LiveIndex&LHS
argument_list|,
argument|const LiveIndex&RHS
argument_list|)
block|{
return|return
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isPod
argument_list|()
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// VNInfo - Value Number Information.
comment|/// This class holds information about a machine level values, including
comment|/// definition and use points.
comment|///
comment|/// Care must be taken in interpreting the def index of the value. The
comment|/// following rules apply:
comment|///
comment|/// If the isDefAccurate() method returns false then def does not contain the
comment|/// index of the defining MachineInstr, or even (necessarily) to a
comment|/// MachineInstr at all. In general such a def index is not meaningful
comment|/// and should not be used. The exception is that, for values originally
comment|/// defined by PHI instructions, after PHI elimination def will contain the
comment|/// index of the MBB in which the PHI originally existed. This can be used
comment|/// to insert code (spills or copies) which deals with the value, which will
comment|/// be live in to the block.
name|class
name|VNInfo
block|{
name|private
operator|:
expr|enum
block|{
name|HAS_PHI_KILL
operator|=
literal|1
block|,
name|REDEF_BY_EC
operator|=
literal|1
operator|<<
literal|1
block|,
name|IS_PHI_DEF
operator|=
literal|1
operator|<<
literal|2
block|,
name|IS_UNUSED
operator|=
literal|1
operator|<<
literal|3
block|,
name|IS_DEF_ACCURATE
operator|=
literal|1
operator|<<
literal|4
block|}
block|;
name|unsigned
name|char
name|flags
block|;
expr|union
block|{
name|MachineInstr
operator|*
name|copy
block|;
name|unsigned
name|reg
block|;     }
name|cr
block|;
name|public
operator|:
typedef|typedef
name|SmallVector
operator|<
name|LiveIndex
operator|,
literal|4
operator|>
name|KillSet
expr_stmt|;
comment|/// The ID number of this value.
name|unsigned
name|id
block|;
comment|/// The index of the defining instruction (if isDefAccurate() returns true).
name|LiveIndex
name|def
block|;
name|KillSet
name|kills
block|;
name|VNInfo
argument_list|()
operator|:
name|flags
argument_list|(
name|IS_UNUSED
argument_list|)
block|,
name|id
argument_list|(
argument|~
literal|1U
argument_list|)
block|{
name|cr
operator|.
name|copy
operator|=
literal|0
block|; }
comment|/// VNInfo constructor.
comment|/// d is presumed to point to the actual defining instr. If it doesn't
comment|/// setIsDefAccurate(false) should be called after construction.
name|VNInfo
argument_list|(
argument|unsigned i
argument_list|,
argument|LiveIndex d
argument_list|,
argument|MachineInstr *c
argument_list|)
operator|:
name|flags
argument_list|(
name|IS_DEF_ACCURATE
argument_list|)
block|,
name|id
argument_list|(
name|i
argument_list|)
block|,
name|def
argument_list|(
argument|d
argument_list|)
block|{
name|cr
operator|.
name|copy
operator|=
name|c
block|; }
comment|/// VNInfo construtor, copies values from orig, except for the value number.
name|VNInfo
argument_list|(
argument|unsigned i
argument_list|,
argument|const VNInfo&orig
argument_list|)
operator|:
name|flags
argument_list|(
name|orig
operator|.
name|flags
argument_list|)
block|,
name|cr
argument_list|(
name|orig
operator|.
name|cr
argument_list|)
block|,
name|id
argument_list|(
name|i
argument_list|)
block|,
name|def
argument_list|(
name|orig
operator|.
name|def
argument_list|)
block|,
name|kills
argument_list|(
argument|orig.kills
argument_list|)
block|{ }
comment|/// Copy from the parameter into this VNInfo.
name|void
name|copyFrom
argument_list|(
argument|VNInfo&src
argument_list|)
block|{
name|flags
operator|=
name|src
operator|.
name|flags
block|;
name|cr
operator|=
name|src
operator|.
name|cr
block|;
name|def
operator|=
name|src
operator|.
name|def
block|;
name|kills
operator|=
name|src
operator|.
name|kills
block|;     }
comment|/// Used for copying value number info.
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|flags
return|;
block|}
name|void
name|setFlags
argument_list|(
argument|unsigned flags
argument_list|)
block|{
name|this
operator|->
name|flags
operator|=
name|flags
block|; }
comment|/// For a register interval, if this VN was definied by a copy instr
comment|/// getCopy() returns a pointer to it, otherwise returns 0.
comment|/// For a stack interval the behaviour of this method is undefined.
name|MachineInstr
operator|*
name|getCopy
argument_list|()
specifier|const
block|{
return|return
name|cr
operator|.
name|copy
return|;
block|}
comment|/// For a register interval, set the copy member.
comment|/// This method should not be called on stack intervals as it may lead to
comment|/// undefined behavior.
name|void
name|setCopy
argument_list|(
argument|MachineInstr *c
argument_list|)
block|{
name|cr
operator|.
name|copy
operator|=
name|c
block|; }
comment|/// For a stack interval, returns the reg which this stack interval was
comment|/// defined from.
comment|/// For a register interval the behaviour of this method is undefined.
name|unsigned
name|getReg
argument_list|()
specifier|const
block|{
return|return
name|cr
operator|.
name|reg
return|;
block|}
comment|/// For a stack interval, set the defining register.
comment|/// This method should not be called on register intervals as it may lead
comment|/// to undefined behaviour.
name|void
name|setReg
argument_list|(
argument|unsigned reg
argument_list|)
block|{
name|cr
operator|.
name|reg
operator|=
name|reg
block|; }
comment|/// Returns true if one or more kills are PHI nodes.
name|bool
name|hasPHIKill
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|HAS_PHI_KILL
return|;
block|}
comment|/// Set the PHI kill flag on this value.
name|void
name|setHasPHIKill
argument_list|(
argument|bool hasKill
argument_list|)
block|{
if|if
condition|(
name|hasKill
condition|)
name|flags
operator||=
name|HAS_PHI_KILL
expr_stmt|;
else|else
name|flags
operator|&=
operator|~
name|HAS_PHI_KILL
expr_stmt|;
block|}
comment|/// Returns true if this value is re-defined by an early clobber somewhere
comment|/// during the live range.
name|bool
name|hasRedefByEC
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|REDEF_BY_EC
return|;
block|}
comment|/// Set the "redef by early clobber" flag on this value.
name|void
name|setHasRedefByEC
argument_list|(
argument|bool hasRedef
argument_list|)
block|{
if|if
condition|(
name|hasRedef
condition|)
name|flags
operator||=
name|REDEF_BY_EC
expr_stmt|;
else|else
name|flags
operator|&=
operator|~
name|REDEF_BY_EC
expr_stmt|;
block|}
comment|/// Returns true if this value is defined by a PHI instruction (or was,
comment|/// PHI instrucions may have been eliminated).
name|bool
name|isPHIDef
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|IS_PHI_DEF
return|;
block|}
comment|/// Set the "phi def" flag on this value.
name|void
name|setIsPHIDef
argument_list|(
argument|bool phiDef
argument_list|)
block|{
if|if
condition|(
name|phiDef
condition|)
name|flags
operator||=
name|IS_PHI_DEF
expr_stmt|;
else|else
name|flags
operator|&=
operator|~
name|IS_PHI_DEF
expr_stmt|;
block|}
comment|/// Returns true if this value is unused.
name|bool
name|isUnused
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|IS_UNUSED
return|;
block|}
comment|/// Set the "is unused" flag on this value.
name|void
name|setIsUnused
argument_list|(
argument|bool unused
argument_list|)
block|{
if|if
condition|(
name|unused
condition|)
name|flags
operator||=
name|IS_UNUSED
expr_stmt|;
else|else
name|flags
operator|&=
operator|~
name|IS_UNUSED
expr_stmt|;
block|}
comment|/// Returns true if the def is accurate.
name|bool
name|isDefAccurate
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|IS_DEF_ACCURATE
return|;
block|}
comment|/// Set the "is def accurate" flag on this value.
name|void
name|setIsDefAccurate
argument_list|(
argument|bool defAccurate
argument_list|)
block|{
if|if
condition|(
name|defAccurate
condition|)
name|flags
operator||=
name|IS_DEF_ACCURATE
expr_stmt|;
else|else
name|flags
operator|&=
operator|~
name|IS_DEF_ACCURATE
expr_stmt|;
block|}
comment|/// Returns true if the given index is a kill of this value.
name|bool
name|isKill
argument_list|(
argument|LiveIndex k
argument_list|)
specifier|const
block|{
name|KillSet
operator|::
name|const_iterator
name|i
operator|=
name|std
operator|::
name|lower_bound
argument_list|(
name|kills
operator|.
name|begin
argument_list|()
argument_list|,
name|kills
operator|.
name|end
argument_list|()
argument_list|,
name|k
argument_list|)
block|;
return|return
operator|(
name|i
operator|!=
name|kills
operator|.
name|end
argument_list|()
operator|&&
operator|*
name|i
operator|==
name|k
operator|)
return|;
block|}
comment|/// addKill - Add a kill instruction index to the specified value
comment|/// number.
name|void
name|addKill
argument_list|(
argument|LiveIndex k
argument_list|)
block|{
if|if
condition|(
name|kills
operator|.
name|empty
argument_list|()
condition|)
block|{
name|kills
operator|.
name|push_back
argument_list|(
name|k
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|KillSet
operator|::
name|iterator
name|i
operator|=
name|std
operator|::
name|lower_bound
argument_list|(
name|kills
operator|.
name|begin
argument_list|()
argument_list|,
name|kills
operator|.
name|end
argument_list|()
argument_list|,
name|k
argument_list|)
expr_stmt|;
name|kills
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|k
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// Remove the specified kill index from this value's kills list.
comment|/// Returns true if the value was present, otherwise returns false.
name|bool
name|removeKill
argument_list|(
argument|LiveIndex k
argument_list|)
block|{
name|KillSet
operator|::
name|iterator
name|i
operator|=
name|std
operator|::
name|lower_bound
argument_list|(
name|kills
operator|.
name|begin
argument_list|()
argument_list|,
name|kills
operator|.
name|end
argument_list|()
argument_list|,
name|k
argument_list|)
block|;
if|if
condition|(
name|i
operator|!=
name|kills
operator|.
name|end
argument_list|()
operator|&&
operator|*
name|i
operator|==
name|k
condition|)
block|{
name|kills
operator|.
name|erase
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// Remove all kills in the range [s, e).
name|void
name|removeKills
argument_list|(
argument|LiveIndex s
argument_list|,
argument|LiveIndex e
argument_list|)
block|{
name|KillSet
operator|::
name|iterator
name|si
operator|=
name|std
operator|::
name|lower_bound
argument_list|(
name|kills
operator|.
name|begin
argument_list|()
argument_list|,
name|kills
operator|.
name|end
argument_list|()
argument_list|,
name|s
argument_list|)
block|,
name|se
operator|=
name|std
operator|::
name|upper_bound
argument_list|(
name|kills
operator|.
name|begin
argument_list|()
argument_list|,
name|kills
operator|.
name|end
argument_list|()
argument_list|,
name|e
argument_list|)
block|;
name|kills
operator|.
name|erase
argument_list|(
name|si
argument_list|,
name|se
argument_list|)
block|;     }
expr|}
block|;
comment|/// LiveRange structure - This represents a simple register range in the
comment|/// program, with an inclusive start point and an exclusive end point.
comment|/// These ranges are rendered as [start,end).
block|struct
name|LiveRange
block|{
name|LiveIndex
name|start
block|;
comment|// Start point of the interval (inclusive)
name|LiveIndex
name|end
block|;
comment|// End point of the interval (exclusive)
name|VNInfo
operator|*
name|valno
block|;
comment|// identifier for the value contained in this interval.
name|LiveRange
argument_list|(
argument|LiveIndex S
argument_list|,
argument|LiveIndex E
argument_list|,
argument|VNInfo *V
argument_list|)
operator|:
name|start
argument_list|(
name|S
argument_list|)
block|,
name|end
argument_list|(
name|E
argument_list|)
block|,
name|valno
argument_list|(
argument|V
argument_list|)
block|{
name|assert
argument_list|(
name|S
operator|<
name|E
operator|&&
literal|"Cannot create empty or backwards range"
argument_list|)
block|;     }
comment|/// contains - Return true if the index is covered by this range.
comment|///
name|bool
name|contains
argument_list|(
argument|LiveIndex I
argument_list|)
specifier|const
block|{
return|return
name|start
operator|<=
name|I
operator|&&
name|I
operator|<
name|end
return|;
block|}
comment|/// containsRange - Return true if the given range, [S, E), is covered by
comment|/// this range.
name|bool
name|containsRange
argument_list|(
argument|LiveIndex S
argument_list|,
argument|LiveIndex E
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|S
operator|<
name|E
operator|)
operator|&&
literal|"Backwards interval?"
argument_list|)
block|;
return|return
operator|(
name|start
operator|<=
name|S
operator|&&
name|S
operator|<
name|end
operator|)
operator|&&
operator|(
name|start
operator|<
name|E
operator|&&
name|E
operator|<=
name|end
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LiveRange
operator|&
name|LR
operator|)
specifier|const
block|{
return|return
name|start
operator|<
name|LR
operator|.
name|start
operator|||
operator|(
name|start
operator|==
name|LR
operator|.
name|start
operator|&&
name|end
operator|<
name|LR
operator|.
name|end
operator|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|LiveRange
operator|&
name|LR
operator|)
specifier|const
block|{
return|return
name|start
operator|==
name|LR
operator|.
name|start
operator|&&
name|end
operator|==
name|LR
operator|.
name|end
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
block|;
name|private
operator|:
name|LiveRange
argument_list|()
block|;
comment|// DO NOT IMPLEMENT
block|}
block|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|os
operator|,
specifier|const
name|LiveRange
operator|&
name|LR
operator|)
block|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|LiveIndex
name|V
operator|,
specifier|const
name|LiveRange
operator|&
name|LR
operator|)
block|{
return|return
name|V
operator|<
name|LR
operator|.
name|start
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LiveRange
operator|&
name|LR
operator|,
name|LiveIndex
name|V
operator|)
block|{
return|return
name|LR
operator|.
name|start
operator|<
name|V
return|;
block|}
comment|/// LiveInterval - This class represents some number of live ranges for a
comment|/// register or value.  This class also contains a bit of register allocator
comment|/// state.
name|class
name|LiveInterval
block|{
name|public
operator|:
typedef|typedef
name|SmallVector
operator|<
name|LiveRange
operator|,
literal|4
operator|>
name|Ranges
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|VNInfo
operator|*
operator|,
literal|4
operator|>
name|VNInfoList
expr_stmt|;
name|unsigned
name|reg
expr_stmt|;
comment|// the register or stack slot of this interval
comment|// if the top bits is set, it represents a stack slot.
name|float
name|weight
decl_stmt|;
comment|// weight of this interval
name|Ranges
name|ranges
decl_stmt|;
comment|// the ranges in which this register is live
name|VNInfoList
name|valnos
decl_stmt|;
comment|// value#'s
struct|struct
name|InstrSlots
block|{
enum|enum
block|{
name|LOAD
init|=
literal|0
block|,
name|USE
init|=
literal|1
block|,
name|DEF
init|=
literal|2
block|,
name|STORE
init|=
literal|3
block|,
name|NUM
init|=
literal|4
block|}
enum|;
block|}
struct|;
name|LiveInterval
argument_list|(
argument|unsigned Reg
argument_list|,
argument|float Weight
argument_list|,
argument|bool IsSS = false
argument_list|)
block|:
name|reg
argument_list|(
name|Reg
argument_list|)
operator|,
name|weight
argument_list|(
argument|Weight
argument_list|)
block|{
if|if
condition|(
name|IsSS
condition|)
name|reg
operator|=
name|reg
operator||
operator|(
literal|1U
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
block|}
typedef|typedef
name|Ranges
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|ranges
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|ranges
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|Ranges
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|ranges
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|ranges
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|VNInfoList
operator|::
name|iterator
name|vni_iterator
expr_stmt|;
name|vni_iterator
name|vni_begin
parameter_list|()
block|{
return|return
name|valnos
operator|.
name|begin
argument_list|()
return|;
block|}
name|vni_iterator
name|vni_end
parameter_list|()
block|{
return|return
name|valnos
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|VNInfoList
operator|::
name|const_iterator
name|const_vni_iterator
expr_stmt|;
name|const_vni_iterator
name|vni_begin
argument_list|()
specifier|const
block|{
return|return
name|valnos
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_vni_iterator
name|vni_end
argument_list|()
specifier|const
block|{
return|return
name|valnos
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// advanceTo - Advance the specified iterator to point to the LiveRange
comment|/// containing the specified position, or end() if the position is past the
comment|/// end of the interval.  If no LiveRange contains this position, but the
comment|/// position is in a hole, this method returns an iterator pointing the the
comment|/// LiveRange immediately after the hole.
name|iterator
name|advanceTo
parameter_list|(
name|iterator
name|I
parameter_list|,
name|LiveIndex
name|Pos
parameter_list|)
block|{
if|if
condition|(
name|Pos
operator|>=
name|endIndex
argument_list|()
condition|)
return|return
name|end
argument_list|()
return|;
while|while
condition|(
name|I
operator|->
name|end
operator|<=
name|Pos
condition|)
operator|++
name|I
expr_stmt|;
return|return
name|I
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
while|while
condition|(
operator|!
name|valnos
operator|.
name|empty
argument_list|()
condition|)
block|{
name|VNInfo
modifier|*
name|VNI
init|=
name|valnos
operator|.
name|back
argument_list|()
decl_stmt|;
name|valnos
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|VNI
operator|->
expr|~
name|VNInfo
argument_list|()
expr_stmt|;
block|}
name|ranges
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// isStackSlot - Return true if this is a stack slot interval.
comment|///
name|bool
name|isStackSlot
argument_list|()
specifier|const
block|{
return|return
name|reg
operator|&
operator|(
literal|1U
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
operator|)
return|;
block|}
comment|/// getStackSlotIndex - Return stack slot index if this is a stack slot
comment|/// interval.
name|int
name|getStackSlotIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isStackSlot
argument_list|()
operator|&&
literal|"Interval is not a stack slot interval!"
argument_list|)
block|;
return|return
name|reg
operator|&
operator|~
operator|(
literal|1U
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
operator|)
return|;
block|}
name|bool
name|hasAtLeastOneValue
argument_list|()
specifier|const
block|{
return|return
operator|!
name|valnos
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|containsOneValue
argument_list|()
specifier|const
block|{
return|return
name|valnos
operator|.
name|size
argument_list|()
operator|==
literal|1
return|;
block|}
name|unsigned
name|getNumValNums
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|valnos
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// getValNumInfo - Returns pointer to the specified val#.
comment|///
specifier|inline
name|VNInfo
modifier|*
name|getValNumInfo
parameter_list|(
name|unsigned
name|ValNo
parameter_list|)
block|{
return|return
name|valnos
index|[
name|ValNo
index|]
return|;
block|}
specifier|inline
specifier|const
name|VNInfo
modifier|*
name|getValNumInfo
argument_list|(
name|unsigned
name|ValNo
argument_list|)
decl|const
block|{
return|return
name|valnos
index|[
name|ValNo
index|]
return|;
block|}
comment|/// getNextValue - Create a new value number and return it.  MIIdx specifies
comment|/// the instruction that defines the value number.
name|VNInfo
modifier|*
name|getNextValue
parameter_list|(
name|LiveIndex
name|def
parameter_list|,
name|MachineInstr
modifier|*
name|CopyMI
parameter_list|,
name|bool
name|isDefAccurate
parameter_list|,
name|BumpPtrAllocator
modifier|&
name|VNInfoAllocator
parameter_list|)
block|{
name|VNInfo
modifier|*
name|VNI
init|=
name|static_cast
operator|<
name|VNInfo
operator|*
operator|>
operator|(
name|VNInfoAllocator
operator|.
name|Allocate
argument_list|(
operator|(
name|unsigned
operator|)
sizeof|sizeof
argument_list|(
name|VNInfo
argument_list|)
argument_list|,
name|alignof
operator|<
name|VNInfo
operator|>
operator|(
operator|)
argument_list|)
operator|)
decl_stmt|;
name|new
argument_list|(
argument|VNI
argument_list|)
name|VNInfo
argument_list|(
operator|(
name|unsigned
operator|)
name|valnos
operator|.
name|size
argument_list|()
argument_list|,
name|def
argument_list|,
name|CopyMI
argument_list|)
expr_stmt|;
name|VNI
operator|->
name|setIsDefAccurate
argument_list|(
name|isDefAccurate
argument_list|)
expr_stmt|;
name|valnos
operator|.
name|push_back
argument_list|(
name|VNI
argument_list|)
expr_stmt|;
return|return
name|VNI
return|;
block|}
comment|/// Create a copy of the given value. The new value will be identical except
comment|/// for the Value number.
name|VNInfo
modifier|*
name|createValueCopy
parameter_list|(
specifier|const
name|VNInfo
modifier|*
name|orig
parameter_list|,
name|BumpPtrAllocator
modifier|&
name|VNInfoAllocator
parameter_list|)
block|{
name|VNInfo
modifier|*
name|VNI
init|=
name|static_cast
operator|<
name|VNInfo
operator|*
operator|>
operator|(
name|VNInfoAllocator
operator|.
name|Allocate
argument_list|(
operator|(
name|unsigned
operator|)
sizeof|sizeof
argument_list|(
name|VNInfo
argument_list|)
argument_list|,
name|alignof
operator|<
name|VNInfo
operator|>
operator|(
operator|)
argument_list|)
operator|)
decl_stmt|;
name|new
argument_list|(
argument|VNI
argument_list|)
name|VNInfo
argument_list|(
operator|(
name|unsigned
operator|)
name|valnos
operator|.
name|size
argument_list|()
argument_list|,
operator|*
name|orig
argument_list|)
expr_stmt|;
name|valnos
operator|.
name|push_back
argument_list|(
name|VNI
argument_list|)
expr_stmt|;
return|return
name|VNI
return|;
block|}
comment|/// addKills - Add a number of kills into the VNInfo kill vector. If this
comment|/// interval is live at a kill point, then the kill is not added.
name|void
name|addKills
argument_list|(
name|VNInfo
operator|*
name|VNI
argument_list|,
specifier|const
name|VNInfo
operator|::
name|KillSet
operator|&
name|kills
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|kills
operator|.
name|size
argument_list|()
operator|)
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|liveBeforeAndAt
argument_list|(
name|kills
index|[
name|i
index|]
argument_list|)
condition|)
block|{
name|VNI
operator|->
name|addKill
argument_list|(
name|kills
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/// isOnlyLROfValNo - Return true if the specified live range is the only
comment|/// one defined by the its val#.
name|bool
name|isOnlyLROfValNo
parameter_list|(
specifier|const
name|LiveRange
modifier|*
name|LR
parameter_list|)
block|{
for|for
control|(
name|const_iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
specifier|const
name|LiveRange
modifier|*
name|Tmp
init|=
name|I
decl_stmt|;
if|if
condition|(
name|Tmp
operator|!=
name|LR
operator|&&
name|Tmp
operator|->
name|valno
operator|==
name|LR
operator|->
name|valno
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
comment|/// MergeValueNumberInto - This method is called when two value nubmers
comment|/// are found to be equivalent.  This eliminates V1, replacing all
comment|/// LiveRanges with the V1 value number with the V2 value number.  This can
comment|/// cause merging of V1/V2 values numbers and compaction of the value space.
name|VNInfo
modifier|*
name|MergeValueNumberInto
parameter_list|(
name|VNInfo
modifier|*
name|V1
parameter_list|,
name|VNInfo
modifier|*
name|V2
parameter_list|)
function_decl|;
comment|/// MergeInClobberRanges - For any live ranges that are not defined in the
comment|/// current interval, but are defined in the Clobbers interval, mark them
comment|/// used with an unknown definition value. Caller must pass in reference to
comment|/// VNInfoAllocator since it will create a new val#.
name|void
name|MergeInClobberRanges
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|Clobbers
parameter_list|,
name|BumpPtrAllocator
modifier|&
name|VNInfoAllocator
parameter_list|)
function_decl|;
comment|/// MergeInClobberRange - Same as MergeInClobberRanges except it merge in a
comment|/// single LiveRange only.
name|void
name|MergeInClobberRange
parameter_list|(
name|LiveIndex
name|Start
parameter_list|,
name|LiveIndex
name|End
parameter_list|,
name|BumpPtrAllocator
modifier|&
name|VNInfoAllocator
parameter_list|)
function_decl|;
comment|/// MergeValueInAsValue - Merge all of the live ranges of a specific val#
comment|/// in RHS into this live interval as the specified value number.
comment|/// The LiveRanges in RHS are allowed to overlap with LiveRanges in the
comment|/// current interval, it will replace the value numbers of the overlaped
comment|/// live ranges with the specified value number.
name|void
name|MergeRangesInAsValue
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|RHS
parameter_list|,
name|VNInfo
modifier|*
name|LHSValNo
parameter_list|)
function_decl|;
comment|/// MergeValueInAsValue - Merge all of the live ranges of a specific val#
comment|/// in RHS into this live interval as the specified value number.
comment|/// The LiveRanges in RHS are allowed to overlap with LiveRanges in the
comment|/// current interval, but only if the overlapping LiveRanges have the
comment|/// specified value number.
name|void
name|MergeValueInAsValue
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|RHS
parameter_list|,
specifier|const
name|VNInfo
modifier|*
name|RHSValNo
parameter_list|,
name|VNInfo
modifier|*
name|LHSValNo
parameter_list|)
function_decl|;
comment|/// Copy - Copy the specified live interval. This copies all the fields
comment|/// except for the register of the interval.
name|void
name|Copy
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|RHS
parameter_list|,
name|MachineRegisterInfo
modifier|*
name|MRI
parameter_list|,
name|BumpPtrAllocator
modifier|&
name|VNInfoAllocator
parameter_list|)
function_decl|;
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|ranges
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// beginIndex - Return the lowest numbered slot covered by interval.
name|LiveIndex
name|beginIndex
argument_list|()
specifier|const
block|{
if|if
condition|(
name|empty
argument_list|()
condition|)
return|return
name|LiveIndex
argument_list|()
return|;
return|return
name|ranges
operator|.
name|front
argument_list|()
operator|.
name|start
return|;
block|}
end_decl_stmt

begin_comment
comment|/// endNumber - return the maximum point of the interval of the whole,
end_comment

begin_comment
comment|/// exclusive.
end_comment

begin_expr_stmt
name|LiveIndex
name|endIndex
argument_list|()
specifier|const
block|{
if|if
condition|(
name|empty
argument_list|()
condition|)
return|return
name|LiveIndex
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|ranges
operator|.
name|back
argument_list|()
operator|.
name|end
return|;
end_return

begin_macro
unit|}      bool
name|expiredAt
argument_list|(
argument|LiveIndex index
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|index
operator|>=
name|endIndex
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|liveAt
argument_list|(
name|LiveIndex
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// liveBeforeAndAt - Check if the interval is live at the index and the
end_comment

begin_comment
comment|// index just before it. If index is liveAt, check if it starts a new live
end_comment

begin_comment
comment|// range.If it does, then check if the previous live range ends at index-1.
end_comment

begin_decl_stmt
name|bool
name|liveBeforeAndAt
argument_list|(
name|LiveIndex
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getLiveRangeContaining - Return the live range that contains the
end_comment

begin_comment
comment|/// specified index, or null if there is none.
end_comment

begin_decl_stmt
specifier|const
name|LiveRange
modifier|*
name|getLiveRangeContaining
argument_list|(
name|LiveIndex
name|Idx
argument_list|)
decl|const
block|{
name|const_iterator
name|I
init|=
name|FindLiveRangeContaining
argument_list|(
name|Idx
argument_list|)
decl_stmt|;
return|return
name|I
operator|==
name|end
argument_list|()
condition|?
literal|0
else|:
operator|&
operator|*
name|I
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getLiveRangeContaining - Return the live range that contains the
end_comment

begin_comment
comment|/// specified index, or null if there is none.
end_comment

begin_function
name|LiveRange
modifier|*
name|getLiveRangeContaining
parameter_list|(
name|LiveIndex
name|Idx
parameter_list|)
block|{
name|iterator
name|I
init|=
name|FindLiveRangeContaining
argument_list|(
name|Idx
argument_list|)
decl_stmt|;
return|return
name|I
operator|==
name|end
argument_list|()
condition|?
literal|0
else|:
operator|&
operator|*
name|I
return|;
block|}
end_function

begin_comment
comment|/// FindLiveRangeContaining - Return an iterator to the live range that
end_comment

begin_comment
comment|/// contains the specified index, or end() if there is none.
end_comment

begin_decl_stmt
name|const_iterator
name|FindLiveRangeContaining
argument_list|(
name|LiveIndex
name|Idx
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// FindLiveRangeContaining - Return an iterator to the live range that
end_comment

begin_comment
comment|/// contains the specified index, or end() if there is none.
end_comment

begin_function_decl
name|iterator
name|FindLiveRangeContaining
parameter_list|(
name|LiveIndex
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// findDefinedVNInfo - Find the by the specified
end_comment

begin_comment
comment|/// index (register interval) or defined
end_comment

begin_decl_stmt
name|VNInfo
modifier|*
name|findDefinedVNInfoForRegInt
argument_list|(
name|LiveIndex
name|Idx
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// findDefinedVNInfo - Find the VNInfo that's defined by the specified
end_comment

begin_comment
comment|/// register (stack inteval only).
end_comment

begin_decl_stmt
name|VNInfo
modifier|*
name|findDefinedVNInfoForStackInt
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// overlaps - Return true if the intersection of the two live intervals is
end_comment

begin_comment
comment|/// not empty.
end_comment

begin_decl_stmt
name|bool
name|overlaps
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|other
argument_list|)
decl|const
block|{
return|return
name|overlapsFrom
argument_list|(
name|other
argument_list|,
name|other
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// overlaps - Return true if the live interval overlaps a range specified
end_comment

begin_comment
comment|/// by [Start, End).
end_comment

begin_decl_stmt
name|bool
name|overlaps
argument_list|(
name|LiveIndex
name|Start
argument_list|,
name|LiveIndex
name|End
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// overlapsFrom - Return true if the intersection of the two live intervals
end_comment

begin_comment
comment|/// is not empty.  The specified iterator is a hint that we can begin
end_comment

begin_comment
comment|/// scanning the Other interval starting at I.
end_comment

begin_decl_stmt
name|bool
name|overlapsFrom
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|other
argument_list|,
name|const_iterator
name|I
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addRange - Add the specified LiveRange to this interval, merging
end_comment

begin_comment
comment|/// intervals as appropriate.  This returns an iterator to the inserted live
end_comment

begin_comment
comment|/// range (which may have grown since it was inserted.
end_comment

begin_function
name|void
name|addRange
parameter_list|(
name|LiveRange
name|LR
parameter_list|)
block|{
name|addRangeFrom
argument_list|(
name|LR
argument_list|,
name|ranges
operator|.
name|begin
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// join - Join two live intervals (this, and other) together.  This applies
end_comment

begin_comment
comment|/// mappings to the value numbers in the LHS/RHS intervals as specified.  If
end_comment

begin_comment
comment|/// the intervals are not joinable, this aborts.
end_comment

begin_decl_stmt
name|void
name|join
argument_list|(
name|LiveInterval
operator|&
name|Other
argument_list|,
specifier|const
name|int
operator|*
name|ValNoAssignments
argument_list|,
specifier|const
name|int
operator|*
name|RHSValNoAssignments
argument_list|,
name|SmallVector
operator|<
name|VNInfo
operator|*
argument_list|,
literal|16
operator|>
operator|&
name|NewVNInfo
argument_list|,
name|MachineRegisterInfo
operator|*
name|MRI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isInOneLiveRange - Return true if the range specified is entirely in the
end_comment

begin_comment
comment|/// a single LiveRange of the live interval.
end_comment

begin_function_decl
name|bool
name|isInOneLiveRange
parameter_list|(
name|LiveIndex
name|Start
parameter_list|,
name|LiveIndex
name|End
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// removeRange - Remove the specified range from this interval.  Note that
end_comment

begin_comment
comment|/// the range must be a single LiveRange in its entirety.
end_comment

begin_function_decl
name|void
name|removeRange
parameter_list|(
name|LiveIndex
name|Start
parameter_list|,
name|LiveIndex
name|End
parameter_list|,
name|bool
name|RemoveDeadValNo
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|removeRange
parameter_list|(
name|LiveRange
name|LR
parameter_list|,
name|bool
name|RemoveDeadValNo
init|=
name|false
parameter_list|)
block|{
name|removeRange
argument_list|(
name|LR
operator|.
name|start
argument_list|,
name|LR
operator|.
name|end
argument_list|,
name|RemoveDeadValNo
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// removeValNo - Remove all the ranges defined by the specified value#.
end_comment

begin_comment
comment|/// Also remove the value# from value# list.
end_comment

begin_function_decl
name|void
name|removeValNo
parameter_list|(
name|VNInfo
modifier|*
name|ValNo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// scaleNumbering - Renumber VNI and ranges to provide gaps for new
end_comment

begin_comment
comment|/// instructions.
end_comment

begin_function_decl
name|void
name|scaleNumbering
parameter_list|(
name|unsigned
name|factor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getSize - Returns the sum of sizes of all the LiveRange's.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|getSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ComputeJoinedWeight - Set the weight of a live interval after
end_comment

begin_comment
comment|/// Other has been merged into it.
end_comment

begin_function_decl
name|void
name|ComputeJoinedWeight
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|Other
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LiveInterval
operator|&
name|other
operator|)
specifier|const
block|{
specifier|const
name|LiveIndex
operator|&
name|thisIndex
operator|=
name|beginIndex
argument_list|()
block|;
specifier|const
name|LiveIndex
operator|&
name|otherIndex
operator|=
name|other
operator|.
name|beginIndex
argument_list|()
block|;
return|return
operator|(
name|thisIndex
operator|<
name|otherIndex
operator|||
operator|(
name|thisIndex
operator|==
name|otherIndex
operator|&&
name|reg
operator|<
name|other
operator|.
name|reg
operator|)
operator|)
return|;
block|}
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
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
literal|0
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

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|Ranges
operator|::
name|iterator
name|addRangeFrom
argument_list|(
argument|LiveRange LR
argument_list|,
argument|Ranges::iterator From
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|extendIntervalEndTo
argument_list|(
name|Ranges
operator|::
name|iterator
name|I
argument_list|,
name|LiveIndex
name|NewEnd
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Ranges
operator|::
name|iterator
name|extendIntervalStartTo
argument_list|(
argument|Ranges::iterator I
argument_list|,
argument|LiveIndex NewStr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|LiveInterval
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LiveInterval
operator|&
name|rhs
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// DO NOT IMPLEMENT
end_comment

begin_expr_stmt
unit|};
specifier|inline
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
name|LiveInterval
operator|&
name|LI
operator|)
block|{
name|LI
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

