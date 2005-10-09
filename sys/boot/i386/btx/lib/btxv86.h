begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms are freely  * permitted provided that the above copyright notice and this  * paragraph and the following disclaimer are duplicated in all  * such forms.  *  * This software is provided "AS IS" and without any express or  * implied warranties, including, without limitation, the implied  * warranties of merchantability and fitness for a particular  * purpose.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BTXV86_H_
end_ifndef

begin_define
define|#
directive|define
name|_BTXV86_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|V86_ADDR
value|0x10000
end_define

begin_comment
comment|/* Segment:offset address */
end_comment

begin_define
define|#
directive|define
name|V86_CALLF
value|0x20000
end_define

begin_comment
comment|/* Emulate far call */
end_comment

begin_define
define|#
directive|define
name|V86_FLAGS
value|0x40000
end_define

begin_comment
comment|/* Return flags */
end_comment

begin_struct
struct|struct
name|__v86
block|{
name|uint32_t
name|ctl
decl_stmt|;
comment|/* Control flags */
name|uint32_t
name|addr
decl_stmt|;
comment|/* Interrupt number or address */
name|uint32_t
name|es
decl_stmt|;
comment|/* V86 ES register */
name|uint32_t
name|ds
decl_stmt|;
comment|/* V86 DS register */
name|uint32_t
name|fs
decl_stmt|;
comment|/* V86 FS register */
name|uint32_t
name|gs
decl_stmt|;
comment|/* V86 GS register */
name|uint32_t
name|eax
decl_stmt|;
comment|/* V86 EAX register */
name|uint32_t
name|ecx
decl_stmt|;
comment|/* V86 ECX register */
name|uint32_t
name|edx
decl_stmt|;
comment|/* V86 EDX register */
name|uint32_t
name|ebx
decl_stmt|;
comment|/* V86 EBX register */
name|uint32_t
name|efl
decl_stmt|;
comment|/* V86 eflags register */
name|uint32_t
name|ebp
decl_stmt|;
comment|/* V86 EBP register */
name|uint32_t
name|esi
decl_stmt|;
comment|/* V86 ESI register */
name|uint32_t
name|edi
decl_stmt|;
comment|/* V86 EDI register */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|__v86
name|__v86
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* V86 interface structure */
end_comment

begin_function_decl
name|void
name|__v86int
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|v86
value|__v86
end_define

begin_define
define|#
directive|define
name|v86int
value|__v86int
end_define

begin_decl_stmt
specifier|extern
name|u_int32_t
name|__base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|__args
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PTOV
parameter_list|(
name|pa
parameter_list|)
value|((caddr_t)(pa) - __base)
end_define

begin_define
define|#
directive|define
name|VTOP
parameter_list|(
name|va
parameter_list|)
value|((vm_offset_t)(va) + __base)
end_define

begin_define
define|#
directive|define
name|VTOPSEG
parameter_list|(
name|va
parameter_list|)
value|(u_int16_t)(VTOP((caddr_t)va)>> 4)
end_define

begin_define
define|#
directive|define
name|VTOPOFF
parameter_list|(
name|va
parameter_list|)
value|(u_int16_t)(VTOP((caddr_t)va)& 0xf)
end_define

begin_function_decl
name|void
name|__exit
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|__exec
parameter_list|(
name|caddr_t
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BTXV86_H_ */
end_comment

end_unit

