begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Edward Tomasz Napierala under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * This file contains Authenticode-specific ASN.1 "configuration", used,  * after being processed by asprintf(3), as an input to ASN1_generate_nconf(3).  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|magic_fmt
init|=
literal|"asn1 = SEQUENCE:SpcIndirectDataContent\n"
literal|"\n"
literal|"[SpcIndirectDataContent]\n"
literal|"a = SEQUENCE:SpcAttributeTypeAndOptionalValue\n"
literal|"b = SEQUENCE:DigestInfo\n"
literal|"\n"
literal|"[SpcAttributeTypeAndOptionalValue]\n"
literal|"# SPC_PE_IMAGE_DATAOBJ\n"
literal|"a = OID:1.3.6.1.4.1.311.2.1.15\n"
literal|"b = SEQUENCE:SpcPeImageData\n"
literal|"\n"
literal|"[SpcPeImageData]\n"
literal|"a = FORMAT:HEX,BITSTRING:00\n"
comment|/*  * Well, there should be some other struct here, "SPCLink", but it doesn't  * appear to be neccessary for UEFI, and I have no idea how to synthesize it,  * as it uses the CHOICE type.  */
literal|"\n"
literal|"[DigestInfo]\n"
literal|"a = SEQUENCE:AlgorithmIdentifier\n"
comment|/*  * Here goes the digest computed from PE headers and sections.  */
literal|"b = FORMAT:HEX,OCTETSTRING:%s\n"
literal|"\n"
literal|"[AlgorithmIdentifier]\n"
literal|"a = OBJECT:sha256\n"
literal|"b = NULL\n"
decl_stmt|;
end_decl_stmt

end_unit

