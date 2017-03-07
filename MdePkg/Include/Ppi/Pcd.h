begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Native Platform Configuration Database (PCD) PPI      Different with the EFI_PCD_PPI defined in PI 1.2 specification, the native   PCD PPI provide interfaces for dynamic and dynamic-ex type PCD.    The interfaces for dynamic type PCD do not require the token space guid as parameter,   but interfaces for dynamic-ex type PCD require token space guid as parameter.  Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCD_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCD_PPI_H__
end_define

begin_define
define|#
directive|define
name|PCD_PPI_GUID
define|\
value|{ 0x6e81c58, 0x4ad7, 0x44bc, { 0x83, 0x90, 0xf1, 0x2, 0x65, 0xf7, 0x24, 0x80 } }
end_define

begin_define
define|#
directive|define
name|PCD_INVALID_TOKEN_NUMBER
value|((UINTN) 0)
end_define

begin_comment
comment|/**   Sets the SKU value for subsequent calls to set or get PCD token values.    SetSku() sets the SKU Id to be used for subsequent calls to set or get PCD values.    SetSku() is normally called only once by the system.    For each item (token), the database can hold a single value that applies to all SKUs,    or multiple values, where each value is associated with a specific SKU Id. Items with multiple,    SKU-specific values are called SKU enabled.       The SKU Id of zero is reserved as a default. The valid SkuId range is 1 to 255.     For tokens that are not SKU enabled, the system ignores any set SKU Id and works with the    single value for that token. For SKU-enabled tokens, the system will use the SKU Id set by the    last call to SetSku(). If no SKU Id is set or the currently set SKU Id isn't valid for the specified token,    the system uses the default SKU Id. If the system attempts to use the default SKU Id and no value has been    set for that Id, the results are unpredictable.    @param[in]  SkuId The SKU value that will be used when the PCD service will retrieve and                set values associated with a PCD token.    @retval VOID  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_SKU
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|SkuId
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves an 8-bit value for a given PCD token.    Retrieves the current byte-sized value for a PCD token number.     If the TokenNumber is invalid, the results are unpredictable.      @param[in]  TokenNumber The PCD token number.     @return The UINT8 value.    **/
end_comment

begin_typedef
typedef|typedef
name|UINT8
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET8
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a 16-bit value for a given PCD token.    Retrieves the current 16-bit value for a PCD token number.     If the TokenNumber is invalid, the results are unpredictable.      @param[in]  TokenNumber The PCD token number.     @return The UINT16 value.    **/
end_comment

begin_typedef
typedef|typedef
name|UINT16
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET16
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a 32-bit value for a given PCD token.    Retrieves the current 32-bit value for a PCD token number.     If the TokenNumber is invalid, the results are unpredictable.      @param[in]  TokenNumber The PCD token number.     @return The UINT32 value.    **/
end_comment

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET32
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a 64-bit value for a given PCD token.    Retrieves the current 64-bit value for a PCD token number.     If the TokenNumber is invalid, the results are unpredictable.      @param[in]  TokenNumber The PCD token number.     @return The UINT64 value.    **/
end_comment

begin_typedef
typedef|typedef
name|UINT64
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET64
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a pointer to a value for a given PCD token.    Retrieves the current pointer to the buffer for a PCD token number.     Do not make any assumptions about the alignment of the pointer that    is returned by this function call.  If the TokenNumber is invalid,    the results are unpredictable.    @param[in]  TokenNumber The PCD token number.     @return The pointer to the buffer to be retrived.    **/
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_POINTER
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a Boolean value for a given PCD token.    Retrieves the current boolean value for a PCD token number.     Do not make any assumptions about the alignment of the pointer that    is returned by this function call.  If the TokenNumber is invalid,    the results are unpredictable.    @param[in]  TokenNumber The PCD token number.     @return The Boolean value.    **/
end_comment

begin_typedef
typedef|typedef
name|BOOLEAN
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_BOOLEAN
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the size of the value for a given PCD token.    Retrieves the current size of a particular PCD token.     If the TokenNumber is invalid, the results are unpredictable.    @param[in]  TokenNumber The PCD token number.     @return The size of the value for the PCD token.    **/
end_comment

begin_typedef
typedef|typedef
name|UINTN
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_SIZE
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves an 8-bit value for a given PCD token and token space.    Retrieves the 8-bit value of a particular PCD token.     If the TokenNumber is invalid or the token space   specified by Guid does not exist, the results are    unpredictable.    @param[in]  Guid        The token space for the token number.   @param[in]  TokenNumber The PCD token number.     @return The size 8-bit value for the PCD token.    **/
end_comment

begin_typedef
typedef|typedef
name|UINT8
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_EX_8
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a 16-bit value for a given PCD token and token space.    Retrieves the 16-bit value of a particular PCD token.     If the TokenNumber is invalid or the token space   specified by Guid does not exist, the results are    unpredictable.    @param[in]  Guid        The token space for the token number.   @param[in]  TokenNumber The PCD token number.     @return The size 16-bit value for the PCD token.    **/
end_comment

begin_typedef
typedef|typedef
name|UINT16
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_EX_16
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a 32-bit value for a given PCD token and token space.    Retrieves the 32-bit value of a particular PCD token.     If the TokenNumber is invalid or the token space   specified by Guid does not exist, the results are    unpredictable.    @param[in]  Guid        The token space for the token number.   @param[in]  TokenNumber The PCD token number.     @return The size 32-bit value for the PCD token.    **/
end_comment

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_EX_32
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a 64-bit value for a given PCD token and token space.    Retrieves the 64-bit value of a particular PCD token.     If the TokenNumber is invalid or the token space   specified by Guid does not exist, the results are    unpredictable.    @param[in]  Guid        The token space for the token number.   @param[in]  TokenNumber The PCD token number.     @return The size 64-bit value for the PCD token.    **/
end_comment

begin_typedef
typedef|typedef
name|UINT64
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_EX_64
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a pointer to a value for a given PCD token and token space.    Retrieves the current pointer to the buffer for a PCD token number.     Do not make any assumptions about the alignment of the pointer that    is returned by this function call.  If the TokenNumber is invalid,    the results are unpredictable.    @param[in]  Guid        The token space for the token number.   @param[in]  TokenNumber The PCD token number.     @return The pointer to the buffer to be retrived.    **/
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_EX_POINTER
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves an Boolean value for a given PCD token and token space.    Retrieves the Boolean value of a particular PCD token.     If the TokenNumber is invalid or the token space   specified by Guid does not exist, the results are    unpredictable.    @param[in]  Guid The token space for the token number.   @param[in]  TokenNumber The PCD token number.     @return The size Boolean value for the PCD token.    **/
end_comment

begin_typedef
typedef|typedef
name|BOOLEAN
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_EX_BOOLEAN
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the size of the value for a given PCD token and token space.    Retrieves the current size of a particular PCD token.     If the TokenNumber is invalid, the results are unpredictable.    @param[in]  Guid        The token space for the token number.   @param[in]  TokenNumber The PCD token number.     @return The size of the value for the PCD token.    **/
end_comment

begin_typedef
typedef|typedef
name|UINTN
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_EX_SIZE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets an 8-bit value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET8
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a 16-bit value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET16
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a 32-bit value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET32
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a 64-bit value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET64
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a value of a specified size for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]      TokenNumber  The PCD token number.    @param[in, out] SizeOfValue  A pointer to the length of the value being set for the PCD token.                                  On input, if the SizeOfValue is greater than the maximum size supported                                 for this TokenNumber then the output value of SizeOfValue will reflect                                 the maximum size supported for this TokenNumber.   @param[in]      Buffer       The buffer to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_POINTER
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|SizeOfValue
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets an Boolean value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_BOOLEAN
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|BOOLEAN
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets an 8-bit value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  Guid        The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_EX_8
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a 16-bit value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  Guid        The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_EX_16
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a 32-bit value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  Guid        The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_EX_32
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a 64-bit value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  Guid        The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_EX_64
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a value of a specified size for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]      Guid         The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]      TokenNumber  The PCD token number.    @param[in, out] SizeOfValue  A pointer to the length of the value being set for the PCD token.                                  On input, if the SizeOfValue is greater than the maximum size supported                                 for this TokenNumber then the output value of SizeOfValue will reflect                                 the maximum size supported for this TokenNumber.   @param[in]      Buffer       The buffer to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_EX_POINTER
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|SizeOfValue
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets an Boolean value for a given PCD token.    When the PCD service sets a value, it will check to ensure that the    size of the value being set is compatible with the Token's existing definition.     If it is not, an error will be returned.    @param[in]  Guid        The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]  TokenNumber The PCD token number.    @param[in]  Value       The value to set for the PCD token.    @retval EFI_SUCCESS           The procedure returned successfully.   @retval EFI_INVALID_PARAMETER The PCD service determined that the size of the data                                  being set was incompatible with a call to this function.                                   Use GetSize() to retrieve the size of the target data.   @retval EFI_NOT_FOUND         The PCD service could not find the requested token number.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_SET_EX_BOOLEAN
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|BOOLEAN
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Callback on SET function prototype definition.    This notification function serves two purposes. Firstly, it notifies the module    which did the registration that the value of this PCD token has been set. Secondly,    it provides a mechanism for the module which did the registration to intercept the set    operation and override the value been set if necessary. After the invocation of the    callback function, TokenData will be used by PCD service PEIM to modify the internal data    in PCD database.    @param[in]      CallBackGuid  The PCD token GUID being set.   @param[in]      CallBackToken The PCD token number being set.   @param[in, out] TokenData     A pointer to the token data being set.   @param[in]      TokenDataSize The size, in bytes, of the data being set.    @retval VOID  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|CallBackGuid
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
name|CallBackToken
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|TokenData
parameter_list|,
name|IN
name|UINTN
name|TokenDataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Specifies a function to be called anytime the value of a designated token is changed.    @param[in]  TokenNumber The PCD token number.    @param[in]  Guid The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]  CallBackFunction The function prototype called when the value associated with the CallBackToken is set.      @retval EFI_SUCCESS  The PCD service has successfully established a call event                          for the CallBackToken requested.   @retval EFI_NOT_FOUND The PCD service could not find the referenced token number.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_CALLBACK_ONSET
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|PCD_PPI_CALLBACK
name|CallBackFunction
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Cancels a previously set callback function for a particular PCD token number.    @param[in]  TokenNumber The PCD token number.    @param[in]  Guid The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]  CallBackFunction The function prototype called when the value associated with the CallBackToken is set.      @retval EFI_SUCCESS  The PCD service has successfully established a call event                          for the CallBackToken requested.   @retval EFI_NOT_FOUND The PCD service could not find the referenced token number.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_CANCEL_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|IN
name|PCD_PPI_CALLBACK
name|CallBackFunction
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the next valid token number in a given namespace.        This is useful since the PCD infrastructure contains a sparse list of token numbers,    and one cannot a priori know what token numbers are valid in the database.       If TokenNumber is 0 and Guid is not NULL, then the first token from the token space specified by Guid is returned.     If TokenNumber is not 0 and Guid is not NULL, then the next token in the token space specified by Guid is returned.     If TokenNumber is 0 and Guid is NULL, then the first token in the default token space is returned.     If TokenNumber is not 0 and Guid is NULL, then the next token in the default token space is returned.     The token numbers in the default token space may not be related to token numbers in token spaces that are named by Guid.     If the next token number can be retrieved, then it is returned in TokenNumber, and EFI_SUCCESS is returned.     If TokenNumber represents the last token number in the token space specified by Guid, then EFI_NOT_FOUND is returned.     If TokenNumber is not present in the token space specified by Guid, then EFI_NOT_FOUND is returned.     @param[in]       Guid        The 128-bit unique value that designates the namespace from which to extract the value.                                  This is an optional parameter that may be NULL.  If this parameter is NULL, then a request                                 is being made to retrieve tokens from the default token space.   @param[in, out]  TokenNumber A pointer to the PCD token number to use to find the subsequent token number.                       @retval EFI_SUCCESS   The PCD service has retrieved the next valid token number.   @retval EFI_NOT_FOUND The PCD service could not find data from the requested token number.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_NEXT_TOKEN
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|UINTN
modifier|*
name|TokenNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the next valid PCD token namespace for a given namespace.    Gets the next valid token namespace for a given namespace. This is useful to traverse the valid   token namespaces on a platform.    @param[in, out]   Guid    An indirect pointer to EFI_GUID. On input it designates a known token                             namespace from which the search will start. On output, it designates the next valid                             token namespace on the platform. If *Guid is NULL, then the GUID of the first token                             space of the current platform is returned. If the search cannot locate the next valid                             token namespace, an error is returned and the value of *Guid is undefined.     @retval  EFI_SUCCESS      The PCD service retrieved the value requested.   @retval  EFI_NOT_FOUND    The PCD service could not find the next valid token namespace.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PCD_PPI_GET_NEXT_TOKENSPACE
function_decl|)
parameter_list|(
name|IN
name|OUT
name|CONST
name|EFI_GUID
modifier|*
modifier|*
name|Guid
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This service abstracts the ability to set/get Platform Configuration Database (PCD).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|PCD_PPI_SET_SKU
name|SetSku
decl_stmt|;
name|PCD_PPI_GET8
name|Get8
decl_stmt|;
name|PCD_PPI_GET16
name|Get16
decl_stmt|;
name|PCD_PPI_GET32
name|Get32
decl_stmt|;
name|PCD_PPI_GET64
name|Get64
decl_stmt|;
name|PCD_PPI_GET_POINTER
name|GetPtr
decl_stmt|;
name|PCD_PPI_GET_BOOLEAN
name|GetBool
decl_stmt|;
name|PCD_PPI_GET_SIZE
name|GetSize
decl_stmt|;
name|PCD_PPI_GET_EX_8
name|Get8Ex
decl_stmt|;
name|PCD_PPI_GET_EX_16
name|Get16Ex
decl_stmt|;
name|PCD_PPI_GET_EX_32
name|Get32Ex
decl_stmt|;
name|PCD_PPI_GET_EX_64
name|Get64Ex
decl_stmt|;
name|PCD_PPI_GET_EX_POINTER
name|GetPtrEx
decl_stmt|;
name|PCD_PPI_GET_EX_BOOLEAN
name|GetBoolEx
decl_stmt|;
name|PCD_PPI_GET_EX_SIZE
name|GetSizeEx
decl_stmt|;
name|PCD_PPI_SET8
name|Set8
decl_stmt|;
name|PCD_PPI_SET16
name|Set16
decl_stmt|;
name|PCD_PPI_SET32
name|Set32
decl_stmt|;
name|PCD_PPI_SET64
name|Set64
decl_stmt|;
name|PCD_PPI_SET_POINTER
name|SetPtr
decl_stmt|;
name|PCD_PPI_SET_BOOLEAN
name|SetBool
decl_stmt|;
name|PCD_PPI_SET_EX_8
name|Set8Ex
decl_stmt|;
name|PCD_PPI_SET_EX_16
name|Set16Ex
decl_stmt|;
name|PCD_PPI_SET_EX_32
name|Set32Ex
decl_stmt|;
name|PCD_PPI_SET_EX_64
name|Set64Ex
decl_stmt|;
name|PCD_PPI_SET_EX_POINTER
name|SetPtrEx
decl_stmt|;
name|PCD_PPI_SET_EX_BOOLEAN
name|SetBoolEx
decl_stmt|;
name|PCD_PPI_CALLBACK_ONSET
name|CallbackOnSet
decl_stmt|;
name|PCD_PPI_CANCEL_CALLBACK
name|CancelCallback
decl_stmt|;
name|PCD_PPI_GET_NEXT_TOKEN
name|GetNextToken
decl_stmt|;
name|PCD_PPI_GET_NEXT_TOKENSPACE
name|GetNextTokenSpace
decl_stmt|;
block|}
name|PCD_PPI
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gPcdPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

