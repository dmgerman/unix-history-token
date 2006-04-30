begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tasn_typ.c */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (shenson@bigfoot.com) for the OpenSSL  * project 2000.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2000 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1t.h>
end_include

begin_comment
comment|/* Declarations for string types */
end_comment

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_INTEGER
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_INTEGER
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_ENUMERATED
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_ENUMERATED
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_BIT_STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_BIT_STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_OCTET_STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_OCTET_STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_NULL
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_NULL
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_OBJECT
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_UTF8STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_UTF8STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_PRINTABLESTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_PRINTABLESTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_T61STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_T61STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_IA5STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_IA5STRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_GENERALSTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_GENERALSTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_UTCTIME
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_UTCTIME
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_GENERALIZEDTIME
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_GENERALIZEDTIME
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_VISIBLESTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_VISIBLESTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_UNIVERSALSTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_UNIVERSALSTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_BMPSTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|ASN1_BMPSTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_ANY
argument_list|)
end_macro

begin_comment
comment|/* Just swallow an ASN1_SEQUENCE in an ASN1_STRING */
end_comment

begin_macro
name|IMPLEMENT_ASN1_TYPE
argument_list|(
argument|ASN1_SEQUENCE
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS_fname
argument_list|(
argument|ASN1_TYPE
argument_list|,
argument|ASN1_ANY
argument_list|,
argument|ASN1_TYPE
argument_list|)
end_macro

begin_comment
comment|/* Multistring types */
end_comment

begin_macro
name|IMPLEMENT_ASN1_MSTRING
argument_list|(
argument|ASN1_PRINTABLE
argument_list|,
argument|B_ASN1_PRINTABLE
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS_name
argument_list|(
argument|ASN1_STRING
argument_list|,
argument|ASN1_PRINTABLE
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_MSTRING
argument_list|(
argument|DISPLAYTEXT
argument_list|,
argument|B_ASN1_DISPLAYTEXT
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS_name
argument_list|(
argument|ASN1_STRING
argument_list|,
argument|DISPLAYTEXT
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_MSTRING
argument_list|(
argument|DIRECTORYSTRING
argument_list|,
argument|B_ASN1_DIRECTORYSTRING
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_FUNCTIONS_name
argument_list|(
argument|ASN1_STRING
argument_list|,
argument|DIRECTORYSTRING
argument_list|)
end_macro

begin_comment
comment|/* Three separate BOOLEAN type: normal, DEFAULT TRUE and DEFAULT FALSE */
end_comment

begin_macro
name|IMPLEMENT_ASN1_TYPE_ex
argument_list|(
argument|ASN1_BOOLEAN
argument_list|,
argument|ASN1_BOOLEAN
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE_ex
argument_list|(
argument|ASN1_TBOOLEAN
argument_list|,
argument|ASN1_BOOLEAN
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_ASN1_TYPE_ex
argument_list|(
argument|ASN1_FBOOLEAN
argument_list|,
argument|ASN1_BOOLEAN
argument_list|,
literal|0
argument_list|)
end_macro

end_unit

