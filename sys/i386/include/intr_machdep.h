begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MACHINE_INTR_MACHDEP_H__
end_ifndef

begin_define
define|#
directive|define
name|__MACHINE_INTR_MACHDEP_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* With I/O APIC's we can have up to 191 interrupts. */
end_comment

begin_define
define|#
directive|define
name|NUM_IO_INTS
value|191
end_define

begin_define
define|#
directive|define
name|INTRCNT_COUNT
value|(1 + NUM_IO_INTS * 2)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|void
name|inthand_t
parameter_list|(
name|u_int
name|cs
parameter_list|,
name|u_int
name|ef
parameter_list|,
name|u_int
name|esp
parameter_list|,
name|u_int
name|ss
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|IDTVEC
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(X,name)
end_define

begin_struct_decl
struct_decl|struct
name|intsrc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Methods that a PIC provides to mask/unmask a given interrupt source,  * "turn on" the interrupt on the CPU side by setting up an IDT entry, and  * return the vector associated with this source.  */
end_comment

begin_struct
struct|struct
name|pic
block|{
name|void
function_decl|(
modifier|*
name|pic_enable_source
function_decl|)
parameter_list|(
name|struct
name|intsrc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pic_disable_source
function_decl|)
parameter_list|(
name|struct
name|intsrc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pic_eoi_source
function_decl|)
parameter_list|(
name|struct
name|intsrc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pic_enable_intr
function_decl|)
parameter_list|(
name|struct
name|intsrc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pic_vector
function_decl|)
parameter_list|(
name|struct
name|intsrc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pic_source_pending
function_decl|)
parameter_list|(
name|struct
name|intsrc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pic_suspend
function_decl|)
parameter_list|(
name|struct
name|intsrc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pic_resume
function_decl|)
parameter_list|(
name|struct
name|intsrc
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * An interrupt source.  The upper-layer code uses the PIC methods to  * control a given source.  The lower-layer PIC drivers can store additional  * private data in a given interrupt source such as an interrupt pin number  * or an I/O APIC pointer.  */
end_comment

begin_struct
struct|struct
name|intsrc
block|{
name|struct
name|pic
modifier|*
name|is_pic
decl_stmt|;
name|struct
name|ithd
modifier|*
name|is_ithread
decl_stmt|;
name|u_long
modifier|*
name|is_count
decl_stmt|;
name|u_long
modifier|*
name|is_straycount
decl_stmt|;
name|u_int
name|is_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|intrframe
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|icu_lock
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|intr_add_handler
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|vector
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|enum
name|intr_type
name|flags
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_execute_handlers
parameter_list|(
name|struct
name|intsrc
modifier|*
name|isrc
parameter_list|,
name|struct
name|intrframe
modifier|*
name|iframe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|intsrc
modifier|*
name|intr_lookup_source
parameter_list|(
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_register_source
parameter_list|(
name|struct
name|intsrc
modifier|*
name|isrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_remove_handler
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_resume
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__MACHINE_INTR_MACHDEP_H__ */
end_comment

end_unit

