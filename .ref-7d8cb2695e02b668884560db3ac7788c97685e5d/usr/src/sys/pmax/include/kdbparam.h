begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)kdbparam.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine dependent definitions for kdb.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|kdbshorten
parameter_list|(
name|w
parameter_list|)
value|((w)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|kdbbyte
parameter_list|(
name|w
parameter_list|)
value|((w)& 0xFF)
end_define

begin_define
define|#
directive|define
name|kdbitol
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(((b)<< 16) | ((a)& 0xFFFF)))
end_define

begin_define
define|#
directive|define
name|kdbbtol
parameter_list|(
name|a
parameter_list|)
value|((long)(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LPRMODE
value|"%R"
end_define

begin_define
define|#
directive|define
name|OFFMODE
value|"+%R"
end_define

begin_define
define|#
directive|define
name|SETBP
parameter_list|(
name|ins
parameter_list|)
value|MACH_BREAK_BRKPT
end_define

begin_comment
comment|/* return the program counter value modified if we are in a delay slot */
end_comment

begin_define
define|#
directive|define
name|kdbgetpc
parameter_list|(
name|pcb
parameter_list|)
value|(kdbvar[kdbvarchk('t')]< 0 ? \ 	(pcb).pcb_regs[34] + 4 : (pcb).pcb_regs[34])
end_define

begin_define
define|#
directive|define
name|kdbishiddenreg
parameter_list|(
name|p
parameter_list|)
value|((p)>=&kdbreglist[33])
end_define

begin_define
define|#
directive|define
name|kdbisbreak
parameter_list|(
name|type
parameter_list|)
value|(((type)& MACH_CR_EXC_CODE) == 0x24)
end_define

begin_comment
comment|/* check for address wrap around */
end_comment

begin_define
define|#
directive|define
name|kdbaddrwrap
parameter_list|(
name|addr
parameter_list|,
name|newaddr
parameter_list|)
value|(((addr)^(newaddr))>> 31)
end_define

begin_comment
comment|/* declare machine dependent routines defined in kadb.c */
end_comment

begin_decl_stmt
name|void
name|kdbprinttrap
name|__P
argument_list|(
operator|(
name|unsigned
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbsetsstep
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbclrsstep
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbreadc
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbwrite
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbprintins
name|__P
argument_list|(
operator|(
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbstacktrace
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbmalloc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

