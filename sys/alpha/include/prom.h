begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: prom.h,v 1.7 1997/04/06 08:47:37 cgd Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Keith Bostic, Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASSEMBLER
end_ifndef

begin_struct
struct|struct
name|prom_vec
block|{
name|u_int64_t
name|routine
decl_stmt|;
name|void
modifier|*
name|routine_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The return value from a prom call. */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|u_int64_t
name|retval
range|:
literal|32
decl_stmt|,
comment|/* return value. */
name|unit
range|:
literal|8
decl_stmt|,
name|mbz
range|:
literal|8
decl_stmt|,
name|error
range|:
literal|13
decl_stmt|,
name|status
range|:
literal|3
decl_stmt|;
block|}
name|u
struct|;
name|u_int64_t
name|bits
decl_stmt|;
block|}
name|prom_return_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|STANDALONE
end_ifdef

begin_function_decl
name|int
name|getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prom_open
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|prom_halt
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
name|int
name|prom_getenv
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prom operation values. */
end_comment

begin_define
define|#
directive|define
name|PROM_R_CLOSE
value|0x11
end_define

begin_define
define|#
directive|define
name|PROM_R_GETC
value|0x01
end_define

begin_define
define|#
directive|define
name|PROM_R_GETENV
value|0x22
end_define

begin_define
define|#
directive|define
name|PROM_R_OPEN
value|0x10
end_define

begin_define
define|#
directive|define
name|PROM_R_PUTS
value|0x02
end_define

begin_define
define|#
directive|define
name|PROM_R_READ
value|0x13
end_define

begin_define
define|#
directive|define
name|PROM_R_WRITE
value|0x14
end_define

begin_comment
comment|/* Environment variable values. */
end_comment

begin_define
define|#
directive|define
name|PROM_E_BOOTED_DEV
value|0x4
end_define

begin_define
define|#
directive|define
name|PROM_E_BOOTED_FILE
value|0x6
end_define

begin_define
define|#
directive|define
name|PROM_E_BOOTED_OSFLAGS
value|0x8
end_define

begin_define
define|#
directive|define
name|PROM_E_TTY_DEV
value|0xf
end_define

begin_comment
comment|/*  * There have to be stub routines to do the copying that ensures that the  * PROM doesn't get called with an address larger than 32 bits.  Calls that  * either don't need to copy anything, or don't need the copy because it's  * already being done elsewhere, are defined here.  */
end_comment

begin_define
define|#
directive|define
name|prom_close
parameter_list|(
name|chan
parameter_list|)
define|\
value|prom_dispatch(PROM_R_CLOSE, chan, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|prom_read
parameter_list|(
name|chan
parameter_list|,
name|len
parameter_list|,
name|buf
parameter_list|,
name|blkno
parameter_list|)
define|\
value|prom_dispatch(PROM_R_READ, chan, len, (u_int64_t)buf, blkno)
end_define

begin_define
define|#
directive|define
name|prom_write
parameter_list|(
name|chan
parameter_list|,
name|len
parameter_list|,
name|buf
parameter_list|,
name|blkno
parameter_list|)
define|\
value|prom_dispatch(PROM_R_WRITE, chan, len, (u_int64_t)buf, blkno)
end_define

begin_define
define|#
directive|define
name|prom_putstr
parameter_list|(
name|chan
parameter_list|,
name|str
parameter_list|,
name|len
parameter_list|)
define|\
value|prom_dispatch(PROM_R_PUTS, chan, (u_int64_t)str, len, 0)
end_define

begin_define
define|#
directive|define
name|prom_getc
parameter_list|(
name|chan
parameter_list|)
define|\
value|prom_dispatch(PROM_R_GETC, chan, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|prom_getenv_disp
parameter_list|(
name|id
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|prom_dispatch(PROM_R_GETENV, id, (u_int64_t)buf, len, 0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ASSEMBLER
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|promcnattach
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|promcndetach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|promcnputc
parameter_list|(
name|dev_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|promcngetc
parameter_list|(
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|promcncheckc
parameter_list|(
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|prom_dispatch
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_bootstrap_console
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASSEMBLER */
end_comment

end_unit

