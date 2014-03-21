begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCObjectDisassembler.h --------------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCObjectDisassembler class, which
end_comment

begin_comment
comment|// can be used to construct an MCModule and an MC CFG from an ObjectFile.
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
name|LLVM_MC_MCOBJECTDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCOBJECTDISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryObject.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|ObjectFile
decl_stmt|;
name|class
name|MachOObjectFile
decl_stmt|;
block|}
name|class
name|MCBasicBlock
decl_stmt|;
name|class
name|MCDisassembler
decl_stmt|;
name|class
name|MCFunction
decl_stmt|;
name|class
name|MCInstrAnalysis
decl_stmt|;
name|class
name|MCModule
decl_stmt|;
name|class
name|MCObjectSymbolizer
decl_stmt|;
comment|/// \brief Disassemble an ObjectFile to an MCModule and MCFunctions.
comment|/// This class builds on MCDisassembler to disassemble whole sections, creating
comment|/// MCAtom (MCTextAtom for disassembled sections and MCDataAtom for raw data).
comment|/// It can also be used to create a control flow graph consisting of MCFunctions
comment|/// and MCBasicBlocks.
name|class
name|MCObjectDisassembler
block|{
name|public
label|:
name|MCObjectDisassembler
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|Obj
argument_list|,
specifier|const
name|MCDisassembler
operator|&
name|Dis
argument_list|,
specifier|const
name|MCInstrAnalysis
operator|&
name|MIA
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|MCObjectDisassembler
argument_list|()
block|{}
comment|/// \brief Build an MCModule, creating atoms and optionally functions.
comment|/// \param withCFG Also build a CFG by adding MCFunctions to the Module.
comment|/// If withCFG is false, the MCModule built only contains atoms, representing
comment|/// what was found in the object file. If withCFG is true, MCFunctions are
comment|/// created, containing MCBasicBlocks. All text atoms are split to form basic
comment|/// block atoms, which then each back an MCBasicBlock.
name|MCModule
operator|*
name|buildModule
argument_list|(
argument|bool withCFG = false
argument_list|)
expr_stmt|;
name|MCModule
modifier|*
name|buildEmptyModule
parameter_list|()
function_decl|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
name|AddressSetTy
expr_stmt|;
comment|/// \name Create a new MCFunction.
name|MCFunction
modifier|*
name|createFunction
parameter_list|(
name|MCModule
modifier|*
name|Module
parameter_list|,
name|uint64_t
name|BeginAddr
parameter_list|,
name|AddressSetTy
modifier|&
name|CallTargets
parameter_list|,
name|AddressSetTy
modifier|&
name|TailCallTargets
parameter_list|)
function_decl|;
comment|/// \brief Set the region on which to fallback if disassembly was requested
comment|/// somewhere not accessible in the object file.
comment|/// This is used for dynamic disassembly (see RawMemoryObject).
name|void
name|setFallbackRegion
argument_list|(
name|OwningPtr
operator|<
name|MemoryObject
operator|>
operator|&
name|Region
argument_list|)
block|{
name|FallbackRegion
operator|.
name|reset
argument_list|(
name|Region
operator|.
name|take
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Set the symbolizer to use to get information on external functions.
comment|/// Note that this isn't used to do instruction-level symbolization (that is,
comment|/// plugged into MCDisassembler), but to symbolize function call targets.
name|void
name|setSymbolizer
parameter_list|(
name|MCObjectSymbolizer
modifier|*
name|ObjectSymbolizer
parameter_list|)
block|{
name|MOS
operator|=
name|ObjectSymbolizer
expr_stmt|;
block|}
comment|/// \brief Get the effective address of the entrypoint, or 0 if there is none.
name|virtual
name|uint64_t
name|getEntrypoint
parameter_list|()
function_decl|;
comment|/// \name Get the addresses of static constructors/destructors in the object.
comment|/// The caller is expected to know how to interpret the addresses;
comment|/// for example, Mach-O init functions expect 5 arguments, not for ELF.
comment|/// The addresses are original object file load addresses, not effective.
comment|/// @{
name|virtual
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|getStaticInitFunctions
argument_list|()
expr_stmt|;
name|virtual
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|getStaticExitFunctions
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// \name Translation between effective and objectfile load address.
comment|/// @{
comment|/// \brief Compute the effective load address, from an objectfile virtual
comment|/// address. This is implemented in a format-specific way, to take into
comment|/// account things like PIE/ASLR when doing dynamic disassembly.
comment|/// For example, on Mach-O this would be done by adding the VM addr slide,
comment|/// on glibc ELF by keeping a map between segment load addresses, filled
comment|/// using dl_iterate_phdr, etc..
comment|/// In most static situations and in the default impl., this returns \p Addr.
name|virtual
name|uint64_t
name|getEffectiveLoadAddr
parameter_list|(
name|uint64_t
name|Addr
parameter_list|)
function_decl|;
comment|/// \brief Compute the original load address, as specified in the objectfile.
comment|/// This is the inverse of getEffectiveLoadAddr.
name|virtual
name|uint64_t
name|getOriginalLoadAddr
parameter_list|(
name|uint64_t
name|EffectiveAddr
parameter_list|)
function_decl|;
comment|/// @}
name|protected
label|:
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|Obj
expr_stmt|;
specifier|const
name|MCDisassembler
modifier|&
name|Dis
decl_stmt|;
specifier|const
name|MCInstrAnalysis
modifier|&
name|MIA
decl_stmt|;
name|MCObjectSymbolizer
modifier|*
name|MOS
decl_stmt|;
comment|/// \brief The fallback memory region, outside the object file.
name|OwningPtr
operator|<
name|MemoryObject
operator|>
name|FallbackRegion
expr_stmt|;
comment|/// \brief Return a memory region suitable for reading starting at \p Addr.
comment|/// In most cases, this returns a StringRefMemoryObject backed by the
comment|/// containing section. When no section was found, this returns the
comment|/// FallbackRegion, if it is suitable.
comment|/// If it is not, or if there is no fallback region, this returns 0.
name|MemoryObject
modifier|*
name|getRegionFor
parameter_list|(
name|uint64_t
name|Addr
parameter_list|)
function_decl|;
name|private
label|:
comment|/// \brief Fill \p Module by creating an atom for each section.
comment|/// This could be made much smarter, using information like symbols, but also
comment|/// format-specific features, like mach-o function_start or data_in_code LCs.
name|void
name|buildSectionAtoms
parameter_list|(
name|MCModule
modifier|*
name|Module
parameter_list|)
function_decl|;
comment|/// \brief Enrich \p Module with a CFG consisting of MCFunctions.
comment|/// \param Module An MCModule returned by buildModule, with no CFG.
comment|/// NOTE: Each MCBasicBlock in a MCFunction is backed by a single MCTextAtom.
comment|/// When the CFG is built, contiguous instructions that were previously in a
comment|/// single MCTextAtom will be split in multiple basic block atoms.
name|void
name|buildCFG
parameter_list|(
name|MCModule
modifier|*
name|Module
parameter_list|)
function_decl|;
name|MCBasicBlock
modifier|*
name|getBBAt
parameter_list|(
name|MCModule
modifier|*
name|Module
parameter_list|,
name|MCFunction
modifier|*
name|MCFN
parameter_list|,
name|uint64_t
name|BeginAddr
parameter_list|,
name|AddressSetTy
modifier|&
name|CallTargets
parameter_list|,
name|AddressSetTy
modifier|&
name|TailCallTargets
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|class
name|MCMachOObjectDisassembler
range|:
name|public
name|MCObjectDisassembler
block|{
specifier|const
name|object
operator|::
name|MachOObjectFile
operator|&
name|MOOF
block|;
name|uint64_t
name|VMAddrSlide
block|;
name|uint64_t
name|HeaderLoadAddress
block|;
comment|// __DATA;__mod_init_func support.
name|llvm
operator|::
name|StringRef
name|ModInitContents
block|;
comment|// __DATA;__mod_exit_func support.
name|llvm
operator|::
name|StringRef
name|ModExitContents
block|;
name|public
operator|:
comment|/// \brief Construct a Mach-O specific object disassembler.
comment|/// \param VMAddrSlide The virtual address slide applied by dyld.
comment|/// \param HeaderLoadAddress The load address of the mach_header for this
comment|/// object.
name|MCMachOObjectDisassembler
argument_list|(
argument|const object::MachOObjectFile&MOOF
argument_list|,
argument|const MCDisassembler&Dis
argument_list|,
argument|const MCInstrAnalysis&MIA
argument_list|,
argument|uint64_t VMAddrSlide
argument_list|,
argument|uint64_t HeaderLoadAddress
argument_list|)
block|;
name|protected
operator|:
name|uint64_t
name|getEffectiveLoadAddr
argument_list|(
argument|uint64_t Addr
argument_list|)
name|LLVM_OVERRIDE
block|;
name|uint64_t
name|getOriginalLoadAddr
argument_list|(
argument|uint64_t EffectiveAddr
argument_list|)
name|LLVM_OVERRIDE
block|;
name|uint64_t
name|getEntrypoint
argument_list|()
name|LLVM_OVERRIDE
block|;
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|getStaticInitFunctions
argument_list|()
name|LLVM_OVERRIDE
block|;
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|getStaticExitFunctions
argument_list|()
name|LLVM_OVERRIDE
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

