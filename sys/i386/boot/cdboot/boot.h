begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1992, 1991 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  *	from: Mach, Revision 2.2  92/04/04  11:35:03  rpd  *	$Id: boot.h,v 1.1 1997/07/11 05:52:38 joerg Exp $  */
end_comment

begin_comment
comment|/*  * Extensions for El Torito CD-ROM booting:  *  * Copyright © 1997 Pluto Technologies International, Inc.  Boulder CO  * Copyright © 1997 interface business GmbH, Dresden.  *      All rights reserved.  *  * This code has been written by Jörg Wunsch, Dresden.  * Direct comments to<joerg_wunsch@interface-business.de>.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * Specification packet per El Torito, BIOS int 0x13 fn 0x4b00/0x4b01  */
end_comment

begin_struct
struct|struct
name|specpacket
block|{
name|u_char
name|size
decl_stmt|;
comment|/* must be 0x13 */
name|u_char
name|mediatype
decl_stmt|;
comment|/* 				 * 0 - no emulation 				 * 1 - 1.2 MB floppy 				 * 2 - 1.44 MB floppy 				 * 3 - 2.88 MB floppy 				 * 4 - hard disk C: 				 */
name|u_char
name|drvno
decl_stmt|;
comment|/* emulated drive number */
name|u_char
name|ctrlindx
decl_stmt|;
comment|/* controller index, see El Torito */
name|u_int32_t
name|lba
decl_stmt|;
comment|/* LBA of emulated disk drive */
name|u_int16_t
name|devspec
decl_stmt|;
comment|/* device specification, see El Torito */
name|u_int16_t
name|ubufseg
decl_stmt|;
comment|/* user buffer segment */
name|u_int16_t
name|loadseg
decl_stmt|;
comment|/* load segment; 0 => use BIOS default 0x7c0 */
name|u_int16_t
name|seccnt
decl_stmt|;
comment|/* number of auto-loaded (virtual) sectors */
name|u_char
name|cyls
decl_stmt|;
comment|/* same values as in int 0x13, fn 8 */
name|u_char
name|secs
decl_stmt|;
name|u_char
name|heads
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Disk address packet for extended BIOS int 0x13 fn's 0x41...0x48.  */
end_comment

begin_struct
struct|struct
name|daddrpacket
block|{
name|u_char
name|size
decl_stmt|;
comment|/* size of daddrpacket, must be 0x10 */
name|u_char
name|reserved1
decl_stmt|;
name|u_char
name|nblocks
decl_stmt|;
comment|/* 				 * number of 512-byte blocks to transfer, 				 * must be<= 127 				 */
name|u_char
name|reserved2
decl_stmt|;
name|u_int16_t
name|boffs
decl_stmt|;
comment|/* bseg:boffs denominate the transfer buffer */
name|u_int16_t
name|bseg
decl_stmt|;
name|u_int32_t
name|lba
decl_stmt|;
comment|/* actually a 64-bit type, but 64-bit arith */
name|u_int32_t
name|lbahigh
decl_stmt|;
comment|/* is expensive, and we don't really need it */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|)
value|printf x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* asm.S */
end_comment

begin_if
if|#
directive|if
name|ASM_ONLY
end_if

begin_function_decl
name|void
name|real_to_prot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prot_to_real
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|startprog
parameter_list|(
name|unsigned
name|int
name|physaddr
parameter_list|,
name|int
name|howto
parameter_list|,
name|int
name|bootdev
parameter_list|,
comment|/* XXX struct bootinfo * */
name|unsigned
name|int
name|bootinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pbzero
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcpy
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bios.S */
end_comment

begin_function_decl
name|int
name|biosread
parameter_list|(
name|int
name|dev
parameter_list|,
name|int
name|cyl
parameter_list|,
name|int
name|head
parameter_list|,
name|int
name|sec
parameter_list|,
name|int
name|nsec
parameter_list|,
name|void
modifier|*
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getbootspec
parameter_list|(
name|struct
name|specpacket
modifier|*
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|biosreadlba
parameter_list|(
name|struct
name|daddrpacket
modifier|*
name|daddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putc
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ischar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_diskinfo
parameter_list|(
name|int
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memsize
parameter_list|(
name|int
name|extended
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* boot.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|loadflags
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|boot
parameter_list|(
name|int
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* boot2.S */
end_comment

begin_function_decl
name|void
name|boot2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cdrom.c */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|sessionstart
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|devopen
parameter_list|(
name|u_int32_t
name|session
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seek
parameter_list|(
name|u_int32_t
name|offs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read
parameter_list|(
name|u_char
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xread
parameter_list|(
name|u_char
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openrd
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* io.c */
end_comment

begin_function_decl
name|void
name|gateA20
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putchar
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delay1ms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gets
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bcopy
parameter_list|(
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|void
modifier|*
name|to
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|twiddle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* probe_keyboard.c */
end_comment

begin_function_decl
name|int
name|probe_keyboard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* serial.S */
end_comment

begin_function_decl
name|void
name|serial_putc
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|serial_getc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|serial_ischar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_serial
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* table.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|devs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|tw_chars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* malloc.c */
end_comment

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
name|chunk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* linker stuff */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|end
decl_stmt|;
end_decl_stmt

end_unit

