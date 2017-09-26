begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//<copyright file="Program.cpp" company="Microsoft Corporation">
end_comment

begin_comment
comment|// Copyright (C) Microsoft Corporation. All rights reserved.
end_comment

begin_comment
comment|// Licensed under the MIT license.
end_comment

begin_comment
comment|//</copyright>
end_comment

begin_comment
comment|//<license>
end_comment

begin_comment
comment|// The MIT License (MIT)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright (C) Microsoft Corporation. All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Permission is hereby granted, free of charge, to any person obtaining
end_comment

begin_comment
comment|// a copy of this software and associated documentation files (the "Software"),
end_comment

begin_comment
comment|// to deal in the Software without restriction, including without limitation the
end_comment

begin_comment
comment|// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
end_comment

begin_comment
comment|// sell copies of the Software, and to permit persons to whom the Software is
end_comment

begin_comment
comment|// furnished to do so, subject to the following conditions:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The above copyright notice and this permission notice shall be included in
end_comment

begin_comment
comment|// all copies or substantial portions of the Software.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
end_comment

begin_comment
comment|// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
end_comment

begin_comment
comment|// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
end_comment

begin_comment
comment|// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
end_comment

begin_comment
comment|// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
end_comment

begin_comment
comment|// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
end_comment

begin_comment
comment|// SOFTWARE.
end_comment

begin_comment
comment|//</license>
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// Constants
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|E_NOTFOUND
end_ifndef

begin_define
define|#
directive|define
name|E_NOTFOUND
value|HRESULT_FROM_WIN32(ERROR_NOT_FOUND)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|E_FILENOTFOUND
end_ifndef

begin_define
define|#
directive|define
name|E_FILENOTFOUND
value|HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Enumerations
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///<summary>
end_comment

begin_comment
comment|/// The state of an instance.
end_comment

begin_comment
comment|///</summary>
end_comment

begin_enum
enum|enum
name|InstanceState
enum|:
name|unsigned
block|{
comment|///<summary>
comment|/// The instance state has not been determined.
comment|///</summary>
name|eNone
init|=
literal|0
block|,
comment|///<summary>
comment|/// The instance installation path exists.
comment|///</summary>
name|eLocal
init|=
literal|1
block|,
comment|///<summary>
comment|/// A product is registered to the instance.
comment|///</summary>
name|eRegistered
init|=
literal|2
block|,
comment|///<summary>
comment|/// No reboot is required for the instance.
comment|///</summary>
name|eNoRebootRequired
init|=
literal|4
block|,
comment|///<summary>
comment|/// The instance represents a complete install.
comment|///</summary>
name|eComplete
init|=
name|MAXUINT
block|, }
enum|;
end_enum

begin_comment
comment|// Forward interface declarations
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ISetupInstance_FWD_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__ISetupInstance_FWD_DEFINED__
end_define

begin_typedef
typedef|typedef
name|struct
name|ISetupInstance
name|ISetupInstance
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ISetupInstance2_FWD_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__ISetupInstance2_FWD_DEFINED__
end_define

begin_typedef
typedef|typedef
name|struct
name|ISetupInstance2
name|ISetupInstance2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__IEnumSetupInstances_FWD_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__IEnumSetupInstances_FWD_DEFINED__
end_define

begin_typedef
typedef|typedef
name|struct
name|IEnumSetupInstances
name|IEnumSetupInstances
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ISetupConfiguration_FWD_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__ISetupConfiguration_FWD_DEFINED__
end_define

begin_typedef
typedef|typedef
name|struct
name|ISetupConfiguration
name|ISetupConfiguration
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ISetupConfiguration2_FWD_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__ISetupConfiguration2_FWD_DEFINED__
end_define

begin_typedef
typedef|typedef
name|struct
name|ISetupConfiguration2
name|ISetupConfiguration2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ISetupPackageReference_FWD_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__ISetupPackageReference_FWD_DEFINED__
end_define

begin_typedef
typedef|typedef
name|struct
name|ISetupPackageReference
name|ISetupPackageReference
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ISetupHelper_FWD_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__ISetupHelper_FWD_DEFINED__
end_define

begin_typedef
typedef|typedef
name|struct
name|ISetupHelper
name|ISetupHelper
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Forward class declarations
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SetupConfiguration_FWD_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__SetupConfiguration_FWD_DEFINED__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_typedef
typedef|typedef
name|class
name|SetupConfiguration
name|SetupConfiguration
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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
comment|// Interface definitions
comment|//
name|EXTERN_C
specifier|const
name|IID
name|IID_ISetupInstance
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
comment|///<summary>
comment|/// Information about an instance of a product.
comment|///</summary>
name|struct
name|DECLSPEC_UUID
argument_list|(
literal|"B41463C3-8866-43B5-BC33-2B0676F7F42E"
argument_list|)
name|DECLSPEC_NOVTABLE
name|ISetupInstance
range|:
name|public
name|IUnknown
block|{
comment|///<summary>
comment|/// Gets the instance identifier (should match the name of the parent instance
comment|/// directory).
comment|///</summary>
comment|///<param name="pbstrInstanceId">The instance identifier.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist.</returns>
name|STDMETHOD
argument_list|(
argument|GetInstanceId
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrInstanceId
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the local date and time when the installation was originally
comment|/// installed.
comment|///</summary>
comment|///<param name="pInstallDate">The local date and time when the installation
comment|/// was originally installed.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|GetInstallDate
argument_list|)
operator|(
name|_Out_
name|LPFILETIME
name|pInstallDate
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the unique name of the installation, often indicating the branch and
comment|/// other information used for telemetry.
comment|///</summary>
comment|///<param name="pbstrInstallationName">The unique name of the installation,
comment|/// often indicating the branch and other information used for
comment|/// telemetry.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|GetInstallationName
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrInstallationName
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the path to the installation root of the product.
comment|///</summary>
comment|///<param name="pbstrInstallationPath">The path to the installation root of
comment|/// the product.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|GetInstallationPath
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrInstallationPath
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the version of the product installed in this instance.
comment|///</summary>
comment|///<param name="pbstrInstallationVersion">The version of the product
comment|/// installed in this instance.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|GetInstallationVersion
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrInstallationVersion
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the display name (title) of the product installed in this instance.
comment|///</summary>
comment|///<param name="lcid">The LCID for the display name.</param>
comment|///<param name="pbstrDisplayName">The display name (title) of the product
comment|/// installed in this instance.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|GetDisplayName
argument_list|)
operator|(
name|_In_
name|LCID
name|lcid
expr|,
name|_Out_
name|BSTR
operator|*
name|pbstrDisplayName
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the description of the product installed in this instance.
comment|///</summary>
comment|///<param name="lcid">The LCID for the description.</param>
comment|///<param name="pbstrDescription">The description of the product installed in
comment|/// this instance.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|GetDescription
argument_list|)
operator|(
name|_In_
name|LCID
name|lcid
expr|,
name|_Out_
name|BSTR
operator|*
name|pbstrDescription
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Resolves the optional relative path to the root path of the instance.
comment|///</summary>
comment|///<param name="pwszRelativePath">A relative path within the instance to
comment|/// resolve, or NULL to get the root path.</param>
comment|///<param name="pbstrAbsolutePath">The full path to the optional relative
comment|/// path within the instance. If the relative path is NULL, the root path will
comment|/// always terminate in a backslash.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|ResolvePath
argument_list|)
operator|(
name|_In_opt_z_
name|LPCOLESTR
name|pwszRelativePath
expr|,
name|_Out_
name|BSTR
operator|*
name|pbstrAbsolutePath
operator|)
operator|=
literal|0
block|; }
decl_stmt|;
endif|#
directive|endif
name|EXTERN_C
specifier|const
name|IID
name|IID_ISetupInstance2
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
comment|///<summary>
comment|/// Information about an instance of a product.
comment|///</summary>
name|struct
name|DECLSPEC_UUID
argument_list|(
literal|"89143C9A-05AF-49B0-B717-72E218A2185C"
argument_list|)
name|DECLSPEC_NOVTABLE
name|ISetupInstance2
range|:
name|public
name|ISetupInstance
block|{
comment|///<summary>
comment|/// Gets the state of the instance.
comment|///</summary>
comment|///<param name="pState">The state of the instance.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist.</returns>
name|STDMETHOD
argument_list|(
argument|GetState
argument_list|)
operator|(
name|_Out_
name|InstanceState
operator|*
name|pState
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets an array of package references registered to the instance.
comment|///</summary>
comment|///<param name="ppsaPackages">Pointer to an array of<see
comment|/// cref="ISetupPackageReference"/>.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// packages property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|GetPackages
argument_list|)
operator|(
name|_Out_
name|LPSAFEARRAY
operator|*
name|ppsaPackages
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets a pointer to the<see cref="ISetupPackageReference"/> that represents
comment|/// the registered product.
comment|///</summary>
comment|///<param name="ppPackage">Pointer to an instance of<see
comment|/// cref="ISetupPackageReference"/>. This may be NULL if<see
comment|/// cref="GetState"/> does not return<see cref="eComplete"/>.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist and E_NOTFOUND if the
comment|/// packages property is not defined.</returns>
name|STDMETHOD
argument_list|(
argument|GetProduct
argument_list|)
operator|(
name|_Outptr_result_maybenull_
name|ISetupPackageReference
operator|*
operator|*
name|ppPackage
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the relative path to the product application, if available.
comment|///</summary>
comment|///<param name="pbstrProductPath">The relative path to the product
comment|/// application, if available.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_FILENOTFOUND if the instance state does not exist.</returns>
name|STDMETHOD
argument_list|(
argument|GetProductPath
argument_list|)
operator|(
name|_Outptr_result_maybenull_
name|BSTR
operator|*
name|pbstrProductPath
operator|)
operator|=
literal|0
block|; }
decl_stmt|;
endif|#
directive|endif
name|EXTERN_C
specifier|const
name|IID
name|IID_IEnumSetupInstances
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
comment|///<summary>
comment|/// A enumerator of installed<see cref="ISetupInstance"/> objects.
comment|///</summary>
name|struct
name|DECLSPEC_UUID
argument_list|(
literal|"6380BCFF-41D3-4B2E-8B2E-BF8A6810C848"
argument_list|)
name|DECLSPEC_NOVTABLE
name|IEnumSetupInstances
range|:
name|public
name|IUnknown
block|{
comment|///<summary>
comment|/// Retrieves the next set of product instances in the enumeration sequence.
comment|///</summary>
comment|///<param name="celt">The number of product instances to retrieve.</param>
comment|///<param name="rgelt">A pointer to an array of<see
comment|/// cref="ISetupInstance"/>.</param>
comment|///<param name="pceltFetched">A pointer to the number of product instances
comment|/// retrieved. If celt is 1 this parameter may be NULL.</param>
comment|///<returns>S_OK if the number of elements were fetched, S_FALSE if nothing
comment|/// was fetched (at end of enumeration), E_INVALIDARG if celt is greater than
comment|/// 1 and pceltFetched is NULL, or E_OUTOFMEMORY if an<see
comment|/// cref="ISetupInstance"/> could not be allocated.</returns>
name|STDMETHOD
argument_list|(
argument|Next
argument_list|)
operator|(
name|_In_
name|ULONG
name|celt
expr|,
name|_Out_writes_to_
argument_list|(
argument|celt
argument_list|,
argument|*pceltFetched
argument_list|)
name|ISetupInstance
operator|*
operator|*
name|rgelt
expr|,
name|_Out_opt_
name|_Deref_out_range_
argument_list|(
literal|0
argument_list|,
argument|celt
argument_list|)
name|ULONG
operator|*
name|pceltFetched
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Skips the next set of product instances in the enumeration sequence.
comment|///</summary>
comment|///<param name="celt">The number of product instances to skip.</param>
comment|///<returns>S_OK if the number of elements could be skipped; otherwise,
comment|/// S_FALSE;</returns>
name|STDMETHOD
argument_list|(
argument|Skip
argument_list|)
operator|(
name|_In_
name|ULONG
name|celt
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Resets the enumeration sequence to the beginning.
comment|///</summary>
comment|///<returns>Always returns S_OK;</returns>
name|STDMETHOD
argument_list|(
name|Reset
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Creates a new enumeration object in the same state as the current
comment|/// enumeration object: the new object points to the same place in the
comment|/// enumeration sequence.
comment|///</summary>
comment|///<param name="ppenum">A pointer to a pointer to a new<see
comment|/// cref="IEnumSetupInstances"/> interface. If the method fails, this
comment|/// parameter is undefined.</param>
comment|///<returns>S_OK if a clone was returned; otherwise, E_OUTOFMEMORY.</returns>
name|STDMETHOD
argument_list|(
argument|Clone
argument_list|)
operator|(
name|_Deref_out_opt_
name|IEnumSetupInstances
operator|*
operator|*
name|ppenum
operator|)
operator|=
literal|0
block|; }
decl_stmt|;
endif|#
directive|endif
name|EXTERN_C
specifier|const
name|IID
name|IID_ISetupConfiguration
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
comment|///<summary>
comment|/// Gets information about product instances set up on the machine.
comment|///</summary>
name|struct
name|DECLSPEC_UUID
argument_list|(
literal|"42843719-DB4C-46C2-8E7C-64F1816EFD5B"
argument_list|)
name|DECLSPEC_NOVTABLE
name|ISetupConfiguration
range|:
name|public
name|IUnknown
block|{
comment|///<summary>
comment|/// Enumerates all completed product instances installed.
comment|///</summary>
comment|///<param name="ppEnumInstances">An enumeration of completed, installed
comment|/// product instances.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|EnumInstances
argument_list|)
operator|(
name|_Out_
name|IEnumSetupInstances
operator|*
operator|*
name|ppEnumInstances
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the instance for the current process path.
comment|///</summary>
comment|///<param name="ppInstance">The instance for the current process
comment|/// path.</param>
comment|///<returns>The instance for the current process path, or E_NOTFOUND if not
comment|/// found.</returns>
name|STDMETHOD
argument_list|(
argument|GetInstanceForCurrentProcess
argument_list|)
operator|(
name|_Out_
name|ISetupInstance
operator|*
operator|*
name|ppInstance
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the instance for the given path.
comment|///</summary>
comment|///<param name="ppInstance">The instance for the given path.</param>
comment|///<returns>The instance for the given path, or E_NOTFOUND if not
comment|/// found.</returns>
name|STDMETHOD
argument_list|(
argument|GetInstanceForPath
argument_list|)
operator|(
name|_In_z_
name|LPCWSTR
name|wzPath
expr|,
name|_Out_
name|ISetupInstance
operator|*
operator|*
name|ppInstance
operator|)
operator|=
literal|0
block|; }
decl_stmt|;
endif|#
directive|endif
name|EXTERN_C
specifier|const
name|IID
name|IID_ISetupConfiguration2
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
comment|///<summary>
comment|/// Gets information about product instances.
comment|///</summary>
name|struct
name|DECLSPEC_UUID
argument_list|(
literal|"26AAB78C-4A60-49D6-AF3B-3C35BC93365D"
argument_list|)
name|DECLSPEC_NOVTABLE
name|ISetupConfiguration2
range|:
name|public
name|ISetupConfiguration
block|{
comment|///<summary>
comment|/// Enumerates all product instances.
comment|///</summary>
comment|///<param name="ppEnumInstances">An enumeration of all product
comment|/// instances.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|EnumAllInstances
argument_list|)
operator|(
name|_Out_
name|IEnumSetupInstances
operator|*
operator|*
name|ppEnumInstances
operator|)
operator|=
literal|0
block|; }
decl_stmt|;
endif|#
directive|endif
name|EXTERN_C
specifier|const
name|IID
name|IID_ISetupPackageReference
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
comment|///<summary>
comment|/// A reference to a package.
comment|///</summary>
name|struct
name|DECLSPEC_UUID
argument_list|(
literal|"da8d8a16-b2b6-4487-a2f1-594ccccd6bf5"
argument_list|)
name|DECLSPEC_NOVTABLE
name|ISetupPackageReference
range|:
name|public
name|IUnknown
block|{
comment|///<summary>
comment|/// Gets the general package identifier.
comment|///</summary>
comment|///<param name="pbstrId">The general package identifier.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|GetId
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrId
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the version of the package.
comment|///</summary>
comment|///<param name="pbstrVersion">The version of the package.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|GetVersion
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrVersion
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the target process architecture of the package.
comment|///</summary>
comment|///<param name="pbstrChip">The target process architecture of the
comment|/// package.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|GetChip
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrChip
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the language and optional region identifier.
comment|///</summary>
comment|///<param name="pbstrLanguage">The language and optional region
comment|/// identifier.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|GetLanguage
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrLanguage
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the build branch of the package.
comment|///</summary>
comment|///<param name="pbstrBranch">The build branch of the package.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|GetBranch
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrBranch
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the type of the package.
comment|///</summary>
comment|///<param name="pbstrType">The type of the package.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|GetType
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrType
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Gets the unique identifier consisting of all defined tokens.
comment|///</summary>
comment|///<param name="pbstrUniqueId">The unique identifier consisting of all
comment|/// defined tokens.</param>
comment|///<returns>Standard HRESULT indicating success or failure, including
comment|/// E_UNEXPECTED if no Id was defined (required).</returns>
name|STDMETHOD
argument_list|(
argument|GetUniqueId
argument_list|)
operator|(
name|_Out_
name|BSTR
operator|*
name|pbstrUniqueId
operator|)
operator|=
literal|0
block|; }
decl_stmt|;
endif|#
directive|endif
name|EXTERN_C
specifier|const
name|IID
name|IID_ISetupHelper
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
comment|///<summary>
comment|/// Helper functions.
comment|///</summary>
comment|///<remarks>
comment|/// You can query for this interface from the<see cref="SetupConfiguration"/>
comment|/// class.
comment|///</remarks>
name|struct
name|DECLSPEC_UUID
argument_list|(
literal|"42b21b78-6192-463e-87bf-d577838f1d5c"
argument_list|)
name|DECLSPEC_NOVTABLE
name|ISetupHelper
range|:
name|public
name|IUnknown
block|{
comment|///<summary>
comment|/// Parses a dotted quad version string into a 64-bit unsigned integer.
comment|///</summary>
comment|///<param name="pwszVersion">The dotted quad version string to parse, e.g.
comment|/// 1.2.3.4.</param>
comment|///<param name="pullVersion">A 64-bit unsigned integer representing the
comment|/// version. You can compare this to other versions.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|ParseVersion
argument_list|)
operator|(
name|_In_
name|LPCOLESTR
name|pwszVersion
expr|,
name|_Out_
name|PULONGLONG
name|pullVersion
operator|)
operator|=
literal|0
block|;
comment|///<summary>
comment|/// Parses a dotted quad version string into a 64-bit unsigned integer.
comment|///</summary>
comment|///<param name="pwszVersionRange">The string containing 1 or 2 dotted quad
comment|/// version strings to parse, e.g. [1.0,) that means 1.0.0.0 or newer.</param>
comment|///<param name="pullMinVersion">A 64-bit unsigned integer representing the
comment|/// minimum version, which may be 0. You can compare this to other
comment|/// versions.</param>
comment|///<param name="pullMaxVersion">A 64-bit unsigned integer representing the
comment|/// maximum version, which may be MAXULONGLONG. You can compare this to other
comment|/// versions.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHOD
argument_list|(
argument|ParseVersionRange
argument_list|)
operator|(
name|_In_
name|LPCOLESTR
name|pwszVersionRange
expr|,
name|_Out_
name|PULONGLONG
name|pullMinVersion
expr|,
name|_Out_
name|PULONGLONG
name|pullMaxVersion
operator|)
operator|=
literal|0
block|; }
decl_stmt|;
endif|#
directive|endif
comment|// Class declarations
comment|//
name|EXTERN_C
specifier|const
name|CLSID
name|CLSID_SetupConfiguration
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|///<summary>
comment|/// This class implements<see cref="ISetupConfiguration"/>,<see
comment|/// cref="ISetupConfiguration2"/>, and<see cref="ISetupHelper"/>.
comment|///</summary>
name|class
name|DECLSPEC_UUID
argument_list|(
literal|"177F0C4A-1CD3-4DE7-A32C-71DBBB9FA36D"
argument_list|)
name|SetupConfiguration
decl_stmt|;
endif|#
directive|endif
comment|// Function declarations
comment|//
comment|///<summary>
comment|/// Gets an<see cref="ISetupConfiguration"/> that provides information about
comment|/// product instances installed on the machine.
comment|///</summary>
comment|///<param name="ppConfiguration">The<see cref="ISetupConfiguration"/> that
comment|/// provides information about product instances installed on the
comment|/// machine.</param>
comment|///<param name="pReserved">Reserved for future use.</param>
comment|///<returns>Standard HRESULT indicating success or failure.</returns>
name|STDMETHODIMP
name|GetSetupConfiguration
parameter_list|(
name|_Out_
name|ISetupConfiguration
modifier|*
modifier|*
name|ppConfiguration
parameter_list|,
name|_Reserved_
name|LPVOID
name|pReserved
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

