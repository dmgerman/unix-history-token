begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usb.h,v 1.8 2000/08/13 22:22:02 augustss Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1999 Lennart Augustsson<augustss@netbsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|report_desc
modifier|*
name|report_desc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hid_data
modifier|*
name|hid_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|hid_kind
block|{
name|hid_input
block|,
name|hid_output
block|,
name|hid_feature
block|,
name|hid_collection
block|,
name|hid_endcollection
block|}
name|hid_kind_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hid_item
block|{
comment|/* Global */
name|int
name|_usage_page
decl_stmt|;
name|int
name|logical_minimum
decl_stmt|;
name|int
name|logical_maximum
decl_stmt|;
name|int
name|physical_minimum
decl_stmt|;
name|int
name|physical_maximum
decl_stmt|;
name|int
name|unit_exponent
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|int
name|report_size
decl_stmt|;
name|int
name|report_ID
decl_stmt|;
define|#
directive|define
name|NO_REPORT_ID
value|0
name|int
name|report_count
decl_stmt|;
comment|/* Local */
name|unsigned
name|int
name|usage
decl_stmt|;
name|int
name|usage_minimum
decl_stmt|;
name|int
name|usage_maximum
decl_stmt|;
name|int
name|designator_index
decl_stmt|;
name|int
name|designator_minimum
decl_stmt|;
name|int
name|designator_maximum
decl_stmt|;
name|int
name|string_index
decl_stmt|;
name|int
name|string_minimum
decl_stmt|;
name|int
name|string_maximum
decl_stmt|;
name|int
name|set_delimiter
decl_stmt|;
comment|/* Misc */
name|int
name|collection
decl_stmt|;
name|int
name|collevel
decl_stmt|;
name|enum
name|hid_kind
name|kind
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* Absolute data position (bits) */
name|unsigned
name|int
name|pos
decl_stmt|;
comment|/* */
name|struct
name|hid_item
modifier|*
name|next
decl_stmt|;
block|}
name|hid_item_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HID_PAGE
parameter_list|(
name|u
parameter_list|)
value|(((u)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|HID_USAGE
parameter_list|(
name|u
parameter_list|)
value|((u)& 0xffff)
end_define

begin_comment
comment|/* Obtaining a report descriptor, descr.c: */
end_comment

begin_function_decl
name|report_desc_t
name|hid_get_report_desc
parameter_list|(
name|int
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|report_desc_t
name|hid_use_report_desc
parameter_list|(
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hid_dispose_report_desc
parameter_list|(
name|report_desc_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parsing of a HID report descriptor, parse.c: */
end_comment

begin_function_decl
name|hid_data_t
name|hid_start_parse
parameter_list|(
name|report_desc_t
name|d
parameter_list|,
name|int
name|kindset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hid_end_parse
parameter_list|(
name|hid_data_t
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_get_item
parameter_list|(
name|hid_data_t
name|s
parameter_list|,
name|hid_item_t
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_report_size
parameter_list|(
name|report_desc_t
name|d
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|,
name|enum
name|hid_kind
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_locate
parameter_list|(
name|report_desc_t
name|d
parameter_list|,
name|unsigned
name|int
name|usage
parameter_list|,
name|enum
name|hid_kind
name|k
parameter_list|,
name|hid_item_t
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Conversion to/from usage names, usage.c: */
end_comment

begin_function_decl
name|int
name|hid_parse_usage_page
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_parse_usage_in_page
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|hid_usage_page
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|hid_usage_in_page
parameter_list|(
name|unsigned
name|int
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hid_init
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extracting/insertion of data, data.c: */
end_comment

begin_function_decl
name|int
name|hid_get_data
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|,
specifier|const
name|hid_item_t
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hid_set_data
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
specifier|const
name|hid_item_t
modifier|*
name|h
parameter_list|,
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

end_unit

