begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014-2015, Juniper Networks, Inc.  * All rights reserved.  * This SOFTWARE is licensed under the LICENSE provided in the  * ../Copyright file. By downloading, installing, copying, or otherwise  * using the SOFTWARE, you agree to be bound by the terms of that  * LICENSE.  * Phil Shafer, July 2014  */
end_comment

begin_comment
comment|/**  * libxo provides a means of generating text, XML, JSON, and HTML output  * using a single set of function calls, maximizing the value of output  * while minimizing the cost/impact on the code.  *  * Full documentation is available in ./doc/libxo.txt or online at:  *   http://juniper.github.io/libxo/libxo-manual.html  */
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__dead2
end_ifdef

begin_define
define|#
directive|define
name|NORETURN
value|__dead2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NORETURN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __dead2 */
end_comment

begin_comment
comment|/*  * Normally we'd use the HAVE_PRINTFLIKE define triggered by the  * --enable-printflike option to configure, but we don't install  * our internal "xoconfig.h", and I'd rather not.  Taking the  * coward's path, we'll turn it on inside a #if that allows  * others to turn it off where needed.  Not ideal, but functional.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_PRINTFLIKE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__printflike
argument_list|)
end_if

begin_define
define|#
directive|define
name|__printflike
parameter_list|(
name|_x
parameter_list|,
name|_y
parameter_list|)
value|__attribute__((__format__ (__printf__, _x, _y)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PRINTFLIKE
parameter_list|(
name|_x
parameter_list|,
name|_y
parameter_list|)
value|__printflike(_x, _y)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRINTFLIKE
parameter_list|(
name|_x
parameter_list|,
name|_y
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_PRINTFLIKE */
end_comment

begin_comment
comment|/** Formatting types */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
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

begin_define
define|#
directive|define
name|XO_STYLE_SDPARAMS
value|4
end_define

begin_comment
comment|/* Generate syslog structured data params */
end_comment

begin_define
define|#
directive|define
name|XO_STYLE_ENCODER
value|5
end_define

begin_comment
comment|/* Generate calls to external encoder */
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
name|XOF_LOG_SYSLOG
value|XOF_BIT(2)
end_define

begin_comment
comment|/** Log (on stderr) our syslog content */
end_comment

begin_define
define|#
directive|define
name|XOF_RESV3
value|XOF_BIT(3)
end_define

begin_comment
comment|/* Unused */
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
name|XOF_RESV15
value|XOF_BIT(15)
end_define

begin_comment
comment|/* Unused */
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
name|XOF_RESV17
value|XOF_BIT(17)
end_define

begin_comment
comment|/* Unused  */
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
name|XOF_RESV19
value|XOF_BIT(19)
end_define

begin_comment
comment|/* Unused */
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

begin_define
define|#
directive|define
name|XOF_COLOR_ALLOWED
value|XOF_BIT(25)
end_define

begin_comment
comment|/** Allow color/effects to be enabled */
end_comment

begin_define
define|#
directive|define
name|XOF_COLOR
value|XOF_BIT(26)
end_define

begin_comment
comment|/** Enable color and effects */
end_comment

begin_define
define|#
directive|define
name|XOF_NO_HUMANIZE
value|XOF_BIT(27)
end_define

begin_comment
comment|/** Block the {h:} modifier */
end_comment

begin_define
define|#
directive|define
name|XOF_LOG_GETTEXT
value|XOF_BIT(28)
end_define

begin_comment
comment|/** Log (stderr) gettext lookup strings */
end_comment

begin_define
define|#
directive|define
name|XOF_UTF8
value|XOF_BIT(29)
end_define

begin_comment
comment|/** Force text output to be UTF8 */
end_comment

begin_define
define|#
directive|define
name|XOF_RETAIN_ALL
value|XOF_BIT(30)
end_define

begin_comment
comment|/** Force use of XOEF_RETAIN */
end_comment

begin_define
define|#
directive|define
name|XOF_RETAIN_NONE
value|XOF_BIT(31)
end_define

begin_comment
comment|/** Prevent use of XOEF_RETAIN */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|xo_emit_flags_t
typedef|;
end_typedef

begin_comment
comment|/* Flags to xo_emit() and friends */
end_comment

begin_define
define|#
directive|define
name|XOEF_RETAIN
value|(1<<0)
end_define

begin_comment
comment|/* Retain parsed formatting information */
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

begin_define
define|#
directive|define
name|XO_INFO_NULL
value|NULL, NULL, NULL
end_define

begin_comment
comment|/* Use '{ XO_INFO_NULL }' to end lists */
end_comment

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

begin_comment
comment|/*  * Early versions of the API used "int" instead of "size_t" for buffer  * sizes.  We want to fix this but allow for backwards compatibility  * where needed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_INT_RETURN_CODES
end_ifdef

begin_typedef
typedef|typedef
name|int
name|xo_ssize_t
typedef|;
end_typedef

begin_comment
comment|/* Buffer size */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_INT_RETURN_CODES */
end_comment

begin_typedef
typedef|typedef
name|ssize_t
name|xo_ssize_t
typedef|;
end_typedef

begin_comment
comment|/* Buffer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_INT_RETURN_CODES */
end_comment

begin_typedef
typedef|typedef
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|int
name|xo_set_file_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_set_file
parameter_list|(
name|FILE
modifier|*
name|fp
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
name|xo_emit_hvf
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_emit_flags_t
name|flags
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
name|xo_ssize_t
name|xo_emit_hf
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_emit_flags_t
name|flags
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
name|xo_ssize_t
name|xo_emit_f
parameter_list|(
name|xo_emit_flags_t
name|flags
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

begin_macro
name|PRINTFLIKE
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|int
name|xo_emit_hvp
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
block|{
return|return
name|xo_emit_hv
argument_list|(
name|xop
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
return|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|int
name|xo_emit_hp
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
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|int
name|rc
init|=
name|xo_emit_hv
argument_list|(
name|xop
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
return|return
name|rc
return|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|int
name|xo_emit_p
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|int
name|rc
init|=
name|xo_emit_hv
argument_list|(
name|NULL
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
return|return
name|rc
return|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|int
name|xo_emit_hvfp
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_emit_flags_t
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|vap
parameter_list|)
block|{
return|return
name|xo_emit_hvf
argument_list|(
name|xop
argument_list|,
name|flags
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
return|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|int
name|xo_emit_hfp
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_emit_flags_t
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|int
name|rc
init|=
name|xo_emit_hvf
argument_list|(
name|xop
argument_list|,
name|flags
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
return|return
name|rc
return|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|int
name|xo_emit_fp
parameter_list|(
name|xo_emit_flags_t
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|int
name|rc
init|=
name|xo_emit_hvf
argument_list|(
name|NULL
argument_list|,
name|flags
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
return|return
name|rc
return|;
block|}
end_function

begin_function_decl
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
name|xo_close_container_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_close_container_d
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
name|xo_close_list_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_close_list_d
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
name|xo_close_instance_hd
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_close_instance_d
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
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
name|xo_ssize_t
name|xo_flush_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_finish_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_finish_atexit
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
function_decl|PRINTFLIKE
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
function_decl|PRINTFLIKE
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
function_decl|PRINTFLIKE
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
function_decl|PRINTFLIKE
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|xo_err
argument_list|(
name|int
name|eval
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|NORETURN
name|PRINTFLIKE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|xo_errx
argument_list|(
name|int
name|eval
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|NORETURN
name|PRINTFLIKE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|xo_errc
argument_list|(
name|int
name|eval
argument_list|,
name|int
name|code
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|NORETURN
name|PRINTFLIKE
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt

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
function_decl|PRINTFLIKE
parameter_list|(
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
function_decl|PRINTFLIKE
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
function_decl|PRINTFLIKE
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|xo_message_e
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|PRINTFLIKE
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
function_decl|PRINTFLIKE
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|xo_emit_warn_hcv
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|int
name|as_warning
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
name|xo_emit_warn_hc
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
name|xo_emit_warn_c
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
name|xo_emit_warn
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
name|xo_emit_warnx
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

begin_decl_stmt
name|void
name|xo_emit_err
argument_list|(
name|int
name|eval
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|xo_emit_errx
argument_list|(
name|int
name|eval
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|xo_emit_errc
argument_list|(
name|int
name|eval
argument_list|,
name|int
name|code
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|NORETURN
decl_stmt|;
end_decl_stmt

begin_macro
name|PRINTFLIKE
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|void
name|xo_emit_warn_hcvp
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|int
name|as_warning
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
block|{
name|xo_emit_warn_hcv
argument_list|(
name|xop
argument_list|,
name|as_warning
argument_list|,
name|code
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|void
name|xo_emit_warn_hcp
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
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|xo_emit_warn_hcv
argument_list|(
name|xop
argument_list|,
literal|1
argument_list|,
name|code
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|void
name|xo_emit_warn_cp
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
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|xo_emit_warn_hcv
argument_list|(
name|NULL
argument_list|,
literal|1
argument_list|,
name|code
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|void
name|xo_emit_warn_p
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|int
name|code
init|=
name|errno
decl_stmt|;
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|xo_emit_warn_hcv
argument_list|(
name|NULL
argument_list|,
literal|1
argument_list|,
name|code
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|void
name|xo_emit_warnx_p
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|xo_emit_warn_hcv
argument_list|(
name|NULL
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|NORETURN
name|PRINTFLIKE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl|static
specifier|inline
namespace|void
name|xo_emit_err_p
namespace|(
name|int
name|eval
operator|,
namespace|const
name|char
modifier|*
name|fmt
operator|,
namespace|...
decl_stmt|)
block|{
name|int
name|code
init|=
name|errno
decl_stmt|;
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|xo_emit_warn_hcv
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|code
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|eval
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_macro
name|PRINTFLIKE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|void
name|xo_emit_errx_p
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
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|xo_emit_warn_hcv
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|eval
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|PRINTFLIKE
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
end_macro

begin_function
specifier|static
specifier|inline
name|void
name|xo_emit_errc_p
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
block|{
name|va_list
name|vap
decl_stmt|;
name|va_start
argument_list|(
name|vap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|xo_emit_warn_hcv
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|code
argument_list|,
name|fmt
argument_list|,
name|vap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|eval
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|xo_emit_err_v
argument_list|(
name|int
name|eval
argument_list|,
name|int
name|code
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
name|va_list
name|vap
argument_list|)
name|NORETURN
name|PRINTFLIKE
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|xo_no_setlocale
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Lift libxo-specific arguments from a set of arguments  *  * libxo-enable programs typically use command line options to enable  * all the nifty-cool libxo features.  xo_parse_args() makes this simple  * by pre-processing the command line arguments given to main(), handling  * and removing the libxo-specific ones, meaning anything starting with  * "--libxo".  A full description of these arguments is in the base  * documentation.  * @param[in] argc Number of arguments (ala #main())  * @param[in] argc Array of argument strings (ala #main())  * @return New number of arguments, or -1 for failure.  */
end_comment

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
comment|/**  * This is the "magic" number returned by libxo-supporting commands  * when passed the equally magic "--libxo-check" option.  If you  * return this, we can (unsafely) assume that since you know the magic  * handshake, you'll happily handle future --libxo options and not do  * something violent like reboot the box or create another hole in the  * ozone layer.  */
end_comment

begin_define
define|#
directive|define
name|XO_HAS_LIBXO
value|121
end_define

begin_comment
comment|/**  * externs for libxo's version number strings  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|xo_version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** Base version triple string */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|xo_version_extra
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** Extra version magic content */
end_comment

begin_comment
comment|/**  * @brief Dump the internal stack of a libxo handle.  *  * This diagnostic function is something I will ask you to call from  * your program when you write to tell me libxo has gone bat-stink  * crazy and has discarded your list or container or content.  Output  * content will be what we lovingly call "developer entertainment".  * @param[in] xop A valid libxo handle, or NULL for the default handle  */
end_comment

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

begin_comment
comment|/**  * @brief Recode the name of the program, suitable for error output.  *  * libxo will record the given name for use while generating error  * messages.  The contents are not copied, so the value must continue  * to point to a valid memory location.  This allows the caller to change  * the value, but requires the caller to manage the memory.  Typically  * this is called with argv[0] from main().  * @param[in] name The name of the current application program  */
end_comment

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

begin_comment
comment|/**  * @brief Add a version string to the output, where possible.  *  * Adds a version number to the output, suitable for tracking  * changes in the content.  This is only important for the "encoding"  * format styles (XML and JSON) and allows a user of the data to  * discern which version of the data model is in use.  * @param[in] version The version number, encoded as a string  */
end_comment

begin_function_decl
name|void
name|xo_set_version
parameter_list|(
specifier|const
name|char
modifier|*
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * #xo_set_version with a handle.  * @param[in] xop A valid libxo handle, or NULL for the default handle  * @param[in] version The version number, encoded as a string  */
end_comment

begin_function_decl
name|void
name|xo_set_version_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_open_log
parameter_list|(
specifier|const
name|char
modifier|*
name|ident
parameter_list|,
name|int
name|logopt
parameter_list|,
name|int
name|facility
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_close_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_set_logmask
parameter_list|(
name|int
name|maskpri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_unit_test_mode
parameter_list|(
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_syslog
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_vsyslog
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xo_syslog_open_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xo_syslog_send_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|full_msg
parameter_list|,
specifier|const
name|char
modifier|*
name|v0_hdr
parameter_list|,
specifier|const
name|char
modifier|*
name|text_only
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xo_syslog_close_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|xo_set_syslog_handler
parameter_list|(
name|xo_syslog_open_t
name|open_func
parameter_list|,
name|xo_syslog_send_t
name|send_func
parameter_list|,
name|xo_syslog_close_t
name|close_func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_syslog_enterprise_id
parameter_list|(
name|unsigned
name|short
name|eid
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xo_simplify_field_func_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|char
modifier|*
name|xo_simplify_format
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
name|int
name|with_numbers
parameter_list|,
name|xo_simplify_field_func_t
name|field_cb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_emit_field_hv
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|rolmod
parameter_list|,
specifier|const
name|char
modifier|*
name|contents
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
specifier|const
name|char
modifier|*
name|efmt
parameter_list|,
name|va_list
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_emit_field_h
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|rolmod
parameter_list|,
specifier|const
name|char
modifier|*
name|contents
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
specifier|const
name|char
modifier|*
name|efmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_ssize_t
name|xo_emit_field
parameter_list|(
specifier|const
name|char
modifier|*
name|rolmod
parameter_list|,
specifier|const
name|char
modifier|*
name|contents
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
specifier|const
name|char
modifier|*
name|efmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_retain_clear_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_retain_clear
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
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

