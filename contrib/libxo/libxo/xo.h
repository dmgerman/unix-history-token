begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014, Juniper Networks, Inc.  * All rights reserved.  * This SOFTWARE is licensed under the LICENSE provided in the  * ../Copyright file. By downloading, installing, copying, or otherwise  * using the SOFTWARE, you agree to be bound by the terms of that  * LICENSE.  * Phil Shafer, July 2014  */
end_comment

begin_comment
comment|/**  * libxo provides a means of generating text, XML, and JSON output  * using a single set of function calls, maximizing the value of output  * while minimizing the cost/impact on the code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDE_XO_H
end_ifndef

begin_define
define|#
directive|define
name|INCLUDE_XO_H
end_define

begin_comment
comment|/** Formatting types */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|xo_style_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XO_STYLE_TEXT
value|0
end_define

begin_comment
comment|/** Generate text output */
end_comment

begin_define
define|#
directive|define
name|XO_STYLE_XML
value|1
end_define

begin_comment
comment|/** Generate XML output */
end_comment

begin_define
define|#
directive|define
name|XO_STYLE_JSON
value|2
end_define

begin_comment
comment|/** Generate JSON output */
end_comment

begin_define
define|#
directive|define
name|XO_STYLE_HTML
value|3
end_define

begin_comment
comment|/** Generate HTML output */
end_comment

begin_comment
comment|/** Flags for libxo */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|xo_xof_flags_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XOF_BIT
parameter_list|(
name|_n
parameter_list|)
value|((xo_xof_flags_t) 1<< (_n))
end_define

begin_define
define|#
directive|define
name|XOF_CLOSE_FP
value|XOF_BIT(0)
end_define

begin_comment
comment|/** Close file pointer on xo_close() */
end_comment

begin_define
define|#
directive|define
name|XOF_PRETTY
value|XOF_BIT(1)
end_define

begin_comment
comment|/** Make 'pretty printed' output */
end_comment

begin_define
define|#
directive|define
name|XOF_DIV_OPEN
value|XOF_BIT(2)
end_define

begin_comment
comment|/** Internal use only: a<div> is open */
end_comment

begin_define
define|#
directive|define
name|XOF_LINE_OPEN
value|XOF_BIT(3)
end_define

begin_comment
comment|/** Internal use only:<div class="line"> */
end_comment

begin_define
define|#
directive|define
name|XOF_WARN
value|XOF_BIT(4)
end_define

begin_comment
comment|/** Generate warnings for broken calls */
end_comment

begin_define
define|#
directive|define
name|XOF_XPATH
value|XOF_BIT(5)
end_define

begin_comment
comment|/** Emit XPath attributes in HTML  */
end_comment

begin_define
define|#
directive|define
name|XOF_INFO
value|XOF_BIT(6)
end_define

begin_comment
comment|/** Emit additional info fields (HTML) */
end_comment

begin_define
define|#
directive|define
name|XOF_WARN_XML
value|XOF_BIT(7)
end_define

begin_comment
comment|/** Emit warnings in XML (on stdout) */
end_comment

begin_define
define|#
directive|define
name|XOF_NO_ENV
value|XOF_BIT(8)
end_define

begin_comment
comment|/** Don't look at LIBXO_OPTIONS env var */
end_comment

begin_define
define|#
directive|define
name|XOF_NO_VA_ARG
value|XOF_BIT(9)
end_define

begin_comment
comment|/** Don't advance va_list w/ va_arg() */
end_comment

begin_define
define|#
directive|define
name|XOF_DTRT
value|XOF_BIT(10)
end_define

begin_comment
comment|/** Enable "do the right thing" mode */
end_comment

begin_define
define|#
directive|define
name|XOF_KEYS
value|XOF_BIT(11)
end_define

begin_comment
comment|/** Flag 'key' fields for xml and json */
end_comment

begin_define
define|#
directive|define
name|XOF_IGNORE_CLOSE
value|XOF_BIT(12)
end_define

begin_comment
comment|/** Ignore errors on close tags */
end_comment

begin_define
define|#
directive|define
name|XOF_NOT_FIRST
value|XOF_BIT(13)
end_define

begin_comment
comment|/* Not the first item (JSON)  */
end_comment

begin_define
define|#
directive|define
name|XOF_NO_LOCALE
value|XOF_BIT(14)
end_define

begin_comment
comment|/** Don't bother with locale */
end_comment

begin_define
define|#
directive|define
name|XOF_TOP_EMITTED
value|XOF_BIT(15)
end_define

begin_comment
comment|/* The top JSON braces have been emitted  */
end_comment

begin_define
define|#
directive|define
name|XOF_NO_TOP
value|XOF_BIT(16)
end_define

begin_comment
comment|/** Don't emit the top braces in JSON */
end_comment

begin_define
define|#
directive|define
name|XOF_ANCHOR
value|XOF_BIT(17)
end_define

begin_comment
comment|/** An anchor is in place  */
end_comment

begin_define
define|#
directive|define
name|XOF_UNITS
value|XOF_BIT(18)
end_define

begin_comment
comment|/** Encode units in XML */
end_comment

begin_define
define|#
directive|define
name|XOF_UNITS_PENDING
value|XOF_BIT(19)
end_define

begin_comment
comment|/** We have a units-insertion pending */
end_comment

begin_define
define|#
directive|define
name|XOF_UNDERSCORES
value|XOF_BIT(20)
end_define

begin_comment
comment|/** Replace dashes with underscores (JSON)*/
end_comment

begin_define
define|#
directive|define
name|XOF_COLUMNS
value|XOF_BIT(21)
end_define

begin_comment
comment|/** xo_emit should return a column count */
end_comment

begin_define
define|#
directive|define
name|XOF_FLUSH
value|XOF_BIT(22)
end_define

begin_comment
comment|/** Flush after each xo_emit call */
end_comment

begin_define
define|#
directive|define
name|XOF_FLUSH_LINE
value|XOF_BIT(23)
end_define

begin_comment
comment|/** Flush after each newline */
end_comment

begin_define
define|#
directive|define
name|XOF_NO_CLOSE
value|XOF_BIT(24)
end_define

begin_comment
comment|/** xo_finish won't close open elements */
end_comment

begin_comment
comment|/*  * The xo_info_t structure provides a mapping between names and  * additional data emitted via HTML.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xo_info_s
block|{
specifier|const
name|char
modifier|*
name|xi_name
decl_stmt|;
comment|/* Name of the element */
specifier|const
name|char
modifier|*
name|xi_type
decl_stmt|;
comment|/* Type of field */
specifier|const
name|char
modifier|*
name|xi_help
decl_stmt|;
comment|/* Description of field */
block|}
name|xo_info_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|xo_handle_s
struct_decl|;
end_struct_decl

begin_comment
comment|/* Opaque structure forward */
end_comment

begin_typedef
typedef|typedef
name|struct
name|xo_handle_s
name|xo_handle_t
typedef|;
end_typedef

begin_comment
comment|/* Handle for XO output */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xo_write_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xo_close_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xo_flush_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|xo_realloc_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xo_free_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The formatter function mirrors "vsnprintf", with an additional argument  * of the xo handle.  The caller should return the number of bytes _needed_  * to fit the data, even if this exceeds 'len'.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xo_formatter_t
function_decl|)
parameter_list|(
name|xo_handle_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xo_checkpointer_t
function_decl|)
parameter_list|(
name|xo_handle_t
modifier|*
parameter_list|,
name|va_list
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|xo_handle_t
modifier|*
name|xo_create
parameter_list|(
name|xo_style_t
name|style
parameter_list|,
name|xo_xof_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_handle_t
modifier|*
name|xo_create_to_file
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|xo_style_t
name|style
parameter_list|,
name|xo_xof_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_destroy
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_writer
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|void
modifier|*
name|opaque
parameter_list|,
name|xo_write_func_t
name|write_func
parameter_list|,
name|xo_close_func_t
name|close_func
parameter_list|,
name|xo_flush_func_t
name|flush_func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_allocator
parameter_list|(
name|xo_realloc_func_t
name|realloc_func
parameter_list|,
name|xo_free_func_t
name|free_func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_style
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_style_t
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_style_t
name|xo_get_style
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_set_style_name
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_set_options
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|input
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_xof_flags_t
name|xo_get_flags
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_flags
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_xof_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_clear_flags
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_xof_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_info
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_info_t
modifier|*
name|infop
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_formatter
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_formatter_t
name|func
parameter_list|,
name|xo_checkpointer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_depth
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|int
name|depth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_emit_hv
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_emit_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_emit
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_container_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_container
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
name|xo_open_container_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_container_d
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
name|xo_close_container_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_close_container
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
name|xo_close_container_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_close_container_d
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_list_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_list
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
name|xo_open_list_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_list_d
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
name|xo_close_list_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_close_list
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
name|xo_close_list_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_close_list_d
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_instance_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_instance
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
name|xo_open_instance_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_instance_d
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
name|xo_close_instance_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_close_instance
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
name|xo_close_instance_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_close_instance_d
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_marker_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_open_marker
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
name|xo_close_marker_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_close_marker
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
name|xo_attr_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_attr_hv
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_attr
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_error_hv
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_error_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_flush_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_finish_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_leading_xpath
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_warn_hc
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_warn_c
parameter_list|(
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_warn
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_warnx
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_err
parameter_list|(
name|int
name|eval
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_errx
parameter_list|(
name|int
name|eval
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_errc
parameter_list|(
name|int
name|eval
parameter_list|,
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_message_hcv
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_message_hc
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_message_c
parameter_list|(
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_message
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_no_setlocale
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_parse_args
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This is the "magic" number returned by libxo-supporting commands  * when passed the equally magic "--libxo-check" option.  If you  * return this, we can assume that since you know the magic handshake,  * you'll happily handle future --libxo options and not do something  * violent like reboot the box or create another hole in the ozone  * layer.  */
end_comment

begin_define
define|#
directive|define
name|XO_HAS_LIBXO
value|121
end_define

begin_comment
comment|/*  * externs for our version number strings  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|xo_version
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|xo_version_extra
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|xo_dump_stack
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_program
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INCLUDE_XO_H */
end_comment

end_unit

