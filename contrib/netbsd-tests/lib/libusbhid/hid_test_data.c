begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: hid_test_data.c,v 1.2 2016/01/07 15:58:23 jakllsch Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2016 Jonathan A. Kollasch  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|range_test_report_descriptor
index|[]
init|=
block|{
literal|0x0b
block|,
literal|0x03
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
comment|// Usage
literal|0x75
block|,
literal|0x20
block|,
comment|// Report Size
literal|0x95
block|,
literal|0x01
block|,
comment|// Report Count
literal|0x17
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x80
block|,
comment|// Logical Minimum
literal|0x27
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x7f
block|,
comment|// Logical Maximum
literal|0x37
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x80
block|,
comment|// Physical Minimum
literal|0x47
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x7f
block|,
comment|// Physical Maximum
literal|0x81
block|,
literal|0x00
block|,
comment|// Input
literal|0x0b
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
comment|// Usage
literal|0x75
block|,
literal|0x10
block|,
comment|// Report Size
literal|0x95
block|,
literal|0x01
block|,
comment|// Report Count
literal|0x16
block|,
literal|0x00
block|,
literal|0x80
block|,
comment|// Logical Minimum
literal|0x26
block|,
literal|0xff
block|,
literal|0x7f
block|,
comment|// Logical Maximum
literal|0x36
block|,
literal|0x00
block|,
literal|0x80
block|,
comment|// Physical Minimum
literal|0x46
block|,
literal|0xff
block|,
literal|0x7f
block|,
comment|// Physical Maximum
literal|0x81
block|,
literal|0x00
block|,
comment|// Input
literal|0x0b
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
comment|// Usage
literal|0x75
block|,
literal|0x08
block|,
comment|// Report Size
literal|0x95
block|,
literal|0x01
block|,
comment|// Report Count
literal|0x15
block|,
literal|0x80
block|,
comment|// Logical Minimum
literal|0x25
block|,
literal|0x7f
block|,
comment|// Logical Maximum
literal|0x35
block|,
literal|0x80
block|,
comment|// Physical Minimum
literal|0x45
block|,
literal|0x7f
block|,
comment|// Physical Maximum
literal|0x81
block|,
literal|0x00
block|,
comment|// Input
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|range_test_minimum_report
index|[
literal|7
index|]
init|=
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x80
block|,
literal|0x00
block|,
literal|0x80
block|,
literal|0x80
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|range_test_negative_one_report
index|[
literal|7
index|]
init|=
block|{
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|range_test_positive_one_report
index|[
literal|7
index|]
init|=
block|{
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x01
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|range_test_maximum_report
index|[
literal|7
index|]
init|=
block|{
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x7f
block|,
literal|0xff
block|,
literal|0x7f
block|,
literal|0x7f
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|unsigned_range_test_report_descriptor
index|[]
init|=
block|{
literal|0x0b
block|,
literal|0x13
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
comment|// Usage
literal|0x75
block|,
literal|0x20
block|,
comment|// Report Size
literal|0x95
block|,
literal|0x01
block|,
comment|// Report Count
literal|0x17
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// Logical Minimum
literal|0x27
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
comment|// Logical Maximum
literal|0x37
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// Physical Minimum
literal|0x47
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
comment|// Physical Maximum
literal|0x81
block|,
literal|0x00
block|,
comment|// Input
literal|0x0b
block|,
literal|0x12
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
comment|// Usage
literal|0x75
block|,
literal|0x10
block|,
comment|// Report Size
literal|0x95
block|,
literal|0x01
block|,
comment|// Report Count
literal|0x16
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// Logical Minimum
literal|0x26
block|,
literal|0xff
block|,
literal|0xff
block|,
comment|// Logical Maximum
literal|0x36
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// Physical Minimum
literal|0x46
block|,
literal|0xff
block|,
literal|0xff
block|,
comment|// Physical Maximum
literal|0x81
block|,
literal|0x00
block|,
comment|// Input
literal|0x0b
block|,
literal|0x11
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
comment|// Usage
literal|0x75
block|,
literal|0x08
block|,
comment|// Report Size
literal|0x95
block|,
literal|0x01
block|,
comment|// Report Count
literal|0x15
block|,
literal|0x00
block|,
comment|// Logical Minimum
literal|0x25
block|,
literal|0xff
block|,
comment|// Logical Maximum
literal|0x35
block|,
literal|0x00
block|,
comment|// Physical Minimum
literal|0x45
block|,
literal|0xff
block|,
comment|// Physical Maximum
literal|0x81
block|,
literal|0x00
block|,
comment|// Input
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|unsigned_range_test_minimum_report
index|[
literal|7
index|]
init|=
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|unsigned_range_test_positive_one_report
index|[
literal|7
index|]
init|=
block|{
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x01
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|unsigned_range_test_negative_one_report
index|[
literal|7
index|]
init|=
block|{
literal|0xfe
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0xfe
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|unsigned_range_test_maximum_report
index|[
literal|7
index|]
init|=
block|{
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|just_pop_report_descriptor
index|[]
init|=
block|{
literal|0xb4
block|, }
decl_stmt|;
end_decl_stmt

end_unit

