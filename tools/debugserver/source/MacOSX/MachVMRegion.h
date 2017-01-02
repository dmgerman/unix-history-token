begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachVMRegion.h ------------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 6/26/07.
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
name|__MachVMRegion_h__
end_ifndef

begin_define
define|#
directive|define
name|__MachVMRegion_h__
end_define

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_include
include|#
directive|include
file|"DNBError.h"
end_include

begin_include
include|#
directive|include
file|<mach/mach.h>
end_include

begin_decl_stmt
name|class
name|MachVMRegion
block|{
name|public
label|:
name|MachVMRegion
argument_list|(
argument|task_t task
argument_list|)
empty_stmt|;
operator|~
name|MachVMRegion
argument_list|()
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|mach_vm_address_t
name|StartAddress
argument_list|()
specifier|const
block|{
return|return
name|m_start
return|;
block|}
name|mach_vm_address_t
name|EndAddress
argument_list|()
specifier|const
block|{
return|return
name|m_start
operator|+
name|m_size
return|;
block|}
name|mach_vm_size_t
name|GetByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_size
return|;
block|}
name|mach_vm_address_t
name|BytesRemaining
argument_list|(
name|mach_vm_address_t
name|addr
argument_list|)
decl|const
block|{
if|if
condition|(
name|ContainsAddress
argument_list|(
name|addr
argument_list|)
condition|)
return|return
name|m_size
operator|-
operator|(
name|addr
operator|-
name|m_start
operator|)
return|;
else|else
return|return
literal|0
return|;
block|}
name|bool
name|ContainsAddress
argument_list|(
name|mach_vm_address_t
name|addr
argument_list|)
decl|const
block|{
return|return
name|addr
operator|>=
name|StartAddress
argument_list|()
operator|&&
name|addr
operator|<
name|EndAddress
argument_list|()
return|;
block|}
name|bool
name|SetProtections
parameter_list|(
name|mach_vm_address_t
name|addr
parameter_list|,
name|mach_vm_size_t
name|size
parameter_list|,
name|vm_prot_t
name|prot
parameter_list|)
function_decl|;
name|bool
name|RestoreProtections
parameter_list|()
function_decl|;
name|bool
name|GetRegionForAddress
parameter_list|(
name|nub_addr_t
name|addr
parameter_list|)
function_decl|;
name|uint32_t
name|GetDNBPermissions
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|DNBError
modifier|&
name|GetError
parameter_list|()
block|{
return|return
name|m_err
return|;
block|}
name|protected
label|:
if|#
directive|if
name|defined
argument_list|(
name|VM_REGION_SUBMAP_SHORT_INFO_COUNT_64
argument_list|)
typedef|typedef
name|vm_region_submap_short_info_data_64_t
name|RegionInfo
typedef|;
enum|enum
block|{
name|kRegionInfoSize
init|=
name|VM_REGION_SUBMAP_SHORT_INFO_COUNT_64
block|}
enum|;
else|#
directive|else
typedef|typedef
name|vm_region_submap_info_data_64_t
name|RegionInfo
typedef|;
enum|enum
block|{
name|kRegionInfoSize
init|=
name|VM_REGION_SUBMAP_INFO_COUNT_64
block|}
enum|;
endif|#
directive|endif
name|task_t
name|m_task
decl_stmt|;
name|mach_vm_address_t
name|m_addr
decl_stmt|;
name|DNBError
name|m_err
decl_stmt|;
name|mach_vm_address_t
name|m_start
decl_stmt|;
name|mach_vm_size_t
name|m_size
decl_stmt|;
name|natural_t
name|m_depth
decl_stmt|;
name|RegionInfo
name|m_data
decl_stmt|;
name|vm_prot_t
name|m_curr_protection
decl_stmt|;
comment|// The current, possibly modified protections.
comment|// Original value is saved in m_data.protections.
name|mach_vm_address_t
name|m_protection_addr
decl_stmt|;
comment|// The start address at which protections were changed
name|mach_vm_size_t
name|m_protection_size
decl_stmt|;
comment|// The size of memory that had its protections changed
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __MachVMRegion_h__
end_comment

end_unit

