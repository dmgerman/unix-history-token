begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config.h for libdivsufsort  * Copyright (c) 2003-2008 Yuta Mori All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person  * obtaining a copy of this software and associated documentation  * files (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use,  * copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following  * conditions:  *  * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/** Define to the version of this package. **/
define|#
directive|define
name|PROJECT_VERSION_FULL
value|"2.0.1-14-g5f60d6f"
comment|/** Define to 1 if you have the header files. **/
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
define|#
directive|define
name|HAVE_STDDEF_H
value|1
define|#
directive|define
name|HAVE_STDINT_H
value|1
define|#
directive|define
name|HAVE_STDLIB_H
value|1
define|#
directive|define
name|HAVE_STRING_H
value|1
define|#
directive|define
name|HAVE_STRINGS_H
value|1
define|#
directive|define
name|HAVE_MEMORY_H
value|1
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
comment|/** for WinIO **/
comment|/* #undef HAVE_IO_H */
comment|/* #undef HAVE_FCNTL_H */
comment|/* #undef HAVE__SETMODE */
comment|/* #undef HAVE_SETMODE */
comment|/* #undef HAVE__FILENO */
comment|/* #undef HAVE_FOPEN_S */
comment|/* #undef HAVE__O_BINARY */
ifndef|#
directive|ifndef
name|HAVE__SETMODE
if|#
directive|if
name|HAVE_SETMODE
define|#
directive|define
name|_setmode
value|setmode
define|#
directive|define
name|HAVE__SETMODE
value|1
endif|#
directive|endif
if|#
directive|if
name|HAVE__SETMODE
operator|&&
operator|!
name|HAVE__O_BINARY
define|#
directive|define
name|_O_BINARY
value|0
define|#
directive|define
name|HAVE__O_BINARY
value|1
endif|#
directive|endif
endif|#
directive|endif
comment|/** for inline **/
ifndef|#
directive|ifndef
name|INLINE
define|#
directive|define
name|INLINE
value|inline
endif|#
directive|endif
comment|/** for VC++ warning **/
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4127
name|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|/* extern "C" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CONFIG_H */
end_comment

end_unit

