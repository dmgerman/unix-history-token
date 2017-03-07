begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Transport Layer Security  -- TLS 1.0/1.1/1.2 Standard definitions, from RFC 2246/4346/5246        This file contains common TLS 1.0/1.1/1.2 definitions from RFC 2246/4346/5246     Copyright (c) 2016 - 2017, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TLS_1_H__
end_ifndef

begin_define
define|#
directive|define
name|__TLS_1_H__
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// TLS Cipher Suite, refers to A.5 of rfc-2246, rfc-4346 and rfc-5246.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_NULL_MD5
value|{0x00, 0x01}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_NULL_SHA
value|{0x00, 0x02}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_RC4_128_MD5
value|{0x00, 0x04}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_RC4_128_SHA
value|{0x00, 0x05}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_IDEA_CBC_SHA
value|{0x00, 0x07}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_DES_CBC_SHA
value|{0x00, 0x09}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_3DES_EDE_CBC_SHA
value|{0x00, 0x0A}
end_define

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_DES_CBC_SHA
value|{0x00, 0x0C}
end_define

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA
value|{0x00, 0x0D}
end_define

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_DES_CBC_SHA
value|{0x00, 0x0F}
end_define

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA
value|{0x00, 0x10}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_DES_CBC_SHA
value|{0x00, 0x12}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA
value|{0x00, 0x13}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_DES_CBC_SHA
value|{0x00, 0x15}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA
value|{0x00, 0x16}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_AES_128_CBC_SHA
value|{0x00, 0x2F}
end_define

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_AES_128_CBC_SHA
value|{0x00, 0x30}
end_define

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_AES_128_CBC_SHA
value|{0x00, 0x31}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_AES_128_CBC_SHA
value|{0x00, 0x32}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_AES_128_CBC_SHA
value|{0x00, 0x33}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_AES_256_CBC_SHA
value|{0x00, 0x35}
end_define

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_AES_256_CBC_SHA
value|{0x00, 0x36}
end_define

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_AES_256_CBC_SHA
value|{0x00, 0x37}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_AES_256_CBC_SHA
value|{0x00, 0x38}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_AES_256_CBC_SHA
value|{0x00, 0x39}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_NULL_SHA256
value|{0x00, 0x3B}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_AES_128_CBC_SHA256
value|{0x00, 0x3C}
end_define

begin_define
define|#
directive|define
name|TLS_RSA_WITH_AES_256_CBC_SHA256
value|{0x00, 0x3D}
end_define

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_AES_128_CBC_SHA256
value|{0x00, 0x3E}
end_define

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_AES_128_CBC_SHA256
value|{0x00, 0x3F}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_AES_128_CBC_SHA256
value|{0x00, 0x40}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_AES_128_CBC_SHA256
value|{0x00, 0x67}
end_define

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_AES_256_CBC_SHA256
value|{0x00, 0x68}
end_define

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_AES_256_CBC_SHA256
value|{0x00, 0x69}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_AES_256_CBC_SHA256
value|{0x00, 0x6A}
end_define

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_AES_256_CBC_SHA256
value|{0x00, 0x6B}
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TLS Version, refers to A.1 of rfc-2246, rfc-4346 and rfc-5246.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TLS10_PROTOCOL_VERSION_MAJOR
value|0x03
end_define

begin_define
define|#
directive|define
name|TLS10_PROTOCOL_VERSION_MINOR
value|0x01
end_define

begin_define
define|#
directive|define
name|TLS11_PROTOCOL_VERSION_MAJOR
value|0x03
end_define

begin_define
define|#
directive|define
name|TLS11_PROTOCOL_VERSION_MINOR
value|0x02
end_define

begin_define
define|#
directive|define
name|TLS12_PROTOCOL_VERSION_MAJOR
value|0x03
end_define

begin_define
define|#
directive|define
name|TLS12_PROTOCOL_VERSION_MINOR
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TLS Content Type, refers to A.1 of rfc-2246, rfc-4346 and rfc-5246.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TlsContentTypeChangeCipherSpec
init|=
literal|20
block|,
name|TlsContentTypeAlert
init|=
literal|21
block|,
name|TlsContentTypeHandshake
init|=
literal|22
block|,
name|TlsContentTypeApplicationData
init|=
literal|23
block|, }
name|TLS_CONTENT_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// TLS Record Header, refers to A.1 of rfc-2246, rfc-4346 and rfc-5246.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ContentType
decl_stmt|;
name|EFI_TLS_VERSION
name|Version
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|TLS_RECORD_HEADER
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

