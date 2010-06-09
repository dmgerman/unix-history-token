begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- target_ocaml.c - LLVM Ocaml Glue ------------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's ocaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Target.h"
end_include

begin_include
include|#
directive|include
file|"caml/alloc.h"
end_include

begin_comment
comment|/* string -> TargetData.t */
end_comment

begin_function
name|CAMLprim
name|LLVMTargetDataRef
name|llvm_targetdata_create
parameter_list|(
name|value
name|StringRep
parameter_list|)
block|{
return|return
name|LLVMCreateTargetData
argument_list|(
name|String_val
argument_list|(
name|StringRep
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_targetdata_add
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddTargetData
argument_list|(
name|TD
argument_list|,
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> string */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_targetdata_as_string
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
block|{
name|char
modifier|*
name|StringRep
init|=
name|LLVMCopyStringRepOfTargetData
argument_list|(
name|TD
argument_list|)
decl_stmt|;
name|value
name|Copy
init|=
name|copy_string
argument_list|(
name|StringRep
argument_list|)
decl_stmt|;
name|LLVMDisposeMessage
argument_list|(
name|StringRep
argument_list|)
expr_stmt|;
return|return
name|Copy
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_targetdata_invalidate_struct_layout
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
block|{
name|LLVMInvalidateStructLayout
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_targetdata_dispose
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
block|{
name|LLVMDisposeTargetData
argument_list|(
name|TD
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Endian.t */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_byte_order
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
block|{
return|return
name|Val_int
argument_list|(
name|LLVMByteOrder
argument_list|(
name|TD
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> int */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_pointer_size
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
block|{
return|return
name|Val_int
argument_list|(
name|LLVMPointerSize
argument_list|(
name|TD
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> Int64.t */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_size_in_bits
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
block|{
return|return
name|caml_copy_int64
argument_list|(
name|LLVMSizeOfTypeInBits
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> Int64.t */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_store_size
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
block|{
return|return
name|caml_copy_int64
argument_list|(
name|LLVMStoreSizeOfType
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> Int64.t */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_abi_size
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
block|{
return|return
name|caml_copy_int64
argument_list|(
name|LLVMABISizeOfType
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> int */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_abi_align
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
block|{
return|return
name|Val_int
argument_list|(
name|LLVMABIAlignmentOfType
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> int */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_stack_align
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
block|{
return|return
name|Val_int
argument_list|(
name|LLVMCallFrameAlignmentOfType
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> int */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_preferred_align
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
block|{
return|return
name|Val_int
argument_list|(
name|LLVMPreferredAlignmentOfType
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.llvalue -> int */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_preferred_align_of_global
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMValueRef
name|GlobalVar
parameter_list|)
block|{
return|return
name|Val_int
argument_list|(
name|LLVMPreferredAlignmentOfGlobal
argument_list|(
name|TD
argument_list|,
name|GlobalVar
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> Int64.t -> int */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_element_at_offset
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|,
name|value
name|Offset
parameter_list|)
block|{
return|return
name|Val_int
argument_list|(
name|LLVMElementAtOffset
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|,
name|Int_val
argument_list|(
name|Offset
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* TargetData.t -> Llvm.lltype -> int -> Int64.t */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_offset_of_element
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|,
name|value
name|Index
parameter_list|)
block|{
return|return
name|caml_copy_int64
argument_list|(
name|LLVMOffsetOfElement
argument_list|(
name|TD
argument_list|,
name|Ty
argument_list|,
name|Int_val
argument_list|(
name|Index
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

