begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/IntEqClasses.h - Equiv. Classes of Integers ----*- C++ -*-===//
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
comment|// Equivalence classes for small integers. This is a mapping of the integers
end_comment

begin_comment
comment|// 0 .. N-1 into M equivalence classes numbered 0 .. M-1.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Initially each integer has its own equivalence class. Classes are joined by
end_comment

begin_comment
comment|// passing a representative member of each class to join().
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Once the classes are built, compress() will number them 0 .. M-1 and prevent
end_comment

begin_comment
comment|// further changes.
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
name|LLVM_ADT_INTEQCLASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_INTEQCLASSES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|IntEqClasses
block|{
comment|/// EC - When uncompressed, map each integer to a smaller member of its
comment|/// equivalence class. The class leader is the smallest member and maps to
comment|/// itself.
comment|///
comment|/// When compressed, EC[i] is the equivalence class of i.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|8
operator|>
name|EC
expr_stmt|;
comment|/// NumClasses - The number of equivalence classes when compressed, or 0 when
comment|/// uncompressed.
name|unsigned
name|NumClasses
decl_stmt|;
name|public
label|:
comment|/// IntEqClasses - Create an equivalence class mapping for 0 .. N-1.
name|IntEqClasses
argument_list|(
argument|unsigned N =
literal|0
argument_list|)
block|:
name|NumClasses
argument_list|(
literal|0
argument_list|)
block|{
name|grow
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
comment|/// grow - Increase capacity to hold 0 .. N-1, putting new integers in unique
comment|/// equivalence classes.
comment|/// This requires an uncompressed map.
name|void
name|grow
parameter_list|(
name|unsigned
name|N
parameter_list|)
function_decl|;
comment|/// clear - Clear all classes so that grow() will assign a unique class to
comment|/// every integer.
name|void
name|clear
parameter_list|()
block|{
name|EC
operator|.
name|clear
argument_list|()
expr_stmt|;
name|NumClasses
operator|=
literal|0
expr_stmt|;
block|}
comment|/// join - Join the equivalence classes of a and b. After joining classes,
comment|/// findLeader(a) == findLeader(b).
comment|/// This requires an uncompressed map.
name|void
name|join
parameter_list|(
name|unsigned
name|a
parameter_list|,
name|unsigned
name|b
parameter_list|)
function_decl|;
comment|/// findLeader - Compute the leader of a's equivalence class. This is the
comment|/// smallest member of the class.
comment|/// This requires an uncompressed map.
name|unsigned
name|findLeader
argument_list|(
name|unsigned
name|a
argument_list|)
decl|const
decl_stmt|;
comment|/// compress - Compress equivalence classes by numbering them 0 .. M.
comment|/// This makes the equivalence class map immutable.
name|void
name|compress
parameter_list|()
function_decl|;
comment|/// getNumClasses - Return the number of equivalence classes after compress()
comment|/// was called.
name|unsigned
name|getNumClasses
argument_list|()
specifier|const
block|{
return|return
name|NumClasses
return|;
block|}
comment|/// operator[] - Return a's equivalence class number, 0 .. getNumClasses()-1.
comment|/// This requires a compressed map.
name|unsigned
name|operator
index|[]
argument_list|(
name|unsigned
name|a
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|NumClasses
operator|&&
literal|"operator[] called before compress()"
argument_list|)
expr_stmt|;
return|return
name|EC
index|[
name|a
index|]
return|;
block|}
comment|/// uncompress - Change back to the uncompressed representation that allows
comment|/// editing.
name|void
name|uncompress
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

