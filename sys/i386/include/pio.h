begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1990 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  */
end_comment

begin_comment
comment|/*   *  * PATCHES MAGIC                LEVEL   PATCH THAT GOT US HERE  * --------------------         -----   ----------------------  * CURRENT PATCH LEVEL:         1       00158  * --------------------         -----   ----------------------  *  * 27 May 93	Rodney W. Grimes	Added #ifndef around inb so that the  *					clash with cpufunc.h does not cause  *					a compile warning.. this is a hack.  *					All of this needs cleaned up at 0.1.5  *  * HISTORY  * $Log: pio.h,v $  * Revision 1.1  1992/05/27  00:48:30  balsup  * machkern/cor merge  *  * Revision 1.1  1991/10/10  20:11:39  balsup  * Initial revision  *  * Revision 2.2  91/04/02  11:52:29  mbj  * 	[90/08/14            mg32]  *   * 	Now we know how types are factor in.  * 	Cleaned up a bunch: eliminated ({ for output and flushed unused  * 	output variables.  * 	[90/08/14            rvb]  *   * 	This is how its done in gcc:  * 		Created.  * 	[90/03/26            rvb]  *   */
end_comment

begin_define
define|#
directive|define
name|inl
parameter_list|(
name|y
parameter_list|)
define|\
value|({ unsigned long _tmp__; \ 	asm volatile("inl %1, %0" : "=a" (_tmp__) : "d" ((unsigned short)(y))); \ 	_tmp__; })
end_define

begin_define
define|#
directive|define
name|inw
parameter_list|(
name|y
parameter_list|)
define|\
value|({ unsigned short _tmp__; \ 	asm volatile(".byte 0x66; inl %1, %0" : "=a" (_tmp__) : "d" ((unsigned short)(y))); \ 	_tmp__; })
end_define

begin_comment
comment|/*  * only do this if it has not already be defined.. this is a crock for the  * patch kit for right now.  Need to clean up all the inx, outx stuff for  * 0.1.5 to use 1 common header file, that has Bruces fast mode inb/outb  * stuff in it.  Rgrimes 5/27/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|inb
end_ifndef

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|y
parameter_list|)
define|\
value|({ unsigned char _tmp__; \ 	asm volatile("inb %1, %0" : "=a" (_tmp__) : "d" ((unsigned short)(y))); \ 	_tmp__; })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|outl
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|{ asm volatile("outl %0, %1" : : "a" (y) , "d" ((unsigned short)(x))); }
end_define

begin_define
define|#
directive|define
name|outw
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|{asm volatile(".byte 0x66; outl %0, %1" : : "a" ((unsigned short)(y)) , "d" ((unsigned short)(x))); }
end_define

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|{ asm volatile("outb %0, %1" : : "a" ((unsigned char)(y)) , "d" ((unsigned short)(x))); }
end_define

end_unit

