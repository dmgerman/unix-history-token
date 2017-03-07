begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID for EFI (NVRAM) Variables.    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID defined in UEFI 2.1 **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLOBAL_VARIABLE_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__GLOBAL_VARIABLE_GUID_H__
end_define

begin_define
define|#
directive|define
name|EFI_GLOBAL_VARIABLE
define|\
value|{ \     0x8BE4DF61, 0x93CA, 0x11d2, {0xAA, 0x0D, 0x00, 0xE0, 0x98, 0x03, 0x2B, 0x8C } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiGlobalVariableGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// Follow UEFI 2.4 spec:
end_comment

begin_comment
comment|// To prevent name collisions with possible future globally defined variables,
end_comment

begin_comment
comment|// other internal firmware data variables that are not defined here must be
end_comment

begin_comment
comment|// saved with a unique VendorGuid other than EFI_GLOBAL_VARIABLE or
end_comment

begin_comment
comment|// any other GUID defined by the UEFI Specification. Implementations must
end_comment

begin_comment
comment|// only permit the creation of variables with a UEFI Specification-defined
end_comment

begin_comment
comment|// VendorGuid when these variables are documented in the UEFI Specification.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: except the globally defined variables defined below, the spec also defines
end_comment

begin_comment
comment|// L"Boot####"      - A boot load option.
end_comment

begin_comment
comment|// L"Driver####"    - A driver load option.
end_comment

begin_comment
comment|// L"SysPrep####"   - A System Prep application load option.
end_comment

begin_comment
comment|// L"Key####"       - Describes hot key relationship with a Boot#### load option.
end_comment

begin_comment
comment|// The attribute for them is NV+BS+RT, #### is a printed hex value, and no 0x or h
end_comment

begin_comment
comment|// is included in the hex value. They can not be expressed as a #define like other globally
end_comment

begin_comment
comment|// defined variables, it is because we can not list the Boot0000, Boot0001, etc one by one.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The language codes that the firmware supports. This value is deprecated.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_LANG_CODES_VARIABLE_NAME
value|L"LangCodes"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The language code that the system is configured for. This value is deprecated.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_LANG_VARIABLE_NAME
value|L"Lang"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The firmware's boot managers timeout, in seconds, before initiating the default boot selection.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_TIME_OUT_VARIABLE_NAME
value|L"Timeout"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The language codes that the firmware supports.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PLATFORM_LANG_CODES_VARIABLE_NAME
value|L"PlatformLangCodes"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The language code that the system is configured for.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PLATFORM_LANG_VARIABLE_NAME
value|L"PlatformLang"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The device path of the default input/output/error output console.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CON_IN_VARIABLE_NAME
value|L"ConIn"
end_define

begin_define
define|#
directive|define
name|EFI_CON_OUT_VARIABLE_NAME
value|L"ConOut"
end_define

begin_define
define|#
directive|define
name|EFI_ERR_OUT_VARIABLE_NAME
value|L"ErrOut"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The device path of all possible input/output/error output devices.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CON_IN_DEV_VARIABLE_NAME
value|L"ConInDev"
end_define

begin_define
define|#
directive|define
name|EFI_CON_OUT_DEV_VARIABLE_NAME
value|L"ConOutDev"
end_define

begin_define
define|#
directive|define
name|EFI_ERR_OUT_DEV_VARIABLE_NAME
value|L"ErrOutDev"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The ordered boot option load list.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_BOOT_ORDER_VARIABLE_NAME
value|L"BootOrder"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The boot option for the next boot only.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_BOOT_NEXT_VARIABLE_NAME
value|L"BootNext"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The boot option that was selected for the current boot.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_BOOT_CURRENT_VARIABLE_NAME
value|L"BootCurrent"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The types of boot options supported by the boot manager. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_BOOT_OPTION_SUPPORT_VARIABLE_NAME
value|L"BootOptionSupport"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The ordered driver load option list.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DRIVER_ORDER_VARIABLE_NAME
value|L"DriverOrder"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The ordered System Prep Application load option list.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SYS_PREP_ORDER_VARIABLE_NAME
value|L"SysPrepOrder"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Identifies the level of hardware error record persistence
end_comment

begin_comment
comment|/// support implemented by the platform. This variable is
end_comment

begin_comment
comment|/// only modified by firmware and is read-only to the OS.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_HW_ERR_REC_SUPPORT_VARIABLE_NAME
value|L"HwErrRecSupport"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Whether the system is operating in setup mode (1) or not (0).
end_comment

begin_comment
comment|/// All other values are reserved. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SETUP_MODE_NAME
value|L"SetupMode"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Key Exchange Key Signature Database.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT+AT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_KEY_EXCHANGE_KEY_NAME
value|L"KEK"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The public Platform Key.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT+AT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PLATFORM_KEY_NAME
value|L"PK"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Array of GUIDs representing the type of signatures supported
end_comment

begin_comment
comment|/// by the platform firmware. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SIGNATURE_SUPPORT_NAME
value|L"SignatureSupport"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Whether the platform firmware is operating in Secure boot mode (1) or not (0).
end_comment

begin_comment
comment|/// All other values are reserved. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SECURE_BOOT_MODE_NAME
value|L"SecureBoot"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The OEM's default Key Exchange Key Signature Database. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_KEK_DEFAULT_VARIABLE_NAME
value|L"KEKDefault"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The OEM's default public Platform Key. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PK_DEFAULT_VARIABLE_NAME
value|L"PKDefault"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The OEM's default secure boot signature store. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DB_DEFAULT_VARIABLE_NAME
value|L"dbDefault"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The OEM's default secure boot blacklist signature store. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DBX_DEFAULT_VARIABLE_NAME
value|L"dbxDefault"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The OEM's default secure boot timestamp signature store. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DBT_DEFAULT_VARIABLE_NAME
value|L"dbtDefault"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Allows the firmware to indicate supported features and actions to the OS.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_OS_INDICATIONS_SUPPORT_VARIABLE_NAME
value|L"OsIndicationsSupported"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Allows the OS to request the firmware to enable certain features and to take certain actions.
end_comment

begin_comment
comment|/// Its attribute is NV+BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_OS_INDICATIONS_VARIABLE_NAME
value|L"OsIndications"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Whether the system is configured to use only vendor provided
end_comment

begin_comment
comment|/// keys or not. Should be treated as read-only.
end_comment

begin_comment
comment|/// Its attribute is BS+RT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_VENDOR_KEYS_VARIABLE_NAME
value|L"VendorKeys"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

