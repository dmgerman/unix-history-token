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

begin_comment
comment|/*  * Copyright 2011 The Chromium Authors, All Rights Reserved.  * Copyright 2008 Jon Loeliger, Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation; either version 2 of the  * License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *                                                                   USA  */
end_comment

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
name|die
argument_list|(
name|char
operator|*
name|str
argument_list|,
operator|...
argument_list|)
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
literal|"realloc() failed (len=%d)\n"
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
comment|/**  * Check a string of a given length to see if it is all printable and  * has a valid terminator.  *  * @param data	The string to check  * @param len	The string length including terminator  * @return 1 if a valid printable string, 0 if not */
end_comment

begin_function_decl
name|int
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
value|"<type>\ts=string, i=int, u=unsigned, x=hex\n" \ 	"\tOptional modifier prefix:\n" \ 	"\t\thh or b=byte, h=2 byte, l=4 byte (default)\n";
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UTIL_H */
end_comment

end_unit

