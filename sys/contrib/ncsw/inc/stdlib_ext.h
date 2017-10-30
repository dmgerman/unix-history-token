begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDLIB_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__STDLIB_EXT_H
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|NCSW_LINUX
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"stdarg_ext.h"
end_include

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/**  * strtoul - convert a string to an uint32_t  * @cp: The start of the string  * @endp: A pointer to the end of the parsed string will be placed here  * @base: The number base to use  */
end_comment

begin_function_decl
name|uint32_t
name|strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|uint32_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * strtol - convert a string to a int32_t  * @cp: The start of the string  * @endp: A pointer to the end of the parsed string will be placed here  * @base: The number base to use  */
end_comment

begin_function_decl
name|long
name|strtol
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|uint32_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * strtoull - convert a string to an uint64_t  * @cp: The start of the string  * @endp: A pointer to the end of the parsed string will be placed here  * @base: The number base to use  */
end_comment

begin_function_decl
name|uint64_t
name|strtoull
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|uint32_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * strtoll - convert a string to a int64 long  * @cp: The start of the string  * @endp: A pointer to the end of the parsed string will be placed here  * @base: The number base to use  */
end_comment

begin_function_decl
name|long
name|long
name|strtoll
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|uint32_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * atoi - convert a character to a int  * @s: The start of the string  */
end_comment

begin_function_decl
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * strnlen - Find the length of a length-limited string  * @s: The string to be sized  * @count: The maximum number of bytes to search  */
end_comment

begin_function_decl
name|size_t
name|strnlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * strlen - Find the length of a string  * @s: The string to be sized  */
end_comment

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * strtok - Split a string into tokens  * @s: The string to be searched  * @ct: The characters to search for  *  * WARNING: strtok is deprecated, use strsep instead.  */
end_comment

begin_function_decl
name|char
modifier|*
name|strtok
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|ct
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * strncpy - Copy a length-limited, %NUL-terminated string  * @dest: Where to copy the string to  * @src: Where to copy the string from  * @count: The maximum number of bytes to copy  *  * Note that unlike userspace strncpy, this does not %NUL-pad the buffer.  * However, the result is not %NUL-terminated if the source exceeds  * @count bytes.  */
end_comment

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * strcpy - Copy a %NUL terminated string  * @dest: Where to copy the string to  * @src: Where to copy the string from  */
end_comment

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * vsscanf - Unformat a buffer into a list of arguments  * @buf:    input buffer  * @fmt:    format of buffer  * @args:    arguments  */
end_comment

begin_function_decl
name|int
name|vsscanf
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * vsnprintf - Format a string and place it in a buffer  * @buf: The buffer to place the result into  * @size: The size of the buffer, including the trailing null space  * @fmt: The format string to use  * @args: Arguments for the format string  *  * Call this function if you are already dealing with a va_list.  * You probably want snprintf instead.  */
end_comment

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * vsprintf - Format a string and place it in a buffer  * @buf: The buffer to place the result into  * @fmt: The format string to use  * @args: Arguments for the format string  *  * Call this function if you are already dealing with a va_list.  * You probably want sprintf instead.  */
end_comment

begin_function_decl
name|int
name|vsprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|NCSW_FREEBSD
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NCSW_LINUX)&& defined(__KERNEL__) */
end_comment

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDLIB_EXT_H */
end_comment

end_unit

