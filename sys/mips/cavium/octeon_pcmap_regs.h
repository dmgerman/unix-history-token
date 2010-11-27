begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/*  *    This product includes software developed by the University of  *    California, Berkeley and its contributors."  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_PCMAP_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_PCMAP_REGS_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Utility inlines& macros  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|oct_write64
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(*(volatile uint64_t *)(a) = (uint64_t)(v))
end_define

begin_define
define|#
directive|define
name|oct_write8_x8
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(*(volatile uint8_t *)(a) = (uint8_t)(v))
end_define

begin_define
define|#
directive|define
name|OCT_READ
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|static inline t oct_read ## n(uintptr_t a)				\ {									\ 	volatile t *p = (volatile t *)a;				\ 	return (*p);							\ }
end_define

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|8
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|16
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|32
argument_list|,
name|uint32_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|64
argument_list|,
name|uint64_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_o32
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_function
specifier|static
specifier|inline
name|void
name|oct_write64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint64_t
name|val64
parameter_list|)
block|{
asm|__asm __volatile (
literal|".set push\n"
literal|".set mips64\n"
literal|"sd     %0, 0(%1)\n"
literal|".set pop\n"
operator|:
operator|:
literal|"r"
operator|(
name|val64
operator|)
operator|,
literal|"r"
operator|(
name|csr_addr
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
specifier|inline
name|void
name|oct_write8_x8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint8_t
name|val8
parameter_list|)
block|{
asm|__asm __volatile (
literal|".set push\n"
literal|".set mips64\n"
literal|"sb    %0, 0(%1)\n"
literal|".set pop\n"
operator|:
operator|:
literal|"r"
operator|(
name|val8
operator|)
operator|,
literal|"r"
operator|(
name|csr_addr
operator|)
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|OCT_READ
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|insn
parameter_list|)
define|\
value|static inline t oct_read ## n(uint64_t a)				\ {									\     uint64_t tmp;							\ 									\     __asm __volatile (							\ 	".set push\n"							\         ".set mips64\n"							\         insn "\t%0, 0(%1)\n"						\         ".set pop\n"							\         : "=r"(tmp)							\         : "r"(a));							\     return ((t)tmp);							\ }
end_define

begin_expr_stmt
unit|OCT_READ
operator|(
literal|8
operator|,
name|uint8_t
operator|,
literal|"lb"
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|16
argument_list|,
name|uint16_t
argument_list|,
literal|"lh"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|32
argument_list|,
name|uint32_t
argument_list|,
literal|"lw"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|64
argument_list|,
name|uint64_t
argument_list|,
literal|"ld"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * XXX  * Add o32 variants that load the address into a register and the result out  * of a register properly, and simply disable interrupts before and after and  * hope that we don't need to refill or modify the TLB to access the address.  * I'd be a lot happier if csr_addr were a physical address and we mapped it  * into XKPHYS here so that we could guarantee that interrupts were the only  * kind of exception we needed to worry about.  *  * Also, some of this inline assembly is needlessly verbose.  Oh, well.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|oct_write64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint64_t
name|val64
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|valh
init|=
name|val64
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|vall
init|=
name|val64
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|;
name|uint32_t
name|tmp2
decl_stmt|;
name|uint32_t
name|tmp3
decl_stmt|;
name|register_t
name|sr
decl_stmt|;
name|sr
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
asm|__asm __volatile (
literal|".set push\n"
literal|".set mips64\n"
literal|".set noreorder\n"
literal|".set noat\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsll   %1, %5, 32\n"
literal|"dsll   %2, %4, 32\n"
literal|"dsrl   %2, %2, 32\n"
literal|"or     %0, %0, %2\n"
literal|"dsll   %2, %6, 32\n"
literal|"dsrl   %2, %2, 32\n"
literal|"or     %1, %1, %2\n"
literal|"sd     %0, 0(%1)\n"
literal|".set pop\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp3
operator|)
operator|:
literal|"r"
operator|(
name|valh
operator|)
operator|,
literal|"r"
operator|(
name|vall
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_expr_stmt
name|intr_restore
argument_list|(
name|sr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
unit|}  static
specifier|inline
name|void
name|oct_write8_x8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint8_t
name|val8
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|;
name|uint32_t
name|tmp2
decl_stmt|;
name|register_t
name|sr
decl_stmt|;
name|sr
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
asm|__asm __volatile (
literal|".set push\n"
literal|".set mips64\n"
literal|".set noreorder\n"
literal|".set noat\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsll   %1, %4, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"sb     %2, 0(%0)\n"
literal|".set pop\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|val8
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_expr_stmt
name|intr_restore
argument_list|(
name|sr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
unit|}
define|#
directive|define
name|OCT_READ
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|insn
parameter_list|)
define|\
value|static inline t oct_read ## n(uint64_t csr_addr)			\ {									\ 	uint32_t csr_addrh = csr_addr>> 32;				\ 	uint32_t csr_addrl = csr_addr;					\ 	uint32_t tmp1, tmp2;						\ 	register_t sr;							\ 									\ 	sr = intr_disable();						\ 									\ 	__asm __volatile (						\ 	    ".set push\n"						\             ".set mips64\n"						\ 	    ".set noreorder\n"						\ 	    ".set noat\n"						\ 	    "dsll   %1, %2, 32\n"					\ 	    "dsll   %0, %3, 32\n"					\ 	    "dsrl   %0, %0, 32\n"					\ 	    "or     %1, %1, %0\n"					\ 	    "lb     %1, 0(%1)\n"					\ 	    ".set pop\n"						\ 	    : "=&r" (tmp1), "=&r" (tmp2)				\ 	    : "r" (csr_addrh), "r" (csr_addrl));			\ 									\ 	intr_restore(sr);						\ 									\ 	return ((t)tmp2);						\ }
end_define

begin_expr_stmt
unit|OCT_READ
operator|(
literal|8
operator|,
name|uint8_t
operator|,
literal|"lb"
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|16
argument_list|,
name|uint16_t
argument_list|,
literal|"lh"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OCT_READ
argument_list|(
literal|32
argument_list|,
name|uint32_t
argument_list|,
literal|"lw"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
specifier|inline
name|uint64_t
name|oct_read64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|valh
decl_stmt|;
name|uint32_t
name|vall
decl_stmt|;
name|register_t
name|sr
decl_stmt|;
name|sr
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
asm|__asm __volatile (
literal|".set push\n"
literal|".set mips64\n"
literal|".set noreorder\n"
literal|".set noat\n"
literal|"dsll   %0, %2, 32\n"
literal|"dsll   %1, %3, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"ld     %1, 0(%0)\n"
literal|"dsrl   %0, %1, 32\n"
literal|"dsll   %1, %1, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|".set pop\n"
operator|:
literal|"=&r"
operator|(
name|valh
operator|)
operator|,
literal|"=&r"
operator|(
name|vall
operator|)
operator|:
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_expr_stmt
name|intr_restore
argument_list|(
name|sr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
operator|(
name|uint64_t
operator|)
name|valh
operator|<<
literal|32
operator|)
operator||
name|vall
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|oct_write64_int64
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(oct_write64(a, (int64_t)(v)))
end_define

begin_comment
comment|/*  * Most write bus transactions are actually 64-bit on Octeon.  */
end_comment

begin_function
unit|static
specifier|inline
name|void
name|oct_write8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint8_t
name|val8
parameter_list|)
block|{
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val8
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|oct_write16
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint16_t
name|val16
parameter_list|)
block|{
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val16
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|oct_write32
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint32_t
name|val32
parameter_list|)
block|{
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val32
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|oct_readint32
parameter_list|(
name|a
parameter_list|)
value|((int32_t)oct_read32((a)))
end_define

begin_comment
comment|/*  * octeon_machdep.c  *  * Direct to Board Support level.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_char
parameter_list|(
name|int
name|char_position
parameter_list|,
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_hexchar
parameter_list|(
name|int
name|char_position
parameter_list|,
name|char
name|hexval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_hex
parameter_list|(
name|uint32_t
name|wl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_string
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_char0
parameter_list|(
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_run_wheel
parameter_list|(
name|int
modifier|*
name|pos
parameter_list|,
name|int
name|led_position
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_debug_symbol
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_ciu_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|octeon_is_simulation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/*  * EBT3000 LED Unit  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_CHAR_LED_BASE_ADDR
value|(0x1d020000 | (0x1ffffffffull<< 31))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !OCTEON_PCMAP_REGS_H__ */
end_comment

end_unit

