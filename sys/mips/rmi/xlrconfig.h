begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XLRCONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|XLRCONFIG_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<mips/rmi/shared_structs.h>
end_include

begin_include
include|#
directive|include
file|<mips/rmi/shared_structs_func.h>
end_include

begin_define
define|#
directive|define
name|read_c0_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({ unsigned int __rv;                                           \         __asm__ __volatile__(                                   \         ".set\tpush\n\t"                                        \         ".set mips32\n\t"                                       \         "mfc0\t%0,$%1,%2\n\t"                                   \         ".set\tpop"                                             \         : "=r" (__rv) : "i" (reg), "i" (sel) );                 \         __rv;})
end_define

begin_define
define|#
directive|define
name|write_c0_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|__asm__ __volatile__(                                   \         ".set\tpush\n\t"                                        \         ".set mips32\n\t"                                       \         "mtc0\t%0,$%1,%2\n\t"                                   \         ".set\tpop"                                             \         : : "r" (value), "i" (reg), "i" (sel) );
end_define

begin_define
define|#
directive|define
name|read_c0_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({ unsigned int __high, __low;                               \         __asm__ __volatile__(                                   \         ".set\tpush\n\t"                                        \         ".set mips64\n\t"                                       \         "dmfc0\t $8, $%2, %3\n\t"                               \         "dsrl32\t%0, $8, 0\n\t"                                 \         "dsll32\t$8, $8, 0\n\t"                                 \         "dsrl32\t%1, $8, 0\n\t"                                 \         ".set\tpop"                                             \         : "=r"(__high), "=r"(__low): "i"(reg), "i"(sel): "$8" );\         (((unsigned long long)__high<< 32) | __low);})
end_define

begin_define
define|#
directive|define
name|write_c0_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|do{                                                            \        unsigned int __high = val>>32;                           \        unsigned int __low = val& 0xffffffff;                   \         __asm__ __volatile__(                                   \         ".set\tpush\n\t"                                        \         ".set mips64\n\t"                                       \         "dsll32\t$8, %1, 0\n\t"                                 \         "dsll32\t$9, %0, 0\n\t"                                 \         "or\t    $8, $8, $9\n\t"                                \         "dmtc0\t $8, $%2, %3\n\t"                               \         ".set\tpop"                                             \         :: "r"(high), "r"(low),  "i"(reg), "i"(sel):"$8", "$9");\    } while(0)
end_define

begin_define
define|#
directive|define
name|read_c2_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({ unsigned int __rv;                                           \         __asm__ __volatile__(                                   \         ".set\tpush\n\t"                                        \         ".set mips32\n\t"                                       \         "mfc2\t%0,$%1,%2\n\t"                                   \         ".set\tpop"                                             \         : "=r" (__rv) : "i" (reg), "i" (sel) );                 \         __rv;})
end_define

begin_define
define|#
directive|define
name|write_c2_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|__asm__ __volatile__(                                   \         ".set\tpush\n\t"                                        \         ".set mips32\n\t"                                       \         "mtc2\t%0,$%1,%2\n\t"                                   \         ".set\tpop"                                             \         : : "r" (value), "i" (reg), "i" (sel) );
end_define

begin_define
define|#
directive|define
name|read_c2_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({ unsigned int __high, __low;                               \         __asm__ __volatile__(                                   \         ".set mips64\n\t"                                       \         "dmfc2\t $8, $%2, %3\n\t"                               \         "dsrl32\t%0, $8, 0\n\t"                                 \         "dsll32\t$8, $8, 0\n\t"                                 \         "dsrl32\t%1, $8, 0\n\t"                                 \         ".set\tmips0"                                           \         : "=r"(__high), "=r"(__low): "i"(reg), "i"(sel): "$8" );\         (((unsigned long long)__high<< 32) | __low);})
end_define

begin_define
define|#
directive|define
name|write_c2_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|do{                                                            \        unsigned int __high = value>>32;                         \        unsigned int __low = value& 0xffffffff;                 \         __asm__ __volatile__(                                   \         ".set mips64\n\t"                                       \         "dsll32\t$8, %1, 0\n\t"                                 \         "dsll32\t$9, %0, 0\n\t"                                 \         "dsrl32\t$8, $8, 0\n\t"                                 \         "or\t    $8, $8, $9\n\t"                                \         "dmtc2\t $8, $%2, %3\n\t"                               \         ".set\tmips0"                                           \         :: "r"(__high), "r"(__low),                             \            "i"(reg), "i"(sel)                                   \         :"$8", "$9");                                           \    } while(0)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|xlr_processor_id
parameter_list|()
define|\
value|({int __id;                                                     \  __asm__ __volatile__ (                                         \            ".set push\n"                                        \            ".set noreorder\n"                                   \            ".word 0x40088007\n"                                 \            "srl  $8, $8, 10\n"                                  \            "andi %0, $8, 0x3f\n"                                \            ".set pop\n"                                         \            : "=r" (__id) : : "$8");                             \  __id;})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|xlr_cpu_id
parameter_list|()
define|\
value|({int __id;                                                     \  __asm__ __volatile__ (                                         \            ".set push\n"                                        \            ".set noreorder\n"                                   \            ".word 0x40088007\n"                                 \            "srl  $8, $8, 4\n"                                   \            "andi %0, $8, 0x7\n"                                \            ".set pop\n"                                         \            : "=r" (__id) : : "$8");                             \  __id;})
end_define

begin_define
define|#
directive|define
name|xlr_thr_id
parameter_list|()
define|\
value|({int __id;                                                     \  __asm__ __volatile__ (                                         \            ".set push\n"                                        \            ".set noreorder\n"                                   \            ".word 0x40088007\n"                                 \            "andi %0, $8, 0x03\n"                                \            ".set pop\n"                                         \            : "=r" (__id) : : "$8");                             \  __id;})
end_define

begin_comment
comment|/* Additional registers on the XLR */
end_comment

begin_define
define|#
directive|define
name|MIPS_COP_0_OSSCRATCH
value|22
end_define

begin_define
define|#
directive|define
name|XLR_CACHELINE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|XLR_MAX_CORES
value|8
end_define

begin_comment
comment|/* functions to write to and read from the extended  * cp0 registers.  * EIRR : Extended Interrupt Request Register  *        cp0 register 9 sel 6  *        bits 0...7 are same as cause register 8...15  * EIMR : Extended Interrupt Mask Register  *        cp0 register 9 sel 7  *        bits 0...7 are same as status register 8...15  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|read_c0_eirr64
parameter_list|(
name|void
parameter_list|)
block|{
name|__uint32_t
name|high
decl_stmt|,
name|low
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	            ".set push\n" 	            ".set noreorder\n" 	            ".set noat\n" 	            ".set mips4\n"  	            ".word 0x40214806  \n\t" 	            "nop               \n\t" 	            "dsra32 %0, $1, 0  \n\t" 	            "sll    %1, $1, 0  \n\t"  	            ".set pop\n"  	    :       "=r"(high), "=r"(low) 	);
return|return
operator|(
operator|(
operator|(
name|__uint64_t
operator|)
name|high
operator|)
operator|<<
literal|32
operator|)
operator||
name|low
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__uint64_t
name|read_c0_eimr64
parameter_list|(
name|void
parameter_list|)
block|{
name|__uint32_t
name|high
decl_stmt|,
name|low
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	            ".set push\n" 	            ".set noreorder\n" 	            ".set noat\n" 	            ".set mips4\n"  	            ".word 0x40214807  \n\t" 	            "nop               \n\t" 	            "dsra32 %0, $1, 0  \n\t" 	            "sll    %1, $1, 0  \n\t"  	            ".set pop\n"  	    :       "=r"(high), "=r"(low) 	);
return|return
operator|(
operator|(
operator|(
name|__uint64_t
operator|)
name|high
operator|)
operator|<<
literal|32
operator|)
operator||
name|low
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|write_c0_eirr64
parameter_list|(
name|__uint64_t
name|value
parameter_list|)
block|{
name|__uint32_t
name|low
decl_stmt|,
name|high
decl_stmt|;
name|high
operator|=
name|value
operator|>>
literal|32
expr_stmt|;
name|low
operator|=
name|value
operator|&
literal|0xffffffff
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	            ".set push\n" 	            ".set noreorder\n" 	            ".set noat\n" 	            ".set mips4\n\t"  	            "dsll32 $2, %1, 0  \n\t" 	            "dsll32 $1, %0, 0  \n\t" 	            "dsrl32 $2, $2, 0  \n\t" 	            "or     $1, $1, $2 \n\t" 	            ".word  0x40a14806 \n\t" 	            "nop               \n\t"  	            ".set pop\n"  	    : 	    :       "r"(high), "r"(low) 	    :       "$1", "$2");
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|write_c0_eimr64
parameter_list|(
name|__uint64_t
name|value
parameter_list|)
block|{
name|__uint32_t
name|low
decl_stmt|,
name|high
decl_stmt|;
name|high
operator|=
name|value
operator|>>
literal|32
expr_stmt|;
name|low
operator|=
name|value
operator|&
literal|0xffffffff
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	            ".set push\n" 	            ".set noreorder\n" 	            ".set noat\n" 	            ".set mips4\n\t"  	            "dsll32 $2, %1, 0  \n\t" 	            "dsll32 $1, %0, 0  \n\t" 	            "dsrl32 $2, $2, 0  \n\t" 	            "or     $1, $1, $2 \n\t" 	            ".word  0x40a14807 \n\t" 	            "nop               \n\t"  	            ".set pop\n"  	    : 	    :       "r"(high), "r"(low) 	    :       "$1", "$2");
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_test_and_set
parameter_list|(
name|int
modifier|*
name|lock
parameter_list|)
block|{
name|int
name|oldval
init|=
literal|0
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(".set push\n" 	            ".set noreorder\n" 	            "move $9, %2\n" 	            "li $8, 1\n"
comment|//      "swapw $8, $9\n"
asm|".word 0x71280014\n" 	            "move %1, $8\n" 	            ".set pop\n" 	    :       "+m"(*lock), "=r"(oldval) 	    :       "r"((unsigned long)lock) 	    :       "$8", "$9" 	);
return|return
operator|(
name|oldval
operator|==
literal|0
condition|?
literal|1
comment|/* success */
else|:
literal|0
comment|/* failure */
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint32_t
name|xlr_mfcr
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	            "move   $8, %1\n" 	            ".word  0x71090018\n" 	            "move   %0, $9\n" 	    :       "=r"(val) 	    :       "r"(reg):"$8", "$9");
return|return
name|val
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|xlr_mtcr
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 	            "move   $8, %1\n" 	            "move   $9, %0\n" 	            ".word  0x71090019\n" 	    ::      "r"(val), "r"(reg) 	    :       "$8", "$9");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

