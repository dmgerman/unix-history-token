begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: esp.h,v 1.13 2000/09/26 08:37:38 itojun Exp $	*/
end_comment

begin_comment
comment|/*	$KAME: esp.h,v 1.15 2000/09/20 18:15:22 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * RFC1827/2406 Encapsulated Security Payload.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_ESP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_ESP_H_
end_define

begin_struct
struct|struct
name|esp
block|{
name|u_int32_t
name|esp_spi
decl_stmt|;
comment|/* ESP */
comment|/*variable size, 32bit bound*/
comment|/* Initialization Vector */
comment|/*variable size*/
comment|/* Payload data */
comment|/*variable size*/
comment|/* padding */
comment|/*8bit*/
comment|/* pad size */
comment|/*8bit*/
comment|/* next header */
comment|/*8bit*/
comment|/* next header */
comment|/*variable size, 32bit bound*/
comment|/* Authentication data (new IPsec) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|newesp
block|{
name|u_int32_t
name|esp_spi
decl_stmt|;
comment|/* ESP */
name|u_int32_t
name|esp_seq
decl_stmt|;
comment|/* Sequence number */
comment|/*variable size*/
comment|/* (IV and) Payload data */
comment|/*variable size*/
comment|/* padding */
comment|/*8bit*/
comment|/* pad size */
comment|/*8bit*/
comment|/* next header */
comment|/*8bit*/
comment|/* next header */
comment|/*variable size, 32bit bound*/
comment|/* Authentication data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|esptail
block|{
name|u_int8_t
name|esp_padlen
decl_stmt|;
comment|/* pad length */
name|u_int8_t
name|esp_nxt
decl_stmt|;
comment|/* Next header */
comment|/*variable size, 32bit bound*/
comment|/* Authentication data (new IPsec)*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NETINET6_ESP_H_*/
end_comment

end_unit

