begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ConstantPool.h - Keep track of assembler-generated  ------*- C++ -*-===//
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
comment|// This file declares the ConstantPool and AssemblerConstantPools classes.
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
name|LLVM_MC_CONSTANTPOOLS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_CONSTANTPOOLS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCSymbolRefExpr
decl_stmt|;
struct|struct
name|ConstantPoolEntry
block|{
name|ConstantPoolEntry
argument_list|(
argument|MCSymbol *L
argument_list|,
argument|const MCExpr *Val
argument_list|,
argument|unsigned Sz
argument_list|,
argument|SMLoc Loc_
argument_list|)
block|:
name|Label
argument_list|(
name|L
argument_list|)
operator|,
name|Value
argument_list|(
name|Val
argument_list|)
operator|,
name|Size
argument_list|(
name|Sz
argument_list|)
operator|,
name|Loc
argument_list|(
argument|Loc_
argument_list|)
block|{}
name|MCSymbol
operator|*
name|Label
expr_stmt|;
specifier|const
name|MCExpr
modifier|*
name|Value
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
name|SMLoc
name|Loc
decl_stmt|;
block|}
struct|;
comment|// A class to keep track of assembler-generated constant pools that are use to
comment|// implement the ldr-pseudo.
name|class
name|ConstantPool
block|{
name|using
name|EntryVecTy
init|=
name|SmallVector
operator|<
name|ConstantPoolEntry
decl_stmt|, 4>;
name|EntryVecTy
name|Entries
decl_stmt|;
name|DenseMap
operator|<
name|int64_t
operator|,
specifier|const
name|MCSymbolRefExpr
operator|*
operator|>
name|CachedEntries
expr_stmt|;
name|public
label|:
comment|// Initialize a new empty constant pool
name|ConstantPool
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|// Add a new entry to the constant pool in the next slot.
comment|// \param Value is the new entry to put in the constant pool.
comment|// \param Size is the size in bytes of the entry
comment|//
comment|// \returns a MCExpr that references the newly inserted value
specifier|const
name|MCExpr
modifier|*
name|addEntry
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|,
name|MCContext
modifier|&
name|Context
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|SMLoc
name|Loc
parameter_list|)
function_decl|;
comment|// Emit the contents of the constant pool using the provided streamer.
name|void
name|emitEntries
parameter_list|(
name|MCStreamer
modifier|&
name|Streamer
parameter_list|)
function_decl|;
comment|// Return true if the constant pool is empty
name|bool
name|empty
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|class
name|AssemblerConstantPools
block|{
comment|// Map type used to keep track of per-Section constant pools used by the
comment|// ldr-pseudo opcode. The map associates a section to its constant pool. The
comment|// constant pool is a vector of (label, value) pairs. When the ldr
comment|// pseudo is parsed we insert a new (label, value) pair into the constant pool
comment|// for the current section and add MCSymbolRefExpr to the new label as
comment|// an opcode to the ldr. After we have parsed all the user input we
comment|// output the (label, value) pairs in each constant pool at the end of the
comment|// section.
comment|//
comment|// We use the MapVector for the map type to ensure stable iteration of
comment|// the sections at the end of the parse. We need to iterate over the
comment|// sections in a stable order to ensure that we have print the
comment|// constant pools in a deterministic order when printing an assembly
comment|// file.
name|using
name|ConstantPoolMapTy
init|=
name|MapVector
operator|<
name|MCSection
operator|*
decl_stmt|,
name|ConstantPool
decl|>
decl_stmt|;
name|ConstantPoolMapTy
name|ConstantPools
decl_stmt|;
name|public
label|:
name|void
name|emitAll
parameter_list|(
name|MCStreamer
modifier|&
name|Streamer
parameter_list|)
function_decl|;
name|void
name|emitForCurrentSection
parameter_list|(
name|MCStreamer
modifier|&
name|Streamer
parameter_list|)
function_decl|;
specifier|const
name|MCExpr
modifier|*
name|addEntry
parameter_list|(
name|MCStreamer
modifier|&
name|Streamer
parameter_list|,
specifier|const
name|MCExpr
modifier|*
name|Expr
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|SMLoc
name|Loc
parameter_list|)
function_decl|;
name|private
label|:
name|ConstantPool
modifier|*
name|getConstantPool
parameter_list|(
name|MCSection
modifier|*
name|Section
parameter_list|)
function_decl|;
name|ConstantPool
modifier|&
name|getOrCreateConstantPool
parameter_list|(
name|MCSection
modifier|*
name|Section
parameter_list|)
function_decl|;
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

begin_comment
comment|// LLVM_MC_CONSTANTPOOLS_H
end_comment

end_unit

