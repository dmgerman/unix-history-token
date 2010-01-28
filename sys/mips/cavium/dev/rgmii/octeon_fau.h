begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*------------------------------------------------------------------  * octeon_fau.h        Fetch& Add Unit  *  *------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|___OCTEON_FAU__H___
end_ifndef

begin_define
define|#
directive|define
name|___OCTEON_FAU__H___
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|OCTEON_FAU_OP_SIZE_8
init|=
literal|0
block|,
name|OCTEON_FAU_OP_SIZE_16
init|=
literal|1
block|,
name|OCTEON_FAU_OP_SIZE_32
init|=
literal|2
block|,
name|OCTEON_FAU_OP_SIZE_64
init|=
literal|3
block|}
name|octeon_fau_op_size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OCTEON_FAU_LOAD_IO_ADDRESS
value|octeon_build_io_address(0x1e, 0)
end_define

begin_define
define|#
directive|define
name|OCTEON_FAU_BITS_SCRADDR
value|63,56
end_define

begin_define
define|#
directive|define
name|OCTEON_FAU_BITS_LEN
value|55,48
end_define

begin_define
define|#
directive|define
name|OCTEON_FAU_BITS_INEVAL
value|35,14
end_define

begin_define
define|#
directive|define
name|OCTEON_FAU_BITS_TAGWAIT
value|13,13
end_define

begin_define
define|#
directive|define
name|OCTEON_FAU_BITS_NOADD
value|13,13
end_define

begin_define
define|#
directive|define
name|OCTEON_FAU_BITS_SIZE
value|12,11
end_define

begin_define
define|#
directive|define
name|OCTEON_FAU_BITS_REGISTER
value|10,0
end_define

begin_define
define|#
directive|define
name|OCTEON_FAU_REG_64_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x<<3) + OCTEON_FAU_REG_64_START)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|OCTEON_FAU_REG_64_START
init|=
literal|0
block|,
name|OCTEON_FAU_REG_OQ_ADDR_INDEX
init|=
name|OCTEON_FAU_REG_64_ADDR
argument_list|(
literal|0
argument_list|)
block|,
name|OCTEON_FAU_REG_OQ_ADDR_END
init|=
name|OCTEON_FAU_REG_64_ADDR
argument_list|(
literal|31
argument_list|)
block|,
name|OCTEON_FAU_REG_64_END
init|=
name|OCTEON_FAU_REG_64_ADDR
argument_list|(
literal|39
argument_list|)
block|, }
name|octeon_fau_reg_64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OCTEON_FAU_REG_32_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x<<2) + OCTEON_FAU_REG_32_START)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|OCTEON_FAU_REG_32_START
init|=
name|OCTEON_FAU_REG_64_END
block|,
name|OCTEON_FAU_REG_32_END
init|=
name|OCTEON_FAU_REG_32_ADDR
argument_list|(
literal|0
argument_list|)
block|, }
name|octeon_fau_reg_32_t
typedef|;
end_typedef

begin_comment
comment|/*  * octeon_fau_atomic_address  *  * Builds a I/O address for accessing the FAU  *  * @param tagwait Should the atomic add wait for the current tag switch  *                operation to complete.  *                - 0 = Don't wait  *                - 1 = Wait for tag switch to complete  * @param reg     FAU atomic register to access. 0<= reg< 4096.  *                - Step by 2 for 16 bit access.  *                - Step by 4 for 32 bit access.  *                - Step by 8 for 64 bit access.  * @param value   Signed value to add.  *                Note: When performing 32 and 64 bit access, only the low  *                22 bits are available.  * @return Address to read from for atomic update  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|octeon_fau_atomic_address
parameter_list|(
name|uint64_t
name|tagwait
parameter_list|,
name|uint64_t
name|reg
parameter_list|,
name|int64_t
name|value
parameter_list|)
block|{
return|return
operator|(
name|OCTEON_ADD_IO_SEG
argument_list|(
name|OCTEON_FAU_LOAD_IO_ADDRESS
argument_list|)
operator||
name|octeon_build_bits
argument_list|(
name|OCTEON_FAU_BITS_INEVAL
argument_list|,
name|value
argument_list|)
operator||
name|octeon_build_bits
argument_list|(
name|OCTEON_FAU_BITS_TAGWAIT
argument_list|,
name|tagwait
argument_list|)
operator||
name|octeon_build_bits
argument_list|(
name|OCTEON_FAU_BITS_REGISTER
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * octeon_fau_store_address  *  * Builds a store I/O address for writing to the FAU  *  * noadd  0 = Store value is atomically added to the current value  *               1 = Store value is atomically written over the current value  * reg    FAU atomic register to access. 0<= reg< 4096.  *               - Step by 2 for 16 bit access.  *               - Step by 4 for 32 bit access.  *               - Step by 8 for 64 bit access.  * Returns Address to store for atomic update  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|octeon_fau_store_address
parameter_list|(
name|uint64_t
name|noadd
parameter_list|,
name|uint64_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|OCTEON_ADD_IO_SEG
argument_list|(
name|OCTEON_FAU_LOAD_IO_ADDRESS
argument_list|)
operator||
name|octeon_build_bits
argument_list|(
name|OCTEON_FAU_BITS_NOADD
argument_list|,
name|noadd
argument_list|)
operator||
name|octeon_build_bits
argument_list|(
name|OCTEON_FAU_BITS_REGISTER
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * octeon_fau_atomic_add32  *  * Perform an atomic 32 bit add  *  * @param reg     FAU atomic register to access. 0<= reg< 4096.  *                - Step by 4 for 32 bit access.  * @param value   Signed value to add.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_fau_atomic_add32
parameter_list|(
name|octeon_fau_reg_32_t
name|reg
parameter_list|,
name|int32_t
name|value
parameter_list|)
block|{
name|oct_write32
argument_list|(
name|octeon_fau_store_address
argument_list|(
literal|0
argument_list|,
name|reg
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * octeon_fau_fetch_and_add  *  * reg     FAU atomic register to access. 0<= reg< 4096.  *                - Step by 8 for 64 bit access.  * value   Signed value to add.  *                Note: Only the low 22 bits are available.  * returns Value of the register before the update  */
end_comment

begin_function
specifier|static
specifier|inline
name|int64_t
name|octeon_fau_fetch_and_add64
parameter_list|(
name|octeon_fau_reg_64_t
name|reg
parameter_list|,
name|int64_t
name|val64
parameter_list|)
block|{
return|return
operator|(
name|oct_read64
argument_list|(
name|octeon_fau_atomic_address
argument_list|(
literal|0
argument_list|,
name|reg
argument_list|,
name|val64
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * octeon_fau_fetch_and_add32  *  * reg     FAU atomic register to access. 0<= reg< 4096.  *                - Step by 8 for 64 bit access.  * value   Signed value to add.  *                Note: Only the low 22 bits are available.  * returns Value of the register before the update  */
end_comment

begin_function
specifier|static
specifier|inline
name|int32_t
name|octeon_fau_fetch_and_add32
parameter_list|(
name|octeon_fau_reg_64_t
name|reg
parameter_list|,
name|int32_t
name|val32
parameter_list|)
block|{
return|return
operator|(
name|oct_read32
argument_list|(
name|octeon_fau_atomic_address
argument_list|(
literal|0
argument_list|,
name|reg
argument_list|,
name|val32
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * octeon_fau_atomic_write32  *  * Perform an atomic 32 bit write  *  * @param reg     FAU atomic register to access. 0<= reg< 4096.  *                - Step by 4 for 32 bit access.  * @param value   Signed value to write.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_fau_atomic_write32
parameter_list|(
name|octeon_fau_reg_32_t
name|reg
parameter_list|,
name|int32_t
name|value
parameter_list|)
block|{
name|oct_write32
argument_list|(
name|octeon_fau_store_address
argument_list|(
literal|1
argument_list|,
name|reg
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * octeon_fau_atomic_write64  *  * Perform an atomic 32 bit write  *  * reg    FAU atomic register to access. 0<= reg< 4096.  *                - Step by 8 for 64 bit access.  * value   Signed value to write.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_fau_atomic_write64
parameter_list|(
name|octeon_fau_reg_64_t
name|reg
parameter_list|,
name|int64_t
name|value
parameter_list|)
block|{
name|oct_write64
argument_list|(
name|octeon_fau_store_address
argument_list|(
literal|1
argument_list|,
name|reg
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|octeon_fau_atomic_add64
parameter_list|(
name|octeon_fau_reg_64_t
name|reg
parameter_list|,
name|int64_t
name|value
parameter_list|)
block|{
name|oct_write64_int64
argument_list|(
name|octeon_fau_store_address
argument_list|(
literal|0
argument_list|,
name|reg
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|octeon_fau_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_fau_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_fau_disable
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
comment|/* ___OCTEON_FAU__H___ */
end_comment

end_unit

