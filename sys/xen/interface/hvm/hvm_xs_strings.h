begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * hvm/hvm_xs_strings.h  *  * HVM xenstore strings used in HVMLOADER.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2013, Citrix Systems  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_HVM_XS_STRINGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_HVM_XS_STRINGS_H__
end_define

begin_define
define|#
directive|define
name|HVM_XS_HVMLOADER
value|"hvmloader"
end_define

begin_define
define|#
directive|define
name|HVM_XS_BIOS
value|"hvmloader/bios"
end_define

begin_define
define|#
directive|define
name|HVM_XS_GENERATION_ID_ADDRESS
value|"hvmloader/generation-id-address"
end_define

begin_define
define|#
directive|define
name|HVM_XS_ALLOW_MEMORY_RELOCATE
value|"hvmloader/allow-memory-relocate"
end_define

begin_comment
comment|/* The following values allow additional ACPI tables to be added to the  * virtual ACPI BIOS that hvmloader constructs. The values specify the guest  * physical address and length of a block of ACPI tables to add. The format of  * the block is simply concatenated raw tables (which specify their own length  * in the ACPI header).  */
end_comment

begin_define
define|#
directive|define
name|HVM_XS_ACPI_PT_ADDRESS
value|"hvmloader/acpi/address"
end_define

begin_define
define|#
directive|define
name|HVM_XS_ACPI_PT_LENGTH
value|"hvmloader/acpi/length"
end_define

begin_comment
comment|/* Any number of SMBIOS types can be passed through to an HVM guest using  * the following xenstore values. The values specify the guest physical  * address and length of a block of SMBIOS structures for hvmloader to use.  * The block is formatted in the following way:  *  *<length><struct><length><struct>...  *  * Each length separator is a 32b integer indicating the length of the next  * SMBIOS structure. For DMTF defined types (0 - 121), the passed in struct  * will replace the default structure in hvmloader. In addition, any  * OEM/vendortypes (128 - 255) will all be added.  */
end_comment

begin_define
define|#
directive|define
name|HVM_XS_SMBIOS_PT_ADDRESS
value|"hvmloader/smbios/address"
end_define

begin_define
define|#
directive|define
name|HVM_XS_SMBIOS_PT_LENGTH
value|"hvmloader/smbios/length"
end_define

begin_comment
comment|/* Set to 1 to enable SMBIOS default portable battery (type 22) values. */
end_comment

begin_define
define|#
directive|define
name|HVM_XS_SMBIOS_DEFAULT_BATTERY
value|"hvmloader/smbios/default_battery"
end_define

begin_comment
comment|/* The following xenstore values are used to override some of the default  * string values in the SMBIOS table constructed in hvmloader.  */
end_comment

begin_define
define|#
directive|define
name|HVM_XS_BIOS_STRINGS
value|"bios-strings"
end_define

begin_define
define|#
directive|define
name|HVM_XS_BIOS_VENDOR
value|"bios-strings/bios-vendor"
end_define

begin_define
define|#
directive|define
name|HVM_XS_BIOS_VERSION
value|"bios-strings/bios-version"
end_define

begin_define
define|#
directive|define
name|HVM_XS_SYSTEM_MANUFACTURER
value|"bios-strings/system-manufacturer"
end_define

begin_define
define|#
directive|define
name|HVM_XS_SYSTEM_PRODUCT_NAME
value|"bios-strings/system-product-name"
end_define

begin_define
define|#
directive|define
name|HVM_XS_SYSTEM_VERSION
value|"bios-strings/system-version"
end_define

begin_define
define|#
directive|define
name|HVM_XS_SYSTEM_SERIAL_NUMBER
value|"bios-strings/system-serial-number"
end_define

begin_define
define|#
directive|define
name|HVM_XS_ENCLOSURE_MANUFACTURER
value|"bios-strings/enclosure-manufacturer"
end_define

begin_define
define|#
directive|define
name|HVM_XS_ENCLOSURE_SERIAL_NUMBER
value|"bios-strings/enclosure-serial-number"
end_define

begin_define
define|#
directive|define
name|HVM_XS_BATTERY_MANUFACTURER
value|"bios-strings/battery-manufacturer"
end_define

begin_define
define|#
directive|define
name|HVM_XS_BATTERY_DEVICE_NAME
value|"bios-strings/battery-device-name"
end_define

begin_comment
comment|/* 1 to 99 OEM strings can be set in xenstore using values of the form  * below. These strings will be loaded into the SMBIOS type 11 structure.  */
end_comment

begin_define
define|#
directive|define
name|HVM_XS_OEM_STRINGS
value|"bios-strings/oem-%d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_HVM_XS_STRINGS_H__ */
end_comment

end_unit

