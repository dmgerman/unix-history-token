begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)isa.c	7.2 (Berkeley) 5/13/91  */
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
file|"opt_mca.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_MCA
end_ifdef

begin_include
include|#
directive|include
file|<i386/bios/mca_machdep.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|NMI_PARITY
value|0x04
end_define

begin_define
define|#
directive|define
name|NMI_EPARITY
value|0x02
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NMI_PARITY
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|NMI_IOCHAN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ENMI_WATCHDOG
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ENMI_BUSTIMER
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ENMI_IOSTATUS
value|(1<< 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Handle a NMI, possibly a machine check.  * return true to panic system, false to ignore.  */
end_comment

begin_function
name|int
name|isa_nmi
parameter_list|(
name|int
name|cd
parameter_list|)
block|{
name|int
name|retval
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|PC98
name|int
name|port
init|=
name|inb
argument_list|(
literal|0x33
argument_list|)
decl_stmt|;
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"NMI PC98 port = %x\n"
argument_list|,
name|port
argument_list|)
expr_stmt|;
if|if
condition|(
name|epson_machine_id
operator|==
literal|0x20
condition|)
name|epson_outb
argument_list|(
literal|0xc16
argument_list|,
name|epson_inb
argument_list|(
literal|0xc16
argument_list|)
operator||
literal|0x1
argument_list|)
expr_stmt|;
if|if
condition|(
name|port
operator|&
name|NMI_PARITY
condition|)
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"BASE RAM parity error, likely hardware failure."
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|port
operator|&
name|NMI_EPARITY
condition|)
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"EXTENDED RAM parity error, likely hardware failure."
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"\nNMI Resume ??\n"
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* IBM-PC */
name|int
name|isa_port
init|=
name|inb
argument_list|(
literal|0x61
argument_list|)
decl_stmt|;
name|int
name|eisa_port
init|=
name|inb
argument_list|(
literal|0x461
argument_list|)
decl_stmt|;
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"NMI ISA %x, EISA %x\n"
argument_list|,
name|isa_port
argument_list|,
name|eisa_port
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEV_MCA
if|if
condition|(
name|MCA_system
operator|&&
name|mca_bus_nmi
argument_list|()
condition|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
if|if
condition|(
name|isa_port
operator|&
name|NMI_PARITY
condition|)
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"RAM parity error, likely hardware failure."
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|isa_port
operator|&
name|NMI_IOCHAN
condition|)
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"I/O channel check, likely hardware failure."
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
comment|/* 	 * On a real EISA machine, this will never happen.  However it can 	 * happen on ISA machines which implement XT style floating point 	 * error handling (very rare).  Save them from a meaningless panic. 	 */
if|if
condition|(
name|eisa_port
operator|==
literal|0xff
condition|)
return|return
operator|(
name|retval
operator|)
return|;
if|if
condition|(
name|eisa_port
operator|&
name|ENMI_WATCHDOG
condition|)
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"EISA watchdog timer expired, likely hardware failure."
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|eisa_port
operator|&
name|ENMI_BUSTIMER
condition|)
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"EISA bus timeout, likely hardware failure."
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|eisa_port
operator|&
name|ENMI_IOSTATUS
condition|)
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"EISA I/O port status error."
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

end_unit

