begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The EFI_BIS_PROTOCOL is used to check a digital signature of a data block    against a digital certificate for the purpose of an integrity and authorization check.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.            @par Revision Reference:             This Protocol is introduced in EFI Specification 1.10.       **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BIS_H__
end_ifndef

begin_define
define|#
directive|define
name|__BIS_H__
end_define

begin_define
define|#
directive|define
name|EFI_BIS_PROTOCOL_GUID
define|\
value|{ \     0x0b64aab0, 0x5429, 0x11d4, {0x98, 0x16, 0x00, 0xa0, 0xc9, 0x1f, 0xad, 0xcf } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// X-Intel-BIS-ParameterSet
end_comment

begin_comment
comment|// Attribute value
end_comment

begin_comment
comment|// Binary Value of X-Intel-BIS-ParameterSet Attribute.
end_comment

begin_comment
comment|// (Value is Base-64 encoded in actual signed manifest).
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|BOOT_OBJECT_AUTHORIZATION_PARMSET_GUID
define|\
value|{ \     0xedd35e31, 0x7b9, 0x11d2, { 0x83,0xa3,0x0,0xa0,0xc9,0x1f,0xad,0xcf } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_BIS_PROTOCOL
name|EFI_BIS_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Basic types
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|BIS_APPLICATION_HANDLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|BIS_ALG_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|BIS_CERT_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BIS_DATA instances obtained from BIS must be freed by calling Free( ).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Length
decl_stmt|;
comment|///< The length of Data in 8 bit bytes.
name|UINT8
modifier|*
name|Data
decl_stmt|;
comment|///< 32 Bit Flat Address of data.
block|}
name|EFI_BIS_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BIS_VERSION type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Major
decl_stmt|;
comment|///< The major BIS version number.
name|UINT32
name|Minor
decl_stmt|;
comment|///< A minor BIS version number.
block|}
name|EFI_BIS_VERSION
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// ----------------------------------------------------//
end_comment

begin_comment
comment|// Use these values to initialize EFI_BIS_VERSION.Major
end_comment

begin_comment
comment|// and to interpret results of Initialize.
end_comment

begin_comment
comment|// ----------------------------------------------------//
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|BIS_CURRENT_VERSION_MAJOR
value|BIS_VERSION_1
end_define

begin_define
define|#
directive|define
name|BIS_VERSION_1
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BIS_SIGNATURE_INFO type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|BIS_CERT_ID
name|CertificateID
decl_stmt|;
comment|///< Truncated hash of platform Boot Object
name|BIS_ALG_ID
name|AlgorithmID
decl_stmt|;
comment|///< A signature algorithm number.
name|UINT16
name|KeyLength
decl_stmt|;
comment|///< The length of alg. keys in bits.
block|}
name|EFI_BIS_SIGNATURE_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// values for EFI_BIS_SIGNATURE_INFO.AlgorithmID.
end_comment

begin_comment
comment|/// The exact numeric values come from the
end_comment

begin_comment
comment|///    "Common Data Security Architecture (CDSA) Specification".
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|BIS_ALG_DSA
value|(41)
end_define

begin_comment
comment|// CSSM_ALGID_DSA
end_comment

begin_define
define|#
directive|define
name|BIS_ALG_RSA_MD5
value|(42)
end_define

begin_comment
comment|// CSSM_ALGID_MD5_WITH_RSA
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// values for EFI_BIS_SIGNATURE_INFO.CertificateId.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|BIS_CERT_ID_DSA
value|BIS_ALG_DSA
end_define

begin_comment
comment|// CSSM_ALGID_DSA
end_comment

begin_define
define|#
directive|define
name|BIS_CERT_ID_RSA_MD5
value|BIS_ALG_RSA_MD5
end_define

begin_comment
comment|// CSSM_ALGID_MD5_WITH_RSA
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The mask value that gets applied to the truncated hash of a
end_comment

begin_comment
comment|/// platform  Boot Object Authorization Certificate to create the certificateID.
end_comment

begin_comment
comment|/// A certificateID must not have any bits set to the value 1 other than bits in
end_comment

begin_comment
comment|/// this mask.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|BIS_CERT_ID_MASK
value|(0xFF7F7FFF)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Macros for dealing with the EFI_BIS_DATA object obtained
end_comment

begin_comment
comment|/// from BIS_GetSignatureInfo().
end_comment

begin_comment
comment|/// BIS_GET_SIGINFO_COUNT - tells how many EFI_BIS_SIGNATURE_INFO
end_comment

begin_comment
comment|///  elements are contained in a EFI_BIS_DATA struct pointed to
end_comment

begin_comment
comment|///  by the provided EFI_BIS_DATA*.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|BIS_GET_SIGINFO_COUNT
parameter_list|(
name|BisDataPtr
parameter_list|)
value|((BisDataPtr)->Length / sizeof (EFI_BIS_SIGNATURE_INFO))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIS_GET_SIGINFO_ARRAY - produces a EFI_BIS_SIGNATURE_INFO*
end_comment

begin_comment
comment|///  from a given EFI_BIS_DATA*.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|BIS_GET_SIGINFO_ARRAY
parameter_list|(
name|BisDataPtr
parameter_list|)
value|((EFI_BIS_SIGNATURE_INFO *) (BisDataPtr)->Data)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Support an old name for backward compatibility.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|BOOT_OBJECT_AUTHORIZATION_PARMSET_GUIDVALUE
define|\
value|BOOT_OBJECT_AUTHORIZATION_PARMSET_GUID
end_define

begin_comment
comment|/**                                                                    Initializes the BIS service, checking that it is compatible with the version requested by the caller.   After this call, other BIS functions may be invoked.                                                         @param  This                     A pointer to the EFI_BIS_PROTOCOL object.   @param  AppHandle                The function writes the new BIS_APPLICATION_HANDLE if                                               successful, otherwise it writes NULL. The caller must eventually                                    destroy this handle by calling Shutdown().                         @param  InterfaceVersion         On input, the caller supplies the major version number of the                                    interface version desired.                                                                       On output, both the major and minor                                                             version numbers are updated with the major and minor version                                    numbers of the interface. This update is done whether or not the                                    initialization was successful.                                       @param  TargetAddress            Indicates a network or device address of the BIS platform to connect to.                                                                     @retval EFI_SUCCESS              The function completed successfully.   @retval EFI_INCOMPATIBLE_VERSION The InterfaceVersion.Major requested by the                                                    caller was not compatible with the interface version of the                                    implementation. The InterfaceVersion.Major has                                    been updated with the current interface version.   @retval EFI_UNSUPPORTED          This is a local-platform implementation and                                            TargetAddress.Data was not NULL, or                                                    TargetAddress.Data was any other value that was not                                    supported by the implementation.                      @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                                 @retval EFI_DEVICE_ERROR         One of the following device errors:                                    * The function encountered an unexpected internal failure while initializing a cryptographic software module                                    * No cryptographic software module with compatible version was found                                    found                                    * A resource limitation was encountered while using a cryptographic software module.   @retval EFI_INVALID_PARAMETER    The This parameter supplied by the caller is NULL or does not                                    reference a valid EFI_BIS_PROTOCOL object. Or,                                    the AppHandle parameter supplied by the caller is NULL or                                    an invalid memory reference. Or,                                    the InterfaceVersion parameter supplied by the caller                                    is NULL or an invalid memory reference. Or,                                    the TargetAddress parameter supplied by the caller is                                    NULL or an invalid memory reference.                                            **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_INITIALIZE
function_decl|)
parameter_list|(
name|IN
name|EFI_BIS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|BIS_APPLICATION_HANDLE
modifier|*
name|AppHandle
parameter_list|,
name|IN
name|OUT
name|EFI_BIS_VERSION
modifier|*
name|InterfaceVersion
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|TargetAddress
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Frees memory structures allocated and returned by other functions in the EFI_BIS protocol.            @param  AppHandle                An opaque handle that identifies the caller's instance of initialization                                    of the BIS service.                                                                                            @param  ToFree                   An EFI_BIS_DATA* and associated memory block to be freed.                                     This EFI_BIS_DATA* must have been allocated by one of the other BIS functions.    @retval EFI_SUCCESS              The function completed successfully.   @retval EFI_NO_MAPPING           The AppHandle parameter is not or is no longer a valid                                    application instance handle associated with the EFI_BIS protocol.                                        @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                                   @retval EFI_INVALID_PARAMETER    The ToFree parameter is not or is no longer a memory resource                                    associated with this AppHandle.                                                                           **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_FREE
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|ToFree
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Shuts down an application's instance of the BIS service, invalidating the application handle. After   this call, other BIS functions may no longer be invoked using the application handle value.                   @param  AppHandle                An opaque handle that identifies the caller's instance of initialization                                    of the BIS service.                                                                                               @retval EFI_SUCCESS              The function completed successfully.   @retval EFI_NO_MAPPING           The AppHandle parameter is not, or is no longer, a valid                                    application instance handle associated with the EFI_BIS protocol.                                        @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                                   @retval EFI_DEVICE_ERROR         The function encountered an unexpected internal failure while                                    returning resources associated with a cryptographic software module, or                                    while trying to shut down a cryptographic software module. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_SHUTDOWN
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves the certificate that has been configured as the identity of the organization designated as   the source of authorization for signatures of boot objects.          @param  AppHandle                An opaque handle that identifies the caller's instance of initialization                                    of the BIS service.                                                                                              @param  Certificate              The function writes an allocated EFI_BIS_DATA* containing the Boot                                    Object Authorization Certificate object.  The caller must                                    eventually free the memory allocated by this function using the function Free().    @retval EFI_SUCCESS              The function completed successfully.   @retval EFI_NO_MAPPING           The AppHandle parameter is not or is no longer a valid                                    application instance handle associated with the EFI_BIS protocol.                                        @retval EFI_NOT_FOUND            There is no Boot Object Authorization Certificate currently installed.                           @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                                   @retval EFI_INVALID_PARAMETER    The Certificate parameter supplied by the caller is NULL or                                    an invalid memory reference.                                                                            **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_GET_BOOT_OBJECT_AUTHORIZATION_CERTIFICATE
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|,
name|OUT
name|EFI_BIS_DATA
modifier|*
modifier|*
name|Certificate
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Verifies the integrity and authorization of the indicated data object according to the   indicated credentials.                                                                          @param  AppHandle                An opaque handle that identifies the caller's instance of initialization                                    of the BIS service.                                                                                              @param  Credentials              A Signed Manifest containing verification information for the indicated                                    data object.                                                               @param  DataObject               An in-memory copy of the raw data object to be verified.   @param  IsVerified               The function writes TRUE if the verification succeeded, otherwise                                    FALSE.                                                                                                  @retval EFI_SUCCESS              The function completed successfully.   @retval EFI_NO_MAPPING           The AppHandle parameter is not or is no longer a valid                                    application instance handle associated with the EFI_BIS protocol.                                          @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                                   @retval EFI_INVALID_PARAMETER    One or more parameters are invalid.   @retval EFI_SECURITY_VIOLATION   The signed manifest supplied as the Credentials parameter                                    was invalid (could not be parsed) or Platform-specific authorization failed, etc.   @retval EFI_DEVICE_ERROR         An unexpected internal error occurred.                                                                **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_VERIFY_BOOT_OBJECT
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|Credentials
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|DataObject
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|IsVerified
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves the current status of the Boot Authorization Check Flag.          @param  AppHandle                An opaque handle that identifies the caller's instance of initialization                                    of the BIS service.                                                                                              @param  CheckIsRequired          The function writes the value TRUE if a Boot Authorization Check is                                    currently required on this platform, otherwise the function writes                                     FALSE.                                                                                                    @retval EFI_SUCCESS              The function completed successfully.   @retval EFI_NO_MAPPING           The AppHandle parameter is not or is no longer a valid                                    application instance handle associated with the EFI_BIS protocol.                                          @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                                   @retval EFI_INVALID_PARAMETER    The CheckIsRequired parameter supplied by the caller is                                    NULL or an invalid memory reference.                                                        **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_GET_BOOT_OBJECT_AUTHORIZATION_CHECKFLAG
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|CheckIsRequired
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves a unique token value to be included in the request credential for the next update of any   parameter in the Boot Object Authorization set                                                              @param  AppHandle                An opaque handle that identifies the caller's                                     instance of initialization of the BIS service.                                                                                              @param  UpdateToken              The function writes an allocated EFI_BIS_DATA*                                     containing the newunique update token value.                                      The caller musteventually free the memory allocated                                      by this function using the function Free().                                       @retval EFI_SUCCESS              The function completed successfully.   @retval EFI_NO_MAPPING           The AppHandle parameter is not or is no longer a valid                                    application instance handle associated with the EFI_BIS protocol.                                          @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                                   @retval EFI_INVALID_PARAMETER    The UpdateToken parameter supplied by the caller is NULL or                                    an invalid memory reference.           @retval EFI_DEVICE_ERROR         An unexpected internal error occurred.                                                                                                 **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_GET_BOOT_OBJECT_AUTHORIZATION_UPDATE_TOKEN
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|,
name|OUT
name|EFI_BIS_DATA
modifier|*
modifier|*
name|UpdateToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Updates one of the configurable parameters of the Boot Object Authorization set.          @param  AppHandle                An opaque handle that identifies the caller's                                     instance of initialization of the BIS service.                                                                                              @param  RequestCredential        This is a Signed Manifest with embedded attributes                                     that carry the details of the requested update.                                                    @param  NewUpdateToken           The function writes an allocated EFI_BIS_DATA*                                     containing the new unique update token value.                                     The caller must eventually free the memory allocated                                      by this function using the function Free().                                       @retval EFI_SUCCESS              The function completed successfully.                                                   @retval EFI_NO_MAPPING           The AppHandle parameter is not or is no longer a valid                                                                  application instance handle associated with the EFI_BIS protocol.                      @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                          @retval EFI_INVALID_PARAMETER    One or more parameters are invalid.                                                    @retval EFI_SECURITY_VIOLATION   The signed manifest supplied as the RequestCredential parameter                                                               was invalid (could not be parsed) or Platform-specific authorization failed, etc.      @retval EFI_DEVICE_ERROR         An unexpected internal error occurred while analyzing the new                                    certificate's key algorithm, or while attempting to retrieve                                    the public key algorithm of the manifest's signer's certificate,                                    or An unexpected internal error occurred in a cryptographic software module.                                                                                                                                                                                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_UPDATE_BOOT_OBJECT_AUTHORIZATION
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|RequestCredential
parameter_list|,
name|OUT
name|EFI_BIS_DATA
modifier|*
modifier|*
name|NewUpdateToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Verifies the integrity and authorization of the indicated data object according to the indicated   credentials and authority certificate.                                                                    @param  AppHandle                An opaque handle that identifies the caller's instance of initialization                                    of the BIS service.                                                                                              @param  Credentials              A Signed Manifest containing verification information for the                                    indicated data object.                                          @param  DataObject               An in-memory copy of the raw data object to be verified.   @param  SectionName              An ASCII string giving the section name in the                                      manifest holding the verification information (in other words,                                    hash value) that corresponds to DataObject.                                @param  AuthorityCertificate     A digital certificate whose public key must match the signer's                                                                  public key which is found in the credentials.                     @param  IsVerified               The function writes TRUE if the verification was successful.                                    Otherwise, the function writes FALSE.                                                              @retval EFI_SUCCESS              The function completed successfully.                                                   @retval EFI_NO_MAPPING           The AppHandle parameter is not or is no longer a valid                                                                  application instance handle associated with the EFI_BIS protocol.                      @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                          @retval EFI_INVALID_PARAMETER    One or more parameters are invalid.                                                    @retval EFI_SECURITY_VIOLATION   The Credentials.Data supplied by the caller is NULL,                                    or the AuthorityCertificate supplied by the caller was                                     invalid (could not be parsed),                                                          or Platform-specific authorization failed, etc.      @retval EFI_DEVICE_ERROR         An unexpected internal error occurred while attempting to retrieve                                    the public key algorithm of the manifest's signer's certificate,                                    or An unexpected internal error occurred in a cryptographic software module.                                                                                                                                                                   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_VERIFY_OBJECT_WITH_CREDENTIAL
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|Credentials
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|DataObject
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|SectionName
parameter_list|,
name|IN
name|EFI_BIS_DATA
modifier|*
name|AuthorityCertificate
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|IsVerified
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves a list of digital certificate identifier, digital signature algorithm, hash algorithm, and keylength   combinations that the platform supports.                                                                          @param  AppHandle                An opaque handle that identifies the caller's instance of initialization                                    of the BIS service.                                                                                              @param  SignatureInfo            The function writes an allocated EFI_BIS_DATA* containing the array                                    of EFI_BIS_SIGNATURE_INFO structures representing the supported                                        digital certificate identifier, algorithm, and key length combinations.                                    The caller must eventually free the memory allocated by this function using the function Free().    @retval EFI_SUCCESS              The function completed successfully.                                                   @retval EFI_NO_MAPPING           The AppHandle parameter is not or is no longer a valid                                                                  application instance handle associated with the EFI_BIS protocol.                      @retval EFI_OUT_OF_RESOURCES     The function failed due to lack of memory or other resources.                          @retval EFI_INVALID_PARAMETER    The SignatureInfo parameter supplied by the caller is NULL                                    or an invalid memory reference.   @retval EFI_DEVICE_ERROR         An unexpected internal error occurred in a                                    cryptographic software module, or                                    The function encountered an unexpected internal consistency check                                    failure (possible corruption of stored Boot Object Authorization Certificate).  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BIS_GET_SIGNATURE_INFO
function_decl|)
parameter_list|(
name|IN
name|BIS_APPLICATION_HANDLE
name|AppHandle
parameter_list|,
name|OUT
name|EFI_BIS_DATA
modifier|*
modifier|*
name|SignatureInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_BIS_PROTOCOL is used to check a digital signature of a data block against a digital
end_comment

begin_comment
comment|/// certificate for the purpose of an integrity and authorization check.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_BIS_PROTOCOL
block|{
name|EFI_BIS_INITIALIZE
name|Initialize
decl_stmt|;
name|EFI_BIS_SHUTDOWN
name|Shutdown
decl_stmt|;
name|EFI_BIS_FREE
name|Free
decl_stmt|;
name|EFI_BIS_GET_BOOT_OBJECT_AUTHORIZATION_CERTIFICATE
name|GetBootObjectAuthorizationCertificate
decl_stmt|;
name|EFI_BIS_GET_BOOT_OBJECT_AUTHORIZATION_CHECKFLAG
name|GetBootObjectAuthorizationCheckFlag
decl_stmt|;
name|EFI_BIS_GET_BOOT_OBJECT_AUTHORIZATION_UPDATE_TOKEN
name|GetBootObjectAuthorizationUpdateToken
decl_stmt|;
name|EFI_BIS_GET_SIGNATURE_INFO
name|GetSignatureInfo
decl_stmt|;
name|EFI_BIS_UPDATE_BOOT_OBJECT_AUTHORIZATION
name|UpdateBootObjectAuthorization
decl_stmt|;
name|EFI_BIS_VERIFY_BOOT_OBJECT
name|VerifyBootObject
decl_stmt|;
name|EFI_BIS_VERIFY_OBJECT_WITH_CREDENTIAL
name|VerifyObjectWithCredential
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBisProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gBootObjectAuthorizationParmsetGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

