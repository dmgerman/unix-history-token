begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- cuda_builtin_vars.h - CUDA built-in variables ---------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CUDA_BUILTIN_VARS_H
end_ifndef

begin_define
define|#
directive|define
name|__CUDA_BUILTIN_VARS_H
end_define

begin_comment
comment|// Forward declares from vector_types.h.
end_comment

begin_struct_decl
struct_decl|struct
name|uint3
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dim3
struct_decl|;
end_struct_decl

begin_comment
comment|// The file implements built-in CUDA variables using __declspec(property).
end_comment

begin_comment
comment|// https://msdn.microsoft.com/en-us/library/yhfk0thd.aspx
end_comment

begin_comment
comment|// All read accesses of built-in variable fields get converted into calls to a
end_comment

begin_comment
comment|// getter function which in turn calls the appropriate builtin to fetch the
end_comment

begin_comment
comment|// value.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Example:
end_comment

begin_comment
comment|//    int x = threadIdx.x;
end_comment

begin_comment
comment|// IR output:
end_comment

begin_comment
comment|//  %0 = call i32 @llvm.nvvm.read.ptx.sreg.tid.x() #3
end_comment

begin_comment
comment|// PTX output:
end_comment

begin_comment
comment|//  mov.u32     %r2, %tid.x;
end_comment

begin_define
define|#
directive|define
name|__CUDA_DEVICE_BUILTIN
parameter_list|(
name|FIELD
parameter_list|,
name|INTRINSIC
parameter_list|)
define|\
value|__declspec(property(get = __fetch_builtin_##FIELD)) unsigned int FIELD;      \   static inline __attribute__((always_inline))                                 \       __attribute__((device)) unsigned int __fetch_builtin_##FIELD(void) {     \     return INTRINSIC;                                                          \   }
end_define

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_define
define|#
directive|define
name|__DELETE
value|=delete
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__DELETE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Make sure nobody can create instances of the special varible types.  nvcc
end_comment

begin_comment
comment|// also disallows taking address of special variables, so we disable address-of
end_comment

begin_comment
comment|// operator as well.
end_comment

begin_define
define|#
directive|define
name|__CUDA_DISALLOW_BUILTINVAR_ACCESS
parameter_list|(
name|TypeName
parameter_list|)
define|\
value|__attribute__((device)) TypeName() __DELETE;                                 \   __attribute__((device)) TypeName(const TypeName&) __DELETE;                 \   __attribute__((device)) void operator=(const TypeName&) const __DELETE;     \   __attribute__((device)) TypeName *operator&() const __DELETE
end_define

begin_struct
struct|struct
name|__cuda_builtin_threadIdx_t
block|{
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|x
argument_list|,
name|__nvvm_read_ptx_sreg_tid_x
argument_list|()
argument_list|)
expr_stmt|;
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|y
argument_list|,
name|__nvvm_read_ptx_sreg_tid_y
argument_list|()
argument_list|)
expr_stmt|;
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|z
argument_list|,
name|__nvvm_read_ptx_sreg_tid_z
argument_list|()
argument_list|)
expr_stmt|;
comment|// threadIdx should be convertible to uint3 (in fact in nvcc, it *is* a
comment|// uint3).  This function is defined after we pull in vector_types.h.
name|__attribute__
argument_list|(
argument|(device)
argument_list|)
name|operator
name|uint3
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|__CUDA_DISALLOW_BUILTINVAR_ACCESS
argument_list|(
name|__cuda_builtin_threadIdx_t
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__cuda_builtin_blockIdx_t
block|{
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|x
argument_list|,
name|__nvvm_read_ptx_sreg_ctaid_x
argument_list|()
argument_list|)
expr_stmt|;
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|y
argument_list|,
name|__nvvm_read_ptx_sreg_ctaid_y
argument_list|()
argument_list|)
expr_stmt|;
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|z
argument_list|,
name|__nvvm_read_ptx_sreg_ctaid_z
argument_list|()
argument_list|)
expr_stmt|;
comment|// blockIdx should be convertible to uint3 (in fact in nvcc, it *is* a
comment|// uint3).  This function is defined after we pull in vector_types.h.
name|__attribute__
argument_list|(
argument|(device)
argument_list|)
name|operator
name|uint3
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|__CUDA_DISALLOW_BUILTINVAR_ACCESS
argument_list|(
name|__cuda_builtin_blockIdx_t
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__cuda_builtin_blockDim_t
block|{
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|x
argument_list|,
name|__nvvm_read_ptx_sreg_ntid_x
argument_list|()
argument_list|)
expr_stmt|;
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|y
argument_list|,
name|__nvvm_read_ptx_sreg_ntid_y
argument_list|()
argument_list|)
expr_stmt|;
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|z
argument_list|,
name|__nvvm_read_ptx_sreg_ntid_z
argument_list|()
argument_list|)
expr_stmt|;
comment|// blockDim should be convertible to dim3 (in fact in nvcc, it *is* a
comment|// dim3).  This function is defined after we pull in vector_types.h.
name|__attribute__
argument_list|(
argument|(device)
argument_list|)
name|operator
name|dim3
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|__CUDA_DISALLOW_BUILTINVAR_ACCESS
argument_list|(
name|__cuda_builtin_blockDim_t
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__cuda_builtin_gridDim_t
block|{
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|x
argument_list|,
name|__nvvm_read_ptx_sreg_nctaid_x
argument_list|()
argument_list|)
expr_stmt|;
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|y
argument_list|,
name|__nvvm_read_ptx_sreg_nctaid_y
argument_list|()
argument_list|)
expr_stmt|;
name|__CUDA_DEVICE_BUILTIN
argument_list|(
name|z
argument_list|,
name|__nvvm_read_ptx_sreg_nctaid_z
argument_list|()
argument_list|)
expr_stmt|;
comment|// gridDim should be convertible to dim3 (in fact in nvcc, it *is* a
comment|// dim3).  This function is defined after we pull in vector_types.h.
name|__attribute__
argument_list|(
argument|(device)
argument_list|)
name|operator
name|dim3
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|__CUDA_DISALLOW_BUILTINVAR_ACCESS
argument_list|(
name|__cuda_builtin_gridDim_t
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__CUDA_BUILTIN_VAR
define|\
value|extern const __attribute__((device)) __attribute__((weak))
end_define

begin_decl_stmt
name|__CUDA_BUILTIN_VAR
name|__cuda_builtin_threadIdx_t
name|threadIdx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__CUDA_BUILTIN_VAR
name|__cuda_builtin_blockIdx_t
name|blockIdx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__CUDA_BUILTIN_VAR
name|__cuda_builtin_blockDim_t
name|blockDim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__CUDA_BUILTIN_VAR
name|__cuda_builtin_gridDim_t
name|gridDim
decl_stmt|;
end_decl_stmt

begin_comment
comment|// warpSize should translate to read of %WARP_SZ but there's currently no
end_comment

begin_comment
comment|// builtin to do so. According to PTX v4.2 docs 'to date, all target
end_comment

begin_comment
comment|// architectures have a WARP_SZ value of 32'.
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(device)
argument_list|)
end_macro

begin_decl_stmt
specifier|const
name|int
name|warpSize
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|__CUDA_DEVICE_BUILTIN
end_undef

begin_undef
undef|#
directive|undef
name|__CUDA_BUILTIN_VAR
end_undef

begin_undef
undef|#
directive|undef
name|__CUDA_DISALLOW_BUILTINVAR_ACCESS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CUDA_BUILTIN_VARS_H */
end_comment

end_unit

