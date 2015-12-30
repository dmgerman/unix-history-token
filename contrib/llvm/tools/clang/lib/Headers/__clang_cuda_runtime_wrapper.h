begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- __clang_cuda_runtime_wrapper.h - CUDA runtime support -------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_comment
comment|/*  * WARNING: This header is intended to be directly -include'd by  * the compiler and is not supposed to be included by users.  *  * CUDA headers are implemented in a way that currently makes it  * impossible for user code to #include directly when compiling with  * Clang. They present different view of CUDA-supplied functions  * depending on where in NVCC's compilation pipeline the headers are  * included. Neither of these modes provides function definitions with  * correct attributes, so we use preprocessor to force the headers  * into a form that Clang can use.  *  * Similarly to NVCC which -include's cuda_runtime.h, Clang -include's  * this file during every CUDA compilation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CLANG_CUDA_RUNTIME_WRAPPER_H__
end_ifndef

begin_define
define|#
directive|define
name|__CLANG_CUDA_RUNTIME_WRAPPER_H__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CUDA__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_comment
comment|// Include some standard headers to avoid CUDA headers including them
end_comment

begin_comment
comment|// while some required macros (like __THROW) are in a weird state.
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_comment
comment|// Preserve common macros that will be changed below by us or by CUDA
end_comment

begin_comment
comment|// headers.
end_comment

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"__THROW"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"__CUDA_ARCH__"
name|)
end_pragma

begin_comment
comment|// WARNING: Preprocessor hacks below are based on specific details of
end_comment

begin_comment
comment|// CUDA-7.x headers and are not expected to work with any other
end_comment

begin_comment
comment|// version of CUDA headers.
end_comment

begin_include
include|#
directive|include
file|"cuda.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CUDA_VERSION
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"cuda.h did not define CUDA_VERSION"
end_error

begin_elif
elif|#
directive|elif
name|CUDA_VERSION
operator|<
literal|7000
operator|||
name|CUDA_VERSION
operator|>
literal|7050
end_elif

begin_error
error|#
directive|error
literal|"Unsupported CUDA version!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Make largest subset of device functions available during host
end_comment

begin_comment
comment|// compilation -- SM_35 for the time being.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CUDA_ARCH__
end_ifndef

begin_define
define|#
directive|define
name|__CUDA_ARCH__
value|350
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"cuda_builtin_vars.h"
end_include

begin_comment
comment|// No need for device_launch_parameters.h as cuda_builtin_vars.h above
end_comment

begin_comment
comment|// has taken care of builtin variables declared in the file.
end_comment

begin_define
define|#
directive|define
name|__DEVICE_LAUNCH_PARAMETERS_H__
end_define

begin_comment
comment|// {math,device}_functions.h only have declarations of the
end_comment

begin_comment
comment|// functions. We don't need them as we're going to pull in their
end_comment

begin_comment
comment|// definitions from .hpp files.
end_comment

begin_define
define|#
directive|define
name|__DEVICE_FUNCTIONS_H__
end_define

begin_define
define|#
directive|define
name|__MATH_FUNCTIONS_H__
end_define

begin_undef
undef|#
directive|undef
name|__CUDACC__
end_undef

begin_define
define|#
directive|define
name|__CUDABE__
end_define

begin_comment
comment|// Disables definitions of device-side runtime support stubs in
end_comment

begin_comment
comment|// cuda_device_runtime_api.h
end_comment

begin_define
define|#
directive|define
name|__CUDADEVRT_INTERNAL__
end_define

begin_include
include|#
directive|include
file|"host_config.h"
end_include

begin_include
include|#
directive|include
file|"host_defines.h"
end_include

begin_include
include|#
directive|include
file|"driver_types.h"
end_include

begin_include
include|#
directive|include
file|"common_functions.h"
end_include

begin_undef
undef|#
directive|undef
name|__CUDADEVRT_INTERNAL__
end_undef

begin_undef
undef|#
directive|undef
name|__CUDABE__
end_undef

begin_define
define|#
directive|define
name|__CUDACC__
end_define

begin_include
include|#
directive|include
file|"cuda_runtime.h"
end_include

begin_undef
undef|#
directive|undef
name|__CUDACC__
end_undef

begin_define
define|#
directive|define
name|__CUDABE__
end_define

begin_comment
comment|// CUDA headers use __nvvm_memcpy and __nvvm_memset which Clang does
end_comment

begin_comment
comment|// not have at the moment. Emulate them with a builtin memcpy/memset.
end_comment

begin_define
define|#
directive|define
name|__nvvm_memcpy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|a
parameter_list|)
value|__builtin_memcpy(s,d,n)
end_define

begin_define
define|#
directive|define
name|__nvvm_memset
parameter_list|(
name|d
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|,
name|a
parameter_list|)
value|__builtin_memset(d,c,n)
end_define

begin_include
include|#
directive|include
file|"crt/host_runtime.h"
end_include

begin_include
include|#
directive|include
file|"crt/device_runtime.h"
end_include

begin_comment
comment|// device_runtime.h defines __cxa_* macros that will conflict with
end_comment

begin_comment
comment|// cxxabi.h.
end_comment

begin_comment
comment|// FIXME: redefine these as __device__ functions.
end_comment

begin_undef
undef|#
directive|undef
name|__cxa_vec_ctor
end_undef

begin_undef
undef|#
directive|undef
name|__cxa_vec_cctor
end_undef

begin_undef
undef|#
directive|undef
name|__cxa_vec_dtor
end_undef

begin_undef
undef|#
directive|undef
name|__cxa_vec_new2
end_undef

begin_undef
undef|#
directive|undef
name|__cxa_vec_new3
end_undef

begin_undef
undef|#
directive|undef
name|__cxa_vec_delete2
end_undef

begin_undef
undef|#
directive|undef
name|__cxa_vec_delete
end_undef

begin_undef
undef|#
directive|undef
name|__cxa_vec_delete3
end_undef

begin_undef
undef|#
directive|undef
name|__cxa_pure_virtual
end_undef

begin_comment
comment|// We need decls for functions in CUDA's libdevice with __device__
end_comment

begin_comment
comment|// attribute only. Alas they come either as __host__ __device__ or
end_comment

begin_comment
comment|// with no attributes at all. To work around that, define __CUDA_RTC__
end_comment

begin_comment
comment|// which produces HD variant and undef __host__ which gives us desided
end_comment

begin_comment
comment|// decls with __device__ attribute.
end_comment

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"__host__"
name|)
end_pragma

begin_define
define|#
directive|define
name|__host__
end_define

begin_define
define|#
directive|define
name|__CUDACC_RTC__
end_define

begin_include
include|#
directive|include
file|"device_functions_decls.h"
end_include

begin_undef
undef|#
directive|undef
name|__CUDACC_RTC__
end_undef

begin_comment
comment|// Temporarily poison __host__ macro to ensure it's not used by any of
end_comment

begin_comment
comment|// the headers we're about to include.
end_comment

begin_define
define|#
directive|define
name|__host__
value|UNEXPECTED_HOST_ATTRIBUTE
end_define

begin_comment
comment|// device_functions.hpp and math_functions*.hpp use 'static
end_comment

begin_comment
comment|// __forceinline__' (with no __device__) for definitions of device
end_comment

begin_comment
comment|// functions. Temporarily redefine __forceinline__ to include
end_comment

begin_comment
comment|// __device__.
end_comment

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"__forceinline__"
name|)
end_pragma

begin_define
define|#
directive|define
name|__forceinline__
value|__device__ __inline__ __attribute__((always_inline))
end_define

begin_include
include|#
directive|include
file|"device_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"math_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"math_functions_dbl_ptx3.hpp"
end_include

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"__forceinline__"
name|)
end_pragma

begin_comment
comment|// Pull in host-only functions that are only available when neither
end_comment

begin_comment
comment|// __CUDACC__ nor __CUDABE__ are defined.
end_comment

begin_undef
undef|#
directive|undef
name|__MATH_FUNCTIONS_HPP__
end_undef

begin_undef
undef|#
directive|undef
name|__CUDABE__
end_undef

begin_include
include|#
directive|include
file|"math_functions.hpp"
end_include

begin_comment
comment|// Alas, additional overloads for these functions are hard to get to.
end_comment

begin_comment
comment|// Considering that we only need these overloads for a few functions,
end_comment

begin_comment
comment|// we can provide them here.
end_comment

begin_function
specifier|static
specifier|inline
name|float
name|rsqrt
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|rsqrtf
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|rcbrt
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|rcbrtf
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|sinpi
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|sinpif
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|cospi
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|cospif
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|sincospi
parameter_list|(
name|float
name|a
parameter_list|,
name|float
modifier|*
name|b
parameter_list|,
name|float
modifier|*
name|c
parameter_list|)
block|{
return|return
name|sincospi
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|erfcinv
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|erfcinvf
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|normcdfinv
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|normcdfinvf
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|normcdf
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|normcdff
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|erfcx
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|erfcxf
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// For some reason single-argument variant is not always declared by
end_comment

begin_comment
comment|// CUDA headers. Alas, device_functions.hpp included below needs it.
end_comment

begin_function
specifier|static
specifier|inline
name|__device__
name|void
name|__brkpt
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|__brkpt
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Now include *.hpp with definitions of various GPU functions.  Alas,
end_comment

begin_comment
comment|// a lot of thins get declared/defined with __host__ attribute which
end_comment

begin_comment
comment|// we don't want and we have to define it out. We also have to include
end_comment

begin_comment
comment|// {device,math}_functions.hpp again in order to extract the other
end_comment

begin_comment
comment|// branch of #if/else inside.
end_comment

begin_define
define|#
directive|define
name|__host__
end_define

begin_undef
undef|#
directive|undef
name|__CUDABE__
end_undef

begin_define
define|#
directive|define
name|__CUDACC__
end_define

begin_undef
undef|#
directive|undef
name|__DEVICE_FUNCTIONS_HPP__
end_undef

begin_include
include|#
directive|include
file|"device_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"device_atomic_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"sm_20_atomic_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"sm_32_atomic_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"sm_20_intrinsics.hpp"
end_include

begin_comment
comment|// sm_30_intrinsics.h has declarations that use default argument, so
end_comment

begin_comment
comment|// we have to include it and it will in turn include .hpp
end_comment

begin_include
include|#
directive|include
file|"sm_30_intrinsics.h"
end_include

begin_include
include|#
directive|include
file|"sm_32_intrinsics.hpp"
end_include

begin_undef
undef|#
directive|undef
name|__MATH_FUNCTIONS_HPP__
end_undef

begin_include
include|#
directive|include
file|"math_functions.hpp"
end_include

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"__host__"
name|)
end_pragma

begin_include
include|#
directive|include
file|"texture_indirect_functions.h"
end_include

begin_comment
comment|// Restore state of __CUDA_ARCH__ and __THROW we had on entry.
end_comment

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"__CUDA_ARCH__"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"__THROW"
name|)
end_pragma

begin_comment
comment|// Set up compiler macros expected to be seen during compilation.
end_comment

begin_undef
undef|#
directive|undef
name|__CUDABE__
end_undef

begin_define
define|#
directive|define
name|__CUDACC__
end_define

begin_define
define|#
directive|define
name|__NVCC__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CUDA_ARCH__
argument_list|)
end_if

begin_comment
comment|// We need to emit IR declaration for non-existing __nvvm_reflect() to
end_comment

begin_comment
comment|// let backend know that it should be treated as const nothrow
end_comment

begin_comment
comment|// function which is what NVVMReflect pass expects to see.
end_comment

begin_extern
extern|extern
literal|"C"
name|__device__
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
name|int
name|__nvvm_reflect
argument_list|(
specifier|const
name|void
operator|*
argument_list|)
decl_stmt|;
end_extern

begin_decl_stmt
specifier|static
name|__device__
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|int
name|__nvvm_reflect_anchor
argument_list|()
block|{
return|return
name|__nvvm_reflect
argument_list|(
literal|"NONE"
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __CUDA__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __CLANG_CUDA_RUNTIME_WRAPPER_H__
end_comment

end_unit

