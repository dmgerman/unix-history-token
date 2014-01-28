begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS `AS IS' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: _libelf_ar.h 2032 2011-10-23 09:07:00Z jkoshy $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBELF_AR_H_
end_ifndef

begin_define
define|#
directive|define
name|__LIBELF_AR_H_
end_define

begin_comment
comment|/*  * Prototypes and declarations needed by libelf's ar(1) archive  * handling code.  */
end_comment

begin_include
include|#
directive|include
file|<ar.h>
end_include

begin_define
define|#
directive|define
name|LIBELF_AR_BSD_EXTENDED_NAME_PREFIX
value|"#1/"
end_define

begin_define
define|#
directive|define
name|LIBELF_AR_BSD_SYMTAB_NAME
value|"__.SYMDEF"
end_define

begin_define
define|#
directive|define
name|LIBELF_AR_BSD_EXTENDED_NAME_PREFIX_SIZE
define|\
value|(sizeof(LIBELF_AR_BSD_EXTENDED_NAME_PREFIX) - 1)
end_define

begin_define
define|#
directive|define
name|IS_EXTENDED_BSD_NAME
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(strncmp((NAME), LIBELF_AR_BSD_EXTENDED_NAME_PREFIX,	\ 	 LIBELF_AR_BSD_EXTENDED_NAME_PREFIX_SIZE) == 0)
end_define

begin_function_decl
name|char
modifier|*
name|_libelf_ar_get_string
parameter_list|(
specifier|const
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_sz
parameter_list|,
name|int
name|_rawname
parameter_list|,
name|int
name|_svr4names
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_libelf_ar_get_raw_name
parameter_list|(
specifier|const
name|struct
name|ar_hdr
modifier|*
name|_arh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_libelf_ar_get_translated_name
parameter_list|(
specifier|const
name|struct
name|ar_hdr
modifier|*
name|_arh
parameter_list|,
name|Elf
modifier|*
name|_ar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_libelf_ar_get_number
parameter_list|(
specifier|const
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_sz
parameter_list|,
name|int
name|_base
parameter_list|,
name|size_t
modifier|*
name|_ret
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIBELF_AR_H_ */
end_comment

end_unit

