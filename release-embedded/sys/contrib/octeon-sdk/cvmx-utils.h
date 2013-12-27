begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  * Small utility functions and macros to ease programming of Octeon.  *  *<hr>$Revision: 38306 $<hr> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_UTILS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_UTILS_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifndef|#
directive|ifndef
name|TRUE
define|#
directive|define
name|FALSE
value|0
define|#
directive|define
name|TRUE
value|(!(FALSE))
endif|#
directive|endif
comment|/*  * The macros cvmx_likely and cvmx_unlikely use the  * __builtin_expect GCC operation to control branch  * probabilities for a conditional. For example, an "if"  * statement in the code that will almost always be  * executed should be written as "if (cvmx_likely(...))".  * If the "else" section of an if statement is more  * probable, use "if (cvmx_unlikey(...))".  */
define|#
directive|define
name|cvmx_likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
define|#
directive|define
name|cvmx_unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
if|#
directive|if
name|CVMX_ENABLE_DEBUG_PRINTS
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
define|#
directive|define
name|cvmx_dprintf
value|printk
define|#
directive|define
name|cvmx_dvprintf
value|vprintk
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_FREEBSD_KERNEL
argument_list|)
name|void
name|cvmx_dvprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
name|void
name|cvmx_dprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cvmx_dprintf
value|printf
end_define

begin_define
define|#
directive|define
name|cvmx_dvprintf
value|vprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|void
name|cvmx_dvprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
block|{
comment|/* Prints are disbled, do nothing */
block|}
end_function

begin_function_decl
specifier|static
specifier|inline
name|void
name|cvmx_dprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
specifier|inline
name|void
name|cvmx_dprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|/* Prints are disbled, do nothing */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CAST64
parameter_list|(
name|v
parameter_list|)
value|((long long)(long)(v))
end_define

begin_comment
comment|// use only when 'v' is a pointer
end_comment

begin_define
define|#
directive|define
name|CASTPTR
parameter_list|(
name|type
parameter_list|,
name|v
parameter_list|)
value|((type *)(long)(v))
end_define

begin_define
define|#
directive|define
name|CVMX_CACHE_LINE_SIZE
value|(128)
end_define

begin_comment
comment|// In bytes
end_comment

begin_define
define|#
directive|define
name|CVMX_CACHE_LINE_MASK
value|(CVMX_CACHE_LINE_SIZE - 1)
end_define

begin_comment
comment|// In bytes
end_comment

begin_define
define|#
directive|define
name|CVMX_CACHE_LINE_ALIGNED
value|__attribute__ ((aligned (CVMX_CACHE_LINE_SIZE)))
end_define

begin_comment
comment|/**  * This macro spins on a field waiting for it to reach a value. It  * is common in code to need to wait for a specific field in a CSR  * to match a specific value. Conceptually this macro expands to:  *  * 1) read csr at "address" with a csr typedef of "type"  * 2) Check if ("type".s."field" "op" "value")  * 3) If #2 isn't true loop to #1 unless too much time has passed.  */
end_comment

begin_define
define|#
directive|define
name|CVMX_WAIT_FOR_FIELD64
parameter_list|(
name|address
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|op
parameter_list|,
name|value
parameter_list|,
name|timeout_usec
parameter_list|)
define|\
value|({int result;                                                       \     do {                                                                \         uint64_t done = cvmx_clock_get_count(CVMX_CLOCK_CORE) + (uint64_t)timeout_usec * \                         cvmx_clock_get_rate(CVMX_CLOCK_CORE) / 1000000; \         type c;                                                         \         while (1)                                                       \         {                                                               \             c.u64 = cvmx_read_csr(address);                             \             if ((c.s.field) op (value)) {                               \                 result = 0;                                             \                 break;                                                  \             } else if (cvmx_clock_get_count(CVMX_CLOCK_CORE)> done) {  \                 result = -1;                                            \                 break;                                                  \             } else                                                      \                 cvmx_wait(100);                                         \         }                                                               \     } while (0);                                                        \     result;})
end_define

begin_define
define|#
directive|define
name|CVMX_BUILD_ASSERT_ZERO
parameter_list|(
name|e
parameter_list|)
value|(sizeof(struct {int __static_assert:(e)?1:-1;}))
end_define

begin_define
define|#
directive|define
name|CVMX_BUILD_ASSERT
parameter_list|(
name|condition
parameter_list|)
value|((void)CVMX_BUILD_ASSERT_ZERO(condition))
end_define

begin_comment
comment|/**  * Builds a bit mask given the required size in bits.  *  * @param bits   Number of bits in the mask  * @return The mask  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|cvmx_build_mask
parameter_list|(
name|uint64_t
name|bits
parameter_list|)
block|{
return|return
operator|~
operator|(
operator|(
operator|~
literal|0x0ull
operator|)
operator|<<
name|bits
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Builds a memory address for I/O based on the Major and Sub DID.  *  * @param major_did 5 bit major did  * @param sub_did   3 bit sub did  * @return I/O base address  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|cvmx_build_io_address
parameter_list|(
name|uint64_t
name|major_did
parameter_list|,
name|uint64_t
name|sub_did
parameter_list|)
block|{
return|return
operator|(
operator|(
literal|0x1ull
operator|<<
literal|48
operator|)
operator||
operator|(
name|major_did
operator|<<
literal|43
operator|)
operator||
operator|(
name|sub_did
operator|<<
literal|40
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Perform mask and shift to place the supplied value into  * the supplied bit rage.  *  * Example: cvmx_build_bits(39,24,value)  *<pre>  * 6       5       4       3       3       2       1  * 3       5       7       9       1       3       5       7      0  * +-------+-------+-------+-------+-------+-------+-------+------+  * 000000000000000000000000___________value000000000000000000000000  *</pre>  *  * @param high_bit Highest bit value can occupy (inclusive) 0-63  * @param low_bit  Lowest bit value can occupy inclusive 0-high_bit  * @param value    Value to use  * @return Value masked and shifted  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|cvmx_build_bits
parameter_list|(
name|uint64_t
name|high_bit
parameter_list|,
name|uint64_t
name|low_bit
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
return|return
operator|(
operator|(
name|value
operator|&
name|cvmx_build_mask
argument_list|(
name|high_bit
operator|-
name|low_bit
operator|+
literal|1
argument_list|)
operator|)
operator|<<
name|low_bit
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the number of cores available in the chip  *  * @return  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|cvmx_octeon_num_cores
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|ciu_fuse
init|=
operator|(
name|uint32_t
operator|)
name|cvmx_read_csr
argument_list|(
name|CVMX_CIU_FUSE
argument_list|)
operator|&
literal|0xffffffffull
decl_stmt|;
return|return
name|cvmx_pop
argument_list|(
name|ciu_fuse
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return true if Octeon is CN36XX  *  * @return  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|cvmx_octeon_model_CN36XX
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN38XX
argument_list|)
operator|&&
name|cvmx_fuse_read
argument_list|(
literal|264
argument_list|)
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_UTILS_H__ */
end_comment

end_unit

