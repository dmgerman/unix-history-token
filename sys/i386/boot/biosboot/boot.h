begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1992, 1991 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  *	from: Mach, Revision 2.2  92/04/04  11:35:03  rpd  *	$Id: boot.h,v 1.21 1997/08/31 06:11:26 phk Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/quota.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/inode.h>
end_include

begin_define
define|#
directive|define
name|RB_DUAL
value|0x40000
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|RB_PROBEKBD
value|0x80000
end_define

begin_comment
comment|/* XXX */
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
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs
modifier|*
name|fs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|inode
name|inode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dosdev
decl_stmt|,
name|unit
decl_stmt|,
name|slice
decl_stmt|,
name|part
decl_stmt|,
name|maj
decl_stmt|,
name|boff
decl_stmt|,
name|poff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|tw_chars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|loadflags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|disklabel
name|disklabel
decl_stmt|;
end_decl_stmt

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

begin_function_decl
name|void
name|vesa_mode
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* boot.c */
end_comment

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
comment|/* disk.c */
end_comment

begin_function_decl
name|int
name|devopen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devread
parameter_list|(
name|char
modifier|*
name|iodest
parameter_list|,
name|int
name|sector
parameter_list|,
name|int
name|cnt
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

begin_ifndef
ifndef|#
directive|ifndef
name|CDBOOT
end_ifndef

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CDBOOT */
end_comment

begin_function_decl
name|int
name|strncasecmp
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
parameter_list|,
name|size_t
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CDBOOT */
end_comment

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
comment|/* sys.c */
end_comment

begin_function_decl
name|void
name|xread
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openrd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

