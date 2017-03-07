begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IA-32/x64 AsmRdRandxx()   Generates random number through CPU RdRand instruction.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Generates a 16-bit random number through RDRAND instruction.    if Rand is NULL, then ASSERT().    @param[out]  Rand     Buffer pointer to store the random result.    @retval TRUE          RDRAND call was successful.   @retval FALSE         Failed attempts to call RDRAND.   **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|AsmRdRand16
parameter_list|(
name|OUT
name|UINT16
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
return|return
name|InternalX86RdRand16
argument_list|(
name|Rand
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   Generates a 32-bit random number through RDRAND instruction.    if Rand is NULL, then ASSERT().    @param[out]  Rand     Buffer pointer to store the random result.    @retval TRUE          RDRAND call was successful.   @retval FALSE         Failed attempts to call RDRAND.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|AsmRdRand32
parameter_list|(
name|OUT
name|UINT32
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
return|return
name|InternalX86RdRand32
argument_list|(
name|Rand
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   Generates a 64-bit random number through RDRAND instruction.    if Rand is NULL, then ASSERT().    @param[out]  Rand     Buffer pointer to store the random result.    @retval TRUE          RDRAND call was successful.   @retval FALSE         Failed attempts to call RDRAND.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|AsmRdRand64
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
return|return
name|InternalX86RdRand64
argument_list|(
name|Rand
argument_list|)
return|;
block|}
end_function

end_unit

