begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2004 The Aerospace Corporation.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions, and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions, and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  The name of The Aerospace Corporation may not be used to endorse or  *     promote products derived from this software.  *  * THIS SOFTWARE IS PROVIDED BY THE AEROSPACE CORPORATION "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AEROSPACE CORPORATION BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEST_EUI64_H
end_ifndef

begin_define
define|#
directive|define
name|_TEST_EUI64_H
end_define

begin_decl_stmt
name|struct
name|eui64
name|test_eui64_id
init|=
block|{
block|{
literal|0x00
block|,
literal|0x11
block|,
literal|0x22
block|,
literal|0x33
block|,
literal|0x44
block|,
literal|0x55
block|,
literal|0x66
block|,
literal|0x77
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|eui64
name|test_eui64_eui48
init|=
block|{
block|{
literal|0x00
block|,
literal|0x11
block|,
literal|0x22
block|,
literal|0xFF
block|,
literal|0xFE
block|,
literal|0x33
block|,
literal|0x44
block|,
literal|0x55
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|eui64
name|test_eui64_mac48
init|=
block|{
block|{
literal|0x00
block|,
literal|0x11
block|,
literal|0x22
block|,
literal|0xFF
block|,
literal|0xFF
block|,
literal|0x33
block|,
literal|0x44
block|,
literal|0x55
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|test_eui64_id_ascii
value|"00-11-22-33-44-55-66-77"
end_define

begin_define
define|#
directive|define
name|test_eui64_id_colon_ascii
value|"00:11:22:33:44:55:66:77"
end_define

begin_define
define|#
directive|define
name|test_eui64_hex_ascii
value|"0x0011223344556677"
end_define

begin_define
define|#
directive|define
name|test_eui64_eui48_ascii
value|"00-11-22-ff-fe-33-44-55"
end_define

begin_define
define|#
directive|define
name|test_eui64_mac48_ascii
value|"00-11-22-ff-fe-33-44-55"
end_define

begin_define
define|#
directive|define
name|test_eui64_mac_ascii
value|"00-11-22-33-44-55"
end_define

begin_define
define|#
directive|define
name|test_eui64_mac_colon_ascii
value|"00:11:22:33:44:55"
end_define

begin_define
define|#
directive|define
name|test_eui64_id_host
value|"id"
end_define

begin_define
define|#
directive|define
name|test_eui64_eui48_host
value|"eui-48"
end_define

begin_define
define|#
directive|define
name|test_eui64_mac48_host
value|"mac-48"
end_define

begin_define
define|#
directive|define
name|test_eui64_line_id
value|"00-11-22-33-44-55-66-77 id"
end_define

begin_define
define|#
directive|define
name|test_eui64_line_id_colon
value|"00:11:22:33:44:55:66:77  id"
end_define

begin_define
define|#
directive|define
name|test_eui64_line_eui48
value|"00-11-22-FF-fe-33-44-55	eui-48"
end_define

begin_define
define|#
directive|define
name|test_eui64_line_mac48
value|"00-11-22-FF-ff-33-44-55	 mac-48"
end_define

begin_define
define|#
directive|define
name|test_eui64_line_eui48_6byte
value|"00-11-22-33-44-55 eui-48"
end_define

begin_define
define|#
directive|define
name|test_eui64_line_eui48_6byte_c
value|"00:11:22:33:44:55 eui-48"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TEST_EUI64_H */
end_comment

end_unit

