begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Random number generator services that uses RdRand instruction access   to provide high-quality random numbers.  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit mask used to determine if RdRand instruction is supported.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|RDRAND_MASK
value|BIT30
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Limited retry number when valid random data is returned.
end_comment

begin_comment
comment|// Uses the recommended value defined in Section 7.3.17 of "Intel 64 and IA-32
end_comment

begin_comment
comment|// Architectures Software Developer's Mannual".
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|RDRAND_RETRY_LIMIT
value|10
end_define

begin_comment
comment|/**   The constructor function checks whether or not RDRAND instruction is supported   by the host hardware.    The constructor function checks whether or not RDRAND instruction is supported.   It will ASSERT() if RDRAND instruction is not supported.   It will always return RETURN_SUCCESS.    @retval RETURN_SUCCESS   The constructor always returns EFI_SUCCESS.  **/
end_comment

begin_function
name|RETURN_STATUS
name|EFIAPI
name|BaseRngLibConstructor
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT32
name|RegEcx
decl_stmt|;
comment|//
comment|// Determine RDRAND support by examining bit 30 of the ECX register returned by
comment|// CPUID. A value of 1 indicates that processor support RDRAND instruction.
comment|//
name|AsmCpuid
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|RegEcx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|(
name|RegEcx
operator|&
name|RDRAND_MASK
operator|)
operator|==
name|RDRAND_MASK
argument_list|)
expr_stmt|;
return|return
name|RETURN_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**   Generates a 16-bit random number.    if Rand is NULL, then ASSERT().    @param[out] Rand     Buffer pointer to store the 16-bit random value.    @retval TRUE         Random number generated successfully.   @retval FALSE        Failed to generate the random number.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|GetRandomNumber16
parameter_list|(
name|OUT
name|UINT16
modifier|*
name|Rand
parameter_list|)
block|{
name|UINT32
name|Index
decl_stmt|;
name|ASSERT
argument_list|(
name|Rand
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//
comment|// A loop to fetch a 16 bit random value with a retry count limit.
comment|//
for|for
control|(
name|Index
operator|=
literal|0
init|;
name|Index
operator|<
name|RDRAND_RETRY_LIMIT
condition|;
name|Index
operator|++
control|)
block|{
if|if
condition|(
name|AsmRdRand16
argument_list|(
name|Rand
argument_list|)
condition|)
block|{
return|return
name|TRUE
return|;
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**   Generates a 32-bit random number.    if Rand is NULL, then ASSERT().    @param[out] Rand     Buffer pointer to store the 32-bit random value.    @retval TRUE         Random number generated successfully.   @retval FALSE        Failed to generate the random number.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|GetRandomNumber32
parameter_list|(
name|OUT
name|UINT32
modifier|*
name|Rand
parameter_list|)
block|{
name|UINT32
name|Index
decl_stmt|;
name|ASSERT
argument_list|(
name|Rand
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//
comment|// A loop to fetch a 32 bit random value with a retry count limit.
comment|//
for|for
control|(
name|Index
operator|=
literal|0
init|;
name|Index
operator|<
name|RDRAND_RETRY_LIMIT
condition|;
name|Index
operator|++
control|)
block|{
if|if
condition|(
name|AsmRdRand32
argument_list|(
name|Rand
argument_list|)
condition|)
block|{
return|return
name|TRUE
return|;
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**   Generates a 64-bit random number.    if Rand is NULL, then ASSERT().    @param[out] Rand     Buffer pointer to store the 64-bit random value.    @retval TRUE         Random number generated successfully.   @retval FALSE        Failed to generate the random number.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|GetRandomNumber64
parameter_list|(
name|OUT
name|UINT64
modifier|*
name|Rand
parameter_list|)
block|{
name|UINT32
name|Index
decl_stmt|;
name|ASSERT
argument_list|(
name|Rand
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//
comment|// A loop to fetch a 64 bit random value with a retry count limit.
comment|//
for|for
control|(
name|Index
operator|=
literal|0
init|;
name|Index
operator|<
name|RDRAND_RETRY_LIMIT
condition|;
name|Index
operator|++
control|)
block|{
if|if
condition|(
name|AsmRdRand64
argument_list|(
name|Rand
argument_list|)
condition|)
block|{
return|return
name|TRUE
return|;
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**   Generates a 128-bit random number.    if Rand is NULL, then ASSERT().    @param[out] Rand     Buffer pointer to store the 128-bit random value.    @retval TRUE         Random number generated successfully.   @retval FALSE        Failed to generate the random number.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|GetRandomNumber128
parameter_list|(
name|OUT
name|UINT64
modifier|*
name|Rand
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|Rand
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//
comment|// Read first 64 bits
comment|//
if|if
condition|(
operator|!
name|GetRandomNumber64
argument_list|(
name|Rand
argument_list|)
condition|)
block|{
return|return
name|FALSE
return|;
block|}
comment|//
comment|// Read second 64 bits
comment|//
return|return
name|GetRandomNumber64
argument_list|(
operator|++
name|Rand
argument_list|)
return|;
block|}
end_function

end_unit

