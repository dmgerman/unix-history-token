begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Wojciech A. Koszek<wkoszek@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: xlr_boot1_console.c,v 1.6 2008-07-16 20:22:49 jayachandranc Exp $  */
end_comment

begin_comment
comment|/*  *  Adapted for XLR bootloader  *  RMi  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_comconsole.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/consio.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<mips/xlr/xlrconfig.h>
end_include

begin_include
include|#
directive|include
file|<mips/xlr/shared_structs.h>
end_include

begin_include
include|#
directive|include
file|<mips/xlr/shared_structs_func.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|static cn_probe_t	xlr_boot1_cnprobe; static cn_init_t	xlr_boot1_cninit; static cn_term_t	xlr_boot1_cnterm; static cn_getc_t	xlr_boot1_cngetc; static cn_checkc_t      xlr_boot1_cncheckc; static cn_putc_t	xlr_boot1_cnputc;  CONS_DRIVER(xlrboot, xlr_boot1_cnprobe, xlr_boot1_cninit, xlr_boot1_cnterm, xlr_boot1_cngetc,     xlr_boot1_cncheckc, xlr_boot1_cnputc, NULL);
comment|/*  * Device gets probed. Firmwire should be checked here probably.  */
end_comment

begin_comment
unit|static void xlr_boot1_cnprobe(struct consdev *cp) { 	cp->cn_pri = CN_NORMAL; 	cp->cn_tp = NULL; 	cp->cn_arg = NULL;
comment|/* softc */
end_comment

begin_comment
unit|cp->cn_unit = -1;
comment|/* ? */
end_comment

begin_comment
unit|cp->cn_flags = 0; }
comment|/*  * Initialization.  */
end_comment

begin_endif
unit|static void xlr_boot1_cninit(struct consdev *cp) { 	sprintf(cp->cn_name, "boot1"); }  static void xlr_boot1_cnterm(struct consdev *cp) { 	cp->cn_pri = CN_DEAD; 	cp->cn_flags = 0; 	return; }  static int xlr_boot1_cngetc(struct consdev *cp) { 	return boot1_info_uart_getchar_func(&xlr_boot1_info); }  static void xlr_boot1_cnputc(struct consdev *cp, int c) { 	boot1_info_uart_putchar_func(&xlr_boot1_info, c); }  static int xlr_boot1_cncheckc(struct consdev *cp) { 	return 0; }
endif|#
directive|endif
end_endif

end_unit

