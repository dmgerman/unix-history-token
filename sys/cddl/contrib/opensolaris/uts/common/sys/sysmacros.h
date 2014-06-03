begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSMACROS_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSMACROS_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/isa_defs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Some macros for units conversion  */
comment|/*  * Disk blocks (sectors) and bytes.  */
define|#
directive|define
name|dtob
parameter_list|(
name|DD
parameter_list|)
value|((DD)<< DEV_BSHIFT)
define|#
directive|define
name|btod
parameter_list|(
name|BB
parameter_list|)
value|(((BB) + DEV_BSIZE - 1)>> DEV_BSHIFT)
define|#
directive|define
name|btodt
parameter_list|(
name|BB
parameter_list|)
value|((BB)>> DEV_BSHIFT)
define|#
directive|define
name|lbtod
parameter_list|(
name|BB
parameter_list|)
value|(((offset_t)(BB) + DEV_BSIZE - 1)>> DEV_BSHIFT)
comment|/* common macros */
ifndef|#
directive|ifndef
name|MIN
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MAX
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
endif|#
directive|endif
ifndef|#
directive|ifndef
name|ABS
define|#
directive|define
name|ABS
parameter_list|(
name|a
parameter_list|)
value|((a)< 0 ? -(a) : (a))
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SIGNOF
define|#
directive|define
name|SIGNOF
parameter_list|(
name|a
parameter_list|)
value|((a)< 0 ? -1 : (a)> 0)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*  * Convert a single byte to/from binary-coded decimal (BCD).  */
specifier|extern
name|unsigned
name|char
name|byte_to_bcd
index|[
literal|256
index|]
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|bcd_to_byte
index|[
literal|256
index|]
decl_stmt|;
define|#
directive|define
name|BYTE_TO_BCD
parameter_list|(
name|x
parameter_list|)
value|byte_to_bcd[(x)& 0xff]
define|#
directive|define
name|BCD_TO_BYTE
parameter_list|(
name|x
parameter_list|)
value|bcd_to_byte[(x)& 0xff]
endif|#
directive|endif
comment|/* _KERNEL */
comment|/*  * WARNING: The device number macros defined here should not be used by device  * drivers or user software. Device drivers should use the device functions  * defined in the DDI/DKI interface (see also ddi.h). Application software  * should make use of the library routines available in makedev(3). A set of  * new device macros are provided to operate on the expanded device number  * format supported in SVR4. Macro versions of the DDI device functions are  * provided for use by kernel proper routines only. Macro routines bmajor(),  * major(), minor(), emajor(), eminor(), and makedev() will be removed or  * their definitions changed at the next major release following SVR4.  */
define|#
directive|define
name|O_BITSMAJOR
value|7
comment|/* # of SVR3 major device bits */
define|#
directive|define
name|O_BITSMINOR
value|8
comment|/* # of SVR3 minor device bits */
define|#
directive|define
name|O_MAXMAJ
value|0x7f
comment|/* SVR3 max major value */
define|#
directive|define
name|O_MAXMIN
value|0xff
comment|/* SVR3 max minor value */
define|#
directive|define
name|L_BITSMAJOR32
value|14
comment|/* # of SVR4 major device bits */
define|#
directive|define
name|L_BITSMINOR32
value|18
comment|/* # of SVR4 minor device bits */
define|#
directive|define
name|L_MAXMAJ32
value|0x3fff
comment|/* SVR4 max major value */
define|#
directive|define
name|L_MAXMIN32
value|0x3ffff
comment|/* MAX minor for 3b2 software drivers. */
comment|/* For 3b2 hardware devices the minor is */
comment|/* restricted to 256 (0-255) */
ifdef|#
directive|ifdef
name|_LP64
define|#
directive|define
name|L_BITSMAJOR
value|32
comment|/* # of major device bits in 64-bit Solaris */
define|#
directive|define
name|L_BITSMINOR
value|32
comment|/* # of minor device bits in 64-bit Solaris */
define|#
directive|define
name|L_MAXMAJ
value|0xfffffffful
comment|/* max major value */
define|#
directive|define
name|L_MAXMIN
value|0xfffffffful
comment|/* max minor value */
else|#
directive|else
define|#
directive|define
name|L_BITSMAJOR
value|L_BITSMAJOR32
define|#
directive|define
name|L_BITSMINOR
value|L_BITSMINOR32
define|#
directive|define
name|L_MAXMAJ
value|L_MAXMAJ32
define|#
directive|define
name|L_MAXMIN
value|L_MAXMIN32
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
ifdef|#
directive|ifdef
name|_KERNEL
comment|/* major part of a device internal to the kernel */
define|#
directive|define
name|major
parameter_list|(
name|x
parameter_list|)
value|(major_t)((((unsigned)(x))>> O_BITSMINOR)& O_MAXMAJ)
define|#
directive|define
name|bmajor
parameter_list|(
name|x
parameter_list|)
value|(major_t)((((unsigned)(x))>> O_BITSMINOR)& O_MAXMAJ)
comment|/* get internal major part of expanded device number */
define|#
directive|define
name|getmajor
parameter_list|(
name|x
parameter_list|)
value|(major_t)((((dev_t)(x))>> L_BITSMINOR)& L_MAXMAJ)
comment|/* minor part of a device internal to the kernel */
define|#
directive|define
name|minor
parameter_list|(
name|x
parameter_list|)
value|(minor_t)((x)& O_MAXMIN)
comment|/* get internal minor part of expanded device number */
define|#
directive|define
name|getminor
parameter_list|(
name|x
parameter_list|)
value|(minor_t)((x)& L_MAXMIN)
else|#
directive|else
comment|/* major part of a device external from the kernel (same as emajor below) */
define|#
directive|define
name|major
parameter_list|(
name|x
parameter_list|)
value|(major_t)((((unsigned)(x))>> O_BITSMINOR)& O_MAXMAJ)
comment|/* minor part of a device external from the kernel  (same as eminor below) */
define|#
directive|define
name|minor
parameter_list|(
name|x
parameter_list|)
value|(minor_t)((x)& O_MAXMIN)
endif|#
directive|endif
comment|/* _KERNEL */
comment|/* create old device number */
define|#
directive|define
name|makedev
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(unsigned short)(((x)<< O_BITSMINOR) | ((y)& O_MAXMIN))
comment|/* make an new device number */
define|#
directive|define
name|makedevice
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(dev_t)(((dev_t)(x)<< L_BITSMINOR) | ((y)& L_MAXMIN))
comment|/*  * emajor() allows kernel/driver code to print external major numbers  * eminor() allows kernel/driver code to print external minor numbers  */
define|#
directive|define
name|emajor
parameter_list|(
name|x
parameter_list|)
define|\
value|(major_t)(((unsigned int)(x)>> O_BITSMINOR)> O_MAXMAJ) ? \ 	    NODEV : (((unsigned int)(x)>> O_BITSMINOR)& O_MAXMAJ)
define|#
directive|define
name|eminor
parameter_list|(
name|x
parameter_list|)
define|\
value|(minor_t)((x)& O_MAXMIN)
comment|/*  * get external major and minor device  * components from expanded device number  */
define|#
directive|define
name|getemajor
parameter_list|(
name|x
parameter_list|)
value|(major_t)((((dev_t)(x)>> L_BITSMINOR)> L_MAXMAJ) ? \ 			    NODEV : (((dev_t)(x)>> L_BITSMINOR)& L_MAXMAJ))
define|#
directive|define
name|geteminor
parameter_list|(
name|x
parameter_list|)
value|(minor_t)((x)& L_MAXMIN)
endif|#
directive|endif
comment|/* sun */
comment|/*  * These are versions of the kernel routines for compressing and  * expanding long device numbers that don't return errors.  */
if|#
directive|if
operator|(
name|L_BITSMAJOR32
operator|==
name|L_BITSMAJOR
operator|)
operator|&&
operator|(
name|L_BITSMINOR32
operator|==
name|L_BITSMINOR
operator|)
define|#
directive|define
name|DEVCMPL
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|DEVEXPL
parameter_list|(
name|x
parameter_list|)
value|(x)
else|#
directive|else
define|#
directive|define
name|DEVCMPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(dev32_t)((((x)>> L_BITSMINOR)> L_MAXMAJ32 || \ 	    ((x)& L_MAXMIN)> L_MAXMIN32) ? NODEV32 : \ 	    ((((x)>> L_BITSMINOR)<< L_BITSMINOR32) | ((x)& L_MAXMIN32)))
define|#
directive|define
name|DEVEXPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x) == NODEV32) ? NODEV : \ 	makedevice(((x)>> L_BITSMINOR32)& L_MAXMAJ32, (x)& L_MAXMIN32))
endif|#
directive|endif
comment|/* L_BITSMAJOR32 ... */
comment|/* convert to old (SVR3.2) dev format */
define|#
directive|define
name|cmpdev
parameter_list|(
name|x
parameter_list|)
define|\
value|(o_dev_t)((((x)>> L_BITSMINOR)> O_MAXMAJ || \ 	    ((x)& L_MAXMIN)> O_MAXMIN) ? NODEV : \ 	    ((((x)>> L_BITSMINOR)<< O_BITSMINOR) | ((x)& O_MAXMIN)))
comment|/* convert to new (SVR4) dev format */
define|#
directive|define
name|expdev
parameter_list|(
name|x
parameter_list|)
define|\
value|(dev_t)(((dev_t)(((x)>> O_BITSMINOR)& O_MAXMAJ)<< L_BITSMINOR) | \ 	    ((x)& O_MAXMIN))
comment|/*  * Macro for checking power of 2 address alignment.  */
define|#
directive|define
name|IS_P2ALIGNED
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|)
value|((((uintptr_t)(v))& ((uintptr_t)(a) - 1)) == 0)
comment|/*  * Macros for counting and rounding.  */
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))/(y))
define|#
directive|define
name|roundup
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x)+((y)-1))/(y))*(y))
comment|/*  * Macro to determine if value is a power of 2  */
define|#
directive|define
name|ISP2
parameter_list|(
name|x
parameter_list|)
value|(((x)& ((x) - 1)) == 0)
comment|/*  * Macros for various sorts of alignment and rounding.  The "align" must  * be a power of 2.  Often times it is a block, sector, or page.  */
comment|/*  * return x rounded down to an align boundary  * eg, P2ALIGN(1200, 1024) == 1024 (1*align)  * eg, P2ALIGN(1024, 1024) == 1024 (1*align)  * eg, P2ALIGN(0x1234, 0x100) == 0x1200 (0x12*align)  * eg, P2ALIGN(0x5600, 0x100) == 0x5600 (0x56*align)  */
define|#
directive|define
name|P2ALIGN
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|((x)& -(align))
comment|/*  * return x % (mod) align  * eg, P2PHASE(0x1234, 0x100) == 0x34 (x-0x12*align)  * eg, P2PHASE(0x5600, 0x100) == 0x00 (x-0x56*align)  */
define|#
directive|define
name|P2PHASE
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|((x)& ((align) - 1))
comment|/*  * return how much space is left in this block (but if it's perfectly  * aligned, return 0).  * eg, P2NPHASE(0x1234, 0x100) == 0xcc (0x13*align-x)  * eg, P2NPHASE(0x5600, 0x100) == 0x00 (0x56*align-x)  */
define|#
directive|define
name|P2NPHASE
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(x)& ((align) - 1))
comment|/*  * return x rounded up to an align boundary  * eg, P2ROUNDUP(0x1234, 0x100) == 0x1300 (0x13*align)  * eg, P2ROUNDUP(0x5600, 0x100) == 0x5600 (0x56*align)  */
define|#
directive|define
name|P2ROUNDUP
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(-(x)& -(align)))
comment|/*  * return the ending address of the block that x is in  * eg, P2END(0x1234, 0x100) == 0x12ff (0x13*align - 1)  * eg, P2END(0x5600, 0x100) == 0x56ff (0x57*align - 1)  */
define|#
directive|define
name|P2END
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(~(x)& -(align)))
comment|/*  * return x rounded up to the next phase (offset) within align.  * phase should be< align.  * eg, P2PHASEUP(0x1234, 0x100, 0x10) == 0x1310 (0x13*align + phase)  * eg, P2PHASEUP(0x5600, 0x100, 0x10) == 0x5610 (0x56*align + phase)  */
define|#
directive|define
name|P2PHASEUP
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|phase
parameter_list|)
value|((phase) - (((phase) - (x))& -(align)))
comment|/*  * return TRUE if adding len to off would cause it to cross an align  * boundary.  * eg, P2BOUNDARY(0x1234, 0xe0, 0x100) == TRUE (0x1234 + 0xe0 == 0x1314)  * eg, P2BOUNDARY(0x1234, 0x50, 0x100) == FALSE (0x1234 + 0x50 == 0x1284)  */
define|#
directive|define
name|P2BOUNDARY
parameter_list|(
name|off
parameter_list|,
name|len
parameter_list|,
name|align
parameter_list|)
define|\
value|(((off) ^ ((off) + (len) - 1))> (align) - 1)
comment|/*  * Return TRUE if they have the same highest bit set.  * eg, P2SAMEHIGHBIT(0x1234, 0x1001) == TRUE (the high bit is 0x1000)  * eg, P2SAMEHIGHBIT(0x1234, 0x3010) == FALSE (high bit of 0x3010 is 0x2000)  */
define|#
directive|define
name|P2SAMEHIGHBIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) ^ (y))< ((x)& (y)))
comment|/*  * Typed version of the P2* macros.  These macros should be used to ensure  * that the result is correctly calculated based on the data type of (x),  * which is passed in as the last argument, regardless of the data  * type of the alignment.  For example, if (x) is of type uint64_t,  * and we want to round it up to a page boundary using "PAGESIZE" as  * the alignment, we can do either  *	P2ROUNDUP(x, (uint64_t)PAGESIZE)  * or  *	P2ROUNDUP_TYPED(x, PAGESIZE, uint64_t)  */
define|#
directive|define
name|P2ALIGN_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(x)& -(type)(align))
define|#
directive|define
name|P2PHASE_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(x)& ((type)(align) - 1))
define|#
directive|define
name|P2NPHASE_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|(-(type)(x)& ((type)(align) - 1))
define|#
directive|define
name|P2ROUNDUP_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|(-(-(type)(x)& -(type)(align)))
define|#
directive|define
name|P2END_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|(-(~(type)(x)& -(type)(align)))
define|#
directive|define
name|P2PHASEUP_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|phase
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(phase) - (((type)(phase) - (type)(x))& -(type)(align)))
define|#
directive|define
name|P2CROSS_TYPED
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|(((type)(x) ^ (type)(y))> (type)(align) - 1)
define|#
directive|define
name|P2SAMEHIGHBIT_TYPED
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|type
parameter_list|)
define|\
value|(((type)(x) ^ (type)(y))< ((type)(x)& (type)(y)))
comment|/*  * Macros to atomically increment/decrement a variable.  mutex and var  * must be pointers.  */
define|#
directive|define
name|INCR_COUNT
parameter_list|(
name|var
parameter_list|,
name|mutex
parameter_list|)
value|mutex_enter(mutex), (*(var))++, mutex_exit(mutex)
define|#
directive|define
name|DECR_COUNT
parameter_list|(
name|var
parameter_list|,
name|mutex
parameter_list|)
value|mutex_enter(mutex), (*(var))--, mutex_exit(mutex)
comment|/*  * Macros to declare bitfields - the order in the parameter list is  * Low to High - that is, declare bit 0 first.  We only support 8-bit bitfields  * because if a field crosses a byte boundary it's not likely to be meaningful  * without reassembly in its nonnative endianness.  */
if|#
directive|if
name|defined
argument_list|(
name|_BIT_FIELDS_LTOH
argument_list|)
define|#
directive|define
name|DECL_BITFIELD2
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
define|\
value|uint8_t _a, _b
define|#
directive|define
name|DECL_BITFIELD3
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|)
define|\
value|uint8_t _a, _b, _c
define|#
directive|define
name|DECL_BITFIELD4
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|)
define|\
value|uint8_t _a, _b, _c, _d
define|#
directive|define
name|DECL_BITFIELD5
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|)
define|\
value|uint8_t _a, _b, _c, _d, _e
define|#
directive|define
name|DECL_BITFIELD6
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|)
define|\
value|uint8_t _a, _b, _c, _d, _e, _f
define|#
directive|define
name|DECL_BITFIELD7
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|,
name|_g
parameter_list|)
define|\
value|uint8_t _a, _b, _c, _d, _e, _f, _g
define|#
directive|define
name|DECL_BITFIELD8
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|,
name|_g
parameter_list|,
name|_h
parameter_list|)
define|\
value|uint8_t _a, _b, _c, _d, _e, _f, _g, _h
elif|#
directive|elif
name|defined
argument_list|(
name|_BIT_FIELDS_HTOL
argument_list|)
define|#
directive|define
name|DECL_BITFIELD2
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
define|\
value|uint8_t _b, _a
define|#
directive|define
name|DECL_BITFIELD3
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|)
define|\
value|uint8_t _c, _b, _a
define|#
directive|define
name|DECL_BITFIELD4
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|)
define|\
value|uint8_t _d, _c, _b, _a
define|#
directive|define
name|DECL_BITFIELD5
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|)
define|\
value|uint8_t _e, _d, _c, _b, _a
define|#
directive|define
name|DECL_BITFIELD6
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|)
define|\
value|uint8_t _f, _e, _d, _c, _b, _a
define|#
directive|define
name|DECL_BITFIELD7
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|,
name|_g
parameter_list|)
define|\
value|uint8_t _g, _f, _e, _d, _c, _b, _a
define|#
directive|define
name|DECL_BITFIELD8
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|,
name|_g
parameter_list|,
name|_h
parameter_list|)
define|\
value|uint8_t _h, _g, _f, _e, _d, _c, _b, _a
else|#
directive|else
error|#
directive|error
error|One of _BIT_FIELDS_LTOH or _BIT_FIELDS_HTOL must be defined
endif|#
directive|endif
comment|/* _BIT_FIELDS_LTOH */
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KMEMUSER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|offsetof
argument_list|)
comment|/* avoid any possibility of clashing with<stddef.h> version */
define|#
directive|define
name|offsetof
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|((size_t)(&(((s *)0)->m)))
endif|#
directive|endif
comment|/*  * Find highest one bit set.  *      Returns bit number + 1 of highest bit that is set, otherwise returns 0.  * High order bit is 31 (or 63 in _LP64 kernel).  */
specifier|static
name|__inline
name|int
name|highbit
parameter_list|(
name|ulong_t
name|i
parameter_list|)
block|{
specifier|register
name|int
name|h
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
ifdef|#
directive|ifdef
name|_LP64
if|if
condition|(
name|i
operator|&
literal|0xffffffff00000000ul
condition|)
block|{
name|h
operator|+=
literal|32
expr_stmt|;
name|i
operator|>>=
literal|32
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|i
operator|&
literal|0xffff0000
condition|)
block|{
name|h
operator|+=
literal|16
expr_stmt|;
name|i
operator|>>=
literal|16
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xff00
condition|)
block|{
name|h
operator|+=
literal|8
expr_stmt|;
name|i
operator|>>=
literal|8
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xf0
condition|)
block|{
name|h
operator|+=
literal|4
expr_stmt|;
name|i
operator|>>=
literal|4
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xc
condition|)
block|{
name|h
operator|+=
literal|2
expr_stmt|;
name|i
operator|>>=
literal|2
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0x2
condition|)
block|{
name|h
operator|+=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|h
operator|)
return|;
block|}
comment|/*  * Find highest one bit set.  *	Returns bit number + 1 of highest bit that is set, otherwise returns 0.  */
specifier|static
name|__inline
name|int
name|highbit64
parameter_list|(
name|uint64_t
name|i
parameter_list|)
block|{
name|int
name|h
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|i
operator|&
literal|0xffffffff00000000ULL
condition|)
block|{
name|h
operator|+=
literal|32
expr_stmt|;
name|i
operator|>>=
literal|32
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xffff0000
condition|)
block|{
name|h
operator|+=
literal|16
expr_stmt|;
name|i
operator|>>=
literal|16
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xff00
condition|)
block|{
name|h
operator|+=
literal|8
expr_stmt|;
name|i
operator|>>=
literal|8
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xf0
condition|)
block|{
name|h
operator|+=
literal|4
expr_stmt|;
name|i
operator|>>=
literal|4
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xc
condition|)
block|{
name|h
operator|+=
literal|2
expr_stmt|;
name|i
operator|>>=
literal|2
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0x2
condition|)
block|{
name|h
operator|+=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|h
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SYSMACROS_H */
end_comment

end_unit

