begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_INCLUDE_BOARD_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_INCLUDE_BOARD_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_typedef
typedef|typedef
name|long
function_decl|(
name|arm_board_init_fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|arm_board
block|{
name|int
name|board_id
decl_stmt|;
comment|/* Board ID from the boot loader */
specifier|const
name|char
modifier|*
name|board_name
decl_stmt|;
comment|/* Human readable name */
name|arm_board_init_fn
modifier|*
name|board_init
decl_stmt|;
comment|/* Board initialize code */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARM_MANY_BOARD
argument_list|)
end_if

begin_include
include|#
directive|include
file|"board_id.h"
end_include

begin_define
define|#
directive|define
name|ARM_BOARD
parameter_list|(
name|id
parameter_list|,
name|name
parameter_list|)
define|\
value|static struct arm_board this_board = { \ 		.board_id = ARM_BOARD_ID_ ## id, \ 		.board_name = name, \ 		.board_init = board_init, \ 	}; \ 	DATA_SET(arm_boards, this_board);
end_define

begin_define
define|#
directive|define
name|BOARD_INIT
value|static
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ARM_MANY_BOARD */
end_comment

begin_define
define|#
directive|define
name|ARM_BOARD
parameter_list|(
name|id
parameter_list|,
name|name
parameter_list|)
end_define

begin_decl_stmt
specifier|extern
name|arm_board_init_fn
name|board_init
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BOARD_INIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_MANY_BOARD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_INCLUDE_BOARD_H_ */
end_comment

end_unit

