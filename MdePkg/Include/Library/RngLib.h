begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides random number generator services.  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RNG_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__RNG_LIB_H__
end_define

begin_comment
comment|/**   Generates a 16-bit random number.    if Rand is NULL, then ASSERT().    @param[out] Rand     Buffer pointer to store the 16-bit random value.    @retval TRUE         Random number generated successfully.   @retval FALSE        Failed to generate the random number.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|GetRandomNumber16
parameter_list|(
name|OUT
name|UINT16
modifier|*
name|Rand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Generates a 32-bit random number.    if Rand is NULL, then ASSERT().    @param[out] Rand     Buffer pointer to store the 32-bit random value.    @retval TRUE         Random number generated successfully.   @retval FALSE        Failed to generate the random number.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|GetRandomNumber32
parameter_list|(
name|OUT
name|UINT32
modifier|*
name|Rand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Generates a 64-bit random number.    if Rand is NULL, then ASSERT().    @param[out] Rand     Buffer pointer to store the 64-bit random value.    @retval TRUE         Random number generated successfully.   @retval FALSE        Failed to generate the random number.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|GetRandomNumber64
parameter_list|(
name|OUT
name|UINT64
modifier|*
name|Rand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Generates a 128-bit random number.    if Rand is NULL, then ASSERT().    @param[out] Rand     Buffer pointer to store the 128-bit random value.    @retval TRUE         Random number generated successfully.   @retval FALSE        Failed to generate the random number.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|GetRandomNumber128
parameter_list|(
name|OUT
name|UINT64
modifier|*
name|Rand
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __RNG_LIB_H__
end_comment

end_unit

