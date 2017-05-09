begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_UTIL_H
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_comment
comment|/*  * Copyright 2011 The Chromium Authors, All Rights Reserved.  * Copyright 2008 Jon Loeliger, Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation; either version 2 of the  * License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *                                                                   USA  */
end_comment

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x) / sizeof((x)[0]))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_decl_stmt
specifier|static
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
name|die
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|,
operator|...
argument_list|)
else|#
directive|else
decl|static
specifier|inline
namespace|void
name|die
namespace|(const
name|char
modifier|*
name|str
operator|,
namespace|...
decl_stmt|)
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"FATAL ERROR: "
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|str
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
name|len
parameter_list|)
block|{
name|void
modifier|*
name|new
init|=
name|malloc
argument_list|(
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|new
condition|)
name|die
argument_list|(
literal|"malloc() failed\n"
argument_list|)
expr_stmt|;
return|return
name|new
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|void
modifier|*
name|new
init|=
name|realloc
argument_list|(
name|p
argument_list|,
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|new
condition|)
name|die
argument_list|(
literal|"realloc() failed (len=%zd)\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
name|new
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
name|xasprintf
argument_list|(
name|char
operator|*
operator|*
name|strp
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|xasprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|strp
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

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|join_path
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check a property of a given length to see if it is all printable and  * has a valid terminator. The property can contain either a single string,  * or multiple strings each of non-zero length.  *  * @param data	The string to check  * @param len	The string length including terminator  * @return 1 if a valid printable string, 0 if not  */
end_comment

begin_function_decl
name|bool
name|util_is_printable_string
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parse an escaped character starting at index i in string s.  The resulting  * character will be returned and the index i will be updated to point at the  * character directly after the end of the encoding, this may be the '\0'  * terminator of the string.  */
end_comment

begin_function_decl
name|char
name|get_escape_char
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
modifier|*
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read a device tree file into a buffer. This will report any errors on  * stderr.  *  * @param filename	The filename to read, or - for stdin  * @return Pointer to allocated buffer containing fdt, or NULL on error  */
end_comment

begin_function_decl
name|char
modifier|*
name|utilfdt_read
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Like utilfdt_read(), but also passes back the size of the file read.  *  * @param len		If non-NULL, the amount of data we managed to read  */
end_comment

begin_function_decl
name|char
modifier|*
name|utilfdt_read_len
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|off_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read a device tree file into a buffer. Does not report errors, but only  * returns them. The value returned can be passed to strerror() to obtain  * an error message for the user.  *  * @param filename	The filename to read, or - for stdin  * @param buffp		Returns pointer to buffer containing fdt  * @return 0 if ok, else an errno value representing the error  */
end_comment

begin_function_decl
name|int
name|utilfdt_read_err
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
modifier|*
name|buffp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Like utilfdt_read_err(), but also passes back the size of the file read.  *  * @param len		If non-NULL, the amount of data we managed to read  */
end_comment

begin_function_decl
name|int
name|utilfdt_read_err_len
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
modifier|*
name|buffp
parameter_list|,
name|off_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Write a device tree buffer to a file. This will report any errors on  * stderr.  *  * @param filename	The filename to write, or - for stdout  * @param blob		Poiner to buffer containing fdt  * @return 0 if ok, -1 on error  */
end_comment

begin_function_decl
name|int
name|utilfdt_write
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|void
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Write a device tree buffer to a file. Does not report errors, but only  * returns them. The value returned can be passed to strerror() to obtain  * an error message for the user.  *  * @param filename	The filename to write, or - for stdout  * @param blob		Poiner to buffer containing fdt  * @return 0 if ok, else an errno value representing the error  */
end_comment

begin_function_decl
name|int
name|utilfdt_write_err
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|void
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Decode a data type string. The purpose of this string  *  * The string consists of an optional character followed by the type:  *	Modifier characters:  *		hh or b	1 byte  *		h	2 byte  *		l	4 byte, default  *  *	Type character:  *		s	string  *		i	signed integer  *		u	unsigned integer  *		x	hex  *  * TODO: Implement ll modifier (8 bytes)  * TODO: Implement o type (octal)  *  * @param fmt		Format string to process  * @param type		Returns type found(s/d/u/x), or 0 if none  * @param size		Returns size found(1,2,4,8) or 4 if none  * @return 0 if ok, -1 on error (no type given, or other invalid format)  */
end_comment

begin_function_decl
name|int
name|utilfdt_decode_type
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|int
modifier|*
name|type
parameter_list|,
name|int
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This is a usage message fragment for the -t option. It is the format  * supported by utilfdt_decode_type.  */
end_comment

begin_define
define|#
directive|define
name|USAGE_TYPE_MSG
define|\
value|"<type>\ts=string, i=int, u=unsigned, x=hex\n" \ 	"\tOptional modifier prefix:\n" \ 	"\t\thh or b=byte, h=2 byte, l=4 byte (default)";
end_define

begin_comment
comment|/**  * Print property data in a readable format to stdout  *  * Properties that look like strings will be printed as strings. Otherwise  * the data will be displayed either as cells (if len is a multiple of 4  * bytes) or bytes.  *  * If len is 0 then this function does nothing.  *  * @param data	Pointers to property data  * @param len	Length of property data  */
end_comment

begin_function_decl
name|void
name|utilfdt_print_data
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Show source version and exit  */
end_comment

begin_function_decl
name|void
name|util_version
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Show usage and exit  *  * This helps standardize the output of various utils.  You most likely want  * to use the usage() helper below rather than call this.  *  * @param errmsg	If non-NULL, an error message to display  * @param synopsis	The initial example usage text (and possible examples)  * @param short_opts	The string of short options  * @param long_opts	The structure of long options  * @param opts_help	An array of help strings (should align with long_opts)  */
end_comment

begin_function_decl
name|void
name|util_usage
parameter_list|(
specifier|const
name|char
modifier|*
name|errmsg
parameter_list|,
specifier|const
name|char
modifier|*
name|synopsis
parameter_list|,
specifier|const
name|char
modifier|*
name|short_opts
parameter_list|,
name|struct
name|option
specifier|const
name|long_opts
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
name|opts_help
index|[]
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Show usage and exit  *  * If you name all your usage variables with usage_xxx, then you can call this  * help macro rather than expanding all arguments yourself.  *  * @param errmsg	If non-NULL, an error message to display  */
end_comment

begin_define
define|#
directive|define
name|usage
parameter_list|(
name|errmsg
parameter_list|)
define|\
value|util_usage(errmsg, usage_synopsis, usage_short_opts, \ 		   usage_long_opts, usage_opts_help)
end_define

begin_comment
comment|/**  * Call getopt_long() with standard options  *  * Since all util code runs getopt in the same way, provide a helper.  */
end_comment

begin_define
define|#
directive|define
name|util_getopt_long
parameter_list|()
value|getopt_long(argc, argv, usage_short_opts, \ 				       usage_long_opts, NULL)
end_define

begin_comment
comment|/* Helper for aligning long_opts array */
end_comment

begin_define
define|#
directive|define
name|a_argument
value|required_argument
end_define

begin_comment
comment|/* Helper for usage_short_opts string constant */
end_comment

begin_define
define|#
directive|define
name|USAGE_COMMON_SHORT_OPTS
value|"hV"
end_define

begin_comment
comment|/* Helper for usage_long_opts option array */
end_comment

begin_define
define|#
directive|define
name|USAGE_COMMON_LONG_OPTS
define|\
value|{"help",      no_argument, NULL, 'h'}, \ 	{"version",   no_argument, NULL, 'V'}, \ 	{NULL,        no_argument, NULL, 0x0}
end_define

begin_comment
comment|/* Helper for usage_opts_help array */
end_comment

begin_define
define|#
directive|define
name|USAGE_COMMON_OPTS_HELP
define|\
value|"Print this help and exit", \ 	"Print version and exit", \ 	NULL
end_define

begin_comment
comment|/* Helper for getopt case statements */
end_comment

begin_define
define|#
directive|define
name|case_USAGE_COMMON_FLAGS
define|\
value|case 'h': usage(NULL); \ 	case 'V': util_version(); \ 	case '?': usage("unknown option");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UTIL_H */
end_comment

end_unit

