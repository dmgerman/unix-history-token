begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)cons.h	7.2 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CONS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CONS_H_
end_define

begin_struct_decl
struct_decl|struct
name|consdev
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|cn_probe_t
parameter_list|(
name|struct
name|consdev
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|cn_init_t
parameter_list|(
name|struct
name|consdev
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|cn_term_t
parameter_list|(
name|struct
name|consdev
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|cn_getc_t
parameter_list|(
name|dev_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|cn_checkc_t
parameter_list|(
name|dev_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|cn_putc_t
parameter_list|(
name|dev_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|cn_dbctl_t
parameter_list|(
name|dev_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|consdev
block|{
name|cn_probe_t
modifier|*
name|cn_probe
decl_stmt|;
comment|/* probe hardware and fill in consdev info */
name|cn_init_t
modifier|*
name|cn_init
decl_stmt|;
comment|/* turn on as console */
name|cn_term_t
modifier|*
name|cn_term
decl_stmt|;
comment|/* turn off as console */
name|cn_getc_t
modifier|*
name|cn_getc
decl_stmt|;
comment|/* kernel getchar interface */
name|cn_checkc_t
modifier|*
name|cn_checkc
decl_stmt|;
comment|/* kernel "return char if available" interface */
name|cn_putc_t
modifier|*
name|cn_putc
decl_stmt|;
comment|/* kernel putchar interface */
name|cn_dbctl_t
modifier|*
name|cn_dbctl
decl_stmt|;
comment|/* debugger control interface */
name|struct
name|tty
modifier|*
name|cn_tp
decl_stmt|;
comment|/* tty structure for console device */
name|dev_t
name|cn_dev
decl_stmt|;
comment|/* major/minor of device */
name|short
name|cn_pri
decl_stmt|;
comment|/* pecking order; the higher the better */
block|}
struct|;
end_struct

begin_comment
comment|/* values for cn_pri - reflect our policy for console selection */
end_comment

begin_define
define|#
directive|define
name|CN_DEAD
value|0
end_define

begin_comment
comment|/* device doesn't exist */
end_comment

begin_define
define|#
directive|define
name|CN_NORMAL
value|1
end_define

begin_comment
comment|/* device exists but is nothing special */
end_comment

begin_define
define|#
directive|define
name|CN_INTERNAL
value|2
end_define

begin_comment
comment|/* "internal" bit-mapped display */
end_comment

begin_define
define|#
directive|define
name|CN_REMOTE
value|3
end_define

begin_comment
comment|/* serial interface with remote bit set */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|cons_unavail
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CONS_DRIVER
parameter_list|(
name|name
parameter_list|,
name|probe
parameter_list|,
name|init
parameter_list|,
name|term
parameter_list|,
name|getc
parameter_list|,
name|checkc
parameter_list|,
name|putc
parameter_list|,
name|dbctl
parameter_list|)
define|\
value|static struct consdev name##_consdev = {			\ 		probe, init, term, getc, checkc, putc, dbctl		\ 	};								\ 	DATA_SET(cons_set, name##_consdev)
end_define

begin_comment
comment|/* Other kernel entry points. */
end_comment

begin_function_decl
name|void
name|cninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cninit_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cnadd
parameter_list|(
name|struct
name|consdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cnremove
parameter_list|(
name|struct
name|consdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cnselect
parameter_list|(
name|struct
name|consdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cncheckc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cngetc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cndbctl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cnputc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_MACHINE_CONS_H_ */
end_comment

end_unit

