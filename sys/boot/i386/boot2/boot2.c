begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms are freely  * permitted provided that the above copyright notice and this  * paragraph and the following disclaimer are duplicated in all  * such forms.  *  * This software is provided "AS IS" and without any express or  * implied warranties, including, without limitation, the implied  * warranties of merchantability and fitness for a particular  * purpose.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/diskslice.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/diskmbr.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<btxv86.h>
end_include

begin_include
include|#
directive|include
file|"boot2.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_define
define|#
directive|define
name|IO_KEYBOARD
value|1
end_define

begin_define
define|#
directive|define
name|IO_SERIAL
value|2
end_define

begin_define
define|#
directive|define
name|SECOND
value|18
end_define

begin_comment
comment|/* Circa that many ticks in a second. */
end_comment

begin_define
define|#
directive|define
name|RBX_ASKNAME
value|0x0
end_define

begin_comment
comment|/* -a */
end_comment

begin_define
define|#
directive|define
name|RBX_SINGLE
value|0x1
end_define

begin_comment
comment|/* -s */
end_comment

begin_define
define|#
directive|define
name|RBX_DFLTROOT
value|0x5
end_define

begin_comment
comment|/* -r */
end_comment

begin_define
define|#
directive|define
name|RBX_KDB
value|0x6
end_define

begin_comment
comment|/* -d */
end_comment

begin_define
define|#
directive|define
name|RBX_CONFIG
value|0xa
end_define

begin_comment
comment|/* -c */
end_comment

begin_define
define|#
directive|define
name|RBX_VERBOSE
value|0xb
end_define

begin_comment
comment|/* -v */
end_comment

begin_define
define|#
directive|define
name|RBX_SERIAL
value|0xc
end_define

begin_comment
comment|/* -h */
end_comment

begin_define
define|#
directive|define
name|RBX_CDROM
value|0xd
end_define

begin_comment
comment|/* -C */
end_comment

begin_define
define|#
directive|define
name|RBX_GDB
value|0xf
end_define

begin_comment
comment|/* -g */
end_comment

begin_define
define|#
directive|define
name|RBX_MUTE
value|0x10
end_define

begin_comment
comment|/* -m */
end_comment

begin_define
define|#
directive|define
name|RBX_PAUSE
value|0x12
end_define

begin_comment
comment|/* -p */
end_comment

begin_define
define|#
directive|define
name|RBX_DUAL
value|0x1d
end_define

begin_comment
comment|/* -D */
end_comment

begin_define
define|#
directive|define
name|RBX_PROBEKBD
value|0x1e
end_define

begin_comment
comment|/* -P */
end_comment

begin_define
define|#
directive|define
name|RBX_NOINTR
value|0x1f
end_define

begin_comment
comment|/* -n */
end_comment

begin_define
define|#
directive|define
name|RBX_MASK
value|0x2005ffff
end_define

begin_define
define|#
directive|define
name|PATH_CONFIG
value|"/boot.config"
end_define

begin_define
define|#
directive|define
name|PATH_BOOT3
value|"/boot/loader"
end_define

begin_define
define|#
directive|define
name|PATH_KERNEL
value|"/kernel"
end_define

begin_define
define|#
directive|define
name|ARGS
value|0x900
end_define

begin_define
define|#
directive|define
name|NOPT
value|14
end_define

begin_define
define|#
directive|define
name|NDEV
value|5
end_define

begin_define
define|#
directive|define
name|MEM_BASE
value|0x12
end_define

begin_define
define|#
directive|define
name|MEM_EXT
value|0x15
end_define

begin_define
define|#
directive|define
name|V86_CY
parameter_list|(
name|x
parameter_list|)
value|((x)& 1)
end_define

begin_define
define|#
directive|define
name|V86_ZR
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x40)
end_define

begin_define
define|#
directive|define
name|DRV_HARD
value|0x80
end_define

begin_define
define|#
directive|define
name|DRV_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|TYPE_AD
value|0
end_define

begin_define
define|#
directive|define
name|TYPE_DA
value|2
end_define

begin_define
define|#
directive|define
name|TYPE_MAXHARD
value|TYPE_DA
end_define

begin_define
define|#
directive|define
name|TYPE_FD
value|4
end_define

begin_decl_stmt
specifier|extern
name|uint32_t
name|_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|optstr
index|[
name|NOPT
index|]
init|=
literal|"DhaCcdgmnPprsv"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|char
name|flags
index|[
name|NOPT
index|]
init|=
block|{
name|RBX_DUAL
block|,
name|RBX_SERIAL
block|,
name|RBX_ASKNAME
block|,
name|RBX_CDROM
block|,
name|RBX_CONFIG
block|,
name|RBX_KDB
block|,
name|RBX_GDB
block|,
name|RBX_MUTE
block|,
name|RBX_NOINTR
block|,
name|RBX_PROBEKBD
block|,
name|RBX_PAUSE
block|,
name|RBX_DFLTROOT
block|,
name|RBX_SINGLE
block|,
name|RBX_VERBOSE
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|dev_nm
index|[
name|NDEV
index|]
init|=
block|{
literal|"ad"
block|,
literal|"wd"
block|,
literal|"da"
block|,
literal|"  "
block|,
literal|"fd"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|char
name|dev_maj
index|[
name|NDEV
index|]
init|=
block|{
literal|30
block|,
literal|0
block|,
literal|4
block|,
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_struct
specifier|static
struct|struct
name|dsk
block|{
name|unsigned
name|drive
decl_stmt|;
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|unit
decl_stmt|;
name|unsigned
name|slice
decl_stmt|;
name|unsigned
name|part
decl_stmt|;
name|unsigned
name|start
decl_stmt|;
name|int
name|init
decl_stmt|;
block|}
name|dsk
struct|;
end_struct

begin_decl_stmt
specifier|static
name|char
name|cmd
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|kname
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint32_t
name|opts
init|=
name|RB_BOOTINFO
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|bootinfo
name|bootinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint8_t
name|ioctrl
init|=
name|IO_KEYBOARD
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|load
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|parse
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|xfsread
parameter_list|(
name|ino_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|dskread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|putchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|uint32_t
name|memsize
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|drvread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|keyhit
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|xputc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|xgetc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|getc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|memcpy
value|__builtin_memcpy
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|static
name|void
name|memcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|memcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|len
parameter_list|)
block|{
while|while
condition|(
name|len
operator|--
condition|)
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
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
block|{
for|for
control|(
init|;
operator|*
name|s1
operator|==
operator|*
name|s2
operator|&&
operator|*
name|s1
condition|;
name|s1
operator|++
operator|,
name|s2
operator|++
control|)
empty_stmt|;
return|return
operator|(
name|u_char
operator|)
operator|*
name|s1
operator|-
operator|(
name|u_char
operator|)
operator|*
name|s2
return|;
block|}
end_function

begin_include
include|#
directive|include
file|"ufsread.c"
end_include

begin_function
specifier|static
name|int
name|xfsread
parameter_list|(
name|ino_t
name|inode
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbyte
parameter_list|)
block|{
if|if
condition|(
name|fsread
argument_list|(
name|inode
argument_list|,
name|buf
argument_list|,
name|nbyte
argument_list|)
operator|!=
name|nbyte
condition|)
block|{
name|printf
argument_list|(
literal|"Invalid %s\n"
argument_list|,
literal|"format"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|getstr
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|c
decl_stmt|;
name|s
operator|=
name|str
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
switch|switch
condition|(
name|c
operator|=
name|xgetc
argument_list|(
literal|0
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
break|break;
case|case
literal|'\177'
case|:
name|c
operator|=
literal|'\b'
expr_stmt|;
case|case
literal|'\b'
case|:
if|if
condition|(
name|s
operator|>
name|str
condition|)
block|{
name|s
operator|--
expr_stmt|;
name|putchar
argument_list|(
literal|'\b'
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
else|else
name|c
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'\n'
case|:
case|case
literal|'\r'
case|:
operator|*
name|s
operator|=
literal|0
expr_stmt|;
return|return;
default|default:
if|if
condition|(
name|s
operator|-
name|str
operator|<
name|size
operator|-
literal|1
condition|)
operator|*
name|s
operator|++
operator|=
name|c
expr_stmt|;
block|}
if|if
condition|(
name|c
condition|)
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|putc
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|v86
operator|.
name|addr
operator|=
literal|0x10
expr_stmt|;
name|v86
operator|.
name|eax
operator|=
literal|0xe00
operator||
operator|(
name|c
operator|&
literal|0xff
operator|)
expr_stmt|;
name|v86
operator|.
name|ebx
operator|=
literal|0x7
expr_stmt|;
name|v86int
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|autoboot
decl_stmt|;
name|ino_t
name|ino
decl_stmt|;
name|dmadat
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|roundup2
argument_list|(
name|__base
operator|+
operator|(
name|int32_t
operator|)
operator|&
name|_end
argument_list|,
literal|0x10000
argument_list|)
operator|-
name|__base
operator|)
expr_stmt|;
name|v86
operator|.
name|ctl
operator|=
name|V86_FLAGS
expr_stmt|;
name|dsk
operator|.
name|drive
operator|=
operator|*
operator|(
name|uint8_t
operator|*
operator|)
name|PTOV
argument_list|(
name|ARGS
argument_list|)
expr_stmt|;
name|dsk
operator|.
name|type
operator|=
name|dsk
operator|.
name|drive
operator|&
name|DRV_HARD
condition|?
name|TYPE_AD
else|:
name|TYPE_FD
expr_stmt|;
name|dsk
operator|.
name|unit
operator|=
name|dsk
operator|.
name|drive
operator|&
name|DRV_MASK
expr_stmt|;
name|dsk
operator|.
name|slice
operator|=
operator|*
operator|(
name|uint8_t
operator|*
operator|)
name|PTOV
argument_list|(
name|ARGS
operator|+
literal|1
argument_list|)
operator|+
literal|1
expr_stmt|;
name|bootinfo
operator|.
name|bi_version
operator|=
name|BOOTINFO_VERSION
expr_stmt|;
name|bootinfo
operator|.
name|bi_size
operator|=
sizeof|sizeof
argument_list|(
name|bootinfo
argument_list|)
expr_stmt|;
name|bootinfo
operator|.
name|bi_basemem
operator|=
literal|0
expr_stmt|;
comment|/* XXX will be filled by loader or kernel */
name|bootinfo
operator|.
name|bi_extmem
operator|=
name|memsize
argument_list|(
name|MEM_EXT
argument_list|)
expr_stmt|;
name|bootinfo
operator|.
name|bi_memsizes_valid
operator|++
expr_stmt|;
comment|/* Process configuration file */
name|autoboot
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|(
name|ino
operator|=
name|lookup
argument_list|(
name|PATH_CONFIG
argument_list|)
operator|)
condition|)
name|fsread
argument_list|(
name|ino
argument_list|,
name|cmd
argument_list|,
sizeof|sizeof
argument_list|(
name|cmd
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|cmd
condition|)
block|{
name|printf
argument_list|(
literal|"%s: %s"
argument_list|,
name|PATH_CONFIG
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
if|if
condition|(
name|parse
argument_list|(
name|cmd
argument_list|)
condition|)
name|autoboot
operator|=
literal|0
expr_stmt|;
comment|/* Do not process this command twice */
operator|*
name|cmd
operator|=
literal|0
expr_stmt|;
block|}
comment|/*      * Try to exec stage 3 boot loader. If interrupted by a keypress,      * or in case of failure, try to load a kernel directly instead.      */
if|if
condition|(
name|autoboot
operator|&&
operator|!
operator|*
name|kname
condition|)
block|{
name|memcpy
argument_list|(
name|kname
argument_list|,
name|PATH_BOOT3
argument_list|,
sizeof|sizeof
argument_list|(
name|PATH_BOOT3
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|keyhit
argument_list|(
literal|3
operator|*
name|SECOND
argument_list|)
condition|)
block|{
name|load
argument_list|(
name|kname
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|kname
argument_list|,
name|PATH_KERNEL
argument_list|,
sizeof|sizeof
argument_list|(
name|PATH_KERNEL
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Present the user with the boot2 prompt. */
for|for
control|(
init|;
condition|;
control|)
block|{
ifdef|#
directive|ifdef
name|UFS1_ONLY
name|printf
argument_list|(
literal|" \n>> FreeBSD/i386/UFS1 BOOT\n"
else|#
directive|else
argument|printf(
literal|" \n>> FreeBSD/i386/UFS[12] BOOT\n"
endif|#
directive|endif
literal|"Default: %u:%s(%u,%c)%s\n"
literal|"boot: "
argument|, 	       dsk.drive& DRV_MASK, dev_nm[dsk.type], dsk.unit,
literal|'a'
argument|+ dsk.part, kname); 	if (ioctrl& IO_SERIAL) 	    sio_flush(); 	if (!autoboot || keyhit(
literal|5
argument|*SECOND)) 	    getstr(cmd, sizeof(cmd)); 	else 	    putchar(
literal|'\n'
argument|); 	autoboot =
literal|0
argument|; 	if (parse(cmd)) 	    putchar(
literal|'\a'
argument|);  	else 	    load(kname);     } }
comment|/* XXX - Needed for btxld to link the boot2 binary; do not remove. */
argument|void exit(int x) { }  static void load(const char *fname) {     union { 	struct exec ex; 	Elf32_Ehdr eh;     } hdr;     Elf32_Phdr ep[
literal|2
argument|];     Elf32_Shdr es[
literal|2
argument|];     caddr_t p;     ino_t ino;     uint32_t addr
argument_list|,
argument|x;     int fmt
argument_list|,
argument|i
argument_list|,
argument|j;      if (!(ino = lookup(fname))) { 	if (!ls) 	    printf(
literal|"No %s\n"
argument|, fname); 	return;     }     if (xfsread(ino,&hdr, sizeof(hdr))) 	return;     if (N_GETMAGIC(hdr.ex) == ZMAGIC) 	fmt =
literal|0
argument|;     else if (IS_ELF(hdr.eh)) 	fmt =
literal|1
argument|;     else { 	printf(
literal|"Invalid %s\n"
argument|,
literal|"format"
argument|); 	return;     }     if (fmt ==
literal|0
argument|) { 	addr = hdr.ex.a_entry&
literal|0xffffff
argument|; 	p = PTOV(addr); 	fs_off = PAGE_SIZE; 	if (xfsread(ino, p, hdr.ex.a_text)) 	    return; 	p += roundup2(hdr.ex.a_text, PAGE_SIZE); 	if (xfsread(ino, p, hdr.ex.a_data)) 	    return; 	p += hdr.ex.a_data + roundup2(hdr.ex.a_bss, PAGE_SIZE); 	bootinfo.bi_symtab = VTOP(p); 	memcpy(p, (char *)&hdr.ex.a_syms, sizeof(hdr.ex.a_syms)); 	p += sizeof(hdr.ex.a_syms); 	if (hdr.ex.a_syms) { 	    if (xfsread(ino, p, hdr.ex.a_syms)) 		return; 	    p += hdr.ex.a_syms; 	    if (xfsread(ino, p, sizeof(int))) 		return; 	    x = *(uint32_t *)p; 	    p += sizeof(int); 	    x -= sizeof(int); 	    if (xfsread(ino, p, x)) 		return; 	    p += x; 	}     } else { 	fs_off = hdr.eh.e_phoff; 	for (j = i =
literal|0
argument|; i< hdr.eh.e_phnum&& j<
literal|2
argument|; i++) { 	    if (xfsread(ino, ep + j, sizeof(ep[
literal|0
argument|]))) 		return; 	    if (ep[j].p_type == PT_LOAD) 		j++; 	} 	for (i =
literal|0
argument|; i<
literal|2
argument|; i++) { 	    p = PTOV(ep[i].p_paddr&
literal|0xffffff
argument|); 	    fs_off = ep[i].p_offset; 	    if (xfsread(ino, p, ep[i].p_filesz)) 		return; 	} 	p += roundup2(ep[
literal|1
argument|].p_memsz, PAGE_SIZE); 	bootinfo.bi_symtab = VTOP(p); 	if (hdr.eh.e_shnum == hdr.eh.e_shstrndx +
literal|3
argument|) { 	    fs_off = hdr.eh.e_shoff + sizeof(es[
literal|0
argument|]) * 		(hdr.eh.e_shstrndx +
literal|1
argument|); 	    if (xfsread(ino,&es, sizeof(es))) 		return; 	    for (i =
literal|0
argument|; i<
literal|2
argument|; i++) { 		memcpy(p, (char *)&es[i].sh_size, sizeof(es[i].sh_size)); 		p += sizeof(es[i].sh_size); 		fs_off = es[i].sh_offset; 		if (xfsread(ino, p, es[i].sh_size)) 		    return; 		p += es[i].sh_size; 	    } 	} 	addr = hdr.eh.e_entry&
literal|0xffffff
argument|;     }     bootinfo.bi_esymtab = VTOP(p);     bootinfo.bi_kernelname = VTOP(fname);     bootinfo.bi_bios_dev = dsk.drive;     __exec((caddr_t)addr, opts& RBX_MASK, 	   MAKEBOOTDEV(dev_maj[dsk.type],
literal|0
argument|, dsk.slice, dsk.unit, dsk.part),
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, VTOP(&bootinfo)); }  static int parse(char *arg) {     char *p
argument_list|,
argument|*q;     int drv
argument_list|,
argument|c
argument_list|,
argument|i;      while ((c = *arg++)) { 	if (c ==
literal|' '
argument||| c ==
literal|'\t'
argument||| c ==
literal|'\n'
argument|) 	    continue; 	for (p = arg; *p&& *p !=
literal|'\n'
argument|&& *p !=
literal|' '
argument|&& *p !=
literal|'\t'
argument|; p++); 	if (*p) 	    *p++ =
literal|0
argument|; 	if (c ==
literal|'-'
argument|) { 	    while ((c = *arg++)) { 		for (i =
literal|0
argument|; c != optstr[i]; i++) 		    if (i == NOPT -
literal|1
argument|) 			return -
literal|1
argument|; 		opts ^=
literal|1
argument|<< flags[i]; 	    } 	    if (opts&
literal|1
argument|<< RBX_PROBEKBD) { 		i = *(uint8_t *)PTOV(
literal|0x496
argument|)&
literal|0x10
argument|;
comment|/* printf("Keyboard: %s\n", i ? "yes" : "no"); */
argument|if (!i) 		    opts |=
literal|1
argument|<< RBX_DUAL |
literal|1
argument|<< RBX_SERIAL; 		opts&= ~(
literal|1
argument|<< RBX_PROBEKBD); 	    } 	    ioctrl = opts&
literal|1
argument|<< RBX_DUAL ? (IO_SERIAL|IO_KEYBOARD) : 		     opts&
literal|1
argument|<< RBX_SERIAL ? IO_SERIAL : IO_KEYBOARD; 	    if (ioctrl& IO_SERIAL) 	        sio_init(); 	} else { 	    for (q = arg--; *q&& *q !=
literal|'('
argument|; q++); 	    if (*q) { 		drv = -
literal|1
argument|; 		if (arg[
literal|1
argument|] ==
literal|':'
argument|) { 		    if (*arg<
literal|'0'
argument||| *arg>
literal|'9'
argument|) 			return -
literal|1
argument|; 		    drv = *arg -
literal|'0'
argument|; 		    arg +=
literal|2
argument|; 		} 		if (q - arg !=
literal|2
argument|) 		    return -
literal|1
argument|; 		for (i =
literal|0
argument|; arg[
literal|0
argument|] != dev_nm[i][
literal|0
argument|] || 			    arg[
literal|1
argument|] != dev_nm[i][
literal|1
argument|]; i++) 		    if (i == NDEV -
literal|1
argument|) 			return -
literal|1
argument|; 		dsk.type = i; 		arg +=
literal|3
argument|; 		if (arg[
literal|1
argument|] !=
literal|','
argument||| *arg<
literal|'0'
argument||| *arg>
literal|'9'
argument|) 		    return -
literal|1
argument|; 		dsk.unit = *arg -
literal|'0'
argument|; 		arg +=
literal|2
argument|; 		dsk.slice = WHOLE_DISK_SLICE; 		if (arg[
literal|1
argument|] ==
literal|','
argument|) { 		    if (*arg<
literal|'0'
argument||| *arg>
literal|'0'
argument|+ NDOSPART) 			return -
literal|1
argument|; 		    if ((dsk.slice = *arg -
literal|'0'
argument|)) 			dsk.slice++; 		    arg +=
literal|2
argument|; 		} 		if (arg[
literal|1
argument|] !=
literal|')'
argument||| *arg<
literal|'a'
argument||| *arg>
literal|'p'
argument|) 		    return -
literal|1
argument|; 		dsk.part = *arg -
literal|'a'
argument|; 		arg +=
literal|2
argument|; 		if (drv == -
literal|1
argument|) 		    drv = dsk.unit; 		dsk.drive = (dsk.type<= TYPE_MAXHARD 			     ? DRV_HARD :
literal|0
argument|) + drv; 		dsk_meta =
literal|0
argument|; 		fsread(
literal|0
argument|, NULL,
literal|0
argument|); 	    } 	    if ((i = p - arg - !*(p -
literal|1
argument|))) { 		if (i>= sizeof(kname)) 		    return -
literal|1
argument|; 		memcpy(kname, arg, i +
literal|1
argument|); 	    } 	} 	arg = p;     }     return
literal|0
argument|; }  static int dskread(void *buf, unsigned lba, unsigned nblk) {     struct dos_partition *dp;     struct disklabel *d;     char *sec;     unsigned sl
argument_list|,
argument|i;      if (!dsk_meta) { 	sec = dmadat->secbuf; 	dsk.start =
literal|0
argument|; 	if (drvread(sec, DOSBBSECTOR,
literal|1
argument|)) 	    return -
literal|1
argument|; 	dp = (void *)(sec + DOSPARTOFF); 	sl = dsk.slice; 	if (sl< BASE_SLICE) { 	    for (i =
literal|0
argument|; i< NDOSPART; i++) 		if (dp[i].dp_typ == DOSPTYP_386BSD&& 		    (dp[i].dp_flag&
literal|0x80
argument||| sl< BASE_SLICE)) { 		    sl = BASE_SLICE + i; 		    if (dp[i].dp_flag&
literal|0x80
argument||| 			dsk.slice == COMPATIBILITY_SLICE) 			break; 		} 	    if (dsk.slice == WHOLE_DISK_SLICE) 		dsk.slice = sl; 	} 	if (sl != WHOLE_DISK_SLICE) { 	    if (sl != COMPATIBILITY_SLICE) 		dp += sl - BASE_SLICE; 	    if (dp->dp_typ != DOSPTYP_386BSD) { 		printf(
literal|"Invalid %s\n"
argument|,
literal|"slice"
argument|); 		return -
literal|1
argument|; 	    } 	    dsk.start = dp->dp_start; 	} 	if (drvread(sec, dsk.start + LABELSECTOR,
literal|1
argument|)) 		return -
literal|1
argument|; 	d = (void *)(sec + LABELOFFSET); 	if (d->d_magic != DISKMAGIC || d->d_magic2 != DISKMAGIC) { 	    if (dsk.part != RAW_PART) { 		printf(
literal|"Invalid %s\n"
argument|,
literal|"label"
argument|); 		return -
literal|1
argument|; 	    } 	} else { 	    if (!dsk.init) { 		if (d->d_type == DTYPE_SCSI) 		    dsk.type = TYPE_DA; 		dsk.init++; 	    } 	    if (dsk.part>= d->d_npartitions || 		!d->d_partitions[dsk.part].p_size) { 		printf(
literal|"Invalid %s\n"
argument|,
literal|"partition"
argument|); 		return -
literal|1
argument|; 	    } 	    dsk.start += d->d_partitions[dsk.part].p_offset; 	    dsk.start -= d->d_partitions[RAW_PART].p_offset; 	}     }     return drvread(buf, dsk.start + lba, nblk); }  static void printf(const char *fmt,...) {     static const char digits[
literal|16
argument|] =
literal|"0123456789abcdef"
argument|;     va_list ap;     char buf[
literal|10
argument|];     char *s;     unsigned r
argument_list|,
argument|u;     int c;      va_start(ap, fmt);     while ((c = *fmt++)) { 	if (c ==
literal|'%'
argument|) { 	    c = *fmt++; 	    switch (c) { 	    case
literal|'c'
argument|: 		putchar(va_arg(ap, int)); 		continue; 	    case
literal|'s'
argument|: 		for (s = va_arg(ap, char *); *s; s++) 		    putchar(*s); 		continue; 	    case
literal|'u'
argument|: 	    case
literal|'x'
argument|: 		r = c ==
literal|'u'
argument|?
literal|10U
argument|:
literal|16U
argument|; 		u = va_arg(ap, unsigned); 		s = buf; 		do 		    *s++ = digits[u % r]; 		while (u /= r); 		while (--s>= buf) 		    putchar(*s); 		continue; 	    } 	} 	putchar(c);     }     va_end(ap);     return; }  static void putchar(int c) {     if (c ==
literal|'\n'
argument|) 	xputc(
literal|'\r'
argument|);     xputc(c); }  static uint32_t memsize(int type) {     v86.addr = type;     v86.eax =
literal|0x8800
argument|;     v86int();     return v86.eax; }  static int drvread(void *buf, unsigned lba, unsigned nblk) {     static unsigned c =
literal|0x2d5c7c2f
argument|;      printf(
literal|"%c\b"
argument|, c = c<<
literal|8
argument|| c>>
literal|24
argument|);     v86.ctl = V86_ADDR | V86_CALLF | V86_FLAGS;     v86.addr = XREADORG;
comment|/* call to xread in boot1 */
argument|v86.es = VTOPSEG(buf);     v86.eax = lba;     v86.ebx = VTOPOFF(buf);     v86.ecx = lba>>
literal|16
argument|;     v86.edx = nblk<<
literal|8
argument|| dsk.drive;     v86int();     v86.ctl = V86_FLAGS;     if (V86_CY(v86.efl)) { 	printf(
literal|"Disk error 0x%x lba 0x%x\n"
argument|, v86.eax>>
literal|8
argument|&
literal|0xff
argument|, lba); 	return -
literal|1
argument|;     }     return
literal|0
argument|; }  static int keyhit(unsigned ticks) {     uint32_t t0
argument_list|,
argument|t1;      if (opts&
literal|1
argument|<< RBX_NOINTR) 	return
literal|0
argument|;     t0 =
literal|0
argument|;     for (;;) { 	if (xgetc(
literal|1
argument|)) 	    return
literal|1
argument|; 	t1 = *(uint32_t *)PTOV(
literal|0x46c
argument|); 	if (!t0) 	    t0 = t1; 	if (t1< t0 || t1>= t0 + ticks) 	    return
literal|0
argument|;     } }  static int xputc(int c) {     if (ioctrl& IO_KEYBOARD) 	putc(c);     if (ioctrl& IO_SERIAL) 	sio_putc(c);     return c; }  static int xgetc(int fn) {     if (opts&
literal|1
argument|<< RBX_NOINTR) 	return
literal|0
argument|;     for (;;) { 	if (ioctrl& IO_KEYBOARD&& getc(
literal|1
argument|)) 	    return fn ?
literal|1
argument|: getc(
literal|0
argument|); 	if (ioctrl& IO_SERIAL&& sio_ischar()) 	    return fn ?
literal|1
argument|: sio_getc(); 	if (fn) 	    return
literal|0
argument|;     } }  static int getc(int fn) {     v86.addr =
literal|0x16
argument|;     v86.eax = fn<<
literal|8
argument|;     v86int();     return fn ==
literal|0
argument|? v86.eax&
literal|0xff
argument|: !V86_ZR(v86.efl); }
end_function

end_unit

