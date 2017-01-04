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
comment|// Include some forward declares that must come before cmath.
end_comment

begin_include
include|#
directive|include
file|<__clang_cuda_math_forward_declares.h>
end_include

begin_comment
comment|// Include some standard headers to avoid CUDA headers including them
end_comment

begin_comment
comment|// while some required macros (like __THROW) are in a weird state.
end_comment

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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
literal|8000
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
file|"__clang_cuda_builtin_vars.h"
end_include

begin_comment
comment|// No need for device_launch_parameters.h as __clang_cuda_builtin_vars.h above
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

begin_define
define|#
directive|define
name|__COMMON_FUNCTIONS_H__
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

begin_include
include|#
directive|include
file|"driver_types.h"
end_include

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
value|__builtin_memcpy(s, d, n)
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
value|__builtin_memset(d, c, n)
end_define

begin_include
include|#
directive|include
file|"crt/device_runtime.h"
end_include

begin_include
include|#
directive|include
file|"crt/host_runtime.h"
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
name|__cxa_vec_new
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
comment|// math_functions.hpp expects this host function be defined on MacOS, but it
end_comment

begin_comment
comment|// ends up not being there because of the games we play here.  Just define it
end_comment

begin_comment
comment|// ourselves; it's simple enough.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_function
specifier|inline
name|__host__
name|double
name|__signbitd
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|std
operator|::
name|signbit
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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
comment|// CUDA 8.0.41 relies on __USE_FAST_MATH__ and __CUDA_PREC_DIV's values.
end_comment

begin_comment
comment|// Previous versions used to check whether they are defined or not.
end_comment

begin_comment
comment|// CU_DEVICE_INVALID macro is only defined in 8.0.41, so we use it
end_comment

begin_comment
comment|// here to detect the switch.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CU_DEVICE_INVALID
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__USE_FAST_MATH__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__USE_FAST_MATH__
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__CUDA_PREC_DIV
argument_list|)
end_if

begin_define
define|#
directive|define
name|__CUDA_PREC_DIV
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|// math_function.hpp uses the __USE_FAST_MATH__ macro to determine whether we
end_comment

begin_comment
comment|// get the slow-but-accurate or fast-but-inaccurate versions of functions like
end_comment

begin_comment
comment|// sin and exp.  This is controlled in clang by -fcuda-approx-transcendentals.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// device_functions.hpp uses __USE_FAST_MATH__ for a different purpose (fast vs.
end_comment

begin_comment
comment|// slow divides), so we need to scope our define carefully here.
end_comment

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"__USE_FAST_MATH__"
name|)
end_pragma

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CLANG_CUDA_APPROX_TRANSCENDENTALS__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__USE_FAST_MATH__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
literal|"__USE_FAST_MATH__"
name|)
end_pragma

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
name|__a
parameter_list|)
block|{
return|return
name|rsqrtf
argument_list|(
name|__a
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
name|__a
parameter_list|)
block|{
return|return
name|rcbrtf
argument_list|(
name|__a
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
name|__a
parameter_list|)
block|{
return|return
name|sinpif
argument_list|(
name|__a
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
name|__a
parameter_list|)
block|{
return|return
name|cospif
argument_list|(
name|__a
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
name|__a
parameter_list|,
name|float
modifier|*
name|__b
parameter_list|,
name|float
modifier|*
name|__c
parameter_list|)
block|{
return|return
name|sincospif
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
name|__c
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
name|__a
parameter_list|)
block|{
return|return
name|erfcinvf
argument_list|(
name|__a
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
name|__a
parameter_list|)
block|{
return|return
name|normcdfinvf
argument_list|(
name|__a
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
name|__a
parameter_list|)
block|{
return|return
name|normcdff
argument_list|(
name|__a
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
name|__a
parameter_list|)
block|{
return|return
name|erfcxf
argument_list|(
name|__a
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
name|__c
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
file|"device_atomic_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"device_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"sm_20_atomic_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"sm_20_intrinsics.hpp"
end_include

begin_include
include|#
directive|include
file|"sm_32_atomic_functions.hpp"
end_include

begin_comment
comment|// Don't include sm_30_intrinsics.h and sm_32_intrinsics.h.  These define the
end_comment

begin_comment
comment|// __shfl and __ldg intrinsics using inline (volatile) asm, but we want to
end_comment

begin_comment
comment|// define them using builtins so that the optimizer can reason about and across
end_comment

begin_comment
comment|// these instructions.  In particular, using intrinsics for ldg gets us the
end_comment

begin_comment
comment|// [addr+imm] addressing mode, which, although it doesn't actually exist in the
end_comment

begin_comment
comment|// hardware, seems to generate faster machine code because ptxas can more easily
end_comment

begin_comment
comment|// reason about our code.
end_comment

begin_if
if|#
directive|if
name|CUDA_VERSION
operator|>=
literal|8000
end_if

begin_include
include|#
directive|include
file|"sm_60_atomic_functions.hpp"
end_include

begin_include
include|#
directive|include
file|"sm_61_intrinsics.hpp"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__MATH_FUNCTIONS_HPP__
end_undef

begin_comment
comment|// math_functions.hpp defines ::signbit as a __host__ __device__ function.  This
end_comment

begin_comment
comment|// conflicts with libstdc++'s constexpr ::signbit, so we have to rename
end_comment

begin_comment
comment|// math_function.hpp's ::signbit.  It's guarded by #undef signbit, but that's
end_comment

begin_comment
comment|// conditional on __GNUC__.  :)
end_comment

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"signbit"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"__GNUC__"
name|)
end_pragma

begin_undef
undef|#
directive|undef
name|__GNUC__
end_undef

begin_define
define|#
directive|define
name|signbit
value|__ignored_cuda_signbit
end_define

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
literal|"__GNUC__"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"signbit"
name|)
end_pragma

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

begin_extern
extern|extern
literal|"C"
block|{
comment|// Device-side CUDA system calls.
comment|// http://docs.nvidia.com/cuda/ptx-writers-guide-to-interoperability/index.html#system-calls
comment|// We need these declarations and wrappers for device-side
comment|// malloc/free/printf calls to work without relying on
comment|// -fcuda-disable-target-call-checks option.
name|__device__
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|__device__
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(nothrow
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|__device__
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(nothrow
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|malloc
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|__device__
name|void
name|__assertfail
parameter_list|(
specifier|const
name|char
modifier|*
name|__message
parameter_list|,
specifier|const
name|char
modifier|*
name|__file
parameter_list|,
name|unsigned
name|__line
parameter_list|,
specifier|const
name|char
modifier|*
name|__function
parameter_list|,
name|size_t
name|__charSize
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// In order for standard assert() macro on linux to work we need to
end_comment

begin_comment
comment|// provide device-side __assert_fail()
end_comment

begin_function
name|__device__
specifier|static
specifier|inline
name|void
name|__assert_fail
parameter_list|(
specifier|const
name|char
modifier|*
name|__message
parameter_list|,
specifier|const
name|char
modifier|*
name|__file
parameter_list|,
name|unsigned
name|__line
parameter_list|,
specifier|const
name|char
modifier|*
name|__function
parameter_list|)
block|{
name|__assertfail
argument_list|(
name|__message
argument_list|,
name|__file
argument_list|,
name|__line
argument_list|,
name|__function
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Clang will convert printf into vprintf, but we still need
end_comment

begin_comment
comment|// device-side declaration for it.
end_comment

begin_function_decl
name|__device__
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// extern "C"
end_comment

begin_comment
comment|// We also need device-side std::malloc and std::free.
end_comment

begin_macro
unit|namespace
name|std
end_macro

begin_block
block|{
name|__device__
specifier|static
specifier|inline
name|void
name|free
parameter_list|(
name|void
modifier|*
name|__ptr
parameter_list|)
block|{
operator|::
name|free
argument_list|(
name|__ptr
argument_list|)
expr_stmt|;
block|}
name|__device__
specifier|static
specifier|inline
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
name|__size
parameter_list|)
block|{
return|return
operator|::
name|malloc
argument_list|(
name|__size
argument_list|)
return|;
block|}
block|}
end_block

begin_comment
comment|// namespace std
end_comment

begin_comment
comment|// Out-of-line implementations from __clang_cuda_builtin_vars.h.  These need to
end_comment

begin_comment
comment|// come after we've pulled in the definition of uint3 and dim3.
end_comment

begin_expr_stmt
name|__device__
specifier|inline
name|__cuda_builtin_threadIdx_t
operator|::
name|operator
name|uint3
argument_list|()
specifier|const
block|{
name|uint3
name|ret
block|;
name|ret
operator|.
name|x
operator|=
name|x
block|;
name|ret
operator|.
name|y
operator|=
name|y
block|;
name|ret
operator|.
name|z
operator|=
name|z
block|;
return|return
name|ret
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__device__
specifier|inline
name|__cuda_builtin_blockIdx_t
operator|::
name|operator
name|uint3
argument_list|()
specifier|const
block|{
name|uint3
name|ret
block|;
name|ret
operator|.
name|x
operator|=
name|x
block|;
name|ret
operator|.
name|y
operator|=
name|y
block|;
name|ret
operator|.
name|z
operator|=
name|z
block|;
return|return
name|ret
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__device__
specifier|inline
name|__cuda_builtin_blockDim_t
operator|::
name|operator
name|dim3
argument_list|()
specifier|const
block|{
return|return
name|dim3
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__device__
specifier|inline
name|__cuda_builtin_gridDim_t
operator|::
name|operator
name|dim3
argument_list|()
specifier|const
block|{
return|return
name|dim3
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|)
return|;
block|}
end_expr_stmt

begin_include
include|#
directive|include
file|<__clang_cuda_cmath.h>
end_include

begin_include
include|#
directive|include
file|<__clang_cuda_intrinsics.h>
end_include

begin_include
include|#
directive|include
file|<__clang_cuda_complex_builtins.h>
end_include

begin_comment
comment|// curand_mtgp32_kernel helpfully redeclares blockDim and threadIdx in host
end_comment

begin_comment
comment|// mode, giving them their "proper" types of dim3 and uint3.  This is
end_comment

begin_comment
comment|// incompatible with the types we give in __clang_cuda_builtin_vars.h.  As as
end_comment

begin_comment
comment|// hack, force-include the header (nvcc doesn't include it by default) but
end_comment

begin_comment
comment|// redefine dim3 and uint3 to our builtin types.  (Thankfully dim3 and uint3 are
end_comment

begin_comment
comment|// only used here for the redeclarations of blockDim and threadIdx.)
end_comment

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"dim3"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"uint3"
name|)
end_pragma

begin_define
define|#
directive|define
name|dim3
value|__cuda_builtin_blockDim_t
end_define

begin_define
define|#
directive|define
name|uint3
value|__cuda_builtin_threadIdx_t
end_define

begin_include
include|#
directive|include
file|"curand_mtgp32_kernel.h"
end_include

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"dim3"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"uint3"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"__USE_FAST_MATH__"
name|)
end_pragma

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

