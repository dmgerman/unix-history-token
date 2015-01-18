begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUKernelCodeT.h - Print AMDGPU assembly code ---------*- C++ -*-===//
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
comment|/// \file AMDKernelCodeT.h
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDKERNELCODET_H
end_ifndef

begin_define
define|#
directive|define
name|AMDKERNELCODET_H
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

begin_comment
comment|//---------------------------------------------------------------------------//
end_comment

begin_comment
comment|// AMD Kernel Code, and its dependencies                                     //
end_comment

begin_comment
comment|//---------------------------------------------------------------------------//
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|hsa_powertwo8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|hsa_ext_code_kind_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|hsa_ext_brig_profile8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|hsa_ext_brig_machine_model8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|hsa_ext_control_directive_present64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|hsa_ext_exception_kind16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|hsa_ext_code_kind32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hsa_dim3_s
block|{
name|uint32_t
name|x
decl_stmt|;
name|uint32_t
name|y
decl_stmt|;
name|uint32_t
name|z
decl_stmt|;
block|}
name|hsa_dim3_t
typedef|;
end_typedef

begin_comment
comment|/// The version of the amd_*_code_t struct. Minor versions must be
end_comment

begin_comment
comment|/// backward compatible.
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|amd_code_version32_t
typedef|;
end_typedef

begin_enum
enum|enum
name|amd_code_version_t
block|{
name|AMD_CODE_VERSION_MAJOR
init|=
literal|0
block|,
name|AMD_CODE_VERSION_MINOR
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/// The values used to define the number of bytes to use for the
end_comment

begin_comment
comment|/// swizzle element size.
end_comment

begin_enum
enum|enum
name|amd_element_byte_size_t
block|{
name|AMD_ELEMENT_2_BYTES
init|=
literal|0
block|,
name|AMD_ELEMENT_4_BYTES
init|=
literal|1
block|,
name|AMD_ELEMENT_8_BYTES
init|=
literal|2
block|,
name|AMD_ELEMENT_16_BYTES
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/// Shader program settings for CS. Contains COMPUTE_PGM_RSRC1 and
end_comment

begin_comment
comment|/// COMPUTE_PGM_RSRC2 registers.
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|amd_compute_pgm_resource_register64_t
typedef|;
end_typedef

begin_comment
comment|/// Every amd_*_code_t has the following properties, which are composed of
end_comment

begin_comment
comment|/// a number of bit fields. Every bit field has a mask (AMD_CODE_PROPERTY_*),
end_comment

begin_comment
comment|/// bit width (AMD_CODE_PROPERTY_*_WIDTH, and bit shift amount
end_comment

begin_comment
comment|/// (AMD_CODE_PROPERTY_*_SHIFT) for convenient access. Unused bits must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// (Note that bit fields cannot be used as their layout is
end_comment

begin_comment
comment|/// implementation defined in the C standard and so cannot be used to
end_comment

begin_comment
comment|/// specify an ABI)
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|amd_code_property32_t
typedef|;
end_typedef

begin_enum
enum|enum
name|amd_code_property_mask_t
block|{
comment|/// Enable the setup of the SGPR user data registers
comment|/// (AMD_CODE_PROPERTY_ENABLE_SGPR_*), see documentation of amd_kernel_code_t
comment|/// for initial register state.
comment|///
comment|/// The total number of SGPRuser data registers requested must not
comment|/// exceed 16. Any requests beyond 16 will be ignored.
comment|///
comment|/// Used to set COMPUTE_PGM_RSRC2.USER_SGPR (set to total count of
comment|/// SGPR user data registers enabled up to 16).
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_BUFFER_SHIFT
init|=
literal|0
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_BUFFER_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_BUFFER
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_BUFFER_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_BUFFER_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_PTR_SHIFT
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_PTR_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_PTR
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_PTR_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_PTR_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_QUEUE_PTR_SHIFT
init|=
literal|2
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_QUEUE_PTR_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_QUEUE_PTR
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_QUEUE_PTR_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_QUEUE_PTR_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_KERNARG_SEGMENT_PTR_SHIFT
init|=
literal|3
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_KERNARG_SEGMENT_PTR_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_KERNARG_SEGMENT_PTR
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_KERNARG_SEGMENT_PTR_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_KERNARG_SEGMENT_PTR_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_ID_SHIFT
init|=
literal|4
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_ID_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_ID
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_ID_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_DISPATCH_ID_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_FLAT_SCRATCH_INIT_SHIFT
init|=
literal|5
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_FLAT_SCRATCH_INIT_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_FLAT_SCRATCH_INIT
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_FLAT_SCRATCH_INIT_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_FLAT_SCRATCH_INIT_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_SIZE_SHIFT
init|=
literal|6
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_SIZE_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_SIZE
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_SIZE_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_PRIVATE_SEGMENT_SIZE_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_X_SHIFT
init|=
literal|7
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_X_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_X
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_X_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_X_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Y_SHIFT
init|=
literal|8
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Y_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Y
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Y_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Y_SHIFT
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Z_SHIFT
init|=
literal|9
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Z_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Z
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Z_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_SGPR_GRID_WORKGROUP_COUNT_Z_SHIFT
block|,
comment|/// Control wave ID base counter for GDS ordered-append. Used to set
comment|/// COMPUTE_DISPATCH_INITIATOR.ORDERED_APPEND_ENBL. (Not sure if
comment|/// ORDERED_APPEND_MODE also needs to be settable)
name|AMD_CODE_PROPERTY_ENABLE_ORDERED_APPEND_GDS_SHIFT
init|=
literal|10
block|,
name|AMD_CODE_PROPERTY_ENABLE_ORDERED_APPEND_GDS_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_ENABLE_ORDERED_APPEND_GDS
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_ORDERED_APPEND_GDS_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_ENABLE_ORDERED_APPEND_GDS_SHIFT
block|,
comment|/// The interleave (swizzle) element size in bytes required by the
comment|/// code for private memory. This must be 2, 4, 8 or 16. This value
comment|/// is provided to the finalizer when it is invoked and is recorded
comment|/// here. The hardware will interleave the memory requests of each
comment|/// lane of a wavefront by this element size to ensure each
comment|/// work-item gets a distinct memory memory location. Therefore, the
comment|/// finalizer ensures that all load and store operations done to
comment|/// private memory do not exceed this size. For example, if the
comment|/// element size is 4 (32-bits or dword) and a 64-bit value must be
comment|/// loaded, the finalizer will generate two 32-bit loads. This
comment|/// ensures that the interleaving will get the the work-item
comment|/// specific dword for both halves of the 64-bit value. If it just
comment|/// did a 64-bit load then it would get one dword which belonged to
comment|/// its own work-item, but the second dword would belong to the
comment|/// adjacent lane work-item since the interleaving is in dwords.
comment|///
comment|/// The value used must match the value that the runtime configures
comment|/// the GPU flat scratch (SH_STATIC_MEM_CONFIG.ELEMENT_SIZE). This
comment|/// is generally DWORD.
comment|///
comment|/// Use values from the amd_element_byte_size_t enum.
name|AMD_CODE_PROPERTY_PRIVATE_ELEMENT_SIZE_SHIFT
init|=
literal|11
block|,
name|AMD_CODE_PROPERTY_PRIVATE_ELEMENT_SIZE_WIDTH
init|=
literal|2
block|,
name|AMD_CODE_PROPERTY_PRIVATE_ELEMENT_SIZE
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_PRIVATE_ELEMENT_SIZE_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_PRIVATE_ELEMENT_SIZE_SHIFT
block|,
comment|/// Are global memory addresses 64 bits. Must match
comment|/// amd_kernel_code_t.hsail_machine_model ==
comment|/// HSA_MACHINE_LARGE. Must also match
comment|/// SH_MEM_CONFIG.PTR32 (GFX6 (SI)/GFX7 (CI)),
comment|/// SH_MEM_CONFIG.ADDRESS_MODE (GFX8 (VI)+).
name|AMD_CODE_PROPERTY_IS_PTR64_SHIFT
init|=
literal|13
block|,
name|AMD_CODE_PROPERTY_IS_PTR64_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_IS_PTR64
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_IS_PTR64_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_IS_PTR64_SHIFT
block|,
comment|/// Indicate if the generated ISA is using a dynamically sized call
comment|/// stack. This can happen if calls are implemented using a call
comment|/// stack and recursion, alloca or calls to indirect functions are
comment|/// present. In these cases the Finalizer cannot compute the total
comment|/// private segment size at compile time. In this case the
comment|/// workitem_private_segment_byte_size only specifies the statically
comment|/// know private segment size, and additional space must be added
comment|/// for the call stack.
name|AMD_CODE_PROPERTY_IS_DYNAMIC_CALLSTACK_SHIFT
init|=
literal|14
block|,
name|AMD_CODE_PROPERTY_IS_DYNAMIC_CALLSTACK_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_IS_DYNAMIC_CALLSTACK
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_IS_DYNAMIC_CALLSTACK_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_IS_DYNAMIC_CALLSTACK_SHIFT
block|,
comment|/// Indicate if code generated has support for debugging.
name|AMD_CODE_PROPERTY_IS_DEBUG_SUPPORTED_SHIFT
init|=
literal|15
block|,
name|AMD_CODE_PROPERTY_IS_DEBUG_SUPPORTED_WIDTH
init|=
literal|1
block|,
name|AMD_CODE_PROPERTY_IS_DEBUG_SUPPORTED
init|=
operator|(
operator|(
literal|1
operator|<<
name|AMD_CODE_PROPERTY_IS_DEBUG_SUPPORTED_WIDTH
operator|)
operator|-
literal|1
operator|)
operator|<<
name|AMD_CODE_PROPERTY_IS_DEBUG_SUPPORTED_SHIFT
block|}
enum|;
end_enum

begin_comment
comment|/// @brief The hsa_ext_control_directives_t specifies the values for the HSAIL
end_comment

begin_comment
comment|/// control directives. These control how the finalizer generates code. This
end_comment

begin_comment
comment|/// struct is used both as an argument to hsaFinalizeKernel to specify values for
end_comment

begin_comment
comment|/// the control directives, and is used in HsaKernelCode to record the values of
end_comment

begin_comment
comment|/// the control directives that the finalize used when generating the code which
end_comment

begin_comment
comment|/// either came from the finalizer argument or explicit HSAIL control
end_comment

begin_comment
comment|/// directives. See the definition of the control directives in HSA Programmer's
end_comment

begin_comment
comment|/// Reference Manual which also defines how the values specified as finalizer
end_comment

begin_comment
comment|/// arguments have to agree with the control directives in the HSAIL code.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hsa_ext_control_directives_s
block|{
comment|/// This is a bit set indicating which control directives have been
comment|/// specified. If the value is 0 then there are no control directives specified
comment|/// and the rest of the fields can be ignored. The bits are accessed using the
comment|/// hsa_ext_control_directives_present_mask_t. Any control directive that is not
comment|/// enabled in this bit set must have the value of all 0s.
name|hsa_ext_control_directive_present64_t
name|enabled_control_directives
decl_stmt|;
comment|/// If enableBreakExceptions is not enabled then must be 0, otherwise must be
comment|/// non-0 and specifies the set of HSAIL exceptions that must have the BREAK
comment|/// policy enabled. If this set is not empty then the generated code may have
comment|/// lower performance than if the set is empty. If the kernel being finalized
comment|/// has any enablebreakexceptions control directives, then the values specified
comment|/// by this argument are unioned with the values in these control
comment|/// directives. If any of the functions the kernel calls have an
comment|/// enablebreakexceptions control directive, then they must be equal or a
comment|/// subset of, this union.
name|hsa_ext_exception_kind16_t
name|enable_break_exceptions
decl_stmt|;
comment|/// If enableDetectExceptions is not enabled then must be 0, otherwise must be
comment|/// non-0 and specifies the set of HSAIL exceptions that must have the DETECT
comment|/// policy enabled. If this set is not empty then the generated code may have
comment|/// lower performance than if the set is empty. However, an implementation
comment|/// should endeavour to make the performance impact small. If the kernel being
comment|/// finalized has any enabledetectexceptions control directives, then the
comment|/// values specified by this argument are unioned with the values in these
comment|/// control directives. If any of the functions the kernel calls have an
comment|/// enabledetectexceptions control directive, then they must be equal or a
comment|/// subset of, this union.
name|hsa_ext_exception_kind16_t
name|enable_detect_exceptions
decl_stmt|;
comment|/// If maxDynamicGroupSize is not enabled then must be 0, and any amount of
comment|/// dynamic group segment can be allocated for a dispatch, otherwise the value
comment|/// specifies the maximum number of bytes of dynamic group segment that can be
comment|/// allocated for a dispatch. If the kernel being finalized has any
comment|/// maxdynamicsize control directives, then the values must be the same, and
comment|/// must be the same as this argument if it is enabled. This value can be used
comment|/// by the finalizer to determine the maximum number of bytes of group memory
comment|/// used by each work-group by adding this value to the group memory required
comment|/// for all group segment variables used by the kernel and all functions it
comment|/// calls, and group memory used to implement other HSAIL features such as
comment|/// fbarriers and the detect exception operations. This can allow the finalizer
comment|/// to determine the expected number of work-groups that can be executed by a
comment|/// compute unit and allow more resources to be allocated to the work-items if
comment|/// it is known that fewer work-groups can be executed due to group memory
comment|/// limitations.
name|uint32_t
name|max_dynamic_group_size
decl_stmt|;
comment|/// If maxFlatGridSize is not enabled then must be 0, otherwise must be greater
comment|/// than 0. See HSA Programmer's Reference Manual description of
comment|/// maxflatgridsize control directive.
name|uint32_t
name|max_flat_grid_size
decl_stmt|;
comment|/// If maxFlatWorkgroupSize is not enabled then must be 0, otherwise must be
comment|/// greater than 0. See HSA Programmer's Reference Manual description of
comment|/// maxflatworkgroupsize control directive.
name|uint32_t
name|max_flat_workgroup_size
decl_stmt|;
comment|/// If requestedWorkgroupsPerCu is not enabled then must be 0, and the
comment|/// finalizer is free to generate ISA that may result in any number of
comment|/// work-groups executing on a single compute unit. Otherwise, the finalizer
comment|/// should attempt to generate ISA that will allow the specified number of
comment|/// work-groups to execute on a single compute unit. This is only a hint and
comment|/// can be ignored by the finalizer. If the kernel being finalized, or any of
comment|/// the functions it calls, has a requested control directive, then the values
comment|/// must be the same. This can be used to determine the number of resources
comment|/// that should be allocated to a single work-group and work-item. For example,
comment|/// a low value may allow more resources to be allocated, resulting in higher
comment|/// per work-item performance, as it is known there will never be more than the
comment|/// specified number of work-groups actually executing on the compute
comment|/// unit. Conversely, a high value may allocate fewer resources, resulting in
comment|/// lower per work-item performance, which is offset by the fact it allows more
comment|/// work-groups to actually execute on the compute unit.
name|uint32_t
name|requested_workgroups_per_cu
decl_stmt|;
comment|/// If not enabled then all elements for Dim3 must be 0, otherwise every
comment|/// element must be greater than 0. See HSA Programmer's Reference Manual
comment|/// description of requiredgridsize control directive.
name|hsa_dim3_t
name|required_grid_size
decl_stmt|;
comment|/// If requiredWorkgroupSize is not enabled then all elements for Dim3 must be
comment|/// 0, and the produced code can be dispatched with any legal work-group range
comment|/// consistent with the dispatch dimensions. Otherwise, the code produced must
comment|/// always be dispatched with the specified work-group range. No element of the
comment|/// specified range must be 0. It must be consistent with required_dimensions
comment|/// and max_flat_workgroup_size. If the kernel being finalized, or any of the
comment|/// functions it calls, has a requiredworkgroupsize control directive, then the
comment|/// values must be the same. Specifying a value can allow the finalizer to
comment|/// optimize work-group id operations, and if the number of work-items in the
comment|/// work-group is less than the WAVESIZE then barrier operations can be
comment|/// optimized to just a memory fence.
name|hsa_dim3_t
name|required_workgroup_size
decl_stmt|;
comment|/// If requiredDim is not enabled then must be 0 and the produced kernel code
comment|/// can be dispatched with 1, 2 or 3 dimensions. If enabled then the value is
comment|/// 1..3 and the code produced must only be dispatched with a dimension that
comment|/// matches. Other values are illegal. If the kernel being finalized, or any of
comment|/// the functions it calls, has a requireddimsize control directive, then the
comment|/// values must be the same. This can be used to optimize the code generated to
comment|/// compute the absolute and flat work-group and work-item id, and the dim
comment|/// HSAIL operations.
name|uint8_t
name|required_dim
decl_stmt|;
comment|/// Reserved. Must be 0.
name|uint8_t
name|reserved
index|[
literal|75
index|]
decl_stmt|;
block|}
name|hsa_ext_control_directives_t
typedef|;
end_typedef

begin_comment
comment|/// AMD Kernel Code Object (amd_kernel_code_t). GPU CP uses the AMD Kernel
end_comment

begin_comment
comment|/// Code Object to set up the hardware to execute the kernel dispatch.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Initial Kernel Register State.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Initial kernel register state will be set up by CP/SPI prior to the start
end_comment

begin_comment
comment|/// of execution of every wavefront. This is limited by the constraints of the
end_comment

begin_comment
comment|/// current hardware.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The order of the SGPR registers is defined, but the Finalizer can specify
end_comment

begin_comment
comment|/// which ones are actually setup in the amd_kernel_code_t object using the
end_comment

begin_comment
comment|/// enable_sgpr_* bit fields. The register numbers used for enabled registers
end_comment

begin_comment
comment|/// are dense starting at SGPR0: the first enabled register is SGPR0, the next
end_comment

begin_comment
comment|/// enabled register is SGPR1 etc.; disabled registers do not have an SGPR
end_comment

begin_comment
comment|/// number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The initial SGPRs comprise up to 16 User SRGPs that are set up by CP and
end_comment

begin_comment
comment|/// apply to all waves of the grid. It is possible to specify more than 16 User
end_comment

begin_comment
comment|/// SGPRs using the enable_sgpr_* bit fields, in which case only the first 16
end_comment

begin_comment
comment|/// are actually initialized. These are then immediately followed by the System
end_comment

begin_comment
comment|/// SGPRs that are set up by ADC/SPI and can have different values for each wave
end_comment

begin_comment
comment|/// of the grid dispatch.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// SGPR register initial state is defined as follows:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Private Segment Buffer (enable_sgpr_private_segment_buffer):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 4. V# that can be used, together with
end_comment

begin_comment
comment|///   Scratch Wave Offset as an offset, to access the Private/Spill/Arg
end_comment

begin_comment
comment|///   segments using a segment address. It must be set as follows:
end_comment

begin_comment
comment|///     - Base address: of the scratch memory area used by the dispatch. It
end_comment

begin_comment
comment|///       does not include the scratch wave offset. It will be the per process
end_comment

begin_comment
comment|///       SH_HIDDEN_PRIVATE_BASE_VMID plus any offset from this dispatch (for
end_comment

begin_comment
comment|///       example there may be a per pipe offset, or per AQL Queue offset).
end_comment

begin_comment
comment|///     - Stride + data_format: Element Size * Index Stride (???)
end_comment

begin_comment
comment|///     - Cache swizzle: ???
end_comment

begin_comment
comment|///     - Swizzle enable: SH_STATIC_MEM_CONFIG.SWIZZLE_ENABLE (must be 1 for
end_comment

begin_comment
comment|///       scratch)
end_comment

begin_comment
comment|///     - Num records: Flat Scratch Work Item Size / Element Size (???)
end_comment

begin_comment
comment|///     - Dst_sel_*: ???
end_comment

begin_comment
comment|///     - Num_format: ???
end_comment

begin_comment
comment|///     - Element_size: SH_STATIC_MEM_CONFIG.ELEMENT_SIZE (will be DWORD, must
end_comment

begin_comment
comment|///       agree with amd_kernel_code_t.privateElementSize)
end_comment

begin_comment
comment|///     - Index_stride: SH_STATIC_MEM_CONFIG.INDEX_STRIDE (will be 64 as must
end_comment

begin_comment
comment|///       be number of wavefront lanes for scratch, must agree with
end_comment

begin_comment
comment|///       amd_kernel_code_t.wavefrontSize)
end_comment

begin_comment
comment|///     - Add tid enable: 1
end_comment

begin_comment
comment|///     - ATC: from SH_MEM_CONFIG.PRIVATE_ATC,
end_comment

begin_comment
comment|///     - Hash_enable: ???
end_comment

begin_comment
comment|///     - Heap: ???
end_comment

begin_comment
comment|///     - Mtype: from SH_STATIC_MEM_CONFIG.PRIVATE_MTYPE
end_comment

begin_comment
comment|///     - Type: 0 (a buffer) (???)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Dispatch Ptr (enable_sgpr_dispatch_ptr):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 2. 64 bit address of AQL dispatch packet
end_comment

begin_comment
comment|///   for kernel actually executing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Queue Ptr (enable_sgpr_queue_ptr):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 2. 64 bit address of AmdQueue object for
end_comment

begin_comment
comment|///   AQL queue on which the dispatch packet was queued.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Kernarg Segment Ptr (enable_sgpr_kernarg_segment_ptr):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 2. 64 bit address of Kernarg segment. This
end_comment

begin_comment
comment|///   is directly copied from the kernargPtr in the dispatch packet. Having CP
end_comment

begin_comment
comment|///   load it once avoids loading it at the beginning of every wavefront.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Dispatch Id (enable_sgpr_dispatch_id):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 2. 64 bit Dispatch ID of the dispatch
end_comment

begin_comment
comment|///   packet being executed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Flat Scratch Init (enable_sgpr_flat_scratch_init):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 2. This is 2 SGPRs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   For CI/VI:
end_comment

begin_comment
comment|///     The first SGPR is a 32 bit byte offset from SH_MEM_HIDDEN_PRIVATE_BASE
end_comment

begin_comment
comment|///     to base of memory for scratch for this dispatch. This is the same offset
end_comment

begin_comment
comment|///     used in computing the Scratch Segment Buffer base address. The value of
end_comment

begin_comment
comment|///     Scratch Wave Offset must be added by the kernel code and moved to
end_comment

begin_comment
comment|///     SGPRn-4 for use as the FLAT SCRATCH BASE in flat memory instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     The second SGPR is 32 bit byte size of a single work-items scratch
end_comment

begin_comment
comment|///     memory usage. This is directly loaded from the dispatch packet Private
end_comment

begin_comment
comment|///     Segment Byte Size and rounded up to a multiple of DWORD.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     \todo [Does CP need to round this to>4 byte alignment?]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     The kernel code must move to SGPRn-3 for use as the FLAT SCRATCH SIZE in
end_comment

begin_comment
comment|///     flat memory instructions. Having CP load it once avoids loading it at
end_comment

begin_comment
comment|///     the beginning of every wavefront.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   For PI:
end_comment

begin_comment
comment|///     This is the 64 bit base address of the scratch backing memory for
end_comment

begin_comment
comment|///     allocated by CP for this dispatch.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Private Segment Size (enable_sgpr_private_segment_size):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 1. The 32 bit byte size of a single
end_comment

begin_comment
comment|///   work-items scratch memory allocation. This is the value from the dispatch
end_comment

begin_comment
comment|///   packet. Private Segment Byte Size rounded up by CP to a multiple of DWORD.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   \todo [Does CP need to round this to>4 byte alignment?]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Having CP load it once avoids loading it at the beginning of every
end_comment

begin_comment
comment|///   wavefront.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   \todo [This will not be used for CI/VI since it is the same value as
end_comment

begin_comment
comment|///   the second SGPR of Flat Scratch Init. However, it is need for PI which
end_comment

begin_comment
comment|///   changes meaning of Flat Scratchg Init..]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Grid Work-Group Count X (enable_sgpr_grid_workgroup_count_x):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 1. 32 bit count of the number of
end_comment

begin_comment
comment|///   work-groups in the X dimension for the grid being executed. Computed from
end_comment

begin_comment
comment|///   the fields in the HsaDispatchPacket as
end_comment

begin_comment
comment|///   ((gridSize.x+workgroupSize.x-1)/workgroupSize.x).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Grid Work-Group Count Y (enable_sgpr_grid_workgroup_count_y):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 1. 32 bit count of the number of
end_comment

begin_comment
comment|///   work-groups in the Y dimension for the grid being executed. Computed from
end_comment

begin_comment
comment|///   the fields in the HsaDispatchPacket as
end_comment

begin_comment
comment|///   ((gridSize.y+workgroupSize.y-1)/workgroupSize.y).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Only initialized if<16 previous SGPRs initialized.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Grid Work-Group Count Z (enable_sgpr_grid_workgroup_count_z):
end_comment

begin_comment
comment|///   Number of User SGPR registers: 1. 32 bit count of the number of
end_comment

begin_comment
comment|///   work-groups in the Z dimension for the grid being executed. Computed
end_comment

begin_comment
comment|///   from the fields in the HsaDispatchPacket as
end_comment

begin_comment
comment|///   ((gridSize.z+workgroupSize.z-1)/workgroupSize.z).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Only initialized if<16 previous SGPRs initialized.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Work-Group Id X (enable_sgpr_workgroup_id_x):
end_comment

begin_comment
comment|///   Number of System SGPR registers: 1. 32 bit work group id in X dimension
end_comment

begin_comment
comment|///   of grid for wavefront. Always present.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Work-Group Id Y (enable_sgpr_workgroup_id_y):
end_comment

begin_comment
comment|///   Number of System SGPR registers: 1. 32 bit work group id in Y dimension
end_comment

begin_comment
comment|///   of grid for wavefront.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Work-Group Id Z (enable_sgpr_workgroup_id_z):
end_comment

begin_comment
comment|///   Number of System SGPR registers: 1. 32 bit work group id in Z dimension
end_comment

begin_comment
comment|///   of grid for wavefront. If present then Work-group Id Y will also be
end_comment

begin_comment
comment|///   present
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Work-Group Info (enable_sgpr_workgroup_info):
end_comment

begin_comment
comment|///   Number of System SGPR registers: 1. {first_wave, 14b0000,
end_comment

begin_comment
comment|///   ordered_append_term[10:0], threadgroup_size_in_waves[5:0]}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Private Segment Wave Byte Offset
end_comment

begin_comment
comment|/// (enable_sgpr_private_segment_wave_byte_offset):
end_comment

begin_comment
comment|///   Number of System SGPR registers: 1. 32 bit byte offset from base of
end_comment

begin_comment
comment|///   dispatch scratch base. Must be used as an offset with Private/Spill/Arg
end_comment

begin_comment
comment|///   segment address when using Scratch Segment Buffer. It must be added to
end_comment

begin_comment
comment|///   Flat Scratch Offset if setting up FLAT SCRATCH for flat addressing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The order of the VGPR registers is defined, but the Finalizer can specify
end_comment

begin_comment
comment|/// which ones are actually setup in the amd_kernel_code_t object using the
end_comment

begin_comment
comment|/// enableVgpr*  bit fields. The register numbers used for enabled registers
end_comment

begin_comment
comment|/// are dense starting at VGPR0: the first enabled register is VGPR0, the next
end_comment

begin_comment
comment|/// enabled register is VGPR1 etc.; disabled registers do not have an VGPR
end_comment

begin_comment
comment|/// number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// VGPR register initial state is defined as follows:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Work-Item Id X (always initialized):
end_comment

begin_comment
comment|///   Number of registers: 1. 32 bit work item id in X dimension of work-group
end_comment

begin_comment
comment|///   for wavefront lane.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Work-Item Id X (enable_vgpr_workitem_id> 0):
end_comment

begin_comment
comment|///   Number of registers: 1. 32 bit work item id in Y dimension of work-group
end_comment

begin_comment
comment|///   for wavefront lane.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Work-Item Id X (enable_vgpr_workitem_id> 0):
end_comment

begin_comment
comment|///   Number of registers: 1. 32 bit work item id in Z dimension of work-group
end_comment

begin_comment
comment|///   for wavefront lane.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The setting of registers is being done by existing GPU hardware as follows:
end_comment

begin_comment
comment|///   1) SGPRs before the Work-Group Ids are set by CP using the 16 User Data
end_comment

begin_comment
comment|///      registers.
end_comment

begin_comment
comment|///   2) Work-group Id registers X, Y, Z are set by SPI which supports any
end_comment

begin_comment
comment|///      combination including none.
end_comment

begin_comment
comment|///   3) Scratch Wave Offset is also set by SPI which is why its value cannot
end_comment

begin_comment
comment|///      be added into the value Flat Scratch Offset which would avoid the
end_comment

begin_comment
comment|///      Finalizer generated prolog having to do the add.
end_comment

begin_comment
comment|///   4) The VGPRs are set by SPI which only supports specifying either (X),
end_comment

begin_comment
comment|///      (X, Y) or (X, Y, Z).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Flat Scratch Dispatch Offset and Flat Scratch Size are adjacent SGRRs so
end_comment

begin_comment
comment|/// they can be moved as a 64 bit value to the hardware required SGPRn-3 and
end_comment

begin_comment
comment|/// SGPRn-4 respectively using the Finalizer ?FLAT_SCRATCH? Register.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The global segment can be accessed either using flat operations or buffer
end_comment

begin_comment
comment|/// operations. If buffer operations are used then the Global Buffer used to
end_comment

begin_comment
comment|/// access HSAIL Global/Readonly/Kernarg (which are combine) segments using a
end_comment

begin_comment
comment|/// segment address is not passed into the kernel code by CP since its base
end_comment

begin_comment
comment|/// address is always 0. Instead the Finalizer generates prolog code to
end_comment

begin_comment
comment|/// initialize 4 SGPRs with a V# that has the following properties, and then
end_comment

begin_comment
comment|/// uses that in the buffer instructions:
end_comment

begin_comment
comment|///   - base address of 0
end_comment

begin_comment
comment|///   - no swizzle
end_comment

begin_comment
comment|///   - ATC=1
end_comment

begin_comment
comment|///   - MTYPE set to support memory coherence specified in
end_comment

begin_comment
comment|///     amd_kernel_code_t.globalMemoryCoherence
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When the Global Buffer is used to access the Kernarg segment, must add the
end_comment

begin_comment
comment|/// dispatch packet kernArgPtr to a kernarg segment address before using this V#.
end_comment

begin_comment
comment|/// Alternatively scalar loads can be used if the kernarg offset is uniform, as
end_comment

begin_comment
comment|/// the kernarg segment is constant for the duration of the kernel execution.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|amd_kernel_code_s
block|{
comment|/// The AMD major version of the Code Object. Must be the value
comment|/// AMD_CODE_VERSION_MAJOR.
name|amd_code_version32_t
name|amd_code_version_major
decl_stmt|;
comment|/// The AMD minor version of the Code Object. Minor versions must be
comment|/// backward compatible. Must be the value
comment|/// AMD_CODE_VERSION_MINOR.
name|amd_code_version32_t
name|amd_code_version_minor
decl_stmt|;
comment|/// The byte size of this struct. Must be set to
comment|/// sizeof(amd_kernel_code_t). Used for backward
comment|/// compatibility.
name|uint32_t
name|struct_byte_size
decl_stmt|;
comment|/// The target chip instruction set for which code has been
comment|/// generated. Values are from the E_SC_INSTRUCTION_SET enumeration
comment|/// in sc/Interface/SCCommon.h.
name|uint32_t
name|target_chip
decl_stmt|;
comment|/// Byte offset (possibly negative) from start of amd_kernel_code_t
comment|/// object to kernel's entry point instruction. The actual code for
comment|/// the kernel is required to be 256 byte aligned to match hardware
comment|/// requirements (SQ cache line is 16). The code must be position
comment|/// independent code (PIC) for AMD devices to give runtime the
comment|/// option of copying code to discrete GPU memory or APU L2
comment|/// cache. The Finalizer should endeavour to allocate all kernel
comment|/// machine code in contiguous memory pages so that a device
comment|/// pre-fetcher will tend to only pre-fetch Kernel Code objects,
comment|/// improving cache performance.
name|int64_t
name|kernel_code_entry_byte_offset
decl_stmt|;
comment|/// Range of bytes to consider prefetching expressed as an offset
comment|/// and size. The offset is from the start (possibly negative) of
comment|/// amd_kernel_code_t object. Set both to 0 if no prefetch
comment|/// information is available.
comment|///
comment|/// \todo ttye 11/15/2013 Is the prefetch definition we want? Did
comment|/// not make the size a uint64_t as prefetching more than 4GiB seems
comment|/// excessive.
name|int64_t
name|kernel_code_prefetch_byte_offset
decl_stmt|;
name|uint64_t
name|kernel_code_prefetch_byte_size
decl_stmt|;
comment|/// Number of bytes of scratch backing memory required for full
comment|/// occupancy of target chip. This takes into account the number of
comment|/// bytes of scratch per work-item, the wavefront size, the maximum
comment|/// number of wavefronts per CU, and the number of CUs. This is an
comment|/// upper limit on scratch. If the grid being dispatched is small it
comment|/// may only need less than this. If the kernel uses no scratch, or
comment|/// the Finalizer has not computed this value, it must be 0.
name|uint64_t
name|max_scratch_backing_memory_byte_size
decl_stmt|;
comment|/// Shader program settings for CS. Contains COMPUTE_PGM_RSRC1 and
comment|/// COMPUTE_PGM_RSRC2 registers.
name|amd_compute_pgm_resource_register64_t
name|compute_pgm_resource_registers
decl_stmt|;
comment|/// Code properties. See amd_code_property_mask_t for a full list of
comment|/// properties.
name|amd_code_property32_t
name|code_properties
decl_stmt|;
comment|/// The amount of memory required for the combined private, spill
comment|/// and arg segments for a work-item in bytes. If
comment|/// is_dynamic_callstack is 1 then additional space must be added to
comment|/// this value for the call stack.
name|uint32_t
name|workitem_private_segment_byte_size
decl_stmt|;
comment|/// The amount of group segment memory required by a work-group in
comment|/// bytes. This does not include any dynamically allocated group
comment|/// segment memory that may be added when the kernel is
comment|/// dispatched.
name|uint32_t
name|workgroup_group_segment_byte_size
decl_stmt|;
comment|/// Number of byte of GDS required by kernel dispatch. Must be 0 if
comment|/// not using GDS.
name|uint32_t
name|gds_segment_byte_size
decl_stmt|;
comment|/// The size in bytes of the kernarg segment that holds the values
comment|/// of the arguments to the kernel. This could be used by CP to
comment|/// prefetch the kernarg segment pointed to by the dispatch packet.
name|uint64_t
name|kernarg_segment_byte_size
decl_stmt|;
comment|/// Number of fbarrier's used in the kernel and all functions it
comment|/// calls. If the implementation uses group memory to allocate the
comment|/// fbarriers then that amount must already be included in the
comment|/// workgroup_group_segment_byte_size total.
name|uint32_t
name|workgroup_fbarrier_count
decl_stmt|;
comment|/// Number of scalar registers used by a wavefront. This includes
comment|/// the special SGPRs for VCC, Flat Scratch Base, Flat Scratch Size
comment|/// and XNACK (for GFX8 (VI)). It does not include the 16 SGPR added if a
comment|/// trap handler is enabled. Used to set COMPUTE_PGM_RSRC1.SGPRS.
name|uint16_t
name|wavefront_sgpr_count
decl_stmt|;
comment|/// Number of vector registers used by each work-item. Used to set
comment|/// COMPUTE_PGM_RSRC1.VGPRS.
name|uint16_t
name|workitem_vgpr_count
decl_stmt|;
comment|/// If reserved_vgpr_count is 0 then must be 0. Otherwise, this is the
comment|/// first fixed VGPR number reserved.
name|uint16_t
name|reserved_vgpr_first
decl_stmt|;
comment|/// The number of consecutive VGPRs reserved by the client. If
comment|/// is_debug_supported then this count includes VGPRs reserved
comment|/// for debugger use.
name|uint16_t
name|reserved_vgpr_count
decl_stmt|;
comment|/// If reserved_sgpr_count is 0 then must be 0. Otherwise, this is the
comment|/// first fixed SGPR number reserved.
name|uint16_t
name|reserved_sgpr_first
decl_stmt|;
comment|/// The number of consecutive SGPRs reserved by the client. If
comment|/// is_debug_supported then this count includes SGPRs reserved
comment|/// for debugger use.
name|uint16_t
name|reserved_sgpr_count
decl_stmt|;
comment|/// If is_debug_supported is 0 then must be 0. Otherwise, this is the
comment|/// fixed SGPR number used to hold the wave scratch offset for the
comment|/// entire kernel execution, or uint16_t(-1) if the register is not
comment|/// used or not known.
name|uint16_t
name|debug_wavefront_private_segment_offset_sgpr
decl_stmt|;
comment|/// If is_debug_supported is 0 then must be 0. Otherwise, this is the
comment|/// fixed SGPR number of the first of 4 SGPRs used to hold the
comment|/// scratch V# used for the entire kernel execution, or uint16_t(-1)
comment|/// if the registers are not used or not known.
name|uint16_t
name|debug_private_segment_buffer_sgpr
decl_stmt|;
comment|/// The maximum byte alignment of variables used by the kernel in
comment|/// the specified memory segment. Expressed as a power of two. Must
comment|/// be at least HSA_POWERTWO_16.
name|hsa_powertwo8_t
name|kernarg_segment_alignment
decl_stmt|;
name|hsa_powertwo8_t
name|group_segment_alignment
decl_stmt|;
name|hsa_powertwo8_t
name|private_segment_alignment
decl_stmt|;
name|uint8_t
name|reserved3
decl_stmt|;
comment|/// Type of code object.
name|hsa_ext_code_kind32_t
name|code_type
decl_stmt|;
comment|/// Reserved for code properties if any are defined in the future.
comment|/// There are currently no code properties so this field must be 0.
name|uint32_t
name|reserved4
decl_stmt|;
comment|/// Wavefront size expressed as a power of two. Must be a power of 2
comment|/// in range 1..64 inclusive. Used to support runtime query that
comment|/// obtains wavefront size, which may be used by application to
comment|/// allocated dynamic group memory and set the dispatch work-group
comment|/// size.
name|hsa_powertwo8_t
name|wavefront_size
decl_stmt|;
comment|/// The optimization level specified when the kernel was
comment|/// finalized.
name|uint8_t
name|optimization_level
decl_stmt|;
comment|/// The HSAIL profile defines which features are used. This
comment|/// information is from the HSAIL version directive. If this
comment|/// amd_kernel_code_t is not generated from an HSAIL compilation
comment|/// unit then must be 0.
name|hsa_ext_brig_profile8_t
name|hsail_profile
decl_stmt|;
comment|/// The HSAIL machine model gives the address sizes used by the
comment|/// code. This information is from the HSAIL version directive. If
comment|/// not generated from an HSAIL compilation unit then must still
comment|/// indicate for what machine mode the code is generated.
name|hsa_ext_brig_machine_model8_t
name|hsail_machine_model
decl_stmt|;
comment|/// The HSAIL major version. This information is from the HSAIL
comment|/// version directive. If this amd_kernel_code_t is not
comment|/// generated from an HSAIL compilation unit then must be 0.
name|uint32_t
name|hsail_version_major
decl_stmt|;
comment|/// The HSAIL minor version. This information is from the HSAIL
comment|/// version directive. If this amd_kernel_code_t is not
comment|/// generated from an HSAIL compilation unit then must be 0.
name|uint32_t
name|hsail_version_minor
decl_stmt|;
comment|/// Reserved for HSAIL target options if any are defined in the
comment|/// future. There are currently no target options so this field
comment|/// must be 0.
name|uint16_t
name|reserved5
decl_stmt|;
comment|/// Reserved. Must be 0.
name|uint16_t
name|reserved6
decl_stmt|;
comment|/// The values should be the actually values used by the finalizer
comment|/// in generating the code. This may be the union of values
comment|/// specified as finalizer arguments and explicit HSAIL control
comment|/// directives. If the finalizer chooses to ignore a control
comment|/// directive, and not generate constrained code, then the control
comment|/// directive should not be marked as enabled even though it was
comment|/// present in the HSAIL or finalizer argument. The values are
comment|/// intended to reflect the constraints that the code actually
comment|/// requires to correctly execute, not the values that were
comment|/// actually specified at finalize time.
name|hsa_ext_control_directives_t
name|control_directive
decl_stmt|;
comment|/// The code can immediately follow the amd_kernel_code_t, or can
comment|/// come after subsequent amd_kernel_code_t structs when there are
comment|/// multiple kernels in the compilation unit.
block|}
name|amd_kernel_code_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDKERNELCODET_H
end_comment

end_unit

