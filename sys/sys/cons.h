begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)cons.h	7.2 (Berkeley) 5/9/91  * $FreeBSD$  */
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

begin_struct_decl
struct_decl|struct
name|tty
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
name|void
name|cn_grab_t
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
name|cn_ungrab_t
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
name|struct
name|consdev
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|cn_putc_t
parameter_list|(
name|struct
name|consdev
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|consdev_ops
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
name|cn_putc_t
modifier|*
name|cn_putc
decl_stmt|;
comment|/* kernel putchar interface */
name|cn_grab_t
modifier|*
name|cn_grab
decl_stmt|;
comment|/* grab console for exclusive kernel use */
name|cn_ungrab_t
modifier|*
name|cn_ungrab
decl_stmt|;
comment|/* ungrab console */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|consdev
block|{
specifier|const
name|struct
name|consdev_ops
modifier|*
name|cn_ops
decl_stmt|;
comment|/* console device operations. */
name|short
name|cn_pri
decl_stmt|;
comment|/* pecking order; the higher the better */
name|void
modifier|*
name|cn_arg
decl_stmt|;
comment|/* drivers method argument */
name|int
name|cn_flags
decl_stmt|;
comment|/* capabilities of this console */
name|char
name|cn_name
index|[
name|SPECNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* console (device) name */
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
name|CN_LOW
value|1
end_define

begin_comment
comment|/* device is a last restort only */
end_comment

begin_define
define|#
directive|define
name|CN_NORMAL
value|2
end_define

begin_comment
comment|/* device exists but is nothing special */
end_comment

begin_define
define|#
directive|define
name|CN_INTERNAL
value|3
end_define

begin_comment
comment|/* "internal" bit-mapped display */
end_comment

begin_define
define|#
directive|define
name|CN_REMOTE
value|4
end_define

begin_comment
comment|/* serial interface with remote bit set */
end_comment

begin_comment
comment|/* Values for cn_flags. */
end_comment

begin_define
define|#
directive|define
name|CN_FLAG_NODEBUG
value|0x00000001
end_define

begin_comment
comment|/* Not supported with debugger. */
end_comment

begin_define
define|#
directive|define
name|CN_FLAG_NOAVAIL
value|0x00000002
end_define

begin_comment
comment|/* Temporarily not available. */
end_comment

begin_comment
comment|/* Visibility of characters in cngets() */
end_comment

begin_define
define|#
directive|define
name|GETS_NOECHO
value|0
end_define

begin_comment
comment|/* Disable echoing of characters. */
end_comment

begin_define
define|#
directive|define
name|GETS_ECHO
value|1
end_define

begin_comment
comment|/* Enable echoing of characters. */
end_comment

begin_define
define|#
directive|define
name|GETS_ECHOPASS
value|2
end_define

begin_comment
comment|/* Print a * for every character. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|msgbuf
name|consmsgbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Message buffer for constty. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|constty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temporary virtual console. */
end_comment

begin_define
define|#
directive|define
name|CONSOLE_DEVICE
parameter_list|(
name|name
parameter_list|,
name|ops
parameter_list|,
name|arg
parameter_list|)
define|\
value|static struct consdev name = {					\ 		.cn_ops =&ops,						\ 		.cn_arg = (arg),					\ 	};								\ 	DATA_SET(cons_set, name)
end_define

begin_define
define|#
directive|define
name|CONSOLE_DRIVER
parameter_list|(
name|name
parameter_list|)
define|\
value|static const struct consdev_ops name##_consdev_ops = {		\ 		.cn_probe = name##_cnprobe,				\ 		.cn_init = name##_cninit,				\ 		.cn_term = name##_cnterm,				\ 		.cn_getc = name##_cngetc,				\ 		.cn_putc = name##_cnputc,				\ 		.cn_grab = name##_cngrab,				\ 		.cn_ungrab = name##_cnungrab,				\ 	};								\ 	CONSOLE_DEVICE(name##_consdev, name##_consdev_ops, NULL)
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
name|cnavailable
parameter_list|(
name|struct
name|consdev
modifier|*
parameter_list|,
name|int
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
name|void
name|cngrab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cnungrab
parameter_list|(
name|void
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
name|cngets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
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

begin_function_decl
name|void
name|cnputs
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cnunavailable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|constty_set
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|constty_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sc(4) / vt(4) coexistence shim */
end_comment

begin_define
define|#
directive|define
name|VTY_SC
value|0x01
end_define

begin_define
define|#
directive|define
name|VTY_VT
value|0x02
end_define

begin_function_decl
name|int
name|vty_enabled
parameter_list|(
name|unsigned
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

