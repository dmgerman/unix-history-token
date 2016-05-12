begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014, Mike Kazantsev  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLATFORM_CONFIG_H
argument_list|)
end_if

begin_comment
comment|/* Use hand-built config.h in environments that need it. */
end_comment

begin_include
include|#
directive|include
include|PLATFORM_CONFIG_H
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not having a config.h of some sort is a serious problem. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<archive.h>
end_include

begin_include
include|#
directive|include
file|<archive_entry.h>
end_include

begin_struct
struct|struct
name|bsdcat
block|{
comment|/* Option parser state */
name|int
name|getopt_state
decl_stmt|;
name|char
modifier|*
name|getopt_word
decl_stmt|;
comment|/* Miscellaneous state information */
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
specifier|const
name|char
modifier|*
name|argument
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|OPTION_VERSION
block|}
enum|;
end_enum

begin_function_decl
name|int
name|bsdcat_getopt
parameter_list|(
name|struct
name|bsdcat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usage
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
name|int
name|eval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsdcat_next
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsdcat_print_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsdcat_read_to_stdout
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

end_unit

