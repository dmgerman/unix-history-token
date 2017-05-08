begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- lwpintrin.h - LWP intrinsics -------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86INTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<lwpintrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__LWPINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__LWPINTRIN_H
end_define

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("lwp")))
end_define

begin_comment
comment|/// \brief Parses the LWPCB at the specified address and enables
end_comment

begin_comment
comment|///        profiling if valid.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> LLWPCB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __addr
end_comment

begin_comment
comment|///    Address to the new Lightweight Profiling Control Block (LWPCB). If the
end_comment

begin_comment
comment|///    LWPCB is valid, writes the address into the LWP_CBADDR MSR and enables
end_comment

begin_comment
comment|///    Lightweight Profiling.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|__llwpcb
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|)
block|{
name|__builtin_ia32_llwpcb
argument_list|(
name|__addr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Flushes the LWP state to memory and returns the address of the LWPCB.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> SLWPCB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return
end_comment

begin_comment
comment|///    Address to the current Lightweight Profiling Control Block (LWPCB).
end_comment

begin_comment
comment|///    If LWP is not currently enabled, returns NULL.
end_comment

begin_function
specifier|static
name|__inline__
name|void
modifier|*
name|__DEFAULT_FN_ATTRS
name|__slwpcb
parameter_list|()
block|{
return|return
name|__builtin_ia32_slwpcb
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Inserts programmed event record into the LWP event ring buffer
end_comment

begin_comment
comment|///        and advances the ring buffer pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> LWPINS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DATA2
end_comment

begin_comment
comment|///    A 32-bit value is zero-extended and inserted into the 64-bit Data2 field.
end_comment

begin_comment
comment|/// \param DATA1
end_comment

begin_comment
comment|///    A 32-bit value is inserted into the 32-bit Data1 field.
end_comment

begin_comment
comment|/// \param FLAGS
end_comment

begin_comment
comment|///    A 32-bit immediate value is inserted into the 32-bit Flags field.
end_comment

begin_comment
comment|/// \returns If the ring buffer is full and LWP is running in Synchronized Mode,
end_comment

begin_comment
comment|///    the event record overwrites the last record in the buffer, the MissedEvents
end_comment

begin_comment
comment|///    counter in the LWPCB is incremented, the head pointer is not advanced, and
end_comment

begin_comment
comment|///    1 is returned. Otherwise 0 is returned.
end_comment

begin_define
define|#
directive|define
name|__lwpins32
parameter_list|(
name|DATA2
parameter_list|,
name|DATA1
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|(__builtin_ia32_lwpins32((unsigned int) (DATA2), (unsigned int) (DATA1), \                            (unsigned int) (FLAGS)))
end_define

begin_comment
comment|/// \brief Decrements the LWP programmed value sample event counter. If the result is
end_comment

begin_comment
comment|///        negative, inserts an event record into the LWP event ring buffer in memory
end_comment

begin_comment
comment|///        and advances the ring buffer pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> LWPVAL</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DATA2
end_comment

begin_comment
comment|///    A 32-bit value is zero-extended and inserted into the 64-bit Data2 field.
end_comment

begin_comment
comment|/// \param DATA1
end_comment

begin_comment
comment|///    A 32-bit value is inserted into the 32-bit Data1 field.
end_comment

begin_comment
comment|/// \param FLAGS
end_comment

begin_comment
comment|///    A 32-bit immediate value is inserted into the 32-bit Flags field.
end_comment

begin_define
define|#
directive|define
name|__lwpval32
parameter_list|(
name|DATA2
parameter_list|,
name|DATA1
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|(__builtin_ia32_lwpval32((unsigned int) (DATA2), (unsigned int) (DATA1), \                            (unsigned int) (FLAGS)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Inserts programmed event record into the LWP event ring buffer
end_comment

begin_comment
comment|///        and advances the ring buffer pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> LWPINS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DATA2
end_comment

begin_comment
comment|///    A 64-bit value is inserted into the 64-bit Data2 field.
end_comment

begin_comment
comment|/// \param DATA1
end_comment

begin_comment
comment|///    A 32-bit value is inserted into the 32-bit Data1 field.
end_comment

begin_comment
comment|/// \param FLAGS
end_comment

begin_comment
comment|///    A 32-bit immediate value is inserted into the 32-bit Flags field.
end_comment

begin_comment
comment|/// \returns If the ring buffer is full and LWP is running in Synchronized Mode,
end_comment

begin_comment
comment|///    the event record overwrites the last record in the buffer, the MissedEvents
end_comment

begin_comment
comment|///    counter in the LWPCB is incremented, the head pointer is not advanced, and
end_comment

begin_comment
comment|///    1 is returned. Otherwise 0 is returned.
end_comment

begin_define
define|#
directive|define
name|__lwpins64
parameter_list|(
name|DATA2
parameter_list|,
name|DATA1
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|(__builtin_ia32_lwpins64((unsigned long long) (DATA2), (unsigned int) (DATA1), \                            (unsigned int) (FLAGS)))
end_define

begin_comment
comment|/// \brief Decrements the LWP programmed value sample event counter. If the result is
end_comment

begin_comment
comment|///        negative, inserts an event record into the LWP event ring buffer in memory
end_comment

begin_comment
comment|///        and advances the ring buffer pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> LWPVAL</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DATA2
end_comment

begin_comment
comment|///    A 64-bit value is and inserted into the 64-bit Data2 field.
end_comment

begin_comment
comment|/// \param DATA1
end_comment

begin_comment
comment|///    A 32-bit value is inserted into the 32-bit Data1 field.
end_comment

begin_comment
comment|/// \param FLAGS
end_comment

begin_comment
comment|///    A 32-bit immediate value is inserted into the 32-bit Flags field.
end_comment

begin_define
define|#
directive|define
name|__lwpval64
parameter_list|(
name|DATA2
parameter_list|,
name|DATA1
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|(__builtin_ia32_lwpval64((unsigned long long) (DATA2), (unsigned int) (DATA1), \                            (unsigned int) (FLAGS)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LWPINTRIN_H */
end_comment

end_unit

